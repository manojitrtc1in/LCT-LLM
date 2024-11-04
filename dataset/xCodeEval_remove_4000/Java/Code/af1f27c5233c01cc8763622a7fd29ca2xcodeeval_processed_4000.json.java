

import java.util.HashMap;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        
    	Scanner s=new Scanner(System.in);
 
    	int t=s.nextInt();
    	for(int ie=0;ie<t;ie++) {
    		
    		int l=s.nextInt();
    		int r=s.nextInt();
    		long m=s.nextLong();
    		int limit=r-l;
    		for(int i=l;i<=r;i++) {
    			if((m%i)==0) {
    				System.out.println(i+" "+l+" "+l);
    				break;
    			}else if(i-(m%i)<=limit) {
    				System.out.println(i+" "+(r-(i-(m%i)))+" "+r);
    				break;
    			}else if(m%i<=limit) {
    				System.out.println(i+" "+r+" "+(r-(m%i)));
    				break;
    			}
    		}
    		
    	}
    	
    }
}