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
		class DSU{
			int p[];
			int sz[];
			public DSU(int n) {
				p = new int[n];
				sz = new int[n];
				for(int i=0;i<n;i++) p[i] = i;
				Arrays.fill(sz, 1);
			}
			public void union(int a, int b) {
				int aa = find(a);
				int bb = find(b);
				p[aa] = bb;
				sz[bb]+=sz[aa];				
			}
			public int find(int a) {
				if(p[a]!=a) p[a] = find(p[a]);
				return p[a];
			}
			public int size(int a) {
				return sz[find(a)];
			}
		}
		class item implements Comparable<item>{
			int[] arr;
			ArrayList<Integer> tmp;
			int sz;
			public item() {
				sz = 0;
				tmp = new ArrayList<Integer>();
			}
			public void add(int a) {
				tmp.add(-a);sz++;
			}
			public void sort() {
				Collections.sort(tmp);
				arr = new int[sz];				
				for(int i=0;i<sz;i++) {
					arr[i] = tmp.get(i)*(-1);
					if(i>0) arr[i]+=arr[i-1];
				}
				tmp.clear();
			}
			public int get(int idx) {
				if(idx>=sz||arr[idx]<0) return 0;
				return arr[idx];
			}
			@Override
			public int compareTo(item t) {				
				return t.sz-this.sz;
			}			
		}
		
		class pair implements Comparable<pair>{
			int a; int b;
			public pair(int i, int j) {
				a=i;b=j;
			}
			@Override
			public int compareTo(pair t) {
				if(this.b==t.b) return this.a-t.a;
				else return this.b-t.b;
			}
		}
		public void solve(InputReader in, PrintWriter out) throws IOException {
































































































































			int n = in.nextInt();
			int k = in.nextInt();
			int arr[] = new int[n];
			for(int i=0;i<n;i++) arr[i] = in.nextInt();
			int l[] = new int[n];
			int r[] = new int[n];
			Arrays.fill(l, -1);
			Arrays.fill(r, -1);
			for(int i=0;i<n;i++) {
				if(arr[i]==1) l[i]=i;
				else if(i>0&&l[i-1]>i-k) l[i] = l[i-1];
			}
			Deque<Integer> tmp = new LinkedList<Integer>();			
			for(int i=n-1;i>=0;i--) {
				if(arr[i]==1) tmp.add(i);
				while(!tmp.isEmpty()&&tmp.peek()>=i+k) {
					tmp.removeFirst();
				}
				if(!tmp.isEmpty()) r[i] = tmp.peek();				
			}
			int p=0;
			int ret=0;
			boolean vis[] = new boolean[n];
			while(p<n) {
				if(r[p]!=-1) {
					ret++;
					vis[r[p]]=true;
					p = r[p]+k;
				}else if(l[p]!=-1) {
					if(!vis[l[p]]) {
						ret++;
						vis[l[p]] = true;										
					}
					p = l[p]+k;	
				}else {
					out.println(-1);
					return;
				}
			}
			out.println(ret);
			

			

			
		}
		class node{
			int id;
			int v;
			Set<Integer> sons;
			int parent;
			public node(int a, int b) {
				id=a; v=b;parent = -1;
				sons = new HashSet<Integer>();
			}
			public void add(int a) {
				sons.add(a);
			}
			public void add_p(int a) {
				parent = a;
			}
		}
	
	    public int[] movesToStamp(String stamp, String target) {
	    	int n = stamp.length();
	    	int m = target.length();
	    	char[] s = stamp.toCharArray();
	    	char[] t = target.toCharArray();
	    	ArrayList<Integer> pos = new ArrayList<Integer>();
	    	int p = target.indexOf(stamp);
	    	if(p==-1) return new int[] {};
	    	pos.add(p);
	    	update(t,p,p+stamp.length());
	    	while(true) {
	    		int x = target.indexOf(stamp,p+stamp.length());	    		
	    		if(x==-1) break;
	    		update(t,x,x+stamp.length());
	    		pos.add(x);
	    		p=x;
	    	}	    
	    	
	    	Set<Integer> todo = new HashSet<Integer>();
	    	for(int i=0;i<m;i++) if(t[i]!='*') todo.add(i);
	    	
	    	while(true) {
	    		int temp = -1;
	    		for(int i:todo) {
	    			if(i+1<m&&t[i+1]=='*') {
	    				temp = i;
	    				int tmp = stamp.indexOf(t[i]);
	    				pos.add(i-tmp);	    			
	    				t[i]='*';
	    				break;
	    			}
	    		}
	    		if(temp==-1) break;
	    		else todo.remove(temp);
	    	}
	    	while(!todo.isEmpty()) {
	    		int temp = -1;
	    		for(int i:todo) {
	    			temp = i;
	    			int tmp = stamp.lastIndexOf(t[i]);
	    			pos.add(i-tmp);
	    			t[i]='*';
	    			break;
	    		}
	    		if(temp==-1) break;
	    		else todo.remove(temp);
	    	}	    	
	    	int[] ret = new int[pos.size()];
	    	for(int i=pos.size()-1;i>=0;i--) {
	    		

	    		ret[pos.size()-1-i] = pos.get(i);
	    	}
	    	return ret;
	    }
	    public void update(char[] arr, int s, int l) {
	    	for(int i=s;i<l;i++) arr[i] = '*';
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
