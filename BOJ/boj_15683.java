import java.awt.List;
import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

class cctv {
	int x;
	int y;
	int dir;// �ٶ󺸴� ����
	int num; // ��� cctv����

	public cctv(int x, int y, int dir, int num) {
		this.x = x;
		this.y = y;
		this.dir = dir;
		this.num = num;
	}
}

//����
public class boj_15683 {
	static int N, M, ans = Integer.MAX_VALUE;
	static int[][] map, newMap;
	static ArrayList<cctv> tv;

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		map = new int[N][M];
		tv = new ArrayList<>();
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < M; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
				if (map[i][j] != 0 && map[i][j] != 6) {
					// cctv���� �ֱ�
					tv.add(new cctv(i, j, 0, map[i][j]));
				}
			}
		}
		
		dfs(0);
		System.out.println(ans);
	}

	// ���� ī���ؼ� �� ������ ���������� ���ο� �ʿ� ���ñ����� ǥ���ϰ�, �簢������ �ּ� ũ�⸦ ã�´�.
	// 1. ī�Ǹ� �Լ� �����
	// 2. cctv���� ȸ���� �ϴ� �Լ� ����� ?�ٶ󺸴� �� updownrightleft.
	// 3. ����¥��
	static void copyMap(int[][] map, int[][] newMap) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				newMap[i][j] = map[i][j];
			}
		}
	}

	static void UP(int x, int y) {
		for (int i = x; i >= 0; i--) {
			if (newMap[i][y] == 6)
				break;
			if (newMap[i][y] == 0) {
				newMap[i][y] = -1;
			}
		}
	}

	static void DOWN(int x, int y) {
		for (int i = x; i < N; i++) {
			if (newMap[i][y] == 6)
				break;
			if (newMap[i][y] == 0)
				newMap[i][y] = -1;
		}
	}

	static void RIGHT(int x, int y) {
		for (int i = y; i < M; i++) {
			if (newMap[x][i] == 6)
				break;
			if (newMap[x][i] == 0)
				newMap[x][i] = -1;
		}
	}

	static void LEFT(int x, int y) {
		for (int i = y; i >= 0; i--) {
			if (newMap[x][i] == 6)
				break;
			if (newMap[x][i] == 0)
				newMap[x][i] = -1;
		}
	}

	static void solve() {
		newMap = new int[N][M];
		copyMap(map, newMap);

		for (int i = 0; i < tv.size(); i++) {
			int x = tv.get(i).x;
			int y = tv.get(i).y;
			int dir = tv.get(i).dir;
			int num = tv.get(i).num;

			// 1�� cctv�� �ѹ���
			if (num == 1) {
				if (dir == 0)
					UP(x, y);
				else if (dir == 1)
					DOWN(x, y);
				else if (dir == 2)
					RIGHT(x, y);
				else if (dir == 3)
					LEFT(x, y);
			}

			// �����
			else if (num == 2) {
				if (dir == 0 || dir == 2) {
					UP(x, y);
					DOWN(x, y);
				} else if (dir == 1 || dir == 3) {
					RIGHT(x, y);
					LEFT(x, y);
				}
			}

			// ����
			else if (num == 3) {
				if (dir == 0) {
					UP(x, y);
					RIGHT(x, y);
				} else if (dir == 1) {
					RIGHT(x, y);
					DOWN(x, y);
				} else if (dir == 2) {
					DOWN(x, y);
					LEFT(x, y);
				} else if (dir == 3) {
					LEFT(x, y);
					UP(x, y);
				}
			}
			// ������
			else if (num == 4) {
				if (dir == 0) {
					LEFT(x, y);
					UP(x, y);
					RIGHT(x, y);
				} else if (dir == 1) {
					UP(x, y);
					RIGHT(x, y);
					DOWN(x, y);
				} else if (dir == 2) {
					RIGHT(x, y);
					DOWN(x, y);
					LEFT(x, y);
				} else if (dir == 3) {
					DOWN(x, y);
					LEFT(x, y);
					UP(x, y);
				}
			} else if (num == 5) {
				UP(x, y);
				DOWN(x, y);
				RIGHT(x, y);
				LEFT(x, y);
			}
		}

		int cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (newMap[i][j] == 0)
					cnt++;
			}
		}
		ans = Math.min(ans, cnt);
	}

	static void dfs(int idx) {
		if (idx == tv.size()) {
			solve();
			return;
		}

		tv.get(idx).dir = 0;
		dfs(idx + 1);
		tv.get(idx).dir = 1;
		dfs(idx + 1);
		tv.get(idx).dir = 2;
		dfs(idx + 1);
		tv.get(idx).dir = 3;
		dfs(idx + 1);
	}
}
