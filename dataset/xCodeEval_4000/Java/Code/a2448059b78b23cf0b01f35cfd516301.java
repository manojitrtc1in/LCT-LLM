import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.lang.reflect.Array;
import java.math.BigInteger;
import java.security.interfaces.DSAKey;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.Collections;
import java.util.Deque;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Scanner;
import java.util.Stack;
import java.util.StringTokenizer;
import java.util.TreeMap;
import java.util.TreeSet;

public class a {

	public static class in {
		static BufferedReader reader;
		static StringTokenizer tokenizer;

		static void init(InputStream input) throws FileNotFoundException {
			

			

			reader = new BufferedReader(new InputStreamReader(input));
			tokenizer = new StringTokenizer("");
		}

		static String next() throws IOException {
			while (!tokenizer.hasMoreTokens())
				tokenizer = new StringTokenizer(reader.readLine());
			return tokenizer.nextToken();
		}

		static int nextInt() throws IOException {
			return Integer.parseInt(next());
		}

		static double nextDouble() throws IOException {
			return Double.parseDouble(next());
		}

		static long nextLong() throws IOException {
			return Long.parseLong(next());
		}
	}

	public static long comp(int n, int r) {
		r = Math.min(r, n - r);
		long ans = 1;
		for (int i = 1; i <= r; i++) {
			ans = ans * (long) (n - r + i) / (long) i;
		}
		return ans;

	}

	public static class node {

		int x;
		int y;
		int p;

		node(int x, int y, int p) {
			this.x = x;
			this.y = y;
			this.p = p;

		}

	}

	public static long gcd(int x, int y) {
		if (y == 0)
			return x;
		return gcd(y, x % y);
	}

	public static int tree[];

	public static void add(int idx, long val, int n, int tree[]) {

		while (idx <= n) {
			tree[idx] += val;
			idx += (idx & -idx);
		}
	}

	public static int get(int idx) {
		int g = 0;
		while (idx > 0) {

			g += tree[idx];
			idx -= (idx & -idx);
		}

		return g;
	}

	public static class point implements Comparable<point> {
		int min;
		int a;
		int b;

		point(int min, int a, int b) {
			this.min = min;
			this.a = a;
			this.b = b;
		}

		@Override
		public int compareTo(point o) {
			if (o.min > min)
				return 1;
			else if (o.min < min)
				return -1;
			return 0;
		}
	}

	

	static String ReadLn(int maxLg) {
		byte lin[] = new byte[maxLg];
		int lg = 0, car = -1;
		String line = "";

		try {
			while (lg < maxLg) {
				car = System.in.read();
				if ((car < 0) || (car == '\n'))
					break;
				lin[lg++] += car;
			}
		} catch (IOException e) {
			return (null);
		}

		if ((car < 0) && (lg == 0))
			return (null);
		return (new String(lin, 0, lg));
	}

	

	

	

	

	


	public class LNode {
		public int value;
		public LNode next;

	}

	public static class ReverseLinkedList {
		

		public static LNode reverseLinkedList(LNode list) {
			

			int n = 0;
			LNode pointer = list;
			while (pointer != null) {
				n++;
				pointer = pointer.next;
			}

			int mid = (n + 1) / 2;
			if (n % 2 == 1)
				mid--;
			LNode arr[] = new LNode[n - mid];
			pointer = list;
			int p = 0;
			int c = 0;
			while (pointer != null) {

				if (c >= mid) {
					arr[p++] = pointer;
				}
				c++;
				pointer = pointer.next;
			}
			LNode swap = null;
			for (int i = 0; i < (n - mid) / 2; i++) {
				swap = arr[i];
				arr[i] = arr[n - mid - 1 - i];
				arr[n - mid - 1 - i] = swap;
			}

			pointer = list;
			p = 0;
			c = 0;
			while (pointer != null) {

				if (c >= mid - 1) {
					pointer.next = arr[p++];
				}
				c++;
				pointer = pointer.next;
			}

			return list;
		}
		

	}

	public static class points implements Comparable<points> {

		int dur;
		int idx;

		points(int d, int i) {
			dur = d;
			idx = i;
		}

		@Override
		public int compareTo(points o) {
			if (o.dur < dur)
				return 1;
			else if (o.dur > dur)
				return -1;
			else if (o.idx < idx)
				return 1;
			else
				return -1;

		}
	}

	public static int dx[] = { 1, 0, 0, -1 };
	public static int dy[] = { 0, 1, -1, 0 };
	public static char[][][] arr;
	public static boolean[][][] vis;
	public static int dp[][][];
	public static int n;
	public static int m;
	public static HashSet<Character>[] set;

	public static boolean check(int x, int y, int p) {
		if (x >= 0 && y >= 0 && x < n && y < m && !vis[x][y][p])
			return true;

		return false;
	}

	public static int solve(node st, node end) {
		Queue<node> q = new LinkedList();
		q.add(st);
		vis[st.x][st.y][st.p] = true;
		dp[st.x][st.y][st.p] = 0;
		while (!q.isEmpty()) {

			node e = q.poll();
			int x = e.x;
			int y = e.y;
			

			
			if (x == end.x && y == end.y)
				return dp[x][y][e.p];

			int new_p = (e.p + 1) % 4;
			if (!vis[x][y][new_p]) {
				dp[x][y][new_p] = dp[x][y][e.p] + 1;
				vis[x][y][new_p] = true;
				q.add(new node(x, y, new_p));
			}

			if (arr[x][y][e.p] == '+') {
				for (int i = 0; i < 4; i++) {
					int x1 = x + dx[i];
					int y1 = y + dy[i];
					if (check(x1, y1, e.p) && set[i].contains(arr[x1][y1][e.p])) {
						vis[x1][y1][e.p] = true;
						dp[x1][y1][e.p] = dp[x][y][e.p] + 1;
						q.add(new node(x1, y1, e.p));
					}
				}
			} else if (arr[x][y][e.p] == '-') {
				for (int i = 1; i < 3; i++) {
					int x1 = x + dx[i];
					int y1 = y + dy[i];
					if (check(x1, y1, e.p) && set[i].contains(arr[x1][y1][e.p])) {
						vis[x1][y1][e.p] = true;
						dp[x1][y1][e.p] = dp[x][y][e.p] + 1;
						q.add(new node(x1, y1, e.p));
					}
				}
			} else if (arr[x][y][e.p] == '|') {
				for (int i = 0; i < 4; i++) {
					if (i == 1 || i == 2)
						continue;
					int x1 = x + dx[i];
					int y1 = y + dy[i];
					if (check(x1, y1, e.p) && set[i].contains(arr[x1][y1][e.p])) {
						vis[x1][y1][e.p] = true;
						dp[x1][y1][e.p] = dp[x][y][e.p] + 1;
						q.add(new node(x1, y1, e.p));
					}
				}
			} else if (arr[x][y][e.p] == '^') {
				int x1 = x + dx[3];
				int y1 = y + dy[3];
				if (check(x1, y1, e.p) && set[3].contains(arr[x1][y1][e.p])) {
					vis[x1][y1][e.p] = true;
					dp[x1][y1][e.p] = dp[x][y][e.p] + 1;
					q.add(new node(x1, y1, e.p));
				}
			} else if (arr[x][y][e.p] == '>') {
				int x1 = x + dx[1];
				int y1 = y + dy[1];
				if (check(x1, y1, e.p) && set[1].contains(arr[x1][y1][e.p])) {
					vis[x1][y1][e.p] = true;
					dp[x1][y1][e.p] = dp[x][y][e.p] + 1;
					q.add(new node(x1, y1, e.p));
				}
			} else if (arr[x][y][e.p] == 'v') {
				int x1 = x + dx[0];
				int y1 = y + dy[0];
				if (check(x1, y1, e.p) && set[0].contains(arr[x1][y1][e.p])) {
					vis[x1][y1][e.p] = true;
					dp[x1][y1][e.p] = dp[x][y][e.p] + 1;
					q.add(new node(x1, y1, e.p));
				}
			} else if (arr[x][y][e.p] == '<') {
				int x1 = x + dx[2];
				int y1 = y + dy[2];
				if (check(x1, y1, e.p) && set[2].contains(arr[x1][y1][e.p])) {
					vis[x1][y1][e.p] = true;
					dp[x1][y1][e.p] = dp[x][y][e.p] + 1;
					q.add(new node(x1, y1, e.p));
				}
			} else if (arr[x][y][e.p] == 'L') {
				for (int i = 0; i < 4; i++) {
					if (i == 2)
						continue;
					int x1 = x + dx[i];
					int y1 = y + dy[i];
					if (check(x1, y1, e.p) && set[i].contains(arr[x1][y1][e.p])) {
						vis[x1][y1][e.p] = true;
						dp[x1][y1][e.p] = dp[x][y][e.p] + 1;
						q.add(new node(x1, y1, e.p));
					}
				}

			} else if (arr[x][y][e.p] == 'R') {
				for (int i = 0; i < 4; i++) {
					if (i == 1)
						continue;
					int x1 = x + dx[i];
					int y1 = y + dy[i];
					if (check(x1, y1, e.p) && set[i].contains(arr[x1][y1][e.p])) {
						vis[x1][y1][e.p] = true;
						dp[x1][y1][e.p] = dp[x][y][e.p] + 1;
						q.add(new node(x1, y1, e.p));
					}
				}
			} else if (arr[x][y][e.p] == 'U') {
				for (int i = 0; i < 4; i++) {
					if (i == 3)
						continue;
					int x1 = x + dx[i];
					int y1 = y + dy[i];
					if (check(x1, y1, e.p) && set[i].contains(arr[x1][y1][e.p])) {
						vis[x1][y1][e.p] = true;
						dp[x1][y1][e.p] = dp[x][y][e.p] + 1;
						q.add(new node(x1, y1, e.p));
					}
				}
			} else if (arr[x][y][e.p] == 'D') {
				for (int i = 0; i < 4; i++) {
					if (i == 0)
						continue;
					int x1 = x + dx[i];
					int y1 = y + dy[i];
					if (check(x1, y1, e.p) && set[i].contains(arr[x1][y1][e.p])) {
						vis[x1][y1][e.p] = true;
						dp[x1][y1][e.p] = dp[x][y][e.p] + 1;
						q.add(new node(x1, y1, e.p));
					}
				}
			}

		}
		return -1;
	}

	public static void main(String[] args) throws IOException {
		

		in.init(System.in);
		PrintWriter out = new PrintWriter(System.out);
		n = in.nextInt();
		m = in.nextInt();
		set = new HashSet[4];
		for (int i = 0; i < 4; i++) {
			set[i] = new HashSet();
		}
		set[0].add('+');
		set[0].add('^');
		set[0].add('|');
		set[0].add('L');
		set[0].add('R');
		set[0].add('D');
		

		set[1].add('+');
		set[1].add('<');
		set[1].add('-');
		set[1].add('U');
		set[1].add('R');
		set[1].add('D');
		

		set[2].add('+');
		set[2].add('>');
		set[2].add('-');
		set[2].add('L');
		set[2].add('U');
		set[2].add('D');
		

		set[3].add('+');
		set[3].add('v');
		set[3].add('|');
		set[3].add('L');
		set[3].add('R');
		set[3].add('U');
		

		arr = new char[n][m][4];
		vis = new boolean[n][m][4];
		dp = new int[n][m][4];
		for (int i = 0; i < n; i++) {
			String a = in.next();
			for (int j = 0; j < m; j++) {

				if (a.charAt(j) == '+') {
					arr[i][j][0] = a.charAt(j);
					arr[i][j][1] = a.charAt(j);
					arr[i][j][2] = a.charAt(j);
					arr[i][j][3] = a.charAt(j);

				} else if (a.charAt(j) == '*') {
					arr[i][j][0] = a.charAt(j);
					arr[i][j][1] = a.charAt(j);
					arr[i][j][2] = a.charAt(j);
					arr[i][j][3] = a.charAt(j);
				} else if (a.charAt(j) == '-') {
					arr[i][j][0] = a.charAt(j);
					arr[i][j][1] = '|';
					arr[i][j][2] = a.charAt(j);
					arr[i][j][3] = '|';
				} else if (a.charAt(j) == '|') {
					arr[i][j][0] = a.charAt(j);
					arr[i][j][1] = '-';
					arr[i][j][2] = a.charAt(j);
					arr[i][j][3] = '-';
				} else if (a.charAt(j) == '^') {
					arr[i][j][0] = a.charAt(j);
					arr[i][j][1] = '>';
					arr[i][j][2] = 'v';
					arr[i][j][3] = '<';
				} else if (a.charAt(j) == '>') {
					arr[i][j][0] = a.charAt(j);
					arr[i][j][1] = 'v';
					arr[i][j][2] = '<';
					arr[i][j][3] = '^';
				} else if (a.charAt(j) == '<') {
					arr[i][j][0] = a.charAt(j);
					arr[i][j][1] = '^';
					arr[i][j][2] = '>';
					arr[i][j][3] = 'v';
				} else if (a.charAt(j) == 'v') {
					arr[i][j][0] = a.charAt(j);
					arr[i][j][1] = '<';
					arr[i][j][2] = '^';
					arr[i][j][3] = '>';
				} else if (a.charAt(j) == 'L') {
					arr[i][j][0] = a.charAt(j);
					arr[i][j][1] = 'U';
					arr[i][j][2] = 'R';
					arr[i][j][3] = 'D';
				} else if (a.charAt(j) == 'R') {
					arr[i][j][0] = a.charAt(j);
					arr[i][j][1] = 'D';
					arr[i][j][2] = 'L';
					arr[i][j][3] = 'U';
				} else if (a.charAt(j) == 'U') {
					arr[i][j][0] = a.charAt(j);
					arr[i][j][1] = 'R';
					arr[i][j][2] = 'D';
					arr[i][j][3] = 'L';
				} else if (a.charAt(j) == 'D') {
					arr[i][j][0] = a.charAt(j);
					arr[i][j][1] = 'L';
					arr[i][j][2] = 'U';
					arr[i][j][3] = 'R';
				}

			}
		}

		int stx = in.nextInt()-1;
		int endx = in.nextInt()-1;
		int sty = in.nextInt()-1;
		int endy = in.nextInt()-1;

		out.println(solve(new node(stx, endx, 0), new node(sty, endy, 0)));

		out.close();

	}
}
