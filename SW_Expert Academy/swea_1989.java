import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class swea_1989 {
	public static void main(String[] args) throws FileNotFoundException {
		System.setIn(new FileInputStream("res/input.txt"));
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int tc = 1; tc <= T; tc++) {
			String input = sc.next();
			String str = reverseString(input);
			
			if(input.equals(str)) {
				System.out.println("#"+tc+" " +"1");
			}
			else
				System.out.println("#"+tc+" " +"0");
		}
	}
	static String reverseString(String s) {
		return (new StringBuffer(s)).reverse().toString();
	}
}
