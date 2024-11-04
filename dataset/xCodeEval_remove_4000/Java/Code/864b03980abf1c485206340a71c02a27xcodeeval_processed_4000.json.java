import java.io.*;
import java.math.*;
import java.util.*;

public class id0 {
	private static final long INF = 12345678987654321L;

	public static void solve(FastIO io) {
		int N = io.nextInt();
		int M = io.nextInt();
		int P = io.nextInt();

		IncreasingMap weapons = new IncreasingMap();
		for (int i = 0; i < N; ++i) {
			int A = io.nextInt();
			int C = io.nextInt();

			weapons.add(A, C);
		}

		IncreasingMap armors = new IncreasingMap();
		for (int i = 0; i < M; ++i) {
			int B = io.nextInt();
			int C = io.nextInt();

			armors.add(B, C);
		}

		Monster[] monsters = new Monster[P];
		for (int i = 0; i < P; ++i) {
			int X = io.nextInt();
			int Y = io.nextInt();
			int Z = io.nextInt();

			monsters[i] = new Monster(X, Y, Z);
		}
		Arrays.sort(monsters, new Comparator<Monster>() {
			@Override
			public int compare(Monster lhs, Monster rhs) {
				int dd = Monster.id6.compare(lhs, rhs);
				if (dd != 0) {
					return dd;
				}
				return Monster.BY_ATTACK.compare(lhs, rhs);
			}
		});

		

		

		


		int monsterIndex = 0;
		Monster bestKill = null;
		id14 atrs = new id14();
		long bestProfit = -weapons.firstEntry().getValue() - armors.firstEntry().getValue();
		int lastArmor = 0;
		

		

		

		

		for (Map.Entry<Integer, Integer> weapon : weapons.entrySet()) {
			int weaponAttack = weapon.getKey();
			int weaponCost = weapon.getValue();
			HashSet<Integer> id3 = new HashSet<>();
			while (monsterIndex < P && monsters[monsterIndex].defense < weaponAttack) {
				Monster m = monsters[monsterIndex++];
				

				atrs.increment(m.attack, m.coins);

				Integer id7 = armors.higherKey(m.attack);
				if (id7 == null) {
					continue;
				}
				int id10 = armors.get(id7);
				long killCoins = atrs.get(0, id7 - 1);
				long id9 = killCoins - id10;
				while (true) {
					Integer lowerArmor = armors.lowerKey(id7);
					if (lowerArmor == null) {
						break;
					}
					long id11 = atrs.get(0, lowerArmor - 1) - armors.get(lowerArmor);
					if (id11 > id9) {
						break;
					}
					armors.remove(lowerArmor);
				}
				

				

				

				bestProfit = Math.max(bestProfit, id9 - weaponCost);
			}


				

				

				

				

				

				

				

				

			





			

			

			

			

			

			

			

			

			

			

			

			

			






			

			

			

			

			

			

		}
		io.println(bestProfit);

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		


		

		

		

		

		

		

		

		

		

		

		

		

		

		

	}

	private static long id15(id14 atrs, IncreasingMap armors, Monster m, int weaponCost) {
		if (m == null) {
			

			return -armors.firstEntry().getValue() - weaponCost;
		}
		Integer needArmor = armors.higherKey(m.attack);
		if (needArmor == null) {
			return -INF;
		}
		int armorCost = armors.get(needArmor);
		long totalCoins = atrs.get(0, needArmor - 1);
		return totalCoins - armorCost - weaponCost;
	}
	
	private static class MonsterPQ extends PriorityQueue<Monster> {
		public long totalCoins = 0;

		public MonsterPQ(Comparator<Monster> cmp) {
			super(cmp);
		}

		@Override
		public Monster poll() {
			Monster m = super.poll();
			totalCoins -= m.coins;
			return m;
		}

		@Override
		public boolean offer(Monster m) {
			if (!super.offer(m)) {
				return false;
			}
			totalCoins += m.coins;
			return true;
		}
	}

	private static class IncreasingMap extends TreeMap<Integer, Integer> {
		public void add(int k, int v) {
			

			while (true) {
				Integer pk = floorKey(k);
				if (pk == null || get(pk) < v) {
					break;
				}
				

				remove(pk);
			}
			Integer nk = ceilingKey(k);
			if (nk != null && get(nk) <= v) {
				return;
			}
			put(k, v);
		}
	}

	public static class Monster {
		public int defense, attack, coins;

		public Monster(int d, int a, int c) {
			defense = d;
			attack = a;
			coins = c;
		}

		@Override
		public String toString() {
			return String.format("{A: %d, D: %d, C: %d}", attack, defense, coins);
		}

		public static Comparator<Monster> BY_ATTACK = new Comparator<Monster>() {
			@Override
			public int compare(Monster lhs, Monster rhs) {
				return Integer.compare(lhs.attack, rhs.attack);
			}
		};

		public static Comparator<Monster> id6 = new Comparator<Monster>() {
			@Override
			public int compare(Monster lhs, Monster rhs) {
				return Integer.compare(lhs.defense, rhs.defense);
			}
		};
	}
	
	public static class id14 {
		private id4 root = new id4(0);

		public void insert(long k, long v) {
			root.insert(k, v);
			root = id4.rebalance(root);
		}

		public void increment(long k, long v) {
			root.increment(k, v);
			root = id4.rebalance(root);
		}

		public long get(long k) {
			return root.get(k);
		}

		public long get(long lo, long hi) {
			return root.get(lo, hi);
		}

		public static class id4 {
			private long key;
			private long val;
			private long sum;
			private int ht;

			private id4 left;
			private id4 right;

			public id4(long k) {
				this.key = k;
			}

			public void insert(long k, long v) {
				id4[] path = id13(k);
				path[0].val = v;
				updatePath(path);
			}

			public void increment(long k, long v) {
				id4[] path = id13(k);
				path[0].val += v;
				updatePath(path);
			}

			public long get(long k) {
				return get(k, k);
			}

			public long get(long lo, long hi) {
				return id1(hi) - id1(lo - 1);
			}

			private id4[] id13(long k) {
				ArrayList<id4> lst = new ArrayList<>();
				id4 curr = this;
				lst.add(curr);
				while (curr.key != k) {
					if (k < curr.key) {
						curr = curr.left = id12(curr.left, k);
					} else {
						curr = curr.right = id12(curr.right, k);
					}
					lst.add(curr);
				}
				Collections.reverse(lst);
				return lst.toArray(new id4[0]);
			}

			private static id4 rotateRight(id4 root) {
				id4 pivot = root.left;
				root.left = pivot.right;
				pivot.right = root;
				root.update();
				pivot.update();
				return pivot;
			}

			private static id4 rotateLeft(id4 root) {
				id4 pivot = root.right;
				root.right = pivot.left;
				pivot.left = root;
				root.update();
				pivot.update();
				return pivot;
			}

			private static void updatePath(id4[] path) {
				for (id4 node : path) {
					node.left = rebalance(node.left);
					node.right = rebalance(node.right);
					node.update();
				}
			}

			private void update() {
				computeHeight();
				computeSum();
			}

			private int computeHeight() {
				ht = 1 + Math.max(getHeight(left), getHeight(right));
				return ht;
			}

			private long computeSum() {
				sum = val + getSum(left) + getSum(right);
				return sum;
			}

			private long id1(long k) {
				id4 curr = this;
				long sum = 0;
				while (curr != null) {
					if (k < curr.key) {
						curr = curr.left;
					} else {
						sum += curr.val + getSum(curr.left);
						curr = curr.right;
					}
				}
				return sum;
			}

			private static id4 rebalance(id4 node) {
				if (node == null) {
					return null;
				}
				int bf = balanceFactor(node);
				if (bf > 1) {
					return rotateRight(node);
				} else if (bf < -1) {
					return rotateLeft(node);
				} else {
					return node;
				}
			}

			private static int balanceFactor(id4 root) {
				return getHeight(root.left) - getHeight(root.right);
			}

			private static id4 id12(id4 node, long k) {
				if (node != null) {
					return node;
				}
				return new id4(k);
			}

			private static int getHeight(id4 node) {
				if (node == null) {
					return 0;
				}
				return node.ht;
			}

			private static long getSum(id4 node) {
				if (node == null) {
					return 0;
				}
				return node.sum;
			}
		}
	}

	public static class BinarySearch {
        

        

        public static int firstThat(int L, int R, IntCheck check) {
            while (L < R) {
                int M = (L + R) >> 1;
                if (check.valid(M)) {
                    R = M;
                } else {
                    L = M + 1;
                }
            }
            return L;
        }
       
        

        

        public static int lastThat(int L, int R, IntCheck check) {
            int firstValue = firstThat(L, R, new IntCheck() {
                @Override
                public boolean valid(int value) {
                    return !check.valid(value);
                }
            });
            return firstValue - 1;
        }
       
        

        public static long firstThat(long L, long R, LongCheck check) {
            while (L < R) {
                long M = (L + R) >> 1;
                if (check.valid(M)) {
                    R = M;
                } else {
                    L = M + 1;
                }
            }
            return L;
        }
       
        

        

        public static long lastThat(long L, long R, LongCheck check) {
            long firstValue = firstThat(L, R, new LongCheck() {
                @Override
                public boolean valid(long value) {
                    return !check.valid(value);
                }
            });
            return firstValue - 1;
        }
       
        public static interface LongCheck {
            public boolean valid(long value);
        }
       
        public static interface IntCheck {
            public boolean valid(int value);
        }
	}

	public static class FastIO {
		private InputStream reader;
		private PrintWriter writer;

		private byte[] buf = new byte[1024];
		private int curChar;
		private int numChars;

		public FastIO(InputStream r, OutputStream w) {
			reader = r;
			writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(w)));
		}

		public int read() {
			if (numChars == -1)
				throw new InputMismatchException();
			if (curChar >= numChars) {
				curChar = 0;
				try {
					numChars = reader.read(buf);
				} catch (IOException e) {
					throw new InputMismatchException();
				}
				if (numChars <= 0)
					return -1;
			}
			return buf[curChar++];
		}

		public String nextLine() {
			int c = read();
			while (id2(c))
				c = read();
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = read();
			} while (!id8(c));
			return res.toString();
		}

		public String nextString() {
			int c = read();
			while (id2(c))
				c = read();
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = read();
			} while (!id2(c));
			return res.toString();
		}

		public long nextLong() {
			int c = read();
			while (id2(c))
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
			} while (!id2(c));
			return res * sgn;
		}

		public int nextInt() {
			int c = read();
			while (id2(c))
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
			} while (!id2(c));
			return res * sgn;
		}

		

		public double nextDouble() {
			return Double.parseDouble(nextString());
		}

		public int[] id5(int n) {
			return id5(n, 0);
		}

		public int[] id5(int n, int off) {
			int[] arr = new int[n + off];
			for (int i = 0; i < n; i++) {
				arr[i + off] = nextInt();
			}
			return arr;
		}

		public long[] id16(int n) {
			return id16(n, 0);
		}

		public long[] id16(int n, int off) {
			long[] arr = new long[n + off];
			for (int i = 0; i < n; i++) {
				arr[i + off] = nextLong();
			}
			return arr;
		}

		private boolean id2(int c) {
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}

		private boolean id8(int c) {
			return c == '\n' || c == '\r' || c == -1;
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

		public void printArray(int[] arr) {
			for (int i = 0; i < arr.length; i++) {
				if (i != 0) {
					writer.print(' ');
				}
				writer.print(arr[i]);
			}
		}

		public void printArray(long[] arr) {
			for (int i = 0; i < arr.length; i++) {
				if (i != 0) {
					writer.print(' ');
				}
				writer.print(arr[i]);
			}
		}

		public void printlnArray(int[] arr) {
			printArray(arr);
			writer.println();
		}

		public void printlnArray(long[] arr) {
			printArray(arr);
			writer.println();
		}

		public void printf(String format, Object... args) {
			print(String.format(format, args));
		}

		public void flush() {
			writer.flush();
		}
	}

	public static void main(String[] args) {
		FastIO io = new FastIO(System.in, System.out);
		solve(io);
		io.flush();
	}
}
