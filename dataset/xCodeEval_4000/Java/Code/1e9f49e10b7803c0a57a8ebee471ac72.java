 import java.util.*; 
                                    import java.math.*;
                                    import java.io.*;
                                    import java.text.DecimalFormat;
                                    import java.math.BigInteger;
                                    public class Main{
                                        

                                        static long mod=1000000007 ;
                                        
                                        static ArrayList<ArrayList<Edge>> arr;
                                       

                                        static int[] a;
                                        static int[] vis,num;
                                        static long max;
                                        static HashSet<String> hs;
                                        

                                        static long max1,max2,ans1;
                                        
                                        static int flag=0;
                                        static int[] tin,tout,parent,level;
                                        static HashMap<Long,Integer> hm;
                                        static long[] dp1,dp2,dp3,dp4;
                                        static int ct=0;
                                           
                                        public static void main(String[] args)  throws IOException {
                                            

                                            boolean online =false;
                                            String fileName = "A-large (4)";
                                            PrintWriter out; 
                                            if (online) {
                                                s.init(new FileInputStream(new File(fileName + ".in")));
                                                 out= new PrintWriter(new FileWriter(fileName + "out.txt"));
                                            }
                                             else {
                                                s.init(System.in);   
                                            
                                                out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
                                                

                                            }

                                            int n=s.ni();
                                            int c=s.ni();
                                            int d=s.ni();
                                            PriorityQueue<item> pq1=new PriorityQueue<>();
                                            PriorityQueue<item> pq2=new PriorityQueue<>();
                                        
                                            for(int i=0;i<n;i++){
                                                int x=s.ni();
                                                int y=s.ni();
                                                char ch=s.ns().charAt(0);
                                                if(ch=='C')
                                                    pq1.add(new item(i,x,y));
                                                else
                                                    pq2.add(new item(i,x,y));
                                            }
                                            while(pq1.size()>0 && pq1.peek().cost>c)
                                                pq1.poll();
                                            while(pq2.size()>0 && pq2.peek().cost>d)
                                                pq2.poll();
                                            int max=0;
                                            if(pq1.size()>0 && pq2.size()>0)
                                                max=pq1.peek().beauty+pq2.peek().beauty;
                                            int n1=pq1.size();
                                            int n2=pq2.size();
                                            ArrayList<item> arr1=new ArrayList<>();
                                            ArrayList<item> arr2=new ArrayList<>();
                                            
                                            for(int i=0;i<n1;i++){
                                                arr1.add(pq1.poll());
                                            }
                                            for(int i=0;i<n2;i++){
                                                arr2.add(pq2.poll());
                                            }
                                            Collections.sort(arr1,(x,y)->x.cost-y.cost);
                                            Collections.sort(arr2,( x, y)-> x.cost-y.cost);
                                            int t = 1;
                                            while ((1 << t) <= n1) {
                                                t++;
                                            }
                                            
                                            int[][] maxx = new int[n1][t];
                                            for (int i = 0; i < n1; i++) {
                                                maxx[i][0] = arr1.get(i).beauty;
                                            }
                                            for (int j = 1; 1<<j <=n1; j++) {
                                                for (int i = 0; i + (1 << j) -1<n1; i++) {
                                                    
                                                    maxx[i][j] = Math.max(maxx[i][j - 1], maxx[i + (1 << (j - 1))][j - 1]);
                                                }
                                            }
                                            for(int i=0;i<n1;i++){
                                                int curr=arr1.get(i).cost;
                                                if(curr>c)
                                                    break;
                                                int bt=arr1.get(i).beauty;
                                                int l=i+1;
                                                int h=n1-1;
                                                while(l<h){
                                                    int mid=(l+h+1)/2;
                                                    if(arr1.get(mid).cost+curr<=c){
                                                        l=mid;
                                                    }
                                                    else
                                                        h=mid-1;
                                                }
                                                if(l<n1 && arr1.get(l).cost+curr<=c){
                                                        int id1=i+1;
                                                        int id2=l;
                                                
                                                    int j = 0;
                                                    while ((1 << (j + 1))-1 <=id2-id1) {
                                                        j++;
                                                    }
                                                    
                                                    int mx = Math.max(maxx[id1][j], maxx[id2 - (1 << j)+1][j]);
                                                    max=Math.max(max,mx+bt);
                                                }
                
                                            }
                                            t = 1;
                                            while ((1 << t) <= n2) {
                                                t++;
                                            }
                                            
                                            maxx = new int[n2][t];
                                            for (int i = 0; i < n2; i++) {
                                                maxx[i][0] = arr2.get(i).beauty;
                                            }
                                            for (int j = 1; 1<<j <=n2; j++) {
                                                for (int i = 0; i + (1 << j) -1<n2; i++) {
                                                    
                                                    maxx[i][j] = Math.max(maxx[i][j - 1], maxx[i + (1 << (j - 1))][j - 1]);
                                                }
                                            }
                                            for(int i=0;i<n2;i++){
                                                int curr=arr2.get(i).cost;
                                                int bt=arr2.get(i).beauty;
                                                if(curr>d)
                                                    break;
                                                int l=i+1;
                                                int h=n2-1;

                                                while(l<h){
                                                    int mid=(l+h+1)/2;
                                                    if(arr2.get(mid).cost+curr<=d){
                                                        l=mid;
                                                    }
                                                    else
                                                        h=mid-1;
                                                }

                                                if(l<arr2.size() && arr2.get(l).cost+curr<=d){
                                                        int id1=i+1;
                                                        int id2=l;
                                                    
                                                    int j = 0;
                                                    while ((1 << (j + 1))-1 <=id2-id1) {
                                                        j++;
                                                    }
                                                    
                                                    int mx = Math.max(maxx[id1][j], maxx[id2 - (1 << j)+1][j]);
                                                    max=Math.max(max,mx+bt);
                                                }
                
                                            }
                                            out.println(max);

                                            out.close();    
                                    
                                        }   
                                      
                                     
                                        public static int gcd(int a, int b){
                                                if (a == 0) return b;
                                                return gcd(b % a, a);
                                        }
                                            
                                        public static void cfs(ArrayList<HashSet<Integer>> arr,int c,int p,int g,int[] vis){
                                            vis[c]=1;
                                            if(g!=-1){
                                                if(!arr.get(c).contains(g)){
                                                    flag=1;
                                                    return;
                                                }
                                            }
                                            for(int x:arr.get(c)){
                                                if(x!=p && x!=g && vis[x]==0 ){
                                                    cfs(arr,x,c,p,vis);
                                                }
                                            }
 
                                        }
                                                              

         

         

         

         

         

         

         

         

         

         

         

         

         

         

                                     

                                        public static int lca(int[][] p,int a,int b){
                                            if(level[a]<level[b]){
                                                int x=a;
                                                a=b;
                                                b=x;
                                            }
                                            int log=p[0].length;
                                            for(int i=log-1;i>=0;i--){
                                                if(1<<i<=level[a]-level[b]){
                                                    a=p[a][i];
                                                }
                                            }
                                            if(a==b)
                                                return a;
                                            for(int i=log-1;i>=0;i--){
                                                if(p[a][i]!=p[b][i]){
                                                    a=p[a][i];
                                                    b=p[b][i];
                                                }
                                            }
                                            return p[a][0];
         
                                        }
                                        public static int[][] par(int[] parent){
                                            int n=arr.size();
                                            int[][] p=new int[n][17];
                                            for(int i=0;i<n;i++)
                                                p[i][0]=parent[i];
                                            for(int k=1;k<17;k++){
                                                for(int i=0;i<n;i++){
                                                    if(p[i][k-1]>-1)
                                                        p[i][k]=p[p[i][k-1]][k-1];
                                                    else
                                                        p[i][k]=-1;
                                                }
                                            }
                                            return p;
                                        }
                                        static class Edge {
                                               int from;
                                                int to;
                                                int cost;
                                        
                                               public Edge(int from, int to, int weight) {
                                                   this.from = from;
                                                   this.to = to;
                                                   this.cost= weight;
                                               }
                                        }                               
                                        static class Node {
                                            int start;
                                            int end;
                        
                                            int cost;
                                            int updated;
                        
                                            Node[] nodes;
                        
                                            public Node(int start, int end) {
                                                this.start = start;
                                                this.end = end;
                        
                                                if (start < end) {
                                                    int[] pos = {start, (start + end) / 2, end};
                                                    nodes = new Node[2];
                                                    for (int i = 0; i < 2; i++) {
                                                        nodes[i] = new Node(pos[i] + i, pos[i + 1]);
                                                    }
                                                }
                                            }
                        
                                            public void update(int queryStart, int queryEnd, int value) {
                                                if (queryEnd < start || end < queryStart) {
                                                    return;
                                                }
                        
                                                if (queryStart <= start && end <= queryEnd) {
                                                    cost += value;
                                                    updated += value;
                                                    return;
                                                }
                        
                                                propagate();
                                                for (Node node: nodes) {
                                                    node.update(queryStart, queryEnd, value);
                                                }
                                            }
                        
                                            public int query(int pos) {
                                                if (pos < start || end < pos) {
                                                    return 0;
                                                }
                        
                                                if (start == end) {
                                                    return cost;
                                                }
                        
                                                propagate();
                                                int ans = 0;
                                                for (Node node: nodes) {
                                                    ans = Math.max(ans, node.query(pos));
                                                }
                                                return ans;
                                            }
                        
                                            public void propagate() {
                                                if (updated != 0 && start < end) {
                                                    for (Node node: nodes) {
                                                        node.cost += updated;
                                                        node.updated += updated;
                                                    }
                                                    updated = 0;
                                                }
                                            }
                                        }
                                        public static double nthroot(int n, double A) {
                                            return nthroot(n, A, 0.00000000000001);
                                        }
                                        public static double nthroot(int n, double A, double p) {
                                            if(A < 0) {
                                                System.err.println("A < 0");

                                                return -1;
                                            } else if(A == 0) {
                                                return 0;
                                            }
                                            double x_prev = A;
                                            double x = A / n;  

                                            while(Math.abs(x - x_prev) > p) {
                                                x_prev = x;
                                                x = ((n - 1.0) * x + A / Math.pow(x, n - 1.0)) / n;
                                            }
                                            return x;
                                        }
                                        
                                        static class item implements Comparable<item> {
                                            int beauty,cost,id;
                                            public item(int x,int y,int z){
                                                id=x;
                                                beauty=y;
                                                cost=z;
                                                
                                            }
                                            public int compareTo(item o){
                                                return  o.beauty-beauty;
                                            }
                                            
                                        }
                                       
                                        public static void dfs2(int c,int p,int[] a){
                                            

                                           
                                            
                                            
                 
                                        }
        

                                        

                                        

                                        

                                        

                                        

                                        

                                        

                                        

                                        

                 

                                        

                                        public static long gcd(long a, long b){
                                                if (a == 0) return b;
                                                return gcd(b % a, a);
                                        }
                                            
                                        public static boolean check(long x){
                                            if(x%4==0 || x%7==0 || x%11==0)
                                                return true;
                                            if(x<4 || x<7 || x<11)
                                                return false;
                                            if(x%2==0){
                                                return check(x/2);
                                            }
                                            else
                                                return check(x/2) && check((x+1)/2);
                                        }
                                        public static int angle(int x1,int x2,int x3,int y1,int y2,int y3){
                                            long val=(y2-y1)*1L*(x3-x2)-(y3-y2)*1L*(x2-x1);
                                            if(val<0)
                                                return 1;
                                            else if(val>0)
                                                return -1;
                                            else
                                                return 0;
                                        }
                                        
                                        static class BIT{
                                        
                                            int N;
                                            long tree[];
                                            
                                            BIT(int N){
                                                this.N = N;
                                                tree = new long[N + 1];
                                            }
                                            
                                            void update(int idx,long val){
                                                while(idx <= N){
                                                    tree[idx]+=val;
                                                    idx += (idx & -idx);
                                                }
                                            }
                                            
                                            long query(int l,int r){
                                                if(l == 1)
                                                    return read(r);
                                                else
                                                    return read(r) - read(l-1);
                                            }
                                            
                                            long read(int idx){
                                                long sum = 0;
                                                while(idx > 0){
                                                    sum += tree[idx];
                                                    idx -= (idx & -idx);
                                                }
                                                return sum;
                                            }
                                        }
                                        public static boolean pal(String a){
                                            int i=0;
                                            int j=a.length()-1;
                                            while(i<j){
                                                if(a.charAt(i)!=a.charAt(j)){
                                                    return false;
                                                }
                                                i++;
                                                j--;
                                            }
                                            return true;
                                                
                                        }
                                        public static long find(long n,long k){
                                            if(n==2){
                                                if(k==1 || k==3)
                                                    return 1;
                                                else
                                                    return 2;
                                            }
                                            long t=pow2(2,n,mod)-1;
                                            long z=(t+1)/2;
                                            if(k==z)
                                                return n;
                                            if(k<z)
                                                return find(n-1,k);
                                            else
                                                return find(n-1,k-z);
                                        }
                                        public static long pow2(long a,long b,long mod){
                                                
                                                long ans=1;
                                               

                                                while(b>0){
                                                   
                                                    if(b%2==1)
                                                        ans=(a*ans)%mod;
                                                    a=(a*a)%mod;
                                                    b/=2;
                                                }
                                              
                                                return  ans;
                                        }
                                         public static long pow3(long a,long b){
                                                
                                                long ans=1;
                                               

                                                while(b>0){
                                                   
                                                    if(b%2==1)
                                                        ans=(a*ans);
                                                    a=(a*a);
                                                    b/=2;
                                                }
                                              
                                                return  ans;
                                        }
                                        public static long fib(long n){
                                            long[][]    f=new long[][]{{1L,1L},{1L,0}};
                                            if(n==0)
                                                return 0;
                                            f=arrpow(f,n-1);
                                            return f[0][0];
                                        }
                                        public static long[][] arrpow(long[][] a,long b){
                                           
                                                int n=a.length;
                                              

                                                long[][] ans=new long[n][n];
                                                for(int i=0;i<n;i++)
                                                    ans[i][i]=1L;
                                                while(b>0){
                                                    
                                                    if(b%2==1)
                                                        ans=mul(a,ans);
                                                    a=mul(a,a);
                                                    b/=2;
                                                }
                                                
                                                return  ans;
                                        }
                                        public static long[][] mul(long[][] a,long[][] b){
                                            int n=a.length;
                                            int m=b[0].length;
                                            long[][] ans=new long[n][m];
                                            if(n==2 && m==2 && b.length==2){
                                                ans[0][0]=((a[0][0]*b[0][0])%mod+(a[0][1]*b[1][0]))%mod;
                                                ans[0][1]=((a[0][0]*b[0][1])%mod+(a[0][1]*b[1][1]))%mod;
                                                ans[1][0]=((a[1][0]*b[0][0])%mod+(a[1][1]*b[1][0]))%mod;
                                                ans[1][1]=((a[1][1]*b[1][1])%mod+(a[1][0]*b[0][1]))%mod;
                                                return ans;
             
                                            }
                                            for(int i=0;i<n;i++){
                                                for(int j=0;j<m;j++){
                                                    for(int k=0;k<b.length;k++){
                                                        ans[i][j]=(ans[i][j]+(a[i][k]*b[k][j])%mod)%mod;
                                                    }
                                                }
                                            }
                                            return ans; 
                                        }
                                         static class name implements Comparable<name> {
                                            long l,b,h;
                                            public name(long   x,long y,long z){
                                                {
                                                    l=x;
                                                    b=y;        
                                                }
                                                
                                                
                                                h=z;
                                            }
                                            public int compareTo(name o){
                                                return -(int)(l*b-o.l*o.b);
                                            }
                                            
                                        }
                                        public static class s {
                                            static BufferedReader reader;
                                            static StringTokenizer tokenizer;
                                        
                                            
                                            static void init(InputStream input) {
                                                reader = new BufferedReader(
                                                            new InputStreamReader(input) );
                                                tokenizer = new StringTokenizer("");
                                            }   
                                        
                                            
                                            static String ns() throws IOException {
                                                while ( ! tokenizer.hasMoreTokens() ) {
                                                    

                                                    tokenizer = new StringTokenizer(
                                                        reader.readLine() );
                                                }
                                                return tokenizer.nextToken();
                                            }
                                        
                                            static int ni() throws IOException {
                                                return Integer.parseInt( ns() );
                                            }
                                        
                                            static double nd() throws IOException {
                                                return Double.parseDouble( ns() );
                                            }
                                            static long nl() throws IOException {
                                                return Long.parseLong( ns() );
                                            }
                                        }
                                    }   