package Algo_0205;

import java.util.Scanner;
import java.util.Stack;

public class swea_제로 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();

		for (int tc = 1; tc <= T; tc++) {
			Stack<Integer> stack = new Stack<>();
			int K = sc.nextInt();
			for (int i = 0; i < K; i++) {
				int N = sc.nextInt();
				if (N != 0) {
					stack.push(N);
				}else if(N == 0) {
					stack.pop();
				}
			}
			int ret = 0;
			while(!stack.isEmpty()) {
				ret += stack.pop();
			}
			
			System.out.println("#"+tc+" "+ret);
		}
	}
}
