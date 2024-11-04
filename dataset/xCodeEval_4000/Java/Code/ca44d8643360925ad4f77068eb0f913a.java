

import java.awt.List;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Scanner;

public class b {
	
	public static void main(String[] args) 
	{
		Scanner s=new Scanner(System.in);

		
		
		
			int n=s.nextInt();
			int y=s.nextInt();
			int x=s.nextInt(); 
			char[] arr=s.next().toCharArray();
			int ans=0;
			
		
			
			for(int i=arr.length-y;i<n;i++) {
				if(i==arr.length-x-1) {
					if(arr[i]=='0') {
						ans++;
					}
				}else {
					if(arr[i]=='1') {
						ans++;
					}
				}
			}
			
			System.out.println(ans);
			
			
			
			
			
			
			
		}
	
}