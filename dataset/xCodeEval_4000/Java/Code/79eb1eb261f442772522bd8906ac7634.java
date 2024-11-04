


import java.io.File;
import java.lang.invoke.MethodHandles;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Random;
import java.util.Scanner;








































































































public class C1616E {
  static final int MOD = (int)1e9+7;
  static final Random RAND = new Random();

  static long solve(String s, String t) {
    

    

    long ans = (long) 1e18;
    long cnt = 0;
    int n = s.length();
    int[] a = new int[n + 1];
    for (int i = 1; i <= n; ++i) {
      add(a, i, 1);
    }
    List<Queue<Integer>> qs = new ArrayList<>();
    for (int i = 0; i < 26; i++) {
      qs.add(new LinkedList<Integer>());
    }
    

    

    for (int i = 0; i < n; ++i) {
      int k = s.charAt(i) - 'a';
      qs.get(k).add(i + 1);
    }

    for (int i = 0; i < n; ++i) {
      int x = n + 1;
      int k = t.charAt(i) - 'a';
      for (int j = 0; j < k; ++j) {
        if (!qs.get(j).isEmpty()) {
          x = Math.min(x, qs.get(j).peek());
        }
      }
      

      if (x < n + 1) {
        ans = Math.min(ans, cnt + sum(a, x-1));
      }

      if (!qs.get(k).isEmpty()) {
        x = qs.get(k).poll();
        cnt += sum(a, x-1);
        add(a, x, -1);
      } else {
        break;
      }
    }

    return ans > 1e16 ? -1 : ans;
  }

  static void add(int[] a, int x, int y) {
    int n = a.length - 1;
    

    

    

    for(; x <= n; x += x & -x) {
      a[x] += y;
    }
  }

  static int sum(int[] a, int x) {
    int r = 0;
    for(; x > 0; x -= x & -x) {
      r += a[x];
    }
    return r;
  }

  

  static long solveA(String s, String t) {
    

    String smin = getMinStr(s);
    

    

    

    if (smin.compareTo(t) >= 0) {
      return -1;
    }

    int n = s.length();
    

    

    int[] potential = new int[n];
    int[] scnt = new int[26];
    for (int i = 0; i < n; i++) {
      int idx = s.charAt(i) - 'a';
      for (int j = idx + 1; j < 26; j++) {
        potential[i] += scnt[j];
      }
      scnt[idx]++;
    }
    

    


    

    long ans = 0;
    List<List<Integer>> idxesa = new ArrayList<>();
    for (int i = 0; i < 26; i++) {
      idxesa.add(new ArrayList<>());
    }
    for (int i = 0; i < n; i++) {
      idxesa.get(s.charAt(i) - 'a').add(i);
    }
    int[] iidx = new int[26];
    int prelen = 0;
    boolean[] used = new boolean[n];
    for (int i = 0; i < n; i++) {
      char cht = t.charAt(i);
      int e = indexOf(idxesa, iidx, cht - 'a', used);
      int l = indexOfLess(idxesa, iidx, cht - 'a', used);
      if (l >= 0) {
        prelen = i;
        break;
      }
      used[e] = true;
      ans += potential[e];
      

    }

    

    int m = n - prelen;
    char[] cs = new char[m];
    int idx = 0;
    for (int i = 0; i < n; i++) {
      if (!used[i]) {
        cs[idx++] = s.charAt(i);
      }
    }
    myAssert(idx == m);
    char[] ct = t.substring(prelen).toCharArray();
    

    


    

    ans += solveSuffix(cs, ct, 0, m - 1);
    return ans;
  }

  static int solveSuffix(char[] cs, char[] ct, int i, int bound) {
    int m = cs.length;
    if (i >= m) {
      return bound;
    }

    int i0 = -1;  

    int i1 = -1;  

    for (int j = i; j < m; j++) {
      if (cs[j] < ct[i]) {
        i1 = j;
        break;
      } else if (i0 < 0 && cs[j] == ct[i]) {
        i0 = j;
      }
    }
    

    

    

    

    if (i0 < 0 && i1 < 0) {
      return bound;
    }
    if (i0 < 0) {
      

      return i1 - i;
    }
    int ans = i1 >= 0 ? i1 - i : bound;
    

    

    

    

    

    

    if (i0 - i < ans) {
      

      

      

      if (i0 == i) {
        char c = ct[i];
        int e = i;
        while (e + 1 < m && cs[e + 1] == c && ct[e + 1] == c) {
          e++;
        }
        i = Math.max(i + 1, e);
        ans = Math.min(ans, solveSuffix(cs, ct, i, ans));
      } else {
        for (int j = i0; j > i; j--) {
          cs[j] = cs[j-1];
        }
        cs[i] = ct[i];
        ans = Math.min(ans, i0 - i + solveSuffix(cs, ct, i + 1, ans - i0 + i));
      }
    }
    return ans;
  }

  static String getMinStr(String s) {
    int[] cts = new int[26];
    for (char c : s.toCharArray()) {
      cts[c-'a']++;
    }
    StringBuilder sb = new StringBuilder();
    for (int i = 0; i < 26; i++) {
      for (int j = 0; j < cts[i]; j++) {
        sb.append((char)('a' + i));
      }
    }
    return sb.toString();
  }

  

  

  static int indexOfLess(List<List<Integer>> idxesa, int[] iidx, int ch, boolean[] used) {
    int j = -1;
    for (int k = 0; k < ch; k++) {
      List<Integer> idxes = idxesa.get(k);
      while (iidx[k] < idxes.size()) {
        int idx = idxes.get(iidx[k]);
        

        if (!used[idx]) {
          if (j < 0 || j > idx) {
            j = idx;
          }
          break;
        }
        iidx[k]++;
      }
      if (iidx[k] >= idxes.size()) {
        continue;
      }
    }
    return j;
  }

  

  static int indexOf(List<List<Integer>> idxesa, int[] iidx, int ch, boolean[] used) {
    List<Integer> idxes = idxesa.get(ch);
    while (iidx[ch] < idxes.size()) {
      int idx = idxes.get(iidx[ch]);
      if (!used[idx]) {
        return idx;
      }
      iidx[ch]++;
    }
    return -1;
  }


  static void swap(char[] ca, int i, int j) {
    char t = ca[i];
    ca[i] = ca[j];
    ca[j] = t;
  }

  static void test(long exp, String s, String t) {
    long ans = solve(s, t);
    int n = s.length();
    if (n < 60) {
      System.out.format("%10d <= %s %s\n", ans, s, t);
    } else {
      System.out.format("%10d <= %s(%d)\n", ans, truncateMiddle(s, 80), n);
      System.out.format("%10s    %s(%d)\n", "", truncateMiddle(t, 80), n);
    }
    if (ans != exp) {
      System.out.format("Expected %10d\n", exp);
      myAssert(false);
    }
  }

  public static String truncateMiddle(String value, int m) {
    int n = value.length();
    return n <= m ? value : value.substring(0, m/2) + "..." + value.substring(n-m/2, n);
  }

  static void doTest() {
    long t0 = System.currentTimeMillis();
    
    test(5, "hbhbbb", "bbhbbh");
    test(-1, "a", "a");
    test(0, "rll", "rrr");
    test(2, "caa", "aca");
    test(2, "ababa", "aabba");
    test(5, "hbhbbb", "bbhbbh");
    test(5, "zzyzy", "yzyzy");
    test(349, "zyyxwvutsrqponmlkjihgfedcba", "abcdefghijklmnopqrstuvwxyzz");
    test(1348, "zzyyyxxwwvvuuttssrrqqppoonnmmllkkjjiihhggffeeddccbbaa",
        "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyyzzz");
    test(1, "qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqrp", "qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq");
    System.out.format("%d msec\n", System.currentTimeMillis() - t0);
    System.exit(0);
  }

  public static void main(String[] args) {
    

    Scanner in = getInputScanner();
    int T = in.nextInt();
    for (int q = 1; q <= T; q++) {
      int n = in.nextInt();
      String s = in.next();
      String t = in.next();
      long ans = solve(s, t);
      System.out.println(ans);
    }
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

  static String trace(int[] a) {
    StringBuilder sb = new StringBuilder();
    for (int v : a) {
     if (sb.length() > 0) {
       sb.append(' ');
     }
      sb.append(v);
    }
    return sb.toString();
  }

  static void myAssert(boolean cond) {
    if (!cond) {
      throw new RuntimeException("Unexpected");
    }
  }
}
