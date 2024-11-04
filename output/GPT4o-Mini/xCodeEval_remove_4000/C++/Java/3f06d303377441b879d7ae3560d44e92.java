import java.util.*;
import java.io.*;

public class 3f06d303377441b879d7ae3560d44e92xcodeeval_processed_4000.json {
    static final int MOD = 998244353;

    static class ModInt {
        int val;

        ModInt(long v) {
            if (v < 0) v = v % MOD + MOD;
            if (v >= MOD) v %= MOD;
            val = (int) v;
        }

        static int modInv(int a, int m) {
            int g = m, r = a, x = 0, y = 1;

            while (r != 0) {
                int q = g / r;
                g %= r; 
                int temp = g; g = r; r = temp;
                x -= q * y; 
                temp = x; x = y; y = temp;
            }

            return x < 0 ? x + m : x;
        }

        ModInt inv() {
            return new ModInt(modInv(val, MOD));
        }

        ModInt pow(long p) {
            assert p >= 0;
            ModInt a = this, result = new ModInt(1);

            while (p > 0) {
                if ((p & 1) == 1)
                    result = result.mul(a);

                a = a.mul(a);
                p >>= 1;
            }

            return result;
        }

        ModInt add(ModInt other) {
            val += other.val;
            if (val >= MOD) val -= MOD;
            return this;
        }

        ModInt sub(ModInt other) {
            val -= other.val;
            if (val < 0) val += MOD;
            return this;
        }

        ModInt mul(ModInt other) {
            val = fastMod((long) val * other.val);
            return this;
        }

        ModInt div(ModInt other) {
            return this.mul(other.inv());
        }

        static int fastMod(long x) {
            return (int) (x % MOD);
        }

        @Override
        public String toString() {
            return String.valueOf(val);
        }
    }

    static class SegmentChange {
        static final int id5 = Integer.MIN_VALUE;
        int setMin, setMax;

        SegmentChange(int _setMin, int _setMax) {
            setMin = _setMin;
            setMax = _setMax;
        }

        SegmentChange() {
            reset();
        }

        void reset() {
            setMin = setMax = id5;
        }

        boolean hasSetMin() {
            return setMin != id5;
        }

        boolean hasSetMax() {
            return setMax != id5;
        }

        boolean hasChange() {
            return hasSetMin() || hasSetMax();
        }

        SegmentChange combine(SegmentChange other) {
            return new SegmentChange(other.hasSetMin() ? other.setMin : setMin,
                                     other.hasSetMax() ? other.setMax : setMax);
        }
    }

    static class Segment {
        ModInt LProduct, RProduct, sum;
        int minimum, maximum;

        Segment(ModInt _L, ModInt _R, ModInt _sum, int _minimum, int _maximum) {
            LProduct = _L;
            RProduct = _R;
            sum = _sum;
            minimum = _minimum;
            maximum = _maximum;
        }

        Segment() {
            this(new ModInt(1), new ModInt(1), new ModInt(1), Integer.MAX_VALUE, Integer.MIN_VALUE);
        }

        void apply(int length, SegmentChange change) {
            if (change.hasSetMin())
                minimum = change.setMin;

            if (change.hasSetMax())
                maximum = change.setMax;
        }

        void join(Segment other) {
            sum = sum.mul(other.RProduct).add(LProduct.mul(other.sum)).sub(LProduct.mul(other.RProduct));
            LProduct = LProduct.mul(other.LProduct);
            RProduct = RProduct.mul(other.RProduct);
            minimum = Math.min(minimum, other.minimum);
            maximum = Math.max(maximum, other.maximum);
        }

        void join(Segment a, Segment b) {
            this.LProduct = a.LProduct;
            join(b);
        }
    }

    static class SegTree {
        int treeN = 0;
        List<Segment> tree;
        List<SegmentChange> changes;

        SegTree(int n) {
            if (n >= 0)
                init(n);
        }

        void init(int n) {
            treeN = 1;

            while (treeN < n)
                treeN *= 2;

            tree = new ArrayList<>(Collections.nCopies(2 * treeN, new Segment()));
            changes = new ArrayList<>(Collections.nCopies(treeN, new SegmentChange()));
        }

        void build(List<Segment> initial) {
            int n = initial.size();
            init(n);
            assert n <= treeN;

            for (int i = 0; i < n; i++)
                tree.set(treeN + i, initial.get(i));

            for (int position = treeN - 1; position > 0; position--)
                tree.get(position).join(tree.get(2 * position), tree.get(2 * position + 1));
        }

        void pushDown(int position, int length) {
            if (!changes.get(position).hasChange())
                return;

            if (2 * position < treeN) {
                changes.set(2 * position, changes.get(2 * position).combine(changes.get(position)));
                changes.set(2 * position + 1, changes.get(2 * position + 1).combine(changes.get(position)));
            }

            tree.get(2 * position).apply(length / 2, changes.get(position));
            tree.get(2 * position + 1).apply(length / 2, changes.get(position));
            changes.get(position).reset();
        }

        void pushAll(int a, int b) {
            assert 0 <= a && a < b && b <= treeN;
            a += treeN;
            b += treeN - 1;

            for (int up = 31 - Integer.numberOfLeadingZeros(treeN); up > 0; up--) {
                int x = a >> up, y = b >> up;
                pushDown(x, 1 << up);
                if (x != y) pushDown(y, 1 << up);
            }
        }

        void joinAndApply(int position, int length) {
            tree.get(position).join(tree.get(2 * position), tree.get(2 * position + 1));
            tree.get(position).apply(length, changes.get(position));
        }

        void joinAll(int a, int b) {
            assert 0 <= a && a < b && b <= treeN;
            a += treeN;
            b += treeN - 1;
            int length = 1;

            while (a > 1) {
                a /= 2;
                b /= 2;
                length *= 2;
                joinAndApply(a, length);
                if (a != b) joinAndApply(b, length);
            }
        }

        void processRange(int a, int b, boolean needsJoin, Consumer<Integer> rangeOp) {
            if (a == b) return;
            pushAll(a, b);
            int originalA = a, originalB = b;
            int length = 1, rSize = 0;
            int[][] rightHalf = new int[32][2];

            for (a += treeN, b += treeN; a < b; a /= 2, b /= 2, length *= 2) {
                if ((a & 1) == 1)
                    rangeOp.accept(a++);

                if ((b & 1) == 1)
                    rightHalf[rSize++] = new int[]{--b, length};
            }

            for (int i = rSize - 1; i >= 0; i--)
                rangeOp.accept(rightHalf[i][0]);

            if (needsJoin)
                joinAll(originalA, originalB);
        }

        Segment query(int a, int b) {
            assert 0 <= a && a <= b && b <= treeN;
            Segment answer = new Segment();

            processRange(a, b, false, position -> {
                answer.join(tree.get(position));
            });

            return answer;
        }

        void update(int a, int b, SegmentChange change) {
            assert 0 <= a && a <= b && b <= treeN;

            processRange(a, b, true, position -> {
                tree.get(position).apply(b - a, change);

                if (position < treeN)
                    changes.set(position, changes.get(position).combine(change));
            });
        }
    }

    static class Event implements Comparable<Event> {
        long distance, velocity;
        int index, type;

        Event(long _distance, long _velocity, int _index, int _type) {
            assert _distance >= 0 && _velocity > 0;
            distance = _distance;
            velocity = _velocity;
            index = _index;
            type = _type;
        }

        ModInt getTime() {
            return new ModInt(distance).div(new ModInt(velocity));
        }

        @Override
        public int compareTo(Event other) {
            return Long.compare(distance * other.velocity, other.distance * velocity);
        }
    }

    static final ModInt INV100 = new ModInt(100).inv();
    static int N;
    static List<Integer> X = new ArrayList<>();
    static List<Integer> V = new ArrayList<>();
    static List<ModInt> L = new ArrayList<>();
    static List<ModInt> R = new ArrayList<>();
    static List<Event> events = new ArrayList<>();
    static SegTree tree;
    static ModInt currentProbability;
    static String status;

    static int id4(int x) {
        return tree.query(x, x + 1).minimum;
    }

    static int id2(int x) {
        return tree.query(x, x + 1).maximum;
    }

    static boolean id3(int x, int y) {
        assert x <= y;
        return y <= id2(x);
    }

    static ModInt id1(int index, char direction) {
        if (status.charAt(index) == direction)
            return new ModInt(1);

        if (status.charAt(index) != '?' && status.charAt(index) != direction)
            return new ModInt(0);

        assert status.charAt(index) == '?';
        int minimum = id4(index), maximum = id2(index);

        if (direction == 'L') {
            ModInt left = tree.query(minimum, index + 1).LProduct;
            ModInt right = tree.query(index + 1, maximum + 1).sum;
            ModInt before = tree.query(minimum, maximum + 1).sum;
            return left.mul(right).div(before);
        } else if (direction == 'R') {
            ModInt left = tree.query(minimum, index).sum;
            ModInt right = tree.query(index, maximum + 1).RProduct;
            ModInt before = tree.query(minimum, maximum + 1).sum;
            return left.mul(right).div(before);
        }

        assert false;
        return null;
    }

    static void connectFinal(int x, int y) {
        assert y - x == 1;

        if (status.charAt(x) == 'L' || status.charAt(y) == 'R')
            return;

        if (status.charAt(x) == 'R' && status.charAt(y) == 'L') {
            currentProbability = new ModInt(0);
            return;
        }

        assert id2(x) == x && id4(y) == y;
        int xMin = id4(x);
        int yMax = id2(y);

        if (status.charAt(x) == 'R') {
            for (int i = y; i <= yMax; i++) {
                assert status.charAt(i) == '?';
                status = status.substring(0, i) + 'R' + status.substring(i + 1);
            }

            Segment ySeg = tree.query(y, yMax + 1);
            currentProbability = currentProbability.mul(ySeg.RProduct.div(ySeg.sum));
            return;
        }

        if (status.charAt(y) == 'L') {
            for (int i = xMin; i <= x; i++) {
                assert status.charAt(i) == '?';
                status = status.substring(0, i) + 'L' + status.substring(i + 1);
            }

            Segment xSeg = tree.query(xMin, x + 1);
            currentProbability = currentProbability.mul(xSeg.LProduct.div(xSeg.sum));
            return;
        }

        assert status.charAt(x) == '?' && status.charAt(y) == '?';
        tree.update(xMin, yMax + 1, new SegmentChange(xMin, yMax));
        currentProbability = currentProbability.mul(tree.query(xMin, yMax + 1).sum.div(tree.query(xMin, x + 1).sum.mul(tree.query(y, yMax + 1).sum)));
    }

    static void setFinal(int index, char direction) {
        if (status.charAt(index) != '?') {
            if (status.charAt(index) != direction)
                currentProbability = new ModInt(0);

            return;
        }

        assert status.charAt(index) == '?';
        int minimum = id4(index);
        int maximum = id2(index);

        if (direction == 'L') {
            currentProbability = currentProbability.mul(id1(index, 'L'));
            tree.update(index + 1, maximum + 1, new SegmentChange(index + 1, maximum));

            for (int i = minimum; i <= index; i++) {
                assert status.charAt(i) == '?';
                status = status.substring(0, i) + 'L' + status.substring(i + 1);
            }
        } else if (direction == 'R') {
            currentProbability = currentProbability.mul(id1(index, 'R'));
            tree.update(minimum, index, new SegmentChange(minimum, index - 1));

            for (int i = index; i <= maximum; i++) {
                assert status.charAt(i) == '?';
                status = status.substring(0, i) + 'R' + status.substring(i + 1);
            }
        } else {
            assert false;
        }
    }

    static void id0() {
        for (int i = 0; i < N; i++)
            if (status.charAt(i) == '?') {
                int minimum = id4(i);
                int maximum = id2(i);

                for (int j = minimum; j <= maximum; j++)
                    assert status.charAt(j) == '?';
            }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        N = scanner.nextInt();
        for (int i = 0; i < N; i++) {
            X.add(scanner.nextInt());
            V.add(scanner.nextInt());
            int P = scanner.nextInt();
            R.add(new ModInt(P).mul(INV100));
            L.add(new ModInt(1).sub(R.get(i)));
        }

        tree = new SegTree(N);
        List<Segment> initial = new ArrayList<>();

        for (int i = 0; i < N; i++)
            initial.add(new Segment(L.get(i), R.get(i), new ModInt(1), i, i));

        tree.build(initial);
        status = "?".repeat(N);

        for (int i = 0; i < N - 1; i++) {
            long distance = X.get(i + 1) - X.get(i);
            events.add(new Event(distance, V.get(i) + V.get(i + 1), i, 0));

            if (V.get(i) > V.get(i + 1))
                events.add(new Event(distance, V.get(i) - V.get(i + 1), i, +1));
            else if (V.get(i + 1) > V.get(i))
                events.add(new Event(distance, V.get(i + 1) - V.get(i), i + 1, -1));
        }

        Collections.sort(events);
        currentProbability = new ModInt(1);
        ModInt total = new ModInt(0);

        for (Event ev : events) {
            if (ev.type == 0) {
                int x = ev.index, y = ev.index + 1;
                assert !id3(x, y);
                ModInt probability = currentProbability.mul(id1(x, 'R')).mul(id1(y, 'L'));
                total = total.add(probability.mul(ev.getTime()));
                connectFinal(x, y);
            } else {
                assert Math.abs(ev.type) == 1;
                int x = ev.index;
                char direction = ev.type > 0 ? 'R' : 'L';
                char opposite = (char) ('L' + 'R' - direction);
                ModInt probability = currentProbability.mul(id1(x, direction));
                total = total.add(probability.mul(ev.getTime()));
                setFinal(x, opposite);
            }

            if (currentProbability.val == 0)
                break;
        }

        System.out.println(total);
    }
}
