

import java.io.*;
import java.math.*;
import java.util.*;

public class test2 {
	
	
	public static class FastWriter {
        private static final int BUF_SIZE = 1 << 13;
        private final byte[] buf = new byte[BUF_SIZE];
        private final OutputStream out;
        private int ptr = 0;
 
        private FastWriter() {
            out = null;
        }
 
        public FastWriter(OutputStream os) {
            this.out = os;
        }
 
        public FastWriter(String path) {
            try {
                this.out = new FileOutputStream(path);
            } catch (FileNotFoundException e) {
                throw new RuntimeException("FastWriter");
            }
        }
 
        public FastWriter write(byte b) {
            buf[ptr++] = b;
            if (ptr == BUF_SIZE) innerflush();
            return this;
        }
 
        public FastWriter write(char c) {
            return write((byte) c);
        }
 
        public FastWriter write(char[] s) {
            for (char c : s) {
                buf[ptr++] = (byte) c;
                if (ptr == BUF_SIZE) innerflush();
            }
            return this;
        }
 
        public FastWriter write(String s) {
            s.chars().forEach(c -> {
                buf[ptr++] = (byte) c;
                if (ptr == BUF_SIZE) innerflush();
            });
            return this;
        }
 
        private static int countDigits(int l) {
            if (l >= 1000000000) return 10;
            if (l >= 100000000) return 9;
            if (l >= 10000000) return 8;
            if (l >= 1000000) return 7;
            if (l >= 100000) return 6;
            if (l >= 10000) return 5;
            if (l >= 1000) return 4;
            if (l >= 100) return 3;
            if (l >= 10) return 2;
            return 1;
        }
 
        public FastWriter write(int x) {
            if (x == Integer.MIN_VALUE) {
                return write((long) x);
            }
            if (ptr + 12 >= BUF_SIZE) innerflush();
            if (x < 0) {
                write((byte) '-');
                x = -x;
            }
            int d = countDigits(x);
            for (int i = ptr + d - 1; i >= ptr; i--) {
                buf[i] = (byte) ('0' + x % 10);
                x /= 10;
            }
            ptr += d;
            return this;
        }
 
        private static int countDigits(long l) {
            if (l >= 1000000000000000000L) return 19;
            if (l >= 100000000000000000L) return 18;
            if (l >= 10000000000000000L) return 17;
            if (l >= 1000000000000000L) return 16;
            if (l >= 100000000000000L) return 15;
            if (l >= 10000000000000L) return 14;
            if (l >= 1000000000000L) return 13;
            if (l >= 100000000000L) return 12;
            if (l >= 10000000000L) return 11;
            if (l >= 1000000000L) return 10;
            if (l >= 100000000L) return 9;
            if (l >= 10000000L) return 8;
            if (l >= 1000000L) return 7;
            if (l >= 100000L) return 6;
            if (l >= 10000L) return 5;
            if (l >= 1000L) return 4;
            if (l >= 100L) return 3;
            if (l >= 10L) return 2;
            return 1;
        }
 
        public FastWriter write(long x) {
            if (x == Long.MIN_VALUE) {
                return write("" + x);
            }
            if (ptr + 21 >= BUF_SIZE) innerflush();
            if (x < 0) {
                write((byte) '-');
                x = -x;
            }
            int d = countDigits(x);
            for (int i = ptr + d - 1; i >= ptr; i--) {
                buf[i] = (byte) ('0' + x % 10);
                x /= 10;
            }
            ptr += d;
            return this;
        }
 
        public FastWriter write(double x, int precision) {
            if (x < 0) {
                write('-');
                x = -x;
            }
            x += Math.pow(10, -precision) / 2;
            

            write((long) x).write(".");
            x -= (long) x;
            for (int i = 0; i < precision; i++) {
                x *= 10;
                write((char) ('0' + (int) x));
                x -= (int) x;
            }
            return this;
        }
 
        public FastWriter writeln(char c) {
            return write(c).writeln();
        }
 
        public FastWriter writeln(int x) {
            return write(x).writeln();
        }
 
        public FastWriter writeln(long x) {
            return write(x).writeln();
        }
 
        public FastWriter writeln(double x, int precision) {
            return write(x, precision).writeln();
        }
 
        public FastWriter write(int... xs) {
            boolean first = true;
            for (int x : xs) {
                if (!first) write(' ');
                first = false;
                write(x);
            }
            return this;
        }
 
        public FastWriter write(long... xs) {
            boolean first = true;
            for (long x : xs) {
                if (!first) write(' ');
                first = false;
                write(x);
            }
            return this;
        }
 
        public FastWriter writeln() {
            return write((byte) '\n');
        }
 
        public FastWriter writeln(int... xs) {
            return write(xs).writeln();
        }
 
        public FastWriter writeln(long... xs) {
            return write(xs).writeln();
        }
 
        public FastWriter writeln(char[] line) {
            return write(line).writeln();
        }
 
        public FastWriter writeln(char[]... map) {
            for (char[] line : map) write(line).writeln();
            return this;
        }
 
        public FastWriter writeln(String s) {
            return write(s).writeln();
        }
 
        private void innerflush() {
            try {
                out.write(buf, 0, ptr);
                ptr = 0;
            } catch (IOException e) {
                throw new RuntimeException("innerflush");
            }
        }
 
        public void flush() {
            innerflush();
            try {
                out.flush();
            } catch (IOException e) {
                throw new RuntimeException("flush");
            }
        }
 
        public FastWriter print(byte b) {
            return write(b);
        }
 
        public FastWriter print(char c) {
            return write(c);
        }
 
        public FastWriter print(char[] s) {
            return write(s);
        }
 
        public FastWriter print(String s) {
            return write(s);
        }
 
        public FastWriter print(int x) {
            return write(x);
        }
 
        public FastWriter print(long x) {
            return write(x);
        }
 
        public FastWriter print(double x, int precision) {
            return write(x, precision);
        }
 
        public FastWriter println(char c) {
            return writeln(c);
        }
 
        public FastWriter println(int x) {
            return writeln(x);
        }
 
        public FastWriter println(long x) {
            return writeln(x);
        }
 
        public FastWriter println(double x, int precision) {
            return writeln(x, precision);
        }
 
        public FastWriter print(int... xs) {
            return write(xs);
        }
 
        public FastWriter print(long... xs) {
            return write(xs);
        }
 
        public FastWriter println(int... xs) {
            return writeln(xs);
        }
 
        public FastWriter println(long... xs) {
            return writeln(xs);
        }
 
        public FastWriter println(char[] line) {
            return writeln(line);
        }
 
        public FastWriter println(char[]... map) {
            return writeln(map);
        }
 
        public FastWriter println(String s) {
            return writeln(s);
        }
 
        public FastWriter println() {
            return writeln();
        }
    }
 
 
    static final class InputReader {
        private final InputStream stream;
        private final byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
 
        public InputReader(InputStream stream) {
            this.stream = stream;
        }
 
        private int read() throws IOException {
            if (curChar >= numChars) {
                curChar = 0;
                numChars = stream.read(buf);
                if (numChars <= 0) {
                    return -1;
                }
            }
            return buf[curChar++];
        }
 
        public final int readInt() throws IOException {
            return (int) readLong();
        }
 
        public final long readLong() throws IOException {
            int c = read();
            while (id2(c)) {
                c = read();
                if (c == -1) throw new IOException();
            }
            boolean negative = false;
            if (c == '-') {
                negative = true;
                c = read();
            }
            long res = 0;
            do {
                res *= 10;
                res += c - '0';
                c = read();
            } while (!id2(c));
            return negative ? -res : res;
        }
 
        public final int[] id0(int size) throws IOException {
            int[] array = new int[size];
            for (int i = 0; i < size; i++) {
                array[i] = readInt();
            }
            return array;
        }
 
        public final long[] id3(int size) throws IOException {
            long[] array = new long[size];
            for (int i = 0; i < size; i++) {
                array[i] = readLong();
            }
            return array;
        }
 
        public final String readString() throws IOException {
            int c = read();
            while (id2(c)) {
                c = read();
            }
            StringBuilder res = new StringBuilder();
            do {
                res.append((char) c);
                c = read();
            } while (!id2(c));
            return res.toString();
        }
 
        private boolean id2(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }
    }
 
    static long mulmod(long a, long b,
                       long mod) {
        long res = 0; 

        a = a % mod;
        while (b > 0) {
            

            if (b % 2 == 1) {
                res = (res + a) % mod;
            }
 
            

            a = (a * 2) % mod;
 
            

            b /= 2;
        }
 
        

        return res % mod;
    }
 
    static long pow(long a, long b, long MOD) {
        long x = 1, y = a;
        while (b > 0) {
            if (b % 2 == 1) {
                x = (x * y);
                if (x > MOD) x %= MOD;
            }
            y = (y * y);
            if (y > MOD) y %= MOD;
            b /= 2;
        }
        return x;
    }
 
    static long[] f = new long[100001];
 
    static long InverseEuler(long n, long MOD) {
        return pow(n, MOD - 2, MOD);
    }
 
    static long C(int n, int r, long MOD) {
 
        return (f[n] * ((InverseEuler(f[r], MOD) * InverseEuler(f[n - r], MOD)) % MOD)) % MOD;
    }
 
 
    static int[] h = {0, 0, -1, 1};
    static int[] v = {1, -1, 0, 0};
 
 
    
 
    static class Pair2 {
        public long cost;
        int node;
 
        public Pair2(long cos, int node) {
            this.cost = cos;
            this.node = node;
        }
    }
 
    static long compute_hash(String s) {
        int p = 31;
        int m = 1000000007;
        long hash_value = 0;
        long p_pow = 1;
        for (int i = 0; i < s.length(); ++i) {
            char c = s.charAt(i);
            hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
            p_pow = (p_pow * p) % m;
        }
        return hash_value;
    }
 
    public static class SegmentTree {
        long[][] tree;
        int n;
 
        public SegmentTree(int[] nodes) {
            tree = new long[nodes.length * 4][2];
            n = nodes.length;
            build(0, n - 1, 0, nodes);
 
        }
 
        private void build(int l, int r, int pos, int[] nodes) {
            if (l == r) {
                tree[pos][0] = nodes[l];
                tree[pos][1] = l;
                return;
            }
            int mid = (l + r) / 2;
            build(l, mid, 2 * pos + 1, nodes);
            build(mid + 1, r, 2 * pos + 2, nodes);
            if (tree[2 * pos + 1][0] > tree[2 * pos + 2][0]) {
                tree[pos][1] = tree[2 * pos + 1][1];
            } else {
                tree[pos][1] = tree[2 * pos + 2][1];
            }
            tree[pos][0] = Math.max(tree[2 * pos + 1][0], tree[2 * pos + 2][0]);
        }
 
        

        

        

 
        public long[] get(int l, int r) {
            return getUtil(0, n - 1, 0, l, r);
        }
 
        private long[] getUtil(int l, int r, int pos, int ql, int qr) {
            if (ql > r || qr < l) {
                return new long[]{-1, -1};
            }
            if (l >= ql && r <= qr) {
                return tree[pos];
            }
 
            int mid = (l + r) / 2;
            long[] left = getUtil(l, mid, 2 * pos + 1, ql, qr);
            long[] right = getUtil(mid + 1, r, 2 * pos + 2, ql, qr);
            long choice = right[1];
            if (left[0] > right[0]) choice = left[1];
            return new long[]{Math.max(left[0], right[0]), choice};
 
        }
 
        

        

        

        

        

        

        

        

        

        

        

        

        

    }
 
    static int counter = 0;
    static int[] rIn;
    static int[] rOut;
    static int[] lIn;
    static int[] lOut;
    private static int[] flatten;
    private static int[] lFlatten;
    static long answer = 0;
 
    static int VISITED = 1;
    static int VISITING = 2;
 
    static int[] DIRX = new int[]{0, 0, 1, -1};
    static int[] DIRY = new int[]{1, -1, 0, 0};
 
    public static class Pair22 {
        int num, pos;
 
        public Pair22(int x, int y) {
            this.num = x;
            this.pos = y;
        }
    }
 
    public static long id1(long n) {
        long sum = 0;
        while (n > 0) {
            sum += n%10;
            n/=10;
        }
        return sum;
    }
	 static int binarySearch(long[] arr, long target) 
    { 
        int start = 0, end = arr.length - 1; 
    
        int ans = 0; 
        while (start <= end) { 
        	
            int mid = start + (end - start) / 2; 
    
            if (arr[mid] <= target) { 
            	ans = mid +1;
                start = mid + 1; 
            } 
    
            else { 
                 
                end = mid - 1; 
            } 
        } 
        return ans; 
    } 
	 
	  static long gcd(long a, long b)
	    {
	        if (a == 0)
	            return b;
	        return gcd(b % a, a);
	    }
	     
	  static boolean id4(long num)
	    {
	        long left = 1, right = num;
	         
	        while (left <= right)
	        {
	            long mid = (left + right) / 2;
	           
	            

	            if (mid * mid == num)
	            {
	                return true;
	            }
	            
	            

	            if (mid * mid < num)
	            {
	                left = mid + 1;
	            }
	           
	            

	            else
	            {
	                right = mid - 1;
	            }
	        }
	        return false;
	    }
	    static long lcm(long a, long b)
	    {
	        return (a / gcd(a, b)) * b;
	    }
	    
	    
	    static long MOD = 1000000007;
		  
		   static long power( long x,
				    long y, long p)
				{
				    long res = 1; 

				 
				    x = x % p; 

				    

				 
				    while (y > 0)
				    {
				 
				        

				        if ((y & 1)>0)
				            res = (res * x) % p;
				 
				        

				        y = y >> 1; 

				        x = (x * x) % p;
				    }
				    return res;
				}
		   static long modInverse( long n,
				    long p)
				{
				    return power(n, p - 2, p);
				}
		   static long id6( int n, int r, long p)
		   {
		       

		       if (n < r)
		           return 0;
		       

		       if (r == 0)
		           return 1;
		    
		       

		       

		       

		       long fac[] = new long[n+1];
		       fac[0] = 1;
		       for (int i = 1; i <= n; i++)
		           fac[i] = (fac[i - 1] * i) % p;
		    
		       return (fac[n] * modInverse(fac[r], p) % p
		           * modInverse(fac[n - r], p) % p)
		           % p;
		   }
		   
		   public static int upperBound(Integer[] a,int size,Integer key)
			{
				int first=0,last=size-1;
				while(first<last)
				{
					int mid=(first+last)/2;
					if(key<a[mid])
						last=mid;
					else
						first=mid+1;
				}
				if(a[first]>key)
					return first;
				return size;
			}
			
			public static int lowerBound(Integer[] a,int size,Integer key)
			{
				int first=0,last=size-1;
				while(first<last)
				{
					int mid=(first+last)/2;
					if(key>a[mid])
						first=mid+1;
					else
						last=mid;
				}
				if(a[first]>=key)
					return first;
				return size;
			}
			
			  static class id5{ 
				   long x;
				   long y;
				   
				   id5(long x,long y){ 
					   this.x = x;
					   this.y = y;
					   
				   }
			   }
			 
			 static int function(int mid,long a[],long q) {
				 
				 long c = q;
				 int ans = 0;
				 for(int i=0;i<a.length;i++) {
					 if(a[i] > c && mid > 0) {
						 mid--;
					 }
					 else if(a[i] > c) {
						 ans++;
						 c--;
					 }
					 else {
						 ans++;
					 }
					if(c == -1) {
						return -1;
					}
				 }
				 
				 
				 return ans;
			 }
	   public static void main(String[] args) throws Exception
	    {
		   Scanner scanner = new Scanner(System.in);
			  
		   int testcase = scanner.nextInt();
		   
		   while(testcase-->0) { 
			   
			   int n = scanner.nextInt();
			   
			   long q = scanner.nextLong();
			   
			   long a[] = new long[n];
			   
			   for(int i=0;i<n;i++) {
				   a[i] = scanner.nextLong();
				   
			   }
			  
			   int l = 0;
			   int r = n;
			   int ans = -1;
			   
			   while(l <= r) {
				   
				   int mid = l + (r-l)/2;
				   
				   if(function(mid,a,q)== -1) {
					   
					   l = mid+1;
				   }
				   else {
					   ans = function(mid,a,q);
					   r = mid-1;
				   }
			   }
			  ans = n - ans;


			   StringBuilder string = new StringBuilder();
			   for(int i=0;i<n;i++) {
				   if(a[i]>q && ans>0) {
					   ans--;
					   string.append('0');
				   }
				   else if(a[i]>q) {
					   q--;
					   string.append('1');
				   }
				   else {
					   string.append('1');
				   }
			   }
			   
			   System.out.println(string);
		   }
		   
	    }
}  


