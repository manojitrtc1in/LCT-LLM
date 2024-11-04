

import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class k{
	
	public static void main(String[] args) throws Exception 
	{ 
	     Scanner s=new Scanner(System.in);

	     int t=s.nextInt();
	     
	     for(int ie=0;ie<t;ie++) {

	    	 int n=s.nextInt();

	    	 int k=s.nextInt();
	    	 HashMap<Integer,Integer> map=new HashMap<>();
	    	ArrayList<Integer> list=new ArrayList<>();
	    	 for(int i=0;i<n;i++) {
	    		int a=s.nextInt();
	    		 if(map.containsKey(a)) {
	    			 map.put(a, map.get(a)+1);
	    		 }else {
	    			 
	    			 map.put(a, 1);
	    			 list.add(a);
	    		 }
	    		
	    	 }
	    	 
	    	
	    	 int how=0;
	    	 long m=1000000007;
	    	Collections.sort(list);
	    	long ans=0;
	    	
	    	for(int i=list.size()-1;i>=0;i-- ) {
	    		if(k>=map.get(list.get(i))) {
	    			k=k-map.get(list.get(i));
	    			
	    		}else {
	    			if(k>0) {
	    				how=map.get(list.get(i));
	    				break;
	    			}else {
	    				break;
	    			}
	    		}
	    	}
	    	

	    	ans=1;
	    	int h=how;
	    	for(int i=0;i<how-k;i++) {
	    		ans=(ans%m*h%m)%m;
	    		h--;
	    		
	    	}
	    

	    	long ans2=1;
	    	for(int i=1;i<=how-k;i++) {
	    		ans2=(ans2%m*i%m)%m;
	    		
	    	}
	    

	    	long d=(ans%m*pow(ans2,m-2,m)%m)%m;
	    	
	    	 
	    	System.out.println(d);
	    	 
	    	 
	     }
	}
	public static long pow(long a,long b,long m) {
		long res=1;
		while(b>0) {
			if(b%2!=0) {
				res=(res%m*a%m)%m;
			}
			b=b/2;
			a=(a%m*a%m)%m;
		}
		return res;
	}
}
