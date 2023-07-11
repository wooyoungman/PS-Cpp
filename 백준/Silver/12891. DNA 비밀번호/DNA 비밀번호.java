import java.io.*;
import java.util.*;

public class Main {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int S=Integer.parseInt(st.nextToken());
		int P=Integer.parseInt(st.nextToken());
		
		char str[] = br.readLine().toCharArray();

		st=new StringTokenizer(br.readLine());
		
		// con_arr는 만족해야 하는 문자의 개수이고, 저장 순서는 A C G T이며 값은 각 개수이다.
		int con_arr[] = new int[4];
		for(int i=0;i<4;i++) {
			int a =Integer.parseInt(st.nextToken());
			con_arr[i]=a;
		}
		
		// now_arr는 현재 부분문자열에서 A C G T 문자의 개수이다.
		int now_arr[] = new int[4];
		
		// 입력 받은 전체 문자열에서 0번 인덱스 부터 부분문자열을 추출
		for(int i=0;i<P;i++) {
			if(str[i]=='A') {
				now_arr[0]++;
			}
			else if (str[i]=='C') {
				now_arr[1]++;
			}
			else if (str[i]=='G') {
				now_arr[2]++;
			}
			else {
				now_arr[3]++;
			}
		}
		
		// 첫 부분 문자열에서 조건을 만족하는지 확인 
		boolean first = true;
		for(int i=0;i<4;i++) {
			if(now_arr[i]<con_arr[i]) {
				first=false;
			}
		}
		
		
		int start=0;
		int end=P-1;
		int cnt=0;
		
		// 첫 부분 문자열에서 조건 만족 시 카운트 + 1
		if(first) {
			cnt++;
		}
		
		// 슬라이딩 시작
		while(end!=S-1) {
			if(str[start]=='A') {
				now_arr[0]--;
			}
			else if (str[start]=='C') {
				now_arr[1]--;
			}
			else if (str[start]=='G') {
				now_arr[2]--;
			}
			else {
				now_arr[3]--;
			}
			start++;
			end++;
			if(str[end]=='A') {
				now_arr[0]++;
			}
			else if (str[end]=='C') {
				now_arr[1]++;
			}
			else if (str[end]=='G') {
				now_arr[2]++;
			}
			else {
				now_arr[3]++;
			}
			first=true;
			for(int i=0;i<4;i++) {
				if(now_arr[i]<con_arr[i]) {
					first=false;
				}
			}
			if(first) {
				cnt++;
			}
		}
		System.out.print(cnt);
	}

}