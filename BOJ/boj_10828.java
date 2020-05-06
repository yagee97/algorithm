import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;

// 스택
public class boj_10828 {
	static Stack<Integer> stack = new Stack<>();

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;
		StringBuilder sb = new StringBuilder();

		int N = Integer.parseInt(br.readLine());

		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			String D = null;
			int num = 0;
			if (st.countTokens() == 2) {
				D = st.nextToken();
				num = Integer.parseInt(st.nextToken());
			} else {
				D = st.nextToken();
			}
			if (D.equals("push")) {
				stack.push(num);
			} else if (D.equals("top")) {
				if (!stack.isEmpty())
					sb.append(stack.peek()).append("\n");
				else
					sb.append("-1").append("\n");
			} else if (D.equals("pop")) {
				if (!stack.isEmpty()) {
					sb.append(stack.pop()).append("\n");
				} else
					sb.append("-1").append("\n");
			} else if (D.equals("size")) {
				sb.append(stack.size()).append("\n");
			} else if (D.equals("empty")) {
				if (!stack.isEmpty()) {
					sb.append("0").append("\n");
				} else
					sb.append("1").append("\n");
			}
		}
		System.out.println(sb.toString());
	}
}
