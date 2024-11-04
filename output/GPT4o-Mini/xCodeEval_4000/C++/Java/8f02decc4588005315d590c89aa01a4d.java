import java.util.*;

public class 8f02decc4588005315d590c89aa01a4d_nc {
    static final int MOD = (int) 1e9 + 7;
    static int sum = 0;
    static int n;
    static int[][] board = new int[4][4];
    static Map<Integer, Integer> cou = new HashMap<>();

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

        if (sum % n != 0) {
            throw new AssertionError();
        }
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
        if (i == 3 && j == 0) {
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
            go(s, i, j);
            return;
        }
        if (i == 3) {
            throw new AssertionError();
        }
        if (i == 2 && j == 1) {
            go(board[0][0] + board[1][0] + board[2][0] - board[1][2] - board[0][3], i, j);
            return;
        }
        if (i == 2 && j == 2) {
            int o = board[0][3] + board[1][3] + sum - board[2][0] - board[2][1] - board[0][0] - board[1][1];
            if (o % 2 == 0) {
                go(o / 2, i, j);
            }
            return;
        }
        if (i == 1 && j == 0) {
            for (Map.Entry<Integer, Integer> x : cou.entrySet()) {
                if (x.getKey() > board[0][1]) {
                    break;
                }
                go(x.getKey(), i, j);
            }
            return;
        }
        for (Map.Entry<Integer, Integer> x : cou.entrySet()) {
            go(x.getKey(), i, j);
        }
    }

    static void go(int num, int i, int j) {
        Map.Entry<Integer, Integer> it = cou.entrySet().stream()
                .filter(entry -> entry.getKey().equals(num))
                .findFirst()
                .orElse(null);
        if (it == null || it.getValue() == 0) return;

        int under = -1;
        if (i == 2) {
            under = sum - board[0][j] - board[1][j] - num;
            if (under == num) {
                if (it.getValue() < 2) return;
                it.setValue(it.getValue() - 1);
            } else {
                Map.Entry<Integer, Integer> itUnder = cou.entrySet().stream()
                        .filter(entry -> entry.getKey().equals(under))
                        .findFirst()
                        .orElse(null);
                if (itUnder == null || itUnder.getValue() == 0) return;
                itUnder.setValue(itUnder.getValue() - 1);
            }
            board[3][j] = under;
        }
        it.setValue(it.getValue() - 1);
        board[i][j] = num;
        if (j == 3) {
            backtrack(i + 1, 0);
        } else {
            backtrack(i, j + 1);
        }
        it.setValue(it.getValue() + 1);
        if (i == 2) {
            cou.put(under, cou.get(under) + 1);
        }
    }

    static boolean nextPermutation(List<Integer> nums) {
        int n = nums.size();
        int i = n - 1;
        while (i > 0 && nums.get(i - 1) >= nums.get(i)) {
            i--;
        }
        if (i <= 0) return false;

        int j = n - 1;
        while (nums.get(j) <= nums.get(i - 1)) {
            j--;
        }
        Collections.swap(nums, i - 1, j);
        Collections.reverse(nums.subList(i, n));
        return true;
    }
}
