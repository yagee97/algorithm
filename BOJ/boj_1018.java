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
				//�� �������� �������� ���ΰ��� �Ұ����� ����� ���ΰ��� �Ұ����� �����ϱ⶧����
				//�Ѵ��غ��� �� �����ɷ� �ּҰ��� ã��
				min = Math.min(tmpB, tmpW);
				ans = Math.min(ans, min);
			}
		}
		System.out.println(ans);
	}

	// ���� ����������
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
	
	// ���� �������
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
