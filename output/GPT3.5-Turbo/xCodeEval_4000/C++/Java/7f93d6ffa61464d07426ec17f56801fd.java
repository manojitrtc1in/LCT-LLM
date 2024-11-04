import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class 7f93d6ffa61464d07426ec17f56801fd_nc {
    static final int MAX = 1000000;
    static final int[] pr = {2, 3, 5, 7, 11, 13, 17, 19};
    static final int[][] num = {{0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5}, {0, 6}, {1, 0}, {1, 1}, {1, 2}, {1, 3}, {1, 4}, {1, 5}, {1, 6}, {1, 7}, {2, 0}, {2, 1}, {2, 2}, {2, 3}, {2, 4}, {2, 5}, {2, 6}, {2, 7}, {3, 0}, {3, 1}, {3, 2}, {3, 3}, {3, 4}, {3, 5}, {3, 6}, {3, 7}, {4, 0}, {4, 1}, {4, 2}, {4, 3}, {4, 4}, {4, 5}, {4, 6}, {4, 7}, {5, 0}, {5, 1}, {5, 2}, {5, 3}, {5, 4}, {5, 5}, {5, 6}, {5, 7}, {6, 0}, {6, 1}, {6, 2}, {6, 3}, {6, 4}, {6, 5}, {6, 6}, {6, 7}, {7, 0}, {7, 2}, {7, 3}, {7, 4}, {7, 5}, {7, 6}, {7, 7}, {7, 8}, {8, 1}, {8, 3}, {8, 4}, {8, 5}, {8, 6}, {8, 7}, {8, 8}, {8, 9}, {9, 3}, {9, 5}, {9, 6}, {9, 7}, {9, 8}, {9, 9}, {9, 10}, {10, 7}, {10, 8}, {10, 9}, {10, 10}};
    static List<List<Integer>> L = new ArrayList<>();
    static int[][] ans = new int[300][300];
    static int cnt = 0;
    static int[] mp = new int[MAX + 1];

    public static void main(String[] args) {
        init(0, MAX, 1 << 30, new ArrayList<>());
        Arrays.fill(mp, 0);
        for (int i = 2; i <= MAX; i++) {
            if (mp[i] == 0) {
                for (int j = i; j <= MAX; j += i) {
                    if (mp[j] == 0) {
                        mp[j] = i;
                    }
                }
            }
        }
        int i = 0, j = 1;
