

import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class G {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), Q = ni();
		char[] s = ns(n);
		
		int[] sa = sa(s);
		int[] lcp = id1(s, sa);
		int[] llcp = new int[2*n-1];
		for(int i = 0;i < n;i++) {
			llcp[2*i] = n-sa[i];
		}
		for(int i = 1;i < n;i++){
			llcp[2*i-1] = lcp[i];
		}
		
		int[] par = id6(llcp);
		int[][] g = id2(par);
		
		int root = -1;
		for(int i = 0;i < 2*n-1;i++){
			if(par[i] == -1)root = i;
		}
		
		int[][] pars = parents3(g, root);
		int[] ord = pars[1], dep = pars[2];
		
		for(int i = 2*n-2;i > 0;i--) {
			int cur = ord[i];
			llcp[cur] -= llcp[par[cur]];
		}
		
		id8 hld = new id8(g, par, ord, dep);
		id7[] sts = new id7[hld.m];
		for(int i = 0;i < hld.m;i++){
			int[] lws = new int[hld.cluspath[i].length];
			for(int j = 0;j < hld.cluspath[i].length;j++){
				lws[j] = llcp[hld.cluspath[i][j]];
			}
			sts[i] = new id7(lws);
		}
		int[] isa = new int[n];
		for(int i =0 ;i < n;i++)isa[sa[i]] = i;
		
		for(int z = 0;z < Q;z++){
			int K = ni(), L = ni();
			int[] qa = na(K);
			int[] qb = na(L);
			for(int j = 0;j < K;j++){
				for(int x = 2*(isa[qa[j]-1]);x != -1;){
					int cx = hld.clus[x];
					int l = 0;
					int r = hld.id9[x];
				
					sts[cx].add(l, r+1, 1); 

				
					x = par[hld.cluspath[cx][0]];
				}
			}
			long ans = 0;
			for(int j = 0;j < L;j++){
				for(int x = 2*(isa[qb[j]-1]);x != -1;){
					int cx = hld.clus[x];
					int l = 0;
					int r = hld.id9[x];
				
					ans += sts[cx].sum(l, r+1);
				
					x = par[hld.cluspath[cx][0]];
				}
			}
			out.println(ans);
			
			for(int j = 0;j < K;j++){
				for(int x = 2*(isa[qa[j]-1]);x != -1;){
					int cx = hld.clus[x];
					int l = 0;
					int r = hld.id9[x];
				
					sts[cx].add(l, r+1, -1); 

				
					x = par[hld.cluspath[cx][0]];
				}
			}
		}
	}
	
	public static class id7 {
		public int M, H, N;
		public long[] st;
		public long[] plus;
		public long[] cum;
		
		public id7(int[] w)
		{
			N = w.length;
			M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
			H = M>>>1;
			st = new long[M];
			plus = new long[H];
			cum = new long[H+1];
			for(int i = 0;i < H;i++){
				cum[i+1] = cum[i] + (i < w.length ? w[i] : 0);
			}
		}
		
		public id7(int[] a, int[] w)
		{
			N = a.length;
			M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
			H = M>>>1;
			st = new long[M];
			plus = new long[H];
			for(int i = 0;i < N;i++){
				st[H+i] = a[i];
			}
			cum = new long[H+1];
			for(int i = 0;i < H;i++){
				cum[i+1] = cum[i] + (i < w.length ? w[i] : 0);
			}
			for(int i = (M>>1)-1;i >= 1;i--){
				propagate(i);
			}
		}
		
		public void add(int pos, long v)
		{
			v *= cum[pos+1] - cum[pos];
			for(int i = H+pos;i >= 1;i >>>= 1){
				st[i] += v;
			}
		}
		
		private void propagate(int i)
		{
			int count = H/Integer.highestOneBit(i);
			int head = count*(i-Integer.highestOneBit(i));
			st[i] = st[2*i]+st[2*i+1]+plus[i]*(cum[head+count] - cum[head]);
		}
		
		public void add(int l, int r, int v) { if(l < r)add(l, r, v, 0, H, 1); }
		
		private void add(int l, int r, int v, int cl, int cr, int cur)
		{
			if(cur >= H){
				st[cur] += v*(cum[cur-H+1] - cum[cur-H]);
			}else if(l <= cl && cr <= r){
				plus[cur] += v;
				propagate(cur);
			}else{
				int mid = cl+cr>>>1;
				if(cl < r && l < mid){
					add(l, r, v, cl, mid, 2*cur);
				}
				if(mid < r && l < cr){
					add(l, r, v, mid, cr, 2*cur+1);
				}
				propagate(cur);
			}
		}
		
		private long gsum;
		
		public long sum(int l, int r) { 
			gsum = 0;
			sum(l, r, 0, H, 1);
			return gsum;
		}
		
		private void sum(int l, int r, int cl, int cr, int cur)
		{
			if(l <= cl && cr <= r){
				gsum += st[cur];
			}else{
				int mid = cl+cr>>>1;
				if(cl < r && l < mid){
					sum(l, r, cl, mid, 2*cur);
				}
				if(mid < r && l < cr){
					sum(l, r, mid, cr, 2*cur+1);
				}
				gsum += plus[cur]*(cum[Math.min(r,cr)]-cum[Math.max(l,cl)]);
			}
		}
	}
	
	public static class id8 {
		public int[][] g;
		public int[] clus;
		public int[][] cluspath;
		public int[] id9;
		public int[] par, dep;
		public int m;
		
		public id8(int[][] g, int[] par, int[] ord, int[] dep)
		{
			init(g, par, ord, dep);
		}
		
		public void init(int[][] g, int[] par, int[] ord, int[] dep)
		{
			clus = id11(g, par, ord);
			cluspath = clusPaths(clus, ord);
			id9 = id0(cluspath, g.length);
			this.m = cluspath.length;
			this.par = par;
			this.dep = dep;
			this.g = g;
		}
		
		public static int[] id11(int[][] g, int[] par, int[] ord)
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
			return id9[x] > id9[y] ? y : x;
		}
		
		public int ancestor(int x, int v)
		{
			while(x != -1){
				if(v <= id9[x])return cluspath[clus[x]][id9[x]-v];
				v -= id9[x]+1;
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

	
	public static int[][] id2(int[] par)
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
	

	
	int[] id6(int[] a)
	{
		int n = a.length;
		int[] L = new int[n];
		for(int i = 0;i < n;i++){
			L[i] = i-1;
			while(L[i] >= 0 && a[L[i]] > a[i])L[i] = L[L[i]];
		}
		
		int[] R = new int[n];
		for(int i = n-1;i >= 0;i--){
			R[i] = i+1;
			while(R[i] < n && a[R[i]] >= a[i])R[i] = R[R[i]];
		}
		
		int[] par = new int[n];
		for(int i = 0;i < n;i++){
			if(L[i] == -1){
				par[i] = R[i] == n ? -1 : R[i];
			}else{
				par[i] = R[i] == n ? L[i] : a[L[i]] <= a[R[i]] ? R[i] : L[i];
			}
		}
		return par;
	}
	
	
	
	private static interface BaseArray {
		public int get(int i);

		public void set(int i, int val);

		public int update(int i, int val);
	}

	private static class CharArray implements BaseArray {
		private char[] m_A = null;
		private int m_pos = 0;

		CharArray(char[] A, int pos) {
			m_A = A;
			m_pos = pos;
		}

		public int get(int i) {
			return m_A[m_pos + i] & 0xffff;
		}

		public void set(int i, int val) {
			m_A[m_pos + i] = (char) (val & 0xffff);
		}

		public int update(int i, int val) {
			return m_A[m_pos + i] += val & 0xffff;
		}
	}

	private static class IntArray implements BaseArray {
		private int[] m_A = null;
		private int m_pos = 0;

		IntArray(int[] A, int pos) {
			m_A = A;
			m_pos = pos;
		}

		public int get(int i) {
			return m_A[m_pos + i];
		}

		public void set(int i, int val) {
			m_A[m_pos + i] = val;
		}

		public int update(int i, int val) {
			return m_A[m_pos + i] += val;
		}
	}

	
	private static void getCounts(BaseArray T, BaseArray C, int n, int k) {
		int i;
		for(i = 0;i < k;++i){
			C.set(i, 0);
		}
		for(i = 0;i < n;++i){
			C.update(T.get(i), 1);
		}
	}

	private static void getBuckets(BaseArray C, BaseArray B, int k, boolean end) {
		int i, sum = 0;
		if(end != false){
			for(i = 0;i < k;++i){
				sum += C.get(i);
				B.set(i, sum);
			}
		}else{
			for(i = 0;i < k;++i){
				sum += C.get(i);
				B.set(i, sum - C.get(i));
			}
		}
	}

	
	private static void id5(BaseArray T, int[] SA, BaseArray C,
			BaseArray B, int n, int k) {
		int b, i, j;
		int c0, c1;
		
		if(C == B){
			getCounts(T, C, n, k);
		}
		getBuckets(C, B, k, false); 
		j = n - 1;
		b = B.get(c1 = T.get(j));
		--j;
		SA[b++] = (T.get(j) < c1) ? ~j : j;
		for(i = 0;i < n;++i){
			if(0 < (j = SA[i])){
				if((c0 = T.get(j)) != c1){
					B.set(c1, b);
					b = B.get(c1 = c0);
				}
				--j;
				SA[b++] = (T.get(j) < c1) ? ~j : j;
				SA[i] = 0;
			}else if(j < 0){
				SA[i] = ~j;
			}
		}
		
		if(C == B){
			getCounts(T, C, n, k);
		}
		getBuckets(C, B, k, true); 
		for(i = n - 1, b = B.get(c1 = 0);0 <= i;--i){
			if(0 < (j = SA[i])){
				if((c0 = T.get(j)) != c1){
					B.set(c1, b);
					b = B.get(c1 = c0);
				}
				--j;
				SA[--b] = (T.get(j) > c1) ? ~(j + 1) : j;
				SA[i] = 0;
			}
		}
	}

	private static int id10(BaseArray T, int[] SA, int n, int m) {
		int i, j, p, q, plen, qlen, name;
		int c0, c1;
		boolean diff;

		
		for(i = 0;(p = SA[i]) < 0;++i){
			SA[i] = ~p;
		}
		if(i < m){
			for(j = i, ++i;;++i){
				if((p = SA[i]) < 0){
					SA[j++] = ~p;
					SA[i] = 0;
					if(j == m){
						break;
					}
				}
			}
		}

		
		i = n - 1;
		j = n - 1;
		c0 = T.get(n - 1);
		do{
			c1 = c0;
		}while ((0 <= --i) && ((c0 = T.get(i)) >= c1));
		for(;0 <= i;){
			do{
				c1 = c0;
			}while ((0 <= --i) && ((c0 = T.get(i)) <= c1));
			if(0 <= i){
				SA[m + ((i + 1) >> 1)] = j - i;
				j = i + 1;
				do{
					c1 = c0;
				}while ((0 <= --i) && ((c0 = T.get(i)) >= c1));
			}
		}

		
		for(i = 0, name = 0, q = n, qlen = 0;i < m;++i){
			p = SA[i];
			plen = SA[m + (p >> 1)];
			diff = true;
			if((plen == qlen) && ((q + plen) < n)){
				for(j = 0;(j < plen) && (T.get(p + j) == T.get(q + j));++j){
				}
				if(j == plen){
					diff = false;
				}
			}
			if(diff != false){
				++name;
				q = p;
				qlen = plen;
			}
			SA[m + (p >> 1)] = name;
		}

		return name;
	}

	
	private static void id3(BaseArray T, int[] SA, BaseArray C,
			BaseArray B, int n, int k) {
		int b, i, j;
		int c0, c1;
		
		if(C == B){
			getCounts(T, C, n, k);
		}
		getBuckets(C, B, k, false); 
		j = n - 1;
		b = B.get(c1 = T.get(j));
		SA[b++] = ((0 < j) && (T.get(j - 1) < c1)) ? ~j : j;
		for(i = 0;i < n;++i){
			j = SA[i];
			SA[i] = ~j;
			if(0 < j){
				if((c0 = T.get(--j)) != c1){
					B.set(c1, b);
					b = B.get(c1 = c0);
				}
				SA[b++] = ((0 < j) && (T.get(j - 1) < c1)) ? ~j : j;
			}
		}
		
		if(C == B){
			getCounts(T, C, n, k);
		}
		getBuckets(C, B, k, true); 
		for(i = n - 1, b = B.get(c1 = 0);0 <= i;--i){
			if(0 < (j = SA[i])){
				if((c0 = T.get(--j)) != c1){
					B.set(c1, b);
					b = B.get(c1 = c0);
				}
				SA[--b] = ((j == 0) || (T.get(j - 1) > c1)) ? ~j : j;
			}else{
				SA[i] = ~j;
			}
		}
	}

	
	private static void SA_IS(BaseArray T, int[] SA, int fs, int n, int k) {
		BaseArray C, B, RA;
		int i, j, b, m, p, q, name, newfs;
		int c0, c1;
		int flags = 0;

		if(k <= 256){
			C = new IntArray(new int[k], 0);
			if(k <= fs){
				B = new IntArray(SA, n + fs - k);
				flags = 1;
			}else{
				B = new IntArray(new int[k], 0);
				flags = 3;
			}
		}else if(k <= fs){
			C = new IntArray(SA, n + fs - k);
			if(k <= (fs - k)){
				B = new IntArray(SA, n + fs - k * 2);
				flags = 0;
			}else if(k <= 1024){
				B = new IntArray(new int[k], 0);
				flags = 2;
			}else{
				B = C;
				flags = 8;
			}
		}else{
			C = B = new IntArray(new int[k], 0);
			flags = 4 | 8;
		}

		
		getCounts(T, C, n, k);
		getBuckets(C, B, k, true); 
		for(i = 0;i < n;++i){
			SA[i] = 0;
		}
		b = -1;
		i = n - 1;
		j = n;
		m = 0;
		c0 = T.get(n - 1);
		do{
			c1 = c0;
		}while ((0 <= --i) && ((c0 = T.get(i)) >= c1));
		for(;0 <= i;){
			do{
				c1 = c0;
			}while ((0 <= --i) && ((c0 = T.get(i)) <= c1));
			if(0 <= i){
				if(0 <= b){
					SA[b] = j;
				}
				b = B.update(c1, -1);
				j = i;
				++m;
				do{
					c1 = c0;
				}while ((0 <= --i) && ((c0 = T.get(i)) >= c1));
			}
		}
		if(1 < m){
			id5(T, SA, C, B, n, k);
			name = id10(T, SA, n, m);
		}else if(m == 1){
			SA[b] = j + 1;
			name = 1;
		}else{
			name = 0;
		}

		
		if(name < m){
			if((flags & 4) != 0){
				C = null;
				B = null;
			}
			if((flags & 2) != 0){
				B = null;
			}
			newfs = (n + fs) - (m * 2);
			if((flags & (1 | 4 | 8)) == 0){
				if((k + name) <= newfs){
					newfs -= k;
				}else{
					flags |= 8;
				}
			}
			for(i = m + (n >> 1) - 1, j = m * 2 + newfs - 1;m <= i;--i){
				if(SA[i] != 0){
					SA[j--] = SA[i] - 1;
				}
			}
			RA = new IntArray(SA, m + newfs);
			SA_IS(RA, SA, newfs, m, name);
			RA = null;

			i = n - 1;
			j = m * 2 - 1;
			c0 = T.get(n - 1);
			do{
				c1 = c0;
			}while ((0 <= --i) && ((c0 = T.get(i)) >= c1));
			for(;0 <= i;){
				do{
					c1 = c0;
				}while ((0 <= --i) && ((c0 = T.get(i)) <= c1));
				if(0 <= i){
					SA[j--] = i + 1;
					do{
						c1 = c0;
					}while ((0 <= --i) && ((c0 = T.get(i)) >= c1));
				}
			}

			for(i = 0;i < m;++i){
				SA[i] = SA[m + SA[i]];
			}
			if((flags & 4) != 0){
				C = B = new IntArray(new int[k], 0);
			}
			if((flags & 2) != 0){
				B = new IntArray(new int[k], 0);
			}
		}

		
		if((flags & 8) != 0){
			getCounts(T, C, n, k);
		}
		
		if(1 < m){
			getBuckets(C, B, k, true); 
			i = m - 1;
			j = n;
			p = SA[m - 1];
			c1 = T.get(p);
			do{
				q = B.get(c0 = c1);
				while (q < j){
					SA[--j] = 0;
				}
				do{
					SA[--j] = p;
					if(--i < 0){
						break;
					}
					p = SA[i];
				}while ((c1 = T.get(p)) == c0);
			}while (0 <= i);
			while (0 < j){
				SA[--j] = 0;
			}
		}
		id3(T, SA, C, B, n, k);
		C = null;
		B = null;
	}

	
	public static void suffixsort(char[] T, int[] SA, int n) {
		if((T == null) || (SA == null) || (T.length < n) || (SA.length < n)){
			return;
		}
		if(n <= 1){
			if(n == 1){
				SA[0] = 0;
			}
			return;
		}
		SA_IS(new CharArray(T, 0), SA, 0, n, 128);
	}
	
	public static int[] sa(char[] T)
	{
		int n = T.length;
		int[] sa = new int[n];
		suffixsort(T, sa, n);
		return sa;
	}
	
	public static int[] id1(char[] str, int[] sa)
	{
		int n = str.length;
		int h = 0;
		int[] lcp = new int[n];
		int[] isa = new int[n];
		for(int i = 0;i < n;i++)isa[sa[i]] = i;
		for(int i = 0;i < n;i++){
			if(isa[i] > 0){
				for(int j = sa[isa[i]-1]; j+h<n && i+h<n && str[j+h] == str[i+h]; h++);
				lcp[isa[i]] = h;
			}else{
				lcp[isa[i]] = 0;
			}
			if(h > 0)h--;
		}
		return lcp;
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
	
	private boolean id4(int c) { return !(c >= 33 && c <= 126); }
	private int skip() { int b; while((b = readByte()) != -1 && id4(b)); return b; }
	
	private double nd() { return Double.parseDouble(ns()); }
	private char nc() { return (char)skip(); }
	
	private String ns()
	{
		int b = skip();
		StringBuilder sb = new StringBuilder();
		while(!(id4(b))){ 

			sb.appendCodePoint(b);
			b = readByte();
		}
		return sb.toString();
	}
	
	private char[] ns(int n)
	{
		char[] buf = new char[n];
		int b = skip(), p = 0;
		while(p < n && !(id4(b))){
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
