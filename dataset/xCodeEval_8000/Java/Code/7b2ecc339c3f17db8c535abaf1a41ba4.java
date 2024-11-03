

import java.util.*;
import java.io.*;
public class InVoker {
	

	static long mod = 1000000007;
	static long mod2 = 998244353;
	static FastReader inp= new FastReader();
	static PrintWriter out= new PrintWriter(System.out);
	public static void main(String args[]) {		    	
	   	InVoker g=new InVoker();
	   	g.main();
	   	out.close();
	}
	
	
	
	

	void main() {
		
		int t=inp.nextInt();
		while(t-->0) {
			int n=inp.nextInt();
			ArrayList<Integer> fac=new ArrayList<>();
			ArrayList<Integer> primes=new ArrayList<>();
			for(int i=2;i*i<=n;i++) {
				if(n%i==0) {
					fac.add(i);
					if(i*i!=n) fac.add(n/i);
				}
			}
			fac.add(n);
			Collections.sort(fac);
			if(fac.size()==3 && isPrime(fac.get(0)) && isPrime(fac.get(1))) {
				for(int x: fac) {
					out.print(x+" ");
				}
				out.println();
				out.println(1);
				continue;
			}
			HashSet<Integer> used=new HashSet<>();
			ArrayList<Integer> connect=new ArrayList<>();
			for(int i=2;i*i<=n;i++) {
				if(n%i==0) {
					primes.add(i);
					while(n%i==0) n/=i;
				}
			}
			if(n>1) primes.add(n);
			
			for(int i=0;i<primes.size();i++) {
				int p1=primes.get(i);
				int p2=primes.get((i+1)%primes.size());
				for(int x: fac) {
					if(!used.contains(x) && x%p1==0 && x%p2==0) {
						used.add(x);
						connect.add(x);
						break;
					}
				}
			}
			
			for(int i=0;i<primes.size();i++) {
				int p=primes.get(i);
				used.add(p);
				out.print(p+" ");
				for(int x: fac) {
					if(!used.contains(x) && x%p==0) {
						used.add(x);
						out.print(x+" ");
					}
				}
				if(primes.size()>1) {
					out.print(connect.get(i)+" ");
				}
			}
			out.println();
			out.println(0);
			
		}
		
	}
	
	boolean isPrime(int x) {
	    for (int i=2;i*i<=x;i++) {
	        if (x%i==0) return false;
	    }
	    return true;
	}
	
	
	
	
	
	

	
	static class Pair implements Comparable<Pair> {
		int f, s, tea;
		Pair () {}
		Pair (int l_, int r_) {
		    this.f = l_;
		    this.s = r_;
		}
		@Override
        public int compareTo(Pair other) {
        	if(this.f==other.f) {
        		return Long.compare(this.s,other.s);
        	}
			return Long.compare(this.f, other.f);
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
