

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class d {
	
	 public static void main(String[] args)  {
	
		 Scanner s=new Scanner(System.in);
		
		int q=s.nextInt();
		for(int ie=0;ie<q;ie++) {
			long a=s.nextLong();
			long b=s.nextLong();
			long c=s.nextLong();
			
			long[] arr=new long[3];
			arr[0]=a;
			arr[1]=b;
			arr[2]=c;
			Arrays.sort(arr);
			
			if(arr[0]==arr[1]&&arr[1]==arr[2]) {
				

			}else if(arr[0]==arr[1]) {
				
					arr[0]=arr[0]+1;
					arr[1]=arr[1]+1;
				
				
				if(arr[1]==arr[2]) {
					
				}else {
					arr[2]=arr[2]-1;
				}
				
				
			}else if(arr[1]==arr[2]){
				
				arr[2]=arr[2]-1;
				arr[1]=arr[1]-1;
			
			
			if(arr[1]==arr[0]) {
				
			}else {
				arr[0]=arr[0]+1;
			}
			}else {
				arr[0]++;
				arr[2]--;
			}
			
			

			long ans=0;
			ans=arr[1]-arr[0]+arr[2]-arr[0]+arr[2]-arr[1];
			System.out.print(ans);
			System.out.println();
		}
	 }
}