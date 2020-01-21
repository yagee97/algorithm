//2068. 최대수 구하기
package Swea;

import java.util.Scanner;

public class swea_2068 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int tc = 1; tc <= t; tc++) {
			int maxEle = 0;
			for (int i = 0; i < 10; i++) {
				int input = sc.nextInt();
				if (maxEle < input)
					maxEle = input;
			}
			System.out.println("#" + tc +" "+maxEle);
		}

	}
}
