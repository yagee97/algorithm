// 덱
package BOJ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Deque;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class boj_10866 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;
		Deque<Integer> deque = new LinkedList<Integer>();

		int N = Integer.parseInt(br.readLine());
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			String dStr = null;
			int data = 0;
			if (st.countTokens() >= 2) {
				dStr = st.nextToken();
				data = Integer.parseInt(st.nextToken());
			} else
				dStr = st.nextToken();

			if (dStr.equals("push_front")) {
				// 정수를 덱의 앞에 넣는다.
				deque.addFirst(data);
			} else if (dStr.equals("push_back")) {
				deque.addLast(data);
			} else if (dStr.equals("pop_front")) {
				if (deque.isEmpty())
					System.out.println("-1");
				else
					System.out.println(deque.pollFirst());
			} else if (dStr.equals("pop_back")) {
				if (deque.isEmpty())
					System.out.println("-1");
				else
					System.out.println(deque.pollLast());
			} else if (dStr.equals("size")) {
				System.out.println(deque.size());
			}else if(dStr.equals("empty")) {
				if(deque.isEmpty()) {
					System.out.println("1");
				}else
					System.out.println("0");
			}else if(dStr.equals("front")) {
				if (deque.isEmpty()) {
					System.out.println("-1");
				}else
					System.out.println(deque.peekFirst());
			}else if(dStr.equals("back")) {
				if(deque.isEmpty()) {
					System.out.println("-1");
				}else
					System.out.println(deque.peekLast());
			}

		}

	}
}
