import java.io.*;
import java.lang.*;
import java.util.*;

public class Codeforces
{
	
	static InputReader in = new InputReader(System.in);
	static FastReader fr = new FastReader();
	static OutputWriter out = new OutputWriter(System.out);
	
	static int MOD = 1000000007, smallestPrimeDiv[];
	static long gcd, x, y;
	static boolean isPrime[];
	static long nCr[][] = new long[1004][1004];
	
	public static void main(String[] args) throws IOException
	{






















		int n = in.nextInt();
		Integer a[] = new Integer[n], b[] = new Integer[n];
		for(int i = 0; i < n; i++) {
			a[i] = in.nextInt();
		}
		for(int i = 0; i < n; i++) {
			b[i] = in.nextInt();
		}
		Arrays.sort(a);
		Arrays.sort(b);
		int ai = n-1, bi = n-1;
		long scoreA = 0, scoreB = 0;
		for(int i = 0; i < n; i++) {
			if(bi == -1) {
				scoreA += a[ai--];
			}
			else if(ai == -1) {
				bi--;
			}
			else if(a[ai] > b[bi]) {
				scoreA += a[ai--];
			}
			else {
				bi--;
			}
			if(ai == -1) {
				scoreB += b[bi--];
			}
			else if(bi == -1) {
				ai--;
			}
			else if(a[ai] < b[bi]) {
				scoreB += b[bi--];
			}
			else {
				ai--;
			}
		}
		out.printLine(scoreA - scoreB);
		out.flush();
		out.close();
	}
	
	class Pair {
		int prev, prev_i;
		int curr, curr_i;
		int next, next_i;
		
		Pair(int p, int p_i, int c, int c_i, int n, int n_i) {
			this.prev = p;
			this.prev_i = p_i;
			this.curr = c;
			this.curr_i = c_i;
			this.next = n;
			this.next_i = n_i;
		}
	}
	












	
	static boolean BinarySearch(long a[], int n, long x)
	{
		int l = 0, h = n-1, mid;
		while(l <= h) {
			mid = l + ((h-l)/2);
			if(a[mid] == x)
				return true;
			else if(a[mid] < x)
				l = mid + 1;
			else
				h = mid - 1;
		}
		return false;
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
		long res = 1;
		x = x % m;
		while(y > 0) {
			if((y & 1) == 1)
				res = (res * x) % m;
			x = (x * x) % m;
			y >>= 1;
		}
		return res;
	}
	
	static void prime_sieve(int N)
	{
        isPrime = new boolean[N+1];
        smallestPrimeDiv = new int[N+1];
        Arrays.fill(isPrime, true);
        for(int i = 1; i <= N; i++)
        	smallestPrimeDiv[i] = i;
        isPrime[0] = isPrime[1] = false;
        for(int i = 2; i*i <= N; i++) {
            if(isPrime[i]==true) {
            	for(int j = i*i; j <= N; j += i) {
            		isPrime[j] = false;
            		if(smallestPrimeDiv[j] > i)
            			smallestPrimeDiv[j] = i;
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
	
	long modInverse(long A, long M)
	{ 

	    return power(A, M-2, M);
	}
	
	static void ExtendedEuclidian(long a, long b)
	{
		if(b == 0) {
	        gcd = a;
	        x = 1;
	        y = 0;
	    }
	    else {
	        ExtendedEuclidian(b, a%b);
	        long temp = x;
	        x = y;
	        y = temp - (a/b)*y;
	    }
	}
	
	static long GCD(long n, long m)
	{
		if(m == 0)
			return n;
		return GCD(m, n % m);
	}
	
	class subset
	{
        int parent, rank;
    };
	
	int find(subset subsets[], int i)
	{
        if (subsets[i].parent != i)
            subsets[i].parent = find(subsets, subsets[i].parent);
        return subsets[i].parent;
    }
	
	void Union(subset subsets[], int x, int y)
	{
        int xroot = find(subsets, x), yroot = find(subsets, y);
        if (subsets[xroot].rank < subsets[yroot].rank)
            subsets[xroot].parent = yroot;
        else if (subsets[xroot].rank > subsets[yroot].rank)
            subsets[yroot].parent = xroot;
        else {
            subsets[yroot].parent = xroot;
            subsets[xroot].rank++;
        }
    }
	
	static int[][] graph(int from[], int to[], int n)
	{ 

		int g[][] = new int[n][];
		int cnt[] = new int[n];
		for (int i = 0; i < from.length; i++) {
			cnt[from[i]]++;
			cnt[to[i]]++;
		}
		for (int i = 0; i < n; i++)
			g[i] = new int[cnt[i]];
		Arrays.fill(cnt, 0);
		for (int i = 0; i < from.length; i++) {
			g[from[i]][cnt[from[i]]++] = to[i];
			g[to[i]][cnt[to[i]]++] = from[i];
		}
		return g;
	}
	
	static class Graph
	{
		
	    private int V, E;
	    Edge edge[];
	    long dist[];
	    private LinkedList<Pair> adj1[];
	    private LinkedList<Integer> adj2[];
	    boolean visited[];
	    
	    class Pair {
	        int v;
	        long w;
	        
	        Pair(int v, long w) {
	            this.v = v;
	            this.w = w;
	        }
	    }
	    
	    class Edge implements Comparable<Edge> {
	        int src, dest, weight;
	        
	        public int compareTo(Edge compareEdge) {
	            return this.weight-compareEdge.weight;
	        }
	    };
	    
	    Graph(int v, int e) {
	        V = v;
	        E = e;
	        edge = new Edge[E];
	        for(int i = 0; i < e; ++i)
	            edge[i] = new Edge();
	    }
	    
	    Graph(int v) {
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
	    
	    public void addEdge1(int u, int v, int w) {
	        adj1[u].add(new Pair(v, w));
	        adj1[v].add(new Pair(u, w));
	    }
	 
	    void addEdge2(int v, int w) {
	        adj2[v].add(w);
	        adj2[w].add(v);
	    }
	    
	    public void dijkstra() { 

	        Queue<Pair> pQueue = new PriorityQueue<Pair>(V, new pQueueComp());
	        pQueue.add(new Pair(1, 0));
	        while(!pQueue.isEmpty()) {
	            Pair p1 = pQueue.poll();
	            int src = p1.v;
	            if(visited[src])
	                continue;
	            visited[src] = true;
	            Iterator<Pair> itr = adj1[src].listIterator();
	            while(itr.hasNext()) {
	                Pair p2 = itr.next();
	                int dest = p2.v;
	                long weight = p2.w;
	                if(dist[src] + weight < dist[dest]) {
	                    dist[dest] = dist[src] + weight;
	                    pQueue.add(new Pair(dest, dist[dest]));
	                }
	            }
	        }
	    }
	    
	    class pQueueComp implements Comparator<Pair> {
	        public int compare(Pair p1, Pair p2) {
	            return (int)(p1.w - p2.w);
	        }
	    }
	    
	    void BFS(int s) {
	        LinkedList<Integer> queue = new LinkedList<Integer>();
	        visited[s] = true;
	        queue.add(s);
	        while(queue.size() != 0) {
	            s = queue.poll();
	            System.out.print(s+" ");
	            Iterator<Integer> i = adj2[s].listIterator();
	            while(i.hasNext()) {
	                int n = i.next();
	                if(!visited[n]) {
	                    visited[n] = true;
	                    queue.add(n);
	                }
	            }
	        }
	    }
	    
	    void DFS(int v) {
	        visited[v] = true;
	        System.out.print(v+" ");
	        Iterator<Integer> i = adj2[v].listIterator();
	        while(i.hasNext()) {
	            int n = i.next();
	            if(!visited[n])
	                DFS(n);
	        }
	    }
	    
	    boolean isCyclicUndirectedUtil(int v, int parent) {
	        visited[v] = true;
	        Iterator<Integer> it = adj2[v].iterator();
	        while(it.hasNext()) {
	            int i = it.next();
	            if(!visited[i]) {
	                if(isCyclicUndirectedUtil(i, v))
	                    return true;
	            }
	            else if(i != parent)
	                return true;
	        }
	        return false;
	    }
	    
	    boolean isCyclicUndirected() {
	        for(int u = 1; u <= V; u++)
	            if(!visited[u])
	                if(isCyclicUndirectedUtil(u, -1))
	                    return true;
	        return false;
	    }
	    
	    boolean isCyclicDirectedUtil(int v, boolean recStack[]) {
	    	if(visited[v] == false) {
	            visited[v] = true;
	            recStack[v] = true;
	            Iterator<Integer> i = adj2[v].listIterator();
	            while(i.hasNext()) {
	            	int n = i.next();
	                if(!visited[n] && isCyclicDirectedUtil(n, recStack))
	                    return true;
	                else if(recStack[n])
	                    return true;
	            }
	        }
	        recStack[v] = false;
	        return false;
	    }
	    
	    boolean isCyclicDirected() {
	    	boolean recStack[] = new boolean[V];
	    	for(int i = 1; i <= V; i++)
	    		if(!visited[i])
	    			if(isCyclicDirectedUtil(i, recStack))
	    				return true;
	    	return false;
	    }
	    
	    void topologicalSortUtil(int v, Stack<Integer> stack) {
			visited[v] = true;
			Iterator<Integer> it = adj2[v].iterator();
			while(it.hasNext()) {
				int i = it.next();
				if(!visited[i])
					topologicalSortUtil(i, stack);
			}
			stack.push(v);
		}
	    
		void topologicalSort() {
			Stack<Integer> stack = new Stack<Integer>();
			for (int i = 1; i <= V; i++)
				if(visited[i] == false)
					topologicalSortUtil(i, stack);
			while(!stack.empty())
				System.out.print(stack.pop() + " ");
		}
	}
	
	static class KMP_String_Matching
	{
		
	    void KMPSearch(String pat, String txt) {
	        int M = pat.length(), N = txt.length();
	 
	        

	        int lps[] = new int[M];
	        int j = 0; 

	 
	        

	        computeLPSArray(pat, M, lps);
	 
	        int i = 0; 

	        while (i < N) {
	            if (pat.charAt(j) == txt.charAt(i)) {
	                j++;
	                i++;
	            }
	            if (j == M) {
	                System.out.println("Found pattern " + "at index "  + (i-j));
	                j = lps[j-1];
	            }
	            else if (i < N && pat.charAt(j) != txt.charAt(i)) { 

	                

	                if (j != 0)
	                    j = lps[j-1];
	                else
	                    i = i+1;
	            }
	        }
	    }
	 
	    void computeLPSArray(String pat, int M, int lps[]) {
	        

	        int len = 0, i = 1;
	        lps[0] = 0; 

	 
	        

	        while (i < M) {
	            if (pat.charAt(i) == pat.charAt(len)) {
	                len++;
	                lps[i] = len;
	                i++;
	            }
	            else { 

	                if (len != 0)
	                    len = lps[len-1];
	                else {
	                    lps[i] = len;
	                    i++;
	                }
	            }
	        }
	    }
	}

	static class Trie
	{
		
	    static final int ALPHABET_SIZE = 26;
	    
	    static class TrieNode {
	    	
	        TrieNode[] children = new TrieNode[ALPHABET_SIZE];
	        boolean isEndOfWord;
	         
	        TrieNode() {
	            isEndOfWord = false;
	            for(int i = 0; i < ALPHABET_SIZE; i++)
	                children[i] = null;
	        }
	    };
	      
	    static TrieNode root; 
	    
	    static void insert(String key) {
	        int level, length = key.length(), index;
	        TrieNode pCrawl = root;
	        for(level = 0; level < length; level++) {
	            index = key.charAt(level) - 'a';
	            if (pCrawl.children[index] == null)
	                pCrawl.children[index] = new TrieNode();
	            pCrawl = pCrawl.children[index];
	        }
	        pCrawl.isEndOfWord = true;
	    }
	    
	    static boolean search(String key) {
	        int level, length = key.length(), index;
	        TrieNode pCrawl = root;
	        for (level = 0; level < length; level++) {
	            index = key.charAt(level) - 'a';
	            if (pCrawl.children[index] == null)
	                return false;
	            pCrawl = pCrawl.children[index];
	        }
	        return (pCrawl != null && pCrawl.isEndOfWord);
	    }
	}
	
	static class SegmentTree
	{

		int st[];
		
		void constructST(int arr[], int n) {
			int x = (int) (Math.ceil(Math.log(n) / Math.log(2)));
			int max_size = 2 * (int) Math.pow(2, x) - 1;
			st = new int[max_size];
			constructSTUtil(arr, 0, n - 1, 0);
		}
		
		int constructSTUtil(int arr[], int ss, int se, int si) {
			if (ss == se) {
				st[si] = arr[ss];
				return arr[ss];
			}
			int mid = getMid(ss, se);
			st[si] = constructSTUtil(arr, ss, mid, si * 2 + 1) + constructSTUtil(arr, mid + 1, se, si * 2 + 2);
			return st[si];
		}

		int getMid(int s, int e) {
			return s + (e - s) / 2;
		}
		
		int getSum(int n, int qs, int qe) {
			if (qs < 0 || qe > n - 1 || qs > qe) {
				System.out.println("Invalid Input");
				return -1;
			}
			return getSumUtil(0, n - 1, qs, qe, 0);
		}

		int getSumUtil(int ss, int se, int qs, int qe, int index) {
			if (qs <= ss && qe >= se)
				return st[index];
			if (se < qs || ss > qe)
				return 0;
			int mid = getMid(ss, se);
			return getSumUtil(ss, mid, qs, qe, 2 * index + 1) + getSumUtil(mid + 1, se, qs, qe, 2 * index + 2);
		}
		
		void updateValue(int arr[], int n, int i, int new_val) {
	        if (i < 0 || i > n - 1) {
	            System.out.println("Invalid Input");
	            return;
	        }
	        int diff = new_val - arr[i];
	        arr[i] = new_val;
	        updateValueUtil(0, n - 1, i, diff, 0);
	    }
		
	    void updateValueUtil(int ss, int se, int i, int diff, int si) {
	        if (i < ss || i > se)
	            return;
	        st[si] += diff;
	        if (se != ss) {
	            int mid = getMid(ss, se);
	            updateValueUtil(ss, mid, i, diff, 2 * si + 1);
	            updateValueUtil(mid + 1, se, i, diff, 2 * si + 2);
	        }
	    }
	}
	
	static class BinaryIndexedTree
	{ 


		private int n, BITree[];
		
		BinaryIndexedTree(int s) {
			n = s+1;
			BITree = new int[s+1];
		}

		int getSum(int index) {
			int sum = 0; 

		
			

			index = index + 1;
		
			

			while(index > 0) {
				

				sum += BITree[index];
		
				

				index -= index & (-index);
			}
			return sum;
		}

		public void updateBIT(int index, int val) {
			

			index = index + 1;
		
			

			while(index <= n) {
				
				

				BITree[index] += val;
			
				

				index += index & (-index);
			}
		}
		
		void constructBITree(int arr[]) {
			

			for(int i = 1; i <= n; i++)
				BITree[i] = 0;
		
			

			for(int i = 0; i < n; i++)
				updateBIT(i, arr[i]);
		}
	}
}

class InputReader
{

    private final InputStream stream;
    private final byte[] buf = new byte[8192];
    private int curChar, snumChars;
    private SpaceCharFilter filter;

    public InputReader(InputStream stream) {
    	this.stream = stream;
    }

    public int snext() {
    	if(snumChars == -1)
    		throw new InputMismatchException();
        if(curChar >= snumChars) {
        	curChar = 0;
        	try {
        		snumChars = stream.read(buf);
        	}
        	catch (IOException e) {
        		throw new InputMismatchException();
        	}
        	if (snumChars <= 0)
        		return -1;
        }
        return buf[curChar++];
    }

    public int nextInt() {
    	int c = snext();
    	while (isSpaceChar(c))
    		c = snext();
    	int sgn = 1;
    	if (c == '-') {
    		sgn = -1;
    		c = snext();
    	}
    	int res = 0;
    	do {
    		if (c < '0' || c > '9')
    			throw new InputMismatchException();
            res *= 10;
            res += c - '0';
            c = snext();
        } while(!isSpaceChar(c));
        return res * sgn;
    }

    public long nextLong() {
    	int c = snext();
        while (isSpaceChar(c))
        	c = snext();
        int sgn = 1;
        if (c == '-') {
        	sgn = -1;
        	c = snext();
        }
        long res = 0;
        do {
        	if (c < '0' || c > '9')
        		throw new InputMismatchException();
        	res *= 10;
        	res += c - '0';
        	c = snext();
        } while(!isSpaceChar(c));
        return res * sgn;
    }

    public int[] nextIntArray(int n) {
    	int a[] = new int[n];
    	for (int i = 0; i < n; i++)
    		a[i] = nextInt();
    	return a;
    }

    public long[] nextLongArray(int n) {
    	long a[] = new long[n];
    	for (int i = 0; i < n; i++)
    		a[i] = nextLong();
    	return a;
    }

    public String readString() {
    	int c = snext();
    	while(isSpaceChar(c))
    		c = snext();
    	StringBuilder res = new StringBuilder();
    	do {
    		res.appendCodePoint(c);
    		c = snext();
    	} while(!isSpaceChar(c));
    	return res.toString();
    }

    public String nextLine() {
    	int c = snext();
    	while (isSpaceChar(c))
    		c = snext();
    	StringBuilder res = new StringBuilder();
    	do {
    		res.appendCodePoint(c);
    		c = snext();
    	} while(!isEndOfLine(c));
    	return res.toString();
    }

    public boolean isSpaceChar(int c) {
    	if(filter != null)
    		return filter.isSpaceChar(c);
    	return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }

    private boolean isEndOfLine(int c) {
    	return c == '\n' || c == '\r' || c == -1;
    }

    public interface SpaceCharFilter {
    	public boolean isSpaceChar(int ch);
    }
}

class FastReader
{
	
    BufferedReader br;
    StringTokenizer st;
 
    public FastReader() {
        br = new BufferedReader(new InputStreamReader(System.in));
    }
 
    String next() {
        while (st == null || !st.hasMoreElements()) {
        	try {
                st = new StringTokenizer(br.readLine());
            }
            catch (IOException  e) {
                e.printStackTrace();
            }
        }
        return st.nextToken();
    }
 
    int nextInt() {
        return Integer.parseInt(next());
    }
 
    long nextLong() {
        return Long.parseLong(next());
    }
 
    double nextDouble() {
        return Double.parseDouble(next());
    }
 
    String nextLine() {
        String str = "";
        try {
            str = br.readLine();
        }
        catch (IOException e) {
            e.printStackTrace();
        }
        return str;
    }
}
 
class OutputWriter
{
	
	private final PrintWriter writer;
 
	public OutputWriter(OutputStream outputStream) {
		writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
	}
 
	public OutputWriter(Writer writer) {
		this.writer = new PrintWriter(writer);
	}
 
	public void print(Object...objects) {
		for (int i = 0; i < objects.length; i++) {
			if (i != 0)
				writer.print(' ');
			writer.print(objects[i]);
		}
	}
 
	public void printLine(Object...objects) {
		print(objects);
		writer.println();
	}
 
	public void close() {
		writer.close();
	}
 
	public void flush() {
		writer.flush();
	}
}