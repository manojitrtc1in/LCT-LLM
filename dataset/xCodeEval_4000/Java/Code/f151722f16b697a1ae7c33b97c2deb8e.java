

import java.util.ArrayList;
import java.util.Scanner;

public class Main {
	
	public static void main(String[] args)
	{
		Scanner s=new Scanner(System.in);

		int res=1;
		int x=0;
		int flag=0;
		int y=0;
		int n=s.nextInt();
		for(int i=0;i<n;i++) {
			int a=s.nextInt();
			int b=s.nextInt();
			
			
		int	ans=Math.min(a, b)-Math.max(x, y);
			if(x!=y) {
				ans++;
			}
				
		res=res+Math.max(0, ans);
			
			x=a;
			
			y=b;
			
			
		}
		System.out.println(res);
		
	}
}