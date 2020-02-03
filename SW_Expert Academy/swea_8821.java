package day05;

import java.util.Arrays;
import java.util.Scanner;

//적고 지우기
public class swea_8821 {
	static int[] map;
	static int[] note;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int tc = 1; tc <= T; tc++) {
			String input = sc.next();
			int cnt = 0;
			map = new int[input.length()];
			note = new int[input.length()];
			for (int i = 0; i < input.length(); i++)
				note[i] = -1;

			for (int i = 0; i < input.length(); i++) {
				map[i] = input.charAt(i) - '0';
				//없는거
				if(note[map[i]] == -1) {
					note[map[i]]++;
				}
				//있는거
				else if(note[map[i]] != -1) {
					note[map[i]]--;
				}
			}
			for(int i = 0;i<note.length;i++) {
				if(note[i] > -1) {
					cnt++;
				}
			}
			System.out.println("#"+tc+" "+cnt);
		}

	}
}
