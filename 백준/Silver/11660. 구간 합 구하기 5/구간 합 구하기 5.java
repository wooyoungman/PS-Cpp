//package b11660;

import java.util.*;
import java.io.*;
public class Main {

	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		
		// 먼저 2차원 구간 합 배열의 1행,1열부터 구한다. 
		// 이를 통해 나머지 2차원 구간 합 배열을 채운다.
		// 이 때 계산하다보면 i-1, j-1에서 중복된 값이 생기는데 이를 빼주어야 한다.
		// 따라서 공식은 D[i][j] = D[i][j-1] + D[i-1][j] - D[i-1][j-1] + A[i][j] 
		// 이제 입력으로 주어지는 (x1,y1)부터 (x2,y2)까지의 합을 구하려면
		// D[x2][y2] - D[x1-1][y2] - D[x2][y1-1] + D[x1-1][y1-1]
		
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		
		int A[][]= new int[N+1][N+1];
		int D[][]= new int[N+1][N+1];
		
		// 원본 배열 저장
		for(int i=1;i<=N;i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=1;j<=N;j++) {
				A[i][j]=Integer.parseInt(st.nextToken());
			}
		}
		
		// 합 배열 저장
		for(int i=1;i<=N;i++) {
			for(int j=1;j<=N;j++) {
				D[i][j]=D[i-1][j]+D[i][j-1]-D[i-1][j-1]+A[i][j];
			}
		}
		
		
		for(int i=0;i<M;i++) {
			st = new StringTokenizer(br.readLine());
			int x1 = Integer.parseInt(st.nextToken());

			int y1 = Integer.parseInt(st.nextToken());

			int x2 = Integer.parseInt(st.nextToken());

			int y2 = Integer.parseInt(st.nextToken());
			
			int res = D[x2][y2] - D[x1-1][y2] - D[x2][y1-1] + D[x1-1][y1-1];
			System.out.println(res);
		}
		
		
	}

}
