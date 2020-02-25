import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class boj1068 {
	static int N;
	static ArrayList<Integer>[] list;
	static int cnt = 0;
	static int[] parent;
	static boolean[] check;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		N = sc.nextInt();
		check = new boolean[N];
		parent = new int[N];

		list = new ArrayList[N+1];
		for (int i = 0; i < N; i++) {
			list[i] = new ArrayList<>();
		}

		for (int i = 0; i < N; i++) {
			int num = sc.nextInt();
			// �θ�����
			parent[i] = num;
		}
		int root = 0;
		for (int i = 0; i < N; i++) {
			int v = parent[i];
			if (v == -1) {
				// -1�� �ڿ� ���ü��� �ִ�.
				root = i;
				continue;
			}
			list[v].add(i);
			list[i].add(v);
		}

		int remove = sc.nextInt();
		//bfs�� �ι��ϸ鼭 �ѹ��� ����°� �ѹ��� root�� �������� leaf��� Ž��
		bfs(remove);
		System.out.println(bfs(root));

	}

	public static int bfs(int num) {
		Queue<Integer> q = new LinkedList<>();
		int cnt = 0;

		if (check[num]) {
			return 0;
		}
		
		q.add(num);
		check[num] = true;
		
		while(!q.isEmpty()) {
			num = q.poll();
			boolean flag = false;
			
			for(int v : list[num]) {
				if (!check[v] && parent[num] != v) {
					// �湮���� �ʾҰ�, �θ������� ���� ������ ���� �ʴٸ� Ž��
					flag = true;
					q.add(v);
					check[v] = true;
				}
				
			}
			// ������ �������� Ž���� ���� ������ ��� �������.
			if (!flag) {
				cnt++;
			}
		}
		return cnt;
	}
}
