package Algo_0205;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

//카드2
public class boj_2161 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		Queue<Integer> q = new LinkedList<>();
		
		int N = sc.nextInt();
		for(int i = 1;i<=N;i++) {
			q.add(i);
		}

		while(q.size()!=1) {
			System.out.print(q.poll()+" ");
			int tmp = q.poll();
			q.add(tmp);
		}
		System.out.print(q.poll()+"\n");
	}
}
