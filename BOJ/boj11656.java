import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;

// 접미사 배열
public class boj11656 {
	public static void main(String[] args) throws IOException {
		BufferedReader br=  new BufferedReader(new InputStreamReader(System.in));
		String str = br.readLine();
		ArrayList<String> list = new ArrayList<>();
		
		// for문돌리면서 substring만들어서 list에 저장하고 정렬
		for (int i = 0; i < str.length(); i++) {
			String str2 = str.substring(i);
			list.add(str2);
		}
		Collections.sort(list);
		for (int i = 0; i < list.size(); i++) {
			System.out.println(list.get(i));
		}
	}
}
