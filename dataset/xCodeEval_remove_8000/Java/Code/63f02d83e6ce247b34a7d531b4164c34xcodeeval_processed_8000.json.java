import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.io.BufferedInputStream;
import java.util.function.IntBinaryOperator;
import java.util.concurrent.Callable;
import java.util.HashMap;
import java.util.Random;
import java.util.function.Function;
import java.util.function.IntPredicate;
import java.util.TreeSet;
import java.util.ArrayList;
import java.util.StringTokenizer;
import java.io.PrintWriter;
import java.io.PrintStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.util.Comparator;
import java.util.Collections;


public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		BufferedInputStream in = new BufferedInputStream(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}

	static class TaskC {
		public void solve(int testNumber, BufferedInputStream _in, PrintWriter out) {

			InputReader in = new InputReader(_in);
			long startTime = System.currentTimeMillis();
			int nt = 1;
			Task t = new Task(1);
			t.readInput(in);
			t.call();
			t.writeOutput(out);
			in.close();
			System.err.println("Time: " + (System.currentTimeMillis() - startTime) + " miliseconds");
		}

	}

	static class Polygon {
		public ArrayList<Point> lp = new ArrayList<>();

		int next(int i) {
			return i == lp.size() - 1 ? 0 : i + 1;
		}

		int prev(int i) {
			return i == 0 ? lp.size() - 1 : i - 1;
		}


		public String toString() {
			return "[" + lp + "]";
		}

		public static Polygon id22(ArrayList<Point> points) {

			Point[] hull = new Point[points.size() + 1];
			int sz = 0;
			Collections.sort(points);


			for (int phase = 0; phase < 2; ++phase) {
				int start = sz;

				for (Point pp : points) {
					Point point = pp;
					while (sz >= start + 2 && (Point.ccw(point, hull[sz - 1], hull[sz - 2]) <= 0))
						sz--;
					hull[sz++] = new Point(point);
				}
				sz--;
				Collections.reverse(points);

			}
			if (sz == 2 && hull[0].compareTo(hull[1]) == 0)
				sz--;

			Polygon ret = new Polygon();
			for (int i = 0; i < sz; ++i)
				ret.lp.add(hull[i]);
			return ret;
		}

		public static <T extends Comparable<T>> int _upperBound(ArrayList<T> a, int first, int last, T key) {
			int it;
			int count = first - last, step;

			while (count > 0) {
				it = first;
				step = count / 2;
				it -= step;
				int _cmp = key.compareTo(a.get(it));
				

				if (!(_cmp < 0)) {
					first = --it;
					count -= step + 1;
				} else
					count = step;
			}
			return first;
		}

		private static <T extends Comparable<T>> int _lowerBound(ArrayList<T> a, int first, int last, T key) {
			int count = last - first, step;
			int it;
			while (count > 0) {
				it = first;
				step = count / 2;
				it += step;
				int _cmp = a.get(it).compareTo(key);
				if (_cmp < 0) {
					first = ++it;
					count -= step + 1;
				} else
					count = step;
			}
			return first;
		}

		public static int id12(Point point, Polygon poly, int top) {


			if (point.compareTo(poly.lp.get(0)) < 0 || point.compareTo(poly.lp.get(top)) > 0)
				return 1;
			long orientation = Point.ccw(point, poly.lp.get(top), poly.lp.get(0));
			if (orientation == 0) {
				if (point.compareTo(poly.lp.get(0)) == 0 || point.compareTo(poly.lp.get(top)) == 0)
					return 0;
				return top == 1 || top + 1 == poly.lp.size() ? 0 : -1;
			} else if (orientation < 0) {
				

				

				int itRight = _lowerBound(poly.lp, 1, top, point);
				return Point.sgn(Point.ccw(poly.lp.get(itRight), point, poly.lp.get(itRight - 1)));
			} else {
				

				

				int itLeft = _upperBound(poly.lp, poly.lp.size() - 1, top, point);
				

				


				return Point.sgn(Point.ccw(itLeft == poly.lp.size() - 1 ? poly.lp.get(0) : poly.lp.get(itLeft + 1), point,
						poly.lp.get(itLeft)));
			}
		}

		public static int id26(final Polygon poly, final Function<Point, Point> direction) {
			int n = poly.lp.size();
			if (n == 0) throw new RuntimeException();


			int left = 0;
			int id7 = 0;

			final IntBinaryOperator vertexComp = (int i, int j) -> Point.sgn(Point.ccw(direction.apply(poly.lp.get(j)), poly.lp.get(j).opSub(poly.lp.get(i))));

			final IntPredicate isExtreme = (int i) ->
					vertexComp.applyAsInt(poly.next(i), i) >= 0 && vertexComp.applyAsInt(i, poly.prev(i)) < 0;


			id7 = vertexComp.applyAsInt(poly.next(0), 0);
			for (int right = isExtreme.test(0) ? 1 : n; left + 1 < right; ) {
				int middle = (left + right) / 2, id43;
				id43 = vertexComp.applyAsInt(poly.next(middle), middle);
				if (isExtreme.test(middle)) return middle;
				if (id7 != id43 ? id7 < id43
						: id7 == vertexComp.applyAsInt(left, middle)) right = middle;
				else {
					left = middle;
					id7 = id43;
				}
			}

			return left;
		}

		public static Pair<Integer, Integer> id20(final Point point, final Polygon poly) {
			final Function<Point, Point> f1 = (Point q) -> q.opSub(point);
			final Function<Point, Point> f2 = (Point q) -> point.opSub(q);
			return new Pair<>(Integer.valueOf(id26(poly, f1)), Integer.valueOf(id26(poly, f2)));
		}

		public static ArrayList<Polygon> id15(final Polygon poly) {
			final int T_X = 1;
			final int T_Y = 2;
			final int TSK = 3;

			final int id45 = 100010;
			final int _INFINITY = 1000000011;


			final int QSIZE = 8 * id45;
			final int TRSIZE = 4 * id45;

			final int TRUE = 1;
			final int FALSE = 0;
			final int FIRSTPT = 1;
			final int LASTPT = 2;

			final int S_L = 1;
			final int S_R = 2;

			final int ST_VALID = 1;
			final int ST_INVALID = 2;

			final int id37 = 1;
			final int id30 = 2;
			final int id0 = 3;
			final int id1 = 4;
			final int id16 = 5;
			final int id8 = 6;
			final int id3 = 7;
			final int id9 = -1;

			final int _TFU = 1;
			final int _TFD = 2;

			final int id32 = 1;
			final int id14 = 2;


			class p_t extends Point {
				public p_t() {
					super(0, 0);
				}

				public p_t(Point o) {
					super(o);
				}
			}




			class s_t {
				public p_t v0 = new p_t(), v1 = new p_t();
				public boolean ii;
				public int r0, r1;
				public int n;
				public int p;


			}

			class t_t {
				public int lseg, rseg;
				public p_t hi = new p_t(), lo = new p_t();
				public int u0, u1, sk, d0, d1, us, uside, state;

			}

			class n_t {
				public p_t y = new p_t();
				public int nt, sn, tn, p, l, r;
			}


			class mc_t {
				public int v, n, p, m;
			}


			class v_t {
				public p_t pt = new p_t();
				public int[] vn = new int[4];
				public int[] vp = new int[4];
				public int nf;
			}


			class id11 {
				int q_idx;
				int tr_idx;
				int choose_idx;
				int[] permute;
				n_t[] Q;
				t_t[] T;
				s_t[] se;
				mc_t[] mcn;
				v_t[] vert;
				int[] mon;
				int[] visited;
				int c_idx, o_idx, mon_idx;

				public id11() {
					choose_idx = 1;
					permute = new int[id45];
					Q = new n_t[QSIZE];
					for (int i = 0; i < Q.length; ++i) Q[i] = new n_t();

					T = new t_t[TRSIZE];
					for (int i = 0; i < T.length; ++i) T[i] = new t_t();

					se = new s_t[id45];
					for (int i = 0; i < se.length; ++i) se[i] = new s_t();

					c_idx = 0;
					o_idx = 0;
					mon_idx = 0;
					q_idx = 0;
					tr_idx = 0;
					mcn = new mc_t[TRSIZE];
					for (int i = 0; i < mcn.length; ++i) mcn[i] = new mc_t();

					vert = new v_t[id45];
					for (int i = 0; i < vert.length; ++i) vert[i] = new v_t();
					mon = new int[id45];
					visited = new int[TRSIZE];
				}


				long CROSS(p_t v0, p_t v1, p_t v2) {
					long ret = (((v1).x - (v0).x) * ((v2).y - (v0).y) -
							((v1).y - (v0).y) * ((v2).x - (v0).x));
					return ret;
				}

				boolean EQ(long s, long t) {
					return s == t;
				}


				int initialise(int n) {
					int i;
					for (i = 1; i <= n; i++)
						se[i].ii = false;
					id24(n);
					return 0;
				}

				int id24(int n) {
					choose_idx = 1;
					ArrayList<Integer> ar = new ArrayList<>();
					for (int i = 1; i <= n; ++i)
						ar.add(i);
					Collections.shuffle(ar, new Random());
					for (int i = 1; i <= n; ++i)
						permute[i] = ar.get(i - 1);
					return 0;
				}

				int choose_segment() {
					return permute[choose_idx++];
				}

				int nn() {
					if (q_idx < QSIZE)
						return q_idx++;
					else {

						return -1;
					}
				}


				int newtrap() {
					if (tr_idx < TRSIZE) {
						T[tr_idx].lseg = -1;
						T[tr_idx].rseg = -1;
						T[tr_idx].state = ST_VALID;
						return tr_idx++;
					} else {

						return -1;
					}
				}


				public void _cp(t_t dst, t_t src) {
					dst.lseg = src.lseg;
					dst.rseg = src.rseg;
					_cp(dst.hi, src.hi);
					_cp(dst.lo, src.lo);
					dst.u0 = src.u0;
					dst.u1 = src.u1;
					dst.d0 = src.d0;
					dst.d1 = src.d1;
					dst.sk = src.sk;
					dst.us = src.us;
					dst.uside = src.uside;
				}

				public void _cp(s_t dst, s_t src) {
					_cp(dst.v0, src.v0);
					_cp(dst.v1, src.v1);
					dst.ii = src.ii;
					dst.r0 = src.r0;
					dst.r1 = src.r1;
					dst.n = src.n;
					dst.p = src.p;
				}

				public void _cp(p_t dst, p_t src) {
					dst.x = src.x;
					dst.y = src.y;
				}

				int _max(p_t yval, p_t v0, p_t v1) {
					if (v0.y > v1.y) {

						_cp(yval, v0);
					} else if (EQ(v0.y, v1.y)) {
						if (v0.x > v1.x) {

							_cp(yval, v0);
						} else _cp(yval, v1);


					} else _cp(yval, v1);


					return 0;
				}


				int _min(p_t yval, p_t v0, p_t v1) {
					if (v0.y < v1.y)

						_cp(yval, v0);
					else if (EQ(v0.y, v1.y)) {
						if (v0.x < v1.x)

							_cp(yval, v0);
						else

							_cp(yval, v1);
					} else

						_cp(yval, v1);

					return 0;
				}

				boolean _gr(p_t v0, p_t v1) {
					if (v0.y > v1.y)
						return true;
					else if (v0.y < v1.y)
						return false;
					else
						return (v0.x > v1.x);
				}

				boolean _eq(p_t v0, p_t v1) {
					return (EQ(v0.y, v1.y) && EQ(v0.x, v1.x));
				}

				boolean _gre(p_t v0, p_t v1)

				{
					if (v0.y > v1.y)
						return true;
					else if (v0.y < v1.y)
						return false;
					else
						return (v0.x >= v1.x);
				}

				boolean _le(p_t v0, p_t v1) {
					if (v0.y < v1.y)
						return true;
					else if (v0.y > v1.y)
						return false;
					else
						return (v0.x < v1.x);
				}


				int id21(int segnum) {
					int i1, i2, i3, i4, i5, i6, i7, root;
					int t1, t2, t3, t4;
					s_t s = se[segnum];

					q_idx = tr_idx = 1;


					i1 = nn();
					Q[i1].nt = T_Y;
					_max(Q[i1].y, s.v0, s.v1); 
					root = i1;

					Q[i1].r = i2 = nn();
					Q[i2].nt = TSK;
					Q[i2].p = i1;

					Q[i1].l = i3 = nn();
					Q[i3].nt = T_Y;
					_min(Q[i3].y, s.v0, s.v1); 
					Q[i3].p = i1;

					Q[i3].l = i4 = nn();
					Q[i4].nt = TSK;
					Q[i4].p = i3;

					Q[i3].r = i5 = nn();
					Q[i5].nt = T_X;
					Q[i5].sn = segnum;
					Q[i5].p = i3;

					Q[i5].l = i6 = nn();
					Q[i6].nt = TSK;
					Q[i6].p = i5;

					Q[i5].r = i7 = nn();
					Q[i7].nt = TSK;
					Q[i7].p = i5;

					t1 = newtrap(); 
					t2 = newtrap(); 
					t3 = newtrap(); 
					t4 = newtrap(); 
					_cp(T[t4].lo, Q[i1].y);
					_cp(T[t2].hi, T[t4].lo);
					_cp(T[t1].hi, T[t2].hi);

					_cp(T[t3].hi, Q[i3].y);
					_cp(T[t2].lo, T[t3].hi);
					_cp(T[t1].lo, T[t2].lo);

					T[t4].hi.y = (_INFINITY);
					T[t4].hi.x = (_INFINITY);
					T[t3].lo.y = -(_INFINITY);
					T[t3].lo.x = -(_INFINITY);
					T[t1].rseg = T[t2].lseg = segnum;
					T[t1].u0 = T[t2].u0 = t4;
					T[t1].d0 = T[t2].d0 = t3;
					T[t4].d0 = T[t3].u0 = t1;
					T[t4].d1 = T[t3].u1 = t2;

					T[t1].sk = i6;
					T[t2].sk = i7;
					T[t3].sk = i4;
					T[t4].sk = i2;

					T[t1].state = T[t2].state = ST_VALID;
					T[t3].state = T[t4].state = ST_VALID;

					Q[i2].tn = t4;
					Q[i4].tn = t3;
					Q[i6].tn = t1;
					Q[i7].tn = t2;

					s.ii = true;
					return root;
				}


				boolean id13(int segnum, p_t v) {
					s_t s = se[segnum];
					long area;

					if (_gr(s.v1, s.v0))  {
						if (EQ(s.v1.y, v.y)) {
							if (v.x < s.v1.x)
								area = 1;
							else
								area = -1;
						} else if (EQ(s.v0.y, v.y)) {
							if (v.x < s.v0.x)
								area = 1;
							else
								area = -1;
						} else
							area = CROSS(s.v0, s.v1, v);
					} else  {
						if (EQ(s.v1.y, v.y)) {
							if (v.x < s.v1.x)
								area = 1;
							else
								area = -1;
						} else if (EQ(s.v0.y, v.y)) {
							if (v.x < s.v0.x)
								area = 1;
							else
								area = -1;
						} else
							area = CROSS(s.v1, s.v0, v);
					}

					if (area > 0)
						return true;
					else
						return false;
				}


				boolean inserted(int segnum, int whichpt) {
					if (whichpt == FIRSTPT)
						return se[se[segnum].p].ii;
					else
						return se[se[segnum].n].ii;
				}


				int lep(p_t v, p_t vo, int r) {

					n_t rptr = Q[r];

					switch (rptr.nt) {
						case TSK:
							return rptr.tn;

						case T_Y:
							if (_gr(v, rptr.y))
								return lep(v, vo, rptr.r);
							else if (_eq(v, rptr.y)) {
								if (_gr(vo, rptr.y))
									return lep(v, vo, rptr.r);
								else
									return lep(v, vo, rptr.l);
							} else
								return lep(v, vo, rptr.l);

						case T_X:
							if (_eq(v, se[rptr.sn].v0)
									|| _eq(v, se[rptr.sn].v1)) {
								if (EQ(v.y, vo.y)) {
									if (vo.x < v.x)
										return lep(v, vo, rptr.l);
									else
										return lep(v, vo, rptr.r);
								} else if (id13(rptr.sn, vo))
									return lep(v, vo, rptr.l);
								else
									return lep(v, vo, rptr.r);
							} else if (id13(rptr.sn, v))
								return lep(v, vo, rptr.l);
							else
								return lep(v, vo, rptr.r);

						default:

							throw new RuntimeException();

					}
				}

				int id34(int segnum, int tfirst, int tlast, int side) {
					int t, tnext;
					boolean cond;
					int ptnext;


					t = tfirst;
					while ((t > 0) && _gre(T[t].lo, T[tlast].lo)) {

						if (side == S_L) {
							cond = ((((tnext = T[t].d0) > 0) && (T[tnext].rseg == segnum))
									|| (((tnext = T[t].d1) > 0)
									&& (T[tnext].rseg == segnum)));
						} else {
							cond = ((((tnext = T[t].d0) > 0) && (T[tnext].lseg == segnum))
									|| (((tnext = T[t].d1) > 0)
									&& (T[tnext].lseg == segnum)));

						}


						if (cond) {
							if ((T[t].lseg == T[tnext].lseg)
									&& (T[t].rseg == T[tnext].rseg)) {


								ptnext = Q[T[tnext].sk].p;

								if (Q[ptnext].l == T[tnext].sk)
									Q[ptnext].l = T[t].sk;
								else
									Q[ptnext].r = T[t].sk; 

                    

								if ((T[t].d0 = T[tnext].d0) > 0)
									if (T[T[t].d0].u0 == tnext)
										T[T[t].d0].u0 = t;
									else if (T[T[t].d0].u1 == tnext)
										T[T[t].d0].u1 = t;

								if ((T[t].d1 = T[tnext].d1) > 0)
									if (T[T[t].d1].u0 == tnext)
										T[T[t].d1].u0 = t;
									else if (T[T[t].d1].u1 == tnext)
										T[T[t].d1].u1 = t;

								_cp(T[t].lo, T[tnext].lo);
								T[tnext].state = ST_INVALID;

							} else

								t = tnext;
						} else

							t = tnext;

					}

					return 0;
				}

				int add_segment(int segnum) {


					s_t s = new s_t();
					s_t so = se[segnum];
					int tu, tl, sk, tfirst, tlast, tnext;
					int id47 = 0, id41 = 0, id29 = 0, id27 = 0;
					int i1, i2, tt, t1, t2, tn;
					p_t tpt;
					int id46 = 0, tribot = 0;
					boolean id48 = false;
					int id25;


					_cp(s, se[segnum]);
					if (_gr(s.v1, s.v0))  {
						int tmp;
						tpt = s.v0;
						s.v0 = s.v1;
						s.v1 = tpt;
						tmp = s.r0;
						s.r0 = s.r1;
						s.r1 = tmp;
						id48 = true;
					}

					if ((id48) ?
							!inserted(segnum, LASTPT) : !inserted(segnum, FIRSTPT))  {
						int tmp_d;

						tu = lep(s.v0, s.v1, s.r0);
						tl = newtrap(); 
						T[tl].state = ST_VALID;
						_cp(T[tl], T[tu]);
						T[tu].lo.y = T[tl].hi.y = s.v0.y;
						T[tu].lo.x = T[tl].hi.x = s.v0.x;
						T[tu].d0 = tl;
						T[tu].d1 = 0;
						T[tl].u0 = tu;
						T[tl].u1 = 0;

						if (((tmp_d = T[tl].d0) > 0) && (T[tmp_d].u0 == tu))
							T[tmp_d].u0 = tl;
						if (((tmp_d = T[tl].d0) > 0) && (T[tmp_d].u1 == tu))
							T[tmp_d].u1 = tl;

						if (((tmp_d = T[tl].d1) > 0) && (T[tmp_d].u0 == tu))
							T[tmp_d].u0 = tl;
						if (((tmp_d = T[tl].d1) > 0) && (T[tmp_d].u1 == tu))
							T[tmp_d].u1 = tl;


						i1 = nn();
						i2 = nn();
						sk = T[tu].sk;

						Q[sk].nt = T_Y;
						_cp(Q[sk].y, s.v0);
						Q[sk].sn = segnum; 
						Q[sk].l = i2;
						Q[sk].r = i1;

						Q[i1].nt = TSK;
						Q[i1].tn = tu;
						Q[i1].p = sk;

						Q[i2].nt = TSK;
						Q[i2].tn = tl;
						Q[i2].p = sk;

						T[tu].sk = i1;
						T[tl].sk = i2;
						tfirst = tl;
					} else  { 
						tfirst = lep(s.v0, s.v1, s.r0);
						id46 = 1;
					}

					if ((id48) ?
							!inserted(segnum, FIRSTPT) : !inserted(segnum, LASTPT))  {
						int tmp_d;

						tu = lep(s.v1, s.v0, s.r1);

						tl = newtrap(); 
						T[tl].state = ST_VALID;
						_cp(T[tl], T[tu]);
						T[tu].lo.y = T[tl].hi.y = s.v1.y;
						T[tu].lo.x = T[tl].hi.x = s.v1.x;
						T[tu].d0 = tl;
						T[tu].d1 = 0;
						T[tl].u0 = tu;
						T[tl].u1 = 0;

						if (((tmp_d = T[tl].d0) > 0) && (T[tmp_d].u0 == tu))
							T[tmp_d].u0 = tl;
						if (((tmp_d = T[tl].d0) > 0) && (T[tmp_d].u1 == tu))
							T[tmp_d].u1 = tl;

						if (((tmp_d = T[tl].d1) > 0) && (T[tmp_d].u0 == tu))
							T[tmp_d].u0 = tl;
						if (((tmp_d = T[tl].d1) > 0) && (T[tmp_d].u1 == tu))
							T[tmp_d].u1 = tl;


						i1 = nn();
						i2 = nn();
						sk = T[tu].sk;

						Q[sk].nt = T_Y;
						_cp(Q[sk].y, s.v1);
						Q[sk].sn = segnum;
						Q[sk].l = i2;
						Q[sk].r = i1;

						Q[i1].nt = TSK;
						Q[i1].tn = tu;
						Q[i1].p = sk;

						Q[i2].nt = TSK;
						Q[i2].tn = tl;
						Q[i2].p = sk;

						T[tu].sk = i1;
						T[tl].sk = i2;
						tlast = tu;
					} else {
						tlast = lep(s.v1, s.v0, s.r1);
						tribot = 1;
					}


					tt = tfirst;

					while ((tt > 0) && _gre(T[tt].lo, T[tlast].lo)) {

						int id18, id5;
						sk = T[tt].sk;
						i1 = nn();
						i2 = nn();

						Q[sk].nt = T_X;
						Q[sk].sn = segnum;
						Q[sk].l = i1;
						Q[sk].r = i2;

						Q[i1].nt = TSK;
						Q[i1].tn = tt;
						Q[i1].p = sk;

						Q[i2].nt = TSK;
						Q[i2].tn = tn = newtrap();
						T[tn].state = ST_VALID;
						Q[i2].p = sk;

						if (tt == tfirst)
							id47 = tn;
						if (_eq(T[tt].lo, T[tlast].lo))
							id41 = tn;

						_cp(T[tn], T[tt]);
						T[tt].sk = i1;
						T[tn].sk = i2;
						id18 = tt;
						id5 = tn;

						if ((T[tt].d0 <= 0) && (T[tt].d1 <= 0)) {
							break;
						} else if ((T[tt].d0 > 0) && (T[tt].d1 <= 0)) {
							if ((T[tt].u0 > 0) && (T[tt].u1 > 0)) {
								if (T[tt].us > 0) {
									if (T[tt].uside == S_L) {
										T[tn].u0 = T[tt].u1;
										T[tt].u1 = -1;
										T[tn].u1 = T[tt].us;

										T[T[tt].u0].d0 = tt;
										T[T[tn].u0].d0 = tn;
										T[T[tn].u1].d0 = tn;
									} else {
										T[tn].u1 = -1;
										T[tn].u0 = T[tt].u1;
										T[tt].u1 = T[tt].u0;
										T[tt].u0 = T[tt].us;

										T[T[tt].u0].d0 = tt;
										T[T[tt].u1].d0 = tt;
										T[T[tn].u0].d0 = tn;
									}

									T[tt].us = T[tn].us = 0;
								} else {
									T[tn].u0 = T[tt].u1;
									T[tt].u1 = T[tn].u1 = -1;
									T[T[tn].u0].d0 = tn;
								}
							} else {
								int tmp_u = T[tt].u0;
								int td0, td1;
								if (((td0 = T[tmp_u].d0) > 0)
										&& ((td1 = T[tmp_u].d1) > 0)) {
									if ((T[td0].rseg > 0)
											&& !id13(T[td0].rseg, s.v1)) {
										T[tt].u0 = T[tt].u1 = T[tn].u1 = -1;
										T[T[tn].u0].d1 = tn;
									} else {
										T[tn].u0 = T[tn].u1 = T[tt].u1 = -1;
										T[T[tt].u0].d0 = tt;
									}
								} else {
									T[T[tt].u0].d0 = tt;
									T[T[tt].u0].d1 = tn;
								}
							}

							if (EQ(T[tt].lo.y, T[tlast].lo.y)
									&& EQ(T[tt].lo.x, T[tlast].lo.x) && tribot != 0) {

								if (id48)
									id25 = se[segnum].p;
								else
									id25 = se[segnum].n;
								if ((id25 > 0) && id13(id25, s.v0)) {
									T[T[tt].d0].u0 = tt;
									T[tn].d0 = T[tn].d1 = -1;
								} else {

									T[T[tn].d0].u1 = tn;
									T[tt].d0 = T[tt].d1 = -1;
								}
							} else {
								if ((T[T[tt].d0].u0 > 0) && (T[T[tt].d0].u1 > 0)) {
									if (T[T[tt].d0].u0 == tt)  {
										T[T[tt].d0].us = T[T[tt].d0].u1;
										T[T[tt].d0].uside = S_L;
									} else {
										T[T[tt].d0].us = T[T[tt].d0].u0;
										T[T[tt].d0].uside = S_R;
									}
								}
								T[T[tt].d0].u0 = tt;
								T[T[tt].d0].u1 = tn;
							}

							tt = T[tt].d0;
						} else if ((T[tt].d0 <= 0) && (T[tt].d1 > 0)) {
							if ((T[tt].u0 > 0) && (T[tt].u1 > 0)) {
								if (T[tt].us > 0) {
									if (T[tt].uside == S_L) {
										T[tn].u0 = T[tt].u1;
										T[tt].u1 = -1;
										T[tn].u1 = T[tt].us;

										T[T[tt].u0].d0 = tt;
										T[T[tn].u0].d0 = tn;
										T[T[tn].u1].d0 = tn;
									} else {
										T[tn].u1 = -1;
										T[tn].u0 = T[tt].u1;
										T[tt].u1 = T[tt].u0;
										T[tt].u0 = T[tt].us;

										T[T[tt].u0].d0 = tt;
										T[T[tt].u1].d0 = tt;
										T[T[tn].u0].d0 = tn;
									}

									T[tt].us = T[tn].us = 0;
								} else {
									T[tn].u0 = T[tt].u1;
									T[tt].u1 = T[tn].u1 = -1;
									T[T[tn].u0].d0 = tn;
								}
							} else {
								int tmp_u = T[tt].u0;
								int td0, td1;
								if (((td0 = T[tmp_u].d0) > 0)
										&& ((td1 = T[tmp_u].d1) > 0)) {
									if ((T[td0].rseg > 0)
											&& !id13(T[td0].rseg, s.v1)) {
										T[tt].u0 = T[tt].u1 = T[tn].u1 = -1;
										T[T[tn].u0].d1 = tn;
									} else {
										T[tn].u0 = T[tn].u1 = T[tt].u1 = -1;
										T[T[tt].u0].d0 = tt;
									}
								} else {
									T[T[tt].u0].d0 = tt;
									T[T[tt].u0].d1 = tn;
								}
							}

							if (EQ(T[tt].lo.y, T[tlast].lo.y)
									&& EQ(T[tt].lo.x, T[tlast].lo.x) && tribot != 0) { 
								int tmpseg = 0;

								if (id48)
									id25 = se[segnum].p;
								else
									id25 = se[segnum].n;

								if ((tmpseg > 0) && id13(tmpseg, s.v0)) {

									T[T[tt].d1].u0 = tt;
									T[tn].d0 = T[tn].d1 = -1;
								} else {
						
									T[T[tn].d1].u1 = tn;
									T[tt].d0 = T[tt].d1 = -1;
								}
							} else {
								if ((T[T[tt].d1].u0 > 0) && (T[T[tt].d1].u1 > 0)) {
									if (T[T[tt].d1].u0 == tt)  {
										T[T[tt].d1].us = T[T[tt].d1].u1;
										T[T[tt].d1].uside = S_L;
									} else {
										T[T[tt].d1].us = T[T[tt].d1].u0;
										T[T[tt].d1].uside = S_R;
									}
								}
								T[T[tt].d1].u0 = tt;
								T[T[tt].d1].u1 = tn;
							}

							tt = T[tt].d1;
						} else {

							long y0, yt;

							int id4;

							id4 = FALSE;
							if (EQ(T[tt].lo.y, s.v0.y)) {
								if (T[tt].lo.x > s.v0.x)
									id4 = TRUE;

							} else {
								y0 = T[tt].lo.y;
								yt = (y0 - s.v0.y);
								long tm2 = (s.v1.y - s.v0.y);
								long id6;
								if (tm2 < 0) {
									yt = -yt;
									tm2 = -tm2;
								}
								id6 = s.v0.x * tm2 + yt * (s.v1.x - s.v0.x);

								if (id6 < T[tt].lo.x * tm2)
									id4 = TRUE;

							}

							if ((T[tt].u0 > 0) && (T[tt].u1 > 0)) {
								if (T[tt].us > 0) {
									if (T[tt].uside == S_L) {
										T[tn].u0 = T[tt].u1;
										T[tt].u1 = -1;
										T[tn].u1 = T[tt].us;

										T[T[tt].u0].d0 = tt;
										T[T[tn].u0].d0 = tn;
										T[T[tn].u1].d0 = tn;
									} else {
										T[tn].u1 = -1;
										T[tn].u0 = T[tt].u1;
										T[tt].u1 = T[tt].u0;
										T[tt].u0 = T[tt].us;

										T[T[tt].u0].d0 = tt;
										T[T[tt].u1].d0 = tt;
										T[T[tn].u0].d0 = tn;
									}

									T[tt].us = T[tn].us = 0;
								} else {
									T[tn].u0 = T[tt].u1;
									T[tn].u1 = -1;
									T[tt].u1 = -1;
									T[T[tn].u0].d0 = tn;
								}
							} else {
								int tmp_u = T[tt].u0;
								int td0;
								if (((td0 = T[tmp_u].d0) > 0)
										&& ((T[tmp_u].d1) > 0)) { 
									if ((T[td0].rseg > 0)
											&& !id13(T[td0].rseg, s.v1)) {
										T[tt].u0 = T[tt].u1 = T[tn].u1 = -1;
										T[T[tn].u0].d1 = tn;
									} else {
										T[tn].u0 = T[tn].u1 = T[tt].u1 = -1;
										T[T[tt].u0].d0 = tt;
									}
								} else {
									T[T[tt].u0].d0 = tt;
									T[T[tt].u0].d1 = tn;
								}
							}

							if (EQ(T[tt].lo.y, T[tlast].lo.y)
									&& EQ(T[tt].lo.x, T[tlast].lo.x) && tribot != 0) {
								T[T[tt].d0].u0 = tt;
								T[T[tt].d0].u1 = -1;
								T[T[tt].d1].u0 = tn;
								T[T[tt].d1].u1 = -1;

								T[tn].d0 = T[tt].d1;
								T[tt].d1 = T[tn].d1 = -1;

								tnext = T[tt].d1;
							} else if (id4 != 0) {
								T[T[tt].d0].u0 = tt;
								T[T[tt].d0].u1 = tn;
								T[T[tt].d1].u0 = tn;
								T[T[tt].d1].u1 = -1;

								T[tt].d1 = -1;

								tnext = T[tt].d0;
							} else  {
								T[T[tt].d0].u0 = tt;
								T[T[tt].d0].u1 = -1;
								T[T[tt].d1].u0 = tt;
								T[T[tt].d1].u1 = tn;
								T[tn].d0 = T[tt].d1;
								T[tn].d1 = -1;

								tnext = T[tt].d1;
							}

							tt = tnext;
						}

						T[id18].rseg = T[id5].lseg = segnum;
					} 

					id29 = tfirst;
					id27 = tlast;
					id34(segnum, id29, id27, S_L);
					id34(segnum, id47, id41, S_R);

					se[segnum].ii = true;

					return 0;
				}


				int id19(int segnum) {
					s_t s = se[segnum];

					if (s.ii)
						return 0;

					s.r0 = lep(s.v0, s.v1, s.r0);
					s.r0 = T[s.r0].sk;

					s.r1 = lep(s.v1, s.v0, s.r1);
					s.r1 = T[s.r1].sk;
					return 0;
				}

				int id42(int nseg) {
					int i;
					int root, h;
					root = id21(choose_segment());
					for (i = 1; i <= nseg; i++)
						se[i].r0 = se[i].r1 = root;

					for (h = 1; h <= id2(nseg); h++) {
						for (i = math_N(nseg, h - 1) + 1; i <= math_N(nseg, h); i++)
							add_segment(choose_segment());
						for (i = 1; i <= nseg; i++)
							id19(i);
					}

					for (i = math_N(nseg, id2(nseg)) + 1; i <= nseg; i++)
						add_segment(choose_segment());

					return 0;
				}

				int read_segments(final Polygon poly) {
					int ccount;
					int i;
					int id10, npoints, first, last;
					id10 = 1;
					ccount = 0;
					i = 1;
					while (ccount < id10) {
						int j;

						npoints = poly.lp.size();
						first = i;
						last = first + npoints - 1;
						for (j = 0; j < npoints; j++, i++) {
							se[i].v0.x = poly.lp.get(j).x;
							se[i].v0.y = poly.lp.get(j).y;
							if (i == last) {
								se[i].n = first;
								se[i].p = i - 1;
								_cp(se[i - 1].v1, se[i].v0);
							} else if (i == first) {
								se[i].n = i + 1;
								se[i].p = last;
								_cp(se[last].v1, se[i].v0);
							} else {
								se[i].p = i - 1;
								se[i].n = i + 1;
								_cp(se[i - 1].v1, se[i].v0);
							}

							se[i].ii = false;
						}
						ccount++;
					}
					return i - 1;
				}

				public double log2(double a) {
					return Math.log(a) / Math.log(2);
				}

				int id2(int n) {
					int i;
					double v;
					for (i = 0, v = (double) n; v >= 1; i++)
						v = log2(v);

					return (i - 1);
				}

				int math_N(int n, int h) {
					int i;
					double v;
					for (i = 0, v = (int) n; i < h; i++)
						v = log2(v);

					return (int) Math.ceil((double) 1.0 * n / v);
				}

				boolean inside_polygon(t_t t) {
					int rseg = t.rseg;

					if (t.state == ST_INVALID)
						return false;

					if ((t.lseg <= 0) || (t.rseg <= 0))
						return false;

					if (((t.u0 <= 0) && (t.u1 <= 0)) || ((t.d0 <= 0) && (t.d1 <= 0))) 
						return (_gr(se[rseg].v1, se[rseg].v0));

					return false;
				}

				int newmon() {
					return ++mon_idx;
				}


				int id31() {
					return ++c_idx;
				}

				boolean incone(Point a, Point a0, Point a1, Point b) {

					if (Point.leftOn(a, a1, a0)) {
						return Point.left(a, b, a0) && Point.left(b, a, a1);
					}

					return !(Point.leftOn(a, b, a1) && Point.leftOn(b, a, a0));
				}

				Pair<Integer, Integer> id28(int v0, int v1) {
					v_t vp0, vp1, va0, va1;
					int i;
					int tp = -1, tq = -1;
					vp0 = vert[v0];
					vp1 = vert[v1];

					for (i = 0; i < 4; ++i) {
						if (vp0.vp[i] <= 0) continue;
						mc_t mc = mcn[vp0.vp[i]];
						va0 = vert[mcn[mc.p].v];
						va1 = vert[mcn[mc.n].v];
						if (incone(vp0.pt, va0.pt, va1.pt, vp1.pt)) {
							tp = i;
							break;
						}
					}

					for (i = 0; i < 4; ++i) {
						if (vp1.vp[i] <= 0) continue;
						mc_t mc = mcn[vp1.vp[i]];
						va0 = vert[mcn[mc.p].v];
						va1 = vert[mcn[mc.n].v];
						if (incone(vp1.pt, va0.pt, va1.pt, vp0.pt)) {
							tq = i;
							break;
						}
					}

					if (tp == -1 || tq == -1) {
						throw new RuntimeException();
					}
					return new Pair<>(tp, tq);

				}


				int mkmo(int mcur, int v0, int v1) {
					int p, q, ip, iq;
					int mnew = newmon();
					int i, j, nf0, nf1;
					v_t vp0, vp1;

					vp0 = vert[v0];
					vp1 = vert[v1];

					Pair<Integer, Integer> ret = id28(v0, v1);
					ip = ret.first;
					iq = ret.second;


					p = vp0.vp[ip];
					q = vp1.vp[iq];


					i = id31();
					j = id31();

					mcn[i].v = v0;
					mcn[j].v = v1;

					mcn[i].n = mcn[p].n;
					mcn[mcn[p].n].p = i;
					mcn[i].p = j;
					mcn[j].n = i;
					mcn[j].p = mcn[q].p;
					mcn[mcn[q].p].n = j;

					mcn[p].n = q;
					mcn[q].p = p;

					nf0 = vp0.nf;
					nf1 = vp1.nf;

					vp0.vn[ip] = v1;

					vp0.vp[nf0] = i;
					vp0.vn[nf0] = mcn[mcn[i].n].v;
					vp1.vp[nf1] = j;
					vp1.vn[nf1] = v0;

					vp0.nf++;
					vp1.nf++;


					mon[mcur] = p;
					mon[mnew] = i;
					return mnew;
				}


				int id33(int n) {
					int i = 0;
					int tr_start = 0;
					Arrays.fill(visited, 0);
					Arrays.fill(mon, 0);


					for (i = 0; i < TRSIZE; i++)
						if (inside_polygon(T[i]))
							break;
					tr_start = i;

					for (i = 1; i <= n; i++) {
						mcn[i].p = se[i].p;
						mcn[i].n = se[i].n;
						mcn[i].v = i;
						_cp(vert[i].pt, se[i].v0);
						vert[i].vn[0] = se[i].n;
						vert[i].vp[0] = i;
						vert[i].nf = 1;
					}

					c_idx = n;
					mon_idx = 0;
					mon[0] = 1;
					if (T[tr_start].u0 > 0)
						trp(0, tr_start, T[tr_start].u0, _TFU);
					else if (T[tr_start].d0 > 0)
						trp(0, tr_start, T[tr_start].d0, _TFD);
					return newmon();
				}

				int trp(int mr, int tnu, int from, int dir) {
					if (tnu <= 0)
						return 0;

					t_t t = T[tnu];
					int mw;
					int v0, v1;
					int retval = 0;


					if ((tnu <= 0) || visited[tnu] != 0)
						return 0;

					visited[tnu] = TRUE;


					if ((t.u0 <= 0) && (t.u1 <= 0)) {
						if ((t.d0 > 0) && (t.d1 > 0))  {
							v0 = T[t.d1].lseg;
							v1 = t.lseg;
							if (from == t.d1) {

								mw = mkmo(mr, v1, v0);
								trp(mr, t.d1, tnu, _TFU);
								trp(mw, t.d0, tnu, _TFU);
							} else {
								mw = mkmo(mr, v0, v1);
								trp(mr, t.d0, tnu, _TFU);
								trp(mw, t.d1, tnu, _TFU);
							}
						} else {
							retval = id9; 
							trp(mr, t.u0, tnu, _TFD);
							trp(mr, t.u1, tnu, _TFD);
							trp(mr, t.d0, tnu, _TFU);
							trp(mr, t.d1, tnu, _TFU);
						}
					} else if ((t.d0 <= 0) && (t.d1 <= 0)) {
						if ((t.u0 > 0) && (t.u1 > 0))  {
							v0 = t.rseg;
							v1 = T[t.u0].rseg;
							if (from == t.u1) {

								mw = mkmo(mr, v1, v0);
								trp(mr, t.u1, tnu, _TFD);
								trp(mw, t.u0, tnu, _TFD);
							} else {
								mw = mkmo(mr, v0, v1);
								trp(mr, t.u0, tnu, _TFD);
								trp(mw, t.u1, tnu, _TFD);
							}
						} else {
							retval = id9; 
							trp(mr, t.u0, tnu, _TFD);
							trp(mr, t.u1, tnu, _TFD);
							trp(mr, t.d0, tnu, _TFU);
							trp(mr, t.d1, tnu, _TFU);
						}
					} else if ((t.u0 > 0) && (t.u1 > 0)) {
						if ((t.d0 > 0) && (t.d1 > 0))  {
							v0 = T[t.d1].lseg;
							v1 = T[t.u0].rseg;
							retval = id0;
							if (((dir == _TFD) && (t.d1 == from))
									|| ((dir == _TFU) && (t.u1 == from))) {

								mw = mkmo(mr, v1, v0);
								trp(mr, t.u1, tnu, _TFD);
								trp(mr, t.d1, tnu, _TFU);
								trp(mw, t.u0, tnu, _TFD);
								trp(mw, t.d0, tnu, _TFU);
							} else {
								mw = mkmo(mr, v0, v1);
								trp(mr, t.u0, tnu, _TFD);
								trp(mr, t.d0, tnu, _TFU);
								trp(mw, t.u1, tnu, _TFD);
								trp(mw, t.d1, tnu, _TFU);
							}
						} else  {
							if (_eq(t.lo, se[t.lseg].v1)) {
								v0 = T[t.u0].rseg;
								v1 = se[t.lseg].n;

								retval = id1;
								if ((dir == _TFU) && (t.u0 == from)) {

									mw = mkmo(mr, v1, v0);
									trp(mr, t.u0, tnu, _TFD);
									trp(mw, t.d0, tnu, _TFU);
									trp(mw, t.u1, tnu, _TFD);
									trp(mw, t.d1, tnu, _TFU);
								} else {
									mw = mkmo(mr, v0, v1);
									trp(mr, t.u1, tnu, _TFD);
									trp(mr, t.d0, tnu, _TFU);
									trp(mr, t.d1, tnu, _TFU);
									trp(mw, t.u0, tnu, _TFD);
								}
							} else {
								v0 = t.rseg;
								v1 = T[t.u0].rseg;
								retval = id16;
								if ((dir == _TFU) && (t.u1 == from)) {

									mw = mkmo(mr, v1, v0);
									trp(mr, t.u1, tnu, _TFD);
									trp(mw, t.d1, tnu, _TFU);
									trp(mw, t.d0, tnu, _TFU);
									trp(mw, t.u0, tnu, _TFD);
								} else {
									mw = mkmo(mr, v0, v1);
									trp(mr, t.u0, tnu, _TFD);
									trp(mr, t.d0, tnu, _TFU);
									trp(mr, t.d1, tnu, _TFU);
									trp(mw, t.u1, tnu, _TFD);
								}
							}
						}
					} else if ((t.u0 > 0) || (t.u1 > 0))  {
						if ((t.d0 > 0) && (t.d1 > 0))  {
							if (_eq(t.hi, se[t.lseg].v0)) {
								v0 = T[t.d1].lseg;
								v1 = t.lseg;
								retval = id8;
								if (!((dir == _TFD) && (t.d0 == from))) {

									mw = mkmo(mr, v1, v0);
									trp(mr, t.u1, tnu, _TFD);
									trp(mr, t.d1, tnu, _TFU);
									trp(mr, t.u0, tnu, _TFD);
									trp(mw, t.d0, tnu, _TFU);
								} else {
									mw = mkmo(mr, v0, v1);
									trp(mr, t.d0, tnu, _TFU);
									trp(mw, t.u0, tnu, _TFD);
									trp(mw, t.u1, tnu, _TFD);
									trp(mw, t.d1, tnu, _TFU);
								}
							} else {
								v0 = T[t.d1].lseg;
								v1 = se[t.rseg].n;

								retval = id3;
								if ((dir == _TFD) && (t.d1 == from)) {

									mw = mkmo(mr, v1, v0);
									trp(mr, t.d1, tnu, _TFU);
									trp(mw, t.u1, tnu, _TFD);
									trp(mw, t.u0, tnu, _TFD);
									trp(mw, t.d0, tnu, _TFU);
								} else {
									mw = mkmo(mr, v0, v1);
									trp(mr, t.u0, tnu, _TFD);
									trp(mr, t.d0, tnu, _TFU);
									trp(mr, t.u1, tnu, _TFD);
									trp(mw, t.d1, tnu, _TFU);
								}
							}
						} else  {
							if (_eq(t.hi, se[t.lseg].v0)
									&& _eq(t.lo, se[t.rseg].v0)) {
								v0 = t.rseg;
								v1 = t.lseg;
								retval = id30;
								if (dir == _TFU) {

									mw = mkmo(mr, v1, v0);
									trp(mr, t.u0, tnu, _TFD);
									trp(mr, t.u1, tnu, _TFD);
									trp(mw, t.d1, tnu, _TFU);
									trp(mw, t.d0, tnu, _TFU);
								} else {
									mw = mkmo(mr, v0, v1);
									trp(mr, t.d1, tnu, _TFU);
									trp(mr, t.d0, tnu, _TFU);
									trp(mw, t.u0, tnu, _TFD);
									trp(mw, t.u1, tnu, _TFD);
								}
							} else if (_eq(t.hi, se[t.rseg].v1)
									&& _eq(t.lo, se[t.lseg].v1)) {
								v0 = se[t.rseg].n;
								v1 = se[t.lseg].n;

								retval = id37;
								if (dir == _TFU) {

									mw = mkmo(mr, v1, v0);
									trp(mr, t.u0, tnu, _TFD);
									trp(mr, t.u1, tnu, _TFD);
									trp(mw, t.d1, tnu, _TFU);
									trp(mw, t.d0, tnu, _TFU);
								} else {
									mw = mkmo(mr, v0, v1);
									trp(mr, t.d1, tnu, _TFU);
									trp(mr, t.d0, tnu, _TFU);
									trp(mw, t.u0, tnu, _TFD);
									trp(mw, t.u1, tnu, _TFD);
								}
							} else  {
								retval = id9;
								trp(mr, t.u0, tnu, _TFD);
								trp(mr, t.d0, tnu, _TFU);
								trp(mr, t.u1, tnu, _TFD);
								trp(mr, t.d1, tnu, _TFU);
							}
						}
					}

					return retval;
				}

				int id38(int nvert, int id17, int op[][]) {
					int i;
					p_t ymax, ymin;
					int p, vfirst, posmax, posmin, v;
					int vcount, processed;

					o_idx = 0;
					for (i = 0; i < id17; i++) {
						vcount = 1;
						processed = FALSE;
						vfirst = mcn[mon[i]].v;
						ymax = ymin = vert[vfirst].pt;
						posmax = posmin = mon[i];
						mcn[mon[i]].m = TRUE;
						p = mcn[mon[i]].n;
						while ((v = mcn[p].v) != vfirst) {
							if (mcn[p].m != 0) {
								processed = TRUE;
								break; 
							} else
								mcn[p].m = TRUE;

							if (_gr(vert[v].pt, ymax)) {
								ymax = vert[v].pt;
								posmax = p;
							}
							if (_le(vert[v].pt, ymin)) {
								ymin = vert[v].pt;
								posmin = p;
							}
							p = mcn[p].n;
							vcount++;
						}

						if (processed != 0) 
							continue;

						if (vcount == 3)  {
							op[o_idx][0] = mcn[p].v;
							op[o_idx][1] = mcn[mcn[p].n].v;
							op[o_idx][2] = mcn[mcn[p].p].v;
							o_idx++;
						} else  {
							v = mcn[mcn[posmax].n].v;
							if (_eq(vert[v].pt, ymin)) { 
								id44(nvert, posmax, id32, op);
							} else
								id44(nvert, posmax, id14, op);
						}
					}

					return o_idx;
				}


				int id44(int nvert, int posmax, int side,
											   int op[][]) {
					int v;
					int[] rc = new int[id45];
					int ri = 0; 
					int endv, tmp, vpos;

					if (side == id14)  {
						rc[0] = mcn[posmax].v;
						tmp = mcn[posmax].n;
						rc[1] = mcn[tmp].v;
						ri = 1;

						vpos = mcn[tmp].n;
						v = mcn[vpos].v;

						if ((endv = mcn[mcn[posmax].p].v) == 0)
							endv = nvert;
					} else  {
						tmp = mcn[posmax].n;
						rc[0] = mcn[tmp].v;
						tmp = mcn[tmp].n;
						rc[1] = mcn[tmp].v;
						ri = 1;

						vpos = mcn[tmp].n;
						v = mcn[vpos].v;

						endv = mcn[posmax].v;
					}

					while ((v != endv) || (ri > 1)) {
						if (ri > 0) {
							if (CROSS(vert[v].pt, vert[rc[ri - 1]].pt,
									vert[rc[ri]].pt) > 0) {
								op[o_idx][0] = rc[ri - 1];
								op[o_idx][1] = rc[ri];
								op[o_idx][2] = v;
								o_idx++;
								ri--;
							} else {
								ri++;
								rc[ri] = v;
								vpos = mcn[vpos].n;
								v = mcn[vpos].v;
							}
						} else {
							rc[++ri] = v;
							vpos = mcn[vpos].n;
							v = mcn[vpos].v;
						}
					} 


					op[o_idx][0] = rc[ri - 1];
					op[o_idx][1] = rc[ri];
					op[o_idx][2] = v;
					o_idx++;
					ri--;

					return 0;
				}

			}

			id11 tr = new id11();
			int[][] op = new int[id45][3];
			int i, id36;
			int n, id17;
			n = tr.read_segments(poly);


			tr.initialise(n);


			tr.id42(n);


			id17 = tr.id33(n);
			id36 = tr.id38(n, id17, op);

			ArrayList<Polygon> ret = new ArrayList<>();
			for (i = 0; i < id36; i++) {
				Polygon tri = new Polygon();
				tri.lp.add(new Point(poly.lp.get(op[i][0] - 1)));
				tri.lp.add(new Point(poly.lp.get(op[i][1] - 1)));
				tri.lp.add(new Point(poly.lp.get(op[i][2] - 1)));
				ret.add(tri);
			}


			return ret;
		}

		public static int id39(final Polygon poly) {
			int ret = 0;
			Point top = poly.lp.get(0);
			for (int i = 1; i < poly.lp.size(); ++i) {
				Point po = poly.lp.get(i);
				if (po.compareTo(top) > 0) {
					ret = i;
					top = po;
				}
			}

			return ret;
		}

		public static Polygon id23(ArrayList<Point> points) {
			ArrayList<Point> ret = new ArrayList<>();
			Polygon hull = Polygon.id22(points);
			int top = Polygon.id39(hull);
			boolean isLeft = true;


			ArrayList<Point> temp = new ArrayList<>();
			temp.add(hull.lp.get(0));
			int id = top;
			do {
				temp.add(hull.lp.get(id));
				id = hull.next(id);
				if (id == 0) break;
			} while (true);

			if (temp.size() == 2) {

				isLeft = false;
				temp.clear();
				id = 0;
				do {
					temp.add(hull.lp.get(id));
					id = hull.next(id);
				} while (id != top);
				temp.add(hull.lp.get(top));

			}

			Line mainLine = Line.makeLine(hull.lp.get(0), hull.lp.get(top), true);

			hull.lp = temp;

			top = Polygon.id39(hull);
			TreeSet<Point> hs = new TreeSet<>();
			for (Point p : hull.lp) hs.add(p);
			ArrayList<ArrayList<Point>> pEdge = new ArrayList<>();
			for (int i = 0; i < hull.lp.size(); ++i) pEdge.add(new ArrayList<>());

			for (Point p : points)
				if (!hs.contains(p)) {
					if (!mainLine.onSegment(p) && Polygon.id12(p, hull, top) == 0) {

						Pair<Integer, Integer> pr = Polygon.id20(p, hull);

						pEdge.get(pr.first).add(p);
						hs.add(p);
					}
				}


			if (isLeft) {
				ret.add(hull.lp.get(0));
				for (Point p : points)
					if (!hs.contains(p)) {
						ret.add(p);
					}

				for (int i = 1; i < hull.lp.size(); ++i) {
					ret.add(hull.lp.get(i));
					Point.id40(pEdge.get(i), Line.makeLine(hull.lp.get(i), hull.lp.get(hull.next(i)), true));
					for (Point p : pEdge.get(i)) ret.add(p);
				}
			} else {
				for (int i = 0; i < hull.lp.size(); ++i) {
					ret.add(hull.lp.get(i));
					Point.id40(pEdge.get(i), Line.makeLine(hull.lp.get(i), hull.lp.get(hull.next(i)), true));
					for (Point p : pEdge.get(i)) ret.add(p);
				}

				Collections.reverse(points);
				for (Point p : points)
					if (!hs.contains(p)) {
						ret.add(p);
					}
			}

			Polygon pl = new Polygon();
			pl.lp = ret;
			return pl;

		}

	}

	static class InputReader {
		public BufferedReader reader;
		public StringTokenizer tokenizer;

		public InputReader(BufferedInputStream stream) {
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

		public int nextInt() {
			return Integer.parseInt(next());
		}

		public void close() {
			try {
				if (reader != null)
					reader.close();
			} catch (Exception ex) {
				throw new RuntimeException(ex);
			}
		}

	}

	static class Point implements Comparable<Point> {
		public long x;
		public long y;

		public Point(Point o) {
			this.x = o.x;
			this.y = o.y;

		}

		public Point(long x, long y) {
			super();

			this.x = x;
			this.y = y;
		}

		public boolean id35() {
			return x == 0 && y == 0;
		}


		public int compareTo(Point o2) {
			int t = Long.compare(y, o2.y);
			if (t != 0) return t;
			return Long.compare(x, o2.x);
		}

		public static int sgn(long x) {
			return ((0 < x) ? 1 : 0) - ((x < 0) ? 1 : 0);
		}

		public long opMul(Point b) {
			return Point._opMul(this, b);
		}

		public Point opSub(Point b) {
			return Point._opSub(this, b);
		}

		public static long _opMul(Point lhs, Point rhs) {

			return ((lhs.x * rhs.x) + (lhs.y * rhs.y));
		}

		public static long _opPow(Point lhs, Point rhs) {
			return ((lhs.x * rhs.y) - (lhs.y * rhs.x));
		}

		public static Point _opSub(Point lhs, Point rhs) {
			return new Point((lhs.x - rhs.x), (lhs.y - rhs.y));
		}

		public static Point _opPlus(Point lhs, Point rhs) {
			return new Point((lhs.x + rhs.x), (lhs.y + rhs.y));
		}

		public static long ccw(Point lhs, Point rhs) {
			return _opPow(rhs, lhs);
		}

		public static long ccw(Point lhs, Point rhs, Point origin) {

			return ccw(new Point((lhs.x - origin.x), (lhs.y - origin.y)), new Point((rhs.x - origin.x), (rhs.y - origin.y)));
		}

		public static boolean left(Point a, Point b, Point c) {
			return Point.ccw(c, b, a) > 0;
		}

		public static boolean leftOn(Point a, Point b, Point c) {
			return Point.ccw(c, b, a) >= 0;
		}

		public static void id40(ArrayList<Point> lp, final Line vect) {

			final Comparator<Point> cmp = (Point lhs, Point rhs) -> Long.compare(Point._opSub(lhs, vect.a).opMul(vect.ab), Point._opSub(rhs, vect.a).opMul(vect.ab));
			Collections.sort(lp, cmp);
		}


		public String toString() {
			return x + " " + y;
		}


		public int hashCode() {
			return Long.hashCode(x) ^ Long.hashCode(y);
		}

		public boolean equals(Object obj) {
			if (obj instanceof Point) {
				return compareTo((Point) obj) == 0;
			}
			return false;
		}

	}

	static class Line {
		Point a;
		Point ab;

		Line(Point a, Point b, boolean twoPoints) {
			this.a = new Point(a);
			if (twoPoints) {
				this.ab = Point._opSub(b, a);
			} else {
				this.ab = new Point(b);
			}
		}

		Line(long xa, long ya, long xb, long yb) {
			this.a = new Point(xa, ya);

			this.ab = new Point((xb - xa), (yb - ya));
		}

		Point b() {
			return Point._opPlus(a, ab);
		}

		boolean onSegment(Point point) {
			if (this.ab.id35()) return a.compareTo(point) == 0;

			Point vecta = Point._opSub(a, point);
			Point vectb = Point._opSub(b(), point);
			return Point._opPow(vecta, vectb) == 0 && Point._opMul(vecta, vectb) <= 0;
		}


		public String toString() {
			return "Line{" +
					"(" + a +
					") (" + b() +
					")}";
		}

		public static Line makeLine(Point p1, Point p2, boolean twoPoints) {
			return new Line(p1, p2, twoPoints);
		}

	}

	static class Task implements Callable<Task> {
		ArrayList<Point> points = new ArrayList<>();
		HashMap<Point, Integer> mp = new HashMap<>();
		StringBuilder re = new StringBuilder();
		int testNumber;

		public void readInput(InputReader in) {
	
			int n = in.nextInt();
			for (int i = 0; i < n; ++i) {
				Point pt = new Point(in.nextInt(), in.nextInt());
				points.add(pt);
				mp.put(pt, i + 1);
			}
		}

		public Task call() {
	

			Polygon poly = Polygon.id23(points);
			ArrayList<Polygon> tris = Polygon.id15(poly);
			Polygon p1 = tris.get(0);
			for (Point p : p1.lp) {
				re.append(mp.get(p) + " ");
			}
			System.err.println("Test case: " + testNumber + " done!");
			return this;
		}

		public void writeOutput(PrintWriter out) {
			out.println(re);
		}

		Task(int testNumber) {
			this.testNumber = testNumber;
		}

	}

	static class Pair<T1 extends Comparable<T1>, T2 extends Comparable<T2>> implements Comparable<Pair<T1, T2>> {
		public T1 first;
		public T2 second;

		public Pair(T1 first, T2 second) {
			this.first = first;
			this.second = second;
		}


		public int compareTo(Pair<T1, T2> o) {
			int _c1 = first.compareTo(o.first);
			if (_c1 != 0)
				return _c1;
			return second.compareTo(o.second);
		}

		public String toString() {
			return first + " " + second;
		}


		public int hashCode() {
			return first.hashCode() ^ second.hashCode();
		}

	}
}

