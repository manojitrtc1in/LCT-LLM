

import java.util.Arrays;
import java.util.HashMap;
import java.util.Scanner;
 public class d {

	public static void main(String[] args) throws Exception {
	 
		Scanner s = new Scanner(System.in);
	
		int n=s.nextInt();
		Integer[] arr=new Integer[n];
		
		for(int i=0;i<n;i++) {
			arr[i]=s.nextInt();
		}
		
		Arrays.sort(arr);
	 
	    HashMap<Integer,Integer> max=new HashMap<>();
	    HashMap<Integer,Integer> min=new HashMap<>();
		
	    max.put(arr[0]-1, 1);
	    for(int i=1;i<n;i++) {
	    	if(!max.containsKey(arr[i]-1)) {
	    	    max.put(arr[i]-1, 1);	
	    	
	    }else {
	    	if(!max.containsKey(arr[i])) {
	    		max.put(arr[i], 1);
	    	}else if(!max.containsKey(arr[i]+1)) {
	    		max.put(arr[i]+1, 1);
	    	}
	    }
	    	
	    }
	    min.put(arr[0]+1, 1);
	    for(int i=0;i<n;i++) {
	    	if(min.containsKey(arr[i]-1)) {
	    		
	    	}else if(min.containsKey(arr[i])) {
	    		
	    	}else if(min.containsKey(arr[i]+1)) {
	    		
	    	}else {
	    		min.put(arr[i]+1, 1);
	    	}
	    }
	    System.out.println(min.size()+" "+max.size());
	    
	 
	}
 }