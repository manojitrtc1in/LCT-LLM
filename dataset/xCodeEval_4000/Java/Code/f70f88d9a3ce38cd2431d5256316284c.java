import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.Writer;
import java.lang.reflect.Constructor;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.InputMismatchException;
import java.util.StringTokenizer;

public class CodeC {
  private static final boolean SHOULD_BUFFER_OUTPUT = false;

  static final SuperWriter sw = new SuperWriter(System.out);

  static final SuperScanner sc = new SuperScanner();

  static class Line {
    static final double MIN_VALUE = Double.NEGATIVE_INFINITY;

    final double m;
    final double b;
    double minX; 


    Line(double m, double b) {
      this.m = m;
      this.b = b;
    }

    double evaluate(double x) {
      return m * x + b;
    }

    double intersectionX(Line l2) {
      return (this.b - l2.b) / (l2.m - this.m);
    }

    

    boolean isIrrelevant(Line l1, Line l3) {
      return (l3.b - l1.b) * (l1.m - this.m) < (this.b - l1.b) * (l1.m - l3.m);
    }
  }

  static class DecreasingConvex {
    static final Line[] lines = new Line[200000];
    int head = -1;
    int currentPoint = 0;

    void add(Line line) {
      if (line.b == Double.POSITIVE_INFINITY) {
        return;
      }
      while (true) {
        if (head <= 0) {
          lines[++head] = line;
          Line previous = head == 0 ? null : lines[head - 1];
          line.minX = previous == null ? Line.MIN_VALUE : previous.intersectionX(line);
          return;
        }
        Line previous = lines[head];
        Line previousPrevious = lines[head - 1];
        if (previous.isIrrelevant(previousPrevious, line)) {
          head--;
        } else {
          line.minX = previous == null ? Line.MIN_VALUE : previous.intersectionX(line);
          lines[++head] = line;
          return;
        }
      }
    }

    

    

    double getBest(double value) {
      if (head == -1) {
        return Double.POSITIVE_INFINITY;
      }
      while (true) {
        if (currentPoint == head) {
          return lines[currentPoint].evaluate(value);
        }
        Line next = lines[currentPoint + 1];
        if (next.minX <= value) {
          currentPoint++;
        } else {
          break;
        }
      }
      return lines[currentPoint].evaluate(value);
    }
  }

  static double[] lastDp;
  static double[] currentDp;
  static double[] t;
  static int currentK;

  static void search(int a, int b) {
    DecreasingConvex convex = new DecreasingConvex();
    double currentSum = 0;
    double previousSum = 0;
    double fromStart = 0;
    double sum = 0;
    double divisors = 0;
    for (int i = a; i <= b; i++) {
      convex.add(new Line(-currentSum,
          (i == 0 ? (currentK == 1 ? 0.0d : Double.POSITIVE_INFINITY) : lastDp[i - 1]) - previousSum + currentSum * divisors));
      currentSum += t[i];
      previousSum += (currentSum) / t[i];
      fromStart += t[i];
      sum += fromStart / t[i];
      divisors += 1 / t[i];
      currentDp[i] = Math.min(currentDp[i], sum + convex.getBest(divisors));
    }
  }

  public static void main() {
    int n = sc.nextInt();
    int k = sc.nextInt();
    t = sc.nextDoubleArray(n);
    lastDp = new double[n];
    Arrays.fill(lastDp, Double.POSITIVE_INFINITY);
    currentDp = new double[n];
    for (int i = 0; i < k; i++) {
      currentK = i + 1;
      Arrays.fill(currentDp, Double.POSITIVE_INFINITY);
      search(0, n - 1);
      double[] tmp = lastDp;
      lastDp = currentDp;
      currentDp = tmp;
    }
    sw.printLine(lastDp[n - 1]);
  }

  static class LineScanner extends Scanner {
    private StringTokenizer st;

    public LineScanner(String input) {
      st = new StringTokenizer(input);
    }

    @Override
    public String next() {
      return st.hasMoreTokens() ? st.nextToken() : null;
    }

    @Override
    public String nextLine() {
      throw new RuntimeException("not supported");
    }

    public boolean hasNext() {
      return st.hasMoreTokens();
    }

    private final ArrayList<Object> temp = new ArrayList<Object>();

    private void fillTemp() {
      while (st.hasMoreTokens()) {
        temp.add(st.nextToken());
      }
    }

    public String[] asStringArray() {
      fillTemp();
      String[] answer = new String[temp.size()];
      for (int i = 0; i < answer.length; i++) {
        answer[i] = (String) temp.get(i);
      }
      temp.clear();
      return answer;
    }

    public int[] asIntArray() {
      fillTemp();
      int[] answer = new int[temp.size()];
      for (int i = 0; i < answer.length; i++) {
        answer[i] = Integer.parseInt((String) temp.get(i));
      }
      temp.clear();
      return answer;
    }

    public long[] asLongArray() {
      fillTemp();
      long[] answer = new long[temp.size()];
      for (int i = 0; i < answer.length; i++) {
        answer[i] = Long.parseLong((String) temp.get(i));
      }
      temp.clear();
      return answer;
    }

    public double[] asDoubleArray() {
      fillTemp();
      double[] answer = new double[temp.size()];
      for (int i = 0; i < answer.length; i++) {
        answer[i] = Double.parseDouble((String) temp.get(i));
      }
      temp.clear();
      return answer;
    }
  }

  static class SuperScanner extends Scanner {
    private InputStream stream;
    private byte[] buf = new byte[8096];
    private int curChar;
    private int numChars;

    public SuperScanner() {
        this.stream = System.in;
    }

    public int read() {
        if (numChars == -1)
            return -1;
        if (curChar >= numChars) {
            curChar = 0;
            try {
                numChars = stream.read(buf);
            } catch (IOException e) {
                throw new InputMismatchException();
            }
            if (numChars <= 0)
                return -1;
        }
        return buf[curChar++];
    }
    
    public static boolean isWhitespace(int c) {
      return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }

    public static boolean isLineEnd(int c) {
      return c == '\n' || c == -1;
    }
    
    private final StringBuilder sb = new StringBuilder();
    
    @Override
    public String next() {
      int c = read();
      while (isWhitespace(c)) {
          if (c == -1) {
            return null;
          }
          c = read();
      }
      sb.setLength(0);
      do {
          sb.append((char) c);
          c = read();
      } while (!isWhitespace(c));
      return sb.toString();
    }

    @Override
    public String nextLine() {
      sb.setLength(0);
      int c;
      while (true) {
        c = read();
        if (!isLineEnd(c)) {
          sb.append((char) c);
        } else {
          break;
        }
      }
      if (c == -1 && sb.length() == 0) {
        return null;
      } else {
        if (sb.length() > 0 && sb.charAt(sb.length() - 1) == '\r') {
          return sb.substring(0, sb.length() - 1);
        } else {
          return sb.toString();
        }
      }
    }

    public LineScanner nextLineScanner() {
      String line = nextLine();
      if (line == null) {
        return null;
      } else {
        return new LineScanner(line);
      }
    }

    public LineScanner nextNonEmptyLineScanner() {
      while (true) {
        String line = nextLine();
        if (line == null) {
          return null;
        } else if (!line.isEmpty()) {
          return new LineScanner(line);
        }
      }
    }

    @Override
    public int nextInt() {
        int c = read();
        while (isWhitespace(c)) {
            c = read();
        }
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        int res = 0;
        do {
            if (c < '0' || c > '9')
                throw new InputMismatchException();
            res = (res << 3) + (res << 1);
            res += c - '0';
            c = read();
        } while (!isWhitespace(c));
        return res * sgn;
    }

    @Override
    public long nextLong() {
        int c = read();
        while (isWhitespace(c))
            c = read();
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        long res = 0;
        do {
            if (c < '0' || c > '9')
                throw new InputMismatchException();
            res = (res << 3) + (res << 1);
            res += c - '0';
            c = read();
        } while (!isWhitespace(c));
        return res * sgn;
    }
  }
  
  static abstract class Scanner {

    public abstract String next();

    public abstract String nextLine();

    public int nextIntOrQuit() {
      Integer n = nextInteger();
      if (n == null) {
        sw.close();
        System.exit(0);
      }
      return n.intValue();
    }

    public int nextInt() {
      return Integer.parseInt(next());
    }

    public long nextLong() {
      return Long.parseLong(next());
    }

    public double nextDouble() {
      return Double.parseDouble(next());
    }

    public int[] nextIntArray(int n) {
      int[] res = new int[n];
      for (int i = 0; i < res.length; i++)
        res[i] = nextInt();
      return res;
    }

    public long[] nextLongArray(int n) {
      long[] res = new long[n];
      for (int i = 0; i < res.length; i++)
        res[i] = nextLong();
      return res;
    }

    public double[] nextDoubleArray(int n) {
      double[] res = new double[n];
      for (int i = 0; i < res.length; i++)
        res[i] = nextDouble();
      return res;
    }

    public void sortIntArray(int[] array) {
      Integer[] vals = new Integer[array.length];
      for (int i = 0; i < array.length; i++)
        vals[i] = array[i];
      Arrays.sort(vals);
      for (int i = 0; i < array.length; i++)
        array[i] = vals[i];
    }

    public void sortLongArray(long[] array) {
      Long[] vals = new Long[array.length];
      for (int i = 0; i < array.length; i++)
        vals[i] = array[i];
      Arrays.sort(vals);
      for (int i = 0; i < array.length; i++)
        array[i] = vals[i];
    }

    public void sortDoubleArray(double[] array) {
      Double[] vals = new Double[array.length];
      for (int i = 0; i < array.length; i++)
        vals[i] = array[i];
      Arrays.sort(vals);
      for (int i = 0; i < array.length; i++)
        array[i] = vals[i];
    }

    public String[] nextStringArray(int n) {
      String[] vals = new String[n];
      for (int i = 0; i < n; i++)
        vals[i] = next();
      return vals;
    }

    public Integer nextInteger() {
      String s = next();
      if (s == null)
        return null;
      return Integer.parseInt(s);
    }

    public int[][] nextIntMatrix(int n, int m) {
      int[][] ans = new int[n][];
      for (int i = 0; i < n; i++)
        ans[i] = nextIntArray(m);
      return ans;
    }

    public char[][] nextGrid(int r) {
      char[][] grid = new char[r][];
      for (int i = 0; i < r; i++)
        grid[i] = next().toCharArray();
      return grid;
    }

    public static <T> T fill(T arreglo, int val) {
      if (arreglo instanceof Object[]) {
        Object[] a = (Object[]) arreglo;
        for (Object x : a)
          fill(x, val);
      } else if (arreglo instanceof int[])
        Arrays.fill((int[]) arreglo, val);
      else if (arreglo instanceof double[])
        Arrays.fill((double[]) arreglo, val);
      else if (arreglo instanceof long[])
        Arrays.fill((long[]) arreglo, val);
      return arreglo;
    }

    public <T> T[] nextObjectArray(Class<T> clazz, int size) {
      @SuppressWarnings("unchecked")
      T[] result = (T[]) java.lang.reflect.Array.newInstance(clazz, size);
      for (int c = 0; c < 3; c++) {
        Constructor<T> constructor;
        try {
          if (c == 0)
            constructor = clazz.getDeclaredConstructor(Scanner.class,
                Integer.TYPE);
          else if (c == 1)
            constructor = clazz.getDeclaredConstructor(Scanner.class);
          else
            constructor = clazz.getDeclaredConstructor();
        } catch (Exception e) {
          continue;
        }
        try {
          for (int i = 0; i < result.length; i++) {
            if (c == 0)
              result[i] = constructor.newInstance(this, i);
            else if (c == 1)
              result[i] = constructor.newInstance(this);
            else
              result[i] = constructor.newInstance();
          }
        } catch (Exception e) {
          throw new RuntimeException(e);
        }
        return result;
      }
      throw new RuntimeException("Constructor not found");
    }

    public Collection<Integer> wrap(int[] as) {
      ArrayList<Integer> ans = new ArrayList<Integer>();
      for (int i : as)
        ans.add(i);
      return ans;
    }

    public int[] unwrap(Collection<Integer> collection) {
      int[] vals = new int[collection.size()];
      int index = 0;
      for (int i : collection)
        vals[index++] = i;
      return vals;
    }

    int testCases = Integer.MIN_VALUE;

    boolean testCases() {
      if (testCases == Integer.MIN_VALUE) {
        testCases = nextInt();
      }
      return --testCases >= 0;
    }
  }

  static class SuperWriter {

    private final PrintWriter writer;

    public SuperWriter(OutputStream outputStream) {
      writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
    }

    public SuperWriter(Writer writer) {
        this.writer = new PrintWriter(writer);
    }

    public void close() {
        writer.flush();
        writer.close();
    }

    public void printLine(String line) {
      writer.println(line);
      if (!SHOULD_BUFFER_OUTPUT) {
        writer.flush();
      }
    }

    public void printLine(int... vals) {
      if (vals.length == 0) {
        writer.println();
      } else {
        writer.print(vals[0]);
        for (int i = 1; i < vals.length; i++)
          writer.print(" ".concat(String.valueOf(vals[i])));
        writer.println();
      }
      if (!SHOULD_BUFFER_OUTPUT) {
        writer.flush();
      }
    }

    public void printLine(long... vals) {
      if (vals.length == 0) {
        writer.println();
      } else {
        writer.print(vals[0]);
        for (int i = 1; i < vals.length; i++)
          writer.print(" ".concat(String.valueOf(vals[i])));
        writer.println();
      }
      if (!SHOULD_BUFFER_OUTPUT) {
        writer.flush();
      }
    }

    public void printLine(double... vals) {
      if (vals.length == 0) {
        writer.println();
      } else {
        writer.print(vals[0]);
        for (int i = 1; i < vals.length; i++)
          writer.print(" ".concat(String.valueOf(vals[i])));
        writer.println();
      }
      if (!SHOULD_BUFFER_OUTPUT) {
        writer.flush();
      }
    }

    public void printLine(int prec, double... vals) {
      if (vals.length == 0) {
        writer.println();
      } else {
        String precision = "%." + prec + "f";
        writer.print(String.format(precision, vals[0]).replace(',', '.'));
        precision = " " + precision;
        for (int i = 1; i < vals.length; i++)
          writer.print(String.format(precision, vals[i]).replace(',', '.'));
        writer.println();
      }
      if (!SHOULD_BUFFER_OUTPUT) {
        writer.flush();
      }
    }

    public <E> void printLine(Collection<E> vals) {
      if (vals.size() == 0) {
        writer.println();
      } else {
        int i = 0;
        for (E val : vals) {
          if (i++ == 0) {
            writer.print(val.toString());
          } else {
            writer.print(" ".concat(val.toString()));
          }
        }
        writer.println();
      }
      if (!SHOULD_BUFFER_OUTPUT) {
        writer.flush();
      }
    }

    public void printSimple(String value) {
      writer.print(value);
      if (!SHOULD_BUFFER_OUTPUT) {
        writer.flush();
      }
    }

    public boolean ifZeroExit(Number... values) {
    	for (Number number : values) {
    		if (number.doubleValue() != 0.0d || number.longValue() != 0) {
    			return false;
    		}
    	}
    	close();
    	System.exit(0);
    	return true;
    }
  }


  public static void main(String[] args) {
    main();
    sw.close();
  }
}
