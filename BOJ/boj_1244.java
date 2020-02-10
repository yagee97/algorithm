package not_solve;

import java.util.Arrays;
import java.util.Scanner;

//스위치 켜고 끄기
public class boj_1244 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		StringBuilder sb = new StringBuilder();
		int N = sc.nextInt();
		int[] switchArr = new int[N + 1];

		for (int i = 1; i <= N; i++) {
			switchArr[i] = sc.nextInt();
		}

		int student = sc.nextInt();

		for (int i = 0; i < student; i++) {
			int gender = sc.nextInt();
			int num = sc.nextInt();

			// 남학생일 경우
			if (gender == 1) {
				for (int j = 1; j < switchArr.length; j++) {
					if (j % num == 0) {
						if (switchArr[j] == 0) {
							switchArr[j] = 1;
						} else {
							switchArr[j] = 0;
						}
					}
				}
			}

			// 여학생일 경우
			else if (gender == 2) {
				int cnt = 0;
				int next = num + 1;
				int pre = num - 1;
				while (true) {
					if (next >= N +1 || pre < 1) {
						// 바꾸는거 ?
						if (cnt > 0) {
							for (int k = pre + 1; k <= next - 1; k++) {
								if (switchArr[k] == 0)
									switchArr[k] = 1;
								else
									switchArr[k] = 0;
							}
						}else if (cnt == 0) {
							if (switchArr[num] == 0) {
								switchArr[num] = 1;
							} else {
								switchArr[num] = 0;
							}
						}
						break;
					}
					else if (switchArr[next] == switchArr[pre]) {
						cnt++;
						next++;
						pre--;
					} else if (switchArr[next] != switchArr[pre]) {
						if (cnt > 0) {
							for (int k = pre+1; k <= next-1; k++) {
								if (switchArr[k] == 0)
									switchArr[k] = 1;
								else
									switchArr[k] = 0;
							}
						} else if (cnt == 0) {
							if (switchArr[num] == 0) {
								switchArr[num] = 1;
							} else {
								switchArr[num] = 0;
							}
						}
						break;
					}
				}
			}

		}
		
		for (int t = 1; t < switchArr.length; t++) {
			System.out.print(switchArr[t] + " ");
			if (t % 20 == 0)
				System.out.println();
		}

	}
}