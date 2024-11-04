

import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.*; 
 
 
 
 
 
 
 
 
 


public class Main {
	
	

 
    
	
	
	static Scanner in = new Scanner(System.in);
	
	public static void main (String[] args) throws java.lang.Exception {
	    
		

		PrintWriter out = new PrintWriter(System.out);
		
 
		int T=1;
		
		for(int t=0;t<T;t++){
			int N=Int();
			int M=Int();
			
			int A[][]=new int[M][3];
			int r=-1;
			for(int i=0;i<M;i++){
				A[i][0]=Int();
				A[i][1]=Int();
				A[i][2]=Int();
				r=Math.max(r,A[i][2]);
			}
			
			Solution sol=new Solution();
			sol.solution(A,N,r);
		}
 
		out.flush();
	}
	
	
	
	public static long Long(){
		return in.nextLong();
	}
	public static int Int(){
		return in.nextInt();
	}
	public static String Str(){
		return in.next();
	}
}
 
class Solution{
	

	final int MAX=Integer.MAX_VALUE;
	final int MIN=Integer.MIN_VALUE;
	

	

 
	public void fastprint(PrintWriter out,String s){
		out.print(s);
	}
	
	public void fastprintln(PrintWriter out,String s){
		out.println(s);
	}

	

	public void solution(int A[][],int N,int r){
		int l=1;
		int S=2*N+5;
		int T=2*N+6;
		int res=-1;
		Arrays.sort(A,(a,b)->{
			return a[2]-b[2];
		});
		
		while(l<=r){
			int mid=l+(r-l)/2;
			List<int[]>B=new ArrayList<>();
			for(int i=0;i<A.length;i++){
				int v1=A[i][0];
				int v2=A[i][1];
				int w=A[i][2];
				if(w>mid)break;
				B.add(new int[]{v1,v2});
			}
			
			
			Hopcroft h=new Hopcroft();
			int flow=h.go(B);
			if(flow==N){
				res=mid;
				r=mid-1;
			}
			else{
				l=mid+1;
			}
		}
		msg(res+"");
		
	}
	
	
	



 
 
 
 
	public void sort(int A[]){
		Arrays.sort(A);
	}
	
	public void swap(int A[],int l,int r){
		int t=A[l];
		A[l]=A[r];
		A[r]=t;
	}
	
 
	
	
	public long C(long fact[],int i,int j){ 

		

		if(j>i)return 0;
		if(j==0)return 1;
		long mod=1000000007;
		long a=fact[i];
		long b=((fact[i-j]%mod)*(fact[j]%mod))%mod;
		BigInteger B= BigInteger.valueOf(b);
		long binverse=B.modInverse(BigInteger.valueOf(mod)).longValue();
		return ((a)*(binverse%mod))%mod;
	}
	
	
	 
	
	

	public void put(Map<Integer,Integer>map,int i){
		if(!map.containsKey(i))map.put(i,0);
		map.put(i,map.get(i)+1);
	}
	
	public void delete(Map<Integer,Integer>map,int i){
		map.put(i,map.get(i)-1);
		if(map.get(i)==0)map.remove(i);
	}
 
 
 
 
 
	
 
 
	
	
	
 
	
	

	public void remove(Map<Integer,Integer>map,int i){
		map.put(i,map.get(i)-1);
		if(map.get(i)==0)map.remove(i);
	}
	
	
	
	public void ascii(String s){
		for(char c:s.toCharArray()){
			System.out.print((c-'a')+" ");
		}
		msg("");
	}
	
	public int flip(int i){
		if(i==0)return 1;
		else return 0;
	}
	
	public boolean[] primes(int n){
		boolean A[]=new boolean[n+1];
		for(int i=2;i<=n;i++){
			if(A[i]==false){
				for(int j=i+i;j<=n;j+=i){
					A[j]=true;
				}
			}
		}
		return A;
	}
	
	public void msg(String s){
		System.out.println(s);
	}
	
	public void msg1(String s){
		System.out.print(s);
	}
	
	public int[] kmpPre(String p){
		int pre[]=new int[p.length()];
		int l=0,r=1;
		while(r<p.length()){
			if(p.charAt(l)==p.charAt(r)){
				pre[r]=l+1;
				l++;r++;
			}else{
				if(l==0)r++;
				else l=pre[l-1];
			}
		}
		return pre;
	}
	
	public boolean isP(String s){
		int l=0,r=s.length()-1;
		while(l<r){
			if(s.charAt(l)!=s.charAt(r))return false;
			l++;r--;
		}
		return true;
	}
	
	public int find(int nums[],int x){

		if(nums[x]==x)return x;
		int root=find(nums,nums[x]);
		nums[x]=root;
		return root;
	}
	
 
	
	public int get(int A[],int i){
		if(i<0||i>=A.length)return 0;
		return A[i];
	}
	public int[] copy1(int A[]){
		int a[]=new int[A.length];
		for(int i=0;i<a.length;i++)a[i]=A[i];
		return a;
	}
	
	
	public void print1(long A[]){
		for(long i:A)System.out.print(i+" ");
		System.out.println();
	}
	public void print2(long A[][]){
		for(int i=0;i<A.length;i++){
			for(int j=0;j<A[0].length;j++){
				System.out.print(A[i][j]+" ");
			}System.out.println();
		}
	}
	
	public int min(int a,int b){
		return Math.min(a,b);
	}
	
	
	public int[][] matrixdp(int[][] grid) {
        if(grid.length==0)return new int[][]{};
        int res[][]=new int[grid.length][grid[0].length];
        for(int i=0;i<grid.length;i++){
            for(int j=0;j<grid[0].length;j++){
                res[i][j]=grid[i][j]+get(res,i-1,j)+get(res,i,j-1)-get(res,i-1,j-1);
            }
        }
        return res;
    }
    
    public int get(int grid[][],int i,int j){
        if(i<0||j<0||i>=grid.length||j>=grid[0].length)return 0;
        return grid[i][j];
    }
	
	public int[] suffixArray(String s){
		int n=s.length();
		Suffix A[]=new Suffix[n];
		
		for(int i=0;i<n;i++){
			A[i]=new Suffix(i,s.charAt(i)-'a',0);
		}
		
		for(int i=0;i<n;i++){
			if(i==n-1){
				A[i].next=-1;
			}else{
				A[i].next=A[i+1].rank;
			}
		}
		Arrays.sort(A);
		
		for(int len=4;len<A.length*2;len<<=1){
			int in[]=new int[A.length];
			int rank=0;
			int pre=A[0].rank;
			A[0].rank=rank;
			in[A[0].index]=0;
			for(int i=1;i<A.length;i++){

				if(A[i].rank==pre&&A[i].next==A[i-1].next){
					pre=A[i].rank;
					A[i].rank=rank;
				}else{
					pre=A[i].rank;
					A[i].rank=++rank;
				}
				in[A[i].index]=i;
			}
			
			for(int i=0;i<A.length;i++){
				int next=A[i].index+len/2;
				if(next>=A.length){
					A[i].next=-1;
				}else{
					A[i].next=A[in[next]].rank;
				}
			}
			
			
			Arrays.sort(A);
		}
		
		
		int su[]=new int[A.length];
		for(int i=0;i<su.length;i++){
			su[i]=A[i].index;
		}
		return su;
	}
	
}
 


class Suffix implements Comparable<Suffix>{
	int index;
	int rank;
	int next;
	public Suffix(int i,int rank,int next){
		this.index=i;
		this.rank=rank;
		this.next=next;
	}
	
	@Override
	public int compareTo(Suffix other) {
		if(this.rank==other.rank){
			return this.next-other.next;
		}
		return this.rank-other.rank;
	}
	
	public String toString(){
		return this.index+"   "+this.rank+"   "+this.next+"  ";
	}
}
 
 
 
class Wrapper implements Comparable<Wrapper>{
	int spf;int cnt;
	public Wrapper(int spf,int cnt){
		this.spf=spf;
		this.cnt=cnt;
	}
		
	@Override
	public int compareTo(Wrapper other) {
		return this.spf-other.spf;
	}
}
 
 
 
    class Node{

		boolean state=false;
        int l=0,r=0;
		int ll=0,rr=0;
        public Node(boolean state){
            this.state=state;
        }
    }
	
	
	
	
	class Seg1{
			int A[];
			public Seg1(int A[]){
				this.A=A;
			}
			
			public void update(int left,int right,int val,int s,int e,int id){
				if(left<0||right<0||left>right)return;
				if(left==s&&right==e){
					
					A[id]+=val;
					return;
				}
				int mid=s+(e-s)/2; 

				
				if(left>=mid+1){
					update(left,right,val,mid+1,e,id*2+2);
				}else if(right<=mid){
					update(left,right,val,s,mid,id*2+1);
				}else{
					update(left,mid,val,s,mid,id*2+1);
					update(mid+1,right,val,mid+1,e,id*2+2);
				}
			}
			
			public int query(int i,int add,int s,int e,int id){
				
				if(s==e&&i==s){
					return A[id]+add;
				}
				
				int mid=s+(e-s)/2; 

				
				if(i>=mid+1){
					return query(i,A[id]+add,mid+1,e,id*2+2);
				}else{
					return query(i,A[id]+add,s,mid,id*2+1);
				}
			}
	}
 
 
	 class MaxFlow{
		
 
		  public static List<Edge>[] createGraph(int nodes) {
			List<Edge>[] graph = new List[nodes];
			for (int i = 0; i < nodes; i++)
			  graph[i] = new ArrayList<>();
			return graph;
		  }
 
		  public static void addEdge(List<Edge>[] graph, int s, int t, int cap) {
			graph[s].add(new Edge(t, graph[t].size(), cap));
			graph[t].add(new Edge(s, graph[s].size() - 1, 0));
		  }
 
		  static boolean dinicBfs(List<Edge>[] graph, int src, int dest, int[] dist) {
			Arrays.fill(dist, -1);
			dist[src] = 0;
			int[] Q = new int[graph.length];
			int sizeQ = 0;
			Q[sizeQ++] = src;
			for (int i = 0; i < sizeQ; i++) {
			  int u = Q[i];
			  for (Edge e : graph[u]) {
				if (dist[e.t] < 0 && e.f < e.cap) {
				  dist[e.t] = dist[u] + 1;
				  Q[sizeQ++] = e.t;
				}
			  }
			}
			return dist[dest] >= 0;
		  }
 
		  static int dinicDfs(List<Edge>[] graph, int[] ptr, int[] dist, int dest, int u, int f) {
			if (u == dest)
			  return f;
			for (; ptr[u] < graph[u].size(); ++ptr[u]) {
			  Edge e = graph[u].get(ptr[u]);
			  if (dist[e.t] == dist[u] + 1 && e.f < e.cap) {
				int df = dinicDfs(graph, ptr, dist, dest, e.t, Math.min(f, e.cap - e.f));
				if (df > 0) {
				  e.f += df;
				  graph[e.t].get(e.rev).f -= df;
				  return df;
				}
			  }
			}
			return 0;
		  }
 
		  public static int maxFlow(List<Edge>[] graph, int src, int dest) {
			int flow = 0;
			int[] dist = new int[graph.length];
			while (dinicBfs(graph, src, dest, dist)) {
			  int[] ptr = new int[graph.length];
			  while (true) {
				int df = dinicDfs(graph, ptr, dist, dest, src, Integer.MAX_VALUE);
				if (df == 0)
				  break;
				flow += df;
			  }
			}
			return flow;
		  }
		 
	 }
	 
	 	 class Edge {
			int t, rev, cap, f;
 
			public Edge(int t, int rev, int cap) {
			  this.t = t;
			  this.rev = rev;
			  this.cap = cap;
			}
		  }
		  
	   class Seg{
        int l,r;
        int min=Integer.MAX_VALUE;
        Seg left=null,right=null;
		int tree[];
        public Seg(int l,int r){
            this.l=l;
            this.r=r;
            if(l!=r){
                int mid=l+(r-l)/2;
                if(l<=mid)left=new Seg(l,mid);
                if(r>=mid+1)right=new Seg(mid+1,r);
                if(left!=null)min=Math.min(left.min,min);
                if(right!=null)min=Math.min(right.min,min);
            }else{
                min=tree[l];
            }
        }
        public int query(int s,int e){
            if(l==s&&r==e){
                return min;
            }
            int mid=l+(r-l)/2; 

            if(e<=mid){
                return left.query(s,e);
            }
            else if(s>=mid+1){
                return right.query(s,e);
            }else{
                return Math.min(left.query(s,mid),right.query(mid+1,e));
            }
        }

        public void update(int index){
            if(l==r){
                min=tree[l];
                return;
            }
            int mid=l+(r-l)/2;
            if(index<=mid){
                left.update(index);
            }else{
                right.update(index);
            }
            this.min=Math.min(left.min,right.min);
        }
    }
	
	
	class Hopcroft
{    
    private final int NIL = 0;
    private final int INF = Integer.MAX_VALUE;
    private ArrayList<Integer>[] Adj; 
    private int[] Pair;
    private int[] Dist;
    private int cx, cy;
 
     
    public boolean BFS() 
    {
        Queue<Integer> queue = new LinkedList<Integer>();
        for (int v = 1; v <= cx; ++v) 
            if (Pair[v] == NIL) 
            { 
                Dist[v] = 0; 
                queue.add(v); 
            }
            else 
                Dist[v] = INF;
 
        Dist[NIL] = INF;
 
        while (!queue.isEmpty()) 
        {
            int v = queue.poll();
            if (Dist[v] < Dist[NIL]) 
                for (int u : Adj[v]) 
                    if (Dist[Pair[u]] == INF) 
                    {
                        Dist[Pair[u]] = Dist[v] + 1;
                        queue.add(Pair[u]);
                    }           
        }
        return Dist[NIL] != INF;
    }    
     
    public boolean DFS(int v) 
    {
        if (v != NIL) 
        {
            for (int u : Adj[v]) 
                if (Dist[Pair[u]] == Dist[v] + 1)
                    if (DFS(Pair[u])) 
                    {
                        Pair[u] = v;
                        Pair[v] = u;
                        return true;
                    }               
 
            Dist[v] = INF;
            return false;
        }
        return true;
    }
	
	
	
     
    public int HopcroftKarp() 
    {
        Pair = new int[cx + cy + 1];
        Dist = new int[cx + cy + 1];
        int matching = 0;
        while (BFS())
            for (int v = 1; v <= cx; ++v)
                if (Pair[v] == NIL)
                    if (DFS(v))
                        matching = matching + 1;
        return matching;
    }
    
    public void makeGraph(int[] x, int[] y, int E)
    {
        Adj = new ArrayList[cx + cy + 1];
        for (int i = 0; i < Adj.length; ++i)
            Adj[i] = new ArrayList<Integer>();        
            
        for (int i = 0; i < E; ++i) 
            addEdge(x[i] + 1, y[i] + 1);    
    }
    
    public void addEdge(int u, int v) 
    {
        Adj[u].add(cx + v);
        Adj[cx + v].add(u);
    }    
    
    public int go (List<int[]>A) 
    {

        Hopcroft hc = new Hopcroft();
		int E=A.size();
        int[] x = new int[E];
        int[] y = new int[E];
        hc.cx = 0;
        hc.cy = 0;
 
        for (int i = 0; i < E; i++)
        {
            x[i] = A.get(i)[0];
            y[i] = A.get(i)[1];
            hc.cx = Math.max(hc.cx, x[i]);
            hc.cy = Math.max(hc.cy, y[i]);
        }
        hc.cx += 1;
        hc.cy += 1;
 

        hc.makeGraph(x, y, E);            
 
        return hc.HopcroftKarp();          
    }    
}
    
		  
		  