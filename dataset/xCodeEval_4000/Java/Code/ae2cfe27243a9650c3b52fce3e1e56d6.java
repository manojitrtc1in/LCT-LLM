


import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.lang.invoke.MethodHandles;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Random;
import java.util.StringTokenizer;









































































































public class C1662B {
  static final int MOD = 998244353;
  static final Random RAND = new Random();

  

  static List<char[]> solve(String s0, String s1, String s2) {
    String[] s = new String[] {s0, s1, s2};
    Arrays.sort(s, (x,y)-> y.length() - x.length());

    int[][] freq = new int[3][26];
    for (int i = 0; i < 3; i++) {
      for(char c : s[i].toCharArray()) {
        freq[i][c-'A']++;
      }
    }

    int npairs = 0;
    for (int c = 0; c < 26; c++) {
      int[] r = {freq[0][c], freq[1][c], freq[2][c]};
      Arrays.sort(r);
      int plus = Math.min(r[0] + r[1], (r[0] + r[1] + r[2]) / 2);
      npairs += plus;
    }
    int l = s[0].length();

    List<char[]> cards = new ArrayList<>();

    while (true) {
      int wild = 3 * l - s[0].length() - s[1].length() - s[2].length();
      if (wild + npairs >= l) {
        CharSet[] cs = new CharSet[3];
        for (int i = 0; i < 3; i++) {
          cs[i] = new CharSet(s[i], l);
          myAssert(cs[i].size() == l);
        }

        List<List<Integer>> pairs = new ArrayList<>();
        for (int i = 0; i < 3; i++) {
          pairs.add(new ArrayList<>());
        }

        int pairsMade = 0;

        for (int c = 0; c < 26; c++) {
          while (pairsMade < l) {
            List<Integer> ord = new ArrayList<>(Arrays.asList(0,1,2));
            final int f = c;
            Collections.sort(ord, (x,y) -> freq[x][f] - freq[y][f]);

            int a = ord.get(1);
            int b = ord.get(2);
            if (freq[a][c] > 0 && freq[b][c] > 0) {
              if (pairsMade < l) {
                freq[a][c]--;
                freq[b][c]--;
                cs[a].erase(c);
                cs[b].erase(c);
                pairs.get(3-a-b).add(c);
                pairsMade++;
              }
            } else {
              break;
            }
          }
        }

        while (pairsMade < l) {
          boolean done = false;
          for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
              if (i == j) {
                continue;
              }
              if (cs[i].empty() || cs[j].empty()) {
                continue;
              }
              if (cs[i].count(26) > 0) {
                int a = cs[j].begin();
                if (a != 26) {
                  if (pairsMade < l) {
                    cs[i].erase(26);
                    cs[j].erase(a);
                    pairs.get(3-i-j).add(a);
                    pairsMade++;
                    done = true;
                  }
                }
              }
            }
          }
          if(!done) {
            break;
          }
        }

        while (pairsMade < l) {
          boolean done = false;
          for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
              if (i == j) {
                continue;
              }
              if (cs[i].empty() || cs[j].empty()) {
                continue;
              }
              if (cs[i].count(26) > 0) {
                int a = cs[j].begin();
                if (true) {
                  if (pairsMade < l){
                    cs[i].erase(26);
                    cs[j].erase(a);
                    pairs.get(3-i-j).add(a);
                    pairsMade++;
                    done = true;
                  }
                }
              }
            }
          }
          if(!done) {
            break;
          }
        }

        if (pairsMade >= l) {
          for (int i = 0; i < 3; i++){
            for (int a : pairs.get(i)) {
              assert(!cs[i].empty());
              int b = cs[i].begin();
              cs[i].erase(b);
              a = Math.min(a, 25);
              b = Math.min(b, 25);
              cards.add(new char[] {(char) (a + 'A'), (char) (b + 'A')});
            }
          }
          break;
        }
      }
      l++;
    }
    return cards;
  }

  static class CharSet {
    int[] ct = new int[27];
    int size = 0;

    public CharSet(String s, int l) {
      for (char c : s.toCharArray()) {
        ct[c - 'A']++;
      }
      ct[26] += l - s.length();
      size = l;
    }

    public void erase(int id) {
      myAssert(ct[id] > 0);
      ct[id]--;
      size--;
    }

    public int begin() {
      for (int i = 0; i < 27; i++) {
        if (ct[i] > 0) {
          return i;
        }
      }
      return 27;
    }

    public int count(int id) {
      return ct[id];
    }

    public int size() {
      return size;
    }

    public boolean empty() {
      return size == 0;
    }
  }

  

  static boolean verify(List<char[]> cards, String s) {
    int[] ct = getCharCount(s);
    int m = cards.size();
    int r = s.length();
    boolean[] used = new boolean[m];
    boolean reduce = true;
    while (reduce) {
      reduce = false;
      for (int i = 0; i < m; i++) {
        char[] card = cards.get(i);
        int j0 = card[0] - 'A';
        int j1 = card[1] - 'A';
        if (ct[j0] == 0 && ct[j1] > 0) {
          ct[j1]--;
          used[i] = true;
          r--;
          reduce = true;
        } else if (ct[j0] > 0 && ct[j1] == 0) {
          ct[j0]--;
          used[i] = true;
          r--;
          reduce = true;
        }
      }
    }
    if (r == 0) {
      return true;
    }
    for (int i = 0; i < m; i++) {
      char[] card = cards.get(i);
      int j0 = card[0] - 'A';
      int j1 = card[1] - 'A';
      if (ct[j0] > 0) {
        ct[j0]--;
        used[i] = true;
        r--;
      } else if (ct[j1] > 0) {
        ct[j1]--;
        used[i] = true;
        r--;
      }
    }
    return r == 0;
  }

  static Queue<Character> getCharQueue(int[] ct) {
    Queue<Character> q = new LinkedList<>();
    for (int i = 0; i < 26; i++) {
      char c = (char) ('A' + i);
      for (int j = 0; j < ct[i]; j++) {
        q.add(c);
      }
    }
    return q;
  }

  static int[] getCharCount(String s) {
    int[] ct = new int[26];
    for (char c : s.toCharArray()) {
      ct[c-'A']++;
    }
    return ct;
  }

  static int[] getCommonCount(int[] ct0, int[] ct1) {
    int[] ct = new int[26];
    for (int i = 0; i < 26; i++) {
      ct[i] = Math.min(ct0[i], ct1[i]);
    }
    return ct;
  }

  static int[] getCommonCount(int[] ct0, int[] ct1, int[] ct2) {
    int[] ct = new int[26];
    for (int i = 0; i < 26; i++) {
      ct[i] = Math.min(Math.min(ct0[i], ct1[i]), ct2[i]);
    }
    return ct;
  }

  static void test(int exp, String s1, String s2, String s3) {
    List<char[]> cards = solve(s1, s2, s3);
    output(cards);
    myAssert(verify(cards, s1));
    myAssert(verify(cards, s2));
    myAssert(verify(cards, s3));
    myAssert(cards.size() == exp);
  }

  static boolean test = false;
  static void doTest() {
    if (!test) {
      return;
    }
    long t0 = System.currentTimeMillis();
    test(3, "AAB", "AAC", "AAD");
    test(2, "AA", "GA", "MA");
    test(8, "TEDDY", "HEDWIG", "RACCOON");
    test(4, "BDC", "CAA", "CE");
    System.out.format("%d msec\n", System.currentTimeMillis() - t0);
    System.exit(0);
  }

  public static void main(String[] args) {
    doTest();
    MyScanner in = new MyScanner();
    String t = in.next();
    String o = in.next();
    String r = in.next();
    List<char[]> ans = solve(t, o, r);
    output(ans);
  }

  static void output(List<char[]> al) {
    StringBuilder sb = new StringBuilder();
    sb.append(al.size());
    sb.append('\n');
    for (char[] v : al) {
      sb.append(v[0]);
      sb.append(v[1]);
      sb.append('\n');
      if (sb.length() > 500) {
        System.out.print(sb.toString());
        sb.setLength(0);
      }
    }
    System.out.print(sb.toString());
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
