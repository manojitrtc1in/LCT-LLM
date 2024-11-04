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
			int c = in.nextInt();
			while(c-->0) {
				int n = in.nextInt();
				int arr[] = in.id0(n);
				Set<Integer> s = new HashSet<Integer>();
				boolean f = false;
				int p=-1;
				for(int i=0;i<n;i++) {
					s.add(arr[i]);
					if(i>0&&arr[i]==arr[i-1]) {
						f = true;
						p=i-1;
					}
				}
				if(s.size()==1) {
					out.println(1);
					for(int i=0;i<n;i++) {
						out.print(1+" ");
					}
					out.println();
				}else if(n%2==0) {
					out.println(2);
					for(int i=0;i<n;i++) {
						out.print((i%2+1)+" ");
					}
					out.println();
				}else if(n%2==1&&(f||arr[n-1]==arr[0])) {
					out.println(2);
					int tmp = 0;
					for(int i=0;i<n;i++) {
						out.print(1+tmp+" ");
						if(i!=p)tmp = 1-tmp;
					}
					out.println();					
				}else {
					out.println(3);
					for(int i=0;i<n;i++) {
						if(i!=n-1)out.print((i%2+1)+" ");
						else out.print(3+" ");
					}
					out.println();					
				}
			}
		}

	    long id8() {
	        BigInteger prime = BigInteger.probablePrime(31, new Random());
	        return prime.longValue();
	    }	    
	    
		int dfs(int cur, int pre, ArrayList<Integer>[] g, int sub_val[], int val[]) {
			int v = val[cur]==1?1:-1;
			for(int nxt:g[cur]) {
				if(nxt==pre) continue;
				int tmp = dfs(nxt,cur,g,sub_val,val);
				if(tmp>0) v+=tmp;
			}
			return sub_val[cur] = v;
		}
		void dfs2(int cur, int pre, ArrayList<Integer>[] g, int sub_val[], int val[], int id5[]) {
			int v = sub_val[cur]+id5[cur];
			if(cur==2) {
				

			}
			for(int nxt:g[cur]) {
				if(nxt==pre) continue;
				id5[nxt] = v;
				if(sub_val[nxt]>0) id5[nxt]-=sub_val[nxt];
				dfs2(nxt,cur,g,sub_val,val,id5);
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
	    	int id11(int L, int R) {
	    		if(L<=l&&r<=R) return this.min_idx;
	    		if(r<=L||R<=l) return Integer.MAX_VALUE;
	    		int a = lt.id11(L, R);
	    		int b = rt.id11(L, R);
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
        private id9 filter;
 
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
