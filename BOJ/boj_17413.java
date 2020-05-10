package BOJ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Stack;
import java.util.StringTokenizer;

// 단어뒤집기 2
public class boj_17413 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		String str = br.readLine();
		Stack<Character> stack = new Stack<>();
		boolean tag = false;
		for (int i = 0; i < str.length(); i++) {
			char ch = str.charAt(i);
			if (ch == '<') {
				while (!stack.isEmpty()) {
					System.out.print(stack.pop());
				}
				System.out.print(ch);
				tag = true;
			} else if (ch == '>') {
				tag = false;
				System.out.print(ch);
			}else if(tag) {
				System.out.print(ch);
			}
			else {
				if(ch == ' ') {
					while (!stack.isEmpty()) {
						System.out.print(stack.pop());
					}
					System.out.print(" ");
				}else {
					stack.add(ch);
				}
			}
		}
		while (!stack.isEmpty()) {
			System.out.print(stack.pop());
		}
		System.out.println();
	}
}
