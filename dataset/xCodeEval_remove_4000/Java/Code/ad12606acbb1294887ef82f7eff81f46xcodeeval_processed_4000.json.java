
import java.util.*;

public class Main{
	
	public static void main(String[] args) {
		
		Scanner s=new Scanner(System.in);
StringBuilder sb=new StringBuilder();
		int t=s.nextInt();
		for(int ie=0;ie<t;ie++) {

			long a=s.nextLong();
			long b=s.nextLong();
			int z=(int)lcm(a,b);
			long[] dp=new long[z+1];
			int curr=1;
			
			for(long j=1;j<z+1;j++) {
			  long g=(j%a)%b;
			  long h=(j%b)%a;
			  
			  if(g!=h) {
				  dp[curr]=dp[curr-1]+1;
			  }else {
				  dp[curr]=dp[curr-1];
			  }
			  
			 
			  curr++;
			  
			  
			}
			int q=s.nextInt();
			for(int i=0;i<q;i++) {
				
				long l=s.nextLong();
				long r=s.nextLong();










				
				
				
				long v=(r-1+1l)/(long)z;
				long ans=0;
				ans=ans+(Math.max(0, v)*dp[z]);
				
				long left=(r-1+1l)-((long)z*Math.max((v),0));
				long c=left%(long)z;
				
				ans=ans+dp[(int)c];
				
				long v1=(l-1)/(long)z;
				long ans1=0;
				ans1=ans1+(Math.max(0, v1)*dp[z]);
				
				long left1=(l-1)-((long)z*Math.max((v1),0));
				long c1=left1%(long)z;
				
				ans1=ans1+dp[(int)c1];
				sb.append(ans-ans1);
				sb.append(" ");
				
				
				
				
				
				
			}
		sb.append("\n");
		}
		System.out.println(sb);
	}
	public static long gcd(long a, long b) 
	    { 
	    if (a == 0) 
	        return b;  
	    return gcd(b % a, a);  
	    } 
	      
	   
	public    static long lcm(long a, long b) 
	    { 
	        return (a*b)/gcd(a, b); 
	    } 
}