import java.io.BufferedReader;
import java.util.Comparator;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Collection;
import java.util.List;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.ArrayList;
import java.util.StringTokenizer;
import java.math.BigInteger;
import java.util.Collections;
import java.io.InputStream;


public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		id12 solver = new id12();
		solver.solve(1, in, out);
		out.close();
	}
}

class id12 {

    int n;
    static Graph g = new Graph();
    int[] parent;
    private LCA lca;
    private DFSOrder order;
    private id11 tree;
    int[] marked;
    int[][] megaParent;
    private int[] level;

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        n = in.nextInt();
        parent = new int[n];
        g.initGraph(n, n-1);
        int root = -1;
        for (int i = 0; i < n; ++i) {
            parent[i] = in.nextInt()-1;
            if (parent[i] != -1) {
                g.id10(parent[i], i);
            } else {
                root = i;
            }
        }

        level = Parent.id14(g, root, parent);
        megaParent = Parent.id9(g, root);
        order = new DFSOrder(g, root, parent);
        lca = new LCA(g, root, parent);

        marked = new int[n];
        Arrays.fill(marked, -1);

        int countQueries = in.nextInt();
        tree = new id11(countQueries + 5, n * 2 + 5);
        for (int i = 0; i < countQueries; ++i) {
            if (i != 0) {
                tree.newVersion();
            }
            int t = in.nextInt();
            if (t == 1) {
                int c = in.nextInt() - 1;
                tree.update(order.start(c), 1);
                tree.update(order.end(c), -1);
                marked[c] = i;
            } else {








                int a = in.nextInt() - 1;
                int b = in.nextInt() - 1;
                int k = in.nextInt();
                int y = in.nextInt();
                int res = -1;
                int l = lca.LCA(a, b);

                if (l == a) {
                    l = getParent(b, level[b] - level[l] - 1);
                    int number = getNumber(b, l, y, tree.curVersion);
                    if (k <= number) {
                        k = number - k + 1;
                        res = calc(b, k, y, tree.curVersion, level[b] - level[l]);
                    } else {
                        res = -1;
                    }
                } else if (l == b) {
                    int number = getNumber(a, l, y, tree.curVersion);
                    if (number >= k) {
                        res = calc(a, k, y, tree.curVersion, level[a] - level[l]);
                    }
                } else {
                    int number = getNumber(a, l, y, tree.curVersion);
                    if (number >= k) {
                        res = calc(a, k, y, tree.curVersion, level[a] - level[l]);
                    } else {
                        k -= number;
                        l = getParent(b, level[b] - level[l] - 1);
                        number = getNumber(b, l, y, tree.curVersion);
                        if (k <= number) {
                            k = number - k + 1;
                            res = calc(b, k, y, tree.curVersion, level[b] - level[l]);
                        } else {
                            res = -1;
                        }

                    }
                }
                if (res == a || res == b) res = -1;
                if (res != -1) ++res;
                out.println(res);
            }
        }
    }

    private int calc(int fromV, int k, int y, int curVersion, int totalNumber) {
        int left = 1, right = totalNumber, middle;
        int res = -1;
        while (left <= right) {
            middle = (left + right) / 2;
            int v = getParent(fromV, middle);
            int cur = getNumber(fromV, v, y, curVersion);
            if (cur < k) {
                left = middle + 1;
            } else {
                res = v;
                right = middle - 1;
            }
        }
        return res;
    }

    private int getParent(int v, int dst) {
        for (int i = megaParent.length-1; i >= 0; --i) {
            if (megaParent[i][v] != -1) {
                if (dst >= (1 << i)) {
                    dst -= (1 << i);
                    v = megaParent[i][v];
                }
            }
        }
        return v;
    }

    private int getNumber(int v, int p, int y, int y2) {
        int id3 = level[v] - level[p];
        int sumP = tree.id2(y, y2, 0, order.start(p)+1);
        int sumV = tree.id2(y, y2, 0, order.start(v)+1);
        int totalMarked = sumV - sumP;
        if (marked[v] >= y) {
            --totalMarked;
        }
        if (marked[p] >= y) {
            ++totalMarked;
        }
        return id3 - totalMarked;
    }

    class id11 {
        class Node {
            Node left = null;
            Node right = null;
            Node parent = null;

            int version;
            int rangeLeft, rangeRight;
            int myValue = 0;
            int sum = 0;

            Node copy() {
                Node copy = new Node();
                copy.left = this.left;
                copy.right = this.right;
                copy.rangeLeft = this.rangeLeft;
                copy.rangeRight = this.rangeRight;
                copy.myValue = this.myValue;
                copy.sum = this.sum;
                copy.parent = this.parent;
                return copy;
            }

            public int getMiddle() {
                return (rangeLeft + rangeRight) >> 1;
            }
        }

        Node[] roots;
        int curVersion;

        public id11(int versions, int size) {
            roots = new Node[versions + 1];
            Arrays.fill(roots, null);
            curVersion = 0;
            roots[0] = new Node();
            roots[0].rangeLeft = 0;
            roots[0].rangeRight = size;
            roots[0].version = 0;
        }

        void newVersion() {
            ++curVersion;
            roots[curVersion] = roots[curVersion-1].copy();
            roots[curVersion].version = curVersion;
        }

        int id2(int v1, int v2, int left, int right) {
            if (v1 == 0) {
                return getSum(v2, left, right);
            }
            return getSum(v2, left, right) - getSum(v1-1, left, right);
        }

        int getSum(int version, int left, int right) {
            return id1(roots[version], left, right);
        }

        private int id1(Node v, int left, int right) {
            if (v.rangeRight <= left || v.rangeLeft >= right) return 0;
            if (v.rangeLeft >= left && v.rangeRight <= right) {
                return v.sum;
            }
            int res = 0;
            if (v.left != null) {
                res += id1(v.left, left, right);
            }
            if (v.right != null) {
                res += id1(v.right, left, right);
            }
            return res;
        }

        void update(int pos, int value) {
            Node v = roots[curVersion];
            while (v.rangeLeft + 1 != v.rangeRight) {
                int middle = v.getMiddle();
                if (pos < middle) {
                    checkLeft(v, v.rangeLeft, middle);
                    v = v.left;
                } else {
                    checkRight(v, middle, v.rangeRight);
                    v = v.right;
                }
            }
            v.myValue = v.sum = value;
            v = v.parent;
            while (v != null) {
                v.sum = v.myValue + getSum(v.left) + getSum(v.right);
                v = v.parent;
            }
        }

        private int getSum(Node node) {
            if (node == null) return 0;
            return node.sum;
        }

        private void checkRight(Node v, int rangeLeft, int rangeRight) {
            if (v.right == null) {
                v.right = new Node();
                v.right.rangeLeft = rangeLeft;
                v.right.rangeRight = rangeRight;
                v.right.version = v.version;
                v.right.parent = v;
            }

            if (v.version != v.right.version) {
                Node t = v.right.copy();
                t.version = v.version;
                t.parent = v;
                v.right = t;
            }
        }

        private void checkLeft(Node v, int rangeLeft, int rangeRight) {
            if (v.left == null) {
                v.left = new Node();
                v.left.rangeLeft = rangeLeft;
                v.left.rangeRight = rangeRight;
                v.left.version = v.version;
                v.left.parent = v;
            }
            if (v.version != v.left.version) {
                Node t = v.left.copy();
                t.version = v.version;
                t.parent = v;
                v.left = t;
            }
        }
    }
}

class Graph {
    public int[] from;
    public int[] to;
    public int[] first;
    public int[] next;
    public int nVertex;
    public int nEdges;
    public int curEdge;

    public Graph() {}

    public void initGraph(int n, int m) {
        curEdge = 0;
        nVertex = n;
        nEdges = m;
        from = new int[m * 2];
        to = new int[m * 2];
        first = new int[n];
        next = new int[m * 2];
        Arrays.fill(first, -1);
    }

    public void id10(int a, int b) {
        next[curEdge] = first[a];
        first[a] = curEdge;
        to[curEdge] = b;
        from[curEdge] = a;
        ++curEdge;
    }

}

class LCA {
    public int[] height;
    public int[] dfsOrder;
    public int[] id5;
    public int id13;
    private int block;
    private int[][] blockTable;
    int id4;
    int[] blockHash;
    int[][][] id6;
    int[] log2;
    int[] parent;
    int n;

    public LCA(Graph tree, int root, int[] parent) {
        n = tree.nVertex;
        log2 = new int[2 * n];
        height = new int[n];
        Arrays.fill(height, -1);
        dfsOrder = new int[n*2-1];
        id5 = new int[n];
        id13 = 0;
        this.parent = parent;
        dfsStack(tree, root);
        id4 = log(id13);
        id7();
    }

    

    private void dfsStack(Graph tree, int v) {
        int[] stackVertex = new int[tree.nVertex*2];
        int[] stackHeight = new int[tree.nVertex*2];
        int[] stackEdge = new int[tree.nVertex*2];
        int top = 0;
        stackHeight[top] = 0;
        stackVertex[top] = v;
        stackEdge[top] = tree.first[v];
        ++top;
        int currentHeight, edge;
        while (top > 0) {
            --top;
            v = stackVertex[top];
            currentHeight = stackHeight[top];
            edge = stackEdge[top];

            if (height[v] == -1) {
                height[v] = currentHeight;
                id5[v] = id13;
                dfsOrder[id13++] = v;
            } else {
                dfsOrder[id13++] = v;
            }

            if (edge == -1) continue;

            int nextEdge = tree.next[edge];

            if (nextEdge != -1) {
                if (tree.to[nextEdge] == parent[v]) {
                    nextEdge = tree.next[nextEdge];
                }
            }

            stackHeight[top] = currentHeight;
            stackVertex[top] = v;
            stackEdge[top] = nextEdge;
            ++top;

            int u = tree.to[edge];
            stackHeight[top] = currentHeight + 1;
            stackVertex[top] = u;
            int edgeId = tree.first[u];
            if (edgeId != -1) {
                if (tree.to[edgeId] == v) {
                    edgeId = tree.next[edgeId];
                }
            }
            stackEdge[top] = edgeId;
            ++top;
        }
    }

    int log(int n) {
        int res = 1;
        while ((1 << res) < n)  ++res;
        return res;
    }

    

    int minHeight(int i, int j) {
        return height[dfsOrder[i]] < height[dfsOrder[j]] ? i : j;
    }

    

    void id7() {
        block = (id4 + 1) / 2;
        int blocks = id13 / block + ((id13 % block > 0) ? 1 : 0);
        int maxBlocks = ((2 * n) / block) + 2;
        blockHash = new int[maxBlocks + 1];
        blockTable = new int[maxBlocks + 1][id4 + 1];
        id6 = new int[(int) (Math.sqrt(2*n) + 2)][block + 2][block + 2];
        ArrayUtils.fill(id6, -1);
        ArrayUtils.fill(blockTable, -1);
        Arrays.fill(blockHash, 0);

        

        for (int i = 0, blockId = 0, j = 0; i < id13; ++i, ++j) {
            if (j == block) {
                j = 0;
                ++blockId;
            }
            if (blockTable[blockId][0] == -1 || minHeight(i, blockTable[blockId][0]) == i) {
                blockTable[blockId][0] = i;
            }
        }

        for (int j = 1; j <= id4; ++j) {
            for (int i = 0; i < blocks; ++i) {
                int ni = i + (1 << (j - 1));
                if (ni >= blocks) {
                    blockTable[i][j] = blockTable[i][j - 1];
                } else {
                    blockTable[i][j] = minHeight(blockTable[i][j - 1], blockTable[ni][j - 1]);
                }
            }
        }

        

        for (int i = 0, blockId = 0, j = 0; i < id13 || j < block; ++i, ++j) {
            if (j == block) {
                j = 0;
                ++blockId;
            }
            if (j > 0 && (i >= id13 || minHeight(i - 1, i) == i - 1)) {
                blockHash[blockId] += (1 << (j - 1));
            }
        }

        

        for (int i = 0; i < blocks; ++i) {
            int id = blockHash[i];
            if (id6[id][0][0] != -1) continue;
            for (int l = 0; l < block; ++l) {
                id6[id][l][l] = l;
                for (int r = l + 1; r < block; ++r) {
                    id6[id][l][r] = id6[id][l][r-1];
                    if (i * block + r < id13) {
                        id6[id][l][r] = minHeight(i * block + id6[id][l][r], i * block + r) - i * block;
                    }
                }
            }
        }

        

        for (int i = 0, j = 0; i < id13; ++i) {
            if (1 << (j + 1) <= i) ++j;
            log2[i] = j;
        }
    }

    

    int id8(int blockId, int l, int r) {
        return id6[blockHash[blockId]][l][r] + blockId * block;
    }

    

    public int LCA(int v, int u) {
        int l = id5[v], r = id5[u];
        if (l > r) {
            int t = l;
            l = r;
            r = t;
        }
        int leftBlock = l / block, rightBlock = r / block;
        if (leftBlock == rightBlock) {
            return dfsOrder[id8(leftBlock, l % block, r % block)];
        }
        int ans1 = id8(leftBlock, l % block, block - 1);
        int ans2 = id8(rightBlock, 0, r % block);
        int ans = minHeight(ans1, ans2);
        if (leftBlock < rightBlock - 1) {
            int pw2 = log2[rightBlock-leftBlock-1];
            int ans3 = blockTable[leftBlock + 1][pw2];
            int ans4 = blockTable[rightBlock - (1 << pw2)][pw2];
            ans = minHeight(ans, minHeight(ans3, ans4));
        }
        return dfsOrder[ans];
    }

    

}

class DFSOrder {
    int[] start;
    int[] end;

    public DFSOrder(Graph tree, int root, int[] p) {
        start = new int[tree.nVertex];
        end = new int[tree.nVertex];
        id0(tree, root, p);
    }

    public int start(int v) {
        return start[v];
    }

    public int end(int v) {
        return end[v];
    }

    private void id0(Graph tree, int root, int[] p) {
        int[] stack = new int[2 * tree.nVertex];
        int top = 0;
        stack[top++] = (root + 1);
        int time = 0;
        while (top > 0) {
            --top;
            int v = stack[top];
            if (v < 0) {
                v = (-v) - 1;
                end[v] = time;
                ++time;
            } else {
                --v;
                start[v] = time++;
                stack[top++] = -(v+1);
                for (int i = tree.first[v]; i != -1; i = tree.next[i]) {
                    if (p[v] != tree.to[i]) {
                        stack[top++] = (tree.to[i] + 1);
                    }
                }
            }
        }
    }
}

class InputReader {
    private BufferedReader reader;
    private StringTokenizer stt;

    public InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream));
    }

    public String nextLine() {
        try {
            return reader.readLine();
        } catch (IOException e) {
            return null;
        }
    }

    public String nextString() {
        while (stt == null || !stt.hasMoreTokens()) {
            stt = new StringTokenizer(nextLine());
        }
        return stt.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(nextString());
    }

}

class Parent {
    public static int[] run(Graph tree, int root) {
        int[] parent = new int[tree.nVertex];
        int[] queue = new int[tree.nVertex];
        int front = 0, back = 0;
        queue[back++] = root;
        parent[root] = -1;
        while (front < back) {
            int v = queue[front++];
            for (int i = tree.first[v]; i != -1; i = tree.next[i]) {
                if (parent[v] != tree.to[i]) {
                    queue[back++] = tree.to[i];
                    parent[tree.to[i]] = v;
                }
            }
        }
        return parent;
    }

    public static int[][] id9(Graph tree, int root) {
        int maxLevel = 1;
        while ((1 << maxLevel) <= tree.nVertex) {
            ++maxLevel;
        }
        int[][] parent = new int[maxLevel][tree.nVertex];
        ArrayUtils.fill(parent, -1);
        parent[0] = Parent.run(tree, root);

        for (int level = 1; level < maxLevel; ++level) {
            for (int i = 0; i < tree.nVertex; ++i) {
                if (parent[level-1][i] != -1) {
                    int u = parent[level-1][i];
                    if (parent[level-1][u] != -1) {
                        int v = parent[level-1][u];
                        parent[level][i] = v;
                    }
                }
            }
        }
        return parent;
    }

    public static int[] id14(Graph tree, int root, int[] parent) {
        int[] queue = new int[tree.nVertex];
        int front = 0, back = 0;
        queue[back++] = root;
        parent[root] = -1;
        int[] level = new int[tree.nVertex];
        level[root] = 0;
        while (front < back) {
            int v = queue[front++];
            for (int i = tree.first[v]; i != -1; i = tree.next[i]) {
                if (parent[v] != tree.to[i]) {
                    queue[back++] = tree.to[i];
                    level[tree.to[i]] = level[v] + 1;
                }
            }
        }
        return level;
    }
}

class ArrayUtils {

    public static void fill(int[][] f, int value) {
        for (int i = 0; i < f.length; ++i) {
            Arrays.fill(f[i], value);
        }
    }

    public static void fill(int[][][] a, int value) {
        for (int i = 0; i < a.length; ++i) {
            fill(a[i], value);
        }
    }

}

