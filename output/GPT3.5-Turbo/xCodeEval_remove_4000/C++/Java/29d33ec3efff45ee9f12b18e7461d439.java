import java.util.*;
import java.io.*;

class Main {
    static final long Mod = 1000000007L, INF = 1_000_000_000L, LINF = 1_000_000_000_000_000L;
    static final double Pi = 3.141592653589793116, EPS = 1e-9, Gold = ((1 + Math.sqrt(5)) / 2);
    static final long[] keymod = {1000000007L, 1000000009L, 1000000021L, 1000000033L};
    static final int keyCount = keymod.length;

    static int getbit(long s, int i) {
        return (int) ((s >> i) & 1);
    }

    static long onbit(long s, int i) {
        return s | (1L << i);
    }

    static long offbit(long s, int i) {
        return s & (~(1L << i));
    }

    static int cntbit(long s) {
        return Long.bitCount(s);
    }

    static long[][] id1;
    static String s1, s2, virus;
    static long n1, n2, nv;

    static void proceedVirus() {
        id1 = new long[(int) nv][26];
        for (int i = 0; i < nv; i++) {
            for (int j = 0; j < 26; j++) {
                StringBuilder pref2 = new StringBuilder(virus.substring(0, i));
                pref2.append((char) (65 + j));
                for (int x = i + 1; x >= 0; x--) {
                    if (pref2.substring(i + 1 - x, x).equals(virus.substring(0, x))) {
                        id1[i][j] = x;
                        break;
                    }
                }
            }
        }
    }

    static void input() {
        Scanner sc = new Scanner(System.in);
        s1 = sc.next();
        s2 = sc.next();
        virus = sc.next();
        nv = virus.length();
        n1 = s1.length();
        n2 = s2.length();
        sc.close();
    }

    static void solve() {
        List<List<Integer>> List1 = new ArrayList<>(26);
        List<List<Integer>> List2 = new ArrayList<>(26);
        for (int i = 0; i < 26; i++) {
            List1.add(new ArrayList<>());
            List2.add(new ArrayList<>());
        }
        for (int i = 0; i < n1; i++) {
            List1.get(s1.charAt(i) - 'A').add(i);
        }
        for (int i = 0; i < n2; i++) {
            List2.get(s2.charAt(i) - 'A').add(i);
        }
        proceedVirus();
        Pair<Pair<Long, Long>, Pair<Long, Long>> Default = new Pair<>(new Pair<>((long) -1, (long) -1), new Pair<>((long) -1, (long) -1));
        boolean[][][][] dp = new boolean[(int) n1][(int) n2][(int) Math.min(n1, n2) + 1][(int) nv + 1];
        Pair[][][][] Last = new Pair[(int) n1][(int) n2][(int) Math.min(n1, n2) + 1][(int) nv + 1];
        for (int i = 0; i < n1; i++) {
            for (int j = 0; j < n2; j++) {
                if (s1.charAt(i) == s2.charAt(j)) {
                    dp[i][j][1][(int) id1[0][s1.charAt(i) - 'A']] = true;
                } else {
                    dp[i][j][0][0] = true;
                }
            }
        }
        for (int x = 1; x < Math.min(n1, n2); x++) {
            for (int i = 0; i < n1 - 1; i++) {
                for (int j = 0; j < n2 - 1; j++) {
                    for (int y = 0; y < nv; y++) {
                        if (!dp[i][j][x][y]) {
                            continue;
                        }
                        for (int z = 0; z < 26; z++) {
                            if (Collections.binarySearch(List1.get(z), i) == List1.get(z).size()) {
                                continue;
                            }
                            if (Collections.binarySearch(List2.get(z), j) == List2.get(z).size()) {
                                continue;
                            }
                            int i1 = List1.get(z).get(Collections.binarySearch(List1.get(z), i));
                            int j1 = List2.get(z).get(Collections.binarySearch(List2.get(z), j));
                            dp[i1][j1][x + 1][(int) id1[y][z]] = true;
                            Last[i1][j1][x + 1][(int) id1[y][z]] = new Pair<>(new Pair<>(i, j), new Pair<>(x, y));
                        }
                    }
                }
            }
        }
        for (int x = (int) Math.min(n1, n2); x > 0; x--) {
            for (int y = 0; y < nv; y++) {
                for (int i = 0; i < n1; i++) {
                    for (int j = 0; j < n2; j++) {
                        if (!dp[i][j][x][y]) {
                            continue;
                        }
                        int I = i, J = j, X = x, Y = y;
                        StringBuilder s = new StringBuilder();
                        while (I != -1) {
                            s.insert(0, s1.charAt(I));
                            Pair<Pair<Long, Long>, Pair<Long, Long>> Token = Last[I][J][X][Y];
                            I = (int) Token.first.first;
                            J = (int) Token.first.second;
                            X = (int) Token.second.first;
                            Y = (int) Token.second.second;
                        }
                        System.out.println(s);
                        return;
                    }
                }
            }
        }
        System.out.println("0");
    }

    public static void main(String[] args) {
        input();
        solve();
    }
}
