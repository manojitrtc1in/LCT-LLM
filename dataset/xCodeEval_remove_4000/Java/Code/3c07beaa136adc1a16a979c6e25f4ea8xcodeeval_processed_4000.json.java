import java.awt.Point;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.lang.reflect.Array;
import java.security.KeyStore.Entry;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Stack;
import java.util.StringTokenizer;
import java.util.TreeMap;
import java.util.TreeSet;

import java.util.*;

public class test2 {
	

	static long ans = 0;
	static ArrayList<Integer> y = new ArrayList<Integer>();
	static char[] s;
	static char[] r;
	static long[][] m;
	static long[] w;
	static int[] v;
	static int n;
	static int[] h;
	static long[] m1;
	static int[][] p;
	static ArrayList<String> arr;
	


	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		PrintWriter sp = new PrintWriter(System.out);		
		int n=sc.nextInt();
		int m=sc.nextInt();
		Long[] x=sc.id3(n);
		

		Long[] dam=new Long[n-1];
		for(int i=0;i<n-1;i++) {
			if(x[i]>x[i+1])dam[i]=x[i]-x[i+1];
			else dam[i]=0l;
		}
		long[] a=new long[n];
		a[0]=0;
		for(int i=0;i<n-1;i++) {
			a[i+1]=a[i]+dam[i];
		}
		

		

		long[] rev=new long[n];
		for(int i=0,j=n-1;i<n;i++,j--)rev[i]=x[j];
		long[] dam2=new long[n-1];
		for(int i=0;i<n-1;i++) {
			if(rev[i]>rev[i+1])dam2[i]=rev[i]-rev[i+1];
			else dam2[i]=0;
		}
		long[] b=new long[n];
		b[0]=0;
		for(int i=0;i<n-1;i++) {
			b[i+1]=b[i]+dam2[i];
		}
		

		

		

		while(m-->0) {
			int s=sc.nextInt();int t=sc.nextInt();
			if(s<t) {
				int i=s;int j=t;
				sp.println(a[j-1]-a[i-1]);
			}
			else {
				int i=(n-s+1);
				int j=(n-t+1);
				
				sp.println(b[j-1]-b[i-1]);
			}
		}
		
		sp.flush();

	}
	public static long vac(int i,int prev) {
		if(i==n)return 0;
		long a=0;
		long b=0;
		long c=0;
		if(m[prev][i]!=-1)return m[prev][i];
		if(prev==0) {
			a=vac(i+1,1)+p[i][0];
			b=vac(i+1,2)+p[i][1];
			c=vac(i+1,3)+p[i][2];
		}
		else if(prev==1) {
			b=vac(i+1,2)+p[i][1];
			c=vac(i+1,3)+p[i][2];
		}
		else if(prev==2) {
			a=vac(i+1,1)+p[i][0];
			c=vac(i+1,3)+p[i][2];
		}
		else {
			a=vac(i+1,1)+p[i][0];
			b=vac(i+1,2)+p[i][1];
		}
		long z=Math.max(a, Math.max(c, b));
		return m[prev][i]= z;
	}
	public static long jump(int i,int k) {
		if(i>=n)return (long)1e12;
		if(i==n-1)return 0;
		if(m1[i]!=-1)return m1[i];
		long z=(long)1e12;
		for(int j=1;j<=k;j++) {
			if(i<n-j) {
				z=Math.min(z, jump(i+j, k)+Math.abs(h[i]-h[i+j]));
			}
		}
		return m1[i]=z;
		
		
	}
	public static void trace(int i,int j) {
		if(i==s.length&&j==r.length)return ;
		

		if(i<s.length&&j<r.length&&s[i]==r[j]) {
			 trace(i+1, j+1);
			

			 return;
		}
		long rep=Integer.MAX_VALUE;long del=Integer.MAX_VALUE;long ins=Integer.MAX_VALUE;
		if(i<s.length&&j<r.length) {
			rep=1+change(i+1, j+1);
		}
		if(j<r.length) {
			ins=1+change(i, j+1);
		}
		if(i<s.length){
			del=1+change(i+1, j);
		}
		long z=m[i][j];
		if(z==rep) {
			arr.add("REPLACE "+(j+1)+" "+r[j]);
			trace(i+1, j+1);
		}
		else if(z==del) {
			arr.add("DELETE "+(j+1));
			trace(i+1, j);
		}
		else {
			arr.add("INSERT "+(j+1)+" "+r[j]);
			trace(i, j+1);
		}
		return;
		
	}
	public static long change(int i,int j) {
		if(i==s.length&&j==r.length)return 0;
		if(m[i][j]!=-1)return m[i][j];
		if(i<s.length&&j<r.length&&s[i]==r[j]) {
			return change(i+1, j+1);
		}
		long rep=Integer.MAX_VALUE;long del=Integer.MAX_VALUE;long ins=Integer.MAX_VALUE;
		if(i<s.length&&j<r.length) {
			rep=1+change(i+1, j+1);
		}
		if(j<r.length) {
			ins=1+change(i, j+1);
		}
		if(i<s.length){
			del=1+change(i+1, j);
		}
		long z=Math.min(del, Math.min(ins, rep));
		return m[i][j]= z;
	}
	public static long ks2(int i,int val) {
		if(i==v.length) {
			if(val==0)return 0;
			else return (long)1e12;
		}
		if(m[i][val]!=-1)return m[i][val];
		long take=(long)1e12;
		long leave=ks2(i+1,val);
		if(val>=v[i])take=w[i]+ks2(i+1,val-v[i]);
		long z=Math.min(take, leave);
		return m[i][val]= z;
	}
	public static long fibit(int n,long[] m,int i) {
		if(i==n&&i!=0&&i!=-1) {
			return m[n-1]+m[n-2];
		}
		else if(i==n&&i==0)return 0;
		else if(i==n&&i==1)return 1;
		else {
			if(i==0)m[0]=0;
			else if(i==1)m[1]=1;
			else {
				

				m[i]=m[i-1]+m[i-2];
			}
			return fibit(n,m,i+1);
		}
	}
	public static long fibdp(int n,long[] m) {
		ans++;
		if(n==0)return 0;
		if(n==1)return 1;
		if(m[n]!=-1)return m[n];
		return m[n]=fibdp(n-1,m)+fibdp(n-2,m);
	}
	
	public static long chang(ArrayList<Character> c,ArrayList<Character> r,int i,Stack<String> x) {
		ans++;
		if(i>=c.size()&&i>=r.size()) {
			boolean isequal=true;
			if(c.size()!=r.size())isequal=false;
			else {
				for(int j=0;j<c.size();j++) {
					if(c.get(j)!=r.get(j)) {
						isequal=false;
						break;
					}
				}
			}
			if(isequal)
				return 0;
			else
				return Integer.MAX_VALUE;
		}
		long ins=0;long del=0;long rep=0;
		long none=0;
		if(i>=r.size()&&i<c.size()) {
			c.remove(i);
			String fun="DELETE "+i+1;
			x.add(fun);
			 del=1+chang(c,r,i,x);
			return del;
		}
		else if(i>=c.size()&&i<r.size()) {
			c.add(i, r.get(i));
			String fun="INSERT "+i+1+" "+r.get(i);
			x.add(fun);
			ins=1+chang(c, r, i+1, x);
			return ins;
		}
		else {
			if(c.get(i)==r.get(i)) {
				none=chang(c, r, i+1, x);
				return none;
			}
			else {
				ArrayList<Character> temp=(ArrayList<Character>) c.clone();
				temp.add(i, r.get(i));
				ins=1+chang(temp, r, i+1, x);
				temp=(ArrayList<Character>) c.clone();
				temp.remove(i);
				del=1+chang(temp, r, i, x);
				temp=(ArrayList<Character>) c.clone();
				temp.set(i, r.get(i));
				rep=1+chang(temp, r, i+1, x);
				return Math.min(rep, Math.min(del, ins));
			}
		}
	}
	

	public static long tet(char in, int c, int n, long[][] m) {
		if (c == n) {
			if (in == 'D')
				return 1;
			else
				return 0;
		}
		long z = 0;
		if (in == 'D') {
			if (m[0][c] != -1)
				return m[0][c];
			else {
				z = (tet('B', c + 1, n, m) % (long) (1e9 + 7)) + (tet('A', c + 1, n, m) % (long) (1e9 + 7))
						+ (tet('C', c + 1, n, m) % (long) (1e9 + 7));
				m[0][c] = z;
			}
		} else if (in == 'A') {
			if (m[1][c] != -1)
				return m[1][c];
			z = (tet('B', c + 1, n, m) % (long) (1e9 + 7)) + (tet('D', c + 1, n, m) % (long) (1e9 + 7))
					+ (tet('C', c + 1, n, m) % (long) (1e9 + 7));
			m[1][c] = z;
		} else if (in == 'B') {
			if (m[2][c] != -1)
				return m[2][c];
			z = (tet('D', c + 1, n, m) % (long) (1e9 + 7)) + (tet('A', c + 1, n, m) % (long) (1e9 + 7))
					+ (tet('C', c + 1, n, m) % (long) (1e9 + 7));
			m[2][c] = z;
		} else {
			if (m[3][c] != -1)
				return m[3][c];
			z = (tet('B', c + 1, n, m) % (long) (1e9 + 7)) + (tet('A', c + 1, n, m) % (long) (1e9 + 7))
					+ (tet('D', c + 1, n, m) % (long) (1e9 + 7));
			m[3][c] = z;
		}
		return z;
	}

	public static long wow(int i, int r) {
		if (r == 3)
			return 1;
		if (i >= s.length)
			return 0;
		if (m[i][r] != -1)
			return m[i][r];
		else {
			long take = 0;
			long leave = wow(i + 1, r);
			if (r == 0) {
				if (s[i] == 'w') {
					take = wow(i + 1, r + 1);
					

					

					

				} 

					

					

					

			} else if (r == 1) {
				if (s[i] == 'o') {
					take = wow(i + 1, r + 1);
					

					

					

				} 

					

					

					

			} else {
				if (s[i] == 'w') {
					take = wow(i + 1, r + 1);
					

					

					

				} 

					

					

					

			}
			long z = take + leave;
			return m[i][r] = z;

		}

	}

	public static long[] max(long[] x, long[] y, boolean f) {
		if (!f) {
			if (x[0] >= y[0])
				return x;
			else
				return y;
		} else {
			if (y[1] >= x[1])
				return y;
			else
				return x;
		}
	}

	
	
	public static void fill(ArrayList<Integer>[] x, int st, boolean[] f) {
		if (f[st])
			return;
		else {
			f[st] = true;
			y.add(st);
			for (int i = 0; i < x[st].size(); i++) {
				fill(x, x[st].get(i), f);
			}
		}
	}

	public static void count(ArrayList<Integer>[] x, int i, int m, int cat, boolean[] f, boolean[] r, int st) {
		

		if (r[i])
			return;
		else
			r[i] = true;
		if (cat > m)
			return;
		if (x[i].size() == 1 && i != st) {
			if (f[i - 1]) {
				if (cat + 1 <= m) {
					

					ans++;
					return;
				} else
					return;
			} else {
				if (cat <= m) {
					ans++;
					return;
				}
				return;
			}
		} else {
			if (f[i - 1]) {
				for (int j = 0; j < x[i].size(); j++) {
					int n = x[i].get(j);
					count(x, n, m, cat + 1, f, r, st);
				}
			} else {
				for (int j = 0; j < x[i].size(); j++) {
					int n = x[i].get(j);
					count(x, n, m, 0, f, r, st);
				}
			}
		}

	}

	public static int[] blwh(ArrayList<Integer>[] x, int i, char[] q) {
		int[] y = new int[2];
		if (x[i].size() == 0) {
			

			if (q[i] == 'B')
				y[0]++;
			else
				y[1]++;
			return y;
		} else {
			if (q[i] == 'B')
				y[0]++;
			else
				y[1]++;
			for (int j = 0; j < x[i].size(); j++) {
				

				int[] t = blwh(x, x[i].get(j), q);
				y[0] += t[0];
				y[1] += t[1];
			}
			if (y[0] == y[1])
				ans++;
			return y;
		}

	}

	

	static class Scanner {
		StringTokenizer st;
		BufferedReader br;

		public Scanner(InputStream s) {
			br = new BufferedReader(new InputStreamReader(s));
		}

		public Scanner(FileReader r) {
			br = new BufferedReader(r);
		}

		public String next() throws IOException {
			while (st == null || !st.hasMoreTokens())
				st = new StringTokenizer(br.readLine());
			return st.nextToken();
		}

		public int nextInt() throws IOException {
			return Integer.parseInt(next());
		}

		public long nextLong() throws IOException {
			return Long.parseLong(next());
		}

		public String nextLine() throws IOException {
			return br.readLine();
		}

		public double nextDouble() throws IOException {
			String x = next();
			StringBuilder sb = new StringBuilder("0");
			double res = 0, f = 1;
			boolean dec = false, neg = false;
			int start = 0;
			if (x.charAt(0) == '-') {
				neg = true;
				start++;
			}
			for (int i = start; i < x.length(); i++)
				if (x.charAt(i) == '.') {
					res = Long.parseLong(sb.toString());
					sb = new StringBuilder("0");
					dec = true;
				} else {
					sb.append(x.charAt(i));
					if (dec)
						f *= 10;
				}
			res += Long.parseLong(sb.toString()) / f;
			return res * (neg ? -1 : 1);
		}

		public long[] id0(int n) throws IOException {
			long[] a = new long[n];
			for (int i = 0; i < n; i++)
				a[i] = nextLong();
			return a;
		}

		public Long[] id3(int n) throws IOException {
			Long[] a = new Long[n];
			for (int i = 0; i < n; i++)
				a[i] = nextLong();
			return a;
		}

		public int[] id1(int n) throws IOException {
			int[] a = new int[n];
			for (int i = 0; i < n; i++)
				a[i] = nextInt();
			return a;
		}

		public Integer[] id2(int n) throws IOException {
			Integer[] a = new Integer[n];
			for (int i = 0; i < n; i++)
				a[i] = nextInt();
			return a;
		}

		public boolean ready() throws IOException {
			return br.ready();
		}

	}

}






