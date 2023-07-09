import java.util.Scanner;
public class Main
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        int score = input.nextInt();
        int piece = input.nextInt();
        int sum = 0;
        for(int i=0;i<piece;i++)
        {
            int a = input.nextInt();
            int b = input.nextInt();
            sum += a*b;
        }
        if(score==sum)
        {
            System.out.println("Yes");
        }
        else
        {
            System.out.println("No");
        }
    }
}