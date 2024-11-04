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

        for (int i = 0; i < n; i++) {
            A[i] -= 'a';
        }
        A[n] = Z;

        int m = Integer.parseInt(br.readLine());
        for (int i = 0; i < m; i++) {
            char[] buf = br.readLine().toCharArray();
            for (char cur : buf) {
                Q[i] |= (1 << (cur - 'a'));
            }
            have.add(Q[i]);
        }

        int[] stk = new int[Z];
        int nn = 0;
        boolean[] vis = new boolean[Z];
        for (int i = 0; i < n; i++) {
            if (!vis[A[i]]) {
                vis[stk[nn++] = A[i]] = true;
            } else {
                int j;
                for (j = 0; ; j++) {
                    if (stk[j] == A[i]) {
                        break;
                    }
                }
                for (; j < nn - 1; j++) {
                    stk[j] = stk[j + 1];
                }
                stk[nn - 1] = A[i];
            }

            int s = 0;
            for (int j = nn; j >= 0; j--) {
                s |= (1 << stk[j]);
                if ((s & (1 << A[i + 1])) != 0) {
                    break;
                }
                if (have.contains(s)) {
                    ans.put(s, ans.getOrDefault(s, 0) + 1);
                }
            }
        }

        for (int i = 0; i < m; i++) {
            pw.println(ans.get(Q[i]));
        }

        pw.flush();
        pw.close();
    }
}
