import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.NoSuchElementException;
import java.util.Random;
import java.util.Stack;
import java.util.StringTokenizer;
import java.util.TreeMap;
import java.util.TreeSet;



public final class CFPS {
	static FastReader fr = new FastReader();
	static PrintWriter out = new PrintWriter(System.out);
	static final int id25 = 1000000007;
	static int t = 1;
	static double epsilon = 0.00000001;
	
	public static void main(String[] args) {
		t = fr.nextInt();
		OUTER: 
		for (int tc = 0; tc < t; tc++) {
			
			int n = fr.nextInt();
			int[] arr = fr.id12(n);
			
			

			
			

			
			

			
			

			

			

			
			

			

			

			

			

			

			

			

			

			
			

			
			Stack<Integer>[] list = (Stack<Integer>[]) new Stack[n];
			for (int i = 0; i < n; i++)
				list[i] = new Stack<>();
			
			list[0].push(arr[0]);
			for (int i = 1; i < n; i++) {
				
				int newNum = arr[i];
				
				if (newNum == 1) {
					for (int elem : list[i - 1])
						list[i].push(elem);
					list[i].push(1);
				} else {
					
					int oldNum = list[i - 1].peek();
					
					if (newNum == oldNum + 1) {
						for (int elem : list[i - 1])
							list[i].push(elem);
						list[i].pop();
						list[i].push(newNum);
					} else {
						
						

						

						

						

						

						Stack<Integer> lastStack = new Stack<>();
						for (int elem : list[i-1])
							lastStack.add(elem);
						
						WHILE: 
						while (lastStack.peek() != newNum - 1)
							lastStack.pop();
						
						for (int elem : lastStack)
							list[i].push(elem);
						list[i].pop();
						list[i].push(newNum);
					}
				}
			}
			
			

			for (int i = 0; i < n; i++) {
				
				int size = list[i].size();
				out.print(list[i].get(0));
				
				for (int j = 1; j < size; j++)
					out.print("." + list[i].get(j));
				
				out.println();
			}
		}
		out.close();
	}
	
	static String reverse(String s) {
		
		StringBuilder sb = new StringBuilder();
		int n = s.length();
		
		for (int i = n - 1; i > -1; i--) {
			sb.append(s.charAt(i));
		}
		
		return sb.toString();
	}
	
	static long power(long x, int y)
	  {
		

		

	    long res = 1; 

	 
	    x = x; 

	    

	 
	    if (x == 0)
	      return 0; 

	 
	    while (y > 0)
	    {
	 
	      

	      if ((y & 1) != 0)
	        res = (res * x);
	 
	      

	      y = y >> 1; 

	      x = (x * x);
	    }
	    return res;
	  }
	
	

	

	static int id31(int row, int col, int n, int m) {
		return row * m + col;
	}
	
	

	static int[] id6(int idx, int n, int m) {
		int[] rnc = new int[2];
		rnc[0] = idx / m;
		rnc[1] = idx % m;
		return rnc;
	}
	
	

	static boolean id30(String s, String t) {
		char[] schars = s.toCharArray();
		char[] tchars = t.toCharArray();
		int slen = schars.length, tlen = tchars.length;
		int tctr = 0;
		
		if (slen < tlen) return false;
		
		for (int i = 0; i < slen || i < tlen; i++) {
			if (tctr == tlen) break;
			if (schars[i] == tchars[tctr]) {
				tctr++;
			}
		}
		
		if (tctr == tlen) return true;
		return false;
	}
	
	

	static String id9(long num, int bits) {
		StringBuilder sb = new StringBuilder(Long.id9(num));
		sb.reverse();
		for (int i = sb.length(); i < bits; i++)
			sb.append('0');
		return sb.reverse().toString();
	}
	
	static class CountMap extends TreeMap<Long, Integer>{
		
		CountMap() {
		}
		
		CountMap(CountMap cm) {
			
		}
		
		public void removeTM(Long key) {
			super.remove(key);
		}
		
		public void removeTM(Integer key) {
			super.remove((long) key);
		}
		
		public Integer put(Long key) {
			if (super.containsKey(key)) {
				return super.put(key, super.get(key) + 1);
			} else {
				return super.put(key, 1);
			}
		}
		
		public Integer put(int key) {
			if (super.containsKey((long) key)) {
				return super.put((long) key, super.get((long) key) + 1);
			} else {
				return super.put((long) key, 1);
			}
		}
		
		public Integer remove(Long key) {
			Integer count = super.get(key);
			if (count == null) return -1;
			if (count == 1)
				return super.remove(key);
			else
				return super.put(key, super.get(key) - 1);
		}
		
		public Integer remove(int key) {
			Integer count = super.get((long) key);
			if (count == null) return -1;
			if (count == 1)
				return super.remove((long) key);
			else
				return super.put((long) key, super.get((long) key) - 1);
		}
		
		public Integer get(int key) {
			Integer count = super.get((long) key);
			if (count == null)
				return 0;
			return count;
		}
		
		public Integer get(long key) {
			Integer count = super.get(key);
			if (count == null)
				return 0;
			return count;
		}
	}
	
	static class Point implements Comparable<Point> {
		long x;
		long y;
		int id;
		
		Point() {
			x = y = id = 0;
		}
		
		Point(Point p) {
			this.x = p.x;
			this.y = p.y;
			this.id = p.id;
		}
		
		Point(long a, long b, int id) {
			this.x = a;
			this.y = b;
			this.id = id;
		}
		
		Point(long a, long b) {
			this.x = a;
			this.y = b;
		}
		
		@Override
		public int compareTo(Point o) {
			if (this.x > o.x)
				return 1;
			if (this.x < o.x)
				return -1;
			if (this.y > o.y)
				return 1;
			if (this.y < o.y)
				return -1;
			return 0;
		}
		
		public boolean equals(Point that) {
			return this.compareTo(that) == 0;
		}
	}
	
	static class PointComparator implements Comparator<Point> {
		@Override
		public int compare(Point o1, Point o2) {
			
			

			
			long amb1 = o1.x - o1.y;
			long amb2 = o2.x - o2.y;
			
			

			if (amb1 > amb2) 
				return -1;
			
			if (amb2 > amb1)
				return 1;
			
			return 0;
		}
	}
	
	

	static int id18(long n, long k) {
		int lo = 0, hi = logk(Long.MAX_VALUE, 3);
		int largestPower = -1;
		while (lo <= hi) {
			int mid = lo + (hi - lo)/2;
			
			long val = (long) Math.pow(k, mid);
			if (val <= n) {
				largestPower = mid;
				lo = mid + 1;
			} else {
				hi = mid - 1;
			}
		}
		return largestPower;
	}
	
	static String id14(int set) {
		

		

		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < 30; i++) {
			if (((set >> i) & 1) == 1) {
				

				

				sb.append((i + 1) + " ");
			}
		}
		sb.append("\n");
		return sb.toString();
	}
	
	static String id19(long set) {
		

		

		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < 60; i++) {
			if (((set >> i) & 1) == 1) {
				

				

				sb.append((i + 1) + " ");
			}
		}
		sb.append("\n");
		return sb.toString();
	}
	
	static int id7(int set, int element) {
		set = (set) | (1 << (element - 1));
		return set;
	}
	
	static int id11(int set, int element) {
		

		if ((set & (1 << (element - 1))) == 0) return set;
		set = set ^ (1 << (element - 1));
		return set;
	}
	
	

	static TreeMap<Long, Integer> id8(long num) {
		TreeMap<Long, Integer> map = new TreeMap<>();
		while (num % 2 == 0) {
			num /= 2;
			Integer id3 = map.get(2L);
			map.put(2L, id3 != null ? id3 + 1 : 1);
		}
		
		for (long i = 3; i * i <= num; i += 2) {
			while (num % i == 0) {
				num /= i;
				Integer id3 = map.get(i);
				map.put(i, id3 != null ? id3 + 1 : 1);
			}
		}
		
		

		

		if (num != 1)
			map.put(num, 1);
		
		return map;
	}
	
	

	static TreeMap<Integer, Integer> id8(int num) {
		TreeMap<Integer, Integer> map = new TreeMap<>();
		while (num % 2 == 0) {
			num /= 2;
			Integer id3 = map.get(2);
			map.put(2, id3 != null ? id3 + 1 : 1);
		}
		
		for (int i = 3; i * i <= num; i += 2) {
			while (num % i == 0) {
				num /= i;
				Integer id3 = map.get(i);
				map.put(i, id3 != null ? id3 + 1 : 1);
			}
		}
		
		

		

		if (num != 1)
			map.put(num, 1);
		
		return map;
	}
	
	static TreeSet<Long> id0(long num) {
		TreeSet<Long> id0 = new TreeSet<Long>();
		id0.add(1L);
		id0.add(num);
		
		for (long i = 2; i * i <= num; i++) {
			if (num % i == 0) {
				id0.add(num/i);
				id0.add(i);
			}
		}
		return id0;
	}
	
	static void dfs(int node, boolean[] marked, ArrayList<Integer>[] adj) {
		if (marked[node]) return;

		marked[node] = true;
		for (int adjc : adj[node])
			dfs(adjc, marked, adj);
	}
	
	

	

	static int bsearch(int[] arr, int val, int lo, int hi) {
		int idx = -1;
		while (lo <= hi) {
			int mid = lo + (hi - lo)/2;
			if (arr[mid] >= val) {
				idx = mid;
				hi = mid - 1;
			} else
				lo = mid + 1;
		}
		return idx;
	}
	
	static int bsearch(long[] arr, long val, int lo, int hi) {
		int idx = -1;
		while (lo <= hi) {
			int mid = lo + (hi - lo)/2;
			if (arr[mid] >= val) {
				idx = mid;
				hi = mid - 1;
			} else
				lo = mid + 1;
		}
		return idx;
	}
	
	

	

	static int bsearch(long[] arr, long val, int lo, int hi, boolean sMode) {
		int idx = -1;
		while (lo <= hi) {
			int mid = lo + (hi - lo)/2;
			if (arr[mid] > val) {
				hi = mid - 1;
			} else {
				idx = mid;
				lo = mid + 1;
			}
		}
		return idx;
	}
	
	static int bsearch(int[] arr, long val, int lo, int hi, boolean sMode) {
		int idx = -1;
		while (lo <= hi) {
			int mid = lo + (hi - lo)/2;
			if (arr[mid] > val) {
				hi = mid - 1;
			} else {
				idx = mid;
				lo = mid + 1;
			}
		}
		return idx;
	}
	
	static long factorial(long n) {
		if (n <= 1)
			return 1;
		long factorial = 1;
		for (int i = 1; i <= n; i++)
			factorial = mod(factorial * i);
		return factorial;
	}
	
	static long id22(long a, long b) {
		if (a == b)
			return 1;
		if (b < a) {
			long temp = a;
			a = b;
			b = temp;
		}
		
		long factorial = 1;
		for (long i = a + 1; i <= b; i++)
			factorial = mod(factorial * i);
		return factorial;
	}
	
	static BigInteger id22(BigInteger a, BigInteger b) {
		if (a.equals(b))
			return BigInteger.ONE;
		return a.multiply(id22(a.subtract(BigInteger.ONE), b));
	}
	
	static long nCr(long n, long r) {
		long p = id25;
	    

	    if (r == 0)
	        return 1;
	 
	    

	    

	    

	    long fac[] = new long[(int)n + 1];
	    fac[0] = 1;
	    for (int i = 1; i <= n; i++)
	        fac[i] = fac[i - 1] * i % p;
	 
	    return (fac[(int)n] * modInverse(fac[(int)r], p) % p
	                    * modInverse(fac[(int)n - (int)r], p) % p) % p;
	}
	
	static long modInverse(long n, long p) {
	    return power(n, p - 2, p);
	}
	
	static long power(long x, long y, long p) {
	    long res = 1; 

	 
	    x = x % p; 

	    

	 
	    while (y > 0) {
	        

	        if ((y & 1)==1)
	            res = (res * x) % p;
	 
	        

	        y = y >> 1; 

	        x = (x * x) % p;
	    }
	    return res;
	}
	
	static long nPr(long n, long r) {
		return id22(n, n - r);
	}
	
	static int log2(long n) {
		return (int)(Math.log(n) / Math.log(2));
	}
	
	static double log2(long n, boolean doubleMode) {
		return (Math.log(n) / Math.log(2));
	}
	
	static int logk(long n, long k) {
		return (int)(Math.log(n) / Math.log(k));
	}
	
	

	static boolean[] primeGenerator(int upto) {
		boolean[] isPrime = new boolean[upto + 1];
		Arrays.fill(isPrime, true);
		isPrime[1] = isPrime[0] = false;

		for (long i = 2; i * i < upto + 1; i++)
			if (isPrime[(int) i])
				

				

				for (long j = i; j * i < upto + 1; j++)
					isPrime[(int) j * (int) i] = false;
		return isPrime;
	}

	static int gcd(int a, int b) {
		if (b == 0) {
			return a;
		} else {
			return gcd(b, a % b);
		}
	}
	
	static long gcd(long a, long b) {
		if (b == 0) {
			return a;
		} else {
			return gcd(b, a % b);
		}
	}
	
	static int gcd(int[] arr) {
		int n = arr.length;
		int gcd = arr[0];
		for (int i = 1; i < n; i++) {
			gcd = gcd(gcd, arr[i]);
		}
		return gcd;
	}
	
	static long gcd(long[] arr) {
		int n = arr.length;
		long gcd = arr[0];
		for (int i = 1; i < n; i++) {
			gcd = gcd(gcd, arr[i]);
		}
		return gcd;
	}
	
	static long lcm(int[] arr) {
		long lcm = arr[0];
		int n = arr.length;
		for (int i = 1; i < n; i++) {
			lcm = (lcm * arr[i]) / gcd(lcm, arr[i]);
		}
		return lcm;
	}
	
	static long lcm(long[] arr) {
		long lcm = arr[0];
		int n = arr.length;
		for (int i = 1; i < n; i++) {
			lcm = (lcm * arr[i]) / gcd(lcm, arr[i]);
		}
		return lcm;
	}
	
	static long lcm(int a, int b) {
		return (a * b)/gcd(a, b);
	}
	
	static long lcm(long a, long b) {
		return (a * b)/gcd(a, b);
	}
	
	static boolean less(int a, int b) {
		return a < b ? true : false;
	}
	
	static boolean isSorted(int[] a) {
		for (int i = 1; i < a.length; i++) {
			if (less(a[i], a[i - 1]))
				return false;
		}
		return true;
	}
	
	static boolean isSorted(long[] a) {
		for (int i = 1; i < a.length; i++) {
			if (a[i] < a[i - 1])
				return false;
		}
		return true;
	}

	static void swap(int[] a, int i, int j) {
		int temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}
	
	static void swap(long[] a, int i, int j) {
		long temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}
	
	static void swap(double[] a, int i, int j) {
		double temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}
	
	static void swap(char[] a, int i, int j) {
		char temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}
	
	static void sort(int[] arr) {
		shuffleArray(arr, 0, arr.length - 1);
		Arrays.sort(arr);
	}
	
	static void sort(char[] arr) {
		shuffleArray(arr, 0, arr.length - 1);
		Arrays.sort(arr);
	}
	
	static void sort(long[] arr) {
		shuffleArray(arr, 0, arr.length - 1);
		Arrays.sort(arr);
	}
	
	static void sort(double[] arr) {
		shuffleArray(arr, 0, arr.length - 1);
		Arrays.sort(arr);
	}
	
	static void reverseSort(int[] arr) {
		shuffleArray(arr, 0, arr.length - 1);
		Arrays.sort(arr);
		int n = arr.length;
		for (int i = 0; i < n/2; i++)
			swap(arr, i, n - 1 - i);
	}
	
	static void reverseSort(char[] arr) {
		shuffleArray(arr, 0, arr.length - 1);
		Arrays.sort(arr);
		int n = arr.length;
		for (int i = 0; i < n/2; i++)
			swap(arr, i, n - 1 - i);
	}
	
	static void reverseSort(long[] arr) {
		shuffleArray(arr, 0, arr.length - 1);
		Arrays.sort(arr);
		int n = arr.length;
		for (int i = 0; i < n/2; i++)
			swap(arr, i, n - 1 - i);
	}
	
	static void reverseSort(double[] arr) {
		shuffleArray(arr, 0, arr.length - 1);
		Arrays.sort(arr);
		int n = arr.length;
		for (int i = 0; i < n/2; i++)
			swap(arr, i, n - 1 - i);
	}
	
	static void shuffleArray(long[] arr, int startPos, int endPos) {
		Random rnd = new Random();
		for (int i = startPos; i < endPos; ++i) {
			long tmp = arr[i];
			int randomPos = i + rnd.nextInt(endPos - i);
			arr[i] = arr[randomPos];
			arr[randomPos] = tmp;
		}
	}
	
	static void shuffleArray(int[] arr, int startPos, int endPos) {
		Random rnd = new Random();
		for (int i = startPos; i < endPos; ++i) {
			int tmp = arr[i];
			int randomPos = i + rnd.nextInt(endPos - i);
			arr[i] = arr[randomPos];
			arr[randomPos] = tmp;
		}
	}
	
	static void shuffleArray(double[] arr, int startPos, int endPos) {
		Random rnd = new Random();
		for (int i = startPos; i < endPos; ++i) {
			double tmp = arr[i];
			int randomPos = i + rnd.nextInt(endPos - i);
			arr[i] = arr[randomPos];
			arr[randomPos] = tmp;
		}
	}
	
	private static void shuffleArray(char[] arr, int startPos, int endPos) {
		Random rnd = new Random();
		for (int i = startPos; i < endPos; ++i) {
			char tmp = arr[i];
			int randomPos = i + rnd.nextInt(endPos - i);
			arr[i] = arr[randomPos];
			arr[randomPos] = tmp;
		}
	}
	
	static boolean isPrime(long n) {
		if (n <= 1)
			return false;
		if (n <= 3)
			return true;

		if (n % 2 == 0 || n % 3 == 0)
			return false;

		for (long i = 5; i * i <= n; i = i + 6)
			if (n % i == 0 || n % (i + 2) == 0)
				return false;

		return true;
	}

	static String toString(int[] dp) {
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < dp.length; i++)
			sb.append(dp[i] + " ");
		return sb.toString();
	}
	
	static String toString(boolean[] dp) {
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < dp.length; i++)
			sb.append(dp[i] + " ");
		return sb.toString();
	}
	
	static String toString(long[] dp) {
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < dp.length; i++)
			sb.append(dp[i] + " ");
		return sb.toString();
	}
	
	static String toString(char[] dp) {
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < dp.length; i++)
			sb.append(dp[i] + "");
		return sb.toString();
	}
	
	static String toString(int[][] dp) {
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < dp.length; i++) {
			for (int j = 0; j < dp[i].length; j++) {
				sb.append(dp[i][j] + "");
			}
			sb.append('\n');
		}
		return sb.toString();
	}
	
	static String toString(long[][] dp) {
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < dp.length; i++) {
			for (int j = 0; j < dp[i].length; j++) {
				sb.append(dp[i][j] + " ");
			}
			sb.append('\n');
		}
		return sb.toString();
	}
	
	static String toString(double[][] dp) {
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < dp.length; i++) {
			for (int j = 0; j < dp[i].length; j++) {
				sb.append(dp[i][j] + " ");
			}
			sb.append('\n');
		}
		return sb.toString();
	}
	
	static String toString(char[][] dp) {
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < dp.length; i++) {
			for (int j = 0; j < dp[i].length; j++) {
				sb.append(dp[i][j] + " ");
			}
			sb.append('\n');
		}
		return sb.toString();
	}
	
	static char toChar(int i) {
		return (char) (i + 48);
	}
	
	static long mod(long a, long m) {
	    return (a%m + m) % m;
	}
	
	static long mod(long num) {
		return (num % id25 + id25) % id25;
	}
	
	

	static class UnionFind {
	    private int[] parent;  

	    private int[] size;    

	                           

	    private int count;     


	    public UnionFind(int n) {
	        count = n;
	        parent = new int[n];
	        size = new int[n];
	        for (int i = 0; i < n; i++) {
	            parent[i] = i;
	            size[i] = 1;
	        }
	    }

	    

	    public int count() {
	        return count;
	    }
	  
	    

	    public int find(int p) {
	        int root = p;
	        while (root != parent[root])
	            root = parent[root];
	        while (p != root) {
	            int newp = parent[p];
	            parent[p] = root;
	            p = newp;
	        }
	        return root;
	    }

	    public boolean connected(int p, int q) {
	        return find(p) == find(q);
	    }
	    
	    public int id10(int node) {
	    	return size[find(node)];
	    }
	    
	    

	    public void union(int p, int q) {
	        int rootP = find(p);
	        int rootQ = find(q);
	        
	        if (rootP == rootQ) return;

	        

	        if (size[rootP] < size[rootQ]) {
	            parent[rootP] = rootQ;
	            size[rootQ] += size[rootP];
	        }
	        else {
	            parent[rootQ] = rootP;
	            size[rootP] += size[rootQ];
	        }
	        count--;
	    }
	    
	    public static int[] connectedComponents(UnionFind uf) {
	    	

	    	
	    	int n = uf.size.length;
	    	int[] id28 = new int[n];
	    	for (int i = 0; i < n; i++)
	    		id28[i] = uf.find(i);
	    	
	    	HashMap<Integer, Integer> id21 = new HashMap<>();
	    	int newCtr = 0;
	    	
	    	for (int i = 0; i < n; i++) {
	    		
	    		int id26 = id28[i];
	    		Integer id5 = id21.get(id26);
	    		if (id5 == null)
	    			id5 = newCtr++;
	    		
	    		id21.put(id26, id5);
	    		id28[i] = id5;
	    	}
	    	
	    	return id28;
	    }
	}
	
	static class UGraph {
		

		private TreeSet<Integer>[] adj;
		private static final String NEWLINE = "\n";
		private int E;
		
		public UGraph(int V) {
			adj = (TreeSet<Integer>[]) new TreeSet[V];
			E = 0;
			for (int i = 0; i < V; i++)
				adj[i] = new TreeSet<Integer>();
		}
		
		public void addEdge(int from, int to) {
			if (adj[from].contains(to)) return;
			E++;
			adj[from].add(to);
			adj[to].add(from);
		}
		
		public TreeSet<Integer> adj(int from) {
			return adj[from];
		}
		
		public int V() {
			return adj.length;
		}
		
		public int E() {
			return E;
		}
		
		public String toString() {
			StringBuilder s = new StringBuilder();
			s.append(V() + " vertices, " + E() + " edges " + NEWLINE);
			for (int v = 0; v < V(); v++) {
				s.append(v + ": ");
				for (int w : adj[v]) {
					s.append(w + " ");
				}
				s.append(NEWLINE);
			}
			return s.toString();
		}
		
		public static void dfsMark(int current, boolean[] marked, UGraph g) {
			if (marked[current]) return;
			
			marked[current] = true;
			Iterable<Integer> adj = g.adj(current);
			for (int adjc : adj)
				dfsMark(adjc, marked, g);
		}
		
		public static void dfsMark(int current, int from, long[] distTo, boolean[] marked, UGraph g, ArrayList<Integer> endPoints) {
			if (marked[current]) return;
			
			marked[current] = true;
			if (from != -1)
				distTo[current] = distTo[from] + 1;
			TreeSet<Integer> adj = g.adj(current);
			int id27 = 0;
			for (int adjc : adj) {
				if (marked[adjc]) id27++;
				dfsMark(adjc, current, distTo, marked, g, endPoints);
			}
			
			if (id27 == adj.size())
				endPoints.add(current);
		}
		
		public static void id2(int current, UGraph g) {
		}
		
		public static void dfsMark(int current, int[] colorIds, int color, UGraph g) {
			if (colorIds[current] != -1) return;
			
			colorIds[current] = color;
			Iterable<Integer> adj = g.adj(current);
			for (int adjc : adj)
				dfsMark(adjc, colorIds, color, g);
		}
		
		public static int[] connectedComponents(UGraph g) {
			int n = g.V();
			int[] componentId = new int[n];
			Arrays.fill(componentId, -1);
			int colorCtr = 0;
			for (int i = 0; i < n; i++) {
				if (componentId[i] != -1) continue;
				dfsMark(i, componentId, colorCtr, g);
				colorCtr++;
			}
			
			return componentId;
		}
		
		public static boolean hasCycle(UGraph ug) {
			int n = ug.V();
			boolean[] marked = new boolean[n];
			boolean[] id24 = new boolean[1];
			for (int i = 0; i < n; i++) {
				if (marked[i]) continue;
				id17(i, ug, marked, id24, -1);
			}
			return id24[0];
		}
		
		

		private static void id17(int current, UGraph ug, boolean[] marked, boolean[] id24, int parent) {
			if (marked[current]) return;
			if (id24[0]) return;
			
			marked[current] = true;
			TreeSet<Integer> adjc = ug.adj(current);
			for (int adj : adjc) {
				if (marked[adj] && adj != parent && parent != -1) {
					id24[0] = true;
					return;
				}
				
				id17(adj, ug, marked, id24, current);
			}
		}
	}
	
	static class Digraph {
		

		private HashSet<Integer>[] adj;
		private static final String NEWLINE = "\n";
		private int E;
		
		public Digraph(int V) {
			adj = (HashSet<Integer>[]) new HashSet[V];
			E = 0;
			for (int i = 0; i < V; i++)
				adj[i] = new HashSet<Integer>();
		}
		
		public void addEdge(int from, int to) {
			if (adj[from].contains(to)) return;
			E++;
			adj[from].add(to);
		}
		
		public HashSet<Integer> adj(int from) {
			return adj[from];
		}
		
		public int V() {
			return adj.length;
		}
		
		public int E() {
			return E;
		}
		
		public String toString() {
			StringBuilder s = new StringBuilder();
			s.append(V() + " vertices, " + E() + " edges " + NEWLINE);
			for (int v = 0; v < V(); v++) {
				s.append(v + ": ");
				for (int w : adj[v]) {
					s.append(w + " ");
				}
				s.append(NEWLINE);
			}
			return s.toString();
		}
		
		public static void dfsMark(int source, boolean[] marked, Digraph g) {
			if (marked[source]) return;
			
			marked[source] = true;
			Iterable<Integer> adj = g.adj(source);
			for (int adjc : adj)
				dfsMark(adjc, marked, g);
		}
		
		public static void id2(int source, Digraph g) {
		}
		
		private static void dfsMark(int source, int[] colorIds, int color, Digraph g) {
			if (colorIds[source] != -1) return;
			
			colorIds[source] = color;
			Iterable<Integer> adj = g.adj(source);
			for (int adjc : adj)
				dfsMark(adjc, colorIds, color, g);
		}
		
		public static int[] connectedComponents(Digraph g) {
			int n = g.V();
			int[] componentId = new int[n];
			Arrays.fill(componentId, -1);
			int colorCtr = 0;
			for (int i = 0; i < n; i++) {
				if (componentId[i] != -1) continue;
				dfsMark(i, componentId, colorCtr, g);
				colorCtr++;
			}
			
			return componentId;
		}
		
		public static Stack<Integer> id13(Digraph dg)
		{
			

			

			

			Stack<Integer> id4 = new Stack<Integer>();
			boolean[] marked = new boolean[dg.V()];
			
			

			for (int i = 0; i < dg.V(); i++)
			{
				if (!marked[i]) id1(dg, id4, marked, i);
			}
			
			return id4;
		}
		
		static void id1(Digraph dg, Stack<Integer> id4, boolean[] marked, int source)
		{
			marked[source] = true;
			for (Integer adjVertex : dg.adj(source))
			{
				if (!marked[adjVertex]) id1(dg, id4, marked, adjVertex);
			}
			id4.add(source);
		}
	}
	
	static class FastReader {
		private BufferedReader bfr;
		private StringTokenizer st;

		public FastReader() {
			bfr = new BufferedReader(new InputStreamReader(System.in));
		}

		String next() {
			if (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(bfr.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}

		char nextChar() {
			return next().toCharArray()[0];
		}

		String nextString() {
			return next();
		}

		int[] id12(int n) {
			int[] arr = new int[n];
			for (int i = 0; i < n; i++)
				arr[i] = nextInt();
			return arr;
		}
		
		int[] id20(int n) {
			int[] arr = new int[n + 1];
			for (int i = 1; i < n; i++)
				arr[i] = nextInt();
			return arr;
		}

		double[] id29(int n) {
			double[] arr = new double[n];
			for (int i = 0; i < arr.length; i++)
				arr[i] = nextDouble();
			return arr;
		}

		long[] id32(int n) {
			long[] arr = new long[n];
			for (int i = 0; i < n; i++)
				arr[i] = nextLong();
			return arr;
		}
		
		
	}
	
	private static class id16<Key extends Comparable<Key>> implements Iterable<Integer> {
	    private int maxN;        

	    private int n;           

	    private int[] pq;        

	    private int[] qp;        

	    private Key[] keys;      


	    public id16(int maxN) {
	        if (maxN < 0) throw new IllegalArgumentException();
	        this.maxN = maxN;
	        n = 0;
	        keys = (Key[]) new Comparable[maxN + 1];    

	        pq   = new int[maxN + 1];
	        qp   = new int[maxN + 1];                   

	        for (int i = 0; i <= maxN; i++)
	            qp[i] = -1;
	    }

	    public boolean isEmpty() {
	        return n == 0;
	    }

	    public boolean contains(int i) {
	        validateIndex(i);
	        return qp[i] != -1;
	    }

	    public int size() {
	        return n;
	    }

	   
	    public void insert(int i, Key key) {
	        validateIndex(i);
	        if (contains(i)) throw new IllegalArgumentException("index is already in the priority queue");
	        n++;
	        qp[i] = n;
	        pq[n] = i;
	        keys[i] = key;
	        swim(n);
	    }

	    
	    public int maxIndex() {
	        if (n == 0) throw new NoSuchElementException("Priority queue underflow");
	        return pq[1];
	    }

	    
	    public Key maxKey() {
	        if (n == 0) throw new NoSuchElementException("Priority queue underflow");
	        return keys[pq[1]];
	    }

	    
	    public int delMax() {
	        if (n == 0) throw new NoSuchElementException("Priority queue underflow");
	        int max = pq[1];
	        exch(1, n--);
	        sink(1);

	        assert pq[n+1] == max;
	        qp[max] = -1;        

	        keys[max] = null;    

	        pq[n+1] = -1;        

	        return max;
	    }

	    
	    public Key keyOf(int i) {
	        validateIndex(i);
	        if (!contains(i)) throw new NoSuchElementException("index is not in the priority queue");
	        else return keys[i];
	    }

	    
	    public void changeKey(int i, Key key) {
	        validateIndex(i);
	        if (!contains(i)) throw new NoSuchElementException("index is not in the priority queue");
	        keys[i] = key;
	        swim(qp[i]);
	        sink(qp[i]);
	    }

	    
	    public void increaseKey(int i, Key key) {
	        validateIndex(i);
	        if (!contains(i)) throw new NoSuchElementException("index is not in the priority queue");
	        if (keys[i].compareTo(key) == 0)
	            throw new IllegalArgumentException("Calling increaseKey() with a key equal to the key in the priority queue");
	        if (keys[i].compareTo(key) > 0)
	            throw new IllegalArgumentException("Calling increaseKey() with a key that is strictly less than the key in the priority queue");

	        keys[i] = key;
	        swim(qp[i]);
	    }

	    
	    public void id15(int i, Key key) {
	        validateIndex(i);
	        if (!contains(i)) throw new NoSuchElementException("index is not in the priority queue");
	        if (keys[i].compareTo(key) == 0)
	            throw new IllegalArgumentException("Calling id15() with a key equal to the key in the priority queue");
	        if (keys[i].compareTo(key) < 0)
	            throw new IllegalArgumentException("Calling id15() with a key that is strictly greater than the key in the priority queue");
	        keys[i] = key;
	        sink(qp[i]);
	    }

	    
	    public void delete(int i) {
	        validateIndex(i);
	        if (!contains(i)) throw new NoSuchElementException("index is not in the priority queue");
	        int index = qp[i];
	        exch(index, n--);
	        swim(index);
	        sink(index);
	        keys[i] = null;
	        qp[i] = -1;
	    }

	    

	    private void validateIndex(int i) {
	        if (i < 0) throw new IllegalArgumentException("index is negative: " + i);
	        if (i >= maxN) throw new IllegalArgumentException("index >= capacity: " + i);
	    }
	    
	    private boolean less(int i, int j) {
	        return keys[pq[i]].compareTo(keys[pq[j]]) < 0;
	    }

	    private void exch(int i, int j) {
	        int swap = pq[i];
	        pq[i] = pq[j];
	        pq[j] = swap;
	        qp[pq[i]] = i;
	        qp[pq[j]] = j;
	    }

	    private void swim(int k) {
	        while (k > 1 && less(k/2, k)) {
	            exch(k, k/2);
	            k = k/2;
	        }
	    }

	    private void sink(int k) {
	        while (2*k <= n) {
	            int j = 2*k;
	            if (j < n && less(j, j+1)) j++;
	            if (!less(k, j)) break;
	            exch(k, j);
	            k = j;
	        }
	    }


	    
	    public Iterator<Integer> iterator() {
	        return new HeapIterator();
	    }

	    private class HeapIterator implements Iterator<Integer> {
	        

	        private id16<Key> copy;

	        

	        

	        public HeapIterator() {
	            copy = new id16<Key>(pq.length - 1);
	            for (int i = 1; i <= n; i++)
	                copy.insert(pq[i], keys[pq[i]]);
	        }

	        public boolean hasNext()  { return !copy.isEmpty();                     }
	        public void remove()      { throw new UnsupportedOperationException();  }

	        public Integer next() {
	            if (!hasNext()) throw new NoSuchElementException();
	            return copy.delMax();
	        }
	    }

	}
	
	public static class id23<Key extends Comparable<Key>> implements Iterable<Integer> {
	    private int maxN;        

	    private int n;           

	    private int[] pq;        

	    private int[] qp;        

	    private Key[] keys;      


	    public id23(int maxN) {
	        if (maxN < 0) throw new IllegalArgumentException();
	        this.maxN = maxN;
	        n = 0;
	        keys = (Key[]) new Comparable[maxN + 1];    

	        pq   = new int[maxN + 1];
	        qp   = new int[maxN + 1];                   

	        for (int i = 0; i <= maxN; i++)
	            qp[i] = -1;
	    }

	    public boolean isEmpty() {
	        return n == 0;
	    }

	    public boolean contains(int i) {
	        validateIndex(i);
	        return qp[i] != -1;
	    }

	    public int size() {
	        return n;
	    }

	    
	    public void insert(int i, Key key) {
	        validateIndex(i);
	        if (contains(i)) throw new IllegalArgumentException("index is already in the priority queue");
	        n++;
	        qp[i] = n;
	        pq[n] = i;
	        keys[i] = key;
	        swim(n);
	    }

	    
	    public int minIndex() {
	        if (n == 0) throw new NoSuchElementException("Priority queue underflow");
	        return pq[1];
	    }

	    
	    public Key minKey() {
	        if (n == 0) throw new NoSuchElementException("Priority queue underflow");
	        return keys[pq[1]];
	    }

	    
	    public int delMin() {
	        if (n == 0) throw new NoSuchElementException("Priority queue underflow");
	        int min = pq[1];
	        exch(1, n--);
	        sink(1);
	        assert min == pq[n+1];
	        qp[min] = -1;        

	        keys[min] = null;    

	        pq[n+1] = -1;        

	        return min;
	    }

	    
	    public Key keyOf(int i) {
	        validateIndex(i);
	        if (!contains(i)) throw new NoSuchElementException("index is not in the priority queue");
	        else return keys[i];
	    }

	    
	    public void changeKey(int i, Key key) {
	        validateIndex(i);
	        if (!contains(i)) throw new NoSuchElementException("index is not in the priority queue");
	        keys[i] = key;
	        swim(qp[i]);
	        sink(qp[i]);
	    }

	    
	    public void id15(int i, Key key) {
	        validateIndex(i);
	        if (!contains(i)) throw new NoSuchElementException("index is not in the priority queue");
	        if (keys[i].compareTo(key) == 0)
	            throw new IllegalArgumentException("Calling id15() with a key equal to the key in the priority queue");
	        if (keys[i].compareTo(key) < 0)
	            throw new IllegalArgumentException("Calling id15() with a key strictly greater than the key in the priority queue");
	        keys[i] = key;
	        swim(qp[i]);
	    }

	    
	    public void increaseKey(int i, Key key) {
	        validateIndex(i);
	        if (!contains(i)) throw new NoSuchElementException("index is not in the priority queue");
	        if (keys[i].compareTo(key) == 0)
	            throw new IllegalArgumentException("Calling increaseKey() with a key equal to the key in the priority queue");
	        if (keys[i].compareTo(key) > 0)
	            throw new IllegalArgumentException("Calling increaseKey() with a key strictly less than the key in the priority queue");
	        keys[i] = key;
	        sink(qp[i]);
	    }

	    
	    public void delete(int i) {
	        validateIndex(i);
	        if (!contains(i)) throw new NoSuchElementException("index is not in the priority queue");
	        int index = qp[i];
	        exch(index, n--);
	        swim(index);
	        sink(index);
	        keys[i] = null;
	        qp[i] = -1;
	    }

	    

	    private void validateIndex(int i) {
	        if (i < 0) throw new IllegalArgumentException("index is negative: " + i);
	        if (i >= maxN) throw new IllegalArgumentException("index >= capacity: " + i);
	    }

	    private boolean greater(int i, int j) {
	        return keys[pq[i]].compareTo(keys[pq[j]]) > 0;
	    }

	    private void exch(int i, int j) {
	        int swap = pq[i];
	        pq[i] = pq[j];
	        pq[j] = swap;
	        qp[pq[i]] = i;
	        qp[pq[j]] = j;
	    }

	    private void swim(int k) {
	        while (k > 1 && greater(k/2, k)) {
	            exch(k, k/2);
	            k = k/2;
	        }
	    }

	    private void sink(int k) {
	        while (2*k <= n) {
	            int j = 2*k;
	            if (j < n && greater(j, j+1)) j++;
	            if (!greater(k, j)) break;
	            exch(k, j);
	            k = j;
	        }
	    }


	   

	    
	    public Iterator<Integer> iterator() { return new HeapIterator(); }

	    private class HeapIterator implements Iterator<Integer> {
	        

	        private id23<Key> copy;

	        

	        

	        public HeapIterator() {
	            copy = new id23<Key>(pq.length - 1);
	            for (int i = 1; i <= n; i++)
	                copy.insert(pq[i], keys[pq[i]]);
	        }

	        public boolean hasNext()  { return !copy.isEmpty();                     }
	        public void remove()      { throw new UnsupportedOperationException();  }

	        public Integer next() {
	            if (!hasNext()) throw new NoSuchElementException();
	            return copy.delMin();
	        }
	    }

	}
	
	public static class SegmentTree {

	    private Node[] heap;
	    private long[] array;
	    private int size;

	    
	    public SegmentTree(long[] array) {
	        this.array = Arrays.copyOf(array, array.length);
	        

	        size = (int) (2 * Math.pow(2.0, Math.floor((Math.log((double) array.length) / Math.log(2.0)) + 1)));
	        heap = new Node[size];
	        build(1, 0, array.length);
	    }


	    public int size() {
	        return array.length;
	    }

	    

	    private void build(int v, int from, int size) {
	        heap[v] = new Node();
	        heap[v].from = from;
	        heap[v].to = from + size - 1;

	        if (size == 1) {
	            heap[v].sum = array[from];
	            heap[v].min = array[from];
	        } else {
	            

	            build(2 * v, from, size / 2);
	            build(2 * v + 1, from + size / 2, size - size / 2);

	            heap[v].sum = heap[2 * v].sum + heap[2 * v + 1].sum;
	            

	            heap[v].min = Math.min(heap[2 * v].min, heap[2 * v + 1].min);
	        }
	    }

	    
	    public long rangeSum(int from, int to) {
	        return rangeSum(1, from, to);
	    }

	    private long rangeSum(int v, int from, int to) {
	        Node n = heap[v];

	        

	        if (n.pendingVal != null && contains(n.from, n.to, from, to)) {
	            return (to - from + 1) * n.pendingVal;
	        }

	        if (contains(from, to, n.from, n.to)) {
	            return heap[v].sum;
	        }

	        if (intersects(from, to, n.from, n.to)) {
	            propagate(v);
	            long leftSum = rangeSum(2 * v, from, to);
	            long rightSum = rangeSum(2 * v + 1, from, to);

	            return leftSum + rightSum;
	        }

	        return 0;
	    }

	    
	    public long rangeMin(int from, int to) {
	        return rangeMin(1, from, to);
	    }

	    private long rangeMin(int v, int from, int to) {
	        Node n = heap[v];


	        

	        if (n.pendingVal != null && contains(n.from, n.to, from, to)) {
	            return n.pendingVal;
	        }

	        if (contains(from, to, n.from, n.to)) {
	            return heap[v].min;
	        }

	        if (intersects(from, to, n.from, n.to)) {
	            propagate(v);
	            long leftMin = rangeMin(2 * v, from, to);
	            long rightMin = rangeMin(2 * v + 1, from, to);

	            return Math.min(leftMin, rightMin);
	        }

	        return Integer.MAX_VALUE;
	    }


	    
	    public void update(int from, int to, int value) {
	        update(1, from, to, value);
	    }

	    private void update(int v, int from, int to, int value) {

	        

	        Node n = heap[v];

	        
	        if (contains(from, to, n.from, n.to)) {
	            change(n, value);
	        }

	        if (n.size() == 1) return;

	        if (intersects(from, to, n.from, n.to)) {
	            
	            propagate(v);

	            update(2 * v, from, to, value);
	            update(2 * v + 1, from, to, value);

	            n.sum = heap[2 * v].sum + heap[2 * v + 1].sum;
	            n.min = Math.min(heap[2 * v].min, heap[2 * v + 1].min);
	        }
	    }
	    
	   

	    

	    private void propagate(int v) {
	        Node n = heap[v];

	        if (n.pendingVal != null) {
	            change(heap[2 * v], n.pendingVal);
	            change(heap[2 * v + 1], n.pendingVal);
	            n.pendingVal = null; 

	        }
	    }

	    

	    private void change(Node n, int value) {
	        n.pendingVal = value;
	        n.sum = n.size() * value;
	        n.min = value;
	        array[n.from] = value;

	    }

	    

	    private boolean contains(int from1, int to1, int from2, int to2) {
	        return from2 >= from1 && to2 <= to1;
	    }

	    

	    private boolean intersects(int from1, int to1, int from2, int to2) {
	        return from1 <= from2 && to1 >= from2   

	                || from1 >= from2 && from1 <= to2; 

	    }

	    

	    static class Node {
	        long sum;
	        long min;
	        

	        Integer pendingVal = null;
	        int from;
	        int to;

	        int size() {
	            return to - from + 1;
	        }

	    }
	}
}










