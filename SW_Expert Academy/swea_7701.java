import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;

// 염라대왕의 이름 정렬
public class swea_7701{
	static int N;
	static ArrayList<String> name;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		for (int tc = 1; tc <= T; tc++) {
			StringBuilder sb = new StringBuilder();
			sb.append("#"+tc+"\n");
			N = Integer.parseInt(br.readLine());
			name = new ArrayList<>();
			for (int i = 0; i < N; i++) {
				name.add(br.readLine());
			}
			
			// 길이대로 정렬
			Collections.sort(name, new Comparator<String>() {
				@Override
				public int compare(String arg0, String arg1) {
					if (arg0.length() > arg1.length()) 
						return 1;
					else if (arg0.length() < arg1.length()) 
						return -1;
					return arg0.compareTo(arg1);
				}
			});

			String tmp = "";
			for(int i = 0;i<name.size();i++) {
				if(!tmp.equals(name.get(i))) {
					sb.append(name.get(i)+"\n");
					tmp = name.get(i);
				}
			}
			System.out.print(sb.toString());
		}
	}
}