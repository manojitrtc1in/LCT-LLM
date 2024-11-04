import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Random;
import java.util.Stack;
import java.util.StringTokenizer;


public class R297 {
	public static InputReader in;
	public static PrintWriter out;
	public static Random ra = new Random(0);

	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		in = new InputReader(inputStream);
		out = new PrintWriter(outputStream, false);

		v3();

		out.close();
	}
	public static void id8() {
		int[] dx4 = {1, 0, -1, 0};
		int[] dy4 = {0, -1, 0, 1};
		
		int[] dx = {1, 1, 1, 0, -1, -1, -1, 0};
		int[] dy = {1, 0, -1, -1, -1, 0, 1, 1};
		
		int Y = in.nextInt();
		int X = in.nextInt();
		char[][] s = new char[Y][];
		for (int i = 0; i < s.length; i++) {
			s[i] = in.next().toCharArray();
		}
		int[][] map = new int[Y][X];
		for (int y = 0; y < Y; y++) {
			int[] temp = new int[X];
			for (int x = 0; x < X; x++) {
				if (s[y][x] == '.') {
					temp[x] = 1;
				} else {
					temp[x] = 0;
				}
			}	
			map[y] = temp;
		}

		boolean wallMod = true;

		while (wallMod) {
			wallMod = false;
			for (int y = 0; y < Y; y++) {
				for (int x = 0; x < X; x++) {
					if (map[y][x] == 0) {

						

						Stack<id6> queue = new Stack<id6>();
						id6 top = new id6(x, y);
						queue.add(top);
						
						while (!queue.isEmpty()) {
							top = queue.pop();

							if (top.x < 0 || top.x >= X) continue;
							if (top.y < 0 || top.y >= map.length) continue;
							if (map[top.y][x] == 1) continue;
							
























							
							for (int startY = -1; startY <= 0; startY++) {
								for (int startX = -1; startX <= 0; startX++) {
									int wallPoints = 0;
									int steps = 0;
									id6 wall = null;
									for (int y2 = top.y + startY; y2 < top.y + 2 + startY && y2 >= 0 && y2 < Y; y2++) {
										for (int x2 = top.x + startX; x2 < top.x + 2 + startX && x2 >= 0 && x2 < X; x2++) {
											steps++;
											if (map[y2][x2] == 0) {
												wallPoints++;
												wall = new id6(x2, y2);
											}
										}
									}
									if (wallPoints == 1 && steps == 4) {
										

										

										map[wall.y][wall.x] = 1;
										for (int i = 0; i < dx.length; i++) {
											queue.add(new id6(wall.x + dx[i], wall.y + dy[i]));
										}
									}
								}
							}
						}
					}
				}
			}
		}
		
		for (int y = 0; y < Y; y++) {
			char[] output = new char[X];
			for (int x = 0; x < X; x++) {
				if (map[y][x] == 1) {
					output[x] = '.';
				} else {
					output[x] = '*';
				}
			}
			out.println(new String(output));
		}
	}

	public static void v4() {
		int Y = in.nextInt();
		int X = in.nextInt();
		char[][] s = new char[Y][];
		for (int i = 0; i < s.length; i++) {
			s[i] = in.next().toCharArray();
		}
		id4[] map = new id4[Y];
		for (int y = 0; y < Y; y++) {
			int[] temp = new int[X];
			for (int x = 0; x < X; x++) {
				if (s[y][x] == '.') {
					temp[x] = 1;
				} else {
					temp[x] = 0;
				}
			}	
			map[y] = new id4(temp);
		}

		boolean wallMod = true;
		int wallCount = 0;

		while (wallMod) {
			HashSet<Integer> id0 = new HashSet<>();
			wallMod = false;
			PriorityQueue<SearchResult> q = new PriorityQueue<>();
			int colour = 0;
			int[][] colourMap = new int[Y][X];
			for (int y = 0; y < Y; y++) {
				for (int x = 0; x < X; x++) {
					if (map[y].query_tree(x,x) == 1 && colourMap[y][x] == 0) {
						int space = 0;
						colour++;
						int[] id3 = {X, 0};
						int[] id1 = {Y, 0};

						

						Stack<id6> stack = new Stack<id6>();
						id6 start = new id6(x, y);
						stack.push(start);

						while (!stack.isEmpty()) {
							id6 top = stack.pop();

							if (top.x < 0 || top.x >= X) continue;
							if (top.y < 0 || top.y >= map.length) continue;
							if (map[top.y].query_tree(top.x,top.x) == 0) continue;
							if (colourMap[top.y][top.x] != 0) continue;

							colourMap[top.y][top.x] = colour;

							id3[0] = Math.min(id3[0], top.x);
							id3[1] = Math.max(id3[1], top.x);
							id1[0] = Math.min(id1[0], top.y);
							id1[1] = Math.max(id1[1], top.y);

							space++;

							

							stack.push(new id6(top.x + 1, top.y));
							stack.push(new id6(top.x - 1, top.y));
							stack.push(new id6(top.x, top.y + 1));
							stack.push(new id6(top.x, top.y - 1));
						}

						int rectSpace = (id1[1] - id1[0] + 1) * (id3[1] - id3[0] + 1);
						q.add(new SearchResult(start, space, rectSpace, colour, id3, id1));
					}
				}
			}

			while (!q.isEmpty()) {
				SearchResult res = q.poll();

				if (res.space != res.rectSpace && !id0.contains(res.colour)) {
					


					for (int y = res.id1[0]; y <= res.id1[1]; y++) {
						if (map[y].query_tree( res.id3[0], res.id3[1]) !=  res.id3[1] - res.id3[0] +1) {
							map[y].set_tree(res.id3[0], res.id3[1], 1);
						}
					}
				}		
			}
		}
		char[][] output = new char[Y][X];
		for (int y = 0; y < Y; y++) {
			for (int x = 0; x < X; x++) {
				if (map[y].query_tree(x,x) == 1) {
					output[y][x] = '.';
				} else {
					output[y][x] = '*';
				}
			}
			out.println(new String(output[y]));
		}


	}

	static class SearchResult implements Comparable<SearchResult> {
		id6 start;
		int space;
		int rectSpace;
		int colour;
		int[] id3;
		int[] id1;
		public SearchResult(id6 start, int space, int rectSpace, int colour, int[] id3, int[] id1) {
			super();
			this.start = start;
			this.space = space;
			this.colour = colour;
			this.rectSpace = rectSpace;
			this.id3 = id3;
			this.id1 = id1;
		}
		@Override
		public int compareTo(SearchResult o) {
			return Integer.compare(o.rectSpace, rectSpace);
		}

	}

	private static class id6 {
		public int x, y;
		public id6 (int x, int y) {
			this.x = x;this.y = y;
		}
	}
	

	public static class id4 {
		protected long tree[];
		protected long lazy_update[];
		protected long lazy_set[];
		private int N;
		private int MAX;
		protected long neg_inf = 0;

		
		protected long function(long a, long b) {
			return a + b;
		}

		public id4(int[] a) {
			N = 1 << (int) (Math.log10(a.length)/Math.log10(2))+1;
			MAX = N*2;

			int[] arr = new int[N];
			for (int i = 0; i < a.length; i++) {
				arr[i] = a[i];
			}

			tree = new long[MAX];
			lazy_update = new long[MAX];
			lazy_set = new long[MAX];
			Arrays.fill(lazy_set, Long.MIN_VALUE);
			build_tree(1, 0, N-1, arr);
			Arrays.fill(lazy_update, 0);
		}
		
		
		private void build_tree(int node, int a, int b, int[] arr) {
			if (a > b) {
				return; 

			}

			if (a == b) { 

				tree[node] = arr[a]; 

				return;
			}

			build_tree(node*2, a, (a+b)/2, arr); 

			build_tree(node*2+1, 1+(a+b)/2, b, arr); 


			tree[node] = function(tree[node*2], tree[node*2+1]); 

		}

		
		public void update_tree(int i, int j, int value) {
			update_tree(1, 0, N-1, i, j, value);
		}

		protected void update_tree(int node, int a, int b, int i, int j, int value) {
			if (lazy_update[node] != 0 || lazy_set[node] != Long.MIN_VALUE) {
				id7(node, a, b);
				id5(node, a, b);
			}
			
			if (a > b || a > j || b < i) { 

				return;
			}

			if (a >= i && b <= j) { 

				tree[node] += value;

				if (a != b) { 

					lazy_update[node*2] += value;
					lazy_update[node*2 + 1] += value;
				}

				return;
			}

			update_tree(node*2, a, (a+b)/2, i, j, value); 

			update_tree(1 + node*2, 1 + (a+b)/2, b, i, j, value); 


			tree[node] = function(tree[node*2], tree[node*2+1]); 

		}
		
		
		public void set_tree(int i, int j, int value) {
			set_tree(1, 0, N-1, i, j, value);
		}

		protected void set_tree(int node, int a, int b, int i, int j, int value) {
			if (lazy_update[node] != 0 || lazy_set[node] != Long.MIN_VALUE) {
				id7(node, a, b);
				id5(node, a, b);
			}

			if (a > b || a > j || b < i) { 

				return;
			}

			if (a >= i && b <= j) { 

				tree[node] = value;

				if (a != b) { 

					lazy_set[node*2] = value;
					lazy_set[node*2 + 1] = value;
				}
				return;
			}

			set_tree(node*2, a, (a+b)/2, i, j, value); 

			set_tree(1 + node*2, 1 + (a+b)/2, b, i, j, value); 


			tree[node] = function(tree[node*2], tree[node*2+1]); 

		}

		
		public long query_tree(int i, int j) {
			return query_tree(1, 0, N-1, i, j);
		}

		
		protected long query_tree(int node, int a, int b, int i, int j) {
			if (a > b || a > j || b < i) {
				return neg_inf; 

			}

			if (lazy_update[node] != 0 || lazy_set[node] != Long.MIN_VALUE) {
				id7(node, a, b);
				id5(node, a, b);
			}

			if (a >= i && b <= j) { 

				return tree[node];
			}

			long q1 = query_tree(node*2, a, (a+b)/2, i, j); 

			long q2 = query_tree(1+node*2, 1+(a+b)/2, b, i, j); 


			long res = function(q1, q2); 

			return res;
		}
		
		protected void id7(int node, int a, int b) {
			if (lazy_update[node] != 0) { 

				tree[node] += lazy_update[node]; 


				if (a != b) {
					lazy_update[node*2] += lazy_update[node]; 

					lazy_update[node*2+1] += lazy_update[node]; 

				}

				lazy_update[node] = 0; 

			}
		}
		
		protected void id5(int node, int a, int b) {
			if (lazy_set[node] != Long.MIN_VALUE) { 

				tree[node] = lazy_set[node]; 


				if (a != b) {
					lazy_set[node*2] = lazy_set[node]; 

					lazy_set[node*2+1] = lazy_set[node]; 

				}

				lazy_set[node] = Long.MIN_VALUE; 

			}
		}
		
		public String toString() {
			return Arrays.toString(this.tree);
		}
	}
	

	public static class SegmentTree {
		private int[][] t;
		private int[] a;
		private int N;
		private int n;

		

		
		protected int function(int a, int b) {
			return a + b;
		}

		
		protected int IDENTITY = 0;

		public SegmentTree(int[] b) {
			n = (int) (Math.log10(b.length)/Math.log10(2))+1;
			N = 1 << n;
			this.a = new int[N];
			for (int i = 0; i < b.length; i++) {
				this.a[i] = b[i];
			}
			t = new int[N][n+1];
			for (int x = 0; x < N; x++) {
				t[x][0] = a[x];
			}
			for (int y = 1; y <= n; y++) {
				for (int x = 0; x < N; x+=(1<<y)) {
					t[x][y] = function(t[x][y-1], t[x+(1<<(y-1))][y-1]);
				}
			}
		} 

		
		public void set(int i, int v) {
			t[i][0] = a[i] = v;
			for (int y = 1; y <= n; y++) {
				int x = i-(i&((1<<y)-1));
				t[x][y] = function(t[x][y-1], t[x+(1<<(y-1))][y-1]);
			}
		}

		
		public int get(int i, int j) {
			int res = IDENTITY, height = 0; j++;
			while (i+(1<<height) <= j) {
				while ((i&((1<<(height+1))-1)) == 0 && i+(1<<(height+1)) <= j) height++;
				res = function(res, t[i][height]);
				i += (1<<height);
			}
			while (i < j) {
				while (i+(1<<height) > j) height--;
				res = function(res, t[i][height]);
				i += (1<<height);
			}
			return res;
		}
	}


	public static void v2() {
		char[] s = in.next().toCharArray();
		int n = in.nextInt();
		int[] a = in.id2(n);

		int[] swapCount = new int[s.length];
		int[] swapSum = new int[s.length];

		for (int i = 0; i < a.length; i++) {
			swapCount[a[i]-1]++;
		}

		swapSum[0] = swapCount[0];
		for (int i = 1; i < swapSum.length; i++) {
			swapSum[i] = swapSum[i-1] + swapCount[i];
		}

		for (int i = 0; i < s.length/2; i++) {
			if (swapSum[i] % 2 == 1) {
				char t = s[i];
				s[i] = s[s.length - i -1];
				s[s.length - i -1] = t;
			}
		}
		out.println(new String(s));
	}

	public static void v1() {
		in.nextInt();
		char[] s = in.next().toCharArray();
		int store = 0;
		int[] chain = new int[26];
		for (int i = 0; i < s.length; i+=2) {
			chain[s[i]-'a']++;
			int door = s[i+1]-'A';
			if (chain[door] > 0) {
				chain[door]--;
			} else {
				store++;
			}
		}
		out.println(store);
	}

	public static class InputReader {
		public BufferedReader reader;
		public StringTokenizer tokenizer;

		public InputReader(InputStream stream) {
			reader = new BufferedReader(new InputStreamReader(stream), 32768);
			tokenizer = null;
		}

		public String next() {
			while (tokenizer == null || !tokenizer.hasMoreTokens()) {
				try {
					tokenizer = new StringTokenizer(reader.readLine());
				} catch (IOException e) {
					throw new RuntimeException(e);
				}
			}
			return tokenizer.nextToken();
		}

		public int nextInt() {return Integer.parseInt(next());}
		public long nextLong() {return Long.parseLong(next());}
		public double nextDouble() {return Double.parseDouble(next());}
		public long[] id9(int n) {
			long[] a = new long[n];
			for (int i = 0; i < a.length; i++) a[i] = this.nextLong();
			return a;
		}
		public int[] id2(int n) {
			int[] a = new int[n];
			for (int i = 0; i < a.length; i++) a[i] = this.nextInt();
			return a;
		}
	}

	public static void v3() {
		int n = in.nextInt();
		int[] a = in.id2(n);
		Arrays.sort(a);
		int[] stx = new int[1000002];
		for (int i = 0; i < a.length; i++) {
			stx[a[i]]++;
		}
		ArrayList<Long> pairs = new ArrayList<>();
		long total = 0;
		for (int i = stx.length-1; i >= 0; i--) {
			boolean valid = true;
			while (stx[i] > 0 && valid) {
				if (stx[i] >= 2) {
					pairs.add((long) i);
					stx[i] -= 2;
				} else {
					if (i > 0 && stx[i-1] > 0) {
						pairs.add((long) i-1);
						stx[i]--;
						stx[i-1]--;
					} else {
						valid = false;
					}
				}
				if (pairs.size() == 2) {
					total += pairs.get(0) * pairs.get(1);
					pairs.clear();
				}				
			}
		}
		

		out.println(total);
	}
}
