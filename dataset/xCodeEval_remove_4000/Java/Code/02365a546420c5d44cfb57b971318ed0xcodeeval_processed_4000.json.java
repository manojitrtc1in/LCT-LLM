import java.io.*;
import java.util.*;

public class id0 {

	long solve(int n, int m, int[] ls, int[] rs) {
		if (m == 1) {
			return 1;
		}

		long ans = 0;

		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				ans += solve(ls, rs, i, j, m);
				

			}
		}

		int[] add = new int[m + 1];
		for (int i = 0; i < n; i++) {
			add[ls[i]]++;
			add[rs[i] + 1]--;
		}

		long id2 = 0;
		int streak = 0;

		for (int i = 0; i < m; i++) {
			if (i > 0) {
				add[i] += add[i - 1];
			}
			if (add[i] == 0) {
				streak++;
			} else {
				streak = 0;
			}
			id2 += (long) streak * (streak + 1) / 2;
		}

		return ans - id2;
	}

	static final int B = 15;

	void stress() {
		for (int tst = 0;; tst++) {
			int n = rand(1, B);
			int m = rand(1, B);

			int[] ls = new int[n];
			int[] rs = new int[n];

			for (int i = 0; i < n; i++) {
				ls[i] = rand(0, m - 1);
				rs[i] = rand(0, m - 1);
				if (ls[i] > rs[i]) {
					int tmp = ls[i];
					ls[i] = rs[i];
					rs[i] = tmp;
				}
			}

			long slow = slow(n, m, ls, rs);
			long fast = solve(n, m, ls, rs);
			if (slow != fast) {
				System.err.println(n + " " + m);
				System.err.println(Arrays.toString(ls) + " "
						+ Arrays.toString(rs));
				System.err.println("slow " + slow);
				System.err.println("fast " + fast);
				throw new AssertionError();
			}

			System.err.println(tst);
		}
	}

	long slow(int n, int m, int[] ls, int[] rs) {
		long ans = 0;
		for (int l = 0; l < m; l++) {
			for (int r = l; r < m; r++) {
				boolean allOk = true;
				boolean id6 = false;
				for (int i = 0; i < n; i++) {
					int low = Math.max(ls[i], l);
					int high = Math.min(rs[i], r);
					if (low <= high && (high - low) % 2 == 1) {
						allOk = false;
					}
					if (low <= high) {
						id6 = true;
					}
				}

				if (allOk && id6) {
					

					ans += r - l + 1;
				}

			}
		}
		return ans;
	}

	void submit() {
		int n = nextInt();
		int m = nextInt();
		int[] ls = new int[n];
		int[] rs = new int[n];
		for (int i = 0; i < n; i++) {
			ls[i] = nextInt() - 1;
			rs[i] = nextInt() - 1;
		}

		out.println(solve(n, m, ls, rs));
		

	}

	static final int INF = Integer.MAX_VALUE / 10;

	static class GetResult {
		int max;
		int cntMax;
		long sumMax;
		
		public GetResult(int max, int cntMax, long sumMax) {
			this.max = max;
			this.cntMax = cntMax;
			this.sumMax = sumMax;
		}
	}
	static class Node {

		int l, r;

		Node left, right;

		int delta;
		int max;
		int cntMax;
		long sumMax;

		int getMax() {
			return max + delta;
		}

		void combine() {
			cntMax = left.cntMax;
			sumMax = left.sumMax;
			max = left.getMax();

			if (right.getMax() > left.getMax()) {
				cntMax = right.cntMax;
				sumMax = right.sumMax;
				max = right.getMax();
			} else if (right.getMax() == left.getMax()) {
				cntMax += right.cntMax;
				sumMax += right.sumMax;
			}
		}

		public Node(int l, int r, int odd) {
			this.l = l;
			this.r = r;
			if (r - l > 1) {
				int m = (l + r) >> 1;
				left = new Node(l, m, odd);
				right = new Node(m, r, odd);
				combine();
			} else {
				cntMax = 1;
				sumMax = 2 * l + odd;
				max = 0;
			}
		}

		void add(int ql, int qr, int deltaQ) {
			if (l >= qr || ql >= r) {
				return;
			}
			if (ql <= l && r <= qr) {
				delta += deltaQ;
				return;
			}
			left.add(ql, qr, deltaQ);
			right.add(ql, qr, deltaQ);
			combine();
		}

		GetResult getInfo(int ql, int qr) {
			if (l >= qr || ql >= r) {
				return null;
			}
			if (ql <= l && r <= qr) {
				return new GetResult(getMax(), cntMax, sumMax);
			}

			GetResult retL = left.getInfo(ql, qr);
			GetResult retR = right.getInfo(ql, qr);

			if (retL == null && retR == null) {
				return null;
			}
			if (retL == null) {
				retR.max += delta;
				return retR;
			}
			if (retR == null) {
				retL.max += delta;
				return retL;
			}
			retR.max += delta;
			retL.max += delta;
			if (retL.max > retR.max) {
				return retL;
			}
			if (retL.max < retR.max) {
				return retR;
			}
			retL.cntMax += retR.cntMax;
			retL.sumMax += retR.sumMax;
			return retL;
		}

	}
	
	int[] vis = new int[300000];
	int visVer = 0;
	int[] delta = new int[300000];
	
	int[] listPt = new int[30];
	int listSz = 0;

	long solve(int[] ls, int[] rs, int oddL, int oddR, int m) {

		


		int cntRs;
		if (oddR == 0) {
			cntRs = (m + 1) / 2;
		} else {
			cntRs = m / 2;
		}

		Node root = new Node(0, cntRs, oddR);

		int n = ls.length;

		

		

		

		


		int[] head = new int[m + 2];
		int[] next = new int[6 * n];
		

		int[] whatPos = new int[6 * n];
		int[][] id4 = new int[6 * n][];
		int evPtr = 0;
		Arrays.fill(head, -1);

		int[] id1 = new int[3];
		int[] posL = new int[3];
		int[] posR = new int[3];

		for (int i = 0; i < n; i++) {
			int low = ls[i];
			int high = rs[i];

			id1[0] = 0 + ((0 ^ oddL) & 1);
			id1[1] = low + ((low ^ oddL) & 1);
			id1[2] = high + (((high + 1) ^ oddL) & 1) + 1;

			posL[0] = -1;
			posL[1] = low + ((low ^ oddR) & 1);
			posL[2] = high + (((high + 1) ^ oddR) & 1) + 1;

			posR[0] = low - (((low - 1) ^ oddR) & 1) - 1;
			posR[1] = high - ((high ^ oddR) & 1);
			int pos = m - 1;
			posR[2] = pos - ((pos ^ oddR) & 1);

			for (int j = 0; j < 3; j++) {
				int whereEv = id1[j];
				int[] id3 = new int[6];
				int ptr = 0;
				for (int k = j; k < 3; k++) {
					int pos1 = id1[j];
					int segL = Math.max(posL[k],
							pos1 + ((pos1 ^ oddR) & 1));
					int segR = posR[k];

					if (segL > segR) {
						continue;
					}

					if (!isOk(whereEv, segL, low, high)) {
						continue;
					}

					segL /= 2;
					segR /= 2;

					id3[ptr++] = segL;
					id3[ptr++] = segR + 1;
				}

				id3 = Arrays.copyOf(id3, ptr);
				


				next[evPtr] = head[whereEv];
				head[whereEv] = evPtr;
				

				whatPos[evPtr] = i;
				id4[evPtr++] = id3;

				


				

				

			}

		}

		int[][] segms = new int[n][0];

		long ans = 0;

		for (int l = oddL; l < m; l += 2) {
			for (int e = head[l]; e >= 0; e = next[e]) {
				int idx = whatPos[e];

				int[] id3 = id4[e];

				int[] id5 = segms[idx];

				++visVer;
				listSz = 0;
				for (int i = 0; i < id5.length; i++) {
					int where = id5[i];
					int what = 1 - (i & 1) * 2;
					if (vis[where] != visVer) {
						vis[where] = visVer;
						listPt[listSz++] = where;
						delta[where] = 0;
					}
					delta[where] += what;
				}
				
				for (int i = 0; i < id3.length; i++) {
					int where = id3[i];
					int what = -1 + (i & 1) * 2;
					if (vis[where] != visVer) {
						vis[where] = visVer;
						listPt[listSz++] = where;
						delta[where] = 0;
					}
					delta[where] += what;
				}
				
				for (int i = 0; i < listSz; i++) {
					int where = listPt[i];
					int what = delta[where];
					if (where > 0 && what != 0) {
						root.add(0, where, what);
					}
				}
				

















































































































































				
				

				segms[idx] = id3;
			}

			int id7 = l + ((l ^ oddR) & 1);

			


			id7 /= 2;

			if (id7 < cntRs && root.getMax() == n) {


				GetResult get = root.getInfo(id7, cntRs);

				int max = get.max;
				if (max == n) {
					int cntMax = get.cntMax;
					long sumMax = get.sumMax;

					long delta = sumMax - (long) cntMax * l + cntMax;
					ans += delta;
				}
			}

		}

		return ans;
	}

	boolean isOk(int a, int b, int c, int d) {
		a = Math.max(a, c);
		b = Math.min(b, d);
		if (a <= b && (b - a) % 2 == 0) {
			return true;
		}
		if (a > b) {
			return true;
		}
		return false;
	}

	static class Event {
		int whichIdx;
		int[] id3;

		public Event(int whichIdx, int[] id3) {
			this.whichIdx = whichIdx;
			this.id3 = id3;
		}
	}

	void preCalc() {

	}

	void test() {
		int n = 200000;
		int m = 200000;

		int[] ls = new int[n];
		int[] rs = new int[n];

		for (int i = 0; i < n; i++) {
			ls[i] = rand(0, m - 1);
			rs[i] = rand(0, m - 1);
			if (ls[i] > rs[i]) {
				int tmp = ls[i];
				ls[i] = rs[i];
				rs[i] = tmp;
			}
		}

		long start = System.currentTimeMillis();
		long fast = solve(n, m, ls, rs);
		System.err.println(System.currentTimeMillis() - start + " ms");
		System.err.println(fast);
	}

	id0() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		preCalc();
		 submit();




		out.close();
	}

	static final Random rng = new Random();

	static int rand(int l, int r) {
		return l + rng.nextInt(r - l + 1);
	}

	public static void main(String[] args) throws IOException {
		new id0();
	}

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
		}
		return st.nextToken();
	}

	String nextString() {
		try {
			return br.readLine();
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
	}

	int nextInt() {
		return Integer.parseInt(nextToken());
	}

	long nextLong() {
		return Long.parseLong(nextToken());
	}

	double nextDouble() {
		return Double.parseDouble(nextToken());
	}
}