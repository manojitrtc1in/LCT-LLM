import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.lang.Character.UnicodeBlock;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.InputMismatchException;
import java.util.List;
import java.util.Set;
import java.util.StringTokenizer;
import java.util.TreeMap;








public class q1 {
    public static void main(String[] args) throws IOException {
        InputStream inputStream = System.in;
    
        
        OutputStream outputStream = System.out;
        FastScanner in;
        PrintWriter out;
        
           in=new FastScanner(System.in);
            out=new PrintWriter(System.out);
        

        
        TaskC solver = new TaskC();
        long var=System.currentTimeMillis();
        solver.solve(1, in, out);
        
        out.close();
    }
}
class Pair {
    
    long x,y,index;
    long  r1,r2;
    
    Pair(long x,long y,int index){
        this.x=x;
        this.y=y;
        this.index=index;
    }
    public String toString(){
        return this.x+" "+this.y+" ";
    }
    
}
class Edge implements  Comparable<Edge>{
    int u;
    int v;
    int time;
    long cost;
    long wcost;
    public Edge(int u,int v,long cost,long wcost){
        this.u=u;
        this.v=v;
        this.cost=cost;
        this.wcost=wcost;
        time=Integer.MAX_VALUE;
    }
    public int other(int x){
        if(u==x)return v;
        return u;
    }
    @Override
    public int compareTo(Edge o) {
        

        return Long.compare(cost, o.cost);
    }
}
class queary{
    int type;
    int l;
    int r;
    int index;
    queary(int type,int l,int r,int index){
        this.type=type;
        this.l=l;
        this.r=r;
        this.index=index;
    }
}
class TaskC {
    static long mod=1000000007;
   static int prime_len=1000010;
    static int prime[]=new int[prime_len];
    static long n_prime[]=new long[prime_len];
    static ArrayList<Integer> primes=new ArrayList<>();
    static{
        for(int i=2;i<=Math.sqrt(prime.length);i++){
            for(int j=i*i;j<prime.length;j+=i){
                
                prime[j]=i;
                
            }
        }
        for(int i=2;i<prime.length;i++){
            n_prime[i]=n_prime[i-1];
            if(prime[i]==0){
               n_prime[i]++;
            }
            
        }
    

        
    

    

    }
    
    
    class TrieNode{
        int value;
        TrieNode children[];
        public TrieNode(int value,TrieNode children[] ){
            this.value=value;
            this.children=children;
        }
    }
    class Trie{
        TrieNode root;
        int count;
        public Trie(TrieNode root,int count){
            this.root=root;
            this.count=count;
        }
    }
    public void insert(Trie t,char key[]){
        t.count++;
        int length=key.length;
        int level=0;
        TrieNode current=t.root;
        if(current==null){
            t.root=new TrieNode(0, new TrieNode[26]);
            current=t.root;
        }
        for(level=0;level<length;level++){
            int index=key[level]-'a';
            if(current.children[index]==null){
                current.children[index]=new TrieNode(0,new TrieNode[26]);
            }
            current=current.children[index];
        }
        current.value=t.count;
    }
    public int search(Trie t,char key[]){
        TrieNode current=t.root;
        if(current==null){
            return 0;
        }
        int length=key.length;
        int level=0;
        for(level=0;level<length;level++){
            int index=key[level]-'a';
            if(current.children[index]==null){
                return 0;
            }
            current=current.children[index];
        }
        return current.value;
    }
    class point implements Comparable<point>{
        long x;
        long y;
        public point(long x,long y){
            this.x=x;
            this.y=y;
        }
        @Override
        public int compareTo(point o) {
            

            if(o.x==x && o.y==y)
            return 0;
            else return (int)Math.max(x-o.x, y-o.y);
        }
        public int hashCode(){
            return (int)(x+y);
            
        }
        public boolean equals(Object z){
            if(z!=null){
                point o=(point)z;
                if(o.x==x && o.y==y)
                    return true;
            }
            return false;
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

    class id7 {

          
          public  List<Edge>[] createGraph(int nodes) {
            List<Edge>[] graph = new List[nodes];
            for (int i = 0; i < nodes; i++)
              graph[i] = new ArrayList<>();
            return graph;
          }

          public  void addEdge(List<Edge>[] graph, int s, int t, int cap) {
            graph[s].add(new Edge(t, graph[t].size(), cap));
            graph[t].add(new Edge(s, graph[s].size() - 1, 0));
          }

           boolean id4(List<Edge>[] graph, int src, int dest, int[] dist) {
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

           int id9(List<Edge>[] graph, int[] ptr, int[] dist, int dest, int u, int f) {
            if (u == dest)
              return f;
            for (; ptr[u] < graph[u].size(); ++ptr[u]) {
              Edge e = graph[u].get(ptr[u]);
              if (dist[e.t] == dist[u] + 1 && e.f < e.cap) {
                int df = id9(graph, ptr, dist, dest, e.t, Math.min(f, e.cap - e.f));
                if (df > 0) {
                  e.f += df;
                  graph[e.t].get(e.rev).f -= df;
                  return df;
                }
              }
            }
            return 0;
          }

          public  int maxFlow(List<Edge>[] graph, int src, int dest) {
            int flow = 0;
            int[] dist = new int[graph.length];
            while (id4(graph, src, dest, dist)) {
              int[] ptr = new int[graph.length];
              while (true) {
                int df = id9(graph, ptr, dist, dest, src, Integer.MAX_VALUE);
                if (df == 0)
                  break;
                flow += df;
              }
            }
            return flow;
          }
    }
        

      String path ="";
      int n,m;
      ArrayList<Integer> list[];
      int color[];
      long  N = 1200021;
    public void solve(int testNumber, FastScanner in, PrintWriter out) throws IOException {
    	int n =in.nextInt();
    	int k =in.nextInt();
    	int isP[] =new int[(int)N];
    	int cntP[] = new int[(int)N];
    	
    	for(int i = 2; i < N; i++)
    		if(isP[i]==0)
    			for(int j = i; j < N; j += i)
    				isP[j] = i;
    	
    	for(int i = 0; i < n; i++)
    	{
    		int x = in.nextInt();
    		while(x > 1)
    		{
    			int p = isP[x];
    			int cnt = 0;
    			while(x!=0 && x % p == 0)
    			{
    				cnt++;
    				x /= p;
    			}
    			cntP[p] = Math.max(cntP[p], cnt);
    		}
    	}
    	boolean ok = true;
    	while(k > 1)
    	{
    		ok &= (cntP[isP[k]] > 0);
    		cntP[isP[k]]--;
    		k /= isP[k];
    	}
    	out.println(ok?"YES":"NO");
    	
    }
    public long lcm(long x ,long y){
    	return  (((long)x *((long)y)) / id1(x, y)) ;
    }
    public boolean chek(int index , int parent){
    	boolean ans =true;
    	for(int x : list[index]){
    		if(x!=parent){
    			if(color[x]==0){
    				color[x] = (color[index]==1) ? 2:1;
    				ans &= chek(x,index);
    			}
    			else if(color[x]==color[index]){
    				return false;
    			 }
    		}
    	}
    	
    	return ans;
    }
    
    public void swap(int a[],int i,int j){
    	int tmp = a[i];
    	a[i]=a[j];
    	a[j]=tmp;
    }
    
    public long[] fun(long n,int k,int a){
        long arr[]=new long[k];
        for(int i=0;i<k;i++){
            
            arr[(int)(pow(i, a, k)%k)]+=((n/k)%mod+ ((i!=0  &&  i<=n%k)? 1: 0))%mod;
        }
        return arr;
    }
         
     
     public long getAns(int d[],int n){
         if(d[0]<0 && d[n-1]>0){
             
             return Math.min(-2*d[0]+d[n-1], 2*d[n-1]-d[0]);
             
             
          }
          else{
              if(d[0]<0){
                     return d[0]*-1;
              }
              else{
                     return(d[n-1]*1);
              }
          }
         
        

     }
     public boolean isTriangle(int x,int y,int z){
         if(x+y>z && x+z>y && y+z>x){
             return true;
         }
         return false;
     }
     public long optimize(long x){
         long y=x;
         if(x%10<5){
             x=x-x%10;
            
         }
         else{
             x=x+(10-x%10);
         }
         return y-x;
     }
   public static long[][] matrixexpo(long m[][],String n,long mod){
       if(n.equals("1")){
           return m.clone();
       }
       if(n.equals("10")){
           return mulmatrix(m, m , mod);
       }
       else{
           long temp [][]=matrixexpo(m,n.substring(0,n.length()-1),mod);
           temp=mulmatrix(temp, temp, mod);
           if(n.charAt(n.length()-1)=='0')return temp;
           else return mulmatrix(temp, m,mod);
       }
   }
   
    public static long[] mul(long[] a, long[] b)
    {
        int n = Math.max(a.length, b.length);
        int h = Integer.highestOneBit(n);
        if(n > h)h *= 2;
        if(a.length < h)a = Arrays.copyOf(a, h);
        if(b.length < h)b = Arrays.copyOf(b, h);
        return mul2(a, b, 0, h, 0, h);
    }
    
    public static long[] mul2(long[] a, long[] b, int al, int ar, int bl, int br)
    {
        int n = ar-al;
        if((n&n-1) != 0)throw new RuntimeException();
        if(n <= 1<<6){
            long[] res = muln(a, b, al, ar, bl, br);
            return res;
        }
        
        long[] c0 = mul2(a, b, al+0, al+n/2, bl+0, bl+n/2);
        long[] c2 = mul2(a, b, al+n/2, al+n, bl+n/2, bl+n);
        
        long[] ab0 = new long[n/2];
        long[] ab1 = new long[n/2];
        for(int i = 0;i < n/2;i++){
            ab0[i] = a[al+i] + a[al+i+n/2];
            ab1[i] = b[bl+i] + b[bl+i+n/2];
            if(ab0[i] >= mod)ab0[i] -= mod;
            if(ab1[i] >= mod)ab1[i] -= mod;
        }
        
        int e = n+c2.length;
        long[] ret = new long[e];
        for(int i = 0;i < c0.length;i++){
            ret[i] += c0[i];
            if(ret[i] >= mod)ret[i] -= mod;
        }
        for(int i = 0;i < c2.length;i++){
            ret[i+n] += c2[i];
            if(ret[i+n] >= mod)ret[i+n] -= mod;
        }
        
        long[] c1 = mul2(ab0, ab1, 0, n/2, 0, n/2);
        for(int i = 0;i < c1.length;i++){
            c1[i] -= c0[i] + c2[i];
            if(c1[i] < 0)c1[i] += mod;
            if(c1[i] < 0)c1[i] += mod;
        }
        for(int i = 0;i < c1.length;i++){
            ret[i+n/2] += c1[i];
            if(ret[i+n/2] >= mod)ret[i+n/2] -= mod;
        }
        return ret;
    }
    
    public static long[] muln(long[] a, long[] b, int al, int ar, int bl, int br)
    {
        int n = ar - al;
        long[] ret = new long[2*n];
        for(int i = 0;i < 2*n;i++){
            long tot = 0;
            for(int j = Math.max(i-n+1, 0);j <= i && j < n;j++){
                tot += a[al+j] * b[bl+i-j];
            }
            ret[i] = tot % mod;
        }
        return ret;
    }
    
   public static long[][] mulmatrix(long m1[][],long m2[][],long mod){
       long ans[][]=new long[m1.length][m2[0].length];
       for(int i=0;i<m1.length;i++){
           for(int j=0;j<m2[0].length;j++){
               for(int k=0;k<m1.length;k++){
                   ans[i][j]+=(m1[i][k]*m2[k][j]);
                   ans[i][j]%=mod;
               }
           }
       }
       return ans;
   }
   long pow(long x,long y,long mod){
       if(y<=0){
           return 1;
       }
       if(y==1){
           return x%mod;
       }
       long temp=pow(x,y/2,mod);
       if(y%2==0){
           return (temp*temp)%mod;
       }
       else{
           return (((temp*temp)%mod)*x)%mod;
       }
   }    
        
   
    

   static long id1 (long m, long n){
       long x;
       long y;
       while(m%n != 0){
           x = n;
           y = m%n;
           m = x;
           n = y;
       }
       return n;
   }
   static void dfs(List<Integer>[] graph, boolean[] used, List<Integer> res, int u,int parent,List<Integer> collection) {
       
       used[u] = true;
       Integer uu=new Integer(u);
       collection.add(uu);
       for (int v : graph[u]){
         if (!used[v]){
           dfs(graph, used, res, v,u,collection);
           
         }
         else if(collection.contains(v)){
             System.out.println("Impossible");
             System.exit(0);
         }
       }
       collection.remove(uu);
       res.add(u);
     }
   
       
     public static List<Integer> id3(List<Integer>[] graph) {
       int n = graph.length;
       boolean[] used = new boolean[n];
       List<Integer> res = new ArrayList<>();
       for (int i = 0; i < n; i++)
         if (!used[i])
           dfs(graph, used, res, i,-1,new ArrayList<Integer>());
       Collections.reverse(res);
       return res;
     }     
     
 }
    





     
 
    class id6 {

          int len;
          int[][] up;
          int[][] max;
          int[] tin;
          int[] tout;
          int time;
          int []lvel;
          
          void dfs(List<Integer>[] tree, int u, int p) {
            tin[u] = time++;
            lvel[u]=lvel[p]+1;
            up[0][u] = p;
            if(u!=p)
            

            for (int i = 1; i < len; i++)
              {
                up[i][u] = up[i - 1][up[i - 1][u]];
                max[i][u]=Math.max(max[i-1][u],max[i-1][up[i-1][u]]);
              }
            for (int v : tree[u])
              if (v != p)
                dfs(tree, v, u);
            tout[u] = time++;
          }

          public id6(List<Integer>[] tree, int root) {
            int n = tree.length;
            len = 1;
            while ((1 << len) <= n) ++len;
            up = new int[len][n];
            max=new int[len][n];
            tin = new int[n];
            tout = new int[n];
            lvel=new int[n];
            lvel[root]=0;
            dfs(tree, root, root);
          }

          boolean isParent(int parent, int child) {
            return tin[parent] <= tin[child] && tout[child] <= tout[parent];
          }

          public int lca(int a, int b) {
            if (isParent(a, b))
              return a;
            if (isParent(b, a))
              return b;
            for (int i = len - 1; i >= 0; i--)
              if (!isParent(up[i][a], b))
                a = up[i][a];
            return up[0][a];
          }
          public long max(int a,int b){
              int lca=lca(a,b);
        

              long ans=0;
              int h=lvel[a]-lvel[lca];
            

              int index=0;
              while(h!=0){
                  if(h%2==1){
                      ans=Math.max(ans,max[index][a]);
                      a=up[index][a];
                  }
                  h/=2;
                  index++;
              }
              h=lvel[b]-lvel[lca];
             

              
              index=0;
              while(h!=0){
                  if(h%2==1){
                      ans=Math.max(ans,max[index][b]);
                      b=up[index][b];
                  }
                  h/=2;
                  index++;
              }
              return ans;
          }
          
    
        
            static void dfs1(List<Integer>[] graph, boolean[] used, List<Integer> res, int u) {
            used[u] = true;
            for (int v : graph[u])
              if (!used[v])
                dfs1(graph, used, res, v);
            res.add(u);
          }

        
        int phi(int n) {
            int res = n;
            for (int i = 2; i * i <= n; ++i) {
                if (n % i == 0) {
                    while (n % i == 0) {
                        n /= i;
                    }
                    res -= res / i;
                }
            }
            if (n != 1) {
                res -= res / n;
            }
            return res;
        }
        
        
        
        public static long[][] mulmatrix(long m1[][],long m2[][],long mod){
            long ans[][]=new long[m1.length][m2[0].length];
            for(int i=0;i<m1.length;i++){
                for(int j=0;j<m2[0].length;j++){
                    for(int k=0;k<m1.length;k++){
                        ans[i][j]+=(m1[i][k]*m2[k][j]);
                        ans[i][j]%=mod;
                    }
                }
            }
            return ans;
        }
        public static long[][] matrixexpo(long m[][],String n,long mod){
            if(n.equals("1")){
                return m.clone();
            }
            if(n.equals("10")){
                return mulmatrix(m, m , mod);
            }
            else{
                long temp [][]=matrixexpo(m,n.substring(0,n.length()-1),mod);
                temp=mulmatrix(temp, temp, mod);
                if(n.charAt(n.length()-1)=='0')return temp;
                else return mulmatrix(temp, m,mod);
            }
        }
        public static boolean isCompatible(long x[],long y[]){
            
            for(int i=0;i<x.length-1;i++){
                if(x[i]==y[i] && x[i+1]==y[i+1] && x[i]==x[i+1] && y[i]==y[i+1]){
                    return false;
                }
            }
            return true;
        }
        
        
        long pow(long x,long y,long mod){
            if(y<=0){
                return 1;
            }
            if(y==1){
                return x%mod;
            }
            long temp=pow(x,y/2,mod);
            if(y%2==0){
                return (temp*temp)%mod;
            }
            else{
                return (((temp*temp)%mod)*x)%mod;
            }
        }
     
        
                long id5(long m,long n,long k){
                    long count=0,i,j;
                    int primes []=new int[(int)(n-m+2)];
                       if(m==1)    primes[0] = 1;
                        for(i=2; i<=Math.sqrt(n); i++)
                        {
                            j = (m/i);    j *= i;
                            if(j<m)
                                j+=i;
                            for(; j<=n; j+=i)
                             {
                                 if(j!=i)
                                    primes[(int)(j-m)] = 1;
                             }
                        }

                for(i=0; i<=n-m; i++)
                            if(primes[(int)i]==0 && (i-1)%k==0)
                                count++;
                return count;
                }
                
}
    
class SegTree {
    int n;
    static long constt=Long.parseLong("111111111111111111111111111111",2);
    long  t[];
    long mod=(long)(1000000007);
    SegTree(int n,long  t[]){
        this.n=n;
        this.t=t;
        build();
    }
    
    void build() {  

        
        for (int i = n - 1; i >= 0; --i){
            t[i]=(t[i<<1]&t[i<<1|1]);
          }
    }

     void modify(int p, long value) {  

      for (t[p += n]=value; p > 1; p >>= 1) t[p>>1] = (t[p]&t[p^1]);
    

     }

     long query(int l, int r) {  

         long res=constt;
         
         for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
               if ((l&1)!=0) res=res&t[l++];
               if ((r&1)!=0) res=res&t[--r];
             }
         return res;
      
      
     }

    
    





}
class FastScanner
{

    private InputStream stream;
    private byte[] buf = new byte[8192];
    private int curChar;
    private int id2;
    private id8 filter;

    public FastScanner(InputStream stream) {
        this.stream = stream;
    }
    
    public int snext() {
        if (id2 == -1)
            throw new InputMismatchException();
        if (curChar >= id2) {
            curChar = 0;
            try {
                id2 = stream.read(buf);
            } catch (IOException e) {
                throw new InputMismatchException();
            }
            if (id2 <= 0)
                return -1;
        }
        return buf[curChar++];
    }
    public int nextInt() {
        int c = snext();
        while (id0(c))
            c = snext();
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = snext();
        }

        int res = 0;

        do {
            if (c < '0' || c > '9')
                throw new InputMismatchException();
            res *= 10;
            res += c - '0';
            c = snext();
        } while (!id0(c));

        return res * sgn;
    }
    
    public long nextLong() {
        int c = snext();
        while (id0(c))
            c = snext();
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = snext();
        }

        long res = 0;

        do {
            if (c < '0' || c > '9')
                throw new InputMismatchException();
            res *= 10;
            res += c - '0';
            c = snext();
        } while (!id0(c));

        return res * sgn;
    }
    
    public String readString() {
        int c = snext();
        while (id0(c))
            c = snext();
        StringBuilder res = new StringBuilder();
        do {
            res.appendCodePoint(c);
            c = snext();
        } while (!id0(c));
        return res.toString();
    }

    public boolean id0(int c) {
        if (filter != null)
            return filter.id0(c);
        return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }

    public interface id8 {
        public boolean id0(int ch);
    }
}
 class UF {

    private int[] parent;  

    private byte[] rank;   

    private int count;     

    public UF(int N) {
        if (N < 0) throw new IllegalArgumentException();
        count = N;
        parent = new int[N];
        rank = new byte[N];
        for (int i = 0; i < N; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    public int find(int p) {
        if (p < 0 || p >= parent.length) throw new IndexOutOfBoundsException();
        while (p != parent[p]) {
            parent[p] = parent[parent[p]];    

            p = parent[p];
        }
        return p;
    }
    public int count() {
        return count;
    }

    public boolean connected(int p, int q) {
        return find(p) == find(q);
    }

    public boolean union(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);
        if (rootP == rootQ) return false;

        

        if      (rank[rootP] < rank[rootQ]) parent[rootP] = rootQ;
        else if (rank[rootP] > rank[rootQ]) parent[rootQ] = rootP;
        else {
            parent[rootQ] = rootP;
            rank[rootP]++;
        }
        count--;
        return true;
    }
    



}
 class MyScanner {
       BufferedReader br;
       StringTokenizer st;
      
       public MyScanner() {
          br = new BufferedReader(new InputStreamReader(System.in));
       }
      
       String next() {
          while (st == null || !st.hasMoreElements()) {
             try {
                st = new StringTokenizer(br.readLine());
             } catch (IOException e) {
                e.printStackTrace();
             }
          }
          return st.nextToken();
       }
      
       int nextInt() {
          return Integer.parseInt(next());
       }
      
       long nextLong() {
          return Long.parseLong(next());
       }
      
       double nextDouble() {
          return Double.parseDouble(next());
       }
      
       String nextLine(){
          String str = "";
          try {
             str = br.readLine();
          } catch (IOException e) {
             e.printStackTrace();
          }
          return str;
       }
    
    }