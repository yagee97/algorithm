// 날짜 계산
package BOJ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_1476 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int oE = Integer.parseInt(st.nextToken());
		int oS = Integer.parseInt(st.nextToken());
		int oM = Integer.parseInt(st.nextToken());

		int year = 0;
		int E = 0, S = 0, M = 0;
		while(true) {
			year++;
			E++;
			S++;
			M++;
			if(E > 15) {
				E = 1;
			}
			if(S > 28) {
				S = 1;
			}if(M > 19) {
				M = 1;
			}
			if(oS == S && oM == M && oE == E)
				break;
			
		}
		System.out.println(year);
	}
}
