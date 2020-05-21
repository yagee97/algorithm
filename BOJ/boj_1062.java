// 가르침
package BOJ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_1062 {
	static int N,K;
	static boolean[][] word;
	static boolean[] chk;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
		
		// N개의 줄에 단어
		word = new boolean[N][26];
		
		for (int i = 0; i < N; i++) {
			String input = br.readLine();
			for (int j = 0; j < input.length(); j++) {
				word[i][input.charAt(j) -'a'] = true;//알파벳 뭐썻는지
			}
		}
		
		chk = new boolean[26];
		solve(0,0);
		System.out.println(ans);
		
	}
	
	static int ans = 0;
	private static void solve(int idx, int depth) {
		// 알파벳 k개 다 골랐으면 단어 몇개 만들수 있는지 체크
		if(depth == K) {
			check();
			return;
		}
		
		for (int i = idx; i < 26; i++) {
			if(!chk[i]) {
				chk[i] = true;
				solve(i, depth+1);
				chk[i] = false;
			}
		}
	}
	
	private static void check() {
		int result = 0;
		
		boolean flag = true;
		for (int k = 0; k < N; k++) {
			flag = true;
			for (int i = 0; i < 26; i++) {
				// 알파벳 골랐는데 이 단어에 이 알파벳이 안쓰였으면 끝!
				if(word[k][i] && !chk[i]) {
					flag = false;
					break;
				}
			}
			if(flag)
				result++;
		}
		ans = Math.max(result, ans);
	}
}
