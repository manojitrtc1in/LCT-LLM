


import java.io.File;
import java.lang.invoke.MethodHandles;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Random;
import java.util.Scanner;
import java.util.Stack;








































































































































































public class C1625E2 {
  static final int MOD = 998244353;
  static final Random RAND = new Random();

  static LazyRangeSumSegmentTree stGlobal = null;
  static int N = 0;

  

  static int[] cidxes = null;

  

  static class LazyRangeSumSegmentTree {
    int n;
    long tree[];  

    long lazy[];  


    LazyRangeSumSegmentTree(int n) {
      this.n = n;
      int m = nextPowerOf2(n);
      this.tree = new long[m * 2 - 1];
      this.lazy = new long[m * 2 - 1];
    }

    LazyRangeSumSegmentTree(long[] arr) {
      

      this(arr.length);
      constructSegTree(arr, 0, n - 1, 0);
    }

    

    

    void constructSegTree(long arr[], int low, int high, int idx) {
      if (low > high) {
        return;
      }

      if (low == high) {
        tree[idx] = arr[low];
        return;
      }

      

      int mid = (low + high) / 2;
      constructSegTree(arr, low, mid, idx * 2 + 1);
      constructSegTree(arr, mid + 1, high, idx * 2 + 2);
      tree[idx] = tree[idx * 2 + 1] + tree[idx * 2 + 2];
    }

    

    public void updateRange(int start, int end, long delta)  {
      if (start > end) {
        return;
      }
      updateRangeInner(0, 0, n - 1, start, end, delta);
    }

    

    public void set(int index, long value)  {
      if (index < 0 ||index >= n) {
        throw new RuntimeException("Invalid index " + index);
      }
      long vcurr = getRangeSum(index, index);
      long delta = value - vcurr;
      updateRange(index, index, delta);
    }

    

    public long getRangeSum(int start, int end) {
      if (start < 0 || end > n - 1 || start > end) {
        return 0;
      }
      return getRangeSum(0, 0, n - 1, start, end);
    }

    

    

    

    private void updateRangeInner(int idx, int low, int high, int start, int end, long delta) {
      

      applyLazy(idx, low, high);

      

      if (low > high || low > end || high < start) {
        return;
      }

      

      if (low >= start && high <= end) {
        tree[idx] += delta * (high - low + 1);
        if (low != high) {
          

          lazy[idx * 2 + 1] += delta;
          lazy[idx * 2 + 2] += delta;
        }
        return;
      }

      

      int mid = (low + high) / 2;
      updateRangeInner(idx * 2 + 1, low, mid, start, end, delta);
      updateRangeInner(idx * 2 + 2, mid + 1, high, start, end, delta);

      

      tree[idx] = tree[idx * 2 + 1] + tree[idx * 2 + 2];
    }

    private long getRangeSum(int idx, int low, int high, int start, int end) {
      

      applyLazy(idx, low, high);

      

      if (low > high || low > end || high < start) {
        return 0;
      }

      


      

      if (low >= start && high <= end) {
        return tree[idx];
      }

      

      int mid = (low + high) / 2;
      return getRangeSum(2 * idx + 1, low, mid, start, end) +
          getRangeSum(2 * idx + 2, mid + 1, high, start, end);
    }

    

    private void applyLazy(int idx, int low, int high) {
      if (lazy[idx] != 0) {
        

        tree[idx] += lazy[idx] * (high - low + 1);

        

        if (low != high) {
          

          lazy[idx * 2 + 1] += lazy[idx];
          lazy[idx * 2 + 2] += lazy[idx];
        }
        

        lazy[idx] = 0;
      }
    }

    public static int nextPowerOf2(int num){
      if (num == 0) {
        return 1;
      }
      if (num > 0 && (num & (num-1)) == 0) {
        return num;
      }
      while ((num & (num-1)) > 0) {
          num = num & (num - 1);
      }
      return num << 1;
    }
  }

  static class Node {
    int l;
    int r;

    

    long count;

    boolean closed = false;

    Node parent;
    List<Node> children = new ArrayList<>();
    

    Map<Integer, Integer> im = new HashMap<>();

    LazyRangeSumSegmentTree stSum = null;
    LazyRangeSumSegmentTree stCount = null;

    public Node(int l) {
      this.l = l;
    }

    public Node(int l, int r) {
      this.l = l;
      this.r = r;
    }

    public void close(int r, boolean isRoot) {
      this.r = r;
      this.closed = true;
      long sum = 0;
      int size = 0;
      for (Node child : children) {
        im.put(child.l, size++);
        im.put(child.r, size++);
        sum += child.count;
      }
      int m = children.size();
      this.count = sum + (isRoot ? 0 : 1) + (long)m * (m-1)/2;

      if (!children.isEmpty()) {
        

        long[] arr = new long[size];
        long[] brr = new long[size];
        for (Node child : children) {
          

          if (!child.closed) {
            break;
          }
          arr[im.get(child.l)] = (int) child.count;
          brr[im.get(child.l)] = 1;
        }
        


        stSum = new LazyRangeSumSegmentTree(arr);
        stCount = new LazyRangeSumSegmentTree(brr);
      }
    }

    public long removeChildAt(int l) {
      

      if (!closed) {
        

        return 0;
      }
      myAssert(l > this.l && l < this.r);
      final int m = im.size() - 1;
      

      long prev = 0;
      {
        long k = stCount.getRangeSum(0, m);
        prev = stSum.getRangeSum(0, m) + 1 + k * (k-1)/2;
      }

      int i = cidxes[l];
      myAssert(i >= 0);
      Node child = children.get(i);
      myAssert(child.l == l);
      long delta = 0;
      int il = im.get(l);
      stSum.updateRange(il, il, -1);
      stCount.updateRange(il, il, -1);
      long k = stCount.getRangeSum(0, m);
      long curr = stSum.getRangeSum(0, m) + 1 + k * (k-1)/2;
      delta = curr - prev;
      

      stGlobal.updateRange(this.l, this.l, delta);
      return delta;
    }

    @Override
    public
    String toString() {
      return String.format("[%d,%d]:%d", l, r, count);
    }

    public String trace() {
      StringBuilder sb = new StringBuilder();
      append(sb, 2);
      return sb.toString();
    }

    void append(StringBuilder sb, int indent) {
      for (int i = 0; i < indent; i++) {
        sb.append(' ');
      }
      sb.append(String.format("[%d,%d]:%d\n", l, r, count));
      for (Node child : children) {
        child.append(sb, indent + 2);
      }
    }
  }

  

  static long[] solve(String s, int[][] queries) {
    int n = s.length();
    int q = queries.length;
    Stack<Node> stack = new Stack<>();
    int b = 0;
    while (b < n && s.charAt(b) == ')') {
      b++;
    }
    int e = n - 1;
    while (e >= 0 && s.charAt(e) == '(') {
      e--;
    }

    N = n;
    stGlobal = new LazyRangeSumSegmentTree(n);
    cidxes = new int[N];

    Node root = new Node(b-1, e+1);
    stack.add(root);
    Map<Integer, Node> inm = new HashMap<>();
    for (int i = b; i <= e; i++) {
      char ch = s.charAt(i);
      if (ch == '(') {
        Node p = stack.peek();
        Node curr = new Node(i);
        curr.parent = p;
        cidxes[i] = p.children.size();
        p.children.add(curr);
        stack.add(curr);
        inm.put(curr.l, curr);
      } else {
        if (stack.peek() == root) {
          

          continue;
        }
        Node curr = stack.pop();
        curr.close(i, false);
      }
    }
    root.close(e+1, true);

    

    int q2 = 0;
    for (int i = 0; i < q; i++) {
      if (queries[i][0] == 2) {
        q2++;
      }
    }
    long[] ans = new long[q2];
    int idx = -1;
    for (int i = 0; i < q; i++) {
      int l = queries[i][1];
      int r = queries[i][2];
      Node node = inm.get(l);
      Node p = node.parent;
      

      if (queries[i][0] == 1) {
        long delta = p.removeChildAt(l);
        

      } else {
        idx++;
        long delta = stGlobal.getRangeSum(l, r);
        if (r == node.r) {
          ans[idx] = node.count;
          

        } else {
          myAssert(r > node.r);
          myAssert(r <= p.r);
          int il = p.im.get(l);
          int ir = p.im.get(r);
          long k = p.stCount.getRangeSum(il, ir);
          ans[idx] = p.stSum.getRangeSum(il, ir) + k * (k-1) / 2;
          

        }
        ans[idx] += delta;
      }
    }
    return ans;
  }

  static List<int[]> getQueryTwo(char[] ca) {
    int n = ca.length;
    List<int[]> rbses = new ArrayList<>();
    

    

    

    for (int i = 0; i < n; i++) {
      if (ca[i] != '(') {
        continue;
      }
      for (int j = i + 1; j < n; j += 2) {
        if (ca[j] != ')') {
          continue;
        }
        

        boolean ok = true;
        int depth = 0;
        for (int k = i; k <= j; k++) {
          if (ca[k] == '(') {
            depth++;
          } else if (ca[k] == ')') {
            depth--;
            if (depth < 0) {
              ok = false;
              break;
            }
          }
        }
        if (ok && depth == 0) {
          rbses.add(new int[] {i,j});
        }
      }
    }
    return rbses;
  }

  static int getCount(char[] ca, int l, int r) {
    int n = ca.length;
    

    

    

    int ans = 0;
    for (int i = l; i < r; i++) {
      if (ca[i] != '(') {
        continue;
      }
      for (int j = i + 1; j <= r; j += 2) {
        if (ca[j] != ')') {
          continue;
        }
        

        boolean ok = true;
        int depth = 0;
        for (int k = i; k <= j; k++) {
          if (ca[k] == '(') {
            depth++;
          } else if (ca[k] == ')') {
            depth--;
            if (depth < 0) {
              ok = false;
              break;
            }
          }
        }
        if (ok && depth == 0) {
          ans++;
        }
      }
    }
    return ans;
  }

  static List<int[]> getQueryOne(char[] ca) {
    int n = ca.length;
    List<int[]> ans = new ArrayList<>();
    int b = 0;
    while (b < n) {
      while (b < n && ca[b] != '(') {
        b++;
      }
      if (b >= n) {
        break;
      }
      int e = b + 1;
      while (ca[e] == '.') {
        e++;
      }
      if (e >= n) {
        break;
      }
      if (ca[e] == ')') {
        ans.add(new int[] {b, e});
        e++;
      }
      b = e;
    }
    return ans;
  }

  static void doTest() {
    long t0 = System.currentTimeMillis();
    

    

    String s = "((((()()))()())())((())(()))";
    String t = "0123456789112345678921234567";
    int q = 20;
    System.out.format("                  %s\n", s);
    System.out.format("                  %s\n", t);
    char[] ca = s.toCharArray();
    int[][] queries = new int[q][3];
    List<Integer> expected = new ArrayList<>();
    List<String> sts = new ArrayList<>();
    for (int i = 0; i < q; i++) {
      int type = 1 + RAND.nextInt(2);
      queries[i][0] = type;
      if (type == 1) {
        List<int[]> ones = getQueryOne(ca);
        int j = RAND.nextInt(ones.size());
        int l = ones.get(j)[0];
        int r = ones.get(j)[1];
        queries[i][1] = l;
        queries[i][2] = r;
        ca[l] = '.';
        ca[r] = '.';
      } else {
        List<int[]> twos = getQueryTwo(ca);
        int j = RAND.nextInt(twos.size());
        int l = twos.get(j)[0];
        int r = twos.get(j)[1];
        queries[i][1] = l;
        queries[i][2] = r;
        expected.add(getCount(ca, l, r));
      }
      sts.add(new String(ca));
    }
    long[] ans = solve(s, queries);
    int idx = -1;
    for (int i = 0; i < q; i++) {
      int type = queries[i][0];
      int l = queries[i][1];
      int r = queries[i][2];
      if (type == 1) {
        System.out.format("  i:%2d %d %2d %2d -> %s\n", i, type, l, r, sts.get(i));
      } else {
        idx++;
        System.out.format("  i:%2d %d %2d %2d -> %2d%s\n", i, type, l, r, ans[idx],
          expected.get(idx) == ans[idx] ? "" : " Expected " + expected.get(idx));
      }
    }
    System.out.format("                  %s\n", t);
    System.out.format("%d msec\n", System.currentTimeMillis() - t0);
    System.exit(0);
  }

  public static void main(String[] args) {
    

    Scanner in = getInputScanner();
    int n = in.nextInt();
    int q = in.nextInt();
    String s = in.next();

    int[][] queries = new int[q][3];
    for (int i = 0; i < q; i++) {
      queries[i][0] = in.nextInt();
      queries[i][1] = in.nextInt() - 1;
      queries[i][2] = in.nextInt() - 1;
    }
    long[] ans = solve(s, queries);
    output(ans);
    in.close();
  }

  static Scanner getInputScanner() {
    try {
      final String USERDIR = System.getProperty("user.dir");
      final String CNAME = MethodHandles.lookup().lookupClass().getSimpleName();
      final File fin = new File(USERDIR + "/io/c" + CNAME.substring(1,5) + "/" + CNAME + ".in");
      return fin.exists() ? new Scanner(fin) : new Scanner(System.in);
    } catch (Exception e) {
      return new Scanner(System.in);
    }
  }

  static void output(long[] a) {
    StringBuilder sb = new StringBuilder();
    for (long v : a) {
      sb.append(v);
      sb.append("\n");
      if (sb.length() >= 500) {
        System.out.print(sb.toString());
        sb.setLength(0);
      }
    }
    System.out.print(sb.toString());
  }

  public static String traceListInt(List<Integer> values) {
    StringBuilder sb = new StringBuilder();
    sb.append('[');
    int n = values.size();
    for (int i = 0; i < n; i++) {
      if (i < 16 || i >= n - 16) {
        if (i > 0) {
          sb.append(',');
        }
        sb.append(values.get(i));
      }
      if (n > 32 && i == 16) {
        sb.append(",...");
      }
    }
    sb.append(']');
    return sb.toString();
  }

  static void myAssert(boolean cond) {
    if (!cond) {
      throw new RuntimeException("Unexpected");
    }
  }
}
