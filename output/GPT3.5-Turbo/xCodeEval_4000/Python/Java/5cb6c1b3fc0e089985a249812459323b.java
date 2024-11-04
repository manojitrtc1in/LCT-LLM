import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class 5cb6c1b3fc0e089985a249812459323b_nc {
    public static void main(String[] args) {
        FastScanner fs = new FastScanner();
        int n = fs.nextInt();
        int k = fs.nextInt();
        int[] l = new int[n];
        for (int i = 0; i < n; i++) {
            l[i] = fs.nextInt() % k;
        }
        if (n == 1) {
            System.out.println(l[0]);
            System.exit(0);
        }
        int[] l1 = new int[n / 2];
        int[] l2 = new int[n - n / 2];
        System.arraycopy(l, 0, l1, 0, n / 2);
        System.arraycopy(l, n / 2, l2, 0, n - n / 2);
        Set<Integer> s = new HashSet<>();
        Set<Integer> s1 = new HashSet<>();
        Set<Integer> s2 = new HashSet<>();
        for (int i = 0; i < n / 2; i++) {
            for (int j : s) {
                s2.add((j + l1[i]) % k);
            }
            s.add(l1[i]);
            for (int j : s2) {
                s.add(j);
            }
            s2.clear();
        }
        for (int i = 0; i < n - n / 2; i++) {
            for (int j : s1) {
                s2.add((j + l2[i]) % k);
            }
            s1.add(l2[i]);
            for (int j : s2) {
                s1.add(j);
            }
            s2.clear();
        }
        int[] sArr = new int[s.size()];
        int[] s1Arr = new int[s1.size()];
        int idx = 0;
        for (int num : s) {
            sArr[idx++] = num;
        }
        idx = 0;
        for (int num : s1) {
            s1Arr[idx++] = num;
        }
        int ans = Math.max(Math.max(max(sArr), max(s1Arr)), max(sArr) + max(s1Arr));
        System.out.println(ans);
    }

    private static int max(int[] arr) {
        int max = Integer.MIN_VALUE;
        for (int num : arr) {
            max = Math.max(max, num);
        }
        return max;
    }

    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner() {
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
}
