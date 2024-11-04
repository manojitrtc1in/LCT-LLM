import java.util.*;

public class 18f4c797aaf57b3947a6000d6b07af4c_nc {
    static final int N = 1000009, M = 10009, Z = 26;
    static char[] A = new char[N];
    static int[] Q = new int[M];
    static Set<Integer> have = new HashSet<>();
    static Map<Integer, Integer> ans = new HashMap<>();
    static int n, m;

    static int[] stk = new int[Z];
    static int nn;
    static boolean[] vis = new boolean[Z];

    static void push(int x) {
        if (!vis[x]) {
            vis[stk[nn++] = x] = true;
        } else {
            int j;
            for (j = 0; ; j++) if (stk[j] == x) break;
            for (; j < nn - 1; j++) stk[j] = stk[j + 1];
            stk[nn - 1] = x;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        String input = scanner.nextLine();
        n = input.length();
        for (int i = 0; i < n; i++) {
            A[i] = (char) (input.charAt(i) - 'a');
        }
        A[n] = (char) Z;

        m = scanner.nextInt();
        scanner.nextLine(); // consume the newline

        for (int i = 0; i < m; i++) {
            String buf = scanner.nextLine();
            for (char cur : buf.toCharArray()) {
                Q[i] |= (1 << (cur - 'a'));
            }
            have.add(Q[i]);
        }

        for (int i = 0; i < n; i++) {
            push(A[i]);
            int s = 0;
            for (int j = nn - 1; j >= 0; j--) {
                s |= (1 << stk[j]);
                if ((s & (1 << A[i + 1])) != 0) break;
                if (have.contains(s)) {
                    ans.put(s, ans.getOrDefault(s, 0) + 1);
                }
            }
        }

        for (int i = 0; i < m; i++) {
            System.out.println(ans.getOrDefault(Q[i], 0));
        }
    }
}
