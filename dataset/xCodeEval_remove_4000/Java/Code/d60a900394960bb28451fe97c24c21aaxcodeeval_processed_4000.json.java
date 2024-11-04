
import java.io.*;
import java.math.*;
import java.util.*;

import static java.util.Arrays.*;

public class C {
	private static final int mod = (int)1e9+7;

	final Random random = new Random(0);
	final IOFast io = new IOFast();

	

	void check() {
		{
			long t1 = System.currentTimeMillis();
			int x = 0, y = 1;
			for(int i = 0; i < 1000000000; i++) {
				int t = x;
				x = y;
				y += t;
			}
			System.err.println((System.currentTimeMillis() - t1) + " " + x + " " + y);
		}
		{
			long t1 = System.currentTimeMillis();
			Integer x = 0, y = 1;
			for(int i = 0; i < 1000000000; i++) {
				Integer t = x;
				x = y;
				y += t;
			}
			System.err.println((System.currentTimeMillis() - t1) + " " + x + " " + y);
		}
	}
	
	id2 union(id2... gs) {
		int V = 0;
		int E = 2;
		for(id2 gg : gs) {
			V += gg.V;
			E += gg.E;
		}
		id2 g = new id2(V, E);
		int v0 = 0;
		for(id2 gg : gs) {
			for(int v = 0; v < gg.V; v++) {
				for(int e = gg.head[v]; e != -1; e = gg.next[e]) {
					g.addEdge(v + v0, gg.to[e] + v0);
				}
			}
			v0 += gg.V;
		}
		return g;
	}
	
	public void run() throws IOException {




		int TEST_CASE = 1;
		while(TEST_CASE-- != 0) {
			int n = io.nextInt();
			int m = io.nextInt();
			int q = io.nextInt();
			int[][] es = new int[m][3];
			UnionFind uf = new UnionFind(n);
			for(int i = 0; i < m; i++) {
				int s = io.nextInt() - 1;
				int t = io.nextInt() - 1;
				es[i][0] = s;
				es[i][1] = t;
				uf.union(s, t);
			}
			for(int i = 0; i < m; i++) {
				es[i][2] = uf.root(es[i][0]);
			}
			id4(es, 2);
			TreeMap<Integer, long[]> mp = new TreeMap<>();
			for(int i = 0, j; i < m; i = j) {
				int id = 0;
				TreeMap<Integer, Integer> mp2 = new TreeMap<>();
				for(j = i; j < m && es[i][2] == es[j][2]; j++) {
					if(!mp2.containsKey(es[j][0])) mp2.put(es[j][0], id++);
					if(!mp2.containsKey(es[j][1])) mp2.put(es[j][1], id++);
				}
				id2 g = new id2(id, (j - i) * 2);
				for(j = i; j < m && es[i][2] == es[j][2]; j++) {
					g.addEdge(mp2.get(es[j][0]), mp2.get(es[j][1]));
					g.addEdge(mp2.get(es[j][1]), mp2.get(es[j][0]));
				}
				int[] d1 = new int[g.V];
				int[] d2 = new int[g.V];
				int f = g.id10(d1);
				g.bfs(d2, g.id1(d1));
				long dis = Long.MAX_VALUE;
				for(int k = 0; k < g.V; k++) {
					if(Math.max(d1[k], d2[k]) < dis) {
						dis = Math.max(d1[k], d2[k]);
					}
				}






				mp.put(es[i][2], new long[] { dis, f });
			}
			for(int i = 0; i < n; i++) {
				if(uf.size(i) == 1) {
					mp.put(i, new long[] { 0, 0, });
				}
			}
			
			for(int i = 0; i < q; i++) {
				int t = io.nextInt();
				if(t == 1) {
					int x = io.nextInt() - 1;
					io.out.println(mp.get(uf.root(x))[1]);
				}
				else {
					int x = io.nextInt() - 1;
					int y = io.nextInt() - 1;
					if(!uf.same(x, y)) {
						long[] g1 = mp.get(uf.root(x));
						long[] g2 = mp.get(uf.root(y));
						uf.union(x, y);
						long n1 = g1[0];
						long f1 = g1[1];
						long n2 = g2[0];
						long f2 = g2[1];
						g1[0] = Math.min(Math.max(n1, n2 + 1), Math.max(n2, n1 + 1));
						g1[1] = Math.max(f1, Math.max(f2, n1 + n2 + 1));
						mp.put(uf.root(x), g1);


					}
				}
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
	class id2 {
		int m, V, E;
		int[] head, next, to;
		
		static id2 read(final IOFast io) throws IOException {
			int n = io.nextInt();
			int m = io.nextInt();
			id2 g = new id2(n, 2 * m);
			for(int i = 0; i < m; i++) {
				final int s = io.nextInt() - 0;
				final int t = io.nextInt() - 0;
				g.addEdge(s, t);
				g.addEdge(t, s);
			}
			return g;
		}

		public id2(int V, int E) {
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
		
		int id1(final int[] dist) {
			int ret = 0;
			for(int i = 0; i < dist.length; i++) {
				if(dist[ret] < dist[i]) {
					ret = i;
				}
			}
			return ret;
		}
		
		
		int id10(int[] dist) {
			bfs(dist, 0);
			final int v0 = id1(dist);
			bfs(dist, v0);




			return dist[id1(dist)];
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
	

	static void id13(int[] xs) {
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
	
	static void id13(long[] xs) {
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
	

	static void id4(int[][] x, int... keys) {
		Arrays.sort(x, new id15(keys));
	}
	
	static class id15 implements Comparator<int[]> {
		final int[] KEY;
		
		public id15(int... key) {
			KEY = key;
		}
		
		@Override
		public int compare(int[] o1, int[] o2) {
			for(int k : KEY) if(o1[k] != o2[k]) return o1[k] - o2[k];
			return 0;
		}
	}
	
	static class id11 implements Comparator<int[]> {
		final int KEY;
		
		public id11(int key) {
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
		catch (id3 e) { }
		io.out.flush();
	}

	public static void main(String[] args) throws IOException {
		new C().main();
	}
	
	static class id3 extends RuntimeException {
		private static final long id9 = -8565341110209207657L; }

	static
	public class IOFast {
		private BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		private PrintWriter out = new PrintWriter(System.out);

		void id7(String ins, String outs) throws IOException {
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
		private static boolean[] id0 = new boolean[256];

		static {
			for(int i = 0; i < 10; i++) { isDigit['0' + i] = true; }
			isDigit['-'] = true;
			isSpace[' '] = isSpace['\r'] = isSpace['\n'] = isSpace['\t'] = true;
			id0['\r'] = id0['\n'] = true;
		}

		public int read() throws IOException {
			if(pos >= readLen) {
				pos = 0;
				readLen = in.read(buffer);
				if(readLen <= 0) { throw new id3(); }
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
			catch(id3 e) { ; }
			
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
			catch(id3 e) { ; }
			
			return len;
		}

		public char[] nextLine() throws IOException {
			int len = 0;
			str[len++] = nextChar();
			len = reads(len, id0);
			
			try {
				if(str[len-1] == '\r') { len--; read(); }
			}
			catch(id3 e) { ; }
			
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

		public long[] id14(final int n) throws IOException {
			final long[] res = new long[n];
			for(int i = 0; i < n; i++) {
				res[i] = nextLong();
			}
			return res;
		}

		public int[] id5(final int n) throws IOException {
			final int[] res = new int[n];
			for(int i = 0; i < n; i++) {
				res[i] = nextInt();
			}
			return res;
		}

		public int[][] id6(final int n, final int k) throws IOException {
			final int[][] res = new int[n][];
			for(int i = 0; i < n; i++) {
				res[i] = id5(k);
			}
			return res;
		}

		public int[][] id8(final int n, final int k) throws IOException {
			final int[][] res = new int[n][k+1];
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < k; j++) {
					res[i][j] = nextInt();
				}
				res[i][k] = i;
			}
			return res;
		}

		public double[] id12(final int n) throws IOException {
			final double[] res = new double[n];
			for(int i = 0; i < n; i++) {
				res[i] = nextDouble();
			}
			return res;
		}

	}

}
