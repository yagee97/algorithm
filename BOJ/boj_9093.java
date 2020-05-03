import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;

// 단어 뒤집기
public class boj_9093 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N= Integer.parseInt(br.readLine());
		
		for (int tc = 0; tc < N; tc++) {
			StringBuilder sb = new StringBuilder();
			StringBuilder ret = new StringBuilder();
			String original = br.readLine();
			
			for (int i = 0; i < original.length(); i++) {
				char c = original.charAt(i);
				if(c != ' ') {
					sb.append(c);
				}
				else if(c == ' ') {
					String str = reverse(sb.toString());
					ret.append(str+" ");
					sb = new StringBuilder();
				}
				if(i == original.length()-1) {
					String str = reverse(sb.toString());
					ret.append(str);
				}
				
			}
			System.out.println(ret.toString());
		
		}
		
	}
	
	private static String reverse(String str) {
		return new StringBuffer(str).reverse().toString();
	}
}
