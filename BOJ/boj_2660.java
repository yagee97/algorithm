import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Scanner;

//플로이드와샬
public class boj_2660 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int N = sc.nextInt();
		int[][] list = new int[N + 1][N + 1];

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				list[i][j] = 987654321;
			}
		}

		while (true) {
			int n1 = sc.nextInt();
			int n2 = sc.nextInt();

			if (n1 == -1 && n2 == -1)
				break;
			list[n1][n2] = 1;
			list[n2][n1] = 1;
		}
		
		for (int i = 1; i <= N; i++) {
			list[i][i] = 1;
			for (int j = 1; j <= N; j++) {
				for (int k = 1; k <= N; k++) {
					if (list[j][k] > list[j][i] + list[i][k]) {
						list[j][k] = list[j][i] + list[i][k];
					}
				}
			}
		}
		
		int max[] = new int[N + 1];
		int min = Integer.MAX_VALUE;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (i == j)
					continue;
				max[i] = Math.max(list[i][j], max[i]);
			}
			min = Math.min(max[i], min);
		}
		
		int cnt = 0;
		LinkedList<Integer> idx = new LinkedList<Integer>();
		for (int i = 1; i <= N; i++) {
			if (min == max[i]) {
				idx.add(i);
			}
		}
		Collections.sort(idx);
		StringBuilder sb = new StringBuilder();
		sb.append(min + " " + idx.size() + "\n");
		for (int i : idx)
			sb.append(i + " ");
		System.out.println(sb.toString());
	}
}