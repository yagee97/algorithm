import java.util.Scanner;

public class boj_안전영역 {
	static int[][] map;
	static int n, high = 0;
	static int ret =0;
	static int[][] check;
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		n = sc.nextInt();
		map = new int[101][101];
		
		for(int i = 0;i<n;i++)
		{
			for(int j = 0;j<n;j++) {
				map[i][j] = sc.nextInt();
				high = Math.max(high, map[i][j]);
			}
		}
		
		//가장높은걸 기준으로
		while(high-- > 0) {
			check = new int[101][101];
			int cnt = 0;
			for(int i = 0;i<n;i++) {
				for(int j = 0;j<n;j++) {
					if(check[i][j] == 0 && map[i][j] > high) {
						//영역탐색
						dfs(i, j, high);
						cnt++;
					}
				}
			}
			ret = Math.max(ret, cnt);
		}
		System.out.println(ret);
	}
	
	public static void dfs(int x, int y, int h) {
		int[] dx = {-1,0,1,0};
		int[] dy = {0,1,0,-1};
		
		check[x][y] = 1;
		
		for(int i = 0;i<4;i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(nx < 0 || ny < 0|| nx >= n || ny >= n)
				continue;
			if(check[nx][ny] != 1 && map[nx][ny] > h) {
				check[nx][ny] = 1;
				dfs(nx,ny,h);
			}
		}
	}
}
