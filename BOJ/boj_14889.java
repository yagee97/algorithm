

import java.util.Scanner;

//스타트와 링크
public class boj_14889 {
	static int N;
	static boolean[] check;
	static int[][] map;
	static int[] sel;
	static int min = Integer.MAX_VALUE;
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		N = sc.nextInt();
		map = new int[N][N];
		check = new boolean[N];
		sel = new int[N];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				map[i][j] = sc.nextInt();
			}
		}
		solve(0,0);
		System.out.println(min);
	}

	static void solve(int idx, int cnt) {
		//더이상 고를게 없는거
		if(idx == N)
			return;
		//다 고른거
		if (cnt == N / 2) {
			// 팀에 속한애들 끼리 더해서 빼기
			int start = 0, link = 0;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					//같은팀이면
					if(check[i] && check[j]) {
						start += map[i][j];
					}
					else if(!check[i] && !check[j]) {
						link += map[i][j];
					}
				}
			}
		
			int diff = Math.abs(start - link);
			if(diff < min) {
				min = diff;
			}
			return;
		}

		for (int i = idx; i < N; i++) {
			if (!check[i]) {
				check[i] = true;
				solve(i , cnt+1);
				check[i] = false;
			}
		}

	}
}
