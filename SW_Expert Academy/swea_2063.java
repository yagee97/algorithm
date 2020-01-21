//2063. 중간값 찾기
package Swea;

import java.util.Arrays;
import java.util.Scanner;

public class swea_2063 {
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int[] arr = new int[N];
		
		for (int i = 0; i < N; i++) {
			arr[i] = sc.nextInt();
		}
		Arrays.sort(arr);
		int mid = N/2;
		System.out.println(arr[mid]);
	}
}
