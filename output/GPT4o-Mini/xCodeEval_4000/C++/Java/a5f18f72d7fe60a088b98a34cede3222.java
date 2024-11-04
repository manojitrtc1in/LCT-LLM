import java.util.*;
import java.io.*;

class Vector<T> extends ArrayList<T> {
    public Vector() {
        super();
    }

    public Vector(int n) {
        super(n);
    }

    public Vector(int n, T value) {
        super(n);
        Collections.fill(this, value);
    }

    public Vector(Collection<? extends T> c) {
        super(c);
    }

    public T get(int index) {
        if (index >= size()) {
            throw new IndexOutOfBoundsException("Out of bounds");
        }
        return super.get(index);
    }

    public T set(int index, T element) {
        if (index >= size()) {
            throw new IndexOutOfBoundsException("Out of bounds");
        }
        return super.set(index, element);
    }

    public Vector<T> clone() {
        return new Vector<>(this);
    }
}

class VectorBoolean extends ArrayList<Boolean> {
    public VectorBoolean() {
        super();
    }

    public VectorBoolean(int n) {
        super(n);
    }

    public VectorBoolean(int n, boolean value) {
        super(n);
        Collections.fill(this, value);
    }

    public Boolean get(int index) {
        if (index >= size()) {
            throw new IndexOutOfBoundsException("Out of bounds");
        }
        return super.get(index);
    }

    public Boolean set(int index, Boolean element) {
        if (index >= size()) {
            throw new IndexOutOfBoundsException("Out of bounds");
        }
        return super.set(index, element);
    }
}

class NumberIterator {
    private int v;

    public NumberIterator(int v) {
        this.v = v;
    }

    public int getValue() {
        return v;
    }
}

class Range {
    private int begin;
    private int end;

    public Range(int begin, int end) {
        this.begin = begin;
        this.end = Math.max(begin, end);
    }

    public Range(int n) {
        this(0, Math.max(0, n));
    }

    public NumberIterator begin() {
        return new NumberIterator(begin);
    }

    public NumberIterator end() {
        return new NumberIterator(end);
    }
}

class Arr<T> {
    private T[] b;
    private int n;

    public Arr(int n) {
        this.n = n;
        if (n > 0) {
            b = (T[]) new Object[n];
        } else {
            b = null;
        }
    }

    public int size() {
        return n;
    }

    public T get(int at) {
        if (at < 0 || at >= n) {
            throw new IndexOutOfBoundsException("Out of bounds");
        }
        return b[at];
    }

    public void set(int at, T value) {
        if (at < 0 || at >= n) {
            throw new IndexOutOfBoundsException("Out of bounds");
        }
        b[at] = value;
    }

    public boolean equals(Arr<T> other) {
        if (n != other.n) {
            return false;
        }
        for (int i = 0; i < n; i++) {
            if (!b[i].equals(other.b[i])) {
                return false;
            }
        }
        return true;
    }
}

class Arr2D<T> {
    private T[][] b;
    private int d1;
    private int d2;

    public Arr2D(int d1, int d2) {
        this.d1 = d1;
        this.d2 = d2;
        b = (T[][]) new Object[d1][d2];
    }

    public T get(int i1, int i2) {
        if (i1 < 0 || i1 >= d1 || i2 < 0 || i2 >= d2) {
            throw new IndexOutOfBoundsException("Out of bounds");
        }
        return b[i1][i2];
    }

    public void set(int i1, int i2, T value) {
        if (i1 < 0 || i1 >= d1 || i2 < 0 || i2 >= d2) {
            throw new IndexOutOfBoundsException("Out of bounds");
        }
        b[i1][i2] = value;
    }
}

class Input {
    private BufferedReader in;
    private StringTokenizer st;

    public Input(InputStream input) {
        in = new BufferedReader(new InputStreamReader(input));
    }

    private String next() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(in.readLine());
        }
        return st.nextToken();
    }

    public int readInt() throws IOException {
        return Integer.parseInt(next());
    }

    public long readLong() throws IOException {
        return Long.parseLong(next());
    }

    public String readString() throws IOException {
        return next();
    }

    public Arr<Integer> readIntArray(int size) throws IOException {
        Arr<Integer> arr = new Arr<>(size);
        for (int i = 0; i < size; i++) {
            arr.set(i, readInt());
        }
        return arr;
    }
}

class Output {
    private PrintWriter out;

    public Output(OutputStream output) {
        out = new PrintWriter(output);
    }

    public void printLine(long value) {
        out.println(value);
    }

    public void flush() {
        out.flush();
    }
}

class DKhaotichnayaV {
    public void solve(Input in, Output out) throws IOException {
        int n = in.readInt();
        Arr<Integer> k = in.readIntArray(n);

        List<Integer> p = primes(5000);
        Arr<Integer> d = divisorTable(5001);
        Arr<List<Integer>> divisors = new Arr<>(5001);
        for (int i = 0; i < 5001; i++) {
            divisors.set(i, new ArrayList<>());
        }
        for (int i = 2; i < 5001; i++) {
            divisors.set(i, new ArrayList<>(divisors.get(i - 1)));
            if (d.get(i) == i) {
                divisors.get(i).add(1);
            } else {
                for (int q = i; q > 1; q /= d.get(q)) {
                    divisors.get(i).add(d.get(q));
                }
            }
        }
        long answer = 0;
        Arr<Integer> q = getQty(k, 5001);
        int lost = 0;
        Arr<Boolean> still = new Arr<>(5001);
        for (int i = 0; i < 5001; i++) {
            still.set(i, true);
        }
        Arr<Integer> cur = new Arr<>(p.size());
        while (true) {
            for (int i = 0; i < cur.size(); i++) {
                cur.set(i, 0);
            }
            for (int i = 0; i < 5001; i++) {
                if (still.get(i) && !divisors.get(i).isEmpty()) {
                    cur.set(divisors.get(i).size() - 1, cur.get(divisors.get(i).size() - 1) + q.get(i));
                }
            }
            int pos = maxElement(cur);
            if (cur.get(pos) <= n / 2) {
                pos = -2;
            }
            int step = Integer.MAX_VALUE;
            for (int i = 0; i < 5001; i++) {
                if (still.get(i) && divisors.get(i).size() - 1 != pos) {
                    answer += q.get(i) * sum(divisors.get(i));
                    lost += q.get(i);
                    still.set(i, false);
                } else if (still.get(i)) {
                    step = Math.min(step, divisors.get(i).get(divisors.get(i).size() - 1));
                }
            }
            if (pos == -2) {
                break;
            }
            answer += (long) step * lost;
            for (int i = 0; i < 5001; i++) {
                if (still.get(i)) {
                    divisors.get(i).set(divisors.get(i).size() - 1, divisors.get(i).get(divisors.get(i).size() - 1) - step);
                    if (divisors.get(i).get(divisors.get(i).size() - 1) == 0) {
                        divisors.get(i).remove(divisors.get(i).size() - 1);
                    }
                }
            }
        }
        out.printLine(answer);
    }

    private List<Integer> primes(int n) {
        boolean[] isPrime = new boolean[n];
        Arrays.fill(isPrime, true);
        List<Integer> res = new ArrayList<>();
        for (int i = 2; i < n; i++) {
            if (isPrime[i]) {
                res.add(i);
                for (int j = i * i; j < n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        return res;
    }

    private Arr<Integer> divisorTable(int n) {
        Arr<Integer> res = new Arr<>(n);
        for (int i = 0; i < n; i++) {
            res.set(i, 0);
        }
        for (int i = 2; i < n; i++) {
            if (res.get(i) == 0) {
                res.set(i, i);
                for (int j = i * i; j < n; j += i) {
                    res.set(j, i);
                }
            }
        }
        return res;
    }

    private Arr<Integer> getQty(Arr<Integer> k, int length) {
        Arr<Integer> res = new Arr<>(length);
        for (int i = 0; i < length; i++) {
            res.set(i, 0);
        }
        for (int i = 0; i < k.size(); i++) {
            res.set(k.get(i), res.get(k.get(i)) + 1);
        }
        return res;
    }

    private int maxElement(Arr<Integer> arr) {
        int maxIndex = 0;
        for (int i = 1; i < arr.size(); i++) {
            if (arr.get(i) > arr.get(maxIndex)) {
                maxIndex = i;
            }
        }
        return maxIndex;
    }

    private long sum(List<Integer> list) {
        long sum = 0;
        for (int value : list) {
            sum += value;
        }
        return sum;
    }
}

public class a5f18f72d7fe60a088b98a34cede3222_nc {
    public static void main(String[] args) throws IOException {
        InputStream input = System.in;
        OutputStream output = System.out;
        Input in = new Input(input);
        Output out = new Output(output);
        DKhaotichnayaV solver = new DKhaotichnayaV();
        solver.solve(in, out);
        out.flush();
    }
}
