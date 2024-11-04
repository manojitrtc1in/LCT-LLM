	import java.io.*;
	import java.math.*;
	import java.util.*;
	
	public class test {
	
		static int INF = 1000000007;
	
		public static void main(String[] args) {
			int test = fs.nextInt();
			

	

			for (int cases = 0; cases < test; cases++) {
				char ar[] = fs.next().toCharArray();
				String s = String.valueOf(ar);
				int t = 0, w = 0, o = 0, n = 0, e = 0;
				ArrayList<Integer> al = new ArrayList<Integer>();
				int length = ar.length;
				for (int i = 0; i < length;) {
					if (ar[i] == 't') {
						t = 1;
						int j = i + 1;
						for (; j < length; j++) {
							if (ar[j] == 't') {
								++t;
							} else {
								break;
							}
						}
						if (j < length && ar[j] == 'w') {
							int k = j + 1;
							w = 1;
							for (; k < length; k++) {
								if (ar[k] == 'w') {
									++w;
								} else {
									break;
								}
							}
							if (w == 1 && k < length && ar[k] == 'o') {
								int l = k + 1;
								o = 1;
								for (; l < length; l++) {
									if (ar[l] == 'o') {
										++o;
									} else {
										break;
									}
								}
								if (l < length && ar[l] == 'n') {
									n = 1;
									int p = l + 1;
									for (; p < length; p++) {
										if (ar[p] == 'n') {
											++n;
										} else {
											break;
										}
									}
									if (n == 1 && p < length && ar[p] == 'e') {
										e = 1;
										int a = p + 1;
										for (; a < length; a++) {
											if (ar[a] == 'e') {
												++e;
											} else {
												break;
											}
										}
										int min1 = Integer.min(t, Integer.min(w, o));
										int min2 = Integer.min(o, Integer.min(n, e));
										int start = 0;
										if (min1 == min2 && min1 == o) {
											start = a - e - n;
											while (min1 > 0) {
												al.add(start);
												--start;
												--min1;
											}
										} else {
											int start1 = 0;
											int start2 = 0;


											if (min2 == o) {
												start2 = a - e - n;
											} else if (min2 == n) {
												start2 = a - e;
											} else if (min2 == e) {
												start2 = a - 1;
											}
	

											while (min2 > 0) {
												al.add(start2);
												start2--;
												min2--;
											}
											if (min1 == t) {
												start1 = a - e - n - o - w;
											} else if (min1 == w) {
												start1 = a - e - n - o;
											} else if (min1 == o) {
												start1 = a - e - n;
											}
	

											while (min1 > 0) {
												al.add(start1);
												start1--;
												min1--;
											}
										}
										t = 0;
										w = 0;
										o = 0;
										n = 0;
										e = 0;
										i = a;
									} else {
										int min = Integer.min(t, Integer.min(w, o));
										int start = 0;
										if (min == t) {
											start = p - n - o - w;
										} else if (min == w) {
											start = p - n - o;
										} else if (min == o) {
											start = p - n;
										}
										while (min > 0) {
											al.add(start);
											min--;
											start--;
										}
										t = 0;
										w = 0;
										o = 0;
										n = 0;
										e = 0;
										i = p;
									}
									

								} else {
									

									int min = Integer.min(t, Integer.min(w, o));
									int start = 0;
									if (min == t) {
										start = l - o - w;
									} else if (min == w) {
										start = l - o;
									} else if (min == o) {
										start = l - 1;
									}
									while (min > 0) {
										al.add(start);
										min--;
										start--;
									}
									t = 0;
									w = 0;
									o = 0;
									n = 0;
									e = 0;
									i = l;
								}
							} else {
								t = 0;
								w = 0;
								o = 0;
								n = 0;
								e = 0;
								i = k;
							}
						} else {
							t = 0;
							w = 0;
							o = 0;
							n = 0;
							e = 0;
							i = j;
						}
					} else if (ar[i] == 'o') {
						o = 1;
						int j = i + 1;
						for (; j < length; j++) {
							if (ar[j] == 'o') {
								++o;
							} else {
								break;
							}
						}
						if (j < length && ar[j] == 'n') {
							int k = j + 1;
							n = 1;
							for (; k < length; k++) {
								if (ar[k] == 'n') {
									++n;
								} else {
									break;
								}
							}
							if (n == 1 && k < length && ar[k] == 'e') {
								int l = k + 1;
								e = 1;
								for (; l < length; l++) {
									if (ar[l] == 'e') {
										++e;
									} else {
										break;
									}
								}
								int min = Integer.min(o, Integer.min(n, e));
								int start = 0;
								if (min == o) {
									start = l - n - e;
								} else if (min == n) {
									start = l - e;
								} else if (min == e) {
									start = l - 1;
								}
								while (min > 0) {
									al.add(start);
									min--;
									start--;
								}
								o = 0;
								n = 0;
								e = 0;
								i = l;
							} else {
								o = 0;
								n = 0;
								e = 0;
								i = k;
							}
						} else {
							i = j;
							o = 0;
							n = 0;
							e = 0;
						}
					} else {
						++i;
					}
				}
				System.out.println(al.size());
				for (Integer integer : al) {
					System.out.print(integer + " ");
				}
				System.out.println();
			}
	
		}
	
		static boolean isBalanced(String s) {
			Stack<Character> st = new Stack<Character>();
			for (int i = 0; i < s.length(); i++) {
				if (s.charAt(i) == '0' && st.isEmpty()) {
					return false;
				} else {
					if (s.charAt(i) == '1') {
						st.push(s.charAt(i));
					} else {
						char x = st.peek();
						if (x == '1') {
							st.pop();
						}
					}
				}
			}
			if (st.isEmpty()) {
				return true;
			} else {
				return false;
			}
		}
	
		static boolean id4(String str1, String str2, int m, int n) {
			if (m == 0)
				return true;
			if (n == 0)
				return false;
			if (str1.charAt(m - 1) == str2.charAt(n - 1))
				return id4(str1, str2, m - 1, n - 1);
			return id4(str1, str2, m, n - 1);
		}
	
		static long power(long x, long y, long p) {
			long res = 1;
			x = x % p;
			while (y > 0) {
				if (y % 2 == 1)
					res = (res * x) % p;
				y = y >> 1;
				x = (x * x) % p;
			}
			return res;
		}
	
		static long modInverse(long n, long p) {
			return power(n, p - 2, p);
		}
	
		static long id9(long n, long r, long p) {
			long ans1 = 1;
			long i = n;
			long k = r;
			while (k > 0) {
				ans1 = mul(ans1, i, p);
				i--;
				k--;
			}
			long ans2 = 1;
			while (r > 0) {
				ans2 = mul(ans2, r, p);
				r--;
			}
			r = modInverse(ans2, p);
			ans1 = mul(ans1, r, p);
			return ans1;
		}
	
		static long facCalc(long total) {
			long ans = 1;
			for (long i = 2; i <= total; i++) {
				ans = mul(ans, i, INF);
			}
			return ans;
		}
	
		static long mul(long a, long b, long p) {
			return ((a % p) * (b % p)) % p;
		}
	
		static void sieve() {
			boolean prime[] = new boolean[101];
			Arrays.fill(prime, true);
			prime[1] = false;
			for (int i = 2; i * i <= prime.length - 1; i++) {
				for (int j = i * i; j <= prime.length - 1; j += i) {
					prime[j] = false;
				}
			}
		}
	
		public static int[] id8(int[] f) {
			return id8(f, f.length);
		}
	
		public static int[] id8(int[] f, int n) {
			int[] to = new int[n];
			{
				int[] b = new int[65537];
				for (int i = 0; i < n; i++)
					b[1 + (f[i] & 0xffff)]++;
				for (int i = 1; i <= 65536; i++)
					b[i] += b[i - 1];
				for (int i = 0; i < n; i++)
					to[b[f[i] & 0xffff]++] = f[i];
				int[] d = f;
				f = to;
				to = d;
			}
			{
				int[] b = new int[65537];
				for (int i = 0; i < n; i++)
					b[1 + (f[i] >>> 16)]++;
				for (int i = 1; i <= 65536; i++)
					b[i] += b[i - 1];
				for (int i = 0; i < n; i++)
					to[b[f[i] >>> 16]++] = f[i];
				int[] d = f;
				f = to;
				to = d;
			}
			return f;
		}
	
		static void printArray(int ar[]) {
			System.out.println(Arrays.toString(ar));
		}
	
		static class Pair {
			int first, second;
	
			public Pair(int first, int second) {
				this.first = first;
				this.second = second;
			}
	
		}
	
		static class LongPair {
			long first;
			long second;
	
			LongPair(long a, long b) {
				this.first = a;
				this.second = b;
			}
	
		}
	
		static long id1(long a, long b, long c) {
			long x = 1;
			long y = a;
			while (b > 0) {
				if (b % 2 == 1) {
					x = (x * y) % c;
				}
				y = (y * y) % c; 

				b /= 2;
			}
			return (long) x % c;
		}
	
		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

	
		static int gcd(int a, int b) {
			if (b == 0)
				return a;
			return gcd(b, a % b);
		}
	
		static void id5(HashMap<Integer, Integer> hm) {
	
			List<Map.Entry<Integer, Integer>> capitalList = new LinkedList<>(hm.entrySet());
	
			Collections.sort(capitalList, new Comparator<Map.Entry<Integer, Integer>>() {
				public int compare(Map.Entry<Integer, Integer> o1, Map.Entry<Integer, Integer> o2) {
					return (o1.getValue()).compareTo(o2.getValue());
				}
			});
			HashMap<Integer, Integer> result = new HashMap<>();
			for (Map.Entry<Integer, Integer> entry : capitalList) {
				result.put(entry.getKey(), entry.getValue());
			}
		}
	
		static boolean id3(long num) {
			if ((num & (num - 1)) == 0)
				return true;
			return false;
		}
	
		static void primeFactors(int n) {
			while (n % 2 == 0) {
				System.out.print(2 + " ");
				n /= 2;
			}
			for (int i = 3; i <= Math.sqrt(n); i += 2) {
				while (n % i == 0) {
					System.out.print(i + " ");
					n /= i;
				}
			}
			if (n > 2)
				System.out.print(n);
		}
	
		static boolean isPrime(long n) {
			

			if (n <= 1)
				return false;
			if (n <= 3)
				return true;
			if (n % 2 == 0 || n % 3 == 0)
				return false;
	
			long sq = (long) Math.sqrt(n);
			for (int i = 5; i <= sq; i = i + 6)
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
	
			private boolean id2(int i, HashSet<Integer> visited, HashSet<Integer> countered) {
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
					if (id2(integer, visited, countered)) {
						return true;
					}
				}
				countered.remove(i);
				return false;
			}
	
			Boolean id0(int s, int d, int k) {
				if (hm.isEmpty()) {
					return false;
				}
				LinkedList<Integer> temp;
				boolean visited[] = new boolean[k];
				LinkedList<Integer> queue = new LinkedList<Integer>();
				visited[s] = true;
				queue.add(s);
				Iterator<Integer> i;
				while (queue.size() != 0) {
					s = queue.poll();
					int n;
					i = hm.get(s).listIterator();
	
					

					

					

					while (i.hasNext()) {
						n = i.next();
	
						

						

						if (n == d)
							return true;
	
						

						if (!visited[n]) {
							visited[n] = true;
							queue.add(n);
						}
					}
				}
	
				

				return false;
			}
	
			private boolean id6() {
				HashSet<Integer> visited = new HashSet<Integer>();
				HashSet<Integer> countered = new HashSet<Integer>();
				Set<Integer> set = hm.keySet();
				for (Integer integer : set) {
					if (id2(integer, visited, countered)) {
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
	
		private static final FastReader fs = new FastReader();
		private static final OutputWriter op = new OutputWriter(System.out);
	}