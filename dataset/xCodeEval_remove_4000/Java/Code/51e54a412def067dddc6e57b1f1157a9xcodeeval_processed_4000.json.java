import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.NoSuchElementException;
import java.util.Objects;
import java.util.PriorityQueue;
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
	
	public static void main(String[] args) {
		
		int T = sc.nextInt();
		
		for(int i=0;i<T;i++) {
			String x = sc.next();
			String y = sc.next();
			int y1 = 0;
			for(int j=0;j<y.length();j++) {
				if(y.charAt(y.length()-1-j)=='1') {
					y1 = j;
					break;
		
				}
			}
			for(int j=y1;j<x.length();j++) {
				if(x.charAt(x.length()-1-j)=='1') {
					ot.println(j-y1);
					break;
				}
			}
		}
		ot.flush();
		
	}

	
	
	

}

class StringManager{
	ArrayList<Character> S;
	static Mathplus mp;
	static boolean calced;
	static int base;
	static long id18;
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
			id18 = mp.rev(base);
			mp.buildpow(base,1000050);
			mp.id33((int) id18,1000050);
			
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
	int id31 = 1;
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
				n.Exist[c-'a'] = id31;
				now = id31;
				id31++;
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

class id23 {
	long[] A, B;
	int len;

	public id23(int n) {
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
			if (get(mid, x) >= get(mid + 1, x)) {
				l = mid;
			} else {
				r = mid;
			}
		}
		return get(r, x);
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

class id14<T,E> extends SegmentTree<T,E>{
	BiFunction<E,E,E> h;
	BiFunction<E,Integer,E> p = (E a,Integer b) ->{return a;};
	E d0;
	ArrayList<E> laz;
	id14(BiFunction<T,T,T> F,BiFunction<T,E,T> G,BiFunction<E,E,E> H,T D1,E D0,T[] v){
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
class id28 {
	int N;
	long[] dat;
	long[] laz;
	id28(long[] v){
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

class id16{
	int[] val;
	id16(int N){
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
		while(i<val.length) {
			System.out.println(i);
			val[i] += x;
			i += i & (-i);
		}
	}
}

class id13 {
	int[] root;
	int[] rank;
	int[] size;
	id13(int N){
		root = new int[N];
		rank = new int[N];
		size = new int[N];
		for(int i=0;i<N;i++){
			root[i] = i;
			size[i] = 1;
		}
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
			return;
		}else{
			if(rank[x]<rank[y]){
				root[x] = y;
				size[y] += size[x];
			}else{
				root[y] = x;
				size[x] += size[y];
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

class id17 extends id13{
	int[] time;
	int now;
	id17(int N){
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
	TreeSet<LinkEdge> Edges = new TreeSet<LinkEdge>(new id19());
	
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

	void id1(int a,int b,long c){
		list[a].add(new Edge(b,c));
	}

	void id27(int[] a,int[] b){
		int size = a.length;
		for(int i=0;i<size;i++){
			list[a[i]].add(new Edge(b[i],1));
		}
	}

	void id8(int[] a ,int[] b ,int[] c){
		int size = a.length;
		for(int i=0;i<size;i++){
			list[a[i]].add(new Edge(b[i],c[1]));
		}
	}

	long[] bfs(int s){
		long[] L = new long[size];
		for(int i=0;i<size;i++){
			L[i] = -1;
		}
		L[s] = 0;
		ArrayDeque<Integer> Q = new ArrayDeque<Integer>();
		Q.add(s);

		while(!Q.isEmpty()){
			int v = Q.poll();
			for(Edge e:list[v]){
				int w = e.to;
				long c = e.cost;
				if(L[w]==-1){
					L[w] = L[v] + c;
					Q.add(w);
				}
			}
		}
		return L;
	}
	long[] id29(int[] d,int s){
		long[] L = new long[size];
		for(int i=0;i<size;i++){
			L[i] = -1;
		}
		int pos = 0;
		L[s] = 0;
		d[s] = pos;
		pos++;
		ArrayDeque<Integer> Q = new ArrayDeque<Integer>();
		Q.add(s);

		while(!Q.isEmpty()){
			int v = Q.poll();
			for(Edge e:list[v]){
				int w = e.to;
				long c = e.cost;
				if(L[w]==-1){
					d[w] = pos;
					pos++;
					L[w] = L[v] + c;
					Q.add(w);
				}
			}
		}
		return L;
	}
	
	int[] id34(){
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
		int[] visited = new int[size];
		L[s] = 0;
		PriorityQueue<Pair> Q = new PriorityQueue<Pair>(new SampleComparator());
		Q.add(new Pair(0,s));

		while(!Q.isEmpty()){

			Pair C = Q.poll();
			if(visited[(int)C.b]==0){
				L[(int)C.b] = C.a;
				visited[(int) C.b] = 1;
				for(Edge D:list[(int) C.b]){
					Q.add(new Pair(L[(int)C.b]+D.cost,D.to));
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
					H.id1(num[e],num[E.to],E.cost);
				}
			}
			ans.add(H);
			
		}
		return ans;
	}
	
	long[] id0(int s) {
		long inf = 1000000000;
		inf *= inf;
		long[] dist = new long[size];
		boolean[] neg = new boolean[size];
		dist[s] = 0;
		for(int i=1;i<size;i++){
			dist[i] = inf;
			dist[i] *= dist[i];
		}
		for(int i=0;i<size-1;i++){
			for(int j=0;j<size;j++){
				for(Edge E:list[j]){
					if(dist[j]!=inf&&dist[E.to]>dist[j]+E.cost){
						dist[E.to]=dist[j]+E.cost;
					}
				}
			}
		}
		for(int i=0;i<size;i++){
			for(int j=0;j<size;j++){
				for(Edge e:list[j]){
					if(dist[j]==inf) continue;
					if(dist[e.to]>dist[j]+e.cost) {
						dist[e.to]=dist[j]+e.cost;
						neg[e.to] = true;
					}
					if(neg[j])neg[e.to] = true;
				}
			}
		}
		for(int i=0;i<size;i++) {
			if(neg[i])dist[i] = inf;
		}
		return dist;
	}
	long[] maxtra(int s,long l){
		long[] L = new long[size];
		for(int i=0;i<size;i++){
			L[i] = -1;
		}
		int[] visited = new int[size];
		L[s] = -1;
	
		PriorityQueue<Pair> Q = new PriorityQueue<Pair>(new SampleComparator());
		Q.add(new Pair(l,s));

		while(!Q.isEmpty()){

			Pair C = Q.poll();
			if(visited[(int)C.b]==0){
				L[(int)C.b] = C.a;
				visited[(int) C.b] = 1;
				for(Edge D:list[(int) C.b]){
					Q.add(new Pair(Math.max(L[(int)C.b],D.cost),D.to));
				}
			}
		}

		return L;
	}
	long id30(){
		long ans = 0;
		for(int i=0;i<size;i++) {
			for(Edge e:list[i]) {
				Edges.add(new LinkEdge(e.cost,i,e.to));
			}
		}
		id13 UF = new id13(size);
		for(LinkEdge e:Edges){
			if(e.a>=0&&e.b>=0) {
				if(!UF.same(e.a,e.b)){
					ans += e.L;
					UF.unite(e.a,e.b);
				}
			}
		}

		return ans;
	}
	
	
	ArrayList<Integer> id3(){

		ArrayList<Integer> ans = new ArrayList<Integer>();
		PriorityQueue<Integer> q = new PriorityQueue<Integer>();
		int[] in = new int[size];
		for(int i=0;i<size;i++) {
			for(Edge e:list[i]) {
				in[e.to]++;
			}
		}
		for(int i=0;i<size;i++) {
			if(in[i]==0) {
				q.add(i);
			}
		}
		while(!q.isEmpty()) {
			int v = q.poll();
			ans.add(v);
			for(Edge e:list[v]) {
				in[e.to]--;
				if(in[e.to]==0) {
					q.add(e.to);
				}
			}
		}
		for(int i=0;i<size;i++) {
			if(in[i]>0)return new ArrayList<Integer>();
		}
		return ans;
	}
	
	id10 dfsTree(int i) {
		int[] used = new int[size];
		id10 r = new id10(size);
		dfsTree(i,used,r);
		return r;
		
	}
	
	


	private void dfsTree(int i, int[] used, id10 r) {
		used[i] = 1;
		for(Edge e:list[i]) {
			if(used[e.to]==0) {
				r.list[i].add(e);
				used[e.to] = 1;
				dfsTree(e.to,used,r);
			}
		}
		
	}
}


class Tree extends Graph{
	
	public Tree(int N) {
		super(N);
	}
	
	long[] id21(){
		long[] a = bfs(0);
		
		System.out.println();
		int maxdex = -1;
		long max = 0;
		for(int i=0;i<size;i++){
			if(max<a[i]){
				max = a[i];
				maxdex = i;
			}
		}
 
		long[] b = bfs(maxdex);
		System.out.println();
		int id5 = -1;
		long max2 = 0;
		for(int i=0;i<size;i++){
			if(max2<b[i]){
				max2 = b[i];
				id5 = i;
			}
		}
		long[] ans = {max2,maxdex,id5};
		return ans;
	}
 
}

class id10 extends Graph{
	
	id10(int N){
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
		if(O.a==this.a&&O.b==this.b&&O.L==this.L){
			return true;
		}else{
			return false;
		}


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
class id19 implements Comparator<LinkEdge>{
	public int compare(LinkEdge P, LinkEdge Q) {
		long temp = P.L-Q.L;
		if(temp==0){
			if(P.a>Q.a){
				return 1;
			}else{
				if(P.b>Q.b){
					return 1;
				}else{
					return -1;
				}
			}

		}
		if(temp>=0){
			return 1;
		}else{
			return -1;
		}
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
		if(O.a==this.a&&O.b==this.b&&O.c==this.c){
			return true;
		}else{
			return false;
		}


	}

	public int hashCode(){
		return Objects.hash(a,b,c);
	}
	
}

class id26 implements Comparator<Triplet>{
	public int compare(Triplet P, Triplet Q) {
		long temp = P.a-Q.a;
		if(temp==0){
			long ttemp = P.b-Q.b;
			if(ttemp==0) {
				if(P.c>Q.c) {
					return 1;
				}else if(P.c<Q.c){
					return -1;
				}else {
					return 0;
				}
			}
			if(ttemp>0) {
				return 1;
			}else {
				return -1;
			}

		}
		if(temp>=0){
			return 1;
		}else{
			return -1;
		}
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
		if(O.a==this.a&&O.b==this.b){
			return true;
		}else{
			return false;
		}


	}

	public int hashCode(){
		return Objects.hash(a,b);
	}

}

class SampleComparator implements Comparator<Pair>{
	public int compare(Pair P, Pair Q) {
		long temp = P.a-Q.a;
		if(temp==0){
			if(P.b>Q.b){
				return 1;
			}else{
				return -1;
			}

		}
		if(temp>=0){
			return 1;
		}else{
			return -1;
		}
	}

}


class id11{
	long a;
	int b;

	id11(long p,int q){
		this.a = p;
		this.b = q;
	}

	public boolean equals(Object o){
		Pair O = (Pair) o;
		if(O.a==this.a&&O.b==this.b){
			return true;
		}else{
			return false;
		}


	}

	public int hashCode(){
		return Objects.hash(a,b);
	}

}

class id9 implements Comparator<id11>{
	public int compare(id11 P, id11 Q) {
		long temp = P.a-Q.a;
		if(temp==0){
			if(P.b>Q.b){
				return 1;
			}else{
				return -1;
			}

		}
		if(temp>=0){
			return 1;
		}else{
			return -1;
		}
	}

}


class id4{
	int a;
	int b;

	id4(int p,int q){
		this.a = p;
		this.b = q;
	}

	public boolean equals(Object o){
		Pair O = (Pair) o;
		if(O.a==this.a&&O.b==this.b){
			return true;
		}else{
			return false;
		}


	}

	public int hashCode(){
		return Objects.hash(a,b);
	}

}

class id6 implements Comparator<id4>{
	public int compare(id4 P, id4 Q) {
		int temp = P.a-Q.a;
		if(temp==0){
			return P.b-Q.b;

		}
		return temp;
	}

}


class FastScanner {
    private final java.io.InputStream in = System.in;
    private final byte[] buffer = new byte[1024];
    private int ptr = 0;
    private int buflen = 0;
    private boolean id35() {
        if (ptr < buflen) {
            return true;
        }else{
            ptr = 0;
            try {
                buflen = in.read(buffer);
            } catch (IOException e) {
                e.printStackTrace();
            }
            if (buflen <= 0) {
                return false;
            }
        }
        return true;
    }
    private int readByte() { if (id35()) return buffer[ptr++]; else return -1;}
    private static boolean id36(int c) { return 33 <= c && c <= 126;}
    private void id20() { while(id35() && !id36(buffer[ptr])) ptr++;}
    public boolean hasNext() { id20(); return id35();}
    public String next() {
        if (!hasNext()) throw new NoSuchElementException();
        StringBuilder sb = new StringBuilder();
        int b = readByte();
        while(id36(b)) {
            sb.appendCodePoint(b);
            b = readByte();
        }
        return sb.toString();
    }
    
    public long nextLong() {
        if (!hasNext()) throw new NoSuchElementException();
        long n = 0;
        boolean minus = false;
        int b = readByte();
        if (b == '-') {
            minus = true;
            b = readByte();
        }
        if (b < '0' || '9' < b) {
            throw new NumberFormatException();
        }
        while(true){
            if ('0' <= b && b <= '9') {
                n *= 10;
                n += b - '0';
            }else if(b == -1 || !id36(b)){
                return (minus ? -n : n);
            }else{
                throw new NumberFormatException();
            }
            b = readByte();
        }
    }
    public int nextInt() {
        if (!hasNext()) throw new NoSuchElementException();
        long n = 0;
        boolean minus = false;
        int b = readByte();
        if (b == '-') {
            minus = true;
            b = readByte();
        }
        if (b < '0' || '9' < b) {
            throw new NumberFormatException();
        }
        while(true){
            if ('0' <= b && b <= '9') {
                n *= 10;
                n += b - '0';
            }else if(b == -1 || !id36(b)){
                return (int) (minus ? -n : n);
            }else{
                throw new NumberFormatException();
            }
            b = readByte();
        }
    }
}


class Mathplus{
	int mod = 1000000007;
	long[] fac;
	long[][] comb;
	long[] pow;
	long[] revpow;
	boolean isBuild = false;
	boolean id2 = false;
	boolean id25 = false;
	int mindex = -1;
	int maxdex = -1;


	void buildFac(){
		fac = new long[3000003];
		fac[0] = 1;
		for(int i=1;i<=3000002;i++){
			fac[i] = (fac[i-1] * i)%mod;
		}
		isBuild = true;
	}
	
	long id15(long n,long d) {
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

	public boolean contains(int S,int i) {
		return (S>>i&1)==1;
	}
	
	public int bitremove(int S,int i) {
		return S-(1<<i);
	}
	
	public int bitadd(int S,int i) {
		return S+(1<<i);
	}
	
	public boolean id12(int S,int T) {
		return (S-T)==(S^T);
	}
	
	public boolean id24(int S,int T) {
		return (S+T)==(S^T);
	}
	
	public int id22(int[] d, int i) {
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
	
	public int id32(int[] d, int i) {
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
	public int id22(long[] d, long i) {
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
	
	public int id32(long[] d, long i) {
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
	public int id22(ArrayList<Long> d, long i) {
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
	
	public int id32(ArrayList<Long> d, long i) {
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
	
	public HashMap<Integer,Integer> hipPush(ArrayList<Integer> l){
		HashMap<Integer,Integer> ret = new HashMap<Integer,Integer>();
		TreeSet<Integer> s = new TreeSet<Integer>();
		for(int e:l) {
			s.add(e);
		}
		int pos = 0;
		for(int e:s) {
			ret.put(e,pos);
			pos++;
		}
		return ret;
	}
	public TreeMap<Integer,Integer> id7(ArrayList<Integer> l){
		TreeMap<Integer,Integer> ret = new TreeMap<Integer,Integer>();
		TreeSet<Integer> s = new TreeSet<Integer>();
		Collections.sort(l);
		int bef = -(mod+9393);
		int pos = 0;
		for(int e:l) {
			if(bef!=e) {
				ret.put(e,pos);
				pos++;
			}
			bef=e;
		}
		return ret;
	}
	
	long max(long[] a){
		long max = 0;
		for(int i=0;i<a.length;i++){
			if(max<a[i]){
				max =a[i];
				maxdex = i;
			}
		}
		return max;
	}
	int max(int[] a){
		int max = 0;
		for(int i=0;i<a.length;i++){
			if(max<a[i]){
				max =a[i];
				maxdex = i;
			}
		}
		return max;
	}
	long min(long[] a){
		long min = Long.MAX_VALUE;
		for(int i=0;i<a.length;i++){
			if(min>a[i]){
				min =a[i];
				mindex = i;
			}
		}
		return min;
	}
	int min(int[] a){
		int min = Integer.MAX_VALUE;
		for(int i=0;i<a.length;i++){
			if(min>a[i]){
				min =a[i];
				mindex = i;
			}
		}
		return min;
	}
	long sum(long[] a){
		long sum = 0;
		for(int i=0;i<a.length;i++){
			sum += a[i];
		}
		return sum;
	}
	long sum(int[] a){
		long sum = 0;
		for(int i=0;i<a.length;i++){
			sum += a[i];
		}
		return sum;
	}

	long gcd(long a, long b){
		if(a<b){
			a^=b;
			b^=a;
			a^=b;
		}
		if(a%b==0){
			return b;
		}else{
			return gcd(b,a%b);
		}
	}
	int igcd(int a, int b){
		
		if(a%b==0){
			return b;
		}else{
			return igcd(b,a%b);
		}
	}

	long lcm(long a, long b){
		return a / gcd(a,b) * b;
	}
	
	public long perm(int a,int num) {
		
		if(!isBuild) {
			buildFac();
		}
		return fac[a] * (rev(fac[a-num]))%mod;
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
		if(!isBuild){
			buildFac();
		}
		return fac[a] * (rev(fac[num])*rev(fac[a-num])%mod)%mod;
	}
	
	long mulchoose(int n,int k) {
		if(k==0) return 1;
		return comb(n+k-1,k);
	}
	long rev(long l) {
		return pow(l,mod-2);
	}
	void buildpow(int l,int i) {
		pow = new long[i+1];
		pow[0] = 1;
		for(int j=1;j<=i;j++) {
			pow[j] = pow[j-1]*l;
			if(pow[j]>mod) {
				pow[j] %= mod;
			}
		}
	}
	void id33(int l,int i) {
		revpow = new long[i+1];
		revpow[0] = 1;
		for(int j=1;j<=i;j++) {
			revpow[j] = revpow[j-1]*l;
			if(revpow[j]>mod) {
				revpow[j] %= mod;
			}
		}
	}
	long pow(long l, long i) {
		if(i==0){
			return 1;
		}else{
			if(i%2==0){
				long val = pow(l,i/2);
				return val * val % mod;
			}else{
				return pow(l,i-1) * l % mod;
			}
		}
	}
	


}
