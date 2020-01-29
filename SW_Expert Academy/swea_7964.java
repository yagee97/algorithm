import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Scanner;

//부먹왕국의 차원관문
public class swea_7964 {
	public static void main(String[] args) throws FileNotFoundException {
		System.setIn(new FileInputStream("res/input.txt"));
		Scanner sc = new Scanner(System.in);

		int T = sc.nextInt();
		for (int tc = 1; tc <= T; tc++) {
			int N = sc.nextInt();
			int D = sc.nextInt();
			int[] map = new int[N + 2];
			// 0번과 N+1에는 차원 관문 설치되어 있음
			map[0] = 1;
			map[N + 1] = 1;
			for (int i = 1; i <= N; i++) {
				map[i] = sc.nextInt();
			}
			int cursor = 0;
			int cnt = 0;
			int dis = 0; // 거리갱신변수
			while (cursor < N + 2) {
				if (map[cursor] == 1) {
					dis = D;
				} else if (map[cursor] == 0) {
					dis--;
					if (dis == 0) {
						cnt++;
						map[cursor] = 1;
						dis = D;
						continue;
					}
				}
				cursor++;
			}
			System.out.println("#"+tc+" "+cnt);
		}
	}
}
