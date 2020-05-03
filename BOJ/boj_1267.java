import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

// 핸드폰 요금
public class boj_1267 {
	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;

		int N = Integer.parseInt(br.readLine());
		int[] arr = new int[N];
		st = new StringTokenizer(br.readLine());

		for (int i = 0; i < N; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}

		int Ytotal = 0, Mtotal = 0;
		for (int i = 0; i < N; i++) {
			// 영식
			int cnt = 0;
			if (arr[i] < 30)
				Ytotal += 10;
			else {
				cnt = (arr[i] / 30) + 1;
				Ytotal += cnt * 10;
			}

			// 민식
			if (arr[i] < 60)
				Mtotal += 15;
			else {
				cnt = (arr[i] / 60) + 1;
				Mtotal += 15 * cnt;
			}
		}
		if (Ytotal < Mtotal) {
			System.out.println("Y " + Ytotal);
		} else if (Ytotal > Mtotal) {
			System.out.println("M " + Mtotal);
		} else {
			System.out.println("Y M " + Ytotal);
		}

	}
}
