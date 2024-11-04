import java.util.*;
import java.io.*;
import java.lang.*;
	
public class code3
	{
		
		public static HashSet<Long> set;
		public static void main(String[] args)
		{
			InputReader in = new InputReader(System.in);
			PrintWriter pw = new PrintWriter(System.out);
			
			

		
			int n = in.nextInt();
			long[] v = new long[n];
			long[] t = new long[n];
			for(int i=0; i<n; i++)
				v[i] = in.nextLong();
			
			long[] psum = new long[n];
			for(int i=0; i<n; i++)
			{
				t[i] = in.nextLong();
				if(i>0)
					psum[i] = psum[i-1] + t[i];
				else
					
					psum[i] = t[i];
			}
			
			
			int[] f = new int[n+1];
			long[] last = new long[n];
			ArrayList<Integer> list = new ArrayList<>();
			pair[] p = new pair[2*n];
			int pi = 0;
			for(int i=0; i<n; i++)
			{
				if(i>0)
					f[i] = lowerboundArray(psum, v[i]+psum[i-1])+1;
				else
					f[i] = lowerboundArray(psum, v[i])+1;
				
				if(i>0 && f[i]<n && f[i]>0)	
					last[f[i]] += (v[i]+psum[i-1] - psum[f[i]-1]); 
				if(i==0 & f[i]<n && f[i]>0)
					last[f[i]] += (v[i]- psum[f[i]-1]); 
				
				p[pi++] = new pair(i, 1);
				p[pi++] = new pair(f[i], -1);
			}
			Arrays.sort(p);
			int sum = 0;
		
			
			int fi = 0;
			for(int i=0; i<pi; i++)
			{
				if(i>0)
				{
					if(p[i].x==p[i-1].x)
						sum += p[i].y;
					else
					{	
						f[p[i-1].x] = sum;
						sum += p[i].y;
					}
				}
				else
					sum += p[i].y;
			}
			if(p[pi-1].x==n-1)
				f[n-1] = sum;
			

		

			

		
			

			for(int i=0; i<n; i++)
			{
				long ans = f[i]*t[i] + last[i];
				if(i>0)
				pw.print(ans+" ");
				else
					pw.print(Math.min(t[i], v[i])+" ");
			}
			
			
			

			
			pw.flush();
			pw.close();
		}
		
		public static double sumOfGP(double a, double r, double n)
		    {
		        

		        return (a * (1 - (int)(Math.pow(r, n)))) / 
		                                            (1 - r);
		    }
		
		static class InputReader 
		{
			 
			private final InputStream stream;
			private final byte[] buf = new byte[8192];
			private int curChar, snumChars;
			private SpaceCharFilter filter;
	 
			public InputReader(InputStream stream) 
			{
				this.stream = stream;
			}
	 
			public int snext() 
			{
				if (snumChars == -1)
					throw new InputMismatchException();
				if (curChar >= snumChars) 
				{
					curChar = 0;
					try 
					{
						snumChars = stream.read(buf);
					} 
					catch (IOException e) 
					{
						throw new InputMismatchException();
					}
					if (snumChars <= 0)
						return -1;
				}
				return buf[curChar++];
			}
	 
			public int nextInt() 
		    {
				int c = snext();
				while (isSpaceChar(c)) 
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
				} while (!isSpaceChar(c));
				return res * sgn;
			}
	 
			public long nextLong()
		    {
				int c = snext();
				while (isSpaceChar(c)) 
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
				} while (!isSpaceChar(c));
				return res * sgn;
			}
	 
			public int[] nextIntArray(int n) 
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
				while (isSpaceChar(c)) 
				{
					c = snext();
				}
				StringBuilder res = new StringBuilder();
				do 
				{
					res.appendCodePoint(c);
					c = snext();
				} while (!isSpaceChar(c));
				return res.toString();
			}
	 
			public String nextLine() 
			{
				int c = snext();
				while (isSpaceChar(c))
					c = snext();
				StringBuilder res = new StringBuilder();
				do 
				{
					res.appendCodePoint(c);
					c = snext();
				} while (!isEndOfLine(c));
				return res.toString();
			}
	 
			public boolean isSpaceChar(int c) 
			{
				if (filter != null)
					return filter.isSpaceChar(c);
				return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
			}
	 
			private boolean isEndOfLine(int c) 
			{
				return c == '\n' || c == '\r' || c == -1;
			}
	 
			public interface SpaceCharFilter
		    {
				public boolean isSpaceChar(int ch);
			}
		}
		public static long c = 0;
		
		public static long mod = 1000000009;
		public static int d;
		public static int p;
		public static int q;
		public static boolean flag;
		
		
				
		public static  int gcd(int p2, int p22)
		{
		    if (p2 == 0)
		        return (int) p22;
		    return gcd(p22%p2, p2);
		}
		
			
	
		
		
		public static int findGCD(int arr[], int n)
		{
		    int result = arr[0];
		    for (int i=1; i<n; i++)
		        result = gcd(arr[i], result);
		 
		    return result;
		}
		
	

		public static void nextGreater(long[] a, int[] ans)
		{
			
			Stack<Integer> stk = new Stack<>();
			stk.push(0);
			
			
			for(int i=1; i<a.length; i++)
			{
				
				if(!stk.isEmpty())
				{
				int s = stk.pop();
				while(a[s]<a[i])
				{
					ans[s] = i;
					if(!stk.isEmpty())
						s = stk.pop();
					else
						break;
				}
				if(a[s]>=a[i])
					stk.push(s);
				}
				
				stk.push(i);
				
			}
			return;
			
		}
		
		public static void nextGreaterRev(long[] a, int[] ans)
		{
			
			int n = a.length;
			int[] pans = new int[n];
			Arrays.fill(pans, -1);
			long[] arev = new long[n];
			for(int i=0; i<n; i++)
				arev[i] = a[n-1-i];
			
			Stack<Integer> stk = new Stack<>();
			stk.push(0);
			
			
			for(int i=1; i<n; i++)
			{
				
				if(!stk.isEmpty())
				{
				int s = stk.pop();
				while(arev[s]<arev[i])
				{
					pans[s] = n - i-1;
					if(!stk.isEmpty())
						s = stk.pop();
					else
						break;
				}
				if(arev[s]>=arev[i])
					stk.push(s);
				}
				
				stk.push(i);
				
			}
			
			

				

			
			for(int i=0; i<n; i++)
				ans[i] = pans[n-i-1];
			
			
			
			return;
			
		}
		
		
		public static void nextSmaller(long[] a, int[] ans)
		{
			
			Stack<Integer> stk = new Stack<>();
			stk.push(0);
			
			
			for(int i=1; i<a.length; i++)
			{
				
				if(!stk.isEmpty())
				{
				int s = stk.pop();
				while(a[s]>a[i])
				{
					ans[s] = i;
					if(!stk.isEmpty())
						s = stk.pop();
					else
						break;
				}
				if(a[s]<=a[i])
					stk.push(s);
				}
				
				stk.push(i);
				
			}
			return;
			
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
		public static ArrayList<Integer> primeFactorization(int n)
		{
			ArrayList<Integer> a =new ArrayList<Integer>();
			HashSet<Long> set = new HashSet<>();
			for(int i=2;i*i<=n;i++)
			{
				while(n%i==0)
				{
					
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
		
		public static int lowerbound(ArrayList<Integer> list, int n) {
			int i=Collections.binarySearch(list, n);
			if(i<0)
				i = -(i+2);
			return i;
			
			
		}
		public static int lowerboundArray(long[] list, long n) {
			int i=Arrays.binarySearch(list, n);
			if(i<0)
				i = -(i+2);
			return i;
			
			
		}
		public static int uperbound(ArrayList<Integer> list, int n) {
			int i=Collections.binarySearch(list, n);
			if(i<0)
				i = -(i+1);
			return i;
			
			
		}
		public static int uperboundArray(long[] list, long n) {
			int i=Arrays.binarySearch(list, n);
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
		
		public static void extendedEuclid(int A,int B)
		{
			if(B==0)
			{
				d = A;
				p = 1 ;
				q = 0;
			}
			else
			{
				extendedEuclid(B, A%B);
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
		
		public static int binaryExponentiation(int x,int n)
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
		
		
		 static long binomialCoeff(int n, int k)
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
		
		public static long binaryExponentiation(long x,long n)
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
		
		public static int modularExponentiation(int x,int n,int M)
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
		
		public static double modularExponentiation(double x,double n,long M)
		{
		    double result=1;
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
		    return modularExponentiation(A,M-2,M);
		}
		
		public static double modInverse(long A,long M)
		{
		    return modularExponentiation(A,M-2,M);
		}
		
		
		public static void sieveFact(int[] primf, int n) {
			
			
			for(int i=2;i*i<=n;i++)
				if(primf[i]==0){
					primf[i]=i;
					
					for(int j=i*i;j<=n;j+=i)
						primf[j]=i;
				
			}
			
			
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
	
		
	
	