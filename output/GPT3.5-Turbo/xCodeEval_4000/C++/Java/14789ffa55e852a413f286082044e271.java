import java.util.*;
import java.io.*;

class Main {
    static class Point {
        int x, y, i;

        Point() {}

        Point(int x, int y, int i) {
            this.x = x;
            this.y = y;
            this.i = i;
        }

        public String toString() {
            return "(" + x + ", " + y + ")";
        }
    }

    static boolean read() throws IOException {
        if (!sc.hasNextInt()) {
            return false;
        }
        n = sc.nextInt();
        a = new Point[n];
        for (int i = 0; i < n; i++) {
            int x = sc.nextInt();
            int y = sc.nextInt();
            a[i] = new Point(x, y, i + 1);
        }
        s = sc.next();
        return true;
    }

    static Point[] a;
    static int n;
    static String s;
    static final int N = 2000 + 7;

    static Point[] build() {
        if (n <= 1) {
            return Arrays.copyOf(a, n);
        }

        List<Point> up = new ArrayList<>();
        List<Point> dw = new ArrayList<>();
        up.add(a[0]);
        dw.add(a[0]);

        for (int i = 1; i < n; i++) {
            if (i == n - 1 || cross(sub(a[n - 1], a[0]), sub(a[i], a[0])) >= 0) {
                while (up.size() > 1 && cross(sub(a[i], up.get(up.size() - 2)), sub(up.get(up.size() - 1), up.get(up.size() - 2))) < 0) {
                    up.remove(up.size() - 1);
                }
                up.add(a[i]);
            }
            if (i == n - 1 || cross(sub(a[n - 1], a[0]), sub(a[i], a[0])) < 0) {
                while (dw.size() > 1 && cross(sub(a[i], dw.get(dw.size() - 2)), sub(dw.get(dw.size() - 1), dw.get(dw.size() - 2))) > 0) {
                    dw.remove(dw.size() - 1);
                }
                dw.add(a[i]);
            }
        }

        List<Point> res = new ArrayList<>(up);
        for (int i = dw.size() - 2; i >= 1; i--) {
            res.add(dw.get(i));
        }

        return res.toArray(new Point[res.size()]);
    }

    static Point sub(Point a, Point b) {
        return new Point(a.x - b.x, a.y - b.y, -1);
    }

    static long sdist(Point a, Point b) {
        return sqr((long) (a.x - b.x)) + sqr((long) (a.y - b.y));
    }

    static long dot(Point a, Point b) {
        return (long) a.x * b.x + (long) a.y * b.y;
    }

    static long cross(Point a, Point b) {
        return (long) a.x * b.y - (long) a.y * b.x;
    }

    static long sqr(long a) {
        return a * a;
    }

    static void solve() {
        Arrays.sort(a, new Comparator<Point>() {
            public int compare(Point p1, Point p2) {
                if (p1.x != p2.x) {
                    return p1.x - p2.x;
                }
                return p1.y - p2.y;
            }
        });

        Set<Point> cur = new HashSet<>(Arrays.asList(a));
        List<Point> ans = new ArrayList<>();

        Point[] ch = build();
        ans.add(ch[0]);
        if (s.charAt(0) == 'L') {
            ans.add(ch[ch.length - 1]);
        } else {
            ans.add(ch[1]);
        }
        cur.remove(ch[0]);

        for (int i = 0; i < s.length(); i++) {
            n = 0;
            for (Point it : cur) {
                a[n++] = it;
            }
            ch = build();
            int pos = Arrays.asList(ch).indexOf(ans.get(ans.size() - 1));
            if (s.charAt(i + 1) == 'L') {
                ans.add(ch[(pos - 1 + ch.length) % ch.length]);
            } else {
                ans.add(ch[(pos + 1) % ch.length]);
            }
            cur.remove(ans.get(ans.size() - 2));
        }

        for (Point it : ans) {
            out.print(it.i + " ");
        }
        out.println();
    }

    static PrintWriter out;
    static Scanner sc;

    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        out = new PrintWriter(System.out);

        while (read()) {
            solve();
        }

        out.close();
    }
}
