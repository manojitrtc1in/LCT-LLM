import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.next();
        int n = s.length();
        char[] S = s.toCharArray();
        int m = scanner.nextInt();
        int[] Q = new int[m];
        Set<Integer> Qs = new HashSet<>();
        Map<Integer, Integer> ans = new HashMap<>();
        for (int i = 0; i < m; i++) {
            Qs.add(Q[i] = getq(scanner));
        }
        int[] stk = new int[27];
        int nn = 0;
        boolean[] vis = new boolean[26];
        for (int i = 0; i < n; i++) {
            int x = S[i] - 'a';
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
                if (i < n - 1 && (t & (1 << (S[i + 1] - 'a'))) != 0) {
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

    private static int getq(Scanner scanner) {
        char[] buf = scanner.next().toCharArray();
        int ret = 0;
        for (int i = buf.length - 1; i >= 0; i--) {
            ret |= 1 << (buf[i] - 'a');
        }
        return ret;
    }
}
