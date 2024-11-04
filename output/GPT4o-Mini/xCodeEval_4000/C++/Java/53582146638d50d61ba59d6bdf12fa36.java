import java.util.*;
import java.io.*;

class ModInt {
    private int val;
    private static final int MOD = 998244353;

    public ModInt() {
        this.val = 0;
    }

    public ModInt(int val) {
        this.val = (val % MOD + MOD) % MOD;
    }

    public long value() {
        return val;
    }

    public ModInt add(ModInt rhs) {
        return new ModInt((this.val + rhs.val) % MOD);
    }

    public ModInt subtract(ModInt rhs) {
        return new ModInt((this.val - rhs.val + MOD) % MOD);
    }

    public ModInt multiply(ModInt rhs) {
        return new ModInt((long) this.val * rhs.val % MOD);
    }

    public static ModInt inverse(ModInt rhs) {
        assert rhs.val != 0;
        int a = MOD, b = rhs.val, u = 0, v = 1;
        while (b != 0) {
            int t = a / b;
            a -= t * b;
            int temp = u;
            u -= t * v;
            v = temp;
            int temp2 = a;
            a = b;
            b = temp2;
        }
        return new ModInt(u);
    }
}

public class 53582146638d50d61ba59d6bdf12fa36_nc {
    private int n;
    private List<List<Integer>> tree;
    private List<List<ModInt>> dp;

    public Solver() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        tree = new ArrayList<>(n);
        dp = new ArrayList<>(n);
        for (int i = 0; i < n; i++) {
            tree.add(new ArrayList<>());
            dp.add(new ArrayList<>(Arrays.asList(new ModInt(), new ModInt(), new ModInt())));
        }

        for (int i = 1; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken()) - 1;
            int b = Integer.parseInt(st.nextToken()) - 1;
            tree.get(a).add(b);
            tree.get(b).add(a);
        }

        treedp(0, -1);
        List<ModInt> rdp = dp.get(0);
        System.out.println(rdp.get(0).add(rdp.get(2)).value());
    }

    private boolean isLeaf(int v) {
        return tree.get(v).size() == 1;
    }

    private void treedp(int now, int pre) {
        List<ModInt> ndp = dp.get(now);
        ndp.set(2, new ModInt(1));
        for (int to : tree.get(now)) {
            if (to == pre) continue;
            List<ModInt> tmp = new ArrayList<>(Arrays.asList(new ModInt(), new ModInt(), new ModInt()));
            treedp(to, now);
            List<ModInt> tdp = dp.get(to);

            for (int i = 0; i < 3; i++) {
                tmp.set(i, tdp.get(2).multiply(ndp.get(i)));
            }

            tmp.set(0, tmp.get(0).add(ndp.get(2).multiply(tdp.get(2))).add(ndp.get(1).multiply(tdp.get(2))));
            tmp.set(0, tmp.get(0).add((ndp.get(1).add(ndp.get(2))).multiply(tdp.get(1))));
            tmp.set(0, tmp.get(0).add(new ModInt(2).multiply(ndp.get(0).multiply(tdp.get(0)))));
            tmp.set(1, tmp.get(1).add((ndp.get(1).multiply(new ModInt(2))).add(ndp.get(2)).multiply(tdp.get(0))));
            tmp.set(2, tmp.get(2).add(ndp.get(2).multiply(tdp.get(0))));

            dp.set(now, tmp);
        }
    }

    public static void main(String[] args) throws IOException {
        new Solver();
    }
}
