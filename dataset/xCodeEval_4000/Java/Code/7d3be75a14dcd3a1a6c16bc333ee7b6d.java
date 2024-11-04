import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.FileNotFoundException;
import java.io.File;
import java.util.StringTokenizer;
import java.io.Writer;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.InputStream;


public class Main {

  public static void main(String[] args) {
    InputStream inputStream = System.in;
    OutputStream outputStream = System.out;
    InputReader in = new InputReader(inputStream);
    OutputWriter out = new OutputWriter(outputStream);
    TaskC solver = new TaskC();
    solver.solve(1, in, out);
    out.close();
  }

  static class TaskC extends ChelperSolution {

    String[] a = new String[101];

    {
      a[1] = "1\no\n";
      a[2] = "-1\n";
      a[3] = "2\no.\noo\n";
      a[4] = "2\noo\noo\n";
      a[5] = "3\no..\no..\nooo\n";
      a[6] = "3\no..\noo.\nooo\n";
      a[7] = "4\no...\no...\no...\noooo\n";
      a[8] = "3\noo.\nooo\nooo\n";
      a[9] = "3\nooo\nooo\nooo\n";
      a[10] = "4\no...\noo..\nooo.\noooo\n";
      a[11] = "4\no...\nooo.\nooo.\noooo\n";
      a[12] = "4\noo..\noo..\noooo\noooo\n";
      a[13] = "4\noo..\nooo.\noooo\noooo\n";
      a[14] = "5\no....\noo...\noo...\noooo.\nooooo\n";
      a[15] = "4\nooo.\noooo\noooo\noooo\n";
      a[16] = "4\noooo\noooo\noooo\noooo\n";
      a[17] = "5\no....\nooo..\noooo.\noooo.\nooooo\n";
      a[18] = "5\no....\noooo.\noooo.\noooo.\nooooo\n";
      a[19] = "5\noo...\nooo..\noooo.\nooooo\nooooo\n";
      a[20] = "5\noo...\noooo.\noooo.\nooooo\nooooo\n";
      a[21] = "5\nooo..\nooo..\nooooo\nooooo\nooooo\n";
      a[22] = "5\nooo..\noooo.\nooooo\nooooo\nooooo\n";
      a[23] = "6\no.....\nooo...\nooo...\nooooo.\nooooo.\noooooo\n";
      a[24] = "5\noooo.\nooooo\nooooo\nooooo\nooooo\n";
      a[25] = "5\nooooo\nooooo\nooooo\nooooo\nooooo\n";
      a[26] = "6\no.....\noooo..\nooooo.\nooooo.\nooooo.\noooooo\n";
      a[27] = "6\no.....\nooooo.\nooooo.\nooooo.\nooooo.\noooooo\n";
      a[28] = "6\noo....\noooo..\nooooo.\nooooo.\noooooo\noooooo\n";
      a[29] = "6\noo....\nooooo.\nooooo.\nooooo.\noooooo\noooooo\n";
      a[30] = "6\nooo...\noooo..\nooooo.\noooooo\noooooo\noooooo\n";
      a[31] = "6\nooo...\nooooo.\nooooo.\noooooo\noooooo\noooooo\n";
      a[32] = "6\noooo..\noooo..\noooooo\noooooo\noooooo\noooooo\n";
      a[33] = "6\noooo..\nooooo.\noooooo\noooooo\noooooo\noooooo\n";
      a[34] = "7\no......\noooo...\noooo...\noooooo.\noooooo.\noooooo.\nooooooo\n";
      a[35] = "6\nooooo.\noooooo\noooooo\noooooo\noooooo\noooooo\n";
      a[36] = "6\noooooo\noooooo\noooooo\noooooo\noooooo\noooooo\n";
      a[37] = "7\no......\nooooo..\noooooo.\noooooo.\noooooo.\noooooo.\nooooooo\n";
      a[38] = "7\no......\noooooo.\noooooo.\noooooo.\noooooo.\noooooo.\nooooooo\n";
      a[39] = "7\noo.....\nooooo..\noooooo.\noooooo.\noooooo.\nooooooo\nooooooo\n";
      a[40] = "7\noo.....\noooooo.\noooooo.\noooooo.\noooooo.\nooooooo\nooooooo\n";
      a[41] = "7\nooo....\nooooo..\noooooo.\noooooo.\nooooooo\nooooooo\nooooooo\n";
      a[42] = "7\nooo....\noooooo.\noooooo.\noooooo.\nooooooo\nooooooo\nooooooo\n";
      a[43] = "7\noooo...\nooooo..\noooooo.\nooooooo\nooooooo\nooooooo\nooooooo\n";
      a[44] = "7\noooo...\noooooo.\noooooo.\nooooooo\nooooooo\nooooooo\nooooooo\n";
      a[45] = "7\nooooo..\nooooo..\nooooooo\nooooooo\nooooooo\nooooooo\nooooooo\n";
      a[46] = "7\nooooo..\noooooo.\nooooooo\nooooooo\nooooooo\nooooooo\nooooooo\n";
      a[47] = "8\no.......\nooooo...\nooooo...\nooooooo.\nooooooo.\nooooooo.\nooooooo.\noooooooo\n";
      a[48] = "7\noooooo.\nooooooo\nooooooo\nooooooo\nooooooo\nooooooo\nooooooo\n";
      a[49] = "7\nooooooo\nooooooo\nooooooo\nooooooo\nooooooo\nooooooo\nooooooo\n";
      a[50] = "8\no.......\noooooo..\nooooooo.\nooooooo.\nooooooo.\nooooooo.\nooooooo.\noooooooo\n";
      a[51] = "8\no.......\nooooooo.\nooooooo.\nooooooo.\nooooooo.\nooooooo.\nooooooo.\noooooooo\n";
      a[52] = "8\noo......\noooooo..\nooooooo.\nooooooo.\nooooooo.\nooooooo.\noooooooo\noooooooo\n";
      a[53] = "8\noo......\nooooooo.\nooooooo.\nooooooo.\nooooooo.\nooooooo.\noooooooo\noooooooo\n";
      a[54] = "8\nooo.....\noooooo..\nooooooo.\nooooooo.\nooooooo.\noooooooo\noooooooo\noooooooo\n";
      a[55] = "8\nooo.....\nooooooo.\nooooooo.\nooooooo.\nooooooo.\noooooooo\noooooooo\noooooooo\n";
      a[56] = "8\noooo....\noooooo..\nooooooo.\nooooooo.\noooooooo\noooooooo\noooooooo\noooooooo\n";
      a[57] = "8\noooo....\nooooooo.\nooooooo.\nooooooo.\noooooooo\noooooooo\noooooooo\noooooooo\n";
      a[58] = "8\nooooo...\noooooo..\nooooooo.\noooooooo\noooooooo\noooooooo\noooooooo\noooooooo\n";
      a[59] = "8\nooooo...\nooooooo.\nooooooo.\noooooooo\noooooooo\noooooooo\noooooooo\noooooooo\n";
      a[60] = "8\noooooo..\noooooo..\noooooooo\noooooooo\noooooooo\noooooooo\noooooooo\noooooooo\n";
      a[61] = "8\noooooo..\nooooooo.\noooooooo\noooooooo\noooooooo\noooooooo\noooooooo\noooooooo\n";
      a[62] = "9\no........\noooooo...\noooooo...\noooooooo.\noooooooo.\noooooooo.\noooooooo.\noooooooo.\nooooooooo\n";
      a[63] = "8\nooooooo.\noooooooo\noooooooo\noooooooo\noooooooo\noooooooo\noooooooo\noooooooo\n";
      a[64] = "8\noooooooo\noooooooo\noooooooo\noooooooo\noooooooo\noooooooo\noooooooo\noooooooo\n";
      a[65] = "9\no........\nooooooo..\noooooooo.\noooooooo.\noooooooo.\noooooooo.\noooooooo.\noooooooo.\nooooooooo\n";
      a[66] = "9\no........\noooooooo.\noooooooo.\noooooooo.\noooooooo.\noooooooo.\noooooooo.\noooooooo.\nooooooooo\n";
      a[67] = "9\noo.......\nooooooo..\noooooooo.\noooooooo.\noooooooo.\noooooooo.\noooooooo.\nooooooooo\nooooooooo\n";
      a[68] = "9\noo.......\noooooooo.\noooooooo.\noooooooo.\noooooooo.\noooooooo.\noooooooo.\nooooooooo\nooooooooo\n";
      a[69] = "9\nooo......\nooooooo..\noooooooo.\noooooooo.\noooooooo.\noooooooo.\nooooooooo\nooooooooo\nooooooooo\n";
      a[70] = "9\nooo......\noooooooo.\noooooooo.\noooooooo.\noooooooo.\noooooooo.\nooooooooo\nooooooooo\nooooooooo\n";
      a[71] = "9\noooo.....\nooooooo..\noooooooo.\noooooooo.\noooooooo.\nooooooooo\nooooooooo\nooooooooo\nooooooooo\n";
      a[72] = "9\noooo.....\noooooooo.\noooooooo.\noooooooo.\noooooooo.\nooooooooo\nooooooooo\nooooooooo\nooooooooo\n";
      a[73] = "9\nooooo....\nooooooo..\noooooooo.\noooooooo.\nooooooooo\nooooooooo\nooooooooo\nooooooooo\nooooooooo\n";
      a[74] = "9\nooooo....\noooooooo.\noooooooo.\noooooooo.\nooooooooo\nooooooooo\nooooooooo\nooooooooo\nooooooooo\n";
      a[75] = "9\noooooo...\nooooooo..\noooooooo.\nooooooooo\nooooooooo\nooooooooo\nooooooooo\nooooooooo\nooooooooo\n";
      a[76] = "9\noooooo...\noooooooo.\noooooooo.\nooooooooo\nooooooooo\nooooooooo\nooooooooo\nooooooooo\nooooooooo\n";
      a[77] = "9\nooooooo..\nooooooo..\nooooooooo\nooooooooo\nooooooooo\nooooooooo\nooooooooo\nooooooooo\nooooooooo\n";
      a[78] = "9\nooooooo..\noooooooo.\nooooooooo\nooooooooo\nooooooooo\nooooooooo\nooooooooo\nooooooooo\nooooooooo\n";
      a[79] = "10\no.........\nooooooo...\nooooooo...\nooooooooo.\nooooooooo.\nooooooooo.\nooooooooo.\nooooooooo.\nooooooooo.\noooooooooo\n";
      a[80] = "9\noooooooo.\nooooooooo\nooooooooo\nooooooooo\nooooooooo\nooooooooo\nooooooooo\nooooooooo\nooooooooo\n";
      a[81] = "9\nooooooooo\nooooooooo\nooooooooo\nooooooooo\nooooooooo\nooooooooo\nooooooooo\nooooooooo\nooooooooo\n";
      a[82] = "10\no.........\noooooooo..\nooooooooo.\nooooooooo.\nooooooooo.\nooooooooo.\nooooooooo.\nooooooooo.\nooooooooo.\noooooooooo\n";
      a[83] = "10\no.........\nooooooooo.\nooooooooo.\nooooooooo.\nooooooooo.\nooooooooo.\nooooooooo.\nooooooooo.\nooooooooo.\noooooooooo\n";
      a[84] = "10\noo........\noooooooo..\nooooooooo.\nooooooooo.\nooooooooo.\nooooooooo.\nooooooooo.\nooooooooo.\noooooooooo\noooooooooo\n";
      a[85] = "10\noo........\nooooooooo.\nooooooooo.\nooooooooo.\nooooooooo.\nooooooooo.\nooooooooo.\nooooooooo.\noooooooooo\noooooooooo\n";
      a[86] = "10\nooo.......\noooooooo..\nooooooooo.\nooooooooo.\nooooooooo.\nooooooooo.\nooooooooo.\noooooooooo\noooooooooo\noooooooooo\n";
      a[87] = "10\nooo.......\nooooooooo.\nooooooooo.\nooooooooo.\nooooooooo.\nooooooooo.\nooooooooo.\noooooooooo\noooooooooo\noooooooooo\n";
      a[88] = "10\noooo......\noooooooo..\nooooooooo.\nooooooooo.\nooooooooo.\nooooooooo.\noooooooooo\noooooooooo\noooooooooo\noooooooooo\n";
      a[89] = "10\noooo......\nooooooooo.\nooooooooo.\nooooooooo.\nooooooooo.\nooooooooo.\noooooooooo\noooooooooo\noooooooooo\noooooooooo\n";
      a[90] = "10\nooooo.....\noooooooo..\nooooooooo.\nooooooooo.\nooooooooo.\noooooooooo\noooooooooo\noooooooooo\noooooooooo\noooooooooo\n";
      a[91] = "10\nooooo.....\nooooooooo.\nooooooooo.\nooooooooo.\nooooooooo.\noooooooooo\noooooooooo\noooooooooo\noooooooooo\noooooooooo\n";
      a[92] = "10\noooooo....\noooooooo..\nooooooooo.\nooooooooo.\noooooooooo\noooooooooo\noooooooooo\noooooooooo\noooooooooo\noooooooooo\n";
      a[93] = "10\noooooo....\nooooooooo.\nooooooooo.\nooooooooo.\noooooooooo\noooooooooo\noooooooooo\noooooooooo\noooooooooo\noooooooooo\n";
      a[94] = "10\nooooooo...\noooooooo..\nooooooooo.\noooooooooo\noooooooooo\noooooooooo\noooooooooo\noooooooooo\noooooooooo\noooooooooo\n";
      a[95] = "10\nooooooo...\nooooooooo.\nooooooooo.\noooooooooo\noooooooooo\noooooooooo\noooooooooo\noooooooooo\noooooooooo\noooooooooo\n";
      a[96] = "10\noooooooo..\noooooooo..\noooooooooo\noooooooooo\noooooooooo\noooooooooo\noooooooooo\noooooooooo\noooooooooo\noooooooooo\n";
      a[97] = "10\noooooooo..\nooooooooo.\noooooooooo\noooooooooo\noooooooooo\noooooooooo\noooooooooo\noooooooooo\noooooooooo\noooooooooo\n";
      a[98] = "11\no..........\noooooooo...\noooooooo...\noooooooooo.\noooooooooo.\noooooooooo.\noooooooooo.\noooooooooo.\noooooooooo.\noooooooooo.\nooooooooooo\n";
      a[99] = "10\nooooooooo.\noooooooooo\noooooooooo\noooooooooo\noooooooooo\noooooooooo\noooooooooo\noooooooooo\noooooooooo\noooooooooo\n";
      a[100] = "10\noooooooooo\noooooooooo\noooooooooo\noooooooooo\noooooooooo\noooooooooo\noooooooooo\noooooooooo\noooooooooo\noooooooooo\n";
    }

    public void solve(int testNumber, InputReader in, OutputWriter out) {
      super.solve(testNumber, in, out);
    }

    public void solve(int testNumber) {
      out.println(a[in.nextInt()]);
    }

  }

  static class InputReader {

    private BufferedReader br;
    private StringTokenizer in;

    public InputReader(String fileName) {
      try {
        br = new BufferedReader(new FileReader(fileName));
      } catch (IOException e) {
        throw new RuntimeException(e);
      }
    }

    public InputReader(InputStream inputStream) {
      br = new BufferedReader(new InputStreamReader(inputStream));
    }

    private boolean hasMoreTokens() {
      while (in == null || !in.hasMoreTokens()) {
        String s = nextLine();
        if (s == null) {
          return false;
        }
        in = new StringTokenizer(s);
      }
      return true;
    }

    public String nextString() {
      return hasMoreTokens() ? in.nextToken() : null;
    }

    public String nextLine() {
      try {
        in = null;
        return br.readLine();
      } catch (Exception e) {
        e.printStackTrace();
        return null;
      }
    }

    public int nextInt() {
      return Integer.parseInt(nextString());
    }

  }

  static class OutputWriter extends PrintWriter {

    public static OutputWriter toFile(String fileName) {
      try {
        return new OutputWriter(fileName);
      } catch (FileNotFoundException e) {
        throw new RuntimeException(e);
      }
    }

    public void close() {
      super.close();
    }

    public OutputWriter(String fileName) throws FileNotFoundException {
      super(fileName);
    }

    public OutputWriter(OutputStream outputStream) {
      super(outputStream, true);
    }

    public OutputWriter(Writer writer) {
      super(writer, true);
    }

  }

  static abstract class ChelperSolution implements ChelperCallable {

    public static final String LOCAL_FILE = "chelper.properties";
    public static final String SAVE_RESULT_FILE = "last_test_output.txt";
    protected final boolean local = new File(LOCAL_FILE).exists();
    protected boolean firstTest = true;
    protected InputReader in;
    protected OutputWriter out;
    protected OutputWriter debug;
    protected OutputWriter fileOut;
    protected boolean saveTestResult = true;
    protected boolean gcj = false;

    protected void init() {
      if (local) {
        debug = new OutputWriter(System.err);
        if (saveTestResult) {
          fileOut = OutputWriter.toFile(SAVE_RESULT_FILE);
        }
      } else {
        debug = new OutputWriter(new NullOutputStream());
      }
    }

    public void solve(int testNumber, InputReader in, OutputWriter out) {
      if (firstTest) {
        init();
        precalc();
        firstTest = false;
      }

      this.in = in;
      if (local && saveTestResult) {
        this.out = new SplittingOutputWriter(out, fileOut);
      } else {
        this.out = out;
      }

      preSolve(testNumber);
      solve(testNumber);
      postSolve(testNumber);
    }

    protected void precalc() {

    }

    protected void preSolve(int testNumber) {
      if (gcj) {
        out.printf("Case #%d: ", testNumber);
      }
    }

    public abstract void solve(int testNumber);

    protected void postSolve(int testNumber) {
      out.flush();
      debug.flush();
    }

  }

  static class SplittingOutputWriter extends OutputWriter {

    private final OutputWriter[] outputWriters;

    public SplittingOutputWriter(OutputWriter... outputWriters) {
      super(new OutputStream() {

        public void write(int b) throws IOException {
          for (OutputWriter outputWriter : outputWriters) {
            outputWriter.write(b);
          }
        }
      });

      this.outputWriters = outputWriters;
    }

    public void flush() {
      for (OutputWriter outputWriter : outputWriters) {
        outputWriter.flush();
      }
    }

    public void close() {
      for (OutputWriter outputWriter : outputWriters) {
        outputWriter.close();
      }
    }

  }

  static interface ChelperCallable {

  }

  static class NullOutputStream extends OutputStream {

    public void write(int b) throws IOException {
      

    }

  }
}

