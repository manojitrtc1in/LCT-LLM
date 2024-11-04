import java.util.*;
import java.io.*;

class Main {
    static class Pair<A, B> {
        A x;
        B y;

        Pair(A x, B y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public String toString() {
            return "(" + x + ", " + y + ")";
        }
    }

    static <A> String arrayToString(ArrayList<A> v) {
        StringBuilder sb = new StringBuilder();
        sb.append("[");
        for (int i = 0; i < v.size(); i++) {
            if (i > 0) {
                sb.append(", ");
            }
            sb.append(v.get(i));
        }
        sb.append("]");
        return sb.toString();
    }

    static Random rnd = new Random();

    static final int INF = (int) 1e9;
    static final long INF64 = (long) 1e18;
    static final int MOD = (int) 1e9 + 7;
    static final double EPS = 1e-9;
    static final double PI = Math.acos(-1.0);

    static final int N = 1000 + 7;

    static int n;
    static String s;

    static boolean read() {
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            s = br.readLine().substring(4);
            n = s.length();
            return true;
        } catch (IOException e) {
            return false;
        }
    }

    static long[] lim = {0, 9, 99, 99, 3099, 13099, 113099, 1113099, 11113099, 111113099};
    static String[] pr1 = {"", "198", "19", "2", "", "", "", "", "", ""};
    static String[] pr2 = {"", "199", "20", "3", "1", "1", "1", "1", "1", "1"};

    static String solve() {
        long x = Long.parseLong(s);
        if (x >= lim[n]) {
            return pr1[n] + s;
        } else {
            return pr2[n] + s;
        }
    }

    public static void main(String[] args) {
        try {
            System.setIn(new FileInputStream("input.txt"));
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }

        int tt = (int) System.currentTimeMillis();

        int tc;
        Scanner sc = new Scanner(System.in);
        tc = sc.nextInt();
        while (tc-- > 0) {
            while (read()) {
                System.out.println(solve());
            }
        }

        System.err.println("TIME = " + ((int) System.currentTimeMillis() - tt));
        tt = (int) System.currentTimeMillis();
    }
}
