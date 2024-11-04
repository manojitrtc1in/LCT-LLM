


import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.invoke.MethodHandles;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Random;
import java.util.Scanner;
import java.util.StringTokenizer;
import java.util.TreeSet;


























































































































































public class C1634D {
  static final int MOD = 998244353;
  static final Random RAND = new Random();

  static void solve(int n, int[] a, MyScanner in) {
    

    if (n == 4) {
      int[] arr = new int[5];
      arr[1] = ask(2, 3, 4, a, in);
      arr[2] = ask(1, 3, 4, a, in);
      arr[3] = ask(1, 2, 4, a, in);
      arr[4] = ask(1, 2, 3, a, in);
      TreeSet<Integer> midxes = new TreeSet<>(getMaxIdxes(arr, 1, n));
      

      

      

      

      

      myAssert(midxes.size() >= 2);
      List<Integer> exclude = new ArrayList<>();
      for (int i = 1; i <= n; i++) {
        if (!midxes.contains(i)) {
          exclude.add(i);
        }
      }
      guess(exclude.get(0), exclude.size() > 1 ? exclude.get(1) : 1, a);
      return;
    }

    int[] ab = new int[n+1];
    for (int k = 3; k <= n; k++) {
      ab[k] = ask(1, 2, k, a, in);
    }
    if (in == null) System.err.format("  ab: %s\n", Arrays.toString(ab));
    

    List<Integer> abmidxes = getMaxIdxes(ab, 3, n);
    if (in == null) System.err.format("  abmidxes: %s\n", traceListInt(abmidxes));

    

    

    

    

    

    

    

    

    

    

    

    if (abmidxes.size() == n - 2) {
      

      

      

      

      int[] a2 = new int[n+1];
      boolean allSmaller = true;
      for (int i = 3; i <= n - 2; i++) {
        a2[i] = ask(i, i+1, i+2, a, in);
        if (a2[i] >= ab[3]) {
          allSmaller = false;
          break;
        }
      }
      if (allSmaller) {
        guess(1, 2, a);
      } else {
        List<Integer> midxes = getMaxIdxes(a2, 3, n);
        myAssert(midxes.size() <= 3);
        int j0 = midxes.get(0);
        int j1 = j0 + 1;
        int j2 = j0 + 2;
        int x = a2[j0];
        int i0 = j2;
        if (ask(1, j1, j2, a, in) < x) {
          i0 = j0;
        } else if (ask(1, j0, j2, a, in) < x) {
          i0 = j1;
        }
        guess(i0, 1, a);
      }
      return;
    } else if (abmidxes.size() == 1) {
      

      

      int i0m = abmidxes.get(0);
      int[] ah = new int[n+1];
      for (int i = 1; i <= n; i++) {
        if (i == i0m) {
          continue;
        }
        int j = getNextSkipOne(n, i, i0m);
        ah[i] = ask(i, j, i0m, a, in);
      }
      if (in == null) System.err.format("  ah: %s\n", Arrays.toString(ah));
      

      List<Integer> ahmidxes = getMaxIdxes(ah, 1, n);
      if (in == null) System.err.format("  ahmidxes: %s\n", traceListInt(ahmidxes));
      

      myAssert(ahmidxes.size() >= 2);
      int j0 = ahmidxes.get(0);
      int j1 = ahmidxes.get(1);
      if (ahmidxes.size() > 2) {
        guess(i0m, j0, a);
      } else {
        

        

        

        

        

        

        

        

        

        

        

        myAssert(j1 == getNextSkipOne(n, j0, i0m) || j0 == getNextSkipOne(n, j1, i0m));
        int im0 = j1 == getNextSkipOne(n, j0, i0m) ? j1 : j0;
        guess(i0m, im0, a);
      }
    } else {
      

      int j0 = abmidxes.get(0);
      int j1 = abmidxes.get(1);
      int[] aj = new int[n+1];
      for (int i = 1; i <= n; i++) {
        if (i == j0 || i == j1) {
          continue;
        }
        aj[i] = ask(i, j0, j1, a, in);
      }
      List<Integer> ajmidxes = getMaxIdxes(aj, 1, n);
      if (ajmidxes.size() == n - 2) {
        guess(j0, j1, a);
      } else {
        myAssert(ajmidxes.size() == 1);
        guess(ajmidxes.get(0), j0, a);
      }
    }
  }

  static int ask(int i, int j, int k, int[] a, MyScanner in) {
    if (in != null) {
      System.out.format("? %d %d %d\n", i, j, k);
      System.out.flush();
      return in.nextInt();
    } else {
      int n = a.length - 1;
      myAssert(i >= 1 && i <= n);
      myAssert(j >= 1 && j <= n);
      myAssert(k >= 1 && k <= n);
      int max = Math.max(Math.max(a[i], a[j]), a[k]);
      int min = Math.min(Math.min(a[i], a[j]), a[k]);
      System.out.format("? %2d %2d %2d -> %d\n", i, j, k, max - min);
      return max - min;
    }
  }

  static boolean guessedOk = false;
  static void guess(int i, int j, int[] a) {
    System.out.format("! %d %d\n", i, j);
    if (a != null) {
      myAssert(a[i] == 0 || a[j] == 0);
      guessedOk = true;
    }
  }

  static boolean isSame(int[] arr, int b, int e) {
    for (int i = b + 1; i <= e; i++) {
      if (arr[i] != arr[b]) {
        return false;
      }
    }
    return true;
  }

  static int getMaxValue(int[] a) {
    int m = 0;
    for (int v : a) {
      m = Math.max(m,  v);
    }
    return m;
  }

  static List<Integer> getMaxIdxes(int[] arr, int b, int e) {
    int max = arr[b];
    for (int i = b + 1; i <= e; i++) {
      max = Math.max(max, arr[i]);
    }
    List<Integer> idxes = new ArrayList<>();
    for (int i = b; i <= e; i++) {
      if (arr[i] == max) {
        idxes.add(i);
      }
    }
    return idxes;
  }

  static List<Integer> getCommon(List<Integer> idxes1, List<Integer> idxes2) {
    List<Integer> idxes = new ArrayList<>();
    int i2 = 0;
    int n2 = idxes2.size();
    for (int v : idxes1) {
      while (i2 < n2 && idxes2.get(i2) < v) {
        i2++;
      }
      if (i2 >= n2) {
        break;
      }
      if (idxes2.get(i2) == v) {
        idxes.add(v);
      }
    }
    return idxes;
  }

  static void doTest() {
    long t0 = System.currentTimeMillis();
    guessedOk = false;
    solve(5, new int[] {0,1, 1, 0,2,2}, null);
    myAssert(guessedOk);
    for (int t = 0; t < 10; t++) {
      int n = 5;
      int[] a = new int[n+1];
      for (int i = 1; i <= n; i++) {
        a[i] = 1 + RAND.nextInt(2);
      }
      int jj = 1 + RAND.nextInt(n);
      a[jj] = 0;
      System.err.format("  a: %s\n", Arrays.toString(a));
      guessedOk = false;
      solve(n, a, null);
      myAssert(guessedOk);
    }
    System.out.format("%d msec\n", System.currentTimeMillis() - t0);
    System.exit(0);
  }

  static int getNextSkipOne(int n, int i, int skip) {
    int j = i + 1;
    if (j == skip) {
      j++;
    }
    if (j == n + 1) {
      j = 1;
    }
    return j;
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

  public static void main(String[] args) {
    

    MyScanner in = new MyScanner();
    int T = in.nextInt();
    for (int t = 1; t <= T; t++) {
      int n = in.nextInt();
      solve(n, null, in);
    }
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

  static void output(int[] a) {
    if (a == null) {
      System.out.println("-1");
      return;
    }
    StringBuilder sb = new StringBuilder();
    for (int v : a) {
      sb.append(v);
      sb.append(' ');
      if (sb.length() > 500) {
        System.out.print(sb.toString());
        sb.setLength(0);
      }
    }
    System.out.println(sb.toString());
  }

  static void myAssert(boolean cond) {
    if (!cond) {
      throw new RuntimeException("Unexpected");
    }
  }

  static class MyScanner {
    BufferedReader br;
    StringTokenizer st;

    public MyScanner() {
      try {
        final String USERDIR = System.getProperty("user.dir");
        String cname = MethodHandles.lookup().lookupClass().getCanonicalName();
        

        int i = cname.lastIndexOf('.');
        if (i > 0) {
          cname = cname.substring(0, i);
        }
        final File fin = new File(USERDIR + "/io/c" + cname.substring(1,5) + "/" + cname + ".in");
        br = new BufferedReader(new InputStreamReader(fin.exists() ? new FileInputStream(fin) : System.in));
      } catch (Exception e) {
        br = new BufferedReader(new InputStreamReader(System.in));
      }
    }

    public String next() {
      while (st == null || !st.hasMoreElements()) {
        try {
          st = new StringTokenizer(br.readLine());
        } catch (IOException e) {
          e.printStackTrace();
        }
      }
      return st.nextToken();
    }

    public int nextInt() {
      return Integer.parseInt(next());
    }

    public long nextLong() {
      return Long.parseLong(next());
    }

    public double nextDouble() {
      return Double.parseDouble(next());
    }
  }
}
