//2050.���ĺ��� ���ڷ� ��ȯ
package Swea;

import java.util.Scanner;

public class swea_2050 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String input = sc.next();
		
		for(int i =0;i<input.length();i++) {
			//string[i]ó�� �����ϸ� �ȵǰ�, charAt(i)�� ����
			int num = (int)input.charAt(i);
			System.out.print(num-64+" ");
		}
	}
}
