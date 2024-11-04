import java.io.*;
import java.math.*;
import java.util.*;

public class test {

	public static void main(String[] args) {


		int test = 1;

		for (int cases = 0; cases < test; cases++) {
			int n = fs.nextInt();
			int m = fs.nextInt();
			HashMap<String, String> hm1 = new HashMap<String, String>();
			HashMap<String, String> hm2 = new HashMap<String, String>();

			for (int i = 0; i < m; i++) {
				String a = fs.next();
				String b = fs.next();
				hm1.put(a, b);
				hm2.put(b, a);
			}
			for (int i = 0; i < n; i++) {
				String s = fs.next();
				String a = s;
				if (hm1.containsKey(a)) {
					String b1 = a;
					String b2 = hm1.get(a);
					if (b1.length() <= b2.length())
						op.print(b1 + " ");
					else
						op.print(b2 + " ");
				} else {
					String b1 = hm2.get(a);
					String b2 = a;
					if (b1.length() <= b2.length()) {
						op.print(b1 + " ");
					} else {
						op.print(b2 + " ");
					}
				}
			}
			op.flush();
		}
	}

	static int id6(int a, int b) {
		int count = 0;
		for (int i = 0; i < 32; i++) {
			if (((a >> i) & 1) != ((b >> i) & 1)) {
				++count;
			}
		}
		return count;
	}

	static int gcd(int a, int b) {
		if (b == 0)
			return a;
		return gcd(b, a % b);
	}

	static void id4(HashMap<String, Integer> hm) {

		List<Map.Entry<String, Integer>> capitalList = new LinkedList<>(hm.entrySet());

		Collections.sort(capitalList, new Comparator<Map.Entry<String, Integer>>() {
			public int compare(Map.Entry<String, Integer> o1, Map.Entry<String, Integer> o2) {
				return (o1.getValue()).compareTo(o2.getValue());
			}
		});
		HashMap<String, Integer> result = new HashMap<>();
		for (Map.Entry<String, Integer> entry : capitalList) {
			result.put(entry.getKey(), entry.getValue());
		}
	}

	static boolean id2(long num) {
		if ((num & (num - 1)) == 0)
			return true;
		return false;
	}

	static boolean isPrime(int n) {
		

		if (n <= 1)
			return false;
		if (n <= 3)
			return true;

		

		

		if (n % 2 == 0 || n % 3 == 0)
			return false;

		for (int i = 5; i * i <= n; i = i + 6)
			if (n % i == 0 || n % (i + 2) == 0)
				return false;

		return true;
	}

	static class Graph {
		HashMap<Integer, LinkedList<Integer>> hm = new HashMap<Integer, LinkedList<Integer>>();

		private void addVertex(int vertex) {
			hm.put(vertex, new LinkedList<>());
		}

		private void addEdge(int source, int dest, boolean bi) {
			if (!hm.containsKey(source))
				addVertex(source);
			if (!hm.containsKey(dest))
				addVertex(dest);
			hm.get(source).add(dest);
			if (bi) {
				hm.get(dest).add(source);
			}
		}

		private boolean uniCycle(int i, HashSet<Integer> visited, int parent) {
			visited.add(i);
			LinkedList<Integer> list = hm.get(i);
			Iterator<Integer> it = list.iterator();
			while (it.hasNext()) {
				Integer integer = (Integer) it.next();
				if (!visited.contains(integer)) {
					if (uniCycle(integer, visited, i))
						return true;
				} else if (integer != parent) {
					return true;
				}
			}
			return false;
		}

		private boolean id7() {
			HashSet<Integer> visited = new HashSet<Integer>();
			Set<Integer> set = hm.keySet();
			for (Integer integer : set) {
				if (!visited.contains(integer)) {
					if (uniCycle(integer, visited, -1)) {
						return true;
					}
				}
			}
			return false;
		}

		private boolean id1(int i, HashSet<Integer> visited, HashSet<Integer> countered) {
			if (countered.contains(i))
				return true;
			if (visited.contains(i))
				return false;
			visited.add(i);
			countered.add(i);
			LinkedList<Integer> list = hm.get(i);
			Iterator<Integer> it = list.iterator();
			while (it.hasNext()) {
				Integer integer = (Integer) it.next();
				if (id1(integer, visited, countered)) {
					return true;
				}
			}
			countered.remove(i);
			return false;
		}

		private boolean id5() {
			HashSet<Integer> visited = new HashSet<Integer>();
			HashSet<Integer> countered = new HashSet<Integer>();
			Set<Integer> set = hm.keySet();
			for (Integer integer : set) {
				if (id1(integer, visited, countered)) {
					return true;
				}
			}
			return false;
		}
	}

	static class Node {
		Node left, right;
		int data;

		public Node(int data) {
			this.data = data;
		}

		public void insert(int val) {
			if (val <= data) {
				if (left == null) {
					left = new Node(val);
				} else {
					left.insert(val);
				}
			} else {
				if (right == null) {
					right = new Node(val);
				} else {
					right.insert(val);
				}
			}
		}

		public boolean contains(int val) {
			if (data == val) {
				return true;
			} else if (val < data) {
				if (left == null) {
					return false;
				} else {
					return left.contains(val);
				}
			} else {
				if (right == null) {
					return false;
				} else {
					return right.contains(val);
				}
			}
		}

		public void inorder() {
			if (left != null) {
				left.inorder();
			}
			System.out.print(data + " ");
			if (right != null) {
				right.inorder();
			}
		}

		public int maxDepth() {
			if (left == null)
				return 0;
			if (right == null)
				return 0;
			else {
				int ll = left.maxDepth();
				int rr = right.maxDepth();
				if (ll > rr)
					return (ll + 1);
				else
					return (rr + 1);
			}
		}

		public int countNodes() {
			if (left == null)
				return 1;
			if (right == null)
				return 1;
			else {
				return left.countNodes() + right.countNodes() + 1;
			}
		}

		public void preorder() {
			System.out.print(data + " ");
			if (left != null) {
				left.inorder();
			}

			if (right != null) {
				right.inorder();
			}

		}

		public void postorder() {
			if (left != null) {
				left.inorder();
			}

			if (right != null) {
				right.inorder();
			}
			System.out.print(data + " ");

		}

		public void levelorder(Node node) {
			LinkedList<Node> ll = new LinkedList<Node>();
			ll.add(node);
			getorder(ll);

		}

		public void getorder(LinkedList<Node> ll) {
			while (!ll.isEmpty()) {
				Node node = ll.poll();
				System.out.print(node.data + " ");
				if (node.left != null)
					ll.add(node.left);
				if (node.right != null)
					ll.add(node.right);
			}
		}
	}

	static class FastReader {
		BufferedReader br;
		StringTokenizer st;

		public FastReader() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		String next() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
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

		String nextLine() {
			String str = "";
			try {
				str = br.readLine();
			} catch (IOException e) {
				e.printStackTrace();
			}
			return str;
		}
	}

	static class Pair {
		int first, second;

		public Pair(int first, int second) {
			this.first = first;
			this.second = second;
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
				if (i != 0)
					writer.print(' ');
				writer.print(objects[i]);
			}
		}

		public void printLine(Object... objects) {
			print(objects);
			writer.println();
		}

		public void close() {
			writer.close();
		}

		public void flush() {
			writer.flush();
		}

	}

	private static final Scanner sc = new Scanner(System.in);
	private static final FastReader fs = new FastReader();
	private static final OutputWriter op = new OutputWriter(System.out);

	static int[] id0(int n) {
		int ar[] = new int[n];
		for (int i = 0; i < n; i++) {
			ar[i] = fs.nextInt();
		}
		return ar;
	}

	static long[] id3(int n) {
		long ar[] = new long[n];
		for (int i = 0; i < n; i++) {
			ar[i] = fs.nextLong();
		}
		return ar;
	}

	static int[][] id9(int n, int m) {
		int ar[][] = new int[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				ar[i][j] = fs.nextInt();
			}
		}
		return ar;
	}

	static Pair[] id8(int n) {
		Pair ar[] = new Pair[n];
		for (int i = 0; i < n; i++) {
			ar[i] = new Pair(fs.nextInt(), fs.nextInt());
		}
		return ar;
	}

	static void printarray(int ar[]) {
		for (int i : ar) {
			op.print(i + " ");
		}
		op.flush();
	}

	static int fact(int n) {
		int fact = 1;
		for (int i = 2; i <= n; i++) {
			fact *= i;
		}
		return fact;
	}




	


}


















































































































































































































































































































































































































































































































































































































































































































































































































































































































































