

import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class b{
	
	public static void main(String[] args) throws Exception 
	{
		Scanner s=new Scanner(System.in);
         int t=s.nextInt();
         for(int ie=0;ie<t;ie++) {
        	
            int n=s.nextInt();
            int[] arr=new int[n];
            for(int i=0;i<n;i++) {
            	arr[i]=s.nextInt();
            }
            
            HashMap<Integer,Integer> map=new HashMap<>();
            Arrays.sort(arr);
            int ans=0;
        	 for(int i=n-1;i>=0;i--) {
        		 if(arr[i]%2==0) {
        		 if(!map.containsKey(arr[i])) {
        			 while(arr[i]%2==0) {
        		      map.put(arr[i], 1);
        		      ans++;
        		      arr[i]=arr[i]/2;
        			 }
        		 }else {
        			 continue;
        		 }
        	 }
        		 
        	 }
        	 System.out.println(ans);
        	 
        	 
         }
         
	}
	
		
	
}