package not_solve;

import java.util.Scanner;

public class boj_1592 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int M = sc.nextInt();
		int L = sc.nextInt();
		
		int[] friends = new int[N+1];
		friends[1] = 1;
		int cnt = 0;
		int idx = 1;
		//M번 받기 전이면
		while(friends[idx]!= M) {
			if(friends[idx] % 2 !=0) {
				idx += L;
				if(idx > N) {
					idx -= N;
				}
			}
			else {//반시계
				idx -= L;
				if(idx <=0)
					idx += N;
			}
			friends[idx]++;
			cnt++;
		}
		System.out.println(cnt);
	}
}
