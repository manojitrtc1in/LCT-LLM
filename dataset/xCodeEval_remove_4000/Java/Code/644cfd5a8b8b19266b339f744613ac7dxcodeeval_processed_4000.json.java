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
		
		public void solve(InputReader in, PrintWriter out) throws IOException {
			int n = in.nextInt();
			int m = in.nextInt();
			int k = in.nextInt();
			long arr[] = new long[n+1];
			long sum[] = new long[n+1];
			for(int i=1;i<=n;i++) {
				arr[i] = in.nextInt();
			}
			id6(arr);
			for(int i=1;i<=n;i++) {
				sum[i] = arr[i];
				sum[i]+=sum[i-1];
			}
			int c[] = new int[n+1];
			for(int i=0;i<m;i++) {
				int a = in.nextInt();
				int b = in.nextInt();
				if(a<=n) c[a] = Math.max(c[a], b);
			}
			long dp[] = new long[k+1];
			Arrays.fill(dp, 999999999);
			dp[0] = 0;
			for(int i=1;i<=k;i++) {
				for(int j=1;j<=i;j++) {
					dp[i] = Math.min(dp[i], dp[i-j]+sum[i]-sum[i-j+c[j]]);
				}
			}
			out.println(dp[k]);








































































		}
		void id6(long arr[]) {
			int n = arr.length;
			Random rgen = new Random();
			for (int i=0; i<n; i++) {
			    int randomPosition = rgen.nextInt(n);
			    long temp = arr[i];
			    arr[i] = arr[randomPosition];
			    arr[randomPosition] = temp;
			}
			Arrays.sort(arr);
		}
		void dfs(int cur, ArrayList<Integer>[]g, int parent[], boolean[] vis, int pre, int[] dist, int val[], int lvl[]) {
			parent[cur] = pre;
			for(int i:g[cur]) {
				if(!vis[i]) {
					vis[i] = true;
					dist[i] = dist[cur]^val[i];
					lvl[i] = lvl[cur]+1;
					dfs(i,g,parent,vis,cur,dist,val,lvl);
				}
			}
		}
		void dfs2(int cur, ArrayList<Integer>[]g, int dist[], int val[], int pre, int[] lvl) {
			for(int i:g[cur]) {
				if(i!=pre&&lvl[i]>lvl[cur]) {
					dist[i] = dist[cur]^val[i];
					dfs2(i,g,dist,val,cur,lvl);
				}
			}
		}
		int[][] build(int arr[], ArrayList<Integer>[] g, int parent[]){
			int n = arr.length;
			int dp[][] = new int[n][21];
			for(int i=0;i<n;i++) {
				Arrays.fill(dp[i], -1);
				dp[i][0] = parent[i];
			}
			for(int i=1;(1<<i)<n;i++) {
				for(int j=0;j<n;j++) {
					if(dp[j][i-1]!=-1) {
						dp[j][i] = dp[dp[j][i-1]][i-1];
					}
				}
			}
			return dp;
		}
		
		int lca(int a, int b, int dp[][], int lvl[], int parent[]) {
			if(lvl[a]<lvl[b]) {
				int tmp = a;
				a = b;
				b = tmp;
			}
			int dis = lvl[a]-lvl[b];
			while(dis>0) {
				int rs = (int)Math.log(dis);
				a = dp[a][rs];
				dis-=(1<<rs);
			}
			if(a==b) return a;
			
			for(int j=20;j>=0;j--) {
				if(dp[a][j]!=-1&&dp[a][j]!=dp[b][j]) {
					a = dp[a][j];
					b = dp[b][j];
				}
			}
			return parent[a];
		}
		
	    public int A(int m, int n) {
	        return n == 0 ? 1 : A(m, n - 1) * (m - n + 1);
	    }		
		
	    public int id7(int N) {
	    	String x = N+"";
	    	int len = x.length();
	    	int ret = 0;
	    	for(int i=1;i<len;i++) {
	    		ret+=9*A(9,i-1);
	    	}
	    	boolean seen[] = new boolean[10];
	    	for(int i=0;i<len;i++) {
	    		int idx = x.charAt(i)-'0';
	            for (int j = i > 0 ? 0 : 1; j < idx; ++j)
	                if (!seen[j])
	                    ret += A(9-i, len - i - 1);
	            if (seen[idx]) break;
	            seen[idx] = true;;
	    	}
	    	return N-ret;
	    }
	    int find(int from, int to) {
	    	int c = 0;
	    	for(int i=from; i<=to;i++) {
	    		int t = i;
	    		boolean arr[] = new boolean[10];
	    		while(t>0) {
	    			int f = t%10;
	    			if(arr[f]) {
	    				c++;
	    				break;
	    			}
	    			else arr[f] = true;
	    			t/=10;
	    		}
	    	}
	    	return c;
	    }
	    public long fa(int a) {
	    	int v = 1;
	    	for(int i=a;i>=1;i--) v*=i;
	    	return v;
	    }






	    public long C(int m, int n) {
	    	return A(m,n)/fa(m);
	    }
	}
	
	class BIT{
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
        private int id5;
        private int id0;
        private id8 filter;

        public InputReader(InputStream stream)
        {
            this.stream = stream;
        }

        public int read()
        {
            if (id0 == -1)
                throw new InputMismatchException();
            if (id5 >= id0)
            {
            	id5 = 0;
                try
                {
                    id0 = stream.read(buf);
                } catch (IOException e)
                {
                    throw new InputMismatchException();
                }
                if (id0 <= 0)
                    return -1;
            }
            return buf[id5++];
        }

        public int nextInt()
        {
            int c = read();
            while (id2(c))
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
            } while (!id2(c));
            return res * sgn;
        }

        public String nextString()
        {
            int c = read();
            while (id2(c))
                c = read();
            StringBuilder res = new StringBuilder();
            do
            {
                res.appendCodePoint(c);
                c = read();
            } while (!id2(c));
            return res.toString();
        }

        public double nextDouble()
        {
            int c = read();
            while (id2(c))
                c = read();
            int sgn = 1;
            if (c == '-')
            {
                sgn = -1;
                c = read();
            }
            double res = 0;
            while (!id2(c) && c != '.')
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
                while (!id2(c))
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
            while (id2(c))
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
            } while (!id2(c));
            return res * sgn;
        }

        public boolean id2(int c)
        {
            if (filter != null)
                return filter.id2(c);
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public String next()
        {
            return nextString();
        }
        
        public int[] readarray(int n)
        {
        	int ret[] = new int[n];
        	for(int i=0;i<n;i++) ret[i] = this.nextInt();
        	return ret;
        }        

        public interface id8
        {
            public boolean id2(int ch);
        }
    }    

	static class Dumper {
		static void id3(int[] arr) {
			for (int i = 0; i < arr.length; i++) {
				System.out.print(arr[i] + " ");
			}
			System.out.println();
			System.out.println("---------------------");
		}

		static void id4(char[] arr) {
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

		static void id1(int[][] arr, int x, int y) {
			for (int i = 0; i < x; i++) {
				for (int j = 0; j < y; j++) {
					System.out.print(arr[i][j] + " ");
				}
				System.out.println();
			}
			System.out.println();
			System.out.println("---------------------");
		}

		static void id1(boolean[][] arr, int x, int y) {
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