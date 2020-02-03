package day05;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Scanner;

//패턴 마디의 길이
public class swea_2007 {
	public static void main(String[] args) throws FileNotFoundException {
		System.setIn(new FileInputStream("res/input.txt"));
		Scanner sc = new Scanner(System.in);

		int T = sc.nextInt();
		for (int tc = 1; tc <= T; tc++) {
			String input = sc.next();
			int cnt = 2;
			int ret = 0;
			for (int i = 0; i < input.length(); i++) {
				while(true) {
					String str = input.substring(0,cnt);
					String str2 = input.substring(cnt, cnt+cnt);
					if(str.equals(str2)) {
						ret = str.length();
						break;
					}
					else
						cnt++;
				}
			}
			System.out.println("#"+tc+ " "+ret);
		}
	}
}