import java.util.*;
import java.io.*;

public class d7830b26cfcc77571fc26a6ff4112a31_nc {
    static final double PI = 3.1415926535897932384626433832795;
    static final long mdlo = 1000000007;
    static long[] pwr2 = new long[100];
    static long[] parent = new long[1010];
    static long[] segTree = new long[600005];
    static long[] segTreeData = new long[100005];
    static long[] sumSegTree = new long[600005];
    static long[] sumSegTreeData = new long[100005];
    static long[] bamboo = new long[111];

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

    static boolean isNthbitOn(long pos, long val) {
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

    static void buildSegmentTree(long b, long e, long node) {
        if (b == e) {
            segTree[(int) node] = b;
            return;
        }
        long mid = (b + e) / 2;
        buildSegmentTree(b, mid, node * 2);
        buildSegmentTree(mid + 1, e, 1 + (node * 2));
        if (segTreeData[(int) segTree[(int) (node * 2)]] > segTreeData[(int) segTree[(int) (1 + (node * 2)))])
            segTree[(int) node] = segTree[(int) (node * 2)];
        else
            segTree[(int) node] = segTree[(int) (1 + (2 * node))];
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

    static long getSumFromSegTree(long b, long e, long node, long qStart, long qEnd) {
        if (qStart > e || qEnd < b)
            return 0;
        if (b >= qStart && e <= qEnd)
            return sumSegTree[(int) node];
        long mid = (b + e) / 2;
        return getSumFromSegTree(b, mid, node * 2, qStart, qEnd) + getSumFromSegTree(mid + 1, e, 1 + 2 * node, qStart, qEnd);
    }

    static long getlen(long num) {
        long len = 1;
        while (num > 9) {
            num /= 10;
            len++;
        }
        return len;
    }

    static void test(long a) {
        switch ((int) a) {
            case 1:
                System.out.print(1);
            case 2:
                System.out.print(2);
                break;
            case 3:
                System.out.print(3);
            case 4:
                System.out.print(4);
            case 5:
                System.out.print(5);
            default:
                System.out.print(0);
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long test_cases = 1;
        pwr2[0] = 1;
        for (long i = 1; i < 18; i++)
            pwr2[(int) i] = pwr2[(int) (i - 1)] * 2;

        for (long T = 0; T < test_cases; T++) {
            long n = sc.nextLong();
            long k = sc.nextLong();
            for (long i = 0; i < n; i++) {
                bamboo[(int) i] = sc.nextLong();
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
                System.out.println((remaining / n) + bamboo[(int) (n - 1)]);
                return;
            }
            Set<Long> candidatePoints = new HashSet<>();

            for (long i = 0; i < n; i++) {
                bambooSum[(int) i] += k;
                long lim = 1 + (long) Math.sqrt(bamboo[(int) i] + 1);
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
            List<Long> sortedCandidates = new ArrayList<>(candidatePoints);
            Collections.sort(sortedCandidates, Collections.reverseOrder());
            for (long cp : sortedCandidates) {
                long total = 0, d1, flag = 1;
                for (long i = 0; i < n; i++) {
                    d1 = (bamboo[(int) i] + cp - 1) / cp;
                    total += (d1 * cp);
                    if (total > bambooSum[(int) i]) {
                        flag = 0;
                        break;
                    }
                }
                if (flag) {
                    long dv = 0;
                    for (long i = 0; i < n; i++)
                        dv += (bamboo[(int) i] + cp - 1) / cp;
                    System.out.println(cp + (bambooSum[(int) (n - 1)] - total) / dv);
                    return;
                }
            }
            System.out.println(1);
        }
        sc.close();
    }
}
