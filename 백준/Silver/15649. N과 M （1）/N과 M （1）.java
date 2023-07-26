
import java.util.*;

public class Main {

	static int[] arr;
	static int m;
	static int[] ans;
	static boolean[] check;
	
	
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner sc = new Scanner(System.in);
		
		int N = sc.nextInt();
		int M = sc.nextInt();
		m=M;
		arr = new int[N];
		check = new boolean[arr.length];
		ans = new int[m];
		for(int i=0;i<N;i++) {
			arr[i]=i+1;
		}
		
		recur(0);
		
	}



	private static void recur(int depth) {
		// TODO Auto-generated method stub
		
		// 종료 조건
		if(depth==m) {
			PrintAns();
			return;
		}
		
		// 처리 코드
		for(int i=0;i<arr.length;i++) {
			if(!check[i]) {
				ans[depth]=arr[i];
				check[i]=true;
				recur(depth+1);
				check[i]=false;
			}
		}
		 
	}



	private static void PrintAns() {
		// TODO Auto-generated method stub
		for(int i :ans) {
			System.out.print(i+" ");
		}
		System.out.println();
	}

}
