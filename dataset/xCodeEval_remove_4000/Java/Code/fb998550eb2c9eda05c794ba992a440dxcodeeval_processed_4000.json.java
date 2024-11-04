import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.InputMismatchException;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Random;
import java.util.Scanner;
import java.util.Stack;
import java.util.StringTokenizer;
import java.util.TreeMap;
import java.util.TreeSet;

public class main {
	private static InputStream stream;
	private static byte[] buf = new byte[1024];
	private static int curChar;
	private static int numChars;
	private static id5 filter;
	private static PrintWriter pw;
	private static long mod = 1000000000 + 7;
	private static long mod1 = 1000000000 + 9;
	private static int MAX=1000001;
	private static int block;
	private static int[][] pa;
	private static int[][] st;
	private static int[] height;
	private static int log;
	private static void soln(){
		int n=nextInt();
		int m=nextInt();
		Edge[] edges=new Edge[m];
		for(int i=0;i<m;i++)
			edges[i]=new Edge(nextInt()-1,nextInt()-1,nextInt(),i);
		Arrays.sort(edges);
		DSU dsu=new DSU(n);
		long weight=0;
		HashSet<Integer> mst=new HashSet<>();
		LinkedList<Integer>[] tree=new LinkedList[n];
		for(int i=0;i<n;i++)
			tree[i]=new LinkedList<>();
		for(int i=0;i<m;i++){
			Edge edge=edges[i];
			if(dsu.find(edge.u)!=dsu.find(edge.v)){
				weight+=(long)edge.len;
				dsu.Union(edge.u, edge.v);
				mst.add(i);
				tree[edge.u].add(0,i);
				tree[edge.v].add(0,i);
			}
		}
		height=new int[n];
		log=(int) Math.ceil(Math.log10(n)/Math.log10(2));
		st=new int[n][log];
		pa=new int[n][log];
		for(int i=0;i<n;i++)
			Arrays.fill(st[i], -1);
		DFS(tree,edges,0,-1,-1);
		long[] ans=new long[m];
		for(int i=0;i<m;i++){
			if(mst.contains(i)){
				ans[edges[i].ind]=weight;
			}else{
				Edge edge=edges[i];
				int tmp=answer(edge.u,edge.v);
				ans[edge.ind]=weight-tmp+(long)edge.len;
				

			}
			

		}
		for(int i=0;i<m;i++)
			pw.println(ans[i]);
	}
	private static void DFS(LinkedList<Integer>[] tree,Edge[] edges,int cur,int prev,int len){
		Iterator<Integer> it=tree[cur].listIterator();
		if(prev!=-1){
			height[cur]=height[prev]+1;
			st[cur][0]=len;
			pa[cur][0]=prev;
		}
		for(int i=1;i<log;i++){
			if(st[cur][i-1]!=-1)
				st[cur][i]=Math.max(st[pa[cur][i-1]][i-1],st[cur][i-1]);
			if(pa[cur][i-1]!=-1)
				pa[cur][i]=pa[pa[cur][i-1]][i-1];
		}
		while(it.hasNext()){
			int x=it.next();
			if(edges[x].u==cur && edges[x].v!=prev)
				DFS(tree,edges,edges[x].v,cur,edges[x].len);
			else if(edges[x].v==cur && edges[x].u!=prev)
				DFS(tree,edges,edges[x].u,cur,edges[x].len);
		}
	}
	private static int answer(int u,int v){
		

		if(height[u]>height[v]){
			int tmp=u;
			u=v;
			v=tmp;
		}
		int ans=-1;
		for(int i=log-1;i>=0;i--){
			if(pa[v][i]!=-1 && height[pa[v][i]]>=height[u]){
				ans=Math.max(ans,st[v][i]);
				v=pa[v][i];
			}
		}
		if(v==u)
			return ans;
		for(int i=log-1;i>=0;i--){
			

			if(pa[v][i]!=pa[u][i]){
				ans=Math.max(ans,Math.max(st[v][i],st[u][i]));
				v=pa[v][i];
				u=pa[u][i];
			}
		}
		return Math.max(ans,Math.max(st[u][0],st[v][0]));
	}
	private static class Edge implements Comparable<Edge>{
		int u,v,len,ind;
		public Edge(int a,int b,int l,int i){
			u=a;
			v=b;
			len=l;
			ind=i;
		}
		public int compareTo(Edge e){
			return this.len-e.len;
		}
	}
	private static class DSU{
		int[] parent;
		int[] rank;
		public DSU(int n){
			parent=new int[n];
			rank=new int[n];
			for(int i=0;i<n;i++){
				parent[i]=i;
				rank[i]=1;
			}
		}
		int find(int i){
	        while(parent[i] !=i){
	        	parent[i]=parent[parent[i]];
	        	i=parent[i];
	        }
	        return i;
	    }
		int Union(int x, int y){
	        int xset = find(x);
	        int yset = find(y);
	        if(rank[xset]<rank[yset]){
	        	parent[xset] = yset;
		        rank[yset]+=rank[xset];
		        rank[xset]=0;
		        return yset;
	        }else{
	        	parent[yset]=xset;
	        	rank[xset]+=rank[yset];
	        	rank[yset]=0;
	        	return xset;
	        }
	    }
	}
	static class Hashing {
	  	  static final int multiplier = 43;
	  	  static final Random rnd = new Random();
	  	  static final int mod1 = BigInteger.valueOf((int) (1e9 + rnd.nextInt((int) 1e9))).nextProbablePrime().intValue();
	  	  static final int mod2 = BigInteger.valueOf((int) (1e9 + rnd.nextInt((int) 1e9))).nextProbablePrime().intValue();
	  	  static final int id4 = BigInteger.valueOf(multiplier).modInverse(BigInteger.valueOf(mod1)).intValue();
	  	  static final int id2 = BigInteger.valueOf(multiplier).modInverse(BigInteger.valueOf(mod2)).intValue();
	  	  long[] hash1, hash2;
	  	  long[] inv1, inv2;
	  	  int n;
	  	  public Hashing(String s){
	  	    n = s.length();
	  	    hash1 = new long[n + 1];
	  	    hash2 = new long[n + 1];
	  	    inv1 = new long[n + 1];
	  	    inv2 = new long[n + 1];
	  	    inv1[0] = 1;
	  	    inv2[0] = 1;
	  	    long p1 = 1;
	  	    long p2 = 1;
	  	    for (int i = 0; i < n; i++) {
	  	      hash1[i + 1] = (hash1[i] + s.charAt(i) * p1) % mod1;
	  	      p1 = p1 * multiplier % mod1;
	  	      inv1[i + 1] = inv1[i] * id4 % mod1;
	  	      hash2[i + 1] = (hash2[i] + s.charAt(i) * p2) % mod2;
	  	      p2 = p2 * multiplier % mod2;
	  	      inv2[i + 1] = inv2[i] * id2 % mod2;
	  	    }
	  	  }
	  	  public long getHash(int i, int len) {
	  	    return (((hash1[i + len] - hash1[i] + mod1) * inv1[i] % mod1) << 32)
	  	        + (hash2[i + len] - hash2[i] + mod2) * inv2[i] % mod2;
	  	  }
	}
	public static class Segment {
		private int[] tree;
		private int[] base;
		private int size;
		private int n;
		private class node{
			private int a;
			private int b;
			private int c;
			public node(int x,int y,int z){
				a=x;
				b=y;
				c=z;
			}
		}
		public Segment(int n,int[] arr){
			this.base=arr;
			int x = (int) (Math.ceil(Math.log(n) / Math.log(2)));
	        size = 2 * (int) Math.pow(2, x) - 1;
			tree=new int[size];
			this.n=n;
			build(0,0,n-1);
		}
		private void build(int id,int l,int r){
			

			if(r==l){
				tree[id]=base[l];
				return;
			}
			int mid=l+(r-l)/2;
			

			build(2*id+1,l,mid);
			

			build(2*id+2,mid+1,r);
			tree[id]=tree[2*id+1]^tree[2*id+2];
		}
		public int query(int l,int r){
			return queryUtil(l,r,0,0,n-1);
		}
		private int queryUtil(int x,int y,int id,int l,int r){
			if(l>y || x>r) 
				return 0;
			if(x <= l && r<=y)
				return tree[id];
			int mid=l+(r-l)/2;
			return queryUtil(x,y,2*id+1,l,mid)^queryUtil(x,y,2*id+2,mid+1,r);
		}
		
		public void update(int x,int colour,int id,int l,int r){
			if(x>r || x<l)
				return;
			if(l==r){
				tree[id]^=colour;
				return;
			}
			int mid=l+(r-l)/2;
			

			update(x,colour,2*id+1,l,mid);
			update(x,colour,2*id+2,mid+1,r);
			tree[id]=tree[2*id+1]^tree[2*id+2];
		}
		private void shift(int id){
			if(tree[id]!=0){
				tree[2*id+1]=tree[2*id+2]=tree[id];
			}
			tree[id]=0;
		}
	}

	static void multiply(long[][] a, long[][] b,long m){
		int n=a.length;
	    long[][] mul=new long[n][n];
	    for (int i = 0; i < n; i++){
	        for (int j = 0; j < n; j++){
	            mul[i][j] = 0;
	            for (int k = 0; k < n; k++)
	                mul[i][j] = (mul[i][j]+(a[i][k]*b[k][j])%m)%m;
	        }
	    }
	    for (int i=0; i<n; i++)
	        for (int j=0; j<n; j++)
	            a[i][j] =mul[i][j];
	}
	static class Pair implements Comparable<Pair>{
		int p;
		int c;
		int b;
		public Pair(int t,int x,int y){
			p=t;
			c=x;
			b=y;
		}
		@Override
		public int compareTo(Pair arg0) {
			return this.p-arg0.p;
		}
		
	}
	private static long pow(long a, long b, long c) {
		if (b == 0)
			return 1;
		long p = pow(a, b / 2, c);
		p = (p * p) % c;
		return (b % 2 == 0) ? p : (a * p) % c;
	}
	
	private static class Mo implements Comparable<Mo>{
		int l;
		int r;
		int i;
		public Mo(int a,int b,int ind) {
			l=a;r=b;i=ind;
		}
		@Override
		public int compareTo(Mo arg0) {
			int b1=this.l/block;
			int b2=arg0.l/block;
			return (b1!=b2)?(b1-b2):(this.r-arg0.r);
		}
	}

	private static long gcd(long n, long l) {
		if (l == 0)
			return n;
		return gcd(l, n % l);
	}

	private static long max(long a, long b) {
		if (a > b)
			return a;
		return b;
	}

	private static long min(long a, long b) {
		if (a < b)
			return a;
		return b;
	}

	public static void main(String[] args) throws Exception {
		new Thread(null,new Runnable(){
			@Override
			public void run() {
				
				InputReader(System.in);
				pw = new PrintWriter(System.out);
				
				soln();
				pw.close();
			}
		},"1",1<<26).start();
	}

	public static void InputReader(InputStream stream1) {
		stream = stream1;
	}

	private static boolean isWhitespace(int c) {
		return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
	}

	private static boolean id3(int c) {
		return c == '\n' || c == '\r' || c == -1;
	}

	private static int read() {
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

	private static int nextInt() {
		int c = read();
		while (id0(c))
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
		} while (!id0(c));
		return res * sgn;
	}

	private static long nextLong() {
		int c = read();
		while (id0(c))
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
		} while (!id0(c));
		return res * sgn;
	}

	private static String nextToken() {
		int c = read();
		while (id0(c))
			c = read();
		StringBuilder res = new StringBuilder();
		do {
			res.appendCodePoint(c);
			c = read();
		} while (!id0(c));
		return res.toString();
	}

	private static String nextLine() {
		int c = read();
		while (id0(c))
			c = read();
		StringBuilder res = new StringBuilder();
		do {
			res.appendCodePoint(c);
			c = read();
		} while (!id3(c));
		return res.toString();
	}

	private static int[] id1(int n) {
		int[] arr = new int[n];
		for (int i = 0; i < n; i++) {
			arr[i] = nextInt();
		}
		return arr;
	}

	private static long[] id6(int n) {
		long[] arr = new long[n];
		for (int i = 0; i < n; i++) {
			arr[i] = nextLong();
		}
		return arr;
	}

	private static void pArray(int[] arr) {
		for (int i = 0; i < arr.length; i++) {
			System.out.print(arr[i] + " ");
		}
		System.out.println();
		return;
	}

	private static void pArray(long[] arr) {
		for (int i = 0; i < arr.length; i++) {
			System.out.print(arr[i] + " ");
		}
		System.out.println();
		return;
	}

	private static boolean id0(int c) {
		if (filter != null)
			return filter.id0(c);
		return isWhitespace(c);
	}
	private static char nextChar() {
		int c = read();
		while (id0(c))
			c = read();
		char c1=(char)c;
		while(!id0(c))
			c=read();
		return c1;
	}
	private interface id5 {
		public boolean id0(int ch);
	}
}