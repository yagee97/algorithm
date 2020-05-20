// 쇠막대기
package BOJ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class boj_10799 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String input = br.readLine();
		
		int stick = 0;
		int ret = 0;
		for (int i = 0; i < input.length(); i++) {
			char ch = input.charAt(i);
			//지금꺼가 열린괄호면 막대기 +1
			if(ch == '(')
				stick++;
			// 닫힘괄호면 막대기 -1
			else if(ch == ')') {
				stick--;
				// 이전꺼가 열림괄호면 레이저다 잘라서 결과에 넣자
				if(input.charAt(i-1) == '(') {
					ret += stick;
				}
				// 이전꺼가 닫힘이면 막대기가 끝난거다. 끝난 막대기 남은 쪼가리 추가
				else if(input.charAt(i-1) == ')') {
					ret++;
				}
			}
		}
		StringBuilder sb = new StringBuilder();
		sb.append(ret);
		System.out.println(sb.toString());
		
	}
}
