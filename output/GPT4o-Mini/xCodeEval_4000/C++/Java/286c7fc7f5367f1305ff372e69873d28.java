import java.io.*;
import java.util.*;

class EDerevoDelitelei {
    public void solve() throws IOException {
        int n = in.readInt();
        long[] a = in.readLongArray(n);

        Arrays.sort(a);
        int[] d = new int[n];
        for (int i = 0; i < n; i++) {
            long c = a[i];
            for (long j = 2; j * j <= c; j++) {
                while (c % j == 0) {
                    d[i]++;
                    c /= j;
                }
            }
            if (c != 1) {
                d[i]++;
            }
        }
        int infty = Integer.MAX_VALUE / 2;
        int[] reachable = new int[1 << n];
        Arrays.fill(reachable, infty);
        reachable[0] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < (1 << i); j++) {
                long rem = a[i];
                boolean good = true;
                for (int k = 0; k < i; k++) {
                    if ((j & (1 << k)) != 0) {
                        if (rem % a[k] != 0) {
                            good = false;
                            break;
                        }
                        rem /= a[k];
                    }
                }
                int qty = 0;
                for (long c = 2; c * c <= rem; c++) {
                    while (rem % c == 0) {
                        qty++;
                        rem /= c;
                    }
                }
                if (rem != 1) {
                    qty++;
                }
                int lim = (i == 0) ? 0 : (1 << (i - 1));
                if (good) {
                    for (int k = 0; k < (1 << i); k++) {
                        if ((j & k) == 0 && reachable[j + k] != infty && j + k >= lim) {
                            reachable[(1 << i) + k] = Math.min(reachable[(1 << i) + k], reachable[j + k] + qty + (d[i] == 1 ? 0 : 1));
                        }
                    }
                }
            }
        }
        int answer = infty;
        for (int i = (1 << (n - 1)); i < (1 << n); i++) {
            if (reachable[i] == infty) {
                continue;
            }
            answer = Math.min(answer, reachable[i] + (Integer.bitCount(i) == 1 ? 0 : 1));
        }
        out.printLine(answer);
    }
}

class Input {
    private BufferedReader reader;
    private StringTokenizer tokenizer;

    public Input() {
        reader = new BufferedReader(new InputStreamReader(System.in));
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

    public long[] readLongArray(int size) throws IOException {
        long[] array = new long[size];
        for (int i = 0; i < size; i++) {
            array[i] = Long.parseLong(next());
        }
        return array;
    }
}

class Output {
    private PrintWriter writer;

    public Output() {
        writer = new PrintWriter(System.out);
    }

    public void printLine(int value) {
        writer.println(value);
        writer.flush();
    }
}

public class 286c7fc7f5367f1305ff372e69873d28_nc {
    static Input in = new Input();
    static Output out = new Output();

    public static void main(String[] args) throws IOException {
        EDerevoDelitelei solver = new EDerevoDelitelei();
        solver.solve();
    }
}
