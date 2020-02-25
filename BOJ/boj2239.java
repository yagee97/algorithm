import java.util.Scanner;

//½ºµµÄí
public class boj2239 {
	static int[][] map;
	static boolean[][] row;
	static boolean[][] col;
	static boolean[][] square;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		map = new int[10][10];
		row = new boolean[10][10];
		col = new boolean[10][10];
		square = new boolean[10][10];

		for (int i = 0; i < 9; i++) {
			String str = sc.next();
			for (int j = 0; j < str.length(); j++) {
				map[i][j] = str.charAt(j)-'0';
				if (map[i][j] != 0) {
					row[i][map[i][j]] = true;
					col[j][map[i][j]] = true;
					// Âü°í..Çß´Ù
					square[(i / 3) *3 +(j / 3)][map[i][j]] = true;
				}
			}
		}
		
		dfs(0);
	}

	static void dfs(int cnt) {
		// °¢ Ä­ÀÇ x,y ÁÂÇ¥
		int x = cnt / 9;
		int y = cnt % 9;

		if (cnt == 81) {
			for (int i = 0; i < 9; i++) {
				for (int j = 0; j < 9; j++) {
					System.out.print(map[i][j]);
				}
				System.out.println();
			}
			System.exit(0);
		}

		if (map[x][y] == 0) {
			for (int i = 1; i <= 9; i++) {
				if (row[x][i] == false && col[y][i] == false && square[(x / 3) * 3 + (y / 3)][i] == false) {
					row[x][i] = true;
					col[y][i] = true;
					square[(x / 3) * 3 + (y / 3)][i] = true;
					map[x][y] = i;
					dfs(cnt + 1);
					map[x][y] = 0;
					row[x][i] = false;
					col[y][i] = false;
					square[(x / 3) * 3 + (y / 3)][i] = false;
				}
			}
		} else
			dfs(cnt + 1);
	}
}
