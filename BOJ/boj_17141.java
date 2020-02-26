import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class boj_17141 {
	static class Pos {
		int x, y;

		public Pos(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}

	static int N, M, times = 0, ret = 987654321;
	static int[][] map;
	static LinkedList<Pos> virus, selectedVirus;
	static boolean[] sel;
	static boolean[][] check;
	static int[][] dis;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		N = sc.nextInt();
		M = sc.nextInt();
		virus = new LinkedList<>();
		selectedVirus = new LinkedList<>();
		sel = new boolean[11];
		check = new boolean[N][N];
		map = new int[N][N];
		dis = new int[N][N];

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				map[i][j] = sc.nextInt();
				if (map[i][j] == 2) {
					// 바이러스 놓을 곳저장
					virus.add(new Pos(i, j));
				}
			}
		}

		dfs(0, 0);
		if (ret == 987654321)
			System.out.println("-1");
		else
			System.out.println(ret);
	}

	static int[] dx = { -1, 0, 1, 0 };
	static int[] dy = { 0, 1, 0, -1 };

	static void spread() {
		Queue<Pos> q = new LinkedList<>();

		for (int i = 0; i < selectedVirus.size(); i++) {
			int x = selectedVirus.get(i).x;
			int y = selectedVirus.get(i).y;
			q.add(new Pos(x, y));
			check[x][y] = true;
		}

		while (!q.isEmpty()) {
			int size = q.size();
			Pos p = q.poll();

			times = dis[p.x][p.y];
			for (int j = 0; j < 4; j++) {
				int nx = p.x + dx[j];
				int ny = p.y + dy[j];
				if (nx < 0 || ny < 0 || nx >= N || ny >= N)
					continue;
				if (!check[nx][ny] && map[nx][ny] != 1) {
					check[nx][ny] = true;
					// 시간 계산
					dis[nx][ny] = dis[p.x][p.y] + 1;
					q.add(new Pos(nx, ny));
				}
			}

		}
		if (verify()) {
			if (ret > times) {
				ret = times;
			}
		}
	}

	static boolean verify() {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] == 1)
					continue;
				if (check[i][j] == false)
					return false;
			}
		}
		return true;
	}

	static void dfs(int cnt, int idx) {
		if (cnt == M) {
			// check랑 거리 배열 초기화도 해야함.
			check = new boolean[N][N];
			dis = new int[N][N];
			spread();
			return;
		}

		for (int i = idx; i < virus.size(); i++) {
			if (!sel[i]) {
				sel[i] = true;
				selectedVirus.add(new Pos(virus.get(i).x, virus.get(i).y));
				dfs(cnt + 1, i);
				selectedVirus.remove(selectedVirus.size() - 1);
				sel[i] = false;
			}
		}
	}
}