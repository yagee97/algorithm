import java.util.Scanner;

public class boj_11654 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String input = sc.next();
		
		if(Character.isAlphabetic(input.charAt(0))) {
			System.out.printf("%d",(int)input.charAt(0));
		}
		else if(Character.isDigit(input.charAt(0))) {
			System.out.println(input.charAt(0)+0);
		}
	}
}
