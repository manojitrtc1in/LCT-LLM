


import java.io.*;
import java.util.*;

public class F {

    public static final boolean id19 = false;

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

        

        List<Integer>[] edges;

        void solve() {
            int n = io.nextInt();
            int m = io.nextInt();
            edges = new ArrayList[n+1];
            for (int i=1; i<=n; i++) edges[i] = new ArrayList<>();
            for (int i=0; i<m; i++) {
                int a = io.nextInt();
                int b = io.nextInt();
                edges[a].add(b);
                edges[b].add(a);
            }

            

            

            Path[] bestP = new Path[n+1];
            List<Integer> ans = null;
            int id24 = Integer.MAX_VALUE;
            boolean[] visited = new boolean[n+1];
            int[] depth = new int[n+1];
            Deque<Path> q = new ArrayDeque<>();
            q.add(new Path(1,null, 0));
            while (!q.isEmpty()) {
                Path curr = q.pollFirst();
                if (visited[curr.id]) continue;
                visited[curr.id] = true;
                depth[curr.id] = curr.depth;
                bestP[curr.id] = curr;
                if (curr.id == n) {
                    id24 = -1;
                    ans = new ArrayList<>();
                    while (curr != null) {
                        id24++;
                        ans.add(curr.id);
                        curr = curr.prev;
                    }
                    Collections.reverse(ans);
                    break;
                }
                for (Integer next : edges[curr.id]) {
                    q.addLast(new Path(next, curr, curr.depth+1));
                }
            }

            

            visited = new boolean[n+1];
            visited[1] = true; 

            for (Integer start : edges[1]) {
                if (visited[start]) continue;

                

                HashSet<Integer> group = new HashSet<>();
                group.add(1);
                Node alphaNode = new Node(1,null);
                Node[] from = new Node[n+1];
                from[1] = alphaNode;
                Deque<Node> quu = new ArrayDeque<>();
                quu.add(new Node(start, alphaNode));
                while (!quu.isEmpty()) {
                    Node curr = quu.pollFirst();
                    if (from[curr.id] != null) continue;
                    from[curr.id] = curr;
                    group.add(curr.id);
                    for (Integer next : edges[curr.id]) {
                        quu.addLast(new Node(next, curr));
                    }
                }
                int groupSize = group.size();

                

                Integer id10 = null;
                Deque<Integer> cliQ = new ArrayDeque<>();
                cliQ.add(start);
                while (!cliQ.isEmpty()) {
                    int curr = cliQ.pollFirst();
                    if (visited[curr]) continue;
                    visited[curr] = true;
                    if (depth[curr] == 1 && edges[curr].size()+1 < groupSize && id10 == null) {
                        id10 = curr;
                    }
                    if (depth[curr] == 2 && 4 < id24) {
                        

                        id24 = 4;
                        ans = new ArrayList<>();
                        ans.add(1);
                        ans.add(bestP[curr].prev.id);
                        ans.add(curr);
                        ans.add(1);
                        ans.add(n);
                    }
                    boolean id5 = false;
                    for (Integer next : edges[curr]) {
                        cliQ.addLast(next);
                        if (next.equals(id10)) {
                            id5 = true;
                        }
                    }
                    if (5 < id24 && id10 != null && !id5 && curr != id10) {
                        

                        int a = id10;
                        int c = curr;
                        int b = id9(a, c);
                        id24 = 5;
                        ans = new ArrayList<>();
                        ans.add(1);
                        ans.add(a);
                        ans.add(b);
                        ans.add(c);
                        ans.add(a);
                        ans.add(n);
                    }
                }
            }

            if (ans == null) {
                io.println(-1);
                return;
            }
            io.println(id24);
            for (int i=0; i<ans.size(); i++) {
                io.print(ans.get(i) + " ");
            }
        }

        int id9(int a, int b) {
            HashSet<Integer> set = new HashSet<>();
            for (int next : edges[a]) set.add(next);
            for (int next : edges[b]) {
                if (next != 1 && set.contains(next)) return next;
            }
            throw new RuntimeException("WOOT");
        }

        class Node {
            int id;
            Node from;

            public Node(int id, Node from) {
                this.id = id;
                this.from = from;
            }
        }

        

        long MOD = (long)1e9 + 7;

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

        class Point {
            int y;
            int x;

            public Point(int y, int x) {
                this.y = y;
                this.x = x;
            }
        }

        class Path {
            int id;
            Path prev;
            int depth;

            public Path(int id, Path prev, int depth) {
                this.id = id;
                this.prev = prev;
                this.depth = depth;
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

        int[] id6(int last) {
            
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

        class id11 {
            
            int[] size;
            int[] parent;
            int componentCount;

            public id11(int n) {
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

        class id12 {

            

            int[] nodes;
            int[] depths;
            int[] entries;
            int pointer;
            id3 fenwick;

            public id12(List<Integer>[] graph) {
                this.nodes = new int[(int)10e6];
                this.depths = new int[(int)10e6];
                this.entries = new int[graph.length];
                this.pointer = 1;
                boolean[] visited = new boolean[graph.length+1];
                dfs(1, 0, graph, visited);
                fenwick = new id3(pointer-1);
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

        class id3 {
            long n;
            long[] original;
            long[] bottomUp;
            long[] topDown;

            public id3(int n) {
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

        class id20 {
            public long[] d;

            public id20(int n) {
                d=new long[n+1];
            }

            
            public id20(long[] a) {
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
            long[] p;

            public SegmentTree(int n) {
                
                for (N=2; N<n; N++) N *= 2;
                p = new long[2*N];
            }

            public void modifyRange(int a, int b, long change) {
                muuta(a, change);
                muuta(b+1, -change);
            }

            void muuta(int k, long muutos) {
                k += N;
                p[k] += muutos;
                for (k /= 2; k >= 1; k /= 2) {
                    p[k] = p[2*k] + p[2*k+1];
                }
            }

            public long get(int k) {
                int a = N;
                int b = k+N;
                long s = 0;
                while (a <= b) {
                    if (a%2 == 1) s += p[a++];
                    if (b%2 == 0) s += p[b--];
                    a /= 2;
                    b /= 2;
                }
                return s;
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
                int[] z = id13(s);
                int max = 0;
                for (int i=haku.length(); i<z.length; i++) {
                    max = Math.max(max, z[i]);
                }
                return max;
            }

            public int[] id13(char[] s) {
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
                int[] z = id13(s);
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
                id4();
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

            void id4() {
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

        private static class Prob {

            

            
            private double logP;

            
            public Prob(double real) {
                if (real > 0) this.logP = Math.log(real);
                else this.logP = Double.NaN;
            }

            
            static boolean id7 = true;
            public Prob(double logP, boolean id15) {
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
                if (id16(a) && id16(b)) return new Prob(Double.NaN, id7);
                if (id16(a)) return copy(b);
                if (id16(b)) return copy(a);

                double x = Math.max(a.logP, b.logP);
                double y = Math.min(a.logP, b.logP);
                double sum = x + Math.log(1 + Math.exp(y - x));
                return new Prob(sum, id7);
            }

            
            public static Prob multiply(Prob a, Prob b) {
                if (id16(a) || id16(b)) return new Prob(Double.NaN, id7);
                return new Prob(a.logP + b.logP, id7);
            }

            
            private static boolean id16(Prob p) {
                return (p == null || Double.isNaN(p.logP));
            }

            
            private static Prob copy(Prob original) {
                return new Prob(original.logP, id7);
            }
        }

        public class id14 {

            

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

        class Binary implements Comparable<Binary> {

            

            private boolean[] d;
            private int first; 

            public int length;


            public Binary(String binaryString) {
                this(binaryString, false);
            }
            public Binary(String binaryString, boolean id23) {
                length = binaryString.length();
                int size = Math.max(2*length, 1);
                first = length/4;
                if (id23) {
                    first = 0;
                    size = Math.max(length, 1);
                }
                d = new boolean[size];
                for (int i=0; i<length; i++) {
                    if (binaryString.charAt(i) == '1') d[i+first] = true;
                }
            }

            public void addFirst(char c) {
                if (first-1 < 0) id25();
                first--;
                d[first] = (c == '1' ? true : false);
                length++;
            }

            public void addLast(char c) {
                if (first+length >= d.length) id25();
                d[first+length] = (c == '1' ? true : false);
                length++;
            }

            private void id25() {
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

        class id17 {
            

            
            public long biCo(long n, long k) {
                long r = 1;
                if (k > n) return 0;
                for (long d = 1; d <= k; d++) {
                    r *= n--;
                    r /= d;
                }
                return r;
            }

            
            public long[] id18(int n, int maxK) {
                long v[] = new long[maxK+1];
                v[0] = 1; 

                for (int i=1; i<=n; i++) {
                    for (int j=Math.min(i,maxK); j>0; j--) {
                        v[j] = v[j] + v[j-1]; 

                    }
                }
                return v;
            }

            
            public long[] id18(int n, int k, long M) {
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

        class Trie {
            int N;
            int Z;
            int id8;
            int[][] pointers;
            boolean[] end;

            
            public Trie(int id21, int alphabetSize) {
                this.N = id21;
                this.Z = alphabetSize;
                this.id8 = 1;
                pointers = new int[N+1][alphabetSize];
                end = new boolean[N+1];
            }

            public void addWord(String word) {
                int curr = 0;
                for (int j=0; j<word.length(); j++) {
                    int c = word.charAt(j) - 'a';
                    int next = pointers[curr][c];
                    if (next == 0) {
                        next = id8++;
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

        private class IO extends PrintWriter {
            private InputStreamReader r;
            private static final int id22 = 1 << 15;
            private char[] buf;
            private int bufc;
            private int bufi;
            private StringBuilder sb;

            public IO() {
                super(new BufferedOutputStream(System.out));
                r = new InputStreamReader(System.in);

                buf = new char[id22];
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
                    bufc = r.read(buf, 0, id22);
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

            private void id26() throws IOException {
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

                    id26();
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

                    id26();

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

                    id26();

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

        void debug(Object output) {
            if (id19) {
                System.out.println(output);
            }
        }
    }

}


