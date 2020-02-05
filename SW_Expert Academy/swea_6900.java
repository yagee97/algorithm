package Algo_0205;

import java.util.Scanner;
public class swea_6900 {
	static char[][] buy;
	static char[][] bok;
	static int[] money;
	static int N, M;

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int tc = 1; tc <= T; tc++) {
			N = sc.nextInt();
			M = sc.nextInt();
			int ret = 0;

			buy = new char[M][8];
			bok = new char[N][8];
			money = new int[N];
			for (int i = 0; i < bok.length; i++) {
				String s = sc.next();
				money[i] = sc.nextInt();
				for (int j = 0; j < bok[i].length; j++) {
					bok[i][j] = s.charAt(j);
				}
			}

			for (int i = 0; i < buy.length; i++) {
				String se = sc.next();
				for (int j = 0; j < buy[i].length; j++) {
					buy[i][j] = se.charAt(j);
				}
			}

			for (int i = 0; i < bok.length; i++) {
				for (int j = 0; j < buy.length; j++) {
					boolean flag = true;
					for (int k = 0; k < 8; k++) {
						if (bok[i][k] == '*') {
							continue;
						}
						else if (bok[i][k] != buy[j][k]) {
							flag = false;
							break;
						}
					}
					if (flag) {
						ret += money[i];
					}
				}
			}
			System.out.println("#" + tc + " " + ret);
		}

	}
}