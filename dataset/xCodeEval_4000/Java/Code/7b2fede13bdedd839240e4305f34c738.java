

import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.List;

public class G {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), Q = ni();
		int[] from = new int[n-1];
		int[] to = new int[n-1];
		for(int i = 0;i < n-1;i++){
			from[i] = ni()-1;
			to[i] = ni()-1;
		}
		int[][] g = packU(n, from, to);
		int[][] pars = parents3(g, 0);
		int[] par = pars[0], dep = pars[2];
		
		int[] ord = new int[n];
		sortByPreorder(g, 0, ord, 0, -1);
		LST black = new LST(n);
		int[] iord = new int[n];
		for(int i = 0;i < n;i++)iord[ord[i]] = i;
		
		
		HeavyLightDecomposition hld = new HeavyLightDecomposition(g, par, pars[1], dep);
		int[][][] sts = new int[hld.m][][];
		for(int i = 0;i < hld.m;i++){
			sts[i] = build(hld.cluspath[i]);
		}
		
		int last = 0;
		int minind = n+114;
		int alca = -1;
		for(int z = 0;z < Q;z++){
			int t = ni();
			int u = (ni()+last)%n;
			if(t == 1){
				if(black.get(iord[u]))continue;
				if(alca != -1){
					int lca = hld.lca(u, alca);
					if(lca != alca){
						for(int x = u;x != par[lca];x = par[x]){
							black.set(iord[x]);
							minind = Math.min(minind, x);
						}
						for(int x = alca;x != par[lca];x = par[x]){
							black.set(iord[x]);
							minind = Math.min(minind, x);
						}
						alca = lca;
						continue;
					}
				}
				int pr = black.prev(iord[u]);
				int ne = black.next(iord[u]);
				int cl = -1;
				if(pr != -1){
					int lu = hld.lca(ord[pr], u);
					if(cl == -1 || dep[cl] < dep[lu]){
						cl = lu;
					}
				}
				if(ne != -1){
					int lu = hld.lca(ord[ne], u);
					if(cl == -1 || dep[cl] < dep[lu]){
						cl = lu;
					}
				}
				if(cl == -1){
					cl = u;
					alca = u;
				}
				for(int x = u;x != par[cl];x = par[x]){
					black.set(iord[x]);
					minind = Math.min(minind, x);
				}
			}else{
				if(black.get(iord[u])){
					out.println(last = minind+1); continue;
				}
				if(alca != -1){
					int lca = hld.lca(u, alca);
					if(lca != alca){
						int ret = minind;
						ret = Math.min(ret, hld.min(u, lca, sts));
						ret = Math.min(ret, hld.min(alca, lca, sts));
						out.println(last = ret+1);
						continue;
					}
				}
				
				int pr = black.prev(iord[u]);
				int ne = black.next(iord[u]);
				int cl = -1;
				if(pr != -1){
					int lu = hld.lca(ord[pr], u);
					if(cl == -1 || dep[cl] < dep[lu]){
						cl = lu;
					}
				}
				if(ne != -1){
					int lu = hld.lca(ord[ne], u);
					if(cl == -1 || dep[cl] < dep[lu]){
						cl = lu;
					}
				}
				assert cl != -1;
				out.println(last = Math.min(minind, hld.min(u, cl, sts)) + 1);
			}
		}
	}
	
	public static int[][] build(int[] a)
	{
		int n = a.length;
		int b = 32-Integer.numberOfLeadingZeros(n);
		int[][] ret = new int[b][];
		for(int i = 0, l = 1;i < b;i++, l*=2) {
			if(i == 0) {
				ret[i] = a;
			}else {
				ret[i] = new int[n-l+1];
				for(int j = 0;j < n-l+1;j++) {
					ret[i][j] = Math.min(ret[i-1][j], ret[i-1][j+l/2]);
				}
			}
		}
		return ret;
	}
	
	

	public static int rmq(int[][] or, int l, int r)
	{
		assert l <= r;
		if(l >= r)return Integer.MAX_VALUE;
		

		int t = 31-Integer.numberOfLeadingZeros(r-l);
		return Math.min(or[t][l], or[t][r-(1<<t)]);
	}

	
	public static class HeavyLightDecomposition {
		public int[][] g;
		public int[] clus;
		public int[][] cluspath;
		public int[] clusiind;
		public int[] par, dep;
		public int m;
		
		public HeavyLightDecomposition(int[][] g, int[] par, int[] ord, int[] dep)
		{
			init(g, par, ord, dep);
		}
		
		public void init(int[][] g, int[] par, int[] ord, int[] dep)
		{
			clus = decomposeToHeavyLight(g, par, ord);
			cluspath = clusPaths(clus, ord);
			clusiind = clusIInd(cluspath, g.length);
			this.m = cluspath.length;
			this.par = par;
			this.dep = dep;
			this.g = g;
		}
		
		public static int[] decomposeToHeavyLight(int[][] g, int[] par, int[] ord)
		{
			int n = g.length;
			int[] size = new int[n];
			Arrays.fill(size, 1);
			for(int i = n-1;i > 0;i--)size[par[ord[i]]] += size[ord[i]];
			
			int[] clus = new int[n];
			Arrays.fill(clus, -1);
			int p = 0;
			for(int i = 0;i < n;i++){
				int u = ord[i];
				if(clus[u] == -1)clus[u] = p++;
				

				int argmax = -1;
				for(int v : g[u]){
					if(par[u] != v && (argmax == -1 || size[v] > size[argmax]))argmax = v;
				}
				if(argmax != -1)clus[argmax] = clus[u];
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
		
		public static int[] clusIInd(int[][] clusPath, int n)
		{
			int[] iind = new int[n];
			for(int[] path : clusPath){
				for(int i = 0;i < path.length;i++){
					iind[path[i]] = i;
				}
			}
			return iind;
		}
		
		public int lca(int x, int y)
		{
			int rx = cluspath[clus[x]][0];
			int ry = cluspath[clus[y]][0];
			while(clus[x] != clus[y]){
				if(dep[rx] > dep[ry]){
					x = par[rx];
					rx = cluspath[clus[x]][0];
				}else{
					y = par[ry];
					ry = cluspath[clus[y]][0];
				}
			}
			return clusiind[x] > clusiind[y] ? y : x;
		}
		
		public int min(int u, int anc, int[][][] sts)
		{
			int min = Integer.MAX_VALUE;
			for(int x = u;;){
				int cx = clus[x];
				int l = cx == clus[anc] ? clusiind[anc] : 0;
				int r = clusiind[x];
			
				min = Math.min(min, rmq(sts[cx], l, r+1));
			
				if(cx == clus[anc])break;
				x = par[cluspath[cx][0]];
			}
			return min;
		}
		
		public int ancestor(int x, int v)
		{
			while(x != -1){
				if(v <= clusiind[x])return cluspath[clus[x]][clusiind[x]-v];
				v -= clusiind[x]+1;
				x = par[cluspath[clus[x]][0]];
			}
			return x;
		}
		
		

		

		public int[][] makeRights()
		{
			int root = -1;
			int n = g.length;
			for(int i = 0;i < n;i++)if(par[i] == -1)root = i;
			
			int[] ord = new int[n];
			int[] right = new int[n];
			
			int[] curs = new int[n];
			int[] inds = new int[n];
			int sp = 0, p = 0;
			curs[sp++] = root;
			while(sp > 0){
				int cur = curs[sp-1];
				int ind = inds[sp-1];
				inds[sp-1]++;
				if(ind == 0){
					ord[p++] = cur;
					for(int e : g[cur]){
						if(par[cur] == e)continue;
						if(clus[cur] == clus[e]){
							curs[sp] = e;
							inds[sp] = 0;
							sp++;
							break;
						}
					}
				}else if(ind-1 < g[cur].length){
					int e = g[cur][ind-1];
					if(e == par[cur])continue;
					if(clus[cur] == clus[e])continue;
					curs[sp] = e;
					inds[sp] = 0;
					sp++;
				}else{
					right[cur] = p;
					sp--;
				}
			}
			int[] iord = new int[n];
			for(int i = 0;i < n;i++)iord[ord[i]] = i;
			return new int[][]{ord, iord, right};
		}
		
		

		
		
		
		public void queryNew(int u, int anc, int v)
		{
		}
	}

	
	public static class LST {
		public long[][] set;
		public int n;


		
		public LST(int n) {
			this.n = n;
			int d = 1;
			for(int m = n;m > 1;m>>>=6, d++);
			
			set = new long[d][];
			for(int i = 0, m = n>>>6;i < d;i++, m>>>=6){
				set[i] = new long[m+1];
			}


		}
		
		

		public LST setRange(int r)
		{
			for(int i = 0;i < set.length;i++, r=r+63>>>6){
				for(int j = 0;j < r>>>6;j++){
					set[i][j] = -1L;
				}
				if((r&63) != 0)set[i][r>>>6] |= (1L<<r)-1;
			}
			return this;
		}
		
		

		public LST unsetRange(int r)
		{
			if(r >= 0){
				for(int i = 0;i < set.length;i++, r=r+63>>>6){
					for(int j = 0;j < r+63>>>6;j++){
						set[i][j] = 0;
					}
					if((r&63) != 0)set[i][r>>>6] &= ~((1L<<r)-1);
				}
			}
			return this;
		}
		
		public LST set(int pos)
		{
			if(pos >= 0 && pos < n){


				for(int i = 0;i < set.length;i++, pos>>>=6){
					set[i][pos>>>6] |= 1L<<pos;
				}
			}
			return this;
		}
		
		public LST unset(int pos)
		{
			if(pos >= 0 && pos < n){


				for(int i = 0;i < set.length && (i == 0 || set[i-1][pos] == 0L);i++, pos>>>=6){
					set[i][pos>>>6] &= ~(1L<<pos);
				}
			}
			return this;
		}
		
		public boolean get(int pos)
		{
			return pos >= 0 && pos < n && set[0][pos>>>6]<<~pos<0;
		}
		
		public int prev(int pos)
		{
			for(int i = 0;i < set.length && pos >= 0;i++, pos>>>=6, pos--){
				int pre = prev(set[i][pos>>>6], pos&63);
				if(pre != -1){
					pos = pos>>>6<<6|pre;
					while(i > 0)pos = pos<<6|63-Long.numberOfLeadingZeros(set[--i][pos]);
					return pos;
				}
			}
			return -1;
		}
		
		public int next(int pos)
		{
			for(int i = 0;i < set.length && pos>>>6 < set[i].length;i++, pos>>>=6, pos++){
				int nex = next(set[i][pos>>>6], pos&63);
				if(nex != -1){
					pos = pos>>>6<<6|nex;
					while(i > 0)pos = pos<<6|Long.numberOfTrailingZeros(set[--i][pos]);
					return pos;
				}
			}
			return -1;
		}
		
		private static int prev(long set, int n)
		{
			long h = Long.highestOneBit(set<<~n);
			if(h == 0L)return -1;
			return Long.numberOfTrailingZeros(h)-(63-n);
		}
		
		private static int next(long set, int n)
		{
			long h = Long.lowestOneBit(set>>>n);
			if(h == 0L)return -1;
			return Long.numberOfTrailingZeros(h)+n;
		}
		
		@Override
		public String toString()
		{
			List<Integer> list = new ArrayList<Integer>();
			for(int pos = next(0);pos != -1;pos = next(pos+1)){
				list.add(pos);
			}
			return list.toString();
		}
	}

	
	public static int sortByPreorder(int[][] g, int cur, int[] ord, int pos, int prev)
	{
		ord[pos++] = cur;
		for(int e : g[cur])if(prev != e)pos = sortByPreorder(g, e, ord, pos, cur);
		return pos;
	}

	
		
		public static int[][] parents3(int[][] g, int root) {
			int n = g.length;
			int[] par = new int[n];
			Arrays.fill(par, -1);
			
			int[] depth = new int[n];
			depth[0] = 0;
			
			int[] q = new int[n];
			q[0] = root;
			for (int p = 0, r = 1; p < r; p++) {
				int cur = q[p];
				for (int nex : g[cur]) {
					if (par[cur] != nex) {
						q[r++] = nex;
						par[nex] = cur;
						depth[nex] = depth[cur] + 1;
					}
				}
			}
			return new int[][] { par, q, depth };
		}
		
		static int[][] packU(int n, int[] from, int[] to) {
			int[][] g = new int[n][];
			int[] p = new int[n];
			for (int f : from)
				p[f]++;
			for (int t : to)
				p[t]++;
			for (int i = 0; i < n; i++)
				g[i] = new int[p[i]];
			for (int i = 0; i < from.length; i++) {
				g[from[i]][--p[from[i]]] = to[i];
				g[to[i]][--p[to[i]]] = from[i];
			}
			return g;
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
	
	public static void main(String[] args) throws Exception { new G().run(); }
	
	private byte[] inbuf = new byte[1024];
	public int lenbuf = 0, ptrbuf = 0;
	
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
	
	private boolean isSpaceChar(int c) { return !(c >= 33 && c <= 126); }
	private int skip() { int b; while((b = readByte()) != -1 && isSpaceChar(b)); return b; }
	
	private double nd() { return Double.parseDouble(ns()); }
	private char nc() { return (char)skip(); }
	
	private String ns()
	{
		int b = skip();
		StringBuilder sb = new StringBuilder();
		while(!(isSpaceChar(b))){ 

			sb.appendCodePoint(b);
			b = readByte();
		}
		return sb.toString();
	}
	
	private char[] ns(int n)
	{
		char[] buf = new char[n];
		int b = skip(), p = 0;
		while(p < n && !(isSpaceChar(b))){
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
