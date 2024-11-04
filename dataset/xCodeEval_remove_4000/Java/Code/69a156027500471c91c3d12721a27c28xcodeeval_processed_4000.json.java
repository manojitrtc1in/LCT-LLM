


import java.io.*;
import java.util.*;

public class D {

    public static void main(String[] args) {
        Solver solver = new Solver();
    }

    static class Solver {
        IO io;

        public Solver() {
            this.io = new IO();
            try {
                solve();
            } finally {
                io.close();
            }
        }

        

        void solve() {
            int n = io.nextInt();
            Team[] leaderboard = new Team[n];
            for (int i=0; i<n; i++) {
                long b = io.nextLong();
                long w = io.nextLong();
                long id12 = w - b + 1;
                boolean id7 = (i==0);
                Team t = new Team(b, id12, id7);
                leaderboard[i] = t;
            }
            Arrays.sort(leaderboard);

            PriorityQueue<Target> targets = new PriorityQueue<>();
            long best = -666; 

            int id20 = -666;
            for (int i=0 ;; i++) {
                Team t = leaderboard[i];
                if (t.id7) {
                    best = i;
                    id20 = i;
                    break;
                }
                targets.add(new Target(t.id12));
            }


            Team limak = leaderboard[id20];
            int enemyDrops = 0;
            while (limak.b > 0 && best > 0 && !targets.isEmpty()) {
                Target t = targets.poll();
                if (t.id12 > limak.b) continue;
                limak.b -= t.id12;
                enemyDrops++;
                


                

                while (id20 <= n-2 && leaderboard[id20+1].b > limak.b) {
                    Team vihu = leaderboard[id20+1];
                    

                    leaderboard[id20] = vihu;
                    targets.add(new Target(vihu.id12));
                    id20++;
                }
                leaderboard[id20] = limak;

                long curr = id20 - enemyDrops;
                

                best = Math.min(best, curr);
            }

            io.println(best+1);
        }

        class Team implements Comparable<Team> {
            boolean id7;
            long b;
            long id12;

            public Team(long b, long id12, boolean id7) {
                this.b = b;
                this.id12 = id12;
                this.id7 = id7;
            }

            @Override
            public int compareTo(Team o) {
                if (this.b > o.b) return -1;
                if (o.b > this.b) return 1;
                if (this.id7) return -1;
                if (o.id7) return 1;
                return 0;
            }
        }

        class Target implements Comparable<Target> {
            long id12;

            public Target(long id12) {
                this.id12 = id12;
            }

            @Override
            public int compareTo(Target o) {
                if (this.id12 < o.id12) return -1;
                if (o.id12 < this.id12) return 1;
                return 0;
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

        long pow(long base, int exp) {
            if (exp == 0) return 1L;
            long x = pow(base, exp/2);
            long ans = x * x;
            if (exp % 2 != 0) ans *= base;
            return ans;
        }

        class ElementCounter {
            private HashMap<Long, Long> elements;

            public ElementCounter() {
                elements = new HashMap<>();
            }

            public void add(long element) {
                long count = 1;
                if (elements.containsKey(element)) count += elements.get(element);
                elements.put(element, count);
            }

            public void remove(long element) {
                long count = elements.get(element);
                count--;
                if (count == 0) elements.remove(element);
                else elements.put(element, count);
            }

            public long get(long element) {
                if (!elements.containsKey(element)) return 0;
                return elements.get(element);
            }

            public int size() {
                return elements.size();
            }
        }

        class StringCounter {
            HashMap<String, Long> elements;

            public StringCounter() {
                elements = new HashMap<>();
            }

            public void add(String identifier) {
                long count = 1;
                if (elements.containsKey(identifier)) count += elements.get(identifier);
                elements.put(identifier, count);
            }

            public void remove(String identifier) {
                long count = elements.get(identifier);
                count--;
                if (count == 0) elements.remove(identifier);
                else elements.put(identifier, count);
            }

            public long get(String identifier) {
                if (!elements.containsKey(identifier)) return 0;
                return elements.get(identifier);
            }

            public int size() {
                return elements.size();
            }
        }

        class id8 {

            

            int[] nodes;
            int[] depths;
            int[] entries;
            int pointer;
            id3 fenwick;

            public id8(List<Integer>[] graph) {
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

        class id16 {
            public long[] d;

            public id16(int n) {
                d=new long[n+1];
            }

            
            public id16(long[] a) {
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
                
                N = n;
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
                int[] z = id9(s);
                int max = 0;
                for (int i=haku.length(); i<z.length; i++) {
                    max = Math.max(max, z[i]);
                }
                return max;
            }

            public int[] id9(char[] s) {
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
                int[] z = id9(s);
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

            
            static boolean id6 = true;
            public Prob(double logP, boolean id11) {
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
                if (id13(a) && id13(b)) return new Prob(Double.NaN, id6);
                if (id13(a)) return copy(b);
                if (id13(b)) return copy(a);

                double x = a.logP;
                double y = b.logP;
                double sum = x + Math.log(1 + Math.exp(y - x));
                return new Prob(sum, id6);
            }

            
            public static Prob multiply(Prob a, Prob b) {
                if (id13(a) || id13(b)) return new Prob(Double.NaN, id6);
                return new Prob(a.logP + b.logP, id6);
            }

            
            private static boolean id13(Prob p) {
                return (p == null || Double.isNaN(p.logP));
            }

            
            private static Prob copy(Prob original) {
                return new Prob(original.logP, id6);
            }
        }

        public class id10 {

            

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
            public Binary(String binaryString, boolean id18) {
                length = binaryString.length();
                int size = Math.max(2*length, 1);
                first = length/4;
                if (id18) {
                    first = 0;
                    size = Math.max(length, 1);
                }
                d = new boolean[size];
                for (int i=0; i<length; i++) {
                    if (binaryString.charAt(i) == '1') d[i+first] = true;
                }
            }

            public void addFirst(char c) {
                if (first-1 < 0) id19();
                first--;
                d[first] = (c == '1' ? true : false);
                length++;
            }

            public void addLast(char c) {
                if (first+length >= d.length) id19();
                d[first+length] = (c == '1' ? true : false);
                length++;
            }

            private void id19() {
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

        class id14 {
            

            
            public long biCo(long n, long k) {
                long r = 1;
                if (k > n) return 0;
                for (long d = 1; d <= k; d++) {
                    r *= n--;
                    r /= d;
                }
                return r;
            }

            
            public long[] id15(int n, int maxK) {
                long v[] = new long[maxK+1];
                v[0] = 1; 

                for (int i=1; i<=n; i++) {
                    for (int j=Math.min(i,maxK); j>0; j--) {
                        v[j] = v[j] + v[j-1]; 

                    }
                }
                return v;
            }

            
            public long[] id15(int n, int k, long M) {
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

        class id5 {

            
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
        }

        private class IO extends PrintWriter {
            private InputStreamReader r;
            private static final int id17 = 1 << 15;
            private char[] buf;
            private int bufc;
            private int bufi;
            private StringBuilder sb;

            public IO() {
                super(new BufferedOutputStream(System.out));
                r = new InputStreamReader(System.in);

                buf = new char[id17];
                bufc = 0;
                bufi = 0;
                sb = new StringBuilder();
            }

            private void fillBuf() throws IOException {
                bufi = 0;
                bufc = 0;
                while(bufc == 0) {
                    bufc = r.read(buf, 0, id17);
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

            private void id21() throws IOException {
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

                    id21();
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

                    id21();

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

                    id21();

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
    }

}

