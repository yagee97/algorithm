import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class boj1786 {
	static int pi[];
	static ArrayList<Integer> list;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String text = br.readLine();
		String pattern = br.readLine();
		list = new ArrayList<>();

		KMP(text, pattern);

		System.out.println(list.size());
		for (int i = 0; i < list.size(); i++)
			System.out.println(list.get(i));

	}

	private static int[] getPi(String pattern) {
		int[] pi = new int[pattern.length()];

		// idx
		int j = 0;
		// i랑j가 가리키는 값이 일치하면 둘다 증가
		// 불일치하면 i만 증가
		for (int i = 1; i < pattern.length(); i++) {
			// 점프
			while (j > 0 && pattern.charAt(i) != pattern.charAt(j)) {
				j = pi[j - 1];
			}
			if (pattern.charAt(i) == pattern.charAt(j)) {
				pi[i] = ++j;
			}
		}
		return pi;
	}

	private static void KMP(String parent, String pattern) {
		int[] table = getPi(pattern);
		int j = 0;
		for (int i = 0; i < parent.length(); i++) {
			while (j > 0 && parent.charAt(i) != pattern.charAt(j)) {
				j = table[j - 1];
			}
			if (parent.charAt(i) == pattern.charAt(j)) {
				if (j == pattern.length() - 1) {
					j = table[j];
					list.add(i - pattern.length() + 2);
				} else {
					j++;
				}
			}
		}
	}
}
