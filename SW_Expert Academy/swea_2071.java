//2071. 평균값 구하기
package Swea;

import java.util.Scanner;

public class swea_2071 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int test = sc.nextInt();
		for (int tc = 1; tc <= test; tc++) {
			double sum = 0;
			for (int i = 0; i < 10; i++) {
				int num = sc.nextInt();
				sum += num;
			}
			double ret = sum / 10;

			System.out.println("#" + tc + " " + Math.round(ret));
		}

	}
}
