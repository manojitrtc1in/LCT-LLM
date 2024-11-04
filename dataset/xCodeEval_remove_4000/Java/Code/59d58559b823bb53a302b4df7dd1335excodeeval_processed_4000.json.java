	import java.util.*;
	import java.awt.List;
	import java.io.*;
	import java.lang.*;
import java.lang.reflect.Array;
		
	public class code4
		{
	 	public static void main(String[] args)
			{
				InputReader in = new InputReader(System.in);
				PrintWriter pw = new PrintWriter(System.out);
				
				

				


				int n = in.nextInt();
				int m = in.nextInt();
				
				
				ArrayList<Integer> ans1 = new ArrayList<>();
				ArrayList<Integer> ans2 = new ArrayList<>();
				int count = 0;
				if(m<n-1 || m>(long)n*(n-1)/2)
					pw.println("Impossible");
				else
				{
					
					for(int i=1; i<=n; i++)
					{
							
							for(int j=i+1; j<=n && m>0; j++)
							{
								
								if(gcd(i, j)==1)
								{
									ans1.add(i);
									ans2.add(j);
									

									count++;
								}
								if(count==m)
									break;
								
								
							}
							
							if(count==m)
								break;
						
						
						
					}
					
					
				
				if(count>=m)
				{
					pw.println("Possible");
					for(int i=0; i<m; i++)
						pw.println(ans1.get(i)+" "+ans2.get(i));
				
				}
				else
					pw.println("Impossible");
				}
				
				

				
				pw.flush();
				pw.close();
			}
		
			
			static class InputReader 
			{
				 
				private final InputStream stream;
				private final byte[] buf = new byte[8192];
				private int curChar, id3;
				private id12 filter;
		 
				public InputReader(InputStream stream) 
				{
					this.stream = stream;
				}
		 
				public int snext() 
				{
					if (id3 == -1)
						throw new InputMismatchException();
					if (curChar >= id3) 
					{
						curChar = 0;
						try 
						{
							id3 = stream.read(buf);
						} 
						catch (IOException e) 
						{
							throw new InputMismatchException();
						}
						if (id3 <= 0)
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
		 
				public int[] id4(int n) 
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
					} while (!id6(c));
					return res.toString();
				}
		 
				public boolean id0(int c) 
				{
					if (filter != null)
						return filter.id0(c);
					return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
				}
		 
				private boolean id6(int c) 
				{
					return c == '\n' || c == '\r' || c == -1;
				}
		 
				public interface id12
			    {
					public boolean id0(int ch);
				}
			}
			public static long c = 0;
			
			public static long mod = 1000000007;
			public static int d;
			public static int p;
			public static int q;
			public static boolean flag;
			public static long INF= Long.MAX_VALUE;
			
			
			public static double slope(pair p1, pair p2)
			{
				double m = INF;
				if((p1.x - p2.x)!=0)
				m =  p1.y - p2.y/(p1.x - p2.x); 
				
				
				return Math.abs(m);
				
			}
			
			public static long gcd(long i, long l) {
				if (i == 0)
					return (long) l;
				return gcd(l % i, i);
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
			
			public static void id10(int[] a, int n) {
				
				
				for(int i=2; i<=n; i+=2)
					a[i] = 2;
				
				
				for(int i=3; i<=n; i+=2)
				{
					if(a[i]==0)
					{
						a[i] = i;
						
						for(int j=i; j*i<=n; j++)
						{
							a[i*j] = i;	
						}
					}
				}
				
				int k = 1000;
				while(k!=1)
				{
					System.out.print(a[k]+" ");
					k /= a[k];
					
				}
			}
		
			
			
			public static long choose(long total, long choose){
			    if(total < choose)
			        return 0;
			    if(choose == 0 || choose == total)
			        return 1;
			    return (choose(total-1,choose-1)+choose(total-1,choose))%mod;
			}
			
			public static long[] suffle(long[] a,Random gen)
			{
				int n = a.length;
				for(int i=0;i<n;i++)
				{
					int ind = gen.nextInt(n-i)+i;
					long temp = a[ind];
					a[ind] = a[i];
					a[i] = temp;
				}
				return a;
			}
			
			public static long[] sort(long[] a)
			{
				Random gen = new Random();
				int n = a.length;
				for(int i=0;i<n;i++)
				{
					int ind = gen.nextInt(n-i)+i;
					long temp = a[ind];
					a[ind] = a[i];
					a[i] = temp;
				}
				
				Arrays.sort(a);
				return a;
			}
			
			public static int[] sort(int[] a)
			{
				Random gen = new Random();
				int n = a.length;
				for(int i=0;i<n;i++)
				{
					int ind = gen.nextInt(n-i)+i;
					int temp = a[ind];
					a[ind] = a[i];
					a[i] = temp;
				}
				
				Arrays.sort(a);
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
			
			public static int lowerbound(ArrayList<Long> net, long c2) {
				int i=Collections.binarySearch(net, c2);
				if(i<0)
					i = -(i+2);
				return i;
				
				
			}
			
			public static int id2(long[] psum, long c2) {
				int i=Arrays.binarySearch(psum, c2);
				if(i<0)
					i = -(i+2);
				return i;
				
				
			}
			
			public static int id5(long[] psum, long c2) {
				int i=Arrays.binarySearch(psum, c2);
				if(i<0)
					i = -(i+1);
				return i;
				
				
			}
			
			
			public static int uperbound(ArrayList<Long> net, long c2) {
				int i=Collections.binarySearch(net, c2);
				if(i<0)
					i = -(i+1);
				return i;
				
				
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
			
			public static void id7(int A,int B)
			{
				if(B==0)
				{
					d = A;
					p = 1 ;
					q = 0;
				}
				else
				{
					id7(B, A%B);
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
			
			public static int id11(int x,int n)
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
			
			
			public static int[] countDer(int n)
		    {
		        int der[] = new int[n + 1];
		     
		        der[0] = 1;
		        der[1] = 0;
		        der[2] = 1;
		     
		        for (int i = 3; i <= n; ++i)
		            der[i] = (i - 1) * (der[i - 1] + der[i - 2]);
		     
		        

		        return der;
		    }
			
			
			 static long id9(int n, int k)
			    {
			    long C[][] = new long[n+1][k+1];
			    int i, j;
			     
			        

			    for (i = 0; i <= n; i++)
			    {
			        for (j = 0; j <= Math.min(i, k); j++)
			        {
			            

			            if (j == 0 || j == i)
			                C[i][j] = 1;
			      
			            

			            else
			                C[i][j] = C[i-1][j-1] + C[i-1][j];
			          }
			     }
			      
			    return C[n][k];
			    }
			
			public static long id11(long x,long n)
			{
			    long result=1;
			    while(n>0)
			    {
			        if(n % 2 ==1)
			            result= (result * x)%mod;
			        x=(x%mod * x%mod)%mod;
			        n=n/2;
			    }
			    return result%mod;
			}
			
			public static int id8(int x,int n,int M)
			{
			    int result=1;
			    while(n>0)
			    {
			        if(n % 2 ==1)
			            result=(result * x)%M;
			        x=(x%M*x%M)%M;
			        n=n/2;
			    }
			    return result;
			}
			
			public static long id8(long x,long n,long M)
			{
			    long result=1;
			    while(n>0)
			    {
			        if(n % 2 ==1)
			            result=(result %M* x%M)%M;
			        x=(x*x)%M;
			        n=n/2;
			    }
			    return result;
			}
			
			public static int modInverse(int A,int M)
			{
			    return id8(A,M-2,M);
			}
			
			public static long modInverse(long A,long M)
			{
			    return id8(A,M-2,M);
			}
			
			
			public static boolean checkYear(int year)
		    {
				if (year % 400 == 0)
		            return true;
		     
		        if (year % 100 == 0)
		            return false;
		     
		        if (year % 4 == 0)
		            return true;
		        return false;
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
				Long x;
				Integer y;
				pair(long a,int y)
				{
					this.x=a;
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
		
			
			static class triplet implements Comparable<triplet>
			{
				Integer x,y,z;
				triplet(int x,int y,int z)
				{
					this.x = x;
					this.y = y;
					this.z = z;
				}
				
				public  int compareTo(triplet o)
				{
					int result = x.compareTo(o.x);
					if(result==0)
						result =  y.compareTo(o.y);
					if(result==0)
						result = z.compareTo(o.z);
	 
					return result;
				}
				
				public boolean equlas(Object o)
				{
					if(o instanceof triplet)
					{
						triplet p = (triplet)o;
						return x==p.x && y==p.y && z==p.z;
					}
					return false;
				}
				
				public String toString()
				{
					return x+" "+y+" "+z;
				}
				public int hashCode()
				{
					return new Long(x).hashCode()*31 + new Long(y).hashCode() + new Long(z).hashCode(); 
				}
			}
			
	 
			
			
	
		}
		
			