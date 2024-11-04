import java.io.*;
import java.util.*;
import java.time.*;

public class 640dc614f856ecc5cfc468b141ab77d4xcodeeval_processed_4000.json {
    static long Mod = 1000000007L, INF = (long) 1e9, LINF = (long) 1e18;
    static double Pi = 3.141592653589793116, EPS = 1e-9, Gold = (1 + Math.sqrt(5)) / 2;
    static long[] keymod = {1000000007L, 1000000009L, 1000000021L, 1000000033L};
    static long keyCount = keymod.length;

    static long x;

    static class Pair {
        long fi, se;
        Pair(long fi, long se) {
            this.fi = fi;
            this.se = se;
        }
    }

    static Pair func(long m, long n, long s) {
        if (m == 0) return new Pair(n, s);
        long k = (long) Math.cbrt(m);
        long x = k * k * k, y = (k - 1) * (k - 1) * (k - 1);
        return max(func(m - x, n + 1, s + x), func(x - y - 1, n + 1, s + y));
    }

    static Pair max(Pair a, Pair b) {
        return (a.fi > b.fi || (a.fi == b.fi && a.se > b.se)) ? a : b;
    }

    static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        x = Long.parseLong(br.readLine());
    }

    static void solve() {
        Pair token = func(x, 0, 0);
        System.out.println(token.fi + " " + token.se);
    }

    public static void main(String[] args) throws IOException {
        ControlIO(args);
        input();
        TimerStart();
        solve();
        TimerStop();

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        TimerStart();
        while (T-- > 0) {
            input();
            solve();
        }
        TimerStop();
    }

    static void ControlIO(String[] args) throws IOException {
        String id0 = "FILE.IN";
        String id1 = "FILE.OUT";

        System.out.println("Source code by ");
        System.out.print("Current time: ");
        LocalDateTime now = LocalDateTime.now();
        System.out.printf("%d-%02d-%02d | %02d:%02d:%02d\n\n", 
                          now.getYear(), now.getMonthValue(), now.getDayOfMonth(), 
                          now.getHour(), now.getMinute(), now.getSecond());

        System.out.println("OI-Mode: ON");
        System.out.println("Input file: " + id0);
        System.out.println("Output file: " + id1);
        System.out.println("\n");

        System.out.println("OI-Mode: OFF");
        System.out.println("Input file: NULL");
        System.out.println("Output file: NULL");
        System.out.println("\n");

        System.out.println("MultiTest-Mode: ON");
        System.out.println("MultiTest-Mode: OFF");

        System.out.println("Interactive-Mode: ON\n");
        System.out.println("Interactive-Mode: OFF\n");

        if (args.length > 0) {
            System.setIn(new FileInputStream(args[0]));
        }
        if (args.length > 1) {
            System.setOut(new PrintStream(new FileOutputStream(args[1])));
        }

        System.setIn(new FileInputStream(id0));
        System.setOut(new PrintStream(new FileOutputStream(id1)));
    }

    static Instant TimeStart, TimeEnd;

    static void TimerStart() {
        TimeStart = Instant.now();
    }

    static void TimerStop() {
        TimeEnd = Instant.now();
        Duration elapsedTime = Duration.between(TimeStart, TimeEnd);
        System.out.printf("\n\nTime elapsed: %.6f seconds.\n", elapsedTime.toMillis() / 1000.0);
    }
}
