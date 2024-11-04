

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
	    	
	    	char[] arr=s.next().toCharArray();
	    	
	    	int st=0;
	    	int end=arr.length;
	    	int ans=Integer.MAX_VALUE;
	    	if(arr.length<=2) {
	    		System.out.println(0);
	    	}else {
	    	while(st<=end) {
	    		HashMap<Character,Integer> map=new HashMap<>();
	    		int mid=(st+end)/2;
	    		
	    		int l=0;
	    		int r=mid-1;
	    		int flag=0;
	    		for(int i=0;i<mid;i++) {
	    			if(map.containsKey(arr[i])) {
	    			map.put(arr[i], map.get(arr[i])+1);
	    			}else {
	    				map.put(arr[i], 1);
	    			}
	    		}
	    		
	    		if(map.size()==3) {
	    			flag=1;
	    		}
	    		
	    		while(r<arr.length) {
	    			if(map.size()==3) {
	    				flag=1;
	    				break;
	    			}else {
	    				if(map.get(arr[l])==1) {
                            map.remove(arr[l]);	    					
	    				}else {
	    					map.put(arr[l], map.get(arr[l])-1);
	    				}
	    				
	    				l++;
	    				if(r<arr.length-1) {
	    					r++;
	    					if(map.containsKey(arr[r])) {
	    		    			map.put(arr[r], map.get(arr[r])+1);
	    		    			}else {
	    		    				map.put(arr[r], 1);
	    		    			}
	    				}else {
	    					break;
	    				}
	    				
	    				
	    			}
	    			
	    			
	    		}
	    		
	    		if(flag==1) {
	    			ans=Math.min(ans, mid);
	    			end=mid-1;
	    		}else {
	    			st=mid+1;
	    		}
	    		
	    		
	    		
	    	}
	    	if(ans!=Integer.MAX_VALUE)
	    	System.out.println(ans);
	    	else
	    		System.out.println(0);
	    	
	    	}
	    	
	    }
	    
	}
}
	    
	    