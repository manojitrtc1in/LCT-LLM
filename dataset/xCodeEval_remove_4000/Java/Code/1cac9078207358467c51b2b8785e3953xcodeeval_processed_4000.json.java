import java.io.*;
import java.lang.reflect.Constructor;
import java.util.*;

public class id12 {
    private static final boolean id6 = true;

    static final SuperWriter sw = new SuperWriter(System.out);

    static final SuperScanner sc = new SuperScanner();

    static class id24
    {
        final int[] queue;
        int head, tail;

        id24(int size)
        {
            queue = new int[size];
            clear();
        }


        void add(int val)
        {
            queue[++tail] = val;
        }

        int poll()
        {
            return queue[head++];
        }

        int pop() {
            return queue[tail--];
        }

        void clear()
        {
            head = 0; tail = -1;
        }

        boolean isEmpty()
        {
            return head > tail;
        }
    }

    static enum State {
        NO_PATHS,
        ONE_PATH,
        MORE_THAN_ONE_PATH,
        INFINITE_PATHS
    }

    static class Node implements Comparable<Node>
    {
        final int name;
        ArrayList<Node> id10 = new ArrayList<Node>();
        int lowlink = -1;
        int index = -1;
        int id15;
        int parents;
        boolean id9 = false;
        State state = State.NO_PATHS;
        boolean id21 = false;

        public Node(final int name)
        {
            this.name = name;
        }

        public int compareTo(final Node other)
        {
            return other == this ? 0 : -1;
        }
    }

    static class Strongly
    {
        final Node[] nodes;
        final id24 stack;
        final boolean[] inStack;

        public Strongly(int N)
        {
            nodes = new Node[N];
            for(int i = 0; i < N; i++)
                nodes[i] = new Node(i);
            stack = new id24(N);
            inStack = new boolean[N];
        }

        public void addEdge(int from, int to)
        {
            nodes[from].id10.add(nodes[to]);
        }

        int index = 0;
        ArrayList<ArrayList<Node>> SCC = new ArrayList<ArrayList<Node>> ();

        public ArrayList<ArrayList<Node>> SCC()
        {
            index = 0;
            SCC.clear();
            while (!stack.isEmpty()) {
                inStack[stack.pop()] = false;
            }
            stack.clear();
            for(int i = 0; i < nodes.length; i++)
                if(nodes[i].index == -1)
                    tarjan(nodes[i]);
            return SCC;
        }

        public void tarjan(Node v)
        {
            v.index = index;
            v.lowlink = index;
            index++;
            stack.add(v.name);
            inStack[v.name] = true;
            for(Node n : v.id10)
            {
                if(n.index == -1)
                {
                    tarjan(n);
                    v.lowlink = Math.min(v.lowlink, n.lowlink);
                }
                else if(inStack[n.name])
                    v.lowlink = Math.min(v.lowlink, n.index);
            }
            if(v.lowlink == v.index)
            {
                Node n;
                ArrayList<Node> component = new ArrayList<Node> ();
                do
                {
                    int nId = stack.pop();
                    inStack[nId] = false;
                    n = nodes[nId];
                    component.add(n);
                }
                while(n != v);
                SCC.add(component);
            }
        }

        int[] id8()
        {
            ArrayList<ArrayList<Node>> scc = SCC();
            for(int i = 0; i < scc.size(); i++)
                for(Node n : scc.get(i))
                    n.id15 = i;
            int[] dag = new int[scc.size()];
            for(int i = 0; i < scc.size(); i++)
            {
                for(Node n : scc.get(i))
                    for(Node o : n.id10)
                    {
                        if(n.id15 == o.id15) continue;
                        dag[i]++;
                    }
            }
            return dag;
        }
    }

    public static void solve() {
        int n = sc.nextInt();
        int m = sc.nextInt();
        Strongly scc = new Strongly(n);
        for (int i = 0; i < m; i++) {
            int a = sc.nextInt() - 1;
            int b = sc.nextInt() - 1;
            if (a == b) {
                scc.nodes[a].id9 = true;
            }
            scc.addEdge(a, b);
        }
        ArrayList<ArrayList<Node>> components = scc.SCC();
        for(int i = 0; i < components.size(); i++) {
            for (Node node : components.get(i)) {
                node.id15 = i;
            }
        }
        ArrayDeque<Node> nodes = new ArrayDeque<>();
        scc.nodes[0].state = State.ONE_PATH;
        scc.nodes[0].id21 = true;
        nodes.add(scc.nodes[0]);
        while (!nodes.isEmpty()) {
            Node current = nodes.pollFirst();
            current.id21 = false;
            for (Node adjacent : current.id10) {
                if (adjacent.id15 == current.id15) {
                    current.state = State.INFINITE_PATHS;
                    continue;
                }
            }
            for (Node adjacent : current.id10) {
                State nextState = State.INFINITE_PATHS;
                if (adjacent.state == State.NO_PATHS) {
                    nextState = current.state;
                } else if (adjacent.state == State.ONE_PATH) {
                    if (current.state == State.INFINITE_PATHS) {
                        nextState = State.INFINITE_PATHS;
                    } else {
                        nextState = State.MORE_THAN_ONE_PATH;
                    }
                } else if (adjacent.state == State.MORE_THAN_ONE_PATH) {
                    if (current.state == State.INFINITE_PATHS) {
                        nextState = State.INFINITE_PATHS;
                    } else {
                        nextState = State.MORE_THAN_ONE_PATH;
                    }
                }
                if (nextState != adjacent.state) {
                    adjacent.state = nextState;
                    if (!adjacent.id21) {
                        nodes.add(adjacent);
                    }
                }
            }
        }
        ArrayList<Integer> answer = new ArrayList<>();
        for (Node node : scc.nodes) {
            if (node.state == State.NO_PATHS) {
                answer.add(0);
            } else if (node.state == State.ONE_PATH) {
                answer.add(1);
            } else if (node.state == State.MORE_THAN_ONE_PATH) {
                answer.add(2);
            } else {
                answer.add(-1);
            }
        }
        sw.printLine(answer);
    }

    public static void main() {
        int t = sc.nextInt();
        for (int cc = 0; cc < t; cc++) {
            solve();
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

        public String[] id1() {
            fillTemp();
            String[] answer = new String[temp.size()];
            for (int i = 0; i < answer.length; i++) {
                answer[i] = (String) temp.get(i);
            }
            temp.clear();
            return answer;
        }

        public int[] id20() {
            fillTemp();
            int[] answer = new int[temp.size()];
            for (int i = 0; i < answer.length; i++) {
                answer[i] = Integer.parseInt((String) temp.get(i));
            }
            temp.clear();
            return answer;
        }

        public long[] id16() {
            fillTemp();
            long[] answer = new long[temp.size()];
            for (int i = 0; i < answer.length; i++) {
                answer[i] = Long.parseLong((String) temp.get(i));
            }
            temp.clear();
            return answer;
        }

        public double[] id19() {
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
                    return -1;
                }
                if (numChars <= 0)
                    return -1;
            }
            return buf[curChar++];
        }

        public static boolean isWhitespace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public static boolean id4(int c) {
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
                if (!id4(c)) {
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

        public LineScanner id17() {
            String line = nextLine();
            if (line == null) {
                return null;
            } else {
                return new LineScanner(line);
            }
        }

        public LineScanner id5() {
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

        public int id7() {
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

        public int[] id11(int n) {
            int[] res = new int[n];
            for (int i = 0; i < res.length; i++)
                res[i] = nextInt();
            return res;
        }

        public long[] id25(int n) {
            long[] res = new long[n];
            for (int i = 0; i < res.length; i++)
                res[i] = nextLong();
            return res;
        }

        public double[] id22(int n) {
            double[] res = new double[n];
            for (int i = 0; i < res.length; i++)
                res[i] = nextDouble();
            return res;
        }

        public void id2(int[] array) {
            Integer[] vals = new Integer[array.length];
            for (int i = 0; i < array.length; i++)
                vals[i] = array[i];
            Arrays.sort(vals);
            for (int i = 0; i < array.length; i++)
                array[i] = vals[i];
        }

        public void id14(long[] array) {
            Long[] vals = new Long[array.length];
            for (int i = 0; i < array.length; i++)
                vals[i] = array[i];
            Arrays.sort(vals);
            for (int i = 0; i < array.length; i++)
                array[i] = vals[i];
        }

        public void id3(double[] array) {
            Double[] vals = new Double[array.length];
            for (int i = 0; i < array.length; i++)
                vals[i] = array[i];
            Arrays.sort(vals);
            for (int i = 0; i < array.length; i++)
                array[i] = vals[i];
        }

        public String[] id23(int n) {
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

        public int[][] id0(int n, int m) {
            int[][] ans = new int[n][];
            for (int i = 0; i < n; i++)
                ans[i] = id11(m);
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

        public <T> T[] id18(Class<T> clazz, int size) {
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
            if (!id6) {
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
            if (!id6) {
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
            if (!id6) {
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
            if (!id6) {
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
            if (!id6) {
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
            if (!id6) {
                writer.flush();
            }
        }

        public void printSimple(String value) {
            writer.print(value);
            if (!id6) {
                writer.flush();
            }
        }

        public boolean id13(Number... values) {
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
