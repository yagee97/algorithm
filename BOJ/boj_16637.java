import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

//괄호 추가하기
public class boj_16637 {
	static int N;
	static char[] map;

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		map = br.readLine().toCharArray();// good

		//1부터 시작하는 이유는 연산자가 두번째부터 나오기 때문
		dfs(1, map[0] - '0', 0, false);
		System.out.println(max);

	}

	static int max = Integer.MIN_VALUE;

	public static void dfs(int idx, int val, int preVal, boolean flag) {
		if (idx == N) {
			// 최대값 갱신
			max = Math.max(max, val);
			return;
		}

		// 현재 인덱스에 괄호를 치지 않는다.
		// idx+2는 다음 연산자를 나타냄. cal로 그 연산자가 속한 연산식을 계산해서 값 넘김. 
		//3+8*7-9*2에서 +가진 식에 괄호 안칠꺼면, 3+8을 계산해서 다음의 피연산자로 넘긴다는 것. 
		dfs(idx + 2, cal(val, map[idx], map[idx + 1] - '0'), val, false);
		
		//괄호를 추가해도 되는 자리면 추가한다
		if(idx > 1 && !flag) {
			//이전에 계산 안된 값이랑 그 연산자를 가지고 괄호안에 있는 연산식을 계산한 값과 연산을 한다. 
			dfs(idx+2, cal(preVal, map[idx-2], cal(map[idx-1]-'0', map[idx],map[idx+1]-'0')),0,true);
		}

	}

	public static int cal(int a, char op, int b) {
		if (op == '+')
			return a + b;
		else if (op == '-')
			return a - b;
		else
			return a * b;
	}
}
