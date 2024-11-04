import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.io.PrintStream;
import java.io.PrintWriter;
        
    public class Solution {

        public static boolean Local(){
            try{ 
                return System.getenv("LOCAL_SYS")!=null;
            }catch(Exception e){
                return false;
            }
        }   

        public static boolean LOCAL;

        static class FastScanner {

                BufferedReader br;
                StringTokenizer st ;

                FastScanner(){
                    br =  new BufferedReader(new InputStreamReader(System.in));
                    st = new StringTokenizer("");
                }

                FastScanner(String file) {

                    try{
                        br =  new BufferedReader(new InputStreamReader(new FileInputStream(file)));
                        st = new StringTokenizer("");
                    }catch(FileNotFoundException e) {
                        

                        System.out.println("file not found");
                        e.printStackTrace();
                    }
                    
                }
                

                String next() {
                    while (!st.hasMoreTokens())
                        try {
                            st = new StringTokenizer(br.readLine());
                        } catch (IOException e) {
                        }
                    return st.nextToken();
                }

                int nextInt() {
                    return Integer.parseInt(next());
                }

                long nextLong() {
                    return Long.parseLong(next());
                }
                String readLine() throws IOException{
                    return br.readLine();
                }
            }
                                
        static class Pair<T,X> {

            T first;
            X second;
            
            Pair(T first,X second){
                this.first = first;
                this.second = second;
            }

            @Override
            public int hashCode(){
                return Objects.hash(first,second);
            }

            @Override
            public boolean equals(Object obj){
                return obj.hashCode() == this.hashCode();
            }

        }


        static PrintStream debug = null;


        static class TreeNode{
            TreeNode left;
            TreeNode right;
            int l;
            int r;
            long gcd;
            TreeNode(int l,int r){
                this.l = l;
                this.r = r;
                this.gcd = 0;
                this.left = null;
                this.right = null;
            }
        }



        static long mod = (long)(Math.pow(10,9) + 7); 
        
        public static interface Operation {
		
            public long op(long a, long b);
        }
        
        public static class SegmentTree {
            
            int n;
            long base;
            long[] tree;
            Operation o;
            
            SegmentTree(long[] arr, Operation o, long base) {
                
                this.n = arr.length;
                this.base = base;
                this.o = o;
                build(arr);
            }
            
            public void build(long[] arr) {
                   tree = new long[2*n];
                   
                   for(int i  = 0; i<n; i++)
                       tree[n+i] = arr[i];
                   
                   for(int i = n-1; i>0; i--)
                       tree[i] = o.op(tree[2*i],tree[2*i+1]);
               
            }
            
            public void update(int in, int v) {
                
                tree[n+in] = v;
                int p = v/2;
                
                while(p>0) {
                    tree[p] = o.op(tree[2*p], tree[2*p+1]);
                    p/=2;
                }
                
            }
            
            public long query(int l, int r) {
                
                l+=n;
                r+=n;
                
                long res = base;
                
                while(l<=r) {
                    
                    if(l%2==1)
                      res = o.op(res, tree[l++]);
                    
                    if(r%2==0)
                      res = o.op(res, tree[r--]);
                    
                    l/=2;
                    r/=2;			
                    
                }
                
                return res;		
            }
            
        }



        public static void main(String[] args) throws Exception {

            PrintWriter out = new PrintWriter(System.out);


            FastScanner s = new FastScanner();

            LOCAL = Local();
            
            if(LOCAL){
                s = new FastScanner("src/input.txt");
                PrintStream o = new PrintStream("src/sampleout.txt");
                debug = new PrintStream("src/debug.txt");
                out = new PrintWriter(o,true);
                System.setOut(o);
            }

            
            long mod = 1000000007;
            
            int tcr = s.nextInt();     
        
            StringBuilder sb = new StringBuilder();

            int dx[] = {0,0,-1,1,1,-1,1,-1};
            int dy[] = {-1,1,0,0,1,1,-1,-1};
            
        
            for(int tc=0;tc<tcr;tc++){
                int n = s.nextInt();

                Long arr[] = new Long[n];
                
                for(int i=0;i<n;i++){
                    arr[i] = s.nextLong();
                }

                if(n <= 1){
                    out.println(1);
                    continue;
                }

                long req[] = new long[n-1];
            
                for(int i=1;i<n;i++){
                    req[i-1] =  Math.abs(arr[i] - arr[i-1]);
                }

                int ans = 1;

                int st = 0;

                int e = 0;

                long gcd = 0;
                
               

               SegmentTree stg = new SegmentTree(req, (a,b) -> gcd(a,b), 0);
               
               while(e < req.length){
                   gcd = stg.query(st, e);
                   while(st <= e && (gcd == 1)){
                       st++;
                       gcd = stg.query(st,e);
                   }
                   ans = Math.max(ans,e - st + 2);
                   e++;
               }

                out.println(ans);
            }

            out.flush();
            System.out.close();

            
            

        }

        public static TreeNode buildTree(int l,int r,List<Long> arr){
            
            if(l>r){return null;}

            if(l == r){
                TreeNode ans = new TreeNode(l,r);
                ans.gcd = arr.get(l);
                return ans;
            }

            TreeNode curr = new TreeNode(l,r);
            
            int mid = (l + r)/2;
            
            curr.left =  buildTree(l, mid, arr);
            
            curr.right = buildTree(mid+1,r, arr);
            
            long gcd = 0;
            
            if(curr.left != null){
                gcd = gcd(gcd,curr.left.gcd);
            }
            
            if(curr.right != null){
                gcd = gcd(gcd,curr.right.gcd);
            }

            curr.gcd = gcd;
            
            return curr;
        }

        public static long query(TreeNode node,int l,int r){
            
            if(l > r){
                return 0;
            }

            if(node.l == l && node.r == r){
                return node.gcd;
            }

            int mid = (node.l + node.r)/2;

            int ls = l;
            int le = Math.min(r,mid);
            int rs = Math.max(l,mid+1);
            int re = r;

            return gcd(query(node.left,ls,le),query(node.right,rs,re));
        }

        
        static long id3(int n, long sum,long arr[])
        {
            HashMap<Long, Integer> hm = new HashMap<>();
        
        
            for (int i = 0; i < n; i++) {
                
                if (!hm.containsKey(arr[i])){
                    hm.put(arr[i], 0);
                    }
        
                hm.put(arr[i], hm.get(arr[i]) + 1);
            }
            long id5 = 0;
            for (int i = 0; i < n; i++) {
                if (hm.get(sum - arr[i]) != null){
                    id5 += hm.get(sum - arr[i]);
                }
        
                
                if (sum - arr[i] == arr[i]){
                    id5--;
                }
            }
        
            

            return id5 / 2l;
        }
        public static long ncr(int n,int r,long fact[]){
            if(r==0){return 1l;}
            long ans = fact[n];
            long denom = mulmod(fact[r], fact[n-r], mod);
            ans = mulmod(ans,modpow(denom,mod-2, mod),mod);
            return ans;
        }

        public static List<long[]> id2(long n){

            List<long[]> list = new ArrayList<>();
            
            for(long i=2;i<=(Math.sqrt(n));i++){

                if(n % i == 0){
                    
                    int cnt = 0;
                    
                    while( (n % i) == 0){
                        n = n/i;
                        cnt++;
                        
                    }

                    list.add(new long[]{i,cnt});
                }
            }


            if(n!=1){
                list.add(new long[]{n,1l});
            }

            return list;

        }

        public static boolean check(int arr[]){
            for(int i=1;i<arr.length;i++){
                if(arr[i] < arr[i-1]){
                    return false;
                }
            }
            return true;
        }


        public static boolean inRange(int r1,int r2,int val){
            return ((val >= r1) && (val <= r2));
        }

        static int len(long num){
            return Long.toString(num).length();
        }

        static long mulmod(long a, long b,long mod)
        {
            long ans = 0l;
            
            while(b > 0l){
                long curr = (b & 1l);
                if(curr == 1l){
                    ans = ((ans % mod) + a) % mod;
                }
                
                a = (a + a) % mod;

                b = b >> 1;
            }

            return ans;
        }


        public static void dbg(PrintStream ps,Object... o) throws Exception{
            if(ps == null){
                return;
            }
            Debug.dbg(ps,o);
        }

        public static long modpow(long num,long pow,long mod){

            long val = num;
            long ans = 1l;

            while(pow > 0l){
                
                long bit = pow & 1l;

                if(bit == 1){
                    ans = (ans * (val%mod))%mod;
                }

                val = (val * val) % mod;
                pow = pow >> 1;
            }

            return ans;

        }

        public static char get(int n){
            return (char)('a' + n);
        }

        public static long[] sort(long arr[]){
            List<Long> list = new ArrayList<>();
            for(long n : arr){list.add(n);}
            Collections.sort(list);
            for(int i=0;i<arr.length;i++){
                arr[i] = list.get(i);
            }
            return arr;
        }

        public static int[] sort(int arr[]){
            List<Integer> list = new ArrayList<>();
            for(int n : arr){list.add(n);}
            Collections.sort(list);
            for(int i=0;i<arr.length;i++){
                arr[i] = list.get(i);
            }
            return arr;
        }

        

        

        

        public static int id0(long arr[],long num){
            

            int st = 0;
            int e = arr.length - 1;

            int ans = -1;

            while(st <= e){

                int mid = (st + e)/2;

                if(arr[mid] >= num){
                    e = mid - 1;
                }else{
                    ans = mid;
                    st = mid + 1;
                }

            }


            return ans + 1;

        }
        public static int id0(int arr[],int num){
            

            int st = 0;
            int e = arr.length - 1;

            int ans = -1;

            while(st <= e){

                int mid = (st + e)/2;

                if(arr[mid] >= num){
                    e = mid - 1;
                }else{
                    ans = mid;
                    st = mid + 1;
                }

            }


            return ans + 1;

        }
        
        

        


        public static int justGreater(long arr[],long num){
            int st = 0;
            int e = arr.length - 1;

            int ans = arr.length;

            while(st <= e){
                
                int mid = (st + e)/2;

                if(arr[mid] <= num){
                    st = mid + 1;
                }else{
                    ans = mid;
                    e = mid - 1;
                }
            }

            return ans;

        }

        public static int justGreater(int arr[],int num){
            int st = 0;
            int e = arr.length - 1;

            int ans = arr.length;

            while(st <= e){
                
                int mid = (st + e)/2;

                if(arr[mid] <= num){
                    st = mid + 1;
                }else{
                    ans = mid;
                    e = mid - 1;
                }
            }

            return ans;

        }

        

        public static void println(Object obj){
            System.out.println(obj.toString());
        }

        public static void print(Object obj){
            System.out.print(obj.toString());
        }

        public static int gcd(int a,int b){
            if(b == 0){return a;}
            return gcd(b,a%b);
        }

        public static long gcd(long a,long b){
            if(b == 0l){
                return a;
            }
            if(a==0l){
                return b;
            }

            return gcd(b,a%b);
        }

        public static int find(int parent[],int v){
            if(parent[v] == v){
                return v;
            }
            
            return parent[v] = find(parent, parent[v]);
        }



        public static List<Integer> sieve(){
        
                List<Integer> prime = new ArrayList<>();

                int arr[] = new int[300001];

            Arrays.fill(arr,1);

            arr[1] = 0;
            arr[2] = 1;

            for(int i=2;i<300001;i++){
                
                if(arr[i] == 1){
                    
                    prime.add(i);

                    for(long j = (i*1l*i);j<300001;j+=i){
                        arr[(int)j] = 0;
                    }
                }
            }

            return prime;
        }

        static boolean isPower(long n,long a){
            
            long log = (long)(Math.log(n)/Math.log(a));

            long power = (long)Math.pow(a,log);

            if(power == n){return true;}

            return false;
        }


        private static int id1(int[] arr, int l,int m, int r)
        {

            

            int[] left =  Arrays.copyOfRange(arr, l, m + 1);

            

            int[] right = Arrays.copyOfRange(arr, m + 1, r + 1);

            int i = 0, j = 0, k = l, swaps = 0;

            while (i < left.length && j < right.length) {
                if (left[i] <= right[j])
                    arr[k++] = left[i++];
                else {
                    arr[k++] = right[j++];
                    swaps += (m + 1) - (l + i);
                }
            }
            while (i < left.length)
                arr[k++] = left[i++];
            while (j < right.length)
                arr[k++] = right[j++];
            return swaps;
        }

        

        private static int id4(int[] arr, int l,int r)
        {

            

            

            int count = 0;

            if (l < r) {
                int m = (l + r) / 2;

                

                


                

                count += id4(arr, l, m);

                

                count += id4(arr, m + 1, r);

                

                count += id1(arr, l, m, r);
            }

            return count;
        }

        static class Debug{
            

            public static final boolean LOCAL = System.getProperty("ONLINE_JUDGE")==null;

            

            private static <T> String ts(T t) {
                if(t==null) {
                    return "null";
                }
                try {
                    return ts((Iterable) t);
                }catch(ClassCastException e) {
                    if(t instanceof int[]) {
                        String s = Arrays.toString((int[]) t);
                        return "{"+s.substring(1, s.length()-1)+"}\n";
                    }else if(t instanceof long[]) {
                        String s = Arrays.toString((long[]) t);
                        return "{"+s.substring(1, s.length()-1)+"}\n";
                    }else if(t instanceof char[]) {
                        String s = Arrays.toString((char[]) t);
                        return "{"+s.substring(1, s.length()-1)+"}\n";
                    }else if(t instanceof double[]) {
                        String s = Arrays.toString((double[]) t);
                        return "{"+s.substring(1, s.length()-1)+"}\n";
                    }else if(t instanceof boolean[]) {
                        String s = Arrays.toString((boolean[]) t);
                        return "{"+s.substring(1, s.length()-1)+"}\n";
                    }
                    try {
                        return ts((Object[]) t);
                    }catch(ClassCastException e1) {
                        return t.toString();
                    }
                }
            }
            private static <T> String ts(T[] arr) {
                StringBuilder ret = new StringBuilder();
                ret.append("{");
                boolean first = true;
                for(T t: arr) {
                    if(!first) {
                        ret.append(", ");
                    }
                    first = false;
                    ret.append(ts(t));
                }
                ret.append("}");
                return ret.toString();
            }
            private static <T> String ts(Iterable<T> iter) {
                StringBuilder ret = new StringBuilder();
                ret.append("{");
                boolean first = true;
                for(T t: iter) {
                    if(!first) {
                        ret.append(", ");
                    }
                    first = false;
                    ret.append(ts(t));
                }
                ret.append("}");
                return ret.toString();
            }
            public static void dbg(PrintStream ps,Object... o) throws Exception {
                if(LOCAL) {
                    System.setErr(ps);
                    System.err.print("Line 
                    for(int i = 0; i<o.length; i++) {
                        if(i!=0) {
                            System.err.print(", ");
                        }
                        System.err.print(ts(o[i]));
                    }
                    System.err.println("]");
                }
            }
    }

    }


    