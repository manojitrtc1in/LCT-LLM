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
			int s = in.nextInt();
			ArrayList<pair> pos = new ArrayList<pair>();
			ArrayList<pair> neg = new ArrayList<pair>();
			int cnt = 0;
			for(int i=0;i<n;i++) {
				pair tmp = new pair(in.nextInt(), in.nextInt());
				if(tmp.c>=0) pos.add(tmp);
				else {
					tmp.r = Math.max(tmp.r, -tmp.c);
					neg.add(tmp);
				}
			}
			Collections.sort(pos);
			Collections.sort(neg);
			for(pair x:pos) {
				if(s<x.r) break;
				s+=x.c;	
				cnt++;
			}
			int m = neg.size();
			int dp[][] = new int[m][s+1];
			

			int ret = 0;
			if(neg.size()>0) {
				for(int i=neg.get(0).r;i<=s;i++) {
					dp[0][i+neg.get(0).c] = 1;
					if(dp[0][i+neg.get(0).c]>ret) ret = dp[0][i+neg.get(0).c];
				}
			}			
			for(int i=1;i<m;i++) {
				int req = neg.get(i).r;
				int cost = neg.get(i).c;
				for(int j=0;j<=s;j++) {
					dp[i][j] = dp[i-1][j];
					if(j>=req) dp[i][j+cost] = Math.max(dp[i][j+cost], dp[i-1][j]+1);						
				}
				for(int j=0;j<=s;j++) if(dp[i][j]>ret) ret = dp[i][j];
			}
			out.println(ret+cnt);
		}
		
		class pair implements Comparable<pair>{
			int r,c;
			public pair(int a, int b) {
				r=a;c=b;
			}
			@Override
			public int compareTo(pair e) {
				if(this.c>=0) {
					if(this.r==e.r) return this.c-e.c;
					return this.r-e.r;
				}else {
					int t1 = e.r+e.c;
					int t2 = this.r+this.c;
					if(t1==t2) return e.r-this.r;
					return t1-t2;
				}
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
			arr[x] = y;
			sz[y] += sz[x];
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