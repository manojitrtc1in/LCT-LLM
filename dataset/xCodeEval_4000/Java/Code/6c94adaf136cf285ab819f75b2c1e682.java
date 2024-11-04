	

	

	

 
import java.io.*;
import java.math.BigInteger;
import java.math.RoundingMode;
import java.text.DecimalFormat;
import java.util.*;



public class Tester1{

	static double eps=(double)1e-6;
	static long mod=(long)1e9+7;
	static long d,x ,y;
	public static void main(String args[]){
		InputReader sc = new InputReader(System.in);
		OutputStream outputStream = System.out;
		PrintWriter out = new PrintWriter(outputStream);
        

		int n = sc.nextInt();
		int x = sc.nextInt();
		if(n==1)
			out.print("YES"+"\n"+x);
		else if(n==2 && x==0)
			out.println("NO");
		else if(n==2)
			out.print("YES"+"\n"+"0"+" "+x);
		else
		{
			long pw1 = 1<<17;
			long pw2 = 1<<18;
			int i;
	        int ans=0;
	        out.println("YES");
	        for(i=1;i<=n-3;i++)
	        {
	            out.print(i+" ");
	            ans^=i;
	        }
	        if(ans==x)
	            out.println((pw1+pw2)+" "+pw1+" "+pw2);
	        else
	            out.print(pw1+" "+((pw1^x)^ans)+" 0");
		}
			
		

		out.close();
	}
	public static int[] spf(int n)
	{
		boolean isPrime[] = sieve(n+1);
		int spf[] = new int[n+1];
		Arrays.fill(spf,1);
		spf[0]=0;
		spf[1]=1;
		for(int i=2;i*i<spf.length;i++)
		{
			
			if(spf[i]==1)
			{
				for(int j=2*i;j<spf.length;j+=i)
				{
					if(spf[j]==1)
						spf[j]=i;
				}
			}
			if(isPrime[i])
				spf[i]=i;
		}
		return spf;
	}
	private static boolean isPrime(long temp) {
		if(temp==0 || temp==1)
			return false;
		for(long i=2;i<Math.sqrt(temp);i++)
		{
			if(temp%i==0)
				return false;
		}
		return true;
	}
	static long modInverse(long A, long M)
	{
	    extendedEuclid(A,M);
	    return (x%M+M)%M;    

	}
	static void extendedEuclid(long A, long B) {
		
		if(B == 0) {
	        d = A;
	        x = 1;
	        y = 0;
	    }
	    else {
	        extendedEuclid(B, A%B);
	        long temp = x;
	        x = y;
	        y = temp - (A/B)*y;
	    }
	}
	
	static void topologicalSortUtil(int v, boolean visited[],Stack stack,ArrayList<Integer>[] adj)
		{
			

				visited[v] = true;
				Integer i;
				for(i=0;i<adj[v].size();i++)
				{
						int temp = adj[v].get(i);
						if (!visited[temp])
							topologicalSortUtil(temp, visited, stack,adj);
				}

				stack.push(new Integer(v));
		}

static void topologicalSort(int top[], int V,ArrayList<Integer>[] adj)
{
Stack stack = new Stack();


boolean visited[] = new boolean[V+1];
for (int i = 0; i <=V; i++)
visited[i] = false;


for (int i = 1; i <=V; i++)
if (visited[i] == false)
topologicalSortUtil(i, visited, stack,adj);

int count=0;
while (stack.empty()==false)
{
	top[count]=(int) stack.pop();
	count++;
}
}
		
		public int find(int parent[],int x)
		{
			if(parent[x]==-1)
				return x;
			return find(parent,parent[x]);
		}
		
		public void union(int parent[],int x,int y)
		{
			int xset = find(parent,x);
			int yset = find(parent,y);
			parent[xset] = yset;
		}
	
	
	private static String  xor(String string, String string2) {
		 String temp = "";
		 for(int i=0;i<string.length();i++)
		 {
			 if((string.charAt(i)=='1' && string2.charAt(i)=='1') || (string2.charAt(i)=='0' && string2.charAt(i)=='0'))
				 	temp+="0";
			 else
				 temp+="1";	
		 }
		 return temp;
	}

	private static int count_ones(String temp) {
		

		 int count=0;
		 for(int i=0;i<temp.length();i++)
				if(temp.charAt(i)=='1')
					count++;
		return count;
	}

	static int power(int x,int n)
		{
		    if(n==0)
		        return 1;
		    else if(n%2 == 0)        

		        return power(x*x,n/2);
		    else                             

		        return x*power(x*x,(n-1)/2);
		}
	static long ce(long x)
	{
		if(x%2!=0)
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
	
	static long sort(int a[]) {
		int n = a.length;
		int b[] = new int[n];
		return mergeSort(a, b, 0, n - 1);
	}

	static long mergeSort(int a[], int b[], long left, long right) {
		long c = 0;
		if (left < right) {
			long mid = left + (right - left) / 2;
			c = mergeSort(a, b, left, mid);
			c += mergeSort(a, b, mid + 1, right);
			c += merge(a, b, left, mid + 1, right);
		}
		return c;
	}

	static long merge(int a[], int b[], long left, long mid, long right) {
		long c = 0;
		int i = (int) left;
		int j = (int) mid;
		int k = (int) left;
		while (i <= (int) mid - 1 && j <= (int) right) {
			if (a[i] <= a[j]) {
				b[k++] = a[i++];
			} else {
				b[k++] = a[j++];
				c += mid - i;
			}
		}
		while (i <= (int) mid - 1)
			b[k++] = a[i++];
		while (j <= (int) right)
			b[k++] = a[j++];
		for (i = (int) left; i <= (int) right; i++)
			a[i] = b[i];
		return c;
	}
	
		
	static long fibo(long l) {
        if (l < 0) {
            throw new IllegalArgumentException("The fibo value cannot be negative");
        }

        if (l <= 1) return l;

        long[][] result = {{1, 0}, {0, 1}}; 

        long[][] fiboM = {{1, 1}, {1, 0}};

        while (l > 0) {
            if (l%2 == 1) {
                multMatrix(result, fiboM);
            }
            l = l / 2;
            multMatrix(fiboM, fiboM);
        }

        return result[1][0];
    }

    private static void multMatrix(long[][] result, long[][] fiboM) {
        long a = (result[0][0]%mod * fiboM[0][0]%mod)%mod +  (result[0][1]%mod * fiboM[1][0]%mod)%mod;
        long b = (result[0][0]%mod * fiboM[0][1]%mod)%mod + ( result[0][1]%mod * fiboM[1][1]%mod)%mod;
        long c = (result[1][0]%mod * fiboM[0][0]%mod)%mod + ( result[1][1]%mod * fiboM[0][1]%mod)%mod;
        long d = (result[1][0]%mod * fiboM[0][1]%mod)%mod +  (result[1][1]%mod * fiboM[1][1]%mod)%mod;

        result[0][0] = a;
        result[0][1] = b;
        result[1][0] = c;
        result[1][1] = d;
    }
    
    
    static boolean[] sieve(int n)
	{
		

		

		

		boolean prime[] = new boolean[n+1];
		for(int i=0;i<n;i++)
			prime[i] = true;
		prime[0]=false;
		prime[1]=false;
		for(int p = 2; p*p <=n; p++)
		{
			

			if(prime[p] == true)
			{
				

				for(int i = p*2; i <= n; i += p)
					prime[i] = false;
			}
		
		}
		return prime;
	}
	
	static boolean isPal(String s)
	{
		for(int i=0, j=s.length()-1;i<=j;i++,j--)
		{
			s=s.toLowerCase();
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
	    return a * (b / gcd(a, b));
	}
	
	static long gcd(long a, long b)
	{
	    while (b > 0)
	    {
	        long temp = b;
	        b = a % b; 

	        a = temp;
	    }
	    return a;
	}
	static long modulo(long a,long b,long c) {
		long x=1;
		long y=a;
		while(b > 0){
			if(b%2 == 1){
				x=(x*y)%c;
			}
			y = (y*y)%c; 

			b /= 2;
		}
		return  x%c;
	}
	public static void debug(Object... o) {
		System.out.println(Arrays.deepToString(o));
	}
	static class Pair implements Comparable<Pair> {
		int a, b;

		Pair(int a, int b) {
			this.a = a;
			this.b = b;
		}

		public int compareTo(Pair o) {
			

			return Integer.compare(this.b,o.b);
			

		}

		public boolean equals(Object o) {
			if (o instanceof Pair) {
				Pair p = (Pair) o;
				return p.a == a && p.b == b;
			}
			return false;
		}

		public int hashCode() {
			return new Integer(a).hashCode() * 31 + new Integer(b).hashCode();
		}

		public String toString() {
			return a + " " + b;
		}
	}
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
	int V;
	int E;
	Edge edge[];
	class Edge
	{
		int src,dest;
	}
	public Graph(int V,int E)
	{
		this.V=V;
		this.E=E;
		edge = new Edge[E];
		for(int i=0;i<E;i++)
			edge[i]=new Edge();
	}
}

class SegmentTree 
{
    int st[]; 

 
    
    SegmentTree(int arr[], int n)
    {
        

        

        int x = (int) (Math.ceil(Math.log(n) / Math.log(2)));
 
        

        int max_size = 2 * (int) Math.pow(2, x) - 1;
 
        st = new int[max_size]; 

 
        constructSTUtil(arr, 0, n - 1, 0);
    }
 
    

    int getMid(int s, int e) {
        return s + (e - s) / 2;
    }
 
    
    int getSumUtil(int ss, int se, int qs, int qe, int si)
    {
        

        

     

       

    	if(qs==qe)
        

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
 
    

   

    int getSum(int n, int qs, int qe)
    {
        

        if (qs < 0 || qe > n - 1 || qs > qe) {
            System.out.println("Invalid Input");
            return -1;
        }
        return getSumUtil(0, n - 1, qs, qe, 0);
    }
 
    

    

    int constructSTUtil(int arr[], int ss, int se, int si)
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
	