

import java.io.*;
import java.util.*;
import java.lang.*;

public class A {

    private static int dist(int[] x, int[] y) {
        return Math.abs(x[0]-y[0]) + Math.abs(x[1]-y[1]);
    }

    private static boolean same(int[] x, int[] y) {
        return x[0] == y[0] || x[1] == y[1];
    }

    public static void main(String[] args) throws Exception {
        setIO();
        int t = nextInt();
        while (t-- > 0) {
            int[] a = nextInts(2);
            int[] b = nextInts(2);
            int[] f = nextInts(2);

            int af = dist(a, f);
            int fb = dist(f, b);
            int ab = dist(a, b);

            if (same(a, b)) {
                if (same(a, f)) {
                    if (af >= ab) {
                        System.out.println(ab);
                    } else {
                        if (af+fb > ab) {
                            System.out.println(ab);
                        } else {
                            System.out.println(ab + 2);
                        }
                    }
                } else {
                    System.out.println(ab);
                }
            } else {
                System.out.println(ab);
            }
        }
    }

    
    private static class Pair<T, K> {
        T key;
        K value;

        public Pair(T key, K value) {
            this.key = key;
            this.value = value;
        }
    }


    
    private static boolean isPalindrome(String s) {
        return isPalindrome(s, 0, s.length()-1);
    }

    private static boolean isPalindrome(String s, int start, int end) {
        for (int i = start, j = end; i < j; ++i, --j)
            if (s.charAt(i) != s.charAt(j))
                return false;
        return true;
    }


    
    

    private static boolean[] id3(int number) {
        boolean[] seive = new boolean[number];
        if ( number > 2 ) {
            for ( int num = 2; num * num <= number - 1; ++num ) {
                if ( !seive[num] ) {
                    for ( int mult = num * 2; mult < seive.length; mult += num ) {
                        seive[mult] = true;
                    }
                }
            }
        }
        return seive;
    }

    private static boolean isPalindrome(long number) {
        String str = Long.toString(number);
        for (int i = 0, j = str.length() - 1; i <= j; ++i, --j) {
            if (str.charAt(i) != str.charAt(j))
                return false;
        }
        return true;
    }

    private static long gcd(long a, long b) {
        return a == 0 ? b : gcd(b % a, a);
    }

    private static long gcd(int a, int b) {
        return a == 0 ? b : gcd(b % a, a);
    }


    
    private static class UnionFind {

        private int groups;
        private final int[] parent;
        private boolean zeroIndexed = true;

        public UnionFind(int size) {
            groups = size;
            parent = new int[size];
            Arrays.fill(parent, -1);
        }

        public UnionFind(int size, boolean zeroIndexed) {
            groups = size;
            if (zeroIndexed)
                parent = new int[size];
            else
                parent = new int[size+1];
            Arrays.fill(parent, -1);
            this.zeroIndexed = zeroIndexed;
        }

        
        public int id1() {
            return this.groups;
        }

        
        public int find(int u) {
            if ( parent[u] < 0 )
                return u;
            return parent[u] = find(parent[u]);
        }

        
        public boolean union(int u, int v) {
            int pu = find(u);
            int pv = find(v);
            if ( pu != pv ) {
                

                if ( parent[pu] <= parent[pv] ) {
                    parent[pv] = pu;
                    parent[pu]--;
                } else {
                    parent[pu] = pv;
                    parent[pv]--;
                }
                groups--;
                return true;
            }
            

            return false;
        }
    }

    private static class IntGraph {
        public final Map<Integer, Map<Integer, Integer>> adj = new HashMap<>();
        public List<int[]> edges;
        public final int size;
        public final boolean isDirected;
        public IntGraph(int size, boolean isDirected) {
            this.size = size;
            this.isDirected = isDirected;
            this.edges = new ArrayList<>(size);
            for (int u = 0; u < size; ++u)
                adj.put(u, new HashMap<>());
        }
        public IntGraph(int size, boolean isDirected, int[][] edges) {
            this(size, isDirected);
            for (int[] edge: edges)
                addEdge(edge);
        }
        public void addEdge(int[] edge) {
            int from = edge[0],
                    to = edge[1],
                    weight = edge.length == 3 ? edge[2] : 0;
            adj.get(from).put(to, weight);
            edges.add(new int[]{from, to, weight});
            if (!isDirected) {
                adj.get(to).put(from, weight);
                edges.add(new int[]{to, from, weight});
            }
        }

        

        private boolean id2(int u, boolean[] visited, boolean[] path) {
            if (!visited[u]) {
                visited[u] = true;
                path[u] = true;
                for (int v: adj.get(u).keySet()) {
                    if (!visited[v]) {
                        if (id2(v, visited, path))
                            return true;
                    } else if (path[v])
                        return true;
                }
            }
            path[u] = false;
            return false;
        }
        public boolean id2() {
            boolean[] visited = new boolean[size];
            boolean[] path = new boolean[size];
            for (int u = 0; u < size; ++u) {
                if (!visited[u] && id2(u, visited, path)) {
                    return true;
                }
            }
            return false;
        }

        

        public boolean isTree() {
            boolean[] visited = new boolean[size];
            boolean[] path = new boolean[size];
            if (id2(0, visited, path))
                return false;
            for (boolean vis: visited)
                if (!vis) return false;
            return true;
        }

        

        public int[] id4() {
            int[] indegree = new int[size];
            int[] ans = new int[size];
            boolean[] visited = new boolean[size];
            Queue<Integer> q = new LinkedList<>();
            adj.values().stream().map(Map::keySet).flatMap(Collection::stream).forEach(u -> indegree[u]++);
            for (int u = 0; u < size; u++) {
                if (indegree[u] == 0) {
                    q.add(u);
                }
            }
            int j = 0;
            while (!q.isEmpty()) {
                int u = q.poll();
                ans[j++] = u;
                for (int v: adj.get(u).keySet()) {
                    if (!visited[v] && --indegree[v] == 0) {
                        q.add(v);
                        visited[v] = true;
                    }
                }
            }
            if (j < size)
                return new int[]{};
            return ans;
        }

        

        public int[] dijkstra(int source) {
            int[] dist = new int[size];
            boolean[] visited = new boolean[size];
            Arrays.fill(dist, Integer.MAX_VALUE);
            dist[source] = 0;
            Queue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(v -> v[0]));
            pq.add(new int[]{0, source});

            while (!pq.isEmpty()) {
                int d = pq.peek()[0],
                        u = pq.poll()[1];
                if (visited[u])
                    continue;
                visited[u] = true;
                for (Map.Entry<Integer, Integer> e: adj.get(u).entrySet()) {
                    int v = e.getKey(),
                            w = e.getValue();
                    if (d + w < dist[v]) {
                        dist[v] = d + w;
                        pq.add(new int[]{dist[v], v});
                    }
                }
            }

            return dist;
        }

        

        public int[] id13(int source) {
            int[] dist = new int[size];
            Arrays.fill(dist, Integer.MAX_VALUE);
            dist[source] = 0;
            for (int i = 0; i < size-1; ++i) {
                for (int[] edge: edges) {
                    int from = edge[0], to = edge[1], weight = edge[2];
                    if (dist[from] != Integer.MAX_VALUE && dist[from] + weight < dist[to]) {
                        dist[to] = dist[from] + weight;
                    }
                }
            }
            for (int[] edge: edges) {
                int from = edge[0], to = edge[1], weight = edge[2];
                if (dist[from] != Integer.MAX_VALUE && dist[from] + weight < dist[to]) {
                    

                    return new int[]{};
                }
            }
            return dist;
        }

        

        public int[][] id7() {
            int[][] dist = new int[size][size];
            for (int u = 0; u < size; ++u) {
                Arrays.fill(dist[u], Integer.MAX_VALUE);
                dist[u][u] = 0;
                for (Map.Entry<Integer, Integer> e: adj.get(u).entrySet()) {
                    dist[u][e.getKey()] = e.getValue();
                }
            }
            for (int k = 0; k < size; ++k) {
                for (int u = 0; u < size; ++u) {
                    for (int v = 0; v < size; ++v) {
                        if (dist[u][k] != Integer.MAX_VALUE && dist[k][v] != Integer.MAX_VALUE
                                && dist[u][k] + dist[k][v] < dist[u][v]) {
                            dist[u][v] = dist[u][k] + dist[k][v];
                        }
                    }
                }
            }
            return dist;
        }

        

        public IntGraph id11() {
            IntGraph mst = new IntGraph(size, isDirected);
            edges.sort(Comparator.comparingInt(e -> e[2]));
            UnionFind uf = new UnionFind(size);
            for (int[] edge: edges) {
                if (uf.union(edge[0], edge[2])) {
                    mst.addEdge(edge);
                }
            }
            return mst;
        }

        

        public IntGraph prim() {
            boolean[] visited = new boolean[size];
            Queue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(e -> e[2]));
            IntGraph mst = new IntGraph(size, isDirected);
            int randomSource = new Random().nextInt(size);
            for (Map.Entry<Integer, Integer> edge: adj.get(randomSource).entrySet())
                pq.add(new int[]{randomSource, edge.getKey(), edge.getValue()});
            visited[randomSource] = true;

            while (!pq.isEmpty()) {
                int u = pq.peek()[0],
                        v = pq.peek()[1],
                        w = pq.poll()[2];
                if (visited[v])
                    continue;
                visited[v] = true;
                mst.addEdge(new int[]{u, v, w});
                for (Map.Entry<Integer, Integer> edge: adj.get(v).entrySet())
                    pq.add(new int[]{v, edge.getKey(), edge.getValue()});
            }
            return mst;
        }
    }


    
    private static int id10(List<Integer> arr, int value) {
        if (arr.isEmpty())
            return 0;
        int l = 0, r = arr.size()-1;
        while (l < r) {
            int m = l + (r-l) / 2;
            if (arr.get(m) == value) {
                while (m-1 > -1 && arr.get(m-1) == value)
                    --m;
                return m;
            } else if (arr.get(m) < value) {
                l = m+1;
            } else {
                r = m-1;
            }
        }
        if (arr.get(l) == value) {
            while (arr.get(l) == value && l - 1 > -1 && arr.get(l-1) == value)
                l--;
            return l;
        }
        return arr.get(l) < value ? l+1 : l;
    }

    private static int id10(int[] arr, int value) {
        if (arr.length == 0)
            return 0;
        int l = 0, r = arr.length-1;
        while (l < r) {
            int m = l + (r-l) / 2;
            if (arr[m] == value) {
                while (m-1 > -1 && arr[m-1] == value)
                    --m;
                return m;
            } else if (arr[m] < value) {
                l = m+1;
            } else {
                r = m-1;
            }
        }
        if (arr[l] == value) {
            while (arr[l] == value && l - 1 > -1 && arr[l - 1] == value)
                l--;
            return l;
        }
        return arr[l] < value ? l+1 : l;
    }

    private static int id0(int[] arr, int value) {
        if (arr.length == 0)
            return 0;
        int l = 0, r = arr.length-1;
        while (l < r) {
            int m = l + (r-l) / 2;
            if (arr[m] == value) {
                while (m+1 < arr.length && arr[m+1] == value)
                    ++m;
                return m+1;
            } else if (arr[m] < value) {
                l = m+1;
            } else {
                r = m-1;
            }
        }
        if (arr[l] == value) {
            while (arr[l] == value && l+1 < arr.length && arr[l+1] == value)
                l++;
            return l+1;
        }
        return arr[l] < value ? l+1 : l;
    }

    private static int id0(List<Integer> arr, int value) {
        if (arr.isEmpty())
            return 0;
        int l = 0, r = arr.size()-1;
        while (l < r) {
            int m = l + (r-l) / 2;
            if (arr.get(m) == value) {
                while (m+1 < arr.size() && arr.get(m+1) == value)
                    ++m;
                return m+1;
            } else if (arr.get(m) < value) {
                l = m+1;
            } else {
                r = m-1;
            }
        }
        if (arr.get(l) == value) {
            while (arr.get(l) == value && l+1 < arr.size() && arr.get(l+1) == value)
                l++;
            return l+1;
        }
        return arr.get(l) < value ? l+1 : l;
    }


    
    private static BufferedReader rd = rd = new BufferedReader(new InputStreamReader(System.in));
    private static StringTokenizer tkn = new StringTokenizer("");

    

    

    

    private static void setIO() throws Exception {
        if (System.getProperty("ONLINE_JUDGE") == null) {
            rd = new BufferedReader(new FileReader("input.txt"));
            System.setOut(new PrintStream(new FileOutputStream("output.txt")));
        }
    }

    

    private static int nextInt() throws Exception {
        while (!tkn.hasMoreTokens())
            tkn = new StringTokenizer(rd.readLine());
        return Integer.parseInt(tkn.nextToken());
    }

    private static int[] nextInts(int n) throws Exception {
        while (!tkn.hasMoreTokens())
            tkn = new StringTokenizer(rd.readLine());
        int[] ans = new int[n];
        for (int i = 0; i < n; i++)
            ans[i] = Integer.parseInt(tkn.nextToken());
        return ans;
    }

    private static List<Integer> id12(int n) throws Exception {
        if (!tkn.hasMoreTokens())
            tkn = new StringTokenizer(rd.readLine());
        List<Integer> ans = new ArrayList<>(n);
        for (int i = 0; i < n; i++)
            ans.add(Integer.parseInt(tkn.nextToken()));
        return ans;
    }

    

    private static long nextLong() throws Exception {
        if (!tkn.hasMoreTokens())
            tkn = new StringTokenizer(rd.readLine());
        return Long.parseLong(tkn.nextToken());
    }

    private static long[] id5(int n) throws Exception {
        if (!tkn.hasMoreTokens())
            tkn = new StringTokenizer(rd.readLine());
        long[] ans = new long[n];
        for (int i = 0; i < n; i++)
            ans[i] = Long.parseLong(tkn.nextToken());
        return ans;
    }

    private static List<Long> id8(int n) throws Exception {
        if (!tkn.hasMoreTokens())
            tkn = new StringTokenizer(rd.readLine());
        List<Long> ans = new ArrayList<>(n);
        for (int i = 0; i < n; i++)
            ans.add(Long.parseLong(tkn.nextToken()));
        return ans;
    }

    

    private static double nextDouble() throws Exception {
        if (!tkn.hasMoreTokens())
            tkn = new StringTokenizer(rd.readLine());
        return Double.parseDouble(tkn.nextToken());
    }

    private static double[] nextDouble(int n) throws Exception {
        if (!tkn.hasMoreTokens())
            tkn = new StringTokenizer(rd.readLine());
        double[] ans = new double[n];
        for (int i = 0; i < n; i++)
            ans[i] = Double.parseDouble(tkn.nextToken());
        return ans;
    }

    private static List<Double> id9(int n) throws Exception {
        if (!tkn.hasMoreTokens())
            tkn = new StringTokenizer(rd.readLine());
        List<Double> ans = new ArrayList<>(n);
        for (int i = 0; i < n; i++)
            ans.add(Double.parseDouble(tkn.nextToken()));
        return ans;
    }

    

    private static String nextString() throws Exception {
        if (!tkn.hasMoreTokens())
            tkn = new StringTokenizer(rd.readLine());
        return tkn.nextToken();
    }

    private static String[] nextStrings(int n) throws Exception {
        if (!tkn.hasMoreTokens())
            tkn = new StringTokenizer(rd.readLine());
        String[] ans = new String[n];
        for (int i = 0; i < n; i++)
            ans[i] = tkn.nextToken();
        return ans;
    }

    private static List<String> id6(int n) throws Exception {
        if (!tkn.hasMoreTokens())
            tkn = new StringTokenizer(rd.readLine());
        List<String> ans = new ArrayList<>(n);
        for (int i = 0; i < n; i++)
            ans.add(tkn.nextToken());
        return ans;
    }

}