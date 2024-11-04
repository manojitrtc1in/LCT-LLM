import java.util.ArrayList;
import java.util.List;

public class 2255cdb417ed15c8fbb210c25f068664_nc {
    static boolean[] p = new boolean[20000];
    static List<Integer> pp = new ArrayList<>();

    public static void main(String[] args) {
        for (int i = 2; i < 20000; ++i) {
            if (p[i]) {
                pp.add(i);
                int j = i + i;
                while (j < 20000) {
                    p[j] = false;
                    j += i;
                }
            }
        }

        int l = 0, r = 0;
        int ans = 0, cl = 0, ul = 0;
        // Read l and r from input
        // ...

        while (l > cl) {
            ++ul;
            cl += len;
        }
        if (cl <= r) {
            ans += get(l, cl-1);
        } else {
            ans += get(l, r);
        }
        while (cl+len-1 <= r) {
            ans += pr[ul];
            cl += len;
            ++ul;
        }

        ans += get(cl, r);

        System.out.println(ans);
    }

    static int get(int l, int r) {
        int ans = 0;
        for (int i = l; i <= r; ++i) {
            boolean flag = true;
            for (int j = 0; j < pp.size() && pp.get(j) * pp.get(j) <= i; ++j) {
                if (i % pp.get(j) == 0) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                boolean f2 = false;
                for (int f = 1; f * f + f * f <= i; ++f) {
                    int s = (int) Math.sqrt(i - f * f);
                    if (s * s + f * f == i || (s + 1) * (s + 1) + f * f == i) {
                        f2 = true;
                        break;
                    }
                }
                if (f2) {
                    ++ans;
                }
            }
        }
        return ans;
    }
}
