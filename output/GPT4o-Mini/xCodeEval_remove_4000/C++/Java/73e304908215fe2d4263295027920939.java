import java.io.*;
import java.util.*;
import java.time.*;

public class 73e304908215fe2d4263295027920939xcodeeval_processed_4000.json {
    static long Mod = 1000000007L, INF = (long) 1e9, LINF = (long) 1e18;
    static long Pi = 3.141592653589793116, EPS = 1e-9, Gold = (1 + Math.sqrt(5)) / 2;
    static long[] keymod = {1000000007L, 1000000009L, 1000000021L, 1000000033L};
    static int keyCount = keymod.length;

    static long m, h1, a1, x1, y1, h2, a2, x2, y2;
    static int[] vis1, vis2;

    public static void main(String[] args) throws IOException {
        ControlIO(args);
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);

        Input(br);
        TimerStart();
        Solve(out);
        TimerStop();

        int T = Integer.parseInt(br.readLine());
        TimerStart();
        while (T-- > 0) {
            Input(br);
            Solve(out);
        }
        TimerStop();
        out.close();
    }

    static void ControlIO(String[] args) throws IOException {
        String id1 = "FILE.IN";
        String id3 = "FILE.OUT";

        if (args.length > 0) {
            System.setIn(new FileInputStream(args[0]));
        } else {
            System.setIn(new FileInputStream(id1));
        }
        if (args.length > 1) {
            System.setOut(new PrintStream(new FileOutputStream(args[1])));
        } else {
            System.setOut(new PrintStream(new FileOutputStream(id3)));
        }

        System.out.println("Source code by ");
        System.out.println("Current time: " + LocalDateTime.now());
        System.out.println("\nOI-Mode: ON");
        System.out.println("Input file: " + id1);
        System.out.println("Output file: " + id3);
        System.out.println("\nMultiTest-Mode: ON");
        System.out.println("Interactive-Mode: ON\n");
    }

    static void Input(BufferedReader br) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        m = Long.parseLong(st.nextToken());
        h1 = Long.parseLong(st.nextToken());
        a1 = Long.parseLong(st.nextToken());
        x1 = Long.parseLong(st.nextToken());
        y1 = Long.parseLong(st.nextToken());
        h2 = Long.parseLong(st.nextToken());
        a2 = Long.parseLong(st.nextToken());
        x2 = Long.parseLong(st.nextToken());
        y2 = Long.parseLong(st.nextToken());
        vis1 = new int[(int) m];
        vis2 = new int[(int) m];
        Arrays.fill(vis1, -1);
        Arrays.fill(vis2, -1);
    }

    static void Solve(PrintWriter out) {
        vis1[(int) h1] = 0;
        long id4 = -1, id5 = -1;
        while (true) {
            long z = (h1 * x1 + y1) % m;
            if (vis1[(int) z] != -1) {
                id4 = vis1[(int) z];
                id5 = (vis1[(int) h1] + 1) - vis1[(int) z];
                break;
            } else {
                vis1[(int) z] = vis1[(int) h1] + 1;
            }
            h1 = z;
        }

        vis2[(int) h2] = 0;
        long id0 = -1, id2 = -1;
        while (true) {
            long z = (h2 * x2 + y2) % m;
            if (vis2[(int) z] != -1) {
                id0 = vis2[(int) z];
                id2 = (vis2[(int) h2] + 1) - vis2[(int) z];
                break;
            } else {
                vis2[(int) z] = vis2[(int) h2] + 1;
            }
            h2 = z;
        }

        if (vis1[(int) a1] == -1 || vis2[(int) a2] == -1) {
            out.println("-1");
            return;
        }

        if (vis1[(int) a1] < id4 && vis2[(int) a2] < id0) {
            if (vis1[(int) a1] == vis2[(int) a2]) out.println(vis1[(int) a1]);
            else out.println("-1");
            return;
        }

        if (vis1[(int) a1] >= id4 && vis2[(int) a2] >= id0) {
            long ans = -1;
            for (long i = 0; i <= 1000000; i++) {
                long expected = vis1[(int) a1] + id5 * i;
                if ((expected - vis2[(int) a2]) % id2 == 0 && (expected - vis2[(int) a2]) / id2 >= 0) {
                    ans = expected;
                    break;
                }
            }
            out.println(ans);
            return;
        }

        if (vis1[(int) a1] < id4 && vis2[(int) a2] >= id0) {
            if ((vis1[(int) a1] - vis2[(int) a2]) % id2 == 0 && (vis1[(int) a1] - vis2[(int) a2]) / id2 >= 0)
                out.println(vis1[(int) a1]);
            else out.println("-1");
            return;
        }

        if (vis1[(int) a1] >= id4 && vis2[(int) a2] < id0) {
            if ((vis2[(int) a2] - vis1[(int) a1]) % id5 == 0 && (vis2[(int) a2] - vis1[(int) a1]) / id5 >= 0)
                out.println(vis2[(int) a2]);
            else out.println("-1");
            return;
        }
    }

    static void TimerStart() {
        // Timer start logic can be implemented if needed
    }

    static void TimerStop() {
        // Timer stop logic can be implemented if needed
    }
}
