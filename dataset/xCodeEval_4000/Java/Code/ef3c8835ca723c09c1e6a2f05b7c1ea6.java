

import java.util.*;
import java.awt.List;
import java.io.*;

public class d {
	

	public static void main(String[] args)  {

		Scanner s=new Scanner(System.in);

		int t=s.nextInt();
		
		for(int ie=0;ie<t;ie++) {
			
			int n=s.nextInt();
			char[] arr=s.next().toCharArray();
			
			int ans=0;
			
			HashMap<Integer,Integer> map=new HashMap<>();
			for(int i=0;i<n;i++) {
				if(arr[i]=='-') {
					
					map.put(i, 1);
					map.put((i+1)%n, 1);
				}
				
			}
			
			ans=ans+map.size();
			
			
			int g=0;
			int td=0;
			for(int i=0;i<n;i++) {
				if(arr[i]=='>') {
					g++;
				}
				
				if(arr[i]=='<') {
					td++;
				}
			}
					
			
			if(g>=1 && td>=1) {
				System.out.println(ans);
			}else {
				System.out.println(n);
				
			}
			
			
		}
		
	}
}