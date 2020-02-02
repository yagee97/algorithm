import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class swea_1959 {
	public static void main(String[] args) throws FileNotFoundException {
		System.setIn(new FileInputStream("res/input.txt"));
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();

		for (int tc = 1; tc <= T; tc++) {
			int N = sc.nextInt();
			int M = sc.nextInt();
			int[] A = new int[N];
			int[] B = new int[M];
			int max = 0;
			for (int i = 0; i < N; i++) {
				A[i] = sc.nextInt();
			}
			for (int j = 0; j < M; j++) {
				B[j] = sc.nextInt();
			}

			if (N == M) {
				for (int i = 0; i < N; i++) {
					max += A[i] * B[i];
				}
			}

			else if (N > M) {
				for (int j = 0; j < N - M +1; j++) {
					int sum = 0;
					int k = j;
					for (int i = 0; i < M; i++) {
						sum += A[k++] * B[i];
					}
					max = Math.max(sum, max);
				}
			} else if(M > N){
				for (int j = 0; j < M - N +1; j++) {
					int sum = 0;
					int k = j;
					for (int i = 0; i < N; i++) {
						sum += A[i] * B[k++];
			
					}
					max = Math.max(sum, max);
				}
			}
			System.out.println("#" + tc + " " + max);
		}
	}
}
