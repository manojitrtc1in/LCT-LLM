import java.io.*;
import java.util.*;

class FastIO {
    private final InputStream in;
    private final OutputStream out;
    private final byte[] buffer = new byte[8192];
    private int pointer, bytesRead;

    public FastIO(InputStream in, OutputStream out) {
        this.in = in;
        this.out = out;
    }

    public int read() throws IOException {
        if (pointer >= bytesRead) {
            pointer = 0;
            bytesRead = in.read(buffer);
            if (bytesRead == -1) return -1;
        }
        return buffer[pointer++];
    }

    public String readLine() throws IOException {
        StringBuilder sb = new StringBuilder();
        int c;
        while ((c = read()) != -1 && c != '\n') {
            sb.append((char) c);
        }
        return sb.toString();
    }

    public void print(String s) throws IOException {
        out.write(s.getBytes());
    }

    public void flush() throws IOException {
        out.flush();
    }
}

class TreeNode {
    int key, value, height, numLeft, numTotal;
    TreeNode left, right, parent;

    TreeNode(int k, int v) {
        key = k;
        value = v;
        left = right = parent = null;
        height = 1;
        numLeft = 1;
        numTotal = 1;
    }
}

class AvlTree {
    private TreeNode tree;

    public void add(int k, int v) {
        if (tree == null) {
            tree = new TreeNode(k, v);
            return;
        }
        TreeNode node = _add(k, v);
        if (node != null) {
            _rebalance(node);
        }
    }

    private TreeNode _add(int k, int v) {
        TreeNode node = tree;
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

    private static int getHeight(TreeNode x) {
        return x == null ? 0 : x.height;
    }

    private static int getNumTotal(TreeNode x) {
        return x == null ? 0 : x.numTotal;
    }

    private void _rebalance(TreeNode node) {
        TreeNode n = node;
        while (n != null) {
            int lh = getHeight(n.left);
            int rh = getHeight(n.right);
            n.height = Math.max(lh, rh) + 1;
            n.numTotal = 1 + getNumTotal(n.left) + getNumTotal(n.right);
            n.numLeft = 1 + getNumTotal(n.left);

            int balanceFactor = lh - rh;

            if (balanceFactor > 1) {
                if (getHeight(n.left.left) < getHeight(n.left.right)) {
                    _rotateLeft(n.left);
                }
                _rotateRight(n);
            } else if (balanceFactor < -1) {
                if (getHeight(n.right.right) < getHeight(n.right.left)) {
                    _rotateRight(n.right);
                }
                _rotateLeft(n);
            } else {
                n = n.parent;
            }
        }
    }

    private void _rotateRight(TreeNode node) {
        if (node.parent == null) {
            tree = node.left;
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
        node.numTotal = 1 + getNumTotal(node.left) + getNumTotal(node.right);
        node.numLeft = 1 + getNumTotal(node.left);
    }

    private void _rotateLeft(TreeNode node) {
        if (node.parent == null) {
            tree = node.right;
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
        node.numTotal = 1 + getNumTotal(node.left) + getNumTotal(node.right);
        node.numLeft = 1 + getNumTotal(node.left);
    }

    private static boolean isLeft(TreeNode node) {
        return node.parent.left != null && node.parent.left == node;
    }

    public void remove(int k) {
        TreeNode node = _getNode(k);
        if (node == null) return;

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
            tree = replacement;
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
            tree = null;
        }
        node.parent = null;
        node.left = null;
        node.right = null;
    }

    private TreeNode _getNode(int k) {
        if (tree == null) return null;
        TreeNode node = tree;
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

    private static boolean isLeaf(TreeNode node) {
        return node.left == null && node.right == null;
    }

    private static TreeNode _getNext(TreeNode node) {
        if (node.right == null) return node.parent;
        TreeNode n = node.right;
        while (n.left != null) {
            n = n.left;
        }
        return n;
    }
}

class SegmentTree {
    private final int[] data;
    private final int size;
    private final int defaultValue;
    private final IntBinaryOperator func;

    public SegmentTree(int[] input, int defaultValue, IntBinaryOperator func) {
        this.defaultValue = defaultValue;
        this.func = func;
        int len = input.length;
        size = 1 << (len - 1).bitLength();
        data = new int[2 * size];
        Arrays.fill(data, defaultValue);
        System.arraycopy(input, 0, data, size, len);
        for (int i = size - 1; i > 0; i--) {
            data[i] = func.applyAsInt(data[i * 2], data[i * 2 + 1]);
        }
    }

    public void set(int idx, int value) {
        idx += size;
        data[idx] = value;
        while (idx > 1) {
            idx >>= 1;
            data[idx] = func.applyAsInt(data[idx * 2], data[idx * 2 + 1]);
        }
    }

    public int query(int start, int stop) {
        if (start == stop) return data[start + size];
        stop++;
        start += size;
        stop += size;

        int res = defaultValue;
        while (start < stop) {
            if ((start & 1) != 0) {
                res = func.applyAsInt(res, data[start++]);
            }
            if ((stop & 1) != 0) {
                res = func.applyAsInt(res, data[--stop]);
            }
            start >>= 1;
            stop >>= 1;
        }
        return res;
    }
}

class Combination {
    private final int MOD;
    private final Factorial factorial;

    public Combination(int MOD) {
        this.MOD = MOD;
        this.factorial = new Factorial(MOD);
    }

    public int ncr(int n, int k) {
        if (k < 0 || n < k) return 0;
        k = Math.min(k, n - k);
        return (int) ((long) factorial.calc(n) * factorial.invFactorial(Math.max(n - k, k)) % MOD * factorial.invFactorial(Math.min(k, n - k)) % MOD);
    }
}

class Factorial {
    private final int MOD;
    private final List<Integer> factorials = new ArrayList<>(Arrays.asList(1, 1));
    private final List<Integer> invModulos = new ArrayList<>(Arrays.asList(0, 1));
    private final List<Integer> invFactorial_ = new ArrayList<>(Arrays.asList(1, 1));

    public Factorial(int MOD) {
        this.MOD = MOD;
    }

    public int calc(int n) {
        if (n < 0) throw new IllegalArgumentException("n must be non-negative");
        if (n < factorials.size()) return factorials.get(n);
        int initialI = factorials.size();
        int prev = factorials.get(initialI - 1);
        for (int i = initialI; i <= n; i++) {
            prev = (int) ((long) prev * i % MOD);
            factorials.add(prev);
        }
        return factorials.get(n);
    }

    public int inv(int n) {
        if (n < 0) throw new IllegalArgumentException("n must be non-negative");
        if (n < invModulos.size()) return invModulos.get(n);
        int initialI = invModulos.size();
        for (int i = initialI; i < Math.min(MOD, n + 1); i++) {
            invModulos.add((int) (-invModulos.get(MOD % i) * (MOD / i) % MOD + MOD) % MOD);
        }
        return invModulos.get(n % MOD);
    }

    public int invFactorial(int n) {
        if (n < 0) throw new IllegalArgumentException("n must be non-negative");
        if (n < invFactorial_.size()) return invFactorial_.get(n);
        inv(n);
        int initialI = invFactorial_.size();
        int prev = invFactorial_.get(initialI - 1);
        for (int i = initialI; i <= n; i++) {
            prev = (int) ((long) prev * invModulos.get(i % MOD) % MOD);
            invFactorial_.add(prev);
        }
        return invFactorial_.get(n);
    }
}

public class 52216489e2215307ed5732d7cb449283_nc {
    public static void main(String[] args) throws IOException {
        FastIO io = new FastIO(System.in, System.out);
        int[] nm = Arrays.stream(io.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        int n = nm[0], m = nm[1];
        int[] cnt = new int[m + 1];
        for (int i = 0; i < n; i++) {
            int[] ab = Arrays.stream(io.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
            cnt[ab[0] - 1]++;
            cnt[ab[1]]--;
        }
        for (int i = 1; i <= m; i++) {
            cnt[i] += cnt[i - 1];
        }
        int[] l = new int[m];
        int[] l1 = new int[m];
        List<int[]> cntList = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            cntList.add(new int[]{cnt[i], i});
        }
        cntList.sort(Comparator.comparingInt(a -> a[0]));
        Map<Integer, Integer> ind = new HashMap<>();
        for (int i = 0; i < cntList.size(); i++) {
            ind.put(cntList.get(i)[1], i);
        }
        SegmentTree s = new SegmentTree(l, 0, Math::max);
        SegmentTree s1 = new SegmentTree(l1, 0, Math::max);
        int[] cou = new int[m];
        int cur = 0, cur1 = 0;
        int[] fi = new int[m];

        for (int i = 0; i < m; i++) {
            int mw = s.query(0, ind.get(i)) + 1;
            l[ind.get(i)] = mw;
            fi[i] = mw;
            cur1 = Math.max(cur1, mw);
            s.set(ind.get(i), mw);
        }

        cntList.sort(Comparator.comparingInt(a -> -a[0]));
        for (int i = 0; i < cntList.size(); i++) {
            ind.put(-cntList.get(i)[1], i);
        }
        for (int i = m - 1; i >= 0; i--) {
            int mw = s1.query(0, ind.get(i)) + 1;
            fi[i] += mw;
            l1[ind.get(i)] = mw;
            s1.set(ind.get(i), mw);
        }
        io.print((max(fi) - 1) + "\n");
        io.flush();
    }

    private static int max(int[] arr) {
        int max = arr[0];
        for (int value : arr) {
            max = Math.max(max, value);
        }
        return max;
    }
}
