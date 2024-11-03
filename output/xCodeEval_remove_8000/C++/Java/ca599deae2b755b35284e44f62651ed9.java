import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] m = new int[n];
        for (int i = 0; i < n; i++) {
            m[i] = scanner.nextInt();
        }
        int[][] rev = new int[n][];
        int[] deps = new int[n];
        for (int i = 0; i < n; i++) {
            int k = scanner.nextInt();
            rev[i] = new int[k];
            for (int j = 0; j < k; j++) {
                int x = scanner.nextInt();
                rev[i][j] = x - 1;
                deps[x - 1]++;
            }
        }
        int[][] load = new int[3][];
        for (int i = 0; i < 3; i++) {
            load[i] = new int[n];
        }
        int[] count = new int[3];
        for (int i = 0; i < n; i++) {
            if (deps[i] == 0) {
                load[m[i]][count[m[i]]++] = i;
            }
        }
        int ans = Integer.MAX_VALUE;
        for (int i = 0; i < 3; i++) {
            int cur = 0;
            int[] depsCopy = deps.clone();
            int[][] loadCopy = new int[3][];
            for (int j = 0; j < 3; j++) {
                loadCopy[j] = load[j].clone();
            }
            while (true) {
                boolean done = true;
                for (int j = 0; j < count[i]; j++) {
                    int node = loadCopy[i][j];
                    if (depsCopy[node] == 0) {
                        done = false;
                        for (int k : rev[node]) {
                            depsCopy[k]--;
                            if (depsCopy[k] == 0) {
                                loadCopy[m[k]][count[m[k]]++] = k;
                            }
                        }
                    }
                }
                if (done) {
                    break;
                }
                cur++;
            }
            ans = Math.min(ans, cur);
        }
        System.out.println(ans + n);
    }
}
