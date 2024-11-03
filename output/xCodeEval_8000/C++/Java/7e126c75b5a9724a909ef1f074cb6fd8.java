import java.util.*;

public class 7e126c75b5a9724a909ef1f074cb6fd8_nc {
    static final int N1 = 100000;
    static final int B = 100000;
    static final int N = 300000000;

    static List<Integer> lp = new ArrayList<>(Collections.nCopies(N1 + 1, 0));
    static List<Integer> prime = new ArrayList<>();

    public static void seive() {
        for (int i = 2; i <= N1; ++i) {
            if (lp.get(i) == 0) {
                lp.set(i, i);
                prime.add(i);
            }
            for (int j : prime) {
                if (j > lp.get(i) || i * j > N1) break;
                lp.set(i * j, j);
            }
        }
    }

    public static int calsum(int l, int r) {
        if (l > r) return 0;
        if (l == 0) return csum.get(r);
        return csum.get(r) - csum.get(l - 1);
    }

    public static int inrange(int l, int r) {
        boolean[] isp = new boolean[r - l + 1];
        Arrays.fill(isp, true);
        for (int i : prime) {
            if (i * i > r) break;
            int st = (l / i) * i;
            if (st < l) st += i;
            if (st == i) st += i;
            for (int cur = st; cur <= r; cur += i) {
                isp[cur - l] = false;
            }
        }
        int ans = 0;
        for (int i = 0, j = l; j <= r; ++i, ++j) {
            if (isp[i] && j % 4 == 1) ++ans;
        }
        if (2 >= l && 2 <= r) ++ans;
        return ans;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        seive();
