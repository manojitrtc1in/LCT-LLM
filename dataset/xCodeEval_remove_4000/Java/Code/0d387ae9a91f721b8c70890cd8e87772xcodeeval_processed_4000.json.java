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
		int n = in.nextInt(), k = in.nextInt();
		long l = in.nextLong();
		Long stave[] = new Long[n*k];
		for(int i = 0; i < n*k; i++) {
			stave[i] = in.nextLong();
		}
		Arrays.sort(stave);
		if(Math.abs(stave[0] - stave[n-1]) > l) {
			out.printLine(0);
		}
		else {
			int index = n-1;
			for(int i = n; i < n*k; i++) {
				if(stave[i] - stave[0] <= l)
					index++;
				else
					break;
			}
			

			long barrel[][] = new long[n][k];
			int id7 = 0;
			int temp_n = n;
			int flag = 0;
			long max_vol = 0;
			for(int i = 0; i < temp_n; i++) {
				n--;
				

				for(int j = 0; j < k; j++) {
					if(index - id7 >= n) {
						barrel[i][j] = stave[id7++];
						if(j == 0) {
							max_vol += barrel[i][j];
						}
					}
					else {
						flag = 1;
						break;
					}
					

				}
				

				

			}
			if(flag == 1) {
				for(int i = id7; i <= index; i++) {
					max_vol += stave[i];
				}
			}
			out.printLine(max_vol);
		}
		out.flush();
	}
	
	static long id4(long a, long b, long c)
	{
		if(a < b && a < c)
			return a;
		if(b < c)
			return b;
		return c;
	}
	
	static long id11(long x, long y, long z)
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
	
	static void id2(int N)
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
	
	static void id14()
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
	
	static void id19(long a, long b)
	{
		if(b == 0)
		{
	        gcd = a;
	        x = 1;
	        y = 0;
	    }
	    else
	    {
	        id19(b, a%b);
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
	
	static class CustomComp implements Comparator<Object>
	{
		@Override
        public int compare(Object o1, Object o2)
		{
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
	    
	    public void id1(int u, int v, int w)
	    {
	        adj1[u].add(new Pair(v, w));
	        adj1[v].add(new Pair(u, w));
	    }
	 
	    void id6(int v, int w)
	    {
	        adj2[v].add(w);
	        adj2[w].add(v);
	    }
	    
	    public void dijkstra()
	    {
	        Queue<Pair> pQueue = new PriorityQueue<Pair>(V, new id12());
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
	    
	    class id12 implements Comparator<Pair>
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
	    	for(int i = 0; i < 26; i++) {
	    		if(visited[i] == false) {
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
	    
	    boolean id15(int v, boolean visited[], int parent)
	    {
	        

	        visited[v] = true;
	        Integer i;
	 
	        

	        Iterator<Integer> it = adj2[v].iterator();
	        while (it.hasNext())
	        {
	            i = it.next();
	 
	            

	            

	            if (!visited[i])
	            {
	                if (id15(i, visited, v))
	                    return true;
	            }
	 
	            

	            

	            else if (i != parent)
	                return true;
	        }
	        return false;
	    }
	 
	    

	    boolean id5()
	    {
	        

	        

	        boolean visited[] = new boolean[V];
	 
	        

	        

	        for (int u = 1; u <= V; u++)
	            if (!visited[u]) 

	                if (id15(u, visited, -1))
	                    return true;
	 
	        return false;
	    }
	    
	    boolean id18(int v, boolean visited[], boolean recStack[])
	    {
	    	if(visited[v] == false)
	    	{
	            

	            visited[v] = true;
	            recStack[v] = true;
	     
	            

	            Iterator<Integer> i = adj2[v].listIterator();
	            while(i.hasNext())
	            {
	            	int n = i.next();
	                if (!visited[n] && id18(n, visited, recStack))
	                    return true;
	                else if (recStack[n])
	                    return true;
	            }
	        }
	        recStack[v] = false;  

	        return false;
	    }
	    
	    boolean id0()
	    {
	    	boolean visited[] = new boolean[V];
	    	boolean recStack[] = new boolean[V];
	    	for(int i = 1; i <= V; i++)
	            if (id18(i, visited, recStack))
	                return true;
	    	return false;
	    }
	    
	    void id16(int v, boolean visited[], Stack stack)
	    {
			

			visited[v] = true;
			
			

			Iterator<Integer> it = adj2[v].iterator();
			while (it.hasNext()) {
				int i = it.next();
				if (!visited[i])
					id16(i, visited, stack);
			}
			
			

			stack.push(new Integer(v));
		}
			
		

		void id10()
		{
			Stack stack = new Stack();
			
			

			boolean visited[] = new boolean[V];
			
			

			

			for (int i = 1; i <= V; i++)
			if (visited[i] == false)
				id16(i, visited, stack);
			
			

			while (stack.empty()==false)
				System.out.print(stack.pop() + " ");
		}
	}
}

class InputReader
{

    private final InputStream stream;
    private final byte[] buf = new byte[8192];
    private int curChar, id8;
    private id17 filter;

    public InputReader(InputStream stream)
    {
            this.stream = stream;
    }

    public int snext()
    {
            if (id8 == -1)
                    throw new InputMismatchException();
            if (curChar >= id8)
            {
                    curChar = 0;
                    try
                    {
                            id8 = stream.read(buf);
                    } catch (IOException e)
                    {
                            throw new InputMismatchException();
                    }
                    if (id8 <= 0)
                            return -1;
            }
            return buf[curChar++];
    }

    public int nextInt()
    {
            int c = snext();
            while (id3(c))
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
            } while (!id3(c));
            return res * sgn;
    }

    public long nextLong()
    {
            int c = snext();
            while (id3(c))
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
            } while (!id3(c));
            return res * sgn;
    }

    public int[] id9(int n)
    {
            int a[] = new int[n];
            for (int i = 0; i < n; i++)
            {
                    a[i] = nextInt();
            }
            return a;
    }

    public long[] id20(int n)
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
            while (id3(c))
            {
                    c = snext();
            }
            StringBuilder res = new StringBuilder();
            do
            {
                    res.appendCodePoint(c);
                    c = snext();
            } while (!id3(c));
            return res.toString();
    }

    public String nextLine()
    {
            int c = snext();
            while (id3(c))
                    c = snext();
            StringBuilder res = new StringBuilder();
            do
            {
                    res.appendCodePoint(c);
                    c = snext();
            } while (!id13(c));
            return res.toString();
    }

    public boolean id3(int c)
    {
            if (filter != null)
                    return filter.id3(c);
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }

    private boolean id13(int c)
    {
            return c == '\n' || c == '\r' || c == -1;
    }

    public interface id17
    {
            public boolean id3(int ch);
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