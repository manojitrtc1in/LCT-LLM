

import java.util.*;
import javafx.util.*;
import java.io.*;
public class id0 {
	

	static long mod = 1000000007;
	static long mod2 = 998244353;
	static FastReader inp= new FastReader();
	static PrintWriter out= new PrintWriter(System.out);
	public static void main(String args[]) {		    	
	   	id0 g=new id0();
	   	g.main();
	   	out.close();
	}
	
	

	void main() {
			
		Point p1=new Point(inp.nextInt(),inp.nextInt());
		Point p2=new Point(inp.nextInt(),inp.nextInt());
		Point p3=new Point(inp.nextInt(),inp.nextInt());
		Point id2=minPoint(p1,p2,p3);
		

		Point id1=maxPoint(p1,p2,p3,id2);
		

		Point midPoint=null;
		if(p1!=id2 && p1!=id1) {
			midPoint=p1;
		}
		else if(p2!=id2 && p2!=id1) {
			midPoint=p2;
		}
		else {
			midPoint=p3;
		}
		

		int gg=id1.x-id2.x + Math.max(id2.y, Math.max(midPoint.y, id1.y)) - Math.min(id2.y, Math.min(midPoint.y, id1.y)) +1 ;
		out.println(gg);
		out.println(id2.x+" "+id2.y);
		printPath(id2,midPoint);
		int y1=Math.min(id2.y, midPoint.y);
		int y2=Math.max(id2.y, midPoint.y);
		if(id1.y>=y2) {
			printPath(new Point(midPoint.x,y2),id1);
		}else if(id1.y<=y1) {
			printPath(new Point(midPoint.x,y1),id1);
		}else {
			printPath(new Point(midPoint.x,id1.y),id1);
		}
		
	}

	static class Point {
		int x, y;
		Point(int x, int y){
			this.x=x;
			this.y=y;
		}
	}
	
	static Point minPoint(Point p1, Point p2, Point p3) {
		if(p1.x<=p2.x && p1.x<=p3.x) {
			return p1;
		}else if(p2.x<=p1.x && p2.x<=p3.x) {
			return p2;
		}else
			return p3;
	}
	static Point maxPoint(Point p1, Point p2, Point p3, Point minPoint) {
		if(p1.x>=p2.x && p1.x>=p3.x && p1!=minPoint) {
			return p1;
		}else if(p2.x>=p1.x && p2.x>=p3.x && p2!=minPoint) {
			return p2;
		}else
			return p3;
	}
	
	static void printPath(Point p1, Point p2) {
		for(int i=p1.x+1;i<=p2.x;i++) {
			out.println(i+" "+p1.y);
		}
		if(p1.y>p2.y) {
			for(int i=p1.y-1;i>=p2.y;i--) {
				out.println(p2.x+" "+i);
			}
		}else {
			for(int i=p1.y+1;i<=p2.y;i++) {
				out.println(p2.x+" "+i);
			}
		}
	}
	
	
	
	
	
	

	static class Edge implements Comparable<Edge>{
		int l,r;
		Edge(){}
		Edge(int l,int r){
			this.l=l;
			this.r=r;
		}
		@Override
		public int compareTo(Edge e) {
			return (l-e.l)!=0?l-e.l:r-e.r;
		}
	}
	
    static class Segment implements Comparable<Segment> {
		long l, r, initialIndex;
		Segment () {}
		Segment (long l_, long r_, long d_) {
		    this.l = l_;
		    this.r = r_;
		    this.initialIndex = d_;
		}
		@Override
		public int compareTo(Segment o) {
		    return (int)((l - o.l) !=0 ? l-o.l : initialIndex - o.initialIndex);
		}
    }
    
    static class FastReader { 
        BufferedReader br; 
        StringTokenizer st; 
  
        public FastReader() { 
            br = new BufferedReader(new InputStreamReader(System.in)); 
        } 
        String next() { 
            while (st==null || !st.hasMoreElements()) { 
                try { 
                    st = new StringTokenizer(br.readLine()); 
                } 
                catch (IOException  e) { 
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
            String s=""; 
            try { 
                s=br.readLine(); 
            } 
            catch (IOException e) { 
                e.printStackTrace(); 
            } 
            return s; 
        } 
    } 
    
    

	static long gcd(long a, long b) { 
		return b==0?a:gcd(b,a%b);
	}
	static int gcd(int a, int b) { 
		return b==0?a:gcd(b,a%b);
	}
	
	void reverse(long[] A,int l,int r) {
        int i=l,j=r-1;
        while(i<j) {
            long t=A[i];
            A[i]=A[j];
            A[j]=t;
            i++;j--;
        }
    }
    void reverse(int[] A,int l,int r) {
        int i=l,j=r-1;
        while(i<j) {
            int t=A[i];
            A[i]=A[j];
            A[j]=t;
            i++;j--;
        }
    }
    
    

    static void input(long a[], int n) {
		for(int i=0;i<n;i++) {
			a[i]=inp.nextLong();
		}
	}
	static void input(int a[], int n) {
		for(int i=0;i<n;i++) {
			a[i]=inp.nextInt();
		}
	}	
	static void input(String s[],int n) {
		for(int i=0;i<n;i++) {
			s[i]=inp.next();
		}
	}
	static void input(int a[][], int n, int m) {
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				a[i][j]=inp.nextInt();
			}
		}
	}
	static void input(long a[][], int n, int m) {
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				a[i][j]=inp.nextLong();
			}
		}
	}
		
}
