import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.StringTokenizer;

//소수경로
public class boj_1963 {
	static int input, output;
	static boolean[] prime;

	public static void main(String[] args) throws Exception, IOException {
		Scanner sc = new Scanner(System.in);
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;

		int T = Integer.parseInt(br.readLine());
		prime = new boolean[10000];

		//미리 소수 숫자 테이블 만들어둠
		for (int i = 1000; i < 10000; i++) {
			prime[i] = isPrime(i);
		}

		for (int tc = 1; tc <= T; tc++) {
			st = new StringTokenizer(br.readLine());
			result = Integer.MAX_VALUE;
			input = Integer.parseInt(st.nextToken());
			output = Integer.parseInt(st.nextToken());
			bfs(input, output);
			if (result == Integer.MAX_VALUE)
				System.out.println("Impossible");
			else
				System.out.println(result);
		}
	}

	static int result = Integer.MAX_VALUE;

	static void bfs(int input, int output) {
		boolean[] visit = new boolean[10000];

		Queue<int[]> queue = new LinkedList<>();
		queue.add(new int[] { input, 0 });

		while (!queue.isEmpty()) {
			int num = queue.peek()[0];//지금 어떤 소수인지
			int cnt = queue.peek()[1];//cnt는 몇번 바꿨는지
			queue.poll();

			if (num == output) {
				result = Math.min(result, cnt);
				continue;
			}

			if (num < 1000 || visit[num])
				continue;

			visit[num] = true;
			for (int i = 1; i <= 4; i++) {
				for (int j = 0; j < 10; j++) {
					int tNum = change(num, i, j);
					//prime[tNum]은 변경한 값이 소수면! 이라는 뜻
					if (tNum >= 1000 && prime[tNum]) {
						queue.add(new int[] { tNum, cnt + 1 });
					}
				}
			}
		}
	}
	// 한자리씩 바꿔보기
	static int change(int num, int type, int t) {
		int ret = 0;
		switch (type) {
		case 1:
			ret = t * 1000;
			ret += (num - num / 1000 * 1000);
			break;
		case 2:
			ret = t * 100;
			ret += (num / 1000 * 1000) + (num - num / 100 * 100);
			break;
		case 3:
			ret = t * 10;
			ret += num / 100 * 100 + (num - num / 10 * 10);
			break;
		case 4:
			ret = t;
			ret += num / 10 * 10;
			break;
		}
		return ret;
	}

	static boolean isPrime(int num) {
		if (num == 1)
			return false;

		for (int i = 2; i < num; i++) {
			if (num % i == 0)
				return false;
		}
		return true;
	}
}
