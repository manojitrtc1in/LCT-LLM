import java.util.*;
import java.io.*;

class Main {
    static final int MOD = 998244353;

    static class mod_int {
        int val;

        mod_int(long v) {
            if (v < 0) v = v % MOD + MOD;
            if (v >= MOD) v %= MOD;
            val = (int) v;
        }

        static int mod_inv(int a, int m) {
            int g = m, r = a, x = 0, y = 1;

            while (r != 0) {
                int q = g / r;
                g %= r;
                int temp = g;
                g = r;
                r = temp;
                x -= q * y;
                int temp2 = x;
                x = y;
                y = temp2;
            }

            return x < 0 ? x + m : x;
        }

        mod_int(int v) {
            this.val = v;
        }

        mod_int(long v) {
            if (v < 0) v = v % MOD + MOD;
            if (v >= MOD) v %= MOD;
            val = (int) v;
        }

        static int mod_inv(int a, int m) {
            int g = m, r = a, x = 0, y = 1;

            while (r != 0) {
                int q = g / r;
                g %= r;
                int temp = g;
                g = r;
                r = temp;
                x -= q * y;
                int temp2 = x;
                x = y;
                y = temp2;
            }

            return x < 0 ? x + m : x;
        }

        mod_int(int v) {
            this.val = v;
        }

        mod_int(long v) {
            if (v < 0) v = v % MOD + MOD;
            if (v >= MOD) v %= MOD;
            val = (int) v;
        }

        static int mod_inv(int a, int m) {
            int g = m, r = a, x = 0, y = 1;

            while (r != 0) {
                int q = g / r;
                g %= r;
                int temp = g;
                g = r;
                r = temp;
                x -= q * y;
                int temp2 = x;
                x = y;
                y = temp2;
            }

            return x < 0 ? x + m : x;
        }

        mod_int(int v) {
            this.val = v;
        }

        mod_int(long v) {
            if (v < 0) v = v % MOD + MOD;
            if (v >= MOD) v %= MOD;
            val = (int) v;
        }

        static int mod_inv(int a, int m) {
            int g = m, r = a, x = 0, y = 1;

            while (r != 0) {
                int q = g / r;
                g %= r;
                int temp = g;
                g = r;
                r = temp;
                x -= q * y;
                int temp2 = x;
                x = y;
                y = temp2;
            }

            return x < 0 ? x + m : x;
        }

        mod_int(int v) {
            this.val = v;
        }

        mod_int(long v) {
            if (v < 0) v = v % MOD + MOD;
            if (v >= MOD) v %= MOD;
            val = (int) v;
        }

        static int mod_inv(int a, int m) {
            int g = m, r = a, x = 0, y = 1;

            while (r != 0) {
                int q = g / r;
                g %= r;
                int temp = g;
                g = r;
                r = temp;
                x -= q * y;
                int temp2 = x;
                x = y;
                y = temp2;
            }

            return x < 0 ? x + m : x;
        }

        mod_int(int v) {
            this.val = v;
        }

        mod_int(long v) {
            if (v < 0) v = v % MOD + MOD;
            if (v >= MOD) v %= MOD;
            val = (int) v;
        }

        static int mod_inv(int a, int m) {
            int g = m, r = a, x = 0, y = 1;

            while (r != 0) {
                int q = g / r;
                g %= r;
                int temp = g;
                g = r;
                r = temp;
                x -= q * y;
                int temp2 = x;
                x = y;
                y = temp2;
            }

            return x < 0 ? x + m : x;
        }

        mod_int(int v) {
            this.val = v;
        }

        mod_int(long v) {
            if (v < 0) v = v % MOD + MOD;
            if (v >= MOD) v %= MOD;
            val = (int) v;
        }

        static int mod_inv(int a, int m) {
            int g = m, r = a, x = 0, y = 1;

            while (r != 0) {
                int q = g / r;
                g %= r;
                int temp = g;
                g = r;
                r = temp;
                x -= q * y;
                int temp2 = x;
                x = y;
                y = temp2;
            }

            return x < 0 ? x + m : x;
        }

        mod_int(int v) {
            this.val = v;
        }

        mod_int(long v) {
            if (v < 0) v = v % MOD + MOD;
            if (v >= MOD) v %= MOD;
            val = (int) v;
        }

        static int mod_inv(int a, int m) {
            int g = m, r = a, x = 0, y = 1;

            while (r != 0) {
                int q = g / r;
                g %= r;
                int temp = g;
                g = r;
                r = temp;
                x -= q * y;
                int temp2 = x;
                x = y;
                y = temp2;
            }

            return x < 0 ? x + m : x;
        }

        mod_int(int v) {
            this.val = v;
        }

        mod_int(long v) {
            if (v < 0) v = v % MOD + MOD;
            if (v >= MOD) v %= MOD;
            val = (int) v;
        }

        static int mod_inv(int a, int m) {
            int g = m, r = a, x = 0, y = 1;

            while (r != 0) {
                int q = g / r;
                g %= r;
                int temp = g;
                g = r;
                r = temp;
                x -= q * y;
                int temp2 = x;
                x = y;
                y = temp2;
            }

            return x < 0 ? x + m : x;
        }

        mod_int(int v) {
            this.val = v;
        }

        mod_int(long v) {
            if (v < 0) v = v % MOD + MOD;
            if (v >= MOD) v %= MOD;
            val = (int) v;
        }

        static int mod_inv(int a, int m) {
            int g = m, r = a, x = 0, y = 1;

            while (r != 0) {
                int q = g / r;
                g %= r;
                int temp = g;
                g = r;
                r = temp;
                x -= q * y;
                int temp2 = x;
                x = y;
                y = temp2;
            }

            return x < 0 ? x + m : x;
        }

        mod_int(int v) {
            this.val = v;
        }

        mod_int(long v) {
            if (v < 0) v = v % MOD + MOD;
            if (v >= MOD) v %= MOD;
            val = (int) v;
        }

        static int mod_inv(int a, int m) {
            int g = m, r = a, x = 0, y = 1;

            while (r != 0) {
                int q = g / r;
                g %= r;
                int temp = g;
                g = r;
                r = temp;
                x -= q * y;
                int temp2 = x;
                x = y;
                y = temp2;
            }

            return x < 0 ? x + m : x;
        }

        mod_int(int v) {
            this.val = v;
        }

        mod_int(long v) {
            if (v < 0) v = v % MOD + MOD;
            if (v >= MOD) v %= MOD;
            val = (int) v;
        }

        static int mod_inv(int a, int m) {
            int g = m, r = a, x = 0, y = 1;

            while (r != 0) {
                int q = g / r;
                g %= r;
                int temp = g;
                g = r;
                r = temp;
                x -= q * y;
                int temp2 = x;
                x = y;
                y = temp2;
            }

            return x < 0 ? x + m : x;
        }

        mod_int(int v) {
            this.val = v;
        }

        mod_int(long v) {
            if (v < 0) v = v % MOD + MOD;
            if (v >= MOD) v %= MOD;
            val = (int) v;
        }

        static int mod_inv(int a, int m) {
            int g = m, r = a, x = 0, y = 1;

            while (r != 0) {
                int q = g / r;
                g %= r;
                int temp = g;
                g = r;
                r = temp;
                x -= q * y;
                int temp2 = x;
                x = y;
                y = temp2;
            }

            return x < 0 ? x + m : x;
        }

        mod_int(int v) {
            this.val = v;
        }

        mod_int(long v) {
            if (v < 0) v = v % MOD + MOD;
            if (v >= MOD) v %= MOD;
            val = (int) v;
        }

        static int mod_inv(int a, int m) {
            int g = m, r = a, x = 0, y = 1;

            while (r != 0) {
                int q = g / r;
                g %= r;
                int temp = g;
                g = r;
                r = temp;
                x -= q * y;
                int temp2 = x;
                x = y;
                y = temp2;
            }

            return x < 0 ? x + m : x;
        }

        mod_int(int v) {
            this.val = v;
        }

        mod_int(long v) {
            if (v < 0) v = v % MOD + MOD;
            if (v >= MOD) v %= MOD;
            val = (int) v;
        }

        static int mod_inv(int a, int m) {
            int g = m, r = a, x = 0, y = 1;

            while (r != 0) {
                int q = g / r;
                g %= r;
                int temp = g;
                g = r;
                r = temp;
                x -= q * y;
                int temp2 = x;
                x = y;
                y = temp2;
            }

            return x < 0 ? x + m : x;
        }

        mod_int(int v) {
            this.val = v;
        }

        mod_int(long v) {
            if (v < 0) v = v % MOD + MOD;
            if (v >= MOD) v %= MOD;
            val = (int) v;
        }

        static int mod_inv(int a, int m) {
            int g = m, r = a, x = 0, y = 1;

            while (r != 0) {
                int q = g / r;
                g %= r;
                int temp = g;
                g = r;
                r = temp;
                x -= q * y;
                int temp2 = x;
                x = y;
                y = temp2;
            }

            return x < 0 ? x + m : x;
        }

        mod_int(int v) {
            this.val = v;
        }

        mod_int(long v) {
            if (v < 0) v = v % MOD + MOD;
            if (v >= MOD) v %= MOD;
            val = (int) v;
        }

        static int mod_inv(int a, int m) {
            int g = m, r = a, x = 0, y = 1;

            while (r != 0) {
                int q = g / r;
                g %= r;
                int temp = g;
                g = r;
                r = temp;
                x -= q * y;
                int temp2 = x;
                x = y;
                y = temp2;
            }

            return x < 0 ? x + m : x;
        }

        mod_int(int v) {
            this.val = v;
        }

        mod_int(long v) {
            if (v < 0) v = v % MOD + MOD;
            if (v >= MOD) v %= MOD;
            val = (int) v;
        }

        static int mod_inv(int a, int m) {
            int g = m, r = a, x = 0, y = 1;

            while (r != 0) {
                int q = g / r;
                g %= r;
                int temp = g;
                g = r;
                r = temp;
                x -= q * y;
                int temp2 = x;
                x = y;
                y = temp2;
            }

            return x < 0 ? x + m : x;
        }

        mod_int(int v) {
            this.val = v;
        }

        mod_int(long v) {
            if (v < 0) v = v % MOD + MOD;
            if (v >= MOD) v %= MOD;
            val = (int) v;
        }

        static int mod_inv(int a, int m) {
            int g = m, r = a, x = 0, y = 1;

            while (r != 0) {
                int q = g / r;
                g %= r;
                int temp = g;
                g = r;
                r = temp;
                x -= q * y;
                int temp2 = x;
                x = y;
                y = temp2;
            }

            return x < 0 ? x + m : x;
        }

        mod_int(int v) {
            this.val = v;
        }

        mod_int(long v) {
            if (v < 0) v = v % MOD + MOD;
            if (v >= MOD) v %= MOD;
            val = (int) v;
        }

        static int mod_inv(int a, int m) {
            int g = m, r = a, x = 0, y = 1;

            while (r != 0) {
                int q = g / r;
                g %= r;
                int temp = g;
                g = r;
                r = temp;
                x -= q * y;
                int temp2 = x;
                x = y;
                y = temp2;
            }

            return x < 0 ? x + m : x;
        }

        mod_int(int v) {
            this.val = v;
        }

        mod_int(long v) {
            if (v < 0) v = v % MOD + MOD;
            if (v >= MOD) v %= MOD;
            val = (int) v;
        }

        static int mod_inv(int a, int m) {
            int g = m, r = a, x = 0, y = 1;

            while (r != 0) {
                int q = g / r;
                g %= r;
                int temp = g;
                g = r;
                r = temp;
                x -= q * y;
                int temp2 = x;
                x = y;
                y = temp2;
            }

            return x < 0 ? x + m : x;
        }

        mod_int(int v) {
            this.val = v;
        }

        mod_int(long v) {
            if (v < 0) v = v % MOD + MOD;
            if (v >= MOD) v %= MOD;
            val = (int) v;
        }

        static int mod_inv(int a, int m) {
            int g = m, r = a, x = 0, y = 1;

            while (r != 0) {
                int q = g / r;
                g %= r;
                int temp = g;
                g = r;
                r = temp;
                x -= q * y;
                int temp2 = x;
                x = y;
                y = temp2;
            }

            return x < 0 ? x + m : x;
        }

        mod_int(int v) {
            this.val = v;
        }

        mod_int(long v) {
            if (v < 0) v = v % MOD + MOD;
            if (v >= MOD) v %= MOD;
            val = (int) v;
        }

        static int mod_inv(int a, int m) {
            int g = m, r = a, x = 0, y = 1;

            while (r != 0) {
                int q = g / r;
                g %= r;
                int temp = g;
                g = r;
                r = temp;
                x -= q * y;
                int temp2 = x;
                x = y;
                y = temp2;
            }

            return x < 0 ? x + m : x;
        }

        mod_int(int v) {
            this.val = v;
        }

        mod_int(long v) {
            if (v < 0) v = v % MOD + MOD;
            if (v >= MOD) v %= MOD;
            val = (int) v;
        }

        static int mod_inv(int a, int m) {
            int g = m, r = a, x = 0, y = 1;

            while (r != 0) {
                int q = g / r;
                g %= r;
                int temp = g;
                g = r;
                r = temp;
                x -= q * y;
                int temp2 = x;
                x = y;
                y = temp2;
            }

            return x < 0 ? x + m : x;
        }
    }

    static class segment_change {
        static final int id5 = Integer.MIN_VALUE;

        int set_min, set_max;

        segment_change(int set_min, int set_max) {
            this.set_min = set_min;
            this.set_max = set_max;
        }

        void reset() {
            set_min = id5;
            set_max = id5;
        }

        boolean has_set_min() {
            return set_min != id5;
        }

        boolean has_set_max() {
            return set_max != id5;
        }

        boolean has_change() {
            return has_set_min() || has_set_max();
        }

        segment_change combine(segment_change other) {
            return new segment_change(other.has_set_min() ? other.set_min : set_min,
                    other.has_set_max() ? other.set_max : set_max);
        }
    }

    static class segment {
        mod_int L_product, R_product, sum;
        int minimum, maximum;

        segment(mod_int L, mod_int R, mod_int sum, int minimum, int maximum) {
            this.L_product = L;
            this.R_product = R;
            this.sum = sum;
            this.minimum = minimum;
            this.maximum = maximum;
        }

        void apply(int length, segment_change change) {
            if (change.has_set_min())
                minimum = change.set_min;

            if (change.has_set_max())
                maximum = change.set_max;
        }

        void join(segment other) {
            sum = sum.multiply(other.R_product).add(L_product.multiply(other.sum)).subtract(L_product.multiply(other.R_product));
            L_product = L_product.multiply(other.L_product);
            R_product = R_product.multiply(other.R_product);
            minimum = Math.min(minimum, other.minimum);
            maximum = Math.max(maximum, other.maximum);
        }

        void join(segment a, segment b) {
            this.L_product = a.L_product;
            this.R_product = a.R_product;
            this.sum = a.sum;
            this.minimum = a.minimum;
            this.maximum = a.maximum;
            join(b);
        }
    }

    static class pair {
        int first, second;

        pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }

    static class seg_tree {
        int tree_n = 0;
        ArrayList<segment> tree;
        ArrayList<segment_change> changes;

        seg_tree(int n) {
            init(n);
        }

        void init(int n) {
            tree_n = 1;

            while (tree_n < n)
                tree_n *= 2;

            tree = new ArrayList<>(2 * tree_n);
            changes = new ArrayList<>(tree_n);

            for (int i = 0; i < 2 * tree_n; i++)
                tree.add(new segment());

            for (int i = 0; i < tree_n; i++)
                changes.add(new segment_change());
        }

        void build(ArrayList<segment> initial) {
            int n = initial.size();
            init(n);
            assert n <= tree_n;

            for (int i = 0; i < n; i++)
                tree.set(tree_n + i, initial.get(i));

            for (int position = tree_n - 1; position > 0; position--)
                tree.get(position).join(tree.get(2 * position), tree.get(2 * position + 1));
        }

        void push_down(int position, int length) {
            if (!changes.get(position).has_change())
                return;

            if (2 * position < tree_n) {
                changes.set(2 * position, changes.get(2 * position).combine(changes.get(position)));
                changes.set(2 * position + 1, changes.get(2 * position + 1).combine(changes.get(position)));
            }

            tree.get(2 * position).apply(length / 2, changes.get(position));
            tree.get(2 * position + 1).apply(length / 2, changes.get(position));
            changes.get(position).reset();
        }

        void push_all(int a, int b) {
            assert 0 <= a && a < b && b <= tree_n;
            a += tree_n;
            b += tree_n - 1;

            for (int up = 31 - Integer.numberOfLeadingZeros(tree_n); up > 0; up--) {
                int x = a >> up, y = b >> up;
                push_down(x, 1 << up);
                if (x != y) push_down(y, 1 << up);
            }
        }

        void join_and_apply(int position, int length) {
            tree.get(position).join(tree.get(2 * position), tree.get(2 * position + 1));
            tree.get(position).apply(length, changes.get(position));
        }

        void join_all(int a, int b) {
            assert 0 <= a && a < b && b <= tree_n;
            a += tree_n;
            b += tree_n - 1;
            int length = 1;

            while (a > 1) {
                a /= 2;
                b /= 2;
                length *= 2;
                join_and_apply(a, length);
                if (a != b) join_and_apply(b, length);
            }
        }

        void process_range(int a, int b, boolean needs_join, RangeOp range_op) {
            if (a == b) return;
            push_all(a, b);
            int original_a = a, original_b = b;
            int length = 1;
            int r_size = 0;

            for (a += tree_n, b += tree_n; a < b; a /= 2, b /= 2, length *= 2) {
                if ((a & 1) != 0)
                    range_op.apply(a++, length);

                if ((b & 1) != 0)
                    right_half[r_size++] = new pair(--b, length);
            }

            for (int i = r_size - 1; i >= 0; i--)
                range_op.apply(right_half[i].first, right_half[i].second);

            if (needs_join)
                join_all(original_a, original_b);
        }

        segment query(int a, int b) {
            assert 0 <= a && a <= b && b <= tree_n;
            segment answer = new segment();

            process_range(a, b, false, (position, length) -> {
                answer.join(tree.get(position));
            });

            return answer;
        }

        void update(int a, int b, segment_change change) {
            assert 0 <= a && a <= b && b <= tree_n;

            process_range(a, b, true, (position, length) -> {
                tree.get(position).apply(length, change);

                if (position < tree_n)
                    changes.set(position, changes.get(position).combine(change));
            });
        }
    }

    static class event implements Comparable<event> {
        long distance, velocity;
        int index, type;

        event(long distance, long velocity, int index, int type) {
            this.distance = distance;
            this.velocity = velocity;
            this.index = index;
            this.type = type;
            assert distance >= 0 && velocity > 0;
        }

        mod_int get_time() {
            return new mod_int(distance).divide(velocity);
        }

        public int compareTo(event other) {
            return Long.compare(distance * other.velocity, other.distance * velocity);
        }
    }

    static final mod_int INV100 = new mod_int(100).inv();

    static int N;
    static ArrayList<Integer> X, V;
    static ArrayList<mod_int> L, R;
    static ArrayList<event> events;
    static seg_tree tree;
    static mod_int current_probability;
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

    static mod_int id1(int index, char direction) {
        if (status.charAt(index) == direction)
            return new mod_int(1);

        if (status.charAt(index) != '?' && status.charAt(index) != direction)
            return new mod_int(0);

        assert status.charAt(index) == '?';
        int minimum = id4(index);
        int maximum = id2(index);

        if (direction == 'L') {
            mod_int left = tree.query(minimum, index + 1).L_product;
            mod_int right = tree.query(index + 1, maximum + 1).sum;
            mod_int before = tree.query(minimum, maximum + 1).sum;
            return left.multiply(right).divide(before);
        } else if (direction == 'R') {
            mod_int left = tree.query(minimum, index).sum;
            mod_int right = tree.query(index, maximum + 1).R_product;
            mod_int before = tree.query(minimum, maximum + 1).sum;
            return left.multiply(right).divide(before);
        }

        assert false;
        return new mod_int(0);
    }

    static void connect_final(int x, int y) {
        assert y - x == 1;

        if (status.charAt(x) == 'L' || status.charAt(y) == 'R')
            return;

        if (status.charAt(x) == 'R' && status.charAt(y) == 'L') {
            current_probability = new mod_int(0);
            return;
        }

        assert id2(x) == x && id4(y) == y;
        int x_min = id4(x);
        int y_max = id2(y);

        if (status.charAt(x) == 'R') {
            for (int i = y; i <= y_max; i++) {
                assert status.charAt(i) == '?';
                status = status.substring(0, i) + 'R' + status.substring(i + 1);
            }

            current_probability = current_probability.multiply(tree.query(y, y_max + 1).R_product).divide(tree.query(y, y_max + 1).sum);
            return;
        }

        if (status.charAt(y) == 'L') {
            for (int i = x_min; i <= x; i++) {
                assert status.charAt(i) == '?';
                status = status.substring(0, i) + 'L' + status.substring(i + 1);
            }

            current_probability = current_probability.multiply(tree.query(x_min, x + 1).L_product).divide(tree.query(x_min, x + 1).sum);
            return;
        }

        assert status.charAt(x) == '?' && status.charAt(y) == '?';
        tree.update(x_min, y_max + 1, new segment_change(x_min, y_max));
        current_probability = current_probability.multiply(tree.query(x_min, y_max + 1).sum).divide(tree.query(x_min, x + 1).sum.multiply(tree.query(y, y_max + 1).sum));
    }

    static void set_final(int index, char direction) {
        if (status.charAt(index) != '?') {
            if (status.charAt(index) != direction)
                current_probability = new mod_int(0);

            return;
        }

        assert status.charAt(index) == '?';
        int minimum = id4(index);
        int maximum = id2(index);

        if (direction == 'L') {
            current_probability = current_probability.multiply(id1(index, 'L'));
            tree.update(index + 1, maximum + 1, new segment_change(index + 1, maximum));

            for (int i = minimum; i <= index; i++) {
                assert status.charAt(i) == '?';
                status = status.substring(0, i) + 'L' + status.substring(i + 1);
            }
        } else if (direction == 'R') {
            current_probability = current_probability.multiply(id1(index, 'R'));
            tree.update(minimum, index, new segment_change(minimum, index - 1));

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

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        N = Integer.parseInt(br.readLine());
        X = new ArrayList<>();
        V = new ArrayList<>();
        L = new ArrayList<>();
        R = new ArrayList<>();

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            X.add(Integer.parseInt(st.nextToken()));
        }

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            V.add(Integer.parseInt(st.nextToken()));
        }

        for (int i = 0; i < N; i++) {
            int P = Integer.parseInt(br.readLine());
            R.add(new mod_int(P).multiply(INV100));
            L.add(new mod_int(1).subtract(R.get(i)));
        }

        tree = new seg_tree(N);
        ArrayList<segment> initial = new ArrayList<>();

        for (int i = 0; i < N; i++)
            initial.add(new segment(L.get(i), R.get(i), new mod_int(1), i, i));

        tree.build(initial);
        status = "?".repeat(N);
        events = new ArrayList<>();

        for (int i = 0; i < N - 1; i++) {
            long distance = X.get(i + 1) - X.get(i);
            events.add(new event(distance, V.get(i) + V.get(i + 1), i, 0));

            if (V.get(i) > V.get(i + 1))
                events.add(new event(distance, V.get(i) - V.get(i + 1), i, +1));
            else if (V.get(i + 1) > V.get(i))
                events.add(new event(distance, V.get(i + 1) - V.get(i), i + 1, -1));
        }

        Collections.sort(events);
        current_probability = new mod_int(1);
        mod_int total = new mod_int(0);

        for (event ev : events) {
            if (ev.type == 0) {
                int x = ev.index, y = ev.index + 1;
                assert !id3(x, y);
                mod_int probability = current_probability.multiply(id1(x, 'R')).multiply(id1(y, 'L'));
                total = total.add(probability.multiply(ev.get_time()));
                connect_final(x, y);
            } else {
                assert Math.abs(ev.type) == 1;
                int x = ev.index;
                char direction = ev.type > 0 ? 'R' : 'L';
                char opposite = (char) ('L' + 'R' - direction);
                mod_int probability = current_probability.multiply(id1(x, direction));
                total = total.add(probability.multiply(ev.get_time()));
                set_final(x, opposite);
            }

            if (current_probability.equals(new mod_int(0)))
                break;

            id0();
        }

        System.out.println(total);
    }

    interface RangeOp {
        void apply(int position, int length);
    }

    static pair[] right_half = new pair[32];
}
