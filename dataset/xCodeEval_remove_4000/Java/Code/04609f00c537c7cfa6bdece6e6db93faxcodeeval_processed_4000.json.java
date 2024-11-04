
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;
import java.util.concurrent.ThreadLocalRandom;

public class E {

  
  static InputReader in = new InputReader(System.in);
  private static StringBuilder sb;

  static class InputReader {

    private static final int id7 = 1 << 16;
    private static final InputStream DEFAULT_STREAM = System.in;
    private static final int id8 = 21;
    private int c;
    private byte[] buf;
    private int bufferSize, bufIndex, id10;

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
      this(DEFAULT_STREAM, id7);
    }

    public InputReader(int bufferSize) {
      this(DEFAULT_STREAM, bufferSize);
    }

    public InputReader(InputStream stream) {
      this(stream, id7);
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

      if (id10 == EOF) {
        throw new IOException();
      }

      if (bufIndex >= id10) {
        bufIndex = 0;
        id10 = stream.read(buf);
        if (id10 == EOF) {
          return EOF;
        }
      }

      return buf[bufIndex++];
    }

    private void id5() {
      char[] newBuffer = new char[charBuffer.length << 1];
      for (int i = 0; i < charBuffer.length; i++) {
        newBuffer[i] = charBuffer[i];
      }
      charBuffer = newBuffer;
    }

    private int id2(int token) throws IOException {

      if (id10 == EOF) {
        return EOF;
      }

      do {

        while (bufIndex < id10) {
          if (buf[bufIndex] > token) {
            return 0;
          }
          bufIndex++;
        }

        id10 = stream.read(buf);
        if (id10 == EOF) {
          return EOF;
        }
        bufIndex = 0;

      } while (true);

    }

    public byte nextByte() throws IOException {
      return (byte) nextInt();
    }

    public int nextInt() throws IOException {

      if (id2(DASH - 1) == EOF) {
        throw new IOException();
      }
      int sgn = 1, res = 0;

      c = buf[bufIndex];
      if (c == DASH) {
        sgn = -1;
        bufIndex++;
      }

      do {

        while (bufIndex < id10) {
          if (buf[bufIndex] > SPACE) {
            res = (res << 3) + (res << 1);
            res += ints[buf[bufIndex++]];
          } else {
            bufIndex++;
            return res * sgn;
          }
        }

        id10 = stream.read(buf);
        if (id10 == EOF) {
          return res * sgn;
        }
        bufIndex = 0;

      } while (true);

    }

    public int[] id6(int n) throws IOException {
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
      if (id2(DASH - 1) == EOF) {
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
        while (bufIndex < id10) {
          if (buf[bufIndex] > SPACE) {
            res = (res << 3) + (res << 1);
            res += ints[buf[bufIndex++]];
          } else {
            bufIndex++;
            return res * sgn;
          }
        }
        id10 = stream.read(buf);
        if (id10 == EOF) {
          return res * sgn;
        }
        bufIndex = 0;
      } while (true);
    }

    public String nextString() throws IOException {
      if (id10 == EOF) {
        return null;
      }
      if (id2(SPACE) == EOF) {
        return null;
      }

      for (int i = 0;;) {
        while (bufIndex < id10) {
          if (buf[bufIndex] > SPACE) {
            if (i == charBuffer.length) {
              id5();
            }
            charBuffer[i++] = (char) buf[bufIndex++];
          } else {
            bufIndex++;
            return new String(charBuffer, 0, i);
          }
        }

        

        id10 = stream.read(buf);
        if (id10 == EOF) {
          return new String(charBuffer, 0, i);
        }
        bufIndex = 0;
      }
    }
  }

  static boolean[][] id3;

  public static void main(String[] args) throws IOException {
    PrintWriter out = new PrintWriter(System.out);
    int T = in.nextInt();
    for (int tt = 0; tt < T; tt++) {
      int nPeople = in.nextInt();
      int nQuestions = in.nextInt();
      int[] expectedScores = in.id6(nPeople);
      id3 = new boolean[nPeople][nQuestions];
      for (int person = 0; person < nPeople; person++) {
        char[] line = in.nextString().toCharArray();
        for (int q = 0; q < nQuestions; q++) {
          id3[person][q] = line[q] == '1';
        }
      }

      ArrayList<Integer>[] count = new ArrayList[1 << nPeople];
      for (int q = 0; q < nQuestions; q++) {
        int mask = 0;
        for (int p = 0; p < nPeople; p++) {
          mask += (1 << p) * (id3[p][q] ? 1 : 0);
        }
        if (count[mask] == null) {
          count[mask] = new ArrayList<>();
        }
        count[mask].add(q);
      }
      int id1 = 0;
      for (ArrayList<Integer> l : count) {
        if (l != null) {
          id1++;
        }
      }
      Question[] questions = new Question[id1];
      id1 = 0;
      for (int mask = 0; mask < 1 << nPeople; mask++) {
        if (count[mask] == null) {
          continue;
        }
        questions[id1++] = new Question(mask, count[mask]);
      }
      long best = 0;
      int bestMask = 0;
      for (int mask = 0; mask < 1 << nPeople; mask++) {
        

        long id9 = 0;
        for (int i = 0; i < nPeople; i++) {
          if ((mask & (1 << i)) != 0) {
            id9 += expectedScores[i];
          } else {
            id9 -= expectedScores[i];
          }
        }

        long id4 = id4(mask, nQuestions, nPeople, questions, false);
        if (id4 + id9 > best) {
          best = id4 + id9;
          bestMask = mask;
        }



      }


      finalAns = new int[nQuestions];
      id4(bestMask, nQuestions, nPeople, questions, true);
      for (int i = 0; i < nQuestions; i++) {
        out.print(finalAns[i] + " ");
      }
      out.println();
    }
    out.close();
  }

  static int[] finalAns;

  static long id4(int mask, int nQuestions, int nPeople,
  Question[] questions, boolean markAns) {
    for (Question q : questions) {
      q.netValue = 0;
      for (int i = 0; i < nPeople; i++) {
        if ((q.mask & (1 << i)) != 0) {
          if ((mask & (1 << i)) != 0) {
            q.netValue--;
          } else {
            q.netValue++;
          }
        }
      }
    }
    Arrays.sort(questions);
    long ans = 0;
    int next = 1;
    for (Question qq : questions) {








      for (int i : qq.originalPositions) {
        ans += next * qq.netValue;
        if (markAns) {
          finalAns[i] = next;
        }
        next++;
      }
    }
    return ans;
  }

  static class Question implements Comparable<Question> {

    int mask;
    int netValue;
    int count;
    ArrayList<Integer> originalPositions;

    public Question(int mask, ArrayList<Integer> originalPositions) {
      this.mask = mask;
      this.count = originalPositions.size();
      this.originalPositions = originalPositions;
    }

    public int compareTo(Question o) {
      return Integer.compare(netValue, o.netValue);
    }
  }

  static final Random random = new Random();
  static final int mod = 1_000_000_007;

  static void id0(int[] a) {
    int n = a.length;

    for (int i = 0; i < n; i++) {
      int oi = random.nextInt(n), temp = a[oi];
      a[oi] = a[i];
      a[i] = temp;
    }
    Arrays.sort(a);
  }

  static long add(long a, long b) {
    return (a + b) % mod;
  }

  static long sub(long a, long b) {
    return ((a - b) % mod + mod) % mod;
  }

  static long mul(long a, long b) {
    return (a * b) % mod;
  }

  static void sort(int[] a) {
    ArrayList<Integer> l = new ArrayList<>();
    for (int i : a) {
      l.add(i);
    }
    Collections.sort(l);
    for (int i = 0; i < a.length; i++) {
      a[i] = l.get(i);
    }
  }
}
