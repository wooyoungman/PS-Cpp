
import java.io.*;
import java.util.*;
public class Main {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		Stack<Integer> stack=new Stack<Integer>();
		int cnt=1;
		int now=0;
		for(int i=0;i<n;i++)
		{
			st = new StringTokenizer(br.readLine());
			int v = Integer.parseInt(st.nextToken());
			stack.push(v);
		}
		int std=stack.pop();
		while(!stack.isEmpty()) {
			now=stack.pop();
			if(now>std) {
				std=now;
				cnt++;
			}
		}
		System.out.print(cnt);
	}

}
