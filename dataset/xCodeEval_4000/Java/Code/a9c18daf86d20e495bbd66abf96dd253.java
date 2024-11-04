

import java.util.HashMap;
import java.util.Scanner;

import javax.swing.plaf.synth.SynthSpinnerUI;

public class Main {
	
	public static void main(String[] args)	{
		
		Scanner s=new Scanner(System.in);
 
		StringBuilder sb=new StringBuilder();
		long[] dp=new long[50];
		dp[0]=1;
		for(int i=1;i<50;i++) {
			dp[i]=dp[i-1]*2;
		}
		
		int n=s.nextInt();
		long[] arr=new long[n];
		int q=s.nextInt();
		HashMap<Long,Integer> map=new HashMap<>();
		
		for(int i=0;i<n;i++) {
			arr[i]=s.nextInt();
			if(map.containsKey(arr[i])) {
				map.put(arr[i], map.get(arr[i])+1);
			}else{
				map.put(arr[i], 1);
			}
		}
		
		for(int ie=0;ie<q;ie++) {
			
			long a=s.nextInt();
			
			long ans=0;
			for(int i=49;i>=0;i--) {
				if(map.containsKey(dp[i])) {
					
					if(a>=dp[i]) {
						long g=a/dp[i];
						
						if(map.get(dp[i])>=g) {
							a=a-g*dp[i];
							ans=ans+g;
						}else {
							a=a-map.get(dp[i])*dp[i];
							ans=ans+map.get(dp[i]);
						}
							
						
					}
					
					
				}else {
					
				}
			}
			
			if(a==0)
			{
				sb.append(ans).append("\n");
			}else
			{
				sb.append(-1).append("\n");
			}
			
			
			
		}
		
		System.out.println(sb);
		
		
		
		
	}
}