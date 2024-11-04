


















































































































































import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.lang.invoke.MethodHandles;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Random;
import java.util.StringTokenizer;

public class C1705F {
  static final int MOD = 998244353;
  static final Random RAND = new Random();

  static void solve(int n, MyScanner in, Judge judge) {
    char[] allt = new char[n];
    Arrays.fill(allt, 'T');

    char[] alltf = new char[n];
    Arrays.fill(alltf, 'T');

    char[] ans = new char[n];
    Arrays.fill(ans, '?');

    for (int i = 1; i < n; i += 2) {
      alltf[i] = 'F';
    }

    int cntt = askexit(allt, in, judge);
    int cnttf = askexit(alltf, in, judge);
    int l = 0;
    int r = n-1;

    char[] s = new char[n];
    while (l <= r) {
      

      if (l == r) {
        System.arraycopy(allt, 0, s, 0, n);
        s[l] = 'F';
        int x = askexit(s, in, judge);
        if (x < cntt) {
          ans[l] = 'T';
        } else {
          ans[l] = 'F';
        }
        break;
      }

      System.arraycopy(allt, 0, s, 0, n);
      s[l] = 'F';
      s[l+1] = 'F';
      int x = askexit(s, in, judge);
      if (x < cntt) {
        ans[l] = 'T';
        ans[l+1] ='T';
        l += 2;
        continue;
      }
      if (x > cntt) {
        ans[l] = 'F';
        ans[l+1] = 'F';
        l += 2;
        continue;
      }

      System.arraycopy(alltf, 0, s, 0, n);
      s[l] = s[l] == 'T' ? 'F' : 'T';
      s[l+1] = s[l+1] == 'T' ? 'F' : 'T';
      s[r] = s[r] == 'T' ? 'F' : 'T';
      x = askexit(s, in, judge);
      if (x == cnttf + 3) {
        ans[l] = s[l];
        ans[l+1] = s[l+1];
        ans[r] = s[r];
      } else if (x == cnttf + 1) {
        ans[l] = s[l];
        ans[l+1] = s[l+1];
        ans[r] = s[r] == 'T' ? 'F' : 'T';
      } else if (x == cnttf - 1) {
        ans[l] = s[l] == 'T' ? 'F' : 'T';
        ans[l+1] = s[l+1] == 'T' ? 'F' : 'T';
        ans[r] = s[r];
      } else {
        ans[l] = s[l] == 'T' ? 'F' : 'T';
        ans[l+1] = s[l+1] == 'T' ? 'F' : 'T';
        ans[r] = s[r] == 'T' ? 'F' : 'T';
      }
      l += 2;
      r--;
    }
    askexit(ans, in, judge);
  }

  static int askexit(char[] ca, MyScanner in, Judge judge) {
    int ans = 0;
    if (in != null) {
      System.out.format("%s\n", new String(ca));
      System.out.flush();
      ans = in.nextInt();
    } else {
      ans = judge.ask(ca);
    }
    if (ans == ca.length) {
      System.exit(0);
    }
    return ans;
  }

  

  

  

  

  static void solveA(int n, MyScanner in, Judge judge) {
    State state = new State(n, in, judge);
    state.solve();
  }

  static class State {
    int n;
    MyScanner in;
    Judge judge;
    char[] ans;
    int score;

    public State(int n, MyScanner in, Judge judge) {
      this.n = n;
      this.in = in;
      this.judge = judge;
      this.ans = new char[n];
      Arrays.fill(ans, 'F');
      this.score = ask(ans, in, judge);
    }

    public void solve() {
      if ((!test && n < 674) || (test && n <= 5)) {
        int idx = 0;
        while (score != n) {
          ans[idx] = 'T';
          int ret = ask(ans, in, judge);
          if (ret == score + 1) {
            score = ret;
          } else if (ret == score - 1) {
            ans[idx] = 'F';
          }
          idx++;
        }
        return;
      }

      List<Integer> idxes = new ArrayList<>();
      for (int i = 0; i < n; i++) {
        idxes.add(i);
      }
      Collections.shuffle(idxes);

      

      List<int[]> curr = new ArrayList<>();
      int sum = 0;
      for (int i = 0; i < n - 1; i += 2) {
        int idx0 = idxes.get(i);
        int idx1 = idxes.get(i + 1);
        ans[idx0] = 'T';
        ans[idx1] = 'T';
        int ret = ask(ans, in, judge);
        if (ret == score + 2) {
          

          score = ret;
          sum += 2;
        } else if (ret == score) {
          

          ans[idx0] = 'F';
          ans[idx1] = 'F';
          curr.add(new int[] {idx0, idx1});
          sum += 1;
        } else if (ret == score - 2) {
          

          ans[idx0] = 'F';
          ans[idx1] = 'F';
          sum += 2;
        }
        

        myAssert(judge == null || judge.getScore(ans) == score);
      }

      boolean refreshedJudge = true;
      if (n % 2 == 1) {
        

        

        myAssert(sum == score || sum == score - 1);
        if (score == sum) {
          

          ans[idxes.get(n-1)] = 'T';
          score++;
          refreshedJudge = false;
        }
        myAssert(judge == null || judge.getScore(ans) == score);
      }
      solvePairs(curr);

      myAssert(judge == null || judge.getScore(ans) == n);

      if (!refreshedJudge && n == score) {
        myAssert(n == ask(ans, in, judge));
      }
    }

    private void solvePairs(List<int[]> curr) {
      if (score == n || curr.isEmpty()) {
        return;
      }
      

      

      int m = curr.size();
      List<int[]> next = new ArrayList<>();
      Map<Integer, Integer> pm = new HashMap<>();
      for (int i = 0; score < n && i < m - 1; i += 2) {
        int[] e0 = curr.get(i);
        int[] e1 = curr.get(i + 1);
        int idx0 = e0[0];
        int idx1 = e1[0];
        pm.put(idx0, idx1);
        ans[idx0] = 'T';
        ans[idx1] = 'T';
        int ret = ask(ans, in, judge);
        if (ret == score + 2) {
          

          score = ret;
        } else if (ret == score) {
          

          ans[idx0] = 'F';
          ans[idx1] = 'F';
          next.add(new int[] {idx0, idx1});
        } else if (ret == score - 2) {
          

          ans[idx0] = 'F';
          ans[idx1] = 'F';
        }
        

        myAssert(judge == null || judge.getScore(ans) == score);
      }

      boolean refreshedJudge = true;

      if (score < n && m % 2 == 1) {
        int[] e = curr.get(m-1);
        int idx0 = e[0];
        int idx1 = e[1];
        ans[idx0] = 'T';
        int ret = ask(ans, in, judge);
        if (ret == score + 1) {
          

          score = ret;
        } else if (ret == score - 1) {
          

          ans[idx0] = 'F';
          ans[idx1] = 'T';
          score++;
          refreshedJudge = false;
        } else {
          myAssert(false);
        }
        

        myAssert(judge == null || judge.getScore(ans) == score);
      }

      

      solvePairs(next);

      for (int[] e : curr) {
        int idx0 = e[0];
        int idx1 = e[1];
        

        if (ans[idx0] == 'F' && ans[idx1] == 'F') {
          ans[idx1] = 'T';
          score++;
          refreshedJudge = false;
        }
      }

      if (!refreshedJudge && score == n) {
        myAssert(n == ask(ans, in, judge));
      }
    }
  }

  static String trace(char[] ca) {
    int n = ca.length;
    char[] arr = new char[n];
    for (int i = 0; i < n; i++) {
      arr[i] = (ca[i] == 'T' || ca[i] == '1') ? '1' : '0';
    }
    return new String(arr);
  }

  static int ask(char[] ca, MyScanner in, Judge judge) {
    if (in != null) {
      System.out.format("%s\n", new String(ca));
      System.out.flush();
      return in.nextInt();
    } else {
      return judge.ask(ca);
    }
  }

  static class Judge {
    int n;
    char[] ans;
    int idx = 0;

    public Judge(String s) {
      this.n = s.length();
      this.ans = s.toCharArray();
      System.out.format("  judge:    %s\n", trace(ans));
    }

    public Judge(int n) {
      this.n = n;
      this.ans = new char[n];
      for (int i = 0; i < n; i++) {
        ans[i] = RAND.nextBoolean() ? 'T' : 'F';
      }
      System.out.format("  judge:    %s\n", trace(ans));
    }

    public int ask(char[] ca) {
      idx++;
      myAssert(idx <= 675);
      int score = getScore(ca);
      System.out.format("    ask %3d %s score:%d\n", idx, trace(ca), score);
      return score;
    }

    public int getScore(char[] ca) {
      int score = 0;
      for (int i = 0; i < n; i++) {
        if (ans[i] == ca[i]) {
          score++;
        }
      }
      return score;
    }
  }

  static boolean test = false;
  static void doTest() {
    if (!test) {
      return;
    }
    long t0 = System.currentTimeMillis();
    

    Judge judge = new Judge(10);
    solve(judge.n, null, judge);
    System.out.format("%d msec\n", System.currentTimeMillis() - t0);
    System.exit(0);
  }

  public static void main(String[] args) {
    doTest();
    MyScanner in = new MyScanner();
    int n = in.nextInt();
    solve(n, in, null);
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
        String cname = MethodHandles.lookup().lookupClass().getCanonicalName().replace(".MyScanner", "");
        cname = cname.lastIndexOf('.') > 0 ? cname.substring(cname.lastIndexOf('.') + 1) : cname;
        final File fin = new File(USERDIR + "/io/c" + cname.substring(1,5) + "/" + cname + ".in");
        br = new BufferedReader(new InputStreamReader(fin.exists()
            ? new FileInputStream(fin) : System.in));
      } catch (Exception e) {
        br = new BufferedReader(new InputStreamReader(System.in));
      }
    }

    public String next() {
      try {
        while (st == null || !st.hasMoreElements()) {
          st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
      } catch (Exception e) {
        throw new RuntimeException(e);
      }
    }

    public int nextInt() {
      return Integer.parseInt(next());
    }

    public long nextLong() {
      return Long.parseLong(next());
    }
  }
}
