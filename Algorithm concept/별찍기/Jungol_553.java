import java.util.Scanner;

//반복제어문3 - 자가진단6
public class Jungol_553 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		char ch = 'A';
		
		for(int i = 0;i<N;i++) {
			for(int j = N-i;j>0;j--)
				System.out.print(ch++ + " ");
			System.out.println();
		}
	}
}
