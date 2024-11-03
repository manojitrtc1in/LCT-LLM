import java.io.*;
import java.util.*;

import static java.lang.Math.*;

public class id24 {

	public static void main(String[] args) {
		

		FastScanner input = new FastScanner();
		int n = input.nextInt();
		P[] arr = new P[n];
		for (int a = 0; a < n; a++) {
			arr[a] = new P(input.nextInt(), input.nextInt());
		}
		double minDist = 234523452345234.0;
		

		for (int a = 0; a < n; a++) {
			for (int b = a + 1; b < n; b++) {
				P point1 = arr[a];
				P point2 = arr[b];
				double dist = point1.dist(point2);
				if (dist < minDist) {
					minDist = dist;
				}
			}
		}

		

		

		for (int a = 0; a < n; a++) {
			P p1 = arr[a];
			P p2 = arr[(a + 2) % n];

			P us = arr[(a + 1) % n];

			Line l1 = new Line(p1, p2);
			double dist = l1.distance(us) / 2;
			if (dist < minDist) {
				minDist = dist;
			}
		}

		System.out.println(minDist);

	}

	

	static class P {
		final double x, y;

		P(double x, double y) {
			this.x = x;
			this.y = y;
		}

		P sub(P that) {
			return new P(x - that.x, y - that.y);
		}

		P add(P that) {
			return new P(x + that.x, y + that.y);
		}

		double dot(P that) {
			return x * that.x + y * that.y;
		}

		P mult(double s) {
			return new P(x * s, y * s);
		}

		

		double length() {
			return sqrt(x * x + y * y);
		}

		double length2() {
			return x * x + y * y;
		}

		P leftNormal() {
			return new P(-y, x);
		} 


		P rightNormal() {
			return new P(y, -x);
		} 


		P normalize() {
			double n = length();
			return n > 0 ? new P(x / n, y / n) : origin();
		}

		

		

		P scale(double l) {
			return normalize().mult(l);
		}

		P project(P a) {
			return mult(a.dot(this) / length2());
		}

		P reflect(P a) {
			return project(a).mult(2.0).sub(a);
		}

		

		P id26(double sinT, double cosT) {
			return new P(x * cosT - y * sinT, x * sinT + y * cosT);
		}

		P rotateCW(double sinT, double cosT) {
			return id26(-sinT, cosT);
		}

		P rotate(double theta) {
			return id26(sin(theta), cos(theta));
		}

		double theta() {
			return atan2(y, x);
		} 


		double angleTo(P a) {
			return acos(this.dot(a) / this.length() / a.length());
		}

		boolean isOrigin() {
			return x == 0 && y == 0;
		}

		public String toString() {
			return String.format("(%f,%f)", this.x, this.y);
		}

		static P read(Scanner s) {
			return new P(s.nextDouble(), s.nextDouble());
		}

		static P origin() {
			return new P(0, 0);
		}

		double det(P that) {
			return this.x * that.y - this.y * that.x;
		}

		double crossproduct(P that) {
			return this.det(that);
		}

		P half(P q) {
			return normalize().add(q.normalize());
		}

		double dist(P to) {
			return sub(to).length();
		}

		double id13(P b, P c) {
			return (b.sub(this).crossproduct(c.sub(this)));
		}

		boolean id12(P b, P c) {
			return abs(id13(b, c)) <= EPS;
		}

		

		

		boolean id15(P b, P c) {
			return id13(b, c) > 0;
		}

		double id19(P b, P c) {
			return id13(b, c) / 2.0;
		}

		

		

		double dist2(P to) {
			double dx = this.x - to.x;
			double dy = this.y - to.y;
			return dx * dx + dy * dy;
		}

		
		P[] id4(double b, double C) {
			P a = this;
			if (a.isOrigin())
				throw new Error("degenerate case");

			boolean transpose = abs(a.x) > abs(a.y);
			a = transpose ? new P(a.y, a.x) : a;

			Double[] x = id2(a.length2(), 2.0 * b * a.x, b * b - a.y
					* a.y * C * C);
			P[] p = new P[x.length];
			for (int i = 0; i < x.length; i++) {
				double x1 = x[i];
				double x2 = ((-b - a.x * x1) / a.y);
				p[i] = transpose ? new P(x2, x1) : new P(x1, x2);
			}
			return p;
		}
	}

	static class HP extends P { 

		HP(double x, double y) {
			super(x, y);
		}

		@Override
		public int hashCode() {
			return Double.hashCode(x + 32768 * y);
		}

		@Override
		public boolean equals(Object _that) {
			HP that = (HP) _that;
			return this.x == that.x && this.y == that.y;
		}
	}

	
	static Comparator<P> id11(final P center) {
		return new Comparator<P>() {
			public int compare(P a, P b) {
				double thetaa = a.sub(center).theta();
				double thetab = b.sub(center).theta();
				if (thetaa < 0)
					thetaa += 2 * PI;
				if (thetab < 0)
					thetab += 2 * PI;
				int c = Double.compare(thetaa, thetab);
				if (c != 0)
					return c;
				return Double.compare(b.x, a.x); 

			}
		};
	}

	
	static Comparator<P> id21(final P center) {
		return new Comparator<P>() {
			public int compare(P a, P b) {
				

				

				if (a.y >= center.y && b.y < center.y)
					return -1;
				if (b.y >= center.y && a.y < center.y)
					return 1;
				int orientation = (int) Math.signum(center
						.id13(b, a));
				if (orientation != 0)
					return orientation;
				return Double.compare(b.x, a.x); 

			}
		};
	}

	
	static Double[] id2(double a, double b, double c) {
		double D = b * b - 4 * a * c;
		if (D < -EPS)
			return new Double[] {};
		D = max(D, 0);
		if (D == 0)
			return new Double[] { -b / 2.0 / a };
		double d = sqrt(D);
		

		

		if (signum(b) == 0)
			return new Double[] { d / 2.0 / a, -d / 2.0 / a };
		double x1 = (-b - signum(b) * d) / (2 * a);
		double x2 = c / (a * x1);
		return new Double[] { Math.min(x1, x2), Math.max(x1, x2) };
	}

	
	static double EPS = 1e-6;

	
	static class Line {
		P p, q, d;

		Line(P p, P q) {
			this.p = p;
			this.q = q;
			d = q.sub(p);
		}

		P id3(double t) {
			return p.add(d.mult(t));
		}

		

		P reflect(P d2) {
			return d.reflect(d2);
		}

		

		P reflectPoint(P r) {
			return reflect(r.sub(p)).add(p);
		}

		

		P project(P a) {
			return p.add(d.project(a.sub(p)));
		}

		

		double distance(P a) {
			return project(a).dist(a);
		}

		@Override
		public String toString() {
			return String.format("[%s => %s]", p, q);
		}

		
		P id14(Line l) {
			double[] st = intersectionParameters(l);
			if (st == null)
				return null;

			

			

			double s = st[0];
			double t = st[1];
			if (s >= -EPS && s <= 1 + EPS && -EPS <= t && t <= 1 + EPS)
				return id3(s);

			return null;
		}

		
		P intersects(Line l) {
			double[] st = intersectionParameters(l);
			if (st != null)
				return id3(st[0]);
			return null;
		}

		
		double[] intersectionParameters(Line l) {
			P dneg = p.sub(q);
			double D = l.d.det(dneg);
			

			if (D == 0.0)
				return null;

			P rp = p.sub(l.p);
			return new double[] { l.d.det(rp) / D, rp.det(dneg) / D };
		}

		
		P[] id8(Circle c) {
			P x = project(c.c);
			double D = x.dist(c.c);
			

			if (D > c.R + EPS)
				return new P[0];
			double h = sqrt(max(0, c.R * c.R - D * D));
			if (h == 0)
				return new P[] { x }; 

			return new P[] { x.add(d.scale(h)), x.add(d.scale(-h)) };
		}

		
		P[] id5(Circle c) {
			P ca = c.c.sub(p);
			P d = q.sub(p);
			Double[] t = id2(d.length2(), -2 * d.dot(ca),
					ca.length2() - c.R * c.R);
			P[] r = new P[t.length];
			for (int i = 0; i < t.length; i++)
				r[i] = p.add(d.mult(t[i]));
			return r;
		}

		
		boolean contains(P r) {
			double t = p.id13(q, r);
			if (abs(t) > EPS) 

				return false;

			

			

			

			return p.dist(r) < p.dist(q) + EPS && r.sub(p).dot(d) >= EPS;
		}
	}

	static class Circle {
		P c;
		double R;

		Circle(P c, double R) {
			this.c = c;
			this.R = R;
		}

		@Override
		public String toString() {
			return String.format("{%s, %.03f}", c, R);
		}

		boolean contains(P p) {
			return R > p.dist(c) + EPS;
		}

		
		boolean isOutside(Line l) {
			if (contains(l.p) || contains(l.q))
				return false;
			P[] _is = l.id8(this);
			if (_is.length > 1)
				for (P is : _is)
					if (l.contains(is))
						return false;
			return true;
		}

		
		Line[] id9(P p) {
			

			

			

			

			P[] r = p.sub(c).id4(-R * R, R);
			Line[] id25 = new Line[r.length];
			for (int i = 0; i < id25.length; i++)
				id25[i] = new Line(p, c.add(r[i]));
			return id25;
		}

		
		P[] id8(Circle that) {
			double r1 = this.R;
			double r2 = that.R;
			P m = that.c.sub(this.c);
			P[] id23 = m.id4(
					(r2 * r2 - r1 * r1 - m.length2()) / 2, r1);
			

			P[] is = new P[id23.length];
			for (int i = 0; i < id23.length; i++)
				is[i] = this.c.add(id23[i]);
			return is;
		}

		

		boolean isOutside(Circle that) {
			return this.c.dist(that.c) > (this.R + that.R);
		}

		

		boolean id6(Circle that) {
			

			P m = this.c.sub(that.c);
			return that.contains(this.c.add(m.scale(this.R)));
		}
	}

	
	static class Polygon {
		P[] p; 


		

		Polygon(Collection<P> c) {
			this.p = c.toArray(new P[c.size()]);
		}

		Polygon(P[] p) {
			this.p = (P[]) p.clone();
		}

		
		double signedArea() {
			double area = 0.0;
			for (int i = 0; i < p.length; i++) {
				area += p[i].det(p[(i + 1) % p.length]);
			}
			return area / 2.0;
		}

		double absoluteArea() {
			return abs(signedArea());
		}

		
		public Polygon id18() {
			if (p.length < 2)
				return null;

			

			final P min = Collections.min(Arrays.asList(p),
					new Comparator<P>() {
						public int compare(P p1, P p2) {
							int y = Double.valueOf(p1.y).compareTo(p2.y);
							return y != 0 ? y : Double.valueOf(p1.x).compareTo(
									p2.x);
						}
					});

			

			Arrays.sort(p, new Comparator<P>() {
				public int compare(P p1, P p2) {
					double o = min.id13(p1, p2); 

					if (o != 0)
						return -(int) Math.signum(o);

					

					return Double.valueOf(min.dist(p1)).compareTo(min.dist(p2));
				}
			});

			

			Stack<P> hull = new Stack<P>();
			assert p[0] == min;
			hull.push(p[0]);
			hull.push(p[1]);

			

			for (int i = 2; i < p.length; i++) {
				P next = p[i];
				while (hull.size() >= 2) {
					P snd = hull.get(hull.size() - 2);
					P top = hull.peek();
					if (snd.id15(top, next)) 

						break;

					hull.pop(); 

				}
				

				hull.push(next);
			}
			return new Polygon(hull);
		}

		
		public boolean contains(P q) {
			return id1(q);
		}

		
		private boolean contains_CN(P q) {
			boolean c = false;
			for (int i = 0, j = p.length - 1; i < p.length; j = i++) {
				if ((((p[i].y <= q.y) && (q.y < p[j].y)) || ((p[j].y <= q.y) && (q.y < p[i].y)))
						&& (q.x < (p[j].x - p[i].x) * (q.y - p[i].y)
								/ (p[j].y - p[i].y) + p[i].x))
					c = !c;
			}
			return c;
		}

		
		public boolean id1(P q) {
			int wn = 0; 


			

			int n = p.length;
			for (int i = 0; i < n; i++) { 

				P p = this.p[i], pn = this.p[(i + 1) % n];
				if (p.y <= q.y) { 

					if (pn.y > q.y) 

						if (p.id15(pn, q)) 

							++wn; 

				} else { 

					if (pn.y <= q.y) 

						if (!p.id15(pn, q)) 

							--wn; 

				}
			}
			return wn != 0;
		}

		
		public boolean onBoundary(P q) {
			int n = p.length;
			for (int i = 0; i < n; i++) {
				P pi = this.p[i], pj = this.p[(i + 1) % n];
				if (new Line(pi, pj).contains(q))
					return true;
			}
			return false;
		}

		@Override
		public String toString() {
			return Arrays.toString(p);
		}
	}

	static class KDTree {
		final static int DIM = 2; 


		static class Node {
			P p;
			final int level;
			Node below;
			Node above;

			Node(P p, int level) {
				this.p = p;
				this.level = level;
			}

			

			double diff(P pt) {
				switch (level) {
				case 0:
					return pt.x - p.x;
				case 1:
					return pt.y - p.y;
				}
				throw new Error("invalid level: " + level);
			}

			
			int rangeCount(P pt, double maxRadius) {
				int count = (p.dist2(pt) <= maxRadius * maxRadius) ? 1 : 0;
				double d = diff(pt);
				if (-d <= maxRadius && above != null)
					count += above.rangeCount(pt, maxRadius);
				if (d <= maxRadius && below != null)
					count += below.rangeCount(pt, maxRadius);
				return count;
			}

			
			void id20(P pt, double maxRadius, List<P> bag) {
				if (p.dist2(pt) <= maxRadius * maxRadius)
					bag.add(p);

				double d = diff(pt);
				if (-d <= maxRadius && above != null)
					above.id20(pt, maxRadius, bag);
				if (d <= maxRadius && below != null)
					below.id20(pt, maxRadius, bag);
			}

			void id22(P pt, double maxRadius, int k,
					TreeSet<P> knn) {
				if (p.dist2(pt) < maxRadius * maxRadius)
					knn.add(p);

				double d = diff(pt);
				Node myside = d <= 0 ? below : above;
				Node otherside = d <= 0 ? above : below;

				if (myside != null)
					myside.id22(pt, maxRadius, k, knn);

				

				if (otherside != null && abs(d) <= maxRadius) {
					double w = knn.size() == k ? pt.sub(knn.last()).length2()
							: Double.POSITIVE_INFINITY;

					

					

					if (d * d <= w)
						otherside.id22(pt, maxRadius, k,
								knn);
				}
			}

			@Override
			public String toString() {
				return String.format("KD[%s - %c,%s,%s]", p,
						"XY".charAt(level), below, above);
			}

			int size() {
				int sz = 1;
				if (below != null)
					sz += below.size();
				if (above != null)
					sz += above.size();
				return sz;
			}
		}

		public int size() {
			return root == null ? 0 : root.size();
		}

		private Node insert(Node t, P pt, int parentLevel) {
			if (t == null) { 

				t = new Node(pt, (parentLevel + 1) % DIM);
			} else {
				if (t.diff(pt) < 0.0) 

										

										

										

					t.below = insert(t.below, pt, t.level);
				else
					t.above = insert(t.above, pt, t.level);
			}
			return t;
		}

		Node root;

		public void insert(P pt) {
			root = insert(root, pt, -1);
		}

		List<P> id20(P pt, double maxRadius) {
			List<P> bag = new ArrayList<>();
			if (root != null)
				root.id20(pt, maxRadius, bag);
			return bag;
		}

		

		public P findmin(final int dim) {
			return findmin(root, dim);
		}

		private P findmin(Node t, final int dim) {
			if (t == null)
				return null;

			if (dim == t.level) {
				if (t.below == null)
					return t.p;
				else
					return findmin(t.below, dim);
			} else {
				

				P pb = findmin(t.below, dim);
				P pa = findmin(t.above, dim);
				P pt = t.p;
				

				if (pa != null) {
					if (dim == 0 && pa.x < pt.x)
						pt = pa;
					if (dim == 1 && pa.y < pt.y)
						pt = pa;
				}

				

				if (pb != null) {
					if (dim == 0 && pb.x < pt.x)
						pt = pb;
					if (dim == 1 && pb.y < pt.y)
						pt = pb;
				}
				return pt;
			}
		}

		public void delete(P x) {
			root = delete(x, root);
		}

		

		private Node delete(P x, Node t) {
			if (t == null)
				throw new Error(String.format("Point %s not found", x));

			if (t.p.equals(x)) {
				if (t.above != null) {
					t.p = findmin(t.above, t.level); 

														

					t.above = delete(t.p, t.above); 

													

				} else if (t.below != null) {
					t.p = findmin(t.below, t.level); 

														

					t.above = delete(t.p, t.below); 

													

					t.below = null;
				} else {
					t = null;
				}
			} else {
				double d = t.diff(x);
				if (d < 0)
					t.below = delete(x, t.below);
				else
					t.above = delete(x, t.above);
			}
			return t;
		}

		
		public void id17() {
			id17(root, Double.NEGATIVE_INFINITY,
					Double.POSITIVE_INFINITY, Double.NEGATIVE_INFINITY,
					Double.POSITIVE_INFINITY, 0);
		}

		private void id17(Node t, double xlow, double xhigh,
				double ylow, double yhigh, int level) {
			if (t == null)
				return;
			if (t.level != level)
				throw new Error();
			switch (t.level) {
			case 0:
				if (t.p.x < xlow)
					throw new Error();
				if (t.p.x >= xhigh)
					throw new Error();
				id17(t.above, t.p.x, xhigh, ylow, yhigh,
						(level + 1) % 2);
				id17(t.below, xlow, t.p.x, ylow, yhigh,
						(level + 1) % 2);
				break;
			case 1:
				if (t.p.y < ylow)
					throw new Error();
				if (t.p.y >= yhigh)
					throw new Error();
				id17(t.above, xlow, xhigh, t.p.y, yhigh,
						(level + 1) % 2);
				id17(t.below, xlow, xhigh, ylow, t.p.y,
						(level + 1) % 2);
				break;
			}
		}

		
		TreeSet<P> id10(P pt, double maxDist, final int k) {
			
			TreeSet<P> knn = new TreeSet<P>(new Comparator<P>() {
				@Override
				public int compare(P a, P b) {
					int c = Double.compare(a.sub(pt).length2(), b.sub(pt)
							.length2());
					if (c != 0)
						return c;
					return Integer.compare(System.identityHashCode(a),
							System.identityHashCode(b));
				}
			}) {
				@Override
				public boolean add(P p) {
					boolean b = super.add(p);
					if (size() > k)
						pollLast();
					return b;
				}
			};
			root.id22(pt, maxDist, k, knn);
			return knn;
		}
	}

	public static class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner(Reader in) {
			br = new BufferedReader(in);
		}

		public FastScanner() {
			this(new InputStreamReader(System.in));
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

		String id16() {
			String str = "";
			try {
				str = br.readLine();
			} catch (IOException e) {
				e.printStackTrace();
			}
			return str;
		}

		int[] id0(int n) {
			int[] a = new int[n];
			for (int idx = 0; idx < n; idx++) {
				a[idx] = nextInt();
			}
			return a;
		}

		long[] id7(int n) {
			long[] a = new long[n];
			for (int idx = 0; idx < n; idx++) {
				a[idx] = nextLong();
			}
			return a;
		}
	}
}
