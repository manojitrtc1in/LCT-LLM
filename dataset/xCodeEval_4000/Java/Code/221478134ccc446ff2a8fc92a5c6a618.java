

import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) {
		
		Scanner s=new Scanner(System.in);
 
		int t=s.nextInt();
		for(int ie=0;ie<t;ie++) {

			int n=s.nextInt();
			int k=s.nextInt();
			
			int[][] ans=new int[n][n];
			
			for(int i=0;i<n;i++) {
				if(k==0) {
					break;
				}
				ans[i][i]=1;
				k--;
				
			}
			
			int x=0;int x2=n;
			p1:while(k>0) {
				x++;
				x2--;
				for(int i=0;i<n-x;i++) {
					if(k==0) {
						break p1;
					}
					ans[i][i+x]=1;
					k--;
				}
				for(int i=0;i<n-x2;i++) {
					if(k==0) {
						break p1;
					}
					ans[x2+i][i]=1;
					k--;
				}
				
				
			}
			
			int max=Integer.MIN_VALUE;
			int min=Integer.MAX_VALUE;
			int r=0;
			int c=0;
			
			for(int i=0;i<n;i++) {
				int count=0;
				for(int j=0;j<n;j++) {
					if(ans[i][j]==1) {
						count++;
					}
					
				}
				max=Math.max(max, count);
				min=Math.min(min, count);
			}
			
			r=(int)Math.pow(max-min, 2);
			
			 max=Integer.MIN_VALUE;
			 min=Integer.MAX_VALUE;
			
			
			for(int i=0;i<n;i++) {
				int count=0;
				for(int j=0;j<n;j++) {
					if(ans[j][i]==1) {
						count++;
					}
					
				}
				max=Math.max(max, count);
				min=Math.min(min, count);
			}
			
			c=(int)Math.pow(max-min, 2);
			
			System.out.println(r+c);
			
			
			for(int i=0;i<n;i++) {
				for(int j=0;j<n;j++) {
					System.out.print(ans[i][j]);
					
				}
				System.out.println();
			}
			
			
			
			
		}
	}
}