
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;

public class E {

  
  static InputReader in = new InputReader(System.in);
  static PrintWriter out = new PrintWriter(System.out);
  private static StringBuilder sb = new StringBuilder();

  static class InputReader {

    private static final int id4 = 1 << 16;
    private static final InputStream DEFAULT_STREAM = System.in;
    private static final int id6 = 21;
    private int c;
    private byte[] buf;
    private int bufferSize, bufIndex, id7;

    private InputStream stream;

    private static final byte EOF = -1;
    private static final byte NEW_LINE = 10;
    private static final byte SPACE = 32;
    private static final byte DASH = 45;
    private static final byte DOT = 46;

    private char[] charBuffer;

    private static byte[] bytes = new byte[58];
    private static int[] ints = new int[58];
    private static char[] chars = new char[128];

    static {
      char ch = ' ';
      int value = 0;
      byte _byte = 0;
      for (int i = 48; i < 58; i++) {
        bytes[i] = _byte++;
      }
      for (int i = 48; i < 58; i++) {
        ints[i] = value++;
      }
      for (int i = 32; i < 128; i++) {
        chars[i] = ch++;
      }
    }

    private static final double[][] doubles = {
      {0.0d, 0.00d, 0.000d, 0.0000d, 0.00000d, 0.000000d, 0.0000000d, 0.00000000d, 0.000000000d,
        0.0000000000d, 0.00000000000d, 0.000000000000d,
        0.0000000000000d, 0.00000000000000d, 0.000000000000000d, 0.0000000000000000d,
        0.00000000000000000d, 0.000000000000000000d,
        0.0000000000000000000d, 0.00000000000000000000d, 0.000000000000000000000d},
      {0.1d, 0.01d, 0.001d, 0.0001d, 0.00001d, 0.000001d, 0.0000001d, 0.00000001d, 0.000000001d,
        0.0000000001d, 0.00000000001d, 0.000000000001d,
        0.0000000000001d, 0.00000000000001d, 0.000000000000001d, 0.0000000000000001d,
        0.00000000000000001d, 0.000000000000000001d,
        0.0000000000000000001d, 0.00000000000000000001d, 0.000000000000000000001d},
      {0.2d, 0.02d, 0.002d, 0.0002d, 0.00002d, 0.000002d, 0.0000002d, 0.00000002d, 0.000000002d,
        0.0000000002d, 0.00000000002d, 0.000000000002d,
        0.0000000000002d, 0.00000000000002d, 0.000000000000002d, 0.0000000000000002d,
        0.00000000000000002d, 0.000000000000000002d,
        0.0000000000000000002d, 0.00000000000000000002d, 0.000000000000000000002d},
      {0.3d, 0.03d, 0.003d, 0.0003d, 0.00003d, 0.000003d, 0.0000003d, 0.00000003d, 0.000000003d,
        0.0000000003d, 0.00000000003d, 0.000000000003d,
        0.0000000000003d, 0.00000000000003d, 0.000000000000003d, 0.0000000000000003d,
        0.00000000000000003d, 0.000000000000000003d,
        0.0000000000000000003d, 0.00000000000000000003d, 0.000000000000000000003d},
      {0.4d, 0.04d, 0.004d, 0.0004d, 0.00004d, 0.000004d, 0.0000004d, 0.00000004d, 0.000000004d,
        0.0000000004d, 0.00000000004d, 0.000000000004d,
        0.0000000000004d, 0.00000000000004d, 0.000000000000004d, 0.0000000000000004d,
        0.00000000000000004d, 0.000000000000000004d,
        0.0000000000000000004d, 0.00000000000000000004d, 0.000000000000000000004d},
      {0.5d, 0.05d, 0.005d, 0.0005d, 0.00005d, 0.000005d, 0.0000005d, 0.00000005d, 0.000000005d,
        0.0000000005d, 0.00000000005d, 0.000000000005d,
        0.0000000000005d, 0.00000000000005d, 0.000000000000005d, 0.0000000000000005d,
        0.00000000000000005d, 0.000000000000000005d,
        0.0000000000000000005d, 0.00000000000000000005d, 0.000000000000000000005d},
      {0.6d, 0.06d, 0.006d, 0.0006d, 0.00006d, 0.000006d, 0.0000006d, 0.00000006d, 0.000000006d,
        0.0000000006d, 0.00000000006d, 0.000000000006d,
        0.0000000000006d, 0.00000000000006d, 0.000000000000006d, 0.0000000000000006d,
        0.00000000000000006d, 0.000000000000000006d,
        0.0000000000000000006d, 0.00000000000000000006d, 0.000000000000000000006d},
      {0.7d, 0.07d, 0.007d, 0.0007d, 0.00007d, 0.000007d, 0.0000007d, 0.00000007d, 0.000000007d,
        0.0000000007d, 0.00000000007d, 0.000000000007d,
        0.0000000000007d, 0.00000000000007d, 0.000000000000007d, 0.0000000000000007d,
        0.00000000000000007d, 0.000000000000000007d,
        0.0000000000000000007d, 0.00000000000000000007d, 0.000000000000000000007d},
      {0.8d, 0.08d, 0.008d, 0.0008d, 0.00008d, 0.000008d, 0.0000008d, 0.00000008d, 0.000000008d,
        0.0000000008d, 0.00000000008d, 0.000000000008d,
        0.0000000000008d, 0.00000000000008d, 0.000000000000008d, 0.0000000000000008d,
        0.00000000000000008d, 0.000000000000000008d,
        0.0000000000000000008d, 0.00000000000000000008d, 0.000000000000000000008d},
      {0.9d, 0.09d, 0.009d, 0.0009d, 0.00009d, 0.000009d, 0.0000009d, 0.00000009d, 0.000000009d,
        0.0000000009d, 0.00000000009d, 0.000000000009d,
        0.0000000000009d, 0.00000000000009d, 0.000000000000009d, 0.0000000000000009d,
        0.00000000000000009d, 0.000000000000000009d,
        0.0000000000000000009d, 0.00000000000000000009d, 0.000000000000000000009d}
    };

    public InputReader() {
      this(DEFAULT_STREAM, id4);
    }

    public InputReader(int bufferSize) {
      this(DEFAULT_STREAM, bufferSize);
    }

    public InputReader(InputStream stream) {
      this(stream, id4);
    }

    public InputReader(InputStream stream, int bufferSize) {
      if (stream == null || bufferSize <= 0) {
        throw new IllegalArgumentException();
      }
      buf = new byte[bufferSize];
      charBuffer = new char[128];
      this.bufferSize = bufferSize;
      this.stream = stream;
    }

    private byte read() throws IOException {

      if (id7 == EOF) {
        throw new IOException();
      }

      if (bufIndex >= id7) {
        bufIndex = 0;
        id7 = stream.read(buf);
        if (id7 == EOF) {
          return EOF;
        }
      }

      return buf[bufIndex++];
    }

    private void id2() {
      char[] newBuffer = new char[charBuffer.length << 1];
      for (int i = 0; i < charBuffer.length; i++) {
        newBuffer[i] = charBuffer[i];
      }
      charBuffer = newBuffer;
    }

    private int id0(int token) throws IOException {

      if (id7 == EOF) {
        return EOF;
      }

      do {

        while (bufIndex < id7) {
          if (buf[bufIndex] > token) {
            return 0;
          }
          bufIndex++;
        }

        id7 = stream.read(buf);
        if (id7 == EOF) {
          return EOF;
        }
        bufIndex = 0;

      } while (true);

    }

    public byte nextByte() throws IOException {
      return (byte) nextInt();
    }

    public int nextInt() throws IOException {

      if (id0(DASH - 1) == EOF) {
        throw new IOException();
      }
      int sgn = 1, res = 0;

      c = buf[bufIndex];
      if (c == DASH) {
        sgn = -1;
        bufIndex++;
      }

      do {

        while (bufIndex < id7) {
          if (buf[bufIndex] > SPACE) {
            res = (res << 3) + (res << 1);
            res += ints[buf[bufIndex++]];
          } else {
            bufIndex++;
            return res * sgn;
          }
        }

        id7 = stream.read(buf);
        if (id7 == EOF) {
          return res * sgn;
        }
        bufIndex = 0;

      } while (true);

    }

    public int[] id3(int n) throws IOException {
      int[] ar = new int[n];
      for (int i = 0; i < n; i++) {
        ar[i] = nextInt();
      }
      return ar;
    }

    public void close() throws IOException {
      stream.close();
    }

    public long nextLong() throws IOException {
      if (id0(DASH - 1) == EOF) {
        throw new IOException();
      }
      int sgn = 1;
      long res = 0L;
      c = buf[bufIndex];
      if (c == DASH) {
        sgn = -1;
        bufIndex++;
      }
      do {
        while (bufIndex < id7) {
          if (buf[bufIndex] > SPACE) {
            res = (res << 3) + (res << 1);
            res += ints[buf[bufIndex++]];
          } else {
            bufIndex++;
            return res * sgn;
          }
        }
        id7 = stream.read(buf);
        if (id7 == EOF) {
          return res * sgn;
        }
        bufIndex = 0;
      } while (true);
    }

    public String nextString() throws IOException {
      if (id7 == EOF) {
        return null;
      }
      if (id0(SPACE) == EOF) {
        return null;
      }

      for (int i = 0;;) {
        while (bufIndex < id7) {
          if (buf[bufIndex] > SPACE) {
            if (i == charBuffer.length) {
              id2();
            }
            charBuffer[i++] = (char) buf[bufIndex++];
          } else {
            bufIndex++;
            return new String(charBuffer, 0, i);
          }
        }

        

        id7 = stream.read(buf);
        if (id7 == EOF) {
          return new String(charBuffer, 0, i);
        }
        bufIndex = 0;
      }
    }
  }

  static boolean[][] id1;

  public static void main(String args[]) throws Exception {
    int t = in.nextInt();
    while (t-- != 0) {
      solve();
    }
    System.out.print(sb.toString());
  }

  static void solve() throws IOException {
    int n;
    n = in.nextInt();
    char[] s, t;
    s = in.nextString().toCharArray();
    t = in.nextString().toCharArray();
    LinkedList<Integer>[] pq = new LinkedList[26];
    long[] arr = new long[n + 1];
    for (int i = 0; i < n; i++) {
      arr[i + 1] = i;
    }
    BIT2 bit = new BIT2(arr);
    for (int i = 0; i < 26; i++) {
      pq[i] = new LinkedList();
    }
    for (int i = 0; i < n; i++) {
      pq[s[i] - 'a'].add(i);
    }
    long ans = Long.MAX_VALUE;
    long swaps = 0;
    for (int i = 0; i < n; i++) {
      char c = t[i];
      for (int j = c - 'a' - 1; j > -1; j--) {
        if (pq[j].isEmpty()) {
          continue;
        }
        Integer index = pq[j].peekFirst();
        long realIndex = bit.get(index + 1);
        ans = Math.min(ans, swaps + realIndex - i);
      }

      if (pq[c - 'a'].isEmpty()) {
        break;
      } else {
        Integer toMove = pq[c - 'a'].removeFirst();
        bit.updateRange(1, toMove, +1);
        long hehe = bit.get(toMove + 1) - i;
        swaps += hehe;
      }
    }
    if (ans == Long.MAX_VALUE) {
      ans = -1;
    }
    System.out.println(ans);
  }

  static class BIT {

    

    final int N;

    

    private long[] tree;

    

    public BIT(int sz) {
      tree = new long[(N = sz + 1)];
    }

    

    

    

    public BIT(long[] values) {

      if (values == null) {
        throw new IllegalArgumentException("Values array cannot be null!");
      }

      N = values.length;
      values[0] = 0L;

      

      

      tree = values.clone();

      for (int i = 1; i < N; i++) {
        int parent = i + lsb(i);
        if (parent < N) {
          tree[parent] += tree[i];
        }
      }
    }

    

    

    

    

    

    private static int lsb(int i) {

      

      return i & -i;

      

      

    }

    

    private long prefixSum(int i) {
      long sum = 0L;
      while (i != 0) {
        sum += tree[i];
        i &= ~lsb(i); 

      }
      return sum;
    }

    

    public long sum(int left, int right) {
      if (right < left) {
        return 0;
      }
      return prefixSum(right) - prefixSum(left - 1);
    }

    

    public long get(int i) {
      return sum(i, i);
    }

    

    public void add(int i, long v) {
      while (i < N) {
        tree[i] += v;
        i += lsb(i);
      }
    }

    

    public void set(int i, long v) {
      add(i, v - sum(i, i));
    }

    @Override
    public String toString() {
      return java.util.Arrays.toString(tree);
    }
  }

  static class BIT2 {

    

    final int N;

    

    

    private long[] originalTree;

    

    private long[] currentTree;

    

    

    

    public BIT2(long[] values) {

      if (values == null) {
        throw new IllegalArgumentException("Values array cannot be null!");
      }

      N = values.length;
      values[0] = 0L;

      

      

      long[] id5 = values.clone();

      for (int i = 1; i < N; i++) {
        int parent = i + lsb(i);
        if (parent < N) {
          id5[parent] += id5[i];
        }
      }

      originalTree = id5;
      currentTree = id5.clone();
    }

    

    public void updateRange(int left, int right, long val) {
      add(left, +val);
      add(right + 1, -val);
    }

    

    private void add(int i, long v) {
      while (i < N) {
        currentTree[i] += v;
        i += lsb(i);
      }
    }

    

    

    

    

    public long get(int i) {
      return prefixSum(i, currentTree) - prefixSum(i - 1, originalTree);
    }

    

    private long prefixSum(int i, long[] tree) {
      long sum = 0L;
      while (i != 0) {
        sum += tree[i];
        i &= ~lsb(i); 

      }
      return sum;
    }

    

    

    

    

    

    private static int lsb(int i) {

      

      return i & -i;

      

      

    }
  }
}
