import java.util.*;
import java.io.*;

public class 02e969828fa8c90ecf63941da505769c_nc {
    static long Mod = 1000000007L;
    static long INF = 1000000000L;
    static double EPS = 1e-9;
    static double Gold = (1 + Math.sqrt(5)) / 2;

    static long[] keymod = {1000000007L, 1000000009L, 1000000021L, 1000000033L};
    static int keyCount = keymod.length;

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

    static long modPow(long a, long b, long M) {
        if (b == 0) return 1;
        long tmp = modPow(a, b / 2, M);
        if (b % 2 == 0) return (tmp * tmp) % M;
        return (((tmp * tmp) % M) * a) % M;
    }

    static void Input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Long.parseLong(st.nextToken());
        m = Long.parseLong(st.nextToken());
    }

    static void Solve() {
        long A = (modPow(3, n, m) + m - 1) % m;
        System.out.println(A);
    }

    public static void main(String[] args) throws IOException {
        Input();
        Solve();
    }
}
