import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
 
public class swea_4366 {
 
    static String binary, tenary;
    static int two[];
    static int three[];
    static ArrayList<Integer> bin, ten;
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
 
        for (int tc = 1; tc <= T; tc++) {
            binary = br.readLine();
            tenary = br.readLine();
            bin = new ArrayList<>();
             
            two = new int[binary.length()];
            three = new int[tenary.length()];
 
            for (int i = 0; i < binary.length(); i++) {
                two[i] = binary.charAt(i) - '0';
            }
            for (int i = 0; i < tenary.length(); i++) {
                three[i] = tenary.charAt(i) - '0';
            }
             
            System.out.println("#" + tc + " " + Solution());
        }
    }
 
    private static int Solution() {
        int[] temp2 = new int[binary.length()];
        int[][] temp3 = new int[tenary.length()][2];
 
        for (int i = 0; i < binary.length(); i++) {
            int twoCopy[] = two.clone();
            if (two[i] == 0)
                twoCopy[i] = 1;
            else
                twoCopy[i] = 0;
             
            temp2[i] = sol(twoCopy,2);
        }
 
        for (int i = 0; i < tenary.length(); i++) {
         
            int threeCopy[] = three.clone();
             
            for (int j = 0; j < 2; j++) {
                 
                if (threeCopy[i] == 0)
                     
                    threeCopy[i] = 1;
                 
                else if (threeCopy[i] == 1)
                     
                    threeCopy[i] = 2;
                 
                else
                    threeCopy[i] = 0;
                 
                temp3[i][j] = sol(threeCopy,3);
            }
        }
        for (int i = 0; i < binary.length(); i++) {
            for (int j = 0; j < tenary.length(); j++)
                for (int cnt = 0; cnt < 2; cnt++)
                    if (temp2[i] == temp3[j][cnt])
                        return temp2[i];
        }
        return -1;
    }
 
    public static int sol(int[] twoCopy, int baseType) {
        int ret = 0;
 
        for (int i = 0; i < twoCopy.length; i++) {
            ret += Math.pow(baseType, twoCopy.length - 1 - i) * twoCopy[i];
        }
        return ret;
    }
}