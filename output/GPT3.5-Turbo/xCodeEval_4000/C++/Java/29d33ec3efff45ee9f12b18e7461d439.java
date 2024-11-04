import java.util.*;
import java.io.*;

class Main {
    static final int Mod = 1000000007, INF = 1_000_000_000, LINF = 1_000_000_000_000;
    static final double Pi = 3.141592653589793116, EPS = 1e-9, Gold = ((1 + Math.sqrt(5)) / 2);
    static final long[] keymod = {1000000007, 1000000009, 1000000021, 1000000033};
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

    static String s1, s2, virus;
    static int n1, n2, nv;
    static ArrayList<ArrayList<Integer>> NextCommonPrefix;

    static void ProceedVirus() {
        NextCommonPrefix = new ArrayList<>(nv);
        for (int i = 0; i < nv; i++) {
            NextCommonPrefix.add(new ArrayList<>(Collections.nCopies(26, 0)));
            for (int j = 0; j < 26; j++) {
                String pref2 = virus.substring(0, i);
                pref2 += (char) (65 + j);
                for (int x = i + 1; x >= 0; x--) {
                    if (pref2.substring(i + 1 - x, i + 1).equals(virus.substring(0, x))) {
                        NextCommonPrefix.get(i).set(j, x);
                        break;
                    }
                }
            }
        }
    }

    static void Input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        s1 = input[0];
        s2 = input[1];
        virus = input[2];
        nv = virus.length();
        n1 = s1.length();
        n2 = s2.length();
    }

    static void Solve() {
        ArrayList<ArrayList<Integer>> List1 = new ArrayList<>(26);
        ArrayList<ArrayList<Integer>> List2 = new ArrayList<>(26);
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
        ProceedVirus();
        Pair<Pair<Integer, Integer>, Pair<Integer, Integer>> Default = new Pair<>(new Pair<>(-1, -1), new Pair<>(-1, -1));
        ArrayList<ArrayList<ArrayList<ArrayList<Pair<Pair<Integer, Integer>, Pair<Integer, Integer>>>>>> Last = new ArrayList<>(n1);
        for (int i = 0; i < n1; i++) {
            Last.add(new ArrayList<>(n2));
            for (int j = 0; j < n2; j++) {
                Last.get(i).add(new ArrayList<>(Math.min(n1, n2) + 1));
                for (int k = 0; k <= Math.min(n1, n2); k++) {
                    Last.get(i).get(j).add(new ArrayList<>(nv + 1));
                    for (int l = 0; l <= nv; l++) {
                        Last.get(i).get(j).get(k).add(Default);
                    }
                }
            }
        }
        boolean[][][][] dp = new boolean[n1][n2][Math.min(n1, n2) + 1][nv + 1];
        for (int i = 0; i < n1; i++) {
            for (int j = 0; j < n2; j++) {
                if (s1.charAt(i) == s2.charAt(j)) {
                    dp[i][j][1][NextCommonPrefix.get(0).get(s1.charAt(i) - 'A')] = true;
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
                            if (upperBound(List1.get(z), i) == List1.get(z).size()) {
                                continue;
                            }
                            if (upperBound(List2.get(z), j) == List2.get(z).size()) {
                                continue;
                            }
                            int i1 = List1.get(z).get(upperBound(List1.get(z), i));
                            int j1 = List2.get(z).get(upperBound(List2.get(z), j));
                            dp[i1][j1][x + 1][NextCommonPrefix.get(y).get(z)] = true;
                            Last.get(i1).get(j1).get(x + 1).set(NextCommonPrefix.get(y).get(z), new Pair<>(new Pair<>(i, j), new Pair<>(x, y)));
                        }
                    }
                }
            }
        }
        for (int x = Math.min(n1, n2); x > 0; x--) {
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
                            Pair<Pair<Integer, Integer>, Pair<Integer, Integer>> Token = Last.get(I).get(J).get(X).get(Y);
                            I = Token.first.first;
                            J = Token.first.second;
                            X = Token.second.first;
                            Y = Token.second.second;
                        }
                        System.out.println(s);
                        return;
                    }
                }
            }
        }
        System.out.println("0");
    }

    static int upperBound(ArrayList<Integer> list, int value) {
        int low = 0, high = list.size();
        while (low < high) {
            int mid = (low + high) / 2;
            if (list.get(mid) <= value) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }

    public static void main(String[] args) throws IOException {
        Input();
        Solve();
    }
}
