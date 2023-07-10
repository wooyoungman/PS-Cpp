//package b11659;

import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int N = sc.nextInt();
		int M = sc.nextInt();
		int sum = 0;
		int cnt = 0;
		int arr[]= new int[N+1];
		int cnt_arr[]=new int[N+1];
		
		for(int i=1;i<=N;i++) {
			arr[i]=sc.nextInt();
			cnt +=arr[i];
			cnt_arr[i]=cnt;
		}
		
		for(int i=0;i<M;i++) {
			int a = sc.nextInt();
			int b = sc.nextInt();			
			System.out.println(cnt_arr[b]-cnt_arr[a-1]);
			sum=0;
		}
	}

}
