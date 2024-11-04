import java.util.*;
import java.io.*;

public class 02e969828fa8c90ecf63941da505769c_nc {
    static long Mod = 1000000007L;
    static long INF = 1000000000L;
    static double EPS = 1e-9;
    static double Gold = (1 + Math.sqrt(5)) / 2;

    static long n, m;

    static long modPow(long a, long b, long M) {
        if (b == 0) return 1;
        long tmp = modPow(a, b / 2, M);
        if (b % 2 == 0) return (tmp * tmp) % M;
        return (((tmp * tmp) % M) * a) % M;
    }

    static void Input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] line = br.readLine().split(" ");
        n = Long.parseLong(line[0]);
        m = Long.parseLong(line[1]);
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
