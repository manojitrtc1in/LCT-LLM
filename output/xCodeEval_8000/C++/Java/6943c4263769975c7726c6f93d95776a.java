import java.util.*;

public class 6943c4263769975c7726c6f93d95776a_nc {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int l = sc.nextInt();
        int r = sc.nextInt();
        int ret = 0;
        int B = 100 * 1000;
        int MN = 3 * 100000000 + 10;
        BitSet is = new BitSet(MN);
        
        for (int d = 1; d * d < MN; ++d) {
            is.set(d * d);
        }
        
        if (l / B == r / B) {
            for (int i = l; i <= r; ++i) {
                if (check(i, is)) {
                    ret++;
                }
            }
            System.out.println(ret);
            return;
        }
        
        int pl = l / B;
        int pr = r / B;
        
        for (int i = pl + 1; i < pr; ++i) {
            ret += prec[i];
        }
        
        for (int i = l; i / B == pl; ++i) {
            if (check(i, is)) {
                ret++;
            }
        }
        
        for (int i = r; i / B == pr; --i) {
            if (check(i, is)) {
                ret++;
            }
        }
        
        System.out.println(ret);
    }
    
    public static boolean check(int x, BitSet is) {
        if (x == 2) {
            return true;
        }
        
        if (x % 4 != 1) {
            return false;
        }
        
        boolean F = false;
        for (int d = 2; d * d <= x; ++d) {
            if (x % d == 0) {
                return false;
            }
            
            if (d * d != x && is.get(x - d * d)) {
                F = true;
            }
        }
        
        return F;
    }
    
