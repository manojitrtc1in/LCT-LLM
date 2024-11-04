import java.util.*;

public class 6943c4263769975c7726c6f93d95776axcodeeval_processed_4000.json {
    static final int B = 100 * 1000;
    static final int MN = 3 * 1000 * 1000 + 10;

    static boolean[] is = new boolean[MN];

    static boolean check(int x) {
        if (x == 2) return true;
        if (x % 4 != 1) return false;

        boolean F = false;
        for (int d = 2; d * d <= x; ++d) {
            if (x % d == 0) return false;
            if (d * d != x && is[x - d * d]) F = true;
        }
        return F;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int l = sc.nextInt();
        int r = sc.nextInt();
        int ret = 0;
        int pl = l / B;
        int pr = r / B;
        for (int d = 1; d * d < MN; ++d)
            is[d * d] = true;

        if (l / B == r / B) {
            for (int i = l; i <= r; ++i)
                ret += check(i);
            System.out.println(ret);
            return;
        }
        for (int i = pl + 1; i < pr; ++i)
            ret += prec[i];
        for (int i = l; i / B == pl; ++i) ret += check(i);
        for (int i = r; i / B == pr; --i) ret += check(i);
        System.out.println(ret);
    }
}
