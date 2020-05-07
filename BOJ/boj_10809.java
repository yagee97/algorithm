import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

// 알파벳 찾기
public class boj_10809 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String str = br.readLine();
		
		char[] alpha = new char[26];
		int[] ret = new int[26];
		Arrays.fill(ret, -1);
		
		for (char c = 'a'; c <= 'z'; c++) {
			alpha[c-97] = c;
		}
		
		for (int i = 0; i < str.length(); i++) {
			char c = str.charAt(i);
			for (int j = 0; j < alpha.length; j++) {
				if(c == alpha[j] && ret[j]==-1) {
					ret[j] = i;
				}
			}
		}
		for (int i = 0; i < ret.length; i++) {
			System.out.print(ret[i] + " ");
		}
		System.out.println();
	}
}
