package Algo_0205;

import java.util.Scanner;
import java.util.Stack;

public class swea_계산기2 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		for (int tc = 1; tc <= 10; tc++) {
			Stack<Character> stack = new Stack<>();
			Stack<Integer> stack2 = new Stack<>();
			StringBuilder sb = new StringBuilder();
			int N = sc.nextInt();
			String input = sc.next();

			for (int i = 0; i < input.length(); i++) {
				char c = input.charAt(i);
				if (Character.isDigit(c)) {
					sb.append(c);
				} else {
					if (c == '+' || c == '-') {
						while (!stack.isEmpty()) {
							sb.append(stack.pop());
						}
						stack.push(c);
					} else if (c == '*' || c == '/') {
						while (!stack.isEmpty() && stack.peek() != '+' && stack.peek() != '-') {
							sb.append(stack.pop());
						}
						stack.push(c);
					}
				}
			}
			//마지막 남은거 다 털어야된다
			while (!stack.isEmpty())
				sb.append(stack.pop());

			String post = sb.toString();
			
			for (int i = 0; i < post.length(); i++) {
				char c = post.charAt(i);
				if (Character.isDigit(c)) {
					stack2.push(c - '0');
				} else {
					int b = stack2.pop();
					int a = stack2.pop();
					int tmp = 0;
					if (c == '+') {
						tmp = a + b;
					} else if (c == '-') {
						tmp = a - b;
					} else if (c == '*') {
						tmp = a * b;
					} else if (c == '/') {
						tmp = a / b;
					}
					stack2.push(tmp);
				}
			}
			System.out.println("#" + tc + " " + stack2.pop());
		}
	}
}
