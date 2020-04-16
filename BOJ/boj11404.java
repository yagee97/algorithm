import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;
import java.util.StringTokenizer;

// 플로이드
public class boj11404 {
	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		int M = Integer.parseInt(br.readLine());

		int[][] D = new int[N + 1][N + 1];

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				D[i][j] = Integer.MAX_VALUE;
				D[i][i] = 0;
			}
		}
		StringTokenizer st = null;
		for (int i = 0; i < M; i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			int c = Integer.parseInt(st.nextToken());

			// 시작점에서 도착점까지 여러 간선이 있을 수 있으니까 그냥 더 작은 cost를 가진애를 이어주자
			if (D[a][b] > c)
				D[a][b] = c;
		}

		for (int k = 1; k < D.length; k++) { // 거쳐가는 정점
			for (int i = 1; i < D.length; i++) { // 출발정점
				for (int j = 1; j < D.length; j++) { // 도착정점
					if (D[i][k] != Integer.MAX_VALUE && D[k][j] != Integer.MAX_VALUE && D[i][j] > D[i][k] + D[k][j])
						D[i][j] = D[i][k] + D[k][j];
				}
			}
		}
		for (int i = 1; i < D.length; i++) {
			for (int j = 1; j < D.length; j++) {
				if (D[i][j] == Integer.MAX_VALUE)
					D[i][j] = 0;
				System.out.print(D[i][j] + " ");
			}
			System.out.println();
		}
	}
}
