import java.util.Scanner;

public class swea_수도요금경쟁 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int T = sc.nextInt();
		for (int tc = 1; tc <= T; tc++) {
			int P, Q, R, S, W;
			P = sc.nextInt();
			Q = sc.nextInt();
			R = sc.nextInt();
			S = sc.nextInt();
			W = sc.nextInt();

			int Apay = 0, Bpay = 0;
			Apay = W * P;
			if (W <= R)
				Bpay = Q;
			else
				Bpay = (W-R) * S + Q;

			int ret = 0;
			if (Apay > Bpay)
				ret = Bpay;
			else if (Apay < Bpay)
				ret = Apay;
			
			System.out.println("#"+tc+" "+ret);
		}
	}
}
