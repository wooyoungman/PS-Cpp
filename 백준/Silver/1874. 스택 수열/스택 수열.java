
import java.io.*;
import java.util.*;
public class Main {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		int p_num=1;
		Stack<Integer> stack=new Stack<Integer>();
		ArrayList<Character> arr = new ArrayList<Character>();
		for(int i=0;i<n;i++) {
			int num = Integer.parseInt(br.readLine());
			while(num>=p_num) {
				stack.push(p_num);
				p_num++;
				arr.add('+');
			}
			if(stack.peek()==num) {
				stack.pop();
				arr.add('-');
			}
			else {
				System.out.println("NO");
				System.exit(0);
			}
		}
		for(Character a:arr) {
			System.out.println(a);
		}
	}

}
