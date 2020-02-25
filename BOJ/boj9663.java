import java.util.Scanner;

public class boj9663 {
	static int N;
	static int cnt;
	static int[] col;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();

		for (int i = 1; i <= N; i++) {
			//첫번째 열부터 퀸을 하나씩 놔보면서 dfs 돌리자. 
			//여길 다시 들어올 때는 dfs가 한번 끝난거기 때문에 col을 다시  초기화해줘야한다.
			col = new int[N + 1];
			col[1] = i;//퀸 놓기
			dfs(1);
		}
		System.out.println(cnt);
	}

	static void dfs(int row) {
		if (row == N) {//퀸 N개 다 놓았으면
			cnt++;//카운트 올리기
			return;
		} else {
			//1열부터 n열까지 반복하면서 row+1,i 에 퀸을 놓을 수 있는지 확인
			for (int i = 1; i <= N; i++) {
				col[row + 1] = i;// 놓기
				if (isPossible(row + 1)) {
					dfs(row + 1);
				}
			}
		}
	}

	static boolean isPossible(int row) {
		for (int i = 1; i < row; i++) {
			if (col[i] == col[row])
				return false;
			if (Math.abs(i - row) == Math.abs(col[i] - col[row]))
				return false;
		}
		return true;
	}
}
