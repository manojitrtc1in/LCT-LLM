import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String S = scanner.next();
        int n = S.length();
        char[] charArray = S.toCharArray();
        int[] SArray = new int[n];
        for (int i = 0; i < n; i++) {
            SArray[i] = charArray[i] - 'a';
        }
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
        for (int i = 0; i < 26; i++) {
            vis[i] = false;
        }
        for (int i = 0; i < n; i++) {
            int x = SArray[i];
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
                if (i < n - 1 && (t & (1 << SArray[i + 1])) != 0) {
                    break;
                }
                if (Qs.contains(t)) {
                    if (!ans.containsKey(t)) {
                        ans.put(t, 1);
                    } else {
                        ans.put(t, ans.get(t) + 1);
                    }
                }
            }
        }
        for (int i = 0; i < m; i++) {
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
