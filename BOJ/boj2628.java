import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

//종이자르기
public class boj2628 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int R = sc.nextInt();
		int C = sc.nextInt();
		int N = sc.nextInt();

		ArrayList<Integer> garo = new ArrayList<>();
		ArrayList<Integer> sero = new ArrayList<>();

		garo.add(0);
		sero.add(0);
		
		for (int i = 0; i < N; i++) {
			int type = sc.nextInt();
			int num = sc.nextInt();
			if (type == 0)
				garo.add(num);
			else
				sero.add(num);
		}
		garo.add(C);
		sero.add(R);
		
		// 어레이리스트 정렬은 collections를 import해야함
		Collections.sort(garo);
		Collections.sort(sero);

		int width = 0;
		for (int i = 1; i < garo.size(); i++) {
			int diff = garo.get(i) - garo.get(i-1);
			if(diff > width) {
				width = diff;
			}
		}

		int height = 0;
		for (int i = 1; i < sero.size(); i++) {
			int diff = sero.get(i) - sero.get(i-1);
			if(diff > height) {
				height = diff;
			}
		}
		System.out.println(width * height);

	}
}
