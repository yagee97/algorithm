import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

class Pos {
	int rx, ry, bx, by, cnt;

	public Pos(int rx, int ry, int bx, int by, int cnt) {
		this.rx = rx;
		this.ry = ry;
		this.bx = bx;
		this.by = by;
		this.cnt = cnt;
	}
}

//구슬탈출
public class boj_13459 {
	static int N, M;
	static char[][] map;
	static int Rx, Ry, Bx, By;
	static boolean[][][][] chk;
	static Queue<Pos> q = new LinkedList<Pos>();

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());

		map = new char[N][M];
		chk = new boolean[N][M][N][M];

		for (int i = 0; i < N; i++) {
			String str = br.readLine();
			for (int j = 0; j < str.length(); j++) {
				map[i][j] = str.charAt(j);
				// 빨간구슬 위치
				if (map[i][j] == 'R') {
					Rx = i;
					Ry = j;
					// 파란구슬 위치
				} else if (map[i][j] == 'B') {
					Bx = i;
					By = j;
				}
			}
		}
		bfs();
		if (flag)
			System.out.println("1");
		else
			System.out.println("0");
	}

	static int[] dx = { -1, 1, 0, 0 };
	static int[] dy = { 0, 0, -1, 1 };
	static boolean flag = false;

	public static void bfs() {

		q.add(new Pos(Rx, Ry, Bx, By, 0));
		chk[Rx][Ry][Bx][By] = true;
		while (!q.isEmpty()) {
			Pos p = q.poll();

			if (p.cnt > 10)
				break;
			if (map[p.rx][p.ry] == 'O' && map[p.bx][p.by] != 'O') {
				flag = true;
				break;
			}

			for (int i = 0; i < 4; i++) {
				int nrx = p.rx + dx[i];
				int nry = p.ry + dy[i];
				int nbx = p.bx + dx[i];
				int nby = p.by + dy[i];
				int disR = 0, disB = 0;// 같은 칸에 도달했을 때 더 늦게 도착한애를 한칸 뒤로 빼자

				// 빨간구슬 움직이기
				while (true) {
					if (map[nrx][nry] != '#' && map[nrx][nry] != 'O') {
						nrx += dx[i];
						nry += dy[i];
						disR++;
					} else {
						if (map[nrx][nry] == '#') {
							nrx -= dx[i];
							nry -= dy[i];
						}
						break;
					}

				}
				// 파랭이움직이기
				while (true) {
					if (map[nbx][nby] != '#' && map[nbx][nby] != 'O') {
						nbx += dx[i];
						nby += dy[i];
						disB++;
					} else {
						if (map[nbx][nby] == '#') {
							nbx -= dx[i];
							nby -= dy[i];
						}
						break;
					}
				}
				// 같은칸일때
				if (nrx == nbx && nry == nby) {
					if (map[nrx][nry] != 'O') {
						if (disR > disB) {
							nrx -= dx[i];
							nry -= dy[i];
						} else {
							nbx -= dx[i];
							nby -= dy[i];
						}
					}
				}

				if (map[nbx][nby] == 'O') {
					continue;
				} else if (!chk[nrx][nry][nbx][nby]) {
					chk[nrx][nry][nbx][nby] = true;
					q.add(new Pos(nrx, nry, nbx, nby, p.cnt + 1));
				}
			}
		}
	}
}
