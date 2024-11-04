import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    static class Pair {
        long first, second;

        Pair(long first, long second) {
            this.first = first;
            this.second = second;
        }
    }

    static class Update {
        Pair first;
        long second;

        Update(Pair first, long second) {
            this.first = first;
            this.second = second;
        }
    }

    static int maxBits = 40;
    static Map<Long, Long>[] counts1 = new HashMap[30];
    static Map<Long, Long>[] counts2 = new HashMap[30];
    static long[] pwr2 = new long[100];
    static long[] parent = new long[1010];
    static long N;
    static List<Long>[] Trree = new ArrayList[100];
    static long PI = 3.1415926535897932384626433832795;
    static long mdlo = 1000000007;

    static long getParent(long node) {
        if (parent[(int) node] != node)
            parent[(int) node] = getParent(parent[(int) node]);
        return parent[(int) node];
    }

    static void unionNode(long node1, long node2) {
        if (getParent(node1) != getParent(node2)) {
            parent[(int) parent[(int) node1]] = parent[(int) node2];
        }
    }

    static void buildpwr2(long lim) {
        pwr2[0] = 1;
        for (long i = 0; i < lim; i++)
            pwr2[(int) (i + 1)] = pwr2[(int) i] << 1;
    }

    static long onNthbit(long pos, long val) {
        return val | pwr2[(int) pos];
    }

    static boolean isNthbitOn(long long pos, long long val) {
        return (val & pwr2[(int) pos]) > 0;
    }

    static long gcd(long a, long b) {
        long c;
        c = b % a;
        while (c > 0) {
            b = a;
            a = c;
            c = b % a;
        }
        return a;
    }

    static String s;
    static long target, sticker;
    static long[] segTree = new long[600005];
    static long[] segTreeData = new long[100005];
    static long[] sumSegTree = new long[600005];
    static long[] sumSegTreeData = new long[100005];
    static long[] minStart = new long[2];
    static long[] minEnd = new long[2];

    static void buildSegmentTree(long b, long e, long node) {
        if (b == e) {
            segTree[(int) node] = b;
            return;
        }
        long mid = (b + e) / 2;
        buildSegmentTree(b, mid, node * 2);
        buildSegmentTree(mid + 1, e, 1 + (node * 2));
        if (segTreeData[(int) segTree[(int) (node * 2)]] > segTreeData[(int) segTree[(int) (1 + (node * 2))]])
            segTree[(int) node] = segTree[(int) (node * 2)];
        else
            segTree[(int) node] = segTree[(int) (1 + (2 * node))];
    }

    static void buildMinSegmentTree(long b, long e, long node) {
        if (b == e) {
            segTree[(int) node] = b;
            return;
        }
        long mid = (b + e) / 2;
        buildMinSegmentTree(b, mid, node * 2);
        buildMinSegmentTree(mid + 1, e, 1 + (node * 2));
        if (segTreeData[(int) segTree[(int) (node * 2)]] > segTreeData[(int) segTree[(int) (1 + (node * 2))]])
            segTree[(int) node] = segTree[(int) (1 + (node * 2))];
        else
            segTree[(int) node] = segTree[(int) (2 * node)];
    }

    static void updateMinSegmentTree(long b, long e, long node, long pos, long val) {
        if (b > pos || e < pos)
            return;
        if (b == e) {
            segTreeData[(int) pos] = val;
            return;
        }
        long mid = (b + e) / 2;
        updateMinSegmentTree(b, mid, node * 2, pos, val);
        updateMinSegmentTree(mid + 1, e, 1 + node * 2, pos, val);
        if (segTreeData[(int) segTree[(int) (node * 2)]] > segTreeData[(int) segTree[(int) (1 + node * 2)]])
            segTree[(int) node] = segTree[(int) (1 + 2 * node)];
        else
            segTree[(int) node] = segTree[(int) (2 * node)];
    }

    static long getMax(long qStart, long qEnd, long sStart, long sEnd, long node) {
        if (qEnd < sStart || qStart > sEnd)
            return -1;
        if (sStart >= qStart && sEnd <= qEnd)
            return segTree[(int) node];
        long sMid = (sStart + sEnd) / 2;
        long r1 = getMax(qStart, qEnd, sStart, sMid, 2 * node);
        long r2 = getMax(qStart, qEnd, sMid + 1, sEnd, 1 + (2 * node));
        if (r1 < 0)
            return r2;
        if (r2 < 0 || segTreeData[(int) r1] > segTreeData[(int) r2])
            return r1;
        return r2;
    }

    static long getMinFromSegTree(long qStart, long qEnd, long sStart, long sEnd, long node) {
        if (qEnd < sStart || qStart > sEnd)
            return -1;
        if (sStart >= qStart && sEnd <= qEnd)
            return segTree[(int) node];
        long sMid = (sStart + sEnd) / 2;
        long r1 = getMinFromSegTree(qStart, qEnd, sStart, sMid, 2 * node);
        long r2 = getMinFromSegTree(qStart, qEnd, sMid + 1, sEnd, 1 + (2 * node));
        if (r2 < 0)
            return r1;
        if (r1 < 0 || segTreeData[(int) r1] > segTreeData[(int) r2])
            return r2;
        return r1;
    }

    static void buildSumSegmentTree(long b, long e, long node) {
        if (b == e) {
            sumSegTree[(int) node] = sumSegTreeData[(int) b];
            return;
        }
        long mid = (b + e) / 2;
        buildSumSegmentTree(b, mid, node * 2);
        buildSumSegmentTree(mid + 1, e, 1 + node * 2);
        sumSegTree[(int) node] = sumSegTree[(int) (node * 2)] + sumSegTree[(int) (1 + (node * 2))];
    }

    static void updateSumSegmentTree(long b, long e, long node, long pos, long val) {
        if (pos < b || pos > e)
            return;
        if (b == e) {
            sumSegTree[(int) node] = val;
            sumSegTreeData[(int) pos] = val;
            return;
        }
        long mid = (b + e) / 2;
        updateSumSegmentTree(b, mid, 2 * node, pos, val);
        updateSumSegmentTree(mid + 1, e, 1 + 2 * node, pos, val);
        sumSegTree[(int) node] = sumSegTree[(int) (node * 2)] + sumSegTree[(int) (1 + (node * 2))];
    }

    static long getSumFromSegTree(long b, long e, long node, long qStart, long qEnd) {
        if (qStart > e || qEnd < b)
            return 0;
        if (b >= qStart && e <= qEnd)
            return sumSegTree[(int) node];
        long mid = (b + e) / 2;
        return getSumFromSegTree(b, mid, node * 2, qStart, qEnd)
                + getSumFromSegTree(mid + 1, e, 1 + 2 * node, qStart, qEnd);
    }

    static long getLcm(long a, long b) {
        long c = a / gcd(a, b);
        return b * c;
    }

    static long[] pow10 = new long[18];
    static long[] pow2 = new long[18];

    static long getlen(long long num) {
        long len = 1;
        while (num > 9) {
            num /= 10;
            len++;
        }
        return len;
    }

    static void test(long a) {
        switch (a) {
            case 1:
                System.out.println(1);
            case 2:
                System.out.println(2);
                break;
            case 3:
                System.out.println(3);
            case 4:
                System.out.println(4);
            case 5:
                System.out.println(5);
            default:
                System.out.println(0);
        }
        System.out.println();
    }

    static class Base {
        void f(String label) {
            System.out.println(label + ":base");
        }
    }

    static class Derived extends Base {
        void f(String label) {
            System.out.println(label + ":derived");
        }
    }

    static void buildRandomTree(List<Long>[] tree, long node) {
        long[] ancestor = new long[100];
        for (int i = 0; i < 100; i++) {
            ancestor[i] = i;
        }
        Random rand = new Random();
        for (long i = 1; i < node; i++) {
            int node1 = rand.nextInt();
            int node2 = rand.nextInt();
            int par1 = node1, par2 = node2;
            while (ancestor[par1] != par1)
                par1 = (int) ancestor[par1];
        }
    }

    public static void main(String[] args) throws java.lang.Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        PrintWriter out = new PrintWriter(System.out);

        long test_cases = 1;
        pow2[0] = 1;
        for (long i = 1; i < 18; i++)
            pow2[(int) i] = pow2[(int) (i - 1)] * 2;

        for (long T = 0; T < test_cases; T++) {

            String s, t;
            String m1, m2;
            long k, n, m, p;
            st = new StringTokenizer(br.readLine());
            n = Long.parseLong(st.nextToken());
            k = Long.parseLong(st.nextToken());
            long[] bamboo = new long[111];
            st = new StringTokenizer(br.readLine());
            for (long i = 0; i < n; i++) {
                bamboo[(int) i] = Long.parseLong(st.nextToken());
            }
            Arrays.sort(bamboo, 0, (int) n);
            long[] bambooSum = new long[111];
            bambooSum[0] = bamboo[0];
            long maxval = 0;
            for (long i = 1; i < n; i++) {
                bambooSum[(int) i] = bamboo[(int) i] + bambooSum[(int) (i - 1)];
                long m = i * bamboo[(int) i] - bambooSum[(int) (i - 1)];
                if (m > k && maxval == 0) {
                    maxval = bamboo[(int) i];
                }
            }
            if (maxval == 0) {
                long remaining = k + bambooSum[(int) (n - 1)] - (n * bamboo[(int) (n - 1)]);
                out.println((remaining / n) + bamboo[(int) (n - 1)]);
                out.flush();
                return;
            }
            Set<Long> candidatePoints = new HashSet<>();

            for (long i = 0; i < n; i++) {
                bambooSum[(int) i] += k;
                long lim = 1 + Math.sqrt(bamboo[(int) i] + 1);
                for (long j = 1; j < lim; j++) {
                    long r1 = bamboo[(int) i] / j, r2 = j;
                    if (r1 < maxval) {
                        if (r1 * j == bamboo[(int) i])
                            candidatePoints.add(r1);
                        else
                            candidatePoints.add(r1 + 1);
                    }
                }
            }
            long lim = (long) Math.sqrt(bamboo[(int) (n - 1)]);
            if (lim > maxval)
                lim = maxval;
            for (long i = 1; i < lim; i++)
                candidatePoints.add(i);
            List<Long> sortedCandidatePoints = new ArrayList<>(candidatePoints);
            Collections.sort(sortedCandidatePoints, Collections.reverseOrder());
            for (long cp : sortedCandidatePoints) {
                long total = 0, d1, flag = 1;
                for (long i = 0; i < n; i++) {
                    d1 = (bamboo[(int) i] + cp - 1) / cp;
                    total += (d1 * cp);
                    if (total > bambooSum[(int) i]) {
                        flag = 0;
                        break;
                    }
                }
                if (flag == 1) {
                    long dv = 0;
                    for (long i = 0; i < n; i++)
                        dv += (bamboo[(int) i] + cp - 1) / cp;
                    out.println(cp + (bambooSum[(int) (n - 1)] - total) / dv);
                    out.flush();
                    return;
                }
            }
            out.println(1);
            out.flush();
        }
    }
}
