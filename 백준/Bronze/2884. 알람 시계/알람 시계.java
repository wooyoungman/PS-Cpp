import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int H = sc.nextInt();
		int M = sc.nextInt();
		sc.close();
		if(M>=45) {
			M-=45;
		}
		else
		{
			M=15+M;
			if(H>0) {
				H-=1;
			}
			else
			{
				H=23;
			}
		}
		System.out.println(H+" "+M);
	}
}


