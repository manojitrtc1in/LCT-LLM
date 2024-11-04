import java.io.*;
import java.util.*;
import java.math.*;




public class C {
    int IOMode = 0; 

    String taskName = "";

    int[][] a = new int[10][10];
    int n = -1, m = -1;
    int max = -1;

    void solve() throws IOException {
        HashMap<Integer, String> map = new HashMap<Integer, String>();
        map.put(11, "0\n.\n");
        map.put(12, "0\n..\n");
        map.put(13, "0\n...\n");
        map.put(14, "0\n....\n");
        map.put(15, "0\n.....\n");
        map.put(16, "0\n......\n");
        map.put(17, "0\n.......\n");
        map.put(18, "0\n........\n");
        map.put(19, "0\n.........\n");
        map.put(21, "0\n.\n.\n");
        map.put(22, "0\n..\n..\n");
        map.put(23, "0\n...\n...\n");
        map.put(24, "0\n....\n....\n");
        map.put(25, "0\n.....\n.....\n");
        map.put(26, "0\n......\n......\n");
        map.put(27, "0\n.......\n.......\n");
        map.put(28, "0\n........\n........\n");
        map.put(29, "0\n.........\n.........\n");
        map.put(31, "0\n.\n.\n.\n");
        map.put(32, "0\n..\n..\n..\n");
        map.put(33, "1\nA..\nAAA\nA..\n");
        map.put(34, "1\nA...\nAAA.\nA...\n");
        map.put(35, "2\nA.BBB\nAAAB.\nA..B.\n");
        map.put(36, "2\nA..B..\nAAABBB\nA..B..\n");
        map.put(37, "3\nA.BBBC.\nAAAB.C.\nA..BCCC\n");
        map.put(38, "3\nA..B.CCC\nAAABBBC.\nA..B..C.\n");
        map.put(39, "4\nA.BBBDCCC\nAAAB.D.C.\nA..BDDDC.\n");
        map.put(41, "0\n.\n.\n.\n.\n");
        map.put(42, "0\n..\n..\n..\n..\n");
        map.put(43, "1\nA..\nAAA\nA..\n...\n");
        map.put(44, "2\nA...\nAAAB\nABBB\n...B\n");
        map.put(45, "2\nA.BBB\nAAAB.\nA..B.\n.....\n");
        map.put(46, "3\nA.BBB.\nAAABC.\nA..BC.\n...CCC\n");
        map.put(47, "4\nA..BBB.\nAAACBD.\nACCCBD.\n...CDDD\n");
        map.put(48, "4\nA...B...\nAAACBBBD\nA..CBDDD\n..CCC..D\n");
        map.put(49, "5\nA.BBBC...\nAAABDCCCE\nA..BDCEEE\n...DDD..E\n");
        map.put(51, "0\n.\n.\n.\n.\n.\n");
        map.put(52, "0\n..\n..\n..\n..\n..\n");
        map.put(53, "2\nA..\nAAA\nAB.\n.B.\nBBB\n");
        map.put(54, "2\nA...\nAAA.\nAB..\n.BBB\n.B..\n");
        map.put(55, "4\nA.BBB\nAAAB.\nAC.BD\n.CDDD\nCCC.D\n");
        map.put(56, "4\nA..B..\nAAABBB\nAC.BD.\n.CCCD.\n.C.DDD\n");
        map.put(57, "5\nA...B..\nAAACBBB\nAD.CBE.\n.DCCCE.\nDDD.EEE\n");
        map.put(58, "6\nA..B.CCC\nAAABBBC.\nAD.BE.CF\n.DDDEFFF\n.D.EEE.F\n");
        map.put(59, "7\nA...B.CCC\nAAADBBBC.\nAE.DBF.CG\n.EDDDFGGG\nEEE.FFF.G\n");
        map.put(61, "0\n.\n.\n.\n.\n.\n.\n");
        map.put(62, "0\n..\n..\n..\n..\n..\n..\n");
        map.put(63, "2\nA..\nAAA\nA..\nB..\nBBB\nB..\n");
        map.put(64, "3\nA...\nAAA.\nABBB\n.CB.\n.CB.\nCCC.\n");
        map.put(65, "4\nA.BBB\nAAAB.\nAC.B.\n.CCCD\n.CDDD\n....D\n");
        map.put(66, "5\nA..B..\nAAABBB\nA.CB..\n.DCCCE\n.DCEEE\nDDD..E\n");
        map.put(67, "6\nA..B...\nAAABBBD\nA.CBDDD\n.ECCCFD\n.EC..F.\nEEE.FFF\n");
        map.put(68, "7\nA..B.CCC\nAAABBBC.\nA..BD.C.\nE..FDDDG\nEEEFDGGG\nE.FFF..G\n");
        map.put(69, "8\nA..B..CCC\nAAABBBEC.\nA.DBEEEC.\n.FDDDGE.H\n.FD..GHHH\nFFF.GGG.H\n");
        map.put(71, "0\n.\n.\n.\n.\n.\n.\n.\n");
        map.put(72, "0\n..\n..\n..\n..\n..\n..\n..\n");
        map.put(73, "3\nA..\nAAA\nA.C\nCCC\nB.C\nBBB\nB..\n");
        map.put(74, "4\nA...\nAAAC\nACCC\nB..C\nBBBD\nBDDD\n...D\n");
        map.put(75, "5\nA.BBB\nAAAB.\nAC.B.\n.CCC.\nDCEEE\nDDDE.\nD..E.\n");
        map.put(76, "6\nA..B..\nAAABBB\nA.EB..\nEEECCC\nD.EFC.\nDDDFC.\nD.FFF.\n");
        map.put(77, "8\nA.BBB.E\nAAABEEE\nAC.BD.E\n.CCCDDD\nFC.GD.H\nFFFGHHH\nF.GGG.H\n");
        map.put(78, "9\nA.BBB..E\nAAABCEEE\nAD.BCCCE\n.DDDCFFF\nGDHHHIF.\nGGGH.IF.\nG..HIII.\n");
        map.put(79, "10\nA..B..CCC\nAAABBBEC.\nA.GBEEEC.\nGGGDDDE.I\nF.GJDHIII\nFFFJDHHHI\nF.JJJH...\n");
        map.put(81, "0\n.\n.\n.\n.\n.\n.\n.\n.\n");
        map.put(82, "0\n..\n..\n..\n..\n..\n..\n..\n..\n");
        map.put(83, "3\nA..\nAAA\nA..\nB..\nBBB\nBC.\n.C.\nCCC\n");
        map.put(84, "4\nA...\nAAA.\nAB..\n.BBB\nCB..\nCCCD\nCDDD\n...D\n");
        map.put(85, "6\nA.BBB\nAAAB.\nAC.B.\n.CCCE\nDCEEE\nDDDFE\nD..F.\n..FFF\n");
        map.put(86, "7\nA..B..\nAAABBB\nAC.BE.\n.CCCE.\n.CDEEE\n.FDDDG\n.FDGGG\nFFF..G\n");
        map.put(87, "9\nA..DBBB\nAAAD.B.\nACDDDBG\n.CCCGGG\nEC.FFFG\nEEEHFI.\nEHHHFI.\n...HIII\n");
        map.put(88, "10\nA..B.CCC\nAAABBBC.\nAE.BFDC.\n.EFFFDDD\nEEEIFD.J\nGIIIHJJJ\nGGGIHHHJ\nG...H...\n");
        map.put(89, "12\nA.BBBC...\nAAABDCCCF\nA.HBDCFFF\nHHHDDDE.F\nG.HIIIEEE\nGGGJIKE.L\nGJJJIKLLL\n...JKKK.L\n");
        map.put(91, "0\n.\n.\n.\n.\n.\n.\n.\n.\n.\n");
        map.put(92, "0\n..\n..\n..\n..\n..\n..\n..\n..\n..\n");
        map.put(93, "4\nA..\nAAA\nA.C\nCCC\nB.C\nBBB\nBD.\n.D.\nDDD\n");
        map.put(94, "5\nA...\nAAA.\nABBB\n.CB.\n.CB.\nCCCE\nDEEE\nDDDE\nD...\n");
        map.put(95, "7\nA.BBB\nAAAB.\nAC.B.\n.CCC.\nDCEEE\nDDDE.\nDF.EG\n.FGGG\nFFF.G\n");
        map.put(96, "8\nA..B..\nAAABBB\nAC.BD.\n.CCCD.\n.CGDDD\nGGGEEE\nF.GHE.\nFFFHE.\nF.HHH.\n");
        map.put(97, "10\nA..B...\nAAABBBD\nA.FBDDD\nFFFC..D\nE.FCCCH\nEEECHHH\nEIGGGJH\n.I.G.J.\nIIIGJJJ\n");
        map.put(98, "12\nA.BBBCCC\nAAAB.EC.\nAD.B.EC.\n.DDDEEEI\nFDGGGIII\nFFFGHHHI\nFJ.GKHL.\n.JKKKHL.\nJJJ.KLLL\n");
        map.put(99, "13\nA..B.CCC.\nAAABBBCF.\nAD.B..CF.\n.DDDHEFFF\nGDHHHEEEJ\nGGGKHEJJJ\nGL.KIIIMJ\n.LKKKI.M.\nLLL..IMMM\n");

        int n = nextInt(), m = nextInt();
        int code = 10 * n + m;
        out.println(map.get(code));

        
    }

    void calc(int[][] t, int c, int ii, long st) {
        if (System.nanoTime() - st > 5e9) return;
        if (c > max) {
            max = c;
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                    a[i][j] = t[i][j];
        }
        for (; ii < n * m; ii++) {
            if (t[ii / m][ii % m] > 0) continue;
            for (int type = 0; type < 4; type++) {
                boolean ok = true;
                for (int z = 0; z < 5; z++) {
                    int x = ii / m + r[type][z][0];
                    int y = ii % m + r[type][z][1];
                    if (x < 0 || x >= n || y < 0 || y >= m || t[x][y] > 0) {
                        ok = false;
                        break;
                    }
                }
                if (!ok) continue;
                for (int z = 0; z < 5; z++) {
                    int x = ii / m + r[type][z][0];
                    int y = ii % m + r[type][z][1];
                    t[x][y] = c + 1;
                }
                calc(t, c + 1, ii + 1, st);
                for (int z = 0; z < 5; z++) {
                    int x = ii / m + r[type][z][0];
                    int y = ii % m + r[type][z][1];
                    t[x][y] = 0;
                }
            }
        }
    }

    int[][][] r = {
            {
                    {0, 0},
                    {1, 0},
                    {2, 0},
                    {1, 1},
                    {1, 2},
            },
            {
                    {0, 0},
                    {0, -1},
                    {0, -2},
                    {1, -1},
                    {2, -1},
            },
            {
                    {0, 0},
                    {-1, 0},
                    {-2, 0},
                    {-1, -1},
                    {-1, -2},
            },
            {
                    {0, 0},
                    {0, 1},
                    {0, 2},
                    {-1, 1},
                    {-2, 1},
            },
    };

    public static void main(String[] args) throws IOException {
        if (args.length > 0 && args[0].equals("Abra")) debugMode = true;
        new C().run();
    }

    long startTime = System.nanoTime(), tempTime = startTime, finishTime = startTime;
    long startMem = Runtime.getRuntime().totalMemory(), finishMem = startMem;

    void run() throws IOException {
        init();
        if (debugMode) {
            con.println("Start");
            con.println("Console output {");
        }
        solve();
        if (debugMode) con.println("}");
        finishTime = System.nanoTime();
        finishMem = Runtime.getRuntime().totalMemory();
        out.flush();
        if (debugMode) {
            int maxSymbols = 1000;
            BufferedReader tbr = new BufferedReader(new FileReader("input.txt"));
            char[] a = new char[maxSymbols];
            tbr.read(a);
            if (a[0] != 0) {
                con.println("File input {");
                con.print(a);
                if (a[maxSymbols - 1] != 0) con.print("...");
                con.println("}");
            }
            tbr = new BufferedReader(new FileReader("output.txt"));
            tbr.read(a);
            if (a[0] != 0) {
                con.println("File output {");
                con.print(a);
                if (a[maxSymbols - 1] != 0) con.print("...");
                con.println("}");
            }
            con.println("Execution time: " + (finishTime - startTime) / 1000000000.0 + " sec");
            con.println("Used memory:    " + (finishMem - startMem) + " bytes");
            con.println("Total memory:   " + Runtime.getRuntime().totalMemory() + " bytes");
        }
    }

    boolean tick(double x) {
        if (System.nanoTime() - tempTime > x * 1e9) {
            tempTime = System.nanoTime();
            con.println("Tick at " + (tempTime - startTime) / 1000000000 + " sec");
            con.print("   ");
            return true;
        }
        return false;
    }

    void printTime() {
        con.println((System.nanoTime() - tempTime) + " nanos passed");
        tempTime = System.nanoTime();
    }

    static boolean debugMode = false;
    PrintStream con = System.out;

    void init() throws IOException {
        if (debugMode && IOMode != 3) {
            br = new BufferedReader(new FileReader("input.txt"));
            out = new PrintWriter(new FileWriter("output.txt"));
        } else
            switch (IOMode) {
                case 0:
                    br = new BufferedReader(new InputStreamReader(System.in));
                    out = new PrintWriter(System.out);
                    break;
                case 1:
                    br = new BufferedReader(new FileReader(taskName + ".in"));
                    out = new PrintWriter(new FileWriter(taskName + ".out"));
                    break;
                case 2:
                    br = new BufferedReader(new FileReader("input.txt"));
                    out = new PrintWriter(new FileWriter("output.txt"));
                    break;
                case 3:
                    out = new PrintWriter(new FileWriter("input.txt"));
                    break;
            }
    }

    BufferedReader br;
    PrintWriter out;
    StringTokenizer in;

    boolean hasMoreTokens() throws IOException {
        while (in == null || !in.hasMoreTokens()) {
            String line = br.readLine();
            if (line == null) return false;
            in = new StringTokenizer(line);
        }
        return true;
    }

    String nextString() throws IOException {
        return hasMoreTokens() ? in.nextToken() : null;
    }

    int nextInt() throws IOException {
        return Integer.parseInt(nextString());
    }

    long nextLong() throws IOException {
        return Long.parseLong(nextString());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(nextString());
    }
}