//2072. 홀수만 더하기
package Swea;

import java.util.Scanner;

public class swea_2072 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
 
        int test = sc.nextInt();
        for (int tc = 1; tc <= test; tc++) {
            int sum = 0;
            for (int i = 0; i < 10; i++) {
                int num = sc.nextInt();
                if (num % 2 != 0)
                    sum += num;
            }
            System.out.println("#"+tc+" "+sum);
        }
         
    }
}