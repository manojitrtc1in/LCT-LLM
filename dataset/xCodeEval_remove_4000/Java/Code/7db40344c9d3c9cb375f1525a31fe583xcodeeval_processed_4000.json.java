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
	static HashSet<Integer> [] id0;
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		out = new PrintWriter(System.out);
	    int n=sc.nextInt();
	    int []a=new int[n];
	    id0=new HashSet[n];
	 

	    si=new int [1000001];
	    primes=new ArrayList<>();
	    int N=1000001;
	    si[1]=1;
	    for(int i=2;i<N;i++) {
	    	if(si[i]==0) {
	    		si[i]=i;
	    		primes.add(i);
	    	}
	    	for(int j=0;j<primes.size() && primes.get(j)<=si[i] && (i*primes.get(j))<N;j++)
	    		si[primes.get(j)*i]=primes.get(j);
	    		
	    }
	    for(int i=0;i<n;i++)
	    	a[i]=sc.nextInt();
	   
	    HashMap<Integer,Integer> id3=new HashMap<>();
	    for(int i=0;i<n;i++) {
	    	id0[i]=new HashSet<>();
	    	if(id3.containsKey(a[i])) {
	    		id0[i]=id0[id3.get(a[i])];
	    		continue;
	    	}
	    	factors=new HashMap<>();
	    	factor(a[i]);
	    id3.put(a[i], i);
            int []ele=new int[factors.size()];
            int []re=new int [factors.size()];
            int io=0;
            for(int j:factors.keySet()) {
            	ele[io]=j;
            	re[io]=factors.get(j);
            	io++;
            }
            findFactors(i, ele, re, 0, 1);
               
	    }
	    long ans=0;
	    int []memo2=new int[N];
	    for(int i=0;i<n;i++) {
	    	HashMap<Integer,Integer> num=new HashMap<>();
	    	for(int k:id0[i]) {
	    		if(k>i+1) {
	    			continue;
	    		}
	    		if(k==1) {
	    			ans=(ans+1)%mod;
	                num.put(1,1);
	    		}
	    		else {
    				ans=(ans+memo2[k-1])%mod;
      				num.put(k,(int)(memo2[k-1]%mod));
    			}
	    	}
	    	for(int k:num.keySet()) {
                memo2[k]=(int)((memo2[k]+num.get(k))%mod);
 	    	}
	    }
	    out.println(ans);
		out.flush();
	}
   static void factor(int n) {
	   if(si[n]==n) {
		   factors.put(n, factors.getOrDefault(n, 0)+1);
		   return;
	   }
	   factors.put(si[n], factors.getOrDefault(si[n], 0)+1);
	 
	   factor(n/si[(int)n]);
   }
   static void findFactors(int idx,int[] id4, int[] multiplicity, int id1, int currentResult) {
	    if (id1 == id4.length) {
	        id0[idx].add(currentResult);
	        return;
	    }
	    

	    

	    for (int i = 0; i <= multiplicity[id1]; ++i) {
	        findFactors(idx,id4, multiplicity, id1 + 1, currentResult);
	        currentResult *= id4[id1];
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

		public void id2() throws InterruptedException {
			Thread.sleep(3000);
		}
	}
}