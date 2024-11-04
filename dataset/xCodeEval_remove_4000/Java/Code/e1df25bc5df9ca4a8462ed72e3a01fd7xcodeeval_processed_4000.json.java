import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Random;
import java.util.Stack;
import java.util.StringTokenizer;



public final class CFPS {
	static FastReader fr = new FastReader();
	static PrintWriter out = new PrintWriter(System.out);
	static final int id26 = 1000000007;
	static int t = 1;
	static double epsilon = 0.0000001;
	static boolean[] isPrime;
	static int[] id22;
	
	@SuppressWarnings("unused")
	public static void main(String[] args) {
		OUTER: 
		for (int tc = 0; tc < t; tc++) {
			
			int k = fr.nextInt();
			char[] s = fr.next().toCharArray();
			reverse(s);
			int n = s.length, q = fr.nextInt();
			int[] ps = new int[q];
			char[] cs = new char[q];
			for (int i = 0; i < q; i++) {
				ps[i] = (n - 1) - (fr.nextInt() - 1);
				cs[i] = fr.nextChar();
			}
			
			

			
			

			
			

			
			

			

			
			

			
			int[] possAt = new int[n];
			init(possAt, s);
			
			for (int qu = 0; qu < q; qu++) {
				

				update(possAt, s, ps[qu], cs[qu]);
				out.println(possAt[0]);
			}
		}
		out.close();
	}
	
	static void update(int[] possAt, char[] s, int pos, char c) {
		
		

		int n = s.length;
		s[pos] = c;
		int node = pos;
		while (node != 0) {
			int child1 = 2 * node + 1, child2 = 2 * node + 2;
			
			

			if (child1 > n - 1) {
				

				if (s[node] == '?')
					possAt[node] = 2;
				else
					possAt[node] = 1;
				
				

				node = (node - 1) / 2;
				continue;
			}
			
			

			if (s[node] == '?') {
				
				

				possAt[node] = possAt[child1] + possAt[child2];
				
			} else {
				
				

				if (s[node] == '1')
					possAt[node] = possAt[child1];
				else
					possAt[node] = possAt[child2];
			}
			
			node = (node - 1) / 2;
		}
		
		

		
		

		if (1 > n - 1) {
			if (s[node] == '?')
				possAt[node] = 2;
			else
				possAt[node] = 1;
		} else if (s[node] == '?')
			possAt[node] = possAt[1] + possAt[2];
		else if (s[node] == '1')
			possAt[node] = possAt[1];
		else
			possAt[node] = possAt[2];
	}
	
	static void init(int[] possAt, char[] s) {
		

		Arrays.fill(possAt, 1);
		int n = s.length;
		
		for (int node = n - 1; node > -1; node--) {
			int child1 = 2 * node + 1, child2 = 2 * node + 2;
			
			

			if (child1 > n - 1) {
				

				if (s[node] == '?')
					possAt[node] = 2;
				continue;
			}
			
			

			if (s[node] == '?') {
				
				

				possAt[node] = possAt[child1] + possAt[child2];
				
			} else {
				
				

				if (s[node] == '1')
					possAt[node] = possAt[child1];
				else
					possAt[node] = possAt[child2];
			}
		}
	}
	
	static String id11(long num, int bits) {
		StringBuilder sb = new StringBuilder(Long.id11(num));
		sb.reverse();
		for (int i = sb.length(); i < bits; i++)
			sb.append('0');
		return sb.reverse().toString();
	}
	
	

	

	public static final class id4 {
		

		private static final boolean RED = true;
		private static final boolean BLACK = false;

		

		private Node root;

		

		public id4() {
			root = null;
		}

		

		private class Node {
			long key;
			long value;
			Node left, right;
			boolean color;
			long size; 


			public Node(long key, long value, boolean color) {
				this.key = key;
				this.value = value;
				this.left = this.right = null;
				this.color = color;
				this.size = value;
			}
		}

		

		

		private Node flipColors(Node node) {
			node.left.color = node.right.color = BLACK;
			node.color = RED;
			return node;
		}

		

		private Node rotateLeft(Node node) {
			Node rn = node.right;
			node.right = rn.left;
			rn.left = node;
			rn.color = node.color;
			node.color = RED;
			return rn;
		}

		

		private Node rotateRight(Node node) {
			Node ln = node.left;
			node.left = ln.right;
			ln.right = node;
			ln.color = node.color;
			node.color = RED;
			return ln;
		}

		
		
		

		
		public void put(long key) {
			root = put(root, key);
			root.color = BLACK; 

		}

		private Node put(Node node, long key) {
			


			if (node == null)
				return new Node(key, 1, RED);

			

			int cmp = Long.compare(key, node.key);
			if (cmp < 0)
				node.left = put(node.left, key);
			else if (cmp > 0)
				node.right = put(node.right, key);
			else
				node.value++;

			

			if (node.left != null && node.right != null) {
				if (node.right.color = RED && node.left.color == BLACK)
					node = rotateLeft(node);
				if (node.left.color == RED && node.left.left.color == RED)
					node = rotateRight(node);
				if (node.left.color == RED && node.right.color == RED)
					node = flipColors(node);
			}

			

			node.size = node.value + size(node.left) + size(node.right);

			return node;
		}

		private long size(Node node) {
			if (node == null)
				return 0;
			else
				return node.size;
		}

		public long rank(long key) {
			return rank(root, key);
		}

		

		private long rank(Node node, long key) {
			if (node == null) return 0;
			int cmp = Long.compare(key, node.key);
			if (cmp < 0)
				return rank(node.left, key);
			else if (cmp > 0)
				return node.value + size(node.left) + rank(node.right, key);
			else
				return size(node.left);
		}
	}
	
	static long modDiv(long a, long b) {
		return mod(a * power(b, id26 - 2, id26));
	}
	
	static class SegTree {
		
		

		int n;
		long[] sumTree;
		long[] ogArr;
		long[] maxTree;
		long[] minTree;
		
		public static final int sumMode = 0;
		public static final int maxMode = 1;
		public static final int minMode = 2;
		
		

		public SegTree(long[] arr, int mode) {
			
			if (mode == sumMode) {
				Arrays.fill(sumTree = new long[4 * (n = ((ogArr = arr.clone()).length))], -1);
				buildSum(0, n - 1, 0);
			} else if (mode == maxMode) {
				Arrays.fill(maxTree = new long[4 * (n = ((ogArr = arr.clone()).length))], -1);
				buildMax(0, n - 1, 0);
			} else if (mode == minMode) {
				Arrays.fill(minTree = new long[4 * (n = ((ogArr = arr.clone()).length))], Long.MAX_VALUE - 1);
				buildMin(0, n - 1, 0);
			}
		}
		
		
		
		
		

		private long buildSum(int l, int r, int segIdx) {
			return sumTree[segIdx] = (l == r) ? ogArr[l] : 
								  (buildSum(l, l + (r - l) / 2, 2 * segIdx + 1)
								 + buildSum((l + (r - l) / 2) + 1, r, 2 * segIdx + 2));
		}
		
		

		public void id2(int idx, long to) {
			id2(idx, to, 0, n - 1, 0);
		}
		
		private long id2(int idx, long to, int l, int r, int segIdx) {
			return sumTree[segIdx] = 
					((l == r) ? (ogArr[idx] = to) :
					((0 * ((idx <= (l + (r - l) / 2)) 
					? id2(idx, to, l, l + (r - l) / 2, 2 * segIdx + 1)
					: id2(idx, to, (l + (r - l) / 2) + 1, r, 2 * segIdx + 2)))
					+ sumTree[2 * segIdx + 1] + sumTree[2 * segIdx + 2]));
		}
		
		

		public long segSum(int l, int r) {
			if (l > r) return 0;
			return segSum(l, r, 0, n - 1, 0);
		}
		
		private long segSum(int segL, int segR, int l, int r, int segIdx) {
			if (segL == l && segR == r)
				return sumTree[segIdx];
			if (segR <= l + (r - l) / 2)
				return segSum(segL, segR, l, l + (r - l) / 2, 2 * segIdx + 1);
			if (segL >= l + (r - l) / 2 + 1)
				return segSum(segL, segR, l + (r - l) / 2 + 1, r, 2 * segIdx + 2);
			return segSum(segL, l + (r - l) / 2, l, l + (r - l) / 2, 2 * segIdx + 1)
				 + segSum(l + (r - l) / 2 + 1, segR, l + (r - l) / 2 + 1, r, 2 * segIdx + 2);
		}
		
		
		
		
		
		
		
		

		private long buildMax(int l, int r, int segIdx) {
			return maxTree[segIdx] = (l == r) ? ogArr[l] : 
				Math.max(buildMax(l, (l + (r - l) / 2), 2 * segIdx + 1), 
						 buildMax(l + (r - l) / 2 + 1, r, 2 * segIdx + 2));
		}
		
		

		public void id5(int idx, long to) {
			id5(0, n - 1, idx, to, 0);
		}
		
		private long id5(int l, int r, int idx, long to, int segIdx) {
			return maxTree[segIdx] = (l == r && l == idx) ? (ogArr[idx] = to) :
				Math.max(id5(l, l + (r - l) / 2, idx, to, 2 * segIdx + 1), 
						 id5(l + (r - l) / 2 + 1, r, idx, to, 2 * segIdx + 2));
		}
		
		public long segMax(int segL, int segR) {
			if (segL > segR) return 0;
			return segMax(0, n - 1, segL, segR, 0);
		}
		
		private long segMax(int l, int r, int segL, int segR, int segIdx) {
			int midL = l + (r - l) / 2;
			if (segL == segR && segL == l)
				return ogArr[segL];
			if (segR <= midL)
				return segMax(l, midL, segL, segR, 2 * segIdx + 1);
			if (segL >= midL + 1)
				return segMax(midL + 1, r, segL, segR, 2 * segIdx + 2);
			return Math.max(segMax(l, midL, segL, midL, 2 * segIdx + 1), 
					        segMax(midL + 1, r, midL + 1, segR, 2 * segIdx + 2));
		}
		
		
		
		
		
		
		
		private long buildMin(int l, int r, int segIdx) {
			return minTree[segIdx] = (l == r) ? ogArr[l] : 
				Math.min(buildMin(l, (l + (r - l) / 2), 2 * segIdx + 1), 
						 buildMin(l + (r - l) / 2 + 1, r, 2 * segIdx + 2));
		}
		
		

		public void id30(int idx, long to) {
			id30(0, n - 1, idx, to, 0);
		}
		
		private long id30(int l, int r, int idx, long to, int segIdx) {
			return minTree[segIdx] = (l == r && l == idx) ? (ogArr[idx] = to) :
				Math.min(id30(l, l + (r - l) / 2, idx, to, 2 * segIdx + 1), 
						 id30(l + (r - l) / 2 + 1, r, idx, to, 2 * segIdx + 2));
		}
		
		public long segMin(int segL, int segR) {
			if (segL > segR) return 0;
			return segMin(0, n - 1, segL, segR, 0);
		}
		
		private long segMin(int l, int r, int segL, int segR, int segIdx) {
			int midL = l + (r - l) / 2;
			if (segL == segR && segL == l)
				return ogArr[segL];
			if (segR <= midL)
				return segMin(l, midL, segL, segR, 2 * segIdx + 1);
			if (segL >= midL + 1)
				return segMin(midL + 1, r, segL, segR, 2 * segIdx + 2);
			return Math.min(segMin(l, midL, segL, midL, 2 * segIdx + 1), 
					        segMin(midL + 1, r, midL + 1, segR, 2 * segIdx + 2));
		}
		
		
		
		
		public String toString() {
			return CFPS.toString(minTree);
		}
	}
	
	@SuppressWarnings("serial")
	static class CountMap<T> extends HashMap<T, Integer>{
		
		CountMap() {
		}
		
		CountMap(T[] arr) {
			this.putCM(arr);
		}
		
		public Integer putCM(T key) {
			if (super.containsKey(key)) {
				return super.put(key, super.get(key) + 1);
			} else {
				return super.put(key, 1);
			}
		}
		
		public Integer removeCM(T key) {
			Integer count = super.get(key);
			if (count == null) return -1;
			if (count == 1)
				return super.remove(key);
			else
				return super.put(key, super.get(key) - 1);
		}
		
		public Integer getCM(T key) {
			Integer count = super.get(key);
			if (count == null)
				return 0;
			return count;
		}
	
		public void putCM(T[] arr) {
			for (T l : arr)
				this.putCM(l);
		}
	}
	
	static void id25(int m, int n, ArrayList<Point> id27, int limit, int id12) {
		
		if (m > limit) return;
		
		if (m <= limit && n <= limit)
			id27.add(new Point(m, n));
		
		if (id27.size() > id12) return;
		
		id25(2 * m - n, m, id27, limit, id12);
		id25(2 * m + n, m, id27, limit, id12);
		id25(m + 2 * n, n, id27, limit, id12);
	}
	
	static long hash(long i) {
		return (i * 2654435761L % id26);
	}

	static long hash2(long key) {
        long h = Long.hashCode(key);
        h ^= (h >>> 20) ^ (h >>> 12) ^ (h >>> 7) ^ (h >>> 4);
        return h & (id26-1);
    }
	
	

	

	static int id33(int row, int col, int n, int m) {
		return row * m + col;
	}
	
	

	static int[] id9(int idx, int n, int m) {
		int[] rnc = new int[2];
		rnc[0] = idx / m;
		rnc[1] = idx % m;
		return rnc;
	}
	
	static class Point implements Comparable<Point> {
		long x;
		long y;
		long id;
		
		Point() {
			x = y = id = 0;
		}
		
		Point(Point p) {
			this.x = p.x;
			this.y = p.y;
			this.id = p.id;
		}
		
		Point(long a, long b, long id) {
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
	
	static double distance(Point p1, Point p2) {
		return Math.sqrt(Math.pow(p2.y-p1.y, 2) + Math.pow(p2.x-p1.x, 2));
	}
	
	static HashMap<Integer, Integer> id20(int num) {
		
		if (id22 == null)
			primeGenerator(1000000);
		
		CountMap<Integer> fnps = new CountMap<>();
		while (num != 1) {
			fnps.putCM(id22[num]);
			num /= id22[num];
		}
		return fnps;
	}
	
	

	static HashMap<Long, Integer> id10(long num) {
		HashMap<Long, Integer> map = new HashMap<>();
		while (num % 2 == 0) {
			num /= 2;
			Integer id6 = map.get(2L);
			map.put(2L, id6 != null ? id6 + 1 : 1);
		}
		
		for (long i = 3; i * i <= num; i += 2) {
			while (num % i == 0) {
				num /= i;
				Integer id6 = map.get(i);
				map.put(i, id6 != null ? id6 + 1 : 1);
			}
		}
		
		

		

		if (num != 1)
			map.put(num, 1);
		
		return map;
	}
	
	static HashSet<Long> id0(long num) {
		HashSet<Long> id0 = new HashSet<Long>();
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
	
	static long id23(long a, long b) {
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
	
	static long nCr(long n, long r) {
		long p = id26;
	    

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
		return id23(n, n - r);
	}
	
	static double logk(long n, long k) {
		return (int)(Math.log(n) / Math.log(k));
	}
	
	

	static boolean[] primeGenerator(int upto) {
		isPrime = new boolean[upto + 1];
		id22 = new int[upto + 1];
		Arrays.fill(id22, 1);
		Arrays.fill(isPrime, true);
		isPrime[1] = isPrime[0] = false;

		for (long i = 2; i < upto + 1; i++)
			if (isPrime[(int) i]) {
				id22[(int) i] = (int) i;
				

				

				for (long j = i; j * i < upto + 1; j++) {
					if (isPrime[(int) j * (int) i]) {
						isPrime[(int) j * (int) i] = false;
						id22[(int) j * (int) i] = (int) i;
					}
				}
			}
		return isPrime;
	}
	
	static long gcd(long a, long b) {
		if (b == 0) {
			return a;
		} else {
			return gcd(b, a % b);
		}
	}
	
	static int gcd(int a, int b) {
		if (b == 0) {
			return a;
		} else {
			return gcd(b, a % b);
		}
	}
	
	static long gcd(long[] arr) {
		int n = arr.length;
		long gcd = arr[0];
		for (int i = 1; i < n; i++) {
			gcd = gcd(gcd, arr[i]);
		}
		return gcd;
	}
	
	static int gcd(int[] arr) {
		int n = arr.length;
		int gcd = arr[0];
		for (int i = 1; i < n; i++) {
			gcd = gcd(gcd, arr[i]);
		}
		return gcd;
	}
	
	static long lcm(long[] arr) {
		long lcm = arr[0];
		int n = arr.length;
		for (int i = 1; i < n; i++) {
			lcm = (lcm * arr[i]) / gcd(lcm, arr[i]);
		}
		return lcm;
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
	
	static void reverse(char[] arr) {
		int n = arr.length;
		for (int i = 0; i < n / 2; i++)
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
				sb.append(dp[i][j] + " ");
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
	
	static long mod(long a, long m) {
	    return (a%m + m) % m;
	}
	
	static long mod(long num) {
		return (num % id26 + id26) % id26;
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
	    
	    public int id13(int node) {
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
	    	int[] id31 = new int[n];
	    	for (int i = 0; i < n; i++)
	    		id31[i] = uf.find(i);
	    	
	    	HashMap<Integer, Integer> id21 = new HashMap<>();
	    	int newCtr = 0;
	    	
	    	for (int i = 0; i < n; i++) {
	    		
	    		int id28 = id31[i];
	    		Integer id8 = id21.get(id28);
	    		if (id8 == null)
	    			id8 = newCtr++;
	    		
	    		id21.put(id28, id8);
	    		id31[i] = id8;
	    	}
	    	
	    	return id31;
	    }
	}
	
	static class UGraph {
		

		private HashSet<Integer>[] adj;
		private static final String NEWLINE = "\n";
		private int E;
		
		public UGraph(int V) {
			adj = (HashSet<Integer>[]) new HashSet[V];
			E = 0;
			for (int i = 0; i < V; i++)
				adj[i] = new HashSet<Integer>();
		}
		
		public void addEdge(int from, int to) {
			if (adj[from].contains(to)) return;
			E++;
			adj[from].add(to);
			adj[to].add(from);
		}
		
		public HashSet<Integer> adj(int from) {
			return adj[from];
		}
		
		public int degree(int v) {
			return adj[v].size();
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
			HashSet<Integer> adj = g.adj(current);
			int id29 = 0;
			for (int adjc : adj) {
				if (marked[adjc]) id29++;
				dfsMark(adjc, current, distTo, marked, g, endPoints);
			}
			
			if (id29 == adj.size())
				endPoints.add(current);
		}
		
		public static void id3(int current, UGraph g) {
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
				id19(i, ug, marked, id24, -1);
			}
			return id24[0];
		}
		
		

		private static void id19(int current, UGraph ug, boolean[] marked, boolean[] id24, int parent) {
			if (marked[current]) return;
			if (id24[0]) return;
			
			marked[current] = true;
			HashSet<Integer> adjc = ug.adj(current);
			for (int adj : adjc) {
				if (marked[adj] && adj != parent && parent != -1) {
					id24[0] = true;
					return;
				}
				
				id19(adj, ug, marked, id24, current);
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
		
		public Digraph reversed() {
			Digraph dg = new Digraph(V());
			for (int i = 0; i < V(); i++)
				for (int adjVert : adj(i)) dg.addEdge(adjVert, i);
			return dg;
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
		
		public static int[] id16(Digraph dg) {
			int[] id = new int[dg.V()];
			
			Digraph reversed = dg.reversed();
			
			

			Stack<Integer> revStack = Digraph.id15(reversed);
			
			

			id = new int[dg.V()];
			int idCtr = -1;
			
			

			boolean[] marked = new boolean[dg.V()];
			
			while (!revStack.isEmpty()) {
				int vertex = revStack.pop();
				if (!marked[vertex]) 
					id18(dg, vertex, marked, ++idCtr, id);
			}
			return id;
		}
		
		private static void id18(Digraph dg, int source, boolean[] marked, int idCtr, int[] id) {
			marked[source] = true;
			id[source] = idCtr;
			for (Integer adjVertex : dg.adj(source))
				if (!marked[adjVertex]) id18(dg, adjVertex, marked, idCtr, id);
		}
		
		public static Stack<Integer> id15(Digraph dg) {
			

			

			

			Stack<Integer> id7 = new Stack<Integer>();
			boolean[] marked = new boolean[dg.V()];
			
			

			for (int i = 0; i < dg.V(); i++)
				if (!marked[i]) 
					id1(dg, id7, marked, i);
			
			return id7;
		}
		
		static void id1(Digraph dg, Stack<Integer> id7, boolean[] marked, int source) {
			marked[source] = true;
			for (Integer adjVertex : dg.adj(source))
				if (!marked[adjVertex]) 
					id1(dg, id7, marked, adjVertex);
			id7.add(source);
		}
		
		public static boolean hasCycle(Digraph dg) {
			int n = dg.V();
			boolean[] marked = new boolean[n];
			boolean[] id24 = new boolean[1];
			for (int i = 0; i < n; i++) {
				if (marked[i]) continue;
				id19(i, dg, marked, id24, -1);
			}
			return id24[0];
		}
		
		

		private static void id19(int current, Digraph dg, boolean[] marked, boolean[] id24, int parent) {
			if (marked[current]) return;
			if (id24[0]) return;
			
			marked[current] = true;
			HashSet<Integer> adjc = dg.adj(current);
			for (int adj : adjc) {
				if (marked[adj] && adj != parent && parent != -1) {
					id24[0] = true;
					return;
				}
				
				id19(adj, dg, marked, id24, current);
			}
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

		int[] id14(int n) {
			int[] arr = new int[n];
			for (int i = 0; i < n; i++)
				arr[i] = nextInt();
			return arr;
		}

		double[] id32(int n) {
			double[] arr = new double[n];
			for (int i = 0; i < arr.length; i++)
				arr[i] = nextDouble();
			return arr;
		}

		long[] id34(int n) {
			long[] arr = new long[n];
			for (int i = 0; i < n; i++)
				arr[i] = nextLong();
			return arr;
		}
		
		int[][] id17(int n, int m) {
			int[][] grid = new int[n][m];
			for (int i = 0; i < n; i++) {
				char[] line = fr.next().toCharArray();
				for (int j = 0; j < m; j++)
					grid[i][j] = line[j] - 48;
			}
			return grid;
		}
	}
}












