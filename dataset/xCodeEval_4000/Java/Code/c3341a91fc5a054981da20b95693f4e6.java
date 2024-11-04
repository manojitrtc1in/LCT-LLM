

import java.io.*;
import java.util.*;

public class Main {

  static FastScanner sc = new FastScanner();
  static Output out = new Output(System.out);

  static final int[] dx = {0, 1, 0, -1};
  static final int[] dy = {-1, 0, 1, 0};

  static final long MOD = (long) (1e9 + 7);
  static final long INF = Long.MAX_VALUE / 2;

  static final int e5 = (int) 1e5;

  public static class Solver {

    public class Lecture {
      int sa, ea, sb, eb, id;
      public Lecture (int sa, int ea, int sb, int eb, int id) {
        this.sa = sa;
        this.ea = ea;
        this.sb = sb;
        this.eb = eb;
        this.id = id;
      }
    }

    public Solver() {

      int N = sc.nextInt();

      Lecture[] lectures = new Lecture[N];
      for (int i=0; i<N; i++) {
        lectures[i] = new Lecture(sc.nextInt(), sc.nextInt(), sc.nextInt(), sc.nextInt(), i);
      }

      Arrays.sort(lectures, (o1, o2) -> o1.sa - o2.sa);

      {
        TreeMap<Integer, Integer> zip = new TreeMap<Integer, Integer>();
        

        int[] a = new int[4*N];
        for (int i=0; i<N; i++) {
          a[4*i] = lectures[i].sa;
          a[4*i+1] = lectures[i].ea;
          a[4*i+2] = lectures[i].sb;
          a[4*i+3] = lectures[i].eb;
        }
        Array.sort(a);
        for (int i = 0, j = 0; i < 4*N; i++) {
          zip.put(a[i], j);
          

          if (i < 4*N - 1 && a[i + 1] != a[i]) j++;
        }
        for (int i=0; i<N; i++) {
          lectures[i].sa = zip.get(lectures[i].sa);
          lectures[i].ea = zip.get(lectures[i].ea);
          lectures[i].sb = zip.get(lectures[i].sb);
          lectures[i].eb = zip.get(lectures[i].eb);
        }
      }

      SegmentTree tree = new SegmentTree(new long[4*N]);
      long[] A = new long[N];
      long[] B = new long[N];

      for (int i=0; i<N; i++) {
        A[lectures[i].id] += tree.query(lectures[i].sa, 4*N);

        tree.add(lectures[i].ea, 1);
      }

      tree = new SegmentTree(new long[4*N]);

      for (int i=N-1; i>=0; i--) {
        A[lectures[i].id] += tree.query(0, lectures[i].ea+1);

        tree.add(lectures[i].sa, 1);
      }

      Arrays.sort(lectures, (o1, o2) -> o1.sb - o2.sb);

      tree = new SegmentTree(new long[4*N]);

      for (int i=0; i<N; i++) {
        B[lectures[i].id] += tree.query(lectures[i].sb, 4*N);

        tree.add(lectures[i].eb, 1);
      }

      tree = new SegmentTree(new long[4*N]);

      for (int i=N-1; i>=0; i--) {
        B[lectures[i].id] += tree.query(0, lectures[i].eb+1);

        tree.add(lectures[i].sb, 1);
      }

      boolean ans = true;
      for (int i=0; i<N; i++) {
        

        if (A[i] != B[i]) ans = false;
      }

      out.println(ans ? "YES" : "NO");

    }

    public static class Array {

      public static void sort(int[] a) {
        shuffle(a);
        Arrays.sort(a);
      }

      public static void sort(long[] a) {
        shuffle(a);
        Arrays.sort(a);
      }

      public static void shuffle(int[] arr){
        int n = arr.length;
        Random rnd = new Random();
        for(int i=0; i<n; ++i){
          int tmp = arr[i];
          int randomPos = i + rnd.nextInt(n-i);
          arr[i] = arr[randomPos];
          arr[randomPos] = tmp;
        }
      }

      public static void shuffle(long[] arr){
        int n = arr.length;
        Random rnd = new Random();
        for(int i=0; i<n; ++i){
          long tmp = arr[i];
          int randomPos = i + rnd.nextInt(n-i);
          arr[i] = arr[randomPos];
          arr[randomPos] = tmp;
        }
      }

      public static int[] reverse(int[] a) {
        int[] b = new int[a.length];
        for (int i=0; i<a.length; i++) {
          b[a.length-1-i] = a[i];
        }
        return b;
      }

      public static long[] reverse(long[] a) {
        long[] b = new long[a.length];
        for (int i=0; i<a.length; i++) {
          b[a.length-1-i] = a[i];
        }
        return b;
      }

      public static long[] toLong(int[] a) {
        long[] b = new long[a.length];
        for (int i=0; i<a.length; i++) {
          b[i] = a[i];
        }
        return b;
      }

      public static int[] toInt(long[] a) {
        int[] b = new int[a.length];
        for (int i=0; i<a.length; i++) {
          b[i] = (int)a[i];
        }
        return b;
      }

      public static long[] cumulativeSum(int[] a, long mod) {
        long[] b = new long[a.length+1];
        for(int i=1; i<=a.length; i++) {
          b[i] += (b[i-1] + a[i-1]) % mod;
        }
        return b;
      }

      public static long[] cumulativeSum(long[] a, long mod) {
        long[] b = new long[a.length+1];
        for(int i=1; i<=a.length; i++) {
          b[i] += (b[i-1] + a[i-1]) % mod;
        }
        return b;
      }

      public static long[] cumulativeSum(int[] a) {
        long[] b = new long[a.length+1];
        for(int i=1; i<=a.length; i++) {
          b[i] += b[i-1] + a[i-1];
        }
        return b;
      }

      public static long[] cumulativeSum(long[] a) {
        long[] b = new long[a.length+1];
        for(int i=1; i<=a.length; i++) {
          b[i] += b[i-1] + a[i-1];
        }
        return b;
      }

      
      public static long sum(int[] a) {
        long sum = 0;
        for (int i=0; i<a.length; i++) {
          sum += a[i];
        }
        return sum;
      }

      
      public static long sum(long[] a) {
        long sum = 0;
        for (int i=0; i<a.length; i++) {
          sum += a[i];
        }
        return sum;
      }

      public static void swap(int[] a, int i, int j) {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
      }

      public static void swap(long[] a, int i, int j) {
        long temp = a[i];
        a[i] = a[j];
        a[j] = temp;
      }

      public static int max(int... a) {
        int M = a[0];
        for (int i = 1; i < a.length; i++) {
          M = Math.max(M, a[i]);
        }
        return M;
      }

      public static int min(int... a) {
        int m = a[0];
        for (int i = 1; i < a.length; i++) {
          m = Math.min(m, a[i]);
        }
        return m;
      }

      public static long max(long... a) {
        long M = a[0];
        for (int i = 1; i < a.length; i++) {
          M = Math.max(M, a[i]);
        }
        return M;
      }

      public static long min(long... a) {
        long m = a[0];
        for (int i = 1; i < a.length; i++) {
          m = Math.min(m, a[i]);
        }
        return m;
      }

      public static int[] iota(int n) {
        int[] a = new int[n];
        for (int i=0; i<n; i++) {
          a[i] = i;
        }
        return a;
      }

      public static long[] iotaL(int n) {
        long[] a = new long[n];
        for (int i=0; i<n; i++) {
          a[i] = i;
        }
        return a;
      }

    }

    
    public static class SegmentTree {

      static final long INF = Long.MAX_VALUE / 2;

      Node[] tree;
      int N = 1; 

      int size; 

      Node initialNode;
      Node calcNode;

      
      public static class Node {
        static long initialVal = 0;
        static long initialLazy = 0;
        long val;
        long lazy;
        boolean isLazy;

        public Node() {
          val = initialVal;
          lazy = initialLazy;
        }
        public Node(long val) {
          this.val = val;
          lazy = initialLazy;
        }

        public Node operation(Node nl, Node nr) {
          val = nl.val + nr.val;
          return this;
        }
        public void prop(Node par) {
          if (!par.isLazy) return;
          lazy += par.lazy/2;
          isLazy = true;
        }
        public void prop(long x, int l, int r) {
          lazy += x * (r-l);
          isLazy = true;
        }
        public void update() {
          if (!isLazy) return;
          val += lazy;
          lazy = initialLazy;
          isLazy = false;
        }
      }

      public void add(int k, long x) {
        update(k, tree[k+N-1].val + x);
      }

      public void update(int k, long x) {
        k += N-1;
        tree[k].val = x;

        while(k != 0) {
          k = parent(k);
          tree[k].operation(tree[childL(k)], tree[childR(k)]);
        }
      }

      private void prop(int k) {
        if (childL(k) < size) { 

          tree[childL(k)].prop(tree[k]);
          tree[childR(k)].prop(tree[k]);
        }
        tree[k].update();
      }

      public void put(int a, int b, long x) {
        put(a, b, 0, 0, N, x);
      }

      private void put(int a, int b, int k, int l, int r, long x) {
        prop(k);

        if (r <= a || b <= l) return; 

        if (a <= l && r <= b) { 

          tree[k].prop(x, l, r);
          prop(k);
        } else { 

          put(a, b, childL(k), l, (l + r) / 2, x);
          put(a, b, childR(k), (l + r) / 2, r, x);
          tree[k].operation(tree[childL(k)], tree[childR(k)]);
        }
      }

      public SegmentTree(long[] A) {
        initialNode = new Node();
        calcNode = new Node();

        

        while (N < A.length) N *= 2;

        size = N*2-1;
        tree = new Node[size];

        for (int i=0; i<size; i++) {
          tree[i] = new Node();
        }

        for (int i=0; i<A.length; i++) {
          update(i, A[i]);
        }

      }

      public long query(int a, int b) {
        return query(a, b, 0, 0, N);
      }

      private long query(int a, int b, int k, int l, int r) {
        prop(k);

        if (r <= a || b <= l) return initialNode.val;
        if (a <= l && r <= b) return tree[k].val;

        return query(a, b, childL(k), l, (l+r)/2) + query(a, b, childR(k), (l+r)/2, r);
      }

      private int parent(int k) {
        return k % 2 == 0 ? (k-2)/2 : (k-1)/2;
      }

      private int childL(int k) {
        return 2*k+1;
      }

      private int childR(int k) {
        return 2*k+2;
      }

      public static void main(String[] args) {
        SegmentTree seg = new SegmentTree(new long[]{3,4,6,8,2,7,5,8,1,4});
        Scanner sc = new Scanner(System.in);
        while(true) {
          int command = sc.nextInt();
          if (command == 0) {
            seg.update(sc.nextInt(), sc.nextLong());
          } else if (command == 1) {
            seg.put(sc.nextInt(), sc.nextInt(), sc.nextLong());
          } else {
            System.out.println(seg.query(sc.nextInt(), sc.nextInt()));
          }
        }
      }

    }

  }

  public static void main(String[] args) {
    new Solver();
    out.flush();
  }

  static class FastScanner {
    private InputStream in = System.in;
    private final byte[] buffer = new byte[1024];
    private int ptr = 0;
    private int buflen = 0;


    public void load() {
      try {
        in = new FileInputStream(next());
      } catch (Exception e) {
        e.printStackTrace();
      }
    }

    private boolean hasNextByte() {
      if (ptr < buflen) {
        return true;
      } else {
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

    private int readByte() {
      if (hasNextByte()) return buffer[ptr++];
      else return -1;
    }

    private static boolean isPrintableChar(int c) {
      return 33 <= c && c <= 126;
    }

    private void skipUnprintable() {
      while (hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++;
    }

    public boolean hasNext() {
      skipUnprintable();
      return hasNextByte();
    }

    public String next() {
      if (!hasNext()) throw new NoSuchElementException();
      StringBuilder sb = new StringBuilder();
      int b = readByte();
      while (isPrintableChar(b)) {
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
      while (true) {
        if ('0' <= b && b <= '9') {
          n *= 10;
          n += b - '0';
        } else if (b == -1 || !isPrintableChar(b)) {
          return minus ? -n : n;
        } else {
          throw new NumberFormatException();
        }
        b = readByte();
      }
    }

    public int nextInt() {
      return (int) nextLong();
    }

    public int[] nextIntArray(int N, boolean oneBased) {
      if (oneBased) {
        int[] array = new int[N + 1];
        for (int i = 1; i <= N; i++) {
          array[i] = sc.nextInt();
        }
        return array;
      } else {
        int[] array = new int[N];
        for (int i = 0; i < N; i++) {
          array[i] = sc.nextInt();
        }
        return array;
      }
    }

    public long[] nextLongArray(int N, boolean oneBased) {
      if (oneBased) {
        long[] array = new long[N + 1];
        for (int i = 1; i <= N; i++) {
          array[i] = sc.nextLong();
        }
        return array;
      } else {
        long[] array = new long[N];
        for (int i = 0; i < N; i++) {
          array[i] = sc.nextLong();
        }
        return array;
      }
    }
  }

  static class Output extends PrintWriter {

    private long startTime;

    public Output(PrintStream ps) {
      super(ps);
    }

    public void print(int[] a, String separator) {
      for (int i = 0; i < a.length; i++) {
        if (i == 0) print(a[i]);
        else print(separator + a[i]);
      }
      println();
    }

    public void print(long[] a, String separator) {
      for (int i = 0; i < a.length; i++) {
        if (i == 0) print(a[i]);
        else print(separator + a[i]);
      }
      println();
    }

    public void print(String[] a, String separator) {
      for (int i = 0; i < a.length; i++) {
        if (i == 0) print(a[i]);
        else print(separator + a[i]);
      }
      println();
    }

    public void print(ArrayList a, String separator) {
      for (int i = 0; i < a.size(); i++) {
        if (i == 0) print(a.get(i));
        else print(separator + a.get(i));
      }
      println();
    }

    public void start() {
      startTime = System.currentTimeMillis();
    }

    public void time(String s) {
      long time = System.currentTimeMillis() - startTime;
      println(s + "(" + time + ")");
    }

  }

}
