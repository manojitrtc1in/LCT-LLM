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
		static final int F = 1_000_000_007;
		static final int BIG_INT = 999999999;
		
		public void solve(InputReader in, PrintWriter out) throws IOException {
			int n = in.nextInt();
			int k = in.nextInt();
			char[] arr = in.next().toCharArray();
			TreeMap<Integer,Integer> tm = new TreeMap<Integer,Integer>();
			for(char c:arr) {
				tm.put(c-'a', tm.getOrDefault(c-'a', 0)+1);
			}
			int c = 1;
			while(c<n&&arr[c]<=arr[0]) {
				if(c==309){
					

				}
				if(arr[c]<arr[0]||c==1) c++;
				else{
					int p = 1;
					int q = c+1;
					boolean delete = false;
					while(p<c&&q<n) {
						if(arr[p]>arr[q]) {
							delete = false;
							break;
						}else if(arr[p]<arr[q]){
							delete = true;
							break;
						}
						p++;q++;
					}
					if(q>=n) delete = true;
					if(delete) {
						break;
					}else {
						c=q;
					}
				}
			}
			StringBuilder sb = new StringBuilder();
			for(int i=0;i<c;i++) sb.append(arr[i]);
			String x = sb.toString();
			while(c<k) {
				x+=x;
				c*=2;
			}
			out.println(x.substring(0, k));
		}
		class edge implements Comparable<edge>{
			int fx; int fy;
			int tx; int ty;
			int l;int step;
			public edge(int a, int b ,int c,int d,int e, int f) {
				fx=a;fy=b;tx=c;ty=d;l=e;step=f;
			}
			@Override
			public int compareTo(edge t) {
				

				return this.l-t.l;
			}
			
		}

	    
	    public int id5(int[] arr) {
	    	int n = arr.length;
	    	int id6 = arr[0];
	    	int id12 = 0;
	        int sum = arr[0];
	        














	        return 1;
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
	    	int id11(int L, int R) {
	    		if(L<=l&&r<=R) {
	    			return this.min_idx;
	    		}
	    		if(r<=L||R<=l) return Integer.MAX_VALUE;
	    		int a = lt.id11(L, R);
	    		int b = rt.id11(L, R);
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
        private int id8;
        private int id1;
        private id9 filter;
 
        public InputReader(InputStream stream)
        {
            this.stream = stream;
        }
 
        public int read()
        {
            if (id1 == -1)
                throw new InputMismatchException();
            if (id8 >= id1)
            {
            	id8 = 0;
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
            return buf[id8++];
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
 
        public interface id9
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
 
		static void id7(char[] arr) {
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