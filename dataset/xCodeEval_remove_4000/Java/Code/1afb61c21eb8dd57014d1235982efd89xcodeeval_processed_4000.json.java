


import java.io.IOException;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

public class Main {
	
	public static class Node implements Comparable<Node>{
		int val;
		int index;
		Node(int val, int index) {
			this.val = val;
			this.index = index;
		}
		@Override
		public int compareTo(Node o) {
			

			return this.val - o.val;
		}
	}
	
	public static void swap(Node a, Node b) {
		int temp = a.index;
		a.index = b.index;
		b.index = temp;
	}
	
	public static void main(String[] args) throws IOException {
		

		InputReader fi = new InputReader();
		int n = fi.nextInt();
		Node[] arr = new Node[n];
		Set<Integer> set = new HashSet<>();
		for(int i = 0; i< n; i++) {
			int val = fi.nextInt();
			arr[i] = new Node(val, i+1);
			set.add(val);
		}
		
		if(set.size() > n-2) System.out.print("NO");
		else {
			Arrays.sort(arr);
			System.out.print("YES\n");
			for(int i = 0; i < n; i++) System.out.print(arr[i].index + " ");
			System.out.print("\n");
			for(int i = 1; i < n; i++) {
				if(arr[i].val == arr[i-1].val) {
					swap(arr[i], arr[i-1]);
					break;
				}
			}
			for(int i = 0; i < n; i++) System.out.print(arr[i].index + " ");
			System.out.print("\n");
			
			boolean id11 = false;
			for(int i = 1; i < n; i++) {
				if(arr[i].val == arr[i-1].val) {
					if(!id11) {
						id11 = true;
						continue;
					}
					swap(arr[i], arr[i-1]);
					break;
				}
			}
			for(int i = 0; i < n; i++) System.out.print(arr[i].index + " ");
		}
		
		
	}
	
	
	 private static class InputReader {
    	 
	        private int c, bufferSize, bufIndex, id14;
	 
	        private final byte[] buf;
	        private final java.io.InputStream stream;
	 
	        private static final int id0 = 1 << 16;
	        private static final java.io.InputStream DEFAULT_STREAM = System.in;
	 
	        private static final byte EOF = -1; 

	        private static final byte NL = 10; 

	        private static final byte SP = 32; 

	        private static final byte DASH = 45; 

	        private static final byte DOT = 46; 

	 
	        

	        private static final int id6 = 21;
	 
	        

	        private static char[] charBuffer = new char[128];
	 
	        

	        private static byte[] bytes = new byte[58];
	        private static int[] ints = new int[58];
	        private static char[] chars = new char[128];
	 
	        static {
	            char ch = ' ';
	            int value = 0;
	            byte _byte = 0;
	            for (int i = 48; i < 58; i++) bytes[i] = _byte++;
	            for (int i = 48; i < 58; i++) ints[i] = value++;
	            for (int i = 32; i < 128; i++) chars[i] = ch++;
	        }
	 
	        

	        private static final double[][] doubles = {
	                {0.0d, 0.00d, 0.000d, 0.0000d, 0.00000d, 0.000000d, 0.0000000d, 0.00000000d, 0.000000000d, 0.0000000000d, 0.00000000000d, 0.000000000000d, 0.0000000000000d, 0.00000000000000d, 0.000000000000000d, 0.0000000000000000d, 0.00000000000000000d, 0.000000000000000000d, 0.0000000000000000000d, 0.00000000000000000000d, 0.000000000000000000000d},
	                {0.1d, 0.01d, 0.001d, 0.0001d, 0.00001d, 0.000001d, 0.0000001d, 0.00000001d, 0.000000001d, 0.0000000001d, 0.00000000001d, 0.000000000001d, 0.0000000000001d, 0.00000000000001d, 0.000000000000001d, 0.0000000000000001d, 0.00000000000000001d, 0.000000000000000001d, 0.0000000000000000001d, 0.00000000000000000001d, 0.000000000000000000001d},
	                {0.2d, 0.02d, 0.002d, 0.0002d, 0.00002d, 0.000002d, 0.0000002d, 0.00000002d, 0.000000002d, 0.0000000002d, 0.00000000002d, 0.000000000002d, 0.0000000000002d, 0.00000000000002d, 0.000000000000002d, 0.0000000000000002d, 0.00000000000000002d, 0.000000000000000002d, 0.0000000000000000002d, 0.00000000000000000002d, 0.000000000000000000002d},
	                {0.3d, 0.03d, 0.003d, 0.0003d, 0.00003d, 0.000003d, 0.0000003d, 0.00000003d, 0.000000003d, 0.0000000003d, 0.00000000003d, 0.000000000003d, 0.0000000000003d, 0.00000000000003d, 0.000000000000003d, 0.0000000000000003d, 0.00000000000000003d, 0.000000000000000003d, 0.0000000000000000003d, 0.00000000000000000003d, 0.000000000000000000003d},
	                {0.4d, 0.04d, 0.004d, 0.0004d, 0.00004d, 0.000004d, 0.0000004d, 0.00000004d, 0.000000004d, 0.0000000004d, 0.00000000004d, 0.000000000004d, 0.0000000000004d, 0.00000000000004d, 0.000000000000004d, 0.0000000000000004d, 0.00000000000000004d, 0.000000000000000004d, 0.0000000000000000004d, 0.00000000000000000004d, 0.000000000000000000004d},
	                {0.5d, 0.05d, 0.005d, 0.0005d, 0.00005d, 0.000005d, 0.0000005d, 0.00000005d, 0.000000005d, 0.0000000005d, 0.00000000005d, 0.000000000005d, 0.0000000000005d, 0.00000000000005d, 0.000000000000005d, 0.0000000000000005d, 0.00000000000000005d, 0.000000000000000005d, 0.0000000000000000005d, 0.00000000000000000005d, 0.000000000000000000005d},
	                {0.6d, 0.06d, 0.006d, 0.0006d, 0.00006d, 0.000006d, 0.0000006d, 0.00000006d, 0.000000006d, 0.0000000006d, 0.00000000006d, 0.000000000006d, 0.0000000000006d, 0.00000000000006d, 0.000000000000006d, 0.0000000000000006d, 0.00000000000000006d, 0.000000000000000006d, 0.0000000000000000006d, 0.00000000000000000006d, 0.000000000000000000006d},
	                {0.7d, 0.07d, 0.007d, 0.0007d, 0.00007d, 0.000007d, 0.0000007d, 0.00000007d, 0.000000007d, 0.0000000007d, 0.00000000007d, 0.000000000007d, 0.0000000000007d, 0.00000000000007d, 0.000000000000007d, 0.0000000000000007d, 0.00000000000000007d, 0.000000000000000007d, 0.0000000000000000007d, 0.00000000000000000007d, 0.000000000000000000007d},
	                {0.8d, 0.08d, 0.008d, 0.0008d, 0.00008d, 0.000008d, 0.0000008d, 0.00000008d, 0.000000008d, 0.0000000008d, 0.00000000008d, 0.000000000008d, 0.0000000000008d, 0.00000000000008d, 0.000000000000008d, 0.0000000000000008d, 0.00000000000000008d, 0.000000000000000008d, 0.0000000000000000008d, 0.00000000000000000008d, 0.000000000000000000008d},
	                {0.9d, 0.09d, 0.009d, 0.0009d, 0.00009d, 0.000009d, 0.0000009d, 0.00000009d, 0.000000009d, 0.0000000009d, 0.00000000009d, 0.000000000009d, 0.0000000000009d, 0.00000000000009d, 0.000000000000009d, 0.0000000000000009d, 0.00000000000000009d, 0.000000000000000009d, 0.0000000000000000009d, 0.00000000000000000009d, 0.000000000000000000009d}
	        };
	 
	        public InputReader() {
	            this(DEFAULT_STREAM, id0);
	        }
	 
	        public InputReader(int bufferSize) {
	            this(DEFAULT_STREAM, bufferSize);
	        }
	 
	        public InputReader(java.io.InputStream stream) {
	            this(stream, id0);
	        }
	 
	        

	        public InputReader(java.io.InputStream stream, int bufferSize) {
	            if (stream == null || bufferSize <= 0)
	                throw new IllegalArgumentException();
	            buf = new byte[bufferSize];
	            this.bufferSize = bufferSize;
	            this.stream = stream;
	        }
	 
	        private byte read() throws java.io.IOException {
	 
	            if (id14 == EOF) throw new java.io.IOException();
	 
	            if (bufIndex >= id14) {
	                bufIndex = 0;
	                id14 = stream.read(buf);
	                if (id14 == EOF)
	                    return EOF;
	            }
	 
	            return buf[bufIndex++];
	 
	        }
	 
	        private int id12(int token) throws java.io.IOException {
	 
	            if (id14 == EOF) return EOF;
	 
	            

	            do {
	 
	                while (bufIndex < id14) {
	                    if (buf[bufIndex] > token) return 0;
	                    bufIndex++;
	                }
	 
	                

	                id14 = stream.read(buf);
	                if (id14 == EOF) return EOF;
	                bufIndex = 0;
	 
	            } while (true);
	 
	        }
	 
	        

	        public int nextInt() throws java.io.IOException {
	 
	            if (id12(DASH - 1) == EOF) throw new java.io.IOException();
	            int sgn = 1, res = 0;
	 
	            c = buf[bufIndex];
	            if (c == DASH) {
	                sgn = -1;
	                bufIndex++;
	            }
	 
	            do {
	 
	                while (bufIndex < id14) {
	                    if (buf[bufIndex] > SP) {
	                        res = (res << 3) + (res << 1);
	                        res += ints[buf[bufIndex++]];
	                    } else {
	                        bufIndex++;
	                        return res * sgn;
	                    }
	                }
	 
	                

	                id14 = stream.read(buf);
	                if (id14 == EOF) return res * sgn;
	                bufIndex = 0;
	 
	            } while (true);
	 
	        }
	 
	        

	        public long nextLong() throws java.io.IOException {
	 
	            if (id12(DASH - 1) == EOF) throw new java.io.IOException();
	            int sgn = 1;
	            long res = 0L;
	            c = buf[bufIndex];
	            if (c == DASH) {
	                sgn = -1;
	                bufIndex++;
	            }
	 
	            do {
	 
	                while (bufIndex < id14) {
	                    if (buf[bufIndex] > SP) {
	                        res = (res << 3) + (res << 1);
	                        res += ints[buf[bufIndex++]];
	                    } else {
	                        bufIndex++;
	                        return res * sgn;
	                    }
	                }
	 
	                

	                id14 = stream.read(buf);
	                if (id14 == EOF) return res * sgn;
	                bufIndex = 0;
	 
	            } while (true);
	 
	        }
	 
	        private void id2() {
	            char[] newBuffer = new char[charBuffer.length << 1];
	            for (int i = 0; i < charBuffer.length; i++) newBuffer[i] = charBuffer[i];
	            charBuffer = newBuffer;
	        }
	 
	        public String nextLine() throws java.io.IOException {
	 
	            try {
	                c = read();
	            } catch (java.io.IOException e) {
	                return null;
	            }
	            if (c == NL) return ""; 

	            if (c == EOF) return null; 

	 
	            int i = 0;
	            charBuffer[i++] = (char) c;
	 
	            do {
	 
	                while (bufIndex < id14) {
	                    if (buf[bufIndex] != NL) {
	                        if (i == charBuffer.length) id2();
	                        charBuffer[i++] = (char) buf[bufIndex++];
	                    } else {
	                        bufIndex++;
	                        return new String(charBuffer, 0, i);
	                    }
	                }
	 
	                

	                id14 = stream.read(buf);
	                if (id14 == EOF)
	                    return new String(charBuffer, 0, i);
	                bufIndex = 0;
	 
	            } while (true);
	 
	        }
	 
	 
	        public String nextString() throws java.io.IOException {
	 
	            if (id14 == EOF) return null;
	            if (id12(SP) == EOF) return null;
	            int i = 0;
	 
	            do {
	 
	                while (bufIndex < id14) {
	                    if (buf[bufIndex] > SP) {
	                        if (i == charBuffer.length) id2();
	                        charBuffer[i++] = (char) buf[bufIndex++];
	                    } else {
	                        bufIndex++;
	                        return new String(charBuffer, 0, i);
	                    }
	                }
	 
	                

	                id14 = stream.read(buf);
	                if (id14 == EOF) return new String(charBuffer, 0, i);
	                bufIndex = 0;
	 
	            } while (true);
	 
	        }
	 
	        public double nextDouble() throws java.io.IOException {
	            String doubleVal = nextString();
	            if (doubleVal == null) throw new java.io.IOException();
	            return Double.valueOf(doubleVal);
	        }
	 
	        public double id5() throws java.io.IOException {
	            c = read();
	            int sgn = 1;
	            while (c <= SP) c = read(); 

	            if (c == DASH) {
	                sgn = -1;
	                c = read();
	            }
	            double res = 0.0;
	            

	            while (c > DOT) {
	                res *= 10.0;
	                res += ints[c];
	                c = read();
	            }
	            if (c == DOT) {
	                int i = 0;
	                c = read();
	                

	                while (c > SP && i < id6) {
	                    res += doubles[ints[c]][i++];
	                    c = read();
	                }
	            }
	            return res * sgn;
	        }
	 
	        public int[] id8(int n) throws java.io.IOException {
	            int[] ar = new int[n];
	            for (int i = 0; i < n; i++) ar[i] = nextInt();
	            return ar;
	        }
	 
	        public long[] id15(int n) throws java.io.IOException {
	            long[] ar = new long[n];
	            for (int i = 0; i < n; i++) ar[i] = nextLong();
	            return ar;
	        }
	 
	        public double[] id7(int n) throws java.io.IOException {
	            double[] ar = new double[n];
	            for (int i = 0; i < n; i++) ar[i] = nextDouble();
	            return ar;
	        }
	 
	        public double[] id13(int n) throws java.io.IOException {
	            double[] ar = new double[n];
	            for (int i = 0; i < n; i++) ar[i] = id5();
	            return ar;
	        }
	 	
	
	        public String[] id9(int n) throws java.io.IOException {
	            String[] ar = new String[n];
	            for (int i = 0; i < n; i++) {
	                String str = nextString();
	                if (str == null) throw new java.io.IOException();
	                ar[i] = str;
	            }
	            return ar;
	        }
	 
	        public int[][] id1(int rows, int cols) throws java.io.IOException {
	            int[][] matrix = new int[rows][cols];
	            for (int i = 0; i < rows; i++)
	                for (int j = 0; j < cols; j++)
	                    matrix[i][j] = nextInt();
	            return matrix;
	        }
	 
	        public long[][] id4(int rows, int cols) throws java.io.IOException {
	            long[][] matrix = new long[rows][cols];
	            for (int i = 0; i < rows; i++)
	                for (int j = 0; j < cols; j++)
	                    matrix[i][j] = nextLong();
	            return matrix;
	        }
	 
	        public double[][] id10(int rows, int cols) throws java.io.IOException {
	            double[][] matrix = new double[rows][cols];
	            for (int i = 0; i < rows; i++)
	                for (int j = 0; j < cols; j++)
	                    matrix[i][j] = id5();
	            return matrix;
	        }
	 
	        public String[][] id3(int rows, int cols) throws java.io.IOException {
	            String[][] matrix = new String[rows][cols];
	            for (int i = 0; i < rows; i++)
	                for (int j = 0; j < cols; j++)
	                    matrix[i][j] = nextString();
	            return matrix;
	        }
	 
	        

	        public void close() throws java.io.IOException {
	            stream.close();
	        }
	 
	    }
}