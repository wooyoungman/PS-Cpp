import java.util.*;
import java.io.*;

public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int N=sc.nextInt();
		int start=1;
		int end=1;
		int sum=1;
		int cnt=1;
		
		while(N!=end) {
			// 현재 누적 합이 N과 같다면 end를 증가
			if(sum==N) {
				cnt++;
				end++;
				sum+=end;
			}
			// 현재 누적 합이 N보다 크다면 현재 sum에서 start 제거 후 start만 +1
			else if(sum>N) {
				sum-=start;
				start++;
			}
			// 현재 누적 합이 N보다 작다면 end+1 후 sum에 end 추가
			else
			{
				end++;
				sum+=end;
			}
		}
		System.out.print(cnt);
		
	}

}
