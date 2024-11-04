

import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Random;

public class D {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), K = ni();
		int[] from = new int[n-1];
		int[] to = new int[n-1];
		for(int i = 0;i < n-1;i++){
			from[i] = ni()-1;
			to[i] = ni()-1;
		}
		int[][] g = packU(n, from, to);
		int[][] pars = parents3(g, 0);
		int[] par = pars[0], ord = pars[1], dep = pars[2];
		int[] clus = id8(g, par, ord);
		int[][] cluspath = clusPaths(clus, ord);
		int[] id5 = id0(cluspath, n);
		int[][] spar = id7(par);
		id2 id4 = new id2(spar, dep);
		
		int low = 1, high = K+1;
		while(high - low > 1){
			int len = high+low>>>1;
			if(ok(len, g, par, ord, clus, cluspath, id5, dep, K, id4)){
				low = len;
			}else{
				high = len;
			}
		}
		out.println(low);
	}
	
	boolean ok(int len, int[][] g, int[] par, int[] ord, int[] clus, int[][] cluspath, int[] id5, int[] dep, int K, id2 id4)
	{
		int n = g.length;
		id6[] stu = new id6[cluspath.length];
		for(int i = 0;i < cluspath.length;i++){
			stu[i] = new id6(cluspath[i].length);
		}
		int use = 0;


		for(int i = 0;i < n;i++){
			{
				int cx = clus[i]; 

				int ind = id5[i]; 

				while(cx != clus[0]){
					use -= stu[cx].count[1];
					stu[cx].add(0, ind+1, 1);
					use += stu[cx].count[1];
					int con = par[cluspath[cx][0]];
					ind = id5[con];
					cx = clus[con];
				}
				use -= stu[clus[0]].count[1];
				stu[clus[0]].add(id5[0], ind+1, 1);
				use += stu[clus[0]].count[1];
			}
			
			if(i >= len-1){
				int lca = id4.lca(i-(len-1), i+1);


				if(use-dep[lca] <= K)return true;
			}
			
			if(i >= len-1){
				int j = i-(len-1);
				int cx = clus[j]; 

				int ind = id5[j]; 

				while(cx != clus[0]){
					use -= stu[cx].count[1];
					stu[cx].add(0, ind+1, -1);
					use += stu[cx].count[1];
					int con = par[cluspath[cx][0]];
					ind = id5[con];
					cx = clus[con];
				}
				use -= stu[clus[0]].count[1];
				stu[clus[0]].add(id5[0], ind+1, -1);
				use += stu[clus[0]].count[1];
			}
		}
		return false;
	}
	
	public static int id3(int a, int b, int[][] spar, int[] depth)
	{
		if(a == -1)return b;
		if(b == -1)return a;
		
		if(depth[a] < depth[b]){
			b = ancestor(b, depth[b]-depth[a], spar);
		}else if(depth[a] > depth[b]){
			a = ancestor(a, depth[a]-depth[b], spar);
		}
		
		if(a == b)return a;
		int sa = a, sb = b;
		for(int low = 0, high = depth[a], t = Integer.highestOneBit(high), k = Integer.numberOfTrailingZeros(t);t > 0;t>>>=1,k--){
			if((low^high) >= t){
				if(spar[k][sa] != spar[k][sb]){
					low |= t;
					sa = spar[k][sa]; sb = spar[k][sb];
				}else{
					high = low|t-1;
				}
			}
		}
		return spar[0][sa];
	}
	
	protected static int ancestor(int a, int m, int[][] spar)
	{
		for(int i = 0;m > 0 && a != -1;m>>>=1,i++){
			if((m&1)==1)a = spar[i][a];
		}
		return a;
	}
	
	
	public static int[][] id7(int[] par)
	{
		int n = par.length;
		int m = Integer.numberOfTrailingZeros(Integer.highestOneBit(n-1))+1;
		int[][] pars = new int[m][n];
		pars[0] = par;
		for(int j = 1;j < m;j++){
			for(int i = 0;i < n;i++){
				pars[j][i] = pars[j-1][i] == -1 ? -1 : pars[j-1][pars[j-1][i]];
			}
		}
		return pars;
	}
	
	public static class id2 {
		public int M, H, N;
		public int[] st;
		public int[][] spar;
		public int[] dep;
		
		public id2(int[][] spar, int[] dep)
		{
			N = dep.length;
			this.spar = spar;
			this.dep = dep;
			M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
			H = M>>>1;
			st = new int[M];
			for(int i = 0;i < N;i++){
				st[H+i] = i;
			}
			Arrays.fill(st, H+N, M, -1);
			for(int i = H-1;i >= 1;i--)propagate(i);
		}
		
		private void tr(Object... o) { System.out.println(Arrays.deepToString(o)); }
		
		private void propagate(int i)
		{
			st[i] = id3(st[2*i], st[2*i+1], spar, dep);
		}
		
		public int lca(int l, int r){ return l >= r ? -1 : lca(l, r, 0, H, 1);}
		
		private int lca(int l, int r, int cl, int cr, int cur)
		{
			if(l <= cl && cr <= r){
				return st[cur];
			}else{
				int mid = cl+cr>>>1;
				int ret = -1;
				if(Math.max(l, cl) < Math.min(r, mid)){
					ret = id3(ret, lca(l, r, cl, mid, 2*cur), spar, dep);
				}
				if(Math.max(l, mid) < Math.min(r, cr)){
					ret = id3(ret, lca(l, r, mid, cr, 2*cur+1), spar, dep);
				}
				return ret;
			}
		}
	}
	
	public static class id6 {
		public int M, H, N;
		public int[] st;
		public int[] count;
		
		public id6(int n)
		{
			N = n;
			M = Integer.highestOneBit(Math.max(n-1, 1))<<2;
			H = M>>>1;
			st = new int[M];
			count = new int[M];
		}
		
		public id6(int[] a)
		{
			N = a.length;
			M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
			H = M>>>1;
			st = new int[M];
			for(int i = 0;i < N;i++){
				st[H+i] = a[i];
			}
			count = new int[M];
			for(int i = H-1;i >= 1;i--)propagate(i);
		}
		
		private void propagate(int i)
		{
			count[i] = st[i] > 0 ? H/Integer.highestOneBit(i) : count[2*i]+count[2*i+1];
		}
		
		public void add(int l, int r, int v){ add(l, r, v, 0, H, 1); }
		
		private void add(int l, int r, int v, int cl, int cr, int cur)
		{
			if(cur >= H){
				st[cur] += v;
				count[cur] = st[cur] > 0 ? 1 : 0;
			}else if(l <= cl && cr <= r){
				st[cur] += v;
				propagate(cur);
			}else{
				int mid = cl+cr>>>1;
				if(Math.max(l, cl) < Math.min(r, mid)){
					add(l, r, v, cl, mid, 2*cur);
				}
				if(Math.max(l, mid) < Math.min(r, cr)){
					add(l, r, v, mid, cr, 2*cur+1);
				}
				propagate(cur);
			}
		}
	}
	
	public static int[][] parents3(int[][] g, int root)
	{
		int n = g.length;
		int[] par = new int[n];
		Arrays.fill(par, -1);
		
		int[] depth = new int[n];
		depth[0] = 0;
		
		int[] q = new int[n];
		q[0] = root;
		for(int p = 0, r = 1;p < r;p++) {
			int cur = q[p];
			for(int nex : g[cur]){
				if(par[cur] != nex){
					q[r++] = nex;
					par[nex] = cur;
					depth[nex] = depth[cur] + 1;
				}
			}
		}
		return new int[][] {par, q, depth};
	}
	
	public static int[] id8(int[][] g, int[] par, int[] ord)
	{
		int n = g.length;
		int[] size = new int[n];
		Arrays.fill(size, 1);
		for(int i = n-1;i > 0;i--)size[par[ord[i]]] += size[ord[i]];
		
		int[] clus = new int[n];
		Arrays.fill(clus, -1);
		int p = 0;
		outer:
		for(int i = 0;i < n;i++){
			int u = ord[i];
			if(clus[u] == -1)clus[u] = p++;
			for(int v : g[u]){
				if(par[u] != v && size[v] >= size[u]/2){
					clus[v] = clus[u];
					continue outer;
				}
			}
			for(int v : g[u]){
				if(par[u] != v){
					clus[v] = clus[u];
					break;
				}
			}
		}
		return clus;
	}
	
	
	public static int[][] clusPaths(int[] clus, int[] ord)
	{
		int n = clus.length;
		int[] rp = new int[n];
		int sup = 0;
		for(int i = 0;i < n;i++){
			rp[clus[i]]++;
			sup = Math.max(sup, clus[i]);
		}
		sup++;
		
		int[][] row = new int[sup][];
		for(int i = 0;i < sup;i++)row[i] = new int[rp[i]];
		
		for(int i = n-1;i >= 0;i--){
			row[clus[ord[i]]][--rp[clus[ord[i]]]] = ord[i];
		}
		return row;
	}
	
	
	public static int[] id0(int[][] clusPath, int n)
	{
		int[] iind = new int[n];
		for(int[] path : clusPath){
			for(int i = 0;i < path.length;i++){
				iind[path[i]] = i;
			}
		}
		return iind;
	}
	
	
	static int[][] packU(int n, int[] from, int[] to) {
		int[][] g = new int[n][];
		int[] p = new int[n];
		for(int f : from)
			p[f]++;
		for(int t : to)
			p[t]++;
		for(int i = 0;i < n;i++)
			g[i] = new int[p[i]];
		for(int i = 0;i < from.length;i++){
			g[from[i]][--p[from[i]]] = to[i];
			g[to[i]][--p[to[i]]] = from[i];
		}
		return g;
	}
	
	public static int[][] tree(int n, Random gen)
	{
		int[][] e = new int[n-1][2];
		
		int[] f = new int[n];
		for(int i = 0;i < n;i++)f[i] = i; 

		for(int i = 0;i < n-1;i++) {
			int other = gen.nextInt(n-i)+i;
			int d = f[i]; f[i] = f[other]; f[other] = d;
		}
		
		for(int i = 0;i < n-1;i++) {
			e[i][0] = f[gen.nextInt(i+1)];
			e[i][1] = f[i+1];
		}
		
		

		for(int i = 0;i < n-1-1;i++) {
			int other = gen.nextInt(n-1-i)+i;
			int d;
			d = e[i][0]; e[i][0] = e[other][0]; e[other][0] = d;
			d = e[i][1]; e[i][1] = e[other][1]; e[other][1] = d;
		}
		return e;
	}
	
	void run() throws Exception
	{




























		
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new D().run(); }
	
	private byte[] inbuf = new byte[1024];
	private int lenbuf = 0, ptrbuf = 0;
	
	private int readByte()
	{
		if(lenbuf == -1)throw new InputMismatchException();
		if(ptrbuf >= lenbuf){
			ptrbuf = 0;
			try { lenbuf = is.read(inbuf); } catch (IOException e) { throw new InputMismatchException(); }
			if(lenbuf <= 0)return -1;
		}
		return inbuf[ptrbuf++];
	}
	
	private boolean id1(int c) { return !(c >= 33 && c <= 126); }
	private int skip() { int b; while((b = readByte()) != -1 && id1(b)); return b; }
	
	private double nd() { return Double.parseDouble(ns()); }
	private char nc() { return (char)skip(); }
	
	private String ns()
	{
		int b = skip();
		StringBuilder sb = new StringBuilder();
		while(!(id1(b))){ 

			sb.appendCodePoint(b);
			b = readByte();
		}
		return sb.toString();
	}
	
	private char[] ns(int n)
	{
		char[] buf = new char[n];
		int b = skip(), p = 0;
		while(p < n && !(id1(b))){
			buf[p++] = (char)b;
			b = readByte();
		}
		return n == p ? buf : Arrays.copyOf(buf, p);
	}
	
	private char[][] nm(int n, int m)
	{
		char[][] map = new char[n][];
		for(int i = 0;i < n;i++)map[i] = ns(m);
		return map;
	}
	
	private int[] na(int n)
	{
		int[] a = new int[n];
		for(int i = 0;i < n;i++)a[i] = ni();
		return a;
	}
	
	private int ni()
	{
		int num = 0, b;
		boolean minus = false;
		while((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
		if(b == '-'){
			minus = true;
			b = readByte();
		}
		
		while(true){
			if(b >= '0' && b <= '9'){
				num = num * 10 + (b - '0');
			}else{
				return minus ? -num : num;
			}
			b = readByte();
		}
	}
	
	private long nl()
	{
		long num = 0;
		int b;
		boolean minus = false;
		while((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
		if(b == '-'){
			minus = true;
			b = readByte();
		}
		
		while(true){
			if(b >= '0' && b <= '9'){
				num = num * 10 + (b - '0');
			}else{
				return minus ? -num : num;
			}
			b = readByte();
		}
	}
	
	private boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	private void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}
