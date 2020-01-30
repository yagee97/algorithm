import java.util.Scanner;

//반복제어문3 - 자가진단7
public class Jungol_554 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int k = 1;
		char ch = 'A';

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N - i; j++) {
				System.out.print(k++ + " ");
			}
			for (int j = 0; j < i + 1; j++) {
				System.out.print(ch++ + " ");
			}
			System.out.println();
		}
	}
}
