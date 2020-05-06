import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;

// 다리만들기2
public class boj_17472 {
	static int R, C;
	static int[][] map, graph;
	static int islandIdx; // 섬의 번호
	static int INF = Integer.MAX_VALUE;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		R = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());

		map = new int[R][C];
		for (int r = 0; r < R; r++) {
			st = new StringTokenizer(br.readLine());
			for (int c = 0; c < C; c++) {
				map[r][c] = Integer.parseInt(st.nextToken());
			}
		}

		// 섬에 번호 매기기
		islandIdx = 2;
		for (int r = 0; r < R; r++) {
			for (int c = 0; c < C; c++) {
				// 땅 발견하면 거기를 기점으로 BFS 탐색 --> 연결된 지점들을 표시
				if (map[r][c] == 1) {
					bfs(r, c); // 한번의 bfs => 섬하나 찾음
					islandIdx++;
				}
			}
		}

		// 그래프 초기화 하기
		graph = new int[islandIdx][islandIdx];
		// 각 섬간의 최단거리로 그래프를 구성할 계획 - 그래프의 값을 최대값으로 초기화
		for (int r = 2; r < islandIdx; r++) {
			Arrays.fill(graph[r], INF);
		}

		// 각 섬별로 거리(간선 가중치) 찾아보기
		for (int r = 0; r < R; r++) {
			for (int c = 0; c < C; c++) {
				if (map[r][c] > 1) {
					makeGraph(r, c);
				}
			}
		}

		System.out.println(prim());

	}

	private static int prim() {
		// 모든 vertex가 처음에 여기 들어있다가 탈출해야한다.
		PriorityQueue<vertex> notMstGroup = new PriorityQueue<>();

		// 연결 비용과 관련된 섬들의 정보를 관리할 배열
		vertex[] vertexes = new vertex[islandIdx];
		for (int i = 2; i < islandIdx; i++) {
			if (i == 2) {
				vertexes[i] = new vertex(i, 0);

			} else {
				vertexes[i] = new vertex(i, INF);
			}
			notMstGroup.offer(vertexes[i]);
		}

		int sum = 0;

		while (!notMstGroup.isEmpty()) {
			vertex front = notMstGroup.poll();

			if (front.cost == INF) {
				return -1;
			}
			sum += front.cost;

			for (int i = 2; i < islandIdx; i++) {
				vertex child = vertexes[i];
				// 아직 MST 요소가 아닌 녀석이라면...
				if (notMstGroup.contains(child)) {
					// 그래프에서 비용 조회, 현재 가지고 있는 것 보다 작으면 업데이트
					if (child.cost > graph[front.idx][i]) {
						child.cost = graph[front.idx][i];
						notMstGroup.remove(child);
						notMstGroup.offer(child);
					}

				}
			}

		}
		return sum;
	}

	private static void makeGraph(int row, int col) {

		// 내땅
		int base = map[row][col];
		for (int d = 0; d < dirs.length; d++) {
			// 무한루핑 -> 한 방향으로 쭉 가야해서
			for (int l = 1;; l++) {
				int nr = row + dirs[d][0] * l;
				int nc = col + dirs[d][1] * l;

				if (isIn(nr, nc)) {
					// 바다면 쭉간다
					if (map[nr][nc] == 0)
						continue;
					else if (map[nr][nc] == base)
						break;
					else {
						// 다리 생성
						if (l > 2) { // 다리길이 2이상
							// 양방향그래프로 만들기
							graph[map[nr][nc]][base] = graph[base][map[nr][nc]] = Math.min(graph[base][map[nr][nc]],
									l - 1);
						}
						break;
					}
				}
				// 영역 안에 없으면 그만
				else {
					break;
				}
			}
		}

	}

	static int[][] dirs = { { -1,0 }, { 1,0 }, { 0,-1 }, { 0,1 } };

	private static void bfs(int row, int col) {
		Queue<Point> queue = new LinkedList<>();
		queue.offer(new Point(row, col));
		// 방문표시 - map 자체에다가 islandIdx 로 한다
		map[row][col] = islandIdx;

		while (!queue.isEmpty()) {
			Point front = queue.poll();

			for (int i = 0; i < dirs.length; i++) {
				int nr = front.row + dirs[i][0];
				int nc = front.col + dirs[i][1];

				// map[nr][nc] == 1 => 아직 방문하지 않은 땅이라면!
				if (isIn(nr, nc) && map[nr][nc] == 1) {
					map[nr][nc] = islandIdx;
					queue.offer(new Point(nr, nc));
				}
			}
		}

	}

	static boolean isIn(int row, int col) {
		return 0 <= row && row < R && 0 <= col && col < C;
	}

	static class Point {
		int row, col;

		public Point(int row, int col) {
			this.row = row;
			this.col = col;
		}
	}

	static class vertex implements Comparable<vertex> {
		int idx, cost;

		public vertex(int idx, int cost) {
			this.idx = idx;
			this.cost = cost;
		}

		@Override
		public int compareTo(vertex o) {
			return Integer.compare(this.cost, o.cost);
		}
	}
}
