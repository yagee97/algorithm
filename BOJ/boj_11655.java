import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

// ROT13
public class boj_11655 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String original = br.readLine();
		StringBuilder sb = new StringBuilder();

		for (int i = 0; i < original.length(); i++) {
			char c = original.charAt(i);
			if (Character.isAlphabetic(c)) {
				if (Character.isLowerCase(c)) {
					if (c + 13 > 'z') {
						c = (char) (c + 13 - 26);
					} else
						c = (char) (c + 13);
				}else if(Character.isUpperCase(c)) {
					if(c+13 > 'Z') {
						c = (char)(c + 13 - 26);
					}else
						c = (char)(c+13);
				}
			}
			sb.append(c);
		}
		System.out.println(sb.toString());

	}
}
