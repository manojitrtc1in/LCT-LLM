

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class b {
	
	
	public static void main(String[] args) throws Exception {

	    Scanner s=new Scanner(System.in);

	    int t=s.nextInt();
	    for(int ie=0;ie<t;ie++) {
	    	
	    	int n=s.nextInt();
	    	char[] arr=s.next().toCharArray();
	    	
	    	
	    	int st2=0;
	    	int one=0;int two=0;
	    	int flag=0;
	    	int in=-1;
	    	for(int i=0;i<n-1;i++) {
	    		if(arr[i]-'0'>arr[i+1]-'0') {
	    			flag=1;
	    			in=i;
	    			break;
	    		}
	    	}
	    	
	    	if(flag==0) {
	    		for(int i=0;i<n;i++) {
	    			System.out.print(1);
	    		}
	    		System.out.println();
	    	}else {
	    	   int v=0;
	    	
	    		int g=0;
	    		int[] ans=new int[n];
	    		for(int si=0;si<=9;si++) {
	    			st2=si;
	    			one=0;
	    			two=si;
	    			g=0;
	    			for(int i=0;i<n;i++) {
	    			if(arr[i]-'0'>=one&&arr[i]-'0'<st2) {
	    				one=arr[i]-'0';
	    				ans[i]=1;
	    			}else if(arr[i]-'0'>=st2&&arr[i]-'0'>=two) {
	    				two=arr[i]-'0';
	    				ans[i]=2;
	    			}else if(arr[i]-'0'==st2){
	    				one=arr[i]-'0';
	    				ans[i]=1;
	    			}else {
	    				g=1;
	    				break;
	    			}
	    		}
	    			if(g==0) {
	    				for(int k=0;k<n;k++) {
		    			v=1;
	    					System.out.print(ans[k]);
		    			}
		    			System.out.println();
		    			break;
	    			}
	    			
	    			
	    		}
	    		
	    		
	    
	    		if(v==0) {
	    			System.out.println("-");
	    		}
	    		
	    		
	    		
	    	}
	    	
	    	
	    	
	    	
	    	
	    }
	    
	}
}