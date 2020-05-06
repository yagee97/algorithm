import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

// 새로운 게임2
public class boj_17837 {
	static int N, K;
	static int[][] map;

	static class Info {
		int x, y, dir;

		public Info(int x, int y, int dir) {
			this.x = x;
			this.y = y;
			this.dir = dir;
		}
	}

	static ArrayList<Info> mal;
	static ArrayList<Integer> seq[][];

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		N = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());

		map = new int[N][N];
		mal = new ArrayList<>();
		seq = new ArrayList[N][N];

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				seq[i][j] = new ArrayList<>();
			}
		}

		// 0: 흰색 1: 빨간색 2: 파란색
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < N; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}

		for (int i = 0; i < K; i++) {
			st = new StringTokenizer(br.readLine());
			int x = Integer.parseInt(st.nextToken()) - 1;
			int y = Integer.parseInt(st.nextToken()) - 1;
			int dir = Integer.parseInt(st.nextToken()) - 1;
			mal.add(new Info(x, y, dir));
			seq[x][y].add(i); // 그 칸에 몇번째에가 쌓였는지
		}

		solve();
		System.out.println(turn);
	}

	static int[] dx = { 0, 0, -1, 1 };
	static int[] dy = { 1, -1, 0, 0 };
	static int turn = 0;

	// 말들이 번호 순서대로 움직여야한다!
	private static void solve() {

		// 종료조건: 턴이 1000보다 크거나 게임이 절대 종료 안되면 -1출력
		while (true) {
			turn++;
			if (turn > 1000) {
				turn = -1;
				return;
			}

			// 말 전부 이동해야함
			for (int i = 0; i < K; i++) {
				// 지금 이동하는 말
				Info info = mal.get(i);
				int x = info.x;
				int y = info.y;
				int dir = info.dir;
				int nx = x + dx[dir];
				int ny = y + dy[dir];

				// 다음칸이 벽이거나 파란색
				if (nx < 0 || ny < 0 || nx >= N || ny >= N || map[nx][ny] == 2) {
					switch (dir) {
					case 0:
						dir = 1;
						break;
					case 1:
						dir = 0;
						break;
					case 2:
						dir = 3;
						break;
					case 3:
						dir = 2;
						break;
					}
					// 지금 차례인 말만 방향 바뀐다!
					mal.get(i).dir = dir;
					nx = x + dx[dir];
					ny = y + dy[dir];

				}
				if ((nx >= 0 && ny >= 0 && nx < N && ny < N) && map[nx][ny]!=2) {
					// 다음칸이 흰칸
					if (map[nx][ny] == 0) {
						int idx = -1;
						// 그 칸에 쌓인 애들 다같이 그 칸으로 이동
						for (int j = 0; j < seq[x][y].size(); j++) {
							int tmp = seq[x][y].get(j); // 몇번 말인지
							
							if (tmp == i) {
								idx = j;
							}
							if (idx == -1)
								continue;

							// 그 번호의 말 이동. 0부터 순서대로. 0이 제일 밑에 있는애
							mal.get(tmp).x = nx;
							mal.get(tmp).y = ny;
							
							seq[nx][ny].add(tmp);// 다음칸에 말 쌓음
							if (seq[nx][ny].size() >= 4) {
								return;
							}
						}

						// 그럼 이동하기 전칸 seq를 없애야함. 이동했으므로.

						int s = seq[x][y].size();
						for (int j = idx; j < s; ++j) {
							seq[x][y].remove(seq[x][y].size() - 1);
						}
					}

					// 빨간칸
					else if (map[nx][ny] == 1) {
						int idx = -1;
						for (int j = seq[x][y].size() - 1; j >= 0; j--) {
							int tmp = seq[x][y].get(j); // 몇번 말인지

							if (tmp == i) {
								idx = j;
								break;
							}
						}
						// 또 지우기
						if (idx == -1)
							continue;

						for (int j = seq[x][y].size() - 1; j >= idx; j--) {
							int tmp = seq[x][y].get(j);

							mal.get(tmp).x = nx;
							mal.get(tmp).y = ny;
							seq[nx][ny].add(tmp);
							if (seq[nx][ny].size() >= 4) {
								return;
							}
						}

						int s = seq[x][y].size();
						for (int j = idx; j < s; j++) {
							seq[x][y].remove(seq[x][y].size() - 1);
						}
					}
				}
			}
		}
	}
}