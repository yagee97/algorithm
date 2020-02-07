import java.util.LinkedList;
import java.util.Scanner;

public class boj_2635 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		LinkedList<Integer> result = new LinkedList<>();
		StringBuilder sb = new StringBuilder();
		
		int max = 0;
		int N = sc.nextInt();

		for (int i = N; i >= N / 2; i--) {
			int tmp = N;
			int num = i;
			LinkedList<Integer> number = new LinkedList<>();
			number.add(tmp);
			number.add(i);
			while(true) {
				int next = tmp - num;
				if(next >= 0) {
					number.add(next);
				}else {
					break;
				}
				tmp = num;
				num = next;
			}
			if(max < number.size()) {
				max = number.size();
				result = number;
			}
		}
		sb.append(max+"\n");
		for(int i = 0;i<result.size();i++)
			sb.append(result.get(i)+" ");

		System.out.println(sb.toString());
	}
}
