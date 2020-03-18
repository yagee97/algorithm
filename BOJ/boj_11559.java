import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

class Info {
	int x, y;

	public Info(int x, int y) {
		this.x = x;
		this.y = y;
	}
}

public class boj_11559 {
	static char[][] map;
	static boolean[][] chk;
	static boolean flag = false;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		map = new char[12][6];
		chk = new boolean[12][6];

		for (int i = 0; i < 12; i++) {
			String str = br.readLine();
			for (int j = 0; j < str.length(); j++) {
				map[i][j] = str.charAt(j);
			}
		}

		int ans = 0;
		while (true) {
			flag = false;
			chk = new boolean[12][6];
			for (int i = 0; i< 12; i++) {
				for (int j = 0; j < 6; j++) {
					if (chk[i][j] || map[i][j] == '.')
						continue;
					bfs(i,j,map[i][j]);
				}
			}
			
			drop();
			if(flag)
				ans++;
			else
				break;
			
		}
		System.out.println(ans);
	}

	// bfs돌면서 기준이 된 애랑 같은 색인 애들을 list에 넣고,
	// bfs가 끝났는데 cnt가 4이상이면, list에 있는 좌표를 다 터뜨리자. .으로 만들기
	// 4이하면 list비우고 넘기자
	// 이게 한턴이 끝나면 중력을 작용시키자.

	static int[] dx = { -1, 0, 1, 0 };
	static int[] dy = { 0, 1, 0, -1 };

	private static void bfs(int x, int y, char stand) {
		Queue<Info> q = new LinkedList<Info>();
		LinkedList<Info> block = new LinkedList<>();
		q.add(new Info(x, y));
		block.add(new Info(x, y));// 터져야하는 block좌표
		chk[x][y] = true;

		while (!q.isEmpty()) {
			Info info = q.poll();
			int cx = info.x;
			int cy = info.y;

			for (int i = 0; i < 4; i++) {
				int nx = cx + dx[i];
				int ny = cy + dy[i];
				if (nx < 0 || ny < 0 || nx >= 12 || ny >= 6)
					continue;
				//기준점의 뿌요색이랑 같아야함.
				if (!chk[nx][ny] && stand == map[nx][ny]) {
					chk[nx][ny] = true;
					q.add(new Info(nx, ny));
					block.add(new Info(nx, ny));
				}
			}
		}

		// 한 위치에서 queue 다 돌았는데, 터뜨릴 block이 4개 이상이면
		if ((int) block.size() >= 4) {
			for (int i = 0; i < block.size(); i++) {
				int bx = block.get(i).x;
				int by = block.get(i).y;
				map[bx][by] = '.';
			}
			flag  = true;// 터진적 있다
		}
	}

	// 중력작용
	private static void drop() {
		// 밑에서 위로 올라가면서, 처음으로 .이 아닌곳만날때까지 가자.
		// .이 아닌곳 만나면, 다시 맨 밑에서부터 그 지점까지 for돌면서 .이 처음으로 나오는 곳과 swap
		for (int j = 0; j < 6; j++) {
			for (int i = 11; i >= 0; i--) {
				if (map[i][j] == '.')
					continue;
				for (int k = 11; k >= i; k--) {
					if (map[k][j] == '.') {
						map[k][j] = map[i][j];
						map[i][j] = '.';
					}
				}
			}
		}
	}
}
