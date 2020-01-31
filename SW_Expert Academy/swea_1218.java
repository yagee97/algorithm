package Algo_0131;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.Stack;

public class swea_1218 {
	public static void main(String[] args) throws FileNotFoundException {
		System.setIn(new FileInputStream("res/input.txt"));
		Scanner sc = new Scanner(System.in);
		

		for (int tc = 1; tc <= 10; tc++) {
			Stack<Character> stack = new Stack<>();
			int N = sc.nextInt();
			char[] input = new char[N];
			boolean flag = true;
			String str = sc.next();
			for (int i = 0; i < str.length(); i++) {
				char ch = str.charAt(i);
				if (ch == '(' || ch == '[' || ch == '{' || ch == '<') {
					stack.push(ch);
				} else {
					if (!stack.isEmpty()) {
						char popCh = stack.pop();
						if (ch == ')') {
							if (popCh!= '(') {
								flag = false;
								break;
							}
						} else if (ch == ']') {
							if (popCh != '[') {
								flag = false;
								break;
							}
						} else if (ch == '}') {
							if (popCh != '{') {
								flag = false;
								break;
							}
						} else if (ch == '>') {
							if (popCh != '<') {
								flag = false;
								break;
							}
						}
					}
				}
			}
			if (flag) {
				if (stack.isEmpty()) {
					System.out.println("#" + tc + " " + "1");
				}else
					System.out.println("#" + tc + " " + "0");
			} else if(!flag)
				System.out.println("#" + tc + " " + "0");

		}

	}
}
