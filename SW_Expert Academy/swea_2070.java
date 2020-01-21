//2070.Å« ³ð, ÀÛÀº ³ð, °°Àº ³ð
package Swea;

import java.util.Scanner;

public class swea_2070 {
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		int t = sc.nextInt();
		for (int tc = 1; tc <= t; tc++) {
			int n1 = sc.nextInt();
			int n2 = sc.nextInt();
			
			if(n1 > n2)
				System.out.println("#"+t+" >");
			else if(n1 == n2)
				System.out.println("#"+t+" =");
			else
				System.out.println("#"+t+" <");
		}
	}
}
