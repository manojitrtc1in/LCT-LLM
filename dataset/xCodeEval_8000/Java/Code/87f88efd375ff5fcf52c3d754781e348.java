import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Map;
import java.util.Queue;
import java.util.Stack;
import java.util.StringTokenizer;







public class asdasas implements Runnable {
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
	    new Thread(null, new asdasas(), "Main", 1<<26).start();
	  }
	public static long[] dp=new long[1000001];
	public void run() {
		OutputStream outputStream =System.out;
	    PrintWriter out =new PrintWriter(outputStream);
	FastReader s=new FastReader();

	int t=s.nextInt();
	while(t>0) {
		int n=s.nextInt();
		long[] f=new long[n+1];
		if(n%2==0) {
		boolean p=false;
		for(int i=1;i<=n;i++) {
			p=!p;
			int k=0;
			if(p) {
				k=1;
			}
			for(int j=i+1;j<=n;j++) {
				if(f[i]==f[j]) {
					f[i]++;
					f[j]++;
					out.print(0+" ");
				}else if(k==1) {
					f[i]+=3;
					out.print(1+" ");
					k=0;
				}else {
					f[j]+=3;
					out.print(-1+" ");
					k=1;
				}
			}
		}






		out.println();
		}else {
			int k=1;
			for(int i=1;i<=n;i++) {

				for(int j=i+1;j<=n;j++) {
					 if(k==1) {
						f[i]+=3;
						out.print(1+" ");
						k=0;
					}else {
						f[j]+=3;
						out.print(-1+" ");
						k=1;
					}
				}
			}






			out.println();	
		}
		t--;
	}
	out.close();
	}
	public static class pair{
		private long a;
		private long b;
		pair(long a,long b){
			this.a=a;
			this.b=b;
		}
	}
	public static pair[] merge_sort(pair[] A, int start, int end) {
		if (end > start) {
			int mid = (end + start) / 2;
			pair[] v = merge_sort(A, start, mid);
			pair[] o = merge_sort(A, mid + 1, end);
			return (merge(v, o));
		} else {
			pair[] y = new pair[1];
			y[0] = A[start];
			return y;
		}
	}
	public static pair[] merge(pair a[], pair b[]) {


		pair[] temp = new pair[a.length + b.length];
		int m = a.length;
		int n = b.length;
		int i = 0;
		int j = 0;
		int c = 0;
		while (i < m && j < n) {
			if (a[i].a < b[j].a) {
				temp[c++] = a[i++];
			
			}else if(a[i].a==b[j].a) {
				if(a[i].b<=b[j].b) {
					temp[c++] = a[i++];
				}else {
					temp[c++] = b[j++];
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
	static int bc(int n, int k)
    {
        int C[][] = new int[n + 1][k + 1];
        int i, j;
 
        

        

        for (i = 0; i <= n; i++) {
            for (j = 0; j <= Math.min(i, k); j++) {
                

                if (j == 0 || j == i)
                    C[i][j] = 1;
 
                

                

                else
                    C[i][j] = (C[i - 1][j - 1] + C[i - 1][j])%(1000000007);
            }
        }
 
        return C[n][k];}
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
	
	public static long res=1;
	public static  int[] arr=new int[1000001];


	public static ArrayList<Integer> prime_vector=new ArrayList<>();
	public static ArrayList<pair> prime_pairs=new ArrayList<>();


	public static void prime_factorization(long n) {
		for(long i=3;i*i<=n;i+=2) {
			if(n%i==0 &&(i%2!=0)) {
				long count=0;
				while(n%i==0) {
					count++;
					n/=i;
				}

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
	public static long[] merge_sort(long[] A, int start, int end) {
		if (end > start) {
			int mid = (end + start) / 2;
			long[] v = merge_sort(A, start, mid);
			long[] o = merge_sort(A, mid + 1, end);
			return (merge(v, o));
		} else {
			long[] y = new long[1];
			y[0] = A[start];
			return y;
		}
	}
	public static long[] merge(long a[], long b[]) {


		long[] temp = new long[a.length + b.length];
		int m = a.length;
		int n = b.length;
		int i = 0;
		int j = 0;
		int c = 0;
		while (i < m && j < n) {
			if (a[i] < b[j]) {
				temp[c++] = a[i++];
			
			} else {
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
	public static pair1[] merge_sort(pair1[] A, int start, int end) {
		if (end > start) {
			int mid = (end + start) / 2;
			pair1[] v = merge_sort(A, start, mid);
			pair1[] o = merge_sort(A, mid + 1, end);
			return (merge(v, o));
		} else {
			pair1[] y = new pair1[1];
			y[0] = A[start];
			return y;
		}
	}
	public static pair1[] merge(pair1 a[], pair1 b[]) {


		pair1[] temp = new pair1[a.length + b.length];
		int m = a.length;
		int n = b.length;
		int i = 0;
		int j = 0;
		int c = 0;
		while (i < m && j < n) {
			if (a[i].i < b[j].i) {
				temp[c++] = a[i++];
			
			}else {
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
  public static void total_Subsets(char[] a,int n) {
	  long tot=(1<<n);
	  for(int i=0;i<tot;i++) {
		  for(int j=0;j<n;j++) {
			  if(((i)&(1<<j))!=0) {
				 System.out.print(a[j]); 
			  }
		  }
		  if(i==0) {
			  System.out.print('#');
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
  public static long vowel_dish(String[] a,int n) {
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
  public static boolean is_Sum_Possible_Using_SubSets(long[] a,int n,long sum) {
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
  public static void is_Sum_Possible_Using_SubSets_Using_Linear_Space(int[] a,int n,int sum) {
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
  public static long min_max_cost_path(long[][] a,int n,int m) {
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
  public static long min_max_path_cost_for_last_row(long[][] a,int n,int m,int column) {
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
  public static int longest_Palindromic_Substring(char[] a,int n) {
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
  public static long unique_Ways_To_Reach_Last_Point(int n,int m) {
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
  public static int unique_Ways_To_Reach_Last_Point_With_Obstacles(int[][] obstacles,int n,int m) {
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
  public static long rod_cutting(long[] a,int n) {
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
 public static int Knapsack_0_1_Recursive_(int[] weight,int[] val,int w,int n){
	 if(n==0 || w==0) {
		 return 0;
	 }
	 if(DP[n][(int) w]!=-1) {
		 return DP[n][ w];
	 }
	 if(weight[n]<=w) {
		 DP[n][w]= Math.max(val[n]+Knapsack_0_1_Recursive_(weight,val,w-weight[n],n-1),Knapsack_0_1_Recursive_(weight,val,w,n-1));
	 return DP[n][w];
	 }else {
		 DP[n][(int) w]= Knapsack_0_1_Recursive_(weight,val,w,n-1);
	 return DP[n][w];
	 }
 }
 public static long Knapsack_0_1_Iterative_Top_Down(int[] weight,int[] val,int w,int n) {
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
 public static boolean subset_Sum_Using_Knapsack(long[] a,int n,long sum) {
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
 public static boolean equal_Sum_Partition(long[] a,int n) {
	 long sum=0;
	 for(int i=1;i<=n;i++) {
		 sum+=a[i];
	 }
	 if(sum%2!=0) {
		 return false;
	 }else {
		 return subset_Sum_Using_Knapsack(a,n,sum/2);
	 }
 }
 public static int count_Subsets_With_Given_Sum(int[] a,int n,int sum) {
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
 public static int minimum_Subset_Sum_Difference(int[] a,int n,int sum) {
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
 public static int Number_Of_subsets_with_minimum_Subset_Sum_Difference(int[] a,int n,int sum) {
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
 public static int count_of_subsets_with_given_sum_difference(int[] a,int n,int sum,int diff) {
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
 public static long unbounded_Knapsack_0_1_Iterative_Top_Down(int[] weight,int[] val,int w,int n) {
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
 public static int rod_Cutting_Using_Unbounded_Knapsack(int[] lencut,int[] val,int n,int length) {
	int[][] dp=new int[n+1][length+1];
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=length;j++) {
			if(lencut[i]<=j) {
				dp[i][j]=Math.max(dp[i-1][j], val[i]+dp[i][j-lencut[i]]);
			}else {
				dp[i][j]=dp[i-1][j];
			}
		}
	}
	return dp[n][length];
 }
 public static int Max_Number_Of_ways_to_get_given_sum_unbounded_knapsack(int[] a,int n,int sum) {
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
 public static int Min_Number_Of_coins_to_get_given_sum_unbounded_knapsack(int[] a,int n,int sum) {
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
public static int longest_Common_Subsequence(String str1,String str2,int n,int m,int[][] dp) {
	if(n==0 || m==0) {
		return 0;
	}
	if(dp[n][m]!=-1) {
		return dp[n][m];
	}
	if(str1.charAt(n-1)==str2.charAt(m-1)) {
		int f= 1+longest_Common_Subsequence(str1,str2,n-1,m-1,dp);
		dp[n][m]=f;
		return f;
	}else {
		int f= Math.max(longest_Common_Subsequence(str1,str2,n-1,m,dp),longest_Common_Subsequence(str1,str2,n,m-1,dp));
		dp[n][m]=f;
		return f;
	}
}
public static int longest_Common_Subsequence_using_top_down(String str1,String str2,int n,int m) {
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
public static int longest_Common_Substring_using_top_down(String str1,String str2,int n,int m) {
	int[][] dp=new int[n+1][m+1];
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
public static void Print_LCS(String str1,String str2,int n,int m) {
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
public static int shortest_Common_Supersequence(String str1,String str2,int n,int m) {
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
public static int min_deletions_insertions_to_convert_String_A_to_B(String str1,String str2,int n,int m) {
	int lcs=longest_Common_Subsequence_using_top_down(str1,str2,n,m);
	int min_no_of_deletions=n-lcs;
	int min_no_of_insertions=m-lcs;
	return (min_no_of_deletions+min_no_of_insertions);
}
public static int longest_Palindromic_Subsequence(String str1,int n) {
	String reverse="";
	for(int i=n-1;i>=0;i--) {
		reverse+=str1.charAt(i);
	}
	int lcs=longest_Common_Subsequence_using_top_down(str1,reverse,n,n);


	return lcs;
}
public static int minimum_Deletions_OR_Insertions_To_Make_String_Palindrome(String str,int n) {
	int lps=longest_Palindromic_Subsequence(str,n);
	return n-lps;
} 
public static void Print_SCS(String str1,String str2,int n,int m) {
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
public static int longest_Repeating_Subsequence(String str,int n) {
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
public static boolean pattern_Searching(String str1,String str2,int n,int m) {
	int g=longest_Common_Subsequence_using_top_down(str1,str2,n,m);
	int length=Math.min(n, m);
	if(g==length) {
		return true;
	}else {
		return false;
	}
}
public static long[][] Dp=new long[1001][1001];
public static long Matrix_Chain_Multiplication(int[] a,int i,int j,int n) {
	if(i==j) {
		return 0;}
	if(Dp[i][j]!=-1) {
		return Dp[i][j];
	}
		long min=Long.MAX_VALUE;
		for(int k=i;k<j;k++) {
			long temp=Matrix_Chain_Multiplication(a,i,k,n)+Matrix_Chain_Multiplication(a,k+1,j,n)+a[i-1]*a[k]*a[j];
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
public static long min_Partitions_required_to_make_String_Palindrome(String str,int i,int j) {
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
			temp+=min_Partitions_required_to_make_String_Palindrome(str,i,k);
		}
		if(Dp[k+1][j]!=-1) {
			temp+=Dp[k+1][j];
		}else {
			temp+=min_Partitions_required_to_make_String_Palindrome(str,k+1,j);
		}
		 temp+=1;
		if(temp<min) {
			min=temp;
		}
		Dp[i][j]=min;
		
	}
	return min;
}
public static int MCM_bottom_UP_dp(int[] a,int n) {
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
public static int Palindrome_MCM(String str,int n) {
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
public static int palindromic_Cuts(String str,int n) {
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
public static int number_of_ways_to_get_boolean_true(String str1,String str2) {
	int n=str1.length();
	int[][] dpt =new int[n][n];
	int[][] dpf =new int[n][n];
	for(int g=0;g<n;g++) {
		for(int i=0,j=g;j<n;j++,i++) {
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
					int lf=dpf[i][k];
					int rt=dpt[k+1][j];
					int rf=dpf[k+1][j];
					if (str2.charAt(k) == '&') {
                        dpt[i][j] += lt * rt;
                        dpf[i][j] += lt * rf + lf * rt + rf * lf;
                    } else if (str2.charAt(k) == '|') {
                        dpt[i][j] += lt * rf + lf * rt + rt * lt;
                        dpf[i][j] += rf * lf;
                    } else {
                        dpt[i][j] += lt * rf + lf * rt;
                        dpf[i][j] += lf * rf + lt * rt;
                    }				}
			}
		}
	}
	return dpt[0][n-1];
}
public static int Matrix_Chain_Multiplication_using_Gap_Method(int[] a,int n) {
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
public static int is_Scrambled(String str1,String str2) {
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
		if ((is_Scrambled(str1.substring(0, i), 
				str2.substring(0, i))==1) && 
		(is_Scrambled(str1.substring(i, n),
				str2.substring(i, n))==1))
	{
		flag=1;
		
		um.put(g, 1);
		return flag;
	}

	

	

	

	if ((is_Scrambled(str1.substring(n - i, n),
				str2.substring(0, i))==1) && 
		(is_Scrambled(str1.substring(0, n - i),
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
public static long egg_Drop(long e,long f) {
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
		 solve1=egg_Drop(e,f-k);}
		if(Dp[(int) (e-1)][(int) (k-1)]!=-1) {
			solve2=Dp[(int) (e-1)][(int) (k-1)];
		}else {
		 solve2=egg_Drop(e-1,k-1);}
		long temp=Math.max(solve1,solve2)+1;
		min=Math.min(min, temp);
	}
	Dp[(int) e][(int) f]=min;
	return min;
}
public static int longest_Increasing_Subsequence(int[] a) {
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
public static long longest_Increasing_Maximm_Sum_Subsequence(int[] a) {
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
public static int longest_bitonic_SubSequence(int[] a) {
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
	int max_bitonic=0;
	for(int i=0;i<n;i++) {
		max_bitonic=Math.max(max_bitonic, lis[i]+lds[i]-1);
	}
	return max_bitonic;
}
public static class bridges {
	int n;
	int s;
	bridges(int n,int s){
		this.n=n;
		this.s=s;
	}
}
public static int maximum_non_overlapping_bridges(bridges[] a,int n) {
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
public static int number_of_palindromic_substrings(String str) {
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
public static int longest_palindromic_Substring(String str) {
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
























































































































































































































































































































































































































































































































































































































































public static int longest_palindromic_subsequence(String str) {
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
public static void wild_String_Matching(String str,String pattern) {
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
public static void regular_expression_Matching(String str,String pattern) {
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
public static void distinct_Palindromic_Subsequences(String str) {
	int n=str.length();
	int[] prev=new int[n];
	int[] next=new int[n];
	HashMap<Character,Integer> e=new HashMap<>();
	for(int i=0;i<n;i++) {
		if(i==0) {
			e.put(str.charAt(i), i);
			next[i]=n;
			prev[i]=-1;
		}else {
			if(!e.containsKey(str.charAt(i))) {
				e.put(str.charAt(i), i);
				next[i]=n;
				prev[i]=-1;
			}else {
				int g=e.get(str.charAt(i));
				prev[i]=g;
				next[g]=i;
				next[i]=n;
				e.put(str.charAt(i), i);
			}
		}
	}
	int[][] dp=new int[n][n];
	for(int g=0;g<n;g++) {
		for(int i=0,j=g;j<n;j++,i++) {
			if(g==0) {
				dp[i][j]=1;
			}else if(g==1) {
				dp[i][j]=2;
			}else {
				if(str.charAt(i)!=str.charAt(j)) {
					dp[i][j]=dp[i][j-1]+dp[i+1][j]-dp[i+1][j-1];
				}else {
					int ne=next[i];
					int pr=prev[j];
					if(ne>pr) {
						dp[i][j]=2*dp[i+1][j-1]+2;
					}else if(ne==pr) {
						dp[i][j]=2*dp[i+1][j-1]+1;
					}else {
						dp[i][j]=2*dp[i+1][j-1]-dp[ne+1][pr-1];
					}
				}
			}
		}
	}
	System.out.println(dp[0][n-1]);
}
public static void catalan_numbers(int n) {
	int[] dp=new int[n+1];
	dp[0]=1;
	dp[1]=1;
	for(int i=2;i<=n;i++) {
		for(int j=i-1;j>=0;j--) {
			dp[i]+=dp[j]*dp[i-j-1];
		}
	}
	System.out.println(dp[n]);
}
public static void total_numbers_of_BST_with_given_node(int n) {
	catalan_numbers(n);
}
public static void total_hills_and_valleys(int n) {
	int[] dp=new int[n+1];
	dp[0]=1;
	dp[1]=1;
	for(int i=2;i<=n;i++) {
		int inside=i-1;
		int outside=0;
		while(inside>=0) {
			dp[i]+=dp[inside]*dp[outside];
			inside--;
			outside++;
		}
	}
	System.out.println(dp[n]);
}
public static void total_no_of_bracket_sequences(int n) {
	int[] dp=new int[n+1];
	dp[0]=1;
	dp[1]=1;
	for(int i=2;i<=n;i++) {
		int inside=i-1;
		int outside=0;
		while(inside>=0) {
			dp[i]+=dp[inside]*dp[outside];
			inside--;
			outside++;
		}
	}
	System.out.println(dp[n]);
}
public static void total_no_of_non_intersecting_chords(int n) {
	long[] dp=new long[n+1];
	dp[0]=1;
	dp[1]=1;
	for(int i=2;i<=n;i++) {
		int inside=i-1;
		int outside=0;
		while(inside>=0) {
			dp[i]+=dp[inside]*dp[outside];
			inside--;
			outside++;
		}
	}
	System.out.println(dp[n]);
}
public static void total_no_of_non_triangles_possible_with_given_polygon_sides(int n) {
	n-=2;
	long[] dp=new long[n+1];
	dp[0]=1;
	dp[1]=1;
	for(int i=2;i<=n;i++) {
		int inside=i-1;
		int outside=0;
		while(inside>=0) {
			dp[i]+=dp[inside]*dp[outside];
			inside--;
			outside++;
		}
	}
	System.out.println(dp[n]);
}
public static void total_ways_to_reach_from_Left_Bottom_to_Top_right_in_a_square_Matrix(int n) {
	

	

	

	catalan_numbers(n-2);
}
public static int minimum_cost_of_triangulation(int[] a) {
	int n=a.length;
	int[][] dp=new int[n][n];
	for(int g=0;g<n;g++) {
		for(int i=0,j=g;j<n;i++,j++) {
			if(g==0) {
				dp[i][j]=0;
			}else if(g==1) {
				dp[i][j]=0;
			}else if(g==2){
				dp[i][j]=a[i]*a[i+1]*a[i+2];
			}else {
				int min=Integer.MAX_VALUE;
				for(int k=i+1;k<j;k++) {
					int tri=a[i]*a[k]*a[j];
					int left=dp[i][k];
					int right=dp[k][j];
					int tot=tri+left+right;
					if(tot<min) {
						min=tot;
					}
				}
				dp[i][j]=min;
			}
		}
	}
	return dp[0][n-1];
}
public static int rod_cutting_with_left_right_strategy(int[] a,int n) {
	int[] dp=new int[n+1];
	dp[1]=a[1];
	for(int i=2;i<=n;i++) {
		dp[i]=a[i];
		int left=1;
		int right=i-1;
		while(left<=right) {
			dp[i]=Math.max(dp[left]+dp[right],dp[i]);
		left++;
		right--;
		}
		
	}
	return dp[n];
}
public static int palidromic_cuts_with_suffix(String str) {
	int n=str.length();
	boolean[][]  pd=new boolean[n][n];
	for(int g=0;g<n;g++) {
		for(int i=0,j=g;j<n;i++,j++) {
			if(g==0) {
				pd[i][j]=true;
			}else if(g==1) {
				if(str.charAt(i)==str.charAt(j)) {
					pd[i][j]=true;
				}else {
					pd[i][j]=false;
				}
			}else {
				if(str.charAt(i)!=str.charAt(j)) {
					pd[i][j]=false;
				}else {
					if(pd[i+1][j-1]) {
						pd[i][j]=true;
					}else {
						pd[i][j]=false;
					}
				}
			}
		}
	}
	int[] dp=new int[n+1];
	for(int i=1;i<=n;i++) {
		if(i==1) {
			dp[1]=0;
		}else if(i==2) {
			if(str.charAt(0)==str.charAt(1)) {
				dp[2]=0;
			}else {
				dp[2]=1;
			}
		}else {
			if(pd[0][i-1]) {
				dp[i]=0;
			}else {
			dp[i]=Integer.MAX_VALUE;
			for(int k=i;k>=1;k--) {
				if(pd[k-1][i-1]) {
					dp[i]=Math.min(dp[i], dp[k-1]+1);
				}
			}
		}
			}
	}
return dp[n];
}
public static int MCM(int[] a) {
	int n=a.length;
	int[][] dp=new int[n-1][n-1];
	for(int g=0;g<n-1;g++) {
		for(int i=0,j=g;j<n-1;j++,i++) {
			if(g==0) {
				dp[i][j]=0;
			}else if(g==1) {
				dp[i][j]=a[i]*a[i+1]*a[i+2];
			}else {
				dp[i][j]=Integer.MAX_VALUE;
				for(int k=i;k<j;k++) {
					int left=dp[i][k];
					int right=dp[k+1][j];
					int mat=a[i]*a[k+1]*a[j+1];
					dp[i][j]=Math.min(dp[i][j], left+right+mat);
				}
			}
		}
	}
	return dp[0][n-2];
}
public static void optimal_Binary_Search_Tree(int[] frequency) {
	int n=frequency.length;
	int[] pre=new int[n];
	for(int i=0;i<n;i++) {
		pre[i]=(i==0)?(frequency[0]):(pre[i-1]+frequency[i]);
	}
	int[][] dp=new int[n][n];
	for(int g=0;g<n;g++) {
		for(int i=0,j=g;j<n;i++,j++) {
			if(g==0) {
				dp[i][j]=frequency[i];
			}else if(g==1){
				dp[i][j]=Math.min(2*frequency[i]+frequency[j], frequency[i]+2*frequency[j]);
			}else {
				int sum=(i==0)?(pre[j]):(pre[j]-pre[i-1]);
				dp[i][j]=Integer.MAX_VALUE;
				for(int k=i;k<=j;k++) {
					int left=(k==0)?(0):(dp[i][k-1]);
					int right=(k==n-1)?(0):(dp[k+1][j]);
					int tot=left+right+sum;
			dp[i][j]=Math.min(dp[i][j], tot);
				}
			}
		}
	}
	System.out.println(dp[0][n-1]);
}
public static void min_squares(int n) {
	int[] dp=new int[n+1];
	dp[1]=1;
	for(int i=2;i<=n;i++) {
		dp[i]=Integer.MAX_VALUE;
		for(int j=1;j*j<=i;j++) {
			int rem=i-j*j;
			dp[i]=Math.min(dp[i], 1+dp[rem]);
		}
	}
	System.out.println(dp[n]);
}
public static long Kadanes_Algo(long[] a) {
    long sum=Long.MIN_VALUE;
	long curr=0;
	int i=0;
	int n=a.length;
	while(i<n) {
		if(curr<0) {
			curr=0;
		}
	curr+=a[i];
	sum=Math.max(sum, curr);
		i++;
	}
return sum;
}
public static void Letter_Combinations_of_a_Phone_Number(int n) {
	int[][] data= {
	{0,8},
	{1,2,4},
	{1,2,3,5},
	{2,3,6},
	{1,4,5,7},
	{2,4,5,6,8},
	{2,5,6,9},
	{4,7,8},
	{5,7,8,9,0},
	{6,8,9}
	};
	int[][] dp=new int[n+1][10];
	for(int i=1;i<=n;i++) {
		for(int j=0;j<=9;j++) {
			if(i==1) {
				dp[i][j]=1;
			}else {
				int sum=0;
				for(int e:data[j]) {
					sum+=dp[i-1][e];
				}
				dp[i][j]=sum;
			}
		}
	}
	long tot_sum=0;
	for(int i=1;i<=n;i++) {
		for(int j=0;j<=9;j++) {
			tot_sum+=dp[i][j];
		}
	}
	System.out.println(tot_sum);
}
public static void maximum_length_subarray_after_K_Concatenations(long[] a,long sum,int k) {
	if(k==1) {
		System.out.println(Kadanes_Algo(a));
	}else {
		if(sum<0) {
			long[] b=new long[2*a.length];
			for(int i=0;i<2*a.length;i++) {
				b[i]=a[(i%(a.length))];
			}
			System.out.println((Kadanes_Algo(b)));
		}else {
			long[] b=new long[2*a.length];
			for(int i=0;i<2*a.length;i++) {
				b[i]=a[(i%(a.length))];
			}
			System.out.println((k-2)*sum+(Kadanes_Algo(b)));
		}
	}
}
public static void Balloon_Burst(int[] a) {
	int n=a.length;
	int[][] dp=new int[n][n];
	for(int g=0;g<n;g++) {
		for(int i=0,j=g;j<n;i++,j++) {
			for(int k=i;k<=j;k++) {
				int left=(k==i)?0:dp[i][k-1];
				int right=(k==j)?0:dp[k+1][j];
				int tot=left+right;
				int val=a[k];
				if(i!=0) {
					val*=a[i-1];
				}
				if(j!=n-1) {
					val*=a[j+1];
				}
				dp[i][j]=Math.max(dp[i][j], tot+val);
			}
			
		}
	}
	System.out.println(dp[0][n-1]);
}
public static boolean isValid(int ni,int nj,int n) {
	if((ni<n && ni>=0) && (nj<n && nj>=0)) {
		return true;
	}
	return false;
}
public static void Knights_Probability(int n,int k,int r,int c) {
	double[][] curr=new double[n][n];
	double[][] next=new double[n][n];
	curr[r][c]=1;
	for(int g=1;g<=k;g++) {
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			if(curr[i][j]!=0) {
				int nir=i-1;
				int nil=i+1;
				int njd=j+2;
				int nju=j-2;
				int niu=i-2;
				int nid=i+2;
				int njr=j+1;
				int njl=j-1;
				if(isValid(nir,njd,n)) {
					next[nir][njd]+=curr[i][j]/8;
				}
                if(isValid(nir,nju,n)) {
                	next[nir][nju]+=curr[i][j]/8;
				}
                if(isValid(nil,njd,n)) {
                	next[nil][njd]+=curr[i][j]/8;
				}
                if(isValid(nil,nju,n)) {
                	next[nil][nju]+=curr[i][j]/8;
                } 
                if(isValid(niu,njr,n)) {
                	next[niu][njr]+=curr[i][j]/8;
				}
                if(isValid(niu,njl,n)) {
                	next[niu][njl]+=curr[i][j]/8;
				}
                if(isValid(nid,njr,n)) {
                	next[nid][njr]+=curr[i][j]/8;
                }
                if(isValid(nid,njl,n)) {
                	next[nid][njl]+=curr[i][j]/8;
				}
			}
		}
	}
	curr=next;
	next=new double[n][n];
	}
	double sum=0;
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			sum+=curr[i][j];
		}
	}
	System.out.println(sum);
}
public static long MAX_diff_between_Zeroes_and_Ones(String str) {
	char[] a=str.toCharArray();
	int n=str.length();
	long[] b=new long[n];
	for(int i=0;i<n;i++) {
		if(a[i]=='1') {
			b[i]=-1;
		}else {
			b[i]=1;
		}
	}
	return Kadanes_Algo(b);
}
public static void Maximum_Sum_Subarray_with_Atleast_K_elements(long[] a,int k) {
	int n=a.length;
	long[] b=new long[n];
	long sum=Long.MIN_VALUE;
	long curr=0;
	for(int i=0;i<n;i++) {
		if(curr<0) {
			curr=0;
		}
		curr+=a[i];
		b[i]=curr;
	}
	long currk=0;
	for(int i=0;i<k;i++) {
		currk+=a[i];
	}
	sum=Long.max(currk, sum);
	for(int i=k;i<n;i++) {
		currk=currk-a[i-k]+a[i];
		sum=Math.max(currk, Math.max(sum, currk+b[i-k]));
	}
	System.out.println(sum);
}
public static void Game(int[] a) {
	int n=a.length;
	int[][] dp=new int[n][n];
	for(int g=0;g<n;g++) {
		for(int i=0,j=g;j<n;j++,i++) {
			if(g==0) {
				dp[i][j]=a[i];
			}else if(g==1) {
				dp[i][j]=Math.max(a[i], a[j]);
			}else {
				int left=a[i]+Math.min(dp[i+2][j], dp[i+1][j-2]);
				int right=a[j]+Math.min(dp[i+1][j-1], dp[i][j-2]);
				dp[i][j]=Math.max(left, right);
			}
		}
	}
	System.out.println(dp[0][n-1]);
}
public static void Egg_drop(int e,int f) {
	int[][] dp=new int[e+1][f+1];
	for(int i=1;i<=f;i++) {
		dp[1][i]=i;
	}
	for(int i=1;i<=e;i++) {
		dp[i][1]=1;
	}
	for(int i=2;i<=e;i++) {
		for(int j=2;j<=f;j++) {
			int max=Integer.MAX_VALUE;
			for(int k=0;k<j;k++) {
				max=Math.min(max,Math.max(dp[i-1][k], dp[i][j-k-1]));
			}
			dp[i][j]=max+1;
		}
	}
	System.out.println(dp[e][f]);
}
public static void Minimum_ASCII_deletions(String str1,String str2) {
	int m=str1.length();
	int n=str2.length();
	int[][] dp=new int[n+1][m+1];
	for(int i=n-1;i>=0;i--) {
		dp[i][m]=dp[i+1][m]+(int)str2.charAt(i);
	}
	for(int i=m-1;i>=0;i--) {
		dp[n][i]=dp[0][i+1]+(int)str1.charAt(i);
	}
	for(int i=n-1;i>=0;i--) {
		for(int j=m-1;j>=0;j--) {
			if(str2.charAt(i)==str1.charAt(j)) {
				dp[i][j]=dp[i+1][j+1];
			}else {
				dp[i][j]=Math.min((int)str1.charAt(j)+dp[i][j+1], (int)str2.charAt(i)+dp[i+1][j]);
			}
		}
	}
	System.out.println(dp[0][0]);
}
public static void Minimum_Cost_Of_deletions(String str1,String str2,int c1,int c2) {
	int n=str1.length();
	int m=str2.length();
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
	int val1=c1*(n-dp[n][m]);
	int val2=c2*(m-dp[n][m]);
	System.out.println(val1+val2);
}
public static void arithmetic_Slices(int[] a) {
	int[] dp=new int[a.length];
	int ans=0;
	for(int i=2;i<a.length;i++) {
		if((a[i]-a[i-1])==(a[i-1]-a[i-2])) {
			dp[i]=dp[i-1]=1;
			ans+=dp[i];
		}
	}
	System.out.println(ans);
}
public static void Largest_SubSquare_Matrix_with_all_1s(int[][] a) {
	int n=a.length;
	int m=a[0].length;
	int[][] dp=new int[n][m];
	for(int i=0;i<n;i++) {
		if(a[i][m-1]==1) {
			dp[i][m-1]=1;
		}
	}
	for(int i=0;i<m;i++) {
		if(a[n-1][i]==1) {
			dp[n-1][i]=1;
		}
	}
	int max=0;
	for(int i=n-2;i>=0;i--) {
		for(int j=m-2;j>=0;j--) {
			if(a[i][j]==1) {
				dp[i][j]=Math.min(dp[i+1][j], Math.min(dp[i+1][j+1], dp[i][j+1]))+1;
			max=Math.max(max, dp[i][j]);
			}
		}
	}
	System.out.println(max);
}
public static void word_break(String str,HashSet<String> dict) {
	int[] dp=new int[str.length()];
	for(int i=0;i<str.length();i++) {
		for(int j=0;j<=i;j++) {
			String str1=str.substring(j,i+1);
			if(dict.contains(str1)) {
			if(j>0) {
				dp[j]+=dp[j-1];
			}else {
				dp[j]+=1;
			}
			}
		}
	}








	if(dp[str.length()-1]!=0) {
		System.out.println("true");
	}else {
		System.out.println("False");
	}
}
public static void distinct_transformation(String so,String t) {
	int[][] dp=new int[t.length()+1][so.length()+1];
	for(int i=0;i<=so.length();i++) {
		dp[t.length()][i]=1;
	}
	for(int i=0;i<t.length();i++) {
		dp[i][so.length()]=0;
	}
	for(int i=t.length()-1;i>=0;i--) {
		for(int j=so.length()-1;j>=0;j--) {
			if(t.charAt(i)==so.charAt(j)) {
				dp[i][j]=(dp[i][j+1]+dp[i+1][j+1]);
			}else {
				dp[i][j]=dp[i][j+1];
			}
		}
	}
	System.out.println(dp[0][0]);
}
static int[][][][] dp1=new int[101][101][11][11];
public static int ceasors_legion(int f,int h,int k1,int k2) {
	if((f+h)==0) {
		System.out.println(f+" "+h);
		return 1;
		
	}
	if(dp1[f][h][k1][k2]!=-1) {
		System.out.println(f+" "+h);
		return dp1[f][h][k1][k2];
	}
	int x=0;
	if(f>0 && k1>0) {
		System.out.println(f+" "+h);
		x=ceasors_legion(f-1,h,k1-1,k2);
	}
	int y=0;
	if(h>0 && k2>0) {
		System.out.println(f+" "+h);
		y=ceasors_legion(f,h-1,k1,k2-1);
	}
	dp1[f][h][k1][k2]=(x+y)%(100000000);
	return (x+y)%(100000000);
}
static int k11=0;
static int k22=0;
int getAns(int f ,int h , int k1 , int k2)
{
	if((f + h) == 0) return 1;
 
	if(dp1[f][h][k1][k2] != -1)	return dp1[f][h][k1][k2];
 
	

	int x = 0;
	if(f > 0 && k1 > 0) { 
		System.out.println(f+" "+h+" "+k1+" "+k2);
		x = getAns(f - 1, h , k1 - 1 , k22);}
 
	

	int y = 0;
	if(h > 0 && k2 > 0) { 
		System.out.println(f+" "+h+" "+k1+" "+k2);
		y = getAns(f , h - 1 , k11 , k2 - 1);
	} 
	return dp1[f][h][k1][k2] = (x + y) % 100000000;
}
static int[] dp2=new int[100001];
public static int getAns(int n,int k) {
	if(n==0) {
		return 1;
	}
	if(dp2[n]!=-1) {
		return dp2[n];
	}
	int x=0;
	if(n>=k) {
		x=getAns(n-k,k);
	}
	int y=0;
	y=getAns(n-1,k);
	dp2[n]=(x+y)%(1000000007);
	return (x+y)%(1000000007);
}
public static void longest_bracket_Sequence(String str) {
	Stack<Integer> st=new Stack<>();
	int[] e=new int[str.length()+1];
	for(int i=0;i<str.length()+1;i++) {
		e[i]=-1;
	}
	int[] f=new int[1000001];
	int max=0;
	f[0]=1;
	out:for(int i=0;i<str.length();i++) {
		if(str.charAt(i)=='(') {
			st.add(i);
		}else {
			if(st.isEmpty()) {
				continue out;
			}else {
				int id=st.pop();
				if(id==0) {
					e[i]=id;
				}else {
					if(e[id-1]>=0) {
						e[i]=e[id-1];
					}else {
						e[i]=id;
					}
				}
				int l=i-e[i]+1;
				f[l]++;
				max=Math.max(max,l);
						
			}
		}
		
	}
	System.out.println(max+" "+f[max]);
	
}
static class pair1{
	private int i;
	private int cost;
	pair1(int i,int cost){
		this.i=i;
		this.cost=cost;
	}
}
static long[][] dp3=new long[3001][3001];
static long INF=(long) Math.pow(10, 15);
public static long get(int x,int prev,int n,pair1[] a) {
	if(x>=n) {
		return 0;
	}
	if(dp3[x][prev]!=INF) {
		return dp3[x][prev];
	}
	long c1=0;
	c1=get(x+1,x,n,a)+a[x].cost;
	long c2=0;
	c2=get(x+1,prev,n,a)+(a[x].i-a[prev].i);
	long val=Math.min(c1, c2);


	return dp3[x][prev]=val;
}
static int[] poss=new int[1001];
static long[][][] dp4=new long[11][1001][2];
public static long get_till_nth(int pos,int n,int sum,int p) {
	if(pos>n) {
		return sum;
	}
if(dp4[pos][sum][p]!=-1) {
	return dp4[pos][sum][p];
}
	int limit=9;
	if(p==0) {
		limit=poss[pos];
	}
	long res=0;
	for(int i=0;i<=limit;i++) {
		
		if((p==1) || i<limit) {
		res+=get_till_nth(pos+1,n,sum+i,1);
		}
		else {
			res+=get_till_nth(pos+1,n,sum+i,0);
		}
	}
	dp4[pos][sum][p]=res;
	return res;

}
}