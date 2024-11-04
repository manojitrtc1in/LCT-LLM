import java.util.*;

class Main {
    static class TreeNode {
        int key;
        int value;
        TreeNode left;
        TreeNode right;
        TreeNode parent;
        int height;
        int num_left;
        int num_total;

        public TreeNode(int k, int v) {
            this.key = k;
            this.value = v;
            this.left = null;
            this.right = null;
            this.parent = null;
            this.height = 1;
            this.num_left = 1;
            this.num_total = 1;
        }
    }

    static class AvlTree {
        private TreeNode _tree;

        public AvlTree() {
            this._tree = null;
        }

        public void add(int k, int v) {
            if (this._tree == null) {
                this._tree = new TreeNode(k, v);
                return;
            }
            TreeNode node = this._add(k, v);
            if (node != null) {
                this._rebalance(node);
            }
        }

        private TreeNode _add(int k, int v) {
            TreeNode node = this._tree;
            while (node != null) {
                if (k < node.key) {
                    if (node.left != null) {
                        node = node.left;
                    } else {
                        node.left = new TreeNode(k, v);
                        node.left.parent = node;
                        return node.left;
                    }
                } else if (node.key < k) {
                    if (node.right != null) {
                        node = node.right;
                    } else {
                        node.right = new TreeNode(k, v);
                        node.right.parent = node;
                        return node.right;
                    }
                } else {
                    node.value = v;
                    return null;
                }
            }
            return null;
        }

        private int getHeight(TreeNode x) {
            return x != null ? x.height : 0;
        }

        private int getNumTotal(TreeNode x) {
            return x != null ? x.num_total : 0;
        }

        private void _rebalance(TreeNode node) {
            TreeNode n = node;
            while (n != null) {
                int lh = this.getHeight(n.left);
                int rh = this.getHeight(n.right);
                n.height = Math.max(lh, rh) + 1;
                int balance_factor = lh - rh;
                n.num_total = 1 + this.getNumTotal(n.left) + this.getNumTotal(n.right);
                n.num_left = 1 + this.getNumTotal(n.left);

                if (balance_factor > 1) {
                    if (this.getHeight(n.left.left) < this.getHeight(n.left.right)) {
                        this._rotateLeft(n.left);
                    }
                    this._rotateRight(n);
                } else if (balance_factor < -1) {
                    if (this.getHeight(n.right.right) < this.getHeight(n.right.left)) {
                        this._rotateRight(n.right);
                    }
                    this._rotateLeft(n);
                } else {
                    n = n.parent;
                }
            }
        }

        private void _removeOne(TreeNode node) {
            TreeNode replacement = node.left != null ? node.left : node.right;
            if (node.parent != null) {
                if (this._isLeft(node)) {
                    node.parent.left = replacement;
                } else {
                    node.parent.right = replacement;
                }
                if (replacement != null) {
                    replacement.parent = node.parent;
                }
                node.parent = null;
            } else {
                this._tree = replacement;
                if (replacement != null) {
                    replacement.parent = null;
                }
            }
            node.left = null;
            node.right = null;
            node.parent = null;
            this._rebalance(replacement);
        }

        private void _removeLeaf(TreeNode node) {
            if (node.parent != null) {
                if (this._isLeft(node)) {
                    node.parent.left = null;
                } else {
                    node.parent.right = null;
                }
                this._rebalance(node.parent);
            } else {
                this._tree = null;
            }
            node.parent = null;
            node.left = null;
            node.right = null;
        }

        public void remove(int k) {
            TreeNode node = this._getNode(k);
            if (node == null) {
                return;
            }
            if (this._isLeaf(node)) {
                this._removeLeaf(node);
                return;
            }
            if (node.left != null && node.right != null) {
                TreeNode nxt = this._getNext(node);
                node.key = nxt.key;
                node.value = nxt.value;
                if (this._isLeaf(nxt)) {
                    this._removeLeaf(nxt);
                } else {
                    this._removeOne(nxt);
                }
                this._rebalance(node);
            } else {
                this._removeOne(node);
            }
        }

        public int get(int k) {
            TreeNode node = this._getNode(k);
            return node != null ? node.value : -1;
        }

        private TreeNode _getNode(int k) {
            if (this._tree == null) {
                return null;
            }
            TreeNode node = this._tree;
            while (node != null) {
                if (k < node.key) {
                    node = node.left;
                } else if (node.key < k) {
                    node = node.right;
                } else {
                    return node;
                }
            }
            return null;
        }

        public int[] getAt(int pos) {
            int x = pos + 1;
            TreeNode node = this._tree;
            while (node != null) {
                if (x < node.num_left) {
                    node = node.left;
                } else if (node.num_left < x) {
                    x -= node.num_left;
                    node = node.right;
                } else {
                    return new int[]{node.key, node.value};
                }
            }
            throw new IndexOutOfBoundsException("Out of ranges");
        }

        private static boolean _isLeft(TreeNode node) {
            return node.parent.left != null && node.parent.left == node;
        }

        private static boolean _isLeaf(TreeNode node) {
            return node.left == null && node.right == null;
        }

        private void _rotateRight(TreeNode node) {
            if (node.parent == null) {
                this._tree = node.left;
                node.left.parent = null;
            } else if (this._isLeft(node)) {
                node.parent.left = node.left;
                node.left.parent = node.parent;
            } else {
                node.parent.right = node.left;
                node.left.parent = node.parent;
            }
            TreeNode bk = node.left.right;
            node.left.right = node;
            node.parent = node.left;
            node.left = bk;
            if (bk != null) {
                bk.parent = node;
            }
            node.height = Math.max(this.getHeight(node.left), this.getHeight(node.right)) + 1;
            node.num_total = 1 + this.getNumTotal(node.left) + this.getNumTotal(node.right);
            node.num_left = 1 + this.getNumTotal(node.left);
        }

        private void _rotateLeft(TreeNode node) {
            if (node.parent == null) {
                this._tree = node.right;
                node.right.parent = null;
            } else if (this._isLeft(node)) {
                node.parent.left = node.right;
                node.right.parent = node.parent;
            } else {
                node.parent.right = node.right;
                node.right.parent = node.parent;
            }
            TreeNode bk = node.right.left;
            node.right.left = node;
            node.parent = node.right;
            node.right = bk;
            if (bk != null) {
                bk.parent = node;
            }
            node.height = Math.max(this.getHeight(node.left), this.getHeight(node.right)) + 1;
            node.num_total = 1 + this.getNumTotal(node.left) + this.getNumTotal(node.right);
            node.num_left = 1 + this.getNumTotal(node.left);
        }

        private static TreeNode _getNext(TreeNode node) {
            if (node.right == null) {
                return node.parent;
            }
            TreeNode n = node.right;
            while (n.left != null) {
                n = n.left;
            }
            return n;
        }
    }

    static class SegmentTree1 {
        private int[] data;
        private int _default;
        private int _len;
        private int _size;

        public SegmentTree1(int[] data, int defaultVal, IntBinaryOperator func) {
            this._default = defaultVal;
            this._len = data.length;
            this._size = (int) Math.pow(2, Math.ceil(Math.log(this._len) / Math.log(2)));

            this.data = new int[2 * this._size];
            Arrays.fill(this.data, this._default);
            System.arraycopy(data, 0, this.data, this._size, this._len);
            for (int i = this._size - 1; i >= 0; i--) {
                this.data[i] = func.applyAsInt(this.data[2 * i], this.data[2 * i + 1]);
            }
        }

        public void remove(int idx) {
            this.data[idx] = this._default;
            idx >>= 1;
            while (idx > 0) {
                this.data[idx] = this._func.applyAsInt(this.data[2 * idx], this.data[2 * idx + 1]);
                idx >>= 1;
            }
        }

        public int get(int idx) {
            return this.data[idx + this._size];
        }

        public void set(int idx, int value) {
            idx += this._size;
            this.data[idx] = value;
            idx >>= 1;
            while (idx > 0) {
                this.data[idx] = this._func.applyAsInt(this.data[2 * idx], this.data[2 * idx + 1]);
                idx >>= 1;
            }
        }

        public int query(int start, int stop) {
            if (start == stop) {
                return this.get(start);
            }
            stop++;
            start += this._size;
            stop += this._size;

            int res = this._default;
            while (start < stop) {
                if ((start & 1) == 1) {
                    res = this._func.applyAsInt(res, this.data[start]);
                    start++;
                }
                if ((stop & 1) == 1) {
                    stop--;
                    res = this._func.applyAsInt(res, this.data[stop]);
                }
                start >>= 1;
                stop >>= 1;
            }
            return res;
        }
    }

    static class SegmentTree {
        private int[] data;
        private int _default;
        private int _len;
        private int _size;

        public SegmentTree(int[] data, int defaultVal, IntBinaryOperator func) {
            this._default = defaultVal;
            this._len = data.length;
            this._size = (int) Math.pow(2, Math.ceil(Math.log(this._len) / Math.log(2)));

            this.data = new int[2 * this._size];
            Arrays.fill(this.data, this._default);
            System.arraycopy(data, 0, this.data, this._size, this._len);
            for (int i = this._size - 1; i >= 0; i--) {
                this.data[i] = func.applyAsInt(this.data[2 * i], this.data[2 * i + 1]);
            }
        }

        public void remove(int idx) {
            this.data[idx] = this._default;
            idx >>= 1;
            while (idx > 0) {
                this.data[idx] = this._func.applyAsInt(this.data[2 * idx], this.data[2 * idx + 1]);
                idx >>= 1;
            }
        }

        public int get(int idx) {
            return this.data[idx + this._size];
        }

        public void set(int idx, int value) {
            idx += this._size;
            this.data[idx] = value;
            idx >>= 1;
            while (idx > 0) {
                this.data[idx] = this._func.applyAsInt(this.data[2 * idx], this.data[2 * idx + 1]);
                idx >>= 1;
            }
        }

        public int query(int start, int stop) {
            if (start == stop) {
                return this.get(start);
            }
            stop++;
            start += this._size;
            stop += this._size;

            int res = this._default;
            while (start < stop) {
                if ((start & 1) == 1) {
                    res = this._func.applyAsInt(res, this.data[start]);
                    start++;
                }
                if ((stop & 1) == 1) {
                    stop--;
                    res = this._func.applyAsInt(res, this.data[stop]);
                }
                start >>= 1;
                stop >>= 1;
            }
            return res;
        }
    }

    static class Factorial {
        private int MOD;
        private int[] factorials;
        private int[] invModulos;
        private int[] invFactorial_;

        public Factorial(int MOD) {
            this.MOD = MOD;
            this.factorials = new int[]{1, 1};
            this.invModulos = new int[]{0, 1};
            this.invFactorial_ = new int[]{1, 1};
        }

        public int calc(int n) {
            if (n <= -1) {
                System.out.println("Invalid argument to calculate n!");
                System.out.println("n must be non-negative value. But the argument was " + n);
                System.exit(1);
            }
            if (n < this.factorials.length) {
                return this.factorials[n];
            }
            int[] nextArr = new int[n + 1 - this.factorials.length];
            int initialI = this.factorials.length;
            int prev = this.factorials[this.factorials.length - 1];
            int m = this.MOD;
            for (int i = initialI; i <= n; i++) {
                prev = nextArr[i - initialI] = (int) ((long) prev * i % m);
            }
            this.factorials = Arrays.copyOf(this.factorials, this.factorials.length + nextArr.length);
            System.arraycopy(nextArr, 0, this.factorials, initialI, nextArr.length);
            return this.factorials[n];
        }

        public int inv(int n) {
            if (n <= -1) {
                System.out.println("Invalid argument to calculate n^(-1)");
                System.out.println("n must be non-negative value. But the argument was " + n);
                System.exit(1);
            }
            int p = this.MOD;
            int pi = n % p;
            if (pi < this.invModulos.length) {
                return this.invModulos[pi];
            }
            int[] nextArr = new int[n + 1 - this.invModulos.length];
            int initialI = this.invModulos.length;
            for (int i = initialI; i < Math.min(p, n + 1); i++) {
                int next = (int) ((long) -this.invModulos[p % i] * (p / i) % p);
                this.invModulos = Arrays.copyOf(this.invModulos, this.invModulos.length + 1);
                this.invModulos[i] = next;
            }
            return this.invModulos[pi];
        }

        public int invFactorial(int n) {
            if (n <= -1) {
                System.out.println("Invalid argument to calculate (n^(-1))!");
                System.out.println("n must be non-negative value. But the argument was " + n);
                System.exit(1);
            }
            if (n < this.invFactorial_.length) {
                return this.invFactorial_[n];
            }
            this.inv(n);
            int[] nextArr = new int[n + 1 - this.invFactorial_.length];
            int initialI = this.invFactorial_.length;
            int prev = this.invFactorial_[this.invFactorial_.length - 1];
            int p = this.MOD;
            for (int i = initialI; i <= n; i++) {
                prev = nextArr[i - initialI] = (int) ((long) prev * this.invModulos[i % p] % p);
            }
            this.invFactorial_ = Arrays.copyOf(this.invFactorial_, this.invFactorial_.length + nextArr.length);
            System.arraycopy(nextArr, 0, this.invFactorial_, initialI, nextArr.length);
            return this.invFactorial_[n];
        }
    }

    static class Combination {
        private int MOD;
        private Factorial factorial;

        public Combination(int MOD) {
            this.MOD = MOD;
            this.factorial = new Factorial(MOD);
        }

        public int ncr(int n, int k) {
            if (k < 0 || n < k) {
                return 0;
            }
            k = Math.min(k, n - k);
            Factorial f = this.factorial;
            return (int) ((long) f.calc(n) * f.invFactorial(Math.max(n - k, k)) % this.MOD * f.invFactorial(Math.min(k, n - k)) % this.MOD);
        }
    }

    static int powm(int a, int n, int m) {
        if (a == 1 || n == 0) {
            return 1;
        }
        if (n % 2 == 0) {
            int s = powm(a, n / 2, m);
            return (int) ((long) s * s % m);
        } else {
            return (int) ((long) a * powm(a, n - 1, m) % m);
        }
    }

    static <T> List<T> sortList(List<T> list1, List<Integer> list2) {
        List<T> z = new ArrayList<>();
        List<Pair<Integer, T>> zippedPairs = new ArrayList<>();
        for (int i = 0; i < list1.size(); i++) {
            zippedPairs.add(new Pair<>(list2.get(i), list1.get(i)));
        }
        zippedPairs.sort(Comparator.comparingInt(Pair::getKey));
        for (Pair<Integer, T> pair : zippedPairs) {
            z.add(pair.getValue());
        }
        return z;
    }

    static long product(List<Long> l) {
        long por = 1;
        for (int i = 0; i < l.size(); i++) {
            por *= l.get(i);
        }
        return por;
    }

    static int binarySearchCount(int[] arr, int n, int key) {
        int left = 0;
        int right = n - 1;

        int count = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (arr[mid] < key) {
                count = mid + 1;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return count;
    }

    static int countdig(int n) {
        int c = 0;
        while (n > 0) {
            n /= 10;
            c++;
        }
        return c;
    }

    static String binary(int x, int length) {
        String y = Integer.toBinaryString(x);
        return y.length() >= length ? y : "0".repeat(length - y.length()) + y;
    }

    static int countGreater(int[] arr, int n, int k) {
        int l = 0;
        int r = n - 1;

        int leftGreater = n;

        while (l <= r) {
            int m = l + (r - l) / 2;
            if (arr[m] >= k) {
                leftGreater = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        return n - leftGreater;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        int[][] l = new int[n][5];
        for (int i = 0; i < n; i++) {
            String[] line = sc.nextLine().split(" ");
            for (int j = 0; j < 5; j++) {
                l[i][j] = Integer.parseInt(line[j]);
            }
        }
        if (n >= 50) {
            System.out.println(0);
            System.exit(0);
        }
        if (n <= 2) {
            System.out.println(n);
            for (int i = 0; i < n; i++) {
                System.out.println(i + 1);
            }
            System.exit(0);
        }
        Set<Integer> er = new HashSet<>();
        for (int i = 0; i < n; i++) {
            int f = 0;
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (i == j || i == k || j == k) {
                        continue;
                    }
                    int w = 0;
                    for (int d = 0; d < 5; d++) {
                        w += (l[i][d] - l[j][d]) * (l[i][d] - l[k][d]);
                    }
                    if (w > 0) {
                        f = 1;
                        break;
                    }
                }
                if (f == 1) {
                    break;
                }
            }
            if (f == 0) {
                er.add(i + 1);
            }
        }
        System.out.println(er.size());
        for (int x : er) {
            System.out.println(x);
        }
    }
}
