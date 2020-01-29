import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Scanner;

public class swea_1206 {
	static int[][] map;

	public static void main(String[] args) throws FileNotFoundException {
		System.setIn(new FileInputStream("res/input.txt"));
		Scanner sc = new Scanner(System.in);

		for (int tc = 1; tc <= 10; tc++) {
			int N = sc.nextInt();
			map = new int[256][N];
			boolean flag = false;
			int cnt = 0;
			for (int i = 0; i < N; i++) {
				int num = sc.nextInt();
				for (int j = 0; j < num; j++)
					map[j][i] = 1;
			}

			//빌딩 최대 높이 = 255 가로 길이 1000 이하
			for (int i = 0; i < 255; i++) {
				for (int j = 2; j < N-1; j++) {
					if(map[i][j] == 1) {
						flag = false;
						for(int k = 1;k<3;k++) {
							//해당 칸의 양옆이 건물이면
							if(map[i][j+k] == 1 || map[i][j-k] == 1) {
								flag = true;
								break;
							}
						}
						if(!flag)
							cnt++;
					}
				}
			}
			
			System.out.println("#"+tc+" "+cnt);
		}

	}
}