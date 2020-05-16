// 소수 구하기
package BOJ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_1929 {
	static int M,N;
	static int[] prime;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		M = Integer.parseInt(st.nextToken());
		N = Integer.parseInt(st.nextToken());
		
		prime = new int[N+1];
		// 에라토스테네스의 체 이용해서 소수 N까지 구해놓고 M부터의 소수 출력하자
		primeNumber();
		for (int i = M; i <=N; i++) {
			if(prime[i] != 0)
				System.out.println(prime[i]);
		}
		
	}
	
	private static void primeNumber() {
		//초기화
		for (int i = 2; i <= N; i++) {
			prime[i] = i;
		}
		
		for (int i = 2; i <= N; i++) {
			if(prime[i] == 0)
				continue;
			
			// 그 수의 배수가 존재하면 0으로 만들기
			for (int j = 2*i; j <= N; j+=i) {
				prime[j] = 0;
			}
		}
	}
}
