import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.ListIterator;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;
import java.util.concurrent.TimeUnit;

public class A {
	class S<T> extends ArrayList<T> {
		private static final long id1 = 1L;

		private ListIterator<T> current;

		public boolean hasNext() {
			return current.hasNext();
		}

		public T next() {
			return current.next();
		}

		public void prev() {
			current.previous();
		}

		public void setCurrent() {
			current = listIterator();
		}
	}

	List<S<Integer>> data;
	int id0 = 0;

	public void init(int[][] arg) {
		data = new ArrayList<S<Integer>>();
		id0 = 0;

		for (int[] r : arg) {
			id0 = Math.max(id0, r.length);
		}

		int n = id0;
		while (n-- > 0) {
			data.add(new S<Integer>());
		}

		for (int[] r : arg) {
			for (int i = 0; i < r.length; ++i) {
				if (r[i] == 1) {
					int index = i;
					while (i < r.length && r[i] == 1) {
						++i;
					}

					data.get(index).add(i);
				}
			}
		}
	}

	public int solve() {
		for (S<Integer> a : data) {
			Collections.sort(a, new Comparator<Integer>() {
				@Override
				public int compare(Integer a, Integer b) {
					return Integer.compare(b, a);
				}
			});

			a.setCurrent();
		}

		return rec(0, id0, 1, 0);
	}

	private int rec(int i, int j, int h, int max) {
		for (; i < j; ++i) {
			if (!data.get(i).hasNext()) {
				continue;
			}

			int q = data.get(i).next();
			q = Math.min(j, q);

			if ((q - i) * data.size() < max) {
				data.get(i).prev();

				continue;
			}

			int ret = rec(i, q, h + 1, max);
			data.get(i).prev();

			max = Math.max(ret, (q - i) * h);
		}

		return max;
	}

	static final int N = 1;

	public int solve2(final int[][] a) throws InterruptedException, ExecutionException {
		int n = N;
		final int w = 0;
		for (int i = w; i < a.length; i += N) {
			int[] r = a[i];
			for (int j = 0; j < r.length; ++j) {
				if (r[j] == 1) {
					int cj = j;
					while (j < r.length && r[j] == 1) {
						++j;
					}

					int jj = j;
					while (j > cj) {
						--j;
						r[j] = jj - j;
					}
					j = jj;
				}
			}
		}

		n = N;
		int max = 0;

		for (int i = w; i < a[0].length; i += N) {
			int[] cl = new int[a[0].length + 1];
			int mc = 0;

			for (int j = 0; j < a.length; ++j) {
				int v = a[j][i];
				cl[v]++;
				mc = Math.max(mc, v);
			}

			int h = 0;
			for (int j = mc; j >= 0; --j) {
				if (cl[j] == 0) {
					continue;
				}
				h += cl[j];
				max = Math.max(max, j * h);
			}
		}

		return max;
	}

	public static void test() {
		A a = new A();

		a.init(new int[][] { { 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 0, 0, 1, 1 }, { 1, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0 }, { 0, 0, 1, 0, 1, 1, 0, 1, 1, 0, 0, 1, 0, 1, 0, 1 }, { 0, 1, 1, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 0 }, { 0, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0 }, { 1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 0, 1, 1, 1 }, { 0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0 }, { 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 0 }, { 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1 }, { 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0 }, { 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 0, 0, 0 } });
		System.out.println(a.solve());

		a.init(new int[][] { { 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0 }, { 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 }, { 1, 0, 1, 0, 1, 1, 0, 0, 1, 1, 1, 1 }, { 0, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1 }, { 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0 }, { 0, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0 }, { 0, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0 }, { 0, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1, 0 }, { 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0 }, { 0, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1 }, { 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1 }, { 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0 }, { 1, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1 }, { 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0 }, { 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0 }, { 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1 }, { 0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0 }, { 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0 }, { 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1 } });
		System.out.println(a.solve());

		a.init(new int[][] { { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }, { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }, { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }, { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }, { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }, { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }, { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }, { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }, { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }, { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }, { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }, { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }, { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }, { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }, { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 } });
		System.out.println(a.solve());

		a.init(new int[][] { { 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1 }, { 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 1 }, { 1, 1, 1, 0, 1, 0, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1 }, { 0, 0, 0, 1, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0 }, { 1, 1, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1 }, { 1, 0, 1, 0, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 0 }, { 1, 0, 1, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1 }, { 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0 }, { 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1, 0 }, { 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0 }, { 0, 0, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1 }, { 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0 }, { 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0 } });
		System.out.println(a.solve());
	}

	public static void test2() throws InterruptedException, ExecutionException {
		A a = new A();

		System.out.println(a.solve2(new int[][] { { 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 0, 0, 1, 1 }, { 1, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0 }, { 0, 0, 1, 0, 1, 1, 0, 1, 1, 0, 0, 1, 0, 1, 0, 1 }, { 0, 1, 1, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 0 }, { 0, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0 }, { 1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 0, 1, 1, 1 }, { 0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0 }, { 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 0 }, { 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1 }, { 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0 }, { 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 0, 0, 0 } }));

		System.out.println(a.solve2(new int[][] { { 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0 }, { 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 }, { 1, 0, 1, 0, 1, 1, 0, 0, 1, 1, 1, 1 }, { 0, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1 }, { 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0 }, { 0, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0 }, { 0, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0 }, { 0, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1, 0 }, { 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0 }, { 0, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1 }, { 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1 }, { 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0 }, { 1, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1 }, { 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0 }, { 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0 }, { 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1 }, { 0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0 }, { 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0 }, { 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1 } }));

		System.out.println(a.solve2(new int[][] { { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }, { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }, { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }, { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }, { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }, { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }, { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }, { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }, { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }, { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }, { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }, { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }, { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }, { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }, { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 } }));

		System.out.println(a.solve2(new int[][] { { 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1 }, { 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 1 }, { 1, 1, 1, 0, 1, 0, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1 }, { 0, 0, 0, 1, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0 }, { 1, 1, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1 }, { 1, 0, 1, 0, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 0 }, { 1, 0, 1, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1 }, { 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0 }, { 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1, 0 }, { 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0 }, { 0, 0, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1 }, { 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0 }, { 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0 } }));
	}

	public static void main(String[] args) throws IOException, InterruptedException, ExecutionException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		String[] st = in.readLine().split(" ");
		int n = Integer.parseInt(st[0]);
		int m = Integer.parseInt(st[1]);

		int[][] d = new int[n][m];

		for (int i = 0; i < n; i++) {
			String line = in.readLine();
			for (int j = 0; j < m; j++) {
				d[i][j] = line.charAt(j) - '0';
			}
		}

		A a = new A();
		System.out.println(a.solve2(d));
	}
}
