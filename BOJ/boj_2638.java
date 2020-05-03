import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

// 치즈
public class boj_2638 {
	static class Pos {
		int x;
		int y;

		public Pos(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}

	static int N, M;
	static int[][] map, air;
	static boolean[][] chk;
	static ArrayList<Pos> cheese;

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());

		map = new int[N][M];

		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < M; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		int time = 0;
		while (true) {
			cheese = new ArrayList<>(); // 녹일 치즈
			// bfs를 0부터 시작해서 외부공기 찾기. int[][] air를 1로 바꾸기 => 외부공기
			bfs();
			// 외부공기 다 찾았으면, 치즈가 4방향으로 공기와 몇변이 맞닿아있는지 확인.
			// cnt>=2 면 cheese list에 좌표 넣기
			findCheese();
			// 끝나면 list에 있는 애들 좌표에 해당하는 map부분 0으로 만들기
			for (int i = 0; i < cheese.size(); i++) {
				int x = cheese.get(i).x;
				int y = cheese.get(i).y;
				map[x][y] = 0;
			}
			time++;
			// 남은 치즈 있는지 확인하기
			boolean flag = checkCheese();	
			// 없으면 break
			if (flag)
				break;
			
		}
		System.out.println(time);

	}

	static int[] dx = { -1,0,1,0 };
	static int[] dy = { 0,1,0,-1 };

	// 외부공기 찾기
	private static void bfs() {
		chk = new boolean[N][M];
		air = new int[N][M]; // 외부공기 배열
		Queue<Pos> q = new LinkedList<>();
		q.add(new Pos(0, 0));
		chk[0][0] = true;
		air[0][0] = 1;

		while (!q.isEmpty()) {
			Pos p = q.poll();
			int x = p.x;
			int y = p.y;
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx < 0 || ny < 0 || nx >= N || ny >= M)
					continue;
				if (map[nx][ny] == 1 || chk[nx][ny])
					continue;
				if (!chk[nx][ny] && map[nx][ny] == 0) {
					chk[nx][ny] = true;
					air[nx][ny] = 1;
					q.add(new Pos(nx, ny));
				}
			}
		}
	}

	private static void findCheese() {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 1) {
					int cnt = 0;
					for (int k = 0; k < 4; k++) {
						int nx = i + dx[k];
						int ny = j + dy[k];

						if (nx < 0 || ny < 0 || nx >= N || ny >= M)
							continue;
						// 외부공기이면 cnt++
						if (air[nx][ny] == 1) {
							cnt++;
						}
						// 맞닿은 외부공기가 2변 이상이면 기준이었던 치즈 좌표 저장
						if (cnt >= 2) {
							cheese.add(new Pos(i, j));
							break;
						}
					}
				}
			}
		}
	}
	
	private static boolean checkCheese() {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 1) {
					return false;
				}
			}
		}
		return true;
	}
}
