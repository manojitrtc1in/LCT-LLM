import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Map;
import java.util.Queue;
import java.util.StringTokenizer;

public class id48 implements Runnable {
	public static ArrayList<Integer> e11=new ArrayList<>();
	static class FastReader 
    { 
        BufferedReader br; 
        StringTokenizer st; 
        public FastReader() 
        { 
            br = new BufferedReader(new
                     InputStreamReader(System.in)); 
        } 
        String next() 
        { 
            while (st == null || !st.hasMoreElements()) 
            { 
                try
                { 
                    st = new StringTokenizer(br.readLine()); 
                } 
                catch (IOException  e) 
                { 
                    e.printStackTrace(); 
                } 
            } 
            return st.nextToken(); 
        } 
        int nextInt() 
        { 
            return Integer.parseInt(next()); 
        } 
        long nextLong() 
        { 
            return Long.parseLong(next()); 
        } 
        double nextDouble() 
        { 
            return Double.parseDouble(next()); 
        } 
        String nextLine() 
        { 
            String str = ""; 
            try
            { 
                str = br.readLine(); 
            } 
            catch (IOException e) 
            { 
                e.printStackTrace(); 
            } 
            return str; 
        } 
    }
	 public static int n;
	  public static int w;
	  public static int[][] DP;
	public static void main(String[] args) throws Exception {
	    new Thread(null, new id48(), "Main", 1<<26).start();
	  }
	public static long[] dp=new long[1000001];
	public void run() {
		OutputStream outputStream =System.out;
	    PrintWriter out =new PrintWriter(outputStream);
	FastReader s=new FastReader();











































































	sieve();
	int t=s.nextInt();
	while(t>0) {
		int d=s.nextInt();
		int d1=1+d;


	if(!primes.contains(d1)) {
		int v1=UpperBound(primes,d1);
		d1=primes.get(v1);
	}
	int d2=d1+d;
	if(!primes.contains(d2)) {
		int v1=UpperBound(primes,d2);
		d2=primes.get(v1);
	}
	System.out.println(d1*d2);
	
	


























		t--;
	}
	
	}
	 static int UpperBound(ArrayList<Integer> a, int x) {

		    int l=-1,r=a.size();
		    while(l+1<r) {
		       int m=(l+r)>>>1;
		       if(a.get(m)<=x) l=m;
		       else r=m;
		    }
		    return l+1;
		 }
	 static int LowerBound(ArrayList<Integer> a, int x) { 

		  int l=-1,r=a.size();
		  while(l+1<r) {
		    int m=(l+r)>>>1;
		    if(a.get(m)>=x) r=m;
		    else l=m;
		  }
		  return r;
		}

	public static int[] is_prime=new int[1000001];
	public static ArrayList<Integer> primes=new ArrayList<>();
	public static void sieve() {
		long maxN=100001;
		for(int i=1;i<=maxN;i++) {
			is_prime[i]=1;
		}
		is_prime[0]=0;
		is_prime[1]=0;
		for(long i=2;i*i<=maxN;i++) {
			if(is_prime[(int) i]==1) {


				for(long j=i*i;j<=maxN;j+=i) {
					is_prime[(int) j]=0;
				}
			}
		}
		for(int i=0;i<=maxN;i++) {
			if(is_prime[i]==1) {
				primes.add(i);
			}
		}






















	}
	
	public static int gcd(int a, int b)
    {
        if (a == 0)
            return b; 
        return gcd(b % a, a); 
    }
	static int lcm(int a, int b)
    {
        return (a / gcd(a, b)) * b;
    }
     
	public static bridges[] merge_sort(bridges[] A, int start, int end) {
		if (end > start) {
			int mid = (end + start) / 2;
			bridges[] v = merge_sort(A, start, mid);
			bridges[] o = merge_sort(A, mid + 1, end);
			return (merge(v, o));
		} else {
			bridges[] y = new bridges[1];
			y[0] = A[start];
			return y;
		}
	}
	public static bridges[] merge(bridges a[], bridges b[]) {


		bridges[] temp = new bridges[a.length + b.length];
		int m = a.length;
		int n = b.length;
		int i = 0;
		int j = 0;
		int c = 0;
		while (i < m && j < n) {
			if (a[i].n < b[j].n) {
				temp[c++] = a[i++];
			
			}else if(a[i].n==b[j].n) {
				if(a[i].s<b[j].s) {
					temp[c++]=a[i++];
				}else {
					temp[c++]=b[j++];
				}
			}
			else {
				temp[c++] = b[j++];
			}
		}
		while (i < m) {
			temp[c++] = a[i++];
		}
		while (j < n) {
			temp[c++] = b[j++];
		}
		return temp;
	}
 
public static long steps(long n) {
	  if(dp[(int) n]!=0) {
		  return (int) dp[(int) n];
	  }  
	   dp[(int) n]=steps(n-1)+steps(n-2)+steps(n-3);
	  return  dp[(int) n];
  }
  public static void id53(char[] a,int n) {
	  long tot=(1<<n);
	  for(int i=0;i<tot;i++) {
		  for(int j=0;j<n;j++) {
			  if(((i)&(1<<j))!=0) {
				 System.out.print(a[j]); 
			  }
		  }
		  if(i==0) {
			  System.out.print('
		  }
		  System.out.println();
	  }
  }
  public static void Subset_sum(int[] a,int n,int sum_k) {
	  long tot=(1<<n);
	  for(int i=0;i<tot;i++) {
		  long sum=0;
		  for(int j=0;j<n;j++) {
			  if(((i)&(1<<j))!=0) {
				sum+=a[j]; 
			  }
		  }
		  if(sum==sum_k) {
			  System.out.println("YES");
		  return;
		  }
	  }
	  System.out.println("NO"); 
	  }
  public static long id16(String[] a,int n) {
	  int[] f=new int[32];
	  for(int i=0;i<n;i++) {
		  String str=a[i];


		  int h=str.length();
		  int mask=0;
		  for(int j=0;j<h;j++) {
			 if(str.charAt(j)=='a')mask=mask|(1<<0);
			 if(str.charAt(j)=='e')mask=mask|(1<<1);
			 if(str.charAt(j)=='i')mask=mask|(1<<2);
			 if(str.charAt(j)=='o')mask=mask|(1<<3);
			 if(str.charAt(j)=='u')mask=mask|(1<<4);
		  }
		  f[mask]++;
		  
	  }
	  long sum=0;
	  for(int i=1;i<32;i++) {
		  for(int j=i+1;j<32;j++) {
			  if((i|j)==31) {
				 sum=sum+(f[i]*f[j]); 
			  }
		  }
	  }
	  return sum;
  }
  public long coinChange(long[] coins, long amount) {
      int c=coins.length;
      long[] a=new long[(int) (amount+1)];
      a[0]=0;
      for(int i=1;i<amount+1;i++){
          a[i]=Long.MAX_VALUE;
      }
      for(int i=1;i<amount+1;i++){
          for(int j=0;j<c;j++){
              if(coins[j]>i){
                  continue;
              }else if(a[(int) (i-coins[j])]==Long.MAX_VALUE){
                 continue;
              }else{
                  a[i]=Math.min(a[i],a[(int) (i-coins[j])]);
              }
          }
          if(a[i]!=100000) {
        	  a[i]++;
          }
      }






      if(a[(int) amount]<100000){
          return  a[(int) amount];
      }else{
          return -1;
      }
}
  public static boolean id38(long[] a,int n,long sum) {
	  long[][] dp=new long[n+1][(int) (sum+1)];
dp[0][0]=1;	  
	for(int i=1;i<=n;i++) {
		for(int j=0;j<=sum;j++) {
			if(dp[i-1][j]==1) {
				dp[i][j]=1;
			}else {
				if((j-a[i]>=0) && (dp[i-1][(int) (j-a[i])]==1)) {
					dp[i][j]=1;
				}
			}
		}
	}
	for(int i=0;i<=n;i++) {
		for(int j=0;j<=sum;j++) {
			System.out.print(dp[i][j]);
		}
		System.out.println();
	}
	  if(dp[n][(int) sum]==1) {
		  return true;
	  }else {
		  return false;
	  }
  }
  public static void id10(int[] a,int n,int sum) {
	  int[] dp=new int[(int) (sum+1)];
	  dp[0]=1;
for(int i=1;i<=n;i++) {
	int curr=a[i];
	for(int j=sum;j>=curr;j--) {
	
		if(dp[j]!=0 || dp[j-curr]==0) {
			continue;
		}else {
			dp[j]=curr;
		}
	}
}
if(dp[sum]==0) {
	System.out.println(-1);
}else {
int curr=sum;
while(curr>0) {
	System.out.println(dp[curr]);
	curr=curr-dp[curr];
}
	
}
  }
  public static long id23(long[][] a,int n,int m) {
	  long[][] dp=new long[n][m];
	  for(int j=m-1;j>=0;j--) {
		  if(j==m-1) {
			  dp[n-1][j]=a[n-1][j];
		  }else {
			  dp[n-1][j]=dp[n-1][j+1]+a[n-1][j];
		  }
	  }
	  for(int i=n-1;i>=0;i--) {
		  if(i==n-1) {
			  dp[i][m-1]=a[i][m-1];
		  }else {
			  dp[i][m-1]=dp[i+1][m-1]+a[i][m-1];
			  
		  }
	  }
	  for(int i=n-2;i>=0;i--) {
		  for(int j=m-2;j>=0;j--) {
			  dp[i][j]=Math.min(dp[i][j+1], dp[i+1][j])+a[i][j];
		  }
	  }
	  return dp[0][0];
  }
  public static long id14(long[][] a,int n,int m,int column) {
	  long[][] dp=new long[n][m];
	  for(int j=0;j<m;j++) {
		  dp[n-1][j]=a[n-1][j];
	  }
	  for(int i=n-2;i>=0;i--) {
		  for(int j=0;j<m;j++) {
			long min=dp[i+1][j];
			if(j!=0) {
				min=Math.min(min, dp[i+1][j-1]);
			}
			if(j!=m-1) {
				min=Math.min(min, dp[i+1][j+1]);
			}
			dp[i][j]=min+a[i][j];
		  }
	  }
	  for(int i=0;i<n;i++) {
		  for(int j=0;j<m;j++) {
			  System.out.print(dp[i][j]+" ");
		  }
		  System.out.println();
	  }
	  long min=Long.MAX_VALUE;
	  for(int j=0;j<m;j++) {
		  min=Math.min(dp[0][j], min);
	  }
	  return min;
  }
  public static int id13(char[] a,int n) {
	  int k = 0,b=0;
	  int[][] dp=new int[n+1][n+1];
	  for(int i=0;i<=n;i++) {
		  dp[0][i]=dp[1][i]=1;
		  k=1;
          b=i;
	  }
	 
	  for(int i=2;i<=n;i++) {
		  for(int j=i;j<=n;j++) {
			  if(a[j]==a[j-i+1] && dp[i-2][j-1]==1) {
				  dp[i][j]=1;
				  k=i;
                  b=j;
			  }
		  }
	  }
	  














	  k=b-k+1;
	  String str="";
        for(int i=k;i<=b;i++){
            str+=a[i];
        }
        System.out.println( k+" "+b);
        System.out.println(str);
	  return k;
  }
  public static long id18(int n,int m) {
	  long[][] dp=new long[n][m];
	  for(int i=0;i<m;i++) {
		  dp[n-1][i]=1;
	  }
	  for(int i=0;i<n;i++) {
		  dp[i][m-1]=1;
	  }
	  for(int i=n-2;i>=0;i--) {
		  for(int j=m-2;j>=0;j--) {
			  dp[i][j]=dp[i+1][j]+dp[i][j+1];
		  }
	  }
	 
	  
	  return dp[0][0];
  }
  public static int id12(int[][] obstacles,int n,int m) {
	  int[][] dp=new int[n][m];
	  for(int i=0;i<n;i++) {
		  for(int j=0;j<m;j++) {
			  if(obstacles[i][j]==1) {
				  obstacles[i][j]=-1;
			  }
		  }
	  }
	  for(int i=m-1;i>=0;i--) {
		  if(obstacles[n-1][i]==-1) {
			  dp[n-1][i]=-1;
			  break;
		  }
		  dp[n-1][i]=1;
	  }
	  for(int i=n-1;i>=0;i--) {
		  if(obstacles[i][m-1]==-1) {
			  dp[i][m-1]=-1;
			  break ;
		  }
		  dp[i][m-1]=1;
	  }
	  for(int i=n-2;i>=0;i--) {
		  for(int j=m-2;j>=0;j--) {
			  if(obstacles[i][j]!=-1) {
			  if(dp[i+1][j]==-1 && dp[i][j+1]==-1)continue;
			  if(dp[i+1][j]==-1) {dp[i][j]=dp[i][j+1];continue;}
			  if(dp[i][j+1]==-1) {dp[i][j]=dp[i+1][j];continue;}
			  dp[i][j]=dp[i+1][j]+dp[i][j+1];
		  }else {
			  dp[i][j]=-1;
		  }
			  }
	  }












	  
	 if(obstacles[n-1][m-1]!=-1 && dp[0][0]!=-1){
		  return dp[0][0];}else{
	          return 0;
	      }
  }
  public static long id3(long[] a,int n) {
	  long[] dp=new long[n+1];
	  dp[1]=a[1];
	  for(int i=2;i<=n;i++) {
		  long profit=Long.MIN_VALUE;
		  for(int j=1;j<=i;j++) {
			  profit=Math.max(profit,a[j]+dp[i-j]);
		  }
		  dp[i]=profit;
	  }
	  return dp[n];
  }
 public static int id57(int[] weight,int[] val,int w,int n){
	 if(n==0 || w==0) {
		 return 0;
	 }
	 if(DP[n][(int) w]!=-1) {
		 return DP[n][ w];
	 }
	 if(weight[n]<=w) {
		 DP[n][w]= Math.max(val[n]+id57(weight,val,w-weight[n],n-1),id57(weight,val,w,n-1));
	 return DP[n][w];
	 }else {
		 DP[n][(int) w]= id57(weight,val,w,n-1);
	 return DP[n][w];
	 }
 }
 public static long id35(int[] weight,int[] val,int w,int n) {
	 int[][] dp=new int[n+1][w+1];
	 for(int i=0;i<=w;i++) {
		 dp[0][i]=0;
	 }
	 for(int i=0;i<=n;i++) {
		 dp[i][0]=0;
	 }
	 for(int i=1;i<=n;i++) {
		 for(int j=1;j<=w;j++) {
			 if(weight[i]<=j) {
				 dp[i][j]=Math.max(dp[i-1][j],val[i]+dp[i-1][j-weight[i]]);
			 }else {
				 dp[i][j]=dp[i-1][j];
			 }
		 }
	 }
	 for(int i=0;i<=n;i++) {
		 for(int j=0;j<=w;j++) {
			 System.out.print(dp[i][j]+" ");
		 }
		 System.out.println();
	 }
	 return dp[n][w];
 }
 public static boolean id21(long[] a,int n,long sum) {
	 int[][] dp=new int[n+1][(int) (sum+1)];
	 for(int i=0;i<=n;i++) {
		 dp[i][0]=1;
	 }
	 for(int i=1;i<=n;i++) {
		 for(int j=1;j<=sum;j++) {
			 if(a[i]<=j) {
				 dp[i][j]=Math.max((dp[i-1][j]),(dp[i-1][(int) (j-a[i])]));
			 }else {
				 dp[i][j]=dp[i-1][j];
			 }
		 }
	 }
	 return dp[n][(int) sum]==1;
 }
 public static boolean id8(long[] a,int n) {
	 long sum=0;
	 for(int i=1;i<=n;i++) {
		 sum+=a[i];
	 }
	 if(sum%2!=0) {
		 return false;
	 }else {
		 return id21(a,n,sum/2);
	 }
 }
 public static int id0(int[] a,int n,int sum) {
	 int[][] dp=new int[n+1][(int) (sum+1)];
	 for(int i=0;i<=n;i++) {
		 dp[i][0]=1;
	 }
	 for(int i=1;i<=n;i++) {
		 for(int j=1;j<=sum;j++) {
			 if(a[i]<=j) {
				 dp[i][j]=dp[i-1][j]+dp[i-1][(int) (j-a[i])];
			 }else {
				 dp[i][j]=dp[i-1][j];
			 }
		 }
	 }
	 for(int i=0;i<=n;i++) {
		 for(int j=0;j<=sum;j++) {
			 System.out.print(dp[i][j]+" ");
		 }
		 System.out.println();
	 }
	 return dp[n][sum];
 }
 public static int id24(int[] a,int n,int sum) {
	 int[][] dp=new int[n+1][(int) (sum+1)];
	 for(int i=0;i<=n;i++) {
		 dp[i][0]=1;
	 }
	 for(int i=1;i<=n;i++) {
		 for(int j=1;j<=sum;j++) {
			 if(a[i]<=j) {
				 dp[i][j]=Math.max((dp[i-1][j]),(dp[i-1][(int) (j-a[i])]));
			 }else {
				 dp[i][j]=dp[i-1][j];
			 }
		 }
	 }
	 int min_diff=Integer.MAX_VALUE;
	 for(int i=0;i<=sum/2+1;i++) {
		 if(dp[n][i]==1) {
			 min_diff=Math.min(min_diff, Math.abs(sum-2*i));
		 }
	 }
	 return min_diff;
 }
 public static int id46(int[] a,int n,int sum) {
	 int[][] dp=new int[n+1][(int) (sum+1)];
	 for(int i=0;i<=n;i++) {
		 dp[i][0]=1;
	 }
	 for(int i=1;i<=n;i++) {
		 for(int j=1;j<=sum;j++) {
			 if(a[i]<=j) {
				 dp[i][j]=dp[i-1][j]+dp[i-1][(int) (j-a[i])];
			 }else {
				 dp[i][j]=dp[i-1][j];
			 }
		 }
	 }
	 int count=0;
	 int min_diff=Integer.MAX_VALUE;
	 for(int i=0;i<=sum/2+1;i++) {
		 if(dp[n][i]==1) {
			 if(Math.abs(sum-2*i)<min_diff) {
				 min_diff=Math.abs(sum-2*i);
				 count=dp[n][i];
			 }
		 }
	 }
	return count; 
 }
 public static int id19(int[] a,int n,int sum,int diff) {
	 int sum_eff=(sum+diff)/2;
	 int[][] dp=new int[n+1][(int) (sum_eff+1)];
	 dp[0][0]=1;
	 for(int i=1;i<=n;i++) {
		 for(int j=0;j<=sum_eff;j++) {
			 if(a[i]<=j) {
				 dp[i][j]=dp[i-1][j]+dp[i-1][(int) (j-a[i])];
			 }else {
				 dp[i][j]=dp[i-1][j];
			 }
			 
		 }
	 }
	 for(int i=0;i<=n;i++) {
		 for(int j=0;j<=sum_eff;j++) {
			 System.out.print(dp[i][j]+" ");
		 }
		 System.out.println();
	 }
	 return dp[n][sum_eff];
	 
 }
 public static long id29(int[] weight,int[] val,int w,int n) {
	 int[][] dp=new int[n+1][w+1];
	 for(int i=1;i<=n;i++) {
		 for(int j=0;j<=w;j++) {
			 if(weight[i]<=j) {
				 dp[i][j]=Math.max(dp[i-1][j],val[i]+dp[i][j-weight[i]]);
			 }else {
				 dp[i][j]=dp[i-1][j];
			 }
		 }
	 }
	 for(int i=0;i<=n;i++) {
		 for(int j=0;j<=w;j++) {
			 System.out.print(dp[i][j]+" ");
		 }
		 System.out.println();
	 }
	 return dp[n][w];
 }
 public static int id52(int[] id37,int[] val,int n,int length) {
	int[][] dp=new int[n+1][length+1];
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=length;j++) {
			if(id37[i]<=j) {
				dp[i][j]=Math.max(dp[i-1][j], val[i]+dp[i][j-id37[i]]);
			}else {
				dp[i][j]=dp[i-1][j];
			}
		}
	}
	return dp[n][length];
 }
 public static int id39(int[] a,int n,int sum) {
	 int[][] dp=new int[n+1][sum+1];
	 dp[0][0]=1;
	 for(int i=1;i<=n;i++) {
		 dp[i][0]=1;
	 }
	 for(int i=1;i<=n;i++) {
		 for(int j=0;j<=sum;j++) {
			 if(a[i]<=j) {
				 dp[i][j]=dp[i-1][j]+dp[i][j-a[i]];
			 }else {
				 dp[i][j]=dp[i-1][j];
			 }
		 }
	 }
	 for(int i=0;i<=n;i++) {
		 for(int j=0;j<=sum;j++) {
			 System.out.print(dp[i][j]+" ");
		 }
		 System.out.println();
	 }
	 return dp[n][sum];
 }
 public static int id50(int[] a,int n,int sum) {
	 int[][] dp=new int[n+1][sum+1];
	 int b=Integer.MAX_VALUE-1;
	 for(int i=0;i<=sum;i++) {
		 dp[0][i]=b;
	 }
	 for(int i=0;i<=sum;i++) {
		 if(i%a[1]==0) {
			 dp[1][i]=i/a[1];
		 }else {
			 dp[1][i]=b;
		 }
	 }
	 for(int i=2;i<=n;i++) {
		 for(int j=0;j<=sum;j++) {
			 if(a[i]<=j) {
				 dp[i][j]=Math.min(dp[i-1][j],1+dp[i][j-a[i]]);
			 }else {
				 dp[i][j]=dp[i-1][j];
			 }
		 }
	 }
	 for(int i=0;i<=n;i++) {
		 for(int j=0;j<=sum;j++) {
			 System.out.print(dp[i][j]+" ");
		 }
		 System.out.println();
	 }
	 return dp[n][sum];
 }
public static int id58(String str1,String str2,int n,int m,int[][] dp) {
	if(n==0 || m==0) {
		return 0;
	}
	if(dp[n][m]!=-1) {
		return dp[n][m];
	}
	if(str1.charAt(n-1)==str2.charAt(m-1)) {
		int f= 1+id58(str1,str2,n-1,m-1,dp);
		dp[n][m]=f;
		return f;
	}else {
		int f= Math.max(id58(str1,str2,n-1,m,dp),id58(str1,str2,n,m-1,dp));
		dp[n][m]=f;
		return f;
	}
}
public static int id6(String str1,String str2,int n,int m) {
	int[][] dp=new int[n+1][m+1];
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			if(str1.charAt(i-1)==str2.charAt(j-1)) {
				dp[i][j]=1+dp[i-1][j-1];
			}else {
				dp[i][j]=Math.max(dp[i][j-1], dp[i-1][j]);		
				}
		}
	}
return dp[n][m];
}
public static int id20(String str1,String str2,int n,int m) {
	int[][] dp=new int[n+1][m+1];
	for(int i=0;i<=n;i++) {
		dp[i][0]=0;
	}
	for(int i=0;i<=m;i++) {
		dp[0][i]=0;
	}
	int max=Integer.MIN_VALUE;
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			if(str1.charAt(i-1)==str2.charAt(j-1)) {
				dp[i][j]=1+dp[i-1][j-1];
				max=Math.max(max, dp[i][j]);
			}else {
				dp[i][j]=0;
			}
		}
	}
	
	return max;
}
public static void id15(String str1,String str2,int n,int m) {
	int[][] dp=new int[n+1][m+1];
	for(int i=0;i<=n;i++) {
		dp[i][0]=0;
	}
	for(int i=0;i<=m;i++) {
		dp[0][i]=0;
	}
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			if(str1.charAt(i-1)==str2.charAt(j-1)) {
				dp[i][j]=1+dp[i-1][j-1];
			}else {
				dp[i][j]=Math.max(dp[i][j-1], dp[i-1][j]);
			}
		}
	}
	int i=n;
	int j=m;
	String str="";
	while(i>0 && j>0) {
		if(str1.charAt(i-1)==str2.charAt(j-1)) {
			str+=str1.charAt(i-1);
			i--;
			j--;
		
		}else {
			if(dp[i][j-1]>dp[i-1][j]) {
				j--;
			}else {
				i--;
			}
		}
	}
	int v=str.length();
	for(int u=v-1;u>=0;u--) {
		System.out.print( str.charAt(u));
	}	
	System.out.println();
}
public static int id47(String str1,String str2,int n,int m) {
	int[][] dp=new int[n+1][m+1];
	for(int i=0;i<=n;i++) {
		dp[i][0]=0;
	}
	for(int i=0;i<=m;i++) {
		dp[0][i]=0;
	}
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			if(str1.charAt(i-1)==str2.charAt(j-1)) {
				dp[i][j]=1+dp[i-1][j-1];
			}else {
				dp[i][j]=Math.max(dp[i][j-1], dp[i-1][j]);
			}
		}
	}
	return n+m-dp[n][m];
}
public static int id51(String str1,String str2,int n,int m) {
	int lcs=id6(str1,str2,n,m);
	int id44=n-lcs;
	int id28=m-lcs;
	return (id44+id28);
}
public static int id31(String str1,int n) {
	String reverse="";
	for(int i=n-1;i>=0;i--) {
		reverse+=str1.charAt(i);
	}
	int lcs=id6(str1,reverse,n,n);


	return lcs;
}
public static int id62(String str,int n) {
	int lps=id31(str,n);
	return n-lps;
} 
public static void id26(String str1,String str2,int n,int m) {
	int[][] dp=new int[n+1][m+1];
	for(int i=0;i<=n;i++) {
		dp[i][0]=0;
	}
	for(int i=0;i<=m;i++) {
		dp[0][i]=0;
	}
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			if(str1.charAt(i-1)==str2.charAt(j-1)) {
				dp[i][j]=1+dp[i-1][j-1];
			}else {
				dp[i][j]=Math.max(dp[i][j-1], dp[i-1][j]);
			}
		}
	}
	int i=n;
	int j=m;
	String str="";
	while(i>0 && j>0) {
		if(str1.charAt(i-1)==str2.charAt(j-1)) {
			str+=str1.charAt(i-1);
			i--;
			j--;
		
		}else {
			if(dp[i][j-1]>dp[i-1][j]) {
				str+=str2.charAt(j-1);
				j--;
			}else {
				str+=str1.charAt(i-1);
				i--;
			}
		}
	}
	while(i>0) {
		str+=str1.charAt(i-1);
		i--;
	}
	while(j>0) {
		str+=str2.charAt(j-1);
		j--;
	}
	int v=str.length();
	for(int u=v-1;u>=0;u--) {
		System.out.print( str.charAt(u));
	}	
	System.out.println();
}
public static int id40(String str,int n) {
	int[][] dp=new int[n+1][n+1];
	for(int i=0;i<=n;i++) {
		dp[i][0]=0;
	}
	for(int i=0;i<=n;i++) {
		dp[0][i]=0;
	}
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			if(str.charAt(i-1)==str.charAt(j-1) &&  i!=j) {
				dp[i][j]=1+dp[i-1][j-1];
			}else {
				dp[i][j]=Math.max(dp[i][j-1], dp[i-1][j]);
			}
		}
	}	
	return dp[n][n];
}
public static boolean id61(String str1,String str2,int n,int m) {
	int g=id6(str1,str2,n,m);
	int length=Math.min(n, m);
	if(g==length) {
		return true;
	}else {
		return false;
	}
}
public static long[][] Dp=new long[1001][1001];
public static long id27(int[] a,int i,int j,int n) {
	if(i==j) {
		return 0;}
	if(Dp[i][j]!=-1) {
		return Dp[i][j];
	}
		long min=Long.MAX_VALUE;
		for(int k=i;k<j;k++) {
			long temp=id27(a,i,k,n)+id27(a,k+1,j,n)+a[i-1]*a[k]*a[j];
			if(temp<min) {
				min=temp;
		}
	}
		Dp[i][j]=min;
	return Dp[i][j];
}
public static boolean IsPalindrome(String str,int a,int b) {
	boolean p=true;
	int i=a;
	int j=b;
	while(i<=j) {
		if(str.charAt(i)!=str.charAt(j)) {
			p=false;
			break;
		}
		i++;
		j--;
	}
	return p;
}
public static long id17(String str,int i,int j) {
	if(i>=j) {
		return 0;
	}
	if(IsPalindrome(str,i,j)) {
		return 0;
	}
	if(Dp[i][j]!=-1) {
		return Dp[i][j];
	}
	long min=Long.MAX_VALUE;
	for(int k=i;k<j;k++) {
		long temp=0;
		if(Dp[i][k]!=-1) {
			temp+=Dp[i][k];
		}else {
			temp+=id17(str,i,k);
		}
		if(Dp[k+1][j]!=-1) {
			temp+=Dp[k+1][j];
		}else {
			temp+=id17(str,k+1,j);
		}
		 temp+=1;
		if(temp<min) {
			min=temp;
		}
		Dp[i][j]=min;
		
	}
	return min;
}
public static int id1(int[] a,int n) {
	 int dp[][] = new int[n][n];
     int q = 0;
     for(int l=2; l < a.length; l++){
         for(int i=0; i < a.length - l; i++){
             int j = i + l;
             dp[i][j] = 1000000;
             for(int k=i+1; k < j; k++){
                 q = dp[i][k] + dp[k][j] + a[i]*a[k]*a[j];
                 if(q < dp[i][j]){
                     dp[i][j] = q;
                 }
             }
         }
     }
     for(int i=0;i<n;i++) {
    	 for(int j=0;j<n;j++) {
    		 System.out.print(dp[i][j]+" ");
    	 }
    	 System.out.println();
     }
     return dp[0][n-1];
}
public static int id25(String str,int n) {
	boolean[][] p=new boolean[n][n];
	int[][] c=new int[n][n];
	for(int i=0;i<n;i++) {
		p[i][i]=true;
		c[i][i]=0;
	}
	for(int l=2;l<n;l++) {
		for(int i=0;i<n-l+1;i++) {
			int j=i+l-1;
			if(l==2) {
				if(str.charAt(i)==str.charAt(j)) {
					p[i][j]=true;
					c[i][j]=0;
				}else {
					p[i][j]=false;
					c[i][j]=1;
				}
			}else {
				if(str.charAt(i)==str.charAt(j) && p[i+1][j-1]) {
					p[i][j]=true;
					c[i][j]=0;
				}else {
					 c[i][j] = Integer.MAX_VALUE; 
	                    for (int k = i; k <= j - 1; k++) { 
	                        c[i][j] = Integer.min(c[i][j], 
	                                              c[i][k] + c[k + 1][j] + 1);} 
	                } 
				}
			}
			
		}
	return c[0][n-1];
	}
public static int id4(String str,int n) {
	boolean[][] p=new boolean[n][n];
	int[][] count=new int[n][n];
	for(int g=0;g<n;g++) {
		for(int i=0,j=g;j<n;i++,j++) {
			if(g==0) {
				count[i][j]=0;
				p[i][j]=true;
			}else {
				if(str.charAt(i)==str.charAt(j) && p[i+1][j-1]) {
					count[i][j]=0;
					p[i][j]=true;
				}else {
					count[i][j]=Integer.MAX_VALUE;
					for(int k=i;k<j;k++) {
						int temp=count[i][k]+count[k+1][j];
						count[i][j]=Math.min(count[i][j], temp);
					}
				}
			}
		}
	}
	return count[0][n-1];
}
public static int id11(String str1,String str2) {
	int n=str1.length();
	int[][] dpt=new int[n][n];
	int[][] dpf=new int[n][n];
	for(int g=0;g<n;g++) {
		for(int i=0,j=g;j<n;i++,j++) {
			if(g==0) {
				if(str1.charAt(i)=='T') {
					dpt[i][j]=1;
					dpf[i][j]=0;
				}else {
					dpt[i][j]=0;
					dpf[i][j]=1;
				}
			}else {
				for(int k=i;k<j;k++) {
					int lt=dpt[i][k];
					int rt=dpt[k+1][j];
					int lf=dpf[i][k];
					int rf=dpf[k+1][j];
					if(str2.charAt(k)=='&') {
						dpt[i][j]+=lt*rt;
						dpf[i][j]+=lt*rf+lf*rt+rf*lf;
					}else if(str2.charAt(k)=='|') {
						dpt[i][j]+=lt*rf+lf*rt+rt*lt;
						dpf[i][j]+=rf*lf;
					}else {
						dpt[i][j]+=lt*rf+lf*rt;
						dpf[i][j]+=lf*rf+lt*rt;
					}
				}
			}
		}
	}
	return dpt[0][n-1];
}
public static int id63(int[] a,int n) {
    int[][] dp=new int[n][n];
for(int g=2;g<n;g++) {
	for(int i=0,j=g;j<n;j++,i++) {
	    dp[i][j]=Integer.MAX_VALUE;
		for(int k=i+1;k<j;k++) {
			dp[i][j]=Math.min(dp[i][j], dp[i][k]+dp[k][j]+a[i]*a[k]*a[j]);
		}
	}}
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			System.out.print(dp[i][j]+" ");
		}
		System.out.println();
	}

return dp[0][n-1];
}
public static HashMap<String,Integer> um=new HashMap<>();
public static int id54(String str1,String str2) {
	if(str1.length()!=str2.length()) {
		return 0;
	}
	if((str1.length()==0) || (str2.length()==0)) {
		return 1;
	}
	if(str1.equals(str2)) {
		return 1;
	}
	String g=str1+" "+str2;
	if(um.containsKey(g)) {
		return um.get(g);
	}
	int n=str1.length();
	int flag=0;
	for(int i=1;i<n;i++) {
		if ((id54(str1.substring(0, i), 
				str2.substring(0, i))==1) && 
		(id54(str1.substring(i, n),
				str2.substring(i, n))==1))
	{
		flag=1;
		
		um.put(g, 1);
		return flag;
	}

	

	

	

	if ((id54(str1.substring(n - i, n),
				str2.substring(0, i))==1) && 
		(id54(str1.substring(0, n - i),
				str2.substring(i, n))==1)) 
	{
		flag=1;
		um.put(g, 1);
		return flag;
	}
}
	um.put(g, flag);
	return flag;
	}
public static long id49(long e,long f) {
	if(Dp[(int) e][(int) f]!=-1) {
		return Dp[(int) e][(int) f];
	}
	if(f==0 || f==1) {
		return f;
	}
	if(e==0) {
		return 0;
	}
	Long min=Long.MAX_VALUE;
	for(long k=1;k<=f;k++) {
		long solve1,solve2=0;
		if(Dp[(int) e][(int) (f-k)]!=-1) {
			solve1=Dp[(int) e][(int) (f-k)];
		}else {
		 solve1=id49(e,f-k);}
		if(Dp[(int) (e-1)][(int) (k-1)]!=-1) {
			solve2=Dp[(int) (e-1)][(int) (k-1)];
		}else {
		 solve2=id49(e-1,k-1);}
		long temp=Math.max(solve1,solve2)+1;
		min=Math.min(min, temp);
	}
	Dp[(int) e][(int) f]=min;
	return min;
}
public static int id9(int[] a) {
	int n=a.length;
	int[] dp=new int[n];
	dp[0]=1;
	int maximum=1;
	for(int i=1;i<n;i++) {
		int max=0;
		for(int j=0;j<i;j++) {
			if(a[i]>a[j]) {
				max=Integer.max(dp[j], max);
			}
		}
		dp[i]=max+1;
		maximum=Integer.max(maximum, dp[i]);
	}
	return maximum;
}
public static long id33(int[] a) {
	int n=a.length;
	long[] dpsum=new long[n];
	dpsum[0]=a[0];
	long maximum=a[0];
	for(int i=1;i<n;i++) {
		int max=0;
		long maxsum=Integer.MIN_VALUE;
		for(int j=0;j<i;j++) {
			if(a[i]>=a[j]) {
				maxsum=Long.max(dpsum[j], maxsum);
			}
		}
		if(maxsum==Integer.MIN_VALUE) {
			dp[i]=a[i];
		}else {
			dp[i]=maxsum+a[i];
		}
		maximum=Math.max(maximum, dpsum[i]);
	}
	return maximum;
}
public static int id2(int[] a) {
	int n=a.length;
	int[] lis=new int[n];
	lis[0]=1;
	for(int i=1;i<n;i++) {
		int max=0;
		for(int j=0;j<i;j++) {
			if(a[i]>a[j]) {
				max=Integer.max(lis[j], max);
			}
		}
		lis[i]=max+1;
	}
	int[] lds=new int[n];
	lds[n-1]=1;
	for(int i=n-2;i>=0;i--) {
		int max=0;
		for(int j=n-1;j>i;j--) {
			if(a[i]>a[j]) {
				max=Integer.max(lds[j], max);
			}
		}
		lds[i]=max+1;
	}
	int id43=0;
	for(int i=0;i<n;i++) {
		id43=Math.max(id43, lis[i]+lds[i]-1);
	}
	return id43;
}
public static class bridges {
	int n;
	int s;
	bridges(int n,int s){
		this.n=n;
		this.s=s;
	}
}
public static int id56(bridges[] a,int n) {
	bridges[] b=merge_sort(a,0,n-1);
	int[] dp=new int[n];
	dp[0]=1;
	int maximum=Integer.MIN_VALUE;
	for(int i=1;i<n;i++) {
		int max=0;
		for(int j=0;j<i;j++) {
			if(b[i].s>=b[j].s ) {
				max=Math.max(dp[j], max);
			}
		}
		dp[i]=max+1;
		maximum=Math.max(maximum, dp[i]);
	}
	return maximum;
}
public static int id36(String str) {
	int n=str.length();
	boolean[][] dp=new boolean[n][n];
	int count=0;
	for(int g=0;g<n;g++) {
		for(int i=0,j=g;j<n;i++,j++) {
			if(g==0) {
				dp[i][j]=true;
			}else if(g==1) {
				if(str.charAt(i)==str.charAt(j)) {
					dp[i][j]=true;
				}else {
					dp[i][j]=false;
				}
			}else {
				if(str.charAt(i)==str.charAt(j) && dp[i+1][j-1]) {
					dp[i][j]=true;
				}else {
					dp[i][j]=false;
				}
			}
			if(dp[i][j]) {
				count++;
			}
		}
		}
	
	return count;
}
public static int id42(String str) {
	int n=str.length();
	boolean[][] dp=new boolean[n][n];
	int length=0;
	for(int g=0;g<n;g++) {
		for(int i=0,j=g;j<n;i++,j++) {
			if(g==0) {
				dp[i][j]=true;
			}else if(g==1) {
				if(str.charAt(i)==str.charAt(j)) {
					dp[i][j]=true;
				}else {
					dp[i][j]=false;
				}
			}else {
				if(str.charAt(i)==str.charAt(j) && dp[i+1][j-1]) {
					dp[i][j]=true;
				}else {
					dp[i][j]=false;
				}
			}
			if(dp[i][j]) {
				length=g+1;
			}
		}
	}
		return length;
}
public static void id45(int[][] a,int n,int m) {
	int[][] dp=new int[n][m];
	for(int i=m-1;i>=0;i--) {
		if(i==m-1) {
			dp[n-1][m-1]=a[n-1][m-1];
		}else {
			dp[n-1][i]+=dp[n-1][i+1]+a[n-1][i];
		}
	}
	for(int i=n-1;i>=0;i--) {
		if(i==n-1) {
			dp[n-1][m-1]=a[n-1][m-1];
		}else {
			dp[i][m-1]+=dp[i+1][m-1]+a[i][m-1];
		}
	}
	for(int i=n-2;i>=0;i--) {
		for(int j=m-2;j>=0;j--) {
			dp[i][j]=Math.min(dp[i+1][j], dp[i][j+1])+a[i][j];
		}
	}
	System.out.println(dp[0][0]);
	Queue<pair> q=new LinkedList<>();
	q.add(new pair("",0,0));
	while(!q.isEmpty()) {
		pair curr=q.poll();
		if(curr.i==n-1 && curr.j==m-1) {
			System.out.println(curr.str);
		}else if(curr.i==n-1) {
			q.add(new pair(curr.str+"H",curr.i,curr.j+1));
		}else if(curr.j==m-1) {
			q.add(new pair(curr.str+"V",curr.i+1,curr.j));
		}else {
			if(dp[curr.i+1][curr.j] <dp[curr.i][curr.j+1]) {
				q.add(new pair(curr.str+"V",curr.i+1,curr.j));
			}else if(dp[curr.i+1][curr.j] >dp[curr.i][curr.j+1]) {
				q.add(new pair(curr.str+"H",curr.i,curr.j+1));
			}else {
				q.add(new pair(curr.str+"V",curr.i+1,curr.j));
				q.add(new pair(curr.str+"H",curr.i,curr.j+1));
			}
		}
		
	}
}
public static class pair{
	private String str;
	private int i;
	private int j;
	pair(String str,int i,int j){
		this.str=str;
		this.i=i;
		this.j=j;
	}
}
public static void id30(int[] a) {
	int n=a.length;
	int[] dp=new int[n];
	for(int i=n-1;i>=0;i--) {
		if(i==n-1) {
			dp[i]=0;
		}else if(a[i]>=n-i-1){
			dp[i]=1;
		}else if(a[i]==0){
			dp[i]=Integer.MAX_VALUE;
		}else {
			int min=Integer.MAX_VALUE;
			for(int j=i+1;j<=i+a[i];j++) {
				min=Math.min(min, dp[j]);
			}
			if(min!=Integer.MAX_VALUE) {
				dp[i]=min+1;
			}else {
				dp[i]=min;
			}
		}
	}
	System.out.println(dp[0]);
	Queue<pair> q=new LinkedList<>();
	q.add(new pair("0",0,dp[0]));
	while(!q.isEmpty()) {
		pair curr=q.poll();
		if(curr.i==n-1) {
			System.out.println(curr.str+" .");
		}else {
			for(int k=curr.i+1;k<=curr.i+a[curr.i] && k<n;k++) {
				if(dp[k]==curr.j-1) {
					q.add(new pair(curr.str+" -> "+k,k,dp[k]));
				}
			}
		}
	}
}
public static long id59(String str) {
	int n=str.length();
	long[] dp=new long[n+1];
	dp[0]=1;
	HashMap<Character,Integer> e=new HashMap<>();
	for(int i=1;i<=n;i++) {
		if(!e.containsKey(str.charAt(i-1))) {
			dp[i]=2*dp[i-1];
			e.put(str.charAt(i-1), i);
		}else {
			dp[i]=2*dp[i-1]-dp[(e.get(str.charAt(i-1)))-1];
			e.remove(str.charAt(i-1));
			e.put(str.charAt(i-1), i);
		}
	}
	return dp[n]-1;
	
}
public static void id60(int[] a) {
	int n=a.length;
	int[] dp=new int[n];
	dp[0]=1;
	int maximum=1;
	int k=0;
	for(int i=1;i<n;i++) {
		int max=0;
		for(int j=0;j<i;j++) {
			if(a[i]>=a[j]) {
				max=Integer.max(dp[j], max);
			}
		}
		dp[i]=max+1;
		if(dp[i]>maximum) {
			maximum=dp[i];
			k=i;
		}
	}
	System.out.println(maximum);
	Queue<pair> q=new LinkedList<>();
	for(int i=0;i<n;i++) {
		if(dp[i]==maximum) {
			q.add(new pair(""+a[i],i,dp[i]));		
		}
	}
	
	while(!q.isEmpty()) {
		pair curr=q.poll();
		if(curr.j==1) {
			System.out.println(curr.str);
		}else {
			for(int j=curr.i-1;j>=0;j--) {
				if(a[j]<=a[curr.i] && dp[j]==curr.j-1) {
					q.add(new pair(a[j]+" -> "+curr.str,j,dp[j]));
				}
			}
		}
	}
	
}
public static int id32(String str) {
	int n=str.length();
	int[][] dp=new int[n][n];
	for(int g=0;g<n;g++) {
		for(int i=0,j=g;j<n;i++,j++) {
			if(g==0) {
				dp[i][j]=1;
			}else if(g==1) {
				if(str.charAt(i)==str.charAt(j)) {
					dp[i][j]=3;
				}else {
					dp[i][j]=2;
				}
			}else {
				if(str.charAt(i)==str.charAt(j)) {
					dp[i][j]=dp[i][j-1]+dp[i+1][j]+1;
				}else {
					dp[i][j]=dp[i][j-1]+dp[i+1][j]-dp[i+1][j-1];
				}
			}
		}}
		return dp[0][n-1];
	
}
public static void id22(int[][] a,int n,int m) {
int[][] dp=new int[n][m];
for(int i=0;i<n;i++) {
	dp[i][m-1]=a[i][m-1];
}
for(int j=m-2;j>=0;j--) {
for(int i=0;i<n;i++) {
	if(i==0) {
		dp[i][j]=Math.max(dp[i][j+1], dp[i+1][j+1])+a[i][j];
	}else if(i==n-1) {
		dp[i][j]=Math.max(dp[i][j+1], dp[i-1][j+1])+a[i][j];
	}else {
		dp[i][j]=Math.max(dp[i][j+1], Math.max(dp[i+1][j+1],dp[i-1][j+1]))+a[i][j];
	}
}
}
int max=Integer.MIN_VALUE;
for(int i=0;i<n;i++) {
	if(dp[i][0]>max) {
		max=dp[i][0];
	}
}
System.out.println(max);
Queue<pair> q=new LinkedList<>();
for(int i=0;i<n;i++) {
	if(dp[i][0]==max) {
		q.add(new pair(""+(i)+" ",i,0));
		
	}
}
while(!q.isEmpty()) {
	pair curr=q.poll();
	if(curr.j==m-1) {
		System.out.println(curr.str);
	}else {
		if(curr.i==n-1) {
			int max1=Math.max(dp[curr.i][curr.j+1],dp[curr.i-1][curr.j+1]);
			if(dp[curr.i][curr.j+1]==max1) {
				q.add(new pair(curr.str+"d2 ",curr.i,curr.j+1));
			}
			if(dp[curr.i-1][curr.j+1]==max1) {
				q.add(new pair(curr.str+"d1 ",curr.i-1,curr.j+1));
			}
			
		}else if(curr.i==0) {
			int max1=Math.max(dp[curr.i][curr.j+1],dp[curr.i+1][curr.j+1]);
			if(dp[curr.i][curr.j+1]==max1) {
				q.add(new pair(curr.str+"d2 ",curr.i,curr.j+1));
			}
			if(dp[curr.i+1][curr.j+1]==max1) {
				q.add(new pair(curr.str+"d3 ",curr.i+1,curr.j+1));
			}

		}else {
			int max1=Math.max(dp[curr.i][curr.j+1],Math.max(dp[curr.i-1][curr.j+1],dp[curr.i+1][curr.j+1]));
			if(dp[curr.i-1][curr.j+1]==max1) {
				q.add(new pair(curr.str+"d1 ",curr.i-1,curr.j+1));
			}
			if(dp[curr.i][curr.j+1]==max1) {
				q.add(new pair(curr.str+"d2 ",curr.i,curr.j+1));
			}
			
			if(dp[curr.i+1][curr.j+1]==max1) {
				q.add(new pair(curr.str+"d3 ",curr.i+1,curr.j+1));
			}

		}
	}
}

}
public static void id41(int[] a,int sum) {
	int n=a.length;
	boolean[][] dp=new boolean[n+1][sum+1];
	for(int i=0;i<=n;i++) {
		dp[i][0]=true;
	}
	
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=sum;j++) {
			if(dp[i-1][j]) {
				dp[i][j]=true;
			}else if(a[i-1]<=j&&dp[i-1][j-a[i-1]]) {
				dp[i][j]=true;
			}
		}
	}
	System.out.println(dp[n][sum]);
	if(dp[n][sum]) {
	Queue<pair> q=new LinkedList<>();
	q.add(new pair("",n,sum));
	while(!q.isEmpty()) {
		pair curr=q.poll();
		if(curr.i==0 || curr.j==0) {
				System.out.println(curr.str);
		}else {
			if(a[curr.i-1]<=curr.j && dp[curr.i-1][curr.j-a[curr.i-1]]) {
				q.add(new pair((curr.i-1)+" "+curr.str,curr.i-1,curr.j-a[curr.i-1]));
			}
			if(dp[curr.i-1][curr.j]) {
				q.add(new pair(curr.str,curr.i-1,curr.j));
			}
			
			
		}
	}
	}
}
public static void id55(int[] a,int[] p,int sum) {
int n=a.length;
int[][] dp=new int[n+1][sum+1];
for(int i=1;i<=n;i++) {
	for(int j=1;j<=sum;j++) {
		if(a[i-1]>j) {
			dp[i][j]=dp[i-1][j];
		}else {
			dp[i][j]=Math.max(dp[i-1][j], dp[i-1][j-a[i-1]]+p[i-1]);
		}
	}
}
System.out.println(dp[n][sum]);
Queue<pair> q=new LinkedList<>();
q.add(new pair("",n,sum));
while(!q.isEmpty()) {
	pair curr=q.poll();
	if(curr.i==0 || curr.j==0) {
		System.out.println(curr.str);
	}else {
		if( curr.j>=a[curr.i-1] && dp[curr.i-1][curr.j-a[curr.i-1]]+p[curr.i-1]==dp[curr.i][curr.j]) {
			q.add(new pair(curr.i-1+" "+curr.str,curr.i-1,curr.j-a[curr.i-1]));
		}
		if(dp[curr.i-1][curr.j]==dp[curr.i][curr.j]) {
			q.add(new pair(curr.str,curr.i-1,curr.j));
		}
		
	}
}


}
public static int id34(String str) {
int n=str.length();
int[][] dp=new int[n][n];
for(int g=0;g<n;g++) {
	for(int i=0,j=g;j<n;j++,i++) {
		if(g==0) {
			dp[i][j]=1;
		}else if(g==1) {
			if(str.charAt(i)==str.charAt(j)) {
				dp[i][j]=2;
			}else {
				dp[i][j]=1;
			}
		}else {
			if(str.charAt(i)==str.charAt(j)) {
				dp[i][j]=2+dp[i+1][j-1];
			}else {
				dp[i][j]=Math.max(dp[i][j-1], dp[i+1][j]);
			}
		}
	}
}
return dp[0][n-1];
}
public static void id7(String str,String pattern) {
	int m=str.length();
	int n=pattern.length();
	boolean[][] dp=new boolean[n+1][m+1];
	dp[n][m]=true;
	for(int i=n-1;i>=0;i--) {
		for(int j=m;j>=0;j--) {
		if(j==m) {
		dp[i][m]=dp[i+1][m];
		}else if((pattern.charAt(i)==str.charAt(j)) || (pattern.charAt(i)=='?')) {
				dp[i][j]=dp[i+1][j+1];
			}else if(pattern.charAt(i)=='*') {
				dp[i][j]=(dp[i+1][j] | dp[i][j+1]);
			}else {
				dp[i][j]=false;
			}
		}
	}
	System.out.println(dp[0][0]);
}
public static void id5(String str,String pattern) {
int n=pattern.length();
int m=str.length();
boolean[][] dp=new boolean[n+1][m+1];
dp[0][0]=true;
for(int i=1;i<=n;i++) {
	for(int j=0;j<=m;j++) {
		if(j==0) {
			if(pattern.charAt(i-1)=='*') {
			dp[i][0]=dp[i-2][0];}
		}else if((str.charAt(j-1)==pattern.charAt(i-1)) || (pattern.charAt(i-1)=='.')) {
			dp[i][j]=dp[i-1][j-1];
		}else if(pattern.charAt(i-1)=='*') {
			if(dp[i-2][j]) {
				dp[i][j]=true;
			}else if((pattern.charAt(i-2)=='.')||(pattern.charAt(i-2)==str.charAt(j-1))) {
				dp[i][j]=dp[i][j-1];
			}
		}
	}
}
System.out.println(dp[n][m]);
}
}