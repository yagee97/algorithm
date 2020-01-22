//3307.최장증가부분수열
package swea_200122;

import java.util.Scanner;

public class swea_3307 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int tc = 1; tc <= T; tc++) {
			int n = sc.nextInt();
			int[] input = new int[n];
			for (int i = 0; i < n; i++) {
				input[i] = sc.nextInt();
			}
			
			int maxEle = 0;
			int[] dp = new int[1001];
			for(int i = 0;i<n;i++) {
				dp[i] = 1;//1로 초기화
				for(int j =0 ;j<i;j++) {
					if(input[j] < input[i] && dp[i] < dp[j]+1)
						dp[i] = dp[j]+1;
				}
				if(dp[i] > maxEle)
					maxEle = dp[i];
			}
			System.out.println("#"+tc+" "+maxEle);
		}
		
	}
}
