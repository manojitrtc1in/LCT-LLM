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
    int v;

    public NumberIterator(int v) {
        this.v = v;
    }

    public int getValue() {
        return v;
    }
}

class Range {
    int first, second;

    public Range(int begin, int end) {
        this.first = begin;
        this.second = Math.max(begin, end);
    }

    public Range(int n) {
        this(0, Math.max(0, n));
    }

    public NumberIterator begin() {
        return new NumberIterator(first);
    }

    public NumberIterator end() {
        return new NumberIterator(second);
    }
}

class Arr<T> {
    private T[] b;
    private int n;

    public Arr(int n) {
        this.n = n;
        if (n < 0) {
            throw new OutOfMemoryError("bad alloc");
        }
        b = (T[]) new Object[n];
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
}

class Input {
    private BufferedReader reader;
    private StringTokenizer tokenizer;

    public Input(InputStream in) {
        reader = new BufferedReader(new InputStreamReader(in));
    }

    private String next() throws IOException {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(reader.readLine());
        }
        return tokenizer.nextToken();
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

    public int[] readIntArray(int size) throws IOException {
        int[] arr = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = readInt();
        }
        return arr;
    }
}

class Output {
    private PrintWriter writer;

    public Output(OutputStream out) {
        writer = new PrintWriter(out);
    }

    public void printLine(long value) {
        writer.println(value);
    }

    public void flush() {
        writer.flush();
    }
}

class DKhaotichnayaV {
    public void solve(Input in, Output out) throws IOException {
        int n = in.readInt();
        int[] k = in.readIntArray(n);

        List<Integer> p = primes(5000);
        int[] d = id7(5001);
        List<List<Integer>> id0 = new ArrayList<>(5001);
        for (int i = 0; i < 5001; i++) {
            id0.add(new ArrayList<>());
        }
        id0.get(0).add(0);
        id0.get(1).add(0);
        for (int i = 2; i < 5001; i++) {
            id0.set(i, new ArrayList<>(id0.get(i - 1)));
            if (d[i] == i) {
                id0.get(i).add(1);
            } else {
                for (int q = i; q > 1; q /= d[q]) {
                    id0.get(i).set(Collections.binarySearch(p, d[q]), id0.get(i).get(Collections.binarySearch(p, d[q])) + 1);
                }
            }
        }
        long answer = 0;
        int[] q = getQty(k, 5001);
        int lost = 0;
        boolean[] still = new boolean[5001];
        Arrays.fill(still, true);
        int[] cur = new int[p.size()];
        while (true) {
            Arrays.fill(cur, 0);
            for (int i = 0; i < 5001; i++) {
                if (still[i] && !id0.get(i).isEmpty()) {
                    cur[id0.get(i).size() - 1] += q[i];
                }
            }
            int pos = maxIndex(cur);
            if (cur[pos] <= n / 2) {
                pos = -2;
            }
            int step = Integer.MAX_VALUE;
            for (int i = 0; i < 5001; i++) {
                if (still[i] && id0.get(i).size() - 1 != pos) {
                    answer += q[i] * id0.get(i).stream().mapToLong(Integer::longValue).sum();
                    lost += q[i];
                    still[i] = false;
                } else if (still[i]) {
                    step = Math.min(step, id0.get(i).get(id0.get(i).size() - 1));
                }
            }
            if (pos == -2) {
                break;
            }
            answer += (long) step * lost;
            for (int i = 0; i < 5001; i++) {
                if (still[i]) {
                    id0.get(i).set(id0.get(i).size() - 1, id0.get(i).get(id0.get(i).size() - 1) - step);
                    if (id0.get(i).get(id0.get(i).size() - 1) == 0) {
                        id0.get(i).remove(id0.get(i).size() - 1);
                    }
                }
            }
        }
        out.printLine(answer);
    }

    private List<Integer> primes(int n) {
        boolean[] isPrime = id5(n);
        List<Integer> res = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            if (isPrime[i]) {
                res.add(i);
            }
        }
        return res;
    }

    private boolean[] id5(int n) {
        boolean[] res = new boolean[n];
        Arrays.fill(res, true);
        if (n > 0) {
            res[0] = false;
        }
        if (n > 1) {
            res[1] = false;
        }
        for (int i = 2; i * i < n; i++) {
            if (res[i]) {
                for (int j = i * i; j < n; j += i) {
                    res[j] = false;
                }
            }
        }
        return res;
    }

    private int[] id7(int n) {
        int[] res = new int[n];
        Arrays.fill(res, 0);
        if (n > 1) {
            res[1] = 1;
        }
        for (int i = 2; i < n; i++) {
            if (res[i] == 0) {
                res[i] = i;
                if ((long) i * i < n) {
                    for (int j = i * i; j < n; j += i) {
                        res[j] = i;
                    }
                }
            }
        }
        return res;
    }

    private int[] getQty(int[] arr, int length) {
        int[] res = new int[length];
        for (int value : arr) {
            res[value]++;
        }
        return res;
    }

    private int maxIndex(int[] arr) {
        int maxIndex = 0;
        for (int i = 1; i < arr.length; i++) {
            if (arr[i] > arr[maxIndex]) {
                maxIndex = i;
            }
        }
        return maxIndex;
    }
}

public class a5f18f72d7fe60a088b98a34cede3222xcodeeval_processed_4000.json {
    public static void main(String[] args) throws IOException {
        InputStream in = System.in;
        OutputStream out = System.out;
        Input input = new Input(in);
        Output output = new Output(out);
        DKhaotichnayaV solver = new DKhaotichnayaV();
        solver.solve(input, output);
        output.flush();
    }
}
