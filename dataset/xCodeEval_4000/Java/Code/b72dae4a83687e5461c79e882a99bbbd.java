import java.io.*;
import java.math.BigInteger;
import java.util.InputMismatchException;
 

final public class test implements Runnable {
        private static String[] args;
 
        public static void main(String[] args) {
                test.args = args;
                new Thread(null, new test(), "MyRunThread", 1 << 27).start();
        }
 
        

        public void run() {
                long time_beg = -1;
                InputStream inputStream = System.in;
                OutputStream outputStream = System.out;
                if (args.length > 0 && args[0].equals("outside")) {
                        time_beg = System.currentTimeMillis();
                        try {
                                inputStream = new FileInputStream("IO/in.txt");


                        } catch (Exception e) {
                                System.err.println(e);
                                System.exit(1);
                        }
                } else {
                        try {




                        } catch (Exception e) {
                                System.err.println(e);
                                System.exit(1);
                        }
                }
 
                Solver s = new Solver();
                s.in = new InputReader(inputStream);
                s.out = new OutputWriter(outputStream);
                if (args.length > 0 && args[0].equals("outside")) {
                        s.dout = new DebugWriter(s.out);
                }
 
                s.solve();
 
                if (args.length > 0 && args[0].equals("outside")) {
                        s.dout.printFormat("*** Total time: %.3f ***\n", (System.currentTimeMillis() - time_beg) / 1000.0);
                }
 
                s.out.close();
        }
}
 
 
final class Solver {
        InputReader in;
        OutputWriter out;
        DebugWriter dout;
        static int t[][];
        static int sz[];
        static int d[];
        static int inTree[];
        static int G[][];
        static void dfs(int v, int p, int num, int depth)
        {
                inTree[v]=num;
                sz[num]++;
                d[v]=depth;
                for (int i=0; i<G[v].length; ++i)
                {
                        int to=G[v][i];
                        if (to==p)
                                continue;
                        dfs(to,v,num,depth+1);
                }
        }
        static int find(int p, int num)
        {
                int res=0;
                for (int i=p; i>0; i-=(i&(-i)))
                        res+=t[num][i];
                return res;
        }
        static void add(int p, int v, int num)
        {
                for (int i=p; i<t[num].length; i+=(i&(-i)))
                        t[num][i]+=v;
        }
        public void solve() {
 
                int n= in.readInt();
                int q=in.readInt();
                int e[][]=new int [n-1][2];
                int degree[]=new int[n];
                for (int i=0; i<n-1; ++i)
                {
                        int v1=in.readInt();
                        int v2=in.readInt();
                        v1--;
                        v2--;
                        degree[v1]++;
                        degree[v2]++;
                        e[i][0]=v1;
                        e[i][1]=v2;
                }
                G=new int[n][];
                for (int i=0; i<n; ++i)
                        G[i]=new int[degree[i]];
                for (int i=0; i<n-1; ++i)
                {
                        int v1=e[i][0];
                        int v2=e[i][1];
                        G[v1][--degree[v1]]=v2;
                        G[v2][--degree[v2]]=v1;
                }
                t=new int[G[0].length+1][];
                sz=new int[G[0].length];
                d=new int[n];
                inTree=new int[n];
                for (int i=0; i<G[0].length; ++i)
                        dfs(G[0][i],0,i,1);
                for (int i=0; i<G[0].length; ++i)
                        t[i]=new int[sz[i]+1];
                t[t.length-1]=new int[n+10];
                int inRoot=0;
                for (int i=0; i<q; ++i)
                {
                        int ty=in.readInt();
                        if (ty==0)
                        {
                                int v=in.readInt();
                                v--;
                                int val=in.readInt();
                                int dist=in.readInt();
                                if (v==0)
                                {
                                        inRoot+=val;
                                        add(1,val,t.length-1);
                                        add(dist+1,-val,t.length-1);
                                }
                                else
                                {
                                        if (dist>=d[v])
                                        {
                                                int left=dist-d[v];
                                                inRoot+=val;
                                                add(1,val,t.length-1);
                                                add(left+1,-val,t.length-1);
                                                add(left+1,val,inTree[v]);
                                                add(d[v]+dist+1,-val,inTree[v]);
                                        }
                                        else
                                        {
                                                add(d[v]-dist,val,inTree[v]);
                                                add(d[v]+dist+1,-val,inTree[v]);
                                        }
                                }
                        }
                        else
                        {
                                int v=in.readInt();
                                v--;
                                if (v==0)
                                        out.print(inRoot+"\n");
                                else
                                        out.print(find(d[v],inTree[v])+find(d[v],t.length-1)+"\n");
                        }
                }
        }
 
 
 
}
 
 
final class InputReader {
        private boolean finished = false;
 
        private InputStream stream;
        private byte[] buf = new byte[1 << 10];
        private int curChar;
        private int numChars;
 
        public InputReader(InputStream stream) {
                this.stream = stream;
        }
 
        private int read() {
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
 
        public int peek() {
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
                return buf[curChar];
        }
 
        public int readInt() {
                int c = read();
                while (isSpaceChar(c))
                        c = read();
                int sgn = 1;
                if (c == '-') {
                        sgn = -1;
                        c = read();
                }
                int res = 0;
                do {
                        if (c < '0' || c > '9')
                                throw new InputMismatchException();
                        res *= 10;
                        res += c - '0';
                        c = read();
                } while (!isSpaceChar(c));
                return res * sgn;
        }
 
        public long readLong() {
                int c = read();
                while (isSpaceChar(c))
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
                        res *= 10;
                        res += c - '0';
                        c = read();
                } while (!isSpaceChar(c));
                return res * sgn;
        }
 
        public String readString() {
                int c = read();
                while (isSpaceChar(c))
                        c = read();
                StringBuilder res = new StringBuilder();
                do {
                        res.appendCodePoint(c);
                        c = read();
                } while (!isSpaceChar(c));
                return res.toString();
        }
 
        public static boolean isSpaceChar(int c) {
                return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }
 
        private String readLine0() {
                StringBuilder buf = new StringBuilder();
                int c = read();
                while (c != '\n' && c != -1) {
                        if (c != '\r')
                                buf.appendCodePoint(c);
                        c = read();
                }
                return buf.toString();
        }
 
        public String readLine() {
                String s = readLine0();
                while (s.trim().length() == 0)
                        s = readLine0();
                return s;
        }
 
        public String readLine(boolean ignoreEmptyLines) {
                if (ignoreEmptyLines)
                        return readLine();
                else
                        return readLine0();
        }
 
        public BigInteger readBigInteger() {
                try {
                        return new BigInteger(readString());
                } catch (NumberFormatException e) {
                        throw new InputMismatchException();
                }
        }
 
        public char readCharacter() {
                int c = read();
                while (isSpaceChar(c))
                        c = read();
                return (char) c;
        }
 
        public double readDouble() {
                int c = read();
                while (isSpaceChar(c))
                        c = read();
                int sgn = 1;
                if (c == '-') {
                        sgn = -1;
                        c = read();
                }
                double res = 0;
                while (!isSpaceChar(c) && c != '.') {
                        if (c == 'e' || c == 'E')
                                return res * Math.pow(10, readInt());
                        if (c < '0' || c > '9')
                                throw new InputMismatchException();
                        res *= 10;
                        res += c - '0';
                        c = read();
                }
                if (c == '.') {
                        c = read();
                        double m = 1;
                        while (!isSpaceChar(c)) {
                                if (c == 'e' || c == 'E')
                                        return res * Math.pow(10, readInt());
                                if (c < '0' || c > '9')
                                        throw new InputMismatchException();
                                m /= 10;
                                res += (c - '0') * m;
                                c = read();
                        }
                }
                return res * sgn;
        }
 
        public boolean isExhausted() {
                int value;
                while (isSpaceChar(value = peek()) && value != -1)
                        read();
                return value == -1;
        }
}
 
final class OutputWriter {
        private final PrintWriter writer;
 
        public OutputWriter(OutputStream outputStream) {
                writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream), 1 << 10));
        }
 
        public OutputWriter(Writer writer) {
                this.writer = new PrintWriter(writer);
        }
 
 
        public void print(Object... objects) {
                for (int i = 0; i < objects.length; i++) {
                        if (i != 0)
                                writer.print(' ');
                        writer.print(objects[i]);
                }
        }
 
        public void printLine(Object... objects) {
                print(objects);
                writer.println();
        }
 
        public void printFormat(String format, Object... objects) {
                writer.printf(format, objects);
        }
 
 
        public void print(char[] objects) {
                writer.print(objects);
        }
 
        public void printLine(char[] objects) {
                writer.println(objects);
        }
 
        public void printLine(char[][] objects) {
                for (int i = 0; i < objects.length; ++i)
                        printLine(objects[i]);
        }
 
 
        public void print(int[] objects) {
                for (int i = 0; i < objects.length; i++) {
                        if (i != 0)
                                writer.print(' ');
                        writer.print(objects[i]);
                }
        }
 
        public void printLine(int[] objects) {
                print(objects);
                writer.println();
        }
 
        public void printLine(int[][] objects) {
                for (int i = 0; i < objects.length; ++i)
                        printLine(objects[i]);
        }
 
 
        public void print(short[] objects) {
                for (int i = 0; i < objects.length; i++) {
                        if (i != 0)
                                writer.print(' ');
                        writer.print(objects[i]);
                }
        }
 
        public void printLine(short[] objects) {
                print(objects);
                writer.println();
        }
 
        public void printLine(short[][] objects) {
                for (int i = 0; i < objects.length; ++i)
                        printLine(objects[i]);
        }
 
 
        public void print(long[] objects) {
                for (int i = 0; i < objects.length; i++) {
                        if (i != 0)
                                writer.print(' ');
                        writer.print(objects[i]);
                }
        }
 
        public void printLine(long[] objects) {
                print(objects);
                writer.println();
        }
 
        public void printLine(long[][] objects) {
                for (int i = 0; i < objects.length; ++i)
                        printLine(objects[i]);
        }
 
 
        public void print(double[] objects) {
                for (int i = 0; i < objects.length; i++) {
                        if (i != 0)
                                writer.print(' ');
                        writer.print(objects[i]);
                }
        }
 
        public void printLine(double[] objects) {
                print(objects);
                writer.println();
        }
 
        public void printLine(double[][] objects) {
                for (int i = 0; i < objects.length; ++i)
                        printLine(objects[i]);
        }
 
 
        public void print(byte[] objects) {
                for (int i = 0; i < objects.length; i++) {
                        if (i != 0)
                                writer.print(' ');
                        writer.print(objects[i]);
                }
        }
 
        public void printLine(byte[] objects) {
                print(objects);
                writer.println();
        }
 
        public void printLine(byte[][] objects) {
                for (int i = 0; i < objects.length; ++i)
                        printLine(objects[i]);
        }
 
 
        public void print(boolean[] objects) {
                for (int i = 0; i < objects.length; i++) {
                        if (i != 0)
                                writer.print(' ');
                        writer.print(objects[i]);
                }
        }
 
        public void printLine(boolean[] objects) {
                print(objects);
                writer.println();
        }
 
        public void printLine(boolean[][] objects) {
                for (int i = 0; i < objects.length; ++i)
                        printLine(objects[i]);
        }
 
 
        public void close() {
                writer.close();
        }
 
        public void flush() {
                writer.flush();
        }
}
 
final class DebugWriter {
        private final OutputWriter writer;
 
        public DebugWriter(OutputWriter writer) {
                this.writer = writer;
        }
 
        private void printDebugMessage() {
                writer.print("DEBUG:\t");
        }
 
 
        public void printLine(Object... objects) {
                flush();
                printDebugMessage();
                writer.printLine(objects);
                flush();
        }
 
        public void printFormat(String format, Object... objects) {
                flush();
                printDebugMessage();
                writer.printFormat(format, objects);
                flush();
        }
 
 
        public void printLine(char[] objects) {
                flush();
                printDebugMessage();
                writer.printLine(objects);
                flush();
        }
 
        public void printLine(char[][] objects) {
                flush();
                for (int i = 0; i < objects.length; ++i)
                        printLine(objects[i]);
                flush();
        }
 
 
        public void printLine(double[] objects) {
                flush();
                printDebugMessage();
                writer.printLine(objects);
                flush();
        }
 
        public void printLine(double[][] objects) {
                flush();
                for (int i = 0; i < objects.length; ++i)
                        printLine(objects[i]);
                flush();
        }
 
 
        public void printLine(int[] objects) {
                flush();
                printDebugMessage();
                writer.printLine(objects);
                flush();
        }
 
        public void printLine(int[][] objects) {
                flush();
                for (int i = 0; i < objects.length; ++i)
                        printLine(objects[i]);
                flush();
        }
 
 
        public void printLine(short[] objects) {
                flush();
                printDebugMessage();
                writer.printLine(objects);
                flush();
        }
 
        public void printLine(short[][] objects) {
                flush();
                for (int i = 0; i < objects.length; ++i)
                        printLine(objects[i]);
                flush();
        }
 
 
        public void printLine(long[] objects) {
                flush();
                printDebugMessage();
                writer.printLine(objects);
                flush();
        }
 
        public void printLine(long[][] objects) {
                flush();
                for (int i = 0; i < objects.length; ++i)
                        printLine(objects[i]);
                flush();
        }
 
 
        public void printLine(byte[] objects) {
                flush();
                printDebugMessage();
                writer.printLine(objects);
                flush();
        }
 
        public void printLine(byte[][] objects) {
                flush();
                for (int i = 0; i < objects.length; ++i)
                        printLine(objects[i]);
                flush();
        }
 
 
        public void printLine(boolean[] objects) {
                flush();
                printDebugMessage();
                writer.printLine(objects);
                flush();
        }
 
        public void printLine(boolean[][] objects) {
                flush();
                for (int i = 0; i < objects.length; ++i)
                        printLine(objects[i]);
                flush();
        }
 
 
        public void flush() {
                writer.flush();
        }
}
 
 
final class Pair<F, S> {
        public F first;
        public S second;
 
        public Pair(F first, S second) {
                this.first = first;
                this.second = second;
        }
 
        @Override
        public int hashCode() {
                int hFirst = first != null ? first.hashCode() : 0;
                int hSecond = second != null ? second.hashCode() : 0;
                return 31 * hFirst + hSecond;
        }
 
        @Override
        public boolean equals(Object o) {
                if (this == o) return true;
                if (o == null || getClass() != o.getClass()) return false;
 
                Pair pair = (Pair) o;
 
                return (first != null ? first.equals(pair.first) : pair.first == null) &&
                                (second != null ? second.equals(pair.second) : pair.second == null);
        }
 
        @Override
        protected Object clone() throws CloneNotSupportedException {
                return new Pair<F, S>(first, second);
        }
 
        @Override
        public String toString() {
                return "(" + first + ", " + second + ")";
        }
}