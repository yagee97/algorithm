import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class boj_13023 {
	static int N, M;
	static ArrayList<Integer> list[];
	static boolean[] chk;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		chk = new boolean[N];
		list = new ArrayList[N];
		for (int i = 0; i < N; i++) {
			list[i] = new ArrayList<>();
		}

		for (int i = 0; i < M; i++) {
			st = new StringTokenizer(br.readLine());
			int n1 = Integer.parseInt(st.nextToken());
			int n2 = Integer.parseInt(st.nextToken());
			list[n1].add(n2);
			list[n2].add(n1);
		}

		int cnt = 0;
		boolean flag = true;
		for (int i = 0; i < N; i++) {
			dfs(i, 1);
			if(ans == 1)
				break;
		}
		System.out.println(ans);

	}
	static int ans = 0;
	private static void dfs(int x, int depth) {
		if(depth == 5) {
			ans = 1;
			return;
		}
		chk[x] = true;
		for (int i = 0; i < list[x].size(); i++) {
			if(!chk[list[x].get(i)]) {
				chk[list[x].get(i)] = true;
				dfs(list[x].get(i), depth+1);
				chk[list[x].get(i)] = false;
			}
		}
		chk[x] = false;
	}
}
