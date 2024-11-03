import java.util.*;
import java.io.*;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String S = br.readLine();
        int n = S.length();
        int[] arr = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            arr[i] = S.charAt(i - 1) - 'a';
        }
        arr[n + 1] = 31;
        int m = Integer.parseInt(br.readLine());
        Set<Integer> Qs = new HashSet<>();
        Map<Integer, Integer> ans = new HashMap<>();
        for (int i = 0; i < m; i++) {
            Qs.add(getq(br.readLine()));
        }
        int[] stk = new int[27];
        int nn = 0;
        boolean[] vis = new boolean[26];
        for (int i = 1; i <= n; i++) {
            int x = arr[i];
            if (!vis[x]) {
                stk[++nn] = x;
                vis[x] = true;
            } else {
                int j;
                for (j = 1; ; j++) {
                    if (stk[j] == x) {
                        break;
                    }
                }
                for (; j < nn; j++) {
                    stk[j] = stk[j + 1];
                }
                stk[nn] = x;
            }
            int t = 0;
            for (int j = nn; j > 0; j--) {
                t |= 1 << stk[j];
                if ((t & (1 << arr[i + 1])) != 0) {
                    break;
                }
                if (Qs.contains(t)) {
                    ans.put(t, ans.getOrDefault(t, 0) + 1);
                }
            }
        }
        for (int i = 0; i < m; i++) {
            System.out.println(ans.getOrDefault(Q[i], 0));
        }
    }

    public static int getq(String s) {
        int ret = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            ret |= 1 << (s.charAt(i) - 'a');
        }
        return ret;
    }
}
