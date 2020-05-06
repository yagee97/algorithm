import java.util.Scanner;

public class boj_10845 {

    static int[][] map;
    static int[] answer;
    static int[][] result;
    static int[] team1 = { 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 3, 3, 4 };
    static int[] team2 = { 1, 2, 3, 4, 5, 2, 3, 4, 5, 3, 4, 5, 4, 5, 5 };

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        map = new int[6][3];
        answer = new int[4];
        result = new int[6][3];

        for (int k = 0; k < 4; k++) {
            for (int i = 0; i < 6; i++) {
                for (int j = 0; j < 3; j++) {
                    map[i][j] = sc.nextInt();
                }
            }
            dfs(k, 0);
        }

        for (int x : answer)
            System.out.print(x + " ");
        System.out.println();

    }
    
    static void dfs(int num, int game) {
        if (game == 15) { 
            if (answer[num] != 1) {
                for (int i = 0; i < 6; i++) {
                    for (int j = 0; j < 3; j++)
                        if (map[i][j] != result[i][j])
                            return;
                }

                answer[num] = 1; 
                return;

            } else
                return;
        }


        int t1 = team1[game];
        int t2 = team2[game];

        // 모든 경우
        result[t1][0]++;        
        result[t2][2]++;
        dfs(num, game + 1);
        result[t1][0]--;       
        result[t2][2]--;

        result[t1][1]++;        
        result[t2][1]++;
        dfs(num, game + 1);
        result[t1][1]--;        
        result[t2][1]--;

        result[t1][2]++;        
        result[t2][0]++;
        dfs(num, game + 1);
        result[t1][2]--;        
        result[t2][0]--;

    }

}