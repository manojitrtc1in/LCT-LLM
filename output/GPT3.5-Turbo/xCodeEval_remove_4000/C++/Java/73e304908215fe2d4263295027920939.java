import java.util.*;
import java.io.*;

class Main {
    static long Mod = 1000000007L;
    static int INF = 1000000000;
    static double Pi = 3.141592653589793116;
    static double EPS = 1e-9;
    static double Gold = ((1 + Math.sqrt(5)) / 2);

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

    static long m, h1, a1, x1, y1, h2, a2, x2, y2;
    static ArrayList<Long> vis1, vis2;

    static void Input() {
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
    }

    static void Solve() {
        vis1.set((int) h1, 0L);
        long id4 = -1, id5 = -1;
        while (true) {
            long z = (h1 * x1 + y1) % m;
            if (vis1.get((int) z) != -1) {
                id4 = vis1.get((int) z);
                id5 = (vis1.get((int) h1) + 1) - vis1.get((int) z);
                break;
            } else {
                vis1.set((int) z, vis1.get((int) h1) + 1);
            }
            h1 = z;
        }
        vis2.set((int) h2, 0L);
        long id0 = -1, id2 = -1;
        while (true) {
            long z = (h2 * x2 + y2) % m;
            if (vis2.get((int) z) != -1) {
                id0 = vis2.get((int) z);
                id2 = (vis2.get((int) h2) + 1) - vis2.get((int) z);
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
        if (vis1.get((int) a1) < id4 && vis2.get((int) a2) < id0) {
            if (vis1.get((int) a1).equals(vis2.get((int) a2))) {
                System.out.println(vis1.get((int) a1));
            } else {
                System.out.println("-1");
            }
            return;
        }
        if (vis1.get((int) a1) >= id4 && vis2.get((int) a2) >= id0) {
            long ans = -1;
            for (long i = 0; i <= 1000000; i++) {
                long expected = vis1.get((int) a1) + id5 * i;
                if ((expected - vis2.get((int) a2)) % id2 == 0 && (expected - vis2.get((int) a2)) / id2 >= 0) {
                    ans = expected;
                    break;
                }
            }
            System.out.println(ans);
            return;
        }
        if (vis1.get((int) a1) < id4 && vis2.get((int) a2) >= id0) {
            if ((vis1.get((int) a1) - vis2.get((int) a2)) % id2 == 0 && (vis1.get((int) a1) - vis2.get((int) a2)) / id2 >= 0) {
                System.out.println(vis1.get((int) a1));
            } else {
                System.out.println("-1");
            }
            return;
        }
        if (vis1.get((int) a1) >= id4 && vis2.get((int) a2) < id0) {
            if ((vis2.get((int) a2) - vis1.get((int) a1)) % id5 == 0 && (vis2.get((int) a2) - vis1.get((int) a1)) / id5 >= 0) {
                System.out.println(vis2.get((int) a2));
            } else {
                System.out.println("-1");
            }
            return;
        }
    }

    public static void main(String[] args) {
        Input();
        Solve();
    }
}
