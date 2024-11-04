import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashSet;
import java.util.List;
import java.util.NoSuchElementException;

public class Main {

	

	

	

	

	


	public static void main(String[] args) throws Exception {
		FastScanner sc = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);

		int testcase = sc.nexI();
		for(int t=0; t<testcase; t++) {
			int n = sc.nexI();
			
			Graph0n tree = Graph0n.make_tree(n, sc);
			
			ArrayList<ArrayList<Edge>> ared = nv_ahead_each_edge(n, tree);
			
			ArrayDeque<Edge> todo = new ArrayDeque<>();
			todo.add(new Edge(0, -1));	

			
			ArrayList<Long> ef_e_edge = new ArrayList<>();
			
			while (todo.size()>0) {
				Edge dw = todo.poll();
				for(Edge e: ared.get(dw.v2)) {
					if(e.v2==dw.weight) continue;
					long oneside = e.weight;
					oneside *= ((long)n - e.weight);
					ef_e_edge.add(oneside);
					todo.add(new Edge(e.v2, dw.v2));
				}
			}
			Collections.sort(ef_e_edge);
			
			int m = sc.nexI();
			long[] ps = new long[m];
			sc.al(ps);
			Arrays.sort(ps);
			
			long ans = 0L;
			if(m<n) {
				for(int i=0; i<(n-m-1); i++) {
					ans += ef_e_edge.get(i);
					ans %= e97;
				}
				for(int i=m; i>0; i--) {
					ans += ps[m-i] * (ef_e_edge.get(n-i-1)%e97);
					ans %= e97;
				}
			}else {
				ans = ef_e_edge.get(n-2)%e97;
				for(int i=(n-2); i<m; i++) {
					ans *= ps[i];
					ans %= e97;
				}
				for(int i=0; i<(n-2); i++) {
					ans += ps[i] * (ef_e_edge.get(i)%e97);
					ans %= e97;
				}
			}
			out.println(ans);
			
		}
		out.flush();
	}
	
	public static ArrayList<ArrayList<Edge>> nv_ahead_each_edge(int n, Graph0n tree) {
		
		ArrayList<ArrayList<Edge>> ans = new ArrayList<>();
		ArrayList<HashSet<Integer>> parents = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			ans.add(new ArrayList<Edge>());
			parents.add(new HashSet<Integer>()); 
			for(int e: tree.get(i)) parents.get(i).add(e);
		}
		
		ArrayDeque<Integer> todo = new ArrayDeque<>();
		for(int i=0; i<n; i++) {
			if(tree.get(i).size()==1) {
				todo.add(i);
			}
		}
		
		int[] seen = new int[n];
		fill(seen,1);
		int[] rest = new int[n];
		fill(rest, n-1);
		while (todo.size()>0) {
			int dw = todo.poll();
			seen[dw]++;
			if(seen[dw]>=tree.get(dw).size()) {
				assertion(parents.get(dw).size()<=1);
				for(int papa: parents.get(dw)){
					ans.get(dw).add(new Edge(papa, rest[dw]));
					
					int restprime = n-rest[dw];
					parents.get(papa).remove(dw);
					rest[papa] -= restprime;
					ans.get(papa).add(new Edge(dw, restprime));
					todo.add(papa);
				}
			}
		}
		
		return ans;
	}

	private static int INF = (int)1e8;
	private static long INFL = (long)1e17;
	private static long e97 = (long)1e9 + 7;

	private static void assertion(boolean b) {
		if(!b) throw new AssertionError();
	}

	private static int pow2(int in) {
		return in*in;
	}
	private static long pow2(long in) {
		return in*in;
	}
	private static double pow2(double in) {
		return in*in;
	}

	private static int getDigit2(long num) {
		long cf = 1;
		int d = 0;
		while(num > cf) {
			d ++;
			cf = (1L<<d);
		}
		return d; 

	}
	private static int getDigit10(long num) {
		long cf = 1L;
		int d = 0;
		while(num >= cf) {
			d ++;
			cf *= 10L;
		}
		return d; 


	}

	private static int divceil(int nume, int deno) {
		return (nume+deno-1)/deno;
	}
	private static long divceil(long nume, long deno) {
		return (nume+deno-1L)/deno;
	}
	
	private static boolean isINF(long in) {
		if((in*20L)>INF) return true;
		else return false;
	}
	private static boolean isINFL(long in) {
		if((in*10L)>INFL) return true;
		else return false;
	}
	
	public static int biSearchMax(long[] dt, long target) {
		int left=-1, right=dt.length, mid=-1;
		while((right-left)>1) {
			mid = (right+left)/2;
			if(dt[mid] <= target) left=mid;
			else right=mid;
		}
		return left;	

	}
	public static int biSearchMaxAL(ArrayList<Long> dt, long target) {
		int left=-1, right=dt.size(), mid=-1;
		while((right-left)>1) {
			mid = (right+left)/2;
			if(dt.get(mid) <= target) left=mid;
			else right=mid;
		}
		return left;

	}
	
	private static int[] Xdir4 = {1,0,0,-1};
	private static int[] Ydir4 = {0,1,-1,0};
	private static int[] Xdir8 = {1,1,1,0,0,-1,-1,-1};
	private static int[] Ydir8 = {1,0,-1,1,-1,1,0,-1};
	
	private static boolean is_in_area(int y, int x, int h, int w) {
		if(y < 0) return false;
		if(x < 0) return false;
		if(y >= h) return false;
		if(x >= w) return false;
		return true;
	}
	
	private static int abs(int a) {
		return (a>=0) ? a: -a;
	}
	private static long abs(long a) {
		return (a>=0) ? a: -a;
	}
	private static double abs(double a) {
		return (a>=0) ? a: -a;
	}
	
	private static int min(int a, int b) {
		return (a>b) ? b : a;
	}
	private static long min(long a, long b) {
		return (a>b) ? b : a;
	}
	private static double min(double a, double b) {
		return (a>b) ? b : a;
	}
	
	private static int max(int a, int b) {
		return (a>b) ? a : b;
	}
	private static long max(long a, long b) {
		return (a>b) ? a : b;
	}
	private static double max(double a, double b) {
		return (a>b) ? a : b;
	}
	
	private static int minN(int... ins) {
		int min = ins[0];
		for(int i=1; i<ins.length; i++) {
			if(ins[i] < min) min = ins[i];
		}
		return min;
	}
	private static long minN(long... ins) {
		long min = ins[0];
		for(int i=1; i<ins.length; i++) {
			if(ins[i] < min) min = ins[i];
		}
		return min;
	}
	private static int maxN(int... ins) {
		int max = ins[0];
		for(int i=1; i<ins.length; i++) {
			if(ins[i] > max) max = ins[i];
		}
		return max;
	}
	private static long maxN(long... ins) {
		long max = ins[0];
		for(int i=1; i<ins.length; i++) {
			if(ins[i] > max) max = ins[i];
		}
		return max;
	}

	private static int minExAd(int[] dt, int ad) {
		int min = Integer.MAX_VALUE;
		for(int i=0; i<dt.length; i++) {
			if((i!=ad) && (dt[i]<min)) min = dt[i];
		}
		return min;
	}
	private static long minExAd(long[] dt, int ad) {
		long min = Long.MAX_VALUE;
		for(int i=0; i<dt.length; i++) {
			if((i!=ad) && (dt[i]<min)) min = dt[i];
		}
		return min;
	}
	private static int minExVal(int[] dt, int ex_val) {
		int min = Integer.MAX_VALUE;
		for(int i=0; i<dt.length; i++) {
			if((dt[i]!=ex_val) && (dt[i]<min)) min = dt[i];
		}
		return min;
	}
	private static long minExVal(long[] dt, long ex_val) {
		long min = Long.MAX_VALUE;
		for(int i=0; i<dt.length; i++) {
			if((dt[i]!=ex_val) && (dt[i]<min)) min = dt[i];
		}
		return min;
	}
	private static int maxExAd(int[] dt, int ad) {
		int max = Integer.MIN_VALUE;
		for(int i=0; i<dt.length; i++) {
			if((i!=ad) && (dt[i]>max)) max = dt[i];
		}
		return max;
	}
	private static long maxExAd(long[] dt, int ad) {
		long max = Long.MIN_VALUE;
		for(int i=0; i<dt.length; i++) {
			if((i!=ad) && (dt[i]>max)) max = dt[i];
		}
		return max;
	}
	private static int maxExVal(int[] dt, int ex_val) {
		int max = Integer.MIN_VALUE;
		for(int i=0; i<dt.length; i++) {
			if((dt[i]!=ex_val) && (dt[i]>max)) max = dt[i];
		}
		return max;
	}
	private static long maxExVal(long[] dt, long ex_val) {
		long max = Long.MIN_VALUE;
		for(int i=0; i<dt.length; i++) {
			if((dt[i]!=ex_val) && (dt[i]>max)) max = dt[i];
		}
		return max;
	}
	
	private static int sumA(int[] dt) {
		int sum = 0;
		for(int e: dt) {
			sum += e;
		} 
		return sum;
	}
	private static long sumA(long[] dt) {
		long sum = 0L;
		for(long e: dt) {
			sum += e;
		}
		return sum;
	}
	private static long sumA(ArrayList<Long> dt) {
		long sum =0L;
		for(long e: dt) {
			sum += e;
		}
		return sum;
	}
	
	private static int pow(int n, int k) {
		int ans = 1;
		for(int i=0; i<k; i++) {
			ans *= n;
			assertion(n>=0);
		}
		return ans;
	}
	private static long pow(long n, int k) {
		long ans = 1L;
		for(int i=0; i<k; i++) {
			ans *= n;
			assertion(n>=0L);
		}
		return ans;
	}
	
	private static double hypod(double a, double b) {
		return Math.sqrt(a*a+b*b);
	}
	
	private static long factorial(int n) {
		long ans=1L;
		for(long i=n; i>0; i--) {
			ans *= i;
			assertion(ans>=0L);
		}
		return ans;
	}
	private static long facP(int n, long p) {
		long ans=1L;
		for(long i=n; i>0; i--) {
			ans *= i;
			ans %= p;
		}
		return ans;
	}
	
	private static long lcm(long m, long n) {
		assertion((m>0L) && (n>0L));
		long ans = m/gcd(m,n);
		ans *= n;
		return ans;
	}
	private static long gcd(long m, long n) {
		if(isINFL(-m)) return n;
		assertion((m>=0L) && (n>=0L));
		if(m < n) return gcd(n, m);
		if(n == 0) return m;
		return gcd(n, m % n);
	}
	
	private static boolean is_prime(long a) {
		if(a==1) return false;
		for(long i=2L; i<=Math.sqrt(a); i++) {
			if(a%i == 0) return false;
		}
		return true;
	}
	
	private static long modinv(long a, long p) {
		assertion((a>0)&&(p>1)&&(a%p != 0));
		

		long b = p, u = 1L, v = 0L;
		while (b > 0) {
			long t = a / b;
			long pe = a%b;
			a = b;
			b = pe;
			pe = u-t*v;
			u = v;
			v = pe;
		}
		u %= p;
		if(u < 0L) u += p;
		return u;
	}
	
	private static long pow10E97(long ob, long soeji, long p) {		

		if(ob==0) return 0L;
		if(soeji==0) return 1L;
		if(soeji==2) return (ob*ob)%p;
		
		long cf = 1L;
		int d = 0;
		while(soeji >= cf) {
			d ++;
			cf = (1L<<d);
		}
		
		long[] ob_pow_2pow = new long[d];
		ob_pow_2pow[0] = ob;
		for(int i=1; i<d; i++) {
			ob_pow_2pow[i] = (ob_pow_2pow[i-1]*ob_pow_2pow[i-1])%p;
		}
		long ans=1L;
		for(long i=(d-1); i>=0L; i--) {
			if(soeji >= (1L<<i)) {
				soeji -= (1L<<i);
				ans = (ans*ob_pow_2pow[(int)i])%p;
			}
 		}
		return ans%p;
	}
	
	private static int inC2(int n) {
		return ((n*(n-1))/2);
	}
	private static long nC2(long n) {
		return ((n*(n-1L))/2L);
	}
	
	private static int intflag(int pos) {
		assertion(pos<31);
		return (1<<pos);
	}
	private static long flag(long pos) {
		assertion(pos<63);
		return (1L<<pos);
	}
	private static boolean isFlaged(int bit, int pos) {
		if((bit&(1<<pos)) > 0) return true;
		else return false;
	}
	private static boolean isFlaged(long bit, int pos) {
		if((bit&(1L<<pos)) > 0L) return true;
		else return false;
	}
	private static int ideflag(int bit, int pos) {
		return bit&~(1<<pos);
	}
	private static int countFlaged(int bit) {
		int ans=0;
		for(int i=0; i<31; i++) {
			if((bit&(1<<i)) > 0) ans++;
		}
		return ans;
	}
	private static int countFlaged(long bit) {
		int ans=0;
		for(long i=0; i<63; i++) {
			if((bit&(1L<<i)) > 0) ans++;
		}
		return ans;
	}
	
	public static int biSearch(int[] dt, int target) {
		int left=0, right=dt.length-1;
		int mid=-1;
		while(left<=right) {
			mid = (right+left)/2;
			if(dt[mid] == target) return mid;
			if(dt[mid] < target) left=mid+1;
			else right=mid-1;
		}
		return -1;
	}
	
	private static void show2(int bit) {
		for(int i=0; i<getDigit2(bit); i++) {
			if(isFlaged(bit,i)) System.out.print("O");
			else System.out.print(".");
		}
		System.out.println();
	}
	static void show2(boolean[][] dt, int lit_x, int lit_y) {
		for(int j=0; j<dt.length; j++) {
			for(int i=0; i<dt[j].length; i++) {
				if((i==lit_y) && (j==lit_x)) System.out.print("X");
				else if(dt[j][i]) System.out.print("O");
				else System.out.print(".");
			}
			System.out.println();
		}
	}
	static void show2(int[][] dt, String cmnt) {
		for(int i=0; i<dt.length; i++) {
			for(int j=0; j<dt[i].length; j++) {
				System.out.print(dt[i][j]+",");
			}
			System.out.println("<-"+cmnt+":"+i);
		}
	}
	static void show2(long[][] dt, String cmnt) {
		for(int i=0; i<dt.length; i++) {
			for(int j=0; j<dt[i].length; j++) {
				System.out.print(dt[i][j]+",");
			}
			System.out.println("<-"+cmnt+":"+i);
		}
	}
	static void show2(ArrayDeque<Long> dt) {		

		long a=0;
		while(dt.size()>0) {
			a=dt.removeFirst();
			System.out.print(a);
		}
		System.out.println("\n");
	}
	static void show2(List dt) {		

	 	for(int i=0; i<dt.size(); i++) {
			System.out.print(dt.get(i)+",");
		}
		System.out.println("\n");
	}
	
	private static void prtlnas(int[] as) {
		PrintWriter out = new PrintWriter(System.out);
		for(int i=0; i<as.length; i++) {
			out.println(as[i]);
		}
		out.flush();
	}
	private static void prtlnas(long[] as) {
		PrintWriter out = new PrintWriter(System.out);
		for(int i=0; i<as.length; i++) {
			out.println(as[i]);
		}
		out.flush();
	}
	private static void prtspas(int[] as) {
		PrintWriter out = new PrintWriter(System.out);
		out.print(as[0]);
		for(int i=1; i<as.length; i++) {
			out.print(" "+as[i]);
		}
		out.println();
		out.flush();
	}
	private static void prtspas(long[] as) {
		PrintWriter out = new PrintWriter(System.out);
		out.print(as[0]);
		for(int i=1; i<as.length; i++) {
			out.print(" "+as[i]);
		}
		out.println();
		out.flush();
	}
	private static void prtspas(ArrayList as) {
		PrintWriter out = new PrintWriter(System.out);
		out.print(as.get(0));
		for(int i=1; i<as.size(); i++) {
			out.print(" "+as.get(i));
		}
		out.println();
		out.flush();
	}
	
	private static void fill(boolean[] ob, boolean res) {
		for(int i=0; i<ob.length; i++) {
			ob[i] = res;
		}
	}
	private static void fill(int[] ob, int res) {
		for(int i=0; i<ob.length; i++) {
			ob[i] = res;
		}
	}
	private static void fill(long[] ob, long res) {
		for(int i=0; i<ob.length; i++) {
			ob[i] = res;
		}
	}
	private static void fill(char[] ob, char res) {
		for(int i=0; i<ob.length; i++) {
			ob[i] = res;
		}
	}
	private static void fill(double[] ob, double res) {
		for(int i=0; i<ob.length; i++) {
			ob[i] = res;
		}
	}
	private static void fill(boolean[][] ob,boolean res) {
		for(int i=0;i<ob.length; i++) {
			for(int j=0; j<ob[0].length; j++) {
				ob[i][j] = res;
			}
		}
	}
	private static void fill(int[][] ob, int res) {
		for(int i=0; i<ob.length; i++) {
			for(int j=0; j<ob[0].length; j++) {
				ob[i][j] = res;
			}
		}
	}
	private static void fill(long[][] ob, long res) {
		for(int i=0; i<ob.length; i++) {
			for(int j=0; j<ob[0].length; j++) {
				ob[i][j] = res;
			}
		}
	}
	private static void fill(char[][] ob, char res) {
		for(int i=0; i<ob.length; i++) {
			for(int j=0; j<ob[0].length; j++) {
				ob[i][j] = res;
			}
		}
	}
	private static void fill(double[][] ob, double res) {
		for(int i=0; i<ob.length; i++) {
			for(int j=0; j<ob[0].length; j++) {
				ob[i][j] = res;
			}
		}
	}
	private static void fill(int[][][] ob,int res) {
		for(int i=0;i<ob.length;i++) {
			for(int j=0;j<ob[0].length;j++) {
				for(int k=0;k<ob[0][0].length;k++) {
					ob[i][j][k]=res;
				}
			}
		}
	}
	private static void fill(long[][][] ob,long res) {
		for(int i=0;i<ob.length;i++) {
			for(int j=0;j<ob[0].length;j++) {
				for(int k=0;k<ob[0][0].length;k++) {
					ob[i][j][k]=res;
				}
			}
		}
	}
	static class FastScanner {
		private final InputStream in = System.in;
		private final byte[] buffer = new byte[1024];
		private int ptr = 0;
		private int buflen = 0;
		private boolean hasNextByte() {
			if(ptr < buflen) {
				return true;
			}else{
				ptr = 0;
				try {
					buflen = in.read(buffer);
				} catch (IOException e) {
					e.printStackTrace();
				}
				if(buflen <= 0) {
					return false;
				}
			}
			return true;
		}
		private int readByte() {
			if(hasNextByte()) return buffer[ptr++];
			else return -1;
		}
		private static boolean isPrintableChar(int c) {
			return (33 <= c) && (c <= 126);
		}
		public boolean hasNext() {
			while(hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++;
			return hasNextByte();
		}
		public String next() {
			if(!hasNext()) throw new NoSuchElementException();
			StringBuilder sb = new StringBuilder();
			int b = readByte();
			while(isPrintableChar(b)) {
				sb.appendCodePoint(b);
				b = readByte();
			}
			return sb.toString();
		}
		public long nexL() {
			if(!hasNext()) throw new NoSuchElementException();
			long n = 0;
			boolean minus = false;
			int b = readByte();
			if(b == '-') {
				minus = true;
				b = readByte();
			}
			if(b < '0' || '9' < b) {
				throw new NumberFormatException();
			}
			while(true) {
				if('0' <= b && b <= '9') {
					n *= 10;
					n += b - '0';
				}else if(b == -1 || !isPrintableChar(b) || b == ':') {
					return minus ? -n : n;
				}else{
					throw new NumberFormatException();
				}
				b = readByte();
			}
		}
		public int nexI() {
			long nl = nexL();
			if(nl < Integer.MIN_VALUE || nl > Integer.MAX_VALUE) throw new NumberFormatException();
			return (int) nl;
		}
		public double nexD() { return Double.parseDouble(next());}
		public void al(long[] array) {
		 	for(int i=0; i<array.length; i++) {
		 		array[i] = nexL();
		 	}
		 	return;
		}
		public void ai(int[] array) {
		 	for(int i=0; i<array.length; i++) {
		 		array[i] = nexI();
		 	}
		 	return;
		}
		public void aimin1(int[] array) {
		 	for(int i=0; i<array.length; i++) {
		 		array[i] = nexI()-1;
		 	}
		 	return;
		}
		public void aD(double[] array) {
		 	for(int i=0; i<array.length; i++) {
		 		array[i] = nexD();
		 	}
		 	return;
		}
		public void ai2(int[] as, int[] bs) {
		 	for(int i=0; i<as.length; i++) {
				as[i] = nexI();
				bs[i] = nexI();
		 	}
		 	return;
		}
		public void al2(long[] as, long[] bs) {
		 	for(int i=0; i<as.length; i++) {
				as[i] = nexL();
				bs[i] = nexL();
		 	}
		 	return;
		}
		public void ai3(int[] as, int[] bs, int[] cs) {
		 	for(int i=0; i<as.length; i++) {
				as[i] = nexI();
				bs[i] = nexI();
				cs[i] = nexI();
		 	}
		 	return;
		}
		public void ad2i(int[][] as) {
			for(int i=0; i<as.length; i++) {
				for(int j=0; j<as[0].length; j++) {
					as[i][j] = nexI();
				}
			}
			return;
		}
		public void ain(int[]... as) {
			for(int i=0; i<as[0].length; i++) {
				for(int j=0; j<as.length; j++) {
					as[j][i] = nexI();
				}
			}
			return;
		}
		public void aln(long[]... as) {
			for(int i=0; i<as[0].length; i++) {
				for(int j=0; j<as.length; j++) {
					as[j][i] = nexL();
				}
			}
			return;
		}
	}
	
	static class Graph0n {
		private ArrayList<Node0n> dt = new ArrayList<>();
		Graph0n(int sz) {
			for(int i = 0; i < sz; i++) {
				Node0n node1 = new Node0n();
				dt.add(node1);
			}
		}
		public void add(int vn, int val) {
			dt.get(vn).add(val);
		}
		public void add2(int vn, int val) {
			dt.get(vn).add(val);
			dt.get(val).add(vn);
		}
		public int get(int vn, int index) {
			return dt.get(vn).get(index);
		}
		public ArrayList<Integer> get(int vn) {
			return dt.get(vn).getAll();
		}
		public int size() {
			return dt.size();
		}
		public int sizeOf(int vn) {
			return dt.get(vn).size();
		}
		public void clear() {
			for(int i = 0; i < dt.size(); i++) {
				dt.get(i).clear();
			}
		}
		public void clear(int i) {
			dt.get(i).clear();
		}
		public static Graph0n make_tree(int vn, FastScanner sc) {
			Graph0n tree = new Graph0n(vn);
			for(int i = 1; i < vn; i++) {
				int s1 = sc.nexI() - 1;
				int g1 = sc.nexI() - 1;
				tree.add2(s1, g1);
			}
			return tree;
		}
		private void add_Vertex(Node0n vnew) {
			dt.add(vnew);
		}
	}

	static class Node0n { 

		private ArrayList<Integer> next_vs = new ArrayList<>();
		public void add(int val) {
			next_vs.add(val);
		}
		public int get(int ad) {
			return next_vs.get(ad);
		}
		public ArrayList<Integer> getAll() {
			return next_vs;
		}
		public int size() {
			return next_vs.size();
		}
		public void clear() {
			next_vs.clear();
		}
		public void addAll(Node0n vnew) {
			this.next_vs.addAll(vnew.next_vs);
		}
	}
	
	static class Edge {
		int from=-1, v2=-1;
		long weight;
		public Edge(int vn, long w) {
			this.v2 = vn;
			this.weight = w;
		}
		public Edge(int cm, int vn, long w) {
			this.from = cm;
			this.v2 = vn;
			this.weight = w;
		}
	}
	
	static class Edge2 {
		int v2;
		long cost1,cost2;
		public Edge2(int vn, long w1, long w2) {
			this.v2 = vn;
			this.cost1 = w1;
			this.cost2 = w2;
		}
	}
	
	static class CompEdge_float implements Comparator<Edge>{
		

		public int compare(Edge a, Edge b) {
			if(a.weight>b.weight) return 1;
			else if(a.weight<b.weight) return -1;
			else return a.v2-b.v2;
		}
	}
	static class Vector {
		int x,y;
		public Vector(int sx, int sy) {
			this.x=sx;
			this.y=sy;
		}
	}
}