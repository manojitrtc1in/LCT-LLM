import java.io.PrintWriter;
import java.util.Scanner;
import java.util.TreeSet;

public class id3 {
	
	int gcd(int a, int b) {
		return b == 0 ? a : gcd(b, a % b);
	}
	
	int id15(LineSeg s) {
		int dx = (int) (s.a.x - s.b.x);
		int dy = (int) (s.a.y - s.b.y);
		return 1 + gcd(Math.abs(dx), Math.abs(dy));
	}
	
	boolean isInteger(double a) {
		return Math.abs(a) % 1 <= 1e-12;
	}
	
	public void solve(Scanner in, PrintWriter out) {
		int n = in.nextInt();
		LineSeg[] segs = new LineSeg[n];
		long ans = 0;
		for(int i = 0; i < n; ++i) {
			Vector a = new Vector(in.nextInt(), in.nextInt());
			Vector b = new Vector(in.nextInt(), in.nextInt());
			LineSeg seg = segs[i] = new LineSeg(a, b);
			int cur = id15(seg);
			TreeSet<Vector> intersections = new TreeSet<>();
			for(int j = 0; j < i; ++j) {
				if(seg.intersects(segs[j])) {
					Vector v = seg.intersect(segs[j]);
					if(isInteger(v.x) && isInteger(v.y)) {
						if(intersections.contains(v)) continue;
						intersections.add(v);
						--cur;
					}
				}
			}
			ans += cur;
		}
		out.println(ans);
	}
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		new id3().solve(in, out);
		in.close();
		out.close();
	}
	static class LineSeg {
	    Vector a, b;
	    
	    public LineSeg(Vector aa, Vector bb) {
	        a = aa;
	        b = bb;
	    }

	    public boolean id5(Vector p) {
	        Vector ap = p.sub(a);
	        Vector pb = b.sub(p);
	        return Vector.equals(ap.mag() + pb.mag(), b.sub(a).mag());
	    }

	    public boolean parallel(LineSeg l) {
	        return Vector.equals(l.b.sub(l.a).cross(b.sub(a)).mag(), 0.0);
	    }

	    public boolean parallel(Vector v) {
	        return Vector.equals(v.cross(b.sub(a)).mag(), 0.0);
	    }

	    

	    public LineSeg rotate(Vector p, double ang) {
	        return new LineSeg(a.rotate(p, ang), b.rotate(p, ang));
	    }

	    

	    public boolean intersects(Vector v) {
	        Vector p = new Vector(a, b).intersect(v);
	        return p == null ? false : id5(p);
	    }
	    
	    

	    public Vector intersect(Vector v) {
	        Vector p = new Vector(a, b).intersect(v);
	        if(p == null || !id5(p)) return null;
	        return p;
	    }
	    

	    public boolean intersects(LineSeg l) {
	        Vector p = intersect(l);
	        return !(p == null);
	    }

	    

	    public Vector intersect(LineSeg l) {
	        if(Vector.equals(a.sub(l.a).mag(), 0.0) || Vector.equals(a.sub(l.b).mag(), 0.0)) return a;
	        if(Vector.equals(b.sub(l.a).mag(), 0.0) || Vector.equals(b.sub(l.b).mag(), 0.0)) return b;
	        Vector p = new Vector(a, b).intersect(new Vector(l.a, l.b));
	        if(p == null || !id5(p) || !l.id5(p)) return null; 
	        return p;
	    }
	    
	    

	    public String toString() {
	        return "{ " + a + " to " + b + " }";
	    } 

	}
	static class Vector implements Comparable<Vector> {
	    public double x, y, z; 

	    public double x0 = 0, y0 = 0, z0 = 0; 

	    public static double epsilon = 1e-6; 

	    public static Vector ORIGIN = new Vector(0, 0, 0); 

	    public static int curId = 0; 

	    public int id = Vector.curId++; 


	    

	    

	    public Vector(double xx, double yy, double zz) {
	        x = xx;
	        y = yy;
	        z = zz;
	    }

	    

	    public Vector(double xx, double yy) {
	        x = xx;
	        y = yy;
	        z = 0.0;
	    }

	    

	    public Vector(Vector a, Vector b) {
	        x = b.x - (x0 = a.x);
	        y = b.y - (y0 = a.y);
	        z = b.z - (z0 = a.z);
	    }

	    

	    
	    

	    public static boolean equals(double a, double b) {
	        return Math.abs(a - b) < epsilon;
	    }

	    public Vector add(Vector v) {
	        return new Vector(x + v.x, y + v.y, z + v.z);
	    }

	    public Vector sub(Vector v) {
	        return new Vector(x - v.x, y - v.y, z - v.z);
	    }
	    
	    public Vector scale(double s) {
	        return new Vector(new Vector(x0, y0, z0), new Vector((x * s) + x0, (y * s) + y0, (z * s) + z0));
	    }

	    public double mag() {
	        return Math.sqrt((x*x) + (y*y) + (z*z));
	    }
	    
	    public double mag2() {
	        return dot(this);
	    }

	    public double dot(Vector v) {
	        return (x * v.x) + (y * v.y) + (z * v.z);
	    }
	    
	    public Vector cross(Vector v) { return new Vector(y*v.z - z*v.y, z*v.x - x*v.z, x*v.y - y*v.x); }

	    public Vector normalize() {
	        double mag = mag();
	        return new Vector(new Vector(x0, y0, z0), new Vector((x / mag) + x0, (y / mag) + y0, (z / mag) + z0));
	    }
	    

	    
	    

	    public Vector id4() { return new Vector(y, -x, z); }

	    

	    public Vector id7() { return new Vector(-y, x, z); }

	    

	    

	    public Vector rotate(Vector c, double a) { return new Vector(new Vector(c.x, c.y, z0), this).rotate(a); }
	    

	    
	    

	    public Vector rotate(double a) {
	        return new Vector(new Vector(x0, y0, z0), new Vector((x*Math.cos(a)) - (y*Math.sin(a)) + x0, (x*Math.sin(a)) + (y*Math.cos(a)) + y0, z + z0));
	    }

	    

	    public boolean id5(Vector p) {
	        if(equals(x, 0.0)) return equals(p.x, x0);
	        return equals(p.y - y0, (y/x) * (p.x - x0));
	    }

	    boolean intersects(Vector v) { return intersect(v) != null; }
	    

	    
	    

	    

	    

	    public Vector intersect(Vector v) {
	        Vector a = new Vector(x0, y0);
	        Vector c = new Vector(v.x0, v.y0);
	        return intersect(a, add(a), c, v.add(c));
	    }
	    

	    
	    

	    

	    public static Vector intersect(Vector a, Vector b, Vector c, Vector d) {
	        double a1 = b.y - a.y, b1 = a.x - b.x, c1 = a1 * a.x + b1 * a.y;
	        double a2 = d.y - c.y, b2 = c.x - d.x, c2 = a2 * c.x + b2 * c.y;
	        double det = a1 * b2 - a2 * b1;
	        if (equals(det, 0)) return null;
	        return new Vector((b2 * c1 - b1 * c2) / det, (a1 * c2 - a2 * c1) / det);
	    }
	    
	    

	    

	    

	    public Vector id17(Vector v) {
	        if(equals(cross(v).mag(), 0.0)) return null; 

	        double s, t;
	        if(!equals(x, 0.0)) {
	            if(!equals(v.y, v.x * y / x)) {
	                s = y0 - v.y0 + (y * (v.x0 - x0) / x);
	                s /= v.y - (v.x * y / x);
	            } else if(!equals(v.z, v.x * z / x)) {
	                s = z0 - v.z0 + (z * (v.x0 - x0) / x);
	                s /= v.z - (v.x * z / x);
	            } else return null;
	            t = (v.x0 + (s * v.x) - x0) / x;
	        } else if(!equals(y, 0.0)) {
	            if(!equals(v.x, v.y * x / y)) {
	                s = x0 - v.x0 + (x * (v.y0 - y0) / y);
	                s /= v.x - (v.y * x / y);
	            } else if(!equals(v.z, v.y * z / y)) {
	                s = z0 - v.z0 + (z * (v.y0 - y0) / y);
	                s /= v.z - (v.y * z / y);
	            } else return null;
	            t = (v.y0 + (s * v.y) - y0) / y;
	        } else if(!equals(z, 0.0)) {
	            if(!equals(v.y, v.z * y / z)) {
	                s = y0 - v.y0 + (y * (v.z0 - z0) / z);
	                s /= v.y - (v.z * y / z);
	            } else if(!equals(v.x, v.z * x / z)) {
	                s = x0 - v.x0 + (x * (v.z0 - z0) / z);
	                s /= v.x - (v.z * x / z);
	            } else return null;
	            t = (v.z0 + (s * v.z) - z0) / z;
	        } else return null;
	        double newX = x0 + (t * x);
	        double id6 = v.x0 + (s * v.x);

	        double newY = y0 + (t * y);
	        double id2 = v.y0 + (s * v.y);

	        double newZ = z0 + (t * z);
	        double id0 = v.z0 + (s * v.z);

	        if(!equals(newX, id6) || !equals(newY, id2) || !equals(newZ, id0)) return null; 

	        return new Vector(newX, newY, newZ);
	    }
	    


	    

	    double angleBetween(Vector v) {
	        return Math.acos( Math.max(-1, Math.min(1, dot(v) / (mag() * v.mag()))) );
	    }

	    

	    double angleTo(Vector v) {
	        

	        

	        if(this.cross(v).z >= 0.0)
	            return Math.acos( Math.max(-1.0, Math.min(1.0, this.dot(v) / (this.mag() * v.mag()))) );
	        return - Math.acos( Math.max(-1.0, Math.min(1.0, this.dot(v) / (this.mag() * v.mag()))) );
	    }
	    
	    

	    

	    

	    int id18(Vector v) { return (int) Math.signum(cross(v).z); }
	    

	    
	    

	    

	    

	    double[] id1(Vector v) {
	        double mags = mag() * v.mag();
	        return new double[]{cross(v).z / mags, dot(v) / mags};
	    }
	    

	    
	    

	    

	    

	    double id9(Vector v) {
	        Vector r = v.sub(this);
	        double dot = r.dot(new Vector(1.0, 0.0)) / r.mag();
	        dot = 1.0 - dot;
	        if(r.y < 0.0)
	            dot = 4.0 - dot;
	        return dot;
	    }
	    


	    

	    

	    boolean id14(Vector v) { return equals(this.dot(v), 0.0); }
	    


	    

	    

	    boolean isParallel(Vector v) { return equals(this.cross(v).mag(), 0.0); }
	    


	     

	    
	    

	    

	    static double triangleArea(Vector p1, Vector p2, Vector p3) {
	        return p2.sub(p1).cross(p3.sub(p1)).mag() / 2.0;
	    }
	    

	    
	    

	    

	    

	    static int id18(Vector p0, Vector p1, Vector p2) {
	        return new Vector(p0, p1).id18(new Vector(p0, p2));
	    }
	    

	    
	    

	    

	    static boolean id8(Vector a, Vector b, Vector c, Vector p) {
	        int pab = (int) Math.signum(p.sub(a).cross(b.sub(a)).z);
	        int pbc = (int) Math.signum(p.sub(b).cross(c.sub(b)).z);
	        if (pab != pbc) return false;
	        int pca = (int) Math.signum(p.sub(c).cross(a.sub(c)).z);
	        return pab == pca;
	    }
	    
	    

	    

	    static boolean id11(Vector a, Vector b, Vector c,
	            Vector d, Vector e, Vector f) {
	        if (id12(a, b, d, e)) return true;
	        if (id12(a, b, e, f)) return true;
	        if (id12(a, b, f, d)) return true;
	            
	        if (id12(b, c, d, e)) return true;
	        if (id12(b, c, e, f)) return true;
	        if (id12(b, c, f, d)) return true;
	            
	        if (id12(a, c, d, e)) return true;
	        if (id12(a, c, e, f)) return true;
	        if (id12(a, c, f, d)) return true;

	        return false;
	    }
	    


	    

	    

	    static double id10(Vector l1, Vector l2, Vector p) {
	        Vector line = l2.sub(l1);  double l = line.dot(line);
	        double t = p.sub(l1).dot(line) / l;  return line.scale(t).add(l1).sub(p).mag();
	    }
	    

	    
	    

	    static double id16(Vector l1, Vector l2, Vector p) {
	        Vector line = l2.sub(l1); double l = line.dot(line);
	        double t = p.sub(l1).dot(line) / l;
	        if (t < 0) return l1.sub(p).mag(); 

	        else if(t > 1) return l2.sub(p).mag(); 

	        return line.scale(t).add(l1).sub(p).mag();
	    }

	    

	    static double id13(Vector p0, Vector p1, Vector p2, Vector p3) {
	        Vector u = p1.sub(p0), v = p3.sub(p2), w = p0.sub(p2);    
	        double a = u.dot(u),  b = u.dot(v), c = v.dot(v),  d = u.dot(w);
	        double e = v.dot(w),  det = a * c - b * b;
	        if (det == 0) return id10(p0, p1, p2);    
	        double s = (b * e - c * d) / det, t = (a * e - b * d) / det;
	        if (s >= 0 && s <= 1 && t >= 0 && t <= 1)
	            return w.add(u.scale(s).sub(v.scale(t))).mag();    
	        double min = Math.min(id10(p0, p1, p2),
	                id10(p0, p1, p3));
	        return Math.min(Math.min(min, id10(p2, p3, p0)),
	                id10(p2, p3, p1));
	    }

	    

	    

	    static boolean id12(Vector a, Vector b, Vector c, Vector d) {
	        Vector ab = b.sub(a), cd = d.sub(c);
	        int o1 = (int) Math.signum(ab.cross(c.sub(a)).z);
	        int o2 = (int) Math.signum(ab.cross(d.sub(a)).z);
	        int o3 = (int) Math.signum(cd.cross(a.sub(c)).z);
	        int o4 = (int) Math.signum(cd.cross(b.sub(c)).z);
	        if (o1 != o2 && o3 != o4) return true;
	        if (o1 == 0 && onSeg(a, b, c)) return true;
	        if (o2 == 0 && onSeg(a, b, d)) return true;
	        if (o3 == 0 && onSeg(c, d, a)) return true;
	        if (o4 == 0 && onSeg(c, d, b)) return true;
	        return false;
	    }
	    
	    

	    

	    static boolean onSeg(Vector a, Vector b, Vector p) {
	        return p.x <= Math.max(a.x, b.x) && p.x >= Math.min(a.x, b.x)
	                && p.y <= Math.max(a.y, b.y) && p.y >= Math.min(a.y, b.y);
	    }

	    

	    static Vector reflect(Vector l1, Vector l2, Vector p) {
	        Vector line = l2.sub(l1);  double l = line.dot(line);
	        double t = p.sub(l1).dot(line) / l;
	        Vector q = line.scale(t).add(l1);
	        return q.add(q.sub(p));
	    }
	    
	    

	    Vector reflect(Vector n) {
	        n = n.normalize();
	        return sub(n.scale(2 * dot(n)));
	    }

	    

	    public int compareTo(Vector p) {
	        if (equals(y, p.y)) return equals(x, p.x) ? 0 : Double.compare(x, p.x);
	        return Double.compare(y, p.y);
	    }
	    

	    
	    

	    

	    

	    public static int compare(Vector a, Vector b) {
	        int res = 0;

	        if (a.x < 0) res += a.y >= 0 ? 1 : 2;
	        else if (a.y < 0) res += 3;
	        
	        if (b.x < 0) res -= b.y >= 0 ? 1 : 2;
	        else if (b.y < 0) res -= 3;

	        if(res == 0) {
	            Vector cross = a.cross(b);  if(cross.z == 0) return 0;
	            if(cross.z > 0) return -1;  else  return 1;
	        }

	        return res;
	    }
	    

	    
	    

	    public String toString() {
	        if(equals(x0, 0.0) && equals(y0, 0.0) && equals(z0, 0.0))
	            return String.format("<%.2f, %.2f, %.2f>", x, y, z);
	        return String.format("<%.2f + %.2ft, %.2f + %.2ft, %.2f + %.2ft>", x0, x, y0, y, z0, z);
	    } 

	}
}
