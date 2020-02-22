package day07;

import java.util.Scanner;

public class boj_9625 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int K = sc.nextInt();
		int cntA = 1, cntB = 0;
		
		while(K-- > 0) {
			int tmp = cntA;
			cntA = cntB;
			cntB += tmp;
		}
		System.out.println(cntA + " " + cntB);
	}
}
