import java.util.*;
import java.io.*;

class Point {
    int x, y, i;

    Point() {}

    Point(int x, int y, int i) {
        this.x = x;
        this.y = y;
        this.i = i;
    }

    @Override
    public String toString() {
        return "(" + x + ", " + y + ")";
    }
}

public class ab064721cbb4c4373b752374fc4f664dxcodeeval_processed_4000.json {
    static final int N = 2000 + 7;
    static int n;
    static Point[] a = new Point[N];
    static String s;

    static boolean read() {
        Scanner scanner = new Scanner(System.in);
        if (!scanner.hasNextInt()) return false;
        n = scanner.nextInt();
        for (int i = 0; i < n; i++) {
            a[i] = new Point(scanner.nextInt(), scanner.nextInt(), i + 1);
        }
        s = scanner.next();
        return true;
    }

    static Point subtract(Point a, Point b) {
        return new Point(a.x - b.x, a.y - b.y, -1);
    }

    static Point add(Point a, Point b) {
        return new Point(a.x + b.x, a.y + b.y, -1);
    }

    static boolean equals(Point a, Point b) {
        return (a.x == b.x && a.y == b.y);
    }

    static long sdist(Point a, Point b) {
        return (long) (a.x - b.x) * (a.x - b.x) + (long) (a.y - b.y) * (a.y - b.y);
    }

    static long dot(Point a, Point b) {
        return a.x * (long) b.x + a.y * (long) b.y;
    }

    static long cross(Point a, Point b) {
        return a.x * (long) b.y - a.y * (long) b.x;
    }

    static List<Point> build() {
        if (n <= 1) {
            return Arrays.asList(Arrays.copyOf(a, n));
        }

        List<Point> up = new ArrayList<>();
        List<Point> dw = new ArrayList<>();
        up.add(a[0]);
        dw.add(a[0]);

        for (int i = 1; i < n; i++) {
            if (i == n - 1 || cross(subtract(a[n - 1], a[0]), subtract(a[i], a[0])) >= 0) {
                while (up.size() > 1 && cross(subtract(a[i], up.get(up.size() - 2)), subtract(up.get(up.size() - 1), up.get(up.size() - 2))) < 0) {
                    up.remove(up.size() - 1);
                }
                up.add(a[i]);
            }
            if (i == n - 1 || cross(subtract(a[n - 1], a[0]), subtract(a[i], a[0])) < 0) {
                while (dw.size() > 1 && cross(subtract(a[i], dw.get(dw.size() - 2)), subtract(dw.get(dw.size() - 1), dw.get(dw.size() - 2))) > 0) {
                    dw.remove(dw.size() - 1);
                }
                dw.add(a[i]);
            }
        }

        List<Point> res = new ArrayList<>(up);
        for (int i = dw.size() - 2; i >= 1; --i) {
            res.add(dw.get(i));
        }

        return res;
    }

    static void solve() {
        Arrays.sort(a, 0, n, Comparator.comparingInt(p -> p.x));
        List<Point> ans = new ArrayList<>();

        List<Point> ch = build();
        ans.add(ch.get(0));
        if (s.charAt(0) == 'L') {
            ans.add(ch.get(ch.size() - 1));
        } else {
            ans.add(ch.get(1));
        }

        for (int i = 0; i < s.length(); i++) {
            int x = Arrays.asList(a).indexOf(ans.get(ans.size() - 2));
            System.arraycopy(a, x + 1, a, x, n - x - 1);
            n--;
            ch = build();
            int pos = ch.indexOf(ans.get(ans.size() - 1));
            if (s.charAt(i + 1) == 'L') {
                ans.add(ch.get((pos - 1 + ch.size()) % ch.size()));
            } else {
                ans.add(ch.get((pos + 1) % ch.size()));
            }
        }

        for (Point it : ans) {
            System.out.print(it.i + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        try {
            Scanner scanner = new Scanner(new File("input.txt"));
            while (read()) {
                solve();
            }
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }
}
