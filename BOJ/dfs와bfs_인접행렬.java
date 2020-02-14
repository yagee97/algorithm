package Algo_0214;

import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class 인접행렬 {
	// 첫줄에는 정점의 개수와 간선의 개수가 주어지고 둘째줄부터 간선의 개수만큼 연결정보가 주어진다.
	// 얘는 양방향 그래프이다. 인접행렬로 담아서 출력해보시오.
	static int[][] matrix;

	static int N, M, V;
	static StringBuilder sb;
	static boolean[] visit;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		N = sc.nextInt();
		M = sc.nextInt();
		V = sc.nextInt();
		sb = new StringBuilder();
		visit = new boolean[N + 1];
		matrix = new int[N + 1][N + 1];
		for (int i = 0; i < M; i++) {
			int v1 = sc.nextInt();
			int v2 = sc.nextInt();

			matrix[v1][v2] = 1;
			matrix[v2][v1] = 1;
		}

		dfs(V);
		System.out.println(sb.toString());
		visit = new boolean[N + 1];
		sb = new StringBuilder();
		bfs(V);
		System.out.println(sb.toString());

	}

	static void dfs(int start) {

		visit[start] = true;
		sb.append(start + " ");
		for (int i = 0; i < N; i++) {
			if (matrix[start][i] == 1 && !visit[i]) {
				dfs(i);
			}
		}
	}

	static void bfs(int start) {
		Queue<Integer> q = new LinkedList<>();
		q.add(start);
		visit[start] = true;
		while (!q.isEmpty()) {
			int x = q.poll();
			sb.append(x + " ");
			for (int i = 0; i < N; i++) {
				if (matrix[x][i] == 1 && !visit[i]) {
					q.add(i);
					visit[i] = true;
				}
			}
		}
	}
}
