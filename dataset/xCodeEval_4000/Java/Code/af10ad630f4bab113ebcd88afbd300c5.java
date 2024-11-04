

import java.util.Arrays;
import java.util.HashMap;
import java.util.Scanner;

public class b {
	
	public static void main(String[] args) throws Exception {

	    Scanner s=new Scanner(System.in);

	    int t=s.nextInt();
	    for(int ie=0;ie<t;ie++) {
	    	
	    	int n=s.nextInt();
	    	int[] arr=new int[n];
	    	int[] brr=new int[n];
	    	for(int i=0;i<n;i++) {
	    		arr[i]=s.nextInt();
	    	}
	    	
	    	for(int i=0;i<n;i++) {
	    		brr[i]=s.nextInt();
	    	}
	    	
	    	int flag=0;
	    	
	    	HashMap<Integer,Integer> map=new HashMap<>();
	    	for(int i=0;i<n;i++) {
	    		map.put(brr[i], 1);
	    	}
	    	if(map.size()==2) {
	    		System.out.println("Yes");
	    	}else {
	    		
	    		for(int i=0;i<n-1;i++) {
	    			if(arr[i]<=arr[i+1]) {
	    				
	    			}else {
	    				flag=1;
	    			}
	    		}
	    		
	    		if(flag==1) {
	    			System.out.println("No");
	    		}else {
	    			System.out.println("Yes");
	    		}
	    	}
	    	
	    	
	    	
	    	
	    	
	    }
	    
	}
}
class pair{
	int a;
	int b;
	
	public pair(int a,int b) {
		this.a=a;
		this.b=b;
		
	}
}