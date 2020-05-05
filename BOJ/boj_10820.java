import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

// 문자열 분석
public class boj_10820 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String str = null;
		
		while((str = br.readLine())!=null) {
			int lower = 0;
			int upper = 0;
			int num = 0;
			int space = 0;
			for (int i = 0; i < str.length(); i++) {
				char c = str.charAt(i);
				if(Character.isUpperCase(c))
					upper++;
				else if(Character.isLowerCase(c))
					lower++;
				else if(Character.isDigit(c))
					num++;
				else if(c == ' ')
					space++;
			}
			System.out.println(lower + " " + upper + " " + num+ " " + space + " ");
		}
	}
}
