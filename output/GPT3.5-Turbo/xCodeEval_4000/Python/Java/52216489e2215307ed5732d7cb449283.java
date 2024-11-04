import java.io.*;
import java.util.*;

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

    static class AvlTree {
        TreeNode _tree;

        public AvlTree() {
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
            return (x != null) ? x.height : 0;
        }

        private int getNumTotal(TreeNode x) {
            return (x != null) ? x.num_total : 0;
        }

        private void _rebalance(TreeNode node) {
            TreeNode n = node;
            while (n != null) {
                int lh = getHeight(n.left);
                int rh = getHeight(n.right);
                n.height = Math.max(lh, rh) + 1;
                int balance_factor = lh - rh;
                n.num_total = 1 + getNumTotal(n.left) + getNumTotal(n.right);
                n.num_left = 1 + getNumTotal(n.left);

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
            TreeNode replacement = (node.left != null) ? node.left : node.right;
            if (node.parent != null) {
                if (isLeft(node)) {
                    node.parent.left = replacement;
                } else {
                    node.parent.right = replacement;
                }
                replacement.parent = node.parent;
                node.parent = null;
            } else {
                _tree = replacement;
                replacement.parent = null;
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
            return (node != null) ? node.value : -1;
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

        public int[] getAt(int pos) {
            int x = pos + 1;
            TreeNode node = _tree;
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

        private boolean isLeft(TreeNode node) {
            return (node.parent != null && node.parent.left == node);
        }

        private boolean isLeaf(TreeNode node) {
            return (node.left == null && node.right == null);
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
            node.num_total = 1 + getNumTotal(node.left) + getNumTotal(node.right);
            node.num_left = 1 + getNumTotal(node.left);
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
            node.num_total = 1 + getNumTotal(node.left) + getNumTotal(node.right);
            node.num_left = 1 + getNumTotal(node.left);
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

    static class SegmentTree1 {
        int[] data;
        int _default;
        int _len;
        int _size;

        public SegmentTree1(int[] data, int defaultVal, int func) {
            _default = defaultVal;
            _len = data.length;
            _size = (int) Math.pow(2, Math.ceil(Math.log(_len) / Math.log(2)));

            this.data = new int[2 * _size];
            Arrays.fill(this.data, defaultVal);
            System.arraycopy(data, 0, this.data, _size, _len);
            for (int i = _size - 1; i >= 0; i--) {
                this.data[i] = func(this.data[2 * i], this.data[2 * i + 1]);
            }
        }

        public void remove(int idx) {
            this.data[idx] = _default;
        }

        public int get(int idx) {
            return this.data[idx + _size];
        }

        public void set(int idx, int value) {
            idx += _size;
            this.data[idx] = value;
            idx >>= 1;
            while (idx > 0) {
                this.data[idx] = func(this.data[2 * idx], this.data[2 * idx + 1]);
                idx >>= 1;
            }
        }

        public int size() {
            return _len;
        }

        public int query(int start, int stop) {
            if (start == stop) {
                return get(start);
            }
            stop++;
            start += _size;
            stop += _size;

            int res = _default;
            while (start < stop) {
                if ((start & 1) == 1) {
                    res = func(res, this.data[start]);
                    start++;
                }
                if ((stop & 1) == 1) {
                    stop--;
                    res = func(res, this.data[stop]);
                }
                start >>= 1;
                stop >>= 1;
            }
            return res;
        }
    }

    static class SegmentTree {
        int[] data;
        int _default;
        int _len;
        int _size;

        public SegmentTree(int[] data, int defaultVal, int func) {
            _default = defaultVal;
            _len = data.length;
            _size = (int) Math.pow(2, Math.ceil(Math.log(_len) / Math.log(2)));

            this.data = new int[2 * _size];
            Arrays.fill(this.data, defaultVal);
            System.arraycopy(data, 0, this.data, _size, _len);
            for (int i = _size - 1; i >= 0; i--) {
                this.data[i] = func(this.data[2 * i], this.data[2 * i + 1]);
            }
        }

        public void remove(int idx) {
            this.data[idx] = _default;
        }

        public int get(int idx) {
            return this.data[idx + _size];
        }

        public void set(int idx, int value) {
            idx += _size;
            this.data[idx] = value;
            idx >>= 1;
            while (idx > 0) {
                this.data[idx] = func(this.data[2 * idx], this.data[2 * idx + 1]);
                idx >>= 1;
            }
        }

        public int size() {
            return _len;
        }

        public int query(int start, int stop) {
            if (start == stop) {
                return get(start);
            }
            stop++;
            start += _size;
            stop += _size;

            int res = _default;
            while (start < stop) {
                if ((start & 1) == 1) {
                    res = func(res, this.data[start]);
                    start++;
                }
                if ((stop & 1) == 1) {
                    stop--;
                    res = func(res, this.data[stop]);
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
            factorials = Arrays.copyOf(factorials, n + 1);
            System.arraycopy(nextArr, 0, factorials, initialI, nextArr.length);
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
                nextArr[i - initialI] = (int) (-1L * (p / i) * nextArr[p % i] % p);
            }
            invModulos = Arrays.copyOf(invModulos, n + 1);
            System.arraycopy(nextArr, 0, invModulos, initialI, nextArr.length);
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
            invFactorial_ = Arrays.copyOf(invFactorial_, n + 1);
            System.arraycopy(nextArr, 0, invFactorial_, initialI, nextArr.length);
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
            Factorial f = factorial;
            return (int) ((long) f.calc(n) * f.invFactorial(Math.max(n - k, k)) % MOD * f.invFactorial(Math.min(k, n - k)) % MOD);
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
        Collections.sort(zippedPairs, Comparator.comparing(Pair::getKey));
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
        StringBuilder sb = new StringBuilder();
        if (y.length() >= length) {
            sb.append(y);
        } else {
            sb.append("0".repeat(length - y.length())).append(y);
        }
        return sb.toString();
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

    public static void main(String[] args) {
        FastReader sc = new FastReader();
        PrintWriter out = new PrintWriter(System.out);

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
        Pair<Integer, Integer>[] cntPairs = new Pair[m];
        for (int i = 0; i < m; i++) {
            cntPairs[i] = new Pair<>(cnt[i], i);
        }
        Arrays.sort(cntPairs, Comparator.comparing(Pair::getKey));
        Map<Integer, Integer> ind = new HashMap<>();
        for (int i = 0; i < cntPairs.length; i++) {
            ind.put(cntPairs[i].getValue(), i);
        }
        SegmentTree1 s = new SegmentTree1(l, 0, (a, b) -> a & b);
        SegmentTree1 s1 = new SegmentTree1(l1, 0, (a, b) -> a & b);
        int[] cou = new int[m];
        int cur = 0;
        int cur1 = 0;
        int[] fi = new int[m];

        for (int i = 0; i < m; i++) {
            int mw = s.query(0, ind.get(i)) + 1;

            l[ind.get(i)] = mw;
            fi[i] = mw;
            cur1 = Math.max(cur1, mw);
            s.set(ind.get(i), mw);
        }

        cntPairs = new Pair[m];
        for (int i = 0; i < m; i++) {
            cntPairs[i] = new Pair<>(cnt[i], -i);
        }
        Arrays.sort(cntPairs, Comparator.comparing(Pair::getKey));
        ind = new HashMap<>();
        for (int i = 0; i < cntPairs.length; i++) {
            ind.put(-cntPairs[i].getValue(), i);
        }

        for (int i = m - 1; i >= 0; i--) {
            int mw = s1.query(0, ind.get(i)) + 1;

            fi[i] += mw;
            l1[ind.get(i)] = mw;
            s1.set(ind.get(i), mw);
        }
        out.println(Arrays.stream(fi).max().getAsInt() - 1);

        out.flush();
        out.close();
    }
}
