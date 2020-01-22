//원재의 메모리 복구하기
package swea_200122;

import java.util.Scanner;

public class swea_1289 {
	static String input;
    static int[] arr = new int[51];
    static int[] init = new int[51];
 
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for (int tc = 1; tc <= T; tc++) {
            input = sc.next();
            for (int i = 0; i < input.length(); i++) {
                arr[i] = input.charAt(i) - '0';
                init[i] = 0;
            }
            int cnt = 0;
            for (int cursor = 0; cursor < input.length(); cursor++) {
                if (arr[cursor] != init[cursor]) {
                    cnt++;
                    for (int i = cursor; i < input.length(); i++) {
                        init[i] = arr[cursor];
                    }
                }
            }
            System.out.println("#"+tc+" "+cnt);
        }
    }
}
