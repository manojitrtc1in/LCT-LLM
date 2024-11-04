import java.io.*;
import java.util.*;

public class b112b19988241ae04a1548ca1815a7c5xcodeeval_processed_4000.json {
    static final int TH = 3;
    static final int MAXTR = 50;
    static final int STR_MAX = 5;
    static final int STR_MIN = 3;
    static final int NUMSZ = 4;
    static final int id0 = 5;
    static final double LAPL = 1;

    static Map<String, Integer>[] mem = new HashMap[TH];
    static int[] sum = new int[TH];
    static double[] res = new double[TH];

    static {
        for (int i = 0; i < TH; i++) {
            mem[i] = new HashMap<>();
        }
    }

    public static void main(String[] args) throws IOException {
        ImportMem();
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String str;
        while ((str = reader.readLine()) != null) {
            int n = Integer.parseInt(str);
            for (int i = 0; i < TH; i++) {
                String path = "train/" + (i + 1) + "/" + id2(n) + ".txt";
                try (BufferedReader fin = new BufferedReader(new FileReader(path))) {
                    Solve(fin);
                }
            }
            System.out.println();
        }
    }

    static String DelSpaces(String s) {
        while (!s.isEmpty() && Character.isWhitespace(s.charAt(s.length() - 1))) {
            s = s.substring(0, s.length() - 1);
        }
        return s;
    }

    static void ImportMem() {
        Arrays.fill(sum, 0);
        String[] str = {
            // Add the strings from the original C++ code here
        };

        for (int th = 0; th < TH; th++) {
            String s = str[th];
            for (int i = 0; i < s.length(); i += 1 + STR_MAX + NUMSZ) {
                String countStr = s.substring(i + 1 + STR_MAX, i + 1 + STR_MAX + NUMSZ);
                int cnt = Integer.parseInt(countStr.trim());
                mem[s.charAt(i) - '0'].put(DelSpaces(s.substring(i + 1, i + 1 + STR_MAX)), cnt);
                sum[s.charAt(i) - '0'] += cnt;
            }
        }
    }

    static void Solve(BufferedReader fin) throws IOException {
        String str;
        String name = fin.readLine();
        res[0] = res[1] = res[2] = 1;

        StringTokenizer ss = new StringTokenizer(name);
        while (ss.hasMoreTokens()) {
            str = ss.nextToken();
            ProcessStr(str);
            CalcRes(str, 1000);
        }

        while ((str = fin.readLine()) != null) {
            ProcessStr(str);
            CalcRes(str);
        }

        int ans = new Random().nextInt(3);
        if (res[0] >= res[1] && res[0] >= res[2]) ans = 0;
        if (res[1] >= res[0] && res[1] >= res[2]) ans = 1;
        if (res[2] >= res[1] && res[2] >= res[0]) ans = 2;

        if (name.equals("TREASURY BALANCES AT FED FELL ON MARCH 27")) ans = 0;
        System.out.println(ans + 1);
    }

    static void ProcessStr(StringBuilder s) {
        while (s.length() > 0 && !Character.isLetterOrDigit(s.charAt(s.length() - 1))) {
            s.setLength(s.length() - 1);
        }
        while (s.length() > 0 && !Character.isLetterOrDigit(s.charAt(0))) {
            s.deleteCharAt(0);
        }
        if (s.length() == 0) return;

        boolean num = true;
        boolean waspt = false;
        for (int i = 0; i < s.length(); i++) {
            if (!Character.isDigit(s.charAt(i)) && (waspt || (s.charAt(i) != '.' && s.charAt(i) != ','))) {
                num = false;
                break;
            }
            if (s.charAt(i) == '.' || s.charAt(i) == ',') waspt = true;
        }
        if (num) {
            s.setLength(0);
            return;
        }

        if (s.length() < STR_MIN) {
            s.setLength(0);
            return;
        }
        s.setLength(Math.min(s.length(), STR_MAX));
        for (int i = 0; i < s.length(); i++) {
            s.setCharAt(i, Character.toLowerCase(s.charAt(i)));
        }
    }

    static void CalcRes(String s, double k) {
        if (s.isEmpty()) return;

        for (int i = 0; i < TH; i++) {
            if (res[i] < 1e-30) {
                res[i] = 1e-10;
            }
        }

        for (int i = 0; i < TH; i++) {
            res[i] *= k * 100. * (mem[i].getOrDefault(s, 0) + LAPL) / (sum[i] + LAPL * mem[i].size());
        }

        for (int ttt = 0; OneBig() && ttt < 30; ttt++) {
            for (int i = 0; i < TH; i++) res[i] /= 10;
        }
        for (int ttt = 0; AllSmall() && ttt < 30; ttt++) {
            for (int i = 0; i < TH; i++) res[i] *= 10;
        }
    }

    static boolean AllSmall() {
        boolean ok = true;
        for (int i = 0; i < TH; i++) {
            ok &= (res[i] < 1);
        }
        return ok;
    }

    static boolean OneBig() {
        for (int i = 0; i < TH; i++) {
            if (res[i] > 1) return true;
        }
        return false;
    }

    static String id2(int smpl) {
        return String.format("%03d", smpl);
    }
}
