import java.io.*;
import java.util.*;

public class c91601431f087729dc27a744402b0d65xcodeeval_processed_4000.json {
    static class Point {
        int x, y;

        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }

        public boolean lessThan(Point other) {
            return x * (long) other.y < y * (long) other.x;
        }
    }

    static Point[] p = new Point[10101];
    static Point[] a = new Point[10101];
    static boolean[] used = new boolean[101010];

    static int solve() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st;

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            p[i] = new Point(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
        }

        int cur = 0;
        for (int i = 0; i < n; i++) {
            if (p[i].x < p[cur].x || (p[i].x == p[cur].x && p[i].y < p[cur].y)) {
                cur = i;
            }
        }

        String s = br.readLine();
        s += 'R';
        List<Integer> ans = new ArrayList<>();
        ans.add(cur);

        for (int i = 0; i + 1 < n; i++) {
            used[cur] = true;
            Point zero = p[cur];
            for (int j = 0; j < n; j++) {
                a[j] = new Point(p[j].x - zero.x, p[j].y - zero.y);
            }

            int idx = -1;
            for (int j = 0; j < n; j++) {
                if (!used[j]) {
                    if (idx == -1) idx = j;
                    else {
                        if (s.charAt(i) == 'R' && a[j].lessThan(a[idx])) idx = j;
                        if (s.charAt(i) == 'L' && a[idx].lessThan(a[j])) idx = j;
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

        return 0;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        solve();
    }
}
