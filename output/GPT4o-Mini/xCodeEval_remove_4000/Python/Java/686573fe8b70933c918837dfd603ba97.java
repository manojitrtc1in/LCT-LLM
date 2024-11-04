import java.io.*;
import java.util.*;

class FastIO {
    private BufferedReader reader;
    private PrintWriter writer;

    public FastIO() {
        reader = new BufferedReader(new InputStreamReader(System.in));
        writer = new PrintWriter(System.out);
    }

    public String readLine() throws IOException {
        return reader.readLine();
    }

    public void print(Object obj) {
        writer.print(obj);
    }

    public void println(Object obj) {
        writer.println(obj);
    }

    public void flush() {
        writer.flush();
    }
}

public class 686573fe8b70933c918837dfd603ba97xcodeeval_processed_4000.json {
    public static void main(String[] args) throws IOException {
        FastIO io = new FastIO();
        int n = Integer.parseInt(io.readLine());
        List<int[]> l = new ArrayList<>();
        
        for (int i = 0; i < n; i++) {
            String[] parts = io.readLine().split(" ");
            int[] arr = new int[5];
            for (int j = 0; j < 5; j++) {
                arr[j] = Integer.parseInt(parts[j]);
            }
            l.add(arr);
        }

        if (n >= 50) {
            io.println(0);
            io.flush();
            return;
        }
        if (n <= 2) {
            io.println(n);
            for (int i = 0; i < n; i++) {
                io.println(i + 1);
            }
            io.flush();
            return;
        }

        Set<Integer> er = new HashSet<>();
        for (int i = 0; i < n; i++) {
            boolean f = false;
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (i == j || i == k || j == k) {
                        continue;
                    }
                    int w = 0;
                    for (int d = 0; d < 5; d++) {
                        w += (l.get(i)[d] - l.get(j)[d]) * (l.get(i)[d] - l.get(k)[d]);
                    }
                    if (w > 0) {
                        f = true;
                        break;
                    }
                }
                if (f) {
                    break;
                }
            }
            if (!f) {
                er.add(i + 1);
            }
        }

        io.println(er.size());
        for (int num : er) {
            io.println(num);
        }
        io.flush();
    }
}
