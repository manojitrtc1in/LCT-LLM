import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String A = scanner.nextLine();
        int n = A.length();
        char[] arr = A.toCharArray();
        int Z = 26;
        int[] A = new int[n + 1];
        for (int i = 0; i < n; i++) {
            A[i] = arr[i] - 'a';
        }
        A[n] = Z;

        int m = scanner.nextInt();
        int[] Q = new int[m];
        Set<Integer> have = new HashSet<>();
        Map<Integer, Integer> ans = new HashMap<>();
        for (int i = 0; i < m; i++) {
            String buf = scanner.next();
            int cur = 0;
            for (char c : buf.toCharArray()) {
                cur |= (1 << (c - 'a'));
            }
            Q[i] = cur;
            have.add(cur);
        }

        int[] stk = new int[Z];
        int nn = 0;
        boolean[] vis = new boolean[Z];
        for (int i = 0; i < n; i++) {
            int x = A[i];
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
        }

        for (int i = 0; i < n; i++) {
            push(A[i]);
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
            System.out.println(ans.get(Q[i]));
        }
    }

    static void push(int x) {
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
    }
}
