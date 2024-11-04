import java.util.*;

public class 9593a92c2c39eb7502bef10ac7a4dc7cxcodeeval_processed_4000.json {
    static final double eps = 1e-8;
    static char[] S = new char[1000100];
    static int n, m;
    
    static int getq() {
        Scanner scanner = new Scanner(System.in);
        String buf = scanner.next();
        int ret = 0;
        for (int i = buf.length() - 1; i >= 0; i--) {
            ret |= 1 << (buf.charAt(i) - 'a');
        }
        return ret;
    }
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        S[0] = ' ';
        String input = scanner.next();
        for (int i = 0; i < input.length(); i++) {
            S[i + 1] = (char) (input.charAt(i) - 'a');
        }
        n = input.length();
        S[n + 1] = 31;
        
        m = scanner.nextInt();
        int[] Q = new int[10010];
        Set<Integer> Qs = new HashSet<>();
        Map<Integer, Integer> ans = new HashMap<>();
        
        for (int i = 1; i <= m; i++) {
            Q[i] = getq();
            Qs.add(Q[i]);
        }
        
        int[] stk = new int[27];
        int nn = 0;
        boolean[] vis = new boolean[26];
        Arrays.fill(vis, false);
        
        for (int i = 1; i <= n; i++) {
            int x = S[i];
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
                if ((t & (1 << S[i + 1])) != 0) break;
                if (Qs.contains(t)) {
                    ans.put(t, ans.getOrDefault(t, 0) + 1);
                }
            }
        }
        
        for (int i = 1; i <= m; i++) {
            System.out.println(ans.getOrDefault(Q[i], 0));
        }
    }
}
