


import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Collections;
import java.util.Objects;
import java.util.StringTokenizer;
import java.util.ArrayList;
import java.util.List;
import java.util.HashMap;
import java.util.Map;
import java.util.Set;
import java.util.HashSet;



public class Practice {
  static FastScanner sc = new FastScanner(System.in);
  static Map<Character, int[]> direction = new HashMap<>();
  static Set<Character> openingBrackets;
  static Set<Character> closingBrackets;
  static Map<Character, Character> bracketsMatching = new HashMap<>();
  private static long mod = (long) (1e9 + 7);
  private static int oneE5 = (int) 1e5;
  private static int oneE9 = (int) 1e9;
  private static final long BIG = 2_000_000_010L;
  private static int[] dx = {-1, -1, 1, 1};
  private static int[] dy = {-1, 1, 1, -1};

  public static void main(String[] args) {
    prebuild();

    try (PrintWriter out = new PrintWriter(System.out)) {
      int T = sc.nextInt();
      for (int tt = 1; tt <= T; tt++) {
        int n = sc.nextInt();
        int q = sc.nextInt();
        int[] ans = new int[q];
        int[] original = new int[n];
        ArrayDeque<Integer> curStrength = new ArrayDeque<>();
        for (int i = 0; i < n; i++) {
          int val = sc.nextInt();
          curStrength.add(val);
          original[i] = val;
        }
        List<int[]> queries = new ArrayList<>();
        int queryId = 0;
        while (q-- > 0) {
          int i = sc.nextInt() - 1;
          int k = sc.nextInt();
          queries.add(new int[]{i, k, queryId++});
        }
        queries.sort((a, b) -> a[1] == b[1] ? a[2] - b[2] : a[1] - b[1]);
        

        int idx = 0; 

        int[] wins = new int[n + 1]; 

        int round = 1;
        while (round <= n - 1) { 

          

          int top1 = curStrength.removeFirst();
          int top2 = curStrength.removeFirst();
          if (top1 > top2) {
            

            wins[top1]++;
            

            curStrength.addFirst(top1);
            

            curStrength.addLast(top2);
          } else { 

            wins[top2]++;
            curStrength.addFirst(top2);
            curStrength.addLast(top1);
          }
          while (idx < queries.size() && round == queries.get(idx)[1]) {
            ans[queries.get(idx)[2]] = wins[original[queries.get(idx)[0]]];
            idx++;
          }
          round++;
        }
        while (idx < queries.size()) {
          

          ans[queries.get(idx)[2]] = wins[original[queries.get(idx)[0]]];
          

          if (n == original[queries.get(idx)[0]])
            ans[queries.get(idx)[2]] += queries.get(idx)[1] - (n - 1);
          idx++;
        }
        StringBuilder sb = new StringBuilder();
        for (int aa : ans)
          sb.append(aa).append("\n");
        System.out.print(sb);
      }
    }
  }
  


  private static void reverse(long[] arr) {
    for (int l = 0, r = arr.length - 1; l < r; l++, r--) {
      long t = arr[l];
      arr[l] = arr[r];
      arr[r] = t;
    }
  }

  private static void reverse(int[] arr) {
    for (int l = 0, r = arr.length - 1; l < r; l++, r--) {
      int t = arr[l];
      arr[l] = arr[r];
      arr[r] = t;
    }
  }

  private static boolean outside(int u1, int v1, int v2) {
    return !(u1 <= v2 && v2 <= v1);
  }

  private static boolean inside(int u1, int v1, int u2) {
    return u1 < u2 && u2 < v1;
  }

  abstract static class A {

  }

  private static long[] prefixSum(int[] arr) {
    long[] ps = new long[arr.length];
    long cs = 0;
    for (int i = 0; i < arr.length; i++) {
      cs += arr[i];
      ps[i] = cs;
    }
    return ps;
  }

  

  private static long rangeSum(long[] arr, int l, int r) {
    return l > 0 ? arr[r] - arr[l - 1] : arr[r];
  }

  private static long convert(long val) {
    List<Integer> digits = getDigits(val);
    Collections.reverse(digits);
    long binary = 0;
    for (int d : digits)
      binary = binary * 2 + d % 2;
    return binary;
  }

  private static List<Integer> getDigits(long val) {
    List<Integer> digits = new ArrayList<>();
    while (val > 0) {
      digits.add((int) (val % 10));
      val /= 10;
    }
    return digits;
  }

  static class Event {
    boolean closing;
    int color;
    int position;
    Integer idx;

    public Event(boolean closing, int color, int position, int idx) {
      this.closing = closing;
      this.color = color;
      this.position = position;
      this.idx = idx;
    }

    @Override
    public String toString() {
      return closing + " " + color + " " + position + " " + idx;
    }
  }

  
  private static boolean intersect(int[] a, int[] b) {
    if (a[0] <= b[0]) 

      return a[1] >= b[0]; 

    else
      return intersect(b, a); 

  }

  private static void prebuild() {
    direction.put('L', new int[]{0, -1});
    direction.put('R', new int[]{0, 1});
    direction.put('U', new int[]{-1, 0});
    direction.put('D', new int[]{1, 0});
    bracketsMatching.put('<', '>');
    bracketsMatching.put('{', '}');
    bracketsMatching.put('(', ')');
    bracketsMatching.put('[', ']');
    openingBrackets = bracketsMatching.keySet();
    closingBrackets = new HashSet<>(bracketsMatching.values());
  }

  private static boolean checkValidParanthesis(String s) {
    int cnt = 0;
    for (int i = 0; i < s.length(); i++) {
      if (openingBrackets.contains(s.charAt(i)))
        cnt++;
      else cnt--;
      if (cnt < 0)
        return false;
    }
    return cnt == 0;
  }

  private static long nc2(long n) {
    return n * (n - 1) / 2;
  }

  private static Map<Integer, Integer> generateMapping(Set<Integer> colors) {
    int id = 0;
    Map<Integer, Integer> mapping = new HashMap<>();
    for (int c : colors)
      mapping.put(c, id++);
    return mapping;
  }

  private static int[][] rotate(int[][] grid) {
    int[][] ans = new int[grid[0].length][grid.length];
    for (int i = 0; i < grid.length; i++) {
      for (int j = 0; j < grid[0].length; j++) {
        ans[j][grid.length - 1 - i] = grid[i][j];
      }
    }
    return ans;
  }


  private static void sort(int[] arr) {
    List<Integer> ls = new ArrayList<>();
    for (int n : arr) ls.add(n);
    Collections.sort(ls);
    for (int i = 0; i < arr.length; i++) arr[i] = ls.get(i);
  }

  static class Kosaraju {
    int n;
    HashSet<Integer>[] al;
    HashSet<Integer>[] ral;
    List<Integer> order;
    int[] comp; 

    boolean[] assignment;
    boolean[] used;

    Kosaraju(int n) {
      this.n = n;
      al = new HashSet[n + 1];
      ral = new HashSet[n + 1];
      comp = new int[n + 1];
      Arrays.fill(comp, -1); 

      assignment = new boolean[n + 1];
      used = new boolean[n + 1];
      order = new ArrayList<>();
      for (int i = 0; i <= n; i++) {
        al[i] = new HashSet<>();
        ral[i] = new HashSet<>();
      }
    }

    void dfs1(int u) {
      if (used[u])
        return;
      used[u] = true;
      for (int v : al[u])
        dfs1(v);
      order.add(u);
    }

    void dfs2(int u, int id) {
      if (comp[u] != -1)
        return;
      comp[u] = id;
      for (int v : ral[u])
        dfs2(v, id);
    }

    boolean solve_2SAT() {
      order.clear();
      Arrays.fill(used, false);
      for (int i = 0; i < n; i++)
        dfs1(i);
      Arrays.fill(comp, -1);
      for (int i = 0, id = 0; i < n; i++) {
        int v = order.get(n - i - 1);
        if (comp[v] == -1)
          dfs2(v, id++);
      }
      Arrays.fill(assignment, false);
      for (int i = 0; i < n; i += 2) {
        if (comp[i] == comp[i + 1]) 

          return false;
        assignment[i / 2] = comp[i] > comp[i + 1];
      }
      return true;
    }

    void addEdge(int u, int v) {
      al[u].add(v);
      ral[v].add(u);
      

    }

    

    

    

    void add_disjunction(int u, int v) {
      addEdge(u ^ 1, v);
      addEdge(v ^ 1, u);
    }

    void add_xor_edge(int u, int v) {
      add_disjunction(u, v);
      add_disjunction(u ^ 1, v ^ 1);
      

    }

    void add_not_xor_edge(int u, int v) {
      add_disjunction(u ^ 1, v);
      add_disjunction(u, v ^ 1);
    }
  }

  static class SegmentTree { 


    int size;
    long[] arr;

    int inputSize;

    private long neutralElement = Long.MIN_VALUE / 2;

    public SegmentTree(int n) {
      size = 1;
      inputSize = n;
      while (size < n) size *= 2;
      arr = new long[2 * size - 1];
      Arrays.fill(arr, neutralElement);
    }

    public void print() {
      

    }

    private void build(long[] input, int x, int lx, int rx) {
      if (rx - lx == 1) {
        if (lx < inputSize)
          arr[x] = input[lx];
        return;
      }
      int mid = (lx + rx) / 2;
      build(input, 2 * x + 1, lx, mid);
      build(input, 2 * x + 2, mid, rx);
      arr[x] = op(arr[2 * x + 1], arr[2 * x + 2]);
    }

    public void build(long[] arr) {
      build(arr, 0, 0, size);
    }

    private void set(int index, long val, int x, int lx, int rx) {
      if (rx - lx == 1) {
        arr[x] = val;
        return;
      }
      int mid = (lx + rx) / 2;
      if (index < mid) {
        set(index, val, 2 * x + 1, lx, mid);
      } else {
        set(index, val, 2 * x + 2, mid, rx);
      }
      arr[x] = op(arr[2 * x + 1], arr[2 * x + 2]);
    }

    public void set(int index, long val) {
      set(index, val, 0, 0, size);
    }

    public long get(int l, int r) {
      return get(l, r, 0, 0, size);
    }

    public long get(int l, int r, int x, int lx, int rx) {
      if (lx >= r || l >= rx)
        return neutralElement;
      if (lx >= l && rx <= r)
        return arr[x];
      int mid = (lx + rx) / 2;
      long max1 = get(l, r, 2 * x + 1, lx, mid);
      long max2 = get(l, r, 2 * x + 2, mid, rx);
      return op(max1, max2);
    }

    private long op(long a, long b) {
      return Math.max(a, b);
    }
  }
  
  

  static class UnionFind { 

    int[] parent;
    int[] size;
    int sz;

    UnionFind(int n) {
      parent = new int[n];
      size = new int[n];
      Arrays.fill(size, 1);
      for (int i = 0; i < parent.length; i++)
        parent[i] = i;
      sz = n;
    }

    int get(int x) {
      return parent[x] == x ? x : get(parent[x]);
    }

    boolean union(int a, int b) {
      int pa = get(a);
      int pb = get(b);
      if (pa == pb)
        return false;
      

      if (size[pa] < size[pb]) {
        int t = pa;
        pa = pb;
        pb = t;
      }
      size[pa] += size[pb];
      parent[pb] = pa;
      sz--;
      return true;
    }

    int getSize() {
      return sz;
    }
  }

  static class Pair {
    int x, y;

    public Pair(int x, int y) {
      this.x = x;
      this.y = y;
    }

    @Override
    public boolean equals(Object o) {
      if (this == o) return true;
      if (o == null || getClass() != o.getClass()) return false;
      Pair pair = (Pair) o;
      return x == pair.x && y == pair.y;
    }

    @Override
    public int hashCode() {
      return Objects.hash(x, y);
    }
  }

  



  static class BIT {
    long[] val;

    BIT(int size) {
      this.val = new long[size + 1];
    }

    long query(int idx) {
      long sum = 0;
      while (idx > 0 && idx < val.length) {
        sum += val[idx];
        idx -= idx & -idx;
      }
      return sum;
    }

    long query(int l, int r) {
      return query(r) - query(l - 1);
    }

    void update(int idx, long delta) {
      while (idx < val.length) {
        val[idx] += delta;
        idx += idx & -idx;
      }
    }
  }

  static class FastScanner {
    BufferedReader br;
    StringTokenizer st;

    public FastScanner(File f) {
      try {
        br = new BufferedReader(new FileReader(f));
      } catch (FileNotFoundException e) {
        e.printStackTrace();
      }
    }

    public FastScanner(InputStream f) {
      br = new BufferedReader(new InputStreamReader(f), 32768);
    }

    String next() {
      while (st == null || !st.hasMoreTokens()) {
        String s = null;
        try {
          s = br.readLine();
        } catch (IOException e) {
          e.printStackTrace();
        }
        if (s == null)
          return null;
        st = new StringTokenizer(s);
      }
      return st.nextToken();
    }

    int[] nextArrayInt(int n) {
      int[] arr = new int[n];
      for (int i = 0; i < n; i++) {
        arr[i] = nextInt();
      }
      return arr;
    }

    long[] nextArrayLong(int n) {
      long[] arr = new long[n];
      for (int i = 0; i < n; i++) {
        arr[i] = nextLong();
      }
      return arr;
    }

    boolean hasMoreTokens() {
      while (st == null || !st.hasMoreTokens()) {
        String s = null;
        try {
          s = br.readLine();
        } catch (IOException e) {
          e.printStackTrace();
        }
        if (s == null)
          return false;
        st = new StringTokenizer(s);
      }
      return true;
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
  }
}