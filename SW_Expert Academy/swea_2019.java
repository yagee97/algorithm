import java.util.Scanner;

//더블더블
public class swea_2019 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int ret= 1;
		for(int i = 0;i<=N;i++) {
			System.out.print(ret+" ");
			ret*=2;
		}
	}
}
