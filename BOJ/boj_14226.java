// 이모티콘
package BOJ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class boj_14226 {
	static int S;// 이모티콘 개수
	static int monitor = 0, clip = 0;
	static boolean[][] visited;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		S = Integer.parseInt(br.readLine());
		visited = new boolean[2002][2002];
		
		Queue<Info> q = new LinkedList<Info>();
		q.add(new Info(1,0));
		visited[1][0] = true;
		int time =0;
		while(!q.isEmpty()) {
			int qs = q.size();
			
			while(qs-- > 0) {
				Info info = q.poll();
				int cnt = info.cnt;
				int clip = info.clip;
				
				if(cnt == S) {
					System.out.println(time);
					return;
				}
				
				//1번. 화면=>클립. 덮어쓰기
				q.add(new Info(cnt, cnt));
				
				//2번. 클립 => 화면. 비어있으면 안돼
				if(clip!=-1) {
					
					int len = cnt+clip;
					// 길이가 1000이 넘어가거나, 지금 이 클립보드 상태+모니터상태를 와본적이 없다면!
					if(!visited[len][clip] && len <= 1000)
						q.add(new Info(len, clip));
					visited[len][clip] = true;
				}
				
				//3번 하나 삭제
				if(!visited[cnt-1][clip] && cnt-1 > 1)
					q.add(new Info(cnt-1, clip));
			}
			time++;
		}
		System.out.println(time);
		
	}
	
}

class Info{
	int cnt, clip;
	public Info(int cnt, int clip) {
		this.cnt = cnt;
		this.clip = clip;
	}
}
