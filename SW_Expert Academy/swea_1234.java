import java.util.Scanner;
import java.util.Stack;
//비밀번호
public class swea_1234 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		Stack<Integer> stack = new Stack<>();
	
		for (int tc = 1; tc <= 10; tc++) {
            StringBuilder sb = new StringBuilder();
			int N = sc.nextInt();
			String input = sc.next();
			for(int i = 0;i<input.length();i++) {
				int num = input.charAt(i)-'0';
				if(i==0 || stack.isEmpty()) {
					stack.push(num);
					continue;
				}
				if(!stack.isEmpty() && stack.peek() != num) {
					stack.push(num);
				}else if(!stack.isEmpty() && stack.peek() == num) {
					stack.pop();
				}
			}
			int[] ret = new int[stack.size()];
			int idx = 0;
			while(!stack.isEmpty()) {
				ret[idx++] = stack.pop();
			}
			sb.append("#"+tc+" ");
			for(int i = ret.length-1;i>=0;i--)
				sb.append(ret[i]);
			
			System.out.println(sb.toString());
			
		}
	}
}