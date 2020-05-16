package BOJ;

import java.util.Scanner;

public class 에라토스테네스의체 {
	static int N;
	static int[] arr;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		arr = new int[N+1];
		primeNumber();
	}
	
	private static void primeNumber() {
		
		// 1. 배열을 생성하여 초기화
		for (int i = 2; i <= N; i++) {
			arr[i] = i;
		}
		
		// 2. 2부터 시작해서 특정 수의 배수에 해당하는 수를 모두 지운다.
		// 자기자신은 지우지 않고, 이미 지워진 수는 건너뛴다.
		for (int i = 2; i <= N; i++) {
			if(arr[i]==0)
				continue;
			
			// 이미 지워진 숫자 x => 배수부터 출발해서 가능한 모든 숫자 지움
			for (int j = 2*i; j <= N; j+=i) {
				arr[j] = 0;
			}
		}
		
		// 3. 2부터 시작하여 남은 수 출력
		for (int i = 2; i <= N; i++) {
			if(arr[i]!=0)
				System.out.println(arr[i]);
		}
	}
}
