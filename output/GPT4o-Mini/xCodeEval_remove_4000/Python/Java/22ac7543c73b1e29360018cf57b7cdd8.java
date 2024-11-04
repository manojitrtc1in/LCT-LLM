import java.io.*;
import java.util.*;

class FastIO extends InputStream {
    private final InputStream in;
    private final byte[] buffer = new byte[8192];
    private int pointer = 0, bytesRead = 0;

    public FastIO(InputStream in) {
        this.in = in;
    }

    public int read() throws IOException {
        if (pointer >= bytesRead) {
            bytesRead = in.read(buffer);
            pointer = 0;
        }
        return (bytesRead == -1) ? -1 : buffer[pointer++];
    }

    public String readLine() throws IOException {
        StringBuilder sb = new StringBuilder();
        int c;
        while ((c = read()) != -1 && c != '\n') {
            sb.append((char) c);
        }
        return sb.toString();
    }
}

class TreeNode {
    int key, value, height, numLeft, numTotal;
    TreeNode left, right, parent;

    TreeNode(int k, int v) {
        key = k;
        value = v;
        height = 1;
        numLeft = 1;
        numTotal = 1;
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

    private void _rebalance(TreeNode node) {
        TreeNode n = node;
        while (n != null) {
            int lh = getHeight(n.left);
            int rh = getHeight(n.right);
            n.height = Math.max(lh, rh) + 1;
            n.numTotal = 1 + id2(n.left) + id2(n.right);
            n.numLeft = 1 + id2(n.left);

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

    private int getHeight(TreeNode x) {
        return (x == null) ? 0 : x.height;
    }

    private int id2(TreeNode x) {
        return (x == null) ? 0 : x.numTotal;
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
        node.numTotal = 1 + id2(node.left) + id2(node.right);
        node.numLeft = 1 + id2(node.left);
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
        node.numTotal = 1 + id2(node.left) + id2(node.right);
        node.numLeft = 1 + id2(node.left);
    }

    private boolean isLeft(TreeNode node) {
        return node.parent.left == node;
    }

    public int get(int k) {
        TreeNode node = _getNode(k);
        return (node != null) ? node.value : -1;
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
}

public class 22ac7543c73b1e29360018cf57b7cdd8xcodeeval_processed_4000.json {
    public static void main(String[] args) throws IOException {
        FastIO input = new FastIO(System.in);
        String[] nm = input.readLine().split(" ");
        int n = Integer.parseInt(nm[0]);
        int m = Integer.parseInt(nm[1]);
        int[] l = Arrays.stream(input.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        List<int[]> t = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            String[] ab = input.readLine().split(" ");
            t.add(new int[]{Integer.parseInt(ab[0]), Integer.parseInt(ab[1])});
        }
        t.sort(Comparator.comparingInt(a -> a[0]));

        int st = 1;
        int end = 2 * Arrays.stream(l).sum();
        int ans = end;

        while (st <= end) {
            int mid = (st + end) / 2;
            if (check(mid, l, t, m)) {
                ans = mid;
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        }
        System.out.println(ans);
    }

    private static boolean check(int x, int[] l, List<int[]> t, int m) {
        int now = x;
        int c = Arrays.stream(l).sum();
        int cur = 0;
        int last = 0;
        Map<Integer, Integer> ld = new HashMap<>();
        for (int i = 0; i < m; i++) {
            if (t.get(i)[0] <= x) {
                ld.put(t.get(i)[1], i);
            }
        }
        for (int i = 0; i < m; i++) {
            if (!ld.containsKey(t.get(i)[1]) || ld.get(t.get(i)[1]) != i) {
                continue;
            }
            if (t.get(i)[0] > x) {
                break;
            }
            cur += t.get(i)[0] - last;
            int rt = Math.min(cur, l[t.get(i)[1] - 1]);
            cur -= rt;
            now -= rt;
            c -= rt;
            last = t.get(i)[0];
        }
        return now >= 2 * c;
    }
}
