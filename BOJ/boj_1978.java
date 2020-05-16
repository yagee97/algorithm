// 소수 찾기
package BOJ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_1978 {
	static int N;
	static int[] input;
	public static void main(String[] args) throws IOException {
		
		BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		input = new int[N+1];
		StringTokenizer st = new StringTokenizer(br.readLine());
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			int num = Integer.parseInt(st.nextToken());
			
			if(num == 1)
				continue;
			// num이 소수면 cnt++
			boolean flag = true;
			for (int j = 2; j < num; j++) {
				if(num % j == 0) {
					flag = false;
					break;
				}
			}
			if(flag)
				cnt++;
		}
		System.out.println(cnt);
		
	}
}
