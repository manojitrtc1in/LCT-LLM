import java.io.IOException;
import java.io.InputStream;

public class Main {
	public static void main(String[] args) throws IOException {
		InputReader scan = new InputReader();
		String x;
		int t=scan.nextInt();
		for(int i=0; i<t; i++)
{
		x=scan.nextString();
		int n=x.length();
		if(n>10)
		{
			System.out.print(x.charAt(0));
			System.out.print((n-2));
			System.out.println(x.charAt(n-1));
		}
		else 
		System.out.println(x);
	}}
}


class InputReader
{
    public static final int id0 = 65536;
    public static final InputStream DEFAULT_STREAM;
    public static final int id13 = 21;
    private int c;
    private final byte[] buf;
    private int bufferSize;
    private int bufIndex;
    private int id27;
    private final InputStream stream;
    private static final byte EOF = -1;
    private static final byte NL = 10;
    private static final byte SP = 32;
    private static final byte DASH = 45;
    private static final byte DOT = 46;
    private static char[] charBuffer;
    private static byte[] bytes;
    private static int[] ints;
    private static char[] chars;
    private static final double[][] doubles;
    
    public InputReader() {
        this(InputReader.DEFAULT_STREAM, 65536);
    }
    
    public InputReader(final int n) {
        this(InputReader.DEFAULT_STREAM, n);
    }
    
    public InputReader(final InputStream inputStream) {
        this(inputStream, 65536);
    }
    
    public InputReader(final InputStream stream, final int bufferSize) {
        if (stream == null || bufferSize <= 0) {
            throw new IllegalArgumentException();
        }
        this.buf = new byte[bufferSize];
        this.bufferSize = bufferSize;
        this.stream = stream;
    }
    
    private byte read() throws IOException {
        if (this.id27 == -1) {
            throw new IOException();
        }
        if (this.bufIndex >= this.id27) {
            this.bufIndex = 0;
            this.id27 = this.stream.read(this.buf);
            if (this.id27 == -1) {
                return -1;
            }
        }
        return this.buf[this.bufIndex++];
    }
    
    private int id23(final int n) throws IOException {
        if (this.id27 == -1) {
            return -1;
        }
        while (true) {
            if (this.bufIndex < this.id27) {
                if (this.buf[this.bufIndex] > n) {
                    return 0;
                }
                ++this.bufIndex;
            }
            else {
                this.id27 = this.stream.read(this.buf);
                if (this.id27 == -1) {
                    return -1;
                }
                this.bufIndex = 0;
            }
        }
    }
    public byte nextByte() throws IOException {
        return (byte)this.nextInt();
    }
    
    public int nextInt() throws IOException {
        if (this.id23(44) == -1) {
            throw new IOException();
        }
        int n = 1;
        int n2 = 0;
        this.c = this.buf[this.bufIndex];
        if (this.c == 45) {
            n = -1;
            ++this.bufIndex;
        }
        while (true) {
            if (this.bufIndex < this.id27) {
                if (this.buf[this.bufIndex] <= 32) {
                    ++this.bufIndex;
                    return n2 * n;
                }
                n2 = (n2 << 3) + (n2 << 1) + InputReader.ints[this.buf[this.bufIndex++]];
            }
            else {
                this.id27 = this.stream.read(this.buf);
                if (this.id27 == -1) {
                    return n2 * n;
                }
                this.bufIndex = 0;
            }
        }
    }
    
    public long nextLong() throws IOException {
        if (this.id23(44) == -1) {
            throw new IOException();
        }
        int n = 1;
        long n2 = 0L;
        this.c = this.buf[this.bufIndex];
        if (this.c == 45) {
            n = -1;
            ++this.bufIndex;
        }
        while (true) {
            if (this.bufIndex < this.id27) {
                if (this.buf[this.bufIndex] <= 32) {
                    ++this.bufIndex;
                    return n2 * n;
                }
                n2 = (n2 << 3) + (n2 << 1) + InputReader.ints[this.buf[this.bufIndex++]];
            }
            else {
                this.id27 = this.stream.read(this.buf);
                if (this.id27 == -1) {
                    return n2 * n;
                }
                this.bufIndex = 0;
            }
        }
    }
    
    private void id3() {
        final char[] charBuffer = new char[InputReader.charBuffer.length << 1];
        for (int i = 0; i < InputReader.charBuffer.length; ++i) {
            charBuffer[i] = InputReader.charBuffer[i];
        }
        InputReader.charBuffer = charBuffer;
    }
    
    public String nextLine() throws IOException {
        try {
            this.c = this.read();
        }
        catch (IOException ex) {
            return null;
        }
        if (this.c == 10) {
            return "";
        }
        if (this.c == -1) {
            return null;
        }
        int n = 0;
        InputReader.charBuffer[n++] = (char)this.c;
        while (true) {
            if (this.bufIndex < this.id27) {
                if (this.buf[this.bufIndex] == 10) {
                    ++this.bufIndex;
                    return new String(InputReader.charBuffer, 0, n);
                }
                if (n == InputReader.charBuffer.length) {
                    this.id3();
                }
                InputReader.charBuffer[n++] = (char)this.buf[this.bufIndex++];
            }
            else {
                this.id27 = this.stream.read(this.buf);
                if (this.id27 == -1) {
                    return new String(InputReader.charBuffer, 0, n);
                }
                this.bufIndex = 0;
            }
        }
    }
    
    public String nextString() throws IOException {
        if (this.id27 == -1) {
            return null;
        }
        if (this.id23(32) == -1) {
            return null;
        }
        int n = 0;
        while (true) {
            if (this.bufIndex < this.id27) {
                if (this.buf[this.bufIndex] <= 32) {
                    ++this.bufIndex;
                    return new String(InputReader.charBuffer, 0, n);
                }
                if (n == InputReader.charBuffer.length) {
                    this.id3();
                }
                InputReader.charBuffer[n++] = (char)this.buf[this.bufIndex++];
            }
            else {
                this.id27 = this.stream.read(this.buf);
                if (this.id27 == -1) {
                    return new String(InputReader.charBuffer, 0, n);
                }
                this.bufIndex = 0;
            }
        }
    }
    
    public double nextDouble() throws IOException {
        final String nextString = this.nextString();
        if (nextString == null) {
            throw new IOException();
        }
        return Double.valueOf(nextString);
    }
    
    public double id8() throws IOException {
        this.c = this.read();
        int n = 1;
        while (this.c <= 32) {
            this.c = this.read();
        }
        if (this.c == 45) {
            n = -1;
            this.c = this.read();
        }
        double n2 = 0.0;
        while (this.c > 46) {
            n2 = n2 * 10.0 + InputReader.ints[this.c];
            this.c = this.read();
        }
        if (this.c == 46) {
            int n3 = 0;
            this.c = this.read();
            while (this.c > 32 && n3 < 21) {
                n2 += InputReader.doubles[InputReader.ints[this.c]][n3++];
                this.c = this.read();
            }
        }
        return n2 * n;
    }
    
    public byte[] id4(final int n) throws IOException {
        final byte[] array = new byte[n];
        for (int i = 0; i < n; ++i) {
            array[i] = this.nextByte();
        }
        return array;
    }
    
    public int[] id16(final int n) throws IOException {
        final int[] array = new int[n];
        for (int i = 0; i < n; ++i) {
            array[i] = this.nextInt();
        }
        return array;
    }
    
    public long[] id29(final int n) throws IOException {
        final long[] array = new long[n];
        for (int i = 0; i < n; ++i) {
            array[i] = this.nextLong();
        }
        return array;
    }
    
    public double[] id14(final int n) throws IOException {
        final double[] array = new double[n];
        for (int i = 0; i < n; ++i) {
            array[i] = this.nextDouble();
        }
        return array;
    }
    
    public double[] id26(final int n) throws IOException {
        final double[] array = new double[n];
        for (int i = 0; i < n; ++i) {
            array[i] = this.id8();
        }
        return array;
    }
    
    public String[] id17(final int n) throws IOException {
        final String[] array = new String[n];
        for (int i = 0; i < n; ++i) {
            final String nextString = this.nextString();
            if (nextString == null) {
                throw new IOException();
            }
            array[i] = nextString;
        }
        return array;
    }
    
    public byte[] id25(final int n) throws IOException {
        final byte[] array = new byte[n + 1];
        for (int i = 1; i <= n; ++i) {
            array[i] = this.nextByte();
        }
        return array;
    }
    
    public int[] id2(final int n) throws IOException {
        final int[] array = new int[n + 1];
        for (int i = 1; i <= n; ++i) {
            array[i] = this.nextInt();
        }
        return array;
    }
    
    public long[] id22(final int n) throws IOException {
        final long[] array = new long[n + 1];
        for (int i = 1; i <= n; ++i) {
            array[i] = this.nextLong();
        }
        return array;
    }
    
    public double[] id11(final int n) throws IOException {
        final double[] array = new double[n + 1];
        for (int i = 1; i <= n; ++i) {
            array[i] = this.nextDouble();
        }
        return array;
    }
    
    public double[] id19(final int n) throws IOException {
        final double[] array = new double[n + 1];
        for (int i = 1; i <= n; ++i) {
            array[i] = this.id8();
        }
        return array;
    }
    
    public String[] id18(final int n) throws IOException {
        final String[] array = new String[n + 1];
        for (int i = 1; i <= n; ++i) {
            array[i] = this.nextString();
        }
        return array;
    }
    
    public byte[][] id9(final int n, final int n2) throws IOException {
        final byte[][] array = new byte[n][n2];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n2; ++j) {
                array[i][j] = this.nextByte();
            }
        }
        return array;
    }
    
    public int[][] id1(final int n, final int n2) throws IOException {
        final int[][] array = new int[n][n2];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n2; ++j) {
                array[i][j] = this.nextInt();
            }
        }
        return array;
    }
    
    public long[][] id7(final int n, final int n2) throws IOException {
        final long[][] array = new long[n][n2];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n2; ++j) {
                array[i][j] = this.nextLong();
            }
        }
        return array;
    }
    
    public double[][] id10(final int n, final int n2) throws IOException {
        final double[][] array = new double[n][n2];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n2; ++j) {
                array[i][j] = this.nextDouble();
            }
        }
        return array;
    }
    
    public double[][] id15(final int n, final int n2) throws IOException {
        final double[][] array = new double[n][n2];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n2; ++j) {
                array[i][j] = this.id8();
            }
        }
        return array;
    }
    
    public String[][] id5(final int n, final int n2) throws IOException {
        final String[][] array = new String[n][n2];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n2; ++j) {
                array[i][j] = this.nextString();
            }
        }
        return array;
    }
    
    public byte[][] id28(final int n, final int n2) throws IOException {
        final byte[][] array = new byte[n + 1][n2 + 1];
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n2; ++j) {
                array[i][j] = this.nextByte();
            }
        }
        return array;
    }
    
    public int[][] id12(final int n, final int n2) throws IOException {
        final int[][] array = new int[n + 1][n2 + 1];
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n2; ++j) {
                array[i][j] = this.nextInt();
            }
        }
        return array;
    }
    
    public long[][] id6(final int n, final int n2) throws IOException {
        final long[][] array = new long[n + 1][n2 + 1];
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n2; ++j) {
                array[i][j] = this.nextLong();
            }
        }
        return array;
    }
    
    public double[][] id20(final int n, final int n2) throws IOException {
        final double[][] array = new double[n + 1][n2 + 1];
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n2; ++j) {
                array[i][j] = this.nextDouble();
            }
        }
        return array;
    }
    

    public double[][] id24(final int n, final int n2) throws IOException {
        final double[][] array = new double[n + 1][n2 + 1];
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n2; ++j) {
                array[i][j] = this.id8();
            }
        }
        return array;
    }
    
    public String[][] id21(final int n, final int n2) throws IOException {
        final String[][] array = new String[n + 1][n2 + 1];
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n2; ++j) {
                array[i][j] = this.nextString();
            }
        }
        return array;
    }
    
    public void close() throws IOException {
        this.stream.close();
    }
    
    static {
        DEFAULT_STREAM = System.in;
        InputReader.charBuffer = new char[128];
        InputReader.bytes = new byte[58];
        InputReader.ints = new int[58];
        InputReader.chars = new char[128];
        int n = ' ';
        int n2 = 0;
        int n3 = 0;
        for (int i = 48; i < 58; ++i) {
            final byte[] bytes = InputReader.bytes;
            final int n4 = i;
            final int n5 = n3;
            n3 = (byte)(n3 + 1);
            bytes[n4] = (byte)n5;
        }
        for (int j = 48; j < 58; ++j) {
            InputReader.ints[j] = n2++;
        }
        for (int k = 32; k < 128; ++k) {
            final char[] chars = InputReader.chars;
            final int n6 = k;
            final int n7 = n;
            n = (char)(n + '\u0001');
            chars[n6] = (char)n7;
        }
        doubles = new double[][] { { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 }, { 0.1, 0.01, 0.001, 1.0E-4, 1.0E-5, 1.0E-6, 1.0E-7, 1.0E-8, 1.0E-9, 1.0E-10, 1.0E-11, 1.0E-12, 1.0E-13, 1.0E-14, 1.0E-15, 1.0E-16, 1.0E-17, 1.0E-18, 1.0E-19, 1.0E-20, 1.0E-21 }, { 0.2, 0.02, 0.002, 2.0E-4, 2.0E-5, 2.0E-6, 2.0E-7, 2.0E-8, 2.0E-9, 2.0E-10, 2.0E-11, 2.0E-12, 2.0E-13, 2.0E-14, 2.0E-15, 2.0E-16, 2.0E-17, 2.0E-18, 2.0E-19, 2.0E-20, 2.0E-21 }, { 0.3, 0.03, 0.003, 3.0E-4, 3.0E-5, 3.0E-6, 3.0E-7, 3.0E-8, 3.0E-9, 3.0E-10, 3.0E-11, 3.0E-12, 3.0E-13, 3.0E-14, 3.0E-15, 3.0E-16, 3.0E-17, 3.0E-18, 3.0E-19, 3.0E-20, 3.0E-21 }, { 0.4, 0.04, 0.004, 4.0E-4, 4.0E-5, 4.0E-6, 4.0E-7, 4.0E-8, 4.0E-9, 4.0E-10, 4.0E-11, 4.0E-12, 4.0E-13, 4.0E-14, 4.0E-15, 4.0E-16, 4.0E-17, 4.0E-18, 4.0E-19, 4.0E-20, 4.0E-21 }, { 0.5, 0.05, 0.005, 5.0E-4, 5.0E-5, 5.0E-6, 5.0E-7, 5.0E-8, 5.0E-9, 5.0E-10, 5.0E-11, 5.0E-12, 5.0E-13, 5.0E-14, 5.0E-15, 5.0E-16, 5.0E-17, 5.0E-18, 5.0E-19, 5.0E-20, 5.0E-21 }, { 0.6, 0.06, 0.006, 6.0E-4, 6.0E-5, 6.0E-6, 6.0E-7, 6.0E-8, 6.0E-9, 6.0E-10, 6.0E-11, 6.0E-12, 6.0E-13, 6.0E-14, 6.0E-15, 6.0E-16, 6.0E-17, 6.0E-18, 6.0E-19, 6.0E-20, 6.0E-21 }, { 0.7, 0.07, 0.007, 7.0E-4, 7.0E-5, 7.0E-6, 7.0E-7, 7.0E-8, 7.0E-9, 7.0E-10, 7.0E-11, 7.0E-12, 7.0E-13, 7.0E-14, 7.0E-15, 7.0E-16, 7.0E-17, 7.0E-18, 7.0E-19, 7.0E-20, 7.0E-21 }, { 0.8, 0.08, 0.008, 8.0E-4, 8.0E-5, 8.0E-6, 8.0E-7, 8.0E-8, 8.0E-9, 8.0E-10, 8.0E-11, 8.0E-12, 8.0E-13, 8.0E-14, 8.0E-15, 8.0E-16, 8.0E-17, 8.0E-18, 8.0E-19, 8.0E-20, 8.0E-21 }, { 0.9, 0.09, 0.009, 9.0E-4, 9.0E-5, 9.0E-6, 9.0E-7, 9.0E-8, 9.0E-9, 9.0E-10, 9.0E-11, 9.0E-12, 9.0E-13, 9.0E-14, 9.0E-15, 9.0E-16, 9.0E-17, 9.0E-18, 9.0E-19, 9.0E-20, 9.0E-21 } };
    }
}