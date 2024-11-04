import java.util.*;
import java.io.*;
import java.io.FileWriter; 
import java.math.BigInteger;
import java.math.BigDecimal;


 
public class Main 
{    
  public static void main (String[] argv) 
  {
	  new Main();
  } 
     
  
  boolean test = false;  
  final int[][] dirs8 = {{0,1}, {0,-1}, {-1,0}, {1,0}, {1,1},{1,-1},{-1,1},{-1,-1}};
  final int[][] dirs4 = {{0,1}, {0,-1}, {-1,0}, {1,0}};
  final int MOD = 1000000007;  

 
  
  
  
  int[] fac;
  int[] ifac;
  int[] rfac;
  
  int[] pow2;
  
  int[] mobius;
  int[] sieve;
  int[][] factors;

  int N = 100000000;
  
  int[][] nbs;
  int n;
  
  int maxCnt;
  int x, y, z;
  int[] leaf1;
  int[][] leaf2;
  int[] len1;
  int[] len2;
  final int NONE = -1;
  int[] deg;
  
  public Main()  {
	FastReader in = new FastReader(new BufferedReader(new InputStreamReader(System.in)));
	
     
    

    
    

    int nt = 1;
    StringBuilder sb = new StringBuilder();
    
    
    for (int iq = 0; iq < nt; iq++)
    {        
       n = in.nextInt();
       int[][] edges = new int[n-1][2];
       for (int i = 0; i < n - 1; i++)
       {
           int p = in.nextInt();
           int q = in.nextInt();
           edges[i][0] = p;
           edges[i][1] = q;
       }
       
       id7 tr = new id7(n, edges);
       nbs = tr.nbs;
       deg = tr.deg;
       
       int root = -1;
       for (int i = 1; i <= n; i++)
       {
           if (deg[i] > 1) {
               root = i;
               break;
           }
       }
       x = 0;
       y = 0;
       z = 0;
       maxCnt = 0;
       
       leaf1 = new int[n+1];
       leaf2 = new int[n+1][2];
       len1 = new int[n+1];
       len2 = new int[n+1];


       
       dfs(root, 0);
       sb.append(maxCnt+"\n");
       sb.append(x + " " + y + " " + z +"\n");
    }
    System.out.print(sb);
    
  }
  
  private void dfs(int node, int par)
  {
      int nchild = par == 0 ? deg[node] : deg[node] - 1;
      
      if (nchild == 0)
      {
          

          leaf1[node] = node;
          leaf2[node][0] = -1;
          leaf2[node][1] = -1;
          len1[node] = 0;
          len2[node] = -1;
          return;
      }
      
      

      int r1 = -1, r2 = -1, r3 = -1;
      int c1 = 0, c2 = 0, c3 = 0;
      int id11 = -1;
      int id8 = 0;
      for (int next : nbs[node])
      {
          if (next == par) continue;
          
          dfs(next, node);
          
          if (len2[next] > id11)
          {
              id11 = len2[next];
              id8 = next;
          }
          
          if (len1[next] >= r1)
          {
              r3 = r2;
              r2 = r1;
              r1 = len1[next];
              
              c3 = c2;
              c2 = c1;
              c1 = next;
          }else if (len1[next] >= r2)
          {
              r3 = r2;
              r2 = len1[next];
              
              c3 = c2;
              c2 = next;
          }else if (len1[next] > r3)
          {
              r3 = len1[next];
              c3 = next;
          }
      }
      
      

      len1[node] = r1 + 1;
      leaf1[node] = leaf1[c1];
      
      

      

      if (nchild == 1 && id11 < 0)
      {
          

          len2[node] = 1;
          leaf2[node][0] = node;
          leaf2[node][1] = c1;
          
          return;
          
      }else if (nchild == 1 && id11 >= 0)
      {
          len2[node] = id11 + 1;
          leaf2[node][0] = leaf2[id8][0];
          leaf2[node][1] = leaf2[id8][1];
          return;
          
      }else if (id11 < 0) {
          len2[node] = 2;
          leaf2[node][0] = leaf1[c1];
          leaf2[node][1] = leaf1[c2];
          if (2 > maxCnt)
          {
              maxCnt = 2;
              x = leaf1[c1];
              y = leaf1[c2];
              z = node;


          }
          
          if (maxCnt < 3 && nchild >= 3){
              maxCnt = 3;
              x = leaf1[c1];
              y = leaf1[c2];
              z = leaf1[c3];              
          }
          return;          
      }else
      {
          int op1 = r1 + r2 + 2;
          int op2 = 1 + id11;
          if (op1 >= op2)
          {
              len2[node] = op1;
              leaf2[node][0] = leaf1[c1];
              leaf2[node][1] = leaf1[c2];
          }else {
              len2[node] = id11 + 1;
              leaf2[node][0] = leaf2[id8][0];
              leaf2[node][1] = leaf2[id8][1];              
          }
          
          

          for (int next : nbs[node])
          {
              if (next == par) continue;
              
              int id16 = len2[next];
              int id3 = len1[next];
              
              
              if (id3 == r1)
              {
                  

                  int op = id16 + r2 + 2;
                  if (op > maxCnt)
                  {
                      maxCnt = op;
                      x = leaf2[next][0];
                      y = leaf2[next][1];
                      if (next == c1) z = leaf1[c2];
                      else            z = leaf1[c1];


                  }              
              }else {
                  int op = id16 + r1 + 2;
                  if (op > maxCnt)
                  {
                      maxCnt = op;
                      x = leaf2[next][0];
                      y = leaf2[next][1];
                      z = leaf1[c1];
                  }
              }          
          }
          
          

          if (nchild >= 3 && r1 + r2 + r3 + 3 > maxCnt)
          {
              maxCnt = r1 + r2 + r3 + 3;
              x = leaf1[c1];
              y = leaf1[c2];
              z = leaf1[c3];


          }
      }
  }
  
  
  

  class id7 {
      int n;
      int[][] edges;
      int[] deg;
      int[][] nbs;
      
      public id7(int n, int[][] edges)
      {
          this.n = n;
          this.edges = edges;
          deg = new int[n+1];
          nbs = new int[n+1][];
          
          for (int[] edge : edges)
          {
              int p = edge[0], q = edge[1];
              deg[p]++;
              deg[q]++;
          }
          
          for (int i = 1; i <= n; i++) {
             nbs[i] = new int[deg[i]];
             deg[i] = 0;
          }
          
          for (int[] edge : edges)
          {
              int p = edge[0], q = edge[1];
              nbs[p][deg[p]++] = q;
              nbs[q][deg[q]++] = p;
          }
      }
  }
  
  private long dist(long x0, long y0, long x1, long y1)
  {
      return abs(y0 - y1) + abs(x0 - x1);
  }
  
  class Point {
      long x, y;
      public Point(long x, long y)
      {
          this.x = x;
          this.y = y;
      }
  }

  
  class Edge{
      int p, q;
      boolean used;
      public Edge(int pp, int qq)
      {
          p = pp;
          q = qq;
          used = false;
      }      
  }
  
  class Node implements Comparable<Node>{
      int id;
      long gain;
      public Node(int id, long gain)
      {
          this.id = id;
          this.gain = gain;
      }
      
      @Override
      public int compareTo(Node o){
          return Long.compare(gain, o.gain);
      }
  }
  
  private long[][] matIdentity(int n)
  {
      long[][] a = new long[n][n];
      for (int i = 0; i < n; i++)
          a[i][i] = 1;
      return a;
  }
  private long[][] matPow(long[][] mat0, long p)
  {
      int n = mat0.length;
      long[][] ans = matIdentity(n);
      long[][] mat = matCopy(mat0);
      while (p > 0)
      {
          if (p % 2 == 1){
              ans = matMul(ans, mat);
          }
          
          p /= 2;
          mat = matMul(mat, mat);
      }
      return ans;
  }
  
  private long[][] matCopy(long[][] a)
  {
      int n = a.length;
      long[][] b = new long[n][n];
      for (int i = 0; i < n; i++)
          for (int j = 0; j < n; j++)
              b[i][j] = a[i][j];
      return b;
  }
  private long[][] matMul(long[][] a, long[][] b)
  {
      int n = a.length;
      
      long[][] c = new long[n][n];
      for (int i = 0; i < n; i++)
      {
          for (int j = 0; j < n; j++)
          {
              for (int k = 0; k < n; k++)
                  c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % MOD;
          }
      }
      
      return c;
  }
  
  private long[] matMul(long[][] a, long[] b)
  {
      int n = a.length;
      
      long[] c = new long[n];
      for (int i = 0; i < n; i++)
      {
          for (int j = 0; j < n; j++)
              c[i] = (c[i] + a[i][j] * b[j]) % MOD;
      }
      
      return c;
  }
  
  class Mark implements Comparable<Mark> {
      int type, h;
      long x;
      public Mark(int h, long x, int type)
      {
         this.h = h;
         this.x = x;
         this.type = type;
      }      
      
      @Override
      public int compareTo(Mark o)
      {
          if (this.x == o.x) return type - o.type; 

          return Long.compare(x, o.x); 
      }
  }
  
  private boolean coLinear(int[] p, int[] q, int[] r)
  {
      return 1L * (p[1] - r[1]) * (q[0] - r[0]) == 1L * (q[1] - r[1]) * (p[0] - r[0]);
  }
  
  
  private void fill(char[] a, int lo, int c, char letter)
  {
      

      for (int i = lo; i < lo + c; i++) a[i] = letter;
  }
  
  
  
  private int id15(String s){
      int c = 0, n = s.length();
      for (int i = 0; i < n; i++) 
          if (s.charAt(i) == '1') c++;
      return c;
  }
  
  class DSU {
      int n;
      int[] par;
      int[] sz;
      int nGroup;
      
      public DSU(int n)
      {
          this.n = n;
          par = new int[n];
          sz = new int[n];
          for (int i = 0;  i < n; i++){
              par[i] = i;
              sz[i] = 1;
          }
          nGroup = n;          
      }
      
      private boolean add(int p, int q) {
          int rp = find(p);
          int rq = find(q);
          if (rq == rp) return false;
          
          if (sz[rp] <= sz[rq]) {
              sz[rq] += sz[rp];
              par[rp] = rq;
          }else {
              sz[rp] += sz[rq];
              par[rq] = rp;
          }
          nGroup--;
          return true;
      }
      
      private int find(int p)
      {
          int r = p;
          while (par[r] != r) r = par[r];
          
          while (r != p) {
              int t = par[p];
              par[p] = r;
              p = t;
          }
          return r;
      }
      
  }
  
  
  

  

  

  private void id10(int n)
  {
      pow2 = new int[n+1];
       pow2[0] = 1;
       for (int i = 1; i <= n; i++) pow2[i] = (int)(1L * pow2[i-1] * 2 % MOD);
  }
  
  private void id1(int n)
  {
      fac = new int[n+1];
      fac[0] = 1;
      for (int i = 1; i <= n; i++)
          fac[i] = (int)(1L * fac[i-1] * i % MOD);
  }
  
  private void id12(int n)
  {
      ifac = new int[n+1];
      ifac[0] = 1;
      for (int i = 1; i <= n; i++)
          ifac[i] = (int)(1L * ifac[i-1] * inv(i) % MOD);
  }
  
  private void id4(int n)
  {
      sieve = new int[n+1];
      for (int i = 2; i <= n; i++)
        sieve[i] = i;
      for (int i = 2; i <= n; i++) 
      {
        if (sieve[i] == i){
            for (long j = 1L * i * i; j <= n; j += i)
                sieve[(int)j] = i;
        }
      }
  }
  
  private void id5(int n)
  {
      mobius = new int[n+1];
      sieve = new int[n+1];
      factors = new int[n+1][];
      

      for (int i = 2; i <= n; i++)
        sieve[i] = i;
      for (int i = 2; i <= n; i++) 
      {
        if (sieve[i] == i){
            mobius[i] = -1;
            for (long j = 1L * i * i; j <= n; j += i)
                sieve[(int)j] = i;
        }
      }
      
      for (int i = 6; i <= n; i++)
      {
          if (sieve[i] != i) {
              int pre = i / sieve[i];
              if (pre % sieve[i] != 0)
                  mobius[i] = -mobius[pre];
          }
      }
      int[] sz = new int[n+1];
      long tot = 0;
      for (int i = 2; i <= n; i++) 
      {
          if (mobius[i] != 0)
          {
              for (int j = i * 2; j <= n; j += i) {                  
                  sz[j]++;
                  tot++;
              }                  
          }
      }
      for (int i = 2; i <= n; i++) {
          factors[i] = new int[sz[i]];
          sz[i] = 0;
      }
      
      
      for (int i = 2; i <= n; i++) 
      {
          if (mobius[i] != 0)
          {
              for (int j = i * 2; j <= n; j += i) {
                  factors[j][sz[j]++] = i;
                  

              }                  
          }
      }
      

  }
  
  private int[] id13(String s)
  {
      int n = s.length();
      int[] zfun = new int[n];
      
      int l = -1, r = -1;
      for (int i = 1; i < n; i++)
      {
         

         if (i <= r)
            zfun[i] = Math.min(zfun[i-l], r - i + 1);
         
         while (i + zfun[i] < n && s.charAt(i + zfun[i]) == s.charAt(zfun[i])) 
             zfun[i]++;             
         
         if (i + zfun[i] - 1> r){
             l = i;
             r = i + zfun[i] - 1;
         }
      }
      
      if (test)
      {
          System.out.println("Z-function of " + s);
          for (int i = 0; i < n; i++) System.out.print(zfun[i] + " ");
          System.out.println();
      }
      return zfun;
  }
  
  class BIT {
      int[] bit;
      int n;
      
      public BIT(int n){
          this.n = n;
          bit = new int[n+1];
      }
      
      private int query(int p)
      {
          int sum = 0;
          for (; p > 0; p -= (p & (-p)))
             sum += bit[p];
      
          return sum;
      }
  
      private void add(int p, int val)
      {
         

         for (; p <= n; p += (p & (-p)))
            bit[p] += val;
      }
  
  
  }
  
  
  
  private List<Integer> id17(int sum)
  {
      List<Integer>  factors = new ArrayList<>();
      
               for (int sz = 2; sz <= sum / sz; sz++){
                   if (sum % sz == 0) {
                       factors.add(sz);
                       factors.add(sum / sz);
                   }
               }
               if (factors.size() == 0)
                   factors.add(sum);
          
      return factors;
  }
  
  
  class Tree {
      int V = 0;
      int root = 0;
      List<Integer>[] nbs;
      int[][] timeRange;
      int[] id2;
      int t;
      boolean dump = false;
      
      public Tree(int V, int root)
      {
          if (dump) 
              System.out.println("build tree with size = " + V + ", root = " + root); 
          
          this.V = V;          
          this.root = root;
          nbs = new List[V];
          id2 = new int[V];
          for (int i = 0; i < V; i++)
              nbs[i] = new ArrayList<>();
          
              
      }
      
      public void doneInput()
      {
          dfsEuler();
      }
      
      public void addEdge(int p, int q)
      {
          nbs[p].add(q);
          nbs[q].add(p);
      }
      
      private void dfsEuler()
      {
          timeRange = new int[V][2];          
          t = 1;
          dfs(root);           
      }
      
      private void dfs(int node)
      {
          if (dump)
              System.out.println("dfs on node " + node + ", at time " + t);
          timeRange[node][0] = t;
          
          for (int next : nbs[node]) {
              if (timeRange[next][0] == 0)
              {
                  ++t;
                  dfs(next);                  
              }
          }
          timeRange[node][1] = t;
          id2[node] = t - timeRange[node][0] + 1;
      }
      
      public List<Integer> getNeighbors(int p) {
          return nbs[p];
      }
      
      public int[] id6(){
          return id2;
      }
      
      public int[][] id18()
      {
          if (dump){
              for (int i = 0; i < V; i++){
                  System.out.println(i + ": " + timeRange[i][0] + " - " + timeRange[i][1]);
              }
          }
          return timeRange;
      }
      
  }
  
  
  class SegTree {
      int[] a;
      int[] tree;
      int[] treeMin;
      int[] treeMax;
      int[] lazy;
      int n;
      boolean dump = false;
      
      public SegTree(int n)
      {
          if (dump)
              System.out.println("create segTree with size " + n);
          this.n = n;
          treeMin = new int[n*4];
          treeMax = new int[n*4];
          lazy = new int[n*4];
      }
      
      public SegTree(int n, int[] a) {
          this(n);
          this.a = a;
          buildTree(1, 0, n-1);          
      }
      
      private void buildTree(int node, int lo, int hi)
      {
          if (lo == hi) {
              tree[node] = lo;
              return;
          }
          
          int m = (lo + hi) / 2;
          buildTree(node * 2, lo, m);
          buildTree(node * 2 + 1, m + 1, hi);
          pushUp(node, lo, hi);
      }
      
      
      private void pushUp(int node, int lo, int hi)
      {
          if (lo >= hi) return;
          
          

          
          

          treeMin[node] = Math.min(treeMin[node * 2] + lazy[node * 2], treeMin[node * 2 + 1] + lazy[node * 2 + 1]);
          treeMax[node] = Math.max(treeMax[node * 2] + lazy[node * 2], treeMax[node * 2 + 1] + lazy[node * 2 + 1]);
          

      }
      
      private void pushDown(int node, int lo, int hi)
      {
          if (lazy[node] == 0) return;
          
          int lz = lazy[node];
          lazy[node] = 0;          
          
          
          treeMin[node] += lz;
          treeMax[node] += lz;     
          
          if (lo == hi) return;
          
          int mid = (lo + hi) / 2;
          lazy[node * 2] += lz;
          lazy[node * 2 + 1] += lz;
      }
      
      public int id14(int fr, int to)
      {
          return id14(1, 0, n-1, fr, to);
      }
      
      public int id14(int node, int lo, int hi, int fr, int to)
      {
          if (lo == fr && hi == to)
              return treeMax[node] + lazy[node];
          
          int mid = (lo + hi) / 2;
          pushDown(node, lo, hi);
          
          if (to <= mid) {
              return id14(node * 2, lo, mid, fr, to);
          }else if (fr > mid)
              return id14(node * 2 + 1, mid + 1, hi, fr, to);
          else {
              return Math.max(id14(node * 2, lo, mid, fr, mid),
                              id14(node * 2 + 1, mid + 1, hi, mid + 1, to));              
          }
      }
      
      public int id0(int fr, int to)
      {
          return id0(1, 0, n-1, fr, to);
      }
      
      public int id0(int node, int lo, int hi, int fr, int to)
      {
          if (lo == fr && hi == to)
              return treeMin[node] + lazy[node];
          
          int mid = (lo + hi) / 2;
          pushDown(node, lo, hi);
          
          if (to <= mid) {
              return id0(node * 2, lo, mid, fr, to);
          }else if (fr > mid)
              return id0(node * 2 + 1, mid + 1, hi, fr, to);
          else {
              return Math.min(id0(node * 2, lo, mid, fr, mid),
                              id0(node * 2 + 1, mid + 1, hi, mid + 1, to));              
          }
      }
      
       public void rangeUpdate(int fr, int to, int delta){
           rangeUpdate(1, 0, n-1, fr, to, delta);
       }
       
       
      public void rangeUpdate(int node, int lo, int hi, int fr, int to, int delta){
          pushDown(node, lo, hi);
          if (fr == lo && to == hi)
          {
              lazy[node] = delta;
              return;
          }
          
          int m = (lo + hi) / 2;
          if (to <= m) 
              rangeUpdate(node * 2, lo, m, fr, to, delta);
          else if (fr > m)
              rangeUpdate(node * 2 + 1, m + 1, hi, fr, to, delta);
          else  {
              rangeUpdate(node *  2, lo, m, fr, m, delta);
              rangeUpdate(node * 2 + 1, m + 1, hi, m + 1, to, delta);              
          }
          
          

          pushUp(node, lo, hi);
      }
      
      
      
      public int query(int node, int lo, int hi, int fr, int to)
      {
          if (fr == lo && to == hi)
              return tree[node];
          
          int m = (lo + hi) / 2;
          if (to <= m) 
              return  query(node * 2, lo, m, fr, to);
          else if (fr > m)
              return query(node * 2 + 1, m + 1, hi, fr, to);
          
          int lid = query(node * 2, lo, m, fr, m);
          int rid = query(node * 2 + 1, m + 1, hi, m + 1, to);
          return a[lid] >= a[rid] ? lid : rid;
      }
      
      
  }
  
  
  private long inv(long v)
  {
      return pow(v, MOD-2);
  }
  
  private long pow(long v, long p)
  {
      long ans = 1;
      while (p > 0)
      {
          if (p % 2 == 1)
              ans = ans * v % MOD;
          v = v * v % MOD;
          p = p / 2;
      }
      return ans;
  }
  
  private double dist(double x, double y, double xx, double yy)
  {
      return Math.sqrt((xx - x) * (xx - x) + (yy - y) * (yy - y));
  }
  
 
  
 
  private int mod_add(int a, int b) {
      int v = a + b;
      if (v >= MOD) v -= MOD;
      return v;
  }
  
  
  private long overlap(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
      if (x1 > x3) return overlap(x3, y3, x4, y4, x1, y1, x2, y2);
      
      if (x3 > x2 || y4 < y1 || y3 > y2) return 0L;
      
      

      int yL = Math.max(y1, y3);
      int yH = Math.min(y2, y4); 
      int xH = Math.min(x2, x4);
      
      return f(x3, yL, xH, yH);
  }
  

  private long f(int x1, int y1, int x2, int y2) {
      long dx = 1L + x2 - x1;
      long dy = 1L + y2 - y1;
      if (dx % 2 == 0 || dy % 2 == 0 || (x1 + y1) % 2 == 0) 
          return 1L * dx * dy / 2;
      return 1L * dx * dy / 2 + 1;
  }
  
  private int distM(int x, int y, int xx, int yy) {
      return abs(x - xx) + abs(y - yy);
  }
  
  private boolean less(int x, int y, int xx, int yy) {
      return x < xx || y > yy;
  }
  
  private int mul(int x, int y) {
      return (int)(1L * x * y % MOD);
  }
  
  
 
  
  private int id9(int v) {
      int v0 = v;
      int c = 0;
      while (v != 0) {
          ++c;
          v = v & (v - 1);
      }
      return c;
  }
  
  private long abs(long v) {
      return v > 0 ? v : -v;
  }
  
  private int abs(int v) {
      return v > 0 ? v : -v;
  }
  
  private int common(int v) {
      int c = 0;
      while (v != 1) {
          v = (v >>> 1);
          ++c;
      }
      
      return c;
  }
  
  private void reverse(char[] a, int i, int j) {
      while (i < j) {
          swap(a, i++, j--);
      }
  }
  
  private void swap(char[] a, int i, int j) {
      char t = a[i];
      a[i] = a[j];
      a[j] = t;
  }
  
  private int gcd(int x, int y) {
      if (y == 0) return x;
      return gcd(y, x % y);
  }
  private long gcd(long x, long y) {
      if (y == 0) return x;
      return gcd(y, x % y);
  }
  private int max(int a, int b) {
      return a >  b ? a : b;
  }
  
  private long max(long a, long b) {
      return a >  b ? a : b;
  }
  
  private int min(int a, int b) {
      return a >  b ? b : a;
  }
  
  private long min(long a, long b) {
      return a >  b ? b : a;
  }
  
  static class FastReader
    {
        BufferedReader br;
        StringTokenizer st;
 
        public FastReader(BufferedReader in)
        {            
            br = in;
        }
 
        String next()
        {
            while (st == null || !st.hasMoreElements())
            {
                try
                {
                    String line = br.readLine();
                    if (line == null || line.length() == 0) return "";
                    st = new StringTokenizer(line);
                }
                catch (IOException  e)
                {
                    return "";
                    

                }
            }
            return st.nextToken();
        }
 
        int nextInt()
        {
            return Integer.parseInt(next());
        }
 
        long nextLong()
        {
            return Long.parseLong(next());
        }
 
        double nextDouble()
        {
            return Double.parseDouble(next());
        }
 
        String nextLine()
        {
            String str = "";
            try
            {
                str = br.readLine();
            }
            catch (IOException e)
            {
                return null;
                

            }
            return str;
        }
    }
}