//2029.몫과 나머지 출력하기
package Swea;

import java.util.Scanner;

public class swea_2029 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();

		for (int tc = 1; tc <= t; tc++) {
			int a = sc.nextInt();
			int b = sc.nextInt();
			int q = a/b;
			int mod = a%b;
			System.out.println("#"+tc+" "+q+" "+mod);
		}
	}
}
