import java.util.*;

import javax.print.attribute.HashAttributeSet;

import java.awt.List;
import java.io.*;
import java.lang.*;
	
public class code3
	{

	
		
	
		public static void main(String[] args)
		{
			InputReader in = new InputReader(System.in);
			PrintWriter pw = new PrintWriter(System.out);
			
			
			
			


			
			
	
			
			int n = in.nextInt();
			int m = in.nextInt();
		
			int[] a = new int[n];
			ArrayList<Integer> list = new ArrayList<>();
			HashMap<Integer, Integer> map = new HashMap<>();
			for(int i=0; i<n; i++) {
				a[i] = in.nextInt();
				if(map.containsKey(a[i]))
					map.put(a[i],map.get(a[i])+1);
				else
					map.put(a[i], 1);
		

			}
			
			Collections.sort(list);
			Stack<pair> stk = new Stack<>();
			
			pair[] p = new pair[m];
			for(int i=0; i<m; i++)
			{
		
				int t = in.nextInt();
				int r = in.nextInt()-1;
				p[i] = new pair(t, r);
				
				
			}
		
			pair[] fp = new pair[m+1];
			int pi = 0;
			fp[pi++] = new pair(0, -1);
			for(int i=m-1; i>=0; i--)
			{
				if(i==m-1)
				fp[pi++] = p[i]; 
				else
				{
					if(p[i].y > fp[pi-1].y)
					{
						fp[pi++] = p[i];
					}
				
				}
				
			}
			
			
			int len = pi;
			int[] ans = new int[n];
			for(int i=fp[pi-1].y+1; i<n; i++)
			{
				ans[i] = a[i];
				map.put(a[i], map.get(a[i])-1);
			

			}
			
			for(int q: map.keySet())
			{
				
				for(int i=0; i<map.get(q); i++)
					list.add(q);
			}
			
			

			
			if(map.size()>=2)
				Collections.sort(list);
			
			int ed = list.size()-1;
			int st = 0;
			
			
			for(int i=pi-1; i-1>=0; i--)
			{
				pair p1 = fp[i];
				pair p2 = fp[i-1];
				for(int j=p1.y; j>p2.y; j--)
				{
					if(p1.x==1)
					{
						ans[j] = list.get(ed--);
					}
					else
					{
						ans[j] = list.get(st++);
					}
				}
				
			}
			
			for(int j=0; j<n; j++)
				pw.print(ans[j]+" ");
			pw.println();
			
			
			
			
			
			

			
			
			
			
			pw.flush();
			pw.close();
		}
	
		
		public static boolean id6(char[] str2,  String str1)
		{
      
			int j = 0;
			int m = str1.length();
			int n = str2.length;		
     
			for (int i = 0; i < n && j < m; i++)
          
				if (str1.charAt(j) == str2[i])
            
					j++;

			return (j == m); 
  }
		
		static class InputReader 
		{
			 
			private final InputStream stream;
			private final byte[] buf = new byte[8192];
			private int curChar, id3;
			private id15 filter;
	 
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
				while (id1(c)) 
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
				} while (!id1(c));
				return res * sgn;
			}
	 
			public long nextLong()
		    {
				int c = snext();
				while (id1(c)) 
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
				} while (!id1(c));
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
				while (id1(c)) 
				{
					c = snext();
				}
				StringBuilder res = new StringBuilder();
				do 
				{
					res.appendCodePoint(c);
					c = snext();
				} while (!id1(c));
				return res.toString();
			}
	 
			public String nextLine() 
			{
				int c = snext();
				while (id1(c))
					c = snext();
				StringBuilder res = new StringBuilder();
				do 
				{
					res.appendCodePoint(c);
					c = snext();
				} while (!id9(c));
				return res.toString();
			}
	 
			public boolean id1(int c) 
			{
				if (filter != null)
					return filter.id1(c);
				return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
			}
	 
			private boolean id9(int c) 
			{
				return c == '\n' || c == '\r' || c == -1;
			}
	 
			public interface id15
		    {
				public boolean id1(int ch);
			}
		}
		public static long c = 0;
		
		public static long mod = 1000000007;
		public static int d;
		public static int p;
		public static int q;
		public static boolean flag;
		public static long INF= Long.MAX_VALUE;
		


		public static void id13(int[] fact, long n) {
			
			
			for(int i=2; i<=n; i+=2)
				fact[i] = 2;
			
			
			for(int i=3; i<=n; i+=2)
			{
				if(fact[i]==0)
				{
					fact[i] = i;
					
					for(int j=i; (long)j*i<=n; j++)
					{
						fact[(int)((long)i*j)] = i;	
					}
				}
			}
			
	
		}
	
		
		public static long id8(long n) {
			long ans = 0;
			long l = 0;
			long r = n;
			long mid = 0;
			while(l<=r)
			{
				mid = (l+r)/2;
				if(mid*mid==n)
					return mid;
				
				if(mid*mid>n)
				{
					r = mid-1;
				}
				else
				{
					ans = mid;
					l = mid+1;
				}
				
			}
			
			
			return ans;
		}
		
		
		public static long fun(int[] a, int[] b, int m,int n) {
			long result =0;
			for(int i=0; i<m; i++)
				for(int j=0; j<m; j++)
				{
					long[] fib  = new long[Math.max(2, n+2)];
					fib[1] = a[i];
					fib[2] = b[j];
					for(int k=3; k<=n; k++)
						fib[k] = (fib[k-1]%mod + fib[k-2]%mod)%mod;
					result = (result%mod + fib[n]%mod)%mod;
				}
			
			return result;
			
		}
		
		
	
		
		public static int count(String[] s, int f)
		{
			int count = 0;
			int n = s[0].length();
			
			if(f==1)
			{
			for(int i = 0; i<n; i++)
			{
				for(int j=0; j<n; j++)
				{
					if(i%2==0)
					{
						if(j%2==0 && s[i].charAt(j)=='0')
							count++;
						if(j%2==1 && s[i].charAt(j)=='1')
							count++;
					}
					if(i%2==1)
					{
						if(j%2==1 && s[i].charAt(j)=='0')
							count++;
						if(j%2==0 && s[i].charAt(j)=='1')
							count++;
					}
					
				}
			}
			}
			else
			{
			
			 count = 0;
			
			for(int i = 0; i<n; i++)
			{
				for(int j=0; j<n; j++)
				{
					if(i%2==1)
					{
						if(j%2==0 && s[i].charAt(j)=='0')
							count++;
						if(j%2==1 && s[i].charAt(j)=='1')
							count++;
					}
					if(i%2==0)
					{
						if(j%2==1 && s[i].charAt(j)=='0')
							count++;
						if(j%2==0 && s[i].charAt(j)=='1')
							count++;
					}
					
				}
			}

			}	
				
		
			return count;
			
			
			
		}
				
		public static  int gcd(int p2, int p22)
		{
		    if (p2 == 0)
		        return (int) p22;
		    return gcd(p22%p2, p2);
		}
		
			
	
		
		
		public static int id16(int arr[], int n)
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
		
		public static void id7(long[] a, int[] ans)
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
		
		
		public static void id0(long[] a, int[] ans)
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
		public static ArrayList<Integer> id2(int n)
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
		public static int uperbound(ArrayList<Integer> list, int c2) {
			int i=Collections.binarySearch(list, c2);
			if(i<0)
				i = -(i+1);
			return i;
			
			
		}
		public static int id5(int[] dis, int c2) {
			int i=Arrays.binarySearch(dis, c2);
			if(i<0)
				i = -(i+1);
			return i;
			
			
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
		
		public static void id10(int A,int B)
		{
			if(B==0)
			{
				d = A;
				p = 1 ;
				q = 0;
			}
			else
			{
				id10(B, A%B);
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
		
		public static int id14(int x,int n)
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
		
		
		 static long id12(int n, int k)
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
		
		public static long id14(long x,long n)
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
		
		public static int id11(int x,int n,int M)
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
		
		public static long id11(long x,long n,long M)
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
		    return id11(A,M-2,M);
		}
		
		public static long sie(long A,long M)
		{
		    return id11(A,M-2,M);
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
		

		
		
		
	
	
	}
	
		
	
	