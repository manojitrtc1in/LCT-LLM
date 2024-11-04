import java.awt.Point;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.lang.reflect.Array;
import java.math.BigInteger;
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
	static Boolean[] m2;
	static long[][] p;
	static ArrayList<String> arr;
	static ArrayList<Integer>[] x;
	static HashMap<String, Integer> l;
	static long[][][][] m3;
	static char[][] g;
	static int H;
	static int W;
	static double[] head;
	static double[][] m4;
	static int[][] gold;
	static int ans2;
	static String k;
	static String L;
	static String R;
	static int d;
	static String a;
	static String b;
	static long[][][] m5;
	static long[][][] m6;
	static int[][] obj;
 
	static int[][] com;
	static int[][] mat;
	static int[][] loc;
	static int[][] diff;
	static Integer[] can;
	static int K;
	static int Mod=(int)1e9+7;
 
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		PrintWriter sp = new PrintWriter(System.out);
		int t=sc.nextInt();
		while(t-->0) {
			int n=sc.nextInt();
			char[] c=sc.next().toCharArray();
			boolean r=false;
			int max=0;
			for(int i=0;i<c.length;i++) {
				if(c[i]=='9') {
					max=1;
					r=true;
					break;
				}
				max=Math.max(max, c[i]-'0');
			}
			if(!r) {
				if(max==c[0]-'0')max=max+1;
				StringBuilder s=new StringBuilder();
				for(int i=0;i<c.length;i++) {
					s.append(max-(c[i]-'0'));
				}
				sp.println(s.toString());
			}
			else{
				if(c[0]!='9'&&c[0]!='8') {
					int targ=(c[0]-'0')+2;
					int ca=0;
					StringBuilder s=new StringBuilder();
					for(int i=c.length-1;i>=0;i--) {
						int m=c[i]-'0';
						if(targ>=(m+ca)) {
							if((targ-m-ca)/10==0){
								s.append(targ-m-ca);
								if(targ/10!=0)ca=1;
							}
							else {
								targ=targ%10;
								s.append(targ-m-ca);
								ca=0;
							}
						}
						else {
							targ=targ+10;
							s.append(targ-m);
							ca=1;
						}
					}
					sp.println(s.reverse().toString());
				}
				else {
					int targ=11;
					int ca=0;
					StringBuilder s=new StringBuilder();
					for(int i=c.length-1;i>=0;i--) {
						int m=c[i]-'0';
						if(targ>=(m+ca)) {
							if((targ-m-ca)/10==0){
								s.append(targ-m-ca);
								if(targ/10!=0)ca=1;
							}
							else {
								targ=targ%10;
								s.append(targ-m-ca);
								ca=0;
							}
						}
						else {
							targ=targ+10;
							s.append(targ-m);
							ca=1;
						}
					}
					sp.println(s.reverse().toString());
				}
			}
		}
		sp.flush();
		
		
 
	}
	public static long mag1(int i,int f,int mod) {
		if(i==a.length()) {
			if(mod==0)return 1;
			return 0;
		}
		if(m5[f][mod][i]!=-1)return m5[f][mod][i];
		int lim=(f==0)?a.charAt(i)-'0':9;
		long res=0;
		if((i+1)%2==0&&d<=lim) {
			int fl=f;
			if(f==0&&d<lim)fl=1;
			res+=(mag1(i+1,fl,(mod*10+d)%n));
			res%=Mod;
		}
		else if((i+1)%2!=0){
			for(int j=0;j<=lim;j++) {
				if(j!=d) {
					int fl=f;
					if(f==0&&j<lim)fl=1;
					res+=(mag1(i+1,fl,(mod*10+j)%n));
					res%=Mod;
				}
			}
		}
		return m5[f][mod][i]=(res+Mod)%Mod;
	}
	public static long cand(int i,int c) {
		if(i==n) {
			if(c==0)return 1;
			return 0;
		}
		if(m[i][c]!=-1)return m[i][c];
		long res=0;
		for(int j=0;j<=can[i];j++) {
			if(c>=j)res+=(cand(i+1,c-j)%(int)(1e9+7));
		}
		return m[i][c]= res%(int)(1e9+7);
	}
	
	public static String trace(int mask) {
		if(Integer.bitCount(mask)==0)return "";
		long res=(long)1e12;
		for(int i=0;i<n;i++) {
			if((mask&(1<<i))!=0) {
				

				if(m1[mask]==2*diff[0][i+1]+ord(mask&~(1<<i))) {
					return "0 "+(i+1)+" "+trace(mask&~(1<<i));
				}
				for(int j=0;j<n;j++) {
					if(i!=j&&(mask&(1<<j))!=0) {
						long add=diff[0][i+1]+diff[i+1][j+1]+diff[0][j+1];
						

						if(m1[mask]==add+ord((mask&~(1<<i))&~(1<<j))) {
							return "0 "+(i+1)+" "+(j+1)+" "+trace((mask&~(1<<i))&~(1<<j));
						}
					}
				}
			}
			
		}
		return "";
	}
	public static long ord(int mask) {
		if(Integer.bitCount(mask)==0)return 0;
		if(m1[mask]!=-1)return m1[mask];
		long res=(long)1e12;
		for(int i=0;i<n;i++) {
			if((mask&(1<<i))!=0) {
				res=Math.min(res, 2*diff[0][i+1]+ord(mask&~(1<<i)));
				for(int j=0;j<n;j++) {
					if(i!=j&&(mask&(1<<j))!=0) {
						long add=diff[0][i+1]+diff[i+1][j+1]+diff[0][j+1];
						res=Math.min(res, add+ord((mask&~(1<<i))&~(1<<j)));
					}
				}
				break;
			}
			
		}
		return m1[mask]= res;
	}
	
 
 
	
 
	public static long matr(int l, int r) {
		if (l == r)
			return 0;
		

		if (m[l][r] != -1)
			return m[l][r];
		long res = Integer.MAX_VALUE;
		for (int i = l; i < r; i++) {
			res = Math.min(res, matr(l, i) + matr(i + 1, r) + mat[l][0] * mat[r][1] * mat[i][1]);
		}
		return m[l][r] = res;
	}
 
	public static long mat(int mask, int i) {
		if (i == n) {
			if (Integer.bitCount(mask) == 0)
				return 1;
			return 0;
		}
		if (m[i][mask] != -1)
			return m[i][mask];
		long res = 0;
		for (int j = 0; j < n; j++) {
			if ((mask & (1 << j)) != 0 && com[i][j] == 1) {
				res += (mat(mask & ~(1 << j), i + 1) % (int) (1e9 + 7));
			}
		}
		return m[i][mask] = res % (int) (1e9 + 7);
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
 
		public long[] nextlongArray(int n) throws IOException {
			long[] a = new long[n];
			for (int i = 0; i < n; i++)
				a[i] = nextLong();
			return a;
		}
 
		public Long[] nextLongArray(int n) throws IOException {
			Long[] a = new Long[n];
			for (int i = 0; i < n; i++)
				a[i] = nextLong();
			return a;
		}
 
		public int[] nextIntArray(int n) throws IOException {
			int[] a = new int[n];
			for (int i = 0; i < n; i++)
				a[i] = nextInt();
			return a;
		}
 
		public Integer[] nextIntegerArray(int n) throws IOException {
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
 
class Pair implements Comparable<Pair> {
	long x;
	long y;
 
	public Pair(long x, long y) {
		this.x = x;
		this.y = y;
	}
 
	

	public int compareTo(Pair o) {
		if(this.x>=o.x) {
			if(this.x>o.x)return 1;
			if(this.y>=o.y)return 1;
			return -1;
		}
		return -1;
	}
 
	public boolean contains(Pair q) {
		if (q.x == x || q.x == y || q.y == x || q.y == y)
			return true;
		return false;
	}
 
	public long getx() {
		return x;
	}
 
	public long gety() {
		return y;
	}
 
	public String toString() {
		return x + " " + y;
	}
}
 

