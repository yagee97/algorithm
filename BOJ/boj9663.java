import java.util.Scanner;

public class boj9663 {
	static int N;
	static int cnt;
	static int[] col;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();

		for (int i = 1; i <= N; i++) {
			//ù��° ������ ���� �ϳ��� �����鼭 dfs ������. 
			//���� �ٽ� ���� ���� dfs�� �ѹ� �����ű� ������ col�� �ٽ�  �ʱ�ȭ������Ѵ�.
			col = new int[N + 1];
			col[1] = i;//�� ����
			dfs(1);
		}
		System.out.println(cnt);
	}

	static void dfs(int row) {
		if (row == N) {//�� N�� �� ��������
			cnt++;//ī��Ʈ �ø���
			return;
		} else {
			//1������ n������ �ݺ��ϸ鼭 row+1,i �� ���� ���� �� �ִ��� Ȯ��
			for (int i = 1; i <= N; i++) {
				col[row + 1] = i;// ����
				if (isPossible(row + 1)) {
					dfs(row + 1);
				}
			}
		}
	}

	static boolean isPossible(int row) {
		for (int i = 1; i < row; i++) {
			if (col[i] == col[row])
				return false;
			if (Math.abs(i - row) == Math.abs(col[i] - col[row]))
				return false;
		}
		return true;
	}
}
