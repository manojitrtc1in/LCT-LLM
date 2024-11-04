


import java.util.*;
import java.util.Map.Entry;


import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.math.BigInteger;

 
public class Main {
	


	
	private static ArrayList<Long> id0(long x) {
		ArrayList<Long>a=new ArrayList<Long>();for(long i=1;i*i<=x;i++) {if(x%i==0) {a.add((long) i);if(x/i!=i)a.add(x/i);}}


		return a;
	}
	static long[] sieve;
    static long[] id10;
 	public static void sieve()
    {
        int n=4000000+1;
    	sieve=new long[n];
    	id10=new long[n];
    	sieve[0]=1;
    	sieve[1]=1;
    	for(int i=2;i<n;i++){
    		sieve[i]=i;
    		id10[i]=i;
    	}
    	for(int i=2;i*i<n;i++){
    		if(sieve[i]==i){
	    		for(int j=i*i;j<n;j+=i){
	    			if(sieve[j]==j)sieve[j]=1;
	    			if(id10[j]==j||id10[j]>i)id10[j]=i;
	    		}
    		}
    	}
    }
 	static long nCr(long n,long r,long MOD) {
 		computeFact(n, MOD);
 		if(n<r)return 0;if(r==0)return 1;
 		return fact[(int) n]*mod_inv(fact[(int) r],MOD)%MOD*mod_inv(fact[(int) (n-r)],MOD)%MOD;
 	}
 	static long[]fact;
 	static void computeFact(long n,long MOD) {
 		fact=new long[(int)n+1];fact[0]=1;
 		for(int i=1;i<=n;i++)fact[i]=(fact[i-1]*i%MOD)%MOD;
 	}
 	static long id12(long a,long b,long MOD) {
	    if(b == 0)return 1;
	    long ans = id12(a,b/2,MOD);
	    ans = (ans*ans)%MOD;
	    if(b % 2!=0)ans = (ans*a)%MOD;
	    return ans%MOD;
	}
 	static int ceil(int x, int y) {return (x % y == 0 ? x / y : (x / y + 1));}
 
	static long ceil(long x, long y) {return (x % y == 0 ? x / y : (x / y + 1));}
 	static long mod_add(long a, long b, long m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
 	static long mod_mul(long a, long b, long m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
 	static long mod_sub(long a, long b, long m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
 	
	static long mod_inv(long n,long p) {return id12(n,p-2,p);}
	static long gcd(long a, long b){if (a == 0) {return b;}return gcd(b % a, a); }
    static int gcd(int a, int b){if (a == 0) {return b; }return gcd(b % a, a); }
    static long lcm(long a,long b){return (a / gcd(a, b)) * b;}
    static long min(long x,long y) {return Math.min(x, y);}static long max(long x,long y) {return Math.max(x, y);}
    static int min(int x,int y) {return Math.min(x, y);}static int max(int x,int y) {return Math.max(x, y);}
    static ArrayList<String>id8;
    static void id11() {
    	long i=1;
    	while(i<(long)2e18) {
    		id8.add(String.valueOf(i));
    		i*=2;
    	}
    }
    static long power(long a, long b){
    	a %=MOD;long out = 1;
	    while (b > 0) {
	        if((b&1)!=0)out = out * a % MOD;
	        a = a * a % MOD;
	        b >>= 1;
			a*=a;
	    }
	    return out;
    }
    static boolean id13(int a, long l){return (gcd(a, l) == 1);}
    
    


    


	 public static int upperBound(long[] arr, long m, int l, int r) {
	    	while(l<=r) {
	    		int mid=(l+r)/2;
	    		if(arr[mid]<=m) l=mid+1;
	    		else r=mid-1;
	    	}
	    	return l;
    }
    public static int lowerBound(long[] a, long m, int l, int r) {
    	while(l<=r) {
    		int mid=(l+r)/2;
    		if(a[mid]<m) l=mid+1;
    		else r=mid-1;
    	}
    	return l;
    }
    public static int lowerBound(ArrayList<Integer> ar,int k){
        int s=0,e=ar.size();
        while (s!=e){
            int mid = s+e>>1;
            if (ar.get(mid) <k)s=mid+1;
            else e=mid;
        }
        if(s==ar.size())return -1;
        return s;
    }
    public static int upperBound(ArrayList<Integer> ar,int k){
        int s=0,e=ar.size();
        while (s!=e){
            int mid = s+e>>1;
            if (ar.get(mid) <=k)s=mid+1;
            else e=mid;
        }
        if(s==ar.size())return -1;
        return s;
    }
    public static long getClosest(long val1, long val2,long target){if (target - val1 >= val2 - target)return val2; else return val1;}
    static void id2(long[] a) {
		int n=a.length;
		Random r=new Random();
		for (int i=0; i<a.length; i++) {
			long oi=r.nextInt(n), temp=a[i];
			a[i]=a[(int)oi];
			a[(int)oi]=temp;
		}
		Arrays.sort(a);
	}
    static void id2(int[] a){
		int n=a.length;
		Random r=new Random();
		for (int i=0; i<a.length; i++) {
			int oi=r.nextInt(n), temp=a[i];
			a[i]=a[oi];
			a[oi]=temp;
		}
		Arrays.sort(a);
    }
    int ceilIndex(int input[], int T[], int end, int s){
        int start = 0;
        int middle;
        int len = end;
        while(start <= end){
            middle = (start + end)/2;
            if(middle < len && input[T[middle]] < s && s <= input[T[middle+1]]){
                return middle+1;
            }else if(input[T[middle]] < s){
                start = middle+1;
            }else{
                end = middle-1;
            }
        }
        return -1;
    }
    static int  id9(ArrayList<Long> v,long k) {
		int n =v.size();
		int first = 0,second = n;
		while(first <second) {
			int mid = first + (second-first)/2;
			if(v.get(mid) > k) {
				second = mid;
			}else {
				first = mid+1;
			}
		}
		
		 if(first < n && v.get(first) < k) {
			 first++;
		    }
		return first; 

    }
    public static int searchindex(long arr[], long t){int index = Arrays.binarySearch(arr, t);return (index < 0) ? -1 : index;}
    public static  long[] sort(long[] a) {ArrayList<Long> al = new ArrayList<>();for(int i=0;i<a.length;i++) al.add(a[i]);Collections.sort(al);for(int i=0;i<a.length;i++) a[i]=al.get(i);return a;}
    public static  int[] sort(int[] a) {ArrayList<Integer> al = new ArrayList<>();for(int i=0;i<a.length;i++) al.add(a[i]);Collections.sort(al);for(int i=0;i<a.length;i++) a[i]=al.get(i);return a;}
    


    


    	

    		

    void buildTree (int[] arr,int[] tree,int start,int end,int treeNode){
    	if(start==end){
    		tree[treeNode]=arr[start];
    		return;
    	}
    	buildTree(arr,tree,start,end,2*treeNode);
    	buildTree(arr,tree,start,end,2*treeNode+1);
    	tree[treeNode]=tree[treeNode*2]+tree[2*treeNode+1];
    }
    void updateTree(int[] arr,int[] tree,int start,int end,int treeNode,int idx,int value){
    	if(start==end){
    		arr[idx]=value;
    		tree[treeNode]=value;
    		return;
    	}
    	int mid=(start+end)/2;
    	if(idx>mid)updateTree(arr,tree,mid+1,end,2*treeNode+1,idx,value);
    	else updateTree(arr,tree,start,mid,2*treeNode,idx,value);
    	tree[treeNode]=tree[2*treeNode]+tree[2*treeNode+1];
    }
    
    long query(int[]arr,int[]tree,int start,int end,int treeNode,int qleft,int qright) {
    	if(start>=qleft&&end<=qright)return tree[treeNode];
    	if(start>qright||end<qleft)return 0;
    	int mid=(start+end)/2;
    	long valLeft=query(arr,tree,start,mid-1,treeNode*2,qleft,qright);
    	long valRight=query(arr,tree,mid+1,end,treeNode*2+1,qleft,qright);
    	return valLeft+valRight;
    }
    
    			

    	


    static int parent[];
    static int rank[];
    static int[]Size;
    static void makeSet(int n){
    	parent=new int[n];
    	rank=new int[n];
    	Size=new int[n];
    	for(int i=0;i<n;i++){
    		parent[i]=i;
    		rank[i]=0;
    		Size[i]=1;
    	}
    }
    static void union(int u,int v){
    	u=findpar(u);
    	v=findpar(v);
    	if(u==v)return;
    	if(rank[u]<rank[v]) {
    		parent[u]=v;
    		Size[v]+=Size[u];
    	}
    	else if(rank[v]<rank[u]) {
    		parent[v]=u;
    		Size[u]+=Size[v];
    	}
    	else{
    		parent[v]=u;
    		rank[u]++;
    		Size[u]+=Size[v];
    	}
    }
    
	private static int findpar(int node){	
		if(node==parent[node])return node;
		return parent[node]=findpar(parent[node]);
	}
	


	


	private static int prim(ArrayList<node>[] adj,int N,int node) {
		int key[] = new int[N+1];
        int parent[] = new int[N+1]; 
        boolean mstSet[] = new boolean[N+1]; 
        for(int i = 0;i<N;i++) {
        	key[i] = 100000000; 
        	mstSet[i] = false; 
        }
        PriorityQueue<node> pq = new PriorityQueue<node>(N, new node());
        key[node] = 0;
        parent[node] = -1; 
        pq.add(new node( node,key[node])); 
        for(int i = 0;i<N-1;i++) {
        	int u = pq.poll().getV();
        	mstSet[u] = true;
        	for(node it: adj[u]) {
        		if(mstSet[it.getV()] == false && it.getW() < key[it.getV()]) {
        			parent[it.getV()] = u; 
        			key[it.getV()] = (int) it.getW(); 
        			pq.add(new node(it.getV(), key[it.getV()]));
        		}
        	}
        }
    	int sum=0;
    	for(int i=1;i<N;i++) {
    		System.out.println(key[i]);
    		sum+=key[i];
    	}
    	System.out.println(sum);
    	return sum;
	}
	


	static int[]dist;
	static int dijkstra(int u,int n,ArrayList<node>adj[]) {
		long[]path=new long[n];
		dist=new int[n];
		Arrays.fill(dist,Integer.MAX_VALUE);
		dist[u]=0;
		path[0]=1;
		PriorityQueue<node>pq=new PriorityQueue<node>(new node());
		pq.add(new node(u,0));
		while(!pq.isEmpty()) {
			node v=pq.poll();
			if(dist[v.getV()]<v.getW())continue;
			for(node it:adj[v.getV()]) {
				if(dist[it.getV()]>it.getW()+dist[v.getV()]) {
					dist[it.getV()]=(int) (it.getW()+dist[v.getV()]);
					pq.add(new node(it.getV(),dist[it.getV()]));
					path[it.getV()]=path[v.getV()];
				}
				else if(dist[it.getV()]==it.getW()+dist[v.getV()]) {
					path[it.getV()]+=path[v.getV()];
				}
			}
		}
		int sum=0;
		for(int i=1;i<n;i++){
			System.out.println(dist[i]);
			sum+=dist[i];
		}
		return sum;
	}
	
	
    private static void setGraph(int n,int m){
    	vis=new boolean[n+1];
    	indeg=new int[n+1];














		
		
    	adj=new ArrayList[n+1];


		for(int i=0;i<=n;i++){
			adj[i]=new ArrayList<Integer>();


		}
		for(int i=0;i<m;i++){
			int u=s.nextInt(),v=s.nextInt();
			adj[u].add(v);
			adj[v].add(u);


			indeg[v]++;
			indeg[u]++;
		}
    	


		




















	}
    


 
    
    static int[][] dirs8 = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
    static int[][] dirs4 = {{1,0},{-1,0},{0,1},{0,-1}}; 

    static long MOD=(long) (1e9+7);
    static int id5[][];
    static boolean[] vis;
    static int[]indeg;


    static ArrayList<Integer> adj[];
    static ArrayList<Integer> backadj[];
    static FastReader s = new FastReader(System.in);
    static PrintWriter out = new PrintWriter(System.out);
    
    public static void main(String[] args) throws IOException
    {














    		int tt = s.nextInt();


	        for(int i=1;i<=tt;i++) {
	        	solver();
	        }
	        out.close();


    }
    static int cnt=0;
    static int[]a;
	private static void solver() {
		f=false;
		cnt=0;
		int n=s.nextInt();
		a=s.rdia(n);
		mergeSort(0,n-1,a);
		if(f){out.println(-1);return;}
		else {out.println(cnt);return;}
	}
	static boolean f;
	private static void mergeSort(int i, int j, int[] a) {
		if(f)return;
		if(j==i)return;
		int mid=(i+j)/2;
		mergeSort(i, mid, a);
		mergeSort(mid+1,j,a);
		if(f)return;
		merge(a,i,mid,j);
	}
	private static void merge(int[] a, int i, int mid, int j) {
		boolean flag=false;
		for(int k=i;k<j;k++) {
			if(a[k]>a[k+1])flag=true;
		}
		if(!flag)return;
		int[]temp=new int[j-i+1];
		int idx=0;
		for(int k=mid+1;k<=j;k++) {temp[idx++]=a[k];}
		for(int k=i;k<=mid;k++) {temp[idx++]=a[k];}
		for(int k=0;k<temp.length-1;k++){
			if(temp[k]>temp[k+1]) {
				f=true;
				return;
			}
		}
		cnt++;
		System.arraycopy(temp, 0, a, i, j-i+1);
	}
	private static long sqroot(long x) {
		long left = 0, right = 2000000123;
		while (right > left) {
			long mid = (left + right) / 2;
			if (mid * mid > x) right = mid;
			else left = mid + 1;
		}
		return left - 1;
	}
	
    static boolean issafe(int i, int j, int r,int c,boolean[][]vis){
		if (i < 0 || j < 0 || i >= r || j >= c||vis[i][j]==true)return false;
		else return true;
    }
    
    
    static void id3(int[][]id5) {
    	for(int i=1;i<=200000;i++) {
			int z=i;
			int j=0;
			while(z>0) {
				if((z&1)==1) {
					id5[i][j]+=(id5[i-1][j]+1);
				}else {
					id5[i][j]=id5[i-1][j];
				}
				z=z>>1;
				j++;
			}
		}
    }
    static void id4(long[]a) {
    	for(int j=30;j>=0;j--) {
			int cnt=0;
			for(long i:a) {
				if((i&1<<j)==1)cnt++;
			}


			System.out.println(cnt);
		}
    }
    public static String revStr(String str){String input = str;StringBuilder input1 = new StringBuilder();input1.append(input);input1.reverse();return input1.toString();}
	static void printA(long[] x) {for(int i=0;i<x.length;i++)out.print(x[i]+" ");out.println();}
	static void printA(int[] x) {for(int i=0;i<x.length;i++)out.print(x[i]+" ");out.println();}
	private static void printA(char[] x) {for(int i=0;i<x.length;i++)out.print(x[i]+" ");out.println();}
    static void id1(boolean[][] vis) {
    	int n=vis.length;
    	int m=vis[0].length;
    	for(int i=0;i<n;i++) {
    		for(int j=0;j<m;j++) {
    			System.out.print(vis[i][j]+" ");
    		}
    		System.out.println();
    	}
    }
    static void id6(char[][] a) {
    	int n=a.length;
    	int m=a[0].length;
    	for(int i=0;i<n;i++) {
    		for(int j=0;j<m;j++) {
    			System.out.print(a[i][j]+" ");
    		}
    		System.out.println();
    	}
    }
    static void id7(int[]a) {
    	for(int i=0;i<a.length;i++)System.out.print(a[i]+" ");
    	System.out.println();
    }
    


	
	

}


class FastReader {
    public BufferedReader reader;
    public StringTokenizer tokenizer;
    public FastReader(InputStream stream) {reader = new BufferedReader(new InputStreamReader(stream), 32768);tokenizer = null;}
    public String next() {while (tokenizer == null || !tokenizer.hasMoreTokens()) {try {tokenizer = new StringTokenizer(reader.readLine());} catch (IOException e) {throw new RuntimeException(e);}}return tokenizer.nextToken();}
    public int nextInt(){ return Integer.parseInt(next());}
    public long nextLong() {return Long.parseLong(next());}
    public double nextDouble() {return Double.parseDouble(next());}
    public String nextLine() {String str = "";try {str = reader.readLine();}catch (IOException e) {e.printStackTrace();}return str;}
    public int[] rdia(int n) {int[] a = new int[n];for (int i = 0; i < n; i++) a[i] = nextInt();return a;}
    public long[] rdla(int n) {long[] a = new long[n];for (int i = 0; i < n; i++) a[i] = nextLong();return a;}
    public Integer[] rdIa(int n) {Integer[] a = new Integer[n];for (int i = 0; i < n; i++) a[i] =nextInt();return a;}
    public Long[] rdLa(int n) {Long[] a = new Long[n];for (int i = 0; i < n; i++) a[i] = nextLong();return a;}

}

class dsu{
	int n;
	static int parent[];
    static int rank[];
    static int[]Size;
	public dsu(int n) {this.n=n;this.parent=new int[n];this.rank=new int[n];this.Size=new int[n];
    	for(int i=0;i<n;i++){parent[i]=i;rank[i]=0;Size[i]=1;}
	}
    static int findpar(int node) {if(node==parent[node])return node;return parent[node]=findpar(parent[node]);}
    static void union(int u,int v){
    	u=findpar(u);v=findpar(v);
    	if(u!=v) {
	    	if(rank[u]<rank[v]) {parent[u]=v;Size[v]+=Size[u];}
	    	else if(rank[v]<rank[u]) {parent[v]=u;Size[u]+=Size[v];}
	    	else{parent[v]=u;rank[u]++;Size[u]+=Size[v];}
    	}
    }
}
class pair{
	int x;int y;
	long u,v;
	public pair(int x,int y){this.x=x;this.y=y;}
	public pair(long u,long v) {this.u=u;this.v=v;}
}
class Tuple{
	String str;int x;int y;
	public Tuple(String str,int x,int y) {
		this.str=str;
		this.x=x;
		this.y=y;
	}
}
class node implements Comparator<node>{
    private int v;
    private long w;
    node(int _v, long _w) { v = _v; w = _w; }
    node() {}
    int getV() { return v; }
    long getW() { return w; }
    @Override
    public int compare(node node1, node node2) { 
        if (node1.w < node2.w) return -1; 
        if (node1.w > node2.w) return 1; 
        return 0; 
    } 
}