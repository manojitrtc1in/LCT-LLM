import java.util.*;

class Main {
    static final long INF = (long) 1e18;

    static long gcd(long a, long b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    static long id1(long a, long b, long[] x, long[] y) {
        if (a < b) {
            return id1(b, a, y, x);
        }

        if (b > 0) {
            long g = id1(b, a % b, y, x);
            y[0] -= (a / b) * x[0];
            return g;
        } else {
            x[0] = 1;
            y[0] = 0;
            return a;
        }
    }

    static long calc(long m, long h1, long a1, long x1, long y1, long h2, long a2, long x2, long y2) {
        ArrayList<Long> t = new ArrayList<>();
        boolean[] used = new boolean[(int) m];
        used[(int) h1] = true;
        t.add(h1);
        while (true) {
            long tmp = (t.get(t.size() - 1) * x1 + y1) % m;
            t.add(tmp);
            if (used[(int) tmp]) {
                break;
            }
            used[(int) tmp] = true;
        }
        used = new boolean[(int) m];
        used[(int) h2] = true;
        ArrayList<Long> s = new ArrayList<>();
        s.add(h2);
        while (true) {
            long tmp = (s.get(s.size() - 1) * x2 + y2) % m;
            s.add(tmp);
            if (used[(int) tmp]) {
                break;
            }
            used[(int) tmp] = true;
        }

        long l1 = -1, l2 = -1;
        long mn1 = INF, mn2 = INF;
        long now = 0;
        while (true) {
            if (t.get(t.size() - 1).equals(t.get((int) now))) {
                l1 = t.size() - now - 1;
            }
            if (t.get((int) now).equals(a1)) {
                mn1 = now;
                break;
            }
            now++;
            if (now == t.size()) {
                break;
            }
        }
        now = 0;
        while (true) {
            if (s.get(s.size() - 1).equals(s.get((int) now))) {
                l2 = s.size() - now - 1;
            }
            if (s.get((int) now).equals(a2)) {
                mn2 = now;
                break;
            }
            now++;
            if (now == s.size()) {
                break;
            }
        }

        if (mn1 != INF && mn2 != INF) {
            if (mn1 == mn2) {
                return mn1;
            }
            if (mn1 > mn2 && l2 == -1) {
                return -1;
            }
            if (mn1 < mn2 && l1 == -1) {
                return -1;
            }
            if (l1 == -1) {
                if ((mn1 - mn2) % l2 == 0) {
                    return mn1;
                } else {
                    return -1;
                }
            }
            if (l2 == -1) {
                if ((mn2 - mn1) % l1 == 0) {
                    return mn2;
                } else {
                    return -1;
                }
            }
            if (l1 == l2) {
                if (Math.abs(mn1 - mn2) % l1 == 0) {
                    return Math.max(mn1, mn2);
                } else {
                    return -1;
                }
            }
            if (mn2 > mn1 && (mn2 - mn1) % l1 == 0) {
                return mn2;
            }
            if (mn1 > mn2 && (mn1 - mn2) % l2 == 0) {
                return mn1;
            }

            if (Math.abs(mn2 - mn1) % Math.abs(gcd(l1, l2)) != 0) {
                return -1;
            }
            long[] x = new long[1];
            long[] y = new long[1];
            long g = id1(l1, l2, x, y);
            x[0] *= (mn2 - mn1) / g;
            y[0] *= (mn2 - mn1) / g;
            long mn = INF;
            while (x[0] * l1 + mn1 < Math.max(mn1, mn2)) {
                x[0] += l2 / g;
            }
            mn = x[0] * l1 + mn1;
            while (true) {
                x[0] -= l2 / g;
                if (x[0] * l1 + mn1 >= Math.max(mn1, mn2)) {
                    mn = Math.min(mn, x[0] * l1 + mn1);
                } else {
                    break;
                }
            }
            return mn;
        } else {
            return -1;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long m = sc.nextLong();
        long h1 = sc.nextLong();
        long a1 = sc.nextLong();
        long x1 = sc.nextLong();
        long y1 = sc.nextLong();
        long h2 = sc.nextLong();
        long a2 = sc.nextLong();
        long x2 = sc.nextLong();
        long y2 = sc.nextLong();
        System.out.println(calc(m, h1, a1, x1, y1, h2, a2, x2, y2));
    }
}
