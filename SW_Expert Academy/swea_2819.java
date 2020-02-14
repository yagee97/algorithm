package Algo_0214;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashSet;
import java.util.StringTokenizer;
//격자판의 숫자 이어붙이기
public class swea_2819 {

	static int[][] map;
	static HashSet<String> set;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int T = Integer.parseInt(br.readLine());

		for (int tc = 1; tc <= T; tc++) {
			map = new int[4][4];
			set = new HashSet<>();
			for (int i = 0; i < 4; i++) {
				StringTokenizer st = new StringTokenizer(br.readLine());
				for (int j = 0; j < 4; j++) {
					int num = Integer.parseInt(st.nextToken());
					map[i][j] = num;
				}
			}
			for(int i = 0;i<4;i++) {
				for(int j = 0;j<4;j++)
					dfs(i,j,0,"");
			}
			System.out.println(set.size());
		}
	}

	static int dx[] = { -1, 0, 1, 0 };
	static int dy[] = { 0, 1, 0, -1 };

	static void dfs(int x, int y, int cnt, String str) {
		if (cnt == 7) {
			// set에 붙이기
			set.add(str);
			str = "";
			return;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= 4 || ny >= 4)
				continue;
			dfs(nx, ny, cnt + 1, str + map[nx][ny]);
		}
	}
}
