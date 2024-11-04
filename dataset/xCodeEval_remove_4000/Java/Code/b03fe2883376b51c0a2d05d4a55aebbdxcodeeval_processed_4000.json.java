

import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;

public class E3 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	public static int[] generateLucky(int n)
	{
		int[] lucky = new int[50];
		lucky[0] = 4;
		lucky[1] = 7;
		int r = 2;
		for(int p = 0;p < r;p++){
			if((long)lucky[p]*10+4 <= n){
				lucky[r++] = lucky[p]*10+4;
			}
			if((long)lucky[p]*10+7 <= n){
				lucky[r++] = lucky[p]*10+7;
			}
		}
		return Arrays.copyOf(lucky, r);
	}

	void solve()
	{
		int[] lucky = generateLucky(10000);
		int[] lmap = new int[10001];
		int next = lucky.length;
		int INF = 99999999;
		for(int i = 10000;i >= 0;i--){
			if(next-1 >= 0 && lucky[next-1] == i){
				next--;
			}
			lmap[i] = next == lucky.length ? INF : lucky[next] - i;
		}
		
		int n = ni(), m = ni();
		int[] a = new int[n];
		int[] D = new int[n];
		int[] E = new int[n];
		for(int i = 0;i < n;i++){
			a[i] = ni();
			D[i] = lmap[a[i]];
			E[i] = a[i] + D[i];
		}
		
		id3 st = new id3(D);
		
		for(int i = 0;i < m;i++){
			char o = ns(5)[0];
			if(o == 'c'){
				int l = ni()-1, r = ni()-1;
				long mp = st.id2(l, r);
				if(mp>>32 == 0){
					out.println(mp);
				}else{
					out.println(0);
				}
			}else if(o == 'a'){
				int l = ni()-1, r = ni()-1, d = ni();
				st.addRange(l, r, -d);




				while(true){




					long mp = st.min2(l, r);
					int val = (int)(mp>>32);
					int ind = (int)mp;
					if(val >= 0)break;
					int cur = E[ind]-val;


					st.add(ind, lmap[cur] - val);
					E[ind] = lmap[cur] + cur;


				}








			}
		}
	}
	
	public static int id4(int[] ft, int[] ftp, int i)
	{
		int n = ft.length;
		int sum = 0;
		for(i++;i > 0;i -= i&-i){
			sum += ft[i];
			int plus = 0;
			for(int j=i+(i&-i);j < n;j += j&-j){
				plus += ftp[j];
			}
			sum += (i&-i)*plus;
		}
		return sum;
	}
	
	public static void id1(int[] ft, int[] ftp, int i, int v)
	{
		int n = ft.length;
		for(i++;i > 0;i -= i&-i){
			ftp[i] += v;
			int w = v*(i&-i);
			for(int j = i;j < n;j += j&-j){
				ft[j] += w;
			}
		}
	}
	
	public static int[] id0(int[] a)
	{
		int n = a.length;
		int[] ft = new int[n+1];
		for(int i = 1;i <= n;i++){
			for(int j = i;j <= n;j += j&-j){
				ft[j] += a[i-1];
			}
		}
		return ft;
	}
	
	public class id3 {
		public int M, H, N, B;
		public int[] st;
		public int[] plus;
		public int[] pos;
		public int[] count;
		
		public id3(int n)
		{
			N = n;
			M = Integer.highestOneBit(Math.max(n-1, 1))<<2;
			H = M>>>1;
			B = Integer.numberOfTrailingZeros(H);
			st = new int[M];
			plus = new int[H];
			pos = new int[M];
			for(int i = M-1;i >= H;i--)pos[i] = i-H;
			for(int i = H-1;i >= 0;i--){
				pos[i] = pos[2*i];
			}
			count = new int[M];
			for(int i = M-1;i >= H;i--)count[i] = 1;
		}
		
		public id3(int[] a)
		{
			N = a.length;
			M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
			H = M>>>1;
			B = Integer.numberOfTrailingZeros(H);
			st = new int[M];
			pos = new int[M];
			count = new int[M];
			for(int i = 0;i < N;i++){
				st[H+i] = a[i];
				pos[H+i] = i;
				count[H+i] = 1;
			}
			plus = new int[H];
			build();
		}
		
		public void build()
		{
			Arrays.fill(st, H+N, M, Integer.MAX_VALUE);
			for(int i = H-1;i >= 1;i--){
				st[i] = Math.min(st[2*i], st[2*i+1]);
				pos[i] = st[2*i] <= st[2*i+1] ? pos[2*i] : pos[2*i+1];
				if(st[2*i] < st[2*i+1]){
					count[i] = count[2*i];
				}else if(st[2*i] > st[2*i+1]){
					count[i] = count[2*i+1];
				}else{
					count[i] = count[2*i] + count[2*i+1];
				}
			}
		}
		
		public void update(int ind, int x)
		{
			st[H+ind] = x;
			for(int i = (H+ind)>>>1;i >= 1;i >>>= 1){
				if(st[2*i] <= st[2*i+1]){
					st[i] = st[2*i] + plus[i];
					pos[i] = pos[2*i];
					if(st[2*i] < st[2*i+1]){
						count[i] = count[2*i];
					}else{
						count[i] = count[2*i] + count[2*i+1];
					}
				}else{
					st[i] = st[2*i+1] + plus[i];
					pos[i] = pos[2*i+1];
					count[i] = count[2*i+1];
				}
			}
		}
		
		public void add(int ind, int x)
		{
			st[H+ind] += x;
			for(int i = (H+ind)>>>1;i >= 1;i >>>= 1){
				if(st[2*i] <= st[2*i+1]){
					st[i] = st[2*i] + plus[i];
					pos[i] = pos[2*i];
					if(st[2*i] < st[2*i+1]){
						count[i] = count[2*i];
					}else{
						count[i] = count[2*i] + count[2*i+1];
					}
				}else{
					st[i] = st[2*i+1] + plus[i];
					pos[i] = pos[2*i+1];
					count[i] = count[2*i+1];
				}
			}
		}
		
		public void addRange(int f, int t, int v){ addRange(f, t, v, B); }
		
		public void addRange(int f, int t, int v, int b)
		{
			if(b == 0){
				update(f, st[H|f]+v);
			}else if(f>>b<<b==f && t+1>>b<<b==t+1){
				plus[(H|f)>>b] += v;
				for(int i = (H|f)>>b;i >= 1;i >>>= 1){
					if(st[2*i] <= st[2*i+1]){
						st[i] = st[2*i] + plus[i];
						pos[i] = pos[2*i];
						if(st[2*i] < st[2*i+1]){
							count[i] = count[2*i];
						}else{
							count[i] = count[2*i] + count[2*i+1];
						}
					}else{
						st[i] = st[2*i+1] + plus[i];
						pos[i] = pos[2*i+1];
						count[i] = count[2*i+1];
					}
				}
			}else{
				b--;
				if((f^t)<<31-b<0){
					int w = t>>b<<b;
					addRange(f, w-1, v, b);
					addRange(w, t, v, b);
				}else{
					addRange(f, t, v, b);
				}
			}
		}
		
		public int[] min(int f, int t) { return min(f, t, B); }
		
		public int[] min(int f, int t, int b)
		{
			if(f>>b<<b==f && t+1>>b<<b==t+1){
				return new int[]{st[(H|f)>>b], pos[(H|f)>>b]};
			}
			
			b--;
			if((f^t)<<31-b<0){
				int w = t>>b<<b;
				int[] l = min(f, w-1, b);
				int[] r = min(w, t, b);
				int[] ret = l[0] <= r[0] ? l : r;
				ret[0] += plus[(H|f)>>b+1];
				return ret;
			}else{
				int[] ret = min(f, t, b);
				ret[0] += plus[(H|f)>>b+1];
				return ret;
			}
		}
		
		public long min2(int f, int t) { return min2(f, t, B, 0); }
		
		public long min2(int f, int t, int b, int carry)
		{
			if(f>>b<<b==f && t+1>>b<<b==t+1){
				return (long)st[(H|f)>>b]<<32|pos[(H|f)>>b];
			}
			if(carry+st[(H|f)>>b] >= 0){
				return (long)st[(H|f)>>b]<<32|pos[(H|f)>>b];
			}
			
			b--;
			if((f^t)<<31-b<0){
				int w = t>>b<<b;
				long l = min2(f, w-1, b, carry+plus[(H|f)>>b+1]);
				long r = min2(w, t, b, carry+plus[(H|f)>>b+1]);
				long ret = Math.min(l, r);
				ret += (long)plus[(H|f)>>b+1]<<32;
				return ret;
			}else{
				long ret = min2(f, t, b, carry+plus[(H|f)>>b+1]);
				ret += (long)plus[(H|f)>>b+1]<<32;
				return ret;
			}
		}
		
		public int[] minCount(int f, int t) { return minCount(f, t, B); }
		
		public int[] minCount(int f, int t, int b)
		{
			if(f>>b<<b==f && t+1>>b<<b==t+1){
				return new int[]{st[(H|f)>>b], count[(H|f)>>b]};
			}
			
			b--;
			if((f^t)<<31-b<0){
				int w = t>>b<<b;
				int[] l = minCount(f, w-1, b);
				int[] r = minCount(w, t, b);
				int[] ret = l[0] <= r[0] ? l : r;
				if(l[0] == r[0]){
					ret[1] = l[1] + r[1];
				}
				ret[0] += plus[(H|f)>>b+1];
				return ret;
			}else{
				int[] ret = minCount(f, t, b);
				ret[0] += plus[(H|f)>>b+1];
				return ret;
			}
		}
		
		public long id2(int f, int t) { return id2(f, t, B); }
		
		public long id2(int f, int t, int b)
		{
			if(f>>b<<b==f && t+1>>b<<b==t+1){
				return (long)st[(H|f)>>b]<<32|count[(H|f)>>b];
			}
			
			b--;
			if((f^t)<<31-b<0){
				int w = t>>b<<b;
				long l = id2(f, w-1, b);
				long r = id2(w, t, b);
				long ret = l>>32 <= r>>32 ? l : r;
				if(l>>32 == r>>32)ret += (int)r;
				ret += (long)plus[(H|f)>>b+1]<<32;
				return ret;
			}else{
				long ret = id2(f, t, b);
				ret += (long)plus[(H|f)>>b+1]<<32;
				return ret;
			}
		}
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
	
	public static void main(String[] args) throws Exception
	{
		new E3().run();
	}
	
	public int ni()
	{
		try {
			int num = 0;
			boolean minus = false;
			while((num = is.read()) != -1 && !((num >= '0' && num <= '9') || num == '-'));
			if(num == '-'){
				num = 0;
				minus = true;
			}else{
				num -= '0';
			}
			
			while(true){
				int b = is.read();
				if(b >= '0' && b <= '9'){
					num = num * 10 + (b - '0');
				}else{
					return minus ? -num : num;
				}
			}
		} catch (IOException e) {
		}
		return -1;
	}
	
	public long nl()
	{
		try {
			long num = 0;
			boolean minus = false;
			while((num = is.read()) != -1 && !((num >= '0' && num <= '9') || num == '-'));
			if(num == '-'){
				num = 0;
				minus = true;
			}else{
				num -= '0';
			}
			
			while(true){
				int b = is.read();
				if(b >= '0' && b <= '9'){
					num = num * 10 + (b - '0');
				}else{
					return minus ? -num : num;
				}
			}
		} catch (IOException e) {
		}
		return -1;
	}
	
	public String ns()
	{
		try{
			int b = 0;
			StringBuilder sb = new StringBuilder();
			while((b = is.read()) != -1 && (b == '\r' || b == '\n' || b == ' '));
			if(b == -1)return "";
			sb.append((char)b);
			while(true){
				b = is.read();
				if(b == -1)return sb.toString();
				if(b == '\r' || b == '\n' || b == ' ')return sb.toString();
				sb.append((char)b);
			}
		} catch (IOException e) {
		}
		return "";
	}
	
	public char[] ns(int n)
	{
		char[] buf = new char[n];
		try{
			int b = 0, p = 0;
			while((b = is.read()) != -1 && (b == ' ' || b == '\r' || b == '\n'));
			if(b == -1)return null;
			buf[p++] = (char)b;
			while(p < n){
				b = is.read();
				if(b == -1 || b == ' ' || b == '\r' || b == '\n')break;
				buf[p++] = (char)b;
			}
			return Arrays.copyOf(buf, p);
		} catch (IOException e) {
		}
		return null;
	}
	
	
	double nd() { return Double.parseDouble(ns()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}
