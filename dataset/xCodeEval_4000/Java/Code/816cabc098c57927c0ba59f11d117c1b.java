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
			int arr[] = new int[n];
			for(int i=0;i<n;i++) arr[i] = in.nextInt();
			int seg[][] = new int[m][2];
			for(int i=0;i<m;i++) {
				seg[i][0] = in.nextInt()-1;
				seg[i][1] = in.nextInt()-1;
			}
			ArrayList<Integer> ret = new ArrayList<Integer>();
			int max = 0;
			for(int i=0;i<n;i++) {
				for(int j=0;j<n;j++) {
					if(i==j) continue;
					ArrayList<Integer> tmp = new ArrayList<Integer>();					
					int a = arr[i]; int b = arr[j];
					for(int k=0;k<m;k++) {
						if(i>=seg[k][0]&&i<=seg[k][1]) {
							if(j<seg[k][0]||j>seg[k][1]) {
								a--;
								tmp.add(k);
							}
						}
					}
					if(b-a>max) {
						max = b-a;
						ret = new ArrayList<Integer>(tmp);
					}
				}
			}
			out.println(max);
			out.println(ret.size());
			for(int i=0;i<ret.size();i++) {
				if(i!=0) out.print(" ");
				out.print(ret.get(i)+1);
			}
			out.println();
		}

	    public int[] movesToStamp(String stamp, String target) {
	    	int n = stamp.length();
	    	int m = target.length();
	    	char[] s = stamp.toCharArray();
	    	char[] t = target.toCharArray();
	    	ArrayList<Integer> part1 = new ArrayList<Integer>();
	    	ArrayList<Integer> part2 = new ArrayList<Integer>();
	    	ArrayList<Integer> part3 = new ArrayList<Integer>();
	    	int p = target.indexOf(stamp);
            if(p==-1) return new int[] {};
            part1.add(p);
	    	update(t,p,p+stamp.length());
	    	while(true) {
	    		int x = target.indexOf(stamp,p+stamp.length());	    		
	    		if(x==-1) break;
	    		update(t,x,x+stamp.length());
	    		part1.add(0,x);
	    		p=x;
	    	}	    
	    	
	    	TreeSet<Integer> todo = new TreeSet<Integer>(Collections.reverseOrder());
	    	for(int i=0;i<m;i++) if(t[i]!='*') todo.add(i);
	    	
	    	while(true) {
	    		int temp = -1;
	    		for(int i:todo) {
	    			if(i+1<m&&t[i+1]=='*') {
	    				temp = i;
	    				int tmp = stamp.indexOf(t[i]);
	    				if(i-tmp<0) return new int[] {};
	    				part2.add(i-tmp);	    			
	    				t[i]='*';
	    				break;
	    			}
	    		}
	    		if(temp==-1) break;
	    		else todo.remove(temp);
	    	}
	    	
	    	while(!todo.isEmpty()) {
	    		int l = 0; int end = 0;
	    		for(int i:todo) {
	    			end=i;
	    			l = backmatch(s,t,i);
	    			part3.add(i-n+1);	    			
	    			update(t,i-l+1,i);
	    			break;
	    		}
	    		if(l==0) return new int[] {};
	    		else {
	    			for(int j=end-l+1;j<=end;j++)
	    				todo.remove(j);    		
	    		}
	    	}	    	
	    	int[] ret = new int[part1.size()+part2.size()+part3.size()];	
	    	int c=0;
	    	for(int i:part3) {
	    		ret[c++] = i;
	    	}
	    	for(int i:part2) {
	    		ret[c++] = i;
	    	}
	    	for(int i:part1) {
	    		ret[c++] = i;
	    	}	    	
	    	return ret;
	    }
	    public int backmatch(char s[], char t[], int idx) {
	    	int q = s.length-1;
	    	int c = 0;
	    	while(q>0&&idx>0&&s[q]==t[idx]) {
	    		q--;idx--;c++;
	    	}
	    	return c;
	    }
	    public void update(char[] arr, int s, int l) {
	    	for(int i=s;i<l;i++) arr[i] = '*';
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