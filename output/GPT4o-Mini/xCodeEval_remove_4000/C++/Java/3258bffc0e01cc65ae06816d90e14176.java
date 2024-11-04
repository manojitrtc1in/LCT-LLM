import java.io.*;
import java.util.*;
import java.time.*;

public class 3258bffc0e01cc65ae06816d90e14176xcodeeval_processed_4000.json {
    static String id0 = "FILE.IN";
    static String id1 = "FILE.OUT";
    static String s;
    static Map<Character, Long> Map = new HashMap<>();
    static long q = 0;

    public static void main(String[] args) throws IOException {
        ControlIO(args);
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter(id1)));

        Input(br);
        TimerStart();
        Solve(pw);
        TimerStop();

        int T = Integer.parseInt(br.readLine());
        TimerStart();
        while (T-- > 0) {
            Input(br);
            Solve(pw);
        }
        TimerStop();

        pw.close();
    }

    static void ControlIO(String[] args) throws IOException {
        if (args.length > 1) {
            System.setIn(new FileInputStream(args[1]));
        }
        if (args.length > 2) {
            System.setOut(new PrintStream(new FileOutputStream(args[2])));
        }
        System.setIn(new FileInputStream(id0));
        System.setOut(new PrintStream(new FileOutputStream(id1)));

        LocalDateTime now = LocalDateTime.now();
        System.out.println("Source code by ");
        System.out.println("Current time: " + now.getYear() + "-" +
                String.format("%02d", now.getMonthValue()) + "-" +
                String.format("%02d", now.getDayOfMonth()) + " | " +
                String.format("%02d", now.getHour()) + ":" +
                String.format("%02d", now.getMinute()) + ":" +
                String.format("%02d", now.getSecond()) + "\n\n");

        System.out.println("OI-Mode: ON");
        System.out.println("Input file: " + id0);
        System.out.println("Output file: " + id1 + "\n");
        System.out.println("OI-Mode: OFF\n");
        System.out.println("MultiTest-Mode: ON\n");
        System.out.println("MultiTest-Mode: OFF\n");
        System.out.println("Interactive-Mode: ON\n");
        System.out.println("Interactive-Mode: OFF\n");
    }

    static void Input(BufferedReader br) throws IOException {
        s = br.readLine();
    }

    static void Solve(PrintWriter pw) {
        long baseAnswer = 1;
        for (char x : s.toCharArray()) {
            if (Character.isDigit(x)) continue;
            if (x == '?') {
                q++;
                continue;
            }
            Map.put(x, Map.getOrDefault(x, 0L) + 1);
        }
        for (long i = 10; i > 10 - Map.size(); i--) {
            baseAnswer *= i;
        }
        if (s.charAt(0) >= 'A' && s.charAt(0) <= 'J') {
            baseAnswer /= 10;
            baseAnswer *= 9;
        }
        if (s.charAt(0) == '?') {
            baseAnswer *= 9;
            q--;
        }
        pw.print(baseAnswer);
        for (long i = 0; i < q; i++) {
            pw.print("0");
        }
        pw.println();
    }

    static Instant TimeStart;
    static Instant TimeEnd;

    static void TimerStart() {
        TimeStart = Instant.now();
    }

    static void TimerStop() {
        TimeEnd = Instant.now();
        Duration elapsedTime = Duration.between(TimeStart, TimeEnd);
        System.out.println("\n\nTime elapsed: " + elapsedTime.toMillis() / 1000.0 + " seconds.\n");
    }
}
