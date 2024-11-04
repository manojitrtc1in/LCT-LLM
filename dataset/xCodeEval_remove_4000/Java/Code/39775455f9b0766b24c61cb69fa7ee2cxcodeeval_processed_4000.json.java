import java.io.*;
import java.util.*;
import static java.lang.Math.*;


public class MarketingScheme {
    public static void main(String[] args) throws IOException {
        

        

        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskA solver = new TaskA();
        solver.solve(1, in, out);
        out.close();
    }
    static class TaskA {
        long mod = (long)(1e9) + 7;
        long fact[];
        int depth[];
        int parentTable[][];
        int degree[];
        ArrayList<Integer> leaves;
        int max = Integer.MIN_VALUE;
        int min = Integer.MAX_VALUE;
        int diam = 0;


        public void solve(int testNumber, InputReader in, PrintWriter out) throws IOException {
            while(testNumber-->0){
                long a[] = new long[6];
                for(int i=0;i<6;i++)
                    a[i] = in.nextLong();
                int n = in.nextInt();
                long b[] = new long[n];
                for(int i=0;i<n;i++)
                    b[i] = in.nextLong();
                

                Arrays.sort(a);
                Arrays.sort(b);
                ArrayList<Abc> c = new ArrayList<>();
                int count = 0;
                for(int j=0;j<n;j++){
                    for(int i=0;i<6;i++){
                        c.add(new Abc(abs(b[j] - a[i]) , j));
                    }
                }
                


                Collections.sort(c , (x , y) -> {
                    

                    return (int)(x.a - y.a);
                });

                

                


                int x[] = new int[n];
                count = 0;
                long ans = Long.MAX_VALUE;
                int i = 0;
                int j=0;
                while(i<c.size()){
                    

                    

                    if(count<n && j<c.size()){
                        x[(int)c.get(j).b]++;
                        if(x[(int)c.get(j).b] == 1)
                            count++;

                        if(count == n && c.get(j).a - c.get(i).a < ans){
                            ans = c.get(j).a - c.get(i).a;
                        }
                        

                        j++;
                    }
                    else{
                        if(count == n && c.get(j-1).a - c.get(i).a < ans){
                            ans = c.get(j-1).a - c.get(i).a;
                        }
                        x[(int)c.get(i).b]--;
                        if(x[(int)c.get(i).b] == 0)
                            count--;
                        i++;
                    }
                }
                out.println(ans);
            }
        }
        

        class Abc{
            long a;
            long b;
            public Abc(long a , long b){
                this.a = a;
                this.b = b;
            }
        }

        public int lower(ArrayList<Integer> a , int x){
            if(a.size() == 0)
                return 0;
            if(a.get(a.size()-1) < x)
                return a.size();
            int l = 0;
            int r = a.size()-1;
            while(l<=r){
                int mid = (l+r)>>1;
                if(a.get(mid)>=x && (mid<1 || a.get(mid-1)<x))
                    return mid;
                else if(a.get(mid) < x)
                    l = mid+1;
                else
                    r = mid-1;
            }
            return -1;
        }

        public Node left(Node x){
            if(x == null || x.empty)
                return x;
            Node y = left(x.left);
            x.left = y;
            return y;
        }

        public Node right(Node x){
            if(x == null || x.empty)
                return x;
            Node y = right(x.right);
            x.right = y;
            return y;
        }

        class Node{
            int val;
            Node left;
            Node right;
            boolean empty;
            public Node(int val){
                this.val = val;
                left = null;
                right = null;
                empty = true;
            }
        }

        public Node add(int a[] , int start , int end){
            if(start>end)
                return null;
            int mid = (start+end)>>1;
            Node root = new Node(a[mid]);
            root.left = add(a , start , mid-1);
            root.right = add(a ,mid+1 , end);
            return root;
        }

        public void dfs(ArrayList<ArrayList<int[]>> a , int index , int parent , int val , int visited[]){
            if(index == a.size()-1){
                max = Math.max(max , val);
                return;
            }
            visited[index] = 1;
            for(int i=0;i<a.get(index).size();i++){
                int u = index;
                int v = a.get(index).get(i)[0];
                int speed = a.get(index).get(i)[1];
                if(visited[v] == 1){
                    if(v == a.size()-1){
                        max = Math.max(max , Math.min(speed , val));
                    }
                    continue;
                }
                dfs(a , v , u , Math.min(val , speed) , visited);
            }
        }

        class Pair{
            int u;
            int v;
            public Pair(int u , int v){
                this.u = u;
                this.v = v;
            }
        }

        public void add(HashMap<Integer , ArrayList<Integer>> m , int x , int y){
            if(!m.containsKey(x))
                m.put(x , new ArrayList<>());
            ArrayList<Integer> a = m.get(x);
            a.add(y);
        }

        public void dfs(ArrayList<ArrayList<Integer>> a , int index , int parent , int size[]){
            size[index] = 1;
            depth[index] = 1+depth[parent];
            for(int i=0;i<a.get(index).size();i++){
                if(a.get(index).get(i) == parent)
                    continue;
                dfs(a , a.get(index).get(i) , index , size);
                size[index] += size[a.get(index).get(i)];
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

        

        public void id4(int a[] , PrintWriter out){
            for(int i=0;i<a.length;i++)
                out.print(a[i] + " ");
            out.println();
        }
        public void id4(long a[] , PrintWriter out){
            for(int i=0;i<a.length;i++)
                out.print(a[i] + " ");
            out.println();
        }
        public void id9(int a[][] , PrintWriter out){
            for(int i=0;i<a.length;i++){
                for(int j=0;j<a[i].length;j++)
                    out.print(a[i][j] + " ");
                out.println();
            }
            

        }
        public void id9(long a[][] , PrintWriter out){
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

        public long id0(int n , int r , long p){
            if(r==0)
                return 1l;
            

            

            

            

            long id8 = pow(fact[r] , p-2 , p);
            long id5 = pow(fact[n-r] , p-2 , p);
            long w = (((fact[n]*id8)%p)*id5)%p;
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
        public void id2(TreeSet<Integer> a , int start, int end) { 
            if (start > end) {
                return;
            }
            int mid = (start + end) / 2;
            a.add(mid);
            id2(a, start, mid - 1);
            id2(a, mid + 1, end); 
        }
        class Combine{
            int value;
            int delete;
            Combine(int val , int delete){
                this.value = val;
                this.delete = delete;
            }
        }
        class Sort2 implements Comparator<Combine>{
            public int compare(Combine a , Combine b){
                if(a.value > b.value)
                    return 1;
                else if(a.value == b.value && a.delete>b.delete)
                    return 1;
                else if(a.value == b.value && a.delete == b.delete)
                    return 0;
                return -1;
            }
        }
        public int id6(ArrayList<Integer> a , int x){
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
        public int id10(ArrayList<Integer> a , int x){
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
        public int id6(long a[] , long x){
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
        public int id10(long a[] , long x){
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
        public long[] id7(long p, long q) {
            if (q == 0)
                return new long[] { p, 1, 0 };
            long[] vals = id7(q, p % q);
            long d = vals[0];
            long a = vals[2];
            long b = vals[1] - (p / q) * vals[2];
            

            return new long[] { d, a, b };
        }
        public void id3(int a[]){
            a[0] = 0;
            a[1] = 1;
            for(int i=2;i<a.length;i++)
                a[i] = i-1;
            for(int i=2;i<a.length;i++)
                for(int j = 2*i;j<a.length;j+=i)
                    a[j] -= a[i];
        }
        public void id1(long a[]){
            int id3[] = new int[(int)1e6 + 1];
            id3(id3);
            a[0] = 0;
            for(int i=1;i<a.length;i++)
                for(int j = i;j<a.length;j+=i)
                    a[j] += (long)i*id3[i];
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