import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main2 {

    static long mod = 1000000007L;


    static Map<Long, Integer> results = new HashMap<>();

    public static void main(String[] args) throws Exception {
        FastScanner scanner = new FastScanner();
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        int k = scanner.nextInt();
        if (m < k) {
            System.out.println("-1");
            return;
        }
        Value[] values = new Value[n];
        for (int i = 0; i < n; i++) {
            values[i] = new Value(i, scanner.nextInt());
        }
        int an = scanner.nextInt();
        for (int i = 0; i < an; i++) {
            int rn = scanner.nextInt();
            values[rn - 1].mashaLikes = true;
        }
        an = scanner.nextInt();
        for (int i = 0; i < an; i++) {
            int rn = scanner.nextInt();
            values[rn - 1].artemLikes = true;
        }

        List<Value> bothLikes = new ArrayList<>();
        List<Value> all = new ArrayList<>();
        List<Value> artem = new ArrayList<>();
        List<Value> masha = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            if (values[i].artemLikes && values[i].mashaLikes) {
                bothLikes.add(values[i]);
                continue;
            }
            all.add(values[i]);
            if (values[i].artemLikes) artem.add(values[i]);
            if (values[i].mashaLikes) masha.add(values[i]);
        }
        Sumable bothSum = new Sumable(bothLikes);
        Sumable allSum = new Sumable(all);
        Sumable artemSum = new Sumable(artem);
        Sumable mashaSum = new Sumable(masha);

        Likes[] allLikes = new Likes[all.size() + 1];
        allLikes[0] = new Likes(0, 0);
        for (int i = 1; i <= all.size(); i++) {
            Value cur = all.get(i-1);
            if (cur.artemLikes) allLikes[i] = allLikes[i-1].nextArtem();
            else if (cur.mashaLikes) allLikes[i] = allLikes[i-1].nextMasha();
            else allLikes[i] = allLikes[i-1];
        }

        long answer = Long.MAX_VALUE;
        for (int i = 0; i <= Math.min(m, bothSum.values.size()); i++) {
            long current = bothSum.getSum(0, i);
            int remaining = m - i;
            int eachRemaining = Math.max(k - i, 0);
            if (remaining < eachRemaining * 2 || all.size() < remaining ||
                    artem.size() < eachRemaining || masha.size() < eachRemaining) continue;


            if (allLikes[remaining].artem >= eachRemaining && allLikes[remaining].masha >= eachRemaining) {
                current += allSum.getSum(0, remaining);
            } else {
                

                int r = remaining;
                while (r >= 0) {
                    if (Math.max(eachRemaining - allLikes[r].artem, 0) + Math.max(eachRemaining - allLikes[r].masha, 0) <= remaining - r) break;
                    r--;
                }
                

                current += allSum.getSum(0, r);
                current += artemSum.getSum(allLikes[r].artem, eachRemaining);
                current += mashaSum.getSum(allLikes[r].masha, eachRemaining);
            }
            answer = Math.min(answer, current);
        }

        System.out.println(answer == Long.MAX_VALUE ? -1 : answer);
    }

    static class Sumable {
        List<Value> values;
        long[] sums;

        public Sumable(List<Value> values) {
            Collections.sort(values);
            this.values = values;
            sums = new long[values.size() + 1];
            for (int i = 1; i <= values.size(); i++) {
                sums[i] = sums[i-1] + values.get(i-1).price;
            }
        }

        long getSum(int start, int end) {
            if (end <= start) return 0;
            return sums[end] - sums[start];
        }
    }

    static class Value implements Comparable<Value> {
        int id;
        int price;
        boolean mashaLikes;
        boolean artemLikes;

        public Value(int id, int price) {
            this.id = id;
            this.price = price;
        }

        @Override
        public int compareTo(Value o) {
            if (o.price == price) return id - o.id;
            return price - o.price;
        }
    }

    static class Likes {
        int artem;
        int masha;

        public Likes(int artem, int masha) {
            this.artem = artem;
            this.masha = masha;
        }

        public Likes nextArtem() {
            return new Likes(artem + 1, masha);
        }

        public Likes nextMasha() {
            return new Likes(artem, masha + 1);
        }
    }

    static long modpow(long base, long exp, long modulus) {
        base %= modulus;
        long result = 1;
        while (exp > 0) {
            if ((exp & 1) == 1) result = (result * base) % modulus;
            base = (base * base) % modulus;
            exp >>= 1;
        }
        return result;
    }

    public static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String nextToken() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    

                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        String nextLine() {
            try {
                return br.readLine();
            } catch (Exception e) {
                e.printStackTrace();
                throw new RuntimeException();
            }
        }

        int nextInt() {
            return Integer.parseInt(nextToken());
        }

        long nextLong() {
            return Long.parseLong(nextToken());
        }

        double nextDouble() {
            return Double.parseDouble(nextToken());
        }
    }
}




