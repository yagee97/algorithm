package SWEA;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class swea_3234 {
	static int N, ans;
	static int[] arr;
	static boolean[] chk;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		StringTokenizer st = null;
		StringBuilder sb = new StringBuilder();
		
		for (int tc = 1; tc <= T; tc++) {
			sb.append("#").append(tc).append(" ");
			N = Integer.parseInt(br.readLine());
			arr = new int[N];
			st = new StringTokenizer(br.readLine());
			for (int i = 0; i < N; i++) {
				int num = Integer.parseInt(st.nextToken());
				arr[i] = num;
			}
			Arrays.sort(arr);
			
			ans = 0;
			// 무게추 배열의 순서를 넥퍼뮤 써서 바꾸면서 dfs 돌리면서 경우의 수 체크
			do {
				solve(1, arr[0] , 0);
			}while(next_permutation(N-1));
			
			sb.append(ans).append("\n");
		}
		System.out.println(sb.toString());
		
	}
	// 왼쪽 오른쪽 무게추 나누기
	private static void solve(int idx, int left, int right) {
		
		if(idx == N) {
			ans++;
			return;
		}
		// 왼쪽에 넣기
		int sum = left + arr[idx];
		solve(idx+1, sum, right);
		
		// 오른쪽에 넣기 단, 무게가 왼쪽보다 작아야함
		sum = right + arr[idx];
		if(sum <= left)
			solve(idx+1, left, sum);
		
	}
	
	private static boolean next_permutation(int len) {
		
		int i = len;
		while(i>0 && arr[i-1] > arr[i])
			i--;
		
		if(i == 0)
			return false;
		
		int j = len;
		while(arr[i-1] > arr[j])
			j--;
		
		int tmp = arr[i-1];
		arr[i-1] = arr[j];
		arr[j] = tmp;
		
		j = len;
		while(i < j) {
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			
			i++;
			j--;
		}
		return true;
	}
	
}