import java.util.*;
import java.io.*;

class FastAllocator {
    static int allocatorPos = 0;
    static final int FAST_ALLOCATOR_MEMORY = 1 << 20; // Example size
    static byte[] allocatorMemory = new byte[FAST_ALLOCATOR_MEMORY];

    static void* new(size_t n) {
        byte[] res = Arrays.copyOfRange(allocatorMemory, allocatorPos, allocatorPos + n);
        allocatorPos += n;
        assert allocatorPos <= FAST_ALLOCATOR_MEMORY;
        return res;
    }

    static void delete(void* ptr) {
        // No operation
    }
}

class BufferFlusher {
    @Override
    protected void finalize() throws Throwable {
        flush();
        super.finalize();
    }
}

public class afb69d139dc9c6d65ecca9bb5333c9e3xcodeeval_processed_4000.json {
    static final int MAXN = 300000 + 42;
    static int n;
    static Random rand = new Random();

    static class Treap {
        Treap left = null;
        Treap right = null;
        long t;
        int y;
        long prefixSum;
        long speed;
        long push = 0;
        long minPrefixSumInSubtree;

        Treap(long t, long val, long speed) {
            this.t = t;
            this.y = rand.nextInt();
            this.prefixSum = val;
            this.speed = speed;
            this.minPrefixSumInSubtree = val;
        }
    }

    static void vertexAdd(Treap a, long push) {
        a.prefixSum += push;
        a.minPrefixSumInSubtree += push;
        a.push += push;
    }

    static void push(Treap a) {
        long push = a.push;
        if (push == 0) return;
        if (a.left != null) {
            vertexAdd(a.left, push);
        }
        if (a.right != null) {
            vertexAdd(a.right, push);
        }
        a.push = 0;
    }

    static final long INF = 1e18;

    static long smin(Treap a) {
        return a != null ? a.minPrefixSumInSubtree : INF;
    }

    static void recalc(Treap a) {
        a.minPrefixSumInSubtree = Math.min(Math.min(smin(a.left), smin(a.right)), a.prefixSum);
    }

    static Treap merge(Treap a, Treap b) {
        if (a == null) return b;
        if (b == null) return a;
        if (a.y < b.y) {
            push(a);
            a.right = merge(a.right, b);
            recalc(a);
            return a;
        } else {
            push(b);
            b.left = merge(a, b.left);
            recalc(b);
            return b;
        }
    }

    static Pair<Treap, Treap> split(Treap a, long k) {
        if (a == null) return new Pair<>(a, a);
        push(a);
        if (a.t < k) {
            Pair<Treap, Treap> splitResult = split(a.right, k);
            a.right = splitResult.first;
            recalc(a);
            return new Pair<>(a, splitResult.second);
        } else {
            Pair<Treap, Treap> splitResult = split(a.left, k);
            a.left = splitResult.second;
            recalc(a);
            return new Pair<>(splitResult.first, a);
        }
    }

    static Treap id12(Treap a) {
        push(a);
        if (a.left == null) {
            return a;
        }
        return id12(a.left);
    }

    static Treap id7(Treap a) {
        push(a);
        if (a.right == null) {
            return a;
        }
        return id7(a.right);
    }

    static Treap id2(Treap a, long v) {
        push(a);
        if (smin(a.left) <= v) {
            return id2(a.left, v);
        }
        if (a.prefixSum <= v) return a;
        return id2(a.right, v);
    }

    static void printTree(Treap a) {
        if (a == null) return;
        printTree(a.left);
        System.err.print(a.t + " ");
        printTree(a.right);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter number of queries:");
        int q = scanner.nextInt();
        Treap root = new Treap(0, 0, 0);
        root = merge(root, new Treap(2e9, 0, 0));

        for (int i = 0; i < q; ++i) {
            int type = scanner.nextInt();
            if (type == 1) {
                long t = scanner.nextLong();
                long s = scanner.nextLong();
                Pair<Treap, Treap> splitResult = split(root, t);
                Treap vr = id12(splitResult.second);
                Treap vl = id7(splitResult.first);
                long psum = vl.prefixSum + (t - vl.t) * vl.speed;
                long id5 = psum + (vr.t - t) * s;
                vertexAdd(vr, id5 - vr.prefixSum);
                root = merge(vl, merge(new Treap(t, psum, s), vr));
            } else if (type == 2) {
                long t = scanner.nextLong();
                Pair<Treap, Treap> splitResult = split(root, t);
                Pair<Treap, Treap> splitResult2 = split(splitResult.second, t + 1);
                Treap vl = id7(splitResult.first);
                Treap vr = id12(splitResult2.second);
                long id5 = vl.prefixSum + (vr.t - vl.t) * vl.speed;
                vertexAdd(vr, id5 - vr.prefixSum);
                root = merge(splitResult.first, vr);
            } else {
                int L = scanner.nextInt();
                int R = scanner.nextInt();
                long v = scanner.nextLong();
                if (v == 0) {
                    System.out.println(L);
                    continue;
                }
                Pair<Treap, Treap> splitResult = split(root, L);
                Pair<Treap, Treap> splitResult2 = split(splitResult.second, R + 1);
                if (splitResult2.first == null) {
                    System.out.println(-1);
                } else {
                    Treap vl = id12(splitResult2.first);
                    Treap vr = id7(splitResult2.first);
                    long id13 = vl.prefixSum - v;

                    if (splitResult2.first.minPrefixSumInSubtree > id13) {
                        long id5 = vr.prefixSum + (R - vr.t) * vr.speed;

                        if (id5 > id13) {
                            System.out.println("-1");
                        } else {
                            System.out.println(vr.t + (double) (id13 - vr.prefixSum) / vr.speed);
                        }
                    } else {
                        Treap h = id2(splitResult2.first, id13);
                        Pair<Treap, Treap> splitResult3 = split(splitResult2.first, h.t);
                        Treap vyl = id7(splitResult3.first);
                        System.out.println(vyl.t + (double) (id13 - vyl.prefixSum) / vyl.speed);
                        splitResult2.first = merge(splitResult3.first, splitResult3.second);
                    }
                }
                root = merge(splitResult.first, merge(splitResult2.first, splitResult2.second));
            }
        }
        scanner.close();
    }

    static void flush() {
        // Implement flush logic if needed
    }

    static void writeChar(int x) {
        // Implement write character logic if needed
    }

    static void writeInt(long x, char end, int outputLen) {
        // Implement write integer logic if needed
    }

    static void writeWord(String s) {
        // Implement write word logic if needed
    }

    static void writeDouble(double x, int outputLen) {
        // Implement write double logic if needed
    }
}

class Pair<F, S> {
    public final F first;
    public final S second;

    public Pair(F first, S second) {
        this.first = first;
        this.second = second;
    }
}
