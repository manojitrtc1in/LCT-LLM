import java.util.*;
import java.io.*;

class Main {
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
                int temp = g;
                g = r;
                r = temp;
                x -= q * y;
                temp = x;
                x = y;
                y = temp;
            }

            return x < 0 ? x + m : x;
        }

        ModInt(int v) {
            this((long) v);
        }

        ModInt() {
            this(0);
        }

        ModInt add(ModInt other) {
            val += other.val;
            if (val >= MOD) val -= MOD;
            return this;
        }

        ModInt subtract(ModInt other) {
            val -= other.val;
            if (val < 0) val += MOD;
            return this;
        }

        ModInt multiply(ModInt other) {
            val = (int) ((long) val * other.val % MOD);
            return this;
        }

        ModInt divide(ModInt other) {
            return multiply(other.inverse());
        }

        ModInt increment() {
            val = val == MOD - 1 ? 0 : val + 1;
            return this;
        }

        ModInt decrement() {
            val = val == 0 ? MOD - 1 : val - 1;
            return this;
        }

        ModInt inverse() {
            return new ModInt(modInv(val, MOD));
        }

        ModInt power(long p) {
            ModInt a = new ModInt(val), result = new ModInt(1);

            while (p > 0) {
                if ((p & 1) == 1)
                    result.multiply(a);

                a.multiply(a);
                p >>= 1;
            }

            return result;
        }

        @Override
        public String toString() {
            return Integer.toString(val);
        }
    }

    static class SegmentChange {
        static final int SENTINEL = Integer.MIN_VALUE;

        int setMin, setMax;

        SegmentChange(int setMin, int setMax) {
            this.setMin = setMin;
            this.setMax = setMax;
        }

        SegmentChange() {
            this(SENTINEL, SENTINEL);
        }

        void reset() {
            setMin = setMax = SENTINEL;
        }

        boolean hasSetMin() {
            return setMin != SENTINEL;
        }

        boolean hasSetMax() {
            return setMax != SENTINEL;
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

        Segment(ModInt L, ModInt R, ModInt sum, int minimum, int maximum) {
            LProduct = L;
            RProduct = R;
            this.sum = sum;
            this.minimum = minimum;
            this.maximum = maximum;
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
            sum = sum.multiply(other.RProduct).add(LProduct.multiply(other.sum)).subtract(LProduct.multiply(other.RProduct));
            LProduct = LProduct.multiply(other.LProduct);
            RProduct = RProduct.multiply(other.RProduct);
            minimum = Math.min(minimum, other.minimum);
            maximum = Math.max(maximum, other.maximum);
        }

        void join(Segment a, Segment b) {
            this.LProduct = a.LProduct;
            this.RProduct = a.RProduct;
            this.sum = a.sum;
            this.minimum = a.minimum;
            this.maximum = a.maximum;
            join(b);
        }
    }

    static class SegTree {
        int treeN;
        Segment[] tree;
        SegmentChange[] changes;

        SegTree(int n) {
            treeN = 1;

            while (treeN < n)
                treeN *= 2;

            tree = new Segment[2 * treeN];
            changes = new SegmentChange[treeN];
        }

        void init(int n) {
            treeN = 1;

            while (treeN < n)
                treeN *= 2;

            tree = new Segment[2 * treeN];
            changes = new SegmentChange[treeN];
        }

        void build(List<Segment> initial) {
            int n = initial.size();
            init(n);
            assert n <= treeN;

            for (int i = 0; i < n; i++)
                tree[treeN + i] = initial.get(i);

            for (int position = treeN - 1; position > 0; position--)
                tree[position].join(tree[2 * position], tree[2 * position + 1]);
        }

        void pushDown(int position, int length) {
            if (!changes[position].hasChange())
                return;

            if (2 * position < treeN) {
                changes[2 * position] = changes[2 * position].combine(changes[position]);
                changes[2 * position + 1] = changes[2 * position + 1].combine(changes[position]);
            }

            tree[2 * position].apply(length / 2, changes[position]);
            tree[2 * position + 1].apply(length / 2, changes[position]);
            changes[position].reset();
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
            tree[position].join(tree[2 * position], tree[2 * position + 1]);
            tree[position].apply(length, changes[position]);
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

        interface RangeOp {
            void apply(int position, int length);
        }

        void processRange(int a, int b, boolean needsJoin, RangeOp rangeOp) {
            if (a == b) return;
            pushAll(a, b);
            int originalA = a, originalB = b;
            int length = 1;
            int rSize = 0;

            for (a += treeN, b += treeN; a < b; a /= 2, b /= 2, length *= 2) {
                if ((a & 1) == 1)
                    rangeOp.apply(a++, length);

                if ((b & 1) == 1)
                    rightHalf[rSize++] = new Pair(--b, length);
            }

            for (int i = rSize - 1; i >= 0; i--)
                rangeOp.apply(rightHalf[i].first, rightHalf[i].second);

            if (needsJoin)
                joinAll(originalA, originalB);
        }

        Segment query(int a, int b) {
            assert 0 <= a && a <= b && b <= treeN;
            Segment answer = new Segment();

            processRange(a, b, false, (position, length) -> {
                answer.join(tree[position]);
            });

            return answer;
        }

        void update(int a, int b, SegmentChange change) {
            assert 0 <= a && a <= b && b <= treeN;

            processRange(a, b, true, (position, length) -> {
                tree[position].apply(length, change);

                if (position < treeN)
                    changes[position] = changes[position].combine(change);
            });
        }
    }

    static class Event implements Comparable<Event> {
        long distance, velocity;
        int index, type;

        Event(long distance, long velocity, int index, int type) {
            this.distance = distance;
            this.velocity = velocity;
            this.index = index;
            this.type = type;
            assert distance >= 0 && velocity > 0;
        }

        ModInt getTime() {
            return new ModInt(distance).divide(new ModInt(velocity));
        }

        @Override
        public int compareTo(Event other) {
            return Long.compare(distance * other.velocity, other.distance * velocity);
        }
    }

    static final ModInt INV100 = new ModInt(100).inverse();

    static int N;
    static int[] X, V;
    static ModInt[] L, R;
    static List<Event> events;
    static SegTree tree;
    static ModInt currentProbability;
    static char[] status;

    static int getMinimum(int x) {
        return tree.query(x, x + 1).minimum;
    }

    static int getMaximum(int x) {
        return tree.query(x, x + 1).maximum;
    }

    static boolean inSameComponent(int x, int y) {
        assert x <= y;
        return y <= getMaximum(x);
    }

    static ModInt getChangeBySetting(int index, char direction) {
        if (status[index] == direction)
            return new ModInt(1);

        if (status[index] != '?' && status[index] != direction)
            return new ModInt(0);

        assert status[index] == '?';
        int minimum = getMinimum(index);
        int maximum = getMaximum(index);

        if (direction == 'L') {
            ModInt left = tree.query(minimum, index + 1).LProduct;
            ModInt right = tree.query(index + 1, maximum + 1).sum;
            ModInt before = tree.query(minimum, maximum + 1).sum;
            return left.multiply(right).divide(before);
        } else if (direction == 'R') {
            ModInt left = tree.query(minimum, index).sum;
            ModInt right = tree.query(index, maximum + 1).RProduct;
            ModInt before = tree.query(minimum, maximum + 1).sum;
            return left.multiply(right).divide(before);
        }

        throw new AssertionError();
    }

    static void connectFinal(int x, int y) {
        assert y - x == 1;

        if (status[x] == 'L' || status[y] == 'R')
            return;

        if (status[x] == 'R' && status[y] == 'L') {
            currentProbability = new ModInt(0);
            return;
        }

        assert getMaximum(x) == x && getMinimum(y) == y;
        int xMin = getMinimum(x);
        int yMax = getMaximum(y);

        if (status[x] == 'R') {
            for (int i = y; i <= yMax; i++) {
                assert status[i] == '?';
                status[i] = 'R';
            }

            currentProbability = currentProbability.multiply(tree.query(y, yMax + 1).RProduct.divide(tree.query(y, yMax + 1).sum));
            return;
        }

        if (status[y] == 'L') {
            for (int i = xMin; i <= x; i++) {
                assert status[i] == '?';
                status[i] = 'L';
            }

            currentProbability = currentProbability.multiply(tree.query(xMin, x + 1).LProduct.divide(tree.query(xMin, x + 1).sum));
            return;
        }

        assert status[x] == '?' && status[y] == '?';
        tree.update(xMin, yMax + 1, new SegmentChange(xMin, yMax));
        currentProbability = currentProbability.multiply(tree.query(xMin, yMax + 1).sum.divide(tree.query(xMin, x + 1).sum.multiply(tree.query(y, yMax + 1).sum)));
    }

    static void setFinal(int index, char direction) {
        if (status[index] != '?') {
            if (status[index] != direction)
                currentProbability = new ModInt(0);

            return;
        }

        assert status[index] == '?';
        int minimum = getMinimum(index);
        int maximum = getMaximum(index);

        if (direction == 'L') {
            currentProbability = currentProbability.multiply(getChangeBySetting(index, 'L'));
            tree.update(index + 1, maximum + 1, new SegmentChange(index + 1, maximum));

            for (int i = minimum; i <= index; i++) {
                assert status[i] == '?';
                status[i] = 'L';
            }
        } else if (direction == 'R') {
            currentProbability = currentProbability.multiply(getChangeBySetting(index, 'R'));
            tree.update(minimum, index, new SegmentChange(minimum, index - 1));

            for (int i = index; i <= maximum; i++) {
                assert status[i] == '?';
                status[i] = 'R';
            }
        } else {
            throw new AssertionError();
        }
    }

    static void checkValidity() {
        for (int i = 0; i < N; i++)
            if (status[i] == '?') {
                int minimum = getMinimum(i);
                int maximum = getMaximum(i);

                for (int j = minimum; j <= maximum; j++)
                    assert status[j] == '?';
            }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        X = new int[N];
        V = new int[N];
        L = new ModInt[N];
        R = new ModInt[N];

        StringTokenizer st;
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            X[i] = Integer.parseInt(st.nextToken());
            V[i] = Integer.parseInt(st.nextToken());
            int P = Integer.parseInt(st.nextToken());
            R[i] = new ModInt(P).multiply(INV100);
            L[i] = new ModInt(1).subtract(R[i]);
        }

        tree = new SegTree(N);
        List<Segment> initial = new ArrayList<>();
        for (int i = 0; i < N; i++)
            initial.add(new Segment(L[i], R[i], new ModInt(1), i, i));

        tree.build(initial);
        status = new char[N];
        Arrays.fill(status, '?');

        events = new ArrayList<>();
        for (int i = 0; i < N - 1; i++) {
            long distance = X[i + 1] - X[i];
            events.add(new Event(distance, V[i] + V[i + 1], i, 0));

            if (V[i] > V[i + 1])
                events.add(new Event(distance, V[i] - V[i + 1], i, +1));
            else if (V[i + 1] > V[i])
                events.add(new Event(distance, V[i + 1] - V[i], i + 1, -1));
        }

        Collections.sort(events);
        currentProbability = new ModInt(1);
        ModInt total = new ModInt(0);

        for (Event ev : events) {
            if (ev.type == 0) {
                int x = ev.index, y = ev.index + 1;
                assert !inSameComponent(x, y);
                ModInt probability = currentProbability.multiply(getChangeBySetting(x, 'R')).multiply(getChangeBySetting(y, 'L'));
                total = total.add(probability.multiply(ev.getTime()));
                connectFinal(x, y);
            } else {
                assert Math.abs(ev.type) == 1;
                int x = ev.index;
                char direction = ev.type > 0 ? 'R' : 'L';
                char opposite = (char) ('L' + 'R' - direction);
                ModInt probability = currentProbability.multiply(getChangeBySetting(x, direction));
                total = total.add(probability.multiply(ev.getTime()));
                setFinal(x, opposite);
            }

            if (currentProbability.val == 0)
                break;
        }

        System.out.println(total);
    }
}
