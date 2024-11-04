

import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class E3 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	char[] s;
	
	void solve()
	{
		int n = ni();
		int[] from = new int[n - 1];
		int[] to = new int[n - 1];
		for (int i = 0; i < n - 1; i++) {
			from[i] = ni() - 1;
			to[i] = ni() - 1;
		}
		int[][] g = packU(n, from, to);
		int[][] pars = parents3(g, 0);
		par = pars[0];
		dep = pars[2];
		int[] ord = pars[1];
		
		spar = logstepParents(par);
		temp = new int[n];
		
		s = ns(n);
		fvs = new long[n];
		int[] cpar = buildCentroidTree(g);
		dfsTopCT(cpar, g);
		
		for(int i = n-1;i >= 1;i--){
			int cur = ord[i];
			fvs[par[cur]] += fvs[cur];
		}
		for(int i = 0;i < n;i++){
			out.print(fvs[i] + " ");
		}
		out.println();
	}
	
	int[] temp;
	long[] fvs;
	int[] par;
	int[] dep;
	int[][] spar;
	
	public static int[] buildCentroidTree(int[][] g) {
		int n = g.length;
		int[] ctpar = new int[n];
		Arrays.fill(ctpar, -1);
		buildCentroidTree(g, 0, new boolean[n], new int[n], new int[n], new int[n], ctpar);
		return ctpar;
	}
	
	private static int buildCentroidTree(int[][] g, int root, boolean[] sed, int[] par, int[] ord, int[] des, int[] ctpar)
	{
		

		ord[0] = root;
		par[root] = -1;
		int r = 1;
		for(int p = 0;p < r;p++) {
			int cur = ord[p];
			for(int nex : g[cur]){
				if(par[cur] != nex && !sed[nex]){
					ord[r++] = nex;
					par[nex] = cur;
				}
			}
		}
		

		
		

		int sep = -1; 

		outer:
		for(int i = r-1;i >= 0;i--){
			int cur = ord[i];
			des[cur] = 1;
			for(int e : g[cur]){
				if(par[cur] != e && !sed[e])des[cur] += des[e];
			}
			if(r-des[cur] <= r/2){
				for(int e : g[cur]){
					if(par[cur] != e && !sed[e] && des[e] >= r/2+1)continue outer;
				}
				sep = cur;
				break;
			}
		}
		
		sed[sep] = true;
		for(int e : g[sep]){
			if(!sed[e])ctpar[buildCentroidTree(g, e, sed, par, ord, des, ctpar)] = sep;
		}
		return sep;
	}
	
	public static class IntHashCounter {
		public int[] keys;
		public int[] allocated;
		private int scale = 1<<2;
		private int rscale = 1<<1;
		private int mask = scale-1;
		public int size = 0;
		
		public IntHashCounter(){
			allocated = new int[scale];
			Arrays.fill(allocated, NG);
			keys = new int[scale];
		}
		
		

		private static final int NG = 0;
		
		public boolean containsKey(int x)
		{
			int pos = h(x)&mask;
			while(allocated[pos] != NG){
				if(x == keys[pos])return true;
				pos = pos+1&mask;
			}
			return false;
		}
		
		public int get(int x)
		{
			int pos = h(x)&mask;
			while(allocated[pos] != NG){
				if(x == keys[pos])return allocated[pos];
				pos = pos+1&mask;
			}
			return NG;
		}
		
		public long put(int x, int v)
		{
			int pos = h(x)&mask;
			while(allocated[pos] != NG){
				if(x == keys[pos]){
					long oldval = allocated[pos];
					allocated[pos] = v;
					return oldval;
				}
				pos = pos+1&mask;
			}
			if(size == rscale){
				resizeAndPut(x, v);
			}else{
				keys[pos] = x;
				allocated[pos] = v;
			}
			size++;
			return NG;
		}
		
		public int inc(int x, int v)
		{
			int pos = h(x)&mask;
			while(allocated[pos] != NG){
				if(x == keys[pos]){
					allocated[pos] += v;
					return allocated[pos];
				}
				pos = pos+1&mask;
			}
			if(size == rscale){
				resizeAndPut(x, v);
			}else{
				keys[pos] = x;
				allocated[pos] = v;
			}
			size++;
			return v;
		}
		
		private void resizeAndPut(int x, int v)
		{
			int nscale = scale<<1;
			int nrscale = rscale<<1;
			int nmask = nscale-1;
			int[] nallocated = new int[nscale];
			Arrays.fill(nallocated, NG);
			int[] nkeys = new int[nscale];
			for(int i = next(0);i < scale;i = next(i+1)){
				int y = keys[i];
				int pos = h(y)&nmask;
				while(nallocated[pos] != NG)pos = pos+1&nmask;
				nkeys[pos] = y;
				nallocated[pos] = allocated[i];
			}
			{
				int pos = h(x)&nmask;
				while(nallocated[pos] != NG)pos = pos+1&nmask;
				nkeys[pos] = x;
				nallocated[pos] = v;
			}
			allocated = nallocated;
			keys = nkeys;
			scale = nscale;
			rscale = nrscale;
			mask = nmask;
		}
		
		public int next(int itr)
		{
			while(itr < scale && allocated[itr] == NG)itr++;
			return itr;
		}
		
		public int h(int x)
		{
			x ^= x>>>16;
			x *= 0x85ebca6b;
			x ^= x>>>13;
			x *= 0xc2b2ae35;
			x ^= x>>>16;
			return x;
		}
		


















		
		@Override
		public String toString()
		{
			StringBuilder sb = new StringBuilder();
			for(int i = next(0);i < scale;i = next(i+1)){
				sb.append(",");
				sb.append(keys[i] + ":" + allocated[i]);
			}
			return sb.length() == 0 ? "" : sb.substring(1);
		}
	}

	
	public void dfsTopCT(int[] cpar, int[][] g) {
		int n = g.length;
		int ctroot = -1;
		for(int i = 0;i < n;i++)if(cpar[i] == -1)ctroot = i;
		int[][] ctch = parentToChildren(cpar);
		long I = Long.MAX_VALUE / 2;
		long[] dd = new long[n];
		Arrays.fill(dd, I);
		dfs(ctroot, new boolean[n], new long[n], new long[n][], dd,
				new int[n], new int[n], g, ctch);
	}
	
	public static int[][] parentToChildren(int[] par)
	{
		int n = par.length;
		int[] ct = new int[n];
		for(int i = 0;i < n;i++){
			if(par[i] >= 0){
				ct[par[i]]++;
			}
		}
		int[][] g = new int[n][];
		for(int i = 0;i < n;i++){
			g[i] = new int[ct[i]];
		}
		for(int i = 0;i < n;i++){
			if(par[i] >= 0){
				g[par[i]][--ct[par[i]]] = i;
			}
		}
		
		return g;
	}

	
	private void dfs(int sep, boolean[] seps, long[] ds, long[][] dss, long[] dd,
			int[] stack, int[] inds, int[][] g, int[][] ctch)
	{
		long I = Long.MAX_VALUE / 2;
		seps[sep] = true;
		int neckp = 0;
		for(int neck : g[sep]){
			if(seps[neck])continue;
			int sp = 0;
			inds[sp] = 0;
			stack[sp++] = neck;
			int gdp = 0;
			dd[neck] = 1L<<s[neck]-'a'+32|neck;
			while(sp > 0){
				int cur = stack[sp-1];
				if(inds[sp-1] == 0){
					ds[gdp++] = dd[cur];
				}
				if(inds[sp-1] == g[cur].length){
					sp--; 
					dd[cur] = I;
					continue; 
				}
				int e = g[cur][inds[sp-1]++];
				if(!seps[e] && dd[e] == I){
					dd[e] = (dd[cur]>>>32 ^ 1L<<s[e]-'a')<<32|e;
					stack[sp] = e;
					inds[sp] = 0;
					sp++;
				}
			}
			dss[neckp++] = Arrays.copyOf(ds, gdp);
		}
		
		process(sep, dss, neckp, g);
		
		for(int e : ctch[sep]){
			dfs(e, seps, ds, dss, dd, stack, inds, g, ctch);
		}
		seps[sep] = false;
	}
	
	void process(int sep, long[][] dss, int t, int[][] g)
	{
		IntHashCounter lhc = new IntHashCounter();
		for(int u = 0;u < t;u++){
			long[] ds = dss[u];
			for(long e : ds){
				lhc.inc((int)(e>>>32), 1);
			}
		}
		lhc.inc(0, 1);
		{
			long h = 0;
			for(int u = 0;u < t;u++){
				long[] ds = dss[u];
				for(long e : ds){
					int fv = 0;
					{
						long v = e>>>32^1<<s[sep]-'a';
						fv += lhc.get((int)v);
					}
					for(int j = 0;j < 20;j++){
						long v = e>>>32^1<<s[sep]-'a'^1<<j;
						fv += lhc.get((int)v);
					}
					fv++;
					int node = (int)e;
					h += fv;
					int lca = lca2(node, sep, spar, dep);
					temp[node] = lca;
					fvs[node] += fv;
					fvs[sep] += fv;
					fvs[lca] -= fv;
					if(par[lca] != -1)fvs[par[lca]] -= fv;
				}
			}
			{
				int fv = 0;
				{
					long v = 0^1<<s[sep]-'a';
					fv += lhc.get((int)v);
				}
				for(int j = 0;j < 20;j++){
					long v = 0^1<<s[sep]-'a'^1<<j;
					fv += lhc.get((int)v);
				}
				fv++;
				int node = sep;
				h += fv;
				int lca = lca2(node, sep, spar, dep);
				temp[node] = lca;
				fvs[node] += fv;
				fvs[sep] += fv;
				fvs[lca] -= fv;
				if(par[lca] != -1)fvs[par[lca]] -= fv;
			}
			fvs[sep] -= h/2;
			if(par[sep] != -1)fvs[par[sep]] += h/2;
		}
		
		for(int u = 0;u < t;u++){
			long[] ds = dss[u];
			if(ds.length >= 40){
				IntHashCounter llhc = new IntHashCounter();
				for(long e : ds){
					llhc.inc((int)(e>>>32), 1);
				}
				{
					long h = 0;
					for(long e : ds){
						int fv = 0;
						{
							long v = e>>>32^1<<s[sep]-'a';
							fv += llhc.get((int)v);
						}
						for(int j = 0;j < 20;j++){
							long v = e>>>32^1<<s[sep]-'a'^1<<j;
							fv += llhc.get((int)v);
						}
						fv++;
						fv = -fv;
						int node = (int)e;
						h += fv;
						int lca = temp[node]; 

						fvs[node] += fv;
						fvs[sep] += fv;
						fvs[lca] -= fv;
						if(par[lca] != -1)fvs[par[lca]] -= fv;
					}
					fvs[sep] -= h/2;
					if(par[sep] != -1)fvs[par[sep]] += h/2;
				}
			}else{
				long h = 0;
				for(long e : ds){
					int fv = 0;
					for(long q : ds){
						long v = e>>>32^q>>>32^1<<s[sep]-'a';
						if((v&v-1) == 0)fv++;
					}
					fv++;
					fv = -fv;
					int node = (int)e;
					h += fv;
					int lca = temp[node]; 

					fvs[node] += fv;
					fvs[sep] += fv;
					fvs[lca] -= fv;
					if(par[lca] != -1)fvs[par[lca]] -= fv;
				}
				fvs[sep] -= h/2;
				if(par[sep] != -1)fvs[par[sep]] += h/2;
			}
		}
	}
































































	
	public static int lca2(int a, int b, int[][] spar, int[] depth) {
		if (depth[a] < depth[b]) {
			b = ancestor(b, depth[b] - depth[a], spar);
		} else if (depth[a] > depth[b]) {
			a = ancestor(a, depth[a] - depth[b], spar);
		}

		if (a == b)
			return a;
		int sa = a, sb = b;
		for (int low = 0, high = depth[a], t = Integer.highestOneBit(high), k = Integer
				.numberOfTrailingZeros(t); t > 0; t >>>= 1, k--) {
			if ((low ^ high) >= t) {
				if (spar[k][sa] != spar[k][sb]) {
					low |= t;
					sa = spar[k][sa];
					sb = spar[k][sb];
				} else {
					high = low | t - 1;
				}
			}
		}
		return spar[0][sa];
	}

	protected static int ancestor(int a, int m, int[][] spar) {
		for (int i = 0; m > 0 && a != -1; m >>>= 1, i++) {
			if ((m & 1) == 1)
				a = spar[i][a];
		}
		return a;
	}

	public static int[][] logstepParents(int[] par) {
		int n = par.length;
		int m = Integer.numberOfTrailingZeros(Integer.highestOneBit(n - 1)) + 1;
		int[][] pars = new int[m][n];
		pars[0] = par;
		for (int j = 1; j < m; j++) {
			for (int i = 0; i < n; i++) {
				pars[j][i] = pars[j - 1][i] == -1 ? -1 : pars[j - 1][pars[j - 1][i]];
			}
		}
		return pars;
	}

	
	public static int lowerBound(long[] a, long v){ return lowerBound(a, 0, a.length, v); }
	public static int lowerBound(long[] a, int l, int r, long v)
	{


		int low = l-1, high = r;
		while(high-low > 1){
			int h = high+low>>>1;
			if(a[h] >= v){
				high = h;
			}else{
				low = h;
			}
		}
		return high;
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
	
	public static void main(String[] args) throws Exception { new E3().run(); }
	
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
