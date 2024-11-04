import java.io.*;
import java.math.*;
import java.util.*;

public class Main {
	InputStream is;
	FastWriter out;
	String INPUT = "";
	
	public static void main(String[] args) throws Exception 
	{
		new Main().run();

	}
	
	void solve()
	{
		int t=ni();
		while(t-->0)
			go();
	}
	
	void go()
	{
		int i,n=ni(),j=0;
		char arr[]=ns().toCharArray();
		char brr[]=Arrays.copyOf(arr, n);
		String s1="",s2="";
		if(n==1&&arr[0]=='?')
		{
			out.println("R");
			return;
		}
		int fg=0;
		for(i=0;i<n;i++)
		{
			if(arr[i]!='?')
			{
				fg=1;
				for(j=i-1;j>=0;j--)
				{
					if(arr[j]=='?')
					{
						if(arr[j+1]=='R')
							arr[j]='B';
						else 
							arr[j]='R';
					}
				}
			}
		}
		if(fg==0)
		{
			for(i=0;i<n;i++)
			{
				if(i%2==0)
					s1+='R';
				else 
					s1+='B';
			}
			out.println(s1);
			return;
		}
		if(arr[n-1]=='?')
		{
			for(i=1;i<n;i++)
			{
				if(arr[i]=='?') {
				if(arr[i-1]=='R')
					arr[i]='B';
				else 
					arr[i]='R';
				}
			}
		}
		int c1=0,c2=0;
		for(i=0;i<n;i++)
		{
			s1=s1+arr[i];
			if(i<n-1&&arr[i]==arr[i+1])
				c1++;
		}
		for(i=n-1;i>=0;i--)
		{
			if(brr[i]!='?')
			{
				for(j=i+1;j<n;j++)
				{
					if(brr[j]=='?')
					{
						if(brr[j-1]=='R')
							brr[j]='B';
						else 
							brr[j]='R';
					}
				}
			}
		}
		if(brr[0]=='?')
		{
			for(i=n-2;i>=0;i--)
			{
				if(brr[i]=='?') {
				if(brr[i+1]=='R')
					brr[i]='B';
				else 
					brr[i]='R';
				}
			}
		}
		for(i=0;i<n;i++)
		{
			s2+=brr[i];
			if(i<n-1&&brr[i]==brr[i+1])
				c2++;
		}


		if(c1<c2)
			out.println(s1);
		else 
			out.println(s2);
	}
	
	static boolean prime[];
	static int count=0;
	void sieve(int n)
	{
		prime=new boolean[n+1];
		Arrays.fill(prime, true);
		for(int i=2;i<=Math.sqrt(n);i++)
			if(prime[i])
				for(int j=i*i;j<=n;j+=i)
					prime[j]=false;
	}
	
	boolean isPrime(int n)
	{
		for(int i=2;i<=Math.sqrt(n);i++)
			if(n%i==0)
				return false;
		return true;
	}
	
	long gcd(long a,long b)
	{
		if(a==0)
			return b;
		return gcd(b%a,a);
	}
	
	void run() throws Exception
	{
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new FastWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	byte[] inbuf = new byte[1024];
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
	
	private int[] ni(int n)
	{
		int[] a = new int[n];
		for(int i = 0;i < n;i++)a[i] = ni();
		return a;
	}
	
	private long[] nl(int n)
	{
		long[] a = new long[n];
		for(int i = 0;i < n;i++)a[i] = nl();
		return a;
	}
	
	private Long[] nL(int n) {
		Long[] a = new Long[n];
		for (int i = 0; i < n; i++)
			a[i] = nl();
		return a;
	}
	
	private Integer[] nI(int n) {
		Integer[] a = new Integer[n];
		for (int i = 0; i < n; i++)
			a[i] = ni();
		return a;
	}
	
	private char[][] ns(int n, int m) {
		char[][] map = new char[n][];
		for(int i = 0;i < n;i++)map[i] = ns(m);
		return map;
	}
	
	private int[][] ni(int n, int m) {
		int[][] map = new int[n][];
		for(int i = 0;i < n;i++)map[i] = ni(m);
		return map;
	}
	
	private long[][] nl(int n, int m) {
		long[][] map = new long[n][];
		for(int i = 0;i < n;i++)map[i] = nl(m);
		return map;
	}
	
	private Integer[][] nI(int n, int m) {
		Integer[][] map = new Integer[n][];
		for(int i = 0;i < n;i++)map[i] = nI(m);
		return map;
	}
	
	private Long[][] nL(int n, int m) {
		Long[][] map = new Long[n][];
		for(int i = 0;i < n;i++)map[i] = nL(m);
		return map;
	}
	
	private int ni() { return (int)nl(); }
	
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
	
	public static class FastWriter
	{
		private static final int BUF_SIZE = 1<<13;
		private final byte[] buf = new byte[BUF_SIZE];
		private final OutputStream out;
		private int ptr = 0;
		
		private FastWriter(){out = null;}
		
		public FastWriter(OutputStream os)
		{
			this.out = os;
		}
		
		public FastWriter(String path)
		{
			try {
				this.out = new FileOutputStream(path);
			} catch (FileNotFoundException e) {
				throw new RuntimeException("FastWriter");
			}
		}
		
		public FastWriter write(byte b)
		{
			buf[ptr++] = b;
			if(ptr == BUF_SIZE)innerflush();
			return this;
		}
		
		public FastWriter write(char c)
		{
			return write((byte)c);
		}
		
		public FastWriter write(char[] s)
		{
			for(char c : s){
				buf[ptr++] = (byte)c;
				if(ptr == BUF_SIZE)innerflush();
			}
			return this;
		}
		
		public FastWriter write(String s)
		{
			s.chars().forEach(c -> {
				buf[ptr++] = (byte)c;
				if(ptr == BUF_SIZE)innerflush();
			});
			return this;
		}
		
		public FastWriter write(int x)
		{
			if(x == Integer.MIN_VALUE){
				return write((long)x);
			}
			if(ptr + 12 >= BUF_SIZE)innerflush();
			if(x < 0){
				write((byte)'-');
				x = -x;
			}
			int d = countDigits(x);
			for(int i = ptr + d - 1;i >= ptr;i--){
				buf[i] = (byte)('0'+x%10);
				x /= 10;
			}
			ptr += d;
			return this;
		}
		
		private static int countDigits(int l) 
		{
			if (l >= 1000000000) return 10;
			if (l >= 100000000) return 9;
			if (l >= 10000000) return 8;
			if (l >= 1000000) return 7;
			if (l >= 100000) return 6;
			if (l >= 10000) return 5;
			if (l >= 1000) return 4;
			if (l >= 100) return 3;
			if (l >= 10) return 2;
			return 1;
		}
		
		private static int countDigits(long l) {
			if (l >= 1000000000000000000L) return 19;
			if (l >= 100000000000000000L) return 18;
			if (l >= 10000000000000000L) return 17;
			if (l >= 1000000000000000L) return 16;
			if (l >= 100000000000000L) return 15;
			if (l >= 10000000000000L) return 14;
			if (l >= 1000000000000L) return 13;
			if (l >= 100000000000L) return 12;
			if (l >= 10000000000L) return 11;
			if (l >= 1000000000L) return 10;
			if (l >= 100000000L) return 9;
			if (l >= 10000000L) return 8;
			if (l >= 1000000L) return 7;
			if (l >= 100000L) return 6;
			if (l >= 10000L) return 5;
			if (l >= 1000L) return 4;
			if (l >= 100L) return 3;
			if (l >= 10L) return 2;
			return 1;
		}
		
		public FastWriter write(long x)
		{
			if(x == Long.MIN_VALUE){
				return write("" + x);
			}
			if(ptr + 21 >= BUF_SIZE)innerflush();
			if(x < 0){
				write((byte)'-');
				x = -x;
			}
			int d = countDigits(x);
			for(int i = ptr + d - 1;i >= ptr;i--){
				buf[i] = (byte)('0'+x%10);
				x /= 10;
			}
			ptr += d;
			return this;
		}
		
		public FastWriter write(double x, int precision)
		{
			if(x < 0){
				write('-');
				x = -x;
			}
			x += Math.pow(10, -precision)/2;
			

			write((long)x).write(".");
			x -= (long)x;
			for(int i = 0;i < precision;i++){
				x *= 10;
				write((char)('0'+(int)x));
				x -= (int)x;
			}
			return this;
		}
		
		public FastWriter writeln(char c){
			return write(c).writeln();
		}
		
		public FastWriter writeln(int x){
			return write(x).writeln();
		}
		
		public FastWriter writeln(long x){
			return write(x).writeln();
		}
		
		public FastWriter writeln(double x, int precision){
			return write(x, precision).writeln();
		}
		
		public FastWriter write(int... xs)
		{
			boolean first = true;
			for(int x : xs) {
				if (!first) write(' ');
				first = false;
				write(x);
			}
			return this;
		}
		
		public FastWriter write(long... xs)
		{
			boolean first = true;
			for(long x : xs) {
				if (!first) write(' ');
				first = false;
				write(x);
			}
			return this;
		}
		
		public FastWriter writeln()
		{
			return write((byte)'\n');
		}
		
		public FastWriter writeln(int... xs)
		{
			return write(xs).writeln();
		}
		
		public FastWriter writeln(long... xs)
		{
			return write(xs).writeln();
		}
		
		public FastWriter writeln(char[] line)
		{
			return write(line).writeln();
		}
		
		public FastWriter writeln(char[]... map)
		{
			for(char[] line : map)write(line).writeln();
			return this;
		}
		
		public FastWriter writeln(String s)
		{
			return write(s).writeln();
		}
		
		private void innerflush()
		{
			try {
				out.write(buf, 0, ptr);
				ptr = 0;
			} catch (IOException e) {
				throw new RuntimeException("innerflush");
			}
		}
		
		public void flush()
		{
			innerflush();
			try {
				out.flush();
			} catch (IOException e) {
				throw new RuntimeException("flush");
			}
		}
		
		public FastWriter print(byte b) { return write(b); }
		public FastWriter print(char c) { return write(c); }
		public FastWriter print(char[] s) { return write(s); }
		public FastWriter print(String s) { return write(s); }
		public FastWriter print(int x) { return write(x); }
		public FastWriter print(long x) { return write(x); }
		public FastWriter print(double x, int precision) { return write(x, precision); }
		public FastWriter println(char c){ return writeln(c); }
		public FastWriter println(int x){ return writeln(x); }
		public FastWriter println(long x){ return writeln(x); }
		public FastWriter println(double x, int precision){ return writeln(x, precision); }
		public FastWriter print(int... xs) { return write(xs); }
		public FastWriter print(long... xs) { return write(xs); }
		public FastWriter println(int... xs) { return writeln(xs); }
		public FastWriter println(long... xs) { return writeln(xs); }
		public FastWriter println(char[] line) { return writeln(line); }
		public FastWriter println(char[]... map) { return writeln(map); }
		public FastWriter println(String s) { return writeln(s); }
		public FastWriter println() { return writeln(); }
	}
	
	public void trnz(int... o)
	{
		for(int i = 0;i < o.length;i++)if(o[i] != 0)System.out.print(i+":"+o[i]+" ");
		System.out.println();
	}
	
	

	public void trt(long... o)
	{
		Queue<Integer> stands = new ArrayDeque<>();
		for(int i = 0;i < o.length;i++){
			for(long x = o[i];x != 0;x &= x-1)stands.add(i<<6|Long.numberOfTrailingZeros(x));
		}
		System.out.println(stands);
	}
	
	public void tf(boolean... r)
	{
		for(boolean x : r)System.out.print(x?'#':'.');
		System.out.println();
	}
	
	public void tf(boolean[]... b)
	{
		for(boolean[] r : b) {
			for(boolean x : r)System.out.print(x?'#':'.');
			System.out.println();
		}
		System.out.println();
	}
	
	public void tf(long[]... b)
	{
		if(INPUT.length() != 0) {
			for (long[] r : b) {
				for (long x : r) {
					for (int i = 0; i < 64; i++) {
						System.out.print(x << ~i < 0 ? '#' : '.');
					}
				}
				System.out.println();
			}
			System.out.println();
		}
	}
	
	public void tf(long... b)
	{
		if(INPUT.length() != 0) {
			for (long x : b) {
				for (int i = 0; i < 64; i++) {
					System.out.print(x << ~i < 0 ? '#' : '.');
				}
			}
			System.out.println();
		}
	}
	
	private boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	private void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}