import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

//탈출
class Pos {
	int x, y;

	public Pos(int x, int y) {
		this.x = x;
		this.y = y;
	}
}

public class boj_3055 {
	static int R, C, sx, sy;
	static char[][] map;
	static boolean[][] chk;
	static Queue<Pos> devil;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		R = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());
		map = new char[R][C];
		chk = new boolean[R][C];
		devil = new LinkedList<Pos>();

		for (int i = 0; i < R; i++) {
			String str = br.readLine();
			for (int j = 0; j < str.length(); j++) {
				map[i][j] = str.charAt(j);
				if (map[i][j] == '*') {
					devil.add(new Pos(i, j));
				} else if (map[i][j] == 'S') {
					sx = i;
					sy = j;
				}
			}
		}
		int ans = bfs(sx,sy);
		if(ans == -1)
			System.out.println("KAKTUS");
		else
			System.out.println(ans);
	}

	static int[] dx = { -1, 0, 1, 0 };
	static int[] dy = { 0, 1, 0, -1 };
	static int time = 0;
	static int bfs(int sx, int sy) {
		Queue<Pos> q = new LinkedList<>();
		q.add(new Pos(sx, sy));
		chk[sx][sy] = true;

		while (!q.isEmpty()) {
			time++;
			int ds = devil.size();
			for (int qs = 0; qs < ds; qs++) {
				Pos p = devil.poll();
				for (int i = 0; i < 4; i++) {
					int nx = p.x + dx[i];
					int ny = p.y + dy[i];
					if (nx < 0 || ny < 0 || nx >= R || ny >= C)
						continue;
					if (map[nx][ny] == '.') {
						map[nx][ny] = '*';
						devil.add(new Pos(nx, ny));
					}
				}
			}
			
			int ss = q.size();
			for(int qs = 0;qs < ss;qs++) {
				Pos p = q.poll();
				for(int i = 0;i<4;i++) {
					int nx = p.x+dx[i];
					int ny = p.y +dy[i];
					if(nx < 0 || ny < 0 || nx >= R || ny >= C)
						continue;
					if(map[nx][ny] == 'D') {
						return time;
					}
					if(map[nx][ny] == '*')
						continue;
					if(!chk[nx][ny] && map[nx][ny] == '.') {
						q.add(new Pos(nx,ny));
						chk[nx][ny] = true;
					}
				}
			}
			
		}
		return -1;
	}
}
