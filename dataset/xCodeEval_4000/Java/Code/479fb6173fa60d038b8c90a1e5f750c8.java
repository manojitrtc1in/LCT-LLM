import java.io.*;
import java.util.*;

public class tr0 {
	static PrintWriter out;
	static StringBuilder sb;
	static long mod = 1000000007;
	static long[] fac;
	static int []si;
	static ArrayList<Integer> primes;
	static HashMap<Integer,Integer> factors;
	static HashSet<Integer> [] divisors;
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		out = new PrintWriter(System.out);
	    int n=sc.nextInt();
	    char [][]grid=new char[n][n];
	    boolean [][]ch=new boolean [n][n];
	    for(int i=0;i<n;i++)
	    	grid[i]=sc.nextLine().toCharArray();
	    for(int i=0;i<n;i++) {
	    	for(int j=0;j<n;j++) {
	    		if(grid[i][j]=='.' && valid(i,j,n) &&  valid(i+1,j,n) && grid[i+1][j]=='.' && valid(i-1,j,n) && grid[i-1][j]=='.'   && valid(i,j+1,n) &&  grid[i][j+1]=='.' && valid(i,j-1,n) && grid[i][j-1]=='.'  && !ch[i][j] && !ch[i+1][j] && !ch[i-1][j] && !ch[i][j+1] && !ch[i][j-1]              ) {
                        ch[i][j]=true;
                        ch[i+1][j]=true;
                        ch[i-1][j]=true;
                        ch[i][j+1]=true;
                        ch[i][j-1]=true;
	    		}
	    		else if(grid[i][j]=='#')
	    			ch[i][j]=true;
	    	}
	    }
	    for(int i=0;i<n;i++) {
	    	for(int j=0;j<n;j++) {
	    	 	if(!ch[i][j]) {
	    	 		System.out.println("NO");
	    	 		return;
	    	 	}
	    	}
	    }
	    out.println("YES");
		out.flush();
	}
	static boolean valid(int x,int y,int n) {
		return x>=0 && x<n && y>=0 && y<n;
	}
   static void factor(int n) {
	   if(si[n]==n) {
		   factors.put(n, factors.getOrDefault(n, 0)+1);
		   return;
	   }
	   factors.put(si[n], factors.getOrDefault(si[n], 0)+1);
	 
	   factor(n/si[(int)n]);
   }
   static void findFactors(int idx,int[] primeDivisors, int[] multiplicity, int currentDivisor, int currentResult) {
	    if (currentDivisor == primeDivisors.length) {
	        divisors[idx].add(currentResult);
	        return;
	    }
	    

	    

	    for (int i = 0; i <= multiplicity[currentDivisor]; ++i) {
	        findFactors(idx,primeDivisors, multiplicity, currentDivisor + 1, currentResult);
	        currentResult *= primeDivisors[currentDivisor];
	    }
	}
 	static long inver(long x) {
		int a = (int) x;
		long e = (mod - 2);
		long res = 1;
		while (e > 0) {
			if ((e & 1) == 1) {
				

				res = (int) ((1l * res * a) % mod);
			}
			a = (int) ((1l * a * a) % mod);
			e >>= 1;
		}
		

		return res % mod;
	}

	static public class segmentTree {
		int[] array, lazy;
		sol[] tree;
		int n;

		segmentTree(int[] aa) {
			array = aa;
			n = array.length - 1;
			tree = new sol[n * 4];
			

			

			build(1, 1, n);
		}

		public String toString() {
			return Arrays.toString(tree);
		}

		void build(int node, int l, int r) {
			if (l == r)
				tree[node] = new sol(true, array[r], array[r], 'e');
			else {
				int mid = (l + r) >> 1;
				build(node << 1, l, mid);
				build((node << 1) | 1, mid + 1, r);
				if (!tree[node << 1].st || !tree[(node << 1) | 1].st) {
					tree[node] = new sol(false, tree[node << 1].l, tree[node << 1 | 1].r, 'n');
				} else if (tree[node << 1].s == 'l' && tree[(node << 1) | 1].s == 'l') {
					tree[node] = new sol(false, tree[node << 1].l, tree[node << 1 | 1].r, 'n');
				} else if (tree[node << 1].s == 'l') {
					if (tree[(node << 1) | 1].s == 'e' && tree[(node << 1) | 1].l <= tree[(node << 1)].r)
						tree[node] = new sol(true, tree[node << 1].l, tree[node << 1 | 1].r, 'l');
					else if (tree[(node << 1) | 1].s == 's' && tree[(node << 1) | 1].l >= tree[(node << 1) | 1].r
							&& tree[(node << 1) | 1].l <= tree[(node << 1)].r)
						tree[node] = new sol(true, tree[node << 1].l, tree[node << 1 | 1].r, 'l');
					else
						tree[node] = new sol(false, tree[node << 1].l, tree[node << 1 | 1].r, 'n');
				} else if (tree[(node << 1) | 1].s == 'l') {
					if (tree[(node << 1)].s == 'e' && tree[(node << 1)].r <= tree[(node << 1) | 1].l)
						tree[node] = new sol(true, tree[node << 1].l, tree[node << 1 | 1].r, 'l');
					else if (tree[(node << 1)].s == 's' && tree[(node << 1)].r >= tree[(node << 1)].l
							&& tree[(node << 1)].r <= tree[(node << 1) | 1].l)
						tree[node] = new sol(true, tree[node << 1].l, tree[node << 1 | 1].r, 'l');
					else
						tree[node] = new sol(false, tree[node << 1].l, tree[node << 1 | 1].r, 'n');
				} else if (tree[node << 1].s == 'e' && tree[(node << 1) | 1].s == 'e') {
					tree[node] = new sol(true, tree[node << 1].l, tree[node << 1 | 1].r, 's');
				} else if (tree[node << 1].s == 's' && tree[(node << 1) | 1].s == 's') {
					if (tree[node << 1].r >= tree[node << 1].l && tree[node << 1 | 1].r <= tree[node << 1 | 1].l)
						tree[node] = new sol(true, tree[node << 1].l, tree[node << 1 | 1].r, 'l');
					else if (tree[node << 1].r >= tree[node << 1].l && tree[node << 1 | 1].l >= tree[node << 1].r
							&& tree[node << 1 | 1].r >= tree[node << 1 | 1].l)
						tree[node] = new sol(true, tree[node << 1].l, tree[node << 1 | 1].r, 's');
					else if (tree[node << 1].l >= tree[node << 1].r && tree[node << 1 | 1].l <= tree[node << 1].r
							&& tree[node << 1 | 1].l >= tree[node << 1 | 1].r)
						tree[node] = new sol(true, tree[node << 1].l, tree[node << 1 | 1].r, 's');
					else
						tree[node] = new sol(false, tree[node << 1].l, tree[node << 1 | 1].r, 'n');
				} else if (tree[node << 1].s == 's') {
					if (tree[node << 1].r >= tree[node << 1].l && tree[node << 1 | 1].l >= tree[node << 1].r)
						tree[node] = new sol(true, tree[node << 1].l, tree[node << 1 | 1].r, 's');
					else if (tree[node << 1].r >= tree[node << 1].l)
						tree[node] = new sol(true, tree[node << 1].l, tree[node << 1 | 1].r, 'l');
					else if (tree[node << 1].l >= tree[node << 1].r && tree[node << 1 | 1].l <= tree[node << 1].r)
						tree[node] = new sol(true, tree[node << 1].l, tree[node << 1 | 1].r, 'l');
					else
						tree[node] = new sol(false, tree[node << 1].l, tree[node << 1 | 1].r, 'n');
				} else if (tree[(node << 1) | 1].s == 's') {
					if (tree[node << 1 | 1].r >= tree[node << 1 | 1].l && tree[node << 1].r <= tree[node << 1 | 1].l)
						tree[node] = new sol(true, tree[node << 1].l, tree[node << 1 | 1].r, 's');
					else if (tree[node << 1 | 1].r >= tree[node << 1 | 1].l)
						tree[node] = new sol(false, tree[node << 1].l, tree[node << 1 | 1].r, 'n');
					else if (tree[node << 1 | 1].l >= tree[node << 1 | 1].r
							&& tree[node << 1].r >= tree[node << 1 | 1].l)
						tree[node] = new sol(true, tree[node << 1].l, tree[node << 1 | 1].r, 's');
					else
						tree[node] = new sol(true, tree[node << 1].l, tree[node << 1 | 1].r, 'l');
				}
				

				

			}
		}

		

		sol query(int i, int j) {
			return query(1, 1, n, i, j);
		}

		sol query(int node, int b, int e, int i, int j) 

		{
			if (i > e || j < b)
				return null;
			if (b >= i && e <= j)
				return tree[node];
			int mid = b + e >> 1;


			sol q1 = query(node << 1, b, mid, i, j);
			sol q2 = query(node << 1 | 1, mid + 1, e, i, j);
			if (q1 == null)
				return q2;
			if (q2 == null)
				return q1;
			sol q3 = null;
			if (!q1.st || !q2.st) {
				q3 = new sol(false, q1.l, q2.r, 'n');
			} else if (q1.s == 'l' && q2.s == 'l') {
				q3 = new sol(false, q1.l, q2.r, 'n');
			} else if (q1.s == 'l') {
				if (q2.s == 'e' && q2.l <= q1.r)
					q3 = new sol(true, q1.l, q2.r, 'l');
				else if (q2.s == 's' && q2.l >= q2.r && q2.l <= q1.r)
					q3 = new sol(true, q1.l, q2.r, 'l');
				else
					q3 = new sol(false, q1.l, q2.r, 'n');
			} else if (q2.s == 'l') {
				if (q1.s == 'e' && q1.r <= q2.l)
					q3 = new sol(true, q1.l, q2.r, 'l');
				else if (q1.s == 's' && q1.r >= q1.l && q1.r <= q2.l)
					q3 = new sol(true, q1.l, q2.r, 'l');
				else
					q3 = new sol(false, q1.l, q2.r, 'n');
			} else if (q1.s == 'e' && q2.s == 'e') {
				q3 = new sol(true, q1.l, q2.r, 's');
			} else if (q1.s == 's' && q2.s == 's') {
				if (q1.r >= q1.l && q2.r <= q2.l)
					q3 = new sol(true, q1.l, q2.r, 'l');
				else if (q1.r >= q1.l && q2.l >= q1.r && q2.r >= q2.l)
					q3 = new sol(true, q1.l, q2.r, 's');
				else if (q1.l >= q1.r && q2.l <= q1.r && q2.l >= q2.r)
					q3 = new sol(true, q1.l, q2.r, 's');
				else
					q3 = new sol(false, q1.l, q2.r, 'n');
			} else if (q1.s == 's') {
				if (q1.r >= q1.l && q2.l >= q1.r)
					q3 = new sol(true, q1.l, q2.r, 's');
				else if (q1.r >= q1.l)
					q3 = new sol(true, q1.l, q2.r, 'l');
				else if (q1.l >= q1.r && q2.l <= q1.r)
					q3 = new sol(true, q1.l, q2.r, 'l');
				else
					q3 = new sol(false, q1.l, q2.r, 'n');
			} else if (q2.s == 's') {
				if (q2.r >= q2.l && q1.r <= q2.l)
					q3 = new sol(true, q1.l, q2.r, 's');
				else if (q2.r >= q2.l)
					q3 = new sol(false, q1.l, q2.r, 'n');
				else if (q2.l >= q2.r && q1.r >= q2.l)
					q3 = new sol(true, q1.l, q2.r, 's');
				else
					q3 = new sol(true, q1.l, q2.r, 'l');
			}
			return q3;

		}

	}

	static long fac(int n) {
		if (n == 0)
			return fac[n] = 1;
		if (n == 1)
			return fac[n] = 1;
		long ans = 1;
		for (int i = 1; i <= n; i++)
			fac[i] = ans = (i % mod * ans % mod) % mod;
		return ans % mod;
	}

	static long gcd(long a, long b) {

		if (b == 0)
			return a;
		return gcd(b, a % b);
	}

	static class sol {
		boolean st;
		int l;
		int r;
		char s;

		sol(boolean st, int l, int r, char s) {
			this.st = st;
			this.l = l;
			this.r = r;
			this.s = s;
		}

		public String toString() {
			return st + " " + l + " " + r + " " + s;
		}
	}

	static class pair implements Comparable<pair> {
		int d;
		int t;

		pair(int d, int t) {
			this.d = d;
			this.t = t;
		}

		public String toString() {
			return d + " " + t;
		}

		public int compareTo(pair o) {
			if (o.d == d)
				return -o.t + t;
			return -o.d + d;
		}
	}

	static class unionfind {
		int[] p;
		int[] size;

		unionfind(int n) {
			p = new int[n];
			size = new int[n];

			for (int i = 0; i < n; i++) {
				p[i] = i;
			}
			Arrays.fill(size, 1);
		}

		int findSet(int v) {
			if (v == p[v])
				return v;
			return p[v] = findSet(p[v]);
		}

		boolean sameSet(int a, int b) {
			a = findSet(a);
			b = findSet(b);
			if (a == b)
				return true;
			return false;
		}

		int max() {
			int max = 0;
			for (int i = 0; i < size.length; i++)
				if (size[i] > max)
					max = size[i];
			return max;
		}

		void combine(int a, int b) {
			a = findSet(a);
			b = findSet(b);
			if (a == b)
				return;
			if (size[a] > size[b]) {
				p[b] = a;
				size[a] += size[b];

			} else {
				p[a] = b;
				size[b] += size[a];
			}
		}
	}

	static class Scanner {
		StringTokenizer st;
		BufferedReader br;

		public Scanner(InputStream system) {
			br = new BufferedReader(new InputStreamReader(system));
		}

		public Scanner(String file) throws Exception {
			br = new BufferedReader(new FileReader(file));
		}

		public String next() throws IOException {
			while (st == null || !st.hasMoreTokens())
				st = new StringTokenizer(br.readLine());
			return st.nextToken();
		}

		public String nextLine() throws IOException {
			return br.readLine();
		}

		public int nextInt() throws IOException {
			return Integer.parseInt(next());
		}

		public double nextDouble() throws IOException {
			return Double.parseDouble(next());
		}

		public char nextChar() throws IOException {
			return next().charAt(0);
		}

		public Long nextLong() throws IOException {
			return Long.parseLong(next());
		}

		public boolean ready() throws IOException {
			return br.ready();
		}

		public void waitForInput() throws InterruptedException {
			Thread.sleep(3000);
		}
	}
}