import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
//연구소
public class boj_14502 {
	static class pos {
		int x, y;

		public pos(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}

	static int N, M;
	static int max = 0;
	static int[][] map;
	static ArrayList<pos> virus;
	static int[] dx = { 1,0,-1,0};
	static int[] dy = { 0,1,0,-1 };

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		N = sc.nextInt();
		M = sc.nextInt();
		map = new int[N][M];

		virus = new ArrayList<>();
		// 0은 빈칸, 1은 벽, 2는 바이러스
		// 벽 꼭 3개
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				map[i][j] = sc.nextInt();
				// 바이러스 좌표 저장
				if (map[i][j] == 2) {
					virus.add(new pos(i, j));
				}
			}
		}
		// solve
		makeWall(0);

		System.out.println(max);
	}

	static void bfs() {

		Queue<pos> q = new LinkedList<pos>();
		for(int i = 0;i<virus.size();i++)
			q.add(virus.get(i));

		int[][] copyMap = new int[N][M];
		mapCopy(map,copyMap);
		
		while (!q.isEmpty()) {
			pos p = q.poll();
			int x = p.x;
			int y = p.y;

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0 || ny < 0 || nx >= N || ny >= M)
					continue;
				if (copyMap[nx][ny] == 0) {
					copyMap[nx][ny] = 2;
					q.add(new pos(nx, ny));
				}
			}
		}

		int cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (copyMap[i][j] == 0) {
					cnt++;
				}
			}
		}
		max = Math.max(max, cnt);
	}

	static void mapCopy(int[][] map, int[][] newMap)
	{
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				newMap[i][j] = map[i][j];
			}
		}
	}
	
	static void makeWall(int cnt) {
		if (cnt == 3) {
			// 바이러스 퍼뜨리기
			bfs();
			return;
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 0) {
					map[i][j] = 1;
					makeWall(cnt + 1);
					map[i][j] = 0;
				}
			}
		}
	}
}
