package algo_0129;

import java.util.Scanner;

public class swea_1984 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		int[] input = new int[10];
		for (int tc = 1; tc <= T; tc++) {
			int max = 0, min = 987654321;
			for (int i = 0; i < 10; i++) {
				input[i] = sc.nextInt();
				max = Math.max(input[i], max);
				min = Math.min(input[i], min);
			}

			double sum = 0;
			int cnt = 0;
			for (int i = 0; i < 10; i++) {
				if(input[i] == max || input[i] == min) {
					cnt++;
					continue;
				}
				sum += input[i];
			}
			double avg = sum/(10-cnt);
			System.out.println("#"+tc+" "+ Math.round(avg));
		}
	}
}
