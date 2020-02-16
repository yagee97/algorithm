import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class 효율적인해킹 {
	static int N, M;
	static int[] arr;
	static boolean[] visit;
	static ArrayList<Integer> arrList[];

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		arrList = new ArrayList[N + 1];
		arr = new int[N + 1];

		for (int i = 1; i <= N; i++)
			arrList[i] = new ArrayList<>();

		for (int i = 0; i < M; i++) {
			st = new StringTokenizer(br.readLine());
			int u = Integer.parseInt(st.nextToken());
			int v = Integer.parseInt(st.nextToken());
			arrList[u].add(v);
		}

		for (int i = 1; i <= N; i++) {
			visit = new boolean[N + 1];
			bfs(i);
		}

		int max = 0;

		for (int i = 1; i <= N; i++) {
			max = Math.max(max, arr[i]);
		}
		StringBuilder sb = new StringBuilder();
		for (int i = 1; i <= N; i++) {
			if (arr[i] == max)
				sb.append(i + " ");
		}
		System.out.println(sb.toString());
	}

	public static void bfs(int index) {

		Queue<Integer> queue = new LinkedList<Integer>();
		queue.add(index);
		visit[index] = true;

		while (!queue.isEmpty()) {
			int val = queue.poll();
			for (int i = 0; i < arrList[val].size(); i++) {
				int v = arrList[val].get(i);
				if (!visit[v]) {
					visit[v] = true;
					arr[v]++;
					queue.add(v);
				}
			}
		}
	}

	public static void dfs(int index) {
		visit[index] = true;

		for (int i = 0; i < arrList[index].size(); i++) {
			if (!visit[arrList[index].get(i)]) {
				arr[arrList[index].get(i)]++;
				dfs(arrList[index].get(i));
			}
		}
	}
}