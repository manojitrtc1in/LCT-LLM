import java.util.*;

class Main {
    static final int mdlo = 1000000007;
    static long[] mInv = new long[41];
    static long[] fact = new long[41];
    static long[] factInv = new long[41];
    static long N, M;
    static int[] levels = new int[15];
    static int[] nextPoint = new int[15];
    static int[] firstDigit = new int[15];
    static boolean[] inTree = new boolean[123466];
    static boolean[] visited = new boolean[123466];

    static class Edge {
        int first, second;

        Edge(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }

    static List<Integer>[] tree = new List[123466];
    static List<Integer> startPoints = new ArrayList<>();

    static List<Integer>[] graph = new List[15];
    static long[] par = new long[45];

    static long getAncestor(long val) {
        if (par[(int) val] != val)
            par[(int) val] = getAncestor(par[(int) val]);
        return par[(int) val];
    }

    static boolean unify(long a, long b) {
        long para = getAncestor(a), parb = getAncestor(b);
        if (para == parb)
            return false;
        if (para < parb)
            par[(int) parb] = para;
        else
            par[(int) para] = parb;
        return true;
    }

    static List<Long> primes = new ArrayList<>();

    static List<Long> id1(long max) {
        boolean[] sieve = new boolean[(int) (max / 8) + 1];

        int m = (int) (max / 8) + 1;
        for (int i = 0; i < m; i++)
            sieve[i] = true;

        for (long x = 2; x <= max; x++) {
            if (sieve[(int) (x / 8)] && (1 << (x % 8) & sieve[(int) (x / 8)]) != 0) {
                primes.add(x);

                for (long j = 2 * x; j <= max; j += x)
                    sieve[(int) (j / 8)] &= ~(1 << (j % 8));
            }
        }

        return primes;
    }

    static long[][] dp = new long[22][22];

    static long getdp(long N, long K) {
        if (dp[(int) N][(int) K] == 0) {
            if (K == 1) {
                dp[(int) N][(int) K] = N;
                return dp[(int) N][(int) K];
            }
            long v1 = getdp(N, K - 1), v2 = getdp(N - 1, K - 1);
            dp[(int) N][(int) K] = (v1 * v2) / (v1 - v2);
        }
        return dp[(int) N][(int) K];
    }

    static boolean isPrime(long N) {
        if (N == 1)
            return false;
        if (N < 4)
            return true;
        for (long i = 2; i * i < N; i++) {
            if (N % i == 0)
                return false;
        }
        return true;
    }

    static long gcd(long a, long b) {
        long c;
        if (a > b) {
            c = a;
            a = b;
            b = c;
        }
        if (a == 0)
            return b;
        c = b % a;
        while (c > 0) {
            b = a;
            a = c;
            c = b % a;
        }
        return a;
    }

    static long id5(long a, long b) {
        long c = a / gcd(a, b);
        return b * c;
    }

    static class TreeInfo {
        long depth;
        long id6;
        long startPointOfLongestPath;
        long id3;
        boolean included;

        TreeInfo(long depth, long id6, long startPointOfLongestPath, long id3, boolean included) {
            this.depth = depth;
            this.id6 = id6;
            this.startPointOfLongestPath = startPointOfLongestPath;
            this.id3 = id3;
            this.included = included;
        }
    }

    static TreeInfo dfs(int startPoint) {
        TreeInfo tInfo = new TreeInfo(0, 0, 0, 0, false);
        int maxDepth = 0, id7 = 0, id3 = 1234567, id9 = 1234567, id6 = 0, id10 = 1234567;
        boolean status = inTree[startPoint];
        visited[startPoint] = true;
        for (int i = 0; i < tree[startPoint].size(); i++) {
            if (!visited[tree[startPoint].get(i)]) {
                TreeInfo childInfo = dfs(tree[startPoint].get(i));
                if (childInfo.included) {
                    status = true;
                    if (maxDepth < childInfo.depth || (maxDepth == childInfo.depth && id3 > childInfo.id3)) {
                        id7 = maxDepth;
                        id9 = id3;
                        id3 = childInfo.id3;
                        maxDepth = childInfo.depth;
                    } else if (id7 < childInfo.depth || (id7 == childInfo.depth && id9 > childInfo.id3)) {
                        id7 = childInfo.depth;
                        id9 = childInfo.id3;
                    }
                    if (childInfo.id6 > id6 || (childInfo.id6 == id6 && id10 < childInfo.startPointOfLongestPath)) {
                        id6 = childInfo.id6;
                        id10 = childInfo.startPointOfLongestPath;
                    }
                }
            }
        }
        tInfo.included = status;
        if (maxDepth == 0) {
            tInfo.id3 = startPoint;
            tInfo.depth = 1;
            tInfo.id6 = 1;
            tInfo.startPointOfLongestPath = startPoint;
            return tInfo;
        }
        if (maxDepth + id7 + 1 > id6 || (maxDepth + id7 + 1 == id6 && id10 > Math.min(id3, id9))) {
            id10 = Math.min(id3, id9);
            id6 = maxDepth + id7 + 1;
        }
        if (id7 == maxDepth && id9 < id3)
            id3 = id9;
        tInfo.id3 = id3;
        tInfo.depth = maxDepth + 1;
        tInfo.id6 = id6;
        tInfo.startPointOfLongestPath = id10;
        inTree[startPoint] = status;
        return tInfo;
    }

    static long getVal(long num) {
        long ans = 1;
        for (long i = 1; i < num; i++)
            ans += (num / gcd(num, i));
        return ans;
    }

    static void buildDp() {
        for (int i = 1; i < 22; i++) {
            for (int j = 1; j <= i; j++) {
                dp[i][j] = getdp(i, j);
                System.out.print(dp[i][j] + " ");
            }
            System.out.println();
        }
    }

    static double[] angle = new double[345768];

    static double maxDist(double t, double v, double r) {
        double dist = t * v;
        double C = t * v / r;
        double id0 = Math.cos((Math.PI + C) / 2) - Math.cos((Math.PI - C) / 2),
                id8 = Math.cos((3 * Math.PI + C) / 2) - Math.cos((3 * Math.PI - C) / 2);
        return dist + r * Math.max(id0, id8);
    }

    static void id2(double C) {
        double maxVal = -1, maxAngle = 0, minVal = 1, minAngle = 0;
        for (double th = 0.00; th < 360.1; th += 0.01) {
            double angle = ((th + C) * Math.PI) / 180.0;
            double val = Math.cos(angle) - Math.cos((th * Math.PI) / 180.0);
            if (val > maxVal) {
                maxVal = val;
                maxAngle = th;
            }
            if (val < minVal) {
                minVal = val;
                minAngle = th;
            }
        }
        System.out.println("max " + maxVal + " angle " + maxAngle);
        System.out.println("min " + minVal + " angle " + minAngle);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        long test_cases = 1, C, D, A, L, R, rep, round = 0, rem, ans = 0, num;
        double st, en, minerr = 0.00000001, r, v;
        test_cases = sc.nextLong();
        r = sc.nextDouble();
        v = sc.nextDouble();

        for (int T = 0; T < test_cases; T++) {
            st = sc.nextDouble();
            en = sc.nextDouble();
            double dist = en - st;
            double low = (dist - 2 * r) / v, high = (dist + 2 * r) / v, mid;
            while (low + minerr < high && low + low * minerr < high) {
                mid = (low + high) / 2;
                if (maxDist(mid, v, r) > dist)
                    high = mid;
                else
                    low = mid;
            }
            System.out.printf("%.15f\n", (low + high) / 2);
        }
    }
}
