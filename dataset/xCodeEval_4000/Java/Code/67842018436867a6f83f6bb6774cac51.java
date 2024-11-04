

import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class b {
	
	
	public static void main(String[] args) throws Exception {

	    Scanner s=new Scanner(System.in);

	    int t=s.nextInt();
	    for(int ie=0;ie<t;ie++) {
	    	int n=s.nextInt();
	    	int k=s.nextInt();
	    	int[] arr=new int[n];
	    	int z=0;
	    	for(int i=0;i<n;i++) {
	    		int a=s.nextInt();
	    		if(a>k) {
	    			arr[i]=1;
	    		}else if(a==k) {
	    			arr[i]=0;
	    			z++;
	    		}else {
	    			arr[i]=-1;
	    		}
	    	}
	    	
	    	if(arr.length==1) {
	    		if(arr[0]==0) {
	    			System.out.println("yes");
	    		}else {
	    			System.out.println("no");
	    		}
	    	}else {
	    	
	    	if(z==0) {
	    		System.out.println("no");
	    		
	    	}else {
	    		int flag=0;
	    		for(int i=0;i<n-1;i++) {
	    			if(arr[i]>=0&&arr[i+1]>=0) {
	    				flag=1;
	    			}
	    		}
	    		for(int i=0;i<n-2;i++) {
	    			if(arr[i]>=0&&arr[i+2]>=0) {
	    				flag=1;
	    			}
	    		}
	    		
	    		if(flag==1) {
	    			System.out.println("yes");
	    		}else {
	    			System.out.println("no");
	    		}
	    		
	    	}
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	}
	    	
	    }
	   
	}
}