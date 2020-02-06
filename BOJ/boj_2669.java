package Algo_0206;

import java.util.Scanner;

public class boj_2669 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int[][] map = new int[101][101];
		int cnt = 0;
		for (int i = 0; i < 4; i++) {
			int x = sc.nextInt();
			int y = sc.nextInt();
			int x2 = sc.nextInt();
			int y2 = sc.nextInt();

			for (int j = x; j < x2; j++) {
				for (int k = y; k < y2; k++) {
					map[j][k] = 1;
				}
			}

		}
		for (int j = 0; j < 100; j++) {
			for (int k = 0; k < 100; k++) {
				if(map[j][k] == 1) {
					cnt++;
				}
			}
		}
		System.out.println(cnt);
	}
}
