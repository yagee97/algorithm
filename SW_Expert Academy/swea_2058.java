//2058.�ڸ��� ���ϱ�
package Swea;

import java.util.Scanner;

public class swea_2058 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int num = sc.nextInt();
		int sum = 0;
		while(num != 0) {
			int tmp = num%10;
			num = num/10;
			sum += tmp;
		}
		System.out.println(sum);
	}
}
