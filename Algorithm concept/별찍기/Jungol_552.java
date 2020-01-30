import java.util.Scanner;

public class Jungol_552 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int N = sc.nextInt();

		for (int i = 0; i < N; i++) {
			for(int j = 1;j<=i;j++) {
				System.out.print(" ");
			}
			for(int k = 1;k<=(N-i)*2-1;k++) {
				System.out.print("*");
			}

			System.out.println();
		}
	}
}
