//2025.N줄덧셈
package Swea;

import java.util.Scanner;

public class swea_2025 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int ret = n*(n+1)/2;
		System.out.println(ret);
	}
}