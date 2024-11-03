import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.NoSuchElementException;
import java.util.Objects;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Random;
import java.util.Scanner;
import java.util.TreeMap;
import java.util.TreeSet;
import java.util.function.BiFunction;

public class Main{
	static Scanner scn = new Scanner(System.in);
	static FastScanner sc = new FastScanner();
	static Mathplus mp = new Mathplus();
	static PrintWriter ot = new PrintWriter(System.out);
	static Random rand = new Random();
	static int mod = 1000000007;
	static long inf = (long)1e17;
	static int[] dx = {0,1,0,-1};
	static int[] dy = {1,0,-1,0};
	static int max;
	public static void main(String[] args) {	
		
		int N = sc.nextInt();
		ArrayList<Integer>[] l = new ArrayList[N];
		HashMap<Long,Integer> map = new HashMap<Long,Integer>();
		long sum = 0;
		long[] s = new long[N];
		for(int i=0;i<N;i++) {
			l[i] = new ArrayList<Integer>();
			int n = sc.nextInt();
			for(int j=0;j<n;j++) {
				int a = sc.nextInt();
				map.put((long)a, i);
				s[i] += a;
				sum += a;
				l[i].add(a);
			}
		}
		if(Math.abs(sum)%N!=0) {
			System.out.println("NO");
			return;
		}
		long make = sum/N;
		boolean[] dp = new boolean[(1<<N)];
		int[] first = new int[(1<<N)];
		int[] bef = new int[(1<<N)];

		Arrays.fill(first,mod);
		for(int i=0;i<N;i++) {
			for(int a:l[i]) {
				int used = 0;
				boolean f = true;
				long now = a;
				int see = i;
				while(true) {
					long next = make-(s[see]-now);
					
					if(next==a) {
						break;
					}
					if(!map.containsKey(next)) {
						f = false;
						break;
					}else {
						int k = map.get(next);
						if(mp.contains(used,k)&&k!=i) {
							f = false;
							break;
						}else {
							used = mp.bitadd(used,k);
							now = next;
							see = k;
						}
					}
				}
				if(f) {
					dp[mp.bitadd(used,i)] = true;
					first[mp.bitadd(used,i)] = a;
				}
			}
		}
		
		dp[0] = true;
		for(int i=1;i<(1<<N);i++) {
			for(int j=i;j>0;j=(j-1)&i) {
				if(dp[i^j]&&dp[j]) {
					dp[i]=true;
					bef[i] = j;
				}
			}
		}
		
		if(!dp[(1<<N)-1]) {
			System.out.println("NO");
		}else {
			System.out.println("YES");
			ArrayDeque<Integer> q = new ArrayDeque<Integer>();
			int[] ans1 = new int[N];
			int[] ans2 = new int[N];
			q.add((1<<N)-1);
			while(!q.isEmpty()) {
				int Q = q.poll();
				if(first[Q]==mod) {
					q.add(bef[Q]);
					q.add(Q^bef[Q]);
				}else {
					
					int a = first[Q];
					long now = a;
					int befo = map.get((long)a);
					while(true) {
						long next = make-(s[befo]-now);
						if(next==a) {
							int k = map.get(next);
							ans1[k] = (int)next;
							ans2[k] = befo;
							break;
						}
						int k = map.get(next);
						ans1[k] = (int)next;
						ans2[k] = befo;
						now = next;
						befo = k;
					}
				}
			}
			for(int i=0;i<N;i++) {
				System.out.println(ans1[i]+" "+(ans2[i]+1));
			}
			
		}
		
		
		
		
	
	
	}
	
}
class GridGraph extends Graph{
	
	int N;
	int M;
	String[] S;
	HashMap<Character,Integer> map;
	GridGraph(int n,int m,String[] s,char[] c){
		super(n*m);
		N = n;
		M = m;
		S = s;
		map = new HashMap<Character,Integer>();
		for(int i=0;i<n-1;i++) {
			for(int j=0;j<m;j++) {
				if(S[i].charAt(j)!='#'&&S[i+1].charAt(j)!='#') {
					addEdge(toint(i,j),toint(i+1,j));
					addEdge(toint(i+1,j),toint(i,j));
				}
			}
		}
		for(int i=0;i<n;i++) {
			for(int j=0;j<m-1;j++) {
				if(S[i].charAt(j)!='#'&&S[i].charAt(j+1)!='#') {
					addEdge(toint(i,j),toint(i,j+1));
					addEdge(toint(i,j+1),toint(i,j));
					
				}
			}
		}
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				for(int k=0;k<c.length;k++) {
					if(S[i].charAt(j)==c[k])map.put(c[k],toint(i,j));
				}
			}
		}
	}
	
	int toint(int i,int j) {
		return i*M+j;
	}
	
}

class BetterGridGraph{
	int N;
	int M;
	char[][] S;
	HashMap<Character,Integer> map;
	int[] dx = {0,1,0,-1};
	int[] dy = {1,0,-1,0};
	char w;
	char b = '#';
	BetterGridGraph(int n,int m,String[] s,char[] c){
		
		N = n;
		M = m;
		for(int i=0;i<s.length;i++) {
			S[i] = s[i].toCharArray();
		}
		map = new HashMap<Character,Integer>();
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				for(int k=0;k<c.length;k++) {
					if(S[i][j]==c[k])map.put(c[k],toint(i,j));
				}
			}
		}
	}
	BetterGridGraph(int n,int m,char[][] s,char[] c){
		
		N = n;
		M = m;
		S = s;
		map = new HashMap<Character,Integer>();
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				for(int k=0;k<c.length;k++) {
					if(S[i][j]==c[k])map.put(c[k],toint(i,j));
				}
			}
		}
	}
	
	BetterGridGraph(int n,int m,String[] s,char[] c,char W,char B){
		
		N = n;
		M = m;
		for(int i=0;i<s.length;i++) {
			S[i] = s[i].toCharArray();
		}
		w = W;
		b = B;
		map = new HashMap<Character,Integer>();
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				for(int k=0;k<c.length;k++) {
					if(S[i][j]==c[k])map.put(c[k],toint(i,j));
				}
			}
		}
	}
	BetterGridGraph(int n,int m,char[][] s,char[] c,char W,char B){
		
		N = n;
		M = m;
		S = s;
		w = W;
		b = B;
		map = new HashMap<Character,Integer>();
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				for(int k=0;k<c.length;k++) {
					if(S[i][j]==c[k])map.put(c[k],toint(i,j));
				}
			}
		}
	}
	
	int toint(int i,int j) {
		return i*M+j;
	}
	
	int[] bfs(char C) {
		int s = map.get(C);
		int[] L = new int[N*M];
		for(int i=0;i<N*M;i++){
			L[i] = -1;
		}
		L[s] = 0;
		ArrayDeque<Integer> Q = new ArrayDeque<Integer>();
		Q.add(s);
		Range X = new Range(0,N-1);
		Range Y = new Range(0,M-1);
		while(!Q.isEmpty()){
			int v = Q.poll();
			for(int i=0;i<4;i++){
				int x = v/M;
				int y = v%M;
				int nx = x+dx[i];
				int ny = y+dy[i];
				if(X.isIn(nx)&&Y.isIn(ny)&&S[nx][ny]!=b) {
					int w = toint(nx,ny);
					if(L[w]==-1){
						L[w] = L[v] + 1;
						Q.add(w);
					}
				}
			}
		}
		return L;
	}
	
	int[][] bfs2(char C,int K){
		int s = map.get(C);
		int[][] L = new int[N*M][K+1];
		for(int i=0;i<N*M;i++){
			for(int j=0;j<=K;j++)
			L[i][j] = 1000000007;
		}
		L[s][0] = 0;
		ArrayDeque<IntIntPair> Q = new ArrayDeque<IntIntPair>();
		Q.add(new IntIntPair(s,0));
		Range X = new Range(0,N-1);
		Range Y = new Range(0,M-1);
		while(!Q.isEmpty()){
			IntIntPair v = Q.poll();
			for(int i=0;i<4;i++){
				int x = v.a/M;
				int y = v.a%M;
				int h = v.b;
				int nx = x+dx[i];
				int ny = y+dy[i];
				if(X.isIn(nx)&&Y.isIn(ny)&&S[nx][ny]!=b) {
					int ni = toint(nx,ny);
					int nh = S[nx][ny]==w?h+1:h;
					if(nh>K) continue;
					if(L[ni][nh]==1000000007){
						L[ni][nh] = L[v.a][h] + 1;
						Q.add(new IntIntPair(ni,nh));
					}
				}
			}
		}
		for(int i=0;i<N*M;i++) {
			for(int j=1;j<=K;j++) {
				L[i][j] = Math.min(L[i][j],L[i][j-1]);
			}
		}
		return L;
	}
}

class StringManager{
	ArrayList<Character> S;
	static Mathplus mp;
	static boolean calced;
	static int base;
	static long baserev;
	ArrayList<Long> l;
	StringManager(String s){
		S = new ArrayList<Character>();
		for(int i=0;i<s.length();i++) {
			S.add(s.charAt(i));
		}
		if(!calced) {
			calced = true;
			mp = new Mathplus();
			base = 1000003;
			baserev = mp.rev(base);
			mp.buildpow(base,1000050);
			mp.buildrevpow((int) baserev,1000050);

		}
		l = new ArrayList<Long>();

		l.add((long)S.get(0));

		for(int i=1;i<S.size();i++) {
			char c = S.get(i);
			l.add((l.get(i-1) + mp.pow[i] * c)%mp.mod);

		}
	}
	void add(char C){
		int i = S.size();
		S.add(C);
		l.add((l.get(i-1) + mp.pow[i] * C)%mp.mod);
	}
	long gethash(int le,int ri) {
		long res = l.get(ri);
		if(le!=0) {
			res -= l.get(le-1);
			res += mp.mod;
			res %= mp.mod;
			res *= mp.revpow[le];
			res %= mp.mod;
		}
		return res;
	}


}


class Trie{
	int nodenumber = 1;
	ArrayList<TrieNode> l;
	Trie(){
		l = new ArrayList<TrieNode>();
		l.add(new TrieNode());
	}

	void add(String S,int W){
		int now = 0;
		for(int i=0;i<S.length();i++) {
			TrieNode n = l.get(now);
			char c = S.charAt(i);
			if(n.Exist[c-'a']!=-1) {
				now = n.Exist[c-'a'];
			}else {
				l.add(new TrieNode());
				n.Exist[c-'a'] = nodenumber;
				now = nodenumber;
				nodenumber++;
			}
		}
		l.get(now).weight = W;
	}

	void find(String S,int i,int[] dp) {
		int now = 0;
		dp[i+1] = Math.max(dp[i],dp[i+1]);
		for(int j=0;;j++) {
			TrieNode n = l.get(now);
			dp[i+j] = Math.max(dp[i+j],dp[i]+n.weight);
			int slook = i+j;
			if(slook>=S.length())return;
			char c = S.charAt(slook);
			if(n.Exist[c-'a']==-1)return;
			now = n.Exist[c-'a'];
		}
	}
}

class TrieNode{

	int[] Exist = new int[26];
	int weight = 0;
	TrieNode(){
		for(int i=0;i<26;i++) {
			Exist[i] = -1;
		}
	}
}

class SizeComparator implements Comparator<Edge>{
	int[] size;
	SizeComparator(int[] s) {
		size = s;
	}

	public int compare(Edge o1, Edge o2) {
		return size[o1.to]-size[o2.to];

	}

}

class ConvexHullTrick {
	long[] A, B;
	int len;

	public ConvexHullTrick(int n) {
		A = new long[n];
		B = new long[n];
	}

	private boolean check(long a, long b) {
		return (B[len - 2] - B[len - 1]) * (a - A[len - 1]) >= (B[len - 1] - b) * (A[len - 1] - A[len - 2]);
	}

	public void add(long a, long b) {
		while (len >= 2 && check(a, b)) {
			len--;
		}
		A[len] = a;
		B[len] = b;
		len++;
	}

	public long query(long x) {
		int l = -1, r = len - 1;
		while (r - l > 1) {
			int mid = (r + l) / 2;
			if (get(mid,x)>=get(mid+1,x)) {
				l = mid;
			} else {
				r = mid;
			}
		}
		return get(r,x);
	}

	private long get(int k, long x) {
		return A[k] * x + B[k];
	}
}

class Range{
	int l;
	int r;
	int length;
	Range(int L,int R){
		l = L;
		r = R;
		length = R-L+1;
	}

	boolean isIn(int x) {
		return (l<=x&&x<=r);

	}
}
class LeftComparator implements Comparator<Range>{
	public int compare(Range P, Range Q) {
		return P.l-Q.l;
	}
}
class RightComparator implements Comparator<Range>{
	public int compare(Range P, Range Q) {
		return P.r-Q.r;
	}
}
class LengthComparator implements Comparator<Range>{
	public int compare(Range P, Range Q) {
		return P.length-Q.length;
	}
}
class SegmentTree<T,E>{
	int N;
	BiFunction<T,T,T> f;
	BiFunction<T,E,T> g;
	T d1;
	ArrayList<T> dat;
	SegmentTree(BiFunction<T,T,T> F,BiFunction<T,E,T> G,T D1,T[] v){
		int n = v.length;
		f = F;
		g = G;
		d1 = D1;
		init(n);
		build(v);
	}


	void init(int n) {
		N = 1;
		while(N<n)N*=2;
		dat = new ArrayList<T>();
	}

	void build(T[] v) {
		for(int i=0;i<2*N;i++) {
			dat.add(d1);
		}
		for(int i=0;i<v.length;i++) {
			dat.set(N+i-1,v[i]);
		}
		for(int i=N-2;i>=0;i--) {
			dat.set(i,f.apply(dat.get(i*2+1),dat.get(i*2+2)));
		}
	}

	void update(int k,E a) {
		k += N-1;
		dat.set(k,g.apply(dat.get(k),a));
		while(k>0){
			k = (k-1)/2;
			dat.set(k,f.apply(dat.get(k*2+1),dat.get(k*2+2)));
		}
	}

	T query(int a,int b, int k, int l ,int r) {
		if(r<=a||b<=l) return d1;
		if(a<=l&&r<=b) return dat.get(k);
		T vl = query(a,b,k*2+1,l,(l+r)/2);
		T vr = query(a,b,k*2+2,(l+r)/2,r);
		return f.apply(vl, vr);
	}
	T query(int a,int b){
		return query(a,b,0,0,N);
	}

}

class LazySegmentTree<T,E> extends SegmentTree<T,E>{
	BiFunction<E,E,E> h;
	BiFunction<E,Integer,E> p = (E a,Integer b) ->{return a;};
	E d0;
	ArrayList<E> laz;
	LazySegmentTree(BiFunction<T,T,T> F,BiFunction<T,E,T> G,BiFunction<E,E,E> H,T D1,E D0,T[] v){
		super(F,G,D1,v);
		int n = v.length;
		h = H;
		d0 = D0;
		Init(n);
	}
	void build() {

	}
	void Init(int n){
		laz = new ArrayList<E>();
		for(int i=0;i<2*N;i++) {
			laz.add(d0);
		}
	}

	void eval(int len,int k) {
		if(laz.get(k).equals(d0)) return;
		if(k*2+1<N*2-1) {
			laz.set(k*2+1,h.apply(laz.get(k*2+1),laz.get(k)));
			laz.set(k*2+2,h.apply(laz.get(k*2+2),laz.get(k)));
		}
		dat.set(k,g.apply(dat.get(k), p.apply(laz.get(k), len)));
		laz.set(k,d0);
	}

	T update(int a,int b,E x,int k,int l,int r) {
		eval(r-l,k);
		if(r<=a||b<=l) {
			return dat.get(k);
		}
		if(a<=l&&r<=b) {
			laz.set(k,h.apply(laz.get(k),x));
			return g.apply(dat.get(k),p.apply(laz.get(k),r-l));
		}
		T vl = update(a,b,x,k*2+1,l,(l+r)/2);
		T vr = update(a,b,x,k*2+2,(l+r)/2,r);
		dat.set(k,f.apply(vl,vr));
		return dat.get(k);

	}

	T update(int a,int b,E x) {
		return update(a,b,x,0,0,N);
	}

	T query(int a,int b,int k,int l,int r) {
		eval(r-l,k);
		if(r<=a||b<=l) return d1;
		if(a<=l&&r<=b) return dat.get(k);

		T vl = query(a,b,k*2+1,l,(l+r)/2);
		T vr = query(a,b,k*2+2,(l+r)/2,r);
		return f.apply(vl, vr);
	}

	T query(int a,int b){
		return query(a,b,0,0,N);
	}

}

class AddSumSegmentTree{
	int N;
	int d1;
	ArrayList<Integer> dat;
	AddSumSegmentTree(int[] v){
		int n = v.length;
		init(n);
		build(v);
	}

	void init(int n) {
		N = 1;
		while(N<n)N*=2;
		dat = new ArrayList<Integer>();
	}

	void build(int[] v) {
		for(int i=0;i<2*N;i++) {
			dat.add(d1);
		}
		for(int i=0;i<v.length;i++) {
			dat.set(N+i-1,v[i]);
		}
		for(int i=N-2;i>=0;i--) {
			dat.set(i,dat.get(i*2+1)+dat.get(i*2+2));
		}
	}

	void update(int k,int a) {
		k += N-1;
		dat.set(k,dat.get(k)+a);
		while(k>0){
			k = (k-1)/2;
			dat.set(k,dat.get(k*2+1)+dat.get(k*2+2));
		}
	}

	int query(int a,int b, int k, int l ,int r) {
		if(r<=a||b<=l) return d1;
		if(a<=l&&r<=b) return dat.get(k);
		int vl = query(a,b,k*2+1,l,(l+r)/2);
		int vr = query(a,b,k*2+2,(l+r)/2,r);
		return vl+vr;
	}
	int query(int a,int b){
		return query(a,b,0,0,N);
	}
}
class AddSumLazySegmentTree {
	int N;
	long[] dat;
	long[] laz;
	AddSumLazySegmentTree(long[] v){
		init(v.length);

		for(int i=0;i<v.length;i++) {
			dat[N+i-1]=v[i];
		}
		for(int i=N-2;i>=0;i--) {
			dat[i]=dat[i*2+1]+dat[i*2+2];
		}
	}

	void init(int n) {
		N = 1;
		while(N<n)N*=2;
		dat = new long[2*N];
		laz = new long[2*N];
	}


	void eval(int len,int k) {
		if(laz[k]==0) return;
		if(k*2+1<N*2-1) {
			laz[k*2+1] += laz[k];
			laz[k*2+2] += laz[k];
		}
		dat[k] += laz[k] * len;
		laz[k] = 0;
	}

	long update(int a,int b,long x,int k,int l,int r) {
		eval(r-l,k);
		if(r<=a||b<=l) {
			return dat[k];
		}
		if(a<=l&&r<=b) {
			laz[k] += x;
			return dat[k]+laz[k]*(r-l);
		}
		long vl = update(a,b,x,k*2+1,l,(l+r)/2);
		long vr = update(a,b,x,k*2+2,(l+r)/2,r);
		return dat[k] = vl+vr;


	}

	long update(int a,int b,long x) {
		return update(a,b,x,0,0,N);
	}

	long query(int a,int b,int k,int l,int r) {
		eval(r-l,k);
		if(r<=a||b<=l) return 0;
		if(a<=l&&r<=b) return dat[k];

		long vl = query(a,b,k*2+1,l,(l+r)/2);
		long vr = query(a,b,k*2+2,(l+r)/2,r);
		return vl+vr;
	}

	long query(int a,int b){
		return query(a,b,0,0,N);
	}

}

class BinaryIndexedTree{
	int[] val;
	BinaryIndexedTree(int N){
		val = new int[N+1];
	}
	long sum(int i) {
		if(i==0)return 0;
		long s = 0;
		while(i>0) {
			s += val[i];
			i -= i & (-i);
		}
		return s;
	}
	void add(int x,int i) {
		if(i==0)return;
		while(i<val.length){
			val[i] += x;
			i += i & (-i);
		}
	}
}

class UnionFindTree {
	int[] root;
	int[] rank;
	int[] size;
	int[] edge;
	int num;
	UnionFindTree(int N){
		root = new int[N];
		rank = new int[N];
		size = new int[N];
		edge = new int[N];
		num = N;
		for(int i=0;i<N;i++){
			root[i] = i;
			size[i] = 1;
		}
	}
	public boolean isRoot(int x) {
		return x==find(x);
	}
	public int extraEdge(int x) {
		int r = find(x);
		return edge[r] - size[r] + 1;
	}
	public int find(int x){
		if(root[x]==x){
			return x;
		}else{
			return find(root[x]);
		}
	}

	public void unite(int x,int y){
		x = find(x);
		y = find(y);
		if(x==y){
			edge[x]++;
			return;
		}else{
			num--;
			if(rank[x]<rank[y]){
				root[x] = y;
				size[y] += size[x];
				edge[y] += edge[x]+1;
			}else{
				root[y] = x;
				size[x] += size[y];
				edge[x] += edge[y]+1;
				if(rank[x]==rank[y]){
					rank[x]++;
				}
			}
		}
	}

	public boolean same(int x,int y){
		return find(x)==find(y);
	}

}

class ParticalEternalLastingUnionFindTree extends UnionFindTree{
	int[] time;
	int now;
	ParticalEternalLastingUnionFindTree(int N){
		super(N);
		time = new int[N];
		for(int i=0;i<N;i++) {
			time[i] = 1000000007;
		}
	}

	public int find(int t,int i) {
		if(time[i]>t) {
			return i;
		}else {
			return find(t,root[i]);
		}
	}

	public void unite(int x,int y,int t) {
		now = t;
		x = find(t,x);
		y = find(t,y);
		if(x==y)return;
		if(rank[x]<rank[y]){
			root[x] = y;
			size[y] += size[x];
			time[x] = t;
		}else{
			root[y] = x;
			size[x] += size[y];
			if(rank[x]==rank[y]){
				rank[x]++;
			}
			time[y] = t;
		}
	}

	public int sametime(int x,int y) {
		if(find(now,x)!=find(now,y)) return -1;
		int ok = now;
		int ng = 0;
		while(ok-ng>1) {
			int mid = (ok+ng)/2;
			if(find(mid,x)==find(mid,y)) {
				ok = mid;
			}else {
				ng = mid;
			}
		}
		return ok;
	}


}
class Graph {
	ArrayList<Edge>[] list;
	int size;
	TreeSet<LinkEdge> Edges = new TreeSet<LinkEdge>(new LinkEdgeComparator());
	
	@SuppressWarnings("unchecked")
	Graph(int N){
		size = N;
		list = new ArrayList[N];
		for(int i=0;i<N;i++){
			list[i] = new ArrayList<Edge>();
		}
	}

	void addEdge(int a,int b){
		list[a].add(new Edge(b,1));
	}

	void addWeightedEdge(int a,int b,long c){
		list[a].add(new Edge(b,c));
	}

	void addEgdes(int[] a,int[] b){

		for(int i=0;i<a.length;i++){
			list[a[i]].add(new Edge(b[i],1));
		}
	}

	void addWeighterEdges(int[] a ,int[] b ,int[] c){
		for(int i=0;i<a.length;i++){
			list[a[i]].add(new Edge(b[i],c[i]));
		}
	}

	long[][] bfs(int s){
		long[][] L = new long[2][size];
		for(int i=0;i<size;i++){
			L[0][i] = -1;
			L[1][i] = -1;
		}
		L[0][s] = 0;
		ArrayDeque<Integer> Q = new ArrayDeque<Integer>();
		Q.add(s);

		while(!Q.isEmpty()){
			int v = Q.poll();
			for(Edge e:list[v]){
				int w = e.to;
				long c = e.cost;
				if(L[0][w]==-1){
					L[0][w] = L[0][v] + c;
					L[1][w] = v; 
					Q.add(w);
				}
			}
		}
		return L;
	}
	long[] bfs2(int[] d,int s){
		long[] L = new long[size];
		for(int i=0;i<size;i++){
			L[i] = -1;
		}
		int p = 0;
		L[s] = 0;
		d[s] = p;
		p++;
		ArrayDeque<Integer> Q = new ArrayDeque<Integer>();
		Q.add(s);

		while(!Q.isEmpty()){
			int v = Q.poll();
			for(Edge e:list[v]){
				int w = e.to;
				long c = e.cost;
				if(L[w]==-1){
					d[w] = p;
					p++;
					L[w] = L[v] + c;
					Q.add(w);
				}
			}
		}
		return L;
	}

	int[] isTwoColor(){
		int[] L = new int[size];
		for(int i=0;i<size;i++){
			L[i] = -1;
		}
		L[0] = 0;
		ArrayDeque<Integer> Q = new ArrayDeque<Integer>();
		Q.add(0);

		while(!Q.isEmpty()){
			int v = Q.poll();
			for(Edge e:list[v]){
				int w = e.to;
				if(L[w]==-1){
					L[w] = 1-L[v];
					Q.add(w);
				}else{
					if(L[v]+L[w]!=1){
						L[0] = -2;
					}
				}
			}
		}
		return L;
	}

	long[] dijkstra(int s){
		long[] L = new long[size];
		for(int i=0;i<size;i++){
			L[i] = -1;
		}
		int[] v = new int[size];
		L[s] = 0;
		PriorityQueue<LongIntPair> Q = new PriorityQueue<LongIntPair>(new LongIntSampleComparator());
		Q.add(new LongIntPair(0,s));

		while(!Q.isEmpty()){

			LongIntPair C = Q.poll();
			
			if(v[C.b]==0){
				L[C.b] = C.a;
				v[C.b] = 1;
				for(Edge D:list[C.b]) {
					if(L[D.to]==-1||L[D.to]>L[C.b]+D.cost) {
						L[D.to]=L[C.b]+D.cost;
						Q.add(new LongIntPair(L[C.b]+D.cost,D.to));
					}
				
				}
			}
		}
		return L;
	}

	ArrayList<Graph> makeapart(){
		ArrayList<Graph> ans = new ArrayList<Graph>();
		boolean[] b = new boolean[size];
		int[] num = new int[size];
		for(int i=0;i<size;i++){
			if(b[i])continue;
			int sz = 0;
			ArrayList<Integer> l = new ArrayList<Integer>();
			ArrayDeque<Integer> Q = new ArrayDeque<Integer>();
			Q.add(i);
			b[i] = true;
			while(!Q.isEmpty()){
				int v = Q.poll();
				num[v] = sz;
				sz++;
				l.add(v);
				for(Edge e:list[v]){
					if(!b[e.to]){
						Q.add(e.to);
						b[e.to] = true;
					}
				}
			}
			Graph H = new Graph(sz);
			for(int e:l){
				for(Edge E:list[e]){
					H.addWeightedEdge(num[e],num[E.to],E.cost);
				}
			}
			ans.add(H);

		}
		return ans;
	}

	long[] bellmanFord(int s) {
		long inf = 1000000000;
		inf *= inf;
		long[] d = new long[size];
		boolean[] n = new boolean[size];
		d[s] = 0;
		for(int i=1;i<size;i++){
			d[i] = inf;
			d[i] *= d[i];
		}
		for(int i=0;i<size-1;i++){
			for(int j=0;j<size;j++){
				for(Edge E:list[j]){
					if(d[j]!=inf&&d[E.to]>d[j]+E.cost){
						d[E.to]=d[j]+E.cost;
					}
				}
			}
		}
		for(int i=0;i<size;i++){
			for(int j=0;j<size;j++){
				for(Edge e:list[j]){
					if(d[j]==inf) continue;
					if(d[e.to]>d[j]+e.cost) {
						d[e.to]=d[j]+e.cost;
						n[e.to] = true;
					}
					if(n[j])n[e.to] = true;
				}
			}
		}
		for(int i=0;i<size;i++) {
			if(n[i])d[i] = inf;
		}
		return d;
	}
	
	long[][] WarshallFloyd(long[][] a){
		int n = a.length;
		long[][] ans = new long[n][n];
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				ans[i][j] = a[i][j]==0?(long)1e16:a[i][j];
				if(i==j)ans[i][j]=0;
			}
		}
		for(int k=0;k<n;k++) {
			for(int i=0;i<n;i++) {
				for(int j=0;j<n;j++) {
					ans[i][j] = Math.min(ans[i][j],ans[i][k]+ans[k][j]);
				}
			}
		}
		return ans;
	}
	long[] maxtra(int s,long l){
		long[] L = new long[size];
		for(int i=0;i<size;i++){
			L[i] = -1;
		}
		int[] v = new int[size];
		L[s] = -1;

		PriorityQueue<Pair> Q = new PriorityQueue<Pair>(new SampleComparator());
		Q.add(new Pair(l,s));

		while(!Q.isEmpty()){

			Pair C = Q.poll();
			if(v[(int)C.b]==0){
				L[(int)C.b] = C.a;
				v[(int) C.b] = 1;
				for(Edge D:list[(int) C.b])Q.add(new Pair(Math.max(L[(int)C.b],D.cost),D.to));
			}
		}

		return L;
	}
	long[] mintra(int s){
		long[] L = new long[size];
		for(int i=0;i<size;i++){
			L[i] = -1;
		}
		int[] v = new int[size];
		L[s] = s;

		PriorityQueue<Pair> Q = new PriorityQueue<Pair>(new SampleComparator().reversed());
		Q.add(new Pair(s,s));

		while(!Q.isEmpty()){

			Pair C = Q.poll();
			if(v[(int)C.b]==0){
				L[(int)C.b] = C.a;
				v[(int) C.b] = 1;
				for(Edge D:list[(int) C.b])Q.add(new Pair(Math.min(L[(int)C.b],D.cost),D.to));
			}
		}

		return L;
	}
	long Kruskal(){
		long r = 0;
		for(int i=0;i<size;i++) {
			for(Edge e:list[i]) {
				Edges.add(new LinkEdge(e.cost,i,e.to));
			}
		}
		UnionFindTree UF = new UnionFindTree(size);
		for(LinkEdge e:Edges){
			if(e.a>=0&&e.b>=0) {
				if(!UF.same(e.a,e.b)){
					r += e.L;
					UF.unite(e.a,e.b);
				}
			}
		}
		return r;
	}

	ArrayList<Integer> Kahntsort(){

		ArrayList<Integer> ans = new ArrayList<Integer>();
		PriorityQueue<Integer> q = new PriorityQueue<Integer>();
		int[] in = new int[size];
		for(int i=0;i<size;i++) {
			for(Edge e:list[i])in[e.to]++;
		}
		for(int i=0;i<size;i++) {
			if(in[i]==0)q.add(i);
		}
		while(!q.isEmpty()) {
			int v = q.poll();
			ans.add(v);
			for(Edge e:list[v]) {
				in[e.to]--;
				if(in[e.to]==0)q.add(e.to);
			}
		}
		for(int i=0;i<size;i++) {
			if(in[i]>0)return new ArrayList<Integer>();
		}
		return ans;
	}

	RootedTree dfsTree(int i) {
		int[] u = new int[size];
		RootedTree r = new RootedTree(size);
		dfsTree(i,u,r);
		return r;

	}

	private void dfsTree(int i, int[] u, RootedTree r) {
		u[i] = 1;
		for(Edge e:list[i]) {
			if(u[e.to]==0) {
				r.list[i].add(e);
				u[e.to] = 1;
				dfsTree(e.to,u,r);
			}
		}

	}
}


class Tree extends Graph{

	public Tree(int N) {
		super(N);
	}

	long[] tyokkei(){
		long[][] a = bfs(0);

		System.out.println();
		int md = -1;
		long m = 0;
		for(int i=0;i<size;i++){
			if(m<a[0][i]){
				m = a[0][i];
				md = i;
			}
		}

		long[][] b = bfs(md);
		int md2 = -1;
		long m2 = 0;
		for(int i=0;i<size;i++){
			if(m2<b[0][i]){
				m2 = b[0][i];
				md2 = i;
			}
		}
		long[] r = {m2,md,md2};
		return r;
	}

}

class RootedTree extends Graph{
	RootedTree(int N){
		super(N);
	}
}
class LinkEdge{
	long L;
	int a ;
	int b;
	LinkEdge(long l,int A,int B){
		L = l;
		a = A;
		b = B;
	}
	public boolean equals(Object o){
		LinkEdge O = (LinkEdge) o;
		return O.a==this.a&&O.b==this.b&&O.L==this.L;
	}

	public int hashCode(){
		return Objects.hash(L,a,b);
	}
}

class Edge{
	int to;
	long cost;

	Edge(int a,long b){
		to = a;
		cost = b;
	}
}
class LinkEdgeComparator implements Comparator<LinkEdge>{
	public int compare(LinkEdge P, LinkEdge Q) {
		long t = P.L-Q.L;
		if(t==0){
			if(P.a>Q.a){
				return 1;
			}else{
				return P.b>Q.b?1:-1;
				
			}
		}
		return t>=0?1:-1;
	}
}

class Triplet{
	long a;
	long b;
	long c;
	Triplet(long p,long q,long r){
		a = p;
		b = q;
		c = r;
	}
	public boolean equals(Object o){
		Triplet O = (Triplet) o;
		return O.a==this.a&&O.b==this.b&&O.c==this.c?true:false;
			
	}

	public int hashCode(){
		return Objects.hash(a,b,c);
	}
}

class TripletComparator implements Comparator<Triplet>{
	public int compare(Triplet P, Triplet Q) {
		long t = P.a-Q.a;
		if(t==0){
			long tt = P.b-Q.b;
			if(tt==0) {
				if(P.c>Q.c) {
					return 1;
				}else if(P.c<Q.c){
					return -1;
				}else {
					return 0;
				}
			}
			return tt>0?1:-1;
		}
		return t>=0?1:-1;
	}
}
class Pair{
	long a;
	long b;

	Pair(long p,long q){
		this.a = p;
		this.b = q;
	}

	public boolean equals(Object o){
		Pair O = (Pair) o;
		return O.a==this.a&&O.b==this.b;
	}

	public int hashCode(){
		return Objects.hash(a,b);
	}
}

class SampleComparator implements Comparator<Pair>{
	public int compare(Pair P, Pair Q) {
		long t = P.a-Q.a;
		if(t==0){
			return P.b>=Q.b?1:-1;

		}
		return t>=0?1:-1;
	}
}


class LongIntPair{
	long a;
	int b;

	LongIntPair(long p,int q){
		this.a = p;
		this.b = q;
	}

	public boolean equals(Object o){
		Pair O = (Pair) o;
		return O.a==this.a&&O.b==this.b;

	}

	public int hashCode(){
		return Objects.hash(a,b);
	}
}

class LongIntSampleComparator implements Comparator<LongIntPair>{
	public int compare(LongIntPair P, LongIntPair Q) {
		long t = P.a-Q.a;
		if(t==0){
			if(P.b>Q.b){
				return 1;
			}else{
				return -1;
			}
		}
		return t>=0?1:-1;
	}
}


class IntIntPair{
	int a;
	int b;

	IntIntPair(int p,int q){
		this.a = p;
		this.b = q;
	}

	public boolean equals(Object o){
		Pair O = (Pair) o;
		return O.a==this.a&&O.b==this.b;
			
	}

	public int hashCode(){
		return Objects.hash(a,b);
	}
}



class IntIntSampleComparator implements Comparator<IntIntPair>{
	public int compare(IntIntPair P, IntIntPair Q) {
		int t = P.a-Q.a;
		if(t==0){
			return P.b-Q.b;
		}
		return t;
	}
}




class DoublePair{
	double a;
	double b;

	DoublePair(double p,double q){
		this.a = p;
		this.b = q;
	}

	public boolean equals(Object o){
		Pair O = (Pair) o;
		return O.a==this.a&&O.b==this.b;
			
	}

	public int hashCode(){
		return Objects.hash(a,b);
	}
}

class DDSampleComparator implements Comparator<DoublePair>{
	public int compare(DoublePair P, DoublePair Q) {
		return P.b-Q.b>=0?1:-1;
	}
}

class DoubleTriplet{
	double a;
	double b;
	double c;

	DoubleTriplet(double p,double q,double r){
		this.a = p;
		this.b = q;
		this.c = r;
	}

	public boolean equals(Object o){
		DoubleTriplet O = (DoubleTriplet) o;
		return O.a==this.a&&O.b==this.b&&O.c==this.c;
			
	}

	public int hashCode(){
		return Objects.hash(a,b,c);
	}
}


class FastScanner {
    private final java.io.InputStream in = System.in;
    private final byte[] b = new byte[1024];
    private int p = 0;
    private int bl = 0;
    private boolean hNB() {
        if (p<bl) {
            return true;
        }else{
            p = 0;
            try {
                bl = in.read(b);
            } catch (IOException e) {
                e.printStackTrace();
            }
            if (bl<=0) {
                return false;
            }
        }
        return true;
    }
    private int rB() { if (hNB()) return b[p++]; else return -1;}
    private static boolean iPC(int c) { return 33 <= c && c <= 126;}
    private void sU() { while(hNB() && !iPC(b[p])) p++;}
    public boolean hN() { sU(); return hNB();}
    public String next() {
        if (!hN()) throw new NoSuchElementException();
        StringBuilder sb = new StringBuilder();
        int b = rB();
        while(iPC(b)) {
            sb.appendCodePoint(b);
            b = rB();
        }
        return sb.toString();
    }
    public char nextChar() {
    	return next().charAt(0);
    }
    public long nextLong() {
        if (!hN()) throw new NoSuchElementException();
        long n = 0;
        boolean m = false;
        int b = rB();
        if (b=='-') {
            m=true;
            b=rB();
        }
        if (b<'0'||'9'<b) {
            throw new NumberFormatException();
        }
        while(true){
            if ('0'<=b&&b<='9') {
                n *= 10;
                n += b - '0';
            }else if(b == -1||!iPC(b)){
                return (m?-n:n);
            }else{
                throw new NumberFormatException();
            }
            b = rB();
        }
    }
    public int nextInt() {
        if (!hN()) throw new NoSuchElementException();
        long n = 0;
        boolean m = false;
        int b = rB();
        if (b == '-') {
            m = true;
            b = rB();
        }
        if (b<'0'||'9'<b) {
            throw new NumberFormatException();
        }
        while(true){
            if ('0'<=b&&b<='9') {
                n *= 10;
                n += b-'0';
            }else if(b==-1||!iPC(b)){
                return (int) (m?-n:n);
            }else{
                throw new NumberFormatException();
            }
            b = rB();
        }
    }
    public int[] nextInts(int n) {
    	int[] a = new int[n];
    	for(int i=0;i<n;i++) {
    		a[i] = nextInt();
    	}
    	return a;
    }
    public long[] nextLongs(int n) {
    	long[] a = new long[n];
    	for(int i=0;i<n;i++) {
    		a[i] = nextLong();
    	}
    	return a;
    }
    public int[][] nextIntses(int n,int m){
    	int[][] a = new int[n][m];
    	for(int i=0;i<n;i++) {
    		for(int j=0;j<m;j++) {
    			a[i][j] = nextInt();
    		}
    	}
    	return a;
    }
}


class Mathplus{
	int mod = 1000000007;
	long[] fac;
	long[] revfac;
	long[][] comb;
	long[] pow;
	long[] revpow;
	boolean isBuild = false;
	boolean isBuildc = false;
	boolean isBuildp = false;
	int mindex = -1;
	int maxdex = -1;
	
	int color(int[][] diff,int N) {
		
		int[] val = new int[1<<N];
		val[0] = 1;
		for(int i=0;i<(1<<N);i++) {		
			for(int j=0;j<N;j++) {
				if(contains(i,j)) {
					if(val[bitremove(i,j)]==1) {
						boolean b = true;
						for(int k=0;k<N;k++) {
							if(contains(i,k)&&diff[j][k]==1) {
								b = false;
							}
						}
						if(b)val[i] = 1;
					}
					break;
				}
			}
		}
		int[] dp = new int[1<<N];
		Arrays.fill(dp,mod);;
		dp[0] = 0;
		for(int i=0;i<(1<<N);i++) {
			for(int j=i;j>0;j=(j-1)&i) {
				if(val[j]==1)dp[i]=Math.min(dp[i],dp[i^j]+1);
			}
		}
		return dp[(1<<N)-1];
	}
	
	public DoubleTriplet Line(double x1,double y1,double x2,double y2) {
		double a = y1-y2;
		double b = x2-x1;
		double c = x1*y2-x2*y1;
		return new DoubleTriplet(a,b,c);
	}
	public double putx(DoubleTriplet T,double x) {
		return -(T.a*x+T.c)/T.b;
	}
	public double puty(DoubleTriplet T,double y) {
		return -(T.b*y+T.c)/T.a;
	}
	public double DistanceofPointandLine(DoublePair P,Triplet T) {
		return Math.abs(P.a*T.a+P.b*T.b+T.c) / Math.sqrt(T.a*T.a+T.b*T.b);
	}
	public boolean cross(long ax, long ay, long bx, long by, long cx, long cy, long dx, long dy) {
		 long ta = (cx - dx) * (ay - cy) + (cy - dy) * (cx - ax);
		 long tb = (cx - dx) * (by - cy) + (cy - dy) * (cx - bx);
		 long tc = (ax - bx) * (cy - ay) + (ay - by) * (ax - cx);
		 long td = (ax - bx) * (dy - ay) + (ay - by) * (ax - dx);
		 return((tc>=0&&td<=0)||(tc<=0&&td>=0))&&((ta>=0&&tb<=0)||(ta<=0&&tb>=0));
	}
	public boolean dcross(double ax, double ay, double bx, double by, double cx, double cy, double dx, double dy) {
		 double ta = (cx - dx) * (ay - cy) + (cy - dy) * (cx - ax);
		 double tb = (cx - dx) * (by - cy) + (cy - dy) * (cx - bx);
		 double tc = (ax - bx) * (cy - ay) + (ay - by) * (ax - cx);
		 double td = (ax - bx) * (dy - ay) + (ay - by) * (ax - dx);
		 return((tc>=0&&td<=0)||(tc<=0&&td>=0))&&((ta>=0&&tb<=0)||(ta<=0&&tb>=0));
	}
	
	void buildFac(){
		fac = new long[10000003];
		revfac = new long[10000003];
		fac[0] = 1;
		for(int i=1;i<=10000002;i++){
			fac[i] = (fac[i-1] * i)%mod;
		}
		revfac[10000002] = rev(fac[10000002])%mod;
		for(int i=10000001;i>=0;i--) {
			revfac[i] = (revfac[i+1] * (i+1))%mod;
		}
		isBuild = true;
	}
	public long[] buildrui(int[] a) {
		int n = a.length;
		long[] ans = new long[n];
		ans[0] = a[0];
		for(int i=1;i<n;i++) {
			ans[i] = ans[i-1] + a[i];
		}
		return ans;
	}
	public long[][] buildrui(int[][] a) {
		int n = a.length;
		int m = a[0].length;
		long[][] ans = new long[n][m];
		for(int i=1;i<n;i++) {
			for(int j=1;j<m;j++) {
				ans[i][j] = a[i][j];
			}
		}
		for(int i=1;i<n;i++) {
			for(int j=1;j<m;j++) {
				ans[i][j] += ans[i][j-1] + ans[i-1][j] - ans[i-1][j-1];
			}
		}
		return ans;
	}
	long divroundup(long n,long d) {
		if(n==0)return 0;
		return (n-1)/d+1;
	}
	public long sigma(long i) {
		return i*(i+1)/2;
	}
	public int digit(long i) {
		int ans = 1;
		while(i>=10) {
			i /= 10;
			ans++;
		}
		return ans;

	}
	public int popcount(int i) {
		int ans = 0;
		while(i>0) {
			ans += i%2;
			i /= 2;
		}
		return ans;
	}
	public boolean contains(int S,int i) {return (S>>i&1)==1;}
	public int bitremove(int S,int i) {return S&(~(1<<i));}
	public int bitadd(int S,int i) {return S|(1<<i);}
	public boolean isSubSet(int S,int T) {return (S-T)==(S^T);}
	public boolean isDisjoint(int S,int T) {return (S+T)==(S^T);}
	public int isBigger(int[] d, int i) {
		int ok = d.length;
		int ng = -1;
		while(Math.abs(ok-ng)>1) {
			int mid = (ok+ng)/2;
			if(d[mid]>i) {
				ok = mid;
			}else {
				ng = mid;
			}
		}
		return ok;
	}
	public int isSmaller(int[] d, int i) {
		int ok = -1;
		int ng = d.length;
		while(Math.abs(ok-ng)>1) {
			int mid = (ok+ng)/2;
			if(d[mid]<i) {
				ok = mid;
			}else {
				ng = mid;
			}
		}
		return ok;
	}
	public int isBigger(long[] d, long i) {
		int ok = d.length;
		int ng = -1;
		while(Math.abs(ok-ng)>1) {
			int mid = (ok+ng)/2;
			if(d[mid]>i) {
				ok = mid;
			}else {
				ng = mid;
			}
		}
		return ok;
	}
	public int isSmaller(long[] d, long i) {
		int ok = -1;
		int ng = d.length;
		while(Math.abs(ok-ng)>1) {
			int mid = (ok+ng)/2;
			if(d[mid]<i) {
				ok = mid;
			}else {
				ng = mid;
			}
		}
		return ok;
	}
	public int isBigger(ArrayList<Long> d, long i) {
		int ok = d.size();
		int ng = -1;
		while(Math.abs(ok-ng)>1) {
			int mid = (ok+ng)/2;
			if(d.get(mid)>i) {
				ok = mid;
			}else {
				ng = mid;
			}
		}
		return ok;
	}
	public int isSmaller(ArrayList<Long> d, long i) {
		int ok = -1;
		int ng = d.size();
		while(Math.abs(ok-ng)>1) {
			int mid = (ok+ng)/2;
			if(d.get(mid)<i) {
				ok = mid;
			}else {
				ng = mid;
			}
		}
		return ok;
	}
	public HashSet<Integer> primetable(int m) {
		HashSet<Integer> pt = new HashSet<Integer>();
		for(int i=2;i<=m;i++) {
			boolean b = true;
			for(int d:pt) {
				if(i%d==0) {
					b = false;
					break;
				}
			}
			if(b) {
				pt.add(i);
			}
		}
		return pt;
	}
	public ArrayList<Integer> primetablearray(int m) {
		ArrayList<Integer> al = new ArrayList<Integer>();
		Queue<Integer> q = new ArrayDeque<Integer>();
		for(int i=2;i<=m;i++) {
			q.add(i);
			
		}
		boolean[] b = new boolean[m+1];
		while(!q.isEmpty()) {
			int e = q.poll();
			if(!b[e]) {
				al.add(e);
				for(int j=1;e*j<=1000000;j++) {
					b[e*j] = true;
				}
			}
		}
		return al;
	}
	public HashMap<Integer,Integer> hipPush(ArrayList<Integer> l){
		HashMap<Integer,Integer> r = new HashMap<Integer,Integer>();
		TreeSet<Integer> s = new TreeSet<Integer>();
		for(int e:l)s.add(e);
		int p = 0;
		for(int e:s) {
			r.put(e,p);
			p++;
		}
		return r;
	}
	public TreeMap<Integer,Integer> thipPush(ArrayList<Integer> l){
		TreeMap<Integer,Integer> r = new TreeMap<Integer,Integer>();
		Collections.sort(l);
		int b = -(mod+9393);
		int p = 0;
		for(int e:l) {
			if(b!=e) {
				r.put(e,p);
				p++;
			}
			b=e;
		}
		return r;
	}

	long max(long[] a){
		long M = 0;
		for(int i=0;i<a.length;i++){
			if(M<a[i]){
				M =a[i];
				maxdex = i;
			}
		}
		return M;
	}
	int max(int[] a){
		int M = 0;
		for(int i=0;i<a.length;i++){
			if(M<a[i]){
				M =a[i];
				maxdex = i;
			}
		}
		return M;
	}
	long min(long[] a){
		long m = Long.MAX_VALUE;
		for(int i=0;i<a.length;i++){
			if(m>a[i]){
				m =a[i];
				mindex = i;
			}
		}
		return m;
	}
	int min(int[] a){
		int m = Integer.MAX_VALUE;
		for(int i=0;i<a.length;i++){
			if(m>a[i]){
				m =a[i];
				mindex = i;
			}
		}
		return m;
	}
	long sum(long[] a){
		long s = 0;
		for(int i=0;i<a.length;i++)s += a[i];
		return s;
	}
	long sum(int[] a){
		long s = 0;
		for(int i=0;i<a.length;i++)s += a[i];
		return s;
	}
	long gcd(long a, long b){
		a = Math.abs(a);
		b = Math.abs(b);
		if(a==0)return b;
		if(b==0)return a;
		if(a%b==0) return b;
		else return gcd(b,a%b);
	}
	int igcd(int a, int b) {
		if(a%b==0) return b;
		else return igcd(b,a%b);
	}
	long lcm(long a, long b) {return a / gcd(a,b) * b;}
	public long perm(int a,int num) {
		if(!isBuild)buildFac();
		return fac[a]*(rev(fac[a-num]))%mod;
	}
	void buildComb(int N) {
		comb = new long[N+1][N+1];
		comb[0][0] = 1;
		for(int i=1;i<=N;i++) {
			comb[i][0] = 1;
			for(int j=1;j<N;j++) {
				comb[i][j] = comb[i-1][j-1]+comb[i-1][j];
				if(comb[i][j]>mod)comb[i][j]-=mod;
			}
			comb[i][i] = 1;
		}
	}
	public long comb(int a,int num){
		if(a-num<0)return 0;
		if(num<0)return 0;
		if(!isBuild)buildFac();
		return fac[a] * ((revfac[num]*revfac[a-num])%mod)%mod;
	}
	long mulchoose(int n,int k) {
		if(k==0) return 1;
		return comb(n+k-1,k);
	}
	long rev(long l) {return pow(l,mod-2);}
	
	void buildpow(int l,int i) {
		pow = new long[i+1];
		pow[0] = 1;
		for(int j=1;j<=i;j++) {
			pow[j] = pow[j-1]*l;
			if(pow[j]>mod)pow[j] %= mod;
		}
	}
	void buildrevpow(int l,int i) {
		revpow = new long[i+1];
		revpow[0] = 1;
		for(int j=1;j<=i;j++) {
			revpow[j] = revpow[j-1]*l;
			if(revpow[j]>mod) revpow[j] %= mod;		
		}
	}
	long pow(long l, long i) {
		if(i==0)return 1;
		else{
			if(i%2==0){
				long val = pow(l,i/2);
				return val * val % mod;
			}
			else return pow(l,i-1) * l % mod;
		}
	}
}
