
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.Collections;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Stack;

public class C {

  
  static InputReader in = new InputReader(System.in);
  private static StringBuilder sb = new StringBuilder();
  static PrintWriter out = new PrintWriter(System.out);

  private static void dfs3(List<Integer>[] edges, int[][] childrens, int root) {
    for (int child : edges[root]) {
      edges[child].remove(edges[child].indexOf(root));
      if (childrens[root][0] == -1) {
        childrens[root][0] = child;
      } else {
        childrens[root][1] = child;
      }
      dfs3(edges, childrens, child);
    }
  }

  static class InputReader {

    private static final int id0 = 1 << 16;
    private static final InputStream DEFAULT_STREAM = System.in;
    private static final int id2 = 21;
    private int c;
    private byte[] buf;
    private int bufferSize, bufIndex, id5;

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
      this(DEFAULT_STREAM, id0);
    }

    public InputReader(int bufferSize) {
      this(DEFAULT_STREAM, bufferSize);
    }

    public InputReader(InputStream stream) {
      this(stream, id0);
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

      if (id5 == EOF) {
        throw new IOException();
      }

      if (bufIndex >= id5) {
        bufIndex = 0;
        id5 = stream.read(buf);
        if (id5 == EOF) {
          return EOF;
        }
      }

      return buf[bufIndex++];
    }

    private void id1() {
      char[] newBuffer = new char[charBuffer.length << 1];
      for (int i = 0; i < charBuffer.length; i++) {
        newBuffer[i] = charBuffer[i];
      }
      charBuffer = newBuffer;
    }

    private int id4(int token) throws IOException {

      if (id5 == EOF) {
        return EOF;
      }

      do {

        while (bufIndex < id5) {
          if (buf[bufIndex] > token) {
            return 0;
          }
          bufIndex++;
        }

        id5 = stream.read(buf);
        if (id5 == EOF) {
          return EOF;
        }
        bufIndex = 0;

      } while (true);

    }

    public byte nextByte() throws IOException {
      return (byte) nextInt();
    }

    public int nextInt() throws IOException {

      if (id4(DASH - 1) == EOF) {
        throw new IOException();
      }
      int sgn = 1, res = 0;

      c = buf[bufIndex];
      if (c == DASH) {
        sgn = -1;
        bufIndex++;
      }

      do {

        while (bufIndex < id5) {
          if (buf[bufIndex] > SPACE) {
            res = (res << 3) + (res << 1);
            res += ints[buf[bufIndex++]];
          } else {
            bufIndex++;
            return res * sgn;
          }
        }

        id5 = stream.read(buf);
        if (id5 == EOF) {
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
      if (id4(DASH - 1) == EOF) {
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
        while (bufIndex < id5) {
          if (buf[bufIndex] > SPACE) {
            res = (res << 3) + (res << 1);
            res += ints[buf[bufIndex++]];
          } else {
            bufIndex++;
            return res * sgn;
          }
        }
        id5 = stream.read(buf);
        if (id5 == EOF) {
          return res * sgn;
        }
        bufIndex = 0;
      } while (true);
    }

    public String nextString() throws IOException {
      if (id5 == EOF) {
        return null;
      }
      if (id4(SPACE) == EOF) {
        return null;
      }

      for (int i = 0;;) {
        while (bufIndex < id5) {
          if (buf[bufIndex] > SPACE) {
            if (i == charBuffer.length) {
              id1();
            }
            charBuffer[i++] = (char) buf[bufIndex++];
          } else {
            bufIndex++;
            return new String(charBuffer, 0, i);
          }
        }

        

        id5 = stream.read(buf);
        if (id5 == EOF) {
          return new String(charBuffer, 0, i);
        }
        bufIndex = 0;
      }
    }

    public long[] id6(int n) throws IOException {
      long[] ar = new long[n];
      for (int i = 0; i < n; i++) {
        ar[i] = nextLong();
      }
      return ar;
    }
  }

  public static void main(String args[]) throws Exception {
    int t = in.nextInt();
    while (t-- != 0) {
      solve();
    }
    out.print(sb.toString());
    out.close();
  }

  static void solve() throws IOException {
    int n = in.nextInt();
    int[][] childrens = new int[n][2];
    for (int[] arr : childrens) {
      Arrays.fill(arr, -1);
    }
    List<Integer>[] edges = new ArrayList[n];
    for (int i = 0;i<n;i++) {
      edges[i] = new ArrayList<>(3);
    }
    for (int i = 1; i < n; i++) {
      int u = in.nextInt() - 1;
      int v = in.nextInt() - 1;
      edges[u].add(v);
      edges[v].add(u);
    }
    
    dfs3(edges, childrens, 0);
    
    int[] childCount = new int[n];
    dfs(childrens, childCount, 0);
    
    int[] dp = new int[n];
    dfs2(childrens, childCount, dp, 0);
    sb.append(dp[0]).append("\n");
  }

  private static void dfs(int[][] childrens, int[] childCount, int root) {
    int left = childrens[root][0];
    if (left != -1) {
      dfs(childrens, childCount, left);
      childCount[root] += 1 +childCount[left];
    }
    int right = childrens[root][1];
    if (right != -1) {
      dfs(childrens, childCount, right);
      childCount[root] += 1 +childCount[right];
    }
  }
  

  private static void dfs2(int[][] childrens, int[] childCount, int[] dp, int root) {
    int left = childrens[root][0];
    int right = childrens[root][1];
    if (left == -1 && right == -1) {
      dp[root] = 0;
      return;
    }
    if (left == -1) {
      dp[root] = childCount[right];
      return;
    }
    if (right == -1) {
      dp[root] = childCount[left];
      return;
    }
    dfs2(childrens, childCount,dp, left);
    dfs2(childrens, childCount,dp, right);
    dp[root] = Math.max(childCount[left] + dp[right] , childCount[right] + dp[left]);
  }
}