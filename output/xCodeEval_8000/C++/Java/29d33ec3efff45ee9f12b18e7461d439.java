import java.util.*;
import java.io.*;

class Main {
    static final int Mod = 1000000007, INF = 1_000_000_000, LINF = 1_000_000_000_000_000L;
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

    static long TimeStart, TimeEnd;
    static final int OImode = 227420978, MultiTest = 227420978, Interactive = 227420978;

    static void ControlIO(String[] args) {
        String cppstr_infile = "FILE.IN";
        String cppstr_outfile = "FILE.OUT";

        String infile = cppstr_infile;
        String outfile = cppstr_outfile;

        #ifdef Akikaze
        System.out.println("Source code by #Team4T-Akikaze.");
        System.out.println("Current time: " + new SimpleDateFormat("yyyy-MM-dd | HH:mm:ss").format(new Date()) + "\n");

        #ifdef OImode
        System.out.println("OI-Mode: ON");
        System.out.println("Input file: " + infile);
        System.out.println("Output file: " + outfile);
        System.out.println();
        #else
        System.out.println("OI-Mode: OFF");
        System.out.println("Input file: NULL");
        System.out.println("Output file: NULL");
        System.out.println();
        #endif

        #ifdef MultiTest
        System.out.println("MultiTest-Mode: ON");
        #else
        System.out.println("MultiTest-Mode: OFF");
        #endif

        #ifdef Interactive
        System.out.println("Interactive-Mode: ON\n");
        #else
        System.out.println("Interactive-Mode: OFF\n");
        #endif

        if (args.length > 0) {
            try {
                System.setIn(new FileInputStream(args[0]));
            } catch (Exception e) {
                e.printStackTrace();
            }
        }

        #elif OImode
        try {
            System.setIn(new FileInputStream(infile));
            System.setOut(new PrintStream(new FileOutputStream(outfile)));
        } catch (Exception e) {
            e.printStackTrace();
        }
        #endif
    }

    static void TimerStart() {
        #ifdef Akikaze
        TimeStart = System.nanoTime();
        #endif
    }

    static void TimerStop() {
        #ifdef Akikaze
        TimeEnd = System.nanoTime();
        double ElapsedTime = (TimeEnd - TimeStart) / 1e9;
        System.out.println("\n\nTime elapsed: " + ElapsedTime + " seconds.");
        #endif
    }

    static void Exit() {
        TimerStop();
        System.exit(0);
    }

    static void proceedVirus(String virus, int nv, int[][] nextCommonPrefix) {
        for (int i = 0; i < nv; i++) {
            for (int j = 0; j < 26; j++) {
                StringBuilder pref2 = new StringBuilder(virus.substring(0, i));
                pref2.append((char) (65 + j));
                for (int x = i + 1; x >= 0; x--) {
                    if (pref2.substring(i + 1 - x, i + 1).equals(virus.substring(0, x))) {
                        nextCommonPrefix[i][j] = x;
                        break;
                    }
                }
            }
        }
    }

    static void solve() {
        Scanner sc = new Scanner(System.in);
        String s1 = sc.next();
        String s2 = sc.next();
        String virus = sc.next();
        int n1 = s1.length();
        int n2 = s2.length();
        int nv = virus.length();
        int[][] nextCommonPrefix = new int[nv][26];

        proceedVirus(virus, nv, nextCommonPrefix);

        List<Integer>[] list1 = new List[26];
        List<Integer>[] list2 = new List[26];
        for (int i = 0; i < 26; i++) {
            list1[i] = new ArrayList<>();
            list2[i] = new ArrayList<>();
        }

        for (int i = 0; i < n1; i++) {
            list1[s1.charAt(i) - 'A'].add(i);
        }

        for (int i = 0; i < n2; i++) {
            list2[s2.charAt(i) - 'A'].add(i);
        }

        boolean[][][][] dp = new boolean[n1][n2][Math.min(n1, n2) + 1][nv + 1];
        int[][][][][] last = new int[n1][n2][Math.min(n1, n2) + 1][nv + 1][4];
        for (int i = 0; i < n1; i++) {
            for (int j = 0; j < n2; j++) {
                if (s1.charAt(i) == s2.charAt(j)) {
                    dp[i][j][1][nextCommonPrefix[0][s1.charAt(i) - 'A']] = true;
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
                            if (upperBound(list1[z], i) == list1[z].size()) {
                                continue;
                            }
                            if (upperBound(list2[z], j) == list2[z].size()) {
                                continue;
                            }
                            int i1 = list1[z].get(upperBound(list1[z], i));
                            int j1 = list2[z].get(upperBound(list2[z], j));
                            dp[i1][j1][x + 1][nextCommonPrefix[y][z]] = true;
                            last[i1][j1][x + 1][nextCommonPrefix[y][z]][0] = i;
                            last[i1][j1][x + 1][nextCommonPrefix[y][z]][1] = j;
                            last[i1][j1][x + 1][nextCommonPrefix[y][z]][2] = x;
                            last[i1][j1][x + 1][nextCommonPrefix[y][z]][3] = y;
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
                            int[] token = last[I][J][X][Y];
                            I = token[0];
                            J = token[1];
                            X = token[2];
                            Y = token[3];
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

        #ifndef Interactive
        Scanner sc = new Scanner(System.in);
        solve();
        #else
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        while (T-- > 0) {
            solve();
        }
        #endif
    }
}
