import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Scanner;

//안경이 없어!
public class swea_7272 {
	static int[] frontArr, endArr;

	public static void main(String[] args) throws FileNotFoundException {
		System.setIn(new FileInputStream("res/input.txt"));
		Scanner sc = new Scanner(System.in);

		int T = sc.nextInt();
		for (int tc = 1; tc <= T; tc++) {
			StringBuilder sb = new StringBuilder();
			String front = sc.next();
			String end = sc.next();

			if (front.length() != end.length()) {
				sb.append("#" + tc + " " + "DIFF");
				System.out.println(sb.toString());
				continue;
			}

			frontArr = new int[front.length()];
			endArr = new int[end.length()];

			for (int i = 0; i < front.length(); i++) {
				char c = front.charAt(i);
				switch (c) {
				case 'A':
				case 'D':
				case 'O':
				case 'P':
				case 'Q':
				case 'R':
					frontArr[i] = 1;
					break;
				case 'B':
					frontArr[i] = 2;
					break;
				default:
					frontArr[i] = 0;
					break;
				}
			}

			for (int i = 0; i < end.length(); i++) {
				char c = end.charAt(i);
				switch (c) {
				case 'A':
				case 'D':
				case 'O':
				case 'P':
				case 'Q':
				case 'R':
					endArr[i] = 1;
					break;
				case 'B':
					endArr[i] = 2;
					break;
				default:
					endArr[i] = 0;
					break;
				}
			}
			
			boolean flag = true;
			sb.append("#" + tc + " ");
			for (int i = 0; i < frontArr.length; i++) {
				if (frontArr[i] != endArr[i]) {
					flag = false;
					break;
				}
			}
			if (!flag)
				sb.append("DIFF");
			else
				sb.append("SAME");
			System.out.println(sb.toString());
		}
	}

}
