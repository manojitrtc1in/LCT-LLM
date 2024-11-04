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
import java.util.HashMap;
import java.util.HashSet;
import java.util.InputMismatchException;
import java.util.StringTokenizer;

public class CodeB {
  private static final boolean SHOULD_BUFFER_OUTPUT = true;

  static final SuperWriter sw = new SuperWriter(System.out);

  static final SuperScanner sc = new SuperScanner();


  
  static class Edge 
  {
    int from, to, index;
    long cap, flow;
 
    Edge(int fromi, int toi, long capi, long flowi, int indexi)
    {
      from = fromi;
      to = toi;
      cap = capi;
      flow = flowi;
      index = indexi;
    }
  }
 
  static class PushRelabel 
  {
    int N;
    ArrayList <Edge> [] G;
    long[] excess;
    int[] dist, count;
    boolean[] active;
    ArrayDeque <Integer> Q = new ArrayDeque <Integer> ();
 
    @SuppressWarnings("unchecked")
    PushRelabel(int N1)
    {
      N = N1;
      G = new ArrayList[N];
      for(int i = 0; i < N; i++)
        G[i] = new ArrayList <Edge> ();
      excess = new long[N];
      dist = new int[N];
      active = new boolean[N];
      count = new int[2 * N];
    }
     
    void clear(int n)
    {
      N = n;
      for(int i = 0; i < N; i++)
        G[i].clear();
      for(int i = 0; i < N; i++)
      {
        excess[i] = 0;
        dist[i] = 0;
        active[i] = false;
      }
      int dosN = 2 * N;
      for(int i = 0; i < dosN; i++)
        count[i] = 0;
    }
 
    void AddEdge(int from, int to, int cap) 
    {
      int cambio = from == to ? 1 : 0;
      G[from].add(new Edge(from, to, cap, 0, G[to].size() + cambio));
      G[to].add(new Edge(to, from, 0, 0, G[from].size() - 1));
    }
 
    void Enqueue(int v) 
    { 
      if (!active[v] && excess[v] > 0)
      { 
        active[v] = true;
        Q.add(v); 
      } 
    }
 
    void Push(Edge e) 
    {
      long amt = Math.min(excess[e.from], e.cap - e.flow);
      if(dist[e.from] <= dist[e.to] || amt == 0) 
        return;
      e.flow += amt;
      G[e.to].get(e.index).flow -= amt;
      excess[e.to] += amt; 
      excess[e.from] -= amt;
      Enqueue(e.to);
    }
 
    void Gap(int k) 
    {
      for(int v = 0; v < N; v++) 
      {
        if(dist[v] < k) 
          continue;
        count[dist[v]]--;
        dist[v] = Math.max(dist[v], N + 1);
        count[dist[v]]++;
        Enqueue(v);
      }
    }
 
    void Relabel(int v) 
    {
      count[dist[v]]--;
      dist[v] = 2 * N;
      for (Edge e : G[v]) 
        if (e.cap - e.flow > 0)
          dist[v] = Math.min(dist[v], dist[e.to] + 1);
      count[dist[v]]++;
      Enqueue(v);
    }
 
    void Discharge(int v) 
    {
      for(Edge e : G[v])
      {
        if(excess[v] <= 0)
          break;
        Push(e);
      }
      if(excess[v] > 0) 
      {
        if(count[dist[v]] == 1) 
          Gap(dist[v]); 
        else
          Relabel(v);
      }
    }
 
    long GetMaxFlow(int s, int t)
    {
      count[0] = N - 1;
      count[N] = 1;
      dist[s] = N;
      active[s] = active[t] = true;
      for (Edge e : G[s]) 
      {
        excess[s] += e.cap;
        Push(e);
      }
      while (!Q.isEmpty()) 
      {
        int v = Q.poll();
        active[v] = false;
        Discharge(v);
      }
      long totflow = 0;
      for (Edge e : G[s]) 
        totflow += e.flow;
      return totflow;
    }
  }

  static String getFirstChoice(String[] team) {
    return team[0].substring(0, 3);
  }

  static String getSecondChoice(String[] team) {
    return team[0].substring(0, 2) + team[1].substring(0, 1);
  }

  public static void main() {
    int n = sc.nextLineScanner().nextInt();
    String[][] teams = new String[n][];
    for (int i = 0; i < n; i++) {
      teams[i] = sc.nextLineScanner().asStringArray();
    }
    HashMap<String, Integer> firstChoices = new HashMap<>();
    HashSet<String> allChoices = new HashSet<>();
    for (int i = 0; i < n; i++) {
      String firstChoice = getFirstChoice(teams[i]);
      firstChoices.putIfAbsent(firstChoice, 0);
      firstChoices.put(firstChoice, firstChoices.get(firstChoice) + 1);
      allChoices.add(firstChoice);
      allChoices.add(getSecondChoice(teams[i]));
    }
    HashMap<String, Integer> choices = new HashMap<>();
    HashMap<Integer, String> choicesInverse = new HashMap<>();
    int currentChoice = 0;
    for (String choice : allChoices) {
      choices.put(choice, currentChoice);
      choicesInverse.put(currentChoice++, choice);
    }
    int currentId = 0;
    int source = currentId++;
    int sink = currentId++;
    int[] ids = new int[n];
    for (int i = 0; i < n; i++) {
      ids[i] = currentId++;
    }
    HashMap<Integer, Integer> choiceIds = new HashMap<>();
    HashMap<Integer, String> choiceIdsInverse = new HashMap<>();
    for (int i = 0; i < currentChoice; i++) {
      choiceIds.put(i, currentId);
      choiceIdsInverse.put(currentId++, choicesInverse.get(i));
    }
    PushRelabel mf = new PushRelabel(currentId);
    HashSet<String> firstChoicesNotPossible = new HashSet<>();
    for (int i = 0; i < n; i++) {
      String firstChoice = getFirstChoice(teams[i]);
      if (firstChoices.get(firstChoice) > 1) {
        firstChoicesNotPossible.add(firstChoice);
      }
    }
    for (int i = 0; i < n; i++) {
      mf.AddEdge(source, ids[i], 1);
      String firstChoice = getFirstChoice(teams[i]);
      if (!firstChoicesNotPossible.contains(firstChoice)) {
        mf.AddEdge(ids[i], choiceIds.get(choices.get(firstChoice)), 1);
      }
      String secondChoice = getSecondChoice(teams[i]);
      mf.AddEdge(ids[i], choiceIds.get(choices.get(secondChoice)), 1);
    }
    for (int i : choiceIds.values()) {
      mf.AddEdge(i, sink, 1);
    }
    long maxFlow = mf.GetMaxFlow(source, sink);
    if (maxFlow != n) {
      sw.printLine("NO");
    } else {
      sw.printLine("YES");
      for (int i = 0; i < n; i++) {
        ArrayList<Edge> edges = mf.G[ids[i]];
        for (Edge edge : edges) {
          if (edge.flow == 1) {
            sw.printLine(choiceIdsInverse.get(edge.to));
          }
        }
      }
    }
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
            throw new InputMismatchException();
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
