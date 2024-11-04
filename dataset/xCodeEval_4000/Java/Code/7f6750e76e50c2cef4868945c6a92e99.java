

import java.util.Arrays;
import java.util.Scanner;

public class Main{
	
	public static void main(String[] args) {
		

		Scanner s=new Scanner(System.in);

		int t=s.nextInt();
		for(int ie=0;ie<t;ie++) {
			
			int r=s.nextInt();
			int c=s.nextInt();
			
			if(r==1) {
				System.out.println("YES");
			}else if(c==1) {
				System.out.println("YES");
			}else if(r==2&&c==2) {
				System.out.println("YES");
			}else {
				System.out.println("NO");
			}
			
		}
		
	}
}