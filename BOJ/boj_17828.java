import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

//문자열 화폐
public class boj_17828 {
	static int N, X;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		X = Integer.parseInt(st.nextToken());

		// N자리를 모두 최대인 Z로 채웟는데도 X미만인경우
		// X가 N보다 작은경우
		if (26 * N < X || X < N) {
			System.out.println("!");
			return;
		}

		// 문자열 모두 A로 초기화
		char[] ret = new char[N];
		for (int i = 0; i < N; i++) {
			ret[i] = 'A';
		}
		// A로 채운값부터 일단 빼기
		X -= N;

		for (int i = N - 1; i >= 0 && X > 0; i--) {
			//A가 Z로 변하려면 25를 더해야하기때문에 기준이 25
			//X가 25보다 크면 해당자리는 Z로 만들고 다음 인덱스로 넘어감
			//X가 25보다 작으면 해당자리는 그 나머지가 해당하는 알파벳으로 만들고 넘어감
			//그럼 X가 0이되니까 종료
			int tmp = Math.min(X, 25);
			ret[i] += tmp;
			X -= tmp;
		}
		StringBuilder sb = new StringBuilder();
		for(int i = 0;i<N;i++)
			sb.append(ret[i]);
		System.out.println(sb.toString());
	}
}
