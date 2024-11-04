import java.util.*;
import java.io.*;

class Main {
    static class Point implements Comparable<Point> {
        int x, y;

        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }

        public int compareTo(Point other) {
            return Integer.compare(this.x * other.y, this.y * other.x);
        }
    }

    static Point[] p;
    static Point[] a;
    static boolean[] used;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        p = new Point[n];
        for (int i = 0; i < n; i++) {
            String[] input = br.readLine().split(" ");
            int x = Integer.parseInt(input[0]);
            int y = Integer.parseInt(input[1]);
            p[i] = new Point(x, y);
        }
        int cur = 0;
        for (int i = 0; i < n; i++) {
            if (p[i].x < p[cur].x || (p[i].x == p[cur].x && p[i].y < p[cur].y)) {
                cur = i;
            }
        }
        String s = br.readLine();
        s += "R";
        ArrayList<Integer> ans = new ArrayList<>();
        ans.add(cur);
        used = new boolean[n];
        for (int i = 0; i + 1 < n; i++) {
            used[cur] = true;
            Point zero = p[cur];
            a = new Point[n];
            for (int j = 0; j < n; j++) {
                a[j] = new Point(p[j].x - zero.x, p[j].y - zero.y);
            }
            int idx = -1;
            for (int j = 0; j < n; j++) {
                if (!used[j]) {
                    if (idx == -1) {
                        idx = j;
                    } else {
                        if (s.charAt(i) == 'R' && a[j].compareTo(a[idx]) < 0) {
                            idx = j;
                        }
                        if (s.charAt(i) == 'L' && a[idx].compareTo(a[j]) < 0) {
                            idx = j;
                        }
                    }
                }
            }
            cur = idx;
            ans.add(cur);
        }
        for (int x : ans) {
            System.out.print((x + 1) + " ");
        }
        System.out.println();
    }
}
