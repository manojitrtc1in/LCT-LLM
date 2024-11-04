import java.util.*;
import java.io.*;
import java.io.FileWriter; 
import java.math.BigInteger;




public class Main 
{    
  public static void main (String[] argv) 
  {
	  new Main();
  } 
     
  
  boolean test = false;  
  final int[][] dirs8 = {{0,1}, {0,-1}, {-1,0}, {1,0}, {1,1},{1,-1},{-1,1},{-1,-1}};
  final int[][] dirs4 = {{0,1}, {0,-1}, {-1,0}, {1,0}};
  final int MOD = 998244353;

  int n_bit = 1;
  int[] bit;
  
  
  final int WALL = -1;
  final int EMPTY = -2;
  final int VISITED = 1;
  final int FULL = 2;
  char[][] ans;
   StringBuilder sb;
   
  public Main()   {
	FastReader in = new FastReader(new BufferedReader(new InputStreamReader(System.in)));
	
     
    

    
    

    int nt = 1;
   sb = new StringBuilder();
    
    
    for (int it = 0; it < nt; it++) 
    {
        
       int a = in.nextInt();
       int b = in.nextInt();
       int c = in.nextInt();
       int d = in.nextInt();
       int cnt = 0;
       if (a > 0) cnt++;
       if (b > 0) cnt++;
       if (c > 0) cnt++;
       if (d > 0) cnt++;
       
       if (cnt == 1) {           
       if (a == 0 && b == 0 && c == 0)
           sb.append(f1(d, '3'));
       if (a == 0 && b == 0 && d == 0)
           sb.append(f1(c, '2'));
       if (a == 0 && d == 0 && c == 0)
           sb.append(f1(b, '1'));
       if (d == 0 && b == 0 && c == 0)
           sb.append(f1(a, '0'));       
       }else if(cnt == 2) {
           if (a > 0 && b > 0)
               sb.append(f2(a,b, '0','1'));
           else if (c > 0 && b > 0)
               sb.append(f2(b,c, '1','2'));
           else if (c > 0 && d > 0)
               sb.append(f2(c,d,'2','3'));
           else 
               sb.append("NO\n");
       }
       else if (cnt == 3) {
           if (a == 0)
               sb.append(f3(b,c,d,'1','2','3'));
           else if (d == 0)
               sb.append(f3(a, b,c,'0','1','2'));
           else 
               sb.append("NO\n");
       }
       else if (cnt == 4)
           sb.append(f4(a, b,c,d));
       
       

       

       

       

    }
    System.out.print(sb);
  }
  
  private String f1(int n,char  v){
      if (n > 1) 
          return "NO\n";
      
      char[] a = new char[n];
      for (int i = 0; i < n; i++) a[i] = v;
      
      StringBuilder  sb = new StringBuilder();
      for (char le : a) sb.append(le + " ");
      return "YES\n" + sb.toString() + "\n";
  }
  
  
  private String f2(int a, int b,char va, char vb){
      if (a == b) {
          char[] ans = new char[a+b];
          for (int i = 0; i < a; i++) {
              ans[i*2] = va;
              ans[i*2+1] = vb;
          }
          StringBuilder  sb = new StringBuilder();
          for (char le : ans) sb.append(le + " ");
          return "YES\n" + sb.toString() + "\n";
      }
      
      if (a + 1 == b) 
          return f2(b, a, vb, va);
      if (a == b + 1) {
          char[] ans = new char[a+b];
          for (int i = 0; i < b; i++) {
              ans[i*2] = va;
              ans[i*2+1] = vb;
          }
          ans[ans.length-1] = va;
          StringBuilder  sb = new StringBuilder();
          for (char le : ans) sb.append(le + " ");
          return "YES\n" + sb.toString() + "\n";
      }else {
          return "NO\n";
      }
  }
  
  private String f3(int a, int b, int c, char va, char vb, char vc)
  {
      if (a > b || c > b || b > a + c + 1)
          return "NO\n";
      
      if (a == b && c == 1) {
          char[] ans = new char[a+b+c];
          for (int i = 0; i < b; i++) {
              ans[i*2] = va;
              ans[i*2+1] = vb;
          }
          ans[ans.length-1] = vc;
          StringBuilder  sb = new StringBuilder();
          for (char le : ans) sb.append(le + " ");
          return "YES\n" + sb.toString() + "\n";
      }
      
      if (a + c == b) {
          char[] ans = new char[a+b+c];
          for (int i = 0; i < b; i++) {
              ans[i*2+1] = vb;
              if (i < a)
                  ans[i*2] = va;
              else ans[i*2] = vc;
          }
          StringBuilder  sb = new StringBuilder();
          for (char le : ans) sb.append(le + " ");
          return "YES\n" + sb.toString() + "\n";
      }
      
      if (a + c + 1 == b){
          char[] ans = new char[a+b+c];
          for (int i = 0; i < b; i++) {
              ans[i*2] = vb;
              if (i < a)
                  ans[i*2+1] = va;
              else if (2*i+1 < a+b+c) ans[i*2+1] = vc;
          }
          StringBuilder  sb = new StringBuilder();
          for (char le : ans) sb.append(le + " ");
         return "YES\n" + sb.toString() + "\n";
      }
      
      if (a + c - 1 == b){
          char[] ans = new char[a+b+c];
          for (int i = 0; i < a+c; i++) {
              if (i * 2 + 1 < ans.length)
                  ans[i*2 + 1] = vb;
              if (i < a)
                  ans[i*2] = va;
              else ans[i*2] = vc;
          }
          StringBuilder  sb = new StringBuilder();
          for (char le : ans) sb.append(le + " ");
          return "YES\n" + sb.toString() + "\n";
      }
      
      return "NO\n";
  }
  
  private String f4(int a, int b, int c, int d) {
      int aa = a, bb = b, cc = c, dd = d;
      char[] ans = new char[a+b+c+d];
      int n = ans.length;
      ans[0] = '0';
      a--;
      boolean ok = true;
      if (a < 0) ok = false;
      for (int i = 1; i < n && ok; i++) {
          if (ans[i-1] == '0') {
              ans[i] = '1';
              b--;
              if (b < 0) {
                  ok = false;
                  break;
              }
          }else if (ans[i-1] == '1')
          {
              if (a > 0) {
                  ans[i] = '0';
                  a--;
              }else if (c > 0) {
                  ans[i] = '2';
                  c--;
              }else {
                  ok = false;
                  break;
              }
          }else if (ans[i-1] == '2') {
              if (b > 0){
                ans[i] = '1';
                --b;
              }else if (d > 0){
                  --d;
                  ans[i] = '3';
              }else {
                  ok = false;
                  break;
              }              
          }else {
              if (c > 0){
                  --c;
                  ans[i] = '2';
              }else {
                  ok = false;
                  break;
              }
          }
      }
      if (ok){
          StringBuilder  sb = new StringBuilder();
          for (char le : ans) sb.append(le + " ");
          return "YES\n" + sb.toString() + "\n";
      }
      
      a = aa;
      b = bb;
      c = cc;
      d = dd;
      ans[0] = '1';
      b--;
      ok = true;
      if (b < 0) ok = false;
      for (int i = 1; i < n && ok; i++) {
          if (ans[i-1] == '0') {
              ans[i] = '1';
              b--;
              if (b < 0) {
                  ok = false;
                  break;
              }
          }else if (ans[i-1] == '1')
          {
              if (a > 0) {
                  ans[i] = '0';
                  a--;
              }else if (c > 0) {
                  ans[i] = '2';
                  c--;
              }else {
                  ok = false;
                  break;
              }
          }else if (ans[i-1] == '2') {
              if (b > 0){
                ans[i] = '1';
                --b;
              }else if (d > 0){
                  --d;
                  ans[i] = '3';
              }else {
                  ok = false;
                  break;
              }              
          }else {
              if (c > 0){
                  --c;
                  ans[i] = '2';
              }else {
                  ok = false;
                  break;
              }
          }
      }
      if (ok){
          StringBuilder  sb = new StringBuilder();
          for (char le : ans) sb.append(le + " ");
          return "YES\n" + sb.toString() + "\n";
      }
      
      
      a = aa;
      b = bb;
      c = cc;
      d = dd;
      ans[0] = '2';
      c--;
      ok = true;
      if (c < 0) ok = false;
      for (int i = 1; i < n && ok; i++) {
          if (ans[i-1] == '0') {
              ans[i] = '1';
              b--;
              if (b < 0) {
                  ok = false;
                  break;
              }
          }else if (ans[i-1] == '1')
          {
              if (a > 0) {
                  ans[i] = '0';
                  a--;
              }else if (c > 0) {
                  ans[i] = '2';
                  c--;
              }else {
                  ok = false;
                  break;
              }
          }else if (ans[i-1] == '2') {
              if (b > 0){
                ans[i] = '1';
                --b;
              }else if (d > 0){
                  --d;
                  ans[i] = '3';
              }else {
                  ok = false;
                  break;
              }              
          }else {
              if (c > 0){
                  --c;
                  ans[i] = '2';
              }else {
                  ok = false;
                  break;
              }
          }
      }
      if (ok){
          StringBuilder  sb = new StringBuilder();
          for (char le : ans) sb.append(le + " ");
          return "YES\n" + sb.toString() + "\n";
      }
      
      a = aa;
      b = bb;
      c = cc;
      d = dd;
      ans[0] = '3';
      d--;
      ok = true;
      if (d < 0) ok = false;
      for (int i = 1; i < n && ok; i++) {
          if (ans[i-1] == '0') {
              ans[i] = '1';
              b--;
              if (b < 0) {
                  ok = false;
                  break;
              }
          }else if (ans[i-1] == '1')
          {
              if (a > 0) {
                  ans[i] = '0';
                  a--;
              }else if (c > 0) {
                  ans[i] = '2';
                  c--;
              }else {
                  ok = false;
                  break;
              }
          }else if (ans[i-1] == '2') {
              if (b > 0){
                ans[i] = '1';
                --b;
              }else if (d > 0){
                  --d;
                  ans[i] = '3';
              }else {
                  ok = false;
                  break;
              }              
          }else {
              if (c > 0){
                  --c;
                  ans[i] = '2';
              }else {
                  ok = false;
                  break;
              }
          }
      }
      if (ok){
          StringBuilder  sb = new StringBuilder();
          for (char le : ans) sb.append(le + " ");
          return "YES\n" + sb.toString() + "\n";
      }
      
       return "NO\n";
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
  
  private int[] id4(String s)
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
  
  private int query(int p)
  {
      int sum = 0;
      for (; p > 0; p -= (p & (-p)))
      {
          sum += bit[p];
      }
      return sum;
  }
  
  private void add(int p, int val)
  {
      

      for (; p <= n_bit; p += (p & (-p)))
      {
          bit[p] += val;
      }
  }
  
  
  
  private List<Integer> id6(int sum)
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
      int[] id1;
      int t;
      boolean dump = false;
      
      public Tree(int V, int root)
      {
          if (dump) 
              System.out.println("build tree with size = " + V + ", root = " + root); 
          
          this.V = V;          
          this.root = root;
          nbs = new List[V];
          id1 = new int[V];
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
          id1[node] = t - timeRange[node][0] + 1;
      }
      
      public List<Integer> getNeighbors(int p) {
          return nbs[p];
      }
      
      public int[] id2(){
          return id1;
      }
      
      public int[][] id7()
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
      
      public int id5(int fr, int to)
      {
          return id5(1, 0, n-1, fr, to);
      }
      
      public int id5(int node, int lo, int hi, int fr, int to)
      {
          if (lo == fr && hi == to)
              return treeMax[node] + lazy[node];
          
          int mid = (lo + hi) / 2;
          pushDown(node, lo, hi);
          
          if (to <= mid) {
              return id5(node * 2, lo, mid, fr, to);
          }else if (fr > mid)
              return id5(node * 2 + 1, mid + 1, hi, fr, to);
          else {
              return Math.max(id5(node * 2, lo, mid, fr, mid),
                              id5(node * 2 + 1, mid + 1, hi, mid + 1, to));              
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
  
  private long pow(long v, int p)
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
  
  
 
  
  private int id3(int v) {
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