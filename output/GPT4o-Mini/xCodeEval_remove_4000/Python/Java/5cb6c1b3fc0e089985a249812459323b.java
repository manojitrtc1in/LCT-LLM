import java.io.*;
import java.util.*;

class FastIO {
    private final InputStream inputStream;
    private final PrintWriter outputWriter;
    private final byte[] buffer = new byte[8192];
    private int pointer, bytesRead;

    public FastIO(InputStream inputStream, OutputStream outputStream) {
        this.inputStream = inputStream;
        this.outputWriter = new PrintWriter(outputStream);
    }

    public String nextLine() {
        StringBuilder sb = new StringBuilder();
        while (true) {
            if (pointer >= bytesRead) {
                try {
                    bytesRead = inputStream.read(buffer);
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
                pointer = 0;
                if (bytesRead == -1) break;
            }
            byte b = buffer[pointer++];
            if (b == '\n') break;
            sb.append((char) b);
        }
        return sb.toString();
    }

    public void print(Object obj) {
        outputWriter.print(obj);
    }

    public void println(Object obj) {
        outputWriter.println(obj);
    }

    public void flush() {
        outputWriter.flush();
    }
}

class TreeNode {
    int key, value, height, numLeft, numTotal;
    TreeNode left, right, parent;

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
        return x != null ? x.height : 0;
    }

    private int id1(TreeNode x) {
        return x != null ? x.numTotal : 0;
    }

    private void _rebalance(TreeNode node) {
        TreeNode n = node;
        while (n != null) {
            int lh = getHeight(n.left);
            int rh = getHeight(n.right);
            n.height = Math.max(lh, rh) + 1;
            int balanceFactor = lh - rh;
            n.numTotal = 1 + id1(n.left) + id1(n.right);
            n.numLeft = 1 + id1(n.left);

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
        return node.parent.left == node;
    }

    public int get(int k) {
        TreeNode node = _getNode(k);
        return node != null ? node.value : -1;
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

public class 5cb6c1b3fc0e089985a249812459323bxcodeeval_processed_4000.json {
    public static void main(String[] args) {
        FastIO io = new FastIO(System.in, System.out);
        String[] input = io.nextLine().split(" ");
        int n = Integer.parseInt(input[0]);
        int k = Integer.parseInt(input[1]);
        int[] l = Arrays.stream(io.nextLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        for (int i = 0; i < n; i++) {
            l[i] %= k;
        }
        if (n == 1) {
            io.println(l[0]);
            io.flush();
            return;
        }
        int[] l1 = Arrays.copyOfRange(l, 0, n / 2);
        int[] l2 = Arrays.copyOfRange(l, n / 2, n);
        Set<Integer> s = new HashSet<>();
        Set<Integer> s1 = new HashSet<>();
        Set<Integer> s2 = new HashSet<>();
        for (int i = 0; i < n / 2; i++) {
            for (int j : s) {
                s2.add((j + l1[i]) % k);
            }
            s.add(l1[i]);
            for (int j : s2) {
                s.add(j);
            }
            s2.clear();
        }
        for (int i = 0; i < n - n / 2; i++) {
            for (int j : s1) {
                s2.add((j + l2[i]) % k);
            }
            s1.add(l2[i]);
            for (int j : s2) {
                s1.add(j);
            }
            s2.clear();
        }
        List<Integer> sList = new ArrayList<>(s);
        List<Integer> s1List = new ArrayList<>(s1);
        Collections.sort(sList);
        Collections.sort(s1List);
        int ans = Math.max(Collections.max(sList), Collections.max(s1List));
        for (int i = 0; i < sList.size(); i++) {
            int t = k - 1 - sList.get(i);
            int ind = id9(s1List, t);
            int r = s1List.get(ind - 1);
            int rt = s1List.get(s1List.size() - 1);
            ans = Math.max(Math.max((r + sList.get(i)) % k, (sList.get(i) + rt) % k), ans);
        }
        io.println(ans);
        io.flush();
    }

    private static int id9(List<Integer> arr, int key) {
        int left = 0;
        int right = arr.size() - 1;
        int count = 0;

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
