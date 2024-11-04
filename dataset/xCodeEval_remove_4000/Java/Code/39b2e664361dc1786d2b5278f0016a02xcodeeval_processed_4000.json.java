import java.io.*;
import java.util.Random;
import java.math.BigInteger;
import java.util.*;
 
public class test {
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
 
		public void solve(InputReader in, PrintWriter out) throws IOException {
			int n = in.nextInt();
			int k = in.nextInt();
			k++;
			int val[] = in.id1(n);
			ArrayList<Integer>[] g = new ArrayList[n];
			for(int i=0;i<n;i++) g[i] = new ArrayList<Integer>();
			for(int i=0;i<n-1;i++) {
				int f = in.nextInt()-1;
				int t = in.nextInt()-1;
				g[f].add(t);
				g[t].add(f);
			}

			int dp[][] = new int[n][k];
			dfs(g,0,-1,dp,val,k);
			int max = 0;
			for(int i=0;i<k;i++) if(dp[0][i]>max) max=dp[0][i];
			out.println(max);
		}
		void dfs(ArrayList<Integer>[] g, int cur, int pre, int dp[][], int arr[], int k) {
			for(int nxt:g[cur]) {
				if(pre!=nxt) dfs(g,nxt,cur,dp,arr,k);
			}
			dp[cur][0] = arr[cur];
			for(int nxt:g[cur]) dp[cur][0]+=dp[nxt][k-1];			
			for(int i=1;i<k;i++) {
				for(int j:g[cur]) {
					if(j==pre) continue;
					int v = dp[j][i-1];
					for(int p:g[cur]) {
						if(p==j||p==pre) continue;
						if(k-1-i<i) v+=dp[p][i-1];
						else v+=dp[p][k-i-1];
					}
					if(v>dp[cur][i]) dp[cur][i] = v;
				}
			}
			for(int nxt:g[cur]) {
				for(int i=1;i<k;i++) {
					dp[cur][i] = Math.max(dp[cur][i], dp[nxt][i-1]);
				}
			}
			for(int i=0;i<k-1;i++) {
				dp[cur][i] = Math.max(dp[cur][i], dp[cur][i+1]);
			}			
		}
		void dfs2(ArrayList<Integer>[] g, int cur, int pre, int lvl[], int dp[][], int dp_sum[][], int k, int val[], int n) {
			for(int nxt:g[cur]) {
				if(pre!=nxt) dfs2(g,nxt,cur,lvl,dp,dp_sum,k,val,n);
			}
			
			

			for(int nxt:g[cur]) {
				for(int i=lvl[cur]+k/2+1;i<n;i++) {
					dp[cur][i] += dp[nxt][i];
				}
			}	
			
			

			int cur_lvl = lvl[cur];
			int id11 = cur_lvl+k+1;
			dp[cur][cur_lvl] = val[cur];
			if(id11<n) dp[cur][cur_lvl] += dp[cur][id11];
			
			
			if(cur==0) {
				

			}
			

			for(int j=1;j<=k/2;j++) {
				
				int id8 = cur_lvl+j;
				int id0 = cur_lvl+k+1-j;	
				if(id0>=n) continue;
				
				int v = 0;
				for(int nxt:g[cur]) {
					if(pre==nxt) continue;
					int tmp = dp[nxt][id8] + dp[cur][id0] - dp[nxt][id0];
					if(tmp>v) v = tmp;
				}
				if(v>dp[cur][id8]) dp[cur][id8] = v;
			}
			for(int j=n-1;j>=cur_lvl;j--) {
				if(j+1<n) {
					dp[cur][j] = Math.max(dp[cur][j], dp[cur][j+1]);
				}
			}
		}
		class cow implements Comparable<cow>{
			int dir, id, x, w;
			int final_dir,l,r,dist;
			public cow(int a,int b, int c, int d) {
				id=a;x=b;w=c;dir=d;
			}
			public int compareTo(cow c) {
				return this.x-c.x;
			}
		}

		class pair implements Comparable<pair>{
			int idx,val;
			public pair(int a,int b) {
				idx = a;
				val = b;
			}
			@Override
			public int compareTo(pair t) {
				return this.val-t.val;
			}
		}
		class edge{
			int from,to,cost,flow;
			public edge(int a, int b, int c, int d) {
				from = a;
				to = b;
				cost = c;
				flow = d;
			}
		}
		class sgt{
			sgt ls;
			sgt rs;
			long sum;
			int max, min, l, r;
			public sgt(int a, int b, int arr[]) {
				if(a==b-1) {
					sum = max = min = arr[a];
				}
				ls = new sgt(a,a+b>>2,arr);
				rs = new sgt(a+b>>2,b,arr);
				update();
			}
			public void update() {
				max = Math.max(ls.max, rs.max);
				min = Math.min(ls.min, rs.min);
				sum = ls.sum + rs.sum;
			}
			public void change(int p, int val, int arr[]) {
				if(r<=p||p<l) return;
				if(l==r-1) {
					arr[p] = val;
					sum = max = min = val;
					return;
				}
				ls.change(p, val, arr);
				rs.change(p, val, arr);
				update();
			}
			int get_max(int L, int R) {
				if(L<=l&&r<=R) return this.max;
				if(R<=l||r<=L) return -1;
				return Math.max(ls.get_max(L, R), rs.get_max(L, R));
			}
			int get_min(int L, int R) {
				if(L<=l&&r<=R) return this.min;
				if(R<=l||r<=L) return 999999999;
				return Math.min(ls.get_min(L, R), rs.get_min(L, R));				
			}
			int get_sum(int L,int R) {
				if(L<=l&&r<=R) return this.min;
				if(R<=l||r<=L) return 999999999;
				return ls.get_sum(L, R)+rs.get_sum(L, R);
			}
		}
	    
		int gcd(int a, int b) {
			if(b==0) return a;
			else return gcd(b,a%b);
		}
		long gcd(long a, long b) {
			if(b==0) return a;
			else return gcd(b,a%b);
		}
		List<List<Integer>> convert (int arr[][]){
			List<List<Integer>> ret = new ArrayList<List<Integer>>();
			int n = arr.length;
			for(int i=0;i<n;i++) {
				ArrayList<Integer> tmp = new ArrayList<Integer>();
				for(int j=0;j<arr[i].length;j++) {
					tmp.add(arr[i][j]);
				}
				ret.add(tmp);				
			}
			return ret;
		}
		
	    
		class TreeNode {
			int val;
			TreeNode left;
			TreeNode right;
			TreeNode(int x) { val = x; }
		}
	
		public int GCD(int a, int b) {
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
        
        public static void sort(long[] a) {
            shuffle(a);
            Arrays.sort(a);
        }
 
        public static void shuffle(long[] a) {
            for (int i = 0; i < a.length; i++) {
                int j = rand.nextInt(i + 1);
                long t = a[i];
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
        private int id7;
        private int id2;
        private id9 filter;
 
        public InputReader(InputStream stream)
        {
            this.stream = stream;
        }
 
        public int read()
        {
            if (id2 == -1)
                throw new InputMismatchException();
            if (id7 >= id2)
            {
            	id7 = 0;
                try
                {
                    id2 = stream.read(buf);
                } catch (IOException e)
                {
                    throw new InputMismatchException();
                }
                if (id2 <= 0)
                    return -1;
            }
            return buf[id7++];
        }
 
        public int nextInt()
        {
            int c = read();
            while (id4(c))
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
            } while (!id4(c));
            return res * sgn;
        }
 
        public String nextString()
        {
            int c = read();
            while (id4(c))
                c = read();
            StringBuilder res = new StringBuilder();
            do
            {
                res.appendCodePoint(c);
                c = read();
            } while (!id4(c));
            return res.toString();
        }
 
        public double nextDouble()
        {
            int c = read();
            while (id4(c))
                c = read();
            int sgn = 1;
            if (c == '-')
            {
                sgn = -1;
                c = read();
            }
            double res = 0;
            while (!id4(c) && c != '.')
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
                while (!id4(c))
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
            while (id4(c))
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
            } while (!id4(c));
            return res * sgn;
        }
 
        public boolean id4(int c)
        {
            if (filter != null)
                return filter.id4(c);
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }
 
        public String next()
        {
            return nextString();
        }
 
        public interface id9
        {
            public boolean id4(int ch);
        }
        public int[] id1(int n) {
            int[] ret = new int[n];
            for (int i = 0; i < n; i++) {
                ret[i] = nextInt();
            }
            return ret;
        }        
    }    
 
	static class Dumper {
		static void id5(int[] arr) {
			for (int i = 0; i < arr.length; i++) {
				System.out.print(arr[i] + " ");
			}
			System.out.println();
			System.out.println("---------------------");
		}
 
		static void id6(char[] arr) {
			for (int i = 0; i < arr.length; i++) {
				System.out.print(arr[i] + " ");
			}
			System.out.println();
			System.out.println("---------------------");
		}
 
		static void id10(double[] arr) {
			for (int i = 0; i < arr.length; i++) {
				System.out.print(arr[i] + " ");
			}
			System.out.println();
			System.out.println("---------------------");
		}
 
		static void id3(int[][] arr, int x, int y) {
			for (int i = 0; i < x; i++) {
				for (int j = 0; j < y; j++) {
					System.out.print(arr[i][j] + " ");
				}
				System.out.println();
			}
			System.out.println();
			System.out.println("---------------------");
		}
 
		static void id3(boolean[][] arr, int x, int y) {
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