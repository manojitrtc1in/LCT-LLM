import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

import java.lang.*;

public class B {
	static long mod = 1000000007;
	static boolean ans=false;
	static int n,m;
	static char g[][];
	static boolean v[][];
	static int c[][];
	static HashSet<Pair1>hs1=new HashSet<>(); 

	static HashSet<Pair1>hs2=new HashSet<>(); 

	static HashSet<Pair1>hs3=new HashSet<>(); 

	static HashSet<Pair1>hs4=new HashSet<>(); 

	static HashSet<Pair1>hs11=new HashSet<>(); 

	static HashSet<Pair1>hs22=new HashSet<>(); 

	static HashSet<Pair1>hs33=new HashSet<>(); 

	static HashSet<Pair1>hs44=new HashSet<>(); 

	static class Pair1 implements Comparable<Pair1>
	{
		int a,b;
		Pair1 (int a,int b)
		{
			this.a=a;
			this.b=b;
		}

		public int compareTo(Pair1 o) {
			

			if(this.a!=o.a)
			return Integer.compare(this.a,o.a);
			else
				return Integer.compare(this.b, o.b);
			

		}
		public boolean equals(Object o) {
	        if (o instanceof Pair1) {
	            Pair1 p = (Pair1)o;
	            return p.a == a && p.b == b;
	        }
	        return false;
	    }
	    public int hashCode() {
	        return new Integer(a).hashCode() * 31 + new Integer(b).hashCode();
	    }

		public String toString()
	    {
	    	return a+" "+b;
	    }
	} 
	static void fill0(int x,int y) {
		for(int i=x-1;i>=0;i--) {
			if(g[i][y]!='*') {
				c[i][y]=0;
				hs1.add(new Pair1(i,y));
			}
			else
				break;
		}
		for(int i=x+1;i<n;i++) {
			if(g[i][y]!='*') {
				c[i][y]=0;
				hs1.add(new Pair1(i,y));
			}
			else {
				break;
			}
		}
		for(int i=y-1;i>=0;i--) {
			if(g[x][i]!='*') {
				c[x][i]=0;
				hs2.add(new Pair1(x,i));
			}
			else {
				break;
			}
		}
		for(int i=y+1;i<m;i++) {
			if(g[x][i]!='*') {
				c[x][i]=0;
				hs2.add(new Pair1(x,i));
			}
			else {
				break;
			}
		}
	}
	static void fill1() {
		for(Pair1 p :hs1) { 

			int x=p.a;
			int y=p.b;
		
			for(int i=y-1;i>=0;i--) {
				if(g[x][i]!='*'&&c[x][i]!=0) {
					c[x][i]=1;
					hs22.add(new Pair1(x,i));
				}
				else {
					break;
				}
			}
			for(int i=y+1;i<m;i++) {
				if(g[x][i]!='*'&&c[x][i]!=0) {
					c[x][i]=1;
					hs22.add(new Pair1(x,i));
				}
				else {
					break;
				}
			}
		}
		for(Pair1 p :hs2) { 

			int x=p.a;
			int y=p.b;
		
			for(int i=x-1;i>=0;i--) {
				if(g[i][y]!='*' &&c[i][y]!=0) {
					c[i][y]=1;
					hs11.add(new Pair1(i,y));
				}
				else
					break;
			}
			for(int i=x+1;i<n;i++) {
				if(g[i][y]!='*' &&c[i][y]!=0) {
					c[i][y]=1;
					hs11.add(new Pair1(i,y));
				}
				else {
					break;
				}
			}
		}
	}
	static void fill2() {
		for(Pair1 p :hs11) { 

			int x=p.a;
			int y=p.b;
		
			for(int i=y-1;i>=0;i--) {
				if(g[x][i]!='*'&&c[x][i]>1) {
					c[x][i]=2;
					

				}
				else {
					break;
				}
			}
			for(int i=y+1;i<m;i++) {
				if(g[x][i]!='*'&&c[x][i]>1) {
					c[x][i]=2;
					

				}
				else {
					break;
				}
			}
		}
		for(Pair1 p :hs22) { 

			int x=p.a;
			int y=p.b;
		
			for(int i=x-1;i>=0;i--) {
				if(g[i][y]!='*' &&c[i][y]>1) {
					c[i][y]=2;
					

				}
				else
					break;
			}
			for(int i=x+1;i<n;i++) {
				if(g[i][y]!='*' &&c[i][y]>1) {
					c[i][y]=2;
					

				}
				else {
					break;
				}
			}
		}
	}
	static boolean check(int x,int y) {
		if(x>=0&&x<n&&y>=0&&y<m&&g[x][y]!='*' &&g[x][y]!='S'&&!v[x][y])
			{
				return true;
			}
		return false;
	}
	

	

	static void bfs(int x,int y,int n,int m,char g[][],int f1,int f2) {
		Queue<Pair>q=new LinkedList<>();
		q.add(new Pair(x,y,'C',0));
		v=new boolean[n][m];
		v[x][y]=true;
		while(!q.isEmpty()) {
			Pair p=q.poll();
			x=p.a;
			y=p.b;
			v[x][y]=true;
			char pre=p.pre;
			int t=p.t;
			

			if(g[x][y]=='T'&&t<=2)
			{
				

				ans=true;
				break;
			}
		
			if(pre=='C') {
				if(check(x-1,y)) { 

					q.add(new Pair(x-1,y,'L',0));
				}
				if(check(x+1,y)) { 

					q.add(new Pair(x+1,y,'R',0));
				}
				if(check(x,y-1)) { 

					q.add(new Pair(x,y-1,'U',0));
				}
				if(check(x,y+1)) { 

					q.add(new Pair(x,y+1,'D',0));
				}
			}
			else if(pre=='U') {
				if(check(x-1,y)&&t<2) { 

					q.add(new Pair(x-1,y,'L',t+1));
				}
				if(check(x+1,y)&&t<2) { 

					q.add(new Pair(x+1,y,'R',t+1));
				}
				if(check(x,y-1)) { 

					q.add(new Pair(x,y-1,'U',t));
				}
				if(check(x,y+1)&&t<2) { 

					q.add(new Pair(x,y+1,'D',t+1));
				}
			}
			else if(pre=='D') {
				if(check(x-1,y)&&t<2) { 

					q.add(new Pair(x-1,y,'L',t+1));
				}
				if(check(x+1,y)&&t<2) { 

					q.add(new Pair(x+1,y,'R',t+1));
				}
				if(check(x,y-1)&&t<2) { 

					q.add(new Pair(x,y-1,'U',t+1));
				}
				if(check(x,y+1)) { 

					q.add(new Pair(x,y+1,'D',t));
				}
			}
			else if(pre=='L') {
				if(check(x-1,y)) { 

					q.add(new Pair(x-1,y,'L',t));
				}
				if(check(x+1,y)&&t<2) { 

					q.add(new Pair(x+1,y,'R',t+1));
				}
				if(check(x,y-1)&&t<2) { 

					q.add(new Pair(x,y-1,'U',t+1));
				}
				if(check(x,y+1)&&t<2) { 

					q.add(new Pair(x,y+1,'D',t+1));
				}
			}
			else {

				if(check(x-1,y)&&t<2) { 

					q.add(new Pair(x-1,y,'L',t+1));
				}
				if(check(x+1,y)) { 

					q.add(new Pair(x+1,y,'R',t));
				}
				if(check(x,y-1)&&t<2) { 

					q.add(new Pair(x,y-1,'U',t+1));
				}
				if(check(x,y+1)&&t<2) { 

					q.add(new Pair(x,y+1,'D',t+1));
				}
			}
		}
	}
	public static void main(String[] args) throws Exception {
		InputReader in = new InputReader(System.in);
		PrintWriter pw = new PrintWriter(System.out);

		

		

		


		n=in.readInt();
		m=in.readInt();
		g=new char[n][m];
		c=new int [n][m];
		for(int i=0;i<n;i++)
			Arrays.fill(c[i], 10000);
		for(int i=0;i<n;i++)
			g[i]=in.readString().toCharArray();
		int f=1;
		int x1=0,y1=0;
		int x2=0,y2=0;
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				if(g[i][j]=='S') {
					x1=i;
					y1=j;
				}
				if(g[i][j]=='T')
				{
					x2=i;
					y2=j;
				}
			}
		}
		

		fill0(x1,y1);
		fill1();
		fill2();
		
		if(c[x2][y2]<=2)
			pw.println("YES");	     	
		else
			pw.println("NO");
		


		pw.close();
	}

	public static long gcd(long x, long y) {
		if (x % y == 0)
			return y;
		else
			return gcd(y, x % y);
	}

	public static int gcd(int x, int y) {
		if (x % y == 0)
			return y;
		else
			return gcd(y, x % y);
	}

	public static int abs(int a, int b) {
		return (int) Math.abs(a - b);
	}

	public static long abs(long a, long b) {
		return (long) Math.abs(a - b);
	}

	public static int max(int a, int b) {
		if (a > b)
			return a;
		else
			return b;
	}

	public static int min(int a, int b) {
		if (a > b)
			return b;
		else
			return a;
	}

	public static long max(long a, long b) {
		if (a > b)
			return a;
		else
			return b;
	}

	public static long min(long a, long b) {
		if (a > b)
			return b;
		else
			return a;
	}

	public static long pow(long n, long p, long m) {
		long result = 1;
		if (p == 0)
			return 1;
		if (p == 1)
			return n;
		while (p != 0) {
			if (p % 2 == 1)
				result *= n;
			if (result >= m)
				result %= m;
			p >>= 1;
			n *= n;
			if (n >= m)
				n %= m;
		}
		return result;
	}

	public static long pow(long n, long p) {
		long result = 1;
		if (p == 0)
			return 1;
		if (p == 1)
			return n;
		while (p != 0) {
			if (p % 2 == 1)
				result *= n;
			p >>= 1;
			n *= n;
		}
		return result;

	}

	static class Pair implements Comparable<Pair> {
		int a, b;
		char pre;int t;
		Pair(int a, int b,char pre,int t) {
			this.a = a;
			this.b = b;
			this.pre=pre;
			this.t=t;
		}

		public int compareTo(Pair o) {
			

			if (this.a != o.a)
				return Integer.compare(this.a, o.a);
			else
				return Integer.compare(this.b, o.b);
			

		}

		public boolean equals(Object o) {
			if (o instanceof Pair) {
				Pair p = (Pair) o;
				return p.a == a && p.b == b &&p.t==t&&p.pre==pre;
			}
			return false;
		}

		public int hashCode() {
			return new Integer(a).hashCode() * 31 + new Integer(b).hashCode()+new Integer(t).hashCode()*21+new Integer(pre).hashCode()*33;
		}

		public String toString() {
			return a + " " + b;
		}
	}

	static long sort(int a[]) {
		int n = a.length;
		int b[] = new int[n];
		return mergeSort(a, b, 0, n - 1);
	}

	static long mergeSort(int a[], int b[], long left, long right) {
		long c = 0;
		if (left < right) {
			long mid = left + (right - left) / 2;
			c = mergeSort(a, b, left, mid);
			c += mergeSort(a, b, mid + 1, right);
			c += merge(a, b, left, mid + 1, right);
		}
		return c;
	}

	static long merge(int a[], int b[], long left, long mid, long right) {
		long c = 0;
		int i = (int) left;
		int j = (int) mid;
		int k = (int) left;
		while (i <= (int) mid - 1 && j <= (int) right) {
			if (a[i] <= a[j]) {
				b[k++] = a[i++];
			} else {
				b[k++] = a[j++];
				c += mid - i;
			}
		}
		while (i <= (int) mid - 1)
			b[k++] = a[i++];
		while (j <= (int) right)
			b[k++] = a[j++];
		for (i = (int) left; i <= (int) right; i++)
			a[i] = b[i];
		return c;
	}

	public static int[] radixSort(int[] f) {
		int[] to = new int[f.length];
		{
			int[] b = new int[65537];
			for (int i = 0; i < f.length; i++)
				b[1 + (f[i] & 0xffff)]++;
			for (int i = 1; i <= 65536; i++)
				b[i] += b[i - 1];
			for (int i = 0; i < f.length; i++)
				to[b[f[i] & 0xffff]++] = f[i];
			int[] d = f;
			f = to;
			to = d;
		}
		{
			int[] b = new int[65537];
			for (int i = 0; i < f.length; i++)
				b[1 + (f[i] >>> 16)]++;
			for (int i = 1; i <= 65536; i++)
				b[i] += b[i - 1];
			for (int i = 0; i < f.length; i++)
				to[b[f[i] >>> 16]++] = f[i];
			int[] d = f;
			f = to;
			to = d;
		}
		return f;
	}

	static class InputReader {
		private InputStream stream;
		private byte[] buf = new byte[1024];
		private int curChar;
		private int numChars;
		private SpaceCharFilter filter;

		public InputReader(InputStream stream) {
			this.stream = stream;
		}

		public int read() {
			if (numChars == -1)
				throw new InputMismatchException();
			if (curChar >= numChars) {
				curChar = 0;
				try {
					numChars = stream.read(buf);
				} catch (IOException e) {
					throw new InputMismatchException();
				}
				if (numChars <= 0)
					return -1;
			}
			return buf[curChar++];
		}

		public int readInt() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = read();
			}
			int res = 0;
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = read();
			} while (!isSpaceChar(c));
			return res * sgn;
		}

		public String readString() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = read();
			} while (!isSpaceChar(c));
			return res.toString();
		}

		public String readLine() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = read();
			} while (!isEndOfLine(c));
			return res.toString();
		}

		public double readDouble() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = read();
			}
			double res = 0;
			while (!isSpaceChar(c) && c != '.') {
				if (c == 'e' || c == 'E')
					return res * Math.pow(10, readInt());
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = read();
			}
			if (c == '.') {
				c = read();
				double m = 1;
				while (!isSpaceChar(c)) {
					if (c == 'e' || c == 'E')
						return res * Math.pow(10, readInt());
					if (c < '0' || c > '9')
						throw new InputMismatchException();
					m /= 10;
					res += (c - '0') * m;
					c = read();
				}
			}
			return res * sgn;
		}

		public long readLong() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = read();
			}
			long res = 0;
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = read();
			} while (!isSpaceChar(c));
			return res * sgn;
		}

		public boolean isSpaceChar(int c) {
			if (filter != null)
				return filter.isSpaceChar(c);
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}

		public String next() {
			return readString();
		}

		public interface SpaceCharFilter {
			public boolean isSpaceChar(int ch);
		}

		public boolean isEndOfLine(int c) {
			return c == '\n' || c == '\r' || c == -1;
		}
	}

	

	

	

	

	


	

	

	

	

	

	

	

	

	

	

	
	


	


}
