import java.awt.Point;
import java.awt.geom.Line2D;
import java.awt.geom.Point2D;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.BitSet;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Random;
import java.util.StringTokenizer;
import java.util.TreeMap;

public class id6 implements Runnable {
	static boolean debug = false;
	static int[] hiddenx = new int[] { 97, 58, 16, 81, 79 };
	static int[] hiddeny = new int[] { -1, 5, 2, 1, 4 };

	public static void genData() {
		hiddenx = new int[1000];
		hiddeny = new int[1000];
		Random generator = new Random();
		for (int i = 0; i < hiddenx.length; i++) {
			boolean ok = true;
			do {
				hiddenx[i] = generator.nextInt(10000000);
				for (int j = 0; j < i; j++) {
					if (hiddenx[j] == hiddenx[i])
						ok = false;
				}
			} while (!ok);

		}
		for (int i = 0; i < hiddenx.length; i++) {
			int bestn = -1;
			for (int next = 0; next < hiddenx.length; next++) {
				if (hiddenx[next] > hiddenx[i] && (bestn == -1 || hiddenx[bestn] > hiddenx[next])) {
					bestn = next;
				}
			}
			hiddeny[i] = bestn + 1;
			if (bestn == -1)
				hiddeny[i] = -1;
		}
		ArrayList<Integer> wow = new ArrayList<Integer>();
		ArrayList<Integer> wowzer = new ArrayList<Integer>();
		for (Integer i : hiddenx) {
			wowzer.add(i);
			wow.add(i);
		}
		Collections.sort(wow);
		

		System.out.println(wow.get(wow.size() - 1));
		System.out.println(wowzer.indexOf(wow.get(0)) + 1 + " " + wow.get(0));
	}

	public static void main(String[] args) {
		

		new Thread(null, new id6(), ":)", 1 << 28).start();
	}

	static FS in;
	static int mod = (int) 1e9 + 7;
	static int[] dx = new int[] { -1, 0, 0, 1 };
	static int[] dy = new int[] { 0, -1, 1, 0 };

	@Override
	public void run() {
		

		try {
			in = new FS(System.in);
			PrintWriter out = new PrintWriter(System.out);
			

			int n = in.nextInt();
			int start = in.nextInt();
			int x = in.nextInt();

			Random generator = new Random();
			int bestidx = start;
			int bestval = query(start).x;
			for (int i = 0; i < 200; i++) {
				int guess = generator.nextInt(n) + 1;
				Point p = query(guess);
				if (p.x > bestval && p.x <= x) {
					bestidx = guess;
					bestval = p.x;
					if (bestval == x)
						break;
				}
			}

			Point cur = query(bestidx);
			Point last = null;
			Point lastlast = null;
			Point id10 = null;
			for (int i = 0; i < 3000; i++) {
				

				id10 = last;
				lastlast = last;
				last = cur;
				if (cur.equals(id10))
					break;
				if (cur.y == -1)
					break;
				if (cur.x == x)
					break;
				Point next = query(cur.y);
				if (next.x == cur.x) {
					System.out.println(next + " " + cur);
				}
				if (next.x > bestval && cur.x < x) {
					cur = next;
					bestval = cur.x;
				}
				if (cur.x < x && next.x >= x) {
					cur = next;
					bestval = cur.x;
					break;
				}
			}
			

			if (cur.x >= x) {
				System.out.println("! " + cur.x);
			} else {
				System.out.println("! " + -1);
			}
			System.out.flush();
			out.close();
		} catch (Exception e) {
			try {
				throw e;
			} catch (Exception e1) {
				

				e1.printStackTrace();
			}
		}
	}

	public Point query(int idx) {
		if (debug) {
			return new Point(hiddenx[idx - 1], hiddeny[idx - 1]);
		}
		System.out.println("? " + idx);
		System.out.flush();
		int val = in.nextInt();
		int nidx = in.nextInt();
		if (val == -1 && nidx == -1) {
			return new Point(1 / 0, 2 / 0);
		}
		return new Point(val, nidx);
	}

	TreeMap<Integer, Integer>[] tm;

	private static class id16 {
		node root;

		public id16(int[] start) {
			root = new node(start);
		}

		private static class node {
			node[] children;
			int[] sub;
			int[] mapleft;
			int[] mapright;
			int l;
			int r;
			int mid;

			public node(int[] start) {
				l = minElement(start);
				r = maxElement(start);
				sub = copyArray(start);
				mid = (l + r) / 2;
				if (l == r)
					return;
				int lcount = 0;
				int rcount = 0;
				for (int i = 0; i < start.length; i++) {
					if (sub[i] <= mid) {
						lcount++;
					} else {
						rcount++;
					}
				}
				int[] left = new int[lcount];
				int[] right = new int[rcount];
				mapleft = new int[start.length];
				mapright = new int[start.length];
				lcount = 0;
				rcount = 0;
				for (int i = 0; i < start.length; i++) {
					if (sub[i] <= mid) {
						left[lcount] = sub[i];
						lcount++;
					} else {
						right[rcount] = sub[i];
						rcount++;
					}
					mapleft[i] = lcount;
					mapright[i] = rcount;
				}
				children = new node[2];
				children[0] = new node(left);
				children[1] = new node(right);
			}
		}

		public int rank(int q, int i) {
			return rank(root, q, i);
		}

		public int rank(node S, int q, int i) {
			if (S.children == null) {
				return i;
			}
			if (q <= S.mid) {
				return rank(S.children[0], q, S.mapleft[i]);
			} else {
				return rank(S.children[1], q, S.mapright[i]);
			}
		}
	}

	static int[] copyArray(int[] arr) {
		int[] neww = new int[arr.length];
		for (int i = 0; i < arr.length; i++) {
			neww[i] = arr[i];
		}
		return neww;
	}

	static int maxElement(int[] arr) {
		int max = arr[0];
		for (int i = 0; i < arr.length; i++) {
			max = Math.max(max, arr[i]);
		}
		return max;
	}

	static int minElement(int[] arr) {
		int min = arr[0];
		for (int i = 0; i < arr.length; i++) {
			min = Math.min(min, arr[i]);
		}
		return min;
	}

	int count(int v, int l, int r) {
		if (tm[v].ceilingKey(l) == null)
			return 0;
		if (tm[v].floorKey(r) == null)
			return 0;
		return tm[v].get(tm[v].floorKey(r)) - tm[v].get(tm[v].ceilingKey(l)) + 1;
	}

	private static int[] cxor(int[] given) {
		int[] ans = new int[given.length + 1];
		for (int i = 1; i < ans.length; i++) {
			ans[i] = given[i - 1] ^ ans[i - 1];
		}
		return ans;
	}

	private static int id1(int[] cxor, int x1, int x2) {
		

		if (x2 < cxor.length)
			return id20(cxor, x1, x2);
		int ans = 0;
		

		ans = id20(cxor, x1 % (cxor.length - 1), cxor.length - 1);
		x1 += cxor.length - 1 - (x1 % (cxor.length - 1));
		int diff = x2 - x1;
		int iterations = diff / (cxor.length - 1);
		

		if (iterations % 2 == 1) {
			ans ^= id20(cxor, 0, cxor.length - 1);
		}
		

		ans ^= id20(cxor, 0, x2 % (cxor.length - 1));
		return ans;
	}

	private static int id20(int[] cxor, int x1, int x2) {
		return cxor[x2] ^ cxor[x1];
	}

	private static double[][][] csum(double[][][] given) {
		double[][][] ans = new double[given.length + 1][given[0].length + 1][given[0][0].length + 1];
		for (int i = 1; i < ans.length; i++) {
			for (int j = 1; j < ans[i].length; j++) {
				for (int k = 1; k < ans[i][j].length; k++) {
					ans[i][j][k] = given[i - 1][j - 1][k - 1] + ans[i - 1][j][k] + ans[i][j - 1][k] + ans[i][j][k - 1]
							- ans[i][j - 1][k - 1] - ans[i - 1][j][k - 1] - ans[i - 1][j - 1][k]
							+ ans[i - 1][j - 1][k - 1];
					

					

				}
			}
		}
		return ans;
	}

	private static double id25(double[][][] csum, int x1, int y1, int z1, int x2, int y2, int z2) {
		if (x1 > x2 || y1 > y2 || z1 > z2)
			return 0;
		if (x1 < 0)
			x1 = 0;
		if (y1 < 0)
			y1 = 0;
		if (z1 < 0)
			z1 = 0;
		if (x2 < 0)
			x2 = 0;
		if (y2 < 0)
			y2 = 0;
		if (z2 < 0)
			z2 = 0;
		if (x1 >= csum.length)
			x1 = csum.length - 1;
		if (y1 >= csum[0].length)
			y1 = csum[0].length - 1;
		if (z1 >= csum[0][0].length)
			z1 = csum[0][0].length - 1;
		if (x2 >= csum.length)
			x2 = csum.length - 1;
		if (y2 >= csum[0].length)
			y2 = csum[0].length - 1;
		if (z2 >= csum[0][0].length)
			z2 = csum[0][0].length - 1;
		double inclusion = csum[x2][y2][z2];
		double exclusion = csum[x1][y2][z2] + csum[x2][y1][z2] + csum[x2][y2][z1];
		double id11 = csum[x2][y1][z1] + csum[x1][y2][z1] + csum[x1][y1][z2];
		double id27 = csum[x1][y1][z1];
		

		

		

		

		

		return (inclusion - exclusion + id11 - id27);
	}

	private static class DFA {
		ArrayList<id21> nodes;
		ArrayList<id21> start;
		ArrayList<id21> end;
		int alpha;

		DFA(int count, int alpha, int s, int e) {
			nodes = new ArrayList<id21>();
			this.alpha = alpha;
			for (int i = 0; i < count; i++) {
				nodes.add(new id21());
				nodes.get(nodes.size() - 1).idx = nodes.size() - 1;
			}
			start = new ArrayList<id21>();
			start.add(nodes.get(s));
			end = new ArrayList<id21>();
			end.add(nodes.get(e));
		}

		public void AddEdge(int s, int f, int letter) {
			nodes.get(s).transition[letter] = nodes.get(f);
		}

		public void Trim() {
			HashSet<id21> valid = new HashSet<id21>();
			valid.addAll(nodes);
			for (id21 n : nodes) {
				for (int i = 0; i < n.transition.length; i++) {
					if (!valid.contains(n.transition[i]))
						n.transition[i] = null;
				}
			}
		}

		private class id21 implements Comparable<id21> {
			id21[] transition;
			int idx;

			public id21() {
				transition = new id21[alpha];
			}

			@Override
			public int hashCode() {
				return idx;
			}

			@Override
			public String toString() {
				StringBuilder sb = new StringBuilder();
				sb.append(idx + ": <");
				for (int i = 0; i < transition.length; i++) {
					if (transition[i] != null) {
						sb.append(i + ":" + transition[i].idx + ",");
					}
				}
				sb.append(">");
				return sb.toString();
			}

			@Override
			public boolean equals(Object obj) {
				return ((id21) obj).toString().equals(toString());
			}

			@Override
			public int compareTo(id21 arg0) {
				

				return Integer.compare(idx, arg0.idx);
			}

		}

		private void id26() {
			HashSet<id21> reached = new HashSet<id21>();
			ArrayDeque<id21> dq = new ArrayDeque<id21>();
			dq.addAll(start);
			reached.addAll(start);
			while (!dq.isEmpty()) {
				id21 cur = dq.poll();
				for (id21 next : cur.transition) {
					if (next == null)
						continue;
					if (!reached.contains(next)) {
						dq.add(next);
						reached.add(next);
					}
				}
			}
			ArrayList<id21> dupe = new ArrayList<id21>();
			ArrayList<id21> dupend = new ArrayList<id21>();
			ArrayList<id21> dupstart = new ArrayList<id21>();
			for (id21 d : nodes) {
				if (reached.contains(d)) {
					dupe.add(d);
				}
			}
			for (id21 d : end) {
				if (reached.contains(d)) {
					dupend.add(d);
				}
			}
			for (id21 d : start) {
				if (reached.contains(d)) {
					dupstart.add(d);
				}
			}
			nodes = dupe;
			end = dupend;
			start = dupstart;
		}

		private void id7() {
			HashSet<id21> reached = new HashSet<id21>();
			reached.addAll(end);
			boolean news = false;
			do {
				news = false;
				for (id21 n : nodes) {
					if (reached.contains(n))
						continue;
					for (id21 nn : n.transition) {
						if (nn == null)
							continue;
						if (reached.contains(nn)) {
							news = true;
							reached.add(n);
						}
					}
				}
			} while (news);
			ArrayList<id21> dupe = new ArrayList<id21>();
			ArrayList<id21> dupend = new ArrayList<id21>();
			ArrayList<id21> dupstart = new ArrayList<id21>();
			for (id21 d : nodes) {
				if (reached.contains(d)) {
					dupe.add(d);
				}
			}
			for (id21 d : end) {
				if (reached.contains(d)) {
					dupend.add(d);
				}
			}
			for (id21 d : start) {
				if (reached.contains(d)) {
					dupstart.add(d);
				}
			}
			nodes = dupe;
			end = dupend;
			start = dupstart;
		}

		private void minimize() {
			number();

			Collections.sort(nodes);
			boolean[][] distinct = new boolean[nodes.size()][nodes.size()];
			for (int i = 0; i < nodes.size(); i++) {
				for (int j = i + 1; j < nodes.size(); j++) {
					boolean hasi = false;
					boolean hasj = false;
					for (id21 n : end) {
						if (nodes.get(i).equals(n))
							hasi = true;
						if (nodes.get(j).equals(n))
							hasj = true;
					}
					if (hasi != hasj) {
						distinct[i][j] = true;
						distinct[j][i] = true;
					}
				}
			}
			boolean news = false;
			do {
				news = false;
				for (int i = 0; i < nodes.size(); i++) {
					for (int j = 0; j < nodes.size(); j++) {
						if (!distinct[i][j]) {
							for (int a = 0; a < nodes.get(i).transition.length; a++) {
								id21 alpha = nodes.get(i).transition[a];
								id21 beta = nodes.get(j).transition[a];
								if (alpha != beta) {
									if (alpha == null || beta == null || distinct[alpha.idx][beta.idx]) {
										distinct[i][j] = true;
										distinct[j][i] = true;
										news = true;
									}
								}
							}
						}
					}
				}
			} while (news);
			ArrayList<id21> cop = new ArrayList<id21>();
			cop.addAll(nodes);
			for (int i = 0; i < distinct.length; i++) {
				ArrayList<id21> needed = new ArrayList<id21>();
				needed.add(cop.get(i));
				for (int j = i + 1; j < distinct.length; j++) {
					if (!distinct[i][j]) {
						needed.add(cop.get(j));
					}
				}
				if (needed.size() > 1) {
					merge(needed);
				}
			}
			number();
		}

		@Override
		public String toString() {
			return start.toString() + " " + end.toString() + " " + nodes.toString();
		}

		public void number() {
			id26();
			id7();
			Trim();
			int num = 0;
			HashSet<id21> reached = new HashSet<id21>();
			ArrayDeque<id21> dq = new ArrayDeque<id21>();
			dq.addAll(start);
			reached.addAll(start);
			HashMap<Integer, id21> remap = new HashMap<Integer, id21>();
			while (!dq.isEmpty()) {
				id21 cur = dq.poll();
				remap.put(num++, cur);
				for (id21 next : cur.transition) {
					if (next == null)
						continue;
					if (!reached.contains(next)) {
						dq.add(next);
						reached.add(next);
					}
				}
			}
			for (Integer i : remap.keySet()) {
				remap.get(i).idx = i;
			}
			Collections.sort(nodes);
		}

		public void merge(ArrayList<id21> toMerge) {
			HashSet<id21> list = new HashSet<id21>();
			id21 id23 = toMerge.get(0);
			list.addAll(toMerge);
			nodes.removeAll(list);
			nodes.add(id23);
			if (start.removeAll(toMerge)) {
				start.add(id23);
			}
			if (end.removeAll(toMerge)) {
				end.add(id23);
			}
			for (id21 n : nodes) {
				for (int i = 0; i < n.transition.length; i++) {
					if (list.contains(n.transition[i])) {
						n.transition[i] = id23;
					}
				}
			}
		}

		@Override
		public boolean equals(Object o) {
			return ((DFA) o).toString().equals(toString());
		}

	}

	private static class id17 {
		int[][][][] rmq;
		int[][] data;

		public id17(int[][] data) {
			this.data = data;
			int k1 = Integer.numberOfTrailingZeros(Integer.highestOneBit(data.length)) + 3;
			int k2 = Integer.numberOfTrailingZeros(Integer.highestOneBit(data[0].length)) + 3;
			rmq = new int[k1][k2][data.length][data[0].length];
			for (int i = 0; i < data.length; i++) {
				for (int j = 0; j < data[0].length; j++) {
					rmq[0][0][i][j] = data[i][j];
				}
			}
			for (int i = 0; i < k1; i++) {
				for (int j = 0; j < k2; j++) {
					if (i == 0 && j == 0)
						continue;
					for (int x = 0; x + (1 << i) - 1 < data.length; x++) {
						for (int y = 0; y + (1 << j) - 1 < data[0].length; y++) {
							if (j == 0) {
								rmq[i][j][x][y] = Math.min(rmq[i - 1][j][x][y], rmq[i - 1][j][x + (1 << (i - 1))][y]);
							} else {
								rmq[i][j][x][y] = Math.min(rmq[i][j - 1][x][y], rmq[i][j - 1][x][y + (1 << (j - 1))]);
							}
						}
					}
				}
			}
		}

		public int query(int x1, int y1, int x2, int y2) {
			int i = (int) (Math.log(x2 - x1 + 1) / Math.log(2));
			int j = (int) (Math.log(y2 - y1 + 1) / Math.log(2));
			int min = Integer.MAX_VALUE;
			min = Math.min(min, rmq[i][j][x1][y1]);
			min = Math.min(min, rmq[i][j][x2 - (1 << i) + 1][y1]);
			min = Math.min(min, rmq[i][j][x1][y2 - (1 << j) + 1]);
			min = Math.min(min, rmq[i][j][x2 - (1 << i) + 1][y2 - (1 << j) + 1]);
			return min;
		}
	}

	private static void printArray(int[][] arr) {
		for (int i = 0; i < arr.length; i++) {
			for (int j = 0; j < arr[i].length; j++) {
				System.out.print(arr[i][j] + " ");
			}
			System.out.println();
		}
	}

	private static Point2D.Double reflectPoint(Point2D.Double p, Line2D.Double line) {
		double dY = line.y2 - line.y1, dX = line.x2 - line.x1;
		Point2D.Double mid = cramer(line, new Line2D.Double(p, new Point2D.Double(p.x - dY, p.y + dX)));
		return new Point2D.Double(2 * mid.x - p.x, 2 * mid.y - p.y);
	}

	private static double angle(Line2D.Double a, Line2D.Double b) {
		return ((Math.atan2(a.y1 - a.y2, a.x1 - a.x2) - Math.atan2(b.y1 - b.y2, b.x1 - b.x2)) % Math.PI + Math.PI)
				% Math.PI;
	}

	private static Point2D.Double cramer(Line2D.Double p, Line2D.Double q) {
		

		


		double id3 = p.x2 - p.x1, id34 = q.x2 - q.x1;
		double id36 = p.y2 - p.y1, id29 = q.y2 - q.y1;

		double a1 = -id36, b1 = id3, c1 = id3 * p.y1 - id36 * p.x1;
		double a2 = -id29, b2 = id34, c2 = id34 * q.y1 - id29 * q.x1;

		double D = a1 * b2 - a2 * b1;
		double Dx = c1 * b2 - c2 * b1;
		double Dy = a1 * c2 - a2 * c1;

		return new Point2D.Double(Dx / D, Dy / D);

	}

	

	private static class ST {
		int[] list, st;
		int K;

		public ST(int[] list) {
			this.list = list;
			K = (int) Math.ceil(Math.log(list.length) / Math.log(2.0));
			st = new int[list.length * 4];
			build(0, (1 << K) - 1, 1);
		}

		private int build(int L, int R, int idx) {
			if (L == R) {
				if (L >= list.length)
					return -1;
				return st[idx] = L;
			}
			int mid = L + R >> 1;
			int l = build(L, mid, idx << 1);
			int r = build(mid + 1, R, (idx << 1) + 1);
			if (l != -1 && r != -1)
				return st[idx] = (list[l] <= list[r]) ? l : r;

																

			if (l != -1)
				return st[idx] = l;
			if (r != -1)
				return st[idx] = r;
			return st[idx] = -1;
		}

		public int query(int L, int R) {
			return query(L, R, 0, (1 << K) - 1, 1);
		}

		private int query(int L, int R, int tL, int tR, int idx) {
			if (tL >= L && tR <= R)
				return st[idx];
			if (tL < L && tR < L || tL > R && tR > R)
				return -1;
			int mid = tL + tR >> 1;
			int l = query(L, R, tL, mid, idx << 1);
			int r = query(L, R, mid + 1, tR, (idx << 1) + 1);
			if (l != -1 && r != -1)
				return (list[l] <= list[r]) ? l : r;

			if (l != -1)
				return l;
			if (r != -1)
				return r;
			return -1;
		}

		public int update(int U, int V) {
			return update(U, 0, (1 << K) - 1, 1, V);
		}

		private int update(int U, int tL, int tR, int idx, int V) {
			if (U == tL && tL == tR) {
				list[U] = V;
				return st[idx] = U;
			}
			if (tL < U && tR < U || tL > U && tR > U)
				return st[idx];
			int mid = tL + tR >> 1;
			int l = update(U, tL, mid, idx << 1, V);
			int r = update(U, mid + 1, tR, (idx << 1) + 1, V);
			if (l != -1 && r != -1)
				return st[idx] = (list[l] <= list[r]) ? l : r;

			if (l != -1)
				return st[idx] = l;
			if (r != -1)
				return st[idx] = r;
			return -1;
		}
	}

	private static class id22 implements Comparable<id22> {
		int length;
		int cost;
		int source;
		int destination;

		public id22(int from, int to, int length, int cost) {
			source = from;
			destination = to;
			this.length = length;
			this.cost = cost;
		}

		@Override
		public int compareTo(id22 arg0) {
			

			return Integer.compare(length, arg0.length);
		}
	}

	private static class Event implements Comparable<Event> {
		int x;
		int y;
		int priority;

		public Event(int time, int val, int priority) {
			this.x = time;
			this.y = val;
			this.priority = priority;
		}

		@Override
		public int compareTo(Event o) {
			

			if (x != o.x)
				return Integer.compare(x, o.x);
			if (y != o.y)
				return Integer.compare(y, o.y);
			return Integer.compare(priority, o.priority);
		}

		@Override
		public boolean equals(Object o) {
			return compareTo((Event) o) == 0;
		}

		@Override
		public String toString() {
			return "(" + x + " , " + y + ", " + priority + ")";
		}

	}

	private static class Lowlink {

		int N, time;
		int[] ord, low;
		boolean[] art;
		ArrayList<Edge>[] adj;

		public Lowlink(ArrayList<Edge>[] adj) {
			this.adj = adj;
			N = adj.length;
		}

		public void start() {
			ord = new int[N];
			low = new int[N];
			art = new boolean[N];

			Arrays.fill(ord, -1);

			for (int i = 0; i < N; i++)
				if (ord[i] == -1)
					dfs(i, -1);
		}

		private int dfs(int u, int parEdge) {

			ord[u] = low[u] = time++;
			int children = 0;

			for (Edge e : adj[u]) {
				int v = e.op(u);
				if (e.id == parEdge)
					continue;
				if (ord[v] == -1) {
					low[u] = Math.min(low[u], dfs(v, e.id));
					if (++children > 1 && parEdge == -1)
						art[u] = true;
					if (parEdge != -1 && low[v] >= ord[u])
						art[u] = true;
					if (low[v] > ord[u])
						e.bridge = true;
				} else
					low[u] = Math.min(low[u], ord[v]);
			}
			return low[u];
		}
	}

	private static class Edge {
		int u, v, id;
		boolean bridge;

		public Edge(int u, int v, int id) {
			this.u = u;
			this.v = v;
			this.id = id;
		}

		public int op(int a) {
			return a == u ? v : u;
		}
	}

	private static class pair implements Comparable<pair> {
		int a;
		int b;

		public pair(int a, int b) {
			this.a = a;
			this.b = b;
		}

		public double dist(pair other) {
			return Math.sqrt((a - other.a) * (a - other.a) + (b - other.b) * (b - other.b));
		}

		@Override
		public int compareTo(pair arg0) {
			

			if (a != arg0.a)
				return Integer.compare(a, arg0.a);
			return Integer.compare(b, arg0.b);
		}

		@Override
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + a;
			result = prime * result + b;
			return result;
		}

		@Override
		public boolean equals(Object obj) {
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			if (getClass() != obj.getClass())
				return false;
			pair other = (pair) obj;
			if (a != other.a)
				return false;
			if (b != other.b)
				return false;
			return true;
		}

		@Override
		public String toString() {
			return "(" + a + " , " + b + ")";
		}

	}

	private static class Line {
		double m;
		double b;

		public Line(double m, double b) {
			this.m = m;
			this.b = b;
		}

		@Override
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			long temp;
			temp = Double.doubleToLongBits(b);
			result = prime * result + (int) (temp ^ (temp >>> 32));
			temp = Double.doubleToLongBits(m);
			result = prime * result + (int) (temp ^ (temp >>> 32));
			return result;
		}

		@Override
		public boolean equals(Object obj) {
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			if (getClass() != obj.getClass())
				return false;
			Line other = (Line) obj;
			if (Double.doubleToLongBits(b) != Double.doubleToLongBits(other.b))
				return false;
			if (Double.doubleToLongBits(m) != Double.doubleToLongBits(other.m))
				return false;
			return true;
		}

	}

	private static class FS {
		BufferedReader br;
		StringTokenizer st;

		public FS(InputStream in) {
			br = new BufferedReader(new InputStreamReader(in));
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

	private static class id30 {
		double eps = 1e-7;
		ArrayList<Edge>[] nodes;
		ArrayList<Double> modifiers;
		ArrayList<Edge> actual;
		ArrayList<Edge> id31;
		double[] demand;
		int[] distance;
		boolean[] blocked;
		int source;
		int sink;

		class Edge {
			int from;
			int to;
			double capacity;
			double flow;
			Edge reverse;

			public Edge(int from, int to, double capacity, double flow, Edge reverse) {
				this.from = from;
				this.to = to;
				this.capacity = capacity;
				this.flow = flow;
				this.reverse = reverse;
			}
		}

		public id30(int nodes) {
			this.id31 = new ArrayList<Edge>();
			this.nodes = new ArrayList[nodes];
			this.actual = new ArrayList<Edge>();
			this.modifiers = new ArrayList<Double>();
			for (int i = 0; i < nodes; i++) {
				this.nodes[i] = new ArrayList<Edge>();
			}
			demand = new double[nodes];
		}

		public Edge addEdge(int from, int to, double capacity) {
			

			Edge forward = new Edge(from, to, capacity, 0, null);
			Edge reverse = new Edge(to, from, 0, 0, forward);
			forward.reverse = reverse;
			nodes[from].add(forward);
			nodes[to].add(reverse);
			actual.add(forward);
			return forward;
		}

		public Edge addEdge(int from, int to, double capacity, double min) {
			Edge o = addEdge(from, to, capacity - min);
			demand[from] += min;
			demand[to] -= min;
			modifiers.add(min);
			return o;
		}

		public void id32(int id0, int id14) {
			for (int i = 0; i < demand.length; i++) {
				if (Math.abs(demand[i]) < eps)
					continue;
				if (demand[i] < 0) {
					id31.add(addEdge(id0, i, -demand[i]));
				}
				if (demand[i] > 0) {
					id31.add(addEdge(i, id14, demand[i]));
				}
			}
		}

		public double flowX(int source, int sink, double amount) {
			

			

			double flow = 0;
			this.source = source;
			this.sink = sink;
			while (bfs()) {
				blocked = new boolean[nodes.length];
				double val = dfs(source, amount - flow);
				flow += val;
				if (flow >= amount)
					break;
			}
			if (id31.size() > 0) {
				for (Edge e : id31) {
					

					if (Math.abs(e.flow - e.capacity) > eps) {
						return -1;
					} else {
						if (e.from == source) {
							flow -= e.flow;
						}
					}
				}
			}
			return flow;
		}

		public double flow(int source, int sink) {
			return flowX(source, sink, Double.MAX_VALUE);
		}

		

		

		

		

		

		

		public double id12(int source, int sink) {
			

			double totalFlow = flow(source, sink);
			for (int i = 0; i < nodes.length - 2; i++) {
				boolean leftside = true;
				for (Edge e : nodes[i]) {
					if (e.to == sink)
						leftside = false;
				}
				if (!leftside)
					break;
				

				for (Edge e : nodes[i]) {
					if (e.to == source || e.from == source || e.to == sink || e.from == sink)
						continue;
					

					if (e.flow == 0) {
						e.capacity = 0;
						e.reverse.capacity = 0;
						

						e.reverse.flow = 0;
						continue;
					}
					if (e.flow < 0)
						continue;
					ForceBlock(e);
				}
			}
			return totalFlow;
		}

		public boolean ForceBlock(Edge e) {
			double cur = e.flow;
			double cap = e.capacity;
			double rcur = e.reverse.flow;
			double rcap = e.reverse.capacity;
			e.capacity = 0;
			e.flow = 0;
			e.reverse.flow = 0;
			e.reverse.capacity = 0;
			double can = flowX(e.from, e.to, cur);
			if (Math.abs(can - cur) < 1e-7) {
				return true;
			} else {
				e.capacity = cap;
				e.flow = cur;
				e.reverse.capacity = rcap;
				e.reverse.flow = rcur;
				return false;
			}
		}

		public boolean bfs() {
			distance = new int[nodes.length];
			Arrays.fill(distance, Integer.MAX_VALUE);
			distance[sink] = 0;
			ArrayDeque<Integer> current = new ArrayDeque<Integer>();
			current.add(sink);
			while (!current.isEmpty()) {
				int cur = current.poll();
				if (distance[cur] >= distance[source])
					break;
				for (Edge e : nodes[cur]) {
					if ((e.reverse.capacity - e.reverse.flow) > eps) {
						if (distance[e.to] > (distance[cur] + 1)) {
							current.add(e.to);
							distance[e.to] = distance[cur] + 1;
						}
					}
				}
			}
			return distance[source] != Integer.MAX_VALUE;
		}

		public double dfs(int pos, double min) {
			if (pos == sink) {
				return min;
			}
			double flow = 0;
			for (Edge e : nodes[pos]) {
				if (blocked[e.to])
					continue;
				if (distance[e.to] != distance[pos] - 1)
					continue;
				if ((e.capacity - e.flow) > eps) {
					double res = dfs(e.to, Math.min(min, e.capacity - e.flow));
					flow += res;
					min -= res;
					e.flow += res;
					e.reverse.flow -= res;
				}
				if (min <= eps)
					break;
			}
			if (min > eps) {
				blocked[pos] = true;
			}
			return flow;
		}

		public void removeEdge(Edge e) {
			

			nodes[e.from].remove(e);
			nodes[e.to].remove(e.reverse);
			

		}

		public void id35() {
			for (Edge e : id31) {
				removeEdge(e);
			}
			id31 = new ArrayList<Edge>();
		}

		public void addDemand(double demand, int node) {
			this.demand[node] += demand;
		}

		public void drain() {
			for (ArrayList<Edge> al : nodes) {
				for (Edge e : al) {
					e.flow = 0;
				}
			}
		}
	}

	private static class STmine {
		
		int ignore = 0;
		
		int[] left;
		
		int[] right;
		
		int[] val;
		
		int[] a;
		
		int[] b;
		
		int[] prop;

		
		int[] height;

		
		STmine(int n) {
			left = new int[4 * n];
			right = new int[4 * n];
			val = new int[4 * n];
			prop = new int[4 * n];
			height = new int[4 * n];
			a = new int[4 * n];
			b = new int[4 * n];
			init(0, 0, n - 1);
		}

		
		int init(int at, int l, int r) {
			a[at] = l;
			b[at] = r;
			if (l == r) {
				left[at] = right[at] = -1;
				height[at] = 0;
			} else {
				int mid = l + r >> 1;
				left[at] = init(2 * at + 1, l, mid);
				right[at] = init(2 * at + 2, mid + 1, r);
				height[at] = Math.max(height[left[at]], height[right[at]]) + 1;
			}
			return at++;
		}

		
		int get(int x, int y) {
			return go(x, y, 0);
		}

		
		void push(int at) {
			System.out.println("PUSH " + prop[at]);
			if (prop[at] != 0) {
				go3(a[left[at]], b[left[at]], prop[at], left[at]);
				go3(a[right[at]], b[right[at]], prop[at], right[at]);
				prop[at] = 0;
			}
		}

		
		int go(int x, int y, int at) {
			if (at == -1 || y < a[at] || x > b[at])
				return ignore;
			if (x <= a[at] && y >= b[at]) {
				push(at);
				System.out.println(prop[at] + " " + val[at]);
				return val[at];
			}
			System.out.println(x + " " + y + " " + a[at] + " " + b[at]);
			push(at);
			return eval(at, go(x, y, left[at]), go(x, y, right[at]));
		}

		
		void add(int x, int y, int v) {
			go3(x, y, v, 0);
		}

		void id18(int x, int y, int v) {
			go2(x, y, v, 0);
		}

		
		void go2(int x, int y, int v, int at) {
			if (at == -1)
				return;
			if (y < a[at] || x > b[at])
				return;
			x = Math.max(x, a[at]);
			y = Math.min(y, b[at]);
			if (y == b[at] && x == a[at]) {
				val[at] = v;
				return;
			}
			go2(x, y, v, left[at]);
			go2(x, y, v, right[at]);
			val[at] = eval(at, val[left[at]], val[right[at]]);
		}

		
		void go3(int x, int y, int v, int at) {
			if (at == -1)
				return;
			if (y < a[at] || x > b[at])
				return;
			x = Math.max(x, a[at]);
			y = Math.min(y, b[at]);
			if (y == b[at] && x == a[at]) {
				val[at] += v;
				prop[at] += v;
				return;
			}
			push(at);
			go3(x, y, v, left[at]);
			go3(x, y, v, right[at]);
			val[at] = eval(at, val[left[at]], val[right[at]]);
		}

		
		int eval(int at, int lval, int rval) {
			

			System.out.println(at + " " + lval + " " + rval + "!");
			return Math.min(lval, rval);
		}

	}

	private static class id15 {
		int ALPHA = 26;
		int nodeCount;
		int[][] transition;
		BitSet[] word;

		public void id19(String[] strs) {
			int maxNodes = 1;
			for (String s : strs) {
				maxNodes += s.length();
			}

			int[][] children = new int[ALPHA][maxNodes];
			word = new BitSet[maxNodes];
			for (int i = 0; i < word.length; i++)
				word[i] = new BitSet();
			nodeCount = 1;
			for (int i = 0; i < strs.length; i++) {
				String s = strs[i];
				int node = 0;
				for (char ch : s.toCharArray()) {
					int c = ch - 'a';
					if (children[c][node] == 0) {
						children[c][node] = nodeCount;
						nodeCount++;
					}
					node = children[c][node];
				}
				word[node].set(i);
			}

			transition = new int[ALPHA][nodeCount];

			ArrayDeque<Integer> queue = new ArrayDeque<Integer>();
			queue.add(0);
			queue.add(0);

			while (queue.size() > 0) {
				int node = queue.remove();
				int id37 = queue.remove();

				word[node].or(word[id37]);

				for (int ch = 0; ch < ALPHA; ch++) {
					if (children[ch][node] != 0) {
						transition[ch][node] = children[ch][node];
						queue.add(children[ch][node]);
						queue.add(node == 0 ? 0 : transition[ch][id37]);
					} else {
						transition[ch][node] = transition[ch][id37];
					}
				}
			}
		}
	}

	private static class id9 {
		static ArrayList<Long> primes;
		static Random r = new Random();

		private static void factorize(long n) {

			primes = new ArrayList<>();
			while (!BigInteger.valueOf(n).isProbablePrime(20)) {
				long rho = rho(n);
				primes.add(rho);
				n /= rho;
			}
			primes.add(n);
		}

		private static long rho(long n) {
			if (n <= 3)
				return -1;
			if ((n & 1) == 0)
				return 2;
			long a = (Math.abs(r.nextLong()) + 2) % 100000, y = (Math.abs(r.nextLong()) + 2) % 100000, x = y, d;
			do {
				x = poly(x, a, n);
				y = poly(poly(y, a, n), a, n);
				d = gcd(n, Math.abs(x - y));
			} while (d == 1);
			return d;
		}

		private static long poly(long x, long a, long n) {
			return (mulmod(x, x, n) + a) % n;
		}

		private static long mulmod(long a, long b, long c) {
			return BigInteger.valueOf(a).multiply(BigInteger.valueOf(b)).mod(BigInteger.valueOf(c)).longValue();
		}

		static long solve(long[] a, long[] m) {
			long A = a[0], M = m[0];
			for (int i = 1; i < a.length; i++) {
				if (A > a[i]) {
					A = A ^ a[i] ^ (a[i] = A);
					M = M ^ m[i] ^ (m[i] = M);
				}
				long gcd = gcd(m[i], M), diff = a[i] - A;
				if (gcd == 0 || diff % gcd != 0)
					return -1;
				long MOD = M * m[i] / gcd;
				A = (modInv(M / gcd, m[i] / gcd) * (diff / gcd) % MOD * M + A) % MOD;
				M = MOD;
			}
			return A;
		}

		private static long modInv(long a, long m) {
			long m0 = m, t, q, x0 = 0, x1 = 1;
			while (a > 1) {
				q = a / (t = m);
				m = a % m;
				a = t;
				x0 = x1 - q * (t = x0);
				x1 = t;
			}
			return (m == 1) ? 0 : (x1 < 0) ? x1 + m0 : x1;
		}

		private static long gcd(long a, long b) {
			return Math.abs(b == 0 ? a : gcd(b, a % b));
		}
	}

	private static class MST {
		static int[] root;
		static int[] rank;
		static int disjoint;

		public MST(int num) {
			root = new int[num];
			rank = new int[num];
			Arrays.fill(root, -1);
			disjoint = num;
		}

		public static int find(int s) {
			if (root[s] != s)
				return root[s] == -1 ? s : (root[s] = find(root[s]));
			return root[s];
		}

		public static void union(int s, int t) {
			int x = find(s);
			int y = find(t);
			if (x != y)
				disjoint--;
			if (rank[x] < rank[y]) {
				root[x] = y;
			}
			if (rank[y] < rank[x]) {
				root[y] = x;
			}
			if (rank[y] == rank[x]) {
				root[y] = x;
				rank[x]++;
			}
		}
	}

	private static class id33 {

		public static int[] id8(String s) {
			if (s == null || s.length() == 0)
				return new int[0];

			char[] s2 = id4(s.toCharArray());
			int[] p = new int[s2.length];
			int c = 0, r = 0; 

								

			int m = 0, n = 0; 

								

			for (int i = 1; i < s2.length; i++) {
				if (i > r) {
					p[i] = 0;
					m = i - 1;
					n = i + 1;
				} else {
					int i2 = c * 2 - i;
					if (p[i2] < (r - i - 1)) {
						p[i] = p[i2];
						m = -1; 

					} else {
						p[i] = r - i;
						n = r + 1;
						m = i * 2 - n;
					}
				}
				while (m >= 0 && n < s2.length && s2[m] == s2[n]) {
					p[i]++;
					m--;
					n++;
				}
				if ((i + p[i]) > r) {
					c = i;
					r = i + p[i];
				}
			}
			

			int len = 0;
			c = 0;
			for (int i = 1; i < s2.length; i++) {
				if (len < p[i]) {
					len = p[i];
					c = i;
				}
			}
			char[] ss = Arrays.copyOfRange(s2, c - len, c + len + 1);
			return p;
		}

		private static char[] id4(char[] cs) {
			if (cs == null || cs.length == 0)
				return "||".toCharArray();

			char[] cs2 = new char[cs.length * 2 + 1];
			for (int i = 0; i < (cs2.length - 1); i = i + 2) {
				cs2[i] = '|';
				cs2[i + 1] = cs[i / 2];
			}
			cs2[cs2.length - 1] = '|';
			return cs2;
		}

		private static char[] id5(char[] cs) {
			if (cs == null || cs.length < 3)
				return "".toCharArray();

			char[] cs2 = new char[(cs.length - 1) / 2];
			for (int i = 0; i < cs2.length; i++) {
				cs2[i] = cs[i * 2 + 1];
			}
			return cs2;
		}
	}

	static class id13 {
		static final int maxk = 21, maxn = (1 << maxk) + 1; 

		static double[] ws_r = new double[maxn];
		static double[] ws_i = new double[maxn];
		static int[] dp = new int[maxn];
		static double[] rs_r = new double[maxn];
		static double[] rs_i = new double[maxn];
		static int n, k;
		static int lastk = -1;

		static void fft(boolean rev) {
			if (lastk != k) {
				lastk = k;
				dp[0] = 0;

				for (int i = 1, g = -1; i < n; ++i) {
					if ((i & (i - 1)) == 0) {
						++g;
					}
					dp[i] = dp[i ^ (1 << g)] ^ (1 << (k - 1 - g));
				}

				ws_r[1] = 1;
				ws_i[1] = 0;
				for (int two = 0; two < k - 1; ++two) {
					double alf = Math.PI / n * (1 << (k - 1 - two));
					double cur_r = Math.cos(alf), cur_i = Math.sin(alf);

					int p2 = (1 << two), p3 = p2 * 2;
					for (int j = p2; j < p3; ++j) {
						ws_r[j * 2] = ws_r[j];
						ws_i[j * 2] = ws_i[j];

						

						ws_r[j * 2 + 1] = ws_r[j] * cur_r - ws_i[j] * cur_i;
						ws_i[j * 2 + 1] = ws_r[j] * cur_i + ws_i[j] * cur_r;
					}
				}
			}
			for (int i = 0; i < n; ++i) {
				if (i < dp[i]) {
					double ar = a_r[i];
					double ai = a_i[i];
					a_r[i] = a_r[dp[i]];
					a_i[i] = a_i[dp[i]];
					a_r[dp[i]] = ar;
					a_i[dp[i]] = ai;

				}
			}
			if (rev) {
				for (int i = 0; i < n; ++i) {
					a_i[i] = -a_i[i];
				}
			}
			for (int len = 1; len < n; len <<= 1) {
				for (int i = 0; i < n; i += len) {
					int wit = len;
					for (int it = 0, j = i + len; it < len; ++it, ++i, ++j) {
						double tmp_r = a_r[j] * ws_r[wit] - a_i[j] * ws_i[wit];
						double tmp_i = a_r[j] * ws_i[wit] + a_i[j] * ws_r[wit];
						wit++;
						a_r[j] = a_r[i] - tmp_r;
						a_i[j] = a_i[i] - tmp_i;
						a_r[i] += tmp_r;
						a_i[i] += tmp_i;
						

						

					}
				}
			}
			

		}

		static double[] a_r = new double[maxn];
		static double[] a_i = new double[maxn];

		static long[] mult(long[] _a, long[] _b) {
			int na = _a.length, nb = _b.length;
			for (k = 0, n = 1; n < na + nb - 1; n <<= 1, ++k)
				;
			ass(n < maxn);
			for (int i = 0; i < n; ++i) {
				a_r[i] = i < na ? _a[i] : 0;
				a_i[i] = i < nb ? _b[i] : 0;
			}
			fft(false);
			a_r[n] = a_r[0];
			a_i[n] = a_i[0];
			double r_i = -1.0d / n / 4.0d;
			for (int i = 0; i <= n - i; ++i) {
				double tmp_r = a_r[i] * a_r[i] - a_i[i] * a_i[i];
				double tmp_i = a_r[i] * a_i[i] * 2.0;
				double id24 = a_r[n - i] * a_r[n - i] - a_i[n - i] * a_i[n - i];
				double id28 = a_r[n - i] * a_i[n - i] * -2.0;
				tmp_r = tmp_r - id24;
				tmp_i = tmp_i - id28;
				a_r[i] = -tmp_i * r_i;
				a_i[i] = tmp_r * r_i;

				a_r[n - i] = a_r[i];
				a_i[n - i] = -a_i[i];
			}
			fft(true);
			int res = 0;
			long[] ans = new long[maxn];
			

			for (int i = 0; i < n; ++i) {
				long val = Math.round(a_r[i]);
				ass(Math.abs(val - a_r[i]) < 1e-1);
				if (val != 0) {
					ass(i < na + nb - 1);
					while (res < i) {
						ans[res++] = 0;
					}
					ans[res++] = val;
				}
			}
			return ans;
		}

		static void ass(boolean f) {
			if (!f)
				System.out.println(1 / 0);
		}
	}

	private static class Sat2 {
		static void dfs1(ArrayList<Integer>[] graph, boolean[] used, ArrayList<Integer> order, int u) {
			used[u] = true;
			for (int v : graph[u]) {
				if (!used[v]) {
					dfs1(graph, used, order, v);
				}
			}
			order.add(u);
		}

		static void dfs2(ArrayList<Integer>[] reverseGraph, int[] comp, int u, int color) {
			comp[u] = color;
			for (int v : reverseGraph[u]) {
				if (comp[v] == -1) {
					dfs2(reverseGraph, comp, v, color);
				}
			}
		}

		public static boolean[] id2(ArrayList<Integer>[] graph) {
			int n = graph.length;
			boolean[] used = new boolean[n];
			ArrayList<Integer> order = new ArrayList<Integer>();
			for (int i = 0; i < n; i++) {
				if (!used[i]) {
					dfs1(graph, used, order, i);
				}
			}
			ArrayList<Integer>[] reverseGraph = new ArrayList[n];
			for (int i = 0; i < n; i++)
				reverseGraph[i] = new ArrayList<Integer>();
			for (int i = 0; i < n; i++) {
				for (int j : graph[i]) {
					reverseGraph[j].add(i);
				}
			}
			int[] comp = new int[n];
			Arrays.fill(comp, -1);
			for (int i = 0, color = 0; i < n; i++) {
				int u = order.get(n - i - 1);
				if (comp[u] == -1) {
					dfs2(reverseGraph, comp, u, color++);
				}
			}
			for (int i = 0; i < n; i++) {
				if (comp[i] == comp[i ^ 1])
					return null;
			}
			boolean[] res = new boolean[n / 2];
			for (int i = 0; i < n; i += 2)
				res[i / 2] = comp[i] > comp[i ^ 1];
			return res;
		}
	}

}