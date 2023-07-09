import java.util.*;
public class Main
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        int m = input.nextInt();
        int [] arr = new int[n+1];
        for(int i=1;i<=n;i++)
        {
            arr[i]=i;
        }
        for(int i=0;i<m;i++)
        {
            int a=input.nextInt();
            int b=input.nextInt();
            int temp=arr[a];
            arr[a]=arr[b];
            arr[b]=temp;
        }
        for(int i=1;i<=n;i++)
        {
            System.out.print(arr[i]+" ");
        }
    }
}