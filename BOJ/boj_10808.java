// 알파벳 개수
package BOJ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class boj_10808 {
	public static void main(String[] args) throws IOException {
		BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
		String input = br.readLine();
		
		int[] freq = new int[26];
		for (int i = 0; i < input.length(); i++) {
			char ch = input.charAt(i);
			freq[ch-97]++;
		}
		for(int data : freq) {
			System.out.print(data+" ");
		}
	}
}
