
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.Random;
import java.util.StringTokenizer;


public class ProblemB {

    private BufferedReader in;
    private PrintWriter out;
    private StringTokenizer tok;
    private final String DELIMETER = " ";
    private final boolean ENABLE_MULTITEST = false;
    private final boolean DEBUG = true;
    private final String FILENAME = null;


    public void run() throws Exception {
        initInputOutput();
        do {
            init();
            solve();
        } while (hasMoreTokens() && ENABLE_MULTITEST);
        finish();
    }

    private void init() throws Exception {
    }

    private void solve() throws Exception {
        n = nextInt();
        ai = new int[n + 1];
        for (int i = 2; i <= n; i++) {
            ai[i] = nextInt();
        }
        addsToY1 = new long[n + 1];
        addsToY2 = new long[n + 1];
        was1 = new boolean[n + 1];
        was2 = new boolean[n + 1];
        goingToRoot1 = new boolean[n + 1];
        goingToRoot2 = new boolean[n + 1];
        was1[1] =true;
        was2[1] =true;
        for (int x = 2; x <= n; x++) {
            if (!was1[x]) {
                dfs1(x);
            }
            if (!was2[x]) {
                dfs2(x);
            }
        }
        for (int x = 1; x <= n - 1; x++) {
            if (goingToRoot2[x + 1]) {
                out.println(-1);
            } else {
                if (addsToY2[x + 1] == Long.MAX_VALUE) {
                    out.println(-1);
                } else {
                    out.println(addsToY2[x + 1] + x);
                }
            }
        }


    }

    public void dfs1(int x) {
        if (was1[x]) {
            return;
        }


        out.flush();
        was1[x] = true;
        addsToY1[x] = Long.MAX_VALUE;
        int xN = x + ai[x];
        if (xN == 1) {
            goingToRoot1[x] = true;
        }
        if (xN >= 1 && xN <= n) {
            dfs2(xN);
            if (addsToY2[xN] == Long.MAX_VALUE) {
                addsToY1[x] = Long.MAX_VALUE;
            } else {
                addsToY1[x] = addsToY2[xN] + ai[x];
            }
            goingToRoot1[x] = goingToRoot1[x] || goingToRoot2[xN];
        } else {
            addsToY1[x] = ai[x];
        }
    }

    public void dfs2(int x) {
        if (was2[x]) {
            return;
        }


        out.flush();
        was2[x] = true;
        addsToY2[x] = Long.MAX_VALUE;
        int xN = x - ai[x];
        if (xN == 1) {
            goingToRoot2[x] = true;
        }
        if (xN >= 1 && xN <= n) {
            dfs1(xN);
            if (addsToY1[xN] == Long.MAX_VALUE) {
                addsToY2[x] = Long.MAX_VALUE;
            } else {
                addsToY2[x] = addsToY1[xN] + ai[x];
            }
            goingToRoot2[x] = goingToRoot2[x] || goingToRoot1[xN];
        } else {
            addsToY2[x] = ai[x];
        }
    }
    int n;
    int[] ai;
    long[] addsToY1;
    long[] addsToY2;
    boolean[] was1;
    boolean[] was2;
    boolean[] goingToRoot1;
    boolean[] goingToRoot2;

    public static void main(String[] args) throws Exception {
        ProblemB solution = new ProblemB();
        solution.run();
    }

    private void initInputOutput() throws Exception {
        if (FILENAME == null) {
            in = new BufferedReader(new InputStreamReader(System.in));
            out = new PrintWriter(System.out);
        } else {
            in = new BufferedReader(new FileReader("input.txt"));
            out = new PrintWriter("output.txt");
        }
    }

    private void shuffleArray(Object[] arr) {
        Random r = new Random();
        for (int i = 0; i < arr.length; ++i) {
            Object tmp = arr[i];
            int j = r.nextInt(arr.length);
            arr[i] = arr[j];
            arr[j] = tmp;
        }
    }

    private void shuffleArray(int[] arr) {
        Random r = new Random();
        for (int i = 0; i < arr.length; ++i) {
            int tmp = arr[i];
            int j = r.nextInt(arr.length);
            arr[i] = arr[j];
            arr[j] = tmp;
        }
    }

    private int[] nextArrayInt(int n) throws Exception {
        int[] res = new int[n];
        for (int i = 0; i < n; i++) {
            res[i] = nextInt();
        }
        return res;
    }

    private String nextWord() throws Exception {
        if (updateTokenizer()) {
            return null;
        } else {
            return tok.nextToken();
        }
    }

    private boolean hasMoreTokens() throws Exception {
        return !updateTokenizer();
    }

    private boolean updateTokenizer() throws Exception {
        while (tok == null || !tok.hasMoreTokens()) {
            String nextLine = in.readLine();
            if (nextLine == null || nextLine.isEmpty()) {
                return true;
            }
            tok = new StringTokenizer(nextLine, DELIMETER);
        }
        return false;
    }

    private int nextInt() throws Exception {
        return Integer.parseInt(nextWord());
    }

    private long nextLong() throws Exception {
        return Long.parseLong(nextWord());
    }

    private void finish() throws Exception {
        in.close();
        out.close();
    }

    private void print(String s) {
        if (DEBUG) {
            System.out.print(s);
        }
    }

    private void println(String s) {
        if (DEBUG) {
            System.out.println(s);
        }
    }

    private void println() {
        if (DEBUG) {
            System.out.println();
        }
    }

    private long[] getFirstSimpleNums(int n) {
        boolean[] notPr = new boolean[n];
        int res = n;
        notPr[0] = true;
        res--;
        notPr[1] = true;
        res--;
        for (int i = 2; i < n; ++i) {
            if (!notPr[i]) {
                for (int j = i + i; j < n; j += i) {
                    if (!notPr[j]) {
                        notPr[j] = true;
                        res--;
                    }
                }
            }
        }
        long[] resA = new long[res];
        int next = 0;
        for (int i = 0; i < n; i++) {
            if (!notPr[i]) {
                resA[next] = i;
                next++;
            }
        }
        return resA;
    }

    private static class Pair {

        int a;
        int b;

        public Pair(int a, int b) {
            this.a = a;
            this.b = b;
        }
        public static final Comparator<Pair> comparator = new Comparator<Pair>() {

            @Override
            public int compare(Pair pair1, Pair pair2) {
                return (pair1.a - pair2.a) != 0 ? (pair1.a - pair2.a) : (pair1.b - pair2.b);
            }
        };

        @Override
        public String toString() {
            return "{" + a + "|" + b + '}';
        }
    }

    class TreeMin {

        int n;
        int[] t;

        public TreeMin(int size, int[] defaultValue) {
            n = 1;
            while (n < size) {
                n *= 2;
            }
            t = new int[2 * n];
            for (int i = 0; i < defaultValue.length; i++) {
                t[n + i] = defaultValue[i];
            }
            for (int i = defaultValue.length; i < n; i++) {
                t[n + i] = Integer.MAX_VALUE;
            }
            for (int i = n - 1; i >= 1; i--) {
                t[i] = Math.min(t[2 * i], t[2 * i + 1]);
            }
        }

        public void set(int index, int value) {
            index += n;
            t[index] = value;
            index /= 2;
            while (index >= 1) {
                t[index] = Math.min(t[2 * index], t[2 * index + 1]);
                index /= 2;
            }
        }

        
        public int getMin(int l, int r) {
            int min = Integer.MAX_VALUE;
            l += n;
            r += n;
            while (l <= r) {
                if (l % 2 == 1) {
                    min = Math.min(min, t[l]);
                    l++;
                }
                if (r % 2 == 0) {
                    min = Math.min(min, t[r]);
                    r--;
                }
                l /= 2;
                r /= 2;
            }
            return min;
        }
    }

    class PriorityQueue {

        int size = 0;
        int capacity = 5;
        int[] key = new int[capacity];
        int[] value = new int[capacity];
        int[] idByInd = new int[capacity];
        int nextID = 0;
        ArrayList<Integer> indById = new ArrayList<Integer>();

        void ensureCapacity(int newSize) {
            if (newSize > capacity) {
                key = increaseArray(key);
                value = increaseArray(value);
                idByInd = increaseArray(idByInd);
                capacity = key.length;
            }
        }

        int[] increaseArray(int[] a) {
            int[] res = new int[Math.max(a.length * 2, 1)];
            for (int i = 0; i < a.length; i++) {
                res[i] = a[i];
            }
            for (int i = a.length; i < res.length; i++) {
                res[i] = Integer.MAX_VALUE;
            }
            return res;
        }

        void swap(int ind1, int ind2) {
            swap(key, ind1, ind2);
            swap(value, ind1, ind2);
            int id1 = idByInd[ind1];
            int id2 = idByInd[ind2];
            swap(idByInd, ind1, ind2);
            swap(indById, id1, id2);
        }

        void swap(int[] a, int ind1, int ind2) {
            int tmp = a[ind1];
            a[ind1] = a[ind2];
            a[ind2] = tmp;
        }

        void swap(ArrayList<Integer> a, int ind1, int ind2) {
            int tmp = a.get(ind1);
            a.set(ind1, a.get(ind2));
            a.set(ind2, tmp);
        }

        int parent(int index) {
            return (index - 1) / 2;
        }

        private void siftUp(int index) {
            while (index > 0) {
                int parent = parent(index);
                if (key[index] < key[parent]) {
                    swap(index, parent);
                }
                index = parent;
            }
        }

        private void siftDown(int index) {
            while (true) {
                int ch1 = 2 * index + 1;
                int ch2 = 2 * index + 2;
                if (ch1 >= size) {
                    ch1 = index;
                }
                if (ch2 >= size) {
                    ch2 = ch1;
                }
                int toSwap = index;
                if (key[ch1] < key[toSwap]) {
                    toSwap = ch1;
                }
                if (key[ch2] < key[toSwap]) {
                    toSwap = ch2;
                }
                if (toSwap == index) {
                    break;
                } else {
                    swap(index, toSwap);
                    index = toSwap;
                }
            }
        }

        public int push(int key, int value) {
            size++;
            ensureCapacity(size);
            int id = nextID;
            nextID++;
            this.key[size - 1] = key;
            this.value[size - 1] = value;
            this.idByInd[size - 1] = id;
            indById.add(size - 1);
            siftUp(size - 1);
            return id;
        }

        public void decreaseKey(int id, int key) {
            int ind = indById.get(id);
            while (key > this.key[ind]) {
            }
            this.key[ind] = key;
            siftUp(ind);
        }
        public final int EMPTY = Integer.MIN_VALUE;

        public int extractMinKey() {
            if (size == 0) {
                return EMPTY;
            } else {
                int res = key[0];
                swap(0, size - 1);
                size--;
                siftDown(0);
                return res;
            }
        }
















    }




























































































































































































































































}