

import java.util.HashMap;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        
    	Scanner s=new Scanner(System.in);
 
    	int t=s.nextInt();
    	for(int ie=0;ie<t;ie++) {
    		int n=s.nextInt();
    		char[] arr=s.next().toCharArray();
    		char[] brr=s.next().toCharArray();
    		
    		int flag=0;
    		for(int i=0;i<n;i++) {
    			if(arr[i]>brr[i]) {
    				flag=1;
    				break;
    			}
    		}
    		
    		if(flag==1) {
    			System.out.println(-1);
    		}else {
    		
    		
    		int ans=0;
    		for(char ch='a';ch<='t';ch++ ) {
    			
    			int in=-1;
    			
    			for(int i=0;i<n;i++) {
    				if(arr[i]!=brr[i]) {
    				if(arr[i]==ch) {
    					if(in==-1) {
    						in=i;
    						
    					}else {
    						if(brr[i]<brr[in]) {
    							in=i;
    						}
    					}
    				}
    			}
    			}
    			
    			if(in==-1) {
    				
    			}else {
    			for(int i=0;i<n;i++) {
    				if(arr[i]!=brr[i]) {
    					if(arr[i]==ch) {
    						arr[i]=brr[in];
    					}
    					
    					
    				}
    			}
    			ans++;
    			}
    			
    			    			
    		}
    		System.out.println(ans);
    		
    	}
    		
    		
    		
    	}
    	
    }
}