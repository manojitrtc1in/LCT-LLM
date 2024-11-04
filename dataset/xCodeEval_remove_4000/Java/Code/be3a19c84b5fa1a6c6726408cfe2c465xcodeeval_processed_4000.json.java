import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		PrintWriter out = new PrintWriter(outputStream);
		InputReader in = new InputReader(inputStream);
		












			Task t = new Task();
			t.solve(in, out);
			out.close();			


	}	
	
	static class Task {
		int times = 0;
		public void solve(InputReader in, PrintWriter out) throws IOException {




































































































































			

			

			
			

			

			

			

			

			int c = in.nextInt();
			while(c-->0) {
				int n = in.nextInt();
				int arr[] = new int[n];
				TreeSet<Integer> ts = new TreeSet<Integer>();
				for(int i=0;i<n;i++) {
					arr[i] = in.nextInt();
					ts.add(arr[i]);
				}
				ArrayUtils.sort(arr);
				int cnt = 0;
				for(int i:arr) {
					if(!ts.contains(i)) continue;
					cnt++;
					int p = i;
					while(true) {
						Integer x = ts.ceiling(p);
						if(x!=null) {
							ts.remove(x);
							p = x+2;
						}else {
							break;
						}
					}
				}
				out.println(cnt);
			}
			
		}

	    
		class pair implements Comparable<pair>{
			int st; int end; int cost;
			public pair(int a, int b, int c) {
				st = a;
				end = b;
				cost = c;
			}
			public int compareTo(pair x) {
				return x.end-this.end;
			}
		}		
		
	    public int maxLength(List<String> arr) {
	    	int n = arr.size();
	    	int w[] = new int[n];
	        int[][] a = new int[n][26];
	        for(int i=0;i<n;i++) {
	        	String tmp = arr.get(i);
	        	w[i] = tmp.length();
	        	for(int j=0;j<tmp.length();j++) {
	        		a[i][tmp.charAt(j)-'a']++;
	        		if(a[i][tmp.charAt(j)-'a']>1) w[i]=0;
	        	}
	        }
	        boolean g[][] = new boolean[n][n];	       
	        for(int i=0;i<n;i++) {
	        	for(int j=i+1;j<n;j++) {
	        		boolean flag = false;
	        		for(int k=0;k<26;k++) {
	        			if(a[i][k]!=0&&a[j][k]!=0) flag = true; 
	        		}
	        		if(!flag) g[i][j] = g[j][i] = true;
	        	}
	        }
	        int max = 0;
	        for(int i=0;i<(1<<n);i++) {
	        	boolean flag = true;
	        	for(int j=0;j<n;j++) {if((i&(1<<j))==0) continue;
	        		if((i&(1<<j))==0||!flag) continue;
	        		for(int k=j+1;k<n;k++) {
	        			if((i&(1<<k))==0||!flag) continue;
	        			if(!g[j][k]) flag = false;
	        		}
	        	}
	        	if(!flag) continue;
	        	

	        	int s = 0;
	        	for(int j=0;j<n;j++) if((i&(1<<j))==(1<<j)) s+=w[j];
	        	if(s>max) max = s;
	        }
	        return max;
	    }

		
		int dfs(int cur, ArrayList<Integer>[] g, boolean vis[], int low[], int[] lvl, int hash[]) {
			lvl[cur] = low[cur] = times;
			hash[times] = cur;
			times++;
			int reach = low[cur];
			vis[cur] = true;
			for(int to:g[cur]) {
				if(vis[to]) {
					reach = Math.min(reach, low[to]);
				}else {
					int tmp = dfs(to,g,vis,low,lvl,hash);
					reach = Math.min(reach, tmp);
				}
			}
			if(reach<low[cur]) low[cur] = reach;
			return low[cur];
		}
		class edge implements Comparable<edge>{
			int f,t,l,s;
			public edge(int a, int b, int c) {
				if(a<b){
					f=a;t=b;
				}else {
					f=b;t=a;
				}
				l=c;
			}
			@Override
			public int compareTo(edge t) {
				return this.l-t.l;
			}			
		}


			    	
		List<List<Integer>> convert(int arr[][]){
			int n = arr.length;
			List<List<Integer>> ret = new ArrayList<>();
			for(int i=0;i<n;i++) {
				ArrayList<Integer> tmp = new ArrayList<Integer>();
				for(int j=0;j<arr[i].length;j++) tmp.add(arr[i][j]);
				ret.add(tmp);
			}
			return ret;
		}
		
	    public int maximumSum(int[] arr) {
	        int n = arr.length;
	        int dp[][] = new int[n][2];
	        dp[0][0] = arr[0];
	        int ret = arr[0];
	        for(int i=1;i<n;i++) {
	        	dp[i][0] = dp[i-1][0]>=0?(dp[i-1][0]+arr[i]):arr[i];
	        	int t1 = dp[i-1][0];
	        	int t2 = (dp[i-1][1]<0?0:dp[i-1][1])+arr[i];
	        	dp[i][1] = Math.max(t1,t2);
	        	ret = Math.max(ret,Math.max(dp[i][0], dp[i][1]));
	        } 
	        return ret;
	    }		
	    public List<Integer> id7(String[] words, String[] puzzles) {
	        List<Integer> ret = new ArrayList<Integer>();
	        HashMap<Integer,Integer>[] mp = new HashMap[26];
	        for(int i=0;i<26;i++) mp[i] = new HashMap<Integer,Integer>();
	        

	        

	        for(int i=0;i<words.length;i++) {
	        	int v = enc(words[i]);
	        	for(int j=0;j<words[i].length();j++) {
	        		mp[words[i].charAt(j)-'a'].put(v, 1);
	        	}
	        }
	        for(int i=0;i<puzzles.length;i++) {
	        	int n = puzzles[i].length();
	        	int t = 0;
	        	for(int j=1;j<1<<(n-1);j++) {
	        		int v = 0;
	        		for(int k=0;k<6;k++) {
	        			if((j&(1<<k))!=0) {
	        				v|=(1<<(puzzles[i].charAt(k)-'a'));
	        			}
	        		}
	        		v|=(1<<(puzzles[i].charAt(0)-'a'));   		
	        		

	        	}
	        	ret.add(t);
	        }
	        return ret;
	    }	
	    int search(int x, HashMap<Integer,Integer> mp, HashSet<Integer> hs) {
	    	if(mp.containsKey(x)) return mp.get(x);
	    	if(x==0) return 0;
	    	int v = 0;
	    	for(int i=0;i<7;i++) {
	    		if((x&(1<<i))!=0) {
	    			int t = x;
	    			t^=(1<<i);
	    			if(!hs.contains(t)) {
	    				hs.add(t);
	    				v+=search(t,mp,hs);	    				
	    			}
	    		}
	    	}
	    	mp.put(x, v);	    	
	    	return v;
	    }
	    int enc(String x) {
	    	char[] arr = x.toCharArray();
	    	int v = 0;
	    	for(int i=0;i<arr.length;i++) {
	    		v|=1<<(arr[i]-'a');
	    	}
	    	return v;
	    }
		
		public class TreeNode {
			int val;
			TreeNode left;
			TreeNode right;
			TreeNode(int x) { val = x; }
		}
	
		public int GCD(int a, int b) {
		   if (b==0) return a;
		   return GCD(b,a%b);
		}
		public long GCD(long a, long b) {
			   if (b==0) return a;
			   return GCD(b,a%b);
			}		
	}
	
	
    static class ArrayUtils {
        static final long seed = System.nanoTime();
        static final Random rand = new Random(seed);

        public static void sort(int[] a) {
            shuffle(a);
            Arrays.sort(a);
        }

        public static void shuffle(int[] a) {
            for (int i = 0; i < a.length; i++) {
                int j = rand.nextInt(i + 1);
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }

    }	
	static class BIT{
		int arr[];
		int n;
		public BIT(int a) {
			n=a;
			arr = new int[n];
		}
		int sum(int p) {
			int s=0;
			while(p>0) {
				s+=arr[p];
				p-=p&(-p);
			}
			return s;
		}
		void add(int p, int v) {
			while(p<n) {
				arr[p]+=v;
				p+=p&(-p);
			}
		}
	}
	static class DSU{
		int[] arr;
		int[] sz;
		public DSU(int n) {
			arr = new int[n];
			sz = new int[n];
			for(int i=0;i<n;i++) arr[i] = i;
			Arrays.fill(sz, 1);
		}
		public int find(int a) {
			if(arr[a]!=a) arr[a] = find(arr[a]);
			return arr[a];
		}
		public void union(int a, int b) {
			int x = find(a);
			int y = find(b);
			if(x==y) return;
			arr[y] = x;
			sz[x] += sz[y];
		}
		public int size(int x) {
			return sz[find(x)];
		}
	}	
	static class MinHeap<Key> implements Iterable<Key> {
		private int maxN;
		private int n;
		private int[] pq;
		private int[] qp;
		private Key[] keys;
		private Comparator<Key> comparator;
		
		public MinHeap(int capacity){
			if (capacity < 0) throw new IllegalArgumentException();
			this.maxN = capacity;
			n=0;
			pq = new int[maxN+1];
			qp = new int[maxN+1];
			keys = (Key[]) new Object[capacity+1];
			Arrays.fill(qp, -1);
		}
		
		public MinHeap(int capacity, Comparator<Key> c){
			if (capacity < 0) throw new IllegalArgumentException();
			this.maxN = capacity;
			n=0;
			pq = new int[maxN+1];
			qp = new int[maxN+1];
			keys = (Key[]) new Object[capacity+1];
			Arrays.fill(qp, -1);
			comparator = c;
		}			
		public boolean isEmpty()	{ return n==0; 	}
		public int size()			{ return n;		}
		public boolean contains(int i) {
	        if (i < 0 || i >= maxN) throw new IllegalArgumentException();
	        return qp[i] != -1;
		}	
		public int peekIdx() {
	        if (n == 0) throw new NoSuchElementException("Priority queue underflow");
	        return pq[1];		
		}	
		public Key peek(){
			if(isEmpty()) throw new NoSuchElementException("Priority queue underflow");
			return keys[pq[1]];
		}
		public int poll(){
			if(isEmpty()) throw new NoSuchElementException("Priority queue underflow");
			int min = pq[1];
			exch(1,n--);
			down(1);
			assert min==pq[n+1];
			qp[min] = -1;
			keys[min] = null;		
			pq[n+1] = -1;
			return min;
		}
	    public void update(int i, Key key) {
	        if (i < 0 || i >= maxN) throw new IllegalArgumentException();
	        if (!contains(i)) {
	        	this.add(i, key);
	        }else {
	        	keys[i] = key;
	        	up(qp[i]);
	        	down(qp[i]);
	        }
	    }	
		private void add(int i, Key x){
	        if (i < 0 || i >= maxN) throw new IllegalArgumentException();
	        if (contains(i)) throw new IllegalArgumentException("index is already in the priority queue");
	        n++;
	        qp[i] = n;
	        pq[n] = i;
	        keys[i] = x;
	        up(n);
		}
		private void up(int k){
			while(k>1&&less(k,k/2)){
				exch(k,k/2);
				k/=2;
			}
		}
		private void down(int k){
			while(2*k<=n){
				int j=2*k;
				if(j<n&&less(j+1,j)) j++;
				if(less(k,j)) break;
				exch(k,j);
				k=j;
			}
		}
		
		public boolean less(int i, int j){
	        if (comparator == null) {
	            return ((Comparable<Key>) keys[pq[i]]).compareTo(keys[pq[j]]) < 0;
	        }
	        else {
	            return comparator.compare(keys[pq[i]], keys[pq[j]]) < 0;
	        }
		}

		public void exch(int i, int j){
	        int swap = pq[i];
	        pq[i] = pq[j];
	        pq[j] = swap;
	        qp[pq[i]] = i;
	        qp[pq[j]] = j;
		}

		@Override
		public Iterator<Key> iterator() {
			

			return null;
		}
	}  	

    private static class InputReader
    {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int id6;
        private int id1;
        private id8 filter;

        public InputReader(InputStream stream)
        {
            this.stream = stream;
        }

        public int read()
        {
            if (id1 == -1)
                throw new InputMismatchException();
            if (id6 >= id1)
            {
            	id6 = 0;
                try
                {
                    id1 = stream.read(buf);
                } catch (IOException e)
                {
                    throw new InputMismatchException();
                }
                if (id1 <= 0)
                    return -1;
            }
            return buf[id6++];
        }

        public int nextInt()
        {
            int c = read();
            while (id3(c))
                c = read();
            int sgn = 1;
            if (c == '-')
            {
                sgn = -1;
                c = read();
            }
            int res = 0;
            do
            {
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = read();
            } while (!id3(c));
            return res * sgn;
        }

        public String nextString()
        {
            int c = read();
            while (id3(c))
                c = read();
            StringBuilder res = new StringBuilder();
            do
            {
                res.appendCodePoint(c);
                c = read();
            } while (!id3(c));
            return res.toString();
        }

        public double nextDouble()
        {
            int c = read();
            while (id3(c))
                c = read();
            int sgn = 1;
            if (c == '-')
            {
                sgn = -1;
                c = read();
            }
            double res = 0;
            while (!id3(c) && c != '.')
            {
                if (c == 'e' || c == 'E')
                    return res * Math.pow(10, nextInt());
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = read();
            }
            if (c == '.')
            {
                c = read();
                double m = 1;
                while (!id3(c))
                {
                    if (c == 'e' || c == 'E')
                        return res * Math.pow(10, nextInt());
                    if (c < '0' || c > '9')
                        throw new InputMismatchException();
                    m /= 10;
                    res += (c - '0') * m;
                    c = read();
                }
            }
            return res * sgn;
        }

        public long nextLong()
        {
            int c = read();
            while (id3(c))
                c = read();
            int sgn = 1;
            if (c == '-')
            {
                sgn = -1;
                c = read();
            }
            long res = 0;
            do
            {
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = read();
            } while (!id3(c));
            return res * sgn;
        }

        public boolean id3(int c)
        {
            if (filter != null)
                return filter.id3(c);
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public String next()
        {
            return nextString();
        }

        public interface id8
        {
            public boolean id3(int ch);
        }
        public int[] id0(int n) {
            int[] ret = new int[n];
            for (int i = 0; i < n; i++) {
                ret[i] = nextInt();
            }
            return ret;
        }        
    }    

	static class Dumper {
		static void id4(int[] arr) {
			for (int i = 0; i < arr.length; i++) {
				System.out.print(arr[i] + " ");
			}
			System.out.println();
			System.out.println("---------------------");
		}

		static void id5(char[] arr) {
			for (int i = 0; i < arr.length; i++) {
				System.out.print(arr[i] + " ");
			}
			System.out.println();
			System.out.println("---------------------");
		}

		static void id9(double[] arr) {
			for (int i = 0; i < arr.length; i++) {
				System.out.print(arr[i] + " ");
			}
			System.out.println();
			System.out.println("---------------------");
		}

		static void id2(int[][] arr, int x, int y) {
			for (int i = 0; i < x; i++) {
				for (int j = 0; j < y; j++) {
					System.out.print(arr[i][j] + " ");
				}
				System.out.println();
			}
			System.out.println();
			System.out.println("---------------------");
		}

		static void id2(boolean[][] arr, int x, int y) {
			for (int i = 0; i < x; i++) {
				for (int j = 0; j < y; j++) {
					System.out.print(arr[i][j] + " ");
				}
				System.out.println();
			}
			System.out.println();
			System.out.println("---------------------");
		}

		static void print(Object o) {
			System.out.println(o.toString());
		}

		static void getc() {
			System.out.println("here");
		}
	}
}