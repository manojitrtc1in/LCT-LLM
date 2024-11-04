

import java.awt.List;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Scanner;

public class b {
	
	public static void main(String[] args) 
	{
		Scanner s=new Scanner(System.in);

	int t=s.nextInt();
	
	
	for(int ie=0;ie<t;ie++) {
		
		int n=s.nextInt();
		int m=s.nextInt();
		
		int[][] arr=new int[n][m];
		
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				arr[i][j]=s.nextInt();
			}
		}
		
		int[] one =new int[n+m];
		int[] zero=new int[n+m];
		
		for(int i=0;i<n+m;i++) {
			
			for(int j=0;j<n;j++) {
				for(int k=0;k<m;k++) {
					if(j+k==i) {
						if(arr[j][k]==1) {
							one[j+k]++;
						}else {
							zero[j+k]++;
						}
					}
				}
			}
			
		}
		
		
		int ans=0;
		for(int i=0;i<(n+m-1)/2;i++) {
			int ts=one[i]+one[n+m-2-i];
			int g=zero[i]+zero[n+m-2-i];
			
			ans=Math.min(ts, g)+ans;
		}
		
		
		System.out.println(ans);
		
		
	}
		
	}
}