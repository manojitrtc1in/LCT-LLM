

import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class b {
	
	
	public static void main(String[] args) throws Exception {

	      Scanner s=new Scanner(System.in);
	      long v=0,x=0;
	      int n=s.nextInt();
	      pair[] arr=new pair[n];
	      for(int i=0;i<n;i++) {
	    	  
	    	   long a=s.nextLong();
	    	   if(i==0) {
	    		   v=a;
	    	   }
	    	   if(i==1) {
	    		   x=a;
	    	   }
	    	   pair ob=new pair(a,i+1);
	    	   arr[i]=ob;
	      }
	      
	      Arrays.sort(arr,new comp());
	      if(arr.length<=3) {
	    	  System.out.println(1);
	      }else {
	    	  int e=0;
	    	  int f=0;
	    	  int g=0;
	    	  int in=arr[0].in;
		    	 int in2=arr[1].in;
		    	 int in3=arr[0].in;
	    	 long d=arr[1].val-arr[0].val;
	    	 
	    	 long curr=arr[1].val;
	    	 int flag=0;
	    	 int be=0;
	    	 for(int i=2;i<n;i++) {
	    		 if(flag==0) {
	    		 curr=curr+d;
	    		 
	    		 }
	    		
	    		 if(arr[i].val!=curr&&flag==0&&be==0) {
	    			 flag=1;
	    			 in=arr[i].in;
	    			 be=1;
	    			 
	    		 }else if(arr[i].val!=curr&&be==1){
	    			
	    			 g=1;
	    			 break;
	    		 }else if(arr[i].val==curr) {
	    			 flag=0;
	    		 }
	    	 }
	    	  
	    	 d=arr[2].val-arr[0].val;
	    	 curr=arr[2].val;
	    	 
	    	 for(int i=3;i<n;i++) {
	    		 curr=curr+d;
	    		 if(arr[i].val!=curr) {
	    			 f=1;
	    			 break;
	    		 }
	    	 }
	    	 
	    	 
	    	 d=arr[2].val-arr[1].val;
	    	 curr=arr[2].val;
	    	 
	    	 for(int i=3;i<n;i++) {
	    		 
	    		 curr=curr+d;
	    		 if(arr[i].val!=curr) {
	    		
	    			 e=1;
	    			 break;
	    		 }
	    	 }
	    	
	    	 
	    	 if(g==0) {
	    		
	    		 System.out.println(in);
	    		 
	    	 }else if(f==0) {
	    		 System.out.println(in2);
	    	 }else if(e==0) {
	    		 System.out.println(in3);
	    	 }else {
	    		 System.out.println(-1);
	    	 }
	    	 
	    	  
	      }
	     
	      
	}
}

class pair{
	long val;
	int in;
	public pair(long val,int in) {
		this.val=val;
		this.in=in;
	}
}

class comp implements Comparator<pair>{
	public int compare(pair h, pair j) {
		
		if(h.val<j.val) {
			return -1;
		}else if(h.val==j.val) {
			return 0;
		}else {
			return 1;
		}
		
		
	}
}