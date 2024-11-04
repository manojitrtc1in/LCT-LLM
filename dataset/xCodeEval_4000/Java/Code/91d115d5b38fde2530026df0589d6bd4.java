import java.io.*;
import java.lang.*;
import java.text.DecimalFormat;
import java.util.*;

public class Codeforces
{
	static InputReader in = new InputReader(System.in);
	static FastReader fr = new FastReader();
	static OutputWriter out = new OutputWriter(System.out);
	
	static int MOD = 1000000007, prime[];
	static long gcd, x, y;
	static boolean isPrime[];
	static long nCr[][] = new long[1004][1004];
	
	public static void main(String[] args) throws IOException
	{
		int n = in.nextInt();
		int a[] = new int[n];
		for(int i = 0; i < n; i++)
			a[i] = in.nextInt();
		int minSwaps = minSwapsUtil(a, n);
		if(3*n%2==0 && minSwaps%2==0)
            out.printLine("Petr");
	    else if(3*n%2==1 && minSwaps%2==1)
	        out.printLine("Petr");
	    else if((7*n+1)%2==0 && minSwaps%2==0)
	    	out.printLine("Um_nik");
	    else if((7*n+1)%2==1 && minSwaps%2==1)
	    	out.printLine("Um_nik");
		out.flush();
	}
	
	static class Pair
    {
        int v;
        int w;
        
        Pair(int v, int w)
        {
            this.v = v;
            this.w = w;
        }
    }
	
	

	

	static int minSwapsUtil(int arr[], int n)
	{
	    

	    

	    

		Pair arrPos[] = new Pair[n];
	    for (int i = 0; i < n; i++)
	    {
	    	arrPos[i] = new Pair(arr[i], i);
	    }
	 
	    

	    

	    

	    Arrays.sort(arrPos, new CustomComp());
	 
	    

	    

	    boolean vis[] = new boolean[n];
	 
	    

	    int ans = 0;
	 
	    

	    for (int i = 0; i < n; i++)
	    {
	        

	        

	        if (vis[i] || arrPos[i].w == i)
	            continue;
	 
	        

	        

	        int cycle_size = 0;
	        int j = i;
	        while (!vis[j])
	        {
	            vis[j] = true;
	 
	            

	            j = arrPos[j].w;
	            cycle_size++;
	        }
	 
	        

	        ans += (cycle_size - 1);
	    }
	 
	    

	    return ans;
	}
	static long min_3(long a, long b, long c)
	{
		if(a < b && a < c)
			return a;
		if(b < c)
			return b;
		return c;
	}
	
	static long max_3(long x, long y, long z)
	{
		if(x >= y && x >= z)
			return x;
		if(y >= x && y >= z)
			return y;
		return z;
	}
	
	static long power(long x, long y, long m)
	{
	    if (y == 0)
	        return 1;
	    long p = power(x, y/2, m) % m;
	    p = (p * p) % m;
	    return (y%2 == 0) ? p : (x * p) % m;
	}
	
	static void prime_sieve(int N)
	{
        isPrime = new boolean[N+1];
        Arrays.fill(isPrime, true);
        isPrime[0] = isPrime[1] = false;
        for(int i = 2; i*i <= N; i++)
        {
            if(isPrime[i]==true)
            {
            	for(int j = 2*i; j <= N; j += i)
            	{
            		isPrime[j] = false;
            		prime[j] = i;
				}
            }
        }
    }
	
	static void Calc_nCr()
	{
		for(int i = 0; i <= 1000; i++)
			nCr[i][0] = 1;
		for(int i = 1; i <= 1000; i++)
			for(int j = 1; j <= 1000; j++)
				nCr[i][j] = (nCr[i-1][j-1] + nCr[i-1][j]) % MOD;
	}
	
	static long factorial(long num)
	{
		long result = 1;
		for(int i = 1; i <= num; i++)
			result = result * (long)i;
		return result;
	}
	
	static void ExtendedEuclidian(long a, long b)
	{
		if(b == 0)
		{
	        gcd = a;
	        x = 1;
	        y = 0;
	    }
	    else
	    {
	        ExtendedEuclidian(b, a%b);
	        int temp = (int) x;
	        x = y;
	        y = temp - (a/b)*y;
	    }
	}
	
	static long GCD(long n, long m)
	{
		if(m != 0)
			return GCD(m, n % m);
		else
			return n;
	}
	
	static class CustomComp implements Comparator<Pair>
	{
		@Override
        public int compare(Pair p1, Pair p2)
		{
			if(p1.v <= p2.v)
				return -1;
			else
				return 1;
        }
	}
	
	static int[][] graph(int from[], int to[], int n) 

	{
		int g[][] = new int[n][];
		int cnt[] = new int[n];
		for (int i = 0; i < from.length; i++)
		{
			cnt[from[i]]++;
			cnt[to[i]]++;
		}
		for (int i = 0; i < n; i++)
			g[i] = new int[cnt[i]];
		Arrays.fill(cnt, 0);
		for (int i = 0; i < from.length; i++)
		{
			g[from[i]][cnt[from[i]]++] = to[i];
			g[to[i]][cnt[to[i]]++] = from[i];
		}
		return g;
	}
	
	static class Graph
	{
		
	    private int V;
	    long dist[];
	    private LinkedList<Pair> adj1[];
	    private LinkedList<Integer> adj2[];
	    boolean visited[];
	    
	    class Pair
	    {
	        int v;
	        long w;
	        
	        Pair(int v, long w)
	        {
	            this.v = v;
	            this.w = w;
	        }
	    }
	    
	    Graph(int v)
	    {
	    	V = v + 1;
	        adj1 = new LinkedList[V];
	        adj2 = new LinkedList[V];
	        visited = new boolean[V];
	        dist = new long[V];
	        Arrays.fill(dist, Long.MAX_VALUE);
	        dist[1] = 0;
	        for(int i = 0; i < V; i++)
	            adj1[i] = new LinkedList<Pair>();
	        for(int i = 0; i < V; i++)
	            adj2[i] = new LinkedList<Integer>();
	    }
	    
	    public void addEdge1(int u, int v, int w)
	    {
	        adj1[u].add(new Pair(v, w));
	        adj1[v].add(new Pair(u, w));
	    }
	 
	    void addEdge2(int v, int w)
	    {
	        adj2[v].add(w);
	        adj2[w].add(v);
	    }
	    
	    public void dijkstra()
	    {
	        Queue<Pair> pQueue = new PriorityQueue<Pair>(V, new pQueueComp());
	        pQueue.add(new Pair(1, 0));
	        while(!pQueue.isEmpty())
	        {
	            Pair p1 = pQueue.poll();
	            int x = p1.v;
	            long wei = p1.w;
	            if(visited[x])
	                continue;
	            visited[x] = true;
	            Iterator<Pair> itr = adj1[x].listIterator();
	            while(itr.hasNext()) {
	                Pair p2 = itr.next();
	                int e = p2.v;
	                long w = p2.w;
	                if(dist[x] + w < dist[e])
	                {
	                    dist[e] = dist[x] + w;
	                    pQueue.add(new Pair(e, dist[e]));
	                }
	            }
	        }
	    }
	    
	    class pQueueComp implements Comparator<Pair>
	    {
	        @Override
	        public int compare(Pair p1, Pair p2)
	        {
	            return (int)(p1.w - p2.w);
	        }
	    }
	    
	    

	    void BFS(int s)
	    {
	        LinkedList<Integer> queue = new LinkedList<Integer>();
	        visited[s] = true;
	        queue.add(s);
	        while (queue.size() != 0)
	        {
	            s = queue.poll();
	            System.out.print(s+" ");
	            Iterator<Integer> i = adj2[s].listIterator();
	            while (i.hasNext())
	            {
	                int n = i.next();
	                if (!visited[n])
	                {
	                    visited[n] = true;
	                    queue.add(n);
	                }
	            }
	        }
	    }
	    
	    int count = 0;
	    
	    int DFS(int u, int v) {
	    	visited = new boolean[26];
	    	for(int i = 0; i < 26; i++)
	    	{
	    		if(visited[i] == false)
	    		{
	    			count = 0;
	    			DFSUtil(i, u, v);
	    			

	    			if(count == 0 && visited[u] == true && visited[v] == true)
	    				return 1;
	    			if(count == 1 && (visited[u] == true || visited[v] == true))
	    				return 1;
	    			if(count == 2)
	    				break;
	    		}
	    	}
	    	return 0;
	    }
	    
	    void DFSUtil(int s, int u, int v)
	    {
	        visited[s] = true;
	        

	        if(s == u)
	        	count++;
	        if(s == v)
	        	count++;
	        if(count == 2)
	        	return;
	        

	        Iterator<Integer> i = adj2[s].listIterator();
	        while(i.hasNext())
	        {
	            int n = i.next();
	            if(!visited[n])
	                DFSUtil(n, u, v);
	        }
	    }
	    
	    boolean isCyclicUndirectedUtil(int v, boolean visited[], int parent)
	    {
	        

	        visited[v] = true;
	        Integer i;
	 
	        

	        Iterator<Integer> it = adj2[v].iterator();
	        while (it.hasNext())
	        {
	            i = it.next();
	 
	            

	            

	            if (!visited[i])
	            {
	                if (isCyclicUndirectedUtil(i, visited, v))
	                    return true;
	            }
	 
	            

	            

	            else if (i != parent)
	                return true;
	        }
	        return false;
	    }
	 
	    

	    boolean isCyclicUndirected()
	    {
	        

	        

	        boolean visited[] = new boolean[V];
	 
	        

	        

	        for (int u = 1; u <= V; u++)
	            if (!visited[u]) 

	                if (isCyclicUndirectedUtil(u, visited, -1))
	                    return true;
	 
	        return false;
	    }
	    
	    boolean isCyclicDirectedUtil(int v, boolean visited[], boolean recStack[])
	    {
	    	if(visited[v] == false)
	    	{
	            

	            visited[v] = true;
	            recStack[v] = true;
	     
	            

	            Iterator<Integer> i = adj2[v].listIterator();
	            while(i.hasNext())
	            {
	            	int n = i.next();
	                if (!visited[n] && isCyclicDirectedUtil(n, visited, recStack))
	                    return true;
	                else if (recStack[n])
	                    return true;
	            }
	        }
	        recStack[v] = false;  

	        return false;
	    }
	    
	    boolean isCyclicDirected()
	    {
	    	boolean visited[] = new boolean[V];
	    	boolean recStack[] = new boolean[V];
	    	for(int i = 1; i <= V; i++)
	            if (isCyclicDirectedUtil(i, visited, recStack))
	                return true;
	    	return false;
	    }
	    
	    void topologicalSortUtil(int v, boolean visited[], Stack stack)
	    {
			

			visited[v] = true;
			
			

			Iterator<Integer> it = adj2[v].iterator();
			while (it.hasNext()) {
				int i = it.next();
				if (!visited[i])
					topologicalSortUtil(i, visited, stack);
			}
			
			

			stack.push(new Integer(v));
		}
			
		

		void topologicalSort()
		{
			Stack stack = new Stack();
			
			

			boolean visited[] = new boolean[V];
			
			

			

			for (int i = 1; i <= V; i++)
			if (visited[i] == false)
				topologicalSortUtil(i, visited, stack);
			
			

			while (stack.empty()==false)
				System.out.print(stack.pop() + " ");
		}
	}
}

class InputReader
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
            } 
            while (!isSpaceChar(c));
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

    public long[] nextLongArray(int n)
    {
            long a[] = new long[n];
            for (int i = 0; i < n; i++)
            {
                    a[i] = nextLong();
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

class FastReader
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
 
class OutputWriter {
	
	private final PrintWriter writer;
 
	public OutputWriter(OutputStream outputStream)
	{
		writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
	}
 
	public OutputWriter(Writer writer)
	{
		this.writer = new PrintWriter(writer);
	}
 
	public void print(Object...objects)
	{
		for (int i = 0; i < objects.length; i++)
		{
			if (i != 0)
				writer.print(' ');
			writer.print(objects[i]);
		}
	}
 
	public void printLine(Object...objects)
	{
		print(objects);
		writer.println();
	}
 
	public void close()
	{
		writer.close();
	}
 
	public void flush()
	{
		writer.flush();
	}
}