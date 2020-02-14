package Algo_0214;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;

//서로소 집합
public class swea_3289 {
	static int[] parents;
	static int N;
	static int[] rank;

	public static void main(String[] args) throws FileNotFoundException {
		System.setIn(new FileInputStream("res/input.txt"));
		Scanner sc = new Scanner(System.in);
		
		int T = sc.nextInt();
		for (int tc = 1; tc <= T; tc++) {
			StringBuilder sb = new StringBuilder();
			N = sc.nextInt();
			int M = sc.nextInt();
			// 1번부터 시작
			parents = new int[N + 1];
			rank = new int[N + 1];
			makeSet();
			sb.append("#" + tc + " ");
			for (int i = 0; i < M; i++) {
				int type = sc.nextInt();
				int a = sc.nextInt();
				int b = sc.nextInt();

				if (type == 0) {
					// Union
					union(a, b);
				} else if (type == 1) {
					// find
					if (find(a) == find(b)) {
						sb.append("1");
					} else
						sb.append("0");
				}
			}
			System.out.println(sb.toString());
		}
	}

	static void makeSet() {
		for (int i = 1; i <= N; i++) {
			parents[i] = i;
		}
	}

	// 자신의 부모 찾기
	static int find(int x) {
		if (x == parents[x])
			return x;
		else {
			parents[x] = find(parents[x]);
			return parents[x];
		}
	}

	static void union(int a, int b) {
		// 부모를 확인해서
		int v1 = find(a);
		int v2 = find(b);

		// 깊이 비교
		if (rank[v1] > rank[v2]) {
			// v1의 깊이가 더 깊으면 v1을 v2의 부모로 설정
			parents[v2] = v1;
		} else if (rank[v1] < rank[v2]) {
			parents[v1] = v2;
		} else {
			parents[v1] = v2;
			// v2가 v1의 부모가 되었으니 rank를 늘린다.
			rank[v2]++;
		}
	}
}
