//최빈수 구하기
package swea_200122;

import java.util.Scanner;

public class swea_1204 {
	public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
 
        for (int tc = 1; tc <= T; tc++) {
            int maxValue = 0, maxIdx = 0;
            int t_num = sc.nextInt();
            int[] fre = new int[1001];
            for (int i = 0; i < 1000; i++) {
                int tmp = sc.nextInt();
                fre[tmp]++;
                if(maxValue <= fre[tmp]) {
                    maxValue = fre[tmp];
                    maxIdx = tmp;
                }
            }
             
            System.out.println("#"+tc+" "+maxIdx);
        }
    }
}
