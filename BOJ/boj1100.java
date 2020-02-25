import java.util.Scanner;

public class boj1100 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		char[][] map = new char[8][8];
		int cnt = 0;
		for (int i = 0; i < 8; i++) {
			String str = sc.next();
			for (int j = 0; j < str.length(); j++) {
				char c = str.charAt(j);
				if (c == 'F') {
					if (i == 0 || i % 2 == 0) {
						if (j == 0 || j % 2 == 0) {
							cnt++;
						}
					} else if (i != 0 && i % 2 == 1) {
						if (j != 0 && j % 2 == 1) {
							cnt++;
						}
					}
				}
				else
					continue;
			}
		}
		System.out.println(cnt);
	}

}
