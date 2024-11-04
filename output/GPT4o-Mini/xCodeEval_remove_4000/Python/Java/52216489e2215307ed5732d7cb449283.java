import java.io.*;
import java.util.*;

class FastIO {
    private final InputStream inputStream;
    private final OutputStream outputStream;
    private final byte[] buffer = new byte[8192];
    private int pointer, bytesRead;

    public FastIO(InputStream inputStream, OutputStream outputStream) {
        this.inputStream = inputStream;
        this.outputStream = outputStream;
    }

    public int read() {
        if (bytesRead == -1) return -1;
        if (pointer >= bytesRead) {
            pointer = 0;
            try {
                bytesRead = inputStream.read(buffer);
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
            if (bytesRead <= 0) return -1;
        }
        return buffer[pointer++];
    }

    public String readLine() {
        StringBuilder sb = new StringBuilder();
        int c;
        while ((c = read()) != -1 && c != '\n') {
            sb.append((char) c);
        }
        return sb.toString();
    }

    public void write(String s) {
        try {
            outputStream.write(s.getBytes());
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public void flush() {
        try {
            outputStream.flush();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}

class TreeNode {
    int key, value;
    TreeNode left, right, parent;
    int height, numLeft, numTotal;

    TreeNode(int k, int v) {
        this.key = k;
        this.value = v;
        this.height = 1;
        this.numLeft = 1;
        this.numTotal = 1;
    }
}

class AVLTree {
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

    private int getHeight(TreeNode x) {
        return x == null ? 0 : x.height;
    }

    private int id1(TreeNode x) {
        return x == null ? 0 : x.numTotal;
    }

    private void _rebalance(TreeNode node) {
        TreeNode n = node;
        while (n != null) {
            int lh = getHeight(n.left);
            int rh = getHeight(n.right);
            n.height = Math.max(lh, rh) + 1;
            n.numTotal = 1 + id1(n.left) + id1(n.right);
            n.numLeft = 1 + id1(n.left);

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
            }
            n = n.parent;
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
        node.numTotal = 1 + id1(node.left) + id1(node.right);
        node.numLeft = 1 + id1(node.left);
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
        node.numTotal = 1 + id1(node.left) + id1(node.right);
        node.numLeft = 1 + id1(node.left);
    }

    private boolean isLeft(TreeNode node) {
        return node.parent.left != null && node.parent.left == node;
    }

    public void remove(int k) {
        TreeNode node = _getNode(k);
        if (node == null) return;
        if (isLeaf(node)) {
            _removeLeaf(node);
        } else {
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

    private boolean isLeaf(TreeNode node) {
        return node.left == null && node.right == null;
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
        this.size = 1 << (Integer.SIZE - Integer.numberOfLeadingZeros(input.length - 1));
        this.data = new int[2 * size];
        Arrays.fill(data, defaultValue);
        System.arraycopy(input, 0, data, size, input.length);
        for (int i = size - 1; i > 0; i--) {
            data[i] = func.applyAsInt(data[i << 1], data[i << 1 | 1]);
        }
    }

    public void update(int idx, int value) {
        idx += size;
        data[idx] = value;
        while (idx > 1) {
            idx >>= 1;
            data[idx] = func.applyAsInt(data[idx << 1], data[idx << 1 | 1]);
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

    public int nCr(int n, int k) {
        if (k < 0 || n < k) return 0;
        k = Math.min(k, n - k);
        return (int) ((long) factorial.calc(n) * factorial.inv(factorial.calc(k)) % MOD * factorial.inv(factorial.calc(n - k)) % MOD);
    }
}

class Factorial {
    private final int MOD;
    private final List<Integer> factorials = new ArrayList<>(Arrays.asList(1, 1));
    private final List<Integer> invModulos = new ArrayList<>(Arrays.asList(0, 1));
    private final List<Integer> invFactorial = new ArrayList<>(Arrays.asList(1, 1));

    public Factorial(int MOD) {
        this.MOD = MOD;
    }

    public int calc(int n) {
        if (n < 0) throw new IllegalArgumentException("Invalid argument to calculate n!");
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
        if (n < 0) throw new IllegalArgumentException("Invalid argument to calculate n^(-1)");
        if (n < invModulos.size()) return invModulos.get(n);
        int initialI = invModulos.size();
        for (int i = initialI; i < Math.min(MOD, n + 1); i++) {
            int next = (int) (-invModulos.get(MOD % i) * (MOD / i) % MOD);
            invModulos.add(next);
        }
        return invModulos.get(n % MOD);
    }

    public int invFactorial(int n) {
        if (n < 0) throw new IllegalArgumentException("Invalid argument to calculate (n^(-1))!");
        if (n < invFactorial.size()) return invFactorial.get(n);
        inv(n);
        int initialI = invFactorial.size();
        int prev = invFactorial.get(initialI - 1);
        for (int i = initialI; i <= n; i++) {
            prev = (int) ((long) prev * invModulos.get(i % MOD) % MOD);
            invFactorial.add(prev);
        }
        return invFactorial.get(n);
    }
}

public class 52216489e2215307ed5732d7cb449283xcodeeval_processed_4000.json {
    public static void main(String[] args) {
        FastIO io = new FastIO(System.in, System.out);
        int n = Integer.parseInt(io.readLine());
        int m = Integer.parseInt(io.readLine());
        int[] cnt = new int[m + 1];
        for (int i = 0; i < n; i++) {
            String[] input = io.readLine().split(" ");
            int a = Integer.parseInt(input[0]);
            int b = Integer.parseInt(input[1]);
            cnt[a - 1]++;
            cnt[b]--;
        }
        for (int i = 1; i <= m; i++) {
            cnt[i] += cnt[i - 1];
        }
        int[] l = new int[m];
        int[] l1 = new int[m];
        List<Pair> cntList = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            cntList.add(new Pair(cnt[i], i));
        }
        Collections.sort(cntList);
        Map<Integer, Integer> ind = new HashMap<>();
        for (int i = 0; i < cntList.size(); i++) {
            ind.put(cntList.get(i).second, i);
        }
        SegmentTree s = new SegmentTree(l, 0, Math::max);
        SegmentTree s1 = new SegmentTree(l1, 0, Math::max);
        int[] cou = new int[m];
        int cur = 0;
        int cur1 = 0;
        int[] fi = new int[m];

        for (int i = 0; i < m; i++) {
            int mw = s.query(0, ind.get(i)) + 1;
            l[ind.get(i)] = mw;
            fi[i] = mw;
            cur1 = Math.max(cur1, mw);
            s.update(ind.get(i), mw);
        }

        cntList = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            cntList.add(new Pair(cnt[i], -i));
        }
        Collections.sort(cntList);
        for (int i = 0; i < cntList.size(); i++) {
            ind.put(-cntList.get(i).second, i);
        }
        for (int i = m - 1; i >= 0; i--) {
            int mw = s1.query(0, ind.get(i)) + 1;
            fi[i] += mw;
            l1[ind.get(i)] = mw;
            s1.update(ind.get(i), mw);
        }
        io.write((Arrays.stream(fi).max().orElse(0) - 1) + "\n");
        io.flush();
    }

    static class Pair {
        int first, second;

        Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }
}
