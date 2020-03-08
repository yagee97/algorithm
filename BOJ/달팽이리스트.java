import java.util.Scanner;

public class 달팽이리스트 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int M = sc.nextInt();
		int V = sc.nextInt();
		int[] arr = new int[200001];
		for (int i = 0; i < N; i++) {
			arr[i] = sc.nextInt();
		}
		
		for(int i =0;i<M;i++) {
			int K =sc.nextInt();
			
			if(K < V-1) {
				System.out.println(arr[K]);
			}
			else {
				int ans = arr[(K - (V-1)) % (N - (V-1)) + (V-1)];
				System.out.println(ans);
			}
		}
	}
}
