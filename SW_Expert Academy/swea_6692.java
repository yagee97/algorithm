import java.util.Scanner;
 
public class swea_6692 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for (int tc = 1; tc <= T; tc++) {
            int N = sc.nextInt();
            double ret = 0;
            for(int i = 0;i<N;i++) {
                double p = sc.nextDouble();
                double x = sc.nextDouble();
                ret += p*x;
            }
            System.out.format("#%d %6f",tc,ret);
        }
    }
}