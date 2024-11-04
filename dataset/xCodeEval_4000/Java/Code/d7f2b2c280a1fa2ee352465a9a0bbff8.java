import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.Writer;
import java.lang.reflect.Constructor;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.Collections;
import java.util.InputMismatchException;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class CodeB {
  private static final boolean SHOULD_BUFFER_OUTPUT = false;

  static final SuperWriter sw = new SuperWriter(System.out);

  static final SuperScanner sc = new SuperScanner();

  static Node[] nodes;

  static class Answer implements Comparable<Answer> {
    final int[] nodes;
    final int cost;

    Answer(int a, int b, int cost) {
      this.nodes = new int[]{a, b};
      this.cost = cost;
    }

    public Answer(Answer other, int id, int addedCost) {
      this.nodes = new int[other.nodes.length + 1];
      this.nodes[0] = id;
      for (int i = 0; i < other.nodes.length; i++) {
        this.nodes[i + 1] = other.nodes[i];
      }
      this.cost = other.cost + addedCost;
    }

    boolean contains(int id) {
      for (int i : nodes) {
        if (i == id) {
          return true;
        }
      }
      return false;
    }

    @Override
    public int compareTo(Answer o) {
      return o.cost - cost;
    }
  }

  
  static Answer[] tmpSort;

  static Answer[] getN(ArrayList<Answer> values, int n) {
    Answer[] answer = new Answer[n];
    int currentMinIndex = 0;
    int currentSize = 0;
    for (Answer v : values) {
      if (currentSize != n) {
        answer[currentSize++] = v;
        int min = Integer.MAX_VALUE;
        for (int i = 0; i < n; i++) {
          if (answer[i] != null && answer[i].cost < min) {
            currentMinIndex = i;
            min = answer[i].cost;
          }
        }
      } else {
        if (v.cost > answer[currentMinIndex].cost) {
          answer[currentMinIndex] = v;
        }
        int min = Integer.MAX_VALUE;
        for (int i = 0; i < n; i++) {
          if (answer[i] != null && answer[i].cost < min) {
            currentMinIndex = i;
            min = answer[i].cost;
          }
        }
      }
    }
    Arrays.sort(answer);
    return answer;
  }

  static class Node {
    final ArrayList<Node> edges = new ArrayList<>();
    final int id;
    int visitedCost;
    int[] costs;
    Answer[] first;
    Answer[] second;

    Node(int id) {
      this.id = id;
    }

    Answer[] getFirst() {
      if (first != null) {
        return first;
      }
      ArrayList<Answer> firstTmp = new ArrayList<>();
      for (int i = 0; i < costs.length; i++) {
        int cost = costs[i];
        if ((i == id) || (cost == Integer.MAX_VALUE)) {
          continue;
        }
        firstTmp.add(new Answer(id, i, cost));
      }
      first = getN(firstTmp, Math.min(firstTmp.size(), 3));
      return first;
    }

    Answer[] getSecond() {
      if (second != null) {
        return second;
      }
      LinkedList<Integer> missing = new LinkedList<>();
      for (int i = 0; i < nodes.length; i++) {
        if (i != id) {
          missing.add(i);
        }
      }
      ArrayList<Answer> secondTmp = new ArrayList<>();
      for (int i = 0; i < costs.length; i++) {
        int cost = costs[i];
        if ((i == id) || (cost == Integer.MAX_VALUE)) {
          continue;
        }
        for (Answer answer : nodes[i].getFirst()) {
          if (!answer.contains(id)) {
            secondTmp.add(new Answer(answer, id, cost));
          }
        }
      }
      Answer[] secondTmp2 = getN(secondTmp, Math.min(secondTmp.size(), 4));
      ArrayList<Answer> relevants = new ArrayList<>();
      for (Answer answer : secondTmp2) {
        if (missing.isEmpty()) {
          break;
        }
        boolean relevant = false;
        Iterator<Integer> it = missing.iterator();
        while (it.hasNext()) {
          int next = it.next();
          if (!answer.contains(next)) {
            it.remove();
            relevant = true;
          }
        }
        if (relevant) {
          relevants.add(answer);
        }
      }
      return second = relevants.toArray(new Answer[0]);
    }

    Answer getSolution(int first, int cost) {
      for (Answer answer : getSecond()) {
        if (!answer.contains(first)) {
          return new Answer(answer, first, cost);
        }
      }
      return null;
    }

    Answer getSolution() {
      Answer best = null;
      for (int i = 0; i < costs.length; i++) {
        int cost = costs[i];
        if ((i == id) || (cost == Integer.MAX_VALUE)) {
          continue;
        }
        Answer possible = nodes[i].getSolution(id, cost);
        if (possible != null) {
          if (best == null || possible.cost > best.cost) {
            best = possible;
          }
        }
      }
      return best;
    }
  }

  static int[] getCosts(Node[] nodes, int fromNode) {
    for (Node node : nodes) {
      node.visitedCost = Integer.MAX_VALUE;
    }
    int[] answer = new int[nodes.length];
    Arrays.fill(answer, Integer.MAX_VALUE);
    answer[fromNode] = 0;
    nodes[fromNode].visitedCost = 0;
    ArrayDeque<Node> queue = new ArrayDeque<>();
    queue.add(nodes[fromNode]);
    while (!queue.isEmpty()) {
      Node current = queue.pollFirst();
      for (Node edge : current.edges) {
        if (edge.visitedCost != Integer.MAX_VALUE) {
          continue;
        }
        answer[edge.id] = edge.visitedCost = answer[current.id] + 1;
        queue.add(edge);
      }
    }
    return answer;
  }

  public static void main() {
    int n = sc.nextInt();
    int m = sc.nextInt();
    nodes = new Node[n];
    tmpSort = new Answer[4 * (m + 1)];
    for (int i = 0; i < n; i++) {
      nodes[i] = new Node(i);
    }
    for (int i = 0; i < m; i++) {
      int u = sc.nextInt() - 1;
      int v = sc.nextInt() - 1;
      nodes[u].edges.add(nodes[v]);
    }
    for (int i = 0; i < n; i++) {
      nodes[i].costs = getCosts(nodes, i);
    }
    for (int i = 0; i < n; i++) {
      nodes[i].costs = getCosts(nodes, i);
    }
    Answer best = null;
    for (int i = 0; i < n; i++) {
      Answer possible = nodes[i].getSolution();
      if (possible != null) {
        if (best == null || possible.cost > best.cost) {
          best = possible;
        }
      }
    }
    for (int i = 0; i < 4; i++) {
      best.nodes[i]++;
    }
    sw.printLine(best.nodes);
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
