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
        int[] Q = new int[m + 1];
        Set<Integer> Qs = new HashSet<>();
        Map<Integer, Integer> ans = new HashMap<>();
        for (int i = 1; i <= m; i++) {
            Qs.add(Q[i] = getq(br));
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
                    if (stk[j] == x) break;
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
        for (int i = 1; i <= m; i++) {
            System.out.println(ans.get(Q[i]));
        }
    }

    public static int getq(BufferedReader br) throws IOException {
        String buf = br.readLine();
        int ret = 0;
        for (int i = buf.length() - 1; i >= 0; i--) {
            ret |= 1 << (buf.charAt(i) - 'a');
        }
        return ret;
    }
}
