import java.io.*;
import java.util.*;
import static java.lang.Math.*;


public class KoaAndTheBeach {
    public static void main(String[] args) throws IOException {
    	InputStream inputStream = System.in;
        OutputStream outputStream = System.out;


        

        


        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskA solver = new TaskA();
        solver.solve(in.nextInt(), in, out);
        out.close();
    }
    static class TaskA {
        long mod = (long)(1000000007);
        long fact[];
        int depth[];
        int parentTable[][];
        int degree[];
        ArrayList<Integer> leaves;
        int max = Integer.MIN_VALUE;
        int min = Integer.MAX_VALUE;

        int timer = 0;

        public void solve(int testNumber, InputReader in, PrintWriter out) throws IOException {
            while(testNumber-->0){
                int n = in.nextInt();
                long k = in.nextLong();
                long l = in.nextLong();
                long a[] = new long[n];
                for(int i=0;i<n;i++)
                	a[i] = in.nextLong();
                ArrayList<ArrayList<Pair>> b = new ArrayList<>();
                boolean ok = true;
                for(int i=0;i<n;i++){
                	if(a[i]>l){
                		ok = false;
                		out.println("No");
                		break;
                	}
                	b.add(new ArrayList<>());
                	long x1 = 0l;
                	long x2 = l-a[i];
                	long y1 = 2*k - x2;
                	long y2 = 2*k-1;
                	if(x2>=y1){
                		b.get(i).add(new Pair(x1 , y2));
                	}
                	else{
                		b.get(i).add(new Pair(x1 , x2));
                		if(y1<=y2)
	                		b.get(i).add(new Pair(y1 , y2));
                	}
                }
                if(!ok)
                	continue;

                

                

                

                

                

                


                ArrayList<Pair> ans = new ArrayList<>();
                ans = b.get(0);

                for(int i=1;i<n;i++){

                	ArrayList<Pair> playerNow = b.get(i);
                	ArrayList<Pair> next = new ArrayList<>();

                	for(int j=0;j<ans.size();j++){
                		Pair aa = ans.get(j);

                		for(int m=0;m<playerNow.size();m++){
                			Pair bb = playerNow.get(m);

                			

                			if(aa.y+1<bb.x || bb.y+1<aa.x)
                				continue;

                			

                			if(aa.y+1 == bb.x){
                				next.add(new Pair(bb.x , bb.y));
                				continue;
                			}

                			

                			if(aa.x<=bb.x && bb.x<=aa.y && aa.y<=bb.y){
                				long start;
                				if(aa.x == bb.x)
                					start = bb.x+1;
                				else
                					start = bb.x;

                				if(start<=bb.y)
                					next.add(new Pair(start , bb.y));
                				continue;
                			}

                			

                			if(bb.x<=aa.x && aa.x<= bb.y && aa.y>=bb.y){
                				long start;
                				if(aa.x == bb.x)
                					start = bb.x+1;
                				else
                					start = aa.x+1;

                				if(start<=bb.y)
                					next.add(new Pair(start , bb.y));
                				continue;
                			}

                			

                			if(bb.y+1 == aa.x){
                				continue;
                			}

                			

                			if(bb.y+1 < aa.x)
                				continue;

                			

                			if(aa.x<=bb.x && aa.y>=bb.y){
                				long start;
                				if(aa.x == bb.x)
                					start = bb.x+1;
                				else
                					start = bb.x;

                				if(start<=bb.y)
                					next.add(new Pair(start , bb.y));
                				continue;
                			}

                			

                			if(bb.x<=aa.x && bb.y>= aa.y){
                				long start;
                				if(aa.x == bb.x)
                					start = bb.x+1;
                				else
                					start = aa.x+1;

                				if(start<=bb.y)
                					next.add(new Pair(start , bb.y));
                				continue;
                			}

                		}
                		if(aa.y == 2*k-1){
                			for(Pair p : b.get(i))
                				if(p.x == 0l){
                					next.add(p);
                					break;
                				}
                		}
                	}

                	for(Pair p : next){
                		if(p.y == 2*k-1){
                			for(Pair q:b.get(i)){
                				if(q.x == 0l)
                					next.add(q);
                			}
                			break;
                		}
                	}

                	

                	

                	


                	ans = next;
                	combine(ans);
                	if(ans.size() == 0){
                		ok = false;
                		break;
                	}
                }

                if(ok)
                	out.println("YES");
                else
                	out.println("NO");
                


            }
        }

        public void combine(ArrayList<Pair> a){
        	while(true){
        		boolean found = false;
        		for(int i=0;i<a.size();i++){
        			Pair aa = a.get(i);
        			for(int j=0;j<a.size();j++){
        				if(i == j)
        					continue;
        				Pair bb = a.get(j);
        				if(aa.y+1<bb.x || bb.y+1<aa.x)
        					continue;
        				Pair cc = new Pair(min(aa.x , bb.x) , max(aa.y , bb.y));
        				a.set(i , cc);
        				a.remove(j);
        				found = true;
        				break;
        			}
        			if(found)
        				break;
        		}
        		if(!found)
        			break;
        	}
        }

        class Pair{
            long x;
            long y;
            public Pair(long x , long y){
                this.x = x;
                this.y = y;
            }
        }

        class Sort implements Comparator<Pair>{
        	public int compare(Pair a , Pair b){
        		if(a.x < b.x)
        			return -1;
        		if(a.x == b.x && a.y<b.y)
        			return -1;
        		if(a.x == b.x && a.y == b.y)
        			return 0;
        		return 1;
        	}
        }

        public void print1d(char a[] , PrintWriter out){
        	for(int i=0;i<a.length;i++)
        		out.print(a[i]);
        	out.println();
        }
        

        public int[][] multiply(int a[][] , int b[][]){
            int c[][] = new int[a.length][b[0].length];
            for(int i=0;i<a.length;i++){
                for(int j=0;j<b[0].length;j++){
                    for(int k=0;k<b.length;k++)
                        c[i][j] += a[i][k]*b[k][j];
                }
            }
            return c;
        }

        public int[][] multiply(int a[][] , int b[][] , int mod){
            int c[][] = new int[a.length][b[0].length];
            for(int i=0;i<a.length;i++){
                for(int j=0;j<b[0].length;j++){
                    for(int k=0;k<b.length;k++){
                        c[i][j] += a[i][k]*b[k][j];
                        c[i][j]%=mod;
                    }
                }
            }
            return c;
        }

        public int[][] pow(int a[][] , long b){
            int res[][] = new int[a.length][a[0].length];
            for(int i=0;i<a.length;i++)
                res[i][i] = 1;
            while(b>0){
                if((b&1) == 1)
                    res = multiply(res , a , 10);
                a = multiply(a , a , 10);
                b>>=1;
            }
            return res;
        }

        public int distance(ArrayList<ArrayList<Integer>> a , int u , int v){
            return depth[u]+depth[v] - 2*depth[lca(a , u , v)];
        }

        public int lca(ArrayList<ArrayList<Integer>> a , int u , int v){
            if(depth[v]<depth[u]){
                int x = u;
                u = v;
                v = x;
            }
            int diff = depth[v] - depth[u];
            for(int i=0;i<parentTable[v].length;i++){
                

                if(((diff>>i)&1) == 1)
                    v = parentTable[v][i];
            }
            if(v == u)
                return v;
            for(int i=parentTable[v].length-1;i>=0;i--){
                if(parentTable[u][i] != parentTable[v][i]){
                    v = parentTable[v][i];
                    u = parentTable[u][i];
                }
            }
            return parentTable[u][0];
        }

        

        public void build(int lookup[][] , int arr[], int n) { 
            for (int i = 0; i < n; i++) 
                lookup[i][0] = arr[i]; 
            for (int j = 1; (1 << j) <= n; j++) { 
                for (int i = 0; (i + (1 << j) - 1) < n; i++) { 
                    if (lookup[i][j - 1] > lookup[i + (1 << (j - 1))][j - 1]) 
                        lookup[i][j] = lookup[i][j - 1]; 
                    else
                        lookup[i][j] = lookup[i + (1 << (j - 1))][j - 1]; 
                } 
            } 
        }
        public int query(int lookup[][] , int L, int R) { 
            int j = (int)(Math.log(R - L + 1)/Math.log(2)); 
            if (lookup[L][j] >= lookup[R - (1 << j) + 1][j]) 
                return lookup[L][j]; 
            else
                return lookup[R - (1 << j) + 1][j]; 
        }

        

        public void print1d(int a[] , PrintWriter out){
            for(int i=0;i<a.length;i++)
                out.print(a[i] + " ");
            out.println();
        }
        public void print1d(long a[] , PrintWriter out){
            for(int i=0;i<a.length;i++)
                out.print(a[i] + " ");
            out.println();
        }
        public void print2d(int a[][] , PrintWriter out){
            for(int i=0;i<a.length;i++){
                for(int j=0;j<a[i].length;j++)
                    out.print(a[i][j] + " ");
                out.println();
            }
            

        }
        public void print2d(long a[][] , PrintWriter out){
            for(int i=0;i<a.length;i++){
                for(int j=0;j<a[i].length;j++)
                    out.print(a[i][j] + " ");
                out.println();
            }
            

        }


        public void sieve(int a[]){
            a[0] = a[1] = 1;
            int i;
            for(i=2;i*i<=a.length;i++){
                if(a[i] != 0)
                    continue;
                a[i] = i;
                for(int k = (i)*(i);k<a.length;k+=i){
                    if(a[k] != 0)
                        continue;
                    a[k] = i;
                }
            }
        }

        public long nCrPFermet(int n , int r , long p){
            if(r==0)
                return 1l;
            

            

            

            

            long modInverseR = pow(fact[r] , p-2 , p);
            long modInverseNR = pow(fact[n-r] , p-2 , p);
            long w = (((fact[n]*modInverseR)%p)*modInverseNR)%p;
            return w;
        }
        public long pow(long a, long b, long m) {
            a %= m;
            long res = 1;
            while (b > 0) {
                long x = b&1;
                if (x == 1)
                    res = res * a % m;
                a = a * a % m;
                b >>= 1;
            }
            return res;
        }
        public long pow(long a, long b) {
            long res = 1;
            while (b > 0) {
                long x = b&1;
                if (x == 1)
                    res = res * a;
                a = a * a;
                b >>= 1;
            }
            return res;
        }
        public void sortedArrayToBST(TreeSet<Integer> a , int start, int end) { 
            if (start > end) {
                return;
            }
            int mid = (start + end) / 2;
            a.add(mid);
            sortedArrayToBST(a, start, mid - 1);
            sortedArrayToBST(a, mid + 1, end); 
        }
        public int lowerLastBound(ArrayList<Integer> a , int x){
            int l = 0;
            int r = a.size()-1;
            if(a.get(l)>=x)
                return -1;
            if(a.get(r)<x)
                return r;
            int mid = -1;
            while(l<=r){
                mid = (l+r)/2;
                if(a.get(mid) == x && a.get(mid-1)<x)
                    return mid-1;
                else if(a.get(mid)>=x)
                    r = mid-1;
                else if(a.get(mid)<x && a.get(mid+1)>=x)
                    return mid;
                else if(a.get(mid)<x && a.get(mid+1)<x)
                    l = mid+1;
            }
            return mid;
        }
        public int upperFirstBound(ArrayList<Integer> a , Integer x){
            int l = 0;
            int r = a.size()-1;
            if(a.get(l)>x)
                return l;
            if(a.get(r)<=x)
                return r+1;
            int mid = -1;
            while(l<=r){
                mid = (l+r)/2;
                if(a.get(mid) == x && a.get(mid+1)>x)
                    return mid+1;
                else if(a.get(mid)<=x)
                    l = mid+1;
                else if(a.get(mid)>x && a.get(mid-1)<=x)
                    return mid;
                else if(a.get(mid)>x && a.get(mid-1)>x)
                    r = mid-1;
            }
            return mid;
        }
        public int lowerLastBound(int a[] , int x){
            int l = 0;
            int r = a.length-1;
            if(a[l]>=x)
                return -1;
            if(a[r]<x)
                return r;
            int mid = -1;
            while(l<=r){
                mid = (l+r)/2;
                if(a[mid] == x && a[mid-1]<x)
                    return mid-1;
                else if(a[mid]>=x)
                    r = mid-1;
                else if(a[mid]<x && a[mid+1]>=x)
                    return mid;
                else if(a[mid]<x && a[mid+1]<x)
                    l = mid+1;
            }
            return mid;
        }
        public int upperFirstBound(long a[] , long x){
            int l = 0;
            int r = a.length-1;
            if(a[l]>x)
                return l;
            if(a[r]<=x)
                return r+1;
            int mid = -1;
            while(l<=r){
                mid = (l+r)/2;
                if(a[mid] == x && a[mid+1]>x)
                    return mid+1;
                else if(a[mid]<=x)
                    l = mid+1;
                else if(a[mid]>x && a[mid-1]<=x)
                    return mid;
                else if(a[mid]>x && a[mid-1]>x)
                    r = mid-1;
            }
            return mid;
        }
        public long log(float number , int base){
            return (long) Math.ceil((Math.log(number) / Math.log(base)) + 1e-9);
        }
        public long gcd(long a , long b){
            if(a<b){
                long c = b;
                b = a;
                a = c;
            }
            while(b!=0){
                long c = a;
                a = b;
                b = c%a;
            }
            return a;
        }
        public long[] gcdEx(long p, long q) {
            if (q == 0)
                return new long[] { p, 1, 0 };
            long[] vals = gcdEx(q, p % q);
            long d = vals[0];
            long a = vals[2];
            long b = vals[1] - (p / q) * vals[2];
            

            return new long[] { d, a, b };
        }
        public void sievePhi(int a[]){
            a[0] = 0;
            a[1] = 1;
            for(int i=2;i<a.length;i++)
                a[i] = i-1;
            for(int i=2;i<a.length;i++)
                for(int j = 2*i;j<a.length;j+=i)
                    a[j] -= a[i];
        }
        public void lcmSum(long a[]){
            int sievePhi[] = new int[(int)1e6 + 1];
            sievePhi(sievePhi);
            a[0] = 0;
            for(int i=1;i<a.length;i++)
                for(int j = i;j<a.length;j+=i)
                    a[j] += (long)i*sievePhi[i];
        }
    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
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

        public long nextLong() {
            return Long.parseLong(next());
        }

    }
}