

import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;
import java.util.Queue;
import java.util.Scanner;
 public class b{
	
	public static void main(String[] args) throws Exception 
	{ 
		Scanner s=new Scanner(System.in);
      
		int t=s.nextInt();
		for(int ie=0;ie<t;ie++) {
			int n=s.nextInt();
			int k=s.nextInt();
			char[] arr=s.next().toCharArray();
			
			int flag=0;
			
			ArrayList<String> list=new ArrayList<>();
			for(int i=0;i<3;i++) {
				StringBuilder sb=new StringBuilder();
				flag=i;
				for(int j=0;j<k;j++) {
					if(flag==0) {
						sb.append('R');
						flag=1;
						
					}else if(flag==1)
					{
						sb.append('G');
						flag=2;
					}else if(flag==2) {
						sb.append('B');
						flag=0;
					}
					
					
					
				}
				list.add(sb.toString());
			}
 			
			int min=Integer.MAX_VALUE;
			for(int ke=0;ke<3;ke++) {
	    for(int i=0;i<=n-k;i++) {
	    	int count=0;
	    	for(int j=0;j<k;j++) {
	    		if(arr[i+j]==list.get(ke).charAt(j)) {
	    			
	    		}else {
	    			count++;
	    		}
	    	}
	    	
	    	if(min>count) {
	    		min=count;
	    	}
	    }
			}
	    
	    System.out.println(min);
			
		}
	}
 }
        	 
        	 