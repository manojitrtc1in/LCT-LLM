import java.io.*;
import java.util.*;

class FastIO {
    private final InputStream inputStream;
    private final OutputStream outputStream;
    private final byte[] buffer = new byte[8192];
    private int bufferPointer, bytesRead;

    public FastIO(InputStream inputStream, OutputStream outputStream) {
        this.inputStream = inputStream;
        this.outputStream = outputStream;
    }

    public int read() {
        if (bufferPointer == bytesRead) {
            bufferPointer = 0;
            try {
                bytesRead = inputStream.read(buffer);
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
            if (bytesRead <= 0) return -1;
        }
        return buffer[bufferPointer++];
    }

    public String readLine() {
        StringBuilder sb = new StringBuilder();
        int c;
        while ((c = read()) != -1 && c != '\n') {
            sb.append((char) c);
        }
        return sb.toString();
    }

    public void print(String s) {
        try {
            outputStream.write(s.getBytes());
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public void flush() {
        try {
            outputStream.flush();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}

class Main {
    static int[] l;
    static List<int[]> t = new ArrayList<>();

    static boolean check(int x) {
        int now = x;
        int c = Arrays.stream(l).sum();
        int cur = 0;
        int last = 0;
        Map<Integer, Integer> ld = new HashMap<>();
        for (int i = 0; i < t.size(); i++) {
            ld.put(t.get(i)[1], i);
        }
        for (int i = 0; i < t.size(); i++) {
            if (ld.get(t.get(i)[1]) != i) {
                continue;
            }
            if (t.get(i)[0] > x) {
                break;
            }
            cur += t.get(i)[0] - last;
            int rt = Math.min(cur, l[t.get(i)[1] - 1]);
            cur -= rt;
            now -= rt;
            c -= rt;
            last = t.get(i)[0];
        }
        return now >= 2 * c;
    }

    public static void main(String[] args) {
        FastIO io = new FastIO(System.in, System.out);
        String[] firstLine = io.readLine().split(" ");
        int n = Integer.parseInt(firstLine[0]);
        int m = Integer.parseInt(firstLine[1]);
        l = new int[n];
        String[] lInput = io.readLine().split(" ");
        for (int i = 0; i < n; i++) {
            l[i] = Integer.parseInt(lInput[i]);
        }
        for (int i = 0; i < m; i++) {
            String[] tInput = io.readLine().split(" ");
            t.add(new int[]{Integer.parseInt(tInput[0]), Integer.parseInt(tInput[1])});
        }
        t.sort(Comparator.comparingInt(a -> a[0]));

        int st = 1;
        int end = 2 * Arrays.stream(l).sum();
        int ans = end;
        while (st <= end) {
            int mid = (st + end) / 2;
            if (check(mid)) {
                ans = mid;
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        }
        io.print(ans + "\n");
        io.flush();
    }
}
