import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

// 큐
public class boj_10845 {
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;
		
		int N = Integer.parseInt(br.readLine());
		Queue<Integer> queue = new LinkedList<Integer>();
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			String d = null;
			int data = 0;
			
			if(st.countTokens() >= 2) {
				d = st.nextToken();
				data = Integer.parseInt(st.nextToken());
			}
			else {
				d = st.nextToken();
			}
			
			if(d.equals("push")) {
				queue.add(data);
			}else if(d.equals("pop")) {
				if(!queue.isEmpty()) 
					System.out.println(queue.poll());
				else
					System.out.println("-1");
			}else if(d.equals("size")) {
				System.out.println(queue.size());
			}else if(d.equals("empty")) {
				if(!queue.isEmpty())
					System.out.println("0");
				else
					System.out.println("1");
			}else if(d.equals("front")) {
				if(queue.isEmpty())
					System.out.println("-1");
				else
					System.out.println(queue.peek());
			}else if(d.equals("back")) {
				if(queue.isEmpty())
					System.out.println("-1");
				else {
					int tmp = 0;
					int size = queue.size();
					for (int j = 0; j < size; j++) {
						tmp = queue.poll();
						queue.add(tmp);
					}
					System.out.println(tmp);
					
				}
			}
		}
	}
}
