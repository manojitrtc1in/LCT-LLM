

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
         
        	 int n=s.nextInt();
        	 int k=s.nextInt();
        	 Long[] arr=new Long[n];
        	 
        	 for(int i=0;i<n;i++) {
        		 arr[i]=s.nextLong();
        	 }
        	 
        	 Arrays.sort(arr);
        	 ArrayList<Integer> list=new ArrayList<>();
        	 int st=0;
        	 int end=0;
        	while(end<n) {
        		
        		if(arr[st].equals(arr[end])) {
        			if(end==n-1) {
            			list.add(st);
            			list.add(end);
            			end++;
            		}
        			end++;
            	}
        		
        		else {
        		

        			list.add(st);
        			list.add(end-1);
        			st=end;
        			
        		}
        	}
        	
        	long[] pre=new long[n];
        	long[] suf=new long[n];
        	pre[0]=0;
        	suf[n-1]=0;
        	for(int i=1;i<n;i++) {
        		pre[i]=pre[i-1]+arr[i-1];
        	}
        	for(int i=n-2;i>=0;i--) {
        		suf[i]=suf[i+1]+arr[i+1];
        	}
        	
        	int flag=0;
        	st=0;
        	end=1;
           long min=Long.MAX_VALUE;
        	

        	while(end<list.size()) {
        		int range=list.get(end)-list.get(st)+1;
        		if(k>range) {
        		long gans=0;
        		
        		long lans=0;
        		long lk=Math.abs((arr[list.get(st)]-1)*list.get(st)-pre[list.get(st)]);
        		
        	      if(k-range<=list.get(st)) {
        	    	  lans=lk+k-range;
        	      }else {
        	    	  lans=-1;
        	      }
        	      
        	      long rans=0;
          		long rk=Math.abs(((arr[list.get(end)]+1)*((n-1)-list.get(end)))-suf[list.get(end)]);
          		
          	      if(k-range<=n-1-list.get(end)) {
          	    	  rans=rk+k-range;
          	      }else {
          	    	  rans=-1;
          	      }
          	      
          	      
          	   long bans=0;
          	 long bk=Math.abs(((arr[list.get(end)]+1)*((n-1)-list.get(end)))-suf[list.get(end)])+Math.abs((arr[list.get(st)]-1)*list.get(st)-pre[list.get(st)]);
       		
     	     bans=bk+k-range;
     	     long ans=0;
     	      if(lans==-1&&rans!=-1) {
     	    	  ans=rans;
     	      }else if(rans==-1&&lans!=-1) {
     	    	  ans=lans;
     	      }else if(lans==-1&&rans==-1) {
     	    	  ans=-1;
     	      }else {
     	    	  ans=Math.min(lans, rans);
     	      }
     	      
     	      if(ans!=-1){
     	    	  gans=Math.min(ans, bans);
     	      }else {
     	    	  gans=bans;
     	      }
          	   
          	   if(min>gans) {
          		   min=gans;
          	   }
          	      st=st+2;
          	      end=end+2;
          	      
          	      
        	   
        	      
        		
        		}else {
        			flag=1;
        		st=st+2;
        		end=end+2;
        			
        		}
        		
        		
        	}
        	
        	if(flag==1) {
        		System.out.println(0);
        	}else {
        		System.out.println(min);
        	}
        	
        	
        	
        	
        	
	}
}