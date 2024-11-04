
import java.io.*;
import java.math.*;
import java.util.*;

import static java.util.Arrays.*;

public class C {
	private static final int mod = (int)1e9+7;

	final Random random = new Random(0);
	final IOFast io = new IOFast();

	

	public void run() throws IOException {




		int TEST_CASE = 1;
		while(TEST_CASE-- != 0) {
			int n = io.nextInt();
			int q = io.nextInt();
			SplayTreeIndex tree = new SplayTreeIndex();
			for(int i = 0; i < n; i++) {
				tree.insert(0, 1);
			}
			
			int len = n;
			for(int i = 0; i < q; i++) {
				int t = io.nextInt();
				if(t == 1) {
					int p = io.nextInt();
					if(p > len / 2) {
						p = len - p;
						tree.reverse(0, len - 1);
					}
					for(int j = p - 1; j >= 0; j--) {
						int v = tree.remove(j);


						tree.add(p - 1, p - 1, v);
					}
					len -= p;
				}
				else {
					int l = io.nextInt();
					int r = io.nextInt();
					io.out.println(tree.sum(l, r - 1));
				}
			}
		}
	}
	
	static
	class SplayTreeIndex {
		Node root;

		static int getCount(Node n) { return n == null ? 0 : n.count; }
		static Node getLeft(Node n) { return n == null ? null : n.getLeft(); }
		static Node getRight(Node n) { return n == null ? null : n.getRight(); }

		

		void insert(int index, int value) {
			insert(index, new Node(value, null));
		}
		void insert(int index, Node insertNode) {
			if(root == null) { root = insertNode; return; }
			final int n = getCount(root);
			if(n < index) throw new RuntimeException();
			final Node add = insertNode;
			if(n == index) {
				Node node = find(n - 1);
				Node.linkRight(add, node);
			}
			else {
				final Node node = find(index);
				final Node nl = Node.cut(node.getLeft());
				Node.linkLeft(nl, add);
				Node.linkRight(node, add);
			}
			root = add.splay();
		}

		

		Node find(Node node, int index) {
			while(node != null) {
				node.pushDown();
				if(getCount(node.getLeft()) > index) { node = node.getLeft(); }
				else if(getCount(node.getLeft()) == index) { return root = node.splay(); }
				else { index -= getCount(node.getLeft()) + 1; node = node.getRight(); }
			}
			return null;
		}

		Node find(int index) {
			return find(root, index);
		}

		

		int remove(final int index) {
			if(index < 0 || getCount(root) <= index) {
				throw new RuntimeException();
			}

			final Node node = find(index);
			final Node nl = Node.cut(node.getLeft());
			final Node nr = Node.cut(node.getRight());

			root = Node.merge(nl, nr);
			
			return node.value;
		}

		final Node[] sep = new Node[3];

		

		Node[] separate(int l, int r) {
			final Node left = Node.cut(getLeft(find(l)));
			final Node mid = find(r - l);
			final Node right = Node.cut(getRight(mid));

			sep[0] = left;
			sep[1] = mid;
			sep[2] = right;

			return sep;
		}
		
		

		Node cut(int i) {
			return Node.cut(getLeft(find(i)));
		}
		
		

		void move(int l, int r, int i) {
			Node left = Node.cut(getLeft(find(l)));
			final Node mid = find(r - l);
			Node right = Node.cut(getRight(mid));
			
			root = Node.merge(left, right);
			if(find(i) == null) {
				left = root;
				root = null;
			}
			else {
				left = Node.cut(getLeft(find(i)));
			}
			root = Node.merge(Node.merge(left, mid), root);
		}

		

		

		void reverse(int l, int r) {
			Node[] sep = separate(l, r);
			sep[1].reverse();
			root = Node.merge(Node.merge(sep[0], sep[1]), sep[2]);
		}

		

		void revolve(int l, int r, int t) {
			rotate(l, r, t % (r - l + 1));
		}

		

		void rotate(int l, int r, int t) {
			if(r - l < t) while(true);
			Node[] sep = separate(l, r);

			Node n = find(sep[1], r - l - t);
			Node nr = Node.cut(getRight(n));
			root = Node.merge(Node.merge(sep[0], nr), Node.merge(n, sep[2]));
		}

		

		int max(int l, int r) {
			Node[] sep = separate(l, r);
			final int res = sep[1].pushDown().max;
			root = Node.merge(Node.merge(sep[0], sep[1]), sep[2]);
			return res;
		}

		

		int min(int l, int r) {
			Node[] sep = separate(l, r);
			final int res = sep[1].pushDown().min;
			root = Node.merge(Node.merge(sep[0], sep[1]), sep[2]);
			return res;
		}

		

		int sum(int l, int r) {
			Node[] sep = separate(l, r);
			final int res = sep[1].pushDown().sum;
			root = Node.merge(Node.merge(sep[0], sep[1]), sep[2]);
			return res;
		}

		

		void add(int l, int r, int val) {
			Node[] sep = separate(l, r);
			sep[1].addSubTree(val);
			root = Node.merge(Node.merge(sep[0], sep[1]), sep[2]);
		}

		
		
		static class Node {
			int value, sum, min, max, count, dval;
			boolean reverse, needPushDown;
			Node left, right, parent;

			void update() {
				count = 1;
				min = max = sum = value;
				if(getLeft() != null) {
					count += left.count;
					sum += left.sum;
					min = Math.min(min, left.min);
					max = Math.max(max, left.max);
				}
				if(getRight() != null) {
					count += right.count;
					sum += right.sum;
					min = Math.min(min, right.min);
					max = Math.max(max, right.max);
				}
				sum += count * dval;
				min += dval;
				max += dval;
			}

			

					

			void reverse() {
				reverse = !reverse;
				needPushDown = true;
			}

			

			void addSubTree(int val) {
				dval += val;
				sum += val * count;
				needPushDown = true;
			}

			

			static void receiveLazyValue(Node n) {
				if(n != null) {
					n.dval += n.parent.dval;
					n.reverse ^= n.parent.reverse;
					n.min += n.parent.dval;
					n.max += n.parent.dval;
					n.sum += n.parent.dval * n.count;
					n.needPushDown = true;
				}
			}

			

			Node pushDown() {
				if(needPushDown) {
					receiveLazyValue(left);
					receiveLazyValue(right);
					value += dval;
					dval = 0;
					if(reverse) {
						final Node n = left;
						left = right;
						right = n;
						reverse = false;
					}
					needPushDown = false;
				}
				return this;
			}

			Node getLeft() { pushDown(); return left; }
			Node getRight() { pushDown(); return right; }

			

			static Node merge(final Node nl, final Node nr) {
				if(nl == null) return nr;
				if(nr == null) return nl;
				nl.splay();
				nr.splay();
				final Node leftMaxNode = nl.maxNode();
				Node.linkRight(nr, leftMaxNode);
				return leftMaxNode;
			}

			

			static void linkLeft(final Node n, final Node p) {
				if(p != null) { p.pushDown(); cut(p.getLeft()); p.left = n; }
				if(n != null) { n.parent = p; }
				if(p != null) { p.update(); }
			}

			

			static void linkRight(final Node n, final Node p) {
				if(p != null) { p.pushDown(); cut(p.getRight()); p.right = n; }
				if(n != null) { n.parent = p; }
				if(p != null) { p.update(); }
			}

			

			static Node cut(final Node n) {
				if(n == null || n.parent == null) { return n; }
				n.parent.pushDown();
				if(n.parent.left == n) {
					n.parent.left = null;
				}
				else {
					n.parent.right = null;
				}
				n.parent.update();
				n.parent = null;
				return n;
			}

			public Node(int value, Node parent) {
				this.value = value;
				this.parent = parent;
				update();
			}

			void rotateRight() {
				final Node x = this;
				final Node p = x.parent;
				final Node g = p.parent;


				p.pushDown();
				x.pushDown();
				p.left = x.right;
				if(x.right != null) { x.right.parent = p; }
				p.parent = x;
				x.right = p;
				x.parent = g;
				p.update();
				x.update();
				if(g != null) {
					if(g.left == p) g.left = x;
					else if(g.right == p) g.right = x;


				}
			}

			void rotateLeft() {
				final Node x = this;
				final Node p = x.parent;
				final Node g = p.parent;


				p.pushDown();
				x.pushDown();
				p.right = x.left;
				if(x.left != null) { x.left.parent = p; }
				p.parent = x;
				x.left = p;
				x.parent = g;
				p.update();
				x.update();
				if(g != null) {
					if(g.left == p) g.left = x;
					else if(g.right == p) g.right = x;


				}
			}

			public Node splay() {
				final Node x = this;
				while(x.parent != null) {
					final Node p = x.parent;
					if(p.parent == null) {
						

						if(p.getLeft() == x) { x.rotateRight(); }
						else { x.rotateLeft(); }
					}
					else {
						final Node g = p.parent;
						

						if(g.getLeft() == p) {
							if(p.getLeft() == x) { p.rotateRight(); x.rotateRight(); }
							else { x.rotateLeft(); x.rotateRight(); }
						}
						else {
							if(p.getLeft() == x) { x.rotateRight(); x.rotateLeft(); }
							else { p.rotateLeft(); x.rotateLeft(); }
						}
					}
				}
				return x;
			}

			Node maxNode() {
				Node n = this;
				while(true) {
					n.pushDown();
					if(n.right == null) break;
					n = n.right;
				}
				return n.splay();
			}

			Node minNode() {
				Node n = this;
				while(true) {
					n.pushDown();
					if(n.left == null) break;
					n = n.left;
				}
				return n.splay();
			}
		}
	}

	
	static
	class UnionFind {
		private int[] data;
		
		public UnionFind(int size) {
			data = new int[size];
			clear();
		}
		
		public UnionFind(final UnionFind uf) {
			data = uf.data.clone();
		}
		
		public void clear() {
			Arrays.fill(data, -1);
		}
		
		public int root(int x) { return data[x] < 0 ? x : (data[x] = root(data[x])); }
		
		public void union(int x, int y) {
			if((x = root(x)) != (y = root(y))) {
				if(data[y] < data[x]) { final int t = x; x = y; y = t; }
				data[x] += data[y];
				data[y] = x;
			}
		}
		
		public boolean same(int x, int y) { return root(x) == root(y); }
		public int size(int x) { return -data[root(x)]; }
	}

	
	static
	class SimpleAdjListGraph {
		int m, V, E;
		int[] head, next, to;
		
		static SimpleAdjListGraph read(final IOFast io) throws IOException {
			int n = io.nextInt();
			int m = io.nextInt();
			SimpleAdjListGraph g = new SimpleAdjListGraph(n, 2 * m);
			for(int i = 0; i < m; i++) {
				final int s = io.nextInt() - 0;
				final int t = io.nextInt() - 0;
				g.addEdge(s, t);
				g.addEdge(t, s);
			}
			return g;
		}

		public SimpleAdjListGraph(int V, int E) {
			head = new int[V];
			next = new int[E];
			to = new int[E];
			this.V = V;
			this.E = E;
			clear();
		}

		public void clear() {
			m = 0;
			Arrays.fill(head, -1);
		}

		public void removeEdge(int s) {
			--m;
			head[s] = next[m];
		}

		public void addEdge(int s, int t) {
			next[m] = head[s];
			head[s] = m;
			to[m++] = t;
		}
		
		int farthestVertex(final int[] dist) {
			int ret = 0;
			for(int i = 0; i < dist.length; i++) {
				if(dist[ret] < dist[i]) {
					ret = i;
				}
			}
			return ret;
		}
		
		
		int farthest(int[] dist) {
			bfs(dist, 0);
			final int v0 = farthestVertex(dist);
			bfs(dist, v0);




			return dist[farthestVertex(dist)];
		}

		int[] q;
		public int bfs(final int[] dist, final int src) {
			if(q == null) {
				q = new int[2 * head.length + 10];
			}
			int s = 0, t = 0;
			
			Arrays.fill(dist, -1);
			dist[src] = 0;
			q[t++] = src;
			while(s != t) {
				final int v = q[s++];
				for(int e = head[v]; e != -1; e = next[e]) {
					final int u = to[e];
					if(dist[u] == -1) {
						dist[u] = dist[v] + 1;
						q[t++] = u;
					}
				}
			}
			int ret = 0;
			for(int a : dist) ret = Math.max(ret, a);
			return ret;
		}
	}


	

	static int gcd(int n, int r) { return r == 0 ? n : gcd(r, n%r); }
	static long gcd(long n, long r) { return r == 0 ? n : gcd(r, n%r); }
	
	static <T> void swap(T[] x, int i, int j) {
		T t = x[i];
		x[i] = x[j];
		x[j] = t;
	}
	
	static void swap(int[] x, int i, int j) {
		int t = x[i];
		x[i] = x[j];
		x[j] = t;
	}
	

	static void radixSort(int[] xs) {
		int[] cnt = new int[(1<<16)+1];
		int[] ys = new int[xs.length];
		
		for(int j = 0; j <= 16; j += 16) {
			Arrays.fill(cnt, 0);
			for(int x : xs) { cnt[(x>>j&0xFFFF)+1]++; }
			for(int i = 1; i < cnt.length; i++) { cnt[i] += cnt[i-1]; }
			for(int x : xs) { ys[cnt[x>>j&0xFFFF]++] = x; }
			{ final int[] t = xs; xs = ys; ys = t; }
		}
	}
	
	static void radixSort(long[] xs) {
		int[] cnt = new int[(1<<16)+1];
		long[] ys = new long[xs.length];
		
		for(int j = 0; j <= 48; j += 16) {
			Arrays.fill(cnt, 0);
			for(long x : xs) { cnt[(int)(x>>j&0xFFFF)+1]++; }
			for(int i = 1; i < cnt.length; i++) { cnt[i] += cnt[i-1]; }
			for(long x : xs) { ys[cnt[(int)(x>>j&0xFFFF)]++] = x; }
			{ final long[] t = xs; xs = ys; ys = t; }
		}
	}
	

	static void arrayIntSort(int[][] x, int... keys) {
		Arrays.sort(x, new ArrayIntsComparator(keys));
	}
	
	static class ArrayIntsComparator implements Comparator<int[]> {
		final int[] KEY;
		
		public ArrayIntsComparator(int... key) {
			KEY = key;
		}
		
		@Override
		public int compare(int[] o1, int[] o2) {
			for(int k : KEY) if(o1[k] != o2[k]) return o1[k] - o2[k];
			return 0;
		}
	}
	
	static class ArrayIntComparator implements Comparator<int[]> {
		final int KEY;
		
		public ArrayIntComparator(int key) {
			KEY = key;
		}
		
		@Override
		public int compare(int[] o1, int[] o2) {
			return o1[KEY] - o2[KEY];
		}
	}
	
	
	void main() throws IOException {
		

		try {
			run();
		}
		catch (EndOfFileRuntimeException e) { }
		io.out.flush();
	}

	public static void main(String[] args) throws IOException {
		new C().main();
	}
	
	static class EndOfFileRuntimeException extends RuntimeException {
		private static final long serialVersionUID = -8565341110209207657L; }

	static
	public class IOFast {
		private BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		private PrintWriter out = new PrintWriter(System.out);

		void setFileIO(String ins, String outs) throws IOException {
			out.flush();
			out.close();
			in.close();
			in = new BufferedReader(new FileReader(ins));
			out = new PrintWriter(new FileWriter(outs));
			System.err.println("reading from " + ins);
		}

		

		private static int pos, readLen;
		private static final char[] buffer = new char[1024 * 8];
		private static char[] str = new char[500*8*2];
		private static boolean[] isDigit = new boolean[256];
		private static boolean[] isSpace = new boolean[256];
		private static boolean[] isLineSep = new boolean[256];

		static {
			for(int i = 0; i < 10; i++) { isDigit['0' + i] = true; }
			isDigit['-'] = true;
			isSpace[' '] = isSpace['\r'] = isSpace['\n'] = isSpace['\t'] = true;
			isLineSep['\r'] = isLineSep['\n'] = true;
		}

		public int read() throws IOException {
			if(pos >= readLen) {
				pos = 0;
				readLen = in.read(buffer);
				if(readLen <= 0) { throw new EndOfFileRuntimeException(); }
			}
			return buffer[pos++];
		}

		public int nextInt() throws IOException {
			return Integer.parseInt(nextString());
		}

		public long nextLong() throws IOException {
			return Long.parseLong(nextString());
		}

		public char nextChar() throws IOException {
			while(true) {
				final int c = read();
				if(!isSpace[c]) { return (char)c; }
			}
		}
		
		int reads(int len, boolean[] accept) throws IOException {
			try {
				while(true) {
					final int c = read();
					if(accept[c]) { break; }
					
					if(str.length == len) {
						char[] rep = new char[str.length * 3 / 2];
						System.arraycopy(str, 0, rep, 0, str.length);
						str = rep;
					}
					
					str[len++] = (char)c;
				}
			}
			catch(EndOfFileRuntimeException e) { ; }
			
			return len;
		}
		
		int reads(char[] cs, int len, boolean[] accept) throws IOException {
			try {
				while(true) {
					final int c = read();
					if(accept[c]) { break; }
					cs[len++] = (char)c;
				}
			}
			catch(EndOfFileRuntimeException e) { ; }
			
			return len;
		}

		public char[] nextLine() throws IOException {
			int len = 0;
			str[len++] = nextChar();
			len = reads(len, isLineSep);
			
			try {
				if(str[len-1] == '\r') { len--; read(); }
			}
			catch(EndOfFileRuntimeException e) { ; }
			
			return Arrays.copyOf(str, len);
		}

		public String nextString() throws IOException {
			return new String(next());
		}

		public char[] next() throws IOException {
			int len = 0;
			str[len++] = nextChar();
			len = reads(len, isSpace);
			return Arrays.copyOf(str, len);
		}

		public int next(char[] cs) throws IOException {
			int len = 0;
			cs[len++] = nextChar();
			len = reads(cs, len, isSpace);
			return len;
		}

		public double nextDouble() throws IOException {
			return Double.parseDouble(nextString());
		}

		public long[] nextLongArray(final int n) throws IOException {
			final long[] res = new long[n];
			for(int i = 0; i < n; i++) {
				res[i] = nextLong();
			}
			return res;
		}

		public int[] nextIntArray(final int n) throws IOException {
			final int[] res = new int[n];
			for(int i = 0; i < n; i++) {
				res[i] = nextInt();
			}
			return res;
		}

		public int[][] nextIntArray2D(final int n, final int k) throws IOException {
			final int[][] res = new int[n][];
			for(int i = 0; i < n; i++) {
				res[i] = nextIntArray(k);
			}
			return res;
		}

		public int[][] nextIntArray2DWithIndex(final int n, final int k) throws IOException {
			final int[][] res = new int[n][k+1];
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < k; j++) {
					res[i][j] = nextInt();
				}
				res[i][k] = i;
			}
			return res;
		}

		public double[] nextDoubleArray(final int n) throws IOException {
			final double[] res = new double[n];
			for(int i = 0; i < n; i++) {
				res[i] = nextDouble();
			}
			return res;
		}

	}

}
