//2050. 알파벳을 숫자로 변환
package Swea;

import java.util.Scanner;

public class swea_2050 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String input = sc.next();
		
		for(int i =0;i<input.length();i++) {
			//string[i]에 바로 접근 불가, charAt(i)으로 접근해야함.			
			int num = (int)input.charAt(i);
			System.out.print(num-64+" ");
		}
	}
}
