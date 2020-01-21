//2056.연월일 달력
package Swea;

import java.util.Scanner;

public class swea_2056 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int tc = 1; tc <= t; tc++) {
			String input = sc.next();
			int[] days = new int[] { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

			String year = input.substring(0, 4);
			String month = input.substring(4, 6);
			String day = input.substring(6);
			
			int tmpMonth = Integer.parseInt(month);
			int tmpDay = Integer.parseInt(day);
			
			if (tmpMonth < 1 || tmpMonth > 12 || tmpDay < 1 || tmpDay > days[tmpMonth - 1])
				System.out.println("#"+tc+" "+"-1");
			else {
				String ret;
				ret = year + "/" + month + "/" + day;
				System.out.println("#"+tc+" "+ret);
			}
		}
	}
}
