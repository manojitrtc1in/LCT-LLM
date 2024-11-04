import java.util.*;
import java.util.concurrent.LinkedBlockingDeque;
import java.io.*;
import java.lang.*;
	
	public class graph1
	{
		public static int n;
		public static ArrayList<Integer> adj[];
		public static ArrayList<Integer> adj2[];
		
		public static ArrayList<Integer> child[];
		public static boolean[] vis;
		public static ArrayList<Integer> pair;
		public static int[] par;
		public static int[] level;
		public static int[] set;
		public static int[] a;
		public static int[] ans;
		public static int[] init;
		public static int[] goal;
		
		public static int count;
		
		public static long INF = Long.MAX_VALUE/100;
		
		
		public static void main(String[] args)
		{
			InputReader in = new InputReader(System.in);
			PrintWriter pw = new PrintWriter(System.out);
	
	

			n = in.nextInt();
			

			

			
			
			

			vis = new boolean[n+1];
			par = new int[n+1];
			set = new int[n+1];
			level = new int[n+1];
			init = new int[n+1];
			goal = new int[n+1];
			pair = new ArrayList<>();
			adj = new ArrayList[n+1];
			adj2 = new ArrayList[n+1];
			for(int i=0; i<=n; i++)
			{
				vis [i] = false;
				par[i] = -1;
			}
			
			
			
			for(int i=0;i<=n;i++)
			{
				adj[i] = new ArrayList<Integer>();
				adj2[i] = new ArrayList<Integer>();
				
			}
			
			
			for(int i=0; i<n-1; i++)
			{
				int u = in.nextInt();
				int v = in.nextInt();
				adj[u].add(v);
				adj[v].add(u);
				
			
			}
			
			for(int i=1; i<=n; i++)
				init[i] = in.nextInt();
			for(int i=1; i<=n; i++)
				goal[i] = in.nextInt();
			
			
			
			bfs(1);
			Queue<Integer> que = new LinkedList<>();
			que.add(1);
			for(int i=0; i<=n; i++)
			{
				vis [i] = false;
				par[i] = -1;
			}
			
			id1(1, 0, 0, que);
			pw.println(count);
			for(int p: pair)
				pw.println(p);
			
			
			
			

			pw.flush();
			pw.close();
		}
		
		
		public static void id1(int last, int odd, int even, Queue<Integer> que)
		
		{
			
			

				

		
			

			

			

				

			
			int curr = (init[last]);
			if(level[last]%2==0)
				curr += even;
			else
				curr += odd;
			
			

			
			if(goal[last]%2!=curr%2)
			{
				if(level[last]%2==0)
					even++;
				else
					odd++;
				count++;
				pair.add(last);
				
			}
			
			for(int p : adj2[last])
				{
					if(!vis[p])
					{
					

						vis[p] = true;
						id1(p, odd, even, que);
					}
				}
			
			
			

			
		}
		
		
		
		
		public static int bfs(int x)
		{
			Queue<Integer> queue = new LinkedList<>();
			queue.add(x);
			level[x] = 0;
			int c = 0;
			

			boolean[] vis = new boolean[n+1]; 
			vis[x] = true;
			while(!queue.isEmpty())
			{
				int last = queue.poll();
				for(int p : adj[last])
				{
					if(!vis[p])
					{
							

						queue.add(p);
					adj2[last].add(p);
						vis[p] = true;
						c++;
					

						level[p] = level[last]+1;
						
					}
				}
			}
			return c;
		}
		
		public static int fbfs(int x)
		{
			Queue<Integer> queue = new LinkedList<>();
			queue.add(x);
			

			int c = 0;
			

			

			vis[x] = true;
			while(!queue.isEmpty())
			{
				int last = queue.poll();
				for(int p : adj[last])
				{
					if(!vis[p])
					{
							

						queue.add(p);
					

						vis[p] = true;
						c++;
					

						

						
					}
				}
			}
			return c;
		}
		
		
		
	
		

		
		
	
		
		
		
		
		
		
		static class pair implements Comparable<pair>
		 
		{
			Long x;
			Integer y;
			pair(long adj,int y)
			{
		
				this.x=adj;
				this.y=y;
			}
			
			public int compareTo(pair o) {
				

				

					int result = -y.compareTo(o.y);
				
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
		
	
		
		
		
		static class InputReader 
		{
			 
			private final InputStream stream;
			private final byte[] buf = new byte[8192];
			private int curChar, id3;
			private id9 filter;
	 
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
				} while (!id5(c));
				return res.toString();
			}
	 
			public boolean id0(int c) 
			{
				if (filter != null)
					return filter.id0(c);
				return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
			}
	 
			private boolean id5(int c) 
			{
				return c == '\n' || c == '\r' || c == -1;
			}
	 
			public interface id9
		    {
				public boolean id0(int ch);
			}
		}
		
		public static long mod = 1000000007;
		public static int d;
		public static int p;
		public static int q;
		
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
		
		public static void swap(int a, int b){
			int temp = a;
			a = b;
			b = temp;
		}
		
		public static HashSet<Integer> id2(int n)
		{
			HashSet<Integer> a =new HashSet<Integer>();
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
		
		public static void id6(int A,int B)
		{
			if(B==0)
			{
				d = A;
				p = 1 ;
				q = 0;
			}
			else
			{
				id6(B, A%B);
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
		        x=x*x;
		        n=n/2;
		    }
		    return result;
		}
		
		public static int id7(int x,int n,int M)
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
		
		public static long id7(long x,long n,long M)
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
		    return id7(A,M-2,M);
		}
		
		public static long modInverse(long A,long M)
		{
		    return id7(A,M-2,M);
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
		
		
	}