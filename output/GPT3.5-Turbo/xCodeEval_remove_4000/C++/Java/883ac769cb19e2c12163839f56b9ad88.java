import java.util.*;

class Main {
    static final int nax = 5 * 100000 + 44;
    static int[] cou = new int[nax];
    static int[] prev = new int[nax];
    static int[] less = new int[nax];

    static int sum(int l, int r) {
        assert l < nax && r < nax;
        return less[r] - less[l];
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        for (int i = 0; i < n; ++i) {
            int x = sc.nextInt();
            cou[x]++;
        }
        for (int i = 1; i < nax; ++i) less[i] = less[i - 1] + cou[i - 1];
        int p = 0;
        for (int i = 0; i < nax; ++i) {
            prev[i] = p;
            if (cou[i] != 0) p = i;
        }
        long ans = 0;
        for (int y = 2; y < nax; ++y) {
            int low = 2, high = nax - 1;
            long all = 0;
            for (int i = 1; i * y < nax; ++i)
                all += i * 1L * sum(i * y, Math.min(nax - 1, i * y + y));
            if (all == 0) continue;
            while (low <= high) {
                int x = (low + high) / 2;
                boolean can_get = false;
                if (x % y == 0) {
                    can_get = (sum(x, nax - 1) >= 2 || sum(Math.min(nax - 1, 2 * x), nax - 1) >= 1) && (all - 2 * (x / y) >= x);
                } else {
                    long best = -1;
                    if (sum(x, nax - 1) >= 2) {
                        int save = 0;
                        int small_loss = x / y;
                        assert x > 0;
                        for (int i = 0; i < nax; i += y) {
                            int top = Math.min(nax - 1, i + y);
                            int g = prev[top];
                            if (g != 0 && g >= Math.max(i, x) && g % y >= x % y) {
                                if (cou[g] >= 2) save += 2;
                                else {
                                    save++;
                                    int gg = prev[g];
                                    if (gg >= Math.max(i, x) && gg % y >= x % y && gg != 0) {
                                        save++;
                                    }
                                }
                            }
                        }
                        best = Math.max(best, all - small_loss * 2 - Math.max(0, 2 - save));
                    }
                    if (2 * x < nax && sum(2 * x, nax - 1) >= 1) {
                        int waste = nax;
                        for (int i = 0; i < nax; i += y) {
                            int top = Math.min(nax - 1, i + y);
                            int g = prev[top];
                            if (g >= 2 * x)
                                waste = Math.min(waste, g / y - (g - 2 * x) / y);
                        }
                        best = Math.max(best, all - waste);
                    }
                    if (best >= x)
                        can_get = true;
                }
                if (can_get) {
                    ans = Math.max(ans, x * 1L * y);
                    low = x + 1;
                } else
                    high = x - 1;
            }
        }
        System.out.println(ans);
    }
}
