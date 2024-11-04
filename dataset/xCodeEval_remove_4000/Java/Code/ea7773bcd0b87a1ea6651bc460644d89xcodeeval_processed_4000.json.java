import java.awt.Point;
import java.awt.geom.Line2D;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileReader;
import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.security.GuardedObject;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.InputMismatchException;
import java.util.LinkedList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Scanner;
import java.util.Stack;
import java.util.StringTokenizer;
import java.util.TreeMap;
import java.util.TreeSet;
import java.io.InputStream;
import java.math.BigInteger;












public class Main {
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
    Pair(long x,long y,int index){
        this.x=x;
        this.y=y;
        this.index=index;
    }
    public String toString(){
        return this.x+" "+this.y+" ";
    }
    
}
class id3{
    long x,y,z;
    ArrayList<String> list=new ArrayList<>();
    id3(long x,long y,long z){
        this.x=x;
        this.y=y;
        this.z=z;
    }
    id3(id3 cl){
        this.x=cl.x;
        this.y=cl.y;
        this.z=cl.z;
        this.list=cl.list;
    }
}
class Edge implements  Comparable<Edge>{
    int u;
    int v;
    int time;
    long cost;
    public Edge(int u,int v){
        this.u=u;
        this.v=v;
        time=Integer.MAX_VALUE;
    }
    public int other(int x){
        if(u==x)return v;
        return u;
    }
    @Override
    public int compareTo(Edge o) {
        

        return(int) (cost-o.cost);
    }
}
class Ss{
    Integer a[]=new Integer[3];
    Ss(Integer a[]){
        this.a=a;
        
    }
    public int hashCode(){
        return a[0].hashCode()+a[1].hashCode()+a[2].hashCode();
    }
    public boolean equals(Object o){
        Ss x=(Ss)o;
        for(int i=0;i<3;i++){
            if(x.a[i]!=this.a[i]){
                return false;
            }
        }
        return true;
        
    }
}
class queary{
    int type;
    int l;
    int r;
    int index;
    queary(int type,int l,int r){
        this.type=type;
        this.l=l;
        this.r=r;
    }
}
class boat implements Comparable<boat>{
    int capacity;
    int index;
    boat(int capacity,int index)
    {
        this.capacity=capacity;
        this.index=index;
    }
    @Override
    public int compareTo(boat o) {
        

        return this.capacity-o.capacity;
    }
}
class angle{
    double x,y,angle;
    int index;
    angle(int x,int y,double angle){
        this.x=x;
        this.y=y;
        this.angle=angle;
    }
}
class TaskC {
    static long mod=1000000007;


    

    
    public void solve(int testNumber, FastScanner in, PrintWriter out) throws IOException {
        int n=in.nextInt();
        int m=in.nextInt();
        boolean f[]=new boolean[m+1];
        for(int i=0;i<n;i++){
            int x=in.nextInt();
            for(int j=0;j<x;j++)
            f[in.nextInt()]=true;
        }
        for(int i=1;i<=m;i++){
            if(!f[i]){
                out.println("NO");
                return;
            }
        }
        out.println("YES");
    }
    
    class Node{
        int parent;
        int index;
        ArrayList<Integer> children;
        Node(int parent){
            this.parent=parent;
            children=new ArrayList<>();
        }
    }
    public class id9 {
          public  long max(int[][] t, int x1, int y1, int x2, int y2) {
            int n = t.length >> 1;
            x1 += n;
            x2 += n;
            int m = t[0].length >> 1;
            y1 += m;
            y2 += m;
            long res = 0;
            for (int lx = x1, rx = x2; lx <= rx; lx = (lx + 1) >> 1, rx = (rx - 1) >> 1)
              for (int ly = y1, ry = y2; ly <= ry; ly = (ly + 1) >> 1, ry = (ry - 1) >> 1) {
                if ((lx & 1) != 0 && (ly & 1) != 0) res = (res+ t[lx][ly]);
                if ((lx & 1) != 0 && (ry & 1) == 0) res = (res+ t[lx][ry]);
                if ((rx & 1) == 0 && (ly & 1) != 0) res =(res+t[rx][ly]);
                if ((rx & 1) == 0 && (ry & 1) == 0) res = (res+ t[rx][ry]);
              }
            return res;
          }

          public  void add(int[][] t, int x, int y, int value) {
            x += t.length >> 1;
            y += t[0].length >> 1;
            t[x][y] += value;
            for (int tx = x; tx > 0; tx >>= 1)
              for (int ty = y; ty > 0; ty >>= 1) {
                if (tx > 1) t[tx >> 1][ty] = (t[tx][ty]+t[tx ^ 1][ty]);
                if (ty > 1) t[tx][ty >> 1] = (t[tx][ty]+ t[tx][ty ^ 1]);
              }
























          }
    }
    class id7 {

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

          public id7(List<Integer>[] tree, int root) {
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
        
      public static List<Integer> id5(List<Integer>[] graph) {
        int n = graph.length;
        boolean[] used = new boolean[n];
        List<Integer> res = new ArrayList<>();
        for (int i = 0; i < n; i++)
          if (!used[i])
            dfs(graph, used, res, i,-1,new ArrayList<Integer>());
        Collections.reverse(res);
        return res;
      }     
    
    static class pairs{
                String company,color;
                String type;
                boolean visit=false;
                pairs(String company,String color,String type){
                    this.company=company;
                    this.color=color;
                    this.type=type;
                }
            }
        BigInteger BMOD=BigInteger.valueOf(mod);
        private long inv(long q) {
            return BigInteger.valueOf(q).modInverse(BMOD).longValue();
        }

            static void dfs1(List<Integer>[] graph, boolean[] used, List<Integer> res, int u) {
            used[u] = true;
            for (int v : graph[u])
              if (!used[v])
                dfs1(graph, used, res, v);
            res.add(u);
          }

          public static List<Integer> id1(List<Integer>[] graph) {
            int n = graph.length;
            boolean[] used = new boolean[n];
            List<Integer> res = new ArrayList<>();
            for (int i = n-1; i >0; i--)
              if (!used[i])
                dfs1(graph, used, res, i);
            Collections.reverse(res);
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
        

            static long id2 (long m, long n){
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
                long id6(long m,long n,long k){
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
    long  t[];
    long mod=(long)(1000000007);
    SegTree(int n,long  t[]){
        this.n=n;
        this.t=t;
        build();
    }
    
    void build() {  

        
        for (int i = n - 1; i > 0; --i)
            t[i]=(t[i<<1]+t[i<<1|1]);
    }

     void modify(int p, long value) {  

      for (t[p += n]+=value; p > 1; p >>= 1) t[p>>1] = (t[p]+t[p^1]);
    }

     long query(int l, int r) {  

      long res=0;
              
      for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if ((l&1)!=0) res=(res+t[l++]);
            if ((r&1)!=0) res=(res+t[--r]);
          }
      return res;
    }

    
    





}
class FastScanner
{

    private InputStream stream;
    private byte[] buf = new byte[8192];
    private int curChar;
    private int id4;
    private id8 filter;

    public FastScanner(InputStream stream) {
        this.stream = stream;
    }
    
    public int snext() {
        if (id4 == -1)
            throw new InputMismatchException();
        if (curChar >= id4) {
            curChar = 0;
            try {
                id4 = stream.read(buf);
            } catch (IOException e) {
                throw new InputMismatchException();
            }
            if (id4 <= 0)
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