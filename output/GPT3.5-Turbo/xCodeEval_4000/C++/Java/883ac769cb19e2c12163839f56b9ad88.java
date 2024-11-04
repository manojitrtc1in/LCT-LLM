import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] cou = new int[500044];
        int[] prev = new int[500044];
        int[] less = new int[500044];
        
        for (int i = 0; i < n; ++i) {
            int x = scanner.nextInt();
            cou[x]++;
        }
        
        for (int i = 1; i < 500044; ++i) {
            less[i] = less[i - 1] + cou[i - 1];
        }
        
        int p = 0;
        for (int i = 0; i < 500044; ++i) {
            prev[i] = p;
            if (cou[i] != 0) {
                p = i;
            }
        }
        
        long ans = 0;
        for (int y = 2; y < 500044; ++y) {
            int low = 2, high = 500044 - 1;
            long all = 0;
            for (int i = 1; i * y < 500044; ++i) {
                all += i * 1L * sum(i * y, Math.min(500044 - 1, i * y + y), less);
            }
            
            if (all == 0) {
                continue;
            }
            
            while (low <= high) {
                int x = (low + high) / 2;
                boolean can_get = false;
                
                if (x % y == 0) {
                    can_get = (sum(x, 500044 - 1, less) >= 2 || sum(Math.min(500044 - 1, 2 * x), 500044 - 1, less) >= 1) && (all - 2 * (x / y) >= x);
                } else {
                    long best = -1;
                    
                    if (sum(x, 500044 - 1, less) >= 2) {
                        int save = 0;
                        int small_loss = x / y;
                        
                        for (int i = 0; i < 500044; i += y) {
                            int top = Math.min(500044 - 1, i + y);
                            int g = prev[top];
                            
                            if (g != 0 && g >= Math.max(i, x) && g % y >= x % y) {
                                if (cou[g] >= 2) {
                                    save += 2;
                                } else {
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
                    
                    if (2 * x < 500044 && sum(2 * x, 500044 - 1, less) >= 1) {
                        int waste = 500044;
                        
                        for (int i = 0; i < 500044; i += y) {
                            int top = Math.min(500044 - 1, i + y);
                            int g = prev[top];
                            
                            if (g >= 2 * x) {
                                waste = Math.min(waste, g / y - (g - 2 * x) / y);
                            }
                        }
                        
                        best = Math.max(best, all - waste);
                    }
                    
                    if (best >= x) {
                        can_get = true;
                    }
                }
                
                if (can_get) {
                    ans = Math.max(ans, x * 1L * y);
                    low = x + 1;
                } else {
                    high = x - 1;
                }
            }
        }
        
        System.out.println(ans);
    }
    
    private static int sum(int l, int r, int[] less) {
        return less[r] - less[l];
    }
}
