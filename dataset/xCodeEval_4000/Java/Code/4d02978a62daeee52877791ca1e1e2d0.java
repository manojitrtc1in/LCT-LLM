


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Random;
import java.util.Scanner;

public class last {
	public static void main(String[] args) throws IOException {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		AVLTree <Integer> t = new AVLTree();
		for (int i = 0; i < n; i++) {
			int x = in.nextInt();
			t.add(x);
		}
		t.del(t.begin());
		if (t.size() != 0) System.out.println(t.begin());
		else System.out.println("NO");
		
	}
}




class mypoint implements Comparable<mypoint>{
	private int ind = -1; 

	
	private boolean isbeg = false;  

	
	private Point p;
	
	mypoint(Point p, int ind, boolean isbeg){
		this.p = p;
		this.ind = ind;
		this.isbeg = isbeg;
	}

	

	@Override
	public int compareTo(mypoint o) {
		if (p.equals(o.getpoint())) {
			if (isbeg) return -1;
			return 1;
		}
		double t = p.getX() - o.getpoint().getX();
		if (p.getX() == o.getpoint().getX()) {
			if (isbeg) return -1;
			return 1;
		}
		if (t > 0) return 1;
		return -1;
	}
	
	

	public int getind() {
		return ind;
	}
	
	

	public boolean isbeg() {
		return isbeg;
	}
	
	

	public Point getpoint() {
		return p;
	}
	
	public String toString() {
		return p.toString();
	}
}



class Point{
	private double x, y;
	private double ep = 0.000001;
	public Point(double x, double y) {
		this.x = x;
		this.y = y;
	}

	

	public double getX() {
		return this.x;
	}
	
	

	public double getY() {
		return this.y;
	}
	
	

	public double getdistance(Point other) {
		double ret = (x - other.x) * (x - other.x) + (y - other.y) * (y - other.y);
		ret = Math.sqrt(ret);
		return ret;
	}
	
	

	public boolean equals(Point other) {
		if (x == other.getX() && y == other.getY()) return true;
		return false;
	}
	
	

	public boolean belongTo(LineSegment L) {
		

		if (L.getVert()) {
			

			if (x != L.getP()) return false;
			
			

			if (y >= L.getBegin().getY() && y <= L.getEnd().getY()) return true;
			return false;
		}
		
		

		if (Math.abs(y - x * L.getSlope() - L.getP()) >= ep) return false;
		
		

		if (x >= L.getBegin().getX() && x <= L.getEnd().getX()) return true;
		return false;
	}
	
	public String toString() {
		return (int)x +  " " + (int)y;
	}
}



class LineSegment implements Comparable<LineSegment>{
	

	private Point beg, end;
		
	private boolean vert = false; 

	
	private double slope = 0; 

	
	private double p = 0; 

	
	private boolean flip = false; 

	
	

	private double length;
	
	public LineSegment(Point beg, Point end) {
		

		if (beg.equals(end)) {
			System.out.println("Invalid Segment");
			return;
		}
		
		

		if (beg.getX() < end.getX()) {
			this.beg = new Point(beg.getX(), beg.getY());
			this.end = new Point(end.getX(), end.getY());
		}
		else if (beg.getX() > end.getX()) {
			this.end = new Point(beg.getX(), beg.getY());
			this.beg = new Point(end.getX(), end.getY());
			flip = true;
		}
		

		else {
			if (beg.getY() <= end.getY()) {
				this.beg = new Point(beg.getX(), beg.getY());
				this.end = new Point(end.getX(), end.getY());
			}
			else {
				this.end = new Point(beg.getX(), beg.getY());
				this.beg = new Point(end.getX(), end.getY());
				flip = true;
			}
		}
		
		length = this.beg.getdistance(this.end);
		
		if (beg.getX() == end.getX()) {
			vert = true;
			p = beg.getX();
		}
		else {
			slope = (beg.getY() - end.getY()) / (beg.getX() - end.getX());
			p = beg.getY() - slope * beg.getX();
		}
	}
	
	

	public double getLength() {
		return length;
	}
	
	

	public boolean getVert() {
		return vert;
	}
	
	

	public double getSlope() {
		return slope;
	}
	
	

	public double getP() {
		return p;
	}
	
	

	public Point getBegin() {
		return beg;
	}
	
	

	public Point getEnd() {
		return end;
	}
	
	

	public boolean isParallel(LineSegment other) {
		

		if (vert != other.vert) return false;
		
		

		if (vert) return true;
		
		

		if (slope == other.getSlope()) return true;
		return false;
	}
	
	

	public boolean isCoincident(LineSegment other) {
		

		if (!isParallel(other)) return false;
		
		Point beg2 = other.getBegin();
		Point end2 = other.getEnd();
		
		

		if (ShareEndPointWhileParallel(other) == true) return false;
		
		

		if (vert == true) {
			

			if (beg.getY() >= beg2.getY() && beg.getY() <= end2.getY()) return true;
			
			

			if (end.getY() >= beg2.getY() && end.getY() <= end2.getY()) return true;
			
			

			if (beg2.getY() >= beg.getY() && end2.getY() <= end.getY()) return true;
			return false;
		}
		
		

		if (beg.getX() >= beg2.getX() && beg.getX() <= end2.getX()) return true;
		
		

		if (end.getX() >= beg2.getX() && end.getX() <= end2.getX()) return true;
		
		

		if (beg2.getX() >= beg.getX() && end2.getX() <= end.getX()) return true;
		
		return false;
	}
	
	

	public boolean ShareEndPointWhileParallel(LineSegment other) {
		

		if (!isParallel(other)) return false;
		
		Point beg2 = other.getBegin();
		Point end2 = other.getEnd();

		

		if (end2.equals(beg) || beg2.equals(end)) return true;
		return false;
	}
	
	

	public Point findIntersection(LineSegment other) {
		double retx = 0;
		double rety = 0;
		if(isParallel(other)) {
			if (ShareEndPointWhileParallel(other)) {
				if (beg.equals(other.getEnd())) return getBegin();
				if (end.equals(other.getBegin())) return getEnd();
			}
			return null;
		}
		else {
			double xA = beg.getX();
			double xB = end.getX();
			double xC = other.getBegin().getX();
			double xD = other.getEnd().getX();

			double yA = beg.getY();
			double yB = end.getY();
			double yC = other.getBegin().getY();
			double yD = other.getEnd().getY();
			
			double xP_num = (xA * yB - yA * xB) * (xC - xD) - (xA - xB) * (xC * yD - yC * xD);
			double den = (xA - xB) * (yC - yD) - (yA - yB) * (xC - xD);
			double yP_num = (xA * yB - yA * xB) * (yC - yD) - (yA - yB) * (xC * yD - yC * xD);
			
			retx = xP_num / den;
			rety = yP_num / den;
		}
		
		Point ret = new Point(retx, rety);
		
		

		if (ret.belongTo(this) && ret.belongTo(other)) return ret;
		return null;
	} 
	
	

	public boolean ShareEndPoint(LineSegment other) {
		if (ShareEndPointWhileParallel(other)) return true;
		
		Point t = findIntersection(other);
		if (t == null) return false;
		
		int num = 0;
		if (t.equals(beg)) num++;
		if (t.equals(end)) num++;
		if (t.equals(other.getBegin())) num++;
		if (t.equals(other.getEnd())) num++;
		
		

		if (num == 2) return true;
		return false;
	}
	
	public String toString() {
		if (flip) {
			return end + " " + beg;
		}
		else {
			return beg + " " + end;
		}
	}
	
	

	public boolean intersect(LineSegment other) {
		if (!isCoincident(other)) {
			Point t = findIntersection(other);
			if (t == null) {
				return false;
			}
			return true;
		}
		return false;
	}
	
	@Override
	public int compareTo(LineSegment other) {
		if (beg.equals(other.getBegin()) && end.equals(other.getEnd())) return 0;
		Point beg2 = other.getBegin();
		Point end2 = other.getEnd();
		double Ythis = 0;
		double Yother = 0;
		if (beg.getX() >= beg2.getX() && beg.getX() <= end2.getX()) {
			Ythis = beg.getY();
			Yother = beg.getX() * other.getSlope() + other.getP();
		}
		else {
			Ythis = beg2.getX() * getSlope() + getP();
			Yother = beg2.getY();
		}
		if (Ythis >= Yother) return 1;
		return -1;
	}
}



class mycollections{
	

	public static <T extends Comparable<T>> void mysort (T arr[]){
		int n = arr.length;
		T[] myarr = (T[]) new Comparable[n];
		for (int i = 0; i < n; i++) {
			myarr[i] = arr[0];
		}
		actualsort(arr, myarr, 0, n - 1);
	}
	
	

	private static <T extends Comparable<T>> void actualsort (T[] arr, T[] myarr, int l, int r) {
		if (l == r) return;
		int mid = (l + r) / 2;
		actualsort(arr, myarr, l, mid);
		actualsort(arr, myarr, mid + 1, r);
		int comp = 0;
		int L1 = l;
		int L2 = mid + 1;
		for (int i = l; i <= r; i++) {
			if (L1 <= mid && L2 <= r) {
				comp = arr[L1].compareTo(arr[L2]);
				if (comp <= 0) {
					myarr[i] = arr[L1++];
				}
				else {
					myarr[i] = arr[L2++];
				}
			}
			else if (L1 > mid) {
				myarr[i] = arr[L2++];
			}
			else {
				myarr[i] = arr[L1++];
			}
		}
		for (int i = l; i <= r; i++) {
			arr[i] = myarr[i];
		}
	}
}

class AVLTree<T extends Comparable<T>>{
	
	class node{
		node par = null;
		node left = null;
		node right = null;
		int size = 0;
		int height = 0;
		T val;
		public node(node par, T val){
			this.val = val;
			this.par = par;
			height = 0;
			size = 1;
		}
		
		

		public void fix() {
			size = 1;
			if (left != null) size += left.size;
			if (right != null) size += right.size;
			if (size == 1) height = 0;
			else {
				int d = 0;
				if (left != null) d = max(d, left.height);
				if (right != null) d = max(d, right.height);
				height = 1 + d;
			}
		}
		
		

		boolean isLeftChild(node parent) {
			if (parent.left == this) return true;
			return false;
		}
		
		

		boolean isRightChild(node parent) {
			if (parent.right == this) return true;
			return false;
		}
	}
	
	private int WholeSize = 0;
	
	private node root;
	
	

	private void FixSize() {
		if (root != null) {
			WholeSize = root.size;
		}
		else WholeSize = 0;
	}
	
	

	public T getroot() {
		if (root == null) return null;
		return root.val;
	}
	
	

	private int max(int x, int y) {
		if (x >= y) return x;
		return y;
	}

	

	public void add(T val) {
		if (WholeSize == 0) {
			root = new node(null, val);
			WholeSize = 1;
			return;
		}
		
		node p = add(root, val);
		
		FixSize();
		
		

		if (p == null) {
			return;
		}
		
		MakeBalanced(p);
	}
	
	

	private node add(node nd, T val) {
		int com = 0;
		com = val.compareTo(nd.val);
		
		if (com == 0) return null; 

		
		

		if (com > 0) {
			if (nd.right == null) {
				

				nd.right = new node(nd, val);
				nd.fix();
				return nd.right;
			}
			nd = nd.right;
		}

		

		else {
			if (nd.left == null) {
				

				nd.left = new node(nd, val);
				nd.fix();
				return nd.left;
			}
			nd = nd.left;
		}
		
		node ret = add(nd, val);
		
		nd.par.fix();
		
		return ret;
	}
	
	

	public void del(T val) {
		if (WholeSize == 0) {
			return;
		}
		
		

		if (WholeSize == 1 && val.compareTo(root.val) == 0) {
			root = null;
			WholeSize = 0;
			return;
		}
		
		if (WholeSize == 1) return;
		
		node p = del(root, val);
		
		FixSize();
		
		

		if (p == null) return;
		
		MakeBalanced(p);
	}
	
	

	private node del(node nd, T val) {
		int com = 0;
		com = val.compareTo(nd.val);
		
		

		if (com == 0) {
			node parent = nd.par;
			

			if (nd.size == 1) {
				if (nd.isLeftChild(parent)) {
					parent.left = null;
				}
				else {
					parent.right = null;
				}
				return parent;
			}
			
			

			else if (nd.left == null) {
				

				if (parent == null) {
					root = root.right;
					root.par = null;
					root.fix();
					return root;
				}
				else {
					if (nd.isLeftChild(parent)) {
						parent.left = nd.right;
					}
					else if (parent != null){
						parent.right = nd.right;
					}
					nd = nd.right;
					nd.par = parent;
					return nd;
				}
			}
			
			

			else if (nd.right == null) {
				

				if (parent == null) {
					root = root.left;
					root.par = null;
					root.fix();
					return root;
				}
				else {
					if (nd.isLeftChild(parent)) {
						parent.left = nd.left;
					}
					else {
						parent.right = nd.left;
					}
					nd = nd.left;
					nd.par = parent;
					return nd;
				}
			}
			
			

			else {
				node t =  LeftMost(nd.right);
				

				T myval = t.val;
				node ret = t.par;
				del(nd, myval);
				nd.val = myval;
				nd.fix();
				return ret;
			}
		}
		
		

		if (com > 0) {
			if (nd.right == null) {
				

				return null;
			}
			nd = nd.right;
		}

		

		else {
			if (nd.left == null) {
				

				return null;
			}
			nd = nd.left;
		}
		node parent = nd.par;
		
		node ret = del(nd, val);
		
		parent.fix();
		
		return ret;
	}
	
	

	public boolean find(T val) {
		if (lowerbound(val).equals(val)) return true;
		return false;
	}
	
	

	public T lowerbound(T val) {
		node nd = root;
		T ans= null;
		int com = 0;
		while(true) {
			if (nd == null) break;
			com = val.compareTo(nd.val);
			if (com >= 0) {
				ans = nd.val;
				nd = nd.right;
			}
			else {
				nd = nd.left;
			}
		}
		return ans;
	}
	
	

	public T upperbound(T val) {
		node nd = root;
		T ans= null;
		int com = 0;
		while(true) {
			if (nd == null) break;
			com = val.compareTo(nd.val);
			if (com > 0) {
				nd = nd.right;
			}
			else {
				ans = nd.val;
				nd = nd.left;
			}
		}
		return ans;
	}
	
	

	public node RightMost(node st) {
		if (st == null) return null;
		while(true) {
			if (st.right == null) return st;
			st = st.right;
		}
	}
	
	

	public node LeftMost(node st) {
		if (st == null) return null;
		while(true) {
			if (st.left == null) return st;
			st = st.left;
		}
	}
	
	

	private int getH(node x) {
		if (x == null) return -1;
		
		return x.height;
	}
	
	

	private void RightRotate(node y) {
		node parent = y.par;
		node x = y.left;
		if (parent != null) {
			if (y.isLeftChild(parent)) {
				parent.left = x;
			}
			else {
				parent.right = x;
			}
		}
		x.par = parent;
		y.par = x;
		y.left = x.right;
		if (x.right != null) x.right.par = y;
		x.right = y;
		if (parent == null) root = x;
		y.fix();
		x.fix();
		if (parent != null) parent.fix();
	}
	
	

	private void LeftRotate(node x) {
		node parent = x.par;
		node y = x.right;
		if (parent != null) {
			if (x.isLeftChild(parent)) {
				parent.left = y;
			}
			else {
				parent.right = y;
			}
		}
		y.par = parent;
		x.par = y;
		x.right = y.left;
		if (y.left != null) y.left.par = x;
		y.left = x;
		if (parent == null) root = y;
		x.fix();
		y.fix();
		if (parent != null) parent.fix();
	}
	
	

	private void MakeBalanced(node nd) {
		node x, y, z;
		x = nd;
		y = nd;
		z = nd;
		int bal = 0;
		while(true) {
			bal = getH(z.left) - getH(z.right);
			if (bal >= -1 && bal <= 1) {
				if (z == root) return;
				x = y;
				y = z;
				z = z.par;
				continue;
			}
			break;
		}
		
		node parent = z.par;
		
		

		if (x == y && y == z) {
			if (getH(z.left) < getH(z.right)) {
				LeftRotate(z);
			}
			else {
				RightRotate(z);
			}
		}
		
		

		else if (x == y) {
			if (y.isLeftChild(z)) {
				RightRotate(z);
			}
			else{
				LeftRotate(z);
			}
		}
		
		

		else if (y.isLeftChild(z) && x.isLeftChild(y)) {
			RightRotate(z);
		}
		
		

		else if (y.isLeftChild(z) && x.isRightChild(y)) {
			LeftRotate(y);
			RightRotate(z);
		}
		
		

		else if (y.isRightChild(z) && x.isRightChild(y)) {
			LeftRotate(z);
		}
		
		

		else if (y.isRightChild(z) && x.isLeftChild(y)) {
			RightRotate(y);
			LeftRotate(z);
		}
		
		if (parent != null) MakeBalanced(parent);
	}
	
	

	public T begin() {
		return LeftMost(root).val;
	}
	
	

	public T end() {
		return RightMost(root).val;
	}
	
	

	public int size() {
		return WholeSize;
	}
	
	

	public int getH() {
		if (root == null) return 0;
		return root.height;
	}
	
	

	public void show() {
		if (root != null)
			show(root);
	}
	
	

	private void show(node nd) {
		System.out.print("This node's value is ");
		System.out.println(nd.val);
		if (nd.par != null) {
			System.out.println("This node's parent's value is " + nd.par.val);
		}
		System.out.print("This node's size is ");
		System.out.println(nd.size);
		System.out.print("This node's height is ");
		System.out.println(nd.height);
		System.out.print("This node's children are: ");
		if (nd.left != null) System.out.print(nd.left.val + " ");
		if (nd.right != null) System.out.println(nd.right.val);
		System.out.println();
		System.out.println("------------------------------------");
		if (nd.left != null) show(nd.left);
		if (nd.right != null) show(nd.right);
	}
}