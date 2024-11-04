import java.util.*;
import java.io.*;

class ModInt {
    private int val;
    private static final int MOD = 998244353;

    public ModInt() {
        this.val = 0;
    }

    public ModInt(int _val) {
        this.val = (_val % MOD + MOD) % MOD;
    }

    public long value() {
        return val;
    }

    public ModInt add(ModInt rhs) {
        return new ModInt((this.val + rhs.val) % MOD);
    }

    public ModInt multiply(ModInt rhs) {
        return new ModInt((long) this.val * rhs.val % MOD);
    }

    public static ModInt inverse(ModInt rhs) {
        assert rhs.val != 0;
        int a = MOD, b = rhs.val, u = 0, v = 1, t;
        while (b != 0) {
            t = a / b;
            a ^= b;
            b ^= (a -= t * b);
            b ^= b;
            u ^= v;
            v ^= (u -= t * v);
            v ^= v;
        }
        return new ModInt(u);
    }

    public static ModInt pow(ModInt rhs, long e) {
        if (e < 0) e = e % (MOD - 1) + MOD - 1;
        ModInt res = new ModInt(1);
        while (e > 0) {
            if ((e & 1) == 1) res = res.multiply(rhs);
            rhs = rhs.multiply(rhs);
            e >>= 1;
        }
        return res;
    }

    @Override
    public String toString() {
        return String.valueOf(val);
    }
}

class Solver {
    private int n;
    private List<List<Integer>> tree;
    private ModInt[][] dp;

    public Solver() {
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        tree = new ArrayList<>(n);
        dp = new ModInt[n][3];

        for (int i = 0; i < n; i++) {
            tree.add(new ArrayList<>());
            dp[i][0] = new ModInt();
            dp[i][1] = new ModInt();
            dp[i][2] = new ModInt();
        }

        for (int i = 1; i < n; i++) {
            int a = scanner.nextInt() - 1;
            int b = scanner.nextInt() - 1;
            tree.get(a).add(b);
            tree.get(b).add(a);
        }

        treeDp(0, -1);
        ModInt[] rdp = dp[0];
        System.out.println(rdp[0].add(rdp[2]));
    }

    private boolean isLeaf(int v) {
        return tree.get(v).size() == 1;
    }

    private void treeDp(int now, int pre) {
        dp[now][2] = new ModInt(1);
        for (int to : tree.get(now)) {
            if (to == pre) continue;
            ModInt[] tmp = new ModInt[3];
            treeDp(to, now);
            ModInt[] tdp = dp[to];

            for (int i = 0; i < 3; i++) {
                tmp[i] = tdp[2].multiply(dp[now][i]);
            }

            tmp[0] = tmp[0].add(dp[now][2].multiply(tdp[2])).add(dp[now][1].multiply(tdp[2]));
            tmp[0] = tmp[0].add((dp[now][1].add(dp[now][2])).multiply(tdp[1]));
            tmp[0] = tmp[0].add(new ModInt(2).multiply(dp[now][0]).multiply(tdp[0]));
            tmp[1] = tmp[1].add((dp[now][1].multiply(new ModInt(2)).add(dp[now][2])).multiply(tdp[0]));
            tmp[2] = tmp[2].add(tdp[0].multiply(dp[now][2]));

            dp[now] = tmp;
        }
    }

    public static void main(String[] args) {
        new Solver();
    }
}
