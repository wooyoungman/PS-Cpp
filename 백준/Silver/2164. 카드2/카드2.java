
import java.io.*;
import java.util.*;
public class Main {

	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		Queue<Integer> queue= new LinkedList<>();
		for(int i=1;i<=N;i++)
		{
			queue.add(i);
		}
		// poll을 사용하면 pop과 동일한 기능이다. 맨 처음 원소를 꺼낸다.
		while(queue.size()>1) {
			queue.poll();
			queue.add(queue.poll());
		}
		System.out.print(queue.peek());
	}

}
