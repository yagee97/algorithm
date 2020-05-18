// 골드바흐의 추측
package BOJ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class boj_6588 {
	static int N;
	static int[] prime;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		prime = new int[1000001];
		primeNumber();
		while (true) {
			StringBuilder sb= new StringBuilder();
			int num = Integer.parseInt(br.readLine());
			if (num == 0)
				break;

			int n1 = 0, n2 = 0;
			for (n1 = 3; n1 < num; n1++) {
				if(prime[n1] != 0) {
					n2 = num - n1;
					if(prime[n2]!=0) {
						sb.append(num).append(" = ").append(n1).append(" + ").append(n2);
						break;
					}
				}
			}
			if(n1 == num)
				sb.append("Goldbach's conjecture is wrong.");
			System.out.println(sb.toString());
		}
	}

	private static void primeNumber() {

		// 초기화
		for (int i = 2; i <= 1000000; i++) {
			prime[i] = i;
		}

		// 배수가 되는 애들 0으로 만들기
		for (int i = 2; i <= Math.sqrt(1000000); i++) {
			if (prime[i] == 0)
				continue;
			for (int j = 2 * i; j <= 1000000; j += i) {
				prime[j] = 0;
			}
		}
	}
}

class Prime {
	int n1, n2;

	public Prime(int n1, int n2) {
		this.n1 = n1;
		this.n2 = n2;
	}
}
