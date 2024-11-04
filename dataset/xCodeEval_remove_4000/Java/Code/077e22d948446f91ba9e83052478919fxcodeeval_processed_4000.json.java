import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Optional;
import java.util.Set;
import java.util.stream.IntStream;

public class Main {
	public static void main(String[] args) {
		Main main = new Main();
		main.solve();
	}

	private void solve() {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int i = 0; i < t; i++) {
			String orig_s = sc.next();
			StringBuilder sb = new StringBuilder();
			for (char c : orig_s.toCharArray()) {
				sb.append(c);
				sb.append("_");
			}
			String ds = sb.substring(0, sb.length() - 1);
			char[] s = ds.toCharArray();
			int same_index = 0;
			for (; same_index < (s.length + 1) / 2; same_index++) {
				if (s[same_index] != s[s.length - 1 - same_index]) {
					break;
				}
			}
			same_index--;
			if (same_index >= (s.length - 1) / 2) {
				System.out.println(orig_s);
			} else {
				String rest = ds.substring(same_index + 1, ds.length() - same_index - 1);
				char[] rs = rest.toCharArray();
				int[] radius = new int[rs.length];
				int l = 0;
				int j = 0;
				while (l < rs.length) {
					while (l - j >= 0 && l + j < rs.length && rs[l - j] == rs[l + j]) {
						j++;
					}
					radius[l] = j;
					int k = 1;
					while (l - k >= 0 && l + k < rs.length && k + radius[l - k] < j) {
						radius[l + k] = radius[l - k];
						k++;
					}
					l += k;
					j -= k;
				}
				int max = -1;
				for (int k = 0; k < rs.length; k++) {
					if (radius[k] == k + 1) {
						max = k + 1;
					}
				}
				boolean id6 = false;
				for (int k = 1; k <= rs.length; k++) {
					if (radius[rs.length - k] == k && max < k) {
						max = k;
						id6 = true;
					}
				}
				System.out.print(orig_s.substring(0, (same_index + 1) / 2));
				if (id6) {
					System.out.print(rest.substring(rest.length() - max * 2 + 1).replace("_", ""));
				} else {
					System.out.print(rest.substring(0, max * 2 - 1).replace("_", ""));
				}
				System.out.println(orig_s.substring(orig_s.length() - (same_index + 1) / 2));
			}
		}
	}

	class Scanner {
		private InputStream in;
		private byte[] buffer = new byte[1024];
		private int index;
		private int length;

		public Scanner(InputStream in) {
			this.in = in;
		}

		private boolean id20(int c) {
			return '!' <= c && c <= '~';
		}

		private boolean isDigit(int c) {
			return '0' <= c && c <= '9';
		}

		private boolean id19() {
			if (index < length) {
				return true;
			} else {
				try {
					length = in.read(buffer);
					index = 0;
				} catch (IOException e) {
					e.printStackTrace();
				}
				return length > 0;
			}
		}

		private boolean hasNext() {
			while (id19() && !id20(buffer[index])) {
				index++;
			}
			return id19();
		}

		private int readByte() {
			return id19() ? buffer[index++] : -1;
		}

		public String next() {
			if (!hasNext()) {
				throw new RuntimeException("no input");
			}
			StringBuilder sb = new StringBuilder();
			int b = readByte();
			while (id20(b)) {
				sb.appendCodePoint(b);
				b = readByte();
			}
			return sb.toString();
		}

		public long nextLong() {
			if (!hasNext()) {
				throw new RuntimeException("no input");
			}
			long value = 0L;
			boolean minus = false;
			int b = readByte();
			if (b == '-') {
				minus = true;
				b = readByte();
			}
			while (id20(b)) {
				if (isDigit(b)) {
					value = value * 10 + (b - '0');
				}
				b = readByte();
			}
			return minus ? -value : value;
		}

		public int nextInt() {
			return (int)nextLong();
		}

		public double nextDouble() {
			return Double.parseDouble(next());
		}
	}

	interface CombCalculator {
		long comb(int n, int m);
	}

	interface id1 {
		int get(int n);
	}

	
	class id2 implements id1 {
		int size;
		int[] id11;

		public id2(int size) {
			this.size = size;
			id11 = new int[size];

			id11[0] = 0;
			id11[1] = 1;
			for (int i = 2; i < size; i++) {
				id11[i] = 1;
			}
			for (int i = 2; i * i < size; i++) {
				for (int k = 1; i * i * k < size; k++) {
					id11[i * i * k] *= 0;
				}
			}

			for (int i = 2; i < size; i++) {
				if (id11[i] == 1) {
					for (int k = 1; i * k < size; k++) {
						id11[i * k] *= -2;
					}
				}
				if (id11[i] > 1) {
					id11[i] = 1;
				}
				if (id11[i] < -1) {
					id11[i] = -1;
				}
			}
		}

		@Override
		public int get(int n) {
			if (n > size) {
				throw new RuntimeException("n is greater than size.");
			}
			if (n < 0) {
				return 0;
			}
			return id11[n];
		}
	}

	
	class id8 implements id1 {
		@Override
		public int get(int n) {
			if (n <= 0) {
				return 0;
			}
			if (n == 1) {
				return 1;
			}
			int num = 0;
			for (int i = 2; i < n; i++) {
				if (n % i == 0) {
					n /= i;
					num++;
					if (n % i == 0) {
						return 0;
					}
				}
			}
			return num % 2 == 0 ? -1 : 1;
		}
	}

	
	class id4 implements CombCalculator {
		int size;
		long[] id5;
		long[] id3;
		long mod;

		public id4(int size, long mod) {
			this.size = size;
			id5 = new long[size + 1];
			id3 = new long[size + 1];
			this.mod = mod;

			id5[0] = 1L;
			for (int i = 1; i <= size; i++) {
				id5[i] = (id5[i - 1] * i) % mod;
			}
			id3[size] = inverse(id5[size], mod);
			for (int i = size - 1; i >= 0; i--) {
				id3[i] = (id3[i + 1] * (i + 1)) % mod;
			}
		}

		private long inverse(long n, long mod) {
			return pow(n, mod - 2, mod);
		}

		private long pow(long n, long p, long mod) {
			if (p == 0) {
				return 1L;
			}
			long half = pow(n, p / 2, mod);
			long ret = (half * half) % mod;
			if (p % 2 == 1) {
				ret = (ret * n) % mod;
			}
			return ret;
		}

		@Override
		public long comb(int n, int m) {
			if (n > size) {
				throw new RuntimeException("n is greater than size.");
			}
			if (n < 0 || m < 0 || n < m) {
				return 0L;
			}
			return (((id5[n] * id3[m]) % mod) * id3[n - m]) % mod;
		}
	}

	
	class id10 implements CombCalculator {
		long[][] table;
		int size;

		public id10(int size, long mod) {
			this.size = size;
			table = new long[size + 1][];

			table[0] = new long[1];
			table[0][0] = 1L;
			for (int n = 1; n <= size; n++) {
				table[n] = new long[n + 1];
				table[n][0] = 1L;
				for (int m = 1; m < n; m++) {
					table[n][m] = (table[n - 1][m - 1] + table[n - 1][m]) % mod;
				}
				table[n][n] = 1L;
			}
		}

		@Override
		public long comb(int n, int m) {
			if (n > size) {
				throw new RuntimeException("n is greater than size.");
			}
			if (n < 0 || m < 0 || n < m) {
				return 0L;
			}
			return table[n][m];
		}
	}

	interface Graph {
		void link(int from, int to, long cost);
		Optional<Long> getCost(int from, int to);
		int id13();
	}

	interface FlowResolver {
		long maxFlow(int from, int to);
	}

	
	class ArrayGraph implements Graph {
		private Long[][] costArray;
		private int vertexNum;

		public ArrayGraph(int n) {
			costArray = new Long[n][];
			for (int i = 0; i < n; i++) {
				costArray[i] = new Long[n];
			}
			vertexNum = n;
		}

		@Override
		public void link(int from, int to, long cost) {
			costArray[from][to] = new Long(cost);
		}

		@Override
		public Optional<Long> getCost(int from, int to) {
			return Optional.ofNullable(costArray[from][to]);
		}

		@Override
		public int id13() {
			return vertexNum;
		}
	}

	
	class id7 implements FlowResolver {
		private Graph graph;
		public id7(Graph graph) {
			this.graph = graph;
		}

		
		public long maxFlow(int from, int to) {
			long sum = 0L;
			long currentFlow;
			do {
				currentFlow = flow(from, to, Long.MAX_VALUE / 3, new boolean[graph.id13()]);
				sum += currentFlow;
			} while (currentFlow > 0);
			return sum;
		}

		
		private long flow(int from, int to, long current_flow, boolean[] passed) {
			passed[from] = true;
			if (from == to) {
				return current_flow;
			}
			for (int id = 0; id < graph.id13(); id++) {
				if (passed[id]) {
					continue;
				}
				Optional<Long> cost = graph.getCost(from, id);
				if (cost.orElse(0L) > 0) {
					long nextFlow = current_flow < cost.get() ? current_flow : cost.get();
					long returnFlow = flow(id, to, nextFlow, passed);
					if (returnFlow > 0) {
						graph.link(from, id, cost.get() - returnFlow);
						graph.link(id, from, graph.getCost(id, from).orElse(0L) + returnFlow);
						return returnFlow;
					}
				}
			}
			return 0L;
		}
	}

	
	class id9 {
		private long[] array;

		public id9(int size) {
			this.array = new long[size + 1];
		}

		
		public void add(int index, long value) {
			for (int i = index; i < array.length; i += (i & -i)) {
				array[i] += value;
			}
		}

		
		public long getSum(int index) {
			long sum = 0L;
			for (int i = index; i > 0; i -= (i & -i)) {
				sum += array[i];
			}
			return sum;
		}
	}

	
	class id12 {
		private long[][] array;

		public id12(int size1, int size2) {
			this.array = new long[size1 + 1][];
			for (int i = 1; i <= size1; i++) {
				this.array[i] = new long[size2 + 1];
			}
		}

		
		public void add(int index1, int index2, long value) {
			for (int i1 = index1; i1 < array.length; i1 += (i1 & -i1)) {
				for (int i2 = index2; i2 < array.length; i2 += (i2 & -i2)) {
					array[i1][i2] += value;
				}
			}
		}

		
		public long getSum(int index1, int index2) {
			long sum = 0L;
			for (int i1 = index1; i1 > 0; i1 -= (i1 & -i1)) {
				for (int i2 = index2; i2 > 0; i2 -= (i2 & -i2)) {
					sum += array[i1][i2];
				}
			}
			return sum;
		}
	}

	interface UnionFind {
		void union(int A, int B);
		boolean judge(int A, int B);
		Set<Integer> getSet(int id);
	}

	
	class id17 extends id15 {
		Map<Integer, Set<Integer>> map;
		public id17(int size) {
			super(size);
			map = new HashMap<>();
			for (int i = 0; i < size; i++) {
				map.put(i, new HashSet<>());
				map.get(i).add(i);
			}
		}

		@Override
		protected void unionTo(int source, int dest) {
			super.unionTo(source, dest);
			map.get(dest).addAll(map.get(source));
		}

		@Override
		public Set<Integer> getSet(int id) {
			return map.get(root(id));
		}
	}

	
	class id15 implements UnionFind {
		int[] parent;
		int[] rank;
		int size;
		public id15(int size) {
			parent = new int[size];
			for (int i = 0; i < size; i++) {
				parent[i] = i;
			}
			rank = new int[size];
			this.size = size;
		}

		@Override
		public void union(int A, int B) {
			int rootA = root(A);
			int rootB = root(B);
			if (rootA != rootB) {
				if (rank[rootA] < rank[rootB]) {
					unionTo(rootA, rootB);
				} else {
					unionTo(rootB, rootA);
					if (rank[rootA] == rank[rootB]) {
						rank[rootA]++;
					}
				}
			}
		}

		protected void unionTo(int source, int dest) {
			parent[source] = dest;
		}

		@Override
		public boolean judge(int A, int B) {
			return root(A) == root(B);
		}

		@Override
		public Set<Integer> getSet(int id) {
			Set<Integer> set = new HashSet<>();
			IntStream.range(0, size).filter(i -> judge(i, id)).forEach(set::add);
			return set;
		}

		protected int root(int id) {
			if (parent[id] == id) {
				return id;
			}
			parent[id] = root(parent[id]);
			return parent[id];
		}
	}

	
	class id0 {
		boolean[] id18;
		List<Integer> primes;

		
		public id0(int limit) {
			if (limit > 10000000) {
				System.err.println("上限の値が高すぎるため素数ユーティリティの初期化でTLEする可能性が大変高いです");
			}
			primes = new ArrayList<>();
			id18 = new boolean[limit];
			if (limit > 2) {
				primes.add(2);
				id18[2] = true;
			}

			for (int i = 3; i < limit; i += 2) {
				if (isPrime(i, primes)) {
					primes.add(i);
					id18[i] = true;
				}
			}
		}

		public List<Integer> id16() {
			return primes;
		}

		public boolean isPrime(int n) {
			return id18[n];
		}

		private boolean isPrime(int n, List<Integer> primes) {
			for (int prime : primes) {
				if (n % prime == 0) {
					return false;
				}
				if (prime > Math.sqrt(n)) {
					break;
				}
			}
			return true;
		}
	}

	interface BitSet {
		void set(int index, boolean bit);
		boolean get(int index);
		void shiftRight(int num);
		void shiftLeft(int num);
		void or(BitSet bitset);
		void and(BitSet bitset);
	}

	
	class LongBit implements BitSet {
		long[] bitArray;

		public LongBit(int size) {
			bitArray = new long[((size + 63) / 64)];
		}

		@Override
		public void set(int index, boolean bit) {
			int segment = index / 64;
			int inIndex = index % 64;
			if (bit) {
				bitArray[segment] |= 1L << inIndex;
			} else {
				bitArray[segment] &= ~(1L << inIndex);
			}
		}

		@Override
		public boolean get(int index) {
			int segment = index / 64;
			int inIndex = index % 64;
			return (bitArray[segment] & (1L << inIndex)) != 0L;
		}

		@Override
		public void shiftRight(int num) {
			int shiftSeg = num / 64;
			int id14 = num % 64;
			for (int segment = 0; segment < bitArray.length; segment++) {
				int sourceSeg = segment + shiftSeg;
				if (sourceSeg < bitArray.length) {
					bitArray[segment] = bitArray[sourceSeg] >>> id14;
					if (id14 > 0 && sourceSeg + 1 < bitArray.length) {
						bitArray[segment] |= bitArray[sourceSeg + 1] << (64 - id14);
					}
				} else {
					bitArray[segment] = 0L;
				}
			}
		}

		@Override
		public void shiftLeft(int num) {
			int shiftSeg = num / 64;
			int id14 = num % 64;
			for (int segment = bitArray.length - 1; segment >= 0; segment--) {
				int sourceSeg = segment - shiftSeg;
				if (sourceSeg >= 0) {
					bitArray[segment] = bitArray[sourceSeg] << id14;
					if (id14 > 0 && sourceSeg > 0) {
						bitArray[segment] |= bitArray[sourceSeg - 1] >>> (64 - id14);
					}
				} else {
					bitArray[segment] = 0L;
				}
			}
		}

		public long getLong(int segment) {
			return bitArray[segment];
		}

		@Override
		public void or(BitSet bitset) {
			if (!(bitset instanceof LongBit)) {
				return;
			}
			for (int segment = 0; segment < bitArray.length; segment++) {
				bitArray[segment] |= ((LongBit)bitset).getLong(segment);
			}
		}

		@Override
		public void and(BitSet bitset) {
			if (!(bitset instanceof LongBit)) {
				return;
			}
			for (int segment = 0; segment < bitArray.length; segment++) {
				bitArray[segment] &= ((LongBit)bitset).getLong(segment);
			}
		}
	}

}