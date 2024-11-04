import java.util.*;

class Main {
    static HashMap<Integer, Integer> cou;
    static int sum;
    static int n;
    static int[][] board;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        cou = new HashMap<>();
        sum = 0;
        board = new int[4][4];

        for (int i = 0; i < n * n; i++) {
            int x = scanner.nextInt();
            cou.put(x, cou.getOrDefault(x, 0) + 1);
            sum += x;
        }

        assert sum % n == 0;
        sum /= n;
        System.out.println(sum);

        if (n <= 3) {
            ArrayList<Integer> nums = new ArrayList<>(cou.keySet());
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
                        break;
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
                        System.out.print(nums.get(i) + " ");
                        if ((i + 1) % n == 0) {
                            System.out.println();
                        }
                    }
                    return;
                }
            } while (nextPermutation(nums));
        }

        backtrack(0, 0);
    }

    static boolean nextPermutation(ArrayList<Integer> nums) {
        int i = nums.size() - 2;
        while (i >= 0 && nums.get(i) >= nums.get(i + 1)) {
            i--;
        }
        if (i < 0) {
            return false;
        }
        int j = nums.size() - 1;
        while (nums.get(j) <= nums.get(i)) {
            j--;
        }
        swap(nums, i, j);
        reverse(nums, i + 1, nums.size() - 1);
        return true;
    }

    static void swap(ArrayList<Integer> nums, int i, int j) {
        int temp = nums.get(i);
        nums.set(i, nums.get(j));
        nums.set(j, temp);
    }

    static void reverse(ArrayList<Integer> nums, int start, int end) {
        while (start < end) {
            swap(nums, start, end);
            start++;
            end--;
        }
    }

    static void go(int num, int i, int j) {
        if (!cou.containsKey(num) || cou.get(num) == 0) {
            return;
        }
        cou.put(num, cou.get(num) - 1);
        board[i][j] = num;
        if (j == 3) {
            int s = sum;
            for (int x = 0; x < 3; x++) {
                s -= board[i][x];
            }
            if (i == 0 && s < board[0][0]) {
                return;
            }
            backtrack(i + 1, 0);
        } else {
            int s = sum;
            for (int x = 0; x < 3; x++) {
                s -= board[x][j];
            }
            go(s, i, j + 1);
        }
        cou.put(num, cou.get(num) + 1);
    }

    static void backtrack(int i, int j) {
        if (i == n && j == 0) {
            for (int x = 0; x < n; x++) {
                for (int y = 0; y < n; y++) {
                    System.out.print(board[x][y] + " ");
                }
                System.out.println();
            }
            System.exit(0);
        }
        if (j == 3) {
            int s = sum;
            for (int x = 0; x < 3; x++) {
                s -= board[i][x];
            }
            if (i == 0 && s < board[0][0]) {
                return;
            }
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
            if (v >= board[0][0]) {
                go(v, i, j);
            }
            return;
        }
        if (i == 2 && j == 2) {
            int o = board[0][3] + board[1][3] + sum - board[2][0] - board[2][1] - board[0][0] - board[1][1];
            if (o % 2 == 0 && o / 2 >= board[0][0]) {
                go(o / 2, i, j);
            }
            return;
        }
        int limit = -1e9;
        if ((i == 0 && j == 2) || ((i == 1 || i == 2) && (j == 0))) {
            limit = board[0][1];
        } else if ((i == j || i + j == 3) && (i != 0 || j != 0)) {
            limit = board[0][0];
        }
        for (int x : cou.keySet()) {
            if (x >= limit) {
                go(x, i, j);
            }
        }
    }
}
