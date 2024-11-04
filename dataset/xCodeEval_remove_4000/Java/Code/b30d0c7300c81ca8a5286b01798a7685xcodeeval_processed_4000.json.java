

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class k{
	
	public static void main(String[] args) throws Exception 
	{ 
		Scanner s=new Scanner(System.in);
		
		int t=s.nextInt();
		for(int ie=0;ie<t;ie++) {
			
			long n=s.nextLong();
			HashMap<Long,Long> map=new HashMap<>();
			
			fun(n,map);
			
			long max=0;
			long num=0;
			
			for(Map.Entry<Long, Long> entry :  map.entrySet()) {
				if(entry.getValue()>max) {
					max=entry.getValue();
					num=entry.getKey();
				}
				
			}
			System.out.println(max);
			long v=0;
			for(int i=0;i<max;i++) {
				 v=pow(num,max-1);
			}
			
			for(int i=0;i<max-1;i++) {
				System.out.print(num+" ");
			}
			System.out.println(n/v);
			
			
			
			
			
			
		}
		
	}
	public static void fun(long n,HashMap<Long,Long> map) 
    { 
        
        while (n%2==0) 
        { 
            map.put(2l, map.getOrDefault(2l,0l)+1);
            n /= 2; 
        } 
  
       
        for (long i = 3; i <= Math.sqrt(n); i+= 2) 
        { 
           
            while (n%i == 0) 
            { 
            	 map.put(i, map.getOrDefault(i,0l)+1);
                n /= i; 
            } 
        } 
  
      
        if (n > 2) 
        	 map.put(n, map.getOrDefault(n,0l)+1);
    } 
	
	
	public static long pow(long a, long b) {
		long res=1;
		
		while(b>0) {
			
			if(b%2!=0) {
				res=res*a;
			}
			
			a=a*a;
			b=b/2;
		}
		return res;
		
	}
	
	
  
}
