

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {
	
    public static void main(String[] args) {
 
    	Scanner s=new Scanner(System.in);
 
    	int t=s.nextInt();
    	for(int ie=0;ie<t;ie++) {
    		char[] arr=s.next().toCharArray();
    		int ans=Integer.MAX_VALUE;
    		int g=0;
    		
    		for(char i='0';i<='9';i++) {
    			for(char j='0';j<='9';j++) {
    				int flag=0;
    				int count=0;
    				for(int k=0;k<arr.length;k++) {
    				if(flag==0) {
    					if(arr[k]==i) {
    						flag=1;
    					}else {
    						count++;
    					}
    				}else {
    					if(arr[k]==j) {
    						flag=0;
    					}else {
    						count++;
    					}
    				}
    					
    					
    				}
    				
    				if(flag==1) {
    					count++;
    				}
    				ans=Math.min(ans, count);
    			}
    		}
    		
    		for(char ch='0';ch<='9';ch++) {
    			int c=0;
    			for(int i=0;i<arr.length;i++) {
    				if(arr[i]!=ch) {
    					c++;
    				}
    			}
    			
    			ans=Math.min(ans, c);
    		}
    		
    		
    		System.out.println(ans);
    	}
    	}
    	
    
}