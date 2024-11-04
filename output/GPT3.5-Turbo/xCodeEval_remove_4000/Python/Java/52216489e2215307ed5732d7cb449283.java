import java.util.*;
import java.io.*;

class Main {
    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }

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
            key = k;
            value = v;
            left = null;
            right = null;
            parent = null;
            height = 1;
            num_left = 1;
            num_total = 1;
        }
    }

    static class AVLTree {
        TreeNode _tree;

        public AVLTree() {
            _tree = null;
        }

        public void add(int k, int v) {
            if (_tree == null) {
                _tree = new TreeNode(k, v);
                return;
            }
            TreeNode node = _add(k, v);
            if (node != null) {
                _rebalance(node);
            }
        }

        private TreeNode _add(int k, int v) {
            TreeNode node = _tree;
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

        private int getSize(TreeNode x) {
            return x != null ? x.num_total : 0;
        }

        private void _rebalance(TreeNode node) {
            TreeNode n = node;
            while (n != null) {
                int lh = getHeight(n.left);
                int rh = getHeight(n.right);
                n.height = Math.max(lh, rh) + 1;
                int balance_factor = lh - rh;
                n.num_total = 1 + getSize(n.left) + getSize(n.right);
                n.num_left = 1 + getSize(n.left);

                if (balance_factor > 1) {
                    if (getHeight(n.left.left) < getHeight(n.left.right)) {
                        _rotateLeft(n.left);
                    }
                    _rotateRight(n);
                } else if (balance_factor < -1) {
                    if (getHeight(n.right.right) < getHeight(n.right.left)) {
                        _rotateRight(n.right);
                    }
                    _rotateLeft(n);
                } else {
                    n = n.parent;
                }
            }
        }

        private void _removeOne(TreeNode node) {
            TreeNode replacement = node.left != null ? node.left : node.right;
            if (node.parent != null) {
                if (isLeft(node)) {
                    node.parent.left = replacement;
                } else {
                    node.parent.right = replacement;
                }
                if (replacement != null) {
                    replacement.parent = node.parent;
                }
                node.parent = null;
            } else {
                _tree = replacement;
                if (replacement != null) {
                    replacement.parent = null;
                }
            }
            node.left = null;
            node.right = null;
            node.parent = null;
            _rebalance(replacement);
        }

        private void _removeLeaf(TreeNode node) {
            if (node.parent != null) {
                if (isLeft(node)) {
                    node.parent.left = null;
                } else {
                    node.parent.right = null;
                }
                _rebalance(node.parent);
            } else {
                _tree = null;
            }
            node.parent = null;
            node.left = null;
            node.right = null;
        }

        public void remove(int k) {
            TreeNode node = _getNode(k);
            if (node == null) {
                return;
            }
            if (isLeaf(node)) {
                _removeLeaf(node);
                return;
            }
            if (node.left != null && node.right != null) {
                TreeNode nxt = _getNext(node);
                node.key = nxt.key;
                node.value = nxt.value;
                if (isLeaf(nxt)) {
                    _removeLeaf(nxt);
                } else {
                    _removeOne(nxt);
                }
                _rebalance(node);
            } else {
                _removeOne(node);
            }
        }

        public int get(int k) {
            TreeNode node = _getNode(k);
            return node != null ? node.value : -1;
        }

        private TreeNode _getNode(int k) {
            if (_tree == null) {
                return null;
            }
            TreeNode node = _tree;
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

        public int getAt(int pos) {
            int x = pos + 1;
            TreeNode node = _tree;
            while (node != null) {
                if (x < node.num_left) {
                    node = node.left;
                } else if (node.num_left < x) {
                    x -= node.num_left;
                    node = node.right;
                } else {
                    return node.key;
                }
            }
            throw new IndexOutOfBoundsException("Out of ranges");
        }

        private boolean isLeft(TreeNode node) {
            return node.parent != null && node.parent.left != null && node.parent.left == node;
        }

        private boolean isLeaf(TreeNode node) {
            return node.left == null && node.right == null;
        }

        private void _rotateRight(TreeNode node) {
            if (node.parent == null) {
                _tree = node.right;
                node.right.parent = null;
            } else if (isLeft(node)) {
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
            node.height = Math.max(getHeight(node.left), getHeight(node.right)) + 1;
            node.num_total = 1 + getSize(node.left) + getSize(node.right);
            node.num_left = 1 + getSize(node.left);
        }

        private void _rotateLeft(TreeNode node) {
            if (node.parent == null) {
                _tree = node.left;
                node.left.parent = null;
            } else if (isLeft(node)) {
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
            node.height = Math.max(getHeight(node.left), getHeight(node.right)) + 1;
            node.num_total = 1 + getSize(node.left) + getSize(node.right);
            node.num_left = 1 + getSize(node.left);
        }

        private TreeNode _getNext(TreeNode node) {
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

    static class SegmentTree {
        int[] data;
        int _default;
        int _len;
        int _size;
        BiFunction<Integer, Integer, Integer> _func;

        public SegmentTree(int[] data, int defaultVal, BiFunction<Integer, Integer, Integer> func) {
            _default = defaultVal;
            _func = func;
            _len = data.length;
            _size = (int) Math.pow(2, Math.ceil(Math.log(_len) / Math.log(2)));

            this.data = new int[2 * _size];
            Arrays.fill(this.data, _default);
            System.arraycopy(data, 0, this.data, _size, _len);
            for (int i = _size - 1; i >= 1; i--) {
                this.data[i] = _func.apply(this.data[2 * i], this.data[2 * i + 1]);
            }
        }

        public void update(int idx, int value) {
            idx += _size;
            data[idx] = value;
            idx >>= 1;
            while (idx >= 1) {
                data[idx] = _func.apply(data[2 * idx], data[2 * idx + 1]);
                idx >>= 1;
            }
        }

        public int query(int start, int stop) {
            if (start == stop) {
                return data[start + _size];
            }
            stop += 1;
            start += _size;
            stop += _size;

            int res = _default;
            while (start < stop) {
                if ((start & 1) == 1) {
                    res = _func.apply(res, data[start]);
                    start += 1;
                }
                if ((stop & 1) == 1) {
                    stop -= 1;
                    res = _func.apply(res, data[stop]);
                }
                start >>= 1;
                stop >>= 1;
            }
            return res;
        }
    }

    static class Factorial {
        int MOD;
        int[] factorials;
        int[] invModulos;
        int[] invFactorial_;

        public Factorial(int MOD) {
            this.MOD = MOD;
            factorials = new int[]{1, 1};
            invModulos = new int[]{0, 1};
            invFactorial_ = new int[]{1, 1};
        }

        public int calc(int n) {
            if (n <= -1) {
                System.out.println("Invalid argument to calculate n!");
                System.out.println("n must be non-negative value. But the argument was " + n);
                System.exit(0);
            }
            if (n < factorials.length) {
                return factorials[n];
            }
            int[] nextArr = new int[n + 1 - factorials.length];
            int initialI = factorials.length;
            int prev = factorials[factorials.length - 1];
            int m = MOD;
            for (int i = initialI; i <= n; i++) {
                prev = nextArr[i - initialI] = (int) ((long) prev * i % m);
            }
            factorials = Arrays.copyOf(factorials, factorials.length + nextArr.length);
            System.arraycopy(nextArr, 0, factorials, factorials.length - nextArr.length, nextArr.length);
            return factorials[n];
        }

        public int inv(int n) {
            if (n <= -1) {
                System.out.println("Invalid argument to calculate n^(-1)");
                System.out.println("n must be non-negative value. But the argument was " + n);
                System.exit(0);
            }
            int p = MOD;
            int pi = n % p;
            if (pi < invModulos.length) {
                return invModulos[pi];
            }
            int[] nextArr = new int[n + 1 - invModulos.length];
            int initialI = invModulos.length;
            for (int i = initialI; i < Math.min(p, n + 1); i++) {
                int next = (int) ((long) -invModulos[p % i] * (p / i) % p);
                invModulos = Arrays.copyOf(invModulos, invModulos.length + 1);
                invModulos[i] = next;
            }
            return invModulos[pi];
        }

        public int invFactorial(int n) {
            if (n <= -1) {
                System.out.println("Invalid argument to calculate (n^(-1))!");
                System.out.println("n must be non-negative value. But the argument was " + n);
                System.exit(0);
            }
            if (n < invFactorial_.length) {
                return invFactorial_[n];
            }
            inv(n);
            int[] nextArr = new int[n + 1 - invFactorial_.length];
            int initialI = invFactorial_.length;
            int prev = invFactorial_[invFactorial_.length - 1];
            int p = MOD;
            for (int i = initialI; i <= n; i++) {
                prev = nextArr[i - initialI] = (int) ((long) prev * invModulos[i % p] % p);
            }
            invFactorial_ = Arrays.copyOf(invFactorial_, invFactorial_.length + nextArr.length);
            System.arraycopy(nextArr, 0, invFactorial_, invFactorial_.length - nextArr.length, nextArr.length);
            return invFactorial_[n];
        }
    }

    static class Combination {
        int MOD;
        Factorial factorial;

        public Combination(int MOD) {
            this.MOD = MOD;
            factorial = new Factorial(MOD);
        }

        public int ncr(int n, int k) {
            if (k < 0 || n < k) {
                return 0;
            }
            k = Math.min(k, n - k);
            return (int) ((long) factorial.calc(n) * factorial.invFactorial(Math.max(n - k, k)) % MOD * factorial.invFactorial(Math.min(k, n - k)) % MOD);
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
        List<Pair<Integer, T>> id5 = new ArrayList<>();
        for (int i = 0; i < list1.size(); i++) {
            id5.add(new Pair<>(list2.get(i), list1.get(i)));
        }
        id5.sort(Comparator.comparingInt(Pair::getKey));

        List<T> z = new ArrayList<>();
        for (Pair<Integer, T> pair : id5) {
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

    static int id9(int[] arr, int n, int key) {
        int left = 0;
        int right = n - 1;

        int count = 0;

        while (left <= right) {
            int mid = (right + left) / 2;

            if (arr[mid] < key) {
                count = mid + 1;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return count;
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

        return (n - leftGreater);
    }

    static int countdig(int n) {
        int c = 0;
        while (n > 0) {
            n /= 10;
            c += 1;
        }
        return c;
    }

    static String binary(int x, int length) {
        String y = Integer.toBinaryString(x);
        return y.length() >= length ? y : "0".repeat(length - y.length()) + y;
    }

    static int countGreater(List<Integer> arr, int n, int k) {
        int l = 0;
        int r = n - 1;

        int leftGreater = n;

        while (l <= r) {
            int m = l + (r - l) / 2;
            if (arr.get(m) >= k) {
                leftGreater = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        return (n - leftGreater);
    }

    public static void main(String[] args) {
        FastReader sc = new FastReader();
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[] cnt = new int[m + 1];
        for (int i = 0; i < n; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            cnt[a - 1]++;
            cnt[b]--;
        }
        for (int i = 1; i <= m; i++) {
            cnt[i] += cnt[i - 1];
        }
        int[] l = new int[m];
        int[] l1 = new int[m];
        int[] fi = new int[m];
        int[] cur = new int[1];
        int[] cur1 = new int[1];
        int[] cou = new int[m];
        AVLTree tree = new AVLTree();
        AVLTree tree1 = new AVLTree();
        for (int i = 0; i < m; i++) {
            int mw = tree.query(0, tree._getNode(i)) + 1;
            l[tree._getNode(i)] = mw;
            fi[i] = mw;
            cur1[0] = Math.max(cur1[0], mw);
            tree.add(tree._getNode(i), mw);
        }
        for (int i = m - 1; i >= 0; i--) {
            int mw = tree1.query(0, tree1._getNode(i)) + 1;
            fi[i] += mw;
            l1[tree1._getNode(i)] = mw;
            tree1.add(tree1._getNode(i), mw);
        }
        System.out.println(Arrays.stream(fi).max().getAsInt() - 1);
    }
}
