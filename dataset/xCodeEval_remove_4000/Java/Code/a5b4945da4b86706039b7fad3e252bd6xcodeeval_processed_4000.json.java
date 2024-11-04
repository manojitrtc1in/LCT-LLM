import java.io.*;
import java.util.*;

public class tr0 {
	static PrintWriter out;
	static StringBuilder sb;
	static final double EPS = 1e-9;
	static int mod = 1000000007;
	static int inf = (int) 1e9 + 2;
	static long[] fac;
	static int[] si;
	static ArrayList<Integer> primes;
	static ArrayList<Integer>[] ad;
	static int[] ans;
	static int m, k;
	static HashMap<Integer, Integer> t;
	static boolean f;

	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		out = new PrintWriter(System.out);
		int n = sc.nextInt();
		int[] a = new int[n];
		String s = sc.nextLine();
		for (int i = 0; i < n; i++)
			a[i] = Integer.parseInt(s.charAt(i) + "");
		if (n % 2 == 0) {
			if(a[n/2]!=0) {
			int idx = (n / 2);
			for (int i = idx; i < n; i++) {
				if (a[i] != 0) {
					idx = i;
					break;
				}
				idx = i;
			}
			ArrayList<Integer> num1 = new ArrayList<>();
			ArrayList<Integer> num2 = new ArrayList<>();
			for (int i = 0; i < n; i++) {
				if (i < idx) {
					num1.add(a[i]);
				} else {
					num2.add(a[i]);
				}
			}
			int rem = 0;
			ArrayList<Integer> ans = new ArrayList<>();
			Collections.reverse(num1);
			Collections.reverse(num2);
			int i = 0;
			int j = 0;
			for (; i < num1.size() && j < num2.size(); i++, j++) {
				ans.add((num1.get(i) + num2.get(j) + rem) % 10);
				if (num1.get(i) + num2.get(j) + rem >= 10)
					rem = 1;
				else
					rem = 0;
			}
			while(i<num1.size()) {
				ans.add((num1.get(i)+rem)%10);
				if (num1.get(i)+ rem >= 10)
					rem = 1;
				else
					rem = 0;
				i++;
			}
			while(j<num2.size()) {
				ans.add((num2.get(j)+rem)%10);
				if (num2.get(j)+ rem >= 10)
					rem = 1;
				else
					rem = 0;
				j++;
			}
			if(rem==1)
				ans.add(rem);
			Collections.reverse(ans);
			for(int o:ans)
				out.print(o);
			}
			else {
				int idx=n/2;
				for (int i = idx; i < n; i++) {
					if (a[i] != 0) {
						idx = i;
						break;
					}
				}
				if(idx==n/2)
					idx=n;
				ArrayList<Integer> num1 = new ArrayList<>();
				ArrayList<Integer> num2 = new ArrayList<>();
				for (int i = 0; i < n; i++) {
					if (i < idx) {
						num1.add(a[i]);
					} else {
						num2.add(a[i]);
					}
				}
				int rem = 0;
				ArrayList<Integer> ans = new ArrayList<>();
				Collections.reverse(num1);
				Collections.reverse(num2);
				int i = 0;
				int j = 0;
				for (; i < num1.size() && j < num2.size(); i++, j++) {
					ans.add((num1.get(i) + num2.get(j) + rem) % 10);
					if (num1.get(i) + num2.get(j) + rem >= 10)
						rem = 1;
					else
						rem = 0;
				}
				while(i<num1.size()) {
					ans.add((num1.get(i)+rem)%10);
					if (num1.get(i)+ rem >= 10)
						rem = 1;
					else
						rem = 0;
					i++;
				}
				while(j<num2.size()) {
					ans.add((num2.get(j)+rem)%10);
					if (num2.get(j)+ rem >= 10)
						rem = 1;
					else
						rem = 0;
					j++;
				}
				if(rem==1)
					ans.add(rem);
				Collections.reverse(ans);
				int remt = 0;
				ArrayList<Integer> anst = new ArrayList<>();
				i = 0;
				 j = 0;
				 int idx1=n/2;
				 while(a[idx1]==0) {
					 idx1--;
				 }
			

				 ArrayList<Integer> id2 = new ArrayList<>();
					ArrayList<Integer> id1 = new ArrayList<>();
					for (int co = 0; co < n; co++) {
						if (co < idx1) {
							id2.add(a[co]);
						} else {
							id1.add(a[co]);
						}
					}
				

					Collections.reverse(id2);
					Collections.reverse(id1);
				for (; i < id2.size() && j < id1.size(); i++, j++) {
					anst.add((id2.get(i) + id1.get(j) + remt) % 10);
					if (id2.get(i) + id1.get(j) + remt >= 10)
						remt = 1;
					else
						remt = 0;
				}
			

				while(i<id2.size()) {
					anst.add((id2.get(i)+remt)%10);
					if (id2.get(i)+ remt >= 10)
						remt = 1;
					else
						remt = 0;
					i++;
				}
				while(j<id1.size()) {
					anst.add((id1.get(j)+remt)%10);
					if (id1.get(j)+ remt >= 10)
						remt = 1;
					else
						remt = 0;
					j++;
				}
				if(remt==1)
					anst.add(remt);
				Collections.reverse(anst);
				f=true;
				

				for(int c=0;c<ans.size();c++) {
					if(anst.get(c)>ans.get(c)) {
						f=true;
						break;
					}
					if(anst.get(c)<ans.get(c)) {
						f=false;
						break;
					}
				}
				if(ans.size()>anst.size()) {
					f=false;
				}
				if(ans.size()<anst.size()) {
					f=true;
				}
				

			  if(f) {
				for(int o:ans)
					out.print(o);
			  }
			  else {
				for(int o:anst)
					out.print(o);
			  }
			}
		} else {
			int idx = n / 2;
			if (a[idx] == 0) {
				for (int i = idx; i < n; i++) {
					if (a[i] != 0) {
						idx = i;
						break;
					}
			

				}
				if(idx==n/2)
					idx=n;
				ArrayList<Integer> num1 = new ArrayList<>();
				ArrayList<Integer> num2 = new ArrayList<>();
				for (int i = 0; i < n; i++) {
					if (i < idx) {
						num1.add(a[i]);
					} else {
						num2.add(a[i]);
					}
				}
				int rem = 0;
				ArrayList<Integer> ans = new ArrayList<>();
				Collections.reverse(num1);
				Collections.reverse(num2);
				int i = 0;
				int j = 0;
				for (; i < num1.size() && j < num2.size(); i++, j++) {
					ans.add((num1.get(i) + num2.get(j) + rem) % 10);
					if (num1.get(i) + num2.get(j) + rem >= 10)
						rem = 1;
					else
						rem = 0;
				}
				while(i<num1.size()) {
					ans.add((num1.get(i)+rem)%10);
					if (num1.get(i)+ rem >= 10)
						rem = 1;
					else
						rem = 0;
					i++;
				}
				while(j<num2.size()) {
					ans.add((num2.get(j)+rem)%10);
					if (num2.get(j)+ rem >= 10)
						rem = 1;
					else
						rem = 0;
					j++;
				}
				if(rem==1)
					ans.add(rem);
				Collections.reverse(ans);
				int remt = 0;
				ArrayList<Integer> anst = new ArrayList<>();
				i = 0;
				 j = 0;
				 int idx1=n/2;
				 while(a[idx1]==0) {
					 idx1--;
				 }
			

				 ArrayList<Integer> id2 = new ArrayList<>();
					ArrayList<Integer> id1 = new ArrayList<>();
					for (int co = 0; co < n; co++) {
						if (co < idx1) {
							id2.add(a[co]);
						} else {
							id1.add(a[co]);
						}
					}
				

					Collections.reverse(id2);
					Collections.reverse(id1);
				for (; i < id2.size() && j < id1.size(); i++, j++) {
					anst.add((id2.get(i) + id1.get(j) + remt) % 10);
					if (id2.get(i) + id1.get(j) + remt >= 10)
						remt = 1;
					else
						remt = 0;
				}
			

				while(i<id2.size()) {
					anst.add((id2.get(i)+remt)%10);
					if (id2.get(i)+ remt >= 10)
						remt = 1;
					else
						remt = 0;
					i++;
				}
				while(j<id1.size()) {
					anst.add((id1.get(j)+remt)%10);
					if (id1.get(j)+ remt >= 10)
						remt = 1;
					else
						remt = 0;
					j++;
				}
				if(remt==1)
					anst.add(remt);
				Collections.reverse(anst);
				f=true;
				
				for(int c=0;c<ans.size();c++) {
					if(anst.get(c)>ans.get(c)) {
						f=true;
						break;
					}
					if(anst.get(c)<ans.get(c)) {
						f=false;
						break;
					}
				}
				if(ans.size()>anst.size()) {
					f=false;
				}
				if(ans.size()<anst.size()) {
					f=true;
				}
				

			  if(f) {
				for(int o:ans)
					out.print(o);
			  }
			  else {
				for(int o:anst)
					out.print(o);
			  }
			} else {
				idx = n / 2;
				int idx1 = idx + 1;
				ArrayList<Integer> num1 = new ArrayList<>();
				ArrayList<Integer> num2 = new ArrayList<>();
				for (int i = 0; i < n; i++) {
					if (i < idx) {
						num1.add(a[i]);
					} else {
						num2.add(a[i]);
					}
				}
				ArrayList<Integer> id2 = new ArrayList<>();
				ArrayList<Integer> id1 = new ArrayList<>();
				for (int i = 0; i < n; i++) {
					if (i < idx1) {
						id2.add(a[i]);
					} else {
						id1.add(a[i]);
					}
				}
				int rem = 0;
				ArrayList<Integer> ans = new ArrayList<>();
				int remt = 0;
				ArrayList<Integer> anst = new ArrayList<>();
				Collections.reverse(num1);
				Collections.reverse(num2);
				Collections.reverse(id2);
				Collections.reverse(id1);
				int i = 0;
				int j = 0;
				for (; i < num1.size() && j < num2.size(); i++, j++) {
					ans.add((num1.get(i) + num2.get(j) + rem) % 10);
					if (num1.get(i) + num2.get(j) + rem >= 10)
						rem = 1;
					else
						rem = 0;
				}
				while(i<num1.size()) {
					ans.add((num1.get(i)+rem)%10);
					if (num1.get(i)+ rem >= 10)
						rem = 1;
					else
						rem = 0;
					i++;
				}
				while(j<num2.size()) {
					ans.add((num2.get(j)+rem)%10);
					if (num2.get(j)+ rem >= 10)
						rem = 1;
					else
						rem = 0;
					j++;
				}
			

				if(rem==1)
					ans.add(rem);
				Collections.reverse(ans);
				i = 0;
				 j = 0;
				for (; i < id2.size() && j < id1.size(); i++, j++) {
					anst.add((id2.get(i) + id1.get(j) + remt) % 10);
					if (id2.get(i) + id1.get(j) + remt >= 10)
						remt = 1;
					else
						remt = 0;
				}
				while(i<id2.size()) {
					anst.add((id2.get(i)+remt)%10);
					if (id2.get(i)+ remt >= 10)
						remt = 1;
					else
						remt = 0;
					i++;
				}
				while(j<id1.size()) {
					anst.add((id1.get(j)+remt)%10);
					if (id1.get(j)+ remt >= 10)
						remt = 1;
					else
						remt = 0;
					j++;
				}
				if(remt==1)
					anst.add(remt);
				Collections.reverse(anst);
				f=true;
				
				for(int c=0;c<ans.size();c++) {
					if(anst.get(c)>ans.get(c)) {
						f=true;
						break;
					}
					if(anst.get(c)<ans.get(c)) {
						f=false;
						break;
					}
				}
				if(ans.size()>anst.size()) {
					f=false;
				}
				if(ans.size()<anst.size()) {
					f=true;
				}
			  if(f) {
				for(int o:ans)
					out.print(o);
			  }
			  else {
				for(int o:anst)
					out.print(o);
			  }
			  }
		}
		out.close();
	}

	static class seg implements Comparable<seg> {
		int s;
		int e;
		int num;
		int id;

		seg(int s, int e) {
			this.s = s;
			this.e = e;
		}

		public String toString() {
			return s + " " + e + " " + num + " " + id;
		}

		@Override
		public int compareTo(seg o) {
			if (o.s == s)
				return o.e - e;
			return s - o.s;
		}
	}

	static public class SegmentTree { 


		int N; 

		int[] array, sTree, lazy, candies;

		SegmentTree(int[] in) {
			array = in.clone();
			N = in.length - 1;
			sTree = new int[N << 1]; 

			lazy = new int[N << 1];
			candies = new int[N << 1];
			build(1, 1, N);
			build2(1, 1, N);
		}

		public String toString() {
			return Arrays.toString(sTree) + "\n" + Arrays.toString(candies);
		}

		void build(int node, int b, int e) 

		{
			if (b == e)
				sTree[node] = array[b];
			else {
				int mid = b + e >> 1;
				build(node << 1, b, mid);
				build(node << 1 | 1, mid + 1, e);
				sTree[node] = (sTree[node << 1] + sTree[node << 1 | 1]) % 10;
				if (sTree[node << 1] + sTree[node << 1 | 1] >= 10)
					candies[node]++;
			}
		}

		void build2(int node, int b, int e) 

		{
			if (b == e)
				b = e;
			else {
				int mid = b + e >> 1;
				build(node << 1, b, mid);
				build(node << 1 | 1, mid + 1, e);
				candies[node] = (candies[node << 1] + candies[node << 1 | 1]);
			}
		}

		void update_point(int index, int val) 

		{
			index += N - 1;
			sTree[index] += val;
			while (index > 1) {
				index >>= 1;
				sTree[index] = sTree[index << 1] + sTree[index << 1 | 1];
			}
		}

		void update_range(int i, int j, int val) 

		{
			update_range(1, 1, N, i, j, val);
		}

		void update_range(int node, int b, int e, int i, int j, int val) {
			if (i > e || j < b)
				return;
			if (b >= i && e <= j) {
				sTree[node] += (e - b + 1) * val;
				lazy[node] += val;
			} else {
				int mid = b + e >> 1;
				propagate(node, b, mid, e);
				update_range(node << 1, b, mid, i, j, val);
				update_range(node << 1 | 1, mid + 1, e, i, j, val);
				sTree[node] = sTree[node << 1] + sTree[node << 1 | 1];
			}

		}

		void propagate(int node, int b, int mid, int e) {
			lazy[node << 1] += lazy[node];
			lazy[node << 1 | 1] += lazy[node];
			sTree[node << 1] += (mid - b + 1) * lazy[node];
			sTree[node << 1 | 1] += (e - mid) * lazy[node];
			lazy[node] = 0;
		}

		

		int query(int i, int j) {
			

			return query(1, 1, N, i, j);
		}

		int query(int node, int b, int e, int i, int j) 

		{
			if (i > e || j < b)
				return 0;
			if (b >= i && e <= j)
				return candies[node];
			int mid = b + e >> 1;
			

			int q1 = query(node << 1, b, mid, i, j);
			int q2 = query(node << 1 | 1, mid + 1, e, i, j);
			return q1 + q2;
		}
	}

	static int x, y, d;

	static long power(int i) {
		

		

		long a = 1;
		for (int k = 0; k < i; k++)
			a *= i;
		return a;
	}

	static void id3(int a, int b) {
		if (b == 0) {
			x = 1;
			y = 0;
			d = a;
			return;
		}
		id3(b, a % b);
		int x1 = y;
		int y1 = x - a / b * y;
		x = x1;
		y = y1;
	}

	static void dfs(int u) {
		int counter = 1;
		for (int v : ad[u])
			if (ans[v] == 0) {
				if (counter == ans[u]) {
					counter++;
					ans[v] = counter;
				} else
					ans[v] = counter++;
				if (counter > k)
					f = false;
				dfs(v);
			}
	}

	static void bfs(int s) {
		Queue<Integer> q = new LinkedList();
		q.add(s);
		ans[s] = 1;
		while (!q.isEmpty()) {
			int u = q.remove();
			int c = 1;
			for (int v : ad[u]) {
				if (ans[v] == 0) {
					

					if (c == ans[u]) {
						c++;
						ans[v] = c++;
					} else
						ans[v] = c++;
					

					if (ans[v] > k)
						f = false;
					q.add(v);
				}
			}
		}
	}

	static void seive() {
		si = new int[1000001];
		primes = new ArrayList<>();
		int N = 1000001;
		si[1] = 1;
		for (int i = 2; i < N; i++) {
			if (si[i] == 0) {
				si[i] = i;
				primes.add(i);
			}
			for (int j = 0; j < primes.size() && primes.get(j) <= si[i] && (i * primes.get(j)) < N; j++)
				si[primes.get(j) * i] = primes.get(j);

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

	static int gcd(int a, int b) {

		if (b == 0)
			return a;
		return gcd(b, a % b);
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

		public void id0() throws InterruptedException {
			Thread.sleep(3000);
		}
	}
}