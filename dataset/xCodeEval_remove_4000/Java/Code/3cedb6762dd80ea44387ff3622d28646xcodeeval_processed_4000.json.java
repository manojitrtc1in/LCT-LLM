import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.TreeSet;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.util.Comparator;
import java.io.InputStream;


public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        id11 solver = new id11();
        solver.solve(1, in, out);
        out.close();
    }

    static class id11 {
        Graph tree;
        private int[][] pp;
        private id7 ft;
        private DFSOrder order;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            tree = new Graph();
            tree.initGraph(n, n - 1);
            for (int i = 0; i < n - 1; ++i) {
                tree.addEdge(in.nextInt() - 1, in.nextInt() - 1);
            }
            int[] parent = Parent.run(tree, 0);
            pp = Parent.id6(tree, 0);
            order = new DFSOrder(tree, 0, parent);
            LCA LC = new LCA(tree, 0, parent);
            final int[] vertexLevels = Parent.id9(tree, 0, parent);
            int countQueries = in.nextInt();
            ft = new id7(2 * n);
            boolean[] isGood = new boolean[n];
            boolean[] wasDeleted = new boolean[n];
            List<Integer> memoDeleted = new ArrayList<Integer>();

            while (countQueries-- > 0) {
                int res = 0;
                int am = in.nextInt();
                Integer[] cities = new Integer[am];
                for (int i = 0; i < am; ++i) {
                    cities[i] = in.nextInt() - 1;
                    isGood[cities[i]] = true;
                    ft.update(order.start(cities[i]), 1);
                }
                memoDeleted.clear();

                Arrays.sort(cities, new Comparator<Integer>() {

                    public int compare(Integer o1, Integer o2) {
                        return order.start(o1) - order.start(o2);
                    }
                });

                boolean done = false;
                for (int v : cities) {
                    if (parent[v] != -1 && isGood[parent[v]]) {
                        out.println(-1);
                        done = true;
                        break;
                    }
                }

                if (!done) {
                    TreeSet<Integer> id10 = new TreeSet<Integer>();
                    id10.add(cities[0]);
                    for (int i = 1; i < am; ++i) {
                        id10.add(LC.LCA(cities[i - 1], cities[i]));
                        id10.add(cities[i]);
                    }

                    Integer[] lcas = new Integer[id10.size()];
                    int cnt = 0;
                    for (int i : id10) {
                        lcas[cnt++] = i;
                    }
                    Arrays.sort(lcas, new Comparator<Integer>() {

                        public int compare(Integer o1, Integer o2) {
                            return vertexLevels[o2] - vertexLevels[o1];
                        }
                    });

                    TreeSet<Item> dict = new TreeSet<Item>();
                    for (int i = 0; i < am; ++i) {
                        dict.add(new Item(order.start(cities[i]), cities[i]));
                    }

                    for (int x : lcas) {
                        if (isGood[x]) {
                            while (true) {
                                Item it = dict.higher(new Item(order.start(x), x));
                                if (it == null) break;
                                if (order.isChild(it.v, x)) {
                                    ++res;
                                    ft.update(it.pos, -1);
                                    dict.remove(it);
                                } else {
                                    break;
                                }
                            }
                        } else {
                            int count = 0;
                            int memo = -1;
                            while (true) {
                                Item it = dict.higher(new Item(order.start(x), x));
                                if (it == null) break;
                                if (order.isChild(it.v, x)) {
                                    ft.update(it.pos, -1);
                                    dict.remove(it);
                                    ++count;
                                    memo = it.v;
                                } else {
                                    break;
                                }
                            }

                            if (count > 1) {
                                ++res;
                            } else {
                                if (count == 1) {
                                    dict.add(new Item(order.start(memo), memo));
                                }
                            }
                        }
                    }
                    out.println(res);

                }


                

                for (int i = 0; i < am; ++i) {


                    isGood[cities[i]] = false;
                }
                for (int v : memoDeleted) {
                    wasDeleted[v] = false;
                }
            }
        }

        class Item implements Comparable<Item> {
            int pos;
            int v;

            public Item(int pos, int v) {
                this.pos = pos;
                this.v = v;
            }


            public int compareTo(Item o) {
                return pos - o.pos;
            }

        }

    }

    static class InputReader {
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

    static class ArrayUtils {
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

    static class Graph {
        public int[] from;
        public int[] to;
        public int[] first;
        public int[] next;
        public int nVertex;
        public int nEdges;
        public int curEdge;

        public Graph() {
        }

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

        public void addEdge(int a, int b) {
            next[curEdge] = first[a];
            first[a] = curEdge;
            to[curEdge] = b;
            from[curEdge] = a;
            ++curEdge;

            next[curEdge] = first[b];
            first[b] = curEdge;
            to[curEdge] = a;
            from[curEdge] = b;
            ++curEdge;
        }

    }

    static class DFSOrder {
        int[] start;
        int[] end;

        public DFSOrder(Graph tree, int root, int[] p) {
            start = new int[tree.nVertex];
            end = new int[tree.nVertex];
            id0(tree, root, p);
        }

        public boolean isChild(int candidate, int v) {
            return start[v] <= start[candidate] && end[v] >= end[candidate];
        }

        public int start(int v) {
            return start[v];
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
                    stack[top++] = -(v + 1);
                    for (int i = tree.first[v]; i != -1; i = tree.next[i]) {
                        if (p[v] != tree.to[i]) {
                            stack[top++] = (tree.to[i] + 1);
                        }
                    }
                }
            }
        }

    }

    static class LCA {
        public int[] height;
        public int[] dfsOrder;
        public int[] id2;
        public int id8;
        private int block;
        private int[][] blockTable;
        int id1;
        int[] blockHash;
        int[][][] id3;
        int[] log2;
        int[] parent;
        int n;

        public LCA(Graph tree, int root, int[] parent) {
            n = tree.nVertex;
            log2 = new int[2 * n];
            height = new int[n];
            Arrays.fill(height, -1);
            dfsOrder = new int[n * 2 - 1];
            id2 = new int[n];
            id8 = 0;
            this.parent = parent;
            dfsStack(tree, root);
            id1 = log(id8);
            id4();
        }

        private void dfsStack(Graph tree, int v) {
            int[] stackVertex = new int[tree.nVertex * 2];
            int[] stackHeight = new int[tree.nVertex * 2];
            int[] stackEdge = new int[tree.nVertex * 2];
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
                    id2[v] = id8;
                    dfsOrder[id8++] = v;
                } else {
                    dfsOrder[id8++] = v;
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
            while ((1 << res) < n) ++res;
            return res;
        }

        int minHeight(int i, int j) {
            return height[dfsOrder[i]] < height[dfsOrder[j]] ? i : j;
        }

        void id4() {
            block = (id1 + 1) / 2;
            int blocks = id8 / block + ((id8 % block > 0) ? 1 : 0);
            int maxBlocks = ((2 * n) / block) + 2;
            blockHash = new int[maxBlocks + 1];
            blockTable = new int[maxBlocks + 1][id1 + 1];
            id3 = new int[(int) (Math.sqrt(2 * n) + 2)][block + 2][block + 2];
            ArrayUtils.fill(id3, -1);
            ArrayUtils.fill(blockTable, -1);
            Arrays.fill(blockHash, 0);

            

            for (int i = 0, blockId = 0, j = 0; i < id8; ++i, ++j) {
                if (j == block) {
                    j = 0;
                    ++blockId;
                }
                if (blockTable[blockId][0] == -1 || minHeight(i, blockTable[blockId][0]) == i) {
                    blockTable[blockId][0] = i;
                }
            }

            for (int j = 1; j <= id1; ++j) {
                for (int i = 0; i < blocks; ++i) {
                    int ni = i + (1 << (j - 1));
                    if (ni >= blocks) {
                        blockTable[i][j] = blockTable[i][j - 1];
                    } else {
                        blockTable[i][j] = minHeight(blockTable[i][j - 1], blockTable[ni][j - 1]);
                    }
                }
            }

            

            for (int i = 0, blockId = 0, j = 0; i < id8 || j < block; ++i, ++j) {
                if (j == block) {
                    j = 0;
                    ++blockId;
                }
                if (j > 0 && (i >= id8 || minHeight(i - 1, i) == i - 1)) {
                    blockHash[blockId] += (1 << (j - 1));
                }
            }

            

            for (int i = 0; i < blocks; ++i) {
                int id = blockHash[i];
                if (id3[id][0][0] != -1) continue;
                for (int l = 0; l < block; ++l) {
                    id3[id][l][l] = l;
                    for (int r = l + 1; r < block; ++r) {
                        id3[id][l][r] = id3[id][l][r - 1];
                        if (i * block + r < id8) {
                            id3[id][l][r] = minHeight(i * block + id3[id][l][r], i * block + r) - i * block;
                        }
                    }
                }
            }

            

            for (int i = 0, j = 0; i < id8; ++i) {
                if (1 << (j + 1) <= i) ++j;
                log2[i] = j;
            }
        }

        int id5(int blockId, int l, int r) {
            return id3[blockHash[blockId]][l][r] + blockId * block;
        }

        public int LCA(int v, int u) {
            int l = id2[v], r = id2[u];
            if (l > r) {
                int t = l;
                l = r;
                r = t;
            }
            int leftBlock = l / block, rightBlock = r / block;
            if (leftBlock == rightBlock) {
                return dfsOrder[id5(leftBlock, l % block, r % block)];
            }
            int ans1 = id5(leftBlock, l % block, block - 1);
            int ans2 = id5(rightBlock, 0, r % block);
            int ans = minHeight(ans1, ans2);
            if (leftBlock < rightBlock - 1) {
                int pw2 = log2[rightBlock - leftBlock - 1];
                int ans3 = blockTable[leftBlock + 1][pw2];
                int ans4 = blockTable[rightBlock - (1 << pw2)][pw2];
                ans = minHeight(ans, minHeight(ans3, ans4));
            }
            return dfsOrder[ans];
        }

    }

    static class Parent {
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

        public static int[][] id6(Graph tree, int root) {
            int maxLevel = 1;
            while ((1 << maxLevel) <= tree.nVertex) {
                ++maxLevel;
            }
            int[][] parent = new int[maxLevel][tree.nVertex];
            ArrayUtils.fill(parent, -1);
            parent[0] = Parent.run(tree, root);

            for (int level = 1; level < maxLevel; ++level) {
                for (int i = 0; i < tree.nVertex; ++i) {
                    if (parent[level - 1][i] != -1) {
                        int u = parent[level - 1][i];
                        if (parent[level - 1][u] != -1) {
                            int v = parent[level - 1][u];
                            parent[level][i] = v;
                        }
                    }
                }
            }
            return parent;
        }

        public static int[] id9(Graph tree, int root, int[] parent) {
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

    static class id7 {
        long[] sum;
        int n;

        public id7(int n) {
            this.n = n;
            sum = new long[n + 1];
            Arrays.fill(sum, 0);
        }

        public void update(int position, long value) {
            ++position;
            for (int i = position; i <= n; i = next(i)) {
                sum[i] += value;
            }
        }

        private static int prev(int x) {
            return (x & (x - 1));
        }

        private static int next(int x) {
            return (x << 1) - prev(x);
        }

    }
}

