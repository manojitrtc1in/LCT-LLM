import java.util.*;
import java.io.*;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        List<List<Tuple>> a = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            String str = br.readLine();
            st = new StringTokenizer(str);
            List<Tuple> row = new ArrayList<>();
            for (int j = 0; j < m; j++) {
                int x = Integer.parseInt(st.nextToken());
                int y = Integer.parseInt(st.nextToken());
                int z = Integer.parseInt(st.nextToken());
                row.add(new Tuple(x, y, z));
            }
            a.add(row);
        }

        int val = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    val = Math.max(val, refill(k, a.get(i), a.get(j)));
                }
            }
        }

        System.out.println(val);
    }

    public static int refill(int k, List<Tuple> left, List<Tuple> right) {
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for (int i = 0; i < left.size(); i++) {
            pq.offer(right.get(i).y - left.get(i).x);
        }

        int val = 0;
        while (!pq.isEmpty() && k > 0) {
            int diff = pq.poll();
            if (diff > 0) {
                int w = Math.min(k, left.get(diff).z);
                k -= w;
                val += w * diff;
            }
        }

        return val;
    }

    static class Tuple {
        int x, y, z;

        public Tuple(int x, int y, int z) {
            this.x = x;
            this.y = y;
            this.z = z;
        }
    }
}
