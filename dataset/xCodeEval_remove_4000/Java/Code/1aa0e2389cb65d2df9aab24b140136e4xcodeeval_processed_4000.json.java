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
	
	static class Task{

		public void solve(InputReader in, PrintWriter out) throws IOException {
			int n = in.nextInt();
			int k = in.nextInt();
			long tmp[] = new long[n];
			for(int i=0;i<n;i++) {
				tmp[i] = in.nextLong();
			}
			TreeMap<Long,Integer> mp = new TreeMap<Long,Integer>();
			for(int i=0;i<n;i++) {			
				mp.put(tmp[i], mp.getOrDefault(tmp[i], 0)+1);
				if(mp.get(tmp[i])>=k) {
					out.println(0);
					return;
				}
			}			
			int m = mp.size()+2;
			long arr[] = new long[m];
			long num[] = new long[m];
			int c = 1;
			for(Long x:mp.keySet()) {
				arr[c] = x;
				num[c++] = mp.get(x);
			}
			
			long sum_left[] = new long[m];
			long sum_right[] = new long[m];
			long num_left[] = new long[m];
			long num_right[] = new long[m];
			for(int i=1;i<m-1;i++) {
				sum_left[i] = arr[i]*num[i];				
				sum_left[i]+= sum_left[i-1];
				num_left[i] = num[i];
				num_left[i]+= num_left[i-1];
			}
			for(int i=m-2;i>0;i--) {
				sum_right[i] = arr[i]*num[i];
				sum_right[i]+= sum_right[i+1];
				num_right[i] = num[i];
				num_right[i]+= num_right[i+1];
			}
			long min = Long.MAX_VALUE;
			for(int i=1;i<m-1;i++) {
				long l = sum_left[i-1];
				long r = sum_right[i+1];
				long lq = num_left[i-1];
				long rq = num_right[i+1];
				long lc = lq*(arr[i]-1)-l;
				long rc = r-rq*(arr[i]+1);
				if(lq+num[i]>=k) min = Math.min(min, lc+k-num[i]);
				if(rq+num[i]>=k) min = Math.min(min, rc+k-num[i]);
				if(lq+num[i]<k&&rq+num[i]<k) {
					min = Math.min(min, lc + rc + k - num[i]);
				}
			}
			out.println(min);
		}


	    long id9() {
	        BigInteger prime = BigInteger.probablePrime(31, new Random());
	        return prime.longValue();
	    }
		
		static class id10{
			int n;
			ArrayList<edge>[] g;
			int lvl[];
			int pare[];
			int dist[];
			public id10(int t, ArrayList<edge>[] x) {
				n=t;
				g=x;
				lvl = new int[n];
				pare = new int[n];
				dist = new int[n];
			}
			void pre_process() {
				dfs(0,-1,g,lvl,pare,dist);
			}
			void dfs(int cur, int pre, ArrayList<edge>[] g, int lvl[], int pare[], int dist[]) {
				for(edge nxt_edge:g[cur]) {
					if(nxt_edge.t!=pre) {
						lvl[nxt_edge.t] = lvl[cur]+1;
						dist[nxt_edge.t] = dist[cur]+nxt_edge.len;
						pare[nxt_edge.t] = cur;
						dfs(nxt_edge.t,cur,g,lvl,pare,dist);
					}
				}				
			}
			public int work(int p, int q) {
				int a = p;
				int b = q;
				while(lvl[p]<lvl[q]) q = pare[q];
				while(lvl[p]>lvl[q]) p = pare[p];			
				while(p!=q){p = pare[p]; q = pare[q];}
				int c = p;
				return dist[a]+dist[b]-dist[c]*2;
			}
		}
		static class id5{
			int n;
			ArrayList<edge>[] g;
			int lvl[];
			int pare[];
			int dist[];
			int table[][];
			public id5(int a, ArrayList<edge>[] t) {
				n = a;
				g = t;
				lvl = new int[n];
				pare = new int[n];
				dist = new int[n];				
				table = new int[20][n];				
			}
			void pre_process() {
				dfs(0,-1,g,lvl,pare,dist);
				for(int i=0;i<20;i++) {
					for(int j=0;j<n;j++) {
						if(i==0) table[0][j] = pare[j];
						else table[i][j] = table[i-1][table[i-1][j]];
					}
				}				
			}
			void dfs(int cur, int pre, ArrayList<edge>[] g, int lvl[], int pare[], int dist[]) {
				for(edge nxt_edge:g[cur]) {
					if(nxt_edge.t!=pre) {
						lvl[nxt_edge.t] = lvl[cur]+1;
						dist[nxt_edge.t] = dist[cur]+nxt_edge.len;
						pare[nxt_edge.t] = cur;
						dfs(nxt_edge.t,cur,g,lvl,pare,dist);
					}
				}				
			}			
			public int work(int p, int q) {
				int a = p;
				int b = q;
				if(lvl[p]>lvl[q]) {
					int tmp = p;
					p=q;
					q=tmp;
				}				
				for(int i=19;i>=0;i--) {
					if(lvl[table[i][q]]>=lvl[p]) q=table[i][q];
				}				
				if(p==q) return p;

				for(int i=19;i>=0;i--) {
					if(table[i][p]!=table[i][q]) {
						p = table[i][p];
						q = table[i][q];
					}
				}
				return table[0][p];
				

			}
		}
		static class id8{
			int n;
			ArrayList<edge>[] g;
			int lvl[];
			int pare[];
			int dist[];
			int jump[];
			int sz;
			public id8(int a, ArrayList<edge>[] b) {
				n=a;
				g=b;
				lvl = new int[n];
				pare = new int[n];
				dist = new int[n];
				jump = new int[n];
				sz = (int) Math.sqrt(n);
			}
			void pre_process() {
				dfs(0,-1,g,lvl,pare,dist,jump);
			}
			void dfs(int cur, int pre, ArrayList<edge>[] g, int lvl[], int pare[], int dist[], int[] jump) {
				for(edge nxt_edge:g[cur]) {
					if(nxt_edge.t!=pre) {
						lvl[nxt_edge.t] = lvl[cur]+1;
						dist[nxt_edge.t] = dist[cur]+nxt_edge.len;
						pare[nxt_edge.t] = cur;
						if(lvl[nxt_edge.t]%sz==0) {
							jump[nxt_edge.t] = cur;
						}else {
							jump[nxt_edge.t] = jump[cur];
						}
						dfs(nxt_edge.t,cur,g,lvl,pare,dist,jump);
					}
				}				
			}
			int work(int p, int q) {
				int a = p; int b = q;
				if(lvl[p]>lvl[q]) {
					int tmp = p;
					p=q;
					q=tmp;
				}
				while(jump[p]!=jump[q]) {
					if(lvl[p]>lvl[q]) p = jump[p];
					else q = jump[q];
				}
				while(p!=q) {
					if(lvl[p]>lvl[q]) p = pare[p];
					else q = pare[q];
				}
				return dist[a]+dist[b]-dist[p]*2;
			}
		}
		
		class edge implements Comparable<edge>{
			int f,t,len;
			public edge(int a, int b, int c) {
				f=a;t=b;len=c;
			}
			@Override
			public int compareTo(edge t) {				
				return t.len-this.len;
			}
		}
	
		class pair implements Comparable<pair>{
			int idx,lvl;
			public pair(int a, int b) {
				idx = a;
				lvl = b;
			}
			@Override
			public int compareTo(pair t) {
				return t.lvl-this.lvl;
			}
		}		
		
		static class id11{
			int n;
			ArrayList<edge>[] g;
			int lvl[];
			int dist[];
			int tour[];
			int tour_rank[];
			int first_occ[];
			int c;
			sgt s;
			public id11(int a, ArrayList<edge>[] b) {
				n=a;
				g=b;
				c=0;
				lvl = new int[n];
				dist = new int[n];
				tour = new int[2*n];
				tour_rank = new int[2*n];
				first_occ = new int[n];
				Arrays.fill(first_occ, -1);
			}
			void pre_process() {
				tour[c++] = 0;
				dfs(0,-1);
				for(int i=0;i<2*n;i++) {
					tour_rank[i] = lvl[tour[i]];
					if(first_occ[tour[i]]==-1) first_occ[tour[i]] = i;
				}
				s = new sgt(0,2*n,tour_rank);
			}
			void dfs(int cur, int pre) {
				for(edge nxt_edge:g[cur]) {
					if(nxt_edge.t!=pre) {
						lvl[nxt_edge.t] = lvl[cur]+1;
						dist[nxt_edge.t] = dist[cur]+nxt_edge.len;
						tour[c++] = nxt_edge.t;
						dfs(nxt_edge.t,cur);
						tour[c++] = cur;
					}
				}				
			}			
			int work(int p,int q) {			
				int a = Math.max(first_occ[p], first_occ[q]);
				int b = Math.min(first_occ[p], first_occ[q]);
				int idx = s.id14(b, a+1);
				

				int c = tour[idx];
				return dist[p]+dist[q]-dist[c]*2;
			}
		}		

		  
	    static class sgt{
	    	sgt lt;
	    	sgt rt;
	    	int l,r;
	    	int sum, max, min, lazy;
	    	int min_idx;
	    	public sgt(int L, int R, int arr[]) {
	    		l=L;r=R;
	    		if(l==r-1) {
	    			sum = max = min = arr[l];
	    			lazy = 0;
	    			min_idx = l;
	    			return;
	    		}
	    		lt = new sgt(l, l+r>>1, arr);
	    		rt = new sgt(l+r>>1, r, arr);
	    		pop_up();
	    	}
	    	void pop_up() {
	    		this.sum = lt.sum + rt.sum;
	    		this.max = Math.max(lt.max, rt.max);
	    		this.min = Math.min(lt.min, rt.min);
	    		if(lt.min<rt.min)
	    			this.min_idx = lt.min_idx;
	    		else if(lt.min>rt.min) this.min_idx = rt.min_idx;
	    		else this.min = Math.min(lt.min_idx, rt.min_idx);
	    	}
	    	void push_down() {
	    		if(this.lazy!=0) {
	    			lt.sum+=lazy;
	    			rt.sum+=lazy;
	    			lt.max+=lazy;
	    			lt.min+=lazy;
	    			rt.max+=lazy;
	    			rt.min+=lazy;
	    			lt.lazy+=this.lazy;
	    			rt.lazy+=this.lazy;
	    			this.lazy = 0;
	    		}
	    	}
	    	void change(int L, int R, int v) {
	    		if(R<=l||r<=L) return;
	    		if(L<=l&&r<=R) {
	    			this.max+=v;
	    			this.min+=v;
	    			this.sum+=v*(r-l);
	    			this.lazy+=v;
	    			return;
	    		}
	    		push_down();
	    		lt.change(L, R, v);
	    		rt.change(L, R, v);
	    		pop_up();
	    	}
	    	int query_max(int L, int R) {
	    		if(L<=l&&r<=R) return this.max;
	    		if(r<=L||R<=l) return Integer.MIN_VALUE;
	    		push_down();
	    		return Math.max(lt.query_max(L, R), rt.query_max(L, R));	    		
	    	}
	    	int query_min(int L, int R) {
	    		if(L<=l&&r<=R) return this.min;
	    		if(r<=L||R<=l) return Integer.MAX_VALUE;
	    		push_down();
	    		return Math.min(lt.query_min(L, R), rt.query_min(L, R));	
	    	}
	    	int query_sum(int L, int R) {
	    		if(L<=l&&r<=R) return this.sum;
	    		if(r<=L||R<=l) return 0;
	    		push_down();
	    		return lt.query_sum(L, R) + rt.query_sum(L, R);
	    	}
	    	int id14(int L, int R) {
	    		if(L<=l&&r<=R) return this.min_idx;
	    		if(r<=L||R<=l) return Integer.MAX_VALUE;
	    		int a = lt.id14(L, R);
	    		int b = rt.id14(L, R);
	    		int aa = lt.query_min(L, R);
	    		int bb = rt.query_min(L, R);
	    		if(aa<bb) return a;
	    		else if(aa>bb) return b;	    		
	    		return Math.min(a,b);
	    	}
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
        private int id1;
        private id12 filter;
 
        public InputReader(InputStream stream)
        {
            this.stream = stream;
        }
 
        public int read()
        {
            if (id1 == -1)
                throw new InputMismatchException();
            if (id7 >= id1)
            {
            	id7 = 0;
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
            return buf[id7++];
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
 
        public interface id12
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
 
		static void id6(char[] arr) {
			for (int i = 0; i < arr.length; i++) {
				System.out.print(arr[i] + " ");
			}
			System.out.println();
			System.out.println("---------------------");
		}
 
		static void id13(double[] arr) {
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
