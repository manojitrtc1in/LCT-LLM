import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class c586892ba128e8135a0cd7cd2985e86d_nc {
    static final double PI = 3.1415926535897932384626433832795;
    static final int MAX_BITS = 40;
    static final int MDLO = 1000000007;
    static final double MAX_ERR = 0.00000064;

    static long[] mInv = new long[41];
    static long[] fact = new long[41];
    static long[] factInv = new long[41];
    static long N, M;

    static class Edge {
        long first;
        long second;

        public Edge(long first, long second) {
            this.first = first;
            this.second = second;
        }
    }

    static class TreeInfo {
        long depth;
        long longestPath;
        long startPointOfLongestPath;
        long deepestNode;
        boolean included;

        public TreeInfo(long depth, long longestPath, long startPointOfLongestPath, long deepestNode, boolean included) {
            this.depth = depth;
            this.longestPath = longestPath;
            this.startPointOfLongestPath = startPointOfLongestPath;
            this.deepestNode = deepestNode;
            this.included = included;
        }
    }

    static List<List<Long>> tree = new ArrayList<>();
    static List<Long> startPoints = new ArrayList<>();

    static List<List<Long>> graph = new ArrayList<>();

    static long getModuloInv(long n) {
        if (n == 1)
            return 1;
        if (mInv[(int) n] > 0)
            return mInv[(int) n];
        long m = (-1 * MDLO) / n;
        m += MDLO;
        m *= getModuloInv(MDLO % n);
        mInv[(int) n] = (m % MDLO);
        return mInv[(int) n];
    }

    static long getAncestor(long val, long[] par) {
        if (par[(int) val] != val)
            par[(int) val] = getAncestor(par[(int) val], par);
        return par[(int) val];
    }

    static boolean unify(long a, long b, long[] par) {
        long para = getAncestor(a, par), parb = getAncestor(b, par);
        if (para == parb)
            return false;
        if (para < parb)
            par[(int) parb] = para;
        else
            par[(int) para] = parb;
        return true;
    }

    static List<Long> getPrimes(long max) {
        List<Long> primes = new ArrayList<>();
        byte[] sieve = new byte[(int) (max / 8 + 1)];
        long m = (max / 8) + 1;
        for (long i = 0; i < m; i++)
            sieve[(int) i] = (byte) 255;
        for (long x = 2; x <= max; x++)
            if ((sieve[(int) (x / 8)] & (0x01 << (x % 8))) != 0) {
                primes.add(x);
                for (long j = 2 * x; j <= max; j += x)
                    sieve[(int) (j / 8)] &= ~(0x01 << (j % 8));
            }
        return primes;
    }

    static long[][] dp = new long[22][22];

    static long getDp(long N, long K) {
        if (dp[(int) N][(int) K] == 0) {
            if (K == 1) {
                dp[(int) N][(int) K] = N;
                return dp[(int) N][(int) K];
            }
            long v1 = getDp(N, K - 1), v2 = getDp(N - 1, K - 1);
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

    static long getLcm(long a, long b) {
        long c = a / gcd(a, b);
        return b * c;
    }

    static TreeInfo dfs(long startPoint, boolean[] inTree, boolean[] visited) {
        TreeInfo tInfo = new TreeInfo(0, 0, 0, 0, false);
        long maxDepth = 0, maxDepth2 = 0, deepestNode = 1234567, deepestNode2 = 1234567, longestPath = 0,
                longestPathStart = 1234567;
        boolean status = inTree[(int) startPoint];
        visited[(int) startPoint] = true;
        for (long i = 0; i < tree.get((int) startPoint).size(); i++) {
            if (!visited[(int) tree.get((int) startPoint).get((int) i)]) {
                TreeInfo childInfo = dfs(tree.get((int) startPoint).get((int) i), inTree, visited);
                if (childInfo.included) {
                    status = true;
                    if (maxDepth < childInfo.depth
                            || (maxDepth == childInfo.depth && deepestNode > childInfo.deepestNode)) {
                        maxDepth2 = maxDepth;
                        deepestNode2 = deepestNode;
                        deepestNode = childInfo.deepestNode;
                        maxDepth = childInfo.depth;
                    } else if (maxDepth2 < childInfo.depth
                            || (maxDepth2 == childInfo.depth && deepestNode2 > childInfo.deepestNode)) {
                        maxDepth2 = childInfo.depth;
                        deepestNode2 = childInfo.deepestNode;
                    }
                    if (childInfo.longestPath > longestPath
                            || (childInfo.longestPath == longestPath
                                    && longestPathStart < childInfo.startPointOflongestpath)) {
                        longestPath = childInfo.longestPath;
                        longestPathStart = childInfo.startPointOflongestpath;
                    }
                }
            }
        }
        tInfo.included = status;
        if (maxDepth == 0) {
            tInfo.deepestNode = startPoint;
            tInfo.depth = 1;
            tInfo.longestPath = 1;
            tInfo.startPointOflongestpath = startPoint;
            return tInfo;
        }
        if (maxDepth + maxDepth2 + 1 > longestPath
                || (maxDepth + maxDepth2 + 1 == longestPath && longestPathStart > Math.min(deepestNode, deepestNode2))) {
            longestPathStart = Math.min(deepestNode, deepestNode2);
            longestPath = maxDepth + maxDepth2 + 1;
        }
        if (maxDepth2 == maxDepth && deepestNode2 < deepestNode)
            deepestNode = deepestNode2;
        tInfo.deepestNode = deepestNode;
        tInfo.depth = maxDepth + 1;
        tInfo.longestPath = longestPath;
        tInfo.startPointOflongestpath = longestPathStart;
        inTree[(int) startPoint] = status;
        return tInfo;
    }

    static long getVal(long num) {
        long ans = 1;
        for (long i = 1; i < num; i++)
            ans += (num / gcd(num, i));
        return ans;
    }

    static void buildDp() {
        for (long i = 1; i < 22; i++) {
            for (long j = 1; j <= i; j++) {
                dp[(int) i][(int) j] = getDp(i, j);
                System.out.print(dp[(int) i][(int) j] + " ");
            }
            System.out.println();
        }
    }

    static double[] angle = new double[345768];

    static double maxDist(double t, double v, double r) {
        double dist = t * v;
        double C = t * v / r;
        double rotateDist1 = Math.cos((PI + C) / 2) - Math.cos((PI - C) / 2);
        double rotateDist2 = Math.cos((3 * PI + C) / 2) - Math.cos((3 * PI - C) / 2);
        return dist + r * Math.max(rotateDist1, rotateDist2);
    }

    static void printMaxMin(double C) {
        double maxVal = -1, maxAngle = 0, minVal = 1, minAngle = 0;
        for (double th = 0.00; th < 360.1; th += 0.01) {
            double angle = ((th + C) * PI) / 180.0;
            double val = Math.cos(angle) - Math.cos((th * PI) / 180.0);
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
        Scanner scanner = new Scanner(System.in);

        long testCases = 1, C, D, A, L, R, rep, round = 0, rem, ans = 0, num;
        double st, en, minErr = 0.00000001, r, v;

        testCases = scanner.nextLong();
        r = scanner.nextDouble();
        v = scanner.nextDouble();

        for (long T = 0; T < testCases; T++) {
            st = scanner.nextDouble();
            en = scanner.nextDouble();
            double dist = en - st;
            double low = (dist - 2 * r) / v, high = (dist + 2 * r) / v, mid;
            while (low + minErr < high && low + low * minErr < high) {
                mid = (low + high) / 2;
                if (maxDist(mid, v, r) > dist)
                    high = mid;
                else
                    low = mid;
            }
            System.out.printf("%.15f\n", (low + high) / 2);
        }

        scanner.close();
    }
}
