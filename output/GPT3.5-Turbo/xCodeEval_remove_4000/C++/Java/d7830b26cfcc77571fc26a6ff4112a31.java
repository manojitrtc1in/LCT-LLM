import java.util.*;

class Main {
    static class Pair {
        long first;
        long second;

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

    static int N;
    static List<Long>[] Tree;
    static Map<Long, Long>[] counts1;
    static Map<Long, Long>[] counts2;
    static long[] pwr2;
    static long[] parent;
    static String s;
    static long target;
    static long sticker;
    static long[] segTree;
    static long[] segTreeData;
    static long[] sumSegTree;
    static long[] sumSegTreeData;
    static long[] minStart;
    static long[] minEnd;
    static long[] pow10;
    static long[] pow2;

    static long getParent(long node) {
        if (parent[node] != node)
            parent[node] = getParent(parent[node]);
        return parent[node];
    }

    static void unionNode(long node1, long node2) {
        if (getParent(node1) != getParent(node2)) {
            parent[(int) getParent(node1)] = parent[(int) node2];
        }
    }

    static void id11(long lim) {
        pwr2[0] = 1;
        for (long i = 0; i < lim; i++)
            pwr2[(int) (i + 1)] = pwr2[(int) i] << 1;
    }

    static long id0(long pos, long val) {
        return val | pwr2[(int) pos];
    }

    static boolean id1(long pos, long val) {
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

    static long id5(long qStart, long qEnd, long sStart, long sEnd, long node) {
        if (qEnd < sStart || qStart > sEnd)
            return -1;
        if (sStart >= qStart && sEnd <= qEnd)
            return segTree[(int) node];
        long sMid = (sStart + sEnd) / 2;
        long r1 = id5(qStart, qEnd, sStart, sMid, 2 * node);
        long r2 = id5(qStart, qEnd, sMid + 1, sEnd, 1 + (2 * node));
        if (r2 < 0)
            return r1;
        if (r1 < 0 || segTreeData[(int) r1] > segTreeData[(int) r2])
            return r2;
        return r1;
    }

    static void id9(long b, long e, long node, long pos, long val) {
        if (pos < b || pos > e)
            return;
        if (b == e) {
            sumSegTree[(int) node] = val;
            sumSegTreeData[(int) pos] = val;
            return;
        }
        long mid = (b + e) / 2;
        id9(b, mid, 2 * node, pos, val);
        id9(mid + 1, e, 1 + 2 * node, pos, val);
        sumSegTree[(int) node] = sumSegTree[(int) node * 2] + sumSegTree[(int) (1 + 2 * node)];
    }

    static long id6(long b, long e, long node, long qStart, long qEnd) {
        if (qStart > e || qEnd < b)
            return 0;
        if (b >= qStart && e <= qEnd)
            return sumSegTree[(int) node];
        long mid = (b + e) / 2;
        return id6(b, mid, 2 * node, qStart, qEnd) + id6(mid + 1, e, 1 + 2 * node, qStart, qEnd);
    }

    static long id2(long a, long b) {
        long c = a / gcd(a, b);
        return b * c;
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

        int test_cases = 1;
        pow2[0] = 1;
        for (int i = 1; i < 18; i++)
            pow2[i] = pow2[i - 1] * 2;

        System.out.println();

        for (int T = 0; T < test_cases; T++) {
            String s, t;
            String m1, m2;
            long k, n, m, p;
            n = sc.nextLong();
            k = sc.nextLong();
            long[] bamboo = new long[111];
            for (int i = 0; i < n; i++) {
                bamboo[i] = sc.nextLong();
            }
            Arrays.sort(bamboo);
            long[] bambooSum = new long[111];
            bambooSum[0] = bamboo[0];
            long maxval = 0;
            for (int i = 1; i < n; i++) {
                bambooSum[i] = bamboo[i] + bambooSum[i - 1];
                m = i * bamboo[i] - bambooSum[i - 1];
                if (m > k && maxval == 0) {
                    maxval = bamboo[i];
                }
            }
            if (maxval == 0) {
                long remaining = k + bambooSum[n - 1] - (n * bamboo[n - 1]);
                System.out.println((remaining / n) + bamboo[n - 1]);
                return;
            }
            Set<Long> candidatePoints = new HashSet<>();

            for (int i = 0; i < n; i++) {
                bambooSum[i] += k;
                long lim = 1 + (long) Math.sqrt(bamboo[i] + 1);
                for (int j = 1; j < lim; j++) {
                    long r1 = bamboo[i] / j, r2 = j;
                    if (r1 < maxval) {
                        if (r1 * j == bamboo[i])
                            candidatePoints.add(r1);
                        else
                            candidatePoints.add(r1 + 1);
                    }
                }
            }
            long lim = (long) Math.sqrt(bamboo[n - 1]);
            if (lim > maxval)
                lim = maxval;
            for (int i = 1; i < lim; i++)
                candidatePoints.add((long) i);
            List<Long> sortedCandidatePoints = new ArrayList<>(candidatePoints);
            Collections.sort(sortedCandidatePoints, Collections.reverseOrder());
            for (long cp : sortedCandidatePoints) {
                long total = 0, d1, flag = 1;
                for (int i = 0; i < n; i++) {
                    d1 = (bamboo[i] + cp - 1) / cp;
                    total += (d1 * cp);
                    if (total > bambooSum[i]) {
                        flag = 0;
                        break;
                    }
                }
                if (flag == 1) {
                    long dv = 0;
                    for (int i = 0; i < n; i++)
                        dv += (bamboo[i] + cp - 1) / cp;
                    System.out.println(cp + (bambooSum[n - 1] - total) / dv);
                    return;
                }
            }
            System.out.println(1);
        }
    }
}
