import java.util.*;

class Main {
    static Map<Integer, Integer> cou;
    static int sum;
    static int n;
    static int[][] board;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        cou = new HashMap<>();
        sum = 0;
        board = new int[4][4];

        for (int i = 0; i < n * n; i++) {
            int x = sc.nextInt();
            cou.put(x, cou.getOrDefault(x, 0) + 1);
            sum += x;
        }

        assert sum % n == 0;
        sum /= n;
        System.out.println(sum);

        if (n <= 3) {
            List<Integer> nums = new ArrayList<>(cou.keySet());
            Collections.sort(nums);
            do {
                boolean good = true;
                for (int i = 0; i < n; i++) {
                    int s1 = 0, s2 = 0;
                    for (int j = 0; j < n; j++) {
                        s1 += nums.get(i * n + j);
                        s2 += nums.get(j * n + i);
                    }
                    if (s1 != sum || s2 != sum)
                        good = false;
                }
                int s1 = 0, s2 = 0;
                for (int i = 0; i < n; i++) {
                    s1 += nums.get(i * n + i);
                    s2 += nums.get(i * n + n - i - 1);
                }
                if (s1 != sum || s2 != sum)
                    good = false;
                if (good) {
                    for (int i = 0; i < n * n; i++) {
                        System.out.print(nums.get(i) + " ");
                        if (i % n == n - 1)
                            System.out.println();
                    }
                    return;
                }
            } while (nextPermutation(nums));
        }

        backtrack(0, 0);
    }

    static boolean nextPermutation(List<Integer> nums) {
        int i = nums.size() - 2;
        while (i >= 0 && nums.get(i) >= nums.get(i + 1))
            i--;
        if (i < 0)
            return false;
        int j = nums.size() - 1;
        while (nums.get(j) <= nums.get(i))
            j--;
        swap(nums, i, j);
        reverse(nums, i + 1, nums.size() - 1);
        return true;
    }

    static void swap(List<Integer> nums, int i, int j) {
        int temp = nums.get(i);
        nums.set(i, nums.get(j));
        nums.set(j, temp);
    }

    static void reverse(List<Integer> nums, int start, int end) {
        while (start < end) {
            swap(nums, start, end);
            start++;
            end--;
        }
    }

    static void backtrack(int i, int j) {
        if (i == 3 && j == 0) {
            for (int x = 0; x < n; x++) {
                for (int y = 0; y < n; y++) {
                    System.out.print(board[x][y] + " ");
                }
                System.out.println();
            }
            return;
        }
        if (j == 3) {
            int s = sum;
            for (int x = 0; x < 3; x++)
                s -= board[i][x];
            go(s, i, j);
            return;
        }
        if (i == 3) {
            assert false;
            int s = sum;
            for (int x = 0; x < 3; x++)
                s -= board[x][j];
            go(s, i, j);
            return;
        }
        if (i == 2 && j == 1) {
            go(board[0][0] + board[1][0] + board[2][0] - board[1][2] - board[0][3], i, j);
            return;
        }
        if (i == 2 && j == 2) {
            int o = board[0][3] + board[1][3] + sum - board[2][0] - board[2][1] - board[0][0] - board[1][1];
            if (o % 2 == 0)
                go(o / 2, i, j);
            return;
        }
        if (i == 1 && j == 0) {
            for (Map.Entry<Integer, Integer> entry : cou.entrySet()) {
                int x = entry.getKey();
                if (x > board[0][1])
                    break;
                go(x, i, j);
            }
            return;
        }
        for (Map.Entry<Integer, Integer> entry : cou.entrySet())
            go(entry.getKey(), i, j);
    }

    static void go(int num, int i, int j) {
        if (!cou.containsKey(num) || cou.get(num) == 0)
            return;
        int under = -1;
        if (i == 2) {
            under = sum - board[0][j] - board[1][j] - num;
            if (under == num) {
                if (cou.get(num) < 2)
                    return;
                cou.put(num, cou.get(num) - 1);
            } else {
                if (!cou.containsKey(under) || cou.get(under) == 0)
                    return;
                cou.put(under, cou.get(under) - 1);
            }
            board[3][j] = under;
        }
        cou.put(num, cou.get(num) - 1);
        board[i][j] = num;
        if (j == 3)
            backtrack(i + 1, 0);
        else
            backtrack(i, j + 1);
        cou.put(num, cou.get(num) + 1);
        if (i == 2) {
            assert cou.containsKey(under);
            cou.put(under, cou.get(under) + 1);
        }
    }
}
