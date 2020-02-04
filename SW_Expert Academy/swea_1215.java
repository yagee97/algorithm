import java.util.Scanner;

public class swea_1215 {
	static Scanner sc  = new Scanner(System.in);
	
	public static void main(String[] args) {
		for(int tc=1; tc<=10; tc++) {
			int len = sc.nextInt();
			char[][] a = new char[8][8];
			
			for(int i=0; i<8; i++) {
				a[i] = sc.next().toCharArray();
			}
			
			int count = 0;
			for(int s=0; s<8-len+1; s++) {
				boolean flag;
				for(int i=0; i<8; i++) {
					flag = true;
					for(int j=0; j<len/2; j++) {
						if(a[i][s+j] != a[i][s+len-1-j]) {
							flag = false;
							break;
						}
					}
					if( flag ) count++;
					flag = true;
					for(int j=0; j<len/2; j++) {
						if(a[s+j][i] != a[s+len-1-j][i]) {
							flag = false;
							break;
						}
					}
					if( flag ) count++;
				}
			}
			System.out.format("#%d %d\n", tc, count);
		}
		sc.close();
	}
}