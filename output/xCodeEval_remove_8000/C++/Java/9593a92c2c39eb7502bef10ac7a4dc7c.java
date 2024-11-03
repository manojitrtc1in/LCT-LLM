import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String S = scanner.next();
        int n = S.length();
        int[] s = new int[n + 1];
        for (int i = 0; i < n; i++) {
            s[i + 1] = S.charAt(i) - 'a';
        }
        s[n + 1] = 31;
        int m = scanner.nextInt();
        int[] Q = new int[m + 1];
        Set<Integer> Qs = new HashSet<>();
        Map<Integer, Integer> ans = new HashMap<>();
        for (int i = 1; i <= m; i++) {
            int q = getq(scanner);
            Qs.add(q);
            Q[i] = q;
        }
        int[] stk = new int[27];
        int nn = 0;
        boolean[] vis = new boolean[26];
        for (int i = 1; i <= n; i++) {
            int x = s[i];
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
                if ((t & (1 << s[i + 1])) != 0) {
                    break;
                }
                if (Qs.contains(t)) {
                    ans.put(t, ans.getOrDefault(t, 0) + 1);
                }
            }
        }
        for (int i = 1; i <= m; i++) {
            System.out.println(ans.getOrDefault(Q[i], 0));
        }
    }

    public static int getq(Scanner scanner) {
        String buf = scanner.next();
        int ret = 0;
        for (int i = buf.length() - 1; i >= 0; i--) {
            ret |= 1 << (buf.charAt(i) - 'a');
        }
        return ret;
    }
}
