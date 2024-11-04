import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.HashSet;
import java.util.List;
import java.util.NoSuchElementException;

public class Main {

	

	

	public static void main(String[] args) throws Exception {

		FastScanner sc = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);

	    Comparator<Integer> comparator = new Comparator<Integer>() {
	      @Override
	      public int compare(Integer o1, Integer o2) {
	        return Integer.valueOf(o1).compareTo(Integer.valueOf(o2));
	      }
	    };

		int Q = sc.id21();

		for(int t=0; t<Q; t++) {
			int n = sc.id21();
			int m = sc.id21();

			int[] as = new int[n];
			sc.ai(as);
			
			int ans=1;
			
			HashSet<List<Integer>> dt = new HashSet<>();
			
			for(int i=0; i<n; i++) {
				List<Integer> fd = id15(as[i]);
				if(dt.contains(fd)) {
					ans++;
					dt = new HashSet<>();
				}
				dt.add(fd);
			}
			out.println(ans);
		}
		
		
		out.flush();
		return;
	}
	
	private static List<Integer> id15(int n){   

	    List<Integer> ans = new ArrayList<>();

	    int quotient = n;
	    int devider = 2;
	    int exponent = 0;

	    while(quotient%devider == 0){
	        quotient /= devider;
	        exponent++;
	    }
	    if(exponent%2==1) ans.add(devider);

	    devider = 3;    exponent = 0;
	    while(quotient%devider == 0){
	        quotient /= devider;
	        exponent++;
	    }
	    if(exponent%2==1) ans.add(devider);

	    devider=1;
	    while(devider <= Math.sqrt(n)){
	        devider+=4L; exponent=0;
    	    while(quotient%devider == 0){
    	        quotient /= devider;
    	        exponent++;
    	    }
    	    if(exponent%2==1) ans.add(devider);

	        devider+=2L; exponent=0;
    	    while(quotient%devider == 0){
    	        quotient /= devider;
    	        exponent++;
    	    }
    	    if(exponent%2==1) ans.add(devider);
	    }
	    if(quotient>1) ans.add(quotient);
	    return ans;
	}

	
	private static int INF = (int) 1e8;
	private static long INFL = (long) 1e17;
	private static long e97 = 1000000007L;
	private static long e99 =  998244353L;

	private static void assertion(boolean should_true) {
		

		if(!should_true) throw new AssertionError();
	}

	private static int abs(int a) {
		return (a>=0) ? a: -a;
	}
	private static long abs(long a) {
		return (a>=0) ? a: -a;
	}
	private static double abs(double a) {
		return (a>=0.0) ? a: -a;
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


	private static int pow2(int id24) {
		return id24*id24;
	}
	private static long pow2(long id24) {
		return id24*id24;
	}


	private static int pow(int id18, int index) {
		int ans = 1;
		for(int i=0; i<index; i++) {
			ans *= id18;
			assertion(ans>=0);
		}
		return ans;
	}
	private static long pow(long id18, int index) {
		long ans = 1L;
		for(int i=0; i<index; i++) {
			ans *= id18;
			assertion(ans>=0L);
		}
		return ans;
	}
	private static long powP(long id18, long index, long p) {
		

		if(id18==0L) return 0L;
		if(index==0L) return 1L;
		if(index==2L) {
			long ans = id18*id18;
			assertion(ans>0);
			return ans%p;
		}

		int d = id0(index);

		long next = 0L;
		long[] id25 = new long[d+1];
		id25[0] = id18;
		for(int i=1; i<=d; i++) {
			next = id25[i-1]*id25[i-1];
			assertion(next>0);
			id25[i] = next%p;
		}
		long ans=1L;
		for(int i=d; i>=0; i--) {
			if(index >= (1L<<(long)i)) {
				index -= (1L<<(long)i);
				ans = ans*id25[i];
				assertion(ans>0);
				ans %= p;
			}
 		}
		return ans%p;
	}
	private static double hypod(double a, double b) {
		return Math.sqrt(a*a+b*b);
	}

	private static int id0(long id9) {
		long compare4 = 1L;
		int digit = 0;
		while(id9 > compare4) {
			digit ++;
			compare4 = (1L<<(long)digit);
		}
		return digit; 

	}
	private static int id16(long id9) {
		long compare4 = 1L;
		int digit = 0;
		while(id9 >= compare4) {
			digit ++;
			compare4 *= 10L;
		}
		return digit; 


	}


	private static int divceil(int numerator, int denominator) {
		return (numerator+denominator-1)/denominator;
	}
	private static long divceil(long numerator, long denominator) {
		return (numerator+denominator-1L)/denominator;
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
		

		assertion((m>=0L) && (n>=0L));
		if(m < n) return gcd(n, m);
		if(n == 0) return m;
		return gcd(n, m % n);
	}

	private static boolean is_prime(long id3) {
		if(id3==1L) return false;
		for(long i=2L; i<=Math.sqrt(id3); i++) {
			if(id3%i == 0) return false;
		}
		return true;
	}

	private static long modinv(long n, long p) {
		assertion((n>0L)&&(p>1L)&&(gcd(n,p)==1L));
		

		n %= p;

		

		

		

		

		


		long a=p, b=n, s=1, t=0, u=0, v=1;
		while(b>1) {
			long quo = a/b;
			long rem = a%b;
			a=b; b=rem;
			long s2 = s*quo+u, t2=t*quo+v;
			u=s; v=t;
			s=s2; t=t2;
		}
		long det = s*v-t*u;
		assertion(abs(det)==1);
		s /= det;

		
		s %= p;
		if(s < 0L) s += p;
		return s;
	}

	private static int minAll(int[] id23) {
		int min = INF;
		for(int i=0; i<id23.length; i++) {
			if(id23[i] < min) min = id23[i];
		}
		return min;
	}
	private static long minAll(long[] id23) {
		long min = INFL;
		for(int i=0; i<id23.length; i++) {
			if(id23[i] < min) min = id23[i];
		}
		return min;
	}
	private static int maxAll(int[] id2) {
		int max = -INF;
		for(int i=0; i<id2.length; i++) {
			if(id2[i] < max) max = id2[i];
		}
		return max;
	}
	private static long maxAll(long[] id2) {
		long max = -INFL;
		for(int i=0; i<id2.length; i++) {
			if(id2[i] < max) max = id2[i];
		}
		return max;
	}

	private static int sumAll(int[] id19) {
		int id10 = 0;
		for(int element: id19) {
			id10 += element;
		}
		return id10;
	}
	private static long sumAll(long[] id19) {
		long id10 = 0L;
		for(long element: id19) {
			id10 += element;
		}
		return id10;
	}
	private static int sumAll(ArrayList<Integer> id19) {
		int id10 = 0;
		for(long element: id19) {
			id10 += element;
		}
		return id10;
	}
	

	private static int[] reverse(int[] as) {
		int ln = as.length;
		int[] bs = new int[ln];
		for(int i=0; i<ln; i++) {
			bs[i] = as[ln-i-1];
		}
		return bs;
	}


	private static boolean id7(int y, int x, int height, int width) {
		if(y < 0) return false;
		if(x < 0) return false;
		if(y >= height) return false;
		if(x >= width) return false;
		return true;
	}

	private static boolean id7(Vector v, int height, int width) {
		if(v.y < 0) return false;
		if(v.x < 0) return false;
		if(v.y >= height) return false;
		if(v.x >= width) return false;
		return true;
	}


	private static int id28(int n) {
		return ((n*(n-1))/2);
	}
	private static long id28(long n) {
		return ((n*(n-1L))/2L);
	}


	private static int iflag(int pos) {
		assertion(pos<31);
		return (1<<pos);
	}
	private static long flag(int pos) {
		assertion(pos<63);
		return (1L<<(long)pos);
	}
	private static boolean id20(int bit, int pos) {
		if((bit&(1<<pos)) > 0) return true;
		else return false;
	}
	private static boolean id20(long bit, int pos) {
		if((bit&(1L<<(long)pos)) > 0L) return true;
		else return false;
	}
	private static int deflag(int bit, int pos) {
		return bit&~(1<<pos);
	}
	private static int id17(int bit) {
		int ans=0;
		for(int i=0; i<31; i++) {
			if((bit&(1<<i)) > 0) ans++;
		}
		return ans;
	}
	private static int id17(long bit) {
		int ans=0;
		for(long i=0; i<63L; i++) {
			if((bit&(1L<<i)) > 0) ans++;
		}
		return ans;
	}

	private static int[] id8 = {1,0,0,-1};
	private static int[] id11 = {0,1,-1,0};
	private static int[] id6 = {1,1,1,0,0,-1,-1,-1};
	private static int[] id27 = {1,0,-1,1,-1,1,0,-1};

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

	public static int id1(long[] dt, long target) {
		int left=-1, right=dt.length, mid=-1;
		while((right-left)>1) {
			mid = (right+left)/2;
			if(dt[mid] < target) left=mid;
			else right=mid;
		}
		return left;	

	}
	public static int id22(long[] dt, long target) {
		int left=-1, right=dt.length, mid=-1;
		while((right-left)>1) {
			mid = (right+left)/2;
			if(dt[mid] <= target) left=mid;
			else right=mid;
		}
		return right;	

	}

	private static void fill(boolean[] target, boolean reset) {
		for(int i=0; i<target.length; i++) {
			target[i] = reset;
		}
	}
	private static void fill(int[] target, int reset) {
		for(int i=0; i<target.length; i++) {
			target[i] = reset;
		}
	}
	private static void fill(long[] target, long reset) {
		for(int i=0; i<target.length; i++) {
			target[i] = reset;
		}
	}
	private static void fill(char[] target, char reset) {
		for(int i=0; i<target.length; i++) {
			target[i] = reset;
		}
	}
	private static void fill(double[] target, double reset) {
		for(int i=0; i<target.length; i++) {
			target[i] = reset;
		}
	}

	private static void fill(boolean[][] target,boolean reset) {
		for(int i=0;i<target.length; i++) {
			for(int j=0; j<target[i].length; j++) {
				target[i][j] = reset;
			}
		}
	}
	private static void fill(int[][] target, int reset) {
		for(int i=0; i<target.length; i++) {
			for(int j=0; j<target[i].length; j++) {
				target[i][j] = reset;
			}
		}
	}
	private static void fill(long[][] target, long reset) {
		for(int i=0; i<target.length; i++) {
			for(int j=0; j<target[i].length; j++) {
				target[i][j] = reset;
			}
		}
	}
	private static void fill(char[][] target, char reset) {
		for(int i=0; i<target.length; i++) {
			for(int j=0; j<target[i].length; j++) {
				target[i][j] = reset;
			}
		}
	}
	private static void fill(double[][] target, double reset) {
		for(int i=0; i<target.length; i++) {
			for(int j=0; j<target[i].length; j++) {
				target[i][j] = reset;
			}
		}
	}
	private static void fill(int[][][] target,int reset) {
		for(int i=0;i<target.length;i++) {
			for(int j=0;j<target[i].length;j++) {
				for(int k=0;k<target[i][j].length;k++) {
					target[i][j][k]=reset;
				}
			}
		}
	}
	private static void fill(long[][][] target,long reset) {
		for(int i=0;i<target.length;i++) {
			for(int j=0;j<target[i].length;j++) {
				for(int k=0;k<target[i][j].length;k++) {
					target[i][j][k]=reset;
				}
			}
		}
	}

	private static void showBit(int bit) {
		for(int i=0; i<id0(bit); i++) {
			if(id20(bit,i)) System.out.print("O");
			else System.out.print(".");
		}
		System.out.println();
	}
	private static void showBit(long bit) {
		for(int i=0; i<id0(bit); i++) {
			if(id20(bit,i)) System.out.print("O");
			else System.out.print(".");
		}
		System.out.println();
	}
	static void show2(boolean[][] dt, String cmnt) {
		for(int i=0; i<dt.length; i++) {
			for(int j=0; j<dt[i].length; j++) {
				if(dt[i][j]) System.out.print("O");
				else System.out.print(".");
			}
			if(!cmnt.equals("")) System.out.print("<-"+cmnt);
			System.out.println(" :"+i);
		}
	}
	static void show2(int[][] dt, String cmnt) {
		for(int i=0; i<dt.length; i++) {
			for(int j=0; j<dt[i].length; j++) {
				System.out.print(dt[i][j]+",");
			}
			if(!cmnt.equals("")) System.out.print("<-"+cmnt);
			System.out.println(" :"+i);
		}
	}
	static void show2(long[][] dt, String cmnt) {
		for(int i=0; i<dt.length; i++) {
			for(int j=0; j<dt[i].length; j++) {
				System.out.print(dt[i][j]+",");
			}
			if(!cmnt.equals("")) System.out.print("<-"+cmnt);
			System.out.println(" :"+i);
		}
	}
	static void show2(ArrayDeque<Long> dt) {		

		long element=0;
		while(dt.size()>0) {
			element=dt.removeFirst();
			System.out.print(element);
		}
		System.out.println("\n");
	}
	static void show2(List<Object> dt) {		

	 	for(int i=0; i<dt.size(); i++) {
			System.out.print(dt.get(i)+",");
		}
		System.out.println("\n");
	}

	private static void id12(int[] array) {
		PrintWriter out = new PrintWriter(System.out);
		for(int i=0; i<array.length; i++) {
			out.println(array[i]);
		}
		out.flush();
	}
	private static void id12(long[] array) {
		PrintWriter out = new PrintWriter(System.out);
		for(int i=0; i<array.length; i++) {
			out.println(array[i]);
		}
		out.flush();
	}
	private static void id12(ArrayList<Object> array) {
		PrintWriter out = new PrintWriter(System.out);
		for(int i=0; i<array.size(); i++) {
			out.println(array.get(i));
		}
		out.flush();
	}
	private static void id4(int[] array) {
		PrintWriter out = new PrintWriter(System.out);
		out.print(array[0]);
		for(int i=1; i<array.length; i++) {
			out.print(" "+array[i]);
		}
		out.println();
		out.flush();
	}
	private static void id4(long[] array) {
		PrintWriter out = new PrintWriter(System.out);
		out.print(array[0]);
		for(int i=1; i<array.length; i++) {
			out.print(" "+array[i]);
		}
		out.println();
		out.flush();
	}
	private static void id4(ArrayList<Integer> array) {
		PrintWriter out = new PrintWriter(System.out);
		out.print(array.get(0));
		for(int i=1; i<array.size(); i++) {
			out.print(" "+array.get(i));
		}
		out.println();
		out.flush();
	}


	static class Vector {
		int x,y;
		public Vector(int sx, int sy) {
			this.x=sx;
			this.y=sy;
		}
	}

	static class FastScanner {
		private final InputStream in = System.in;
		private final byte[] buffer = new byte[1024];
		private int ptr = 0;
		private int buflen = 0;
		private boolean id29() {
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
			if(id29()) return buffer[ptr++];
			else return -1;
		}
		private static boolean id30(int c) {
			return (33 <= c) && (c <= 126);
		}
		public boolean hasNext() {
			while(id29() && !id30(buffer[ptr])) ptr++;
			return id29();
		}
		public String next() {
			if(!hasNext()) throw new NoSuchElementException();
			StringBuilder sb = new StringBuilder();
			int b = readByte();
			while(id30(b)) {
				sb.appendCodePoint(b);
				b = readByte();
			}
			return sb.toString();
		}
		public long id13() {
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
				}else if(b == -1 || !id30(b) || b == ':') {
					return minus ? -n : n;
				}else{
					throw new NumberFormatException();
				}
				b = readByte();
			}
		}
		public int id21() {
			long nl = id13();
			if(nl < Integer.MIN_VALUE || nl > Integer.MAX_VALUE) throw new NumberFormatException();
			return (int) nl;
		}
		public double id14() { return Double.parseDouble(next());}
		

		public void ai(int[]... array) {
			for(int i=0; i<array[0].length; i++) {
				for(int j=0; j<array.length; j++) {
					array[j][i] = id21();
				}
			}
			return;
		}
		public void al(long[]... array) {
			for(int i=0; i<array[0].length; i++) {
				for(int j=0; j<array.length; j++) {
					array[j][i] = id13();
				}
			}
			return;
		}
		public void id5(int[] array) {
		 	for(int i=0; i<array.length; i++) {
		 		array[i] = id21()-1;
		 	}
		 	return;
		}
		public void aD(double[] array) {
		 	for(int i=0; i<array.length; i++) {
		 		array[i] = id14();
		 	}
		 	return;
		}
		public void id26(int[][] array) {
			for(int i=0; i<array.length; i++) {
				for(int j=0; j<array[0].length; j++) {
					array[i][j] = id21();
				}
			}
			return;
		}
	}
}

