import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Random;
import java.util.Stack;
import java.util.StringTokenizer;
import java.util.TreeMap;
import java.util.function.IntToLongFunction;

public final class CFPS {
	static FastReader fr = new FastReader();
	static PrintWriter out = new PrintWriter(System.out);
	static final int id38 = 1000000007;
	static final int mod = 998244353;
	static int t = 1;
	static double epsilon = 0.00000001;
	static boolean[] isPrime;
	static int[] id7;
	static final int UP = 0, LEFT = 1, DOWN = 2, RIGHT = 3;
	
	@SuppressWarnings({"unused"})
	public static void main(String[] args) throws Exception {
		t = fr.nextInt();
		OUTER: 
		for (int tc = 0; tc < t; tc++) {
			
			int n = fr.nextInt();
			int[] arr = fr.id13(n);
			int x = fr.nextInt();
			
			

			
			

			
			

			

			

			
			for (int i = 0; i < n; i++)
				arr[i] -= x;
			
			

			

			

			
			

			

			

			

			

			
			

			

			

			

			

			

			

			

			
			

			

			
			

			

			

			
			int[] dp = new int[n];
			dp[0] = 1;
			
			for (int i = 1; i < n; i++) {
				
				dp[i] = 1;
				
				

				

				

				
				if (arr[i] + arr[i - 1] >= 0)
					dp[i] = 2;
				
				

				

				

				

				

				
				if (i >= 2) {
					boolean id47 = (arr[i - 2] + arr[i - 1] + arr[i]) >= 0;
					boolean id8 = (arr[i - 2] + arr[i - 1]) >= 0;
					boolean id31 = (arr[i - 1] + arr[i]) >= 0;
					
					if (id47 && id8 && id31)
						dp[i] = Math.max(dp[i], 3);
					
					

					

					

					
					if (i >= 3) {
						boolean id20 = (arr[i - 3] + arr[i - 2] + arr[i - 1]) >= 0;
						
						if (id20 && id47 && id8 && id31)
							dp[i] = Math.max(dp[i], dp[i - 2] + 2);
					}
				}
			}
			
			long[] dpdp = new long[n];
			dpdp[0] = 1;
			for (int i = 1; i < n; i++) {
				int clen = dp[i];
				
				dpdp[i] = dp[i];
				
				if (i - clen - 1 >= 0)
					dpdp[i] += dpdp[i - clen - 1];
			}
			
			out.println(dpdp[n - 1]);
		}
		out.close();
	}
	
	static class Pair implements Comparable<Pair> {
		int first, second;
		
		Pair() { first = second = 0; }
		
		Pair (int ff, int ss) {
			first = ff;
			second = ss;
		}

		public int compareTo(Pair that) {
			if (this.first < that.first) return -1;
			if (this.first > that.first) return 1;
			return Long.compare(second, that.second);
		}
	}
	
	static class id36 implements Cloneable {
        private static long inf = (long) 2e18;
        private id36 left;
        private id36 right;
        private long firstLargest;
        private long secondLargest;
        private int id49;
        private long id58;
        private long id41;
        private int id34;
        private long dirty;
        private int size;
        private long sum;

        private void setMin(long x) {
            if (firstLargest <= x) {
                return;
            }
            sum -= (firstLargest - x) * id49;
            firstLargest = x;

            if (id58 >= x) {
                id58 = x;
                id34 = size;
            }
            id41 = Math.min(id41, x);
            if (id41 == id58) {
                id41 = inf;
            }
        }

        private void setMax(long x) {
            if (id58 >= x) {
                return;
            }
            sum += (x - id58) * id34;
            id58 = x;

            if (firstLargest <= x) {
                firstLargest = x;
                id49 = size;
            }
            secondLargest = Math.max(secondLargest, x);
            if (secondLargest == firstLargest) {
                secondLargest = -inf;
            }
        }

        private void modify(long x) {
            dirty += x;
            sum += x * size;
            id58 += x;
            firstLargest += x;
            id41 += x;
            secondLargest += x;
        }

        public void pushUp() {
            firstLargest = Math.max(left.firstLargest, right.firstLargest);
            secondLargest = Math.max(left.firstLargest == firstLargest ? left.secondLargest : left.firstLargest, right.firstLargest == firstLargest ? right.secondLargest : right.firstLargest);
            id49 = (left.firstLargest == firstLargest ? left.id49 : 0) + (right.firstLargest == firstLargest ? right.id49 : 0);

            id58 = Math.min(left.id58, right.id58);
            id41 = Math.min(left.id58 == id58 ? left.id41 : left.id58,
                    right.id58 == id58 ? right.id41 : right.id58);
            id34 = (left.id58 == id58 ? left.id34 : 0) + (right.id58 == id58 ? right.id34 : 0);

            sum = left.sum + right.sum;
            size = left.size + right.size;
        }

        public void pushDown() {
            if (dirty != 0) {
                left.modify(dirty);
                right.modify(dirty);
                dirty = 0;
            }
            left.setMin(firstLargest);
            right.setMin(firstLargest);
            left.setMax(id58);
            right.setMax(id58);
        }

        public id36(int l, int r, IntToLongFunction func) {
            if (l < r) {
                int m = DigitUtils.floorAverage(l, r);
                left = new id36(l, m, func);
                right = new id36(m + 1, r, func);
                pushUp();
            } else {
                sum = id58 = firstLargest = func.applyAsLong(l);
                id34 = id49 = 1;
                id41 = inf;
                secondLargest = -inf;
                size = 1;
            }
        }

        private boolean covered(int ll, int rr, int l, int r) {
            return ll <= l && rr >= r;
        }

        private boolean noIntersection(int ll, int rr, int l, int r) {
            return ll > r || rr < l;
        }

        public void updateMin(int ll, int rr, int l, int r, long x) {
            if (noIntersection(ll, rr, l, r)) {
                return;
            }
            if (covered(ll, rr, l, r)) {
                if (firstLargest <= x) {
                    return;
                }
                if (secondLargest < x) {
                    setMin(x);
                    return;
                }
            }
            pushDown();
            int m = DigitUtils.floorAverage(l, r);
            left.updateMin(ll, rr, l, m, x);
            right.updateMin(ll, rr, m + 1, r, x);
            pushUp();
        }

        public void updateMax(int ll, int rr, int l, int r, long x) {
            if (noIntersection(ll, rr, l, r)) {
                return;
            }
            if (covered(ll, rr, l, r)) {
                if (id58 >= x) {
                    return;
                }
                if (id41 > x) {
                    setMax(x);
                    return;
                }
            }
            pushDown();
            int m = DigitUtils.floorAverage(l, r);
            left.updateMax(ll, rr, l, m, x);
            right.updateMax(ll, rr, m + 1, r, x);
            pushUp();
        }

        public void update(int ll, int rr, int l, int r, long x) {
            if (noIntersection(ll, rr, l, r)) {
                return;
            }
            if (covered(ll, rr, l, r)) {
                modify(x);
                return;
            }
            pushDown();
            int m = DigitUtils.floorAverage(l, r);
            left.update(ll, rr, l, m, x);
            right.update(ll, rr, m + 1, r, x);
            pushUp();
        }

        public long querySum(int ll, int rr, int l, int r) {
            if (noIntersection(ll, rr, l, r)) {
                return 0;
            }
            if (covered(ll, rr, l, r)) {
                return sum;
            }
            pushDown();
            int m = DigitUtils.floorAverage(l, r);
            return left.querySum(ll, rr, l, m) +
                    right.querySum(ll, rr, m + 1, r);
        }

        private id36 deepClone() {
            id36 seg = clone();
            if (seg.left != null) {
                seg.left = seg.left.deepClone();
            }
            if (seg.right != null) {
                seg.right = seg.right.deepClone();
            }
            return seg;
        }

        protected id36 clone() {
            try {
                return (id36) super.clone();
            } catch (CloneNotSupportedException e) {
                throw new RuntimeException(e);
            }
        }

        private void toString(StringBuilder builder) {
            if (left == null && right == null) {
                builder.append(sum).append(",");
                return;
            }
            pushDown();
            left.toString(builder);
            right.toString(builder);
        }

        public String toString() {
            StringBuilder builder = new StringBuilder();
            deepClone().toString(builder);
            if (builder.length() > 0) {
                builder.setLength(builder.length() - 1);
            }
            return builder.toString();
        }
        
        static class DigitUtils {
            private DigitUtils() {
            }

            public static int floorAverage(int x, int y) {
                return (x & y) + ((x ^ y) >> 1);
            }

        }
    }
	
	static class SegmentTree {
		int left, right;
		SegmentTree lChild, rChild;
		long sum;
		long min; 
		long max;
		Long addLazy, assignLazy;
		
		public SegmentTree(int qleft, int qright, long[] arr) {
			left = qleft;
			right = qright;
			addLazy = assignLazy = null;
			if (left == right)
				

				assign(arr[left]);
			else {
				int mid = left + (right - left) / 2;
				lChild = new SegmentTree(left, mid, arr);
				rChild = new SegmentTree(mid + 1, right, arr);
				reCalc();
			}
		}
		
		

		private void assign(long val) {
			sum = min = max = val;
		}
		
		private void reCalc() {
			if (left == right) return;
			sum = lChild.sum + rChild.sum;
			min = Math.min(lChild.min, rChild.min);
			max = Math.max(lChild.max, rChild.max);
		}
		
		private void propagate() {
			
			if (assignLazy != null) {
				sum = (right + 1 - left) * assignLazy;
				min = assignLazy;
				max = assignLazy;
				
				if (lChild != null)
					lChild.assignLazy = rChild.assignLazy = assignLazy;
				
				assignLazy = null;
			}
			
			if (addLazy != null) {
				sum += (right + 1 - left) * addLazy;
				min += addLazy;
				max += addLazy;
				
				if (lChild != null)
					lChild.addLazy = rChild.addLazy = addLazy;
				
				addLazy = null;
			}
		}
		
		public void pointUpdate(int index, long val) {
			propagate();
			
			if (index == left && left == right)
				

				sum = val;
			else if (index <= lChild.right) {
				

				lChild.pointUpdate(index, val);
				reCalc();
			} else {
				

				rChild.pointUpdate(index, val);
				reCalc();
			}
		}
		
		public long RSQ(int qleft, int qright) {
			propagate();
			
			if (qleft > right || qright < left) return 0;
			if (qleft <= left && qright >= right) return sum;
			return lChild.RSQ(qleft, qright) + 
				   rChild.RSQ(qleft, qright);
		}
		
		public void rngAdd(int qleft, int qright, long val) {
			
			if (qleft > right || qright < left) return;
			if (qleft <= left && right <= qright) {
				

				addLazy += val;
				return;
			}
			
			propagate();
			lChild.rngAdd(qleft, qright, val);
			rChild.rngAdd(qleft, qright, val);
		}
		
		public void rngSet(int qleft, int qright, long val) {
			
		}
	}
	
	static class id12 {

	    private Node[] heap;
	    private int[] array;
	    private int size;
	   
	    public id12(int[] array) {
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

	    public int rsq(int from, int to) {
	        return rsq(1, from, to);
	    }

	    private int rsq(int v, int from, int to) {
	        Node n = heap[v];

	        

	        if (n.pendingVal != null && contains(n.from, n.to, from, to)) {
	            return (to - from + 1) * n.pendingVal;
	        }

	        if (contains(from, to, n.from, n.to)) {
	            return heap[v].sum;
	        }

	        if (intersects(from, to, n.from, n.to)) {
	            propagate(v);
	            int leftSum = rsq(2 * v, from, to);
	            int rightSum = rsq(2 * v + 1, from, to);

	            return leftSum + rightSum;
	        }

	        return 0;
	    }

	    public int id32(int from, int to) {
	        return id32(1, from, to);
	    }

	    private int id32(int v, int from, int to) {
	        Node n = heap[v];


	        

	        if (n.pendingVal != null && contains(n.from, n.to, from, to)) {
	            return n.pendingVal;
	        }

	        if (contains(from, to, n.from, n.to)) {
	            return heap[v].min;
	        }

	        if (intersects(from, to, n.from, n.to)) {
	            propagate(v);
	            int leftMin = id32(2 * v, from, to);
	            int rightMin = id32(2 * v + 1, from, to);

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
	        int sum;
	        int min;
	        

	        Integer pendingVal = null;
	        int from;
	        int to;

	        int size() {
	            return to - from + 1;
	        }

	    }
	}
	
	static boolean[] id50(char[] s) {
		int n = s.length;
		boolean[] res = new boolean[n + 1];
		
		int[] pi = prefixFunction(s);
		
		res[0] = true;
        for (int p = n; p != 0; p = pi[p])
            res[p] = true;
		
		return res;
	}
	
	static int[] prefixFunction(char[] s) {
		int k = s.length;
		int[] pfunc = new int[k + 1];
        pfunc[0] = pfunc[1] = 0;
        for (int i = 2; i <= k; i++) {
            pfunc[i] = 0;
            for (int p = pfunc[i - 1]; p != 0; p = pfunc[p])
                if (s[p] == s[i - 1]) {
                    pfunc[i] = p + 1;
                    break;
                }
            if (pfunc[i] == 0 && s[i - 1] == s[0])
                pfunc[i] = 1;
        }
        
        return pfunc;
	}
	
	static int[] treeDiameter(UGraph ug) {
		int n = ug.V();
		
		int id26 = -1;
		int[] distTo = new int[n];
		diamDFS(0, -1, 0, ug, distTo);
		
		int maxDist = -1;
		for (int i = 0; i < n; i++)
			if (maxDist < distTo[i]) {
				maxDist = distTo[i];
				id26 = i;
			}
		
		distTo = new int[n + 1];
		diamDFS(id26, -1, 0, ug, distTo);
		distTo[n] = id26;
		
		return distTo;
	}
	
	static void diamDFS(int current, int from, int dist, UGraph ug, int[] distTo) {
		distTo[current] = dist;
		for (int adj : ug.adj(current))
			if (adj != from)
				diamDFS(adj, current, dist + 1, ug, distTo);
	}
	
	static class id4 {
		UGraph ug;
		int n;
		int[] depthOf;
		LCA lca;
		
		id4(UGraph ug) {
			this.ug = ug;
			n = ug.V();
			depthOf = new int[n];
			depthCalc(0, -1, ug, 0, depthOf);
			lca = new LCA(ug, 0);
		}
		
		id4(UGraph ug, int a) {
			this.ug = ug;
			n = ug.V();
			depthOf = new int[n];
			depthCalc(a, -1, ug, 0, depthOf);
			lca = new LCA(ug, a);
		}
		
		private void depthCalc(int current, int from, UGraph ug, int depth, int[] depthOf) {
			depthOf[current] = depth;
			for (int adj : ug.adj(current))
				if (adj != from)
					depthCalc(adj, current, ug, depth + 1, depthOf);
		}
		
		public int dist(int a, int b) {
			int lc = lca.lca(a, b);
			return (depthOf[a] - depthOf[lc] + depthOf[b] - depthOf[lc]);
		}
	}
	
	public static long[][] id14(long[] a)
	{
		int n = a.length;
		int b = 32-Integer.numberOfLeadingZeros(n);
		long[][] ret = new long[b][];
		for(int i = 0, l = 1;i < b;i++, l*=2) {
			if(i == 0) {
				ret[i] = a;
			} else {
				ret[i] = new long[n-l+1];
				for(int j = 0;j < n-l+1;j++) {
					ret[i][j] = gcd(ret[i-1][j], ret[i-1][j+l/2]);
				}
			}
		}
		return ret;
	}
	
	public static long id33(long[][] table, int l, int r)
	{
		

		assert l <= r;
		if(l > r)return 1;
		

		int t = 31-Integer.numberOfLeadingZeros(r-l);
		return gcd(table[t][l], table[t][r-(1<<t)]);
	}
	
	static class Trie {
		
		TrieNode root;
		
		Trie(char[][] strings) {
			root = new TrieNode('A', false);
			construct(root, strings);
		}
		
		public Stack<String> set(TrieNode root) {
			Stack<String> set = new Stack<>();
			
			StringBuilder sb = new StringBuilder();
			for (TrieNode next : root.next)
				collect(sb, next, set);
			
			return set;
		}
		
		private void collect(StringBuilder sb, TrieNode node, Stack<String> set) {
			if (node == null) return;
			
			sb.append(node.character);
			if (node.isTerminal)
				set.add(sb.toString());
			
			for (TrieNode next : node.next)
				collect(sb, next, set);
			
			if (sb.length() > 0)
				sb.setLength(sb.length() - 1);
		}
		
		private void construct(TrieNode root, char[][] strings) {
			
			

			for (char[] string : strings) {
				if (string.length == 0) continue;
				
				root.next[string[0] - 'a'] = put(root.next[string[0] - 'a'], string, 0);
				
				if (root.next[string[0] - 'a'] != null)
					root.isLeaf = false;
			}
		}
		
		private TrieNode put(TrieNode node, char[] string, int idx) {
			boolean isTerminal = (idx == string.length - 1);
			if (node == null) node = new TrieNode(string[idx], isTerminal);
			
			node.character = string[idx];
			node.isTerminal |= isTerminal;
			
			if (!isTerminal) {
				node.isLeaf = false;
				node.next[string[idx + 1] - 'a'] = put(node.next[string[idx + 1] - 'a'], string, idx + 1);
			}
			
			return node;
		}
		
		class TrieNode {
			char character;
			TrieNode[] next;
			boolean isTerminal, isLeaf;
			boolean canWin, canLose;
			
			TrieNode(char c, boolean id25) {
				character = c;
				isTerminal = id25;
				next = new TrieNode[26];
				isLeaf = true;
			}
		}
	}
	
	static class Edge implements Comparable<Edge> {
		int from, to;
		long weight;
		int id;
		

		
		Edge(int fro, int t, long wt, int i) {
			from = fro;
			to = t;
			id = i;
			weight = wt;
			

		}
		
		
		
		public int compareTo(Edge that) {
			return Long.compare(this.id, that.id);
		}
	}
	
	public static long[][] id37(long[] a)
	{
		int n = a.length;
		int b = 32-Integer.numberOfLeadingZeros(n);
		long[][] ret = new long[b][];
		for(int i = 0, l = 1;i < b;i++, l*=2) {
			if(i == 0) {
				ret[i] = a;
			}else {
				ret[i] = new long[n-l+1];
				for(int j = 0;j < n-l+1;j++) {
					ret[i][j] = Math.min(ret[i-1][j], ret[i-1][j+l/2]);
				}
			}
		}
		return ret;
	}
	
	public static long id39(long[][] table, int l, int r)
	{
		

		assert l <= r;
		if(l >= r)return Integer.MAX_VALUE;
		

		int t = 31-Integer.numberOfLeadingZeros(r-l);
		return Math.min(table[t][l], table[t][r-(1<<t)]);
	}
	
	public static long[][] id55(long[] a)
	{
		int n = a.length;
		int b = 32-Integer.numberOfLeadingZeros(n);
		long[][] ret = new long[b][];
		for(int i = 0, l = 1;i < b;i++, l*=2) {
			if(i == 0) {
				ret[i] = a;
			}else {
				ret[i] = new long[n-l+1];
				for(int j = 0;j < n-l+1;j++) {
					ret[i][j] = Math.max(ret[i-1][j], ret[i-1][j+l/2]);
				}
			}
		}
		return ret;
	}
	
	public static long id21(long[][] table, int l, int r)
	{
		

		assert l <= r;
		if(l >= r)return Integer.MIN_VALUE;
		

		int t = 31-Integer.numberOfLeadingZeros(r-l);
		return Math.max(table[t][l], table[t][r-(1<<t)]);
	}
	
	static class LCA {
	    int[] height, first, id24;
	    ArrayList<Integer> euler;
	    boolean[] visited;
	    int n;

	    LCA(UGraph ug, int root) {
	        n = ug.V();
	        height = new int[n];
	        first = new int[n];
	        euler = new ArrayList<>();
	        visited = new boolean[n];
	        dfs(ug, root, 0);
	        int m = euler.size();
	        id24 = new int[m * 4];
	        build(1, 0, m - 1);
	    }

	    void dfs(UGraph ug, int node, int h) {
	        visited[node] = true;
	        height[node] = h;
	        first[node] = euler.size();
	        euler.add(node);
	        for (int adj : ug.adj(node)) {
	            if (!visited[adj]) {
	                dfs(ug, adj, h + 1);
	                euler.add(node);
	            }
	        }
	    }

	    void build(int node, int b, int e) {
	        if (b == e) {
	            id24[node] = euler.get(b);
	        } else {
	            int mid = (b + e) / 2;
	            build(node << 1, b, mid);
	            build(node << 1 | 1, mid + 1, e);
	            int l = id24[node << 1], r = id24[node << 1 | 1];
	            id24[node] = (height[l] < height[r]) ? l : r;
	        }
	    }

	    int query(int node, int b, int e, int L, int R) {
	        if (b > R || e < L)
	            return -1;
	        if (b >= L && e <= R)
	            return id24[node];
	        int mid = (b + e) >> 1;

	        int left = query(node << 1, b, mid, L, R);
	        int right = query(node << 1 | 1, mid + 1, e, L, R);
	        if (left == -1) return right;
	        if (right == -1) return left;
	        return height[left] < height[right] ? left : right;
	    }

	    int lca(int u, int v) {
	        int left = first[u], right = first[v];
	        if (left > right) {
	        	int temp = left;
	        	left = right;
	        	right = temp;
	        }
	        return query(1, 0, euler.size() - 1, left, right);
	    }
	}
	
	static class id30 {

	    long[] array; 


	    public id30(int size) {
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
	
	static class Point implements Comparable<Point> {
		long x;
		long y;
		long z;
		long id;
		

		
		Point() {
			x = z = y = 0;
			

		}
		
		Point(Point p) {
			this.x = p.x;
			this.y = p.y;
			this.z = p.z;
			this.id = p.id;
			

		}
		
		Point(long x, long y, long z, long id) {
			this.x = x;
			this.y = y;
			this.z = z;
			this.id = id;
			

		}
		
		Point(long a, long b) {
			this.x = a;
			this.y = b;
			this.z = 0;
			

		}
		
		Point(long x, long y, long id) {
			this.x = x;
			this.y = y;
			this.id = id;
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
			if (this.z < o.z)
				return -1;
			if (this.z > o.z)
				return 1;
			return 0;
		}
		
		@Override
		public boolean equals(Object that) {
			return this.compareTo((Point) that) == 0;
		}
	}
	
	static class BinaryLift {
		
		

		
		int[] parentOf;
		int id6;
		int[][] id28;
		int n;
		int[] lvlOf;
		
		

		
		

		
		

		

		
		public BinaryLift(UGraph tree) {
			n = tree.V();
			id6 = logk(n, 2) + 1;
			parentOf = new int[n];
			id28 = new int[n][id6];
			lvlOf = new int[n];
			for (int i = 0; i < n; i++)
				Arrays.fill(id28[i], -1);
			parentConstruct(0, -1, tree, 0);
			binConstruct();
		}
		
		

		public BinaryLift(int[] parentOf) {
			this.parentOf = parentOf;
			n = parentOf.length;
			id6 = logk(n, 2) + 1;
			id28 = new int[n][id6];
			lvlOf = new int[n];
			for (int i = 0; i < n; i++)
				Arrays.fill(id28[i], -1);
			UGraph tree = new UGraph(n);
			for (int i = 1; i < n; i++)
				tree.addEdge(i, parentOf[i]);
			binConstruct();
			parentConstruct(0, -1, tree, 0);
		}
		
		private void parentConstruct(int current, int from, UGraph tree, int depth) {
			parentOf[current] = from;
			lvlOf[current] = depth;
			for (int adj : tree.adj(current))
				if (adj != from)
					parentConstruct(adj, current, tree, depth + 1);
		}
		
		private void binConstruct() {
			for (int node = 0; node < n; node++)
				for (int lvl = 0; lvl < id6; lvl++)
					binConstruct(node, lvl);
		}
		
		private int binConstruct(int node, int lvl) {
			if (node < 0)
				return -1;
			if (lvl == 0)
				return id28[node][lvl] = parentOf[node];
			if (node == 0)
				return id28[node][lvl] = -1;
			
			if (id28[node][lvl] != -1)
				return id28[node][lvl];
			return id28[node][lvl] = binConstruct(binConstruct(node, lvl - 1), lvl - 1);
		}
		
		

		public int ancestor(int node, int k) {
			if (node < 0)
				return -1;
			if (node == 0)
				if (k == 0) return node;
				else return -1;
			if (k > (1 << id6) - 1)
				return -1;
			if (k == 0)
				return node;
			
			int ancestor = node;
			int highestBit = Integer.highestOneBit(k);
			
			while (k > 0 && ancestor != -1) {
				ancestor = id28[ancestor][logk(highestBit, 2)];
				k -= highestBit;
				highestBit = Integer.highestOneBit(k);
			}
			
			return ancestor;
		}
	
		public int lca(int u, int v) {
			
			if (u == v)
				return u;
			
			

			if (lvlOf[u] < lvlOf[v]) {
				int temp = u;
				u = v;
				v = temp;
			}
			
			

			u = ancestor(u, lvlOf[u] - lvlOf[v]);
			
			if (u == v)
				return u;
			
			

			for (int power = id6 - 1; power > -1; power--)
				if (id28[u][power] != id28[v][power]) {
					u = id28[u][power];
					v = id28[v][power];
				}
			
			return ancestor(u, 1);
		}
	}
	
	static class id53 {
		
		

		

		
		UGraph tree;
		UGraph backUG;
		int hasBridge;
		int n;
		Edge backEdge;
		
		
		id53(UGraph ug) {
			this.n = ug.V();
			tree = new UGraph(n);
			hasBridge = -1;
			backUG = new UGraph(n);
			treeCalc(0, -1, new boolean[n], ug);
		}
		
		private void treeCalc(int current, int from, boolean[] marked, UGraph ug) {
			if (marked[current]) {
				

				backUG.addEdge(from, current);
				backEdge = new Edge(from, current, 1, 0);
				return;
			}
			
			if (from != -1)
				tree.addEdge(from, current);
			marked[current] = true;
			
			for (int adj : ug.adj(current))
				if (adj != from)
					treeCalc(adj, current, marked, ug);
		}
		
		public boolean hasBridge() {
			if (hasBridge != -1)
				return (hasBridge == 1);
			
			

			bridgeFinder();
			return (hasBridge == 1);
		}
		
		int[] levelOf; 
		int[] dp;
		
		
		
		private void bridgeFinder() {
			
			

			levelOf = new int[n];
			
			levelDFS(0, -1, 0);
			
			

			

			

			dp = new int[n];
			Arrays.fill(dp, Integer.MAX_VALUE / 100);
			dpDFS(0, -1);
			
			

			

			
			for (int i = 0; i < n; i++)
				for (int adj : tree.adj(i)) {
					
					

					
					if (dp[adj] > levelOf[i])
						hasBridge = 1;
				}
			
			if (hasBridge != 1)
				hasBridge = 0;
		}
		
		private void levelDFS(int current, int from, int lvl) {
			levelOf[current] = lvl;
			for (int adj : tree.adj(current))
				if (adj != from)
					levelDFS(adj, current, lvl + 1);
		}
		
		private int dpDFS(int current, int from) {
			dp[current] = levelOf[current];
			
			for (int back : backUG.adj(current))
				dp[current] = Math.min(dp[current], levelOf[back]);
			
			for (int adj : tree.adj(current))
				if (adj != from)
					dp[current] = Math.min(dp[current], dpDFS(adj, current));
			
			return dp[current];
		}
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
	    
	    public int id48(int node) {
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
	    	int[] id40 = new int[n];
	    	for (int i = 0; i < n; i++)
	    		id40[i] = uf.find(i);
	    	
	    	HashMap<Integer, Integer> id52 = new HashMap<>();
	    	int newCtr = 0;
	    	
	    	for (int i = 0; i < n; i++) {
	    		
	    		int id56 = id40[i];
	    		Integer id11 = id52.get(id56);
	    		if (id11 == null)
	    			id11 = newCtr++;
	    		
	    		id52.put(id56, id11);
	    		id40[i] = id11;
	    	}
	    	
	    	return id40;
	    }
	}
	
	static class UGraph {
		

		private HashSet<Integer>[] adj;
		private static final String NEWLINE = "\n";
		private int E;
		
		@SuppressWarnings("unchecked")
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
			int id57 = 0;
			for (int adjc : adj) {
				if (marked[adjc]) id57++;
				dfsMark(adjc, current, distTo, marked, g, endPoints);
			}
			
			if (id57 == adj.size())
				endPoints.add(current);
		}
		
		public static void id1(int current, UGraph g) {
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
			boolean[] id23 = new boolean[1];
			for (int i = 0; i < n; i++) {
				if (marked[i]) continue;
				id17(i, ug, marked, id23, -1);
			}
			return id23[0];
		}
		
		

		private static void id17(int current, UGraph ug, boolean[] marked, boolean[] id23, int parent) {
			if (marked[current]) return;
			if (id23[0]) return;
			
			marked[current] = true;
			HashSet<Integer> adjc = ug.adj(current);
			for (int adj : adjc) {
				if (marked[adj] && adj != parent && parent != -1) {
					id23[0] = true;
					return;
				}
				
				id17(adj, ug, marked, id23, current);
			}
		}
	}
	
	static class Digraph {
		

		private HashSet<Integer>[] adj;
		private static final String NEWLINE = "\n";
		private int E;
		
		@SuppressWarnings("unchecked")
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
		
		public static int[] id15(Digraph dg) {
			int[] id = new int[dg.V()];
			
			Digraph reversed = dg.reversed();
			
			

			Stack<Integer> revStack = Digraph.id35(reversed);
			
			

			id = new int[dg.V()];
			int idCtr = -1;
			
			

			boolean[] marked = new boolean[dg.V()];
			
			while (!revStack.isEmpty()) {
				int vertex = revStack.pop();
				if (!marked[vertex]) 
					id51(dg, vertex, marked, ++idCtr, id);
			}
			return id;
		}
		
		private static void id51(Digraph dg, int source, boolean[] marked, int idCtr, int[] id) {
			marked[source] = true;
			id[source] = idCtr;
			for (Integer adjVertex : dg.adj(source))
				if (!marked[adjVertex]) id51(dg, adjVertex, marked, idCtr, id);
		}
		
		public static Stack<Integer> id35(Digraph dg) {
			

			

			

			Stack<Integer> id2 = new Stack<Integer>();
			boolean[] marked = new boolean[dg.V()];
			
			

			for (int i = 0; i < dg.V(); i++)
				if (!marked[i]) 
					id43(dg, id2, marked, i);
			
			return id2;
		}
		
		static void id43(Digraph dg, Stack<Integer> id2, boolean[] marked, int source) {
			marked[source] = true;
			for (Integer adjVertex : dg.adj(source))
				if (!marked[adjVertex]) 
					id43(dg, id2, marked, adjVertex);
			id2.add(source);
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

		int[] id13(int n) {
			int[] arr = new int[n];
			for (int i = 0; i < n; i++)
				arr[i] = nextInt();
			return arr;
		}

		double[] id10(int n) {
			double[] arr = new double[n];
			for (int i = 0; i < arr.length; i++)
				arr[i] = nextDouble();
			return arr;
		}

		long[] id59(int n) {
			long[] arr = new long[n];
			for (int i = 0; i < n; i++)
				arr[i] = nextLong();
			return arr;
		}
		
		int[][] id16(int n, int m) {
			int[][] grid = new int[n][m];
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++)
					grid[i][j] = fr.nextInt();
			}
			return grid;
		}
	}
	
	@SuppressWarnings("serial")
	static class CountMap<T> extends TreeMap<T, Integer>{
		
		CountMap() {
		}
		
		CountMap(Comparator<T> cmp) {
		}
		
		CountMap(T[] arr) {
			this.putCM(arr);
		}
		
		public Integer putCM(T key) {
			return super.put(key, super.getOrDefault(key, 0) + 1);
		}
		
		public Integer removeCM(T key) {
			int count = super.getOrDefault(key, -1);
			if (count == -1) return -1;
			if (count == 1)
				return super.remove(key);
			else
				return super.put(key, count - 1);
		}
		
		public Integer getCM(T key) {
			return super.getOrDefault(key, 0);
		}
	
		public void putCM(T[] arr) {
			for (T l : arr)
				this.putCM(l);
		}
	}
	
	static long id46(long a, long b, long[] x0, long[] y0) {
	    if (b == 0) {
	        x0[0] = 1;
	        y0[0] = 0;
	        return a;
	    }
	    long[] x1 = new long[1], y1 = new long[1];
	    long d = id46(b, a % b, x1, y1);
	    x0[0] = y1[0];
	    y0[0] = x1[0] - y1[0] * (a / b);
	    return d;
	}

	static boolean id19(long a, long b, long c, long[] x0, long[] y0, long[] g) {
	    g[0] = id46(Math.abs(a), Math.abs(b), x0, y0);
	    if (c % g[0] > 0) {
	        return false;
	    }

	    x0[0] *= c / g[0];
	    y0[0] *= c / g[0];
	    if (a < 0) x0[0] = -x0[0];
	    if (b < 0) y0[0] = -y0[0];
	    return true;
	}
	
	static long[][] prod(long[][] mat1, long[][] mat2) {
		int n = mat1.length;
		long[][] prod = new long[n][n];
		
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				

				

				for (int k = 0; k < n; k++)
					prod[i][j] += mat1[i][k] * mat2[k][j];
		return prod;
	}
	static long[][] matExpo(long[][] mat, long power) {
		int n = mat.length;
		long[][] ans = new long[n][n];
		
		if (power == 0)
			return null;
		
		if (power == 1)
			return mat;
		
		long[][] half = matExpo(mat, power / 2);
		ans = prod(half, half);
		
		if (power % 2 == 1) {
			ans = prod(ans, mat);
		}
		
		return ans;
	}
	
	static int id29(char[] text, char[] pat) {
		int n = text.length;
		int m = pat.length;
		
		char[] id9 = new char[n + m + 1];
		for (int i = 0; i < m; i++)
			id9[i] = pat[i];
		id9[m] = '^'; 		

		for (int i = 0; i < n; i++)
			id9[m + i] = text[i];
		
		int[] fullPi = id22(id9);
		int answer = 0;
		for (int i = 0; i < n + m + 1; i++)
			if (fullPi[i] == m)
				answer++;
		return answer;
	}
	static int[] id22(char[] s) {
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
	static long hash(long key) {
        long h = Long.hashCode(key);
        h ^= (h >>> 20) ^ (h >>> 12) ^ (h >>> 7) ^ (h >>> 4);
        return h & (id38-1);
    }
	
	static int id42(int row, int col, int n, int m) {
		

		

		return row * m + col;
	}
	static int[] id3(int idx, int n, int m) {
		

		int[] rnc = new int[2];
		rnc[0] = idx / m;
		rnc[1] = idx % m;
		return rnc;
	}
	
	static boolean[] primeGenerator(int upto) {
		

		isPrime = new boolean[upto + 1];
		id7 = new int[upto + 1];
		Arrays.fill(id7, 1);
		Arrays.fill(isPrime, true);
		isPrime[1] = isPrime[0] = false;

		for (long i = 2; i < upto + 1; i++)
			if (isPrime[(int) i]) {
				id7[(int) i] = (int) i;
				

				

				for (long j = i; j * i < upto + 1; j++) {
					if (isPrime[(int) j * (int) i]) {
						isPrime[(int) j * (int) i] = false;
						id7[(int) j * (int) i] = (int) i;
					}
				}
			}
		return isPrime;
	}
	static HashMap<Integer, Integer> id18(int num) {
		if (id7 == null)
			primeGenerator(num + 1);
		HashMap<Integer, Integer> fnps = new HashMap<>();
		while (num != 1) {
			fnps.put(id7[num], fnps.getOrDefault(id7[num], 0) + 1);
			num /= id7[num];
		}
		return fnps;
	}
	static HashMap<Long, Integer> id45(long num) {
		

		HashMap<Long, Integer> map = new HashMap<>();
		while (num % 2 == 0) {
			num /= 2;
			Integer id44 = map.get(2L);
			map.put(2L, id44 != null ? id44 + 1 : 1);
		}
		for (long i = 3; i * i <= num; i += 2) {
			while (num % i == 0) {
				num /= i;
				Integer id44 = map.get(i);
				map.put(i, id44 != null ? id44 + 1 : 1);
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
	static void id54(int m, int n, ArrayList<Point> id27, int limit, int id5) {
		if (m > limit) return;
		if (m <= limit && n <= limit)
			id27.add(new Point(m, n));
		if (id27.size() > id5) return;
		id54(2 * m - n, m, id27, limit, id5);
		id54(2 * m + n, m, id27, limit, id5);
		id54(m + 2 * n, n, id27, limit, id5);
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
	
	static long nCr(long n, long r, long[] fac) { long p = id38; if (r == 0) return 1; return (fac[(int)n] * modInverse(fac[(int)r], p) % p * modInverse(fac[(int)n - (int)r], p) % p) % p; } 
	static long modInverse(long n, long p) { return power(n, p - 2, p); } 
	static long modDiv(long a, long b){return mod(a * power(b, id38 - 2, id38));}
	static long power(long x, long y, long p) { long res = 1; x = x % p; while (y > 0) { if ((y & 1)==1) res = (res * x) % p; y = y >> 1; x = (x * x) % p; } return res; } 
	static int logk(long n, long k) { return (int)(Math.log(n) / Math.log(k)); }
	static long gcd(long a, long b) { if (b == 0) { return a; } else { return gcd(b, a % b); } } static int gcd(int a, int b) { if (b == 0) { return a; } else { return gcd(b, a % b); } } static long gcd(long[] arr) { int n = arr.length; long gcd = arr[0]; for (int i = 1; i < n; i++) { gcd = gcd(gcd, arr[i]); } return gcd; } static int gcd(int[] arr) { int n = arr.length; int gcd = arr[0]; for (int i = 1; i < n; i++) { gcd = gcd(gcd, arr[i]); } return gcd; } static long lcm(long[] arr) { long lcm = arr[0]; int n = arr.length; for (int i = 1; i < n; i++) { lcm = (lcm * arr[i]) / gcd(lcm, arr[i]); } return lcm; } static long lcm(long a, long b) { return (a * b)/gcd(a, b); } static boolean less(int a, int b) { return a < b ? true : false; } static boolean isSorted(int[] a) { for (int i = 1; i < a.length; i++) { if (less(a[i], a[i - 1])) return false; } return true; } static boolean isSorted(long[] a) { for (int i = 1; i < a.length; i++) { if (a[i] < a[i - 1]) return false; } return true; } static void swap(int[] a, int i, int j) { int temp = a[i]; a[i] = a[j]; a[j] = temp; } static void swap(long[] a, int i, int j) { long temp = a[i]; a[i] = a[j]; a[j] = temp; } static void swap(double[] a, int i, int j) { double temp = a[i]; a[i] = a[j]; a[j] = temp; } static void swap(char[] a, int i, int j) { char temp = a[i]; a[i] = a[j]; a[j] = temp; }
	static void sort(int[] arr) { shuffleArray(arr, 0, arr.length - 1); Arrays.sort(arr); } static void sort(char[] arr) { shuffleArray(arr, 0, arr.length - 1); Arrays.sort(arr); } static void sort(long[] arr) { shuffleArray(arr, 0, arr.length - 1); Arrays.sort(arr); } static void sort(double[] arr) { shuffleArray(arr, 0, arr.length - 1); Arrays.sort(arr); } static void reverseSort(int[] arr) { shuffleArray(arr, 0, arr.length - 1); Arrays.sort(arr); int n = arr.length; for (int i = 0; i < n/2; i++) swap(arr, i, n - 1 - i); } static void reverseSort(char[] arr) { shuffleArray(arr, 0, arr.length - 1); Arrays.sort(arr); int n = arr.length; for (int i = 0; i < n/2; i++) swap(arr, i, n - 1 - i); } static void reverse(char[] arr) { int n = arr.length; for (int i = 0; i < n / 2; i++) swap(arr, i, n - 1 - i); } static void reverseSort(long[] arr) { shuffleArray(arr, 0, arr.length - 1); Arrays.sort(arr); int n = arr.length; for (int i = 0; i < n/2; i++) swap(arr, i, n - 1 - i); } static void reverseSort(double[] arr) { shuffleArray(arr, 0, arr.length - 1); Arrays.sort(arr); int n = arr.length; for (int i = 0; i < n/2; i++) swap(arr, i, n - 1 - i); }
	static void shuffleArray(long[] arr, int startPos, int endPos) { Random rnd = new Random(); for (int i = startPos; i < endPos; ++i) { long tmp = arr[i]; int randomPos = i + rnd.nextInt(endPos - i); arr[i] = arr[randomPos]; arr[randomPos] = tmp; } } static void shuffleArray(int[] arr, int startPos, int endPos) { Random rnd = new Random(); for (int i = startPos; i < endPos; ++i) { int tmp = arr[i]; int randomPos = i + rnd.nextInt(endPos - i); arr[i] = arr[randomPos]; arr[randomPos] = tmp; } }
	static void shuffleArray(double[] arr, int startPos, int endPos) { Random rnd = new Random(); for (int i = startPos; i < endPos; ++i) { double tmp = arr[i]; int randomPos = i + rnd.nextInt(endPos - i); arr[i] = arr[randomPos]; arr[randomPos] = tmp; } }
	static void shuffleArray(char[] arr, int startPos, int endPos) { Random rnd = new Random(); for (int i = startPos; i < endPos; ++i) { char tmp = arr[i]; int randomPos = i + rnd.nextInt(endPos - i); arr[i] = arr[randomPos]; arr[randomPos] = tmp; } }
	static boolean isPrime(long n) {if (n<=1)return false;if(n<=3)return true;if(n%2==0||n%3==0)return false;for(long i=5;i*i<=n;i=i+6)if(n%i==0||n%(i+2)==0)return false;return true;}
	static String toString(int[] dp){StringBuilder sb=new StringBuilder();for(int i=0;i<dp.length;i++)sb.append(dp[i]+" ");return sb.toString();}
	static String toString(boolean[] dp){StringBuilder sb=new StringBuilder();for(int i=0;i<dp.length;i++)sb.append(dp[i]+" ");return sb.toString();}
	static String toString(long[] dp){StringBuilder sb=new StringBuilder();for(int i=0;i<dp.length;i++)sb.append(dp[i]+" ");return sb.toString();}
	static String toString(char[] dp){StringBuilder sb=new StringBuilder();for(int i=0;i<dp.length;i++)sb.append(dp[i]+"");return sb.toString();}
	static String toString(int[][] dp){StringBuilder sb=new StringBuilder();for(int i=0;i<dp.length;i++){for(int j=0;j<dp[i].length;j++){sb.append(dp[i][j]+" ");}sb.append('\n');}return sb.toString();}
	static String toString(long[][] dp){StringBuilder sb=new StringBuilder();for(int i=0;i<dp.length;i++){for(int j=0;j<dp[i].length;j++) {sb.append(dp[i][j]+" ");}sb.append('\n');}return sb.toString();}
	static String toString(double[][] dp){StringBuilder sb=new StringBuilder();for(int i = 0;i<dp.length;i++){for(int j = 0;j<dp[i].length;j++){sb.append(dp[i][j]+" ");}sb.append('\n');}return sb.toString();}
	static String toString(char[][] dp){StringBuilder sb = new StringBuilder();for(int i = 0;i<dp.length;i++){for(int j = 0;j<dp[i].length;j++){sb.append(dp[i][j]+"");}sb.append('\n');}return sb.toString();}
	static long mod(long a, long m){return(a%m+1000000L*m)%m;}
	static long mod(long num){return(num%id38+id38)%id38;}
}












