
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) throws Exception
	{
		Scanner s=new Scanner(System.in);
		
		

		int t=s.nextInt();
		StringBuilder sb=new StringBuilder();
		for(int ie=0;ie<t;ie++) {
			
			int n=s.nextInt();
			int m=s.nextInt();
			int r=s.nextInt();
			int c=s.nextInt();
			

			int[] col=new int[m];
			
			int[][] ans=new int[n][m];
			int flag=0;
			p1:for(int i=0;i<n;i++) {
				
				for(int z=0;z<r;z++) {
					int  min=Integer.MAX_VALUE;
					   int in=-1;
				   for(int j=0;j<m;j++) {
					   if(col[j]<min) {
						   min=col[j];
						   in=j;
					   }
				   }
				   
				   if(col[in]<c) {
					   ans[i][in]=1;
					   col[in]++;
				   }else {
					   flag=1;
					   break p1;
				   }
				   
				}
			}
			if(flag==1) {
				sb.append("NO");
				sb.append("\n");
			}else {
				int g=0;
				for(int i=0;i<n;i++) {
					int count=0;
					for(int j=0;j<m;j++) {
						if(ans[i][j]==1) {
							count++;
						}
					}
					
					if(count==r) {
						
					}else {
						g=1;
					}
				}
				
				for(int i=0;i<m;i++) {
					int count=0;
					for(int j=0;j<n;j++) {
						if(ans[j][i]==1) {
							count++;
						}
					}
					
					if(count==c) {
						
					}else {
						g=1;
					}
				}
				
				if(g==0) {
				sb.append("YES");
				sb.append("\n");
				for(int i=0;i<n;i++) {
					for(int j=0;j<m;j++) {
						sb.append(ans[i][j]);
					}
					sb.append("\n");
				}
				
				
				}else {
					sb.append("NO");
					sb.append("\n");
				}
			}
			
			sb.append("\n");
			
					
			
			
		}
		System.out.println(sb);
		
	} 
}