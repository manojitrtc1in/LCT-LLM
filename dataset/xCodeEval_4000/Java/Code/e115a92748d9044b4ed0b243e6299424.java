import java.io.*;
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
			long arr[][][] = new long[n+1][4][4];
			for(int i=1;i<=n;i++) {
				arr[i] = new long[4][4];
			}
			for(int i=1;i<=n;i++) {
				int num = in.nextInt();
				long a1=0; long a2=0; long a3=0;
				long b1=0; long c1=0;
				for(int j=0;j<num;j++) {
					long c = in.nextLong();
					long d = in.nextLong();
					if(c==1) {
						if(d>=a1) {
							a3=a2;
							a2=a1;
							a1=d;
						}else if(d>=a2) {
							a3=a2;
							a2=d;
						}else if(d>=a3) {
							a3=d;
						}
					}else if(c==2) {
						b1 = Math.max(b1, d);
					}else {
						c1 = Math.max(c1, d);
					}
				}
				arr[i][1][1] = a1;
				arr[i][1][2] = a2;
				arr[i][1][3] = a3;
				arr[i][2][1] = b1;
				arr[i][3][1] = c1;
			}
			long dp[][] = new long[n+1][11];
			for(int i=0;i<=n;i++) Arrays.fill(dp[i], -1);
			dp[0][0] = 0;
			long ret = 0;
			for(int i=1;i<=n;i++) {
				for(int k=1;k<=10;k++) {			
					for(int p=0;p<=3;p++) {
						long damage = -1;
						int kk=k;
						if(p>kk) kk+=10;
						if(p==0) {
							damage = 0;
						}else if(p==1) {
							damage = Math.max(arr[i][1][1], Math.max(arr[i][2][1], arr[i][3][1]));
							if(kk>=10) damage*=2;
						}else if(p==2&&arr[i][1][1]>0&&(arr[i][1][2]>0||arr[i][2][1]>0)) {
							if(kk>=10) {
								long tmp = Math.max(arr[i][1][2], arr[i][2][1]);
								if(arr[i][1][1]>tmp) {
									damage = 2*arr[i][1][1]+tmp;
								}else {
									damage = arr[i][1][1]+2*tmp;
								}
							}else {
								damage = arr[i][1][1]+Math.max(arr[i][1][2], arr[i][2][1]);
							}
						}else if(p==3&&arr[i][1][3]>0){
							if(kk>=10) {
								damage = 2*arr[i][1][1]+arr[i][1][2]+arr[i][1][3];
							}else {
								damage = arr[i][1][1]+arr[i][1][2]+arr[i][1][3];
							}
						}
						if(damage==-1) break;
						long max = -1;
						for(int q=i-1;q>=Math.max(0, i-10);q--) {
							max = Math.max(dp[q][(kk-p)%10], max);
							if(max==-1) continue;
							dp[i][kk%10] = Math.max(dp[i][kk%10], damage+max);
							if(dp[i][kk%10]>ret) ret = dp[i][kk%10];							
						}
					}
				}
			}
			out.println(ret);
		}
		class pair implements Comparable<pair>{
			int cost; int damage; int idx; 
			int original_damage; int original_cost;
			public pair(int a, int b, int c) {
				original_cost = a;
				original_damage = b;
				cost = 6;
				idx = c;
				damage = 6/original_cost*b;
			}
			@Override
			public int compareTo(pair t) {				
				return t.damage-this.damage;
			}			
		}		
		int gcd(int a, int b) {
			if(b==0) return a;
			else return gcd(b,a%b);
		}
	    public int longestDecomposition(String text) {
	        char arr[] = text.toCharArray();
	        int n = arr.length;
	        int ret = 0;
	        int p = 0; int q = n-1;
	        while(p<q) {
	        	boolean find = false;
	        	for(int i=p;i<=p+(q-p)/2;i++) {
	        		int j=i; int k=q;
	        		boolean ok = true;
	        		while(j>=p) {
	        			if(arr[j--]!=arr[k--]) {
	        				ok = false;
	        				break;
	        			}  			
	        		}
	        		if(ok) {
	        			ret+=2;
	        			q-=i+1-p;
	        			p=i+1;	 
	        			find = true;
	        			break;
	        		}
	        	}
	        	if(!find) break;
	        }
	        if(p<=q) ret++;
	        return ret;
	    }
		boolean is_prime(int a) {
			if(a==2||a==3) return true;
			for(int i=2;i<=Math.sqrt(a);i++) {
				if(a%i==0) return false;
			}
			return true;
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
        private int zcurChar;
        private int znumChars;
        private SpaceCharFilter filter;
 
        public InputReader(InputStream stream)
        {
            this.stream = stream;
        }
 
        public int read()
        {
            if (znumChars == -1)
                throw new InputMismatchException();
            if (zcurChar >= znumChars)
            {
            	zcurChar = 0;
                try
                {
                    znumChars = stream.read(buf);
                } catch (IOException e)
                {
                    throw new InputMismatchException();
                }
                if (znumChars <= 0)
                    return -1;
            }
            return buf[zcurChar++];
        }
 
        public int nextInt()
        {
            int c = read();
            while (isSpaceChar(c))
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
            } while (!isSpaceChar(c));
            return res * sgn;
        }
 
        public String nextString()
        {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            StringBuilder res = new StringBuilder();
            do
            {
                res.appendCodePoint(c);
                c = read();
            } while (!isSpaceChar(c));
            return res.toString();
        }
 
        public double nextDouble()
        {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            int sgn = 1;
            if (c == '-')
            {
                sgn = -1;
                c = read();
            }
            double res = 0;
            while (!isSpaceChar(c) && c != '.')
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
                while (!isSpaceChar(c))
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
            while (isSpaceChar(c))
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
            } while (!isSpaceChar(c));
            return res * sgn;
        }
 
        public boolean isSpaceChar(int c)
        {
            if (filter != null)
                return filter.isSpaceChar(c);
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }
 
        public String next()
        {
            return nextString();
        }
 
        public interface SpaceCharFilter
        {
            public boolean isSpaceChar(int ch);
        }
        public int[] readIntArray(int n) {
            int[] ret = new int[n];
            for (int i = 0; i < n; i++) {
                ret[i] = nextInt();
            }
            return ret;
        }        
    }    
 
	static class Dumper {
		static void print_int_arr(int[] arr) {
			for (int i = 0; i < arr.length; i++) {
				System.out.print(arr[i] + " ");
			}
			System.out.println();
			System.out.println("---------------------");
		}
 
		static void print_char_arr(char[] arr) {
			for (int i = 0; i < arr.length; i++) {
				System.out.print(arr[i] + " ");
			}
			System.out.println();
			System.out.println("---------------------");
		}
 
		static void print_double_arr(double[] arr) {
			for (int i = 0; i < arr.length; i++) {
				System.out.print(arr[i] + " ");
			}
			System.out.println();
			System.out.println("---------------------");
		}
 
		static void print_2d_arr(int[][] arr, int x, int y) {
			for (int i = 0; i < x; i++) {
				for (int j = 0; j < y; j++) {
					System.out.print(arr[i][j] + " ");
				}
				System.out.println();
			}
			System.out.println();
			System.out.println("---------------------");
		}
 
		static void print_2d_arr(boolean[][] arr, int x, int y) {
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