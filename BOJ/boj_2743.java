import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

// 단어길이재기
public class boj_2743 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String input = br.readLine();
		System.out.println(input.length());
	}
}
