import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

//펭귄추락대책위원회
public class boj_18228 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine());

		int[] arr = new int[N];
		int K = 0;
		for (int i = 0; i < N; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
			if (arr[i] == -1) {
				K = i;
			}
		}
		// 왼쪽꺼 뿌시기
		int left = Integer.MAX_VALUE;
		for (int i = 0; i < K; i++) {
			left = Math.min(left, arr[i]);
		}
		// 오른쪽꺼 뿌시기
		int right = Integer.MAX_VALUE;
		for (int i = K+1; i < N; i++) {
			right = Math.min(right, arr[i]);
		}
		System.out.println(left+right);

	}
}
