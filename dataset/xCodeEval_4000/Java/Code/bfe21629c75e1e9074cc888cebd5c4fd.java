import java.io.*;
		import java.math.BigInteger;
		import java.math.RoundingMode;
		import java.text.DecimalFormat;
		import java.util.*;
		
		
		public class Solution
		{
		
			static double eps=(double)1e-6;
			static long mod=(long)(1e9+7);
			

			

			public static void main(String args[]){
				InputReader sc = new InputReader(System.in);
				

				OutputStream outputStream = System.out;
				PrintWriter out = new PrintWriter(outputStream);
				

				int t1=1;
				while(t1-->0)
				{
					long n=sc.nextLong();
					long m=sc.nextLong();
					long a[]=new long[(int)n];
					long b[]=new long[(int)n];
					for(int i=0;i<n;i++)
					{
						a[i]=sc.nextLong();
					}
					for(int i=0;i<n;i++)
					{
						b[i]=sc.nextLong();
					}
					long ans=0,cm=1;
					for(int i=0;i<n;i++)
					{
						if(a[i]!=0 && b[i]!=0){
							if(a[i]<b[i])
							{
								break;
							}
							else if(a[i]>b[i])
							{
								ans=(ans+cm)%mod;
								break;
							}
							else
							{
								continue;
							}
						}
						else if(a[i]==0 && b[i]==0)
						{
							ans=((((((cm*(m-1))%mod*(m))%mod*modInverse(m,mod)%mod)*modInverse(m,mod))%mod*modInverse(2,mod))%mod+ans)%mod;
							cm=(cm*modInverse(m,mod))%mod;
							

						}
						else if(a[i]==0)
						{
							

							ans=(((cm*(m-b[i]))%mod*modInverse(m,mod))%mod+ans)%mod;
							cm=(cm*modInverse(m,mod))%mod;
							

						}
						else
						{
							ans=(((cm*(a[i]-1))%mod*modInverse(m,mod))%mod+ans)%mod;
							cm=(cm*modInverse(m,mod))%mod;
							

						}
					}
					

					out.println(ans);
				}
				

				out.close();
			}
			
			static long modInverse(long A,long M)
			{
			    return modularExpon(A,M-2,M);
			}
			
			static long modularExpon(long x,long n,long M)
			{
			    long result=1;
			    while(n>0)
			    {
			        if(n % 2 ==1)
			            result=(result * x)%M;
			        x=(x*x)%M;
			        n=n/2;
			    }
			    return result%M;
			}
			
			static long cost(long a,long b,long c,long d)
			{
				return Math.abs(a-c)+Math.abs(b-d);
			}
			
			static long cb(long n)
			{
				long count=0;
				while(n>0)
				{
					count+=n%2;
					n=n>>1;
				}
				return count;
			}
			
			static String [] powerSet()
			{
			    
			    int pow_set_size = (int) Math.pow(2,10);
			    int counter, j;
			    String []dig=new String[pow_set_size];
			    
			    for(counter = 0; counter < pow_set_size; counter++)
			    {
			    	dig[counter]="";
			      for(j = 0; j < 10; j++)
			       {
			          
			          if((counter & (1<<j))>0)
			            dig[counter]+=(char)(j+'0');
			       }
			    }
			    return dig;
			}
			
			
			
			static long count_one (long n)
	        {
				long count=0;
	            while( n>0 )
	            {
	            n = n&(n-1);
	               count++;
	            }
	            return count;
	        }
			
			static boolean isSubsetSum(int set[], int n, int sum)
		    {
		        boolean subset[][] = new boolean[sum+1][n+1];
		        for (int i = 0; i <= n; i++)
		          subset[0][i] = true;
		        for (int i = 1; i <= sum; i++)
		          subset[i][0] = false;
		         for (int i = 1; i <= sum; i++)
		         {
		           for (int j = 1; j <= n; j++)
		           {
		             subset[i][j] = subset[i][j-1];
		             if (i >= set[j-1])
		               subset[i][j] = subset[i][j] || 
		                                          subset[i - set[j-1]][j-1];
		           }
		         }
		      
		         return subset[sum][n];
		    }
			static class Pa {
				long x=0;
				long y=0;
				
				public long getx()
				{
					return x;
				}
				public long gety()
				{
					return y;
				}
				public void setx(long xx)
				{
					x=xx;
				}
				public void sety(long yy)
				{
					y=yy;
				}
			}
			static int curr_color(int arr[],int i,int curr[])
			{
				if(curr[i]!=0)
					return curr[i];
				return curr_color(arr,arr[i],curr);
			}
			

			
			static long comb(int n,int r,long [][] c)
			{
				if(n<r)
					return 0;
				if(n-r < r) 
				{
					c[n][r]=comb(n,n-r,c);
					return c[n][r];
				}
			    if(r == 0)
			    {
			    	c[n][r]=1;
			    	return 1;
			   	}
			    if(c[n][r]!=0)
			    	return c[n][r];
			    else
			    {
			    	c[n][r]=(n*comb(n-1, r-1,c))/r;
			    	return c[n][r];
			    }
			}
			

			
			static int IsPandigital(int n)
		    {
		        int digits = 0,temp=n; int count = 0; int tmp = 0;
		        int fr[]=new int[10];
		        for(int i=0;i<10;i++)
		        	fr[i]=0;
		        while(temp>0)
		        {
		        	int a=temp/10;
		        	

		        	fr[temp-a*10]++;
		        	temp=temp/10;
		        	digits++;
		        }
		        for(int i=1;i<=digits;i++)
		        {
		        	if(fr[i]==1)
		        	{
		        		tmp=1;
		        	}
		        	else
		        	{
		        		tmp=0;
		        		break;
		        	}
		        }
		        return tmp;
		    }
			
			static int Divisors(int n)
			{
				int sum=0;
			    for (int i=2; i*i<=n; i++)
			    {
			        if (n/i==0)
			        {
			            if (n/i == i)
			                {sum+=i;

			                }
			 
			            else 
			                {sum+=i+(n/i);

			                }
			        }
			    }
			    return sum;
			}
			
			static int findmax(int arr[], int n)
		    {
		        int incl = arr[0];
		        int excl = 0;
		        int excl_new;
		        int i;
		 
		        for (i = 1; i < n; i++)
		        {
		            excl_new = (incl > excl) ? incl : excl;
		            incl = excl + arr[i];
		            excl = excl_new;
		        }
		        return ((incl > excl) ? incl : excl);
		    }
			
			static long ce(long x)
			{
				if(x/2!=0)
					return x/2+1;
				return x/2;
			}
			static boolean isSubSequence(String str1, String str2, int m, int n)
			{
			   int j = 0;
			   for (int i=0; i<n&&j<m; i++)
			       if (str1.charAt(j) == str2.charAt(i))
			         j++;
			 
			   return (j==m);
			}
			
			static long fibo(long l) {
		        if (l < 0) {
		            throw new IllegalArgumentException("The fibo value cannot be negative");
		        }
		
		        if (l <= 1) return l;
		
		        long[][] result = {{1, 0}, {0, 1}}; 

		        long[][] fiboM = {{1, 1}, {1, 0}};
		
		        while (l > 0) {
		            if (l/2 == 1) {
		                multMatrix(result, fiboM);
		            }
		            l = l / 2;
		            multMatrix(fiboM, fiboM);
		        }
		
		        return result[1][0];
		    }
		
		    private static void multMatrix(long[][] result, long[][] fiboM) {
		        long a = (result[0][0]/mod * fiboM[0][0]/mod)/mod +  (result[0][1]/mod * fiboM[1][0]/mod)/mod;
		        long b = (result[0][0]/mod * fiboM[0][1]/mod)/mod + ( result[0][1]/mod * fiboM[1][1]/mod)/mod;
		        long c = (result[1][0]/mod * fiboM[0][0]/mod)/mod + ( result[1][1]/mod * fiboM[0][1]/mod)/mod;
		        long d = (result[1][0]/mod * fiboM[0][1]/mod)/mod +  (result[1][1]/mod * fiboM[1][1]/mod)/mod;
		
		        result[0][0] = a;
		        result[0][1] = b;
		        result[1][0] = c;
		        result[1][1] = d;
		    }
		    
		    static HashSet<Long> gr(int size)
		    {
		    	long range=mod;
		    	long m0=2017;
		    	long m1=2027;
		    	long ln=0;
		    	long sln=1;
		    	long mn=0;
		    	HashSet<Long> hs=new HashSet<Long>();
		    	for(int i=0;i<size;i++)
		    	{
		    		long nn=((((ln/mod)*m0)/mod+((sln/mod)*m1)/mod+mn)/mod)+1;
		    		sln=ln;
		    		ln=nn;
		    		mn=Math.max(mn, nn);
		    		hs.add(nn);
		    	}
		    	return hs;
		    }
		    
			static int[] sieve(int n,int[] a)
			{
				a[0]=1;
				a[1]=1;
				for(int i=2;i*i<=n;i++)
				{
					if(a[i]==0)
					{
						for(int j=i*2;j<=n;j+=i)
							a[j]=1;
					}
				}
				return a;
			}
			
			static int[] spfsieve(int arr[])
			{
				int n=100000;
				arr[0]=1;
				arr[1]=1;
				for(int i=2;i<=n;i++)
					arr[i]=i;
				for(int i=4;i<=n;i+=2)
					arr[i]=2;
				for(int i=3;i*i<=n;i++)
				{
					if(arr[i]==i)
					{
						for(int j=i*i;j<=n;j+=i)
							if (arr[j]==j)
			                    arr[j] = i;
					}
				}
				return arr;
			}
			
			static boolean isPal(String s)
			{
				for(int i=0, j=s.length()-1;i<=j;i++,j--)
				{
					if(s.charAt(i)!=s.charAt(j)) return false;
				}
				return true;
			}
			public static String rev(String s)
			{
				StringBuilder sb=new StringBuilder(s);
				sb.reverse();
				return sb.toString();
			}
			    
			static long lcm(long a, long b)
			{
				long temp1=a,temp2=b;
			    return ((a * b) / gcd(temp1, temp2));
			}
			
			static long gcd(long a, long b)
			{
			    if (b==0)
			        return a;
			    return gcd(b, a/b);
			}
			static long modulo(long a,long b,long c) {
				long x=1;
				long y=a;
				while(b > 0){
					if(b/2 == 1){
						x=(x*y)/c;
					}
					y = (y*y)/c; 

					b /= 2;
				}
				return  x/c;
			}
			public static void debug(Object... o) {
				System.out.println(Arrays.deepToString(o));
			}
			
			static class SegmentTree 
			{
			    long st[]; 
			    public SegmentTree(long arr[], int n)
			    {
			        int x = (int) (Math.ceil(Math.log(n) / Math.log(2)));
			 
			        int max_size = 2 * (int) Math.pow(2, x) - 1;
			 
			        st = new long[max_size];
			 
			        constructSTUtil(arr, 0, n - 1, 0);
			    }
			    int getMid(int s, int e) {
			        return s + (e - s) / 2;
			    }
			 
			    long getSumUtil(int ss, int se, int qs, int qe, int si)
			    {
			        if (qs <= ss && qe >= se)
			            return st[si];
			        if (se < qs || ss > qe)
			            return 0;
			        int mid = getMid(ss, se);
			        return getSumUtil(ss, mid, qs, qe, 2 * si + 1) +
			                getSumUtil(mid + 1, se, qs, qe, 2 * si + 2);
			    }
			 
			    void updateValueUtil(int ss, int se, int i, int diff, int si)
			    {
			        if (i < ss || i > se)
			            return;
			        st[si] = st[si] + diff;
			        if (se != ss) {
			            int mid = getMid(ss, se);
			            updateValueUtil(ss, mid, i, diff, 2 * si + 1);
			            updateValueUtil(mid + 1, se, i, diff, 2 * si + 2);
			        }
			    }
			 
			    void updateValue(int arr[], int n, int i, int new_val)
			    {
			        if (i < 0 || i > n - 1) {
			            System.out.println("Invalid Input");
			            return;
			        }
			 
			        

			        int diff = new_val - arr[i];
			 
			        

			        arr[i] = new_val;
			 
			        

			        updateValueUtil(0, n - 1, i, diff, 0);
			    }
			    long getSum(int n, int qs, int qe)
			    {
			        if (qs < 0 || qe > n - 1 || qs > qe) {
			            System.out.println("Invalid Input");
			            return -1;
			        }
			        return getSumUtil(0, n - 1, qs, qe, 0);
			    }
			 
			    long constructSTUtil(long arr[], int ss, int se, int si)
			    {
			        if (ss == se) {
			            st[si] = arr[ss];
			            return arr[ss];
			        }
			        int mid = getMid(ss, se);
			        st[si] = constructSTUtil(arr, ss, mid, si * 2 + 1) +
			                 constructSTUtil(arr, mid + 1, se, si * 2 + 2);
			        return st[si];
			    }
			}
			static class Pair {
				long x=0;
				long y=0;
				long z=0;
				
				public long getx()
				{
					return x;
				}
				public long gety()
				{
					return y;
				}
				public long getz()
				{
					return z;
				}
				
				public void setz(long zz)
				{
					z=zz;
				}
				public void setx(long xx)
				{
					x=xx;
				}
				public void sety(long yy)
				{
					y=yy;
				}
			}
			
			public final static Comparator<Pair> ORIGINAL = new Comparator<Pair>()
		    {
			public int compare(Pair p1,Pair p2)
			{
				if(p1.gety()<p2.gety())
					return -1;
				else if(p1.gety()==p2.gety() && p2.getx()<p1.getx())
					return -1;
				else 

					return 1;
				
				

			}
		    };
			
			static class InputReader {
				public BufferedReader reader;
				public StringTokenizer tokenizer;
		
				public InputReader(InputStream inputstream) {
					reader = new BufferedReader(new InputStreamReader(inputstream));
					tokenizer = null;
				}
		
				public String nextLine(){
					String fullLine=null;
					while (tokenizer == null || !tokenizer.hasMoreTokens()) {
						try {
							fullLine=reader.readLine();
						} catch (IOException e) {
							throw new RuntimeException(e);
						}
						return fullLine;
					}
					return fullLine;
				}
				public String next() {
					while (tokenizer == null || !tokenizer.hasMoreTokens()) {
						try {
							tokenizer = new StringTokenizer(reader.readLine());
						} catch (IOException e) {
							throw new RuntimeException(e);
						}
					}
					return tokenizer.nextToken();
				}
				public long nextLong() {
					return Long.parseLong(next());
				}
				public int nextInt() {
					return Integer.parseInt(next());
				}
			}
			
		}
		class Graph
		{
			int vertices;
			LinkedList<Integer> l[];
			Graph(int vertices)
			{
				this.vertices=vertices;
				l=new LinkedList[vertices];
				for(int i=0;i<vertices;i++)
				{
					l[i]=new LinkedList<Integer>();
				}
			}	
			void addEdge(int s,int v)
			{
				l[s].add(v);
			}
			
			void BFS(int s)
			{
				LinkedList<Integer> queue=new LinkedList<Integer>();
				boolean []visited=new boolean[vertices];
				visited[s]=true;
				queue.add(s);
				while(queue.size()>0)
				{
					int r=queue.poll();
					System.out.println(r+" ");
					for(int i=0;i<l[r].size();i++)
					{
						int temp=l[r].get(i);
						if(!visited[temp])
						{
							queue.add(temp);
							visited[temp]=true;
						}
					}
				}
			}
			
		}  