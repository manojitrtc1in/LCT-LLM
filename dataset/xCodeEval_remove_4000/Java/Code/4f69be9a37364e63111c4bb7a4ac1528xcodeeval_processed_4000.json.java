import java.util.*;
import java.awt.RenderingHints.Key;
import java.io.*;
			import java.lang.*;
			
			public class cf1
			{
				public static void main(String[] args)
				{
					InputReader in = new InputReader(System.in);
					PrintWriter pw = new PrintWriter(System.out);
					
					

				
					
					
					int n = in.nextInt();
					int[] a = in.id3(n);
					randomize(a, n);
					Arrays.sort(a);
					
					
					if(n>1) {
					long[] mul = new long[n+1];
					long[] dp =  new long[n+1];
					mul[0] = 1;
					dp[0] = 1;
					for(int i=1; i<=n; i++)
					{
						mul[i] = ((mul[i-1]%mod)*2%mod)%mod;
						dp[i] = (dp[i-1]%mod + mul[i]%mod)%mod;
					}
					
					long ans1 = 0;
					long ans2 = 0;
					for(int i=0; i<n/2; i++)
					{
						

						long tmp =	((dp[n-2-i] - (i>0?dp[i-1]:0))%mod)%mod;
						
						ans1 = (ans1%mod + (a[i]%mod * tmp%mod)%mod)%mod;

						ans2 = (ans2%mod + (a[n-i-1]%mod * tmp%mod)%mod)%mod;
					}
				
					long ans = (long)(ans2%mod - ans1%mod + mod)%mod;
					pw.println((ans+mod)%mod);
					
					}
					else
						pw.println(0);
					
					pw.flush();
					pw.close();
				}
				
				static class InputReader 
				{
					 
					private final InputStream stream;
					private final byte[] buf = new byte[8192];
					private int curChar, id2;
					private id9 filter;
			 
					public InputReader(InputStream stream) 
					{
						this.stream = stream;
					}
			 
					public int snext() 
					{
						if (id2 == -1)
							throw new InputMismatchException();
						if (curChar >= id2) 
						{
							curChar = 0;
							try 
							{
								id2 = stream.read(buf);
							} 
							catch (IOException e) 
							{
								throw new InputMismatchException();
							}
							if (id2 <= 0)
								return -1;
						}
						return buf[curChar++];
					}
			 
					public int nextInt() 
				    {
						int c = snext();
						while (id0(c)) 
						{
							c = snext();
						}
						int sgn = 1;
						if (c == '-')
					    {
							sgn = -1;
							c = snext();
						}
						int res = 0;
						do 
						{
							if (c < '0' || c > '9')
								throw new InputMismatchException();
							res *= 10;
							res += c - '0';
							c = snext();
						} while (!id0(c));
						return res * sgn;
					}
			 
					public long nextLong()
				    {
						int c = snext();
						while (id0(c)) 
						{
							c = snext();
						}
						int sgn = 1;
						if (c == '-') 
						{
							sgn = -1;
							c = snext();
						}
						long res = 0;
						do 
						{
							if (c < '0' || c > '9')
								throw new InputMismatchException();
							res *= 10;
							res += c - '0';
							c = snext();
						} while (!id0(c));
						return res * sgn;
					}
			 
					public int[] id3(int n) 
					{
						int a[] = new int[n];
						for (int i = 0; i < n; i++) 
						{
							a[i] = nextInt();
						}
						return a;
					}
			 
					public String readString()
				    {
						int c = snext();
						while (id0(c)) 
						{
							c = snext();
						}
						StringBuilder res = new StringBuilder();
						do 
						{
							res.appendCodePoint(c);
							c = snext();
						} while (!id0(c));
						return res.toString();
					}
			 
					public String nextLine() 
					{
						int c = snext();
						while (id0(c))
							c = snext();
						StringBuilder res = new StringBuilder();
						do 
						{
							res.appendCodePoint(c);
							c = snext();
						} while (!id4(c));
						return res.toString();
					}
			 
					public boolean id0(int c) 
					{
						if (filter != null)
							return filter.id0(c);
						return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
					}
			 
					private boolean id4(int c) 
					{
						return c == '\n' || c == '\r' || c == -1;
					}
			 
					public interface id9
				    {
						public boolean id0(int ch);
					}
				}
				public static long c = 0;
				
				public static long mod = 1000000007;
				public static int d;
				public static int p;
				public static int q;
				
				
				
						
				public static  int gcd(int p2, int p22)
				{
				    if (p2 == 0)
				        return (int) p22;
				    return gcd(p22%p2, p2);
				}
				
					
				
				public static int id10(int arr[], int n)
				{
				    int result = arr[0];
				    for (int i=1; i<n; i++)
				        result = gcd(arr[i], result);
				 
				    return result;
				}
				
				
				
				
			
			    public static long lcm(int[] numbers) {
			        long lcm = 1;
			        int divisor = 2;
			        while (true) {
			            int cnt = 0;
			            boolean divisible = false;
			            for (int i = 0; i < numbers.length; i++) {
			                if (numbers[i] == 0) {
			                    return 0;
			                } else if (numbers[i] < 0) {
			                    numbers[i] = numbers[i] * (-1);
			                }
			                if (numbers[i] == 1) {
			                    cnt++;
			                }
			                if (numbers[i] % divisor == 0) {
			                    divisible = true;
			                    numbers[i] = numbers[i] / divisor;
			                }
			            }
			            if (divisible) {
			                lcm = lcm * divisor;
			            } else {
			                divisor++;
			            }
			            if (cnt == numbers.length) {
			                return lcm;
			            }
			        }
			    }
				public static long fact(long n) {
					
					long factorial = 1;
					 for(int i = 1; i <= n; i++)
				        {
				            factorial *= i;
				        }
					 return factorial;
				}
				
				
				
				public static int lowerLimit(int[] a, int n) {
					int ans = 0;
					
					int ll = 0;
					int rl = a.length-1;
				

					if(a[0]>n)
						return 0;
					if(a[0]==n)
						return 1;
					else if(a[rl]<=n)
						return rl+1;
				
					while(ll<=rl)
					{
						
						int mid = (ll+rl)/2;
						if(a[mid]==n)
						{
							ans = mid + 1;
							break;
						}
						
						else if(a[mid]>n)
						{
							rl = mid-1;
							
						}
						else
						{
							ans = mid+1;
							ll = mid+1;
						}
					}
					
					return ans; 
				}
				
				
				public static long choose(long total, long choose){
				    if(total < choose)
				        return 0;
				    if(choose == 0 || choose == total)
				        return 1;
				    return (choose(total-1,choose-1)+choose(total-1,choose))%mod;
				}
				
				public static int[] suffle(int[] a,Random gen)
				{
					int n = a.length;
					for(int i=0;i<n;i++)
					{
						int ind = gen.nextInt(n-i)+i;
						int temp = a[ind];
						a[ind] = a[i];
						a[i] = temp;
					}
					return a;
				}
				
				public static int floorSearch(int arr[], int low, int high, int x)
				{
				    if (low > high)
				        return -1;
				 
				    if (x > arr[high])
				        return high;
				    int mid = (low+high)/2;
				 
				 
				    if (mid > 0 && arr[mid-1] < x && x < arr[mid])
				        return mid-1;
				 
				    if (x < arr[mid])
				        return floorSearch(arr, low, mid-1, x);
				 
				    return floorSearch(arr, mid+1, high, x);
				}
				
				
				public static void swap(int a, int b){
					int temp = a;
					a = b;
					b = temp;
				}
				
				
				
				public static long power(long x, long y)
				{
				    long temp;
				    if( y == 0)
				       return 1;
				    temp = power(x, y/2)%mod;       
				    if (y%2 == 0)
				        return (temp*temp)%mod;
				    else
				    {
				        if(y > 0)
				            return ((x*temp)%mod*(temp)%mod)%mod;
				        else
				            return ((temp*temp)%mod/x)%mod;
				    }
				}  
				
				public static void randomize( int arr[], int n)
			    {
			        Random r = new Random();
			        for (int i = n-1; i > 0; i--) {
			        	int j = r.nextInt(i);
			            int temp = arr[i];
			            arr[i] = arr[j];
			            arr[j] = temp;
			        }
			    }
			     
				
				public static ArrayList<Integer> id1(int n)
				{
					ArrayList<Integer> a =new ArrayList<Integer>();
					for(int i=2;i*i<=n;i++)
					{
						while(n%i==0)
						{
							a.add(i);
							n/=i;
						}
					}
					if(n!=1)
						a.add(n);
					return a;
				}
				
				public static void sieve(boolean[] isPrime,int n)
				{
					for(int i=1;i<n;i++)
						isPrime[i] = true;
					
					isPrime[0] = false;
					isPrime[1] = false;
					
					for(int i=2;i*i<n;i++)
					{
						if(isPrime[i] == true)
						{
							for(int j=(2*i);j<n;j+=i)
								isPrime[j] = false;
						}
					}
				}
				
				public static int GCD(int a,int b)
				{
					if(b==0)
						return a;
					else
						return GCD(b,a%b);
				}
				
				public static long GCD(long a,long b)
				{
					if(b==0)
						return a;
					else
						return GCD(b,a%b);
				}
				
				public static void id5(int A,int B)
				{
					if(B==0)
					{
						d = A;
						p = 1 ;
						q = 0;
					}
					else
					{
						id5(B, A%B);
						int temp = p;
						p = q;
						q = temp - (A/B)*q;
					}
				}
				
				public static long LCM(long a,long b)
				{
					return (a*b)/GCD(a,b);
				}
				
				public static int LCM(int a,int b)
				{
					return (a*b)/GCD(a,b);
				}
				
				public static int id8(int x,int n)
				{
				    int result=1;
				    while(n>0)
				    {
				        if(n % 2 ==1)
				            result=result * x;
				        x=x*x;
				        n=n/2;
				    }
				    return result;
				}
				
				public static long id8(long x,long n)
				{
				    long result=1;
				    while(n>0)
				    {
				        if(n % 2 ==1)
				            result=result * x;
				        x=(x%mod * x%mod)%mod;
				        n=n/2;
				    }
				    return result;
				}
				
				public static int id6(int x,int n,int M)
				{
				    int result=1;
				    while(n>0)
				    {
				        if(n % 2 ==1)
				            result=(result * x)%M;
				        x=(x*x)%M;
				        n=n/2;
				    }
				    return result;
				}
				
				public static long id6(long x,long n,long M)
				{
				    long result=1;
				    while(n>0)
				    {
				        if(n % 2 ==1)
				            result=(result * x)%M;
				        x=(x*x)%M;
				        n=n/2;
				    }
				    return result;
				}
				
				public static int modInverse(int A,int M)
				{
				    return id6(A,M-2,M);
				}
				
				public static long modInverse(long A,long M)
				{
				    return id6(A,M-2,M);
				}
				
				public static boolean isPrime(int n)
				{
				    
				    if (n <= 1)  return false;
				    if (n <= 3)  return true;
				    
				    if (n%2 == 0 || n%3 == 0) 
				    	return false;
				 
				    for (int i=5; i*i<=n; i=i+6)
				    {
				        if (n%i == 0 || n%(i+2) == 0)
				           return false;
				    }
				    
				    return true;
				}
				
				static class pair implements Comparable<pair>
		
				{
					Integer x, y;
					pair(int x,int y)
					{
						this.x=x;
						this.y=y;
					}
					
					public int compareTo(pair o) {
						int result = x.compareTo(o.x);
						if(result==0)
							result = y.compareTo(o.y);
						
						return result;
					}  
					
					public String toString()
					{
						return x+" "+y;
					}
					
					public boolean equals(Object o)
					{
						if (o instanceof pair)
					    {
							pair p = (pair)o;
							return p.x == x && p.y == y ;
						}
						return false;
					}
					
					public int hashCode()
					{
						return new Long(x).hashCode()*31 + new Long(y).hashCode();
					}
				}
			
		
				static class pairLong implements Comparable<pairLong>
				
				{
					Long x, y;
					pairLong(long x,long y)
					{
						this.x=x;
						this.y=y;
					}
					
					public int compareTo(pairLong o) {
						int result = x.compareTo(o.x);
						if(result==0)
							result = y.compareTo(o.y);
						
						return result;
					}  
					
					public String toString()
					{
						return x+" "+y;
					}
					
					public boolean equals(Object o)
					{
						if (o instanceof pair)
					    {
							pairLong p = (pairLong)o;
							return p.x == x && p.y == y ;
						}
						return false;
					}
					
					public int hashCode()
					{
						return new Long(x).hashCode()*31 + new Long(y).hashCode();
					}
				}
				
				
				
				public static int id7(pairLong[] a, long n)
				{
					int idx = 0;
					int start = 0;
					int end = a.length-1;
					while(start <= end)
					{
						

						
						int mid = (end + start)/2;
						if(n==a[mid].x)
							return mid;
						else if(n<a[mid].x)
							end = mid -1;
						else
							start = mid +1;
					}
					
					
					
					
					return -1;
				}
		
				static class node implements Comparable<node>
		
				{
					Integer x, y, z;
					node(int x,int y, int z)
					{
						this.x=x;
						this.y=y;
						this.z=z;
					}
					
					public int compareTo(pair o) {
						int result = x.compareTo(o.x);
						if(result==0)
							result = y.compareTo(o.y);
						if(result==0)
							result = z.compareTo(z); 
						return result;
					}
		
					@Override
					public int compareTo(node o) {
						

						return 0;
					}  
				}
			}
				