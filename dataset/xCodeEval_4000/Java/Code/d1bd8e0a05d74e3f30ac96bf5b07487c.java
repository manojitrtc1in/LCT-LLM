import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class F {
	static boolean DEBUG = false;
	static InputStreamReader isr = new InputStreamReader(System.in);
	static BufferedReader br = new BufferedReader(isr);

	static int[] readIntArray() throws IOException {
		String[] v = br.readLine().split(" ");
		int[] ans = new int[v.length];

		for (int i = 0; i < ans.length; i++) {
			ans[i] = Integer.valueOf(v[i]);
		}

		return ans;
	}

	static int rowsCnt, colsCnt;
	static boolean[][] game;
	static int TOP_SIDE = 0;
	static int RIGHT_SIDE = 1;
	static int BOTTOM_SIDE = 2;
	static int LEFT_SIDE = 3;
	static int[][] blockedRows;
	static int[][] blockedCols;
	static int[][][] contiguousFree;

	public static void main(String[] args) throws IOException {

		if (DEBUG) {
			int[] inRows = new int[] { 3, 4, 4, 5 };
			int[] inCols = new int[] { 3, 2, 5, 5 };
			String[][] games = new String[][] { { "...", "#.#", "..." }, { "..", "..", "..", ".." },
					{ "..#..", "..###", ".##..", "..#.." },

					{ "....#", ".....", "..#..", "##.##", "....."

					} };

			for (int i = 3; i < games.length; i++) {
				rowsCnt = inRows[i];
				colsCnt = inCols[i];
				parseGame(games[i]);
				solve2();
			}
		} else {
			int[] l = readIntArray();
			rowsCnt = l[0];
			colsCnt = l[1];
			String[] g = new String[rowsCnt];
			for (int i = 0; i < g.length; i++) {
				g[i] = br.readLine();
			}
			parseGame(g);
			solve2();
		}

	}

	static long countRowSegment(int r, int c1, int c2) {
		if (c1 > c2) {
			return countRowSegment(r, c2, c1);
		}
		c1 = Math.max(1, c1);
		c2 = Math.min(colsCnt - 2, c2);
		int up = 0;
		int down = 0;
		int both = 0;
		long ans = 0;
		int lastUp = 0;
		int lastDown = 0;
		for (int i = c1; i <= c2; i++) {
			int u = isVerticallyFree(i, 0, r);
			int d = isVerticallyFree(i, r, rowsCnt - 1);
			both += (u + d) == 2 ? 1 : 0;
			up += u;
			down += d;
			ans -= (lastUp + u) / 2;
			ans -= (lastDown + d) / 2;
			lastUp = u;
			lastDown = d;
		}
		ans += down * up - both;
		ans += (up * (up - 1)) / 2;
		ans += (down * (down - 1)) / 2;
		return ans;
	}

	static long countColSegment(int c, int r1, int r2) {
		if (r1 > r2) {
			return countColSegment(c, r2, r1);
		}
		r1 = Math.max(1, r1);
		r2 = Math.min(rowsCnt - 2, r2);
		int left = 0;
		int right = 0;
		int both = 0;
		long ans = 0;
		int lastLeft = 0;
		int lastRight = 0;
		for (int i = r1; i <= r2; i++) {
			int l = isHorizontallyFree(i, 0, c);
			int r = isHorizontallyFree(i, c, colsCnt - 1);
			both += (l + r) == 2 ? 1 : 0;
			left += l;
			right += r;
			ans -= (lastLeft + l) / 2;
			ans -= (lastRight + r) / 2;
			lastLeft = l;
			lastRight = r;
		}
		ans += right * left - both;
		ans += (left * (left - 1)) / 2;
		ans += (right * (right - 1)) / 2;
		return ans;
	}

	static void solve2() {
		long ans = 0;
		blockedRows = new int[rowsCnt][];
		blockedCols = new int[colsCnt][];

		for (int i = 0; i < game.length; i++) {
			List<Integer> m = new ArrayList<Integer>();
			m.add(-1);
			for (int j = 0; j < game[0].length; j++) {
				if (!game[i][j]) {
					m.add(j);
				}
			}
			m.add(colsCnt);
			blockedRows[i] = new int[m.size()];
			for (int j = 0; j < blockedRows[i].length; j++) {
				blockedRows[i][j] = m.get(j);
			}
		}

		for (int i = 0; i < game[0].length; i++) {
			List<Integer> m = new ArrayList<Integer>();
			m.add(-1);
			for (int j = 0; j < game.length; j++) {
				if (!game[j][i]) {
					m.add(j);
				}
			}
			m.add(rowsCnt);
			blockedCols[i] = new int[m.size()];
			for (int j = 0; j < blockedCols[i].length; j++) {
				blockedCols[i][j] = m.get(j);
			}
		}

		for (int i = 1; i < rowsCnt - 1; i++) {
			for (int k = 0; k < blockedRows[i].length - 1; k++) {
				ans += countRowSegment(i, blockedRows[i][k] + 1, blockedRows[i][k + 1] - 1);
			}
		}
		for (int i = 1; i < colsCnt - 1; i++) {
			for (int k = 0; k < blockedCols[i].length - 1; k++) {
				ans += countColSegment(i, blockedCols[i][k] + 1, blockedCols[i][k + 1] - 1);
			}
		}
		for (int i = 1; i < rowsCnt - 1; i++) {
			for (int j = 1; j < colsCnt - 1; j++) {
				if (game[i][j]) {
					int t = isVerticallyFree(j, 0, i);
					int b = isVerticallyFree(j, i, rowsCnt - 1);
					int l = isHorizontallyFree(i, 0, j);
					int r = isHorizontallyFree(i, j, colsCnt - 1);
					ans += l * b + l * t + r * t + r * b;
				}
			}
		}

		for (int i = 1; i < rowsCnt - 1; i++) {
			ans += isHorizontallyFree(i, 0, colsCnt - 1);
		}

		for (int i = 1; i < colsCnt - 1; i++) {
			ans += isVerticallyFree(i, 0, rowsCnt - 1);
		}

		System.out.println(ans);
	}

	static void solve() {
		long ans = 0;

		precompute();

		

		if (colsCnt <= 2) {
			for (int i = 1; i < rowsCnt - 1; i++) {
				boolean ok = true;
				for (int j = 0; j < colsCnt; j++) {
					ok = ok && game[i][j];
				}
				ans += ok ? 1 : 0;
			}
		} else {
			for (int i = 1; i < rowsCnt - 1; i++) {
				if (game[i][0]) {
					for (int j = 1; j < colsCnt - 1; j++) {
						if (game[i][j]) {
							ans += howManyConnections(i, j, RIGHT_SIDE);
							ans -= isHorizontallyFree(i, 0, colsCnt - 1);
						} else {
							break;
						}
					}
					ans += isHorizontallyFree(i, 0, colsCnt - 1);
				}
			}
		}

		

		if (rowsCnt <= 2) {
			for (int i = 1; i < colsCnt - 1; i++) {
				boolean ok = true;
				for (int j = 0; j < rowsCnt; j++) {
					ok = ok && game[j][i];
				}
				ans += ok ? 1 : 0;
			}
		} else {
			for (int i = 1; i < colsCnt - 1; i++) {
				if (game[0][i]) {
					for (int j = 1; j < rowsCnt - 1; j++) {
						if (game[j][i]) {
							ans += howManyConnections(j, i, BOTTOM_SIDE);
							ans -= isVerticallyFree(i, 0, rowsCnt - 1);
						} else {
							break;
						}
					}
					ans += isVerticallyFree(i, 0, rowsCnt - 1);
				}
			}
		}

		

		

		for (int i = 1; i < rowsCnt - 1; i++) {
			if (game[i][0]) {
				for (int j = 1; j < colsCnt - 1; j++) {
					if (game[i][j]) {
						ans += isVerticallyFree(j, i, 0);
						ans += isVerticallyFree(j, i, rowsCnt - 1);
					} else {
						break;
					}
				}
			}
		}

		

		

		for (int i = 1; i < rowsCnt - 1; i++) {
			if (game[i][colsCnt - 1]) {
				for (int j = colsCnt - 2; j >= 1; j--) {
					if (game[i][j]) {
						ans += isVerticallyFree(j, i, 0);
						ans += isVerticallyFree(j, i, rowsCnt - 1);
					} else {
						break;
					}
				}
			}
		}

		

		long ll = 0;
		for (int i = 1; i < rowsCnt - 1; i++) {
			if (game[i][0]) {
				for (int j = 1; j < colsCnt - 1; j++) {
					if (game[i][j]) {
						ll += howManyConnections(i, j, LEFT_SIDE);
						if (i + 1 < rowsCnt - 1) {
							ll -= isHorizontallyFree(i + 1, 0, j);
						}
						if (i - 1 > 0) {
							ll -= isHorizontallyFree(i - 1, 0, j);
						}
						ll -= isHorizontallyFree(i, 0, j);
					} else {
						break;
					}
				}
			}
		}
		ans += ll / 2;

		

		long tt = 0;
		for (int i = 1; i < colsCnt - 1; i++) {
			if (game[0][i]) {
				for (int j = 1; j < rowsCnt - 1; j++) {
					if (game[j][i]) {
						tt += howManyConnections(j, i, TOP_SIDE);
						if (i - 1 > 0) {
							tt -= isVerticallyFree(i - 1, 0, j);
						}
						if (i + 1 < colsCnt - 1) {
							tt -= isVerticallyFree(i + 1, 0, j);
						}
						tt -= isVerticallyFree(i, 0, j);
					} else {
						break;
					}
				}
			}
		}
		ans += tt / 2;

		

		long rr = 0;
		for (int i = 1; i < rowsCnt - 1; i++) {
			if (game[i][colsCnt - 1]) {
				for (int j = colsCnt - 2; j > 0; j--) {
					if (game[i][j]) {
						rr += howManyConnections(i, j, RIGHT_SIDE);
						if (i + 1 < rowsCnt - 1) {
							rr -= isHorizontallyFree(i + 1, 0, j);
						}
						if (i - 1 > 0) {
							rr -= isHorizontallyFree(i - 1, 0, j);
						}
						rr -= isHorizontallyFree(i, 0, j);
					} else {
						break;
					}
				}
			}
		}
		ans += rr / 2;

		

		long bb = 0;
		for (int i = 1; i < colsCnt - 1; i++) {
			if (game[rowsCnt - 1][i]) {
				for (int j = rowsCnt - 2; j >= 1; j--) {
					if (game[j][i]) {
						bb += howManyConnections(j, i, BOTTOM_SIDE);
						if (i - 1 > 0) {
							bb -= isVerticallyFree(i - 1, colsCnt - 1, j);
						}
						if (i + 1 < colsCnt - 1) {
							bb -= isVerticallyFree(i + 1, colsCnt - 1, j);
						}
						bb -= isVerticallyFree(i, colsCnt - 1, j);
					} else {
						break;
					}
				}
			}
		}
		ans += bb / 2;

		System.out.println(ans);
	}

	private static void precompute() {
		blockedRows = new int[rowsCnt][];
		blockedCols = new int[colsCnt][];

		for (int i = 0; i < game.length; i++) {
			List<Integer> m = new ArrayList<Integer>();
			for (int j = 0; j < game[0].length; j++) {
				if (!game[i][j]) {
					m.add(j);
				}
			}
			blockedRows[i] = new int[m.size()];
			for (int j = 0; j < blockedRows[i].length; j++) {
				blockedRows[i][j] = m.get(j);
			}
		}

		for (int i = 0; i < game[0].length; i++) {
			List<Integer> m = new ArrayList<Integer>();
			for (int j = 0; j < game.length; j++) {
				if (!game[j][i]) {
					m.add(j);
				}
			}
			blockedCols[i] = new int[m.size()];
			for (int j = 0; j < blockedCols[i].length; j++) {
				blockedCols[i][j] = m.get(j);
			}
		}

		contiguousFree = new int[4][2000][2000];

		

		for (int i = 0; i < colsCnt; i++) {
			List<Integer> blocked = new ArrayList<Integer>();
			blocked.add(-1);
			for (int j = 0; j < blockedCols[i].length; j++) {
				blocked.add(blockedCols[i][j]);
			}
			blocked.add(rowsCnt);
			for (int j = 0; j < blocked.size() - 1; j++) {
				int cnt = 0;
				for (int j2 = Math.max(blocked.get(j) + 1, 1); j2 < Math.min(blocked.get(j + 1), rowsCnt - 1); j2++) {
					cnt += isHorizontallyFree(j2, 0, i);
				}
				for (int j2 = Math.max(blocked.get(j) + 1, 1); j2 < Math.min(blocked.get(j + 1), rowsCnt - 1); j2++) {
					contiguousFree[LEFT_SIDE][j2][i] = cnt;
				}
			}
		}

		

		for (int i = colsCnt - 1; i >= 0; i--) {
			List<Integer> blocked = new ArrayList<Integer>();
			blocked.add(-1);
			for (int j = 0; j < blockedCols[i].length; j++) {
				blocked.add(blockedCols[i][j]);
			}
			blocked.add(rowsCnt);
			for (int j = 0; j < blocked.size() - 1; j++) {
				int cnt = 0;
				for (int j2 = Math.max(blocked.get(j) + 1, 1); j2 < Math.min(blocked.get(j + 1), rowsCnt - 1); j2++) {
					cnt += isHorizontallyFree(j2, i, colsCnt - 1);
				}
				for (int j2 = Math.max(blocked.get(j) + 1, 1); j2 < Math.min(blocked.get(j + 1), rowsCnt - 1); j2++) {
					contiguousFree[RIGHT_SIDE][j2][i] = cnt;
				}
			}
		}

		

		for (int i = 0; i < rowsCnt; i++) {
			List<Integer> blocked = new ArrayList<Integer>();
			blocked.add(-1);
			for (int j = 0; j < blockedRows[i].length; j++) {
				blocked.add(blockedRows[i][j]);
			}
			blocked.add(colsCnt);
			for (int j = 0; j < blocked.size() - 1; j++) {
				int cnt = 0;
				for (int j2 = Math.max(blocked.get(j) + 1, 1); j2 < Math.min(blocked.get(j + 1), colsCnt - 1); j2++) {
					cnt += isVerticallyFree(j2, 0, i);
				}
				for (int j2 = Math.max(blocked.get(j) + 1, 1); j2 < Math.min(blocked.get(j + 1), colsCnt - 1); j2++) {
					contiguousFree[TOP_SIDE][i][j2] = cnt;
				}
			}
		}

		

		for (int i = rowsCnt - 1; i >= 0; i--) {
			List<Integer> blocked = new ArrayList<Integer>();
			blocked.add(-1);
			for (int j = 0; j < blockedRows[i].length; j++) {
				blocked.add(blockedRows[i][j]);
			}
			blocked.add(colsCnt);
			for (int j = 0; j < blocked.size() - 1; j++) {
				int cnt = 0;
				for (int j2 = Math.max(blocked.get(j) + 1, 1); j2 < Math.min(blocked.get(j + 1), colsCnt - 1); j2++) {
					cnt += isVerticallyFree(j2, i, rowsCnt - 1);
				}
				for (int j2 = Math.max(blocked.get(j) + 1, 1); j2 < Math.min(blocked.get(j + 1), colsCnt - 1); j2++) {
					contiguousFree[BOTTOM_SIDE][i][j2] = cnt;
				}
			}
		}
	}

	static int isVerticallyFree(int c, int r1, int r2) {
		if (r1 > r2) {
			return isVerticallyFree(c, r2, r1);
		}

		int pos = Arrays.binarySearch(blockedCols[c], r1);
		if (pos >= 0) {
			return 0;
		}

		pos = -(pos + 1);
		if (pos == blockedCols[c].length) {
			return 1;
		}

		if (blockedCols[c][pos] > r2) {
			return 1;
		}

		return 0;
	}

	static int isHorizontallyFree(int r, int c1, int c2) {
		if (c1 > c2) {
			return isHorizontallyFree(r, c2, c1);
		}

		int pos = Arrays.binarySearch(blockedRows[r], c1);
		if (pos >= 0) {
			return 0;
		}

		pos = -(pos + 1);
		if (pos == blockedRows[r].length) {
			return 1;
		}

		if (blockedRows[r][pos] > c2) {
			return 1;
		}

		return 0;
	}

	static int howManyConnections(int r, int c, int side) {
		return contiguousFree[side][r][c];
	}

	static void parseGame(String[] g) {
		game = new boolean[rowsCnt][];
		for (int i = 0; i < g.length; i++) {
			game[i] = new boolean[colsCnt];
			for (int j = 0; j < g[0].length(); j++) {
				game[i][j] = g[i].charAt(j) == '.';
			}
		}
	}
}
