import java.util.*;
import java.io.*;

class Main {
    static final int N = 1000009, M = 10009, Z = 26;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        char[] A = br.readLine().toCharArray();
        int n = A.length;
        int[] Q = new int[M];
        Set<Integer> have = new HashSet<>();
        Map<Integer, Integer> ans = new HashMap<>();

        for (int i = 0; i < M; i++) {
            char[] buf = br.readLine().toCharArray();
            int q = 0;
            for (char c : buf) {
                q |= (1 << (c - 'a'));
            }
            Q[i] = q;
            have.add(q);
        }

        int[] stk = new int[Z];
        int nn = 0;
        boolean[] vis = new boolean[Z];

        for (int i = 0; i < n; i++) {
            int x = A[i] - 'a';
            if (!vis[x]) {
                vis[stk[nn++] = x] = true;
            } else {
                int j;
                for (j = 0; ; j++) {
                    if (stk[j] == x) {
                        break;
                    }
                }
                for (; j < nn - 1; j++) {
                    stk[j] = stk[j + 1];
                }
                stk[nn - 1] = x;
            }

            int s = 0;
            for (int j = nn; j >= 0; j--) {
                s |= (1 << stk[j]);
                if ((s & (1 << (A[i + 1] - 'a'))) != 0) {
                    break;
                }
                if (have.contains(s)) {
                    ans.put(s, ans.getOrDefault(s, 0) + 1);
                }
            }
        }

        for (int i = 0; i < M; i++) {
            pw.println(ans.getOrDefault(Q[i], 0));
        }

        pw.flush();
        pw.close();
    }
}
