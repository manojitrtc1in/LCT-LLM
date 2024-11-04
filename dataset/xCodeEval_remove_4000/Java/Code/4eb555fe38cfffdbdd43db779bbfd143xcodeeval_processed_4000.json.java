import java.io.*;
import java.util.*;
import static java.lang.Math.*;


public class Era {
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
        long mod = (long)(1e9) + 7;
        long fact[];
        int depth[];
        int parentTable[][];
        int degree[];
        ArrayList<Integer> leaves;
        long max = Long.MIN_VALUE;
        long min = Long.MAX_VALUE;
        int diam = 0;

        int res = 0;
        int time = 0;

        long INF = (long)(1e17);
        long NINF = -INF;

        int r[] = {1 , 0 , -1 , 0};
        int c[] = {0 , 1 , 0 , -1};
        


        public void solve(int testNumber, InputReader in, PrintWriter out) throws IOException {
            while(testNumber-->0){
            	

            	int n = in.nextInt();
                int a[] = new int[n];
                for(int i=0;i<n;i++)
                    a[i] = in.nextInt();
                if(n%2 == 0)
                    out.println("YES");
                else{
                    boolean found = false;
                    for(int i=0;i<n-1;i++){
                        if(a[i]>=a[i+1])
                            found = true;
                    }
                    if(found)
                        out.println("YES");
                    else
                        out.println("NO");
                }
            }
        }

        public ArrayList<Integer> id12(int a[][] , long dist[] , int parent[]){
        	ArrayList<Integer> ans = new ArrayList<>();
        	int index = -1;
        	for(int i=1;i<dist.length-1;i++){
        		for(int e[] : a){
        			int u = e[0];
        			int v = e[1];
        			int w = e[2];
        			if(dist[u] == INF)
        				continue;
        			if(dist[v] > dist[u] + w){
        				dist[v] = NINF;
        				parent[v] = u;
        				index = v;
        			}
        		}
        	}

        	if(index != -1){
        		ans.add(index);
        		int x = ans.get(0);
        		while(true){
        			x = parent[x];
        			ans.add(x);
        			if(x == ans.get(0))
        				break;
        		}
        	}
        	return ans;
        }

        public long[] id0(int a[][] , int n , int parent[]){
        	long dist[] = new long[n+1];
        	Arrays.fill(dist , INF);
        	dist[1] = 0;
        	for(int count = 1;count<n;count++){
	        	for(int i=0;i<a.length;i++){
	        		int u = a[i][0];
	        		int v = a[i][1];
	        		int w = a[i][2];
	        		if(dist[u] == INF)
	        			continue;
	        		if(dist[v] > dist[u] + w){
	        			dist[v] = dist[u] + w;
	        			parent[v] = u;
	        			

	        		}
	        	}
	        }
        	return dist;
        }

        public void mergeSort(long a[][] , int start , int end){
        	if(end<=start)
        		return;
        	int mid = (start+end)>>1;
        	mergeSort(a , start , mid);
        	mergeSort(a , mid+1 , end);
        	merge(a , start , mid , end);
        }

        public void merge(long a[][] , int start , int mid , int end){
        	int n = a.length;
        	long l[][] = new long[mid-start+1][a[0].length];
        	long r[][] = new long[end-mid][a[0].length];

        	for(int i=0;i<l.length;i++){
        		

        		copy(l[i] , a[start+i]);
        	}
        	for(int i=0;i<r.length;i++){
        		

        		copy(r[i] , a[i+mid+1]);
        	}
        	int i = 0;
        	int j = 0;
        	int k = start;
        	while(i<l.length && j<r.length){
        		if(l[i][0] <= r[j][0]){
        			

        			copy(a[k] , l[i]);
        			k++;
        			i++;
        		}
        		else{
        			

        			copy(a[k] , r[j]);
        			k++;
        			j++;
        		}
        	}
        	while(i<l.length){
        		

        		copy(a[k] , l[i]);
        		k++;
        		i++;
        	}
        	while(j<r.length){
        		

        		copy(a[k] , r[j]);
        		k++;
        		j++;
        	}
        }

        public void copy(long a[] , long b[]){
        	for(int i=0;i<b.length;i++)
        		a[i] = b[i];
        }

        public void mergeSort(long a[] , int start , int end){
        	if(end<=start)
        		return;
        	int mid = (start+end)>>1;
        	mergeSort(a , start , mid);
        	mergeSort(a , mid+1 , end);
        	merge(a , start , mid , end);
        }

        public void merge(long a[] , int start , int mid , int end){
        	int n = a.length;
        	long l[] = new long[mid-start+1];
        	long r[] = new long[end-mid];
        	for(int i=0;i<l.length;i++){
        		l[i] = a[start+i];
        	}
        	for(int i=0;i<r.length;i++){
        		r[i] = a[i+mid+1];
        	}
        	int i = 0;
        	int j = 0;
        	int k = start;
        	while(i<l.length && j<r.length){
        		if(l[i] <= r[j]){
        			a[k++] = l[i++];
        		}
        		else{
        			a[k++] = r[j++];
        		}
        	}
        	while(i<l.length){
        		a[k++] = l[i++];
        	}
        	while(j<r.length){
        		a[k++] = r[j++];
        	}
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

        

        public void id5(int a[] , PrintWriter out){
            for(int i=0;i<a.length;i++)
                out.print(a[i] + " ");
            out.println();
        }
        public void id5(boolean a[] , PrintWriter out){
            for(int i=0;i<a.length;i++)
                out.print(a[i] + " ");
            out.println();
        }
        public void id5(long a[] , PrintWriter out){
            for(int i=0;i<a.length;i++)
                out.print(a[i] + " ");
            out.println();
        }
        public void id10(int a[][] , PrintWriter out){
            for(int i=0;i<a.length;i++){
                for(int j=0;j<a[i].length;j++)
                    out.print(a[i][j] + " ");
                out.println();
            }
            

        }
        public void id10(long a[][] , PrintWriter out){
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

        public long id1(int n , int r , long p){
            if(r==0)
                return 1l;
            

            

            

            

            long id9 = pow(fact[r] , p-2 , p);
            long id6 = pow(fact[n-r] , p-2 , p);
            long w = (((fact[n]*id9)%p)*id6)%p;
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
        public void id3(TreeSet<Integer> a , int start, int end) { 
            if (start > end) {
                return;
            }
            int mid = (start + end) / 2;
            a.add(mid);
            id3(a, start, mid - 1);
            id3(a, mid + 1, end); 
        }

        public int id7(ArrayList<Integer> a , int x){
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
        public int id11(ArrayList<Integer> a , int x){
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
        public int id7(long a[] , long x){
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
        public int id11(long a[] , long x){
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
        public long[] id8(long p, long q) {
            if (q == 0)
                return new long[] { p, 1, 0 };
            long[] vals = id8(q, p % q);
            long d = vals[0];
            long a = vals[2];
            long b = vals[1] - (p / q) * vals[2];
            

            return new long[] { d, a, b };
        }
        public void id4(int a[]){
            a[0] = 0;
            a[1] = 1;
            for(int i=2;i<a.length;i++)
                a[i] = i-1;
            for(int i=2;i<a.length;i++)
                for(int j = 2*i;j<a.length;j+=i)
                    a[j] -= a[i];
        }
        public void id2(long a[]){
            int id4[] = new int[(int)1e6 + 1];
            id4(id4);
            a[0] = 0;
            for(int i=1;i<a.length;i++)
                for(int j = i;j<a.length;j+=i)
                    a[j] += (long)i*id4[i];
        }
    }

    static class Reader {
        final private int BUFFER_SIZE = 1 << 16;
        private DataInputStream din;
        private byte[] buffer;
        private int bufferPointer, bytesRead;
 
        public Reader()
        {
            din = new DataInputStream(System.in);
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }
 
        public Reader(String file_name) throws IOException
        {
            din = new DataInputStream(
                new FileInputStream(file_name));
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }

        public String next() throws IOException
        {
            byte[] buf = new byte[64]; 

            int cnt = 0, c;
            while ((c = read()) != -1) {
                if (c == ' ' || c == '\n') {
                    if (cnt != 0) {
                        break;
                    }
                    else {
                        continue;
                    }
                }
                buf[cnt++] = (byte)c;
            }
            return new String(buf, 0, cnt);
        }
 
        public String nextLine() throws IOException
        {
            byte[] buf = new byte[64]; 

            int cnt = 0, c;
            while ((c = read()) != -1) {
                if (c == '\n') {
                    if (cnt != 0) {
                        break;
                    }
                    else {
                        continue;
                    }
                }
                buf[cnt++] = (byte)c;
            }
            return new String(buf, 0, cnt);
        }
 
        public int nextInt() throws IOException
        {
            int ret = 0;
            byte c = read();
            while (c <= ' ') {
                c = read();
            }
            boolean neg = (c == '-');
            if (neg)
                c = read();
            do {
                ret = ret * 10 + c - '0';
            } while ((c = read()) >= '0' && c <= '9');
 
            if (neg)
                return -ret;
            return ret;
        }
 
        public long nextLong() throws IOException
        {
            long ret = 0;
            byte c = read();
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)
                c = read();
            do {
                ret = ret * 10 + c - '0';
            } while ((c = read()) >= '0' && c <= '9');
            if (neg)
                return -ret;
            return ret;
        }
 
        public double nextDouble() throws IOException
        {
            double ret = 0, div = 1;
            byte c = read();
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)
                c = read();
 
            do {
                ret = ret * 10 + c - '0';
            } while ((c = read()) >= '0' && c <= '9');
 
            if (c == '.') {
                while ((c = read()) >= '0' && c <= '9') {
                    ret += (c - '0') / (div *= 10);
                }
            }
 
            if (neg)
                return -ret;
            return ret;
        }
 
        private void fillBuffer() throws IOException
        {
            bytesRead = din.read(buffer, bufferPointer = 0,
                                 BUFFER_SIZE);
            if (bytesRead == -1)
                buffer[0] = -1;
        }
 
        private byte read() throws IOException
        {
            if (bufferPointer == bytesRead)
                fillBuffer();
            return buffer[bufferPointer++];
        }
 
        public void close() throws IOException
        {
            if (din == null)
                return;
            din.close();
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