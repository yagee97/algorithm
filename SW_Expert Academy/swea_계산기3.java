package Algo_0205;

import java.util.Scanner;
import java.util.Stack;

public class swea_계산기3 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		for (int tc = 1; tc <= 10; tc++) {
			sc.next();
			String expr = sc.next();
			StringBuilder sb = new StringBuilder();
			Stack<Character> stack = new Stack<>();
			for (int i = 0; i < expr.length(); i++) {
				char c = expr.charAt(i);
				if (Character.isDigit(c)) {
					// System.out.print(c);
					sb.append(c);
				} else {
					// 동급과 나보다 높으면은 꺼낸다.
					if (c == '+' || c == '-') {
						// 열림괄호는 누구나 깔고 앉을 수 잇다.
						while (!stack.isEmpty() && stack.peek() != '(') {
							sb.append(stack.pop());
						}
						stack.push(c);
					}
					// 스택이 비어있지 않으면서 스택의 맨위가 덧셈/뺄셈이면 자기를 푸쉬
					else if (c == '*' || c == '/') {
						while (!stack.isEmpty() && stack.peek() != '+' && stack.peek() != '-' && stack.peek() != '(') {
							sb.append(stack.pop());
						}
						stack.push(c);
					} else if (c == '(') {
						// 열림괄호는 일단 그냥 다 깔고 앉음
						stack.push(c);
					} else if (c == ')') {
						// 닫힘괄호는 열림괄호를 만날때까지 다 꺼내서 출력하고, 열림괄호 버린다.
						while (true) {
							char top = stack.pop();
							if (top != '(') {
								sb.append(top);
							} else {
								break;
							}
						}

					}
				}
			}
			while (!stack.isEmpty())
				sb.append(stack.pop());

			String str = sb.toString();

			Stack<Integer> stack2 = new Stack<>();

			for (int i = 0; i < str.length(); i++) {
				char op = str.charAt(i);
				// Character.isDigit(op) 이것도 가능
				if (op != '*' && op != '+' && op != '-' && op != '/') {
					stack2.push(str.charAt(i) - '0');
				} else {
					// 먼저 나가는 애가 나중에 들어온 애니까 빼기, 나누기에 영향을 준다.
					// 그래서 변수를 제대로 설정해야함.
					int b = stack2.pop();
					int a = stack2.pop();
					int tmp = 0;
					if (op == '*') {
						tmp = a * b;
					} else if (op == '/') {
						tmp = a / b;
					} else if (op == '-') {
						tmp = a - b;
					} else if (op == '+') {
						tmp = a + b;
					}
					stack2.push(tmp);
				}
			}
			System.out.println("#"+tc+" "+stack2.pop());
		}
	}
}