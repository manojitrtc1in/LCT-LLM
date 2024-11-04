import java.util.*;
import java.io.*;

public class c586892ba128e8135a0cd7cd2985e86d_nc {
    static final long mdlo = 1000000007;
    static final double maxERR = 0.00000064;
    static final int maxBits = 40;
    static final double pi = 3.1415926535897932384626433832795;
    static final long INF = 999999999999;
    static long[] mInv = new long[41];
    static long[] fact = new long[41];
    static long[] factInv = new long[41], N, M;
    static long[] levels = new long[15];
    static long[] nextPoint = new long[15];
    static long[] firstDigit = new long[15];
    static boolean[] inTree = new boolean[123466];
    static boolean[] visited = new boolean[123466];
    static List<Long>[] tree = new ArrayList[123466];
    static List<Long> startPoints = new ArrayList<>();
    static long[] par = new long[45];
    static long[][] dp = new long[22][22];

    static {
        for (int i = 0; i < tree.length; i++) {
            tree[i] = new ArrayList<>();
        }
    }

    static long getmoduloInv(long n) {
        if (n == 1)
            return 1;
        if (mInv[(int) n] > 0)
            return mInv[(int) n];
        long m = (-1 * mdlo) / n;
        m += mdlo;
        m *= getmoduloInv(mdlo % n);
        mInv[(int) n] = (m % mdlo);
        return mInv[(int) n];
    }

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

    static List<Long> get_primes(long max) {
        List<Long> primes = new ArrayList<>();
        boolean[] sieve = new boolean[(int) (max + 1)];
        Arrays.fill(sieve, true);
        for (long x = 2; x <= max; x++) {
            if (sieve[(int) x]) {
                primes.add(x);
                for (long j = 2 * x; j <= max; j += x)
                    sieve[(int) j] = false;
            }
        }
        return primes;
    }

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

    static long getLcm(long a, long b) {
        long c = a / gcd(a, b);
        return b * c;
    }

    static class TreeInfo {
        long depth;
        long longestPath;
        long startPointOflongestpath;
        long deepestNode;
        boolean included;
    }

    static TreeInfo dfs(long startPoint) {
        TreeInfo tInfo = new TreeInfo();
        long maxDepth = 0, maxDepth2 = 0, deepestNode = 1234567, deepestNode2 = 1234567, longestPath = 0, longestPathStart = 1234567;
        boolean status = inTree[(int) startPoint];
        visited[(int) startPoint] = true;
        for (long neighbor : tree[(int) startPoint]) {
            if (!visited[(int) neighbor]) {
                TreeInfo childInfo = dfs(neighbor);
                if (childInfo.included) {
                    status = true;
                    if (maxDepth < childInfo.depth || (maxDepth == childInfo.depth && deepestNode > childInfo.deepestNode)) {
                        maxDepth2 = maxDepth;
                        deepestNode2 = deepestNode;
                        deepestNode = childInfo.deepestNode;
                        maxDepth = childInfo.depth;
                    } else if (maxDepth2 < childInfo.depth || (maxDepth2 == childInfo.depth && deepestNode2 > childInfo.deepestNode)) {
                        maxDepth2 = childInfo.depth;
                        deepestNode2 = childInfo.deepestNode;
                    }
                    if (childInfo.longestPath > longestPath || (childInfo.longestPath == longestPath && longestPathStart < childInfo.startPointOflongestpath)) {
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
        if (maxDepth + maxDepth2 + 1 > longestPath || (maxDepth + maxDepth2 + 1 == longestPath && longestPathStart > Math.min(deepestNode, deepestNode2))) {
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
        for (long[] row : dp) {
            Arrays.fill(row, 0);
        }
        for (long i = 1; i < 22; i++) {
            for (long j = 1; j <= i; j++) {
                dp[(int) i][(int) j] = getdp(i, j);
                System.out.print(dp[(int) i][(int) j] + " ");
            }
            System.out.println();
        }
    }

    static double maxDist(double t, double v, double r) {
        double dist = t * v;
        double C = t * v / r;
        double rotateDist1 = Math.cos((pi + C) / 2) - Math.cos((pi - C) / 2);
        double rotateDist2 = Math.cos((3 * pi + C) / 2) - Math.cos((3 * pi - C) / 2);
        return dist + r * Math.max(rotateDist1, rotateDist2);
    }

    static void printMaxMin(double C) {
        double maxVal = -1, maxAngle = 0, minVal = 1, minAngle = 0;
        for (double th = 0.00; th < 360.1; th += 0.01) {
            double angle = ((th + C) * pi) / 180.0;
            double val = Math.cos(angle) - Math.cos((th * pi) / 180.0);
            if (val > maxVal) {
                maxVal = val;
                maxAngle = th;
            }
            if (val < minVal) {
                minVal = val;
                minAngle = th;
            }
        }
        System.out.printf("max %.15f angle %.15f\n", maxVal, maxAngle);
        System.out.printf("min %.15f angle %.15f\n", minVal, minAngle);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        long test_cases = 1, C, D, A, L, R, rep, round = 0, rem, ans = 0, num;

        double st, en, minerr = 0.00000001, r, v;
        StringTokenizer stoken = new StringTokenizer(br.readLine());
        test_cases = Long.parseLong(stoken.nextToken());
        r = Double.parseDouble(stoken.nextToken());
        v = Double.parseDouble(stoken.nextToken());
        out.printf("%.15f\n", 0.0);

        for (long T = 0; T < test_cases; T++) {
            stoken = new StringTokenizer(br.readLine());
            st = Double.parseDouble(stoken.nextToken());
            en = Double.parseDouble(stoken.nextToken());
            double dist = en - st;
            double low = (dist - 2 * r) / v, high = (dist + 2 * r) / v, mid;
            while (low + minerr < high && low + low * minerr < high) {
                mid = (low + high) / 2;
                if (maxDist(mid, v, r) > dist)
                    high = mid;
                else
                    low = mid;
            }
            out.printf("%.15f\n", (low + high) / 2);
        }
        out.flush();
    }
}
