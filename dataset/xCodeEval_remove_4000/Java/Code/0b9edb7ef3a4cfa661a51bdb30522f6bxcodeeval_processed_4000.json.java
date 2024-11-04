
import java.util.Scanner;

public class b{
	
	
	public static void main(String[] args) 
	{
		Scanner s=new Scanner(System.in);
		int t=s.nextInt();
		
		for(int ie=0;ie<t;ie++) {
			
			
			int n=s.nextInt();
			int m=s.nextInt();
			if(m>=n) {
				if(2*n==m||n==m) {
					System.out.println("YES");
				}else {
					System.out.println("NO");
				}
			}else {
				if(n%m==0) {
					System.out.println("YES");
				}else {
					System.out.println("NO");
				}
			}
			
			
			
			
		}
	
	}
}