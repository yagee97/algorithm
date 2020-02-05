package Algo_0205;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class swea_암호생성기 {
	public static void main(String[] args) throws FileNotFoundException {
		System.setIn(new FileInputStream("res/input.txt"));
		Scanner sc = new Scanner(System.in);
		Queue<Integer> q;

		for (int tc = 1; tc <= 10; tc++) {
			int T = sc.nextInt();
			q = new LinkedList<>();
			
			for (int i = 0; i < 8; i++) {
				int num = sc.nextInt();
				q.add(num);
			}

			int cnt = 1;
			while (true) {
				int tmp = q.poll() - cnt;
				if (tmp <= 0) {
					tmp = 0;
					q.add(tmp);
					break;
				}
				q.add(tmp);
				cnt++;
				if(cnt == 6)
					cnt = 1;
			}
			System.out.print("#" + tc );
			while (!q.isEmpty())
				System.out.print(" " + q.poll());
			System.out.println();
		}

	}
}
