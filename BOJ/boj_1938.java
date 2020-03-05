import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

class Info {
	int x, y, dir, cnt;

	public Info(int x, int y, int dir, int cnt) {
		this.x = x;
		this.y = y;
		this.dir = dir;
		this.cnt = cnt;
	}
}

public class boj_1938 {
	static int N;
	static char[][] map;
	static boolean chk[][][];

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		map = new char[N][N];
		chk = new boolean[N][N][2];
		int mx = 0, my = 0, dir = 0;

		int flag = 0;
		for (int i = 0; i < N; i++) {
			String str = br.readLine();
			for (int j = 0; j < str.length(); j++) {
				map[i][j] = str.charAt(j);
				if (map[i][j] == 'B') {
					if (flag == 1) {
						mx = i;
						my = j;
						if (j > 0 && map[i][j -1] == 'B') {
							dir = 0;
						} else
							dir = 1;
						flag++;
					} else
						flag++;
				}
			}
		}
		int ans = bfs(mx, my, dir);
		System.out.println(ans);
	}

// 상하좌우  대각선
	static int[] dx = { -1, 1, 0, 0, -1, -1, 1, 1 };
	static int[] dy = { 0, 0, -1, 1, -1, 1, -1, 1 };

	// 회전가능한가?
	static boolean isRotate(int mx, int my) {
		for (int i = 0; i < 8; i++) {
			int nx = mx + dx[i];
			int ny = my + dy[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= N)
				return false;
			if (map[nx][ny] == '1')
				return false;
		}
		return true;

	}

	public static int bfs(int mx, int my, int d) {
		Queue<Info> q = new LinkedList<Info>();
		q.add(new Info(mx, my, d, 0));
		chk[mx][my][d] = true; 
		int ret = 0;
		
		while(!q.isEmpty()) {
			Info info = q.poll();
			int x = info.x;
			int y = info.y;
			int dir = info.dir;
			int cnt = info.cnt;
			
			//최소값 갱신조건 . 통나무 좌표랑 eee좌표랑 같으면.
			if(dir == 0 && y-1>= 0 && y+1 < N && map[x][y-1] == 'E' && map[x][y] == 'E' && map[x][y+1] == 'E') {
				ret = cnt;
				break;
			}else if(dir == 1 && x-1>= 0 && x+1 < N && map[x-1][y] == 'E' && map[x][y] == 'E' && map[x+1][y] == 'E') {
				ret = cnt;
				break;		
			}
			
			for(int k = 0;k<5;k++) {
				//회전
				if(k == 4) {
					if(isRotate(x,y)) {
						dir ^= 1;
						//회전을 하면, 중심은 그대로인데 방향이 바뀐다.
						if(!chk[x][y][dir]) {
							chk[x][y][dir] = true;
							q.add(new Info(x,y,dir, cnt +1));
						}
					}
				}else {
					for(int i = 0;i<4;i++) {
						int nx = x + dx[i];
						int ny = y + dy[i];
						if (nx < 0 || ny < 0 || nx >= N || ny >= N)
							continue;
						if (map[nx][ny] == '1' || chk[nx][ny][dir])
							continue;
						//각각 범위체크 해야함.
						//0은 가로 1은 세로
						if(dir == 0) {
							if(ny - 1 < 0 || ny + 1 >= N || map[nx][ny-1] == '1' || map[nx][ny+1] == '1')
								continue;
							chk[nx][ny][dir] = true;
							q.add(new Info(nx,ny,dir,cnt+1));
						}
						else if(dir == 1) {
							if(nx - 1 < 0 || nx + 1 >= N || map[nx-1][ny] == '1' || map[nx+1][ny] == '1')
								continue;
							chk[nx][ny][dir] = true;
							q.add(new Info(nx,ny,dir,cnt+1));
						}
					}
				}
			}
			
		}

		return ret;
	}
}
