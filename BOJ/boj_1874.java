import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

// 스택 수열
public class boj_1874 {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int N = Integer.parseInt(br.readLine());
		int[] arr = new int[N];
		Stack<Integer> stack = new Stack<>();
		StringBuilder sb = new StringBuilder();

		for (int i = 0; i < N; i++) {
			arr[i] = Integer.parseInt(br.readLine());
		}

		int idx = 1;
		for (int i = 0; i < N; i++) {
			while(idx <= arr[i]) {
				stack.push(idx++);
				sb.append("+").append("\n");
			}
			
			if(stack.peek() == arr[i]) {
				sb.append("-").append("\n");
				stack.pop();
			}else {
				System.out.println("NO");
				return;
			}
		}
		System.out.println(sb.toString());
	}
}
