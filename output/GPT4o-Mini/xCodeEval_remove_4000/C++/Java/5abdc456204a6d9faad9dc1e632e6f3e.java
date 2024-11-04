import java.util.*;

public class 5abdc456204a6d9faad9dc1e632e6f3excodeeval_processed_4000.json {
    static final int MOD = (int) 1e9 + 7;
    static int n;
    static int[][] board = new int[4][4];
    static Map<Integer, Integer> cou = new HashMap<>();
    static int sum = 0;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        List<Integer> nums = new ArrayList<>();

        for (int i = 0; i < n * n; i++) {
            int x = scanner.nextInt();
            cou.put(x, cou.getOrDefault(x, 0) + 1);
            sum += x;
            nums.add(x);
        }

        assert sum % n == 0;
        sum /= n;
        System.out.println(sum);

        if (n <= 3) {
            Collections.sort(nums);
            do {
                boolean good = true;
                for (int i = 0; i < n; i++) {
                    int s1 = 0, s2 = 0;
                    for (int j = 0; j < n; j++) {
                        s1 += nums.get(i * n + j);
                        s2 += nums.get(j * n + i);
                    }
                    if (s1 != sum || s2 != sum) {
                        good = false;
                    }
                }
                int s1 = 0, s2 = 0;
                for (int i = 0; i < n; i++) {
                    s1 += nums.get(i * n + i);
                    s2 += nums.get(i * n + n - i - 1);
                }
                if (s1 != sum || s2 != sum) {
                    good = false;
                }
                if (good) {
                    for (int i = 0; i < n * n; i++) {
                        System.out.print(nums.get(i) + (i % n == n - 1 ? "\n" : " "));
                    }
                    return;
                }
            } while (nextPermutation(nums));
        }
        backtrack(0, 0);
    }

    static void backtrack(int i, int j) {
        if (i == n && j == 0) {
            for (int x = 0; x < n; x++) {
                for (int y = 0; y < n; y++) {
                    System.out.printf("%2d%c", board[x][y], y == n - 1 ? '\n' : ' ');
                }
            }
            System.exit(0);
        }
        if (j == 3) {
            int s = sum;
            for (int x = 0; x < 3; x++) {
                s -= board[i][x];
            }
            if (i == 0 && s < board[0][0]) return;
            go(s, i, j);
            return;
        }
        if (i == 3) {
            int s = sum;
            for (int x = 0; x < 3; x++) {
                s -= board[x][j];
            }
            go(s, i, j);
            return;
        }
        if (i == 2 && j == 1) {
            int v = board[0][0] + board[1][0] + board[2][0] - board[1][2] - board[0][3];
            if (v >= board[0][0]) go(v, i, j);
            return;
        }
        if (i == 2 && j == 2) {
            int o = board[0][3] + board[1][3] + sum - board[2][0] - board[2][1] - board[0][0] - board[1][1];
            if (o % 2 == 0 && o / 2 >= board[0][0]) go(o / 2, i, j);
            return;
        }
        int limit = Integer.MIN_VALUE;
        if ((i == 0 && j == 2) || ((i == 1 || i == 2) && (j == 0))) {
            limit = board[0][1];
        } else if ((i == j || i + j == 3) && (i != 0 || j != 0)) {
            limit = board[0][0];
        }
        for (Map.Entry<Integer, Integer> x : cou.entrySet()) {
            if (x.getKey() >= limit) {
                go(x.getKey(), i, j);
            }
        }
    }

    static void go(int num, int i, int j) {
        if (!cou.containsKey(num) || cou.get(num) == 0) return;
        cou.put(num, cou.get(num) - 1);
        board[i][j] = num;
        if (j == 3) {
            backtrack(i + 1, 0);
        } else {
            backtrack(i, j + 1);
        }
        cou.put(num, cou.get(num) + 1);
    }

    static boolean nextPermutation(List<Integer> nums) {
        int n = nums.size();
        int i = n - 2;
        while (i >= 0 && nums.get(i) >= nums.get(i + 1)) {
            i--;
        }
        if (i < 0) {
            Collections.reverse(nums);
            return false;
        }
        int j = n - 1;
        while (nums.get(j) <= nums.get(i)) {
            j--;
        }
        Collections.swap(nums, i, j);
        Collections.reverse(nums.subList(i + 1, n));
        return true;
    }
}
