import java.util.*;
import java.io.*;

class Main {
    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }

    public static void main(String[] args) {
        FastReader sc = new FastReader();
        int N = sc.nextInt();
        List<Long> a = new ArrayList<>();
        Map<Long, Integer> mp = new HashMap<>();
        for (int i = 0; i < N; i++) {
            long num = sc.nextLong();
            a.add(num);
            mp.put(num, mp.getOrDefault(num, 0) + 1);
        }
        List<Long> b = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            long num = sc.nextLong();
            b.add(num);
        }

        List<Long> vs = new ArrayList<>();
        for (Map.Entry<Long, Integer> entry : mp.entrySet()) {
            if (entry.getValue() > 1) {
                vs.add(entry.getKey());
            }
        }

        long ans = 0;
        for (int i = 0; i < N; i++) {
            boolean isok = false;
            for (long elem : vs) {
                if ((elem & a.get(i)) == a.get(i)) {
                    isok = true;
                    break;
                }
            }

            if (isok) {
                ans += b.get(i);
            }
        }

        System.out.println(ans);
    }
}
