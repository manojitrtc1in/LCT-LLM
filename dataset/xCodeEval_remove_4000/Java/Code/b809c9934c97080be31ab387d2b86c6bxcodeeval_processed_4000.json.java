import java.io.*;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Set;

public class id5{
    static class InputReader {
        private static final int id0 = 1 << 16; 

        private static final InputStream DEFAULT_STREAM = System.in;private static final int id4 = 21;private int c;private byte[] buf;private int bufferSize, bufIndex, id7;private InputStream stream;private static final byte EOF = -1;private static final byte NEW_LINE = 10;private static final byte id8 = 13;private static final byte SPACE = 32;private static final byte DASH = 45;private static final byte DOT = 46;private char[] charBuffer;private static byte[] bytes = new byte[58];private static int[] ints = new int[58];private static char[] chars = new char[128];static { char ch = ' ';int value = 0;byte _byte = 0;for (int i = 48; i < 58; i++) bytes[i] = _byte++;for (int i = 48; i < 58; i++) ints[i] = value++;for (int i = 32; i < 128; i++) chars[i] = ch++; }private static final double[][] doubles = {{0.0d, 0.00d, 0.000d, 0.0000d, 0.00000d, 0.000000d, 0.0000000d, 0.00000000d, 0.000000000d, 0.0000000000d, 0.00000000000d, 0.000000000000d, 0.0000000000000d, 0.00000000000000d, 0.000000000000000d, 0.0000000000000000d, 0.00000000000000000d, 0.000000000000000000d, 0.0000000000000000000d, 0.00000000000000000000d, 0.000000000000000000000d}, {0.1d, 0.01d, 0.001d, 0.0001d, 0.00001d, 0.000001d, 0.0000001d, 0.00000001d, 0.000000001d, 0.0000000001d, 0.00000000001d, 0.000000000001d, 0.0000000000001d, 0.00000000000001d, 0.000000000000001d, 0.0000000000000001d, 0.00000000000000001d, 0.000000000000000001d, 0.0000000000000000001d, 0.00000000000000000001d, 0.000000000000000000001d}, {0.2d, 0.02d, 0.002d, 0.0002d, 0.00002d, 0.000002d, 0.0000002d, 0.00000002d, 0.000000002d, 0.0000000002d, 0.00000000002d, 0.000000000002d, 0.0000000000002d, 0.00000000000002d, 0.000000000000002d, 0.0000000000000002d, 0.00000000000000002d, 0.000000000000000002d, 0.0000000000000000002d, 0.00000000000000000002d, 0.000000000000000000002d}, {0.3d, 0.03d, 0.003d, 0.0003d, 0.00003d, 0.000003d, 0.0000003d, 0.00000003d, 0.000000003d, 0.0000000003d, 0.00000000003d, 0.000000000003d, 0.0000000000003d, 0.00000000000003d, 0.000000000000003d, 0.0000000000000003d, 0.00000000000000003d, 0.000000000000000003d, 0.0000000000000000003d, 0.00000000000000000003d, 0.000000000000000000003d}, {0.4d, 0.04d, 0.004d, 0.0004d, 0.00004d, 0.000004d, 0.0000004d, 0.00000004d, 0.000000004d, 0.0000000004d, 0.00000000004d, 0.000000000004d, 0.0000000000004d, 0.00000000000004d, 0.000000000000004d, 0.0000000000000004d, 0.00000000000000004d, 0.000000000000000004d, 0.0000000000000000004d, 0.00000000000000000004d, 0.000000000000000000004d}, {0.5d, 0.05d, 0.005d, 0.0005d, 0.00005d, 0.000005d, 0.0000005d, 0.00000005d, 0.000000005d, 0.0000000005d, 0.00000000005d, 0.000000000005d, 0.0000000000005d, 0.00000000000005d, 0.000000000000005d, 0.0000000000000005d, 0.00000000000000005d, 0.000000000000000005d, 0.0000000000000000005d, 0.00000000000000000005d, 0.000000000000000000005d}, {0.6d, 0.06d, 0.006d, 0.0006d, 0.00006d, 0.000006d, 0.0000006d, 0.00000006d, 0.000000006d, 0.0000000006d, 0.00000000006d, 0.000000000006d, 0.0000000000006d, 0.00000000000006d, 0.000000000000006d, 0.0000000000000006d, 0.00000000000000006d, 0.000000000000000006d, 0.0000000000000000006d, 0.00000000000000000006d, 0.000000000000000000006d}, {0.7d, 0.07d, 0.007d, 0.0007d, 0.00007d, 0.000007d, 0.0000007d, 0.00000007d, 0.000000007d, 0.0000000007d, 0.00000000007d, 0.000000000007d, 0.0000000000007d, 0.00000000000007d, 0.000000000000007d, 0.0000000000000007d, 0.00000000000000007d, 0.000000000000000007d, 0.0000000000000000007d, 0.00000000000000000007d, 0.000000000000000000007d}, {0.8d, 0.08d, 0.008d, 0.0008d, 0.00008d, 0.000008d, 0.0000008d, 0.00000008d, 0.000000008d, 0.0000000008d, 0.00000000008d, 0.000000000008d, 0.0000000000008d, 0.00000000000008d, 0.000000000000008d, 0.0000000000000008d, 0.00000000000000008d, 0.000000000000000008d, 0.0000000000000000008d, 0.00000000000000000008d, 0.000000000000000000008d}, {0.9d, 0.09d, 0.009d, 0.0009d, 0.00009d, 0.000009d, 0.0000009d, 0.00000009d, 0.000000009d, 0.0000000009d, 0.00000000009d, 0.000000000009d, 0.0000000000009d, 0.00000000000009d, 0.000000000000009d, 0.0000000000000009d, 0.00000000000000009d, 0.000000000000000009d, 0.0000000000000000009d, 0.00000000000000000009d, 0.000000000000000000009d}};
        public InputReader() { this(DEFAULT_STREAM, id0); }
        public InputReader(int bufferSize) { this(DEFAULT_STREAM, bufferSize); }
        public InputReader(InputStream stream) { this(stream, id0); }
        public InputReader(InputStream stream, int bufferSize) { if (stream == null || bufferSize <= 0) throw new IllegalArgumentException();buf = new byte[bufferSize];charBuffer = new char[128];this.bufferSize = bufferSize;this.stream = stream; }
        private byte read() throws IOException { if (id7 == EOF) throw new IOException();if (bufIndex >= id7) { bufIndex = 0;id7 = stream.read(buf);if (id7 == EOF) return EOF; }return buf[bufIndex++]; }
        private int id6(int token) throws IOException { if (id7 == EOF) return EOF;
            do { while (bufIndex < id7) { if (buf[bufIndex] > token) return 0;bufIndex++; }
                id7 = stream.read(buf);if (id7 == EOF) return EOF;bufIndex = 0; } while (true); }
        public byte nextByte() throws IOException {return (byte) nextInt(); }
        public int nextInt() throws IOException { if (id6(DASH - 1) == EOF) throw new IOException();int sgn = 1, res = 0;c = buf[bufIndex];if (c == DASH) { sgn = -1;bufIndex++; } do { while (bufIndex < id7) { if (buf[bufIndex] > SPACE) { res = (res << 3) + (res << 1);res += ints[buf[bufIndex++]]; } else { bufIndex++;return res * sgn; } }id7 = stream.read(buf);if (id7 == EOF) return res * sgn;bufIndex = 0; } while (true); }
        public long nextLong() throws IOException { if (id6(DASH - 1) == EOF) throw new IOException();int sgn = 1;long res = 0L;c = buf[bufIndex];if (c == DASH) { sgn = -1;bufIndex++; } do { while (bufIndex < id7) { if (buf[bufIndex] > SPACE) { res = (res << 3) + (res << 1);res += ints[buf[bufIndex++]]; } else { bufIndex++;return res * sgn; } }id7 = stream.read(buf);if (id7 == EOF) return res * sgn;bufIndex = 0; } while (true); }
        private void id1() { char[] newBuffer = new char[charBuffer.length << 1];for (int i = 0; i < charBuffer.length; i++) newBuffer[i] = charBuffer[i];charBuffer = newBuffer; }
        public String nextLine() throws IOException { try { c = read(); } catch (IOException e) { return null; }if (c == NEW_LINE) return "";if (c == EOF) return null;int i = 0;charBuffer[i++] = (char) c;do { while (bufIndex < id7) { if (buf[bufIndex] != NEW_LINE && buf[bufIndex] != id8) { if (i == charBuffer.length) id1();charBuffer[i++] = (char) buf[bufIndex++]; } else { if(buf[bufIndex] == id8) bufIndex++;bufIndex++;return new String(charBuffer, 0, i); } }id7 = stream.read(buf);if (id7 == EOF) return new String(charBuffer, 0, i);bufIndex = 0; } while (true); }
        public String nextString() throws IOException { if (id7 == EOF) return null;if (id6(SPACE) == EOF) return null;for (int i = 0; ; ) { while (bufIndex < id7) { if (buf[bufIndex] > SPACE) { if (i == charBuffer.length) id1();charBuffer[i++] = (char) buf[bufIndex++]; } else {bufIndex++;return new String(charBuffer, 0, i); } }id7 = stream.read(buf);if (id7 == EOF) return new String(charBuffer, 0, i);bufIndex = 0; } }
        public double id3() throws IOException {c = read();int sgn = 1;while (c <= SPACE) c = read();if (c == DASH) { sgn = -1;c = read(); }double res = 0.0;while (c > DOT) { res *= 10.0;res += ints[c];c = read(); }if (c == DOT) { int i = 0;c = read();while (c > SPACE && i < id4) { res += doubles[ints[c]][i++];c = read(); } }return res * sgn; }
        public void close() throws IOException {stream.close(); }
    }

    

    static InputReader sc = new InputReader();
    static OutputStream outputStream = System.out;
    static PrintWriter w = new PrintWriter(outputStream);
    


    private static void id2()
            throws IOException {if (System.getProperty("ONLINE_JUDGE") == null) { try { w = new PrintWriter("output.txt");sc = new InputReader(new FileInputStream("input.txt")); } catch (Exception e) { throw new IOException(); }} }

    public static void main(String[] args)
            throws IOException {

        id2();

        int t = sc.nextInt();
        while(t-- > 0) {
            solve();
        }

        w.close();

    }

    static void solve() throws IOException {
        int n = sc.nextInt();
        int k = sc.nextInt();
        HashMap<Integer, pair> hm = new HashMap<>();
        int[] arr2 = new int[n];

        for(int i = 0; i < n; i++) {
            int curr = sc.nextInt();
            if(hm.containsKey(curr)) {
                hm.replace(curr, new pair(hm.get(curr).val+1, -1));
            } else hm.put(curr, new pair(1, -1));
            arr2[i] = curr;
        }

        int count = 0;
        int buffCount = 0;


        List<Integer> lastKeys = new ArrayList<>();
        for(int key: hm.keySet()) {
            if(hm.get(key).val >= k) {
                hm.get(key).strt = 1;
                count++;
                continue;
            }

            hm.get(key).strt = buffCount+1;
            lastKeys.add(key);
            buffCount += hm.get(key).val;
            if(buffCount >= k) {
                lastKeys.clear();
                lastKeys.add(key);
                count++;
                buffCount -= k;
            }
        }

        if(buffCount != 0) {
            for(int i = 0; i < lastKeys.size(); i++) {
                int curr = lastKeys.get(i);
                if(i == 0 && hm.get(curr).val + hm.get(curr).strt > k) {
                    hm.get(curr).val += k;
                } else hm.get(curr).strt = -1;
            }
        }






        for(int i = 0; i < n; i++) {
            int curr = arr2[i];

            if(hm.get(curr).strt > k && hm.get(curr).val > k) {
                w.print("0 ");
                continue;
            }

            if(hm.get(curr).strt == -1) {
                w.print("0 ");
                continue;
            }

            if(hm.get(curr).strt > k) {
                hm.get(curr).strt = 1;
            }

            

            w.print(hm.get(curr).strt + " ");


            hm.get(curr).strt++;
        }

        w.println();
    }

    static class pair {
        int val;
        int strt;
        pair (int val, int strt){
            this.val = val;
            this.strt = strt;
        }
    }
}