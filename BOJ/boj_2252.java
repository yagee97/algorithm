package BOJ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class boj_2252 {
	static int N, M;
	static ArrayList<Integer> list[];
	static int[] inDegree;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br= new BufferedReader(new InputStreamReader(System.in));

		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		list = new ArrayList[N+1];
		inDegree = new int[N+1];
		
		for (int i = 1; i <= N; i++) {
			list[i] = new ArrayList<>();
		}
		
		for (int i = 0; i < M; i++) {
			int num1,num2;
			st = new StringTokenizer(br.readLine());
			num1 = Integer.parseInt(st.nextToken());
			num2 = Integer.parseInt(st.nextToken());
			list[num1].add(num2);
			inDegree[num2]++;
			
		}
		
		topologySort();
	}
	
	private static void topologySort() {
		int[] result = new int[32001];
		Queue<Integer> queue = new LinkedList<Integer>();
		
		for (int i = 1; i <= N; i++) {
			if(inDegree[i] == 0)
				queue.add(i);
		}
		
		for (int i = 1; i <= N; i++) {
			if(queue.isEmpty())
				return;
			int x = queue.poll();
			result[i] = x;
			for (int j = 0; j < list[x].size(); j++) {
				int y = list[x].get(j);
				if(--inDegree[y] == 0)
					queue.add(y);
			}
		}
		
		for (int i = 1; i <= N; i++) {
			System.out.print(result[i]+" ");
		}
		
	}
}
