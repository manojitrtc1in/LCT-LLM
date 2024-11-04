import java.util.*;
import java.io.*;

public class 73e304908215fe2d4263295027920939_nc {
    static long m, h1, a1, x1, y1, h2, a2, x2, y2;
    static ArrayList<Long> vis1, vis2;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        m = sc.nextLong();
        h1 = sc.nextLong();
        a1 = sc.nextLong();
        x1 = sc.nextLong();
        y1 = sc.nextLong();
        h2 = sc.nextLong();
        a2 = sc.nextLong();
        x2 = sc.nextLong();
        y2 = sc.nextLong();
        vis1 = new ArrayList<>(Collections.nCopies((int) m, -1L));
        vis2 = new ArrayList<>(Collections.nCopies((int) m, -1L));

        vis1.set((int) h1, 0L);
        long cycleStart1 = -1, cycleLen1 = -1;
        while (true) {
            long z = (h1 * x1 + y1) % m;
            if (vis1.get((int) z) != -1) {
                cycleStart1 = vis1.get((int) z);
                cycleLen1 = (vis1.get((int) h1) + 1) - vis1.get((int) z);
                break;
            } else {
                vis1.set((int) z, vis1.get((int) h1) + 1);
            }
            h1 = z;
        }

        vis2.set((int) h2, 0L);
        long cycleStart2 = -1, cycleLen2 = -1;
        while (true) {
            long z = (h2 * x2 + y2) % m;
            if (vis2.get((int) z) != -1) {
                cycleStart2 = vis2.get((int) z);
                cycleLen2 = (vis2.get((int) h2) + 1) - vis2.get((int) z);
                break;
            } else {
                vis2.set((int) z, vis2.get((int) h2) + 1);
            }
            h2 = z;
        }

        if (vis1.get((int) a1) == -1 || vis2.get((int) a2) == -1) {
            System.out.println("-1");
            return;
        }

        if (vis1.get((int) a1) < cycleStart1 && vis2.get((int) a2) < cycleStart2) {
            if (vis1.get((int) a1).equals(vis2.get((int) a2))) {
                System.out.println(vis1.get((int) a1));
            } else {
                System.out.println("-1");
            }
            return;
        }

        if (vis1.get((int) a1) >= cycleStart1 && vis2.get((int) a2) >= cycleStart2) {
            long ans = -1;
            for (long i = 0; i <= 1000000; i++) {
                long expected = vis1.get((int) a1) + cycleLen1 * i;
                if ((expected - vis2.get((int) a2)) % cycleLen2 == 0 && (expected - vis2.get((int) a2)) / cycleLen2 >= 0) {
                    ans = expected;
                    break;
                }
            }
            System.out.println(ans);
            return;
        }

        if (vis1.get((int) a1) < cycleStart1 && vis2.get((int) a2) >= cycleStart2) {
            if ((vis1.get((int) a1) - vis2.get((int) a2)) % cycleLen2 == 0 && (vis1.get((int) a1) - vis2.get((int) a2)) / cycleLen2 >= 0) {
                System.out.println(vis1.get((int) a1));
            } else {
                System.out.println("-1");
            }
            return;
        }

        if (vis1.get((int) a1) >= cycleStart1 && vis2.get((int) a2) < cycleStart2) {
            if ((vis2.get((int) a2) - vis1.get((int) a1)) % cycleLen1 == 0 && (vis2.get((int) a2) - vis1.get((int) a1)) / cycleLen1 >= 0) {
                System.out.println(vis2.get((int) a2));
            } else {
                System.out.println("-1");
            }
            return;
        }
    }
}
