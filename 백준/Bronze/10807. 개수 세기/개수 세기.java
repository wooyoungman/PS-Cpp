
import java.io.*;
import java.util.*;

public class Main {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int []arr = new int[210];
		st = new StringTokenizer(br.readLine());
		for(int i=0;i<n;i++) {
			int v = Integer.parseInt(st.nextToken());
			arr[v+100]++;
		}
		st = new StringTokenizer(br.readLine());
		int f=Integer.parseInt(st.nextToken());
		System.out.print(arr[f+100]);
	}

}
