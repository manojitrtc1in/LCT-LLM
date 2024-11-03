import java.util.*;
import java.io.*;

class Main {
    static class Pair {
        int first, second;
        Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }

    static class PairPair {
        Pair first, second;
        PairPair(Pair first, Pair second) {
            this.first = first;
            this.second = second;
        }
    }

    static final int Mod = 1000000007, INF = 1e9, LINF = 1e18;
    static final double Pi = 3.141592653589793116, EPS = 1e-9, Gold = ((1+Math.sqrt(5))/2);
    static final long[] keymod = {1000000007, 1000000009, 1000000021, 1000000033};
    static final int keyCount = keymod.length;

    static int getbit(long s, int i) { return (int)((s >> i) & 1); }
    static long onbit(long s, int i) { return s | (1L << i); }
    static long offbit(long s, int i) { return s & (~(1L << i)); }
    static int cntbit(long s) { return Long.bitCount(s); }

    static long TimeStart, TimeEnd;

    static void ControlIO(String[] args) {
        String infile = "FILE.IN";
        String outfile = "FILE.OUT";

        System.out.println("Source code by ");
        System.out.println("Current time: " + new SimpleDateFormat("yyyy-MM-dd | HH:mm:ss").format(new Date()) + "\n");

        System.out.println("OI-Mode: ON");
        System.out.println("Input file: " + infile);
        System.out.println("Output file: " + outfile + "\n");

        System.out.println("OI-Mode: OFF");
        System.out.println("Input file: NULL");
        System.out.println("Output file: NULL\n");

        System.out.println("MultiTest-Mode: ON");

        System.out.println("MultiTest-Mode: OFF");

        System.out.println("Interactive-Mode: ON\n");

        System.out.println("Interactive-Mode: OFF\n");

        if (args.length > 0) {
            try {
                System.setIn(new FileInputStream(args[0]));
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
        if (args.length > 1) {
            try {
                System.setOut(new PrintStream(new FileOutputStream(args[1])));
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }

    static void TimerStart() {
        TimeStart = System.nanoTime();
    }

    static void TimerStop() {
        TimeEnd = System.nanoTime();
        double ElapsedTime = (double)(TimeEnd - TimeStart) / 1e9;
        System.out.println("\n\nTime elapsed: " + ElapsedTime + " seconds.");
    }

    static void Exit() {
        TimerStop();
        System.exit(0);
    }

    static String s1, s2, virus;
    static int n1, n2, nv;
    static List<List<Integer>> id1;

    static void ProceedVirus() {
        id1 = new ArrayList<>();
        for (int i = 0; i < nv; i++) {
            id1.add(new ArrayList<>());
            for (int j = 0; j < 26; j++) {
                String pref2 = virus.substring(0, i);
                pref2 += (char)(65 + j);
                for (int x = i + 1; x >= 0; x--) {
                    if (pref2.substring(i + 1 - x, x).equals(virus.substring(0, x))) {
                        id1.get(i).add(x);
                        break;
                    }
                }
            }
        }
    }

    static void Input() {
        Scanner sc = new Scanner(System.in);
        s1 = sc.next();
        s2 = sc.next();
        virus = sc.next();
        nv = virus.length();
        n1 = s1.length();
        n2 = s2.length();
    }

    static void Solve() {
        List<List<Integer>> List1 = new ArrayList<>();
        List<List<Integer>> List2 = new ArrayList<>();
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
        PairPair Default = new PairPair(new Pair(-1, -1), new Pair(-1, -1));
        boolean[][][][] dp = new boolean[n1][n2][Math.min(n1, n2) + 1][nv + 1];
        PairPair[][][][] Last = new PairPair[n1][n2][Math.min(n1, n2) + 1][nv + 1];
        for (int i = 0; i < n1; i++) {
            for (int j = 0; j < n2; j++) {
                if (s1.charAt(i) == s2.charAt(j)) {
                    dp[i][j][1][id1.get(0).get(s1.charAt(i) - 'A')] = true;
                } else {
                    dp[i][j][0][0] = true;
                }
            }
        }
        for (int x = 1; x < Math.min(n1, n2); x++) {
            for (int i = 0; i < n1 - 1; i++) {
                for (int j = 0; j < n2 - 1; j++) {
                    for (int y = 0; y < nv; y++) {
                        if (!dp[i][j][x][y]) continue;
                        for (int z = 0; z < 26; z++) {
                            if (Collections.binarySearch(List1.get(z), i) == List1.get(z).size()) continue;
                            if (Collections.binarySearch(List2.get(z), j) == List2.get(z).size()) continue;
                            int i1 = List1.get(z).get(Collections.binarySearch(List1.get(z), i));
                            int j1 = List2.get(z).get(Collections.binarySearch(List2.get(z), j));
                            dp[i1][j1][x + 1][id1.get(y).get(z)] = true;
                            Last[i1][j1][x + 1][id1.get(y).get(z)] = new PairPair(new Pair(i, j), new Pair(x, y));
                        }
                    }
                }
            }
        }
        for (int x = Math.min(n1, n2); x > 0; x--) {
            for (int y = 0; y < nv; y++) {
                for (int i = 0; i < n1; i++) {
                    for (int j = 0; j < n2; j++) {
                        if (!dp[i][j][x][y]) continue;
                        int I = i, J = j, X = x, Y = y;
                        StringBuilder s = new StringBuilder();
                        while (I != -1) {
                            s.insert(0, s1.charAt(I));
                            PairPair Token = Last[I][J][X][Y];
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

    public static void main(String[] args) {
        ControlIO(args);

        Input();
        TimerStart();
        Solve();
        TimerStop();

        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        TimerStart();
        while (T-- > 0) {
            Input();
            Solve();
        }
        TimerStop();
    }
}
