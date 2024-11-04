import java.io.*;
import java.math.BigInteger;
import java.util.*;
 
public class Main{
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
			int c = in.nextInt();
			int f = 1000000007;
			int sz = 200011;
			int cnt[][] = new int[sz][10];
			cnt[0][0] = 1;
			for(int i=0;i<sz-1;i++) {
				for(int j=0;j<10;j++) {
					if(j!=9) {
						cnt[i+1][j+1] = cnt[i][j];
						cnt[i+1][j+1] %= f;
					}
					else {
						cnt[i+1][0] = cnt[i][9];
						cnt[i+1][1] += cnt[i][9];
						cnt[i+1][0] %= f;
						cnt[i+1][1] %= f;
					}					
				}
			}
			int dp[][] = new int[10][sz];			
			for(int i=0;i<10;i++) {
				for(int j=0;j+1<sz;j++) {
					if(i==0) {
						for(int k=0;k<10;k++) {						
							dp[i][j]+=cnt[j][k];
							dp[i][j]%=f;
						}
					}else {
						dp[i][j] = dp[i-1][j+1];
					}
				}
			}
			while(c-->0) {

				int x = in.nextInt();
				int n = in.nextInt();				
				if(x==0) {
					out.println(dp[0][n]);
				}else {
					int sum = 0;
					while(x!=0) {
						

						sum+=dp[x%10][n];
						x/=10;
						sum%=f;
					}
					out.println(sum);
				}				
			}
		}
	    
		class edge implements Comparable<edge>{
			int id,f,t; int len;
			public edge(int a, int b, int c, int d) {
				f=a;t=b;len=c;id=d;
			}
			@Override
			public int compareTo(edge t) {				
				if(this.len-t.len>0) return 1;
				else if(this.len-t.len<0) return -1;
				return 0;
			}
		}
		
		
	    public int minMoves(int[] nums, int k) {
	        int n = 0;
	        for(int i:nums) n+=i;
	        int arr[] = new int[n];
	        for(int i=0,j=0;i<nums.length;i++) {
	        	if(nums[i]==1) arr[j++] = i;
	        }
	        int sum[] = new int[n];
	        for(int i=0;i<n;i++) {
	        	sum[i] = arr[i];
	        	if(i>0) sum[i]+=sum[i-1];
	        }
	        int ret = Integer.MAX_VALUE;
	        for(int i=0;i+k-1<n;i++) {
	        	int j = i+k-1;
	        	int mid = (i+j)/2;
	        	int lnum = mid-i;
	        	int left = arr[mid]*lnum-(mid-1>=0?sum[mid-1]:0)+(i>0?sum[i-1]:0)-(1+lnum)*lnum/2;
	        	int rnum = j-mid;
	        	int right = sum[j]-sum[mid]-rnum*arr[mid]-(1+rnum)*rnum/2;
	        	ret = Math.min(ret, left+right);
	        }
	        return ret;
	    }
	    class pair implements Comparable<pair>{
	    	int idx;
	    	int bit_pos;
	    	public pair(int a, int b) {
	    		idx=a;bit_pos=b;
	    	}
			@Override
			public int compareTo(pair t) {
				return t.idx-this.idx;
			}
	    }
		
	    public List<List<Integer>> id0(int n, int[][] edges) {
	        int idx = 0;
	        int m = edges.length;
	        ArrayList<edge> all = new ArrayList<edge>();
	        for(int x[]:edges) {
	        	int f = x[0];
	        	int t = x[1];
	        	int w = x[2];
	        	edge tmp1 = new edge(f,t,w,idx++);
	        	all.add(tmp1);
	        }
	        DSU ds = new DSU(n+1);
	        Collections.sort(all);
	        Set<Integer> crit = new HashSet<Integer>();
	        Set<Integer> no_use = new HashSet<Integer>();
	        int p = 0;
	        boolean vis[] = new boolean[n];
	        while(p<m) {
	        	edge t = all.get(p);
	        	ArrayList<edge> tmp = new ArrayList<edge>();
	        	tmp.add(t);
	        	p++;
	        	while(p<m&&all.get(p).len==t.len) {
	        		tmp.add(all.get(p++));
	        	}
	        	int cnt[] = new int[n];
	        	Arrays.fill(cnt, -1);
	        	for(edge v:tmp) {
	        		if(ds.find(v.f)==ds.find(v.t)) {
	        			no_use.add(v.id);
	        			continue;
	        		}
	        		if(!vis[v.f]) {
	        			if(cnt[v.f]==-1) {
	        				cnt[v.f] = v.id;
	        			}else {
	        				cnt[v.f] = -2;
	        			}
	        		}
	        		if(!vis[v.t]) {
	        			if(cnt[v.t]==-1) {
	        				cnt[v.t] = v.id;
	        			}else {
	        				cnt[v.t] = -2;
	        			}
	        		}
	        	}
	        	for(int i=0;i<n;i++) {
	        		if(cnt[i]>=0) crit.add(cnt[i]);
	        	}
	        	for(edge v:tmp) {
	        		ds.union(v.f, v.t);
	        		vis[v.f] = true;
	        		vis[v.t] = true;
	        	}
	        }
	        List<List<Integer>> ret = new ArrayList<List<Integer>>();
	        List<Integer> r1 = new ArrayList<Integer>();
	        List<Integer> r2 = new ArrayList<Integer>();
	        for(int i=0;i<m;i++) {
	        	if(crit.contains(i)) r1.add(i);
	        	else if(!no_use.contains(i)) {
	        		r2.add(i);
	        	}
	        }
	        ret.add(r1);ret.add(r2);
	        return ret;
	    }


	
		class pair2 implements Comparable<pair2>{
			long val; int idx;
			public pair2(long a, int b) {
				val = a;
				idx = b;
			}
			@Override
			public int compareTo(pair2 t) {
				if(this.val-t.val>0) return 1;
				else if(this.val-t.val<0) return -1;				
				return 0;
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
	    		else this.min_idx = Math.min(lt.min_idx, rt.min_idx);
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
	    	int id10(int L, int R) {
	    		if(L<=l&&r<=R) {
	    			return this.min_idx;
	    		}
	    		if(r<=L||R<=l) return Integer.MAX_VALUE;
	    		int a = lt.id10(L, R);
	    		int b = rt.id10(L, R);
	    		int aa = lt.query_min(L, R);
	    		int bb = rt.query_min(L, R);
	    		int ret = 0;
	    		if(aa<bb) ret = a;
	    		else if(aa>bb) ret = b; 		
	    		else ret = Math.min(a,b);
	    		return ret;
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
        private int id2;
        private id8 filter;
 
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
 
        public interface id8
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
 
		static void id9(double[] arr) {
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