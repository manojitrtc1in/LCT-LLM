import java.util.*;
import java.io.*;

class Main {
    static final long Mod = 1000000007L, INF = 1_000_000_000L, LINF = 1_000_000_000_000_000L;
    static final double Pi = 3.141592653589793116, EPS = 1e-9, Gold = ((1 + Math.sqrt(5)) / 2);
    static final long[] keymod = {1000000007L, 1000000009L, 1000000021L, 1000000033L};
    static final int keyCount = keymod.length;

    static long getbit(long s, int i) {
        return (s >> i) & 1;
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

    static void ControlIO(String[] args) {
        String infile = "FILE.IN";
        String outfile = "FILE.OUT";

        Date now = new Date();
        System.out.println("Source code by ");
        System.out.println("Current time: " + (now.getYear() + 1900) + "-" +
                ((now.getMonth() < 9) ? "0" : "") + (now.getMonth() + 1) + "-" +
                ((now.getDate() < 10) ? "0" : "") + now.getDate() + " | " +
                ((now.getHours() < 10) ? "0" : "") + now.getHours() + ":" +
                ((now.getMinutes() < 10) ? "0" : "") + now.getMinutes() + ":" +
                ((now.getSeconds() < 10) ? "0" : "") + now.getSeconds() +
                "\n\n");

        System.out.println("OI-Mode: ON");
        System.out.println("Input file: " + infile);
        System.out.println("Output file: " + outfile);
        System.out.println();

        System.out.println("OI-Mode: OFF");
        System.out.println("Input file: NULL");
        System.out.println("Output file: NULL");
        System.out.println();

        System.out.println("MultiTest-Mode: ON");

        System.out.println("MultiTest-Mode: OFF");

        System.out.println("Interactive-Mode: ON\n");

        System.out.println("Interactive-Mode: OFF\n");

        if (args.length > 0) {
            try {
                System.setIn(new FileInputStream(args[0]));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }
        if (args.length > 1) {
            try {
                System.setOut(new PrintStream(new FileOutputStream(args[1])));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        try {
            System.setIn(new FileInputStream(infile));
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        try {
            System.setOut(new PrintStream(new FileOutputStream(outfile)));
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    static void TimerStart() {
        // Start the timer
    }

    static void TimerStop() {
        // Stop the timer and print the elapsed time
    }

    static void Exit() {
        TimerStop();
        System.exit(0);
    }

    static String s;
    static Map<Character, Long> Map;
    static long q;

    static void Input() {
        Scanner sc = new Scanner(System.in);
        s = sc.next();
        sc.close();
    }

    static void Solve() {
        long baseAnswer = 1;
        Map = new HashMap<>();
        q = 0;
        for (char x : s.toCharArray()) {
            if (x >= '0' && x <= '9') continue;
            if (x == '?') {
                q++;
                continue;
            }
            Map.put(x, Map.getOrDefault(x, 0L) + 1);
        }
        for (long i = 10; i > 10 - Map.size(); i--) baseAnswer *= i;
        if (s.charAt(0) >= 'A' && s.charAt(0) <= 'J') {
            baseAnswer /= 10;
            baseAnswer *= 9;
        }
        if (s.charAt(0) == '?') {
            baseAnswer *= 9;
            q--;
        }
        System.out.print(baseAnswer);
        for (long i = 0; i < q; i++) System.out.print("0");
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
