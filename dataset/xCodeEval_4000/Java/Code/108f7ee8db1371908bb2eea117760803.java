
import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.math.RoundingMode;
import java.util.*;
import java.util.concurrent.LinkedBlockingDeque;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;







public class scratch_25{
    static class Graph{

        public static class Vertex{
            HashMap<Integer,Integer> nb= new HashMap<>();     

        }

        public static HashMap<Integer,Vertex> vt;   


        public Graph(){
            vt= new HashMap<>();
        }

        public static int numVer(){
            return vt.size();
        }

        public static boolean contVer(int ver){
            return vt.containsKey(ver);
        }

        public static void addVer(int ver){
            Vertex v= new Vertex();
            vt.put(ver,v);
        }






        public static void addEdge(int ver1, int ver2, int weight){
            if(!vt.containsKey(ver1) || !vt.containsKey(ver2)){
                return;
            }
            Vertex v1= vt.get(ver1);
            Vertex v2= vt.get(ver2);
            v1.nb.put(ver2,weight);                                 

            v2.nb.put(ver1,weight);
        }

        public static void delEdge(int ver1, int ver2){

            if(!vt.containsKey(ver1) || !vt.containsKey(ver2)){
                return;
            }
            vt.get(ver1).nb.remove(ver2);
            vt.get(ver2).nb.remove(ver1);
        }
        public static void delVer(int ver){
            if(!vt.containsKey(ver)){
                return;
            }
            Vertex v1= vt.get(ver);
            ArrayList<Integer> arr= new ArrayList<>(v1.nb.keySet());
            for (int i = 0; i <arr.size() ; i++) {
                int s= arr.get(i);
                vt.get(s).nb.remove(ver);
            }
            vt.remove(ver);
        }
        static boolean done[];
        static int parent[];
        static ArrayList<Integer>vals= new ArrayList<>();


        public static boolean isCycle(int i){
            Stack<Integer>stk= new Stack<>();

            stk.push(i);
            while(!stk.isEmpty()){
                int x= stk.pop();
                vals.add(x);
                

                if(!done[x]){
                    done[x]=true;
                }
                else if(done[x] ){
                    return true;
                }

                ArrayList<Integer>ar= new ArrayList<>(vt.get(x).nb.keySet());
                for (int j = 0; j <ar.size() ; j++) {
                    if(parent[x]!=ar.get(j)){
                        parent[ar.get(j)]=x;
                        stk.push(ar.get(j));
                    }
                }
                

            }
            return false;
        }
        static int[]level;
        static int[] curr;
        static int[] fin;

        public static void dfs(int src){
            done[src]=true;
            level[src]=0;
            Queue<Integer>q= new LinkedList<>();
            q.add(src);
            while(!q.isEmpty()){
                int x= q.poll();
                ArrayList<Integer>arr= new ArrayList<>(vt.get(x).nb.keySet());
                for (int i = 0; i <arr.size() ; i++) {
                    int v= arr.get(i);
                    if(!done[v]){
                        level[v]=level[x]+1;
                        done[v]=true;
                        q.offer(v);
                    }
                }
            }
        }
        static int oc[];
        static int ec[];


        public static void dfs1(int src){
            Queue<Integer>q= new LinkedList<>();
            q.add(src);
            done[src]= true;
            

            while(!q.isEmpty()){

                int x= q.poll();
                

                int even= ec[x];
                int odd= oc[x];
                if(level[x]%2==0){
                    int val= (curr[x]+even)%2;
                    if(val!=fin[x]){
                        

                        even++;
                        vals.add(x);
                    }
                }
                else{
                    int val= (curr[x]+odd)%2;
                    if(val!=fin[x]){
                        

                        odd++;
                        vals.add(x);
                    }

                }
                ArrayList<Integer>arr= new ArrayList<>(vt.get(x).nb.keySet());
                

                for (int i = 0; i <arr.size() ; i++) {
                    int v= arr.get(i);
                    if(!done[v]){
                        done[v]=true;
                        oc[v]=odd;
                        ec[v]=even;
                        q.add(v);
                    }
                }
            }

        }

        static long popu[];
        static long happy[];
        static long count[]; 

        static long sum[]; 



        public static void bfs(int x){
            done[x]=true;
            long total= popu[x];


            ArrayList<Integer>nbrs= new ArrayList<>(vt.get(x).nb.keySet());
            for (int i = 0; i <nbrs.size() ; i++) {
                int r= nbrs.get(i);
                if(!done[r]){
                    bfs(r);
                    total+=count[r];


                }
            }
            count[x]=total;


        }


        public static void bfs1(int x){
            done[x]=true;


            long smile= 0;
            ArrayList<Integer>nbrs= new ArrayList<>(vt.get(x).nb.keySet());
            for (int i = 0; i <nbrs.size() ; i++) {
                int r= nbrs.get(i);
                if(!done[r]){
                    bfs1(r);


                    smile+=happy[r];
                }
            }


            sum[x]=smile;
        }


    }




    static class Reader {
        static BufferedReader reader;
        static StringTokenizer tokenizer;

        
        static void init(InputStream input) {
            reader = new BufferedReader(
                    new InputStreamReader(input));
            tokenizer = new StringTokenizer("");
        }

        
        static String next() throws IOException {
            while (!tokenizer.hasMoreTokens()) {
                

                tokenizer = new StringTokenizer(
                        reader.readLine());
            }
            return tokenizer.nextToken();
        }

        static int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        static double nextDouble() throws IOException {
            return Double.parseDouble(next());
        }

        static long nextLong() throws IOException {
            return Long.parseLong(next());
        }
    }


    static class Pair implements Comparable<Pair>     {
        int pos;
        int val;



        public Pair(int pos, int val) {
            this.pos = pos;
            this.val = val;


        }


        @Override
        public String toString() {
            return pos + " " + val;
        }

        @Override
        public int compareTo(Pair o) {
            if(this.pos >o.pos){
                return 1;
            }
            else if(this.pos==o.pos){
                if(this.val>o.val){
                    return 1;
                }
                else{
                    return -1;
                }


            }
            else{
                return -1;
            }
        }


    }



    static class Node implements Comparable<Node>{
        int ind;
        int len;
        int val;
        Node prev;
        Node next;
        public Node(int ind, int len,int val){
            this.ind=ind;
            this.len=len;
            this.val=val;
        }

        @Override
        public String toString() {
            if(this.next!=null){
            return ind+ " " + len+" "+val+" "+this.next.val;
        }
            return ind+" "+len+" "+val+" "+-1;


        }

        @Override
        public int compareTo(Node o) {
            if(this.len <o.len){
                return 1;
            }
            if(this.ind==o.ind && this.len==o.len && this.val==o.val){
                return 0;
            }
             if(this.len==o.len){
                if(this.ind>o.ind){
                    return 1;
                }
                else{
                    return -1;
                }
            }
            return -1;

        }
        @Override
        public boolean equals(Object x){
            Node a= (Node)x;
            if(this.ind==a.ind && this.len==a.len && this.val==a.val){
                return true;
            }
            return false;
        }
    }


    

    

    

    

    

    

    

    static void merge(int arr[], int l, int m, int r)
    {
        

        int n1 = m - l + 1;
        int n2 = r - m;

        
        int L[] = new int[n1];
        int R[] = new int[n2];

        
        for (int i = 0; i < n1; ++i)
            L[i] = arr[l + i];
        for (int j = 0; j < n2; ++j)
            R[j] = arr[m + 1 + j];

        

        

        int i = 0, j = 0;

        

        int k = l;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            }
            else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        
        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }

        
        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }

    

    

    static void sort(int arr[], int l, int r)
    {
        if (l < r) {
            

            int m =l+ (r-l)/2;

            

            sort(arr, l, m);
            sort(arr, m + 1, r);

            

            merge(arr, l, m, r);
        }
    }



    public static void main(String[] args)  throws IOException {
        Reader.init(System.in);
        BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));

            int n= Reader.nextInt();
            int arr[][]= new int[n][n];
        for (int i = 0; i <n ; i++) {
            Arrays.fill(arr[i],-1);
        }


            for (int i = 0; i <n ; i++) {
                for (int j = 0; j <n ; j++) {
                    int f= Reader.nextInt();
                    if(f==1){
                        boolean b1=false;
                        for (int k = 0; k <n ; k++) {
                            for (int l = 0; l <n ; l++) {
                                if(arr[k][l]==-1 && (k+l)%2==0){
                                    arr[k][l]=2;
                                    out.append(2+" "+(k+1)+" "+(l+1)+" ");
                                    out.flush();
                                    b1=true;
                                    break;
                                }
                            }
                            if(b1){
                                break;
                            }
                        }


                        if(!b1){

                            for (int k = 0; k <n ; k++) {
                                for (int l = 0; l <n ; l++) {
                                    if(arr[k][l]==-1 && (k+l)%2==1){
                                        arr[k][l]=3;
                                        out.append(3+" "+(k+1)+" "+(l+1)+" ");
                                        out.flush();
                                        b1=true;
                                        break;
                                    }
                                }
                                if(b1){
                                    break;
                                }
                            }
                        }
                    }




                    if(f==2){
                        boolean b1=false;
                        for (int k = 0; k <n ; k++) {
                            for (int l = 0; l <n ; l++) {
                                if(arr[k][l]==-1 && (k+l)%2==1){
                                    arr[k][l]=1;
                                    out.append(1+" "+(k+1)+" "+(l+1)+" ");
                                    out.flush();
                                    b1=true;
                                    break;
                                }
                            }
                            if(b1){
                                break;
                            }
                        }


                        if(!b1){

                            for (int k = 0; k <n ; k++) {
                                for (int l = 0; l <n ; l++) {
                                    if(arr[k][l]==-1 && (k+l)%2==0){
                                        arr[k][l]=3;
                                        out.append(3+" "+(k+1)+" "+(l+1)+" ");
                                        out.flush();
                                        b1=true;
                                        break;
                                    }
                                }
                                if(b1){
                                    break;
                                }
                            }
                        }
                    }

                    if(f==3){
                        boolean b1=false;
                        for (int k = 0; k <n ; k++) {
                            for (int l = 0; l <n ; l++) {
                                if(arr[k][l]==-1 && (k+l)%2==0){
                                    arr[k][l]=2;
                                    out.append(2+" "+(k+1)+" "+(l+1)+" ");
                                    out.flush();
                                    b1=true;
                                    break;
                                }
                            }
                            if(b1){
                                break;
                            }
                        }


                        if(!b1){

                            for (int k = 0; k <n ; k++) {
                                for (int l = 0; l <n ; l++) {
                                    if(arr[k][l]==-1 && (k+l)%2==1){
                                        arr[k][l]=1;
                                        out.append(1+" "+(k+1)+" "+(l+1)+" ");
                                        out.flush();
                                        b1=true;
                                        break;
                                    }
                                }
                                if(b1){
                                    break;
                                }
                            }
                        }
                    }












                }
            }



















        out.close();
    }











    public static String convert(String s,int n){
        if(s.length()==n){
            return s;
        }
        else{
            int x= s.length();
            int v=n-x;
            String str="";
            StringBuilder s2= new StringBuilder();
            for (int i = 0; i <v ; i++) {
                s2.append('0');
            }
            StringBuilder s1= new StringBuilder(s);
            s2.append(s1);



            String q= s2.toString();
            return q;

        }
    }
    public static int lower(int arr[],int key){
        int low = 0;
        int high = arr.length-1;
        while(low < high){
            int mid = low + (high - low)/2;
            if(arr[mid] >= key){
                high = mid;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }

    public static int upper(int arr[],int key){
        int low = 0;
        int high = arr.length-1;
        while(low < high){
            int mid = low + (high - low+1)/2;
            if(arr[mid] <= key){
                low = mid;
            }
            else{
                high = mid-1;
            }
        }
        return low;
    }





    static long modExp(long a, long b, long mod) {
        

        if (a==1) return 1;
        long ans = 1;
        while (b!=0) {
            if (b%2==1) {
                ans = (ans*a)%mod;
            }
            a = (a*a)%mod;
            b/=2;
        }
        return ans;
    }


    public static long modmul(long a, long b, long mod) {
        return b == 0 ? 0 : ((modmul(a, b >> 1, mod) << 1) % mod + a * (b & 1)) % mod;
    }

    static long sum(long n){
        

        return (n*(n+1))/2;
    }






    public static ArrayList<Integer> Sieve(int n) {
        boolean arr[]= new boolean [n+1];
        Arrays.fill(arr,true);
        arr[0]=false;
        arr[1]=false;
        for (int i = 2; i*i <=n ; i++) {
            if(arr[i]){
                for (int j = 2; j <=n/i ; j++) {
                    int u= i*j;
                    arr[u]=false;
                }}
        }
        ArrayList<Integer> ans= new ArrayList<>();
        for (int i = 0; i <n+1 ; i++) {
            if(arr[i]){
                ans.add(i);
            }
        }
        return ans;
    }




    static long power( long x, long y, long p)
    {

        long res = 1;


        x = x % p;

        if (x == 0) return 0;

        while (y > 0)
        {

            if((y & 1)==1)
                res = (res * x) % p;


            y = y >> 1;
            x = (x * x) % p;
        }
        return res;
    }

    public static long ceil_div(long a, long b){
        return (a+b-1)/b;
    }

    static long gcd(long a, long b)
    {
        if (a == 0)
            return b;
        return gcd(b % a, a);
    }

    static long lcm(long a, long b)
    {
        return (a*b)/gcd(a, b);
    }

}