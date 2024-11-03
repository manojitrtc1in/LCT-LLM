


import java.io.*;
import java.util.*;

public class E {

    public static void main(String[] args) {
        Solver solver = new Solver();
    }

    static class Solver {
        IO io;

        public Solver() {
            this.io = new IO();
            try {
                solve();
            } catch (RuntimeException e) {
                if (!e.getMessage().equals("Clean exit")) {
                    throw e;
                }
            } finally {
                io.close();
            }
        }

        

        int n;
        List<Integer>[] g;

        long[] size;
        int[] depth;

        void solve() {
            n = io.nextInt();
            g = toGraph(io, n);
            size = new long[n+1];
            depth = new int[n+1];

            prep(1, 0, 0);
            long s = id9(1, 0);
            long o = calcO();
            io.println((s+o)/2);
        }

        void prep(int curr, int d, int prev) {
            depth[curr] = d;
            int sum = 1;
            for (int child : g[curr]) {
                if (child == prev) continue;
                prep(child, d+1, curr);
                sum += size[child];
            }
            size[curr] = sum;
        }

        long id9(int curr, int prev) {
            long ans = size[curr] * (n - size[curr]);
            for (int child : g[curr]) {
                if (child == prev) continue;
                ans += id9(child, curr);
            }
            return ans;
        }

        long calcO() {
            long countOdd = 0;
            long countEven = 0;
            for (int i=1; i<=n; i++) {
                if (depth[i] % 2 == 0) countEven++;
                else countOdd++;
            }
            return countEven * countOdd;
        }


        

        long MOD = (long)1e9 + 7;

        boolean id12(double v) {
            

            return Math.abs(v) <= 0.0000000001;
        }

        class DrawGrid {

            void draw(boolean[][] d) {
                System.out.print("  ");
                for (int x=0; x<d[0].length; x++) {
                    System.out.print(" " + x + " ");
                }
                System.out.println("");
                for (int y=0; y<d.length; y++) {
                    System.out.print(y + " ");
                    for (int x=0; x<d[0].length; x++) {
                        System.out.print((d[y][x] ? "[x]" : "[ ]"));
                    }
                    System.out.println("");
                }
            }

            void draw(int[][] d) {
                int max = 1;
                for (int y=0; y<d.length; y++) {
                    for (int x=0; x<d[0].length; x++) {
                        max = Math.max(max, ("" + d[y][x]).length());
                    }
                }
                System.out.print("  ");
                String format = "%" + (max+2) + "s";
                for (int x=0; x<d[0].length; x++) {
                    System.out.print(String.format(format, x) + " ");
                }
                format = "%" + (max) + "s";
                System.out.println("");
                for (int y=0; y<d.length; y++) {
                    System.out.print(y + " ");
                    for (int x=0; x<d[0].length; x++) {
                        System.out.print(" [" + String.format(format, (d[y][x])) + "]");
                    }
                    System.out.println("");
                }
            }

        }

        class IDval implements Comparable<IDval> {
            int id;
            long val;

            public IDval(int id, long val) {
                this.val = val;
                this.id = id;
            }

            @Override
            public int compareTo(IDval o) {
                if (this.val < o.val) return -1;
                if (this.val > o.val) return 1;
                return this.id - o.id;
            }
        }

        private class ElementCounter {
            private HashMap<Long, Integer> elements;

            public ElementCounter() {
                elements = new HashMap<>();
            }

            public void add(long element) {
                int count = 1;
                Integer prev = elements.get(element);
                if (prev != null) count += prev;
                elements.put(element, count);
            }

            public void remove(long element) {
                int count = elements.remove(element);
                count--;
                if (count > 0) elements.put(element, count);
            }

            public int get(long element) {
                Integer val = elements.get(element);
                if (val == null) return 0;
                return val;
            }

            public int size() {
                return elements.size();
            }
        }

        class StringCounter {
            HashMap<String, Integer> elements;

            public StringCounter() {
                elements = new HashMap<>();
            }

            public void add(String identifier) {
                int count = 1;
                Integer prev = elements.get(identifier);
                if (prev != null) count += prev;
                elements.put(identifier, count);
            }

            public void remove(String identifier) {
                int count = elements.remove(identifier);
                count--;
                if (count > 0) elements.put(identifier, count);
            }

            public long get(String identifier) {
                Integer val = elements.get(identifier);
                if (val == null) return 0;
                return val;
            }

            public int size() {
                return elements.size();
            }
        }

        class id19 {
            
            int[] size;
            int[] parent;
            int componentCount;

            public id19(int n) {
                componentCount = n;
                size = new int[n];
                parent = new int[n];
                for (int i=0; i<n; i++) parent[i] = i;
                for (int i=0; i<n; i++) size[i] = 1;
            }

            public void join(int a, int b) {
                
                int rootA = parent[a];
                int rootB = parent[b];
                while (rootA != parent[rootA]) rootA = parent[rootA];
                while (rootB != parent[rootB]) rootB = parent[rootB];

                if (rootA == rootB) {
                    
                    return;
                }

                
                if (size[rootA] > size[rootB]) {
                    size[rootA] += size[rootB];
                    parent[rootB] = rootA;
                } else {
                    size[rootB] += size[rootA];
                    parent[rootA] = rootB;
                }
                componentCount--;
            }

        }

        class Trie {
            int N;
            int Z;
            int id14;
            int[][] pointers;
            boolean[] end;

            
            public Trie(int id37, int alphabetSize) {
                this.N = id37;
                this.Z = alphabetSize;
                this.id14 = 1;
                pointers = new int[N+1][alphabetSize];
                end = new boolean[N+1];
            }

            public void addWord(String word) {
                int curr = 0;
                for (int j=0; j<word.length(); j++) {
                    int c = word.charAt(j) - 'a';
                    int next = pointers[curr][c];
                    if (next == 0) {
                        next = id14++;
                        pointers[curr][c] = next;
                    }
                    curr = next;
                }
                end[curr] = true;
            }

            public boolean hasWord(String word) {
                int curr = 0;
                for (int j=0; j<word.length(); j++) {
                    int c = word.charAt(j) - 'a';
                    int next = pointers[curr][c];
                    if (next == 0) return false;
                    curr = next;
                }
                return end[curr];
            }

        }

        private static class Prob {

            

            
            private double logP;

            
            public Prob(double real) {
                if (real > 0) this.logP = Math.log(real);
                else this.logP = Double.NaN;
            }

            
            static boolean id11 = true;
            public Prob(double logP, boolean id28) {
                this.logP = logP;
            }

            
            public double get() {
                return Math.exp(logP);
            }

            @Override
            public String toString() {
                return ""+get();
            }

            

            
            public static Prob add(Prob a, Prob b) {
                if (id31(a) && id31(b)) return new Prob(Double.NaN, id11);
                if (id31(a)) return copy(b);
                if (id31(b)) return copy(a);

                double x = Math.max(a.logP, b.logP);
                double y = Math.min(a.logP, b.logP);
                double sum = x + Math.log(1 + Math.exp(y - x));
                return new Prob(sum, id11);
            }

            
            public static Prob multiply(Prob a, Prob b) {
                if (id31(a) || id31(b)) return new Prob(Double.NaN, id11);
                return new Prob(a.logP + b.logP, id11);
            }

            
            private static boolean id31(Prob p) {
                return (p == null || Double.isNaN(p.logP));
            }

            
            private static Prob copy(Prob original) {
                return new Prob(original.logP, id11);
            }
        }

        class Binary implements Comparable<Binary> {

            

            private boolean[] d;
            private int first; 

            public int length;


            public Binary(String binaryString) {
                this(binaryString, false);
            }
            public Binary(String binaryString, boolean id41) {
                length = binaryString.length();
                int size = Math.max(2*length, 1);
                first = length/4;
                if (id41) {
                    first = 0;
                    size = Math.max(length, 1);
                }
                d = new boolean[size];
                for (int i=0; i<length; i++) {
                    if (binaryString.charAt(i) == '1') d[i+first] = true;
                }
            }

            public void addFirst(char c) {
                if (first-1 < 0) id44();
                first--;
                d[first] = (c == '1' ? true : false);
                length++;
            }

            public void addLast(char c) {
                if (first+length >= d.length) id44();
                d[first+length] = (c == '1' ? true : false);
                length++;
            }

            private void id44() {
                boolean[] bigArray = new boolean[(d.length+1) * 2];
                int newFirst = bigArray.length / 4;
                for (int i=0; i<length; i++) {
                    bigArray[i + newFirst] = d[i + first];
                }
                first = newFirst;
                d = bigArray;
            }

            public boolean flip(int i) {
                boolean value = (this.d[first+i] ? false : true);
                this.d[first+i] = value;
                return value;
            }

            public void set(int i, char c) {
                boolean value = (c == '1' ? true : false);
                this.d[first+i] = value;
            }

            public char get(int i) {
                return (this.d[first+i] ? '1' : '0');
            }

            @Override
            public int compareTo(Binary o) {
                if (this.length != o.length) return this.length - o.length;
                int len = this.length;
                for (int i=0; i<len; i++) {
                    int diff = this.get(i) - o.get(i);
                    if (diff != 0) return diff;
                }
                return 0;
            }

            @Override
            public String toString() {
                StringBuilder sb = new StringBuilder();
                for (int i=0; i<length; i++) {
                    sb.append(d[i+first] ? '1' : '0');
                }
                return sb.toString();
            }


        }

        

        class id4 {
            long n;
            long[] original;
            long[] bottomUp;
            long[] topDown;

            public id4(int n) {
                this.n = n;
                original = new long[n+2];
                bottomUp = new long[n+2];
                topDown = new long[n+2];
            }

            public void set(int modifiedNode, long value) {
                long replaced = original[modifiedNode];
                original[modifiedNode] = value;
                

                int i = modifiedNode;
                long v = value;
                while (i <= n) {
                    if (v > bottomUp[i]) {
                        if (replaced == bottomUp[i]) {
                            v = Math.min(v, original[i]);
                            for (int r=1 ;; r++) {
                                int x = (i&-i)>>>r;
                                if (x == 0) break;
                                int child = i-x;
                                v = Math.min(v, bottomUp[child]);
                            }
                        } else break;
                    }
                    if (v == bottomUp[i]) break;
                    bottomUp[i] = v;
                    i += (i&-i);
                }
                

                i = modifiedNode;
                v = value;
                while (i > 0) {
                    if (v > topDown[i]) {
                        if (replaced == topDown[i]) {
                            v = Math.min(v, original[i]);
                            for (int r=1 ;; r++) {
                                int x = (i&-i)>>>r;
                                if (x == 0) break;
                                int child = i+x;
                                if (child > n+1) break;
                                v = Math.min(v, topDown[child]);
                            }
                        } else break;
                    }
                    if (v == topDown[i]) break;
                    topDown[i] = v;
                    i -= (i&-i);
                }
            }

            public long getMin(int a, int b) {
                long min = original[a];
                int prev = a;
                int curr = prev + (prev&-prev); 

                while (curr <= b) {
                    min = Math.min(min, topDown[prev]); 

                    prev = curr;
                    curr = prev + (prev&-prev);;
                }
                min = Math.min(min, original[prev]);
                prev = b;
                curr = prev - (prev&-prev); 

                while (curr >= a) {
                    min = Math.min(min,bottomUp[prev]); 

                    prev = curr;
                    curr = prev - (prev&-prev);
                }
                return min;
            }

        }

        class id38 {
            public long[] d;

            public id38(int n) {
                d=new long[n+1];
            }

            
            public id38(long[] a) {
                d=new long[a.length];
                for (int i=1; i<a.length; i++) {
                    modify(i, a[i]);
                }
            }

            
            void modify(int i, long v) {
                while (i<d.length) {
                    d[i] += v;
                    

                    i += (i&-i);
                }
            }

            
            long getSum(int a, int b) {
                return getSum(b) - getSum(a-1);
            }

            private long getSum(int i) {
                long sum = 0;
                while (i>0) {
                    sum += d[i];
                    

                    i -= (i&-i);
                }
                return sum;
            }
        }

        class SegmentTree {

            

            int N;
            long[] lazy;
            long[] sum;
            long[] min;
            long[] max;
            boolean supportSum;
            boolean supportMin;
            boolean supportMax;

            public SegmentTree(int n) {
                this(n, true, true, true);
            }

            public SegmentTree(int n, boolean supportSum, boolean supportMin, boolean supportMax) {
                for (N=2; N<n;) N*=2;
                this.lazy = new long[2*N];
                this.supportSum = supportSum;
                this.supportMin = supportMin;
                this.supportMax = supportMax;
                if (this.supportSum) this.sum = new long[2*N];
                if (this.supportMin) this.min = new long[2*N];
                if (this.supportMax) this.max = new long[2*N];
            }

            void modifyRange(long x, int a, int b) {
                modifyRec(a, b, 1, 0, N-1, x);
            }

            void setRange() {
                

            }

            long getSum(int a, int b) {
                return querySum(a, b, 1, 0, N-1);
            }

            long getMin(int a, int b) {
                return queryMin(a, b, 1, 0, N-1);
            }

            long getMax(int a, int b) {
                return queryMax(a, b, 1, 0, N-1);
            }

            private long querySum(int wantedLeft, int wantedRight, int i, int actualLeft, int actualRight) {
                if (wantedLeft > actualRight || wantedRight < actualLeft) {
                    return 0;
                }
                if (wantedLeft == actualLeft && wantedRight == actualRight) {
                    int count = wantedRight - wantedLeft + 1;
                    return sum[i] + count * lazy[i];
                }
                if (lazy[i] != 0) propagate(i, actualLeft, actualRight);
                int d = (actualRight - actualLeft + 1) / 2;
                long left = querySum(wantedLeft, min(actualLeft+d-1, wantedRight), 2*i, actualLeft, actualLeft+d-1);
                long right = querySum(max(actualLeft+d, wantedLeft), wantedRight, 2*i+1, actualLeft+d, actualRight);
                return left + right;
            }

            private long queryMin(int wantedLeft, int wantedRight, int i, int actualLeft, int actualRight) {
                if (wantedLeft > actualRight || wantedRight < actualLeft) {
                    return 0;
                }
                if (wantedLeft == actualLeft && wantedRight == actualRight) {
                    return min[i] + lazy[i];
                }
                if (lazy[i] != 0) propagate(i, actualLeft, actualRight);
                int d = (actualRight - actualLeft + 1) / 2;
                long left = queryMin(wantedLeft, min(actualLeft+d-1, wantedRight), 2*i, actualLeft, actualLeft+d-1);
                long right = queryMin(max(actualLeft+d, wantedLeft), wantedRight, 2*i+1, actualLeft+d, actualRight);
                return min(left, right);
            }

            private long queryMax(int wantedLeft, int wantedRight, int i, int actualLeft, int actualRight) {
                if (wantedLeft > actualRight || wantedRight < actualLeft) {
                    return 0;
                }
                if (wantedLeft == actualLeft && wantedRight == actualRight) {
                    return max[i] + lazy[i];
                }
                if (lazy[i] != 0) propagate(i, actualLeft, actualRight);
                int d = (actualRight - actualLeft + 1) / 2;
                long left = queryMax(wantedLeft, min(actualLeft+d-1, wantedRight), 2*i, actualLeft, actualLeft+d-1);
                long right = queryMax(max(actualLeft+d, wantedLeft), wantedRight, 2*i+1, actualLeft+d, actualRight);
                return max(left, right);
            }

            private void modifyRec(int wantedLeft, int wantedRight, int i, int actualLeft, int actualRight, long value) {
                if (wantedLeft > actualRight || wantedRight < actualLeft) {
                    return;
                }
                if (wantedLeft == actualLeft && wantedRight == actualRight) {
                    lazy[i] += value;
                    return;
                }
                if (lazy[i] != 0) propagate(i, actualLeft, actualRight);
                int d = (actualRight - actualLeft + 1) / 2;
                modifyRec(wantedLeft, min(actualLeft+d-1, wantedRight), 2*i, actualLeft, actualLeft+d-1, value);
                modifyRec(max(actualLeft+d, wantedLeft), wantedRight, 2*i+1, actualLeft+d, actualRight, value);
                if (supportSum) sum[i] += value * (min(actualRight, wantedRight) - max(actualLeft, wantedLeft) + 1);
                if (supportMin) min[i] = min(min[2*i] + lazy[2*i], min[2*i+1] + lazy[2*i+1]);
                if (supportMax) max[i] = max(max[2*i] + lazy[2*i], max[2*i+1] + lazy[2*i+1]);
            }

            private void propagate(int i, int actualLeft, int actualRight) {
                lazy[2*i] += lazy[i];
                lazy[2*i+1] += lazy[i];
                if (supportSum) sum[i] += lazy[i] * (actualRight - actualLeft + 1);
                if (supportMin) min[i] += lazy[i];
                if (supportMax) max[i] += lazy[i];
                lazy[i] = 0;
            }

        }

        

        List<Integer>[] toGraph(IO io, int n) {
            List<Integer>[] g = new ArrayList[n+1];
            for (int i=1; i<=n; i++) g[i] = new ArrayList<>();
            for (int i=1; i<=n-1; i++) {
                int a = io.nextInt();
                int b = io.nextInt();
                g[a].add(b);
                g[b].add(a);
            }
            return g;
        }

        class Graph {
            HashMap<Long, List<Long>> edges;

            public Graph() {
                edges = new HashMap<>();
            }

            List<Long> id23(Long node) {
                List<Long> neighbors = edges.get(node);
                if (neighbors == null) {
                    neighbors = new ArrayList<>();
                    edges.put(node, neighbors);
                }
                return neighbors;
            }

            void id15(Long a, Long b) {
                addEdge(a, b);
                addEdge(b, a);
            }

            void addEdge(Long from, Long to) {
                id23(to); 

                List<Long> neighbors = id23(from);
                neighbors.add(to);
            }

            

            int id29 = 0;
            int FINISHED = 2;
            int id3 = 1;
            HashMap<Long, Integer> vis;
            List<Long> id26;
            List<Long> id16 = new ArrayList<Long>() {{ add(-1L); }};

            List<Long> id43() {
                id26 = new ArrayList<>();
                vis = new HashMap<>();
                for (Long a : edges.keySet()) {
                    if (!id20(a)) return id16;
                }
                Collections.reverse(id26);
                return id26;
            }

            boolean id20(long curr) {
                Integer status = vis.get(curr);
                if (status == null) status = id29;
                if (status == FINISHED) return true;
                if (status == id3) {
                    return false;
                }
                vis.put(curr, id3);
                for (long next : edges.get(curr)) {
                    if (!id20(next)) return false;
                }
                vis.put(curr, FINISHED);
                id26.add(curr);
                return true;
            }

        }

        public class id25 {

            

            ArrayList<Integer>[] forw;
            ArrayList<Integer>[] bacw;

            
            public int getCount(int n, int[] mista, int[] minne) {
                forw = new ArrayList[n+1];
                bacw = new ArrayList[n+1];
                for (int i=1; i<=n; i++) {
                    forw[i] = new ArrayList<Integer>();
                    bacw[i] = new ArrayList<Integer>();
                }
                for (int i=0; i<mista.length; i++) {
                    int a = mista[i];
                    int b = minne[i];
                    forw[a].add(b);
                    bacw[b].add(a);
                }
                int count = 0;
                List<Integer> list = new ArrayList<Integer>();
                boolean[] visited = new boolean[n+1];
                for (int i=1; i<=n; i++) {
                    dfsForward(i, visited, list);
                }
                visited = new boolean[n+1];
                for (int i=n-1; i>=0; i--) {
                    int node = list.get(i);
                    if (visited[node]) continue;
                    count++;
                    dfsBackward(node, visited);
                }
                return count;
            }

            public void dfsForward(int i, boolean[] visited, List<Integer> list) {
                if (visited[i]) return;
                visited[i] = true;
                for (int neighbor : forw[i]) {
                    dfsForward(neighbor, visited, list);
                }
                list.add(i);
            }

            public void dfsBackward(int i, boolean[] visited) {
                if (visited[i]) return;
                visited[i] = true;
                for (int neighbor : bacw[i]) {
                    dfsBackward(neighbor, visited);
                }
            }
        }

        class id22 {

            

            int[] nodes;
            int[] depths;
            int[] entries;
            int pointer;
            id4 fenwick;

            public id22(List<Integer>[] graph) {
                this.nodes = new int[(int)10e6];
                this.depths = new int[(int)10e6];
                this.entries = new int[graph.length];
                this.pointer = 1;
                boolean[] visited = new boolean[graph.length+1];
                dfs(1, 0, graph, visited);
                fenwick = new id4(pointer-1);
                for (int i=1; i<pointer; i++) {
                    fenwick.set(i, depths[i] * 1000000L + i);
                }
            }

            private void dfs(int node, int depth, List<Integer>[] graph, boolean[] visited) {
                visited[node] = true;
                entries[node] = pointer;
                nodes[pointer] = node;
                depths[pointer] = depth;
                pointer++;
                for (int neighbor : graph[node]) {
                    if (visited[neighbor]) continue;
                    dfs(neighbor, depth+1, graph, visited);
                    nodes[pointer] = node;
                    depths[pointer] = depth;
                    pointer++;
                }
            }

            public int find(int a, int b) {
                int left = entries[a];
                int right = entries[b];
                if (left > right) {
                    int temp = left;
                    left = right;
                    right = temp;
                }
                long mixedBag = fenwick.getMin(left, right);
                int index = (int) (mixedBag % 1000000L);
                return nodes[index];
            }
        }

        

        class Point {
            int y;
            int x;

            public Point(int y, int x) {
                this.y = y;
                this.x = x;
            }
        }

        boolean segmentsIntersect(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) {
            


            if (x1 == x2 && x3 == x4) {
                

                if (x1 != x3) return false;
                if (min(y1,y2) < min(y3,y4)) {
                    return max(y1,y2) >= min(y3,y4);
                } else {
                    return max(y3,y4) >= min(y1,y2);
                }
            }
            if (x1 == x2) {
                

                double a34 = (y4-y3)/(x4-x3);
                double b34 = y3 - a34*x3;
                double y = a34 * x1 + b34;
                return y >= min(y1,y2) && y <= max(y1,y2) && x1 >= min(x3,x4) && x1 <= max(x3,x4);
            }
            if (x3 == x4) {
                

                double a12 = (y2-y1)/(x2-x1);
                double b12 = y1 - a12*x1;
                double y = a12 * x3 + b12;
                return y >= min(y3,y4) && y <= max(y3,y4) && x3 >= min(x1,x2) && x3 <= max(x1,x2);
            }
            double a12 = (y2-y1)/(x2-x1);
            double b12 = y1 - a12*x1;
            double a34 = (y4-y3)/(x4-x3);
            double b34 = y3 - a34*x3;
            if (id12(a12 - a34)) {
                

                return id12(b12 - b34);
            }
            

            double x = -(b12-b34)/(a12-a34);
            return x >= min(x1,x2) && x <= max(x1,x2) && x >= min(x3,x4) && x <= max(x3,x4);
        }

        boolean id30(Point p, List<Point> r, boolean id27) {
            Point a = r.get(0);
            Point b = r.get(1);
            Point c = r.get(2);
            Point d = r.get(3);
            double apd = id7(a, p, d);
            double dpc = id7(d, p, c);
            double cpb = id7(c, p, b);
            double pba = id7(p, b, a);
            double id35 = apd + dpc + cpb + pba;
            if (id12(id35 - id42(r))) {
                if (id12(apd) || id12(dpc) || id12(cpb) || id12(pba)) {
                    return id27;
                }
                return true;
            }
            return false;
        }

        double id7(Point a, Point b, Point c) {
            return 0.5 * Math.abs((a.x-c.x)*(b.y-a.y)-(a.x-b.x)*(c.y-a.y));
        }

        double id42(List<Point> r) {
            double id39 = r.get(0).x - r.get(1).x;
            double id6 = r.get(0).y - r.get(1).y;
            double id32 = r.get(1).x - r.get(2).x;
            double id21 = r.get(1).y - r.get(2).y;
            double side1 = Math.sqrt(id39 * id39 + id6 * id6);
            double side2 = Math.sqrt(id32 * id32 + id21 * id21);
            return side1 * side2;
        }

        boolean id13(double x1, double y1, double x2, double y2, double x3, double y3) {
            double id10 = x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2);
            return (id12(id10));
        }

        class id17 {

            

            double id18(double point_x, double point_y, double x1, double y1, double x2, double y2) {
                return Math.sqrt(id34(point_x, point_y, x1, y1, x2, y2));
            }

            private double id34(double point_x, double point_y, double x1, double y1, double x2, double y2) {
                double l2 = dist2(x1,y1,x2,y2);
                if (l2 == 0) return dist2(point_x, point_y, x1, y1);
                double t = ((point_x - x1) * (x2 - x1) + (point_y - y1) * (y2 - y1)) / l2;
                if (t < 0) return dist2(point_x, point_y, x1, y1);
                if (t > 1) return dist2(point_x, point_y, x2, y2);

                double com_x = x1 + t * (x2 - x1);
                double com_y = y1 + t * (y2 - y1);
                return dist2(point_x, point_y, com_x, com_y);
            }

            private double dist2(double x1, double y1, double x2, double y2) {
                return Math.pow((x1 - x2), 2) + Math.pow((y1 - y2), 2);
            }

        }

        

        long pow(long base, int exp) {
            if (exp == 0) return 1L;
            long x = pow(base, exp/2);
            long ans = x * x;
            if (exp % 2 != 0) ans *= base;
            return ans;
        }

        long gcd(long... v) {
            
            if (v.length == 1) return v[0];
            long ans = gcd(v[1], v[0]);
            for (int i=2; i<v.length; i++) {
                ans = gcd(ans, v[i]);
            }
            return ans;
        }

        long gcd(long a, long b) {
            
            if (b == 0) return a;
            return gcd(b, a%b);
        }

        int[] id8(int last) {
            
            int[] div = new int[last+1];
            for (int x=2; x<=last; x++) {
                if (div[x] > 0) continue;
                for (int u=2*x; u<=last; u+=x) {
                    div[u] = x;
                }
            }
            return div;
        }

        long lcm(long a, long b) {
            
            return a * b / gcd(a,b);
        }

        class BaseConverter {

            
            public String convert(Long number, int base) {
                return Long.toString(number, base);
            }

            
            public String convert(String number, int baseFrom, int baseTo) {
                return Long.toString(Long.parseLong(number, baseFrom), baseTo);
            }

            
            public long longify(String number, int baseFrom) {
                return Long.parseLong(number, baseFrom);
            }
        }

        class id33 {
            

            
            public long biCo(long n, long k) {
                long r = 1;
                if (k > n) return 0;
                for (long d = 1; d <= k; d++) {
                    r *= n--;
                    r /= d;
                }
                return r;
            }

            
            public long[] id36(int n, int maxK) {
                long v[] = new long[maxK+1];
                v[0] = 1; 

                for (int i=1; i<=n; i++) {
                    for (int j=Math.min(i,maxK); j>0; j--) {
                        v[j] = v[j] + v[j-1]; 

                    }
                }
                return v;
            }

            
            public long[] id36(int n, int k, long M) {
                long v[] = new long[k+1];
                v[0] = 1; 

                for (int i=1; i<=n; i++) {
                    for (int j=Math.min(i,k); j>0; j--) {
                        v[j] = v[j] + v[j-1]; 

                        v[j] %= M;
                    }
                }
                return v;
            }
        }

        

        class Zalgo {

            public int id1(String haku, String kohde) {
                char[] s = new char[haku.length() + 1 + kohde.length()];
                for (int i=0; i<haku.length(); i++) {
                    s[i] = haku.charAt(i);
                }
                int j = haku.length();
                s[j++] = '
                for (int i=0; i<kohde.length(); i++) {
                    s[j++] = kohde.charAt(i);
                }
                int[] z = id24(s);
                int max = 0;
                for (int i=haku.length(); i<z.length; i++) {
                    max = Math.max(max, z[i]);
                }
                return max;
            }

            public int[] id24(char[] s) {
                int n = s.length;
                int[] z = new int[n];
                int a = 0, b = 0;
                for (int i = 1; i < n; i++) {
                    if (i > b) {
                        for (int j = i; j < n && s[j - i] == s[j]; j++)  z[i]++;
                    }
                    else {
                        z[i] = z[i - a];
                        if (i + z[i - a] > b) {
                            for (int j = b + 1; j < n && s[j - i] == s[j]; j++) z[i]++;
                            a = i;
                            b = i + z[i] - 1;
                        }
                    }
                }
                return z;
            }

            public List<Integer> id2(String haku, String kohde) {
                

                char[] s = new char[haku.length() + 1 + kohde.length()];
                for (int i=0; i<haku.length(); i++) {
                    s[i] = haku.charAt(i);
                }
                int j = haku.length();
                s[j++] = '
                for (int i=0; i<kohde.length(); i++) {
                    s[j++] = kohde.charAt(i);
                }
                int[] z = id24(s);
                List<Integer> indexes = new ArrayList<>();
                for (int i=haku.length(); i<z.length; i++) {
                    if (z[i] < haku.length()) continue;
                    indexes.add(i);
                }
                return indexes;
            }

        }

        class StringHasher {

            class id0 {
                long[] hashes;
                long[] modifiers;

                public id0(long[] hashes, long[] modifiers) {
                    this.hashes = hashes;
                    this.modifiers = modifiers;
                }
            }

            long P;
            long M;

            public StringHasher() {
                id5();
            }

            id0 hashString(String s) {
                int n = s.length();
                long[] hashes = new long[n];
                long[] modifiers = new long[n];
                hashes[0] = s.charAt(0);
                modifiers[0] = 1;
                for (int i=1; i<n; i++) {
                    hashes[i] = (hashes[i-1] * P + s.charAt(i)) % M;
                    modifiers[i] = (modifiers[i-1] * P) % M;
                }
                return new id0(hashes, modifiers);
            }

            
            long getHash(id0 hashedString, int startIndex, int endIndex) {
                long[] hashes = hashedString.hashes;
                long[] modifiers = hashedString.modifiers;
                long result = hashes[endIndex];
                if (startIndex > 0) result -= (hashes[startIndex-1] * modifiers[endIndex-startIndex+1]) % M;
                if (result < 0) result += M;
                return result;
            }

            




            
            id0[] hashString(String first, String second) {
                id0[] array = new id0[2];
                int n = first.length();
                long[] modifiers = new long[n];
                modifiers[0] = 1;

                long[] firstHashes = new long[n];
                firstHashes[0] = first.charAt(0);
                array[0] = new id0(firstHashes, modifiers);

                long[] secondHashes = new long[n];
                secondHashes[0] = second.charAt(0);
                array[1] = new id0(secondHashes, modifiers);

                for (int i=1; i<n; i++) {
                    modifiers[i] = (modifiers[i-1] * P) % M;
                    firstHashes[i] = (firstHashes[i-1] * P + first.charAt(i)) % M;
                    secondHashes[i] = (secondHashes[i-1] * P + second.charAt(i)) % M;
                }
                return array;
            }

            
            id0[] hashString(String... strings) {
                id0[] array = new id0[strings.length];
                int n = strings[0].length();
                long[] modifiers = new long[n];
                modifiers[0] = 1;
                for (int j=0; j<strings.length; j++) {
                    

                    if (strings[j].length() != n) {
                        for (int i=0; i<n; i++) {
                            array[i] = hashString(strings[i]);
                        }
                        return array;
                    }

                    

                    long[] hashes = new long[n];
                    hashes[0] = strings[j].charAt(0);
                    array[j] = new id0(hashes, modifiers);
                }
                for (int i=1; i<n; i++) {
                    modifiers[i] = (modifiers[i-1] * P) % M;
                    for (int j=0; j<strings.length; j++) {
                        String s = strings[j];
                        long[] hashes = array[j].hashes;
                        hashes[i] = (hashes[i-1] * P + s.charAt(i)) % M;
                    }
                }
                return array;
            }

            void id5() {
                ArrayList<Long> modOptions = new ArrayList<>(20);
                modOptions.add(353873237L);
                modOptions.add(353875897L);
                modOptions.add(353878703L);
                modOptions.add(353882671L);
                modOptions.add(353885303L);
                modOptions.add(353888377L);
                modOptions.add(353893457L);
                P = modOptions.get(new Random().nextInt(modOptions.size()));

                modOptions.clear();
                modOptions.add(452940277L);
                modOptions.add(452947687L);
                modOptions.add(464478431L);
                modOptions.add(468098221L);
                modOptions.add(470374601L);
                modOptions.add(472879717L);
                modOptions.add(472881973L);
                M = modOptions.get(new Random().nextInt(modOptions.size()));

            }
        }

        int editDistance(String a, String b) {
            a = "
            b = "
            int n = a.length();
            int m = b.length();
            int[][] dp = new int[n+1][m+1];
            for (int y=0; y<=n; y++) {
                for (int x=0; x<=m; x++) {
                    if (y == 0) dp[y][x] = x;
                    else if (x == 0) dp[y][x] = y;
                    else {
                        int e1 = dp[y-1][x] + 1;
                        int e2 = dp[y][x-1] + 1;
                        int e3 = dp[y-1][x-1] + (a.charAt(y-1) != b.charAt(x-1) ? 1 : 0);
                        dp[y][x] = min(e1, e2, e3);
                    }
                }
            }
            return dp[n][m];
        }

        

        private class IO extends PrintWriter {
            private InputStreamReader r;
            private static final int id40 = 1 << 15;
            private char[] buf;
            private int bufc;
            private int bufi;
            private StringBuilder sb;

            public IO() {
                super(new BufferedOutputStream(System.out));
                r = new InputStreamReader(System.in);

                buf = new char[id40];
                bufc = 0;
                bufi = 0;
                sb = new StringBuilder();
            }

            
            private int queryInt(String s) {
                io.println(s);
                io.flush();
                return nextInt();
            }

            
            private long queryLong(String s) {
                io.println(s);
                io.flush();
                return nextLong();
            }

            
            private String queryNext(String s) {
                io.println(s);
                io.flush();
                return next();
            }

            private void fillBuf() throws IOException {
                bufi = 0;
                bufc = 0;
                while(bufc == 0) {
                    bufc = r.read(buf, 0, id40);
                    if(bufc == -1) {
                        bufc = 0;
                        return;
                    }
                }
            }

            private boolean pumpBuf() throws IOException {
                if(bufi == bufc) {
                    fillBuf();
                }
                return bufc != 0;
            }

            private boolean isDelimiter(char c) {
                return c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\f';
            }

            private void id45() throws IOException {
                while(true) {
                    if(bufi == bufc) {
                        fillBuf();
                        if(bufc == 0) throw new RuntimeException("IO: Out of input.");
                    }

                    if(!isDelimiter(buf[bufi])) break;
                    ++bufi;
                }
            }

            public String next() {
                try {
                    sb.setLength(0);

                    id45();
                    int start = bufi;

                    while(true) {
                        if(bufi == bufc) {
                            sb.append(buf, start, bufi - start);
                            fillBuf();
                            start = 0;
                            if(bufc == 0) break;
                        }

                        if(isDelimiter(buf[bufi])) break;
                        ++bufi;
                    }

                    sb.append(buf, start, bufi - start);

                    return sb.toString();
                } catch(IOException e) {
                    throw new RuntimeException("IO.next: Caught IOException.");
                }
            }

            public int nextInt() {
                try {
                    int ret = 0;

                    id45();

                    boolean positive = true;
                    if(buf[bufi] == '-') {
                        ++bufi;
                        if(!pumpBuf()) throw new RuntimeException("IO.nextInt: Invalid int.");
                        positive = false;
                    }

                    boolean first = true;
                    while(true) {
                        if(!pumpBuf()) break;
                        if(isDelimiter(buf[bufi])) {
                            if(first) throw new RuntimeException("IO.nextInt: Invalid int.");
                            break;
                        }
                        first = false;

                        if(buf[bufi] >= '0' && buf[bufi] <= '9') {
                            if(ret < -214748364) throw new RuntimeException("IO.nextInt: Invalid int.");
                            ret *= 10;
                            ret -= (int)(buf[bufi] - '0');
                            if(ret > 0) throw new RuntimeException("IO.nextInt: Invalid int.");
                        } else {
                            throw new RuntimeException("IO.nextInt: Invalid int.");
                        }

                        ++bufi;
                    }

                    if(positive) {
                        if(ret == -2147483648) throw new RuntimeException("IO.nextInt: Invalid int.");
                        ret = -ret;
                    }

                    return ret;
                } catch(IOException e) {
                    throw new RuntimeException("IO.nextInt: Caught IOException.");
                }
            }

            public long nextLong() {
                try {
                    long ret = 0;

                    id45();

                    boolean positive = true;
                    if(buf[bufi] == '-') {
                        ++bufi;
                        if(!pumpBuf()) throw new RuntimeException("IO.nextLong: Invalid long.");
                        positive = false;
                    }

                    boolean first = true;
                    while(true) {
                        if(!pumpBuf()) break;
                        if(isDelimiter(buf[bufi])) {
                            if(first) throw new RuntimeException("IO.nextLong: Invalid long.");
                            break;
                        }
                        first = false;

                        if(buf[bufi] >= '0' && buf[bufi] <= '9') {
                            if(ret < -922337203685477580L) throw new RuntimeException("IO.nextLong: Invalid long.");
                            ret *= 10;
                            ret -= (long)(buf[bufi] - '0');
                            if(ret > 0) throw new RuntimeException("IO.nextLong: Invalid long.");
                        } else {
                            throw new RuntimeException("IO.nextLong: Invalid long.");
                        }

                        ++bufi;
                    }

                    if(positive) {
                        if(ret == -9223372036854775808L) throw new RuntimeException("IO.nextLong: Invalid long.");
                        ret = -ret;
                    }

                    return ret;
                } catch(IOException e) {
                    throw new RuntimeException("IO.nextLong: Caught IOException.");
                }
            }

            public double nextDouble() {
                return Double.parseDouble(next());
            }

        }

        void print(Object output) {
            io.println(output);
        }

        void done(Object output) {
            print(output);
            done();
        }

        void done() {
            io.close();
            throw new RuntimeException("Clean exit");
        }

        long min(long... v) {
            long ans = v[0];
            for (int i=1; i<v.length; i++) {
                ans = Math.min(ans, v[i]);
            }
            return ans;
        }

        double min(double... v) {
            double ans = v[0];
            for (int i=1; i<v.length; i++) {
                ans = Math.min(ans, v[i]);
            }
            return ans;
        }

        int min(int... v) {
            int ans = v[0];
            for (int i=1; i<v.length; i++) {
                ans = Math.min(ans, v[i]);
            }
            return ans;
        }

        long max(long... v) {
            long ans = v[0];
            for (int i=1; i<v.length; i++) {
                ans = Math.max(ans, v[i]);
            }
            return ans;
        }

        double max(double... v) {
            double ans = v[0];
            for (int i=1; i<v.length; i++) {
                ans = Math.max(ans, v[i]);
            }
            return ans;
        }

        int max(int... v) {
            int ans = v[0];
            for (int i=1; i<v.length; i++) {
                ans = Math.max(ans, v[i]);
            }
            return ans;
        }

    }

}