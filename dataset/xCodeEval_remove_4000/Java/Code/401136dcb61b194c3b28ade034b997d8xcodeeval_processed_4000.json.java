











import java.io.*;
import java.math.*;
import java.util.*;
import java.util.Map.*;
public class Main {
    static InputStream inputStream = System.in;
    static OutputStream outputStream = System.out;
    static InputReader sc = new InputReader(inputStream);
    static OutputWriter out = new OutputWriter(outputStream);
    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        while(T > 0) {
            T--;
            int a;
            int b;
            a = sc.nextInt();
            b = sc.nextInt();
            int m = (a-1) % 4;
            int xor;
            if(m == 0){
                xor = a-1;
            }else if(m == 1){
                xor = 1;
            }else if(m == 2){
                xor = a;
            }else{
                xor = 0;
            }

            if (xor == b) {
                System.out.println(a);
            } else {
                int K = xor ^ b;
                if (K == a) {
                    K = xor ^ (a + 1) ^ b;
                    System.out.println(a + 2);
                } else {
                    System.out.println(a + 1);
                }
            }
        }
    }
    static class InputReader
    {
        

        private InputStream stream;
        

        private byte[] buf = new byte[1024];
        private int curChar;

        private int numChars;

        

        private id6 filter;

        

        public InputReader(InputStream stream)
        {
            this.stream = stream;
        }

        

        public int read()
        {
            if (numChars == -1)
                throw new InputMismatchException();
            

            if (curChar >= numChars)
            {
                curChar = 0;

                try
                {
                    

                    numChars = stream.read(buf);
                } catch (IOException e)
                {
                    throw new InputMismatchException();
                }
                if (numChars <= 0)

                    return -1;
            }
            

            return buf[curChar++];
        }

        

        public int readInt()
        {
            int c = read();
            while (id5(c))

                c = read();
            int sgn = 1;

            if (c == '-')
            {
                sgn = -1;
                c = read();
            }
            int res = 0;
            do
            {
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = read();
            } while (!id5(c));
            

            return res * sgn;
        }

        

        public long readLong()
        {
            int c = read();
            while (id5(c))
                c = read();
            int sgn = 1;
            if (c == '-')
            {
                sgn = -1;
                c = read();
            }
            long res = 0;
            do
            {
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = read();
            } while (!id5(c));
            return res * sgn;
        }

        

        public String readString()
        {
            int c = read();
            while (id5(c))
                c = read();
            StringBuilder res = new StringBuilder();
            do
            {
                

                if (Character.isValidCodePoint(c))
                    res.appendCodePoint(c);

                c = read();
            } while (!id5(c));
            return res.toString();
        }

        

        public String next()
        {
            return readString();
        }

        

        public static String[] id2(InputReader in, int size)
        {
            String[] array = new String[size];
            for (int i = 0; i < size; i++)
                array[i] = in.readString();
            return array;
        }

        

        public static String[][] id1(InputReader in, int rowCount, int columnCount)
        {
            String[][] table = new String[rowCount][];
            for (int i = 0; i < rowCount; i++)
                table[i] = id2(in, columnCount);
            return table;
        }

        

        public char readCharacter()
        {
            int c = read();
            while (id5(c))
                c = read();
            return (char) c;
        }

        

        public String id3()
        {
            int c = read();
            while (id4(c))
                c = read();
            StringBuilder res = new StringBuilder();
            do
            {
                

                if (Character.isValidCodePoint(c))
                    res.appendCodePoint(c);

                c = read();
            } while (!id4(c));
            return res.toString();
        }

        

        public double readDouble()
        {
            int c = read();
            while (id5(c))
                c = read();
            int sgn = 1;
            if (c == '-')
            {
                sgn = -1;
                c = read();
            }
            double res = 0;
            while (!id5(c) && c != '.')
            {
                if (c == 'e' || c == 'E')
                    return res * Math.pow(10, readInt());
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = read();
            }
            if (c == '.')
            {
                c = read();
                double m = 1;
                while (!id5(c))
                {
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

        public boolean id5(int c)
        {
            if (filter != null)
                return filter.id5(c);
            return isWhitespace(c);
        }

        public boolean id4(int c)
        {
            if (filter != null)
                return filter.id4(c);
            return id0(c);
        }

        

        public static boolean id0(int c)
        {
            return c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public static boolean isWhitespace(int c)
        {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        

        public interface id6
        {
            public boolean id5(int ch);

            public boolean id4(int ch);
        }
    }

    static class OutputWriter
    {
        

        private final PrintWriter writer;

        public OutputWriter(OutputStream outputStream)
        {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

        

        public void print(int[] array)
        {
            for (int i = 0; i < array.length; i++)
            {
                if (i != 0)
                    writer.print(' ');
                writer.print(array[i]);
            }
        }

        

        public void printLine(int[] array)
        {
            print(array);
            writer.println();
        }

        public void print(Object... objects)
        {
            for (int i = 0; i < objects.length; i++)
            {
                if (i != 0)
                    writer.print(' ');
                writer.print(objects[i]);
            }
        }

        public void printLine(Object... objects)
        {
            print(objects);
            writer.println();
        }

        public void close()
        {
            writer.close();
        }

        public void print(int i)
        {
            writer.print(i);
        }

        public void print(String i)
        {
            writer.print(i);
        }

        public void print(long i)
        {
            writer.print(i);
        }

        public void print(char i)
        {
            writer.print(i);
        }

        public void printf(String format, Object... x)
        {
            writer.printf(format, x);
        }

        

        public void printLine(int i)
        {
            writer.println(i);
        }

        public void printLine(long i)
        {
            writer.println(i);
        }
    }
}
