    import java.util.*;
    import java.io.*;
     
    public class Main {
	static InputReader scn = new InputReader(System.in);
	static OutputWriter out = new OutputWriter(System.out);
	static long[][][] x;
	static long[][][] y;
	static String[] str;
	public static void main(String[] HastaLaVistaLa) {
		

		String s = "1 1 1 10 1 100 1 1000 1 10000 1 100000 1 1000000 1 10000000 1 100000000 10 1 10 11 10 10 10 101 10 100 10 1001 10 1000 10 10001 10 10000 10 100001 10 100000 10 1000001 10 1000000 10 10000001 10 10000000 10 100000001 10 100000000 100 1 100 11 100 10 100 101 100 110 100 100 100 1001 100 1010 100 1000 100 10001 100 10010 100 10000 100 100001 100 100010 100 100000 100 1000001 100 1000010 100 1000000 100 10000001 100 10000010 100 10000000 100 100000001 100 100000010 100 100000000 1000 1 1000 11 1000 10 1000 101 1000 110 1000 100 1000 1001 1000 1010 1000 1100 1000 1000 1000 10001 1000 10010 1000 10100 1000 10000 1000 100001 1000 100010 1000 100100 1000 100000 1000 1000001 1000 1000010 1000 1000100 1000 1000000 1000 10000001 1000 10000010 1000 10000100 1000 10000000 1000 100000001 1000 100000010 1000 100000100 1000 100000000 10000 1 10000 11 10000 10 10000 101 10000 110 10000 100 10000 1001 10000 1008 10000 1100 10000 1000 10000 10001 10000 10010 10000 10100 10000 11000 10000 10000 10000 100001 10000 100010 10000 100100 10000 101000 10000 100000 10000 1000001 10000 1000010 10000 1000100 10000 1001000 10000 1000000 10000 10000001 10000 10000010 10000 10000100 10000 10001000 10000 10000000 10000 100000001 10000 100000010 10000 100000100 10000 100001000 10000 100000000 100000 1 100000 11 100000 10 100000 101 100000 110 100000 100 100000 1001 100000 1008 100000 1100 100000 1000 100000 10001 100000 10010 100000 10080 100000 11000 100000 10000 100000 100001 100000 100010 100000 100100 100000 101000 100000 110000 100000 100000 100000 1000001 100000 1000010 100000 1000100 100000 1001000 100000 1010000 100000 1000000 100000 10000001 100000 10000010 100000 10000100 100000 10001000 100000 10010000 100000 10000000 100000 100000001 100000 100000010 100000 100000100 100000 100001000 100000 100010000 100000 100000000 1000000 1 1000000 11 1000000 10 1000000 101 1000000 110 1000000 100 1000000 1001 1000000 1008 1000000 1100 1000000 1000 1000000 10001 1000000 10010 1000000 10080 1000000 11000 1000000 10000 1000000 100001 1000000 100010 1000000 100100 1000000 100800 1000000 109375 1000000 100000 1000000 1000001 1000000 1000010 1000000 1000100 1000000 1001000 1000000 1010000 1000000 1100000 1000000 1000000 1000000 10000001 1000000 10000010 1000000 10000100 1000000 10001000 1000000 10010000 1000000 10100000 1000000 10000000 1000000 100000001 1000000 100000010 1000000 100000100 1000000 100001000 1000000 100010000 1000000 100100000 1000000 100000000 10000000 1 10000000 11 10000000 10 10000000 101 10000000 110 10000000 100 10000000 1001 10000000 1008 10000000 1024 10000000 1000 10000000 10001 10000000 10010 10000000 10080 10000000 11000 10000000 10000 10000000 100001 10000000 100010 10000000 100096 10000000 100800 10000000 109375 10000000 100000 10000000 1000001 10000000 1000010 10000000 1000064 10000000 1001000 10000000 1008000 10000000 1093750 10000000 1000000 10000000 10000001 10000000 10000010 10000000 10000100 10000000 10001000 10000000 10010000 10000000 10100000 10000000 11000000 10000000 10000000 10000000 100000001 10000000 100000010 10000000 100000100 10000000 100001000 10000000 100010000 10000000 100100000 10000000 101000000 10000000 100000000 100000000 1 100000000 11 100000000 10 100000000 101 100000000 110 100000000 100 100000000 1001 100000000 1008 100000000 1024 100000000 1000 100000000 10001 100000000 10010 100000000 10080 100000000 10240 100000000 10000 100000000 100001 100000000 100010 100000000 100096 100000000 100800 100000000 109375 100000000 100000 100000000 1000001 100000000 1000010 100000000 1000064 100000000 1000960 100000000 1008000 100000000 1093750 100000000 1000000 100000000 10000001 100000000 10000010 100000000 10000100 100000000 10000640 100000000 10010000 100000000 10080000 100000000 10937500 100000000 10000000 100000000 100000001 100000000 100000010 100000000 100000100 100000000 100001000 100000000 100010000 100000000 100100000 100000000 101000000 100000000 110000000 100000000 100000000";
		str = s.split(" ");
		int t = scn.nextInt();
		while(t-- > 0)
			dummy();
		out.close();
	}

	public static void dummy(){
		
		int n = str.length;
		int a = scn.nextInt();
		int b = scn.nextInt();
		int c = scn.nextInt();
		for(int i = 0; i + 1 < n; i += 2) {
			if(a == Len(Integer.valueOf(str[i])) && b == Len(Integer.valueOf(str[i+1])) ){
				String s1 = str[i];
				String s2 = str[i+1];
				long aa = Long.valueOf(s1);
				long bb = Long.valueOf(s2);
				if(Len(gcd(aa, bb)) == c) {
					out.println(s1 + " " + s2);
					return;
				}
 					
			}
		}
	}

	static long[] dp;
	static long mod = 1000000007L;
	public static void solve() {
		

			
		for(int i = 1; i <= 9; i++) {
	 		for(int j = 1; j <= 9; j++) {
	 			int p = Math.min(i, j);
	 			for(int k = 1; k <= p; k++){
		 			out.print(x[i][j][k] + " " + y[i][j][k] + " ");
	 			}	
	 		}
	 	}
	}

	public static long[] answer(int a, int b, int c){

		long aa = (long) Math.pow(10, a) - 1;
	 	long bb = (long) Math.pow(10, b) - 1;
	 	long innerA = (aa+1)/10;
	 	long innerB = (bb+1)/10;
	 	boolean check = false;
	 	long[] arr = new long[2];
		for(long p = innerA; p <= aa; p++) {
	 		for(long q = innerB; q <= bb; q++) {
	 			if(Len(gcd(p, q)) == c) {
	 				arr[0] = p;
	 				arr[1] = q;
	 				check = true;
	 			}
	 			if(check) break;
	 		}
	 		if(check) break;
	 	}
	 	return arr;

	}

	public static int Len(long a) {
		int l = 0;
		while(a != 0) {
			a /= 10;
			l++;
		}
		return l;
	}

	public static long gcd(long a, long b) {
		if (a == 0)
			return b;
		return gcd(b % a, a);
	}

	public static long factorial(long number) {
		number %= mod;
	        long result = 1;
	        for (long factor = 2; factor <= number; factor++) {
	            result *= factor % mod;
	            result %= mod;
	        }
	        result %= mod;

        	return result;
    }

	

	public static int[] NumberOFDivisors(int l, int r) {
		int[] arr = new int[l - r + 1];
		for(int i = l; i <= r; i++) {
			for(int j = i; j <= r; j += i)
				arr[j]++;
		}
		return arr;
	}

	public static int LowerBound(long a[], long x) { 


		  int l = -1,r = a.length;
		  while(l + 1 < r) {

		    int m = (l + r) >>> 1;
		    if(a[m] >= x) r = m;
		    else l = m;

		  }
		  return r;
	}

	static boolean[] prime;
	public static void sieveOfEratosthenes(int n) {
        	prime = new boolean[n+1];
	        for(int i=0;i<n;i++)
	            prime[i] = true;
	          
	        for(int p = 2; p*p <=n; p++) {

	            if(prime[p] == true) {

	                for(int i = p*p; i <= n; i += p)
	                    prime[i] = false;
	            }
	        }
    	}

	public static long binpow(long n, long m, long mod) {
	        long res = 1;
	        while (m > 0) {
	            if (m % 2 == 1) {
	                res *= n;
	                res %= mod;
	                m--;
	            }
	            n *= n;
	            n %= mod;
	            m /= 2;
	        }
	        return res;
    	}

	public static int UpperBound(long a[], long x) {


		    int l = -1,r = a.length;

		    while(l + 1 < r) {

		       int m = (l + r) >>> 1;
		       if(a[m] <= x) l = m;
		       else r = m;

		    }
		    return l + 1;
	}

    	public static long lcm(long a, long b) {
		return (a * b) / gcd(a, b);
	}
     
	public static HashMap<Integer, Integer> CountFrequencies(int[] arr) {
     
		HashMap<Integer, Integer> map = new HashMap<>();
		for (int i : arr) {
			if (map.containsKey(i)) map.put(i, map.get(i) + 1);
			else map.put(i, 1);
		}
		return map;
	}

	public static void sort(int[] arr) {
		Random rand = new Random();
		int n = arr.length;
		for(int i = 0; i<n; i++) {
			swap(arr, i, rand.nextInt(n));
		}
		Arrays.sort(arr);
	}

	public static void swap(int[] arr, int i, int j) {
		if(i!=j) {
			arr[i] ^= arr[j];
			arr[j] ^= arr[i];
			arr[i] ^= arr[j];
		}
	}
     
	public static void sortbyColumn(int[][] arr, int col) {
		Arrays.sort(arr, new Comparator<int[]>() {
			public int compare(final int[] entry1, final int[] entry2) {
				if (entry1[col] > entry2[col])
					return 1;
				else
					return -1;
			}
		});
	}

	public static void ArraySort2D(int[][] arr, int xy) {
		

		

		Arrays.sort(arr, Comparator.comparingDouble(o -> o[xy]));
	}
	
	public static int binarySearch(int arr[], int l, int r, int x) {
		if (r >= l) {
			int mid = l + (r - l) / 2;
			if (arr[mid] == x)
				return mid;
			if (arr[mid] > x)
				return binarySearch(arr, l, mid - 1, x);
			return binarySearch(arr, mid + 1, r, x);
		}
		return -1;
	}
     
	static class InputReader {
		private InputStream stream;
		private byte[] buf = new byte[1024];
		private int curChar;
		private int numChars;
		private SpaceCharFilter filter;
     
		public InputReader(InputStream stream) {
			this.stream = stream;
		}
     
		public int[] readIntArray(int n) {
			int[] a = new int[n];
			for (int i = 0; i < n; i++) {
				a[i] = scn.nextInt();
			}
			return a;
		}
     			
     		public long[] readLongArray(int n) {
			long[] a = new long[n];
			for (int i = 0; i < n; i++) {
				a[i] = scn.nextLong();
			}
			return a;
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
     
		public int nextInt() {
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
     
		public long nextLong() {
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
     
		public String nextLine() {
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
     
		public boolean isSpaceChar(int c) {
			if (filter != null)
				return filter.isSpaceChar(c);
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}
     
		public String next() {
			return nextLine();
		}
     
		public interface SpaceCharFilter {
			public boolean isSpaceChar(int ch);
		}
	}
     
	static class OutputWriter {
		private final PrintWriter writer;
     
		public OutputWriter(OutputStream outputStream) {
			writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
		}
     
		public OutputWriter(Writer writer) {
			this.writer = new PrintWriter(writer);
		}
     
		public void print(Object... objects) {
			for (int i = 0; i < objects.length; i++) {
				if (i != 0) {
					writer.print(' ');
    

				}
				writer.print(objects[i]);
			}
		}
     
		public void println(Object... objects) {
			print(objects);
			writer.println();
		}
     
		public void close() {
			writer.close();
		}
	}
}