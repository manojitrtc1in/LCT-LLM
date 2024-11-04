import java.io.*;
import java.util.*;

class FastIO {
    private final InputStream inputStream;
    private final OutputStream outputStream;
    private final byte[] buffer = new byte[8192];
    private int bufferPointer, bytesRead;

    public FastIO(InputStream inputStream, OutputStream outputStream) {
        this.inputStream = inputStream;
        this.outputStream = outputStream;
    }

    public int read() {
        if (bufferPointer == bytesRead) {
            bufferPointer = 0;
            try {
                bytesRead = inputStream.read(buffer);
            } catch (IOException e) {
                return -1;
            }
            if (bytesRead == -1) return -1;
        }
        return buffer[bufferPointer++];
    }

    public String next() {
        StringBuilder sb = new StringBuilder();
        int c;
        while ((c = read()) != -1 && !Character.isWhitespace(c)) {
            sb.append((char) c);
        }
        return sb.toString();
    }

    public void print(String s) {
        try {
            outputStream.write(s.getBytes());
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void println(String s) {
        print(s + "\n");
    }

    public void close() throws IOException {
        inputStream.close();
        outputStream.close();
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
        return x != null ? x.height : 0;
    }

    private static int getNumTotal(TreeNode x) {
        return x != null ? x.numTotal : 0;
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
        return node.parent.left == node;
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

    public SegmentTree(int[] data, int defaultValue, IntBinaryOperator func) {
        this.defaultValue = defaultValue;
        this.func = func;
        this.size = 1 << (Integer.highestOneBit(data.length) << 1);
        this.data = new int[size];
        System.arraycopy(data, 0, this.data, size / 2, data.length);
        for (int i = size / 2 - 1; i > 0; i--) {
            this.data[i] = func.applyAsInt(this.data[i * 2], this.data[i * 2 + 1]);
        }
    }

    public void set(int idx, int value) {
        idx += size / 2;
        data[idx] = value;
        while (idx > 1) {
            idx /= 2;
            data[idx] = func.applyAsInt(data[idx * 2], data[idx * 2 + 1]);
        }
    }

    public int query(int start, int stop) {
        start += size / 2;
        stop += size / 2 + 1;
        int res = defaultValue;
        while (start < stop) {
            if ((start & 1) == 1) {
                res = func.applyAsInt(res, data[start++]);
            }
            if ((stop & 1) == 1) {
                res = func.applyAsInt(res, data[--stop]);
            }
            start /= 2;
            stop /= 2;
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

public class 5cb6c1b3fc0e089985a249812459323b_nc {
    public static void main(String[] args) throws IOException {
        FastIO io = new FastIO(System.in, System.out);
        int n = Integer.parseInt(io.next());
        int k = Integer.parseInt(io.next());
        int[] l = new int[n];
        for (int i = 0; i < n; i++) {
            l[i] = Integer.parseInt(io.next()) % k;
        }
        if (n == 1) {
            io.println(l[0]);
            io.close();
            return;
        }
        int[] l1 = Arrays.copyOfRange(l, 0, n / 2);
        int[] l2 = Arrays.copyOfRange(l, n / 2, n);
        Set<Integer> s = new HashSet<>();
        Set<Integer> s1 = new HashSet<>();
        Set<Integer> s2 = new HashSet<>();
        for (int i : l1) {
            for (int j : s) {
                s2.add((j + i) % k);
            }
            s.add(i);
            s.addAll(s2);
            s2.clear();
        }
        for (int i : l2) {
            for (int j : s1) {
                s2.add((j + i) % k);
            }
            s1.add(i);
            s1.addAll(s2);
            s2.clear();
        }
        List<Integer> sList = new ArrayList<>(s);
        List<Integer> s1List = new ArrayList<>(s1);
        Collections.sort(sList);
        Collections.sort(s1List);
        int ans = Math.max(Collections.max(sList), Collections.max(s1List));
        for (int i = 0; i < sList.size(); i++) {
            int t = k - 1 - sList.get(i);
            int ind = binarySearchCount(s1List, t);
            int r = s1List.get(ind - 1);
            int rt = s1List.get(s1List.size() - 1);
            ans = Math.max(Math.max((r + sList.get(i)) % k, (sList.get(i) + rt) % k), ans);
        }
        io.println(ans);
        io.close();
    }

    private static int binarySearchCount(List<Integer> arr, int key) {
        int left = 0, right = arr.size() - 1, count = 0;
        while (left <= right) {
            int mid = (right + left) / 2;
            if (arr.get(mid) <= key) {
                count = mid + 1;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return count;
    }
}
