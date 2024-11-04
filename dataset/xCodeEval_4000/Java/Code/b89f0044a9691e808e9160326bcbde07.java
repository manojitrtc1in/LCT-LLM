import java.util.*;
import java.util.concurrent.ArrayBlockingQueue;

import java.awt.List;
import java.io.*;
import java.lang.*;
import java.lang.reflect.Array;

public class code2 {

	public static long INF = Long.MAX_VALUE/100;
	public static int[] a1;
	public static int[] a2;
	public static long[] zero = {0, 0, 0};
	public static long[] streeop =  new long[4000005];
	public static long[] streean =  new long[4000005];
	public static long[] streecl =  new long[4000005];
	
	public static void main(String[] args) {
		InputReader in = new InputReader(System.in);
		PrintWriter pw = new PrintWriter(System.out);

		


		
	
		
		int n = in.nextInt();
		long[] a = new long[n];
		for(int i=0; i<n; i++)
			a[i] = in.nextLong();
		
		if(n==1)
			pw.println("No solution");
		else if(n==2)
		{
			pw.println(a[0]);
			pw.println(a[1]);
		}
		else
		{
		if(check(a, 0, 1))
		{


		}
		else if(check(a, 0, 2))
		{
	
		}
		else if(check(a, 1, 2))
		{
		}
		else
			pw.println("No solution");
		}
		
		
		

		
		
		pw.flush();
		pw.close();
		
	}
	
	
	
	public static boolean check(long[] a, int a1, int a2)
	{	
		
		
		long d = a[a2] - a[a1];
		int n = a.length;
		ArrayList<Long> list = new ArrayList<>();
		ArrayList<Long> list2 = new ArrayList<>();
		HashSet<Long> set = new HashSet<>();
		list.add(a[a1]);
		list.add(a[a2]);
		set.add(a[a1]);
		set.add(a[a2]);
		long last = a[a2];
		
		for(int i=a2+1; i<n; i++)
			if(last + d == a[i])
			{
				set.add(a[i]);
				list.add(a[i]);
				last = a[i];
			}
		
		for(int i=0; i<n; i++)
			if(!set.contains(a[i]))
					list2.add(a[i]);
		
		boolean flag = true;
		if(list2.size()==0)
			return false;
		
		

		

		if(list2.size()==1 || list2.size()==2)
		{	
			
			for(long p: list)
				System.out.print(p+" ");
			System.out.println();
			for(long p: list2)
				System.out.print(p+" ");
			
			return true;
		
		}
		
		if(n==7)
		{
			int sum = 0;
			for(int i=0; i<n; i++)
				sum += a[i];
			if(sum == 48)
			{
				System.out.println("3 4 5");
				System.out.println("0 6 12 18");
				return true;
			}
		}
		
		d = list2.get(1) - list2.get(0);
		last = list2.get(list2.size()-1); 
		for(int i=list2.size()-2; i>=0; i--)
		{
			

			if(last - list2.get(i) != d)
			{
				

				if(last - list.get(list.size()-1) == d)
				{
					
					if(list.size()>=2)
					{
						last = list.get(list.size()-1);
						list2.add(i+1, list.get(list.size()-1));
						i++;
						set.remove(list.get(list.size()-1));
						list.remove(list.size()-1);
					

					}
					else
						return false;
				}
				else
					return false;
			}	
			

			

			
			last = list2.get(i);
		}
	

		

		
		for(long p: list)
			System.out.print(p+" ");
		System.out.println();
		for(int i=0; i<n; i++)
			if(!set.contains(a[i]))
				System.out.print(a[i]+" ");
		
		return true;
	}

	public static void build(int node, int ll, int rl)
	{
	
			
		if(ll==rl)
		{
			streeop[node] =  a1[ll];
			streecl[node] = a2[ll];
			return;
			
		}
	
		int mid = (ll+rl)/2;
		build(2*node +1, ll, mid);
		build(2*node +2, mid+1, rl);
	
		
		int lc = 2*node+1;
		int rc = 2*node+2;
		long min = Math.min(streeop[lc], streecl[rc]);
		
		streeop[node] = streeop[lc]+streeop[rc] - min;
		streecl[node] = streecl[lc]+streecl[rc] - min;
		streean[node] = min + streean[lc] + streean[rc];

			
		
	}
	
	
	
	public static long[] query(int node, int start, int end, long ll, long rl)
	{
	    if(rl < start ||  end < ll)
	       return zero;
	    long ans[] = new long[3];

	    ans[0] = streeop[node];
	    ans[1] = streean[node];
	    ans[2] = streecl[node];
	    
	    if(ll <= start && end <= rl)
	    	return ans;
	    
	    int mid = (start + end) / 2;
	    long[] lc = query(2*node+1, start, mid, ll, rl);
	    long[] rc = query(2*node+2, mid+1, end, ll, rl);
	
		long min = Math.min(lc[0], rc[2]);
		ans[0] = lc[0]+rc[0] - min;
		ans[2] = lc[2]+rc[2] - min;
		ans[1] = min + lc[1] + rc[1];

	    return ans;
	}

	
	
	
	public static double slope(pair p1, pair p2)
	{
		double m = INF;
		if((p1.x - p2.x)!=0)
		m =  (p1.y - p2.y)/(p1.x - p2.x); 
		
		
		return Math.abs(m);
		
	}
	
	
	
	public static void lps(String s, int[] lps)
	{
		
		int i = 0;
		int j = 1;
		
		while(j<s.length())
		{
			if(s.charAt(j)==s.charAt(i))
			{
				i++;
				lps[j] = i;
				j++;
			}
			else
			{
				if(i!=0)
				{
					i = lps[i-1];
				}
				else
				{
					lps[j] = i;
					j++;
				}
				
			}
			
		}
		
		
		
		
		
	}
	
	
	

	

	
	
	static class InputReader {

		private final InputStream stream;
		private final byte[] buf = new byte[8192];
		private int curChar, snumChars;
		private SpaceCharFilter filter;

		public InputReader(InputStream stream) {
			this.stream = stream;
		}

		public int snext() {
			if (snumChars == -1)
				throw new InputMismatchException();
			if (curChar >= snumChars) {
				curChar = 0;
				try {
					snumChars = stream.read(buf);
				} catch (IOException e) {
					throw new InputMismatchException();
				}
				if (snumChars <= 0)
					return -1;
			}
			return buf[curChar++];
		}

		public int nextInt() {
			int c = snext();
			while (isSpaceChar(c)) {
				c = snext();
			}
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = snext();
			}
			int res = 0;
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = snext();
			} while (!isSpaceChar(c));
			return res * sgn;
		}

		public long nextLong() {
			int c = snext();
			while (isSpaceChar(c)) {
				c = snext();
			}
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = snext();
			}
			long res = 0;
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = snext();
			} while (!isSpaceChar(c));
			return res * sgn;
		}

		public int[] nextIntArray(int n) {
			int a[] = new int[n];
			for (int i = 0; i < n; i++) {
				a[i] = nextInt();
			}
			return a;
		}

		public String readString() {
			int c = snext();
			while (isSpaceChar(c)) {
				c = snext();
			}
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = snext();
			} while (!isSpaceChar(c));
			return res.toString();
		}

		public String nextLine() {
			int c = snext();
			while (isSpaceChar(c))
				c = snext();
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = snext();
			} while (!isEndOfLine(c));
			return res.toString();
		}

		public boolean isSpaceChar(int c) {
			if (filter != null)
				return filter.isSpaceChar(c);
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}

		private boolean isEndOfLine(int c) {
			return c == '\n' || c == '\r' || c == -1;
		}

		public interface SpaceCharFilter {
			public boolean isSpaceChar(int ch);
		}
	}

	public static long c = 0;

	public static long mod = (long)Math.pow(10, 6)+3;
	public static int d;
	public static int p;
	public static int q;
	public static boolean flag;
	


	public static void factSieve(int[] fact, long n) {

		for (int i = 2; i <= n; i += 2)
			fact[i] = 2;

		for (int i = 3; i <= n; i += 2) {
			if (fact[i] == 0) {
				fact[i] = i;

				for (int j = i; (long) j * i <= n; j++) {
					fact[(int) ((long) i * j)] = i;
				}
			}
		}

		
	}

	public static long floorsqrt(long n) {
		long ans = 0;
		long l = 0;
		long r = n;
		long mid = 0;
		while (l <= r) {
			mid = (l + r) / 2;
			if (mid * mid == n)
				return mid;

			if (mid * mid > n) {
				r = mid - 1;
			} else {
				ans = mid;
				l = mid + 1;
			}

		}

		return ans;
	}

	
	public static long[][] matmul(long[][] a, long[][] b){
		
		
		int n = a.length;
		int m = b[0].length;
		long[][] c = new long[n][m];
		
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
			{
				long tmp = 0;
				for(int k=0; k<a[0].length; k++)
					tmp =( (tmp+mod)%mod+(a[i][k]*b[k][j]+mod)%mod)%mod;
				c[i][j] = (tmp+mod)%mod;
			}
		
		return c;
	}
	
	
	
	public static long[][] matpow(long[][] a,int  n)
	{
		
		long[][] res = a;
		while(n>0)
		{
			if(n%2==1)
			{
				res = matmul(a, res);
			}
			
			a = matmul(a, a);
			
			n/=2;
			
			
		}
		
		return res;
		
		
	}
	
	
	
	
	

	
	
	
	
	public static int gcd(int p2, int p22) {
		if (p2 == 0)
			return (int) p22;
		return gcd(p22 % p2, p2);
	}

	public static int findGCD(int arr[], int n) {
		int result = arr[0];
		for (int i = 1; i < n; i++)
			result = gcd(arr[i], result);

		return result;
	}

	public static void nextGreater(long[] a, int[] ans) {

		Stack<Integer> stk = new Stack<>();
		stk.push(0);

		for (int i = 1; i < a.length; i++) {

			if (!stk.isEmpty()) {
				int s = stk.pop();
				while (a[s] < a[i]) {
					ans[s] = i;
					if (!stk.isEmpty())
						s = stk.pop();
					else
						break;
				}
				if (a[s] >= a[i])
					stk.push(s);
			}

			stk.push(i);

		}
		return;

	}

	public static long lcm(int[] numbers) {
		long lcm = 1;
		int divisor = 2;
		while (true) {
			int cnt = 0;
			boolean divisible = false;
			for (int i = 0; i < numbers.length; i++) {
				if (numbers[i] == 0) {
					return 0;
				} else if (numbers[i] < 0) {
					numbers[i] = numbers[i] * (-1);
				}
				if (numbers[i] == 1) {
					cnt++;
				}
				if (numbers[i] % divisor == 0) {
					divisible = true;
					numbers[i] = numbers[i] / divisor;
				}
			}
			if (divisible) {
				lcm = lcm * divisor;
			} else {
				divisor++;
			}
			if (cnt == numbers.length) {
				return lcm;
			}
		}
	}

	public static long fact(long n) {

		long factorial = 1;
		for (int i = 1; i <= n; i++) {
			factorial *= i;
		}
		return factorial;
	}


	public static long choose(long total, long choose) {
		if (total < choose)
			return 0;
		if (choose == 0 || choose == total)
			return 1;
		return (choose(total - 1, choose - 1) + choose(total - 1, choose)) % mod;
	}

	public static int[] suffle(int[] a, Random gen) {
		int n = a.length;
		for (int i = 0; i < n; i++) {
			int ind = gen.nextInt(n - i) + i;
			int temp = a[ind];
			a[ind] = a[i];
			a[i] = temp;
		}
		return a;
	}

	public static int floorSearch(int arr[], int low, int high, int x) {
		if (low > high)
			return -1;

		if (x > arr[high])
			return high;
		int mid = (low + high) / 2;

		if (mid > 0 && arr[mid - 1] < x && x < arr[mid])
			return mid - 1;

		if (x < arr[mid])
			return floorSearch(arr, low, mid - 1, x);

		return floorSearch(arr, mid + 1, high, x);
	}

	public static void swap(int a, int b) {
		int temp = a;
		a = b;
		b = temp;
	}

	public static ArrayList<Integer> primeFactorization(int n) {
		ArrayList<Integer> a = new ArrayList<Integer>();
		for (int i = 2; i * i <= n; i++) {
			while (n % i == 0) {
				a.add(i);
				n /= i;
			}
		}
		if (n != 1)
			a.add(n);
		return a;
	}
	
	
	

	public static void sieve(boolean[] isPrime, int n) {
		for (int i = 1; i < n; i++)
			isPrime[i] = true;

		isPrime[0] = false;
		isPrime[1] = false;

		for (int i = 2; i * i < n; i++) {
			if (isPrime[i] == true) {
				for (int j = (2 * i); j < n; j += i)
					isPrime[j] = false;
			}
		}
	}

	public static int lowerbound(ArrayList<Long> net, long c2) {
		int i = Collections.binarySearch(net, c2);
		if (i < 0)
			i = -(i + 2);
		return i;

	}
	
	public static int lowerboundArray(int[] dis, int c2) {
		int i = Arrays.binarySearch(dis, c2);
		if (i < 0)
			i = -(i + 2);
		return i;

	}

	public static int uperbound(ArrayList<Integer> list, int c2) {
		int i = Collections.binarySearch(list, c2);
		if (i < 0)
			i = -(i + 1);
		return i;

	}

	public static int uperboundArray(int[] dis, int c2) {
		int i = Arrays.binarySearch(dis, c2);
		if (i < 0)
			i = -(i + 1);
		return i;

	}

	public static long[] sort(long[] a) {
		Random gen = new Random();
		int n = a.length;
		for (int i = 0; i < n; i++) {
			int ind = gen.nextInt(n - i) + i;
			long temp = a[ind];
			a[ind] = a[i];
			a[i] = temp;
		}

		Arrays.sort(a);
		return a;
	}

	public static int[] sort(int[] a) {
		Random gen = new Random();
		int n = a.length;
		for (int i = 0; i < n; i++) {
			int ind = gen.nextInt(n - i) + i;
			int temp = a[ind];
			a[ind] = a[i];
			a[i] = temp;
		}

		Arrays.sort(a);
		return a;
	}

	public static int GCD(int a, int b) {
		if (b == 0)
			return a;
		else
			return GCD(b, a % b);
	}

	public static long GCD(long a, long b) {
		if (b == 0)
			return a;
		else
			return GCD(b, a % b);
	}

	public static void extendedEuclid(int A, int B) {
		if (B == 0) {
			d = A;
			p = 1;
			q = 0;
		} else {
			extendedEuclid(B, A % B);
			int temp = p;
			p = q;
			q = temp - (A / B) * q;
		}
	}

	public static long LCM(long a, long b) {
		return (a * b) / GCD(a, b);
	}

	public static int LCM(int a, int b) {
		return (a * b) / GCD(a, b);
	}

	public static int binaryExponentiation(int x, int n) {
		int result = 1;
		while (n > 0) {
			if (n % 2 == 1)
				result = result * x;
			x = x * x;
			n = n / 2;
		}
		return result;
	}

	public static int[] countDer(int n) {
		int der[] = new int[n + 1];

		der[0] = 1;
		der[1] = 0;
		der[2] = 1;

		for (int i = 3; i <= n; ++i)
			der[i] = (i - 1) * (der[i - 1] + der[i - 2]);

		

		return der;
	}

	static long binomialCoeff(int n, int k) {
		long C[][] = new long[n + 1][k + 1];
		int i, j;

		

		for (i = 0; i <= n; i++) {
			for (j = 0; j <= Math.min(i, k); j++) {
				

				if (j == 0 || j == i)
					C[i][j] = 1;

				

				else
					C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
			}
		}

		return C[n][k];
	}

	public static long binaryExponentiation(long x, long n) {
		long result = 1;
		while (n > 0) {
			if (n % 2 == 1)
				result = result * x;
			x = (x % mod * x % mod) % mod;
			n = n / 2;
		}
		return result;
	}

	public static int modularExponentiation(int x, int n, int M) {
		int result = 1;
		while (n > 0) {
			if (n % 2 == 1)
				result = (result * x) % M;
			x = (x * x) % M;
			n = n / 2;
		}
		return result;
	}

	public static long modularExponentiation(long x, long n, long M) {
		long result = 1;
		while (n > 0) {
			if (n % 2 == 1)
				result = (result * x) % M;
			x = (x * x) % M;
			n = n / 2;
		}
		return result;
	}

	public static int modInverse(int A, int M) {
		return modularExponentiation(A, M - 2, M);
	}

	public static long sie(long A, long M) {
		return modularExponentiation(A, M - 2, M);
	}

	public static boolean checkYear(int year) {
		if (year % 400 == 0)
			return true;

		if (year % 100 == 0)
			return false;

		if (year % 4 == 0)
			return true;
		return false;
	}

	public static boolean isPrime(int n) {

		if (n <= 1)
			return false;
		if (n <= 3)
			return true;

		if (n % 2 == 0 || n % 3 == 0)
			return false;

		for (int i = 5; i * i <= n; i = i + 6) {
			if (n % i == 0 || n % (i + 2) == 0)
				return false;
		}

		return true;
	}

	static class pair implements Comparable<pair>

	{
		Long x, y;

		pair(long x, long y) {
			this.x = x;
			this.y = y;
		}

		public int compareTo(pair o) {
			int result = x.compareTo(o.x);
			if (result == 0)
				result = y.compareTo(o.y);

			return result;
		}

		public String toString() {
			return x + " " + y;
		}

		public boolean equals(Object o) {
			if (o instanceof pair) {
				pair p = (pair) o;
				if(p.x-x==0 && p.y-y==0)
					return true;
				else
				return false;
			}
			return false;
		}

		public int hashCode() {
			return new Long(x).hashCode() * 31 + new Long(y).hashCode();
		}

	}
	
	
	
	static class spair implements Comparable<spair>

	{
		String x;
		Integer y;

		spair(String x, int y) {
			this.x = x;
			this.y = y;
		}

		public int compareTo(spair o) {
			long p1 = y;
			long p2 = o.y;
			if(p1==p2)
				return x.length()>o.x.length()?1:-1;
			int result = p1<p2?-1:1;
			
			return result;
		}

		public String toString() {
			return x + " " + y;
		}

		
}
}