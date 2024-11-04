import java.io.*;
import java.time.Duration;
import java.time.Instant;
import java.util.*;

public class Cses {
    static boolean[] table = new boolean[10001];
    static StringBuilder sb = new StringBuilder();
    static TreeSet<String> sn = new TreeSet<>();
    static List<Long> sm = new ArrayList<>();
    static boolean[][] visited = new boolean[7][7];

    static int numberOfWays = 0;

    static class Point {
        int a;
        int b;

        public Point(int a, int b) {
            this.a = a;
            this.b = b;

        }
    }

    static int ways;

    static void dfs(int n, int m, int i, int j, boolean[][] visited, int steps) {

        System.out.println(i + "  " + j);
        boolean r, l, u, d = false;


        visited[i][j] = true;
        steps++;
        if (i < n - 1) if (!visited[i + 1][j]) {
            dfs(n, m, i + 1, j, visited, steps);
        }
        if (j < m - 1) if (!visited[i][j + 1]) dfs(n, m, i, j + 1, visited, steps);
        if (i > 0) if (!visited[i - 1][j]) dfs(n, m, i - 1, j, visited, steps);
        if (j > 0) if (!visited[i][j - 1]) dfs(n, m, i, j - 1, visited, steps);

        if (steps == 3 * 3) ways++;


    }

    static void sieveOfEratosthenes() {
        

        

        


        for (int i = 0; i <= 10000; i++) {
            table[i] = true;
        }

        for (int p = 2; p * p <= 100000000; p++) {
            

            if (table[p]) {
                

                for (int i = p * p; i <= 100000000; i += p)
                    table[i] = false;
            }
        }

        


    }

    public static void minDistance(int[] tab, long s, int index) {
        if (tab.length == index) {
            sm.add(s);
            return;
        }
        int go = tab[index];
        index++;
        minDistance(tab, s, index);
        minDistance(tab, s + go, index);

    }

    public static void steps(int n, int start, int end) {

        int mid = 0;
        if (n == 0) return;
        if (start + end == 3) mid = 3;
        if (start + end == 4) mid = 2;
        if (start + end == 5) mid = 1;
        steps(n - 1, start, mid);
        sb.append(start).append(" ").append(end).append(System.lineSeparator());
        steps(n - 1, mid, end);


    }

    public static void print_rec(LinkedList<String> strings, StringBuilder s) {
        if (strings.size() == 0) {
            sn.add(String.valueOf(s));
            return;
        }
        for (int i = 0; i < strings.size(); i++) {
            StringBuilder ss = new StringBuilder();
            LinkedList<String> subStrings = (LinkedList<String>) strings.clone();
            subStrings.remove(i);

            ss.append(s).append(strings.get(i));
            print_rec(subStrings, ss);


        }

    }

    static boolean[] ld = new boolean[15];
    static boolean[] rd = new boolean[15];
    static boolean[] col = new boolean[8];
    static boolean[][] reserved = new boolean[8][8];

    static void callNumberOfWays(int j) {
        if (j == 8) {
            numberOfWays++;
            return;
        }
        for (int i = 0; i < 8; i++) {
            if (!ld[i + j] && !rd[i - j + 7] && !col[i] && !reserved[j][i]) {

                ld[i + j] = rd[i - j + 7] = col[i] = true;

                callNumberOfWays(j + 1);
                ld[i + j] = rd[i - j + 7] = col[i] = false;
            }

        }


    }

    static int comp(String s1, String s2) {
        char[] tab1 = s1.toCharArray();
        char[] tab2 = s2.toCharArray();
        int res = 0;
        for (int i = 0; i < s1.length(); i++) {
            res += Math.abs(tab1[i] - tab2[i]);
        }
        return res;
    }

    static int binarySearch(ArrayList<Long> arr, int l, int r, long x) {


        if (r >= l) {
            int mid = l + (r - l) / 2;

            

            

            if (arr.get(mid) == x)
                return mid;

            

            

            if (arr.get(mid) > x)
                return binarySearch(arr, l, mid - 1, x);

            

            

            return binarySearch(arr, mid + 1, r, x);
        } else return l;

        

        


    }

    static int binarySearch2(ArrayList<Integer> arr, int l, int r, long x) {


        if (r >= l) {
            int mid = l + (r - l) / 2;

            

            

            if (arr.get(mid) == x)
                return mid;

            

            

            if (arr.get(mid) > x)
                return binarySearch2(arr, l, mid - 1, x);

            

            

            return binarySearch2(arr, mid + 1, r, x);
        } else return l;

        

        


    }

    static public int findComplement(int num) {
        int MSB = (int) (Math.log(num) / Math.log(2)); 

        int mask = ((1 << MSB) | ((int) Math.pow(2, MSB) - 1)); 

        return num ^ mask; 

    }

    static public boolean checkswap(int[][] arr, int n, int m, int in, int io) {

        int[] aa1 = new int[n];
        int[] aa2 = new int[n];
        for (int i = 0; i < n; i++) {
            aa1[i] = arr[i][in];
            aa2[i] = arr[i][io];
        }
        for (int i = 0; i < n; i++) {
            arr[i][io] = aa1[i];
            arr[i][in] = aa2[i];
        }
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (arr[i][j] < arr[i][j - 1]) return false;
            }
        }
        return true;
    }

    static boolean check(int a) {
        if (a == 0) return true;
        else {
            int b = a - 1;
            return ((a & b) == 0);
        }
    }

    ;


    static int findmin(int[] tab, int l, int r) {
        int min = tab[l];
        for (int i = l; i < r; i++) {
            if (tab[i] < min) min = tab[i];
        }
        return min;

    }

    public static void swap(int[] a, int i, int j) {
        int t = a[i];
        a[i] = a[j];
        a[j] = t;
    }

    class Element implements Comparable<Element> {
        int id;
        int ti;
        int ram;

        public Element(int id, int ti, int ram) {
            this.ti = ti;
            this.id = id;
            this.ram = ram;
        }

        @Override
        public int compareTo(Element el) {
            if (el.ti == this.ti) {
                if (el.ram == this.ram) {
                    return el.id - this.id;

                } else return el.ram - this.ram;
            } else return el.ti - this.ti;
        }
    }
    








    



    

    

    static void upper_bound(int arr[], int key) {
        int mid, N = arr.length;

        

        

        int low = 0;
        int high = N;

        

        while (low < high && low != N) {
            

            mid = low + (high - low) / 2;

            

            

            

            if (key >= arr[mid]) {
                low = mid + 1;
            }

            

            

            else {
                high = mid;
            }
        }

        

        

        

        if (low == N) {
            System.out.print("The upper bound of " + key + " does not exist.");
            return;
        }

        

        System.out.print("The upper bound of " + key + " is " + arr[low] + " at index " + low);
    }

    static int recursive_lower_bound(int array[], int low,
                                     int high, int key) {
        

        if (low > high) {
            return low;
        }

        

        int mid = low + (high - low) / 2;

        

        

        

        if (key <= array[mid]) {

            return recursive_lower_bound(array, low,
                    mid - 1, key);
        }

        

        

        return recursive_lower_bound(array, mid + 1, high,
                key);
    }

    

    

    static int lower_bound(int array[], int key) {
        

        

        int low = 0, high = array.length;

        

        return recursive_lower_bound(array, low, high, key);
    }

    static public class pair implements Comparable<pair> {
        int a;
        int b;

        pair(int p, int q) {
            a = p;
            b = q;
        }

        public boolean equals(Object o) {
            if (o instanceof pair) {
                pair p = (pair) o;
                return p.a == a && p.b == b;
            }
            return false;
        }

        public int hashCode() {
            return new Integer(a).hashCode() * 31 + new Integer(b).hashCode();
        }

        @Override
        public int compareTo(pair o) {
            if (this.a == o.a) {
                return o.b - this.b;
            }
            return this.a - o.a;
        }

        @Override
        public String toString() {
            return "pair{" +
                    "a=" + a +
                    ", b=" + b +
                    '}';
        }
    }


    public static void add_map_occurance(HashMap<Integer, Integer> hashMap, int a) {

        if (hashMap.containsKey(a)) hashMap.put(a, hashMap.get(a) + 1);
        else hashMap.put(a, 1);

    }

    public static void rm_map_occurance(HashMap<Integer, Integer> hashMap, int a) {

        if (hashMap.containsKey(a)) {
            if (hashMap.get(a) == 1) hashMap.remove(a);
            else hashMap.put(a, hashMap.get(a) - 1);

        }
    }

    

    

    public static int call(ArrayList<Integer> array, int a, int b, int x) {
        if (a == array.size()) {
            

            return -1;
        }
        if (a > b) return a;
        else {
            int m = (a + b) / 2;
            

            if (array.get(m) == x)
                return m;

            if (array.get(m) < x) return call(array, m + 1, b, x);
            else return call(array, a, m - 1, x);
        }

    }




    

    


    public static void main(String[] args) throws Exception {
        Reader s = new Reader();
        BufferedReader b = new BufferedReader(new InputStreamReader(System.in));
        int t = s.nextInt();
        while (t-- > 0) {
           int n =s.nextInt();
           int x = s.nextInt();
           long[] tab = new long[n];
           TreeMap<Long,Long>  hashMap = new TreeMap<>();
            for (int i = 0; i < n; i++) {
                Long a = s.nextLong();
                tab[i]=a;
                if(hashMap.containsKey(a))hashMap.put(a,hashMap.get(a)+1);
                else hashMap.put(a,1L);
            }
            Arrays.sort(tab);
            HashMap<Long,Long> hashMap1 = new HashMap<>();
            for (int i = 0; i < n; i++) {
                long a = tab[i];
                if(hashMap1.containsKey(a)){
                    if(hashMap1.get(a)>1)hashMap1.put(a,hashMap1.get(a)-1);
                    else hashMap1.remove(a);
                }
                else {
                    long alp = a*x;
                    if(hashMap.containsKey(alp)){
                        if(hashMap.get(a)>1)hashMap.put(a,hashMap.get(a)-1);
                        else hashMap.remove(a);

                        if(hashMap.get(alp)>1)hashMap.put(alp,hashMap.get(alp)-1);
                        else hashMap.remove(alp);
                        if(hashMap1.containsKey(alp))hashMap1.put(alp,hashMap1.get(alp)+1);
                        else hashMap1.put(alp,1L);

                    }

                }

            }
            int res =0;
            for (Map.Entry<Long,Long> en: hashMap.entrySet()
                 ) {
                res += en.getValue();
            }
            System.out.println(res);
        }


    }


    static class Reader {
        final private int BUFFER_SIZE = 1 << 16;
        private DataInputStream din;
        private byte[] buffer;
        private int bufferPointer, bytesRead;

        public Reader() {
            din = new DataInputStream(System.in);
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }

        public Reader(String file_name) throws IOException {
            din = new DataInputStream(
                    new FileInputStream(file_name));
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }

        public String readLine() throws IOException {
            byte[] buf = new byte[64]; 

            int cnt = 0, c;
            while ((c = read()) != -1) {
                if (c == '\n') {
                    if (cnt != 0) {
                        break;
                    } else {
                        continue;
                    }
                }
                buf[cnt++] = (byte) c;
            }
            return new String(buf, 0, cnt);
        }

        public int nextInt() throws IOException {
            int ret = 0;
            byte c = read();
            while (c <= ' ') {
                c = read();
            }
            boolean neg = (c == '-');
            if (neg)
                c = read();
            do {
                ret = ret * 10 + c - '0';
            } while ((c = read()) >= '0' && c <= '9');

            if (neg)
                return -ret;
            return ret;
        }

        public long nextLong() throws IOException {
            long ret = 0;
            byte c = read();
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)
                c = read();
            do {
                ret = ret * 10 + c - '0';
            } while ((c = read()) >= '0' && c <= '9');
            if (neg)
                return -ret;
            return ret;
        }

        public double nextDouble() throws IOException {
            double ret = 0, div = 1;
            byte c = read();
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)
                c = read();

            do {
                ret = ret * 10 + c - '0';
            } while ((c = read()) >= '0' && c <= '9');

            if (c == '.') {
                while ((c = read()) >= '0' && c <= '9') {
                    ret += (c - '0') / (div *= 10);
                }
            }

            if (neg)
                return -ret;
            return ret;
        }

        private void fillBuffer() throws IOException {
            bytesRead = din.read(buffer, bufferPointer = 0,
                    BUFFER_SIZE);
            if (bytesRead == -1)
                buffer[0] = -1;
        }

        private byte read() throws IOException {
            if (bufferPointer == bytesRead)
                fillBuffer();
            return buffer[bufferPointer++];
        }

        public void close() throws IOException {
            if (din == null)
                return;
            din.close();
        }
    }

}