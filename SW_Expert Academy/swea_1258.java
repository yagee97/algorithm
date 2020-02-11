import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Scanner;

public class swea_1258 {
	static int N;
	static int[][] map;
	static int endX = -1, endY = -1;

	static class pos implements Comparable<pos>{
		int x;
		int y;

		public pos(int x, int y) {
			this.x = x;
			this.y = y;
		}
		
		public int getX() {
			return x;
		}

		public int getY() {
			return y;
		}

		@Override
		public int compareTo(pos p) {
			int ret = this.x * this.y;
			int ret2 = p.getX() * p.getY();
			if(ret > ret2) {
				return 1;
			}
			else if(ret < ret2) {
				return -1;
			}
			else if(ret == ret2) {
				if(this.x > p.getX())
					return 1;
				else if(this.x < p.getX())
					return -1;
				return 0;
			}
			return 0;
		}
		
	}

	public static void main(String[] args) throws FileNotFoundException {
		System.setIn(new FileInputStream("res/input.txt"));
		Scanner sc = new Scanner(System.in);

		int T = sc.nextInt();
		for (int tc = 1; tc <= T; tc++) {
			StringBuilder sb = new StringBuilder();
			
			N = sc.nextInt();
			map = new int[N][N];
			LinkedList<pos> list = new LinkedList<>();
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					map[i][j] = sc.nextInt();
				}
			}
			int cnt = 0;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (map[i][j] != 0) {
						endX = -1;
						endY = -1;
						dfs(i, j);
						list.add(new pos(endX-i+1, endY-j+1));
						cnt++;
					}
				}
			}
			Collections.sort(list);
			
			sb.append("#"+tc+" "+cnt+" ");
			for(int i = 0;i<list.size();i++) {
				pos p = list.get(i);
				sb.append(p.x + " " + p.y+" ");
			}
			System.out.println(sb.toString());
		}
	}

	
	static int[] dx = { 0,0,-1,1};
	static int[] dy = { -1,1,0,0 };
	static void dfs(int x, int y) {
		map[x][y] = 0;

		endX = (endX < x) ? x : endX;
		endY = (endY < y) ? y : endY;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx > N-1 || ny > N-1 || map[nx][ny] == 0)
				continue;
			dfs(nx, ny);
		}
	}
}
