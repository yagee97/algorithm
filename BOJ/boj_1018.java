import java.util.Arrays;
import java.util.Scanner;

public class boj_1018 {
	static int N, M;
	static char[][] map;
	static int min = Integer.MAX_VALUE;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		N = sc.nextInt();
		M = sc.nextInt();
		map = new char[N][M];

		for (int i = 0; i < N; i++) {
			String str = sc.next();
			for (int j = 0; j < str.length(); j++) {
				map[i][j] = str.charAt(j);
			}
		}
		
		int ans = Integer.MAX_VALUE;
		for(int i = 0;i<=N-8;i++) {
			for(int j = 0;j<=M-8;j++) {
				int tmpB = solveB(i,j);
				int tmpW = solveW(i,j);
				//한 지점에서 검은색이 앞인경우로 할것인지 흰색이 앞인경우로 할것인지 골라야하기때문에
				//둘다해보고 더 작은걸로 최소값을 찾자
				min = Math.min(tmpB, tmpW);
				ans = Math.min(ans, min);
			}
		}
		System.out.println(ans);
	}

	// 앞이 검정색부터
	static int solveB(int x, int y) {
		int cnt = 0;
		for (int i = x; i < x+8; i++) {
			for (int j = y; j < y+8; j++) {
				if ((i % 2 == 0) && (j % 2 == 0)) {
					if (map[i][j] != 'B')
						cnt++;
				} else if ((i % 2 == 1) && (j % 2 == 1)) {
					if (map[i][j] != 'B')
						cnt++;
				} else if ((i % 2 == 0) && (j % 2 == 1)) {
					if (map[i][j] != 'W')
						cnt++;
				} else if ((i % 2 == 1) && (j % 2 == 0)) {
					if (map[i][j] != 'W')
						cnt++;
				}
			}
		}
		return cnt;
	}
	
	// 앞이 흰색부터
		static int solveW(int x, int y) {
			int cnt = 0;
			for (int i = x; i < x+8; i++) {
				for (int j = y; j < y+8; j++) {
					if ((i % 2 == 0) && (j % 2 == 0)) {
						if (map[i][j] != 'W')
							cnt++;
					} else if ((i % 2 == 1) && (j % 2 == 1)) {
						if (map[i][j] != 'W')
							cnt++;
					} else if ((i % 2 == 0) && (j % 2 == 1)) {
						if (map[i][j] != 'B')
							cnt++;
					} else if ((i % 2 == 1) && (j % 2 == 0)) {
						if (map[i][j] !=  'B')
							cnt++;
					}
				}
			}
			return cnt;
		}
}
