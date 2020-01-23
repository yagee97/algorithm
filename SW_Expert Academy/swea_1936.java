//1대 1 가위바위보
import java.util.Scanner;

public class swea_1936 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int user1 = sc.nextInt();
		int user2 = sc.nextInt();
		if(user1 == 1 && user2 == 2)
			System.out.println("B");
		else if(user1 == 2 && user2 == 3)
			System.out.println("B");
		else
			System.out.println("A");
	}
}
