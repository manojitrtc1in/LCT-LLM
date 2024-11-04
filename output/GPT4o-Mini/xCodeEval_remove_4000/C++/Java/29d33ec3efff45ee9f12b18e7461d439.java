import java.io.*;
import java.util.*;

public class 29d33ec3efff45ee9f12b18e7461d439xcodeeval_processed_4000.json {
    static final long Mod = 1000000007L, INF = (long) 1e9, LINF = (long) 1e18;
    static final double Pi = 3.141592653589793116, EPS = 1e-9, Gold = (1 + Math.sqrt(5)) / 2;
    static long[] keymod = {1000000007L, 1000000009L, 1000000021L, 1000000033L};
    static long keyCount = keymod.length;

    static String id0 = "FILE.IN";
    static String id2 = "FILE.OUT";
    static String s1, s2, virus;
    static long n1, n2, nv;
    static int[][] id1;

    static void ProceedVirus() {
        id1 = new int[(int) nv][26];
        for (int i = 0; i < nv; i++) {
            for (int j = 0; j < 26; j++) {
                String pref2 = virus.substring(0, i) + (char) (65 + j);
                for (int x = i + 1; x >= 0; x--) {
                    if (pref2.substring(i + 1 - x, i + 1).equals(virus.substring(0, x))) {
                        id1[i][j] = x;
                        break;
                    }
                }
            }
        }
    }

    static void Input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        s1 = br.readLine();
        s2 = br.readLine();
        virus = br.readLine();
        nv = virus.length();
        n1 = s1.length();
        n2 = s2.length();
    }

    static void Solve() {
        List<Integer>[] List1 = new ArrayList[26];
        List<Integer>[] List2 = new ArrayList[26];
        for (int i = 0; i < 26; i++) {
            List1[i] = new ArrayList<>();
            List2[i] = new ArrayList<>();
        }
        for (int i = 0; i < n1; i++) List1[s1.charAt(i) - 'A'].add(i);
        for (int i = 0; i < n2; i++) List2[s2.charAt(i) - 'A'].add(i);
        ProceedVirus();
        int[][][] dp = new int[(int) n1][(int) n2][Math.min((int) n1, (int) n2) + 1];
        Arrays.fill(dp, -1);
        int[][][][] Last = new int[(int) n1][(int) n2][Math.min((int) n1, (int) n2) + 1][(int) nv];
        for (int i = 0; i < n1; i++) {
            for (int j = 0; j < n2; j++) {
                if (s1.charAt(i) == s2.charAt(j)) {
                    dp[i][j][1] = id1[0][s1.charAt(i) - 'A'];
                } else {
                    dp[i][j][0] = 0;
                }
            }
        }
        for (int x = 1; x < Math.min(n1, n2); x++) {
            for (int i = 0; i < n1 - 1; i++) {
                for (int j = 0; j < n2 - 1; j++) {
                    for (int y = 0; y < nv; y++) {
                        if (dp[i][j][x] == -1) continue;
                        for (int z = 0; z < 26; z++) {
                            if (List1[z].isEmpty() || List2[z].isEmpty()) continue;
                            int i1 = Collections.binarySearch(List1[z], i);
                            int j1 = Collections.binarySearch(List2[z], j);
                            if (i1 < 0) i1 = -i1 - 1;
                            if (j1 < 0) j1 = -j1 - 1;
                            if (i1 < List1[z].size() && j1 < List2[z].size()) {
                                dp[i1][j1][x + 1] = id1[y][z];
                                Last[i1][j1][x + 1][id1[y][z]] = new int[]{i, j, x, y};
                            }
                        }
                    }
                }
            }
        }
        for (int x = Math.min(n1, n2); x > 0; x--) {
            for (int y = 0; y < nv; y++) {
                for (int i = 0; i < n1; i++) {
                    for (int j = 0; j < n2; j++) {
                        if (dp[i][j][x] == -1) continue;
                        int I = i, J = j, X = x, Y = y;
                        StringBuilder s = new StringBuilder();
                        while (I != -1) {
                            s.insert(0, s1.charAt(I));
                            int[] Token = Last[I][J][X][Y];
                            I = Token[0];
                            J = Token[1];
                            X = Token[2];
                            Y = Token[3];
                        }
                        System.out.println(s);
                        return;
                    }
                }
            }
        }
        System.out.println("0");
    }

    public static void main(String[] args) throws IOException {
        ControlIO(args);
        Input();
        TimerStart();
        Solve();
        TimerStop();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        TimerStart();
        while (T-- > 0) {
            Input();
            Solve();
        }
        TimerStop();
    }

    static void ControlIO(String[] args) throws FileNotFoundException {
        if (args.length > 1) System.setIn(new FileInputStream(args[0]));
        if (args.length > 2) System.setOut(new PrintStream(args[1]));
        System.setIn(new FileInputStream(id0));
        System.setOut(new PrintStream(id2));
    }

    static long TimeStart, TimeEnd;

    static void TimerStart() {
        TimeStart = System.nanoTime();
    }

    static void TimerStop() {
        TimeEnd = System.nanoTime();
        double elapsedTime = (TimeEnd - TimeStart) / 1e9;
        System.out.printf("\n\nTime elapsed: %.6f seconds.\n", elapsedTime);
    }
}
