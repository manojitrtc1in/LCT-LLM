import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class beb185f1a818ac2b7758c180959ad313_nc {
    static final long INF = (long) 1e18;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long m = sc.nextLong();
        long h1 = sc.nextLong();
        long a1 = sc.nextLong();
        long x1 = sc.nextLong();
        long y1 = sc.nextLong();
        List<Long> t = new ArrayList<>();
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
        long h2 = sc.nextLong();
        long a2 = sc.nextLong();
        long x2 = sc.nextLong();
        long y2 = sc.nextLong();
        used[(int) h2] = true;
        List<Long> s = new ArrayList<>();
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
        int now = 0;
        while (true) {
            if (t.get(t.size() - 1).equals(t.get(now))) {
                l1 = t.size() - now - 1;
            }
            if (t.get(now).equals(a1)) {
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
            if (s.get(s.size() - 1).equals(s.get(now))) {
                l2 = s.size() - now - 1;
            }
            if (s.get(now).equals(a2)) {
                mn2 = now;
                break;
            }
            now++;
            if (now == s.size()) {
                break;
            }
        }

        long ans = calc(l1, l2, mn1, mn2);
        System.out.println(ans);
    }

    static long calc(long l1, long l2, long mn1, long mn2) {
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
            if (Math.abs(mn2 - mn1) % gcd(l1, l2) != 0) {
                return -1;
            }
            long x = 0, y = 0;
            long g = extgcd(l1, l2, x, y);
            x *= (mn2 - mn1) / g;
            y *= (mn2 - mn1) / g;
            long mn = INF;
            while (x * l1 + mn1 < Math.max(mn1, mn2)) {
                x += l2 / g;
            }
            mn = x * l1 + mn1;
            while (true) {
                x -= l2 / g;
                if (x * l1 + mn1 >= Math.max(mn1, mn2)) {
                    mn = Math.min(mn, x * l1 + mn1);
                } else {
                    break;
                }
            }
            return mn;
        } else {
            return -1;
        }
    }

    static long extgcd(long a, long b, long x, long y) {
        if (a < b) {
            return extgcd(b, a, y, x);
        }
        if (b > 0) {
            long g = extgcd(b, a % b, y, x);
            y -= (a / b) * x;
            return g;
        } else {
            x = 1;
            y = 0;
            return a;
        }
    }

    static long gcd(long a, long b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }
}
