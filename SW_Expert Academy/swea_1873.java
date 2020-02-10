import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Scanner;

//상호의 배틀필드
public class swea_1873 {
	static int H, W;
	static char[][] map;
	static int tankX, tankY;

	public static void main(String[] args) throws FileNotFoundException  {
		System.setIn(new FileInputStream("res/input.txt"));
		Scanner sc = new Scanner(System.in);

		int T = sc.nextInt();
		for (int tc = 1; tc <= T; tc++) {
			StringBuilder sb = new StringBuilder();
			tankX = 0;
			tankY = 0;
			H = sc.nextInt();
			W = sc.nextInt();
			map = new char[H][W];
			// 맵 구성
			for (int i = 0; i < H; i++) {
				String input = sc.next();
				for (int j = 0; j < input.length(); j++) {
					map[i][j] = input.charAt(j);
					if (map[i][j] == '>' || map[i][j] == '<' || map[i][j] == '^' || map[i][j] == 'v') {
						tankX = i;
						tankY = j;
					}
				}
			}

			int N = sc.nextInt();
			String str = sc.next();
			for (int i = 0; i < str.length(); i++) {
				char c = str.charAt(i);
				solve(c);
			}
			
			sb.append("#"+tc+" ");
			for(int i = 0;i<H;i++) {
				for(int j = 0;j<W;j++) {
					sb.append(map[i][j]);
				}
                sb.append("\n");
			}
			System.out.print(sb.toString());
		}
	}

	static void solve(char c) {
		switch (c) {
		case 'U':
			Up(tankX, tankY);
			break;
		case 'D':
			Down(tankX, tankY);
			break;
		case 'L':
			Left(tankX, tankY);
			break;
		case 'R':
			Right(tankX, tankY);
			break;
		case 'S':
			Shoot(tankX, tankY);
			break;
		}
	}
	static void Up(int x, int y) {
		map[x][y] = '^';
		if (x - 1 < 0)
			return;
		if (map[x - 1][y] == '.' && map[x - 1][y] != '-') {
			map[x][y] = '.';
			map[x - 1][y] = '^';
			tankX = x - 1;
			tankY = y;
		} 
	}
	static void Down(int x, int y) {
		map[x][y] = 'v';
		if (x + 1 >= H)
			return;
		if (map[x + 1][y] == '.' && map[x + 1][y] != '-') {
			map[x][y] = '.';
			map[x + 1][y] = 'v';
			tankX = x + 1;
			tankY = y;
		} 
	}
	static void Left(int x, int y) {
		map[x][y] = '<';
		if (y - 1 < 0)
			return;
		if (map[x][y - 1] == '.' && map[x][y - 1] != '-') {
			map[x][y] = '.';
			map[x][y - 1] = '<';
			tankX = x;
			tankY = y - 1;
		} 
	}
	static void Right(int x, int y) {
		map[x][y] = '>';
		if (y + 1 >= W)
			return;
		if (map[x][y + 1] == '.' && map[x][y + 1] != '-') {
			map[x][y] = '.';
			map[x][y + 1] = '>';
			tankX = x;
			tankY = y + 1;
		}
	}
	static void Shoot(int x, int y) {
		if (map[x][y] == '^') {
			for (int i = x; i >= 0; i--) {
				if (map[i][y] == '*') {
					map[i][y] = '.';
					break;
				} else if (map[i][y] == '#')
					break;
			}
		}
		else if (map[x][y] == 'v') {
			for (int i = x; i < H; i++) {
				if (map[i][y] == '*') {
					map[i][y] = '.';
					break;
				} else if (map[i][y] == '#')
					break;
			}
		}
		else if (map[x][y] == '<') {
			for (int i = y; i >= 0; i--) {
				if (map[x][i] == '*') {
					map[x][i] = '.';
					break;
				} else if (map[x][i] == '#')
					break;
			}
		} else if (map[x][y] == '>') {
			for (int i = y; i < W; i++) {
				if (map[x][i] == '*') {
					map[x][i] = '.';
					break;
				} else if (map[x][i] == '#')
					break;
			}
		}
	}
}