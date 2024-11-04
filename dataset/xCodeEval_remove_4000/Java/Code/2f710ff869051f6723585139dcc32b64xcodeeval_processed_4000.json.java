import java.io.*;
import java.util.*;
import java.math.*;


public class AA {
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
        long mod = (long)(998244353);
        long fact[];
        int depth[];
        int parentTable[][];
        int degree[];
        ArrayList<Integer> leaves;
        int start=0;
        int end = 0;
        int length = Integer.MAX_VALUE;
        public void solve(int testNumber, InputReader in, PrintWriter out) throws IOException {
            while(testNumber-->0){
                int n = in.nextInt();
                int m = in.nextInt();
                int k = in.nextInt();
                ArrayList<ArrayList<Integer>> a = new ArrayList<>();
                for(int i=0;i<=n;i++)
                    a.add(new ArrayList<>());
                for(int i=0;i<m;i++){
                    int u = in.nextInt();
                    int v = in.nextInt();
                    a.get(u).add(v);
                    a.get(v).add(u);
                }
                depth = new int[n+1];
                int p[] = new int[n+1];
                dfs(a , 1 , 0 , new int[n+1] , p);
                

                

                leaves = new ArrayList<>();
                int index = end;
                while(index!=start){
                    leaves.add(index);
                    index = p[index];
                }
                leaves.add(start);
                

                if(length<=k-1 && length>=0){
                    out.println(2);
                    out.println(length+1);
                    for(int i=leaves.size()-1;i>=0;i--)
                        out.print(leaves.get(i) + " ");
                    out.println();
                }
                else if(length>=0 && length!=Integer.MAX_VALUE){
                    out.println(1);
                    int count = (k%2==0)?k/2:k/2+1;
                    for(int i=leaves.size()-1;i>=0 && count>0;i-=2){
                        out.print(leaves.get(i) + " ");
                        count--;
                    }
                    out.println();
                }
                else{
                    out.println(1);
                    int count = (k%2==0)?k/2:k/2+1;
                    int even = 0;
                    int odd = 0;
                    for(int i=1;i<=n;i++){
                        if(depth[i]%2 == 1){
                            odd++;
                        }
                        else
                            even++;
                    }
                    int rem = 1;
                    if(even>odd)
                        rem = 0;
                    for(int i=1;i<=n && count>0;i++){
                        if(depth[i]%2 == rem){
                            out.print(i + " ");
                            count--;
                        }
                    }
                    out.println();
                }
            }
        }

        public void dfs(ArrayList<ArrayList<Integer>> a , int index , int parent , int visited[] , int p[]){
            depth[index] = 1+depth[parent];
            p[index] = parent;
            visited[index] = 1;
            int l = a.get(index).size();
            

            

            

            

            

            for(int i=0;i<l;i++){
                if(a.get(index).get(i) == parent)
                    continue;
                if(visited[a.get(index).get(i)] == 1){
                    int x = Math.abs(depth[index] - depth[a.get(index).get(i)]);
                    if(x<length){
                        length = x;
                        start = a.get(index).get(i);
                        end = index;
                    }
                    continue;
                }
                dfs(a , a.get(index).get(i) , index , visited , p);
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
        public void id9(int a[][] , PrintWriter out){
            for(int i=0;i<a.length;i++){
                for(int j=0;j<a[i].length;j++)
                    out.print(a[i][j] + " ");
                out.println();
            }
            out.println();
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
        public int [][] matrixExpo(int c[][] , int n){
            int a[][] = new int[c.length][c[0].length];
            int b[][] = new int[a.length][a[0].length];
            for(int i=0;i<c.length;i++)
                for(int j=0;j<c[0].length;j++)
                    a[i][j] = c[i][j];
            for(int i=0;i<a.length;i++)
                b[i][i] = 1;
            while(n!=1){
                if(n%2 == 1){
                    b = matrixMultiply(a , a);
                    n--;
                }
                a = matrixMultiply(a , a);
                n/=2;
            }
            return matrixMultiply(a , b);
        }
        public int [][] matrixMultiply(int a[][] , int b[][]){
            int r1 = a.length;
            int c1 = a[0].length;
            int c2 = b[0].length;
            int c[][] = new int[r1][c2];
            for(int i=0;i<r1;i++){
                for(int j=0;j<c2;j++){
                    for(int k=0;k<c1;k++)
                        c[i][j] += a[i][k]*b[k][j];
                }
            }
            return c;
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
        public void swap(int a[] , int p1 , int p2){
            int x = a[p1];
            a[p1] = a[p2];
            a[p2] = x;
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
        public int id10(ArrayList<Integer> a , Integer x){
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
        public int id6(int a[] , int x){
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
        static class AVLTree{
            Node root;
            public AVLTree(){
                this.root = null;
            }
            public int height(Node n){
                return (n == null ? 0 : n.height);
            }
            public int getBalance(Node n){
                return (n == null ? 0 : height(n.left) - height(n.right));
            }
            public Node rotateRight(Node a){
                Node b = a.left;
                Node br = b.right;

                a.lSum -= b.lSum;
                a.lCount -= b.lCount;
                
                b.rSum += a.rSum;
                b.rCount += a.rCount;
                
                b.right = a;
                a.left = br;
                
                a.height = 1 + Math.max(height(a.left) , height(a.right));
                b.height = 1 + Math.max(height(b.left) , height(b.right));
                return b;
            }
            public Node rotateLeft(Node a){
                Node b = a.right;
                Node bl = b.left;
                
                a.rSum -= b.rSum;
                a.rCount -= b.rCount;
                
                b.lSum += a.lSum;
                b.lCount += a.lCount;
                
                b.left = a;
                a.right = bl;
                
                a.height = 1 + Math.max(height(a.left) , height(a.right));
                b.height = 1 + Math.max(height(b.left) , height(b.right));
                return b;
            }
            public Node insert(Node root , long value){
                if(root == null){
                    return new Node(value);
                }
                if(value<=root.value){
                    root.lCount++;
                    root.lSum += value;
                    root.left =  insert(root.left , value);
                }
                if(value>root.value){
                    root.rCount++;
                    root.rSum += value;
                    root.right = insert(root.right , value);
                }
                

                root.height = 1 + Math.max(height(root.left) , height(root.right));
                int balance = getBalance(root);

                

                if(balance>1 && value<=root.left.value)
                    return rotateRight(root);
                

                if(balance<-1 && value>root.right.value)
                    return rotateLeft(root);
                

                if(balance>1 && value>root.left.value){
                    root.left = rotateLeft(root.left);
                    return rotateRight(root);
                }
                

                if(balance<-1 && value<=root.right.value){
                    root.right = rotateRight(root.right);
                    return rotateLeft(root);
                }
                return root;
            }
            public void insertElement(long value){
                this.root = insert(root , value);
            }
            public int id11(long k){
                int count = 0;
                Node temp = root;
                while(temp!=null){
                    if(temp.value == k){
                        if(temp.left == null || temp.left.value<k){
                            count += temp.lCount;
                            return count-1;
                        }
                        else
                            temp = temp.left;
                    }
                    else if(temp.value>k){
                        temp = temp.left;
                    }
                    else{
                        count += temp.lCount;
                        temp = temp.right;
                    }
                }
                return count;
            }
            public void inorder(Node root , PrintWriter out){
                Node temp = root;
                if(temp!=null){
                    inorder(temp.left , out);
                    out.println(temp.value + " " + temp.lCount + " " + temp.rCount);
                    inorder(temp.right , out);
                }
            }
        }
        static class Node{
            long value;
            long lCount , rCount;
            long lSum , rSum;
            Node left , right;
            int height;
            public Node(long value){
                this.value = value;
                left = null;
                right = null;
                lCount = 1;
                rCount = 1;
                lSum = value;
                rSum = value;
                height = 1;
            }
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
