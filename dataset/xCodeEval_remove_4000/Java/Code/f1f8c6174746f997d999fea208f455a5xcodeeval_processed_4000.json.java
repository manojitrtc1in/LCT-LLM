

import java.util.ArrayList;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        
    	Scanner s=new Scanner(System.in);
 
    	int t=s.nextInt();
    	for(int ie=0;ie<t;ie++) {
 
    		int n=s.nextInt();
    		n=2*n;
    		int[] arr=new int[n];
    		for(int i=0;i<n;i++) {
    			arr[i]=s.nextInt();
    		}
    		
    		ArrayList<Integer> list=new ArrayList<>();
    		
    		int last=n;
    		
    		while(last!=0) {
    			int max=0;
    			int in=-1;
    			for(int i=0;i<last;i++) {
    				if(arr[i]>max) {
    					max=arr[i];
    					in=i;
    				}
    			}
    			
    			
    			list.add(last-in);
    			last=in;
    			
    		}
    		
    		
    		int[][] dp=new int[list.size()+1][1+(n/2)];
    		for(int i=1;i<list.size()+1;i++) {
    			for(int j=1;j<1+(n/2);j++) {
    				if(list.get(i-1)>j) {
    					dp[i][j]=dp[i-1][j];
    				}else if(list.get(i-1)==j) {
    					dp[i][j]=1;
    				}else {
    					dp[i][j]=Math.max(dp[i-1][j], dp[i-1][j-list.get(i-1)]);
    				}
    			}
    		}
    		
    		if(dp[list.size()][n/2]==1) {
    			System.out.println("YES");
    		}else {
    			System.out.println("NO");
    		}
    	
    	}
    }
}