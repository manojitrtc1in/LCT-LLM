

import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class E {
	InputStream is;
	PrintWriter out;
	String INPUT = "";

	void solve()
	{
		int n = ni(),  Q= ni();
		int[] par = new int[n];
		par[0] = -1;
		for(int i = 1;i < n;i++)par[i] = ni()-1;
		int[] t = na(n);
		
		int[][] g = id1(par);
		int[][] pars = parents3(g, 0);
		int[] ord = pars[1], dep = pars[2];
		id4 hld = new id4(g, par, ord, dep);
		
		int[] des = new int[n];
		Arrays.fill(des, 1);
		for(int i = n-1;i > 0;i--){
			des[par[ord[i]]] += des[ord[i]];
		}
		
		HitCounter[] hcs = new HitCounter[hld.m];
		int ans = 0;
		for(int i = 0;i < hld.m;i++){
			int[] ldes = new int[hld.cluspath[i].length];
			for(int j = 0;j < hld.cluspath[i].length;j++){
				ldes[j] = -t[hld.cluspath[i][j]]-1;
				if(ldes[j] >= 0)ans++;
			}
			hcs[i] = new HitCounter(ldes);
		}
		
		int big = 1000000;
		for(int z = 0;z < Q;z++){
			int q = ni();
			int id = Math.abs(q) - 1;
			int io = q > 0 ? 1 : -1;
			
			if(io == 1 && hcs[hld.clus[id]].val(hld.id5[id]) >= 0)ans--;
			hcs[hld.clus[id]].add(hld.id5[id], hld.id5[id]+1, io*big);
			if(io == -1 && hcs[hld.clus[id]].val(hld.id5[id]) >= 0)ans++;
			
			for(int x = id;x != -1;){
				int cx = hld.clus[x];
				int l = 0;
				int r = hld.id5[x];
				
				hcs[cx].add(l, r+1, io);
				if(io < 0){
					ans -= hcs[cx].countEq(l, r+1, -1);
				}else{
					ans += hcs[cx].countEq(l, r+1, 0);
				}
			
				x = par[hld.cluspath[cx][0]];
			}
			out.print(ans + " ");
		}
	}
	
	public static int[][] id1(int[] par)
	{
		int n = par.length;
		int[] ct = new int[n];
		for(int i = 0;i < n;i++){
			if(par[i] >= 0){
				ct[i]++;
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
				g[i][--ct[i]] = par[i];
			}
		}
		return g;
	}

	
	public static class id4 {
		public int[][] g;
		public int[] clus;
		public int[][] cluspath;
		public int[] id5;
		public int[] par, dep;
		public int m;
		
		public id4(int[][] g, int[] par, int[] ord, int[] dep)
		{
			init(g, par, ord, dep);
		}
		
		public void init(int[][] g, int[] par, int[] ord, int[] dep)
		{
			clus = id6(g, par, ord);
			cluspath = clusPaths(clus, ord);
			id5 = id0(cluspath, g.length);
			this.m = cluspath.length;
			this.par = par;
			this.dep = dep;
			this.g = g;
		}
		
		public static int[] id6(int[][] g, int[] par, int[] ord)
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
			return id5[x] > id5[y] ? y : x;
		}
		
		public int ancestor(int x, int v)
		{
			while(x != -1){
				if(v <= id5[x])return cluspath[clus[x]][id5[x]-v];
				v -= id5[x]+1;
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
		
		

		
		
		
	}

	
	public static class HitCounter
	{
		public int[] a;
		int n;
		int B;
		public id3[] hits;
		public int[] pluss;
		
		public HitCounter(int[] a)
		{
			this.a = a;
			n = a.length;
			B = Math.max(1, (int)Math.sqrt(n)/3);
			hits = new id3[n/B+1];
			pluss = new int[n/B+1];
			for(int i = 0;i < n/B+1;i++){
				make(i);
			}
		}
		
		private void make(int x)
		{
			id3 map = new id3();
			for(int i = x*B;i < n && i < x*B+B;i++){
				map.inc(a[i], 1);
			}
			hits[x] = map;
		}
		
		public void add(int l, int r, int v)
		{
			r--;
			if(l/B >= r/B){
				for(int i = l;i <= r;i++){
					a[i] += v;
				}
				make(l/B);
			}else{
				for(int i = l;i < l/B*B+B && i < n;i++)a[i] += v;
				make(l/B);
				for(int i = r/B*B;i <= r;i++)a[i] += v;
				make(r/B);
				for(int i = l/B+1;i < r/B;i++)pluss[i] += v;
			}
		}
		
		public int countEq(int l, int r, int v)
		{
			r--;
			if(l/B >= r/B){
				int ct = 0;
				for(int i = l;i <= r;i++){
					if(a[i]+pluss[l/B] == v)ct++;
				}
				return ct;
			}else{
				int ct = 0;
				for(int i = l;i < l/B*B+B && i < n;i++){
					if(a[i]+pluss[l/B] == v)ct++;
				}
				for(int i = r/B*B;i <= r;i++){
					if(a[i]+pluss[r/B] == v)ct++;
				}
				for(int i = l/B+1;i < r/B;i++){
					ct += hits[i].get(v-pluss[i]);






				}
				return ct;
			}
		}
		
		public int val(int x)
		{
			return a[x] + pluss[x/B];
		}
	}
	
	public static class id3 {
		public int[] keys;
		public long[] allocated;
		private int scale = 1<<2;
		private int rscale = 1<<1;
		private int mask = scale-1;
		public int size = 0;
		
		public id3(){
			allocated = new long[scale];
			Arrays.fill(allocated, NG);
			keys = new int[scale];
		}
		
		

		private static final long NG = 0;
		
		public boolean containsKey(int x)
		{
			int pos = h(x)&mask;
			while(allocated[pos] != NG){
				if(x == keys[pos])return true;
				pos = pos+1&mask;
			}
			return false;
		}
		
		public long get(int x)
		{
			int pos = h(x)&mask;
			while(allocated[pos] != NG){
				if(x == keys[pos])return allocated[pos];
				pos = pos+1&mask;
			}
			return NG;
		}
		
		public long put(int x, long v)
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
				id7(x, v);
			}else{
				keys[pos] = x;
				allocated[pos] = v;
			}
			size++;
			return NG;
		}
		
		public long inc(int x, long v)
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
				id7(x, v);
			}else{
				keys[pos] = x;
				allocated[pos] = v;
			}
			size++;
			return v;
		}
		
		public boolean remove(int x)
		{
			int pos = h(x)&mask;
			while(allocated[pos] != NG){
				if(x == keys[pos]){
					size--;
					

					int last = pos;
					pos = pos+1&mask;
					while(allocated[pos] != NG){
						int lh = h(keys[pos])&mask;
						

						if(
								lh <= last && last < pos ||
								pos < lh && lh <= last ||
								last < pos && pos < lh
								){
							keys[last] = keys[pos];
							allocated[last] = allocated[pos];
							last = pos;
						}
						pos = pos+1&mask;
					}
					keys[last] = 0;
					allocated[last] = NG;
					
					return true;
				}
				pos = pos+1&mask;
			}
			return false;
		}
		
		private void id7(int x, long v)
		{
			int nscale = scale<<1;
			int nrscale = rscale<<1;
			int nmask = nscale-1;
			long[] nallocated = new long[nscale];
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

	
	void run() throws Exception
	{
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new E().run(); }
	
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
	
	private boolean id2(int c) { return !(c >= 33 && c <= 126); }
	private int skip() { int b; while((b = readByte()) != -1 && id2(b)); return b; }
	
	private double nd() { return Double.parseDouble(ns()); }
	private char nc() { return (char)skip(); }
	
	private String ns()
	{
		int b = skip();
		StringBuilder sb = new StringBuilder();
		while(!(id2(b))){ 

			sb.appendCodePoint(b);
			b = readByte();
		}
		return sb.toString();
	}
	
	private char[] ns(int n)
	{
		char[] buf = new char[n];
		int b = skip(), p = 0;
		while(p < n && !(id2(b))){
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
