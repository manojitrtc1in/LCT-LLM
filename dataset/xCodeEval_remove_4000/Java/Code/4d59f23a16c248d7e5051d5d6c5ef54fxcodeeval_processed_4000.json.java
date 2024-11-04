import java.io.*;
import java.lang.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.function.*;

public class E {
  public static void main(String[] args) {
    int n = in.nextInt();
    int k = in.nextInt();
    int[][] xrf = new int[n][];
    for (int i = 0; i < n; ++i) {
      xrf[i] = in.nextInts(3);
    }
    id0[] temp = new id0[id0.id3 + 1];
    

    Arrays.sort(xrf, (xrfi1, xrfi2) -> Integer.compare(xrfi1[1], xrfi2[1]));
    

    Map<Integer, id0> m = new HashMap<>();
    for (int i = 0; i < n; ++i) {
      id0 ftree = m.get(xrf[i][2]);
      if (ftree == null) {
        m.put(xrf[i][2], id6(xrf[i][0]));
      } else {
        m.put(xrf[i][2], aaInsert(ftree, xrf[i][0], temp));
      }
    }
    long bad = 0;
    for (int i = 0; i < n; ++i) {
      for (int fi = xrf[i][2] - k; fi <= xrf[i][2] + k; ++fi) {
        id0 ftree = m.get(fi);
        if (ftree != null) {
          bad += aaRank(ftree, xrf[i][0] + xrf[i][1]) - aaRank(ftree, xrf[i][0] - xrf[i][1] - 1);
        }
        if (fi == xrf[i][2]) {
          --bad;
        }
      }
      
      m.put(xrf[i][2], aaDelete(m.get(xrf[i][2]), xrf[i][0], temp));
    }
    out.println(bad);
  }

  static class id0 {
    static int id3 = 31;
    static id0 nil = new id0();

    id0[] children;
    int level;
    int size;
    int value;

    id0() {
      this.children = new id0[] {this, this};
      level = 0;
      size = 0;
      value = 0;
    }

    id0(int value) {
      this.children = new id0[] {nil, nil};
      this.level = 1;
      this.size = 1;
      this.value = value;
    }

    id0(id0 left, id0 right, int level, int size, int value) {
      this.children = new id0[] {left, right};
      this.level = level;
      this.size = size;
      this.value = value;
    }

    public String toString() {
      if (this == nil) {
        return "nil";
      } else {
        StringBuilder sb = new StringBuilder();
        id0[] nodes = id9(this);
        for (int i = 0; i < nodes.length; ++i) {
          sb.append(nodes[i].level)
              .append(" ")
              .append(nodes[i].size)
              .append(" ")
              .append(nodes[i].value)
              .append(", ");
        }
        sb.delete(sb.length() - 2, sb.length() - 1);
        return sb.toString();
      }
    }
  }

  
  static boolean aaContains(id0 t, int k) {
    return aaFind(t, k) != id0.nil;
  }

  
  static id0 aaDelete(id0 root, int k, id0[] ns) {
    if (root == id0.nil) {
      return root;
    }

    id0 n = root;
    int nsTop = 0;

    while (n.value != k) {
      ns[nsTop++] = n;
      if (n.value > k && n.children[0] != id0.nil) {
        n = n.children[0];
      } else if (n.value < k && n.children[1] != id0.nil) {
        n = n.children[1];
      } else {
        break;
      }
    }

    if (n.value != k) {
      return root;
    }

    if (n.children[0] == id0.nil || n.children[1] == id0.nil) {
      int nside = n.children[1] == id0.nil ? 0 : 1;
      if (nsTop > 0) {
        ns[nsTop - 1].children[ns[nsTop - 1].children[0] == n ? 0 : 1] = n.children[nside];
      } else {
        root = n.children[nside];
      }
    } else {
      ns[nsTop++] = n;
      id0 nn = n.children[1];
      while (nn.children[0] != id0.nil) {
        ns[nsTop++] = nn;
        nn = nn.children[0];
      }
      n.value = nn.value;
      ns[nsTop - 1].children[ns[nsTop - 1].children[0] == nn ? 0 : 1] = nn.children[1];
    }

    while (--nsTop >= 0) {
      id0 nTop = ns[nsTop];
      --ns[nsTop].size;

      if (ns[nsTop].children[0].level < ns[nsTop].level - 1
          || ns[nsTop].children[1].level < ns[nsTop].level - 1) {
        if (ns[nsTop].children[1].level > --ns[nsTop].level) {
          --ns[nsTop].children[1].level;
        }

        ns[nsTop] = id5(ns[nsTop]);
        ns[nsTop].children[1] = id5(ns[nsTop].children[1]);
        ns[nsTop].children[1].children[1] = id5(ns[nsTop].children[1].children[1]);
        ns[nsTop] = aaSplit(ns[nsTop]);
        ns[nsTop].children[1] = aaSplit(ns[nsTop].children[1]);
      }

      if (nsTop > 0) {
        ns[nsTop - 1].children[ns[nsTop - 1].children[0] == nTop ? 0 : 1] = ns[nsTop];
      } else {
        root = ns[nsTop];
      }
    }

    return root;
  }

  
  static id0 aaDelete(id0 root, int k) {
    return aaDelete(root, k, new id0[id0.id3 + 1]);
  }

  static id0 aaFind(id0 t, int k) {
    while (t != id0.nil) {
      if (t.value == k) {
        return t;
      } else {
        t = t.children[t.value > k ? 0 : 1];
      }
    }
    return t;
  }

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  


  
  static id0[] id9(id0 t) {
    int id11 = 0;
    id0[] inorder = new id0[t.size];
    while (t != id0.nil) {
      id0 previous = t.children[0];
      if (previous != id0.nil) {
        while (previous.children[1] != id0.nil && previous.children[1] != t) {
          previous = previous.children[1];
        }
        if (previous.children[1] == t) {
          inorder[id11++] = t;
          previous.children[1] = id0.nil;
          t = t.children[1];
        } else {
          previous.children[1] = t;
          t = t.children[0];
        }
      } else {
        inorder[id11++] = t;
        t = t.children[1];
      }
    }
    return inorder;
  }

  
  static id0 aaInsert(id0 root, int k, id0[] ns) {
    if (root == id0.nil) {
      return id6(k);
    }

    id0 n = root;
    int nsTop = 0;
    while (n.value != k) {
      ns[nsTop++] = n;
      if (n.value > k && n.children[0] != id0.nil) {
        n = n.children[0];
      } else if (n.value < k && n.children[1] != id0.nil) {
        n = n.children[1];
      } else {
        break;
      }
    }

    if (n.value == k) {
      return root;
    }

    id0 nn = id6(k);
    ns[nsTop - 1].children[ns[nsTop - 1].value > k ? 0 : 1] = nn;
    while (--nsTop >= 0) {
      int nside = nsTop > 0 ? ns[nsTop - 1].children[0] == ns[nsTop] ? 0 : 1 : 0;
      ++ns[nsTop].size;
      ns[nsTop] = id5(ns[nsTop]);
      ns[nsTop] = aaSplit(ns[nsTop]);
      if (nsTop > 0) {
        ns[nsTop - 1].children[nside] = ns[nsTop];
      }
    }

    return ns[0];
  }

  
  static id0 aaInsert(id0 root, int k) {
    return aaInsert(root, k, new id0[id0.id3 + 1]);
  }

  

  

  


  
  static id0 id6(int value) {
    return new id0(value);
  }

  
  static id0 id4(id0 left, id0 right, int level, int size, int value) {
    return new id0(left, right, level, size, value);
  }

  static int aaRank(id0 root, int value) {
    int rank = 0;
    id0 n = root;
    while (n != id0.nil) {
      if (n.value > value) {
        n = n.children[0];
      } else if (n.value < value) {
        rank += n.children[0].size + 1;
        n = n.children[1];
      } else {
        return rank + n.children[0].size + 1;
      }
    }
    return rank;
  }

  

  

  

  

  

  

  


  static id0 aaSelect(id0 root, int i) {
    id0 n = root;
    while (n != id0.nil) {
      if (n.children[0].size == i - 1) {
        return n;
      } else if (n.children[0].size > i - 1) {
        n = n.children[0];
      } else {
        i -= n.children[0].size + 1;
        n = n.children[1];
      }
    }
    throw new NoSuchElementException();
  }

  
  static id0 id5(id0 nodeY) {
    if (nodeY != id0.nil && nodeY.children[0].level == nodeY.level) {
      id0 nodeX = nodeY.children[0];
      id0 nodeA = nodeY.children[0].children[0];
      id0 nodeB = nodeY.children[0].children[1];
      id0 nodeC = nodeY.children[1];
      nodeX.size += nodeC.size + 1;
      nodeY.size -= nodeA.size + 1;
      nodeY.children[0].children[1] = nodeY;
      nodeY.children[0] = nodeB;
      return nodeX;
    } else {
      return nodeY;
    }
  }

  
  static id0 aaSplit(id0 nodeX) {
    id0 nodeY = nodeX.children[1];
    id0 nodeZ = nodeY.children[1];
    if (nodeX != id0.nil
        && nodeY != id0.nil
        && nodeZ != id0.nil
        && nodeX.level == nodeY.level
        && nodeY.level == nodeZ.level) {
      id0 nodeA = nodeX.children[0];
      id0 nodeB = nodeY.children[0];
      id0 nodeC = nodeZ.children[0];
      id0 nodeD = nodeZ.children[1];
      nodeX.size -= nodeC.size + nodeD.size + 2;
      nodeY.size += nodeA.size + 1;
      nodeX.children[1] = nodeB;
      nodeY.children[0] = nodeX;
      ++nodeY.level;
      return nodeY;
    } else {
      return nodeX;
    }
  }

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  


  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  static MyScanner in = new MyScanner();
  static id2 out = new id2();
  static RandScanner rand = new RandScanner();

  static class id2 {
    BufferedOutputStream bos;
    PrintWriter pw;

    id2() {
      this.bos = new BufferedOutputStream(System.out);
      this.pw = new PrintWriter(bos, true);
    }

    void print(String t) {
      pw.print(t);
    }

    void println() {
      pw.println("");
    }

    void println(String s) {
      pw.println(s);
    }

    void println(int t) {
      pw.println(t);
    }

    void println(long t) {
      pw.println(t);
    }

    void println(double t) {
      pw.println(t);
    }

    <T> void println(T t) {
      pw.println(t.toString());
    }

    void println(int[] ts) {
      println(ts, true);
    }

    void println(long[] ts) {
      println(ts, true);
    }

    void println(double[] ts) {
      println(ts, true);
    }

    <T> void println(T[] ts) {
      println(ts, true);
    }

    <T> void println(Collection<T> ts) {
      println(ts, true);
    }

    <T, U> void println(Map<T, U> ts) {
      println(ts, true);
    }

    void println(int[] ts, boolean newline) {
      StringBuilder sb = new StringBuilder();
      for (int t : ts) {
        sb.append(t);
        sb.append((newline ? "\n" : " "));
      }
      if (sb.length() > 0) {
        sb.deleteCharAt(sb.length() - 1);
      }
      pw.println(sb.toString());
    }

    void println(long[] ts, boolean newline) {
      StringBuilder sb = new StringBuilder();
      for (long t : ts) {
        sb.append(t);
        sb.append((newline ? "\n" : " "));
      }
      if (sb.length() > 0) {
        sb.deleteCharAt(sb.length() - 1);
      }
      pw.println(sb.toString());
    }

    void println(double[] ts, boolean newline) {
      StringBuilder sb = new StringBuilder();
      for (double t : ts) {
        sb.append(t);
        sb.append((newline ? "\n" : " "));
      }
      if (sb.length() > 0) {
        sb.deleteCharAt(sb.length() - 1);
      }
      pw.println(sb.toString());
    }

    <T> void println(T[] ts, boolean newline) {
      println(Arrays.asList(ts), newline);
    }

    <T> void println(Collection<T> ts, boolean newline) {
      StringBuilder sb = new StringBuilder();
      for (T t : ts) {
        sb.append(t.toString());
        sb.append((newline ? "\n" : " "));
      }
      if (sb.length() > 0) {
        sb.deleteCharAt(sb.length() - 1);
      }
      pw.println(sb.toString());
    }

    <T, U> void println(Map<T, U> ts, boolean newline) {
      StringBuilder sb = new StringBuilder();
      for (Map.Entry<T, U> t : ts.entrySet()) {
        sb.append(t.getKey().toString());
        sb.append(" -> ");
        sb.append(t.getValue().toString());
        sb.append((newline ? "\n" : " "));
      }
      if (sb.length() > 0) {
        sb.deleteCharAt(sb.length() - 1);
      }
      pw.println(sb.toString());
    }

    void println(int[][] tss) {
      StringBuilder sb = new StringBuilder();
      for (int[] ts : tss) {
        for (int t : ts) {
          sb.append(t).append(" ");
        }
        if (ts.length > 0) {
          sb.setCharAt(sb.length() - 1, '\n');
        } else {
          sb.append('\n');
        }
      }
      pw.print(sb.toString());
      pw.flush();
    }

    void println(long[][] tss) {
      StringBuilder sb = new StringBuilder();
      for (long[] ts : tss) {
        for (long t : ts) {
          sb.append(t).append(" ");
        }
        if (ts.length > 0) {
          sb.setCharAt(sb.length() - 1, '\n');
        } else {
          sb.append('\n');
        }
      }
      pw.print(sb.toString());
      pw.flush();
    }

    void println(double[][] tss) {
      StringBuilder sb = new StringBuilder();
      for (double[] ts : tss) {
        for (double t : ts) {
          sb.append(t).append(" ");
        }
        if (ts.length > 0) {
          sb.setCharAt(sb.length() - 1, '\n');
        } else {
          sb.append('\n');
        }
      }
      pw.print(sb.toString());
      pw.flush();
    }
  }

  static class MyScanner {
    InputStreamReader is;
    BufferedReader br;
    StringTokenizer st;

    MyScanner() {
      this.is = new InputStreamReader(System.in);
      this.br = new BufferedReader(is);
    }

    void findToken() {
      while (st == null || !st.hasMoreTokens()) {
        try {
          st = new StringTokenizer(br.readLine());
        } catch (IOException e) {
          throw new RuntimeException(e);
        }
      }
    }

    String next() {
      findToken();
      return st.nextToken();
    }

    String nextLine() {
      String str = "";
      try {
        str = br.readLine();
      } catch (IOException e) {
        e.printStackTrace();
      }
      return str;
    }

    int nextInt() {
      return Integer.parseInt(next());
    }

    int[] nextInts(int n) {
      return nextInts(n, false);
    }

    int[] nextInts(int n, boolean oneBased) {
      if (oneBased) {
        return nextInts(n, 1, n + 1);
      } else {
        return nextInts(n, 0, n);
      }
    }

    int[] nextInts(int n, int iMin, int iMax) {
      int[] ints = new int[iMax];
      for (int i = iMin; i < iMax; ++i) {
        ints[i] = nextInt();
      }
      return ints;
    }

    long nextLong() {
      return Long.parseLong(next());
    }

    long[] id8(int n) {
      return id8(n, false);
    }

    long[] id8(int n, boolean oneBased) {
      if (oneBased) {
        return id8(n, 1, n + 1);
      } else {
        return id8(n, 0, n);
      }
    }

    long[] id8(int n, int iMin, int iMax) {
      long[] longs = new long[iMax];
      for (int i = iMin; i < iMax; ++i) {
        longs[i] = nextLong();
      }
      return longs;
    }

    double nextDouble() {
      return Double.parseDouble(next());
    }

    double[] id7(int n) {
      return id7(n, false);
    }

    double[] id7(int n, boolean oneBased) {
      if (oneBased) {
        return id7(n, 1, n + 1);
      } else {
        return id7(n, 0, n);
      }
    }

    double[] id7(int n, int iMin, int iMax) {
      double[] doubles = new double[iMax];
      for (int i = iMin; i < iMax; ++i) {
        doubles[i] = nextDouble();
      }
      return doubles;
    }
  }

  static class RandScanner {
    ThreadLocalRandom r;

    RandScanner() {
      this.r = ThreadLocalRandom.current();
    }

    int nextInt() {
      return r.nextInt();
    }

    int nextInt(int id1) {
      return r.nextInt(id1);
    }

    int nextInt(int id10, int id1) {
      return r.nextInt(id10, id1);
    }

    int[] nextInts(int n) {
      return nextInts(n, false);
    }

    int[] nextInts(int n, int id1) {
      return nextInts(n, false, id1);
    }

    int[] nextInts(int n, int id10, int id1) {
      return nextInts(n, false, id10, id1);
    }

    int[] nextInts(int n, boolean oneBased) {
      int iMin = oneBased ? 1 : 0;
      int iMax = oneBased ? n + 1 : n;
      int[] ints = new int[iMax];
      for (int i = iMin; i < iMax; ++i) {
        ints[i] = nextInt();
      }
      return ints;
    }

    int[] nextInts(int n, boolean oneBased, int id1) {
      int iMin = oneBased ? 1 : 0;
      int iMax = oneBased ? n + 1 : n;
      int[] ints = new int[iMax];
      for (int i = iMin; i < iMax; ++i) {
        ints[i] = nextInt(id1);
      }
      return ints;
    }

    int[] nextInts(int n, boolean oneBased, int id10, int id1) {
      int iMin = oneBased ? 1 : 0;
      int iMax = oneBased ? n + 1 : n;
      int[] ints = new int[iMax];
      for (int i = iMin; i < iMax; ++i) {
        ints[i] = nextInt(id10, id1);
      }
      return ints;
    }

    long nextLong() {
      return r.nextLong();
    }

    long nextLong(long id1) {
      return r.nextLong(id1);
    }

    long nextLong(long id10, long id1) {
      return r.nextLong(id10, id1);
    }

    long[] id8(int n) {
      return id8(n, false);
    }

    long[] id8(int n, long id1) {
      return id8(n, false, id1);
    }

    long[] id8(int n, long id10, long id1) {
      return id8(n, false, id10, id1);
    }

    long[] id8(int n, boolean oneBased) {
      int iMin = oneBased ? 1 : 0;
      int iMax = oneBased ? n + 1 : n;
      long[] longs = new long[iMax];
      for (int i = iMin; i < iMax; ++i) {
        longs[i] = nextLong();
      }
      return longs;
    }

    long[] id8(int n, boolean oneBased, long id1) {
      int iMin = oneBased ? 1 : 0;
      int iMax = oneBased ? n + 1 : n;
      long[] longs = new long[iMax];
      for (int i = iMin; i < iMax; ++i) {
        longs[i] = nextLong(id1);
      }
      return longs;
    }

    long[] id8(int n, boolean oneBased, long id10, long id1) {
      int iMin = oneBased ? 1 : 0;
      int iMax = oneBased ? n + 1 : n;
      long[] longs = new long[iMax];
      for (int i = iMin; i < iMax; ++i) {
        longs[i] = nextLong(id10, id1);
      }
      return longs;
    }

    double nextDouble() {
      return r.nextDouble();
    }

    double nextDouble(double id1) {
      return r.nextDouble(id1);
    }

    double nextDouble(double id10, double id1) {
      return r.nextDouble(id10, id1);
    }

    double[] id7(int n) {
      return id7(n, false);
    }

    double[] id7(int n, double id1) {
      return id7(n, false, id1);
    }

    double[] id7(int n, double id10, double id1) {
      return id7(n, false, id10, id1);
    }

    double[] id7(int n, boolean oneBased) {
      int iMin = oneBased ? 1 : 0;
      int iMax = oneBased ? n + 1 : n;
      double[] doubles = new double[iMax];
      for (int i = iMin; i < iMax; ++i) {
        doubles[i] = nextDouble();
      }
      return doubles;
    }

    double[] id7(int n, boolean oneBased, double id1) {
      int iMin = oneBased ? 1 : 0;
      int iMax = oneBased ? n + 1 : n;
      double[] doubles = new double[iMax];
      for (int i = iMin; i < iMax; ++i) {
        doubles[i] = nextDouble(id1);
      }
      return doubles;
    }

    double[] id7(
        int n, boolean oneBased, double id10, double id1) {
      int iMin = oneBased ? 1 : 0;
      int iMax = oneBased ? n + 1 : n;
      double[] doubles = new double[iMax];
      for (int i = iMin; i < iMax; ++i) {
        doubles[i] = nextDouble(id10, id1);
      }
      return doubles;
    }
  }
}
