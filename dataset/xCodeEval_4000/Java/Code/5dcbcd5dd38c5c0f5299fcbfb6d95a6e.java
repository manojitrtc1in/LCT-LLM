import java.util.Comparator;
import java.math.*;
import java.util.Arrays;
import java.awt.*;
import javax.swing.text.Segment;
import java.io.*;
import java.util.Iterator;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        Run run = new Run();
        new Thread(null, run, "Solver", 1l << 28).start();
        

    }

    static class Run implements Runnable {
        @Override
        public void run() {
            try {
                new Solver().solve();
                System.exit(0);
            } catch (Error | Exception e) {
                e.printStackTrace();
                System.exit(1);
            }
        }
    }
}

class myArrayListInteger implements Iterable<Integer> {
    private int len;
    private int[] A;

    public myArrayListInteger(int initialLength) {
        A = new int[Math.max(1, initialLength)];
        len = 0;
    }

    public myArrayListInteger(myArrayListInteger src) {
        A = new int[src.A.length];
        System.arraycopy(src.A, 0, A, 0, src.len);
        len = src.len;
    }

    public void add(int ele) {
        if (len == A.length) {
            int[] newAr = new int[A.length << 1];
            System.arraycopy(A, 0, newAr, 0, len);
            A = newAr;
        }
        A[len++] = ele;
    }

    public void set(int ind, int ele) throws Exception {
        if (ind >= len) throw new ArrayIndexOutOfBoundsException(ind);
        else if (ind < 0) ind += size();
        A[ind] = ele;
    }

    public int get(int ind) {
        if (ind >= len) throw new ArrayIndexOutOfBoundsException(ind);
        else if (ind < 0) ind += size();
        return A[ind];
    }

    public int pop() {
        return A[--len];
    }

    public void clear() {
        len = 0;
    }

    public int size() {
        return len;
    }

    public int length() {
        return len;
    }

    public boolean isEmpty() {
        return len == 0;
    }

    public myArrayListInteger mergeSorted(myArrayListInteger list) {
        myArrayListInteger ret = new myArrayListInteger(size() + list.size());
        int p1 = 0, p2 = 0;
        while (p1 < size() || p2 < list.size()) {
            if (p1 >= size()) ret.add(list.get(p2++));
            else if (p2 >= list.size()) ret.add(get(p1++));
            else if (get(p1) <= list.get(p2)) ret.add(get(p1++));
            else ret.add(list.get(p2++));
        }
        return ret;
    }

    public void sort(int fromIndex, int toIndex) {
        Arrays.sort(A, fromIndex, toIndex);
    }

    public void sort() {
        sort(0, size());
    }

    public void sort(int fromIndex, int toIndex, Comparator<Integer> com) {
        Integer[] temp = new Integer[toIndex - fromIndex];
        for (int i = fromIndex, k = 0; i < toIndex; ++i) temp[k++] = A[i];
        Arrays.sort(temp, com);
        for (int i = fromIndex, k = 0; i < toIndex; ++i) A[i] = temp[k++];
    }

    public void reverse() {
        for (int i = 0; i < size() >> 1; ++i) {
            int j = size() - 1 - i;
            A[i] ^= A[j];
            A[j] ^= A[i];
            A[i] ^= A[j];
        }
    }

    public int countFloor(int key) {
        

        if (isEmpty()) return 0;
        int l = 0, r = size() - 1, mid;
        while (true) {
            mid = l + r >> 1;
            if (l + 1 >= r) {
                if (get(r) <= key) return r + 1;
                else if (get(l) > key) return l;
                else return r;
            } else if (get(mid) <= key) l = mid + 1;
            else r = mid;
        }
    }

    int itrInd;

    public Iterator<Integer> iterator() {
        itrInd = 0;
        Iterator<Integer> iterator = new Iterator<Integer>() {
            @Override
            public boolean hasNext() {
                return itrInd < size();
            }

            @Override
            public Integer next() {
                return get(itrInd++);
            }
        };
        return iterator;
    }

    public myArrayListInteger clone() {
        return new myArrayListInteger(this);
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < len; i++) sb.append(A[i]).append(", ");
        return "[" + sb.toString().trim() + "]";
    }
}

class myArrayListLong implements Iterable<Long> {
    private int len;
    private long[] A;

    public myArrayListLong(int initialLength) {
        A = new long[Math.max(1, initialLength)];
        len = 0;
    }

    public myArrayListLong(myArrayListLong src) {
        A = new long[src.A.length];
        System.arraycopy(src.A, 0, A, 0, src.len);
        len = src.len;
    }

    public void add(long ele) {
        if (len == A.length) {
            long[] newAr = new long[A.length << 1];
            System.arraycopy(A, 0, newAr, 0, len);
            A = newAr;
        }
        A[len++] = ele;
    }

    public void set(int ind, long ele) throws Exception {
        if (ind >= len) throw new ArrayIndexOutOfBoundsException(ind);
        else if (ind < 0) ind += size();
        A[ind] = ele;
    }

    public long get(int ind) {
        if (ind >= len) throw new ArrayIndexOutOfBoundsException(ind);
        else if (ind < 0) ind += size();
        return A[ind];
    }

    public myArrayListLong get(int l, int r) {
        r = Math.min(r, size() - 1);
        if (l > r) return null;
        myArrayListLong ret = new myArrayListLong(r - l + 1);
        while (l <= r) {
            ret.add(get(l++));
        }
        return ret;
    }

    public long pop() {
        return A[--len];
    }

    public void clear() {
        len = 0;
    }

    public int size() {
        return len;
    }

    public int length() {
        return len;
    }

    public boolean isEmpty() {
        return len == 0;
    }

    public myArrayListLong mergeSorted(myArrayListLong list) {
        myArrayListLong ret = new myArrayListLong(size() + list.size());
        int p1 = 0, p2 = 0;
        while (p1 < size() || p2 < list.size()) {
            if (p1 >= size()) ret.add(list.get(p2++));
            else if (p2 >= list.size()) ret.add(get(p1++));
            else if (get(p1) <= list.get(p2)) ret.add(get(p1++));
            else ret.add(list.get(p2++));
        }
        return ret;
    }

    public void sort(int fromIndex, int toIndex) {
        Arrays.sort(A, fromIndex, toIndex);
    }

    public void sort() {
        sort(0, size());
    }

    public void sort(int fromIndex, int toIndex, Comparator<Long> com) {
        Long[] temp = new Long[toIndex - fromIndex];
        for (int i = fromIndex, k = 0; i < toIndex; ++i) temp[k++] = A[i];
        Arrays.sort(temp, com);
        for (int i = fromIndex, k = 0; i < toIndex; ++i) A[i] = temp[k++];
    }

    public void reverse() {
        for (int i = 0; i < size() >> 1; ++i) {
            int j = size() - 1 - i;
            A[i] ^= A[j];
            A[j] ^= A[i];
            A[i] ^= A[j];
        }
    }

    public int countFloor(long key) {
        

        if (isEmpty()) return 0;
        int l = 0, r = size() - 1, mid;
        while (true) {
            mid = l + r >> 1;
            if (l + 1 >= r) {
                if (get(r) <= key) return r + 1;
                else if (get(l) > key) return l;
                else return r;
            } else if (get(mid) <= key) l = mid + 1;
            else r = mid;
        }
    }

    int itrInd;

    public Iterator<Long> iterator() {
        itrInd = 0;
        Iterator<Long> iterator = new Iterator<Long>() {
            @Override
            public boolean hasNext() {
                return itrInd < size();
            }

            @Override
            public Long next() {
                return get(itrInd++);
            }
        };
        return iterator;
    }

    public myArrayListLong clone() {
        return new myArrayListLong(this);
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < len; i++) sb.append(A[i]).append(" ");
        return sb.toString().trim();
    }
}

class Solver {
    final Helper hp;
    final int MAXN = 1000_006;
    final long MOD = (long) 1e9 + 7;
    final static long MASK = 1000_000;

    Solver() {
        hp = new Helper(MOD, MAXN);
        hp.initIO(System.in, System.out);
    }

    int N, Q;
    int[] A;

    void solve() throws Exception {
        int i, j, k;
        long time = System.currentTimeMillis();

        N = hp.nextInt(); Q = hp.nextInt();
        A = hp.getIntArray(N);

        HashMap<Integer, Integer> map = new HashMap<>();
        myArrayListLong ar = new myArrayListLong(N);
        for (i = N - 1; i >= 0; --i) {
            long next = map.getOrDefault(A[i], N + 7);
            ar.add(next * MASK + next - i);
            map.put(A[i], i);
        }
        ar.reverse();

        MergeSortTree mst = new MergeSortTree(ar);

        while (Q-- > 0) {
            int l = hp.nextInt() - 1, r = hp.nextInt() - 1;
            int temp = mst.query(l, r);
            if (temp > N) temp = -1;
            hp.println(temp);
        }

        hp.flush();
    }

}

class MergeSortTree {
    int N;
    Node[] tree;

    MergeSortTree(myArrayListLong ar) {
        N = 1; while (N < ar.size()) N <<= 1;
        tree = new Node[N << 1];
        build(0, 0, N - 1, ar, ar.size());
    }

    myArrayListLong build(int idx, int l, int r, myArrayListLong ar, int n) {
        if (l < r) {
            int c1 = idx * 2 + 1, c2 = c1 + 1, mid = l + r >> 1;
            myArrayListLong left = ar.get(0, mid - l);
            myArrayListLong right = ar.get(mid - l + 1, ar.size() - 1);

            if (left != null) left = build(c1, l, mid, left, n);
            if (right != null) right = build(c2, mid + 1, r, right, n);

            if (left != null && right != null) ar = left.mergeSorted(right);
            else if (left == null) ar = right;
            else ar = left;
        }

        if (r < n) tree[idx] = new Node(ar);
        return ar;
    }

    int query(int l, int r) {
        return query(0, 0, N - 1, l, r);
    }

    int query(int i, int l, int r, int ql, int qr) {
        if (l > qr || r < ql) return Integer.MAX_VALUE >> 2;
        else if (l >= ql && r <= qr) return tree[i].query(qr);
        else {
            int c1 = i * 2 + 1, c2 = c1 + 1, mid = l + r >> 1;
            return Math.min(query(c1, l, mid, ql, qr), query(c2, mid + 1, r, ql, qr));
        }
    }
}

class Node {
    final static long MASK = 1000_000;

    myArrayListInteger list;
    Prefix prefix;

    Node (myArrayListLong ar) {
        list = new myArrayListInteger(ar.size());
        int[] temp = new int[ar.size()];
        for (int i = 0; i < ar.size(); ++i) {
            list.add((int) (ar.get(i) / MASK));
            temp[i] = (int) (ar.get(i) % MASK);
        }
        prefix = new Prefix(temp);
    }

    int query(int upto) {
        int idx = list.countFloor(upto);
        return prefix.query(idx - 1);
    }
}

class Prefix {
    int[] prefix;

    Prefix(int[] ar) {
        prefix = ar;
        for (int i = 1; i < ar.length; ++i) {
            prefix[i] = Math.min(prefix[i], prefix[i - 1]);
        }
    }

    int query(int idx) {
        return idx < 0 ? Integer.MAX_VALUE >> 2 : prefix[idx];
    }
}

class Helper {
    final long MOD;
    final int MAXN;
    final Random rnd;

    public Helper(long mod, int maxn) {
        MOD = mod;
        MAXN = maxn;
        rnd = new Random();
    }


    public static int[] sieve;
    public static ArrayList<Integer> primes;

    public void setSieve() {
        primes = new ArrayList<>();
        sieve = new int[MAXN];
        int i, j;
        for (i = 2; i < MAXN; ++i)
            if (sieve[i] == 0) {
                primes.add(i);
                for (j = i; j < MAXN; j += i) {
                    sieve[j] = i;
                }
            }
    }


    public static long[] factorial;

    public void setFactorial() {
        factorial = new long[MAXN];
        factorial[0] = 1;
        for (int i = 1; i < MAXN; ++i) factorial[i] = factorial[i - 1] * i % MOD;
    }

    public long getFactorial(int n) {
        if (factorial == null) setFactorial();
        return factorial[n];
    }

    public long ncr(int n, int r) {
        if (r > n) return 0;
        if (factorial == null) setFactorial();
        long numerator = factorial[n];
        long denominator = factorial[r] * factorial[n - r] % MOD;
        return numerator * pow(denominator, MOD - 2, MOD) % MOD;
    }


    public long[] getLongArray(int size) throws Exception {
        long[] ar = new long[size];
        for (int i = 0; i < size; ++i) ar[i] = nextLong();
        return ar;
    }

    public int[] getIntArray(int size) throws Exception {
        int[] ar = new int[size];
        for (int i = 0; i < size; ++i) ar[i] = nextInt();
        return ar;
    }

    public String[] getStringArray(int size) throws Exception {
        String[] ar = new String[size];
        for (int i = 0; i < size; ++i) ar[i] = next();
        return ar;
    }

    public String joinElements(long... ar) {
        StringBuilder sb = new StringBuilder();
        for (long itr : ar) sb.append(itr).append(" ");
        return sb.toString().trim();
    }


    public String joinElements(int... ar) {
        StringBuilder sb = new StringBuilder();
        for (int itr : ar) sb.append(itr).append(" ");
        return sb.toString().trim();
    }

    public String joinElements(String... ar) {
        StringBuilder sb = new StringBuilder();
        for (String itr : ar) sb.append(itr).append(" ");
        return sb.toString().trim();
    }

    public String joinElements(Object... ar) {
        StringBuilder sb = new StringBuilder();
        for (Object itr : ar) sb.append(itr).append(" ");
        return sb.toString().trim();
    }


    public long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    public int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }


    public long max(long... ar) {
        long ret = ar[0];
        for (long itr : ar) ret = Math.max(ret, itr);
        return ret;
    }

    public int max(int... ar) {
        int ret = ar[0];
        for (int itr : ar) ret = Math.max(ret, itr);
        return ret;
    }

    public long min(long... ar) {
        long ret = ar[0];
        for (long itr : ar) ret = Math.min(ret, itr);
        return ret;
    }

    public int min(int... ar) {
        int ret = ar[0];
        for (int itr : ar) ret = Math.min(ret, itr);
        return ret;
    }


    public long sum(long... ar) {
        long sum = 0;
        for (long itr : ar) sum += itr;
        return sum;
    }

    public long sum(int... ar) {
        long sum = 0;
        for (int itr : ar) sum += itr;
        return sum;
    }

    public void shuffle(int[] ar) {
        int r;
        for (int i = 0; i < ar.length; ++i) {
            r = rnd.nextInt(ar.length);
            if (r != i) {
                ar[i] ^= ar[r];
                ar[r] ^= ar[i];
                ar[i] ^= ar[r];
            }
        }
    }

    public void shuffle(long[] ar) {
        int r;
        for (int i = 0; i < ar.length; ++i) {
            r = rnd.nextInt(ar.length);
            if (r != i) {
                ar[i] ^= ar[r];
                ar[r] ^= ar[i];
                ar[i] ^= ar[r];
            }
        }
    }

    public void reverse(int[] ar) {
        int r;
        for (int i = 0; i < ar.length; ++i) {
            r = ar.length - 1 - i;
            if (r > i) {
                ar[i] ^= ar[r];
                ar[r] ^= ar[i];
                ar[i] ^= ar[r];
            }
        }
    }

    public void reverse(long[] ar) {
        int r;
        for (int i = 0; i < ar.length; ++i) {
            r = ar.length - 1 - i;
            if (r > i) {
                ar[i] ^= ar[r];
                ar[r] ^= ar[i];
                ar[i] ^= ar[r];
            }
        }
    }

    public long pow(long base, long exp, long MOD) {
        base %= MOD;
        long ret = 1;
        while (exp > 0) {
            if ((exp & 1) == 1) ret = ret * base % MOD;
            base = base * base % MOD;
            exp >>= 1;
        }
        return ret;
    }


    static final int BUFSIZE = 1 << 20;
    static byte[] buf;
    static int index, total;
    static InputStream in;
    static BufferedWriter bw;


    public void initIO(InputStream is, OutputStream os) {
        try {
            in = is;
            bw = new BufferedWriter(new OutputStreamWriter(os));
            buf = new byte[BUFSIZE];
        } catch (Exception e) {
        }
    }

    public void initIO(String inputFile, String outputFile) {
        try {
            in = new FileInputStream(inputFile);
            bw = new BufferedWriter(new OutputStreamWriter(
                    new FileOutputStream(outputFile)));
            buf = new byte[BUFSIZE];
        } catch (Exception e) {
        }
    }

    private int scan() throws Exception {
        if (index >= total) {
            index = 0;
            total = in.read(buf);
            if (total <= 0)
                return -1;
        }
        return buf[index++];
    }

    public String next() throws Exception {
        int c;
        for (c = scan(); c <= 32; c = scan()) ;
        StringBuilder sb = new StringBuilder();
        for (; c > 32; c = scan())
            sb.append((char) c);
        return sb.toString();
    }

    public int nextInt() throws Exception {
        int c, val = 0;
        for (c = scan(); c <= 32; c = scan()) ;
        boolean neg = c == '-';
        if (c == '-' || c == '+')
            c = scan();
        for (; c >= '0' && c <= '9'; c = scan())
            val = (val << 3) + (val << 1) + (c & 15);
        return neg ? -val : val;
    }

    public long nextLong() throws Exception {
        int c;
        long val = 0;
        for (c = scan(); c <= 32; c = scan()) ;
        boolean neg = c == '-';
        if (c == '-' || c == '+')
            c = scan();
        for (; c >= '0' && c <= '9'; c = scan())
            val = (val << 3) + (val << 1) + (c & 15);
        return neg ? -val : val;
    }

    public void print(Object a) throws Exception {
        bw.write(a.toString());
    }

    public void printsp(Object a) throws Exception {
        print(a);
        print(" ");
    }

    public void println() throws Exception {
        bw.write("\n");
    }

    public void println(Object a) throws Exception {
        print(a);
        println();
    }

    public void flush() throws Exception {
        bw.flush();
    }
}
