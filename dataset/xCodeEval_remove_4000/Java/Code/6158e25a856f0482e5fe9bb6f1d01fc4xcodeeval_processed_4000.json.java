import java.io.*;
import java.lang.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.function.*;

public class F {
  public static void main(String[] args) {
    int n = in.nextInt();
    int m = in.nextInt();
    long[] x = in.id4(n, true);
    long[][] pc = new long[m + 1][2];
    
    
    
    
    long totalCapacity = 0;
    for (int i = 1; i <= m; ++i) {
      pc[i][0] = in.nextLong();
      
      pc[i][1] = in.nextLong();
      
      totalCapacity += pc[i][1];
      
      
      
      
      
      
      
      
      
      
    }
    

    out.println(id7(n, m, x, pc, totalCapacity));
  }

  static long dpOnly(int n, int m, long[] x, long[][] pc, long totalCapacity) {

    Arrays.sort(x, 1, n + 1);
    Arrays.sort(pc, 1, m + 1, (long[] pc1, long[] pc2) -> Long.compare(pc1[0], pc2[0]));

    if (totalCapacity < n) {
      return -1;
    }

    long[][] M = new long[m + 1][n + 1];
    M[1][1] = Math.abs(x[1] - pc[1][0]);
    for (int j = 2; j <= n; ++j) {
      M[1][j] = j <= pc[1][1] ? M[1][j - 1] + Math.abs(x[j] - pc[1][0]) : -1;
    }

    for (int i = 2; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        long mij = M[i - 1][j];
        long dist = 0;
        for (int k = 0; k < j && k < pc[i][1]; ++k) {
          dist += Math.abs(x[j - k] - pc[i][0]);
          if (M[i - 1][j - k - 1] != -1) {
            mij =
                mij != -1 ? Math.min(mij, M[i - 1][j - k - 1] + dist) : M[i - 1][j - k - 1] + dist;
          }
        }
        M[i][j] = mij;
      }
    }
    

    return M[m][n];
  }

  static long id7(int n, int m, long[] x, long[][] pc, long totalCapacity) {
    Arrays.sort(x, 1, n + 1);
    Arrays.sort(pc, 1, m + 1, (long[] pc1, long[] pc2) -> Long.compare(pc1[0], pc2[0]));

    if (totalCapacity < n) {
      return -1;
    }

    long[][] M = new long[m + 1][n + 1];
    M[1][1] = Math.abs(x[1] - pc[1][0]);
    for (int j = 2; j <= n; ++j) {
      M[1][j] = j <= pc[1][1] ? M[1][j - 1] + Math.abs(x[j] - pc[1][0]) : -1;
    }

    id3 mmql = new id3(n);
    for (int i = 2; i <= m; ++i) {
      long dist = 0;
      
      
      
      
      int j1 = 0;
      for (int j = 0; j <= n && M[i - 1][j] != -1; ++j, ++j1) {
        
        dist += Math.abs(x[j] - pc[i][0]);
        mmql.enqueue(M[i - 1][j] - dist);
        

        M[i][j] = mmql.getMin() + dist;
        if (mmql.size() > pc[i][1]) {
          mmql.dequeue();
        }
      }
      int j2 = j1;
      for (int j = 0; j1 + j <= n && j < pc[i][1]; ++j, ++j2) {
        if (mmql.size() > pc[i][1] - j) {
          mmql.dequeue();
        }
        
        dist += Math.abs(x[j1 + j] - pc[i][0]);
        

        M[i][j1 + j] = mmql.getMin() + dist;
      }

      for (int j = 0; j2 + j <= n; ++j) {
        M[i][j2 + j] = -1;
      }
      mmql.reset();
    }
    
    return M[m][n];
  }

  static MyScanner in = new MyScanner();
  static id0 out = new id0();
  static RandScanner rand = new RandScanner();

  static class id0 {
    BufferedOutputStream bos;
    PrintWriter pw;

    id0() {
      this.bos = new BufferedOutputStream(System.out);
      this.pw = new PrintWriter(bos, true);
    }

    void flush() {
      pw.flush();
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

    long[] id4(int n) {
      return id4(n, false);
    }

    long[] id4(int n, boolean oneBased) {
      if (oneBased) {
        return id4(n, 1, n + 1);
      } else {
        return id4(n, 0, n);
      }
    }

    long[] id4(int n, int iMin, int iMax) {
      long[] longs = new long[iMax];
      for (int i = iMin; i < iMax; ++i) {
        longs[i] = nextLong();
      }
      return longs;
    }

    double nextDouble() {
      return Double.parseDouble(next());
    }

    double[] id2(int n) {
      return id2(n, false);
    }

    double[] id2(int n, boolean oneBased) {
      if (oneBased) {
        return id2(n, 1, n + 1);
      } else {
        return id2(n, 0, n);
      }
    }

    double[] id2(int n, int iMin, int iMax) {
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
      return nextInt(0, Integer.MAX_VALUE);
    }

    int nextInt(int lowerBound, int upperBound) {
      return r.nextInt(lowerBound, upperBound);
    }

    int[] nextInts(int n) {
      return nextInts(n, 0, Integer.MAX_VALUE);
    }

    int[] nextInts(int n, int lowerBound, int upperBound) {
      return nextInts(n, false, lowerBound, upperBound);
    }

    int[] nextInts(int n, boolean oneBased) {
      return nextInts(n, oneBased, 0, Integer.MAX_VALUE);
    }

    int[] nextInts(int n, boolean oneBased, int lowerBound, int upperBound) {
      if (oneBased) {
        return nextInts(n, 1, n + 1, lowerBound, upperBound);
      } else {
        return nextInts(n, 0, n, lowerBound, upperBound);
      }
    }

    

    

    


    int[] nextInts(int n, int iMin, int iMax, int lowerBound, int upperBound) {
      int[] ints = new int[iMax];
      for (int i = iMin; i < iMax; ++i) {
        ints[i] = nextInt(lowerBound, upperBound);
      }
      return ints;
    }

    long nextLong() {
      return nextLong(0L, Long.MAX_VALUE);
    }

    long nextLong(long lowerBound, long upperBound) {
      return r.nextLong(lowerBound, upperBound);
    }

    long[] id4(int n) {
      return id4(n, 0L, Long.MAX_VALUE);
    }

    long[] id4(int n, long lowerBound, long upperBound) {
      return id4(n, false, lowerBound, upperBound);
    }

    long[] id4(int n, boolean oneBased) {
      return id4(n, oneBased, 0L, Long.MAX_VALUE);
    }

    long[] id4(int n, boolean oneBased, long lowerBound, long upperBound) {
      if (oneBased) {
        return id4(n, 1, n + 1, lowerBound, upperBound);
      } else {
        return id4(n, 0, n, lowerBound, upperBound);
      }
    }

    

    

    


    long[] id4(int n, int iMin, int iMax, long lowerBound, long upperBound) {
      long[] longs = new long[iMax];
      for (int i = iMin; i < iMax; ++i) {
        longs[i] = nextLong(lowerBound, upperBound);
      }
      return longs;
    }

    double nextDouble() {
      return nextDouble(0, 1);
    }

    double nextDouble(double lowerBound, double upperBound) {
      return r.nextDouble(lowerBound, upperBound);
    }

    double[] id2(int n) {
      return id2(n, 0, 1);
    }

    double[] id2(int n, double lowerBound, double upperBound) {
      return id2(n, false, lowerBound, upperBound);
    }

    double[] id2(int n, boolean oneBased) {
      return id2(n, oneBased, 0, 1);
    }

    double[] id2(int n, boolean oneBased, double lowerBound, double upperBound) {
      if (oneBased) {
        return id2(n, 1, n + 1, lowerBound, upperBound);
      } else {
        return id2(n, 0, n, lowerBound, upperBound);
      }
    }

    

    

    


    double[] id2(int n, int iMin, int iMax, double lowerBound, double upperBound) {
      double[] doubles = new double[iMax];
      for (int i = iMin; i < iMax; ++i) {
        doubles[i] = nextDouble(lowerBound, upperBound);
      }
      return doubles;
    }
  }

  static class id6 {
    long[][] stack;
    int top;

    id6(int capacity) {
      stack = new long[capacity][2];
      top = -1;
    }

    long getMax() {
      return stack[top][2];
    }

    long getMin() {
      return stack[top][1];
    }

    boolean isEmpty() {
      return top == -1;
    }

    long pop() {
      
      
      
      return stack[top--][0];
    }

    void push(long i) {
      if (top == stack.length - 1) {
        int id5 = stack.length;
        int id1 = id5 * 2;
        stack = Arrays.copyOf(stack, id1);
        for (int j = id5; j < id1; ++j) {
          stack[j] = new long[2];
        }
      }
      top++;
      stack[top][0] = i;
      stack[top][1] = top == 0 ? i : Math.min(i, stack[top - 1][1]);
      
    }

    void reset() {
      top = -1;
    }

    int size() {
      return top + 1;
    }

    public String toString() {
      StringBuilder sb = new StringBuilder(stack.length * 6);
      for (int j = 0; j < 3; ++j) {
        toString(sb, j, false);
        sb.append("\n");
      }
      return sb.toString();
    }

    void toString(StringBuilder sb, int j, boolean reversed) {
      if (reversed) {
        for (int i = 0; i < size(); ++i) {
          sb.append(stack[i][j] + " ");
        }
      } else {
        for (int i = 0; i < size(); ++i) {
          sb.append(stack[size() - i - 1][j] + " ");
        }
      }
      if (size() > 0) {
        sb.deleteCharAt(sb.length() - 1);
      }
    }
  }

  static class id3 {
    id6 stackIn;
    id6 stackOut;

    id3(int queueCapacity) {
      stackIn = new id6(queueCapacity);
      stackOut = new id6(queueCapacity);
    }

    long dequeue() {
      if (!stackOut.isEmpty()) {
        return stackOut.pop();
      } else {
        while (!stackIn.isEmpty()) {
          stackOut.push(stackIn.pop());
        }
        return stackOut.pop();
      }
    }

    long getMax() {
      return stackIn.isEmpty()
          ? stackOut.getMax()
          : stackOut.isEmpty() ? stackIn.getMax() : Math.max(stackIn.getMax(), stackOut.getMax());
    }

    long getMin() {
      return stackIn.isEmpty()
          ? stackOut.getMin()
          : stackOut.isEmpty() ? stackIn.getMin() : Math.min(stackIn.getMin(), stackOut.getMin());
    }

    boolean isEmpty() {
      return stackIn.isEmpty() && stackOut.isEmpty();
    }

    void enqueue(long i) {
      stackIn.push(i);
    }

    void reset() {
      stackIn.reset();
      stackOut.reset();
    }

    int size() {
      return stackIn.size() + stackOut.size();
    }

    public String toString() {
      StringBuilder sb = new StringBuilder(size() * 6);
      for (int j = 0; j < 3; ++j) {
        stackIn.toString(sb, j, true);
        if (stackIn.size() > 0) {
          sb.append(" ");
        }
        stackOut.toString(sb, j, false);
        sb.append("\n");
      }
      return sb.toString();
    }
  }
}
