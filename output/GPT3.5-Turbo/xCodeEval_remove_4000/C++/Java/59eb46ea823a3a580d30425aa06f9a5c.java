import java.util.*;
import java.io.*;

class Main {
    static class Pair implements Comparable<Pair> {
        long x, y;
        int idx;

        Pair(long x, long y, int idx) {
            this.x = x;
            this.y = y;
            this.idx = idx;
        }

        @Override
        public int compareTo(Pair other) {
            if (this.x != other.x) {
                return Long.compare(this.x, other.x);
            }
            return Long.compare(this.y, other.y);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        Pair[] p = new Pair[n];
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            long x = Long.parseLong(st.nextToken());
            long y = Long.parseLong(st.nextToken());
            p[i] = new Pair(x, y, i);
        }
        String s = br.readLine();
        List<Pair> perm = new ArrayList<>();
        int firstIdx = 0;
        for (int i = 0; i < n; i++) {
            if (p[i].compareTo(p[firstIdx]) < 0) {
                firstIdx = i;
            }
        }
        take(firstIdx, perm, p);
        for (int i = 0; i < n - 2; i++) {
            Pair q = perm.get(perm.size() - 1);
            int best = 0;
            for (int j = 1; j < p.length; j++) {
                if ((((p[best].x - q.x) * (p[j].y - q.y)) > 0) == (s.charAt(i) == 'R')) {
                    best = j;
                }
            }
            take(p[best].idx, perm, p);
        }
        take(p[0].idx, perm, p);
        for (Pair pair : perm) {
            System.out.print((pair.idx + 1) + " ");
        }
        System.out.println();
    }

    static void take(int k, List<Pair> perm, Pair[] points) {
        int n = points.length;
        for (int i = 0; i < n; i++) {
            if (points[i].idx == k) {
                swap(points, i, n - 1);
                break;
            }
        }
        perm.add(points[n - 1]);
        points[n - 1] = null;
    }

    static void swap(Pair[] points, int i, int j) {
        Pair temp = points[i];
        points[i] = points[j];
        points[j] = temp;
    }
}
