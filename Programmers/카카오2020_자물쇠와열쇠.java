import java.util.Iterator;

public class 카카오2020_자물쇠와열쇠 {
	static boolean isOk = false;

	public boolean solution(int[][] key, int[][] lock) {
		int len = lock.length;
		// 3배 확장 후 중앙으로 옮기기
		// 이렇게 하면 key를 직접 상하좌우로 이동시켜보지 않아도
		// 그냥 좌상단부터 훑으면서 대입해보면 된다.
		int[][] copyLock = new int[len * 3][len * 3];
		for (int i = 0; i < len; i++) {
			for (int j = 0; j < len; j++) {
				copyLock[i + len][j + len] = lock[i][j];
			}
		}

		// dfs
		dfs(key, copyLock, 0);
		return isOk;
	}

	// 인자로 3배 확장한 애가 넘어옴
	private static void dfs(int[][] key, int[][] lock, int cnt) {
		check(key, lock, 0, 0);
		if (isOk)
			return;
		if (cnt >= 4)
			return; // 회전 네번 다했는데도 안됐으면 return
		int[][] tmp = rotate(key); // key 회전하자
		dfs(tmp, lock, cnt + 1);
	}

	// 여기도 3배확장한 애가 넘어오면서, KEY를 상하좌우 이동시켜가며 자물쇠에 맞는 열쇤지 확인
	private static void check(int[][] key, int[][] lock, int x, int y) {
		if (isOk)
			return;
		if (y + key.length > lock.length) {
			y = 0;
			x++;
		}
		// 오른쪽으로 다 가봤으면
		if (x + key.length > lock.length)
			return;

		int[][] copyLock = new int[lock.length][lock.length];
		for (int i = 0; i < lock.length; i++) {
			copyLock[i] = lock[i].clone();
		}

		boolean isFail = false;
		loop: for (int i = 0; i < key.length; i++) {
			for (int j = 0; j < key.length; j++) {
				// 열쇠의 돌기 부분이면
				if (key[i][j] == 1) {
					// 상하좌우 이동해가는데 자물쇠카피본자식도 돌기면
					if (copyLock[i + x][j + y] == 1) {
						isFail = true;
						break loop;
					}
					// 자물쇠에 열쇠 끼워넣기
					copyLock[i + x][j + y] = key[i][j];
				}
			}
		}
		if (!isFail) {
			loop:
			// 돌기랑 돌기랑 닿은곳은 없지만, 자물쇠의 중앙이랑 맞지 않으면!
			for (int i = 0; i < lock.length / 3; i++) {
				for (int j = 0; j < lock.length / 3; j++) {
					// 아마 홈이랑 홈이면
					if (copyLock[i + lock.length / 3][j + lock.length / 3] != 1) {
						isFail = true;
						break loop;
					}
				}
			}
		}
		if (!isFail) {
			isOk = true;
		}
		// 아래로 한칸 내려서 다시 시도하자
		check(key, lock, x, y + 1);
	}

	// 회전하자 시계방향으로~
	private static int[][] rotate(int[][] key) {
		int len = key.length;
		int[][] tmp = new int[len][len];
		for (int i = 0; i < len; i++) {
			for (int j = 0; j < len; j++) {
				tmp[i][j] = key[len - j - 1][i];
			}
		}
		return tmp;
	}
}
