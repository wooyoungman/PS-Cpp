
import java.util.*;
import java.io.*;
public class Main {

	static int[][] map;
	static int N,M;
	static int [] dx = {0,0,1,-1};
	static int [] dy = {1,-1,0,0};
	static int [][] visited;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		map = new int [N+1][M+1]; // 배열 생성
		visited = new int[N+1][M+1];
		for(int i=0;i<N;i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0;j<M;j++) {
				map[i][j]=Integer.parseInt(st.nextToken());
			}
		}
	
		bfs(0,0);
		
	}
	public static void bfs(int _x, int _y) {
		// TODO Auto-generated method stub
		
		// 우선순위 큐를 써야 중복하여 지나는 길까지 기다렸다가 중복되는 횟수를 더하고 탐색을 다시 시작할 수 있다.
		Queue<int[]> queue = new PriorityQueue<>((a,b)->Integer.compare(b[0], a[0]));
		queue.offer(new int[] {map[_x][_y],_x,_y});
		visited[_x][_y]=1;
		
		while(!queue.isEmpty()) {
			int cur[]=queue.poll();
			for(int i=0;i<4;i++) {
				int next_x=cur[1]+dx[i];
				int next_y=cur[2]+dy[i];
				// 현재 높이와 다음 높이 비교 
				if(next_x>=0&&next_x<N&&next_y>=0&&next_y<M) {
					int cur_high=cur[0];
					int next_high=map[next_x][next_y];
					if(cur_high>next_high)
					{
						if(visited[next_x][next_y]==0) {
							queue.offer(new int[] {map[next_x][next_y],next_x,next_y});	
						}
						visited[next_x][next_y]+=visited[cur[1]][cur[2]];

					}

				}
			}
		}
		System.out.println(visited[N-1][M-1]);

	}
	
}
