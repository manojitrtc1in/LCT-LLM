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
	static final int id30 = 1000000007;
	static int t = 1;
	static double epsilon = 0.0000001;
	static boolean[] isPrime;
	static int[] id24;
	
	@SuppressWarnings("unused")
	public static void main(String[] args) {
		OUTER: 
		for (int tc = 0; tc < t; tc++) {
			
			int a = fr.nextInt(), b = fr.nextInt(), k = fr.nextInt();
			int acpy = a, bcpy = b;
			int n = a + b;
			
			

			
			

			

			
			char[] x = new char[n];
			char[] y = new char[n];
			
			if (k == 0) {
				
				for (int i = 0; i < b; i++)
					x[i] = '1';
				for (int i = 0; i < a; i++)
					x[i + b] = '0';
				
				out.println("Yes");
				out.println(toString(x));
				out.println(toString(x));
				continue OUTER;
			}
			
			Arrays.fill(x, '0');
			Arrays.fill(y, '0');
			
			x[0] = '1';
			y[0] = '1';
			b--;
			
			if (k > 0 && b == 0) {
				out.println("No");
				continue OUTER;
			}
			
			if (k + 1 > n - 1) {
				out.println("No");
				continue OUTER;
			}
			
			x[1] = '1';
			y[k + 1] = '1';
			b--;
			
			for (int i = 2; i < n; i++)
				if (i != k + 1)
					if (b > 0) {
						x[i] = '1';
						y[i] = '1';
						b--;
					}
			
			

			
			int oneCount = 0, zeroCount = 0;
			for (int i = 0; i < n; i++)
				if (x[i] == '1')
					oneCount++;
				else
					zeroCount++;
			
			if (oneCount != bcpy || zeroCount != acpy) {
				out.println("No");
				continue OUTER;
			}
			
			out.println("Yes");
			out.println(toString(x));
			out.println(toString(y));
		}
		out.close();
	}
	
	public static class id36 {

	    long[] array; 


	    public id36(int size) {
	        array = new long[size + 1];
	    }
	    
	    public long rsq(int ind) {
	        assert ind > 0;
	        long sum = 0;
	        while (ind > 0) {
	            sum += array[ind];
	            

	            ind -= ind & (-ind);
	        }

	        return sum;
	    }
	    
	    public long rsq(int a, int b) {
	        assert b >= a && a > 0 && b > 0;

	        return rsq(b) - rsq(a - 1);
	    }
	    
	    public void update(int ind, long value) {
	        assert ind > 0;
	        while (ind < array.length) {
	            array[ind] += value;
	            

	            ind += ind & (-ind);
	        }
	    }

	    public int size() {
	        return array.length - 1;
	    }
	}
	
	static int id38(char[] s) {
		int n = s.length;
		
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < n; i++)
			sb.append(s[i]);
		StringBuilder sb2 = new StringBuilder(sb);
		sb.append('^');
		sb.append(sb2.reverse());
		
		

		
		char[] newS = sb.toString().toCharArray();
		int m = newS.length;
		int[] pi = id25(newS);
		return pi[m - 1];
	}
	
	static int id37(char[] text, char[] pat) {
		int n = text.length;
		int m = pat.length;
		
		char[] id26 = new char[n + m + 1];
		for (int i = 0; i < m; i++)
			id26[i] = pat[i];
		id26[m] = '^'; 		

		for (int i = 0; i < n; i++)
			id26[m + i] = text[i];
		
		int[] fullPi = id25(id26);
		int answer = 0;
		for (int i = 0; i < n + m + 1; i++)
			if (fullPi[i] == m)
				answer++;
		return answer;
	}
	
	static int[] id25(char[] s) {
		int n = s.length;
		int[] pi = new int[n];
		for (int i = 1; i < n; i++) {
			int j = pi[i - 1];
			while (j > 0 && s[i] != s[j])
				j = pi[j - 1];
			if (s[i] == s[j])
				j++;
			pi[i] = j;
		}
		return pi;
	}
	
	static String id13(long num, int bits) {
		StringBuilder sb = new StringBuilder(Long.id13(num));
		sb.reverse();
		for (int i = sb.length(); i < bits; i++)
			sb.append('0');
		return sb.reverse().toString();
	}
	
	

	

	public static final class id5 {
		

		private static final boolean RED = true;
		private static final boolean BLACK = false;

		

		private Node root;

		

		public id5() {
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
				return node.value + size(node.left);
		}
	}
	
	static long modDiv(long a, long b) {
		return mod(a * power(b, id30 - 2, id30));
	}
	
	static class SegTree {
		
		

		int n;						

		long[] sumTree;
		long[] ogArr;
		long[] maxTree;
		long[] minTree;
		boolean[] id2;		

									

		
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
			id2 = new boolean[minTree.length];
		}
		
		
		
		
		

		private long buildSum(int l, int r, int segIdx) {
			return sumTree[segIdx] = (l == r) ? ogArr[l] : 
								  (buildSum(l, l + (r - l) / 2, 2 * segIdx + 1)
								 + buildSum((l + (r - l) / 2) + 1, r, 2 * segIdx + 2));
		}
		
		

		public void id3(int idx, long to) {
			id3(idx, to, 0, n - 1, 0);
		}
		
		private long id3(int idx, long to, int l, int r, int segIdx) {
			return sumTree[segIdx] = 
					((l == r) ? (ogArr[idx] = to) :
					((0 * ((idx <= (l + (r - l) / 2)) 
					? id3(idx, to, l, l + (r - l) / 2, 2 * segIdx + 1)
					: id3(idx, to, (l + (r - l) / 2) + 1, r, 2 * segIdx + 2)))
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
		
		

		public void id6(int idx, long to) {
			id6(0, n - 1, idx, to, 0);
		}
		
		private long id6(int l, int r, int idx, long to, int segIdx) {
			return maxTree[segIdx] = (l == r && l == idx) ? (ogArr[idx] = to) :
				Math.max(id6(l, l + (r - l) / 2, idx, to, 2 * segIdx + 1), 
						 id6(l + (r - l) / 2 + 1, r, idx, to, 2 * segIdx + 2));
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
		
		

		public void pointUpdate(int idx, long to) {
			pointUpdate(0, n - 1, idx, to, 0);
		}
		
		private long pointUpdate(int l, int r, int idx, long to, int segIdx) {
			id10(l, r, segIdx);
			return minTree[segIdx] = (l == r && l == idx) ? (to) :
				Math.min(pointUpdate(l, l + (r - l) / 2, idx, to, 2 * segIdx + 1), 
						 pointUpdate(l + (r - l) / 2 + 1, r, idx, to, 2 * segIdx + 2));
		}
		
		

		public void rangeUpdate(int segL, int segR, long to) {
			rangeUpdate(0, n - 1, segL, segR, to, 0);
		}
		
		private long rangeUpdate(int l, int r, int segL, int segR, long to, int segIdx) {
			id10(l, r, segIdx);			

			if (l == segL && r == segR) {
				id2[segIdx] = true;
				return minTree[segIdx] = to;
			}
			int midL = l + (r - l) / 2;
			if (segR <= midL)
				return minTree[segIdx] = rangeUpdate(l, midL, segL, segR, to, 2 * segIdx + 1);
			if (segL >= midL + 1)
				return minTree[segIdx] = rangeUpdate(midL + 1, r, segL, segR, to, 2 * segIdx + 2);
			return minTree[segIdx] = Math.min(rangeUpdate(l, midL, segL, midL, to, 2 * segIdx + 1), 
					 		rangeUpdate(midL + 1, r, midL + 1, segR, to, 2 * segIdx + 2));
		}
		
		public long rangeMin(int segL, int segR) {
			if (segL > segR) return 0;
			return rangeMin(0, n - 1, segL, segR, 0);
		}
		
		private long rangeMin(int l, int r, int segL, int segR, int segIdx) {
			id10(l, r, segIdx);
			int midL = l + (r - l) / 2;
			if (segL == l && segR == r)
				return minTree[segIdx];
			if (segR <= midL)
				return rangeMin(l, midL, segL, segR, 2 * segIdx + 1);
			if (segL >= midL + 1)
				return rangeMin(midL + 1, r, segL, segR, 2 * segIdx + 2);
			return Math.min(rangeMin(l, midL, segL, midL, 2 * segIdx + 1), 
					        rangeMin(midL + 1, r, midL + 1, segR, 2 * segIdx + 2));
		}
		
		
		
		
		
		
		

		

		void id10(int l, int r, int segIdx) {
			if (!id2[segIdx]) 
				return;
			
			int child1 = 2 * segIdx + 1, child2 = 2 * segIdx + 2;
			if (child2 > 4 * n - 1)
				child2 = child1;
			if (child1 > 4 * n - 1)
				return;
			minTree[child1] = minTree[child2] = minTree[segIdx];
			id2[child1] = id2[child2] = true;
			id2[segIdx] = false;
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
	
	static void id29(int m, int n, ArrayList<Point> id31, int limit, int id14) {
		
		if (m > limit) return;
		
		if (m <= limit && n <= limit)
			id31.add(new Point(m, n));
		
		if (id31.size() > id14) return;
		
		id29(2 * m - n, m, id31, limit, id14);
		id29(2 * m + n, m, id31, limit, id14);
		id29(m + 2 * n, n, id31, limit, id14);
	}
	
	static long hash(long i) {
		return (i * 2654435761L % id30);
	}

	static long hash2(long key) {
        long h = Long.hashCode(key);
        h ^= (h >>> 20) ^ (h >>> 12) ^ (h >>> 7) ^ (h >>> 4);
        return h & (id30-1);
    }
	
	

	

	static int id39(int row, int col, int n, int m) {
		return row * m + col;
	}
	
	

	static int[] id11(int idx, int n, int m) {
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
			if (this.x < o.x)
				return -1;
			if (this.x > o.x)
				return 1;
			if (this.y < o.y)
				return -1;
			if (this.y > o.y)
				return 1;
			return 0;
		}
		
		public boolean equals(Point that) {
			return this.compareTo(that) == 0;
		}
	}
	
	static double distance(Point p1, Point p2) {
		return Math.sqrt(Math.pow(p2.y-p1.y, 2) + Math.pow(p2.x-p1.x, 2));
	}
	
	static HashMap<Integer, Integer> id22(int num) {
		
		if (id24 == null)
			primeGenerator(2750132);
		
		CountMap<Integer> fnps = new CountMap<>();
		while (num != 1) {
			fnps.putCM(id24[num]);
			num /= id24[num];
		}
		return fnps;
	}
	
	

	static HashMap<Long, Integer> id12(long num) {
		HashMap<Long, Integer> map = new HashMap<>();
		while (num % 2 == 0) {
			num /= 2;
			Integer id7 = map.get(2L);
			map.put(2L, id7 != null ? id7 + 1 : 1);
		}
		
		for (long i = 3; i * i <= num; i += 2) {
			while (num % i == 0) {
				num /= i;
				Integer id7 = map.get(i);
				map.put(i, id7 != null ? id7 + 1 : 1);
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
			if (arr[mid] >= val) {
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
	
	static long id27(long a, long b) {
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
	
	static long nCr(long n, long r, long[] fac) {
		long p = 998244353;
	    

	    if (r == 0)
	        return 1;
	 
	    

	    

	    

	    
	 
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
		return id27(n, n - r);
	}
	
	static int logk(long n, long k) {
		return (int)(Math.log(n) / Math.log(k));
	}
	
	

	static boolean[] primeGenerator(int upto) {
		isPrime = new boolean[upto + 1];
		id24 = new int[upto + 1];
		Arrays.fill(id24, 1);
		Arrays.fill(isPrime, true);
		isPrime[1] = isPrime[0] = false;

		for (long i = 2; i < upto + 1; i++)
			if (isPrime[(int) i]) {
				id24[(int) i] = (int) i;
				

				

				for (long j = i; j * i < upto + 1; j++) {
					if (isPrime[(int) j * (int) i]) {
						isPrime[(int) j * (int) i] = false;
						id24[(int) j * (int) i] = (int) i;
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
		return (num % id30 + id30) % id30;
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
	    	while (p != parent[p])
	            p = parent[p];
	        return p;
	    }

	    public boolean connected(int p, int q) {
	        return find(p) == find(q);
	    }
	    
	    public int id15(int node) {
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
	    	int[] id34 = new int[n];
	    	for (int i = 0; i < n; i++)
	    		id34[i] = uf.find(i);
	    	
	    	HashMap<Integer, Integer> id23 = new HashMap<>();
	    	int newCtr = 0;
	    	
	    	for (int i = 0; i < n; i++) {
	    		
	    		int id32 = id34[i];
	    		Integer id9 = id23.get(id32);
	    		if (id9 == null)
	    			id9 = newCtr++;
	    		
	    		id23.put(id32, id9);
	    		id34[i] = id9;
	    	}
	    	
	    	return id34;
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
			int id33 = 0;
			for (int adjc : adj) {
				if (marked[adjc]) id33++;
				dfsMark(adjc, current, distTo, marked, g, endPoints);
			}
			
			if (id33 == adj.size())
				endPoints.add(current);
		}
		
		public static void id4(int current, UGraph g) {
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
			boolean[] id28 = new boolean[1];
			for (int i = 0; i < n; i++) {
				if (marked[i]) continue;
				id21(i, ug, marked, id28, -1);
			}
			return id28[0];
		}
		
		

		private static void id21(int current, UGraph ug, boolean[] marked, boolean[] id28, int parent) {
			if (marked[current]) return;
			if (id28[0]) return;
			
			marked[current] = true;
			HashSet<Integer> adjc = ug.adj(current);
			for (int adj : adjc) {
				if (marked[adj] && adj != parent && parent != -1) {
					id28[0] = true;
					return;
				}
				
				id21(adj, ug, marked, id28, current);
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
		
		public static int[] id18(Digraph dg) {
			int[] id = new int[dg.V()];
			
			Digraph reversed = dg.reversed();
			
			

			Stack<Integer> revStack = Digraph.id17(reversed);
			
			

			id = new int[dg.V()];
			int idCtr = -1;
			
			

			boolean[] marked = new boolean[dg.V()];
			
			while (!revStack.isEmpty()) {
				int vertex = revStack.pop();
				if (!marked[vertex]) 
					id20(dg, vertex, marked, ++idCtr, id);
			}
			return id;
		}
		
		private static void id20(Digraph dg, int source, boolean[] marked, int idCtr, int[] id) {
			marked[source] = true;
			id[source] = idCtr;
			for (Integer adjVertex : dg.adj(source))
				if (!marked[adjVertex]) id20(dg, adjVertex, marked, idCtr, id);
		}
		
		public static Stack<Integer> id17(Digraph dg) {
			

			

			

			Stack<Integer> id8 = new Stack<Integer>();
			boolean[] marked = new boolean[dg.V()];
			
			

			for (int i = 0; i < dg.V(); i++)
				if (!marked[i]) 
					id1(dg, id8, marked, i);
			
			return id8;
		}
		
		static void id1(Digraph dg, Stack<Integer> id8, boolean[] marked, int source) {
			marked[source] = true;
			for (Integer adjVertex : dg.adj(source))
				if (!marked[adjVertex]) 
					id1(dg, id8, marked, adjVertex);
			id8.add(source);
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

		int[] id16(int n) {
			int[] arr = new int[n];
			for (int i = 0; i < n; i++)
				arr[i] = nextInt();
			return arr;
		}

		double[] id35(int n) {
			double[] arr = new double[n];
			for (int i = 0; i < arr.length; i++)
				arr[i] = nextDouble();
			return arr;
		}

		long[] id40(int n) {
			long[] arr = new long[n];
			for (int i = 0; i < n; i++)
				arr[i] = nextLong();
			return arr;
		}
		
		int[][] id19(int n, int m) {
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












