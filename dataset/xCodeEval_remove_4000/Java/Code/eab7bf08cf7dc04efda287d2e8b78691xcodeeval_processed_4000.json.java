

import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

public class G {
	InputStream is;
	PrintWriter out;










	String INPUT = "";
	
	void solve()
	{
		int x1 = ni(), y2 = ni();
		int x2 = ni(), y1 = ni();
		x1 = x1 * 3 + 1;
		y1 = y1 * 3 + 1;
		y2 = y2 * 3 - 1;
		x2 = x2 * 3 - 1;
		int n = ni();
		int[][] co = new int[n][];
		for(int i = 0;i < n;i++){
			co[i] = new int[]{ni()*3, ni()*3};
		}
		
		if(id4(co))co = rev(co);
		
		int score = 
				(id1(x1, y1, x2, y1, co) ? 1 : 0) + 
				(id1(x2, y1, x2, y2, co) ? 1 : 0) + 
				(id1(x2, y2, x1, y2, co) ? 1 : 0) + 
				(id1(x1, y2, x1, y1, co) ? 1 : 0)
				;
		if(score == 4){
			out.println(1);
			return;
		}
		
		int[][] W = {
				{x1, y1}, {x2, y1}, {x2, y2}, {x1, y2}
		};
		score = 0;
		for(int i = 0;i < n;i++){
			if(id1(co[i], co[(i+1)%n], W)){
				score++;
			}
		}
		if(score == n){
			out.println(1);
			return;
		}
		
		

		{
			int slide = -1;
			for(int i = 0;i < n;i++){
				if(x1 < co[i][0] && co[i][0] < x2 &&
						y1 < co[i][1] && co[i][1] < y2){
					continue;
				}
				slide = i;
				break;
			}
			assert slide != -1;
			
			int[][] nco = new int[n][];
			for(int i = 0;i < n;i++){
				nco[i] = co[(i+slide)%n];
			}
			co = nco;
		}


		
		int[][][] D = {
				{{x1, y1}, {x2, y1}},
				{{x2, y1}, {x2, y2}},
				{{x2, y2}, {x1, y2}},
				{{x1, y2}, {x1, y1}}
		};
		long[][] is = new long[2*n][];
		int p = 0;
		for(int i = 0;i < n;i++){
			for(int j = 0;j < 4;j++){
				long[] il = id0(co[i], co[(i+1)%n], D[j][0], D[j][1]);
				if(il != null && ((il[0] > 0 && il[0] < il[2] && il[1] > 0 && il[1] < il[2])
						)
								){
					
					long pos = 
							j == 0 ? (long)(x2-x1)*il[1]/il[2] :
								j == 1 ? (long)(y2-y1)*il[1]/il[2]+x2-x1 :
									j == 2 ? (long)(x2-x1)*il[1]/il[2]+x2-x1+y2-y1 :
										(long)(y2-y1)*il[1]/il[2]+2*(x2-x1)+y2-y1;
					long len = Math.abs(co[i][0]-co[(i+1)%n][0])+Math.abs(co[i][1]-co[(i+1)%n][1]);
					is[p++] = new long[]{i, il[0]*len/il[2], pos};
				}
			}
		}
		is = Arrays.copyOf(is, p);
		Arrays.sort(is, new Comparator<long[]>() {
			public int compare(long[] a, long[] b) {
				if(a[0] != b[0])return Long.compare(a[0], b[0]);
				return Long.compare(a[1], b[1]);
			}
		});
		
		assert p % 2 == 0;
		int ans = 0;
		long max = 0;
		int argmax = -1;
		for(int i = 0;i < p;i+=2){
			if(is[i][2] > is[i+1][2]){
				ans++;
			}
			if(Math.abs(is[i][2] - is[i+1][2]) > max){
				max = Math.abs(is[i][2] - is[i+1][2]);
				argmax = i;
			}
		}
		
		if(argmax != -1 && is[argmax][2] < is[argmax+1][2])ans++;
		
		out.println(ans);
	}
	
	int[] one(int[] a, int[] b)
	{
		return new int[]{
		Integer.signum(b[0]-a[0]) + a[0],
		Integer.signum(b[1]-a[1]) + a[1]
		};
	}
	
	public static class DJSet {
		public int[] upper;

		public DJSet(int n) {
			upper = new int[n];
			Arrays.fill(upper, -1);
		}

		public int root(int x) {
			return upper[x] < 0 ? x : (upper[x] = root(upper[x]));
		}

		public boolean equiv(int x, int y) {
			return root(x) == root(y);
		}

		public boolean union(int x, int y) {
			x = root(x);
			y = root(y);
			if (x != y) {
				if (upper[y] < upper[x]) {
					int d = x;
					x = y;
					y = d;
				}
				upper[x] += upper[y];
				upper[y] = x;
			}
			return x == y;
		}

		public int count() {
			int ct = 0;
			for (int u : upper)
				if (u < 0)
					ct++;
			return ct;
		}
	}

	
	static boolean isIn(long a, long b, long c, long n)
	{
		if(a >= c)c += n;
		if(a >= b)b += n;
		return a < b && b < c;
	}
	
	public static long[] id0(int[] a, int[] b, int[] c, int[] d) { return id0(a[0], a[1], b[0], b[1], c[0], c[1], d[0], d[1]);}

	
	public static long[] id0(long ax, long ay, long bx, long by, long cx, long cy, long dx, long dy)
	{
		long aa = bx - ax;
		long cc = by - ay;
		long bb = cx - dx;
		long dd = cy - dy;
		long xx = cx - ax;
		long yy = cy - ay;
		long det = aa * dd - bb * cc;
		if(det == 0)return null;
		long tnum = dd*xx-bb*yy;
		long unum = -cc*xx+aa*yy;
		if(det < 0){
			det = -det;
			tnum = -tnum;
			unum = -unum;
		}


		return new long[]{
				tnum,
				unum,
				det
		};
	}

	public static boolean id1(int[] a, int[] b, int[][] co){ return id1(a[0], a[1], b[0], b[1], co); }
	
	public static boolean id1(int ax, int ay, int bx, int by, int[][] co)
	{
		if(ax == bx && ay == by)return id1(ax, ay, co);
		int n = co.length;
		
		int aedge = -1;
		int bedge = -1;
		

		for(int i = 0, j = i+1;i < n;i++,j++){
			if(j == n)j = 0;
			long cx = co[i][0], cy = co[i][1];
			long dx = co[j][0], dy = co[j][1];
			long aa = bx - ax, cc = by - ay, bb = cx - dx, dd = cy - dy;
			long det = aa * dd - bb * cc;
			if(det != 0){
				long xx = co[i][0] - ax, yy = co[i][1] - ay;
				long tnum = dd*xx-bb*yy;
				long unum = -cc*xx+aa*yy;
				if(det < 0){
					det = -det;
					tnum = -tnum;
					unum = -unum;
				}
				if(tnum > 0 && tnum < det && unum > 0 && unum < det)return false;
			}
			if(id3(cx, cy, dx, dy, ax, ay))aedge = i;
			if(id3(cx, cy, dx, dy, bx, by))bedge = i;
		}
		for(int i = 0;i < n;i++){
			if(id3(ax, ay, bx, by, co[i][0], co[i][1])
					&& !(co[i][0] == ax && co[i][1] == ay)
					&& !(co[i][0] == bx && co[i][1] == by)
					){
				

				int pre = i-1; if(pre < 0)pre += n;
				int nex = i+1; if(nex >= n)nex -= n;
				if(inArg(co[i][0], co[i][1], co[nex][0], co[nex][1], co[pre][0], co[pre][1], ax, ay) < 0)return false;
				if(inArg(co[i][0], co[i][1], co[nex][0], co[nex][1], co[pre][0], co[pre][1], bx, by) < 0)return false;
			}
		}
		if(aedge == -1){
			

			return id1(ax, ay, co);
		}
		if(bedge == -1){
			return id1(bx, by, co);
		}
		int aver = -1, bver = -1; 

		for(int i = 0;i < n;i++){
			if(co[i][0] == ax && co[i][1] == ay)aver = i;
			if(co[i][0] == bx && co[i][1] == by)bver = i;
		}
		
		

		if(aver == -1){
			if(ccw(co[aedge][0], co[aedge][1], ax, ay, bx, by) > 0)return false;
		}else{
			int pre = aver-1;
			if(pre < 0)pre += n;
			int nex = aver+1;
			if(nex >= n)nex -= n;
			if(inArg(co[nex][0]-ax, co[nex][1]-ay, co[pre][0]-ax, co[pre][1]-ay, bx-ax, by-ay) < 0)return false;
		}
		
		if(bver == -1){
			if(ccw(co[bedge][0], co[bedge][1], bx, by, ax, ay) > 0)return false;
		}else{
			int pre = bver-1;
			if(pre < 0)pre += n;
			int nex = bver+1;
			if(nex >= n)nex -= n;
			if(inArg(co[nex][0]-bx, co[nex][1]-by, co[pre][0]-bx, co[pre][1]-by, ax-bx, ay-by) < 0)return false;
		}
		
		

		for(int i = 0;i < n;i++){
			if(i != aver && i != bver && id3(ax, ay, bx, by, co[i][0], co[i][1])){
				int pre = i-1;
				if(pre < 0)pre += n;
				int nex = i+1;
				if(nex >= n)nex -= n;
				if(inArg(co[nex][0]-co[i][0], co[nex][1]-co[i][1], co[pre][0]-co[i][0], co[pre][1]-co[i][1], ax-co[i][0], ay-co[i][1]) < 0)return false;
				if(inArg(co[nex][0]-co[i][0], co[nex][1]-co[i][1], co[pre][0]-co[i][0], co[pre][1]-co[i][1], bx-co[i][0], by-co[i][1]) < 0)return false;
			}
		}
		return true;
	}
	
	public static int inArg(long x, long y, long ax, long ay, long bx, long by, long cx, long cy)
	{
		return inArg(ax-x, ay-y, bx-x, by-y, cx-x, cy-y);
	}

	
	public static int inArg(int[] t, int[] a, int[] b, int[] c){ return inArg(a[0]-t[0], a[1]-t[1], b[0]-t[0], b[1]-t[1], c[0]-t[0], c[1]-t[1]); }
	
	public static boolean id1(int[] a, int[][] co){ return id1(a[0], a[1], co); }
	
	public static boolean id1(int ax, int ay, int[][] co)
	{
		int n = co.length;
		

		for(int i = 0, j = i+1;i < n;i++,j++){
			if(j == n)j = 0;
			if(id3(co[i][0], co[i][1], co[j][0], co[j][1], ax, ay))return true;
		}
		
		

		int ct = 0;
		for(int i = 0, j = i+1;i < n;i++,j++){
			if(j == n)j = 0;
			long cx = co[i][0], cy = co[i][1];
			long dx = co[j][0], dy = co[j][1];
			if(cy >= dy){
				long t = cx; cx = dx; dx = t;
				t = cy; cy = dy; dy = t;
			}
			if(cy <= ay && dy > ay){
				

				if((ay-cy)*(dx-cx) >= (ax-cx)*(dy-cy)){
					ct++;
				}
			}
		}
		return (ct&1) == 1;
	}
	
	public static int inArg(long[] t, long[] a, long[] b, long[] c) {
		return inArg(a[0] - t[0], a[1] - t[1], b[0] - t[0], b[1] - t[1], c[0] - t[0], c[1] - t[1]);
	}

	
	public static int ccw(long ax, long ay, long bx, long by, long tx, long ty) {
		return Long.signum((tx - ax) * (by - ay) - (bx - ax) * (ty - ay));
	}

	
	public static int ccw(long[] a, long[] b, long[] t) {
		return Long.signum((t[0] - a[0]) * (b[1] - a[1]) - (b[0] - a[0]) * (t[1] - a[1]));
	}

	
	public static int inArg(long ax, long ay, long bx, long by, long cx, long cy) {
		return (int) (Long.signum(ax * cy - ay * cx) - Long.signum(bx * cy - by * cx) - Long.signum(ax * by - ay * bx));
	}

	
	

	public static boolean id3(long ax, long ay, long bx, long by, long cx, long cy)
	{
		return (cx-ax)*(by-ay)-(cy-ay)*(bx-ax)==0 && (cx-ax)*(cx-bx)+(cy-ay)*(cy-by) <= 0;
	}
	
	public static boolean id3(long[] a, long[] b, long[] c) { return id3(a[0], a[1], b[0], b[1], c[0], c[1]); }
	public static boolean id3(int[] a, int[] b, int[] c) { return id3(a[0], a[1], b[0], b[1], c[0], c[1]); }

	
	public static boolean id4(int[]... poly)
	{
		int n = poly.length;
		if(n <= 2)return true;
		long minx = Integer.MAX_VALUE;
		long miny = Integer.MAX_VALUE;
		int mini = -1;
		for(int i = 0;i < n;i++){
			if(poly[i][0] < minx || poly[i][0] == minx && poly[i][1] < miny){
				minx = poly[i][0]; miny = poly[i][1]; mini = i;
			}
		}
		int prev = (mini+n-1)%n;
		int next = (mini+1)%n;
		return ccw(poly[prev], poly[mini], poly[next]) == 1;
	}
	
	public static int[][] rev(int[][] co)
	{
		for(int i = 0, j = co.length-1;i < j;i++,j--){
			int[] dum = co[i]; co[i] = co[j]; co[j] = dum;
		}
		return co;
	}
	
	public static int ccw(int[] a, int[] b, int[] t) {
		return Long.signum((long) (t[0] - a[0]) * (b[1] - a[1]) - (long) (b[0] - a[0]) * (t[1] - a[1]));
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
