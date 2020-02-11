import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Scanner;

public class Jongol_냉장고 {
	static class Info implements Comparable<Info> {
		int low, high;

		public Info(int low, int high) {
			this.low = low;
			this.high = high;
		}

		public int getLow() {
			return low;
		}

		public int getHigh() {
			return high;
		}

		@Override
		public int compareTo(Info i) {
			if (this.high > i.getHigh()) {
				return 1;
			} else if (this.high < i.getHigh()) {
				return -1;
			}
			return 0;
		}
	}

	public static void main(String[] args) throws FileNotFoundException {
		System.setIn(new FileInputStream("res/input.txt"));
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();

		LinkedList<Info> re = new LinkedList<>();

		for (int i = 0; i < N; i++) {
			int low = sc.nextInt();
			int high = sc.nextInt();
			re.add(new Info(low, high));
		}

		Collections.sort(re);
		for(int i = 0;i<re.size();i++)
			System.out.println(re.get(i).low + " "+ re.get(i).high);
		
		int cnt = 1;
		int max = 0;
		for (int i = 0; i < re.size(); i++) {
			Info info = re.get(i);
			int curLow = info.low;
			int curHigh = info.high;
			
			if(i == 0) {
				max = curHigh;
				continue;
			}
			//범위안에 있으면
			if(max >= curLow) {
				if(max > curHigh) {
					max = curHigh;
				}
				continue;
			}else {
				cnt++;
				max = curHigh;
			}
		}
		System.out.println(cnt);
	}
}
