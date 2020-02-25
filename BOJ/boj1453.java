import java.util.Scanner;

public class boj1453 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		boolean[] map = new boolean[101];
		
		int cnt = 0;
		int N = sc.nextInt();
		for(int i = 0;i<N;i++) {
			int num = sc.nextInt();
			if(map[num]) {
				cnt++;
				continue;
			}
			map[num] = true;
		}
		System.out.println(cnt);
	}
}
