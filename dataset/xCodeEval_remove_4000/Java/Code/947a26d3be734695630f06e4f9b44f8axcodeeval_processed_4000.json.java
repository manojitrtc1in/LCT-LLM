


import java.io.*;
import java.util.*;


public class id3 {
   

    

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

    public static class Graph{
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

        public static int id2(){
            int count=0;
            ArrayList<Integer> vrtc= new ArrayList<>(vt.keySet());
            for (int i = 0; i <vrtc.size() ; i++) {
                count+=(vt.get(vrtc.get(i))).nb.size();
            }
            return count/2;
        }

        public static boolean id0(int ver1, int ver2){
            if(vt.get(ver1)==null || vt.get(ver2)==null){
                return false;
            }

            Vertex v= vt.get(ver1);
            if(v.nb.containsKey(ver2)){
                return true;
            }
            return false;
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

        public class Pair{
            int vname;
            ArrayList<Integer> psf= new ArrayList<>();       

            int dis;
            int col;
        }









        public HashMap<Integer,Integer> bfs(int src){
            HashMap<Integer, Boolean> prcd= new HashMap<>();    


            HashMap<Integer, Integer> ans= new HashMap<>();

            LinkedList<Pair> queue= new LinkedList<>();      


            Pair strtp= new Pair();

            strtp.vname= src;

            ArrayList<Integer> ar= new ArrayList<>();
            ar.add(src);

            strtp.psf= ar;
            strtp.dis=0;

            queue.addLast(strtp);

            while(!queue.isEmpty()){

                Pair rp =  queue.removeFirst();

                if(prcd.containsKey(rp.vname)){
                    continue;
                }
                prcd.put(rp.vname,true);
                ans.put(rp.vname,rp.dis);








                Vertex a= vt.get(rp.vname);
                ArrayList<Integer> arr= new ArrayList<>(a.nb.keySet());
                for (int i = 0; i <arr.size() ; i++) {
                    int s= arr.get(i);
                    if(!prcd.containsKey(s)){
                        Pair np = new Pair();
                        np.vname= s;
                        np.dis+=rp.dis+a.nb.get(s);
                        np.psf.addAll(rp.psf);
                        np.psf.add(s);




                        queue.addLast(np);
                    }

                }
            }
            return ans;

            

        }








        public HashMap<Integer,Integer> dfs(int src){
            HashMap<Integer, Boolean> prcd= new HashMap<>();    


            HashMap<Integer, Integer> ans= new HashMap<>();

            LinkedList<Pair> stack= new LinkedList<>();      


            Pair strtp= new Pair();

            strtp.vname= src;

            ArrayList<Integer> ar= new ArrayList<>();
            ar.add(src);

            strtp.psf= ar;
            strtp.dis=0;

            stack.addFirst(strtp);

            while(!stack.isEmpty()){

                Pair rp =  stack.removeFirst();

                if(prcd.containsKey(rp.vname)){
                    continue;
                }
                prcd.put(rp.vname,true);
                ans.put(rp.vname,rp.dis);








                Vertex a= vt.get(rp.vname);
                ArrayList<Integer> arr= new ArrayList<>(a.nb.keySet());
                for (int i = 0; i <arr.size() ; i++) {
                    int s= arr.get(i);
                    if(!prcd.containsKey(s)){
                        Pair np = new Pair();
                        np.vname= s;
                        np.dis+=rp.dis+a.nb.get(s);
                        np.psf.addAll(rp.psf);
                        np.psf.add(s);




                        stack.addFirst(np);
                    }

                }
            }
            return ans;

            

        }






        public boolean isCycle(){
            HashMap<Integer, Boolean> prcd= new HashMap<>();    


            


            LinkedList<Pair> queue= new LinkedList<>();      




            ArrayList<Integer> keys = new ArrayList<>(vt.keySet());
            for (int i = 0; i <keys.size(); i++) {
                int cur= keys.get(i);
                if(prcd.containsKey(cur)){
                    continue;
                }

                Pair sp = new Pair();
                sp.vname= cur;
                ArrayList<Integer> as= new ArrayList<>();
                as.add(cur);
                sp.psf= as;

                queue.addLast(sp);

                while(!queue.isEmpty()){




                    Pair rp= queue.removeFirst();
                    if(prcd.containsKey(rp.vname)){
                        return true;
                    }

                    prcd.put(rp.vname,true);




                    Vertex v1= vt.get(rp.vname);
                    ArrayList<Integer> nbrs= new ArrayList<>(v1.nb.keySet());
                    for (int j = 0; j <nbrs.size() ; j++) {
                        int u= nbrs.get(j);
                        Pair np= new Pair();
                        np.vname= u;
                        queue.addLast(np);
                    }
                }

            }
            return false;
        }






        public  ArrayList<ArrayList<Integer>> id4(){
            HashMap<Integer, Boolean> prcd= new HashMap<>();    


            ArrayList<ArrayList<Integer>> ans= new ArrayList<>();

            


            LinkedList<Pair> queue= new LinkedList<>();      


            


            ArrayList<Integer> keys = new ArrayList<>(vt.keySet());
            for (int i = 0; i <keys.size(); i++) {
                int cur= keys.get(i);
                if(prcd.containsKey(cur)){
                    

                    continue;
                }
                int count=0;
                ArrayList<Integer> fu= new ArrayList<>();
                fu.add(cur);


                Pair sp = new Pair();
                sp.vname= cur;
                ArrayList<Integer> as= new ArrayList<>();
                as.add(cur);
                sp.psf= as;

                queue.addLast(sp);

                while(!queue.isEmpty()){




                    Pair rp= queue.removeFirst();
                    if(prcd.containsKey(rp.vname)){
                        

                        continue;
                    }

                    prcd.put(rp.vname,true);
                    fu.add(rp.vname);



                    Vertex v1= vt.get(rp.vname);
                    ArrayList<Integer> nbrs= new ArrayList<>(v1.nb.keySet());
                    for (int j = 0; j <nbrs.size() ; j++) {
                        int u= nbrs.get(j);
                        if(!prcd.containsKey(u)){
                            count++;
                        Pair np= new Pair();
                        np.vname= u;
                        queue.addLast(np);
                    }
                }}
                fu.add(count);
                ans.add(fu);

            }
            

            return ans;

        }

        public boolean id5(int src){                       


            HashMap<Integer,Integer> clr= new HashMap<>();
            



            LinkedList<Integer>q = new LinkedList<Integer>();
            clr.put(src,1);
            q.add(src);


            while(!q.isEmpty()){

                int u = q.getFirst();
                q.pop();

                ArrayList<Integer> arr= new ArrayList<>(vt.keySet());

                for (int i = 0; i <arr.size() ; ++i) {

                    int x= arr.get(i);

                    if(vt.get(u).nb.containsKey(x) && !clr.containsKey(x)){

                        if(clr.get(u)==1){
                            clr.put(x,-1);
                        }
                        else{
                            clr.put(x,1);
                        }
                        q.push(x);
                    }

                    else if(vt.get(u).nb.containsKey(x) && (clr.get(x)==clr.get(u))){
                        return false;
                    }

                }
            }
            return true;
        }

















        public static void printGr() {
            ArrayList<Integer> arr= new ArrayList<>(vt.keySet());
            for (int i = 0; i <arr.size() ; i++) {
                int ver= arr.get(i);
                Vertex v1= vt.get(ver);
                ArrayList<Integer> arr1= new ArrayList<>(v1.nb.keySet());
                for (int j = 0; j <arr1.size() ; j++) {
                    System.out.println(ver+"-"+arr1.get(j)+":"+v1.nb.get(arr1.get(j)));
                }

            }
        }
    }

    static class Cus implements Comparable<Cus>{
        int size;
        int mon;
        int num;
        public Cus(int size,int mon,int num){
            this.size=size;
            this.mon=mon;
            this.num=num;
        }
        @Override
        public int compareTo(Cus o){
            if(this.mon!=o.mon){
                return this.mon-o.mon;}

            else{
                return o.size-this.size;
            }

        }



    }

    static class Table implements Comparable<Table>{
        int go;
        int cum;
        int cost;
        public Table(int go,int cum,int cost){
            this.go=go;
            this.cum=cum;
            this.cost=cost;
        }
        @Override
        public int compareTo(Table o){
            if(this.go==o.go){
                return this.cum-o.cum;
            }
            return this.go-o.go;

        }


    }
    static class Table1 implements Comparable<Table1>{
        int go;
        int cum;
        int cost;
        public Table1(int go,int cum,int cost){
            this.go=go;
            this.cum=cum;
            this.cost=cost;
        }
        @Override
        public int compareTo(Table1 o){
            return this.cost-o.cost;


        }}

    public static class id1{
        HashMap<Integer,Node> mp= new HashMap<>();

        public static class Node{
            int data;
            Node parent;
            int rank;
        }


        public void create(int val){
            Node nn= new Node();
            nn.data=val;
            nn.parent=nn;
            nn.rank=0;
            mp.put(val,nn);
        }

        public int find(int val){

            return findn(mp.get(val)).data;

        }


        public Node findn(Node n){
            if(n==n.parent){
                return n;
            }
            Node rr= findn(n.parent);
            n.parent=rr;
            return rr;
        }



        public void union(int val1, int val2){                                                                               


            Node n1= findn(mp.get(val1));
            Node n2= findn(mp.get(val2));


            if(n1.data==n2.data) {
                return;
            }



            if(n1.rank<n2.rank){
                n1.parent=n2;
            }

            else if(n2.rank<n1.rank){
                n2.parent=n1;
            }

            else {
                n2.parent=n1;
                n1.rank++;
            }

        }
    }









    public static void main(String[] args)  throws IOException {
        Reader.init(System.in);
        BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
        long a= Reader.nextInt();
        long b= Reader.nextInt();
        long x= gcd(a,b);
        int q= Reader.nextInt();
        ArrayList<Long> ar= new ArrayList<>();
        for (int i = 1; i*i <=x ; i++) {
            if(x%i==0){
                if(x/i == i){
                    ar.add((long)i);
                }
                else{
                    ar.add((long)i);
                    ar.add(x/i);
                }
            }
        }
        Collections.sort(ar);
        long arr[]= new long[ar.size()];
        for (int i = 0; i <ar.size() ; i++) {
            arr[i]= ar.get(i);
        }


        for (int i = 0; i <q ; i++) {
        int l= Reader.nextInt();
        int r= Reader.nextInt();
        int d= Arrays.binarySearch(arr,r);
           

        if(d<0){
            d=~d -1;
        }
          

        if(d>=0){
            

            long ans= arr[d];
           

            if(ans<l || ans>r){
                System.out.println(-1);




            }
            else{
                System.out.println(ans);




            }
        }














        }



    }



















































    public static void df(int x, int y,int n, int m, char[][]ar, int l){
        boolean done[][]= new boolean[n][m];
        int count=0;
        LinkedList<int[]> stk= new LinkedList<>();
        int a[]= {x,y};
        stk.addFirst(a);
        while(!stk.isEmpty() && count<l){
          

            int b[]=stk.removeFirst();
            if( done[b[0]][b[1]]){
                continue;
            }
            count++;

            done[b[0]][b[1]]=true;
            ar[b[0]][b[1]]='@';
            int arr[][]={{1,0},{-1,0},{0,1},{0,-1}};
            for (int i = 0; i <arr.length ; i++) {
                if(!(b[0]+arr[i][0]>=n || b[1]+arr[i][1]>=m || b[0]+arr[i][0]<0 || b[1]+arr[i][1]<0 ||  ar[b[0]+arr[i][0]][b[1]+arr[i][1]]=='
                    int r[]= {b[0]+arr[i][0], b[1]+arr[i][1]};
                    stk.addFirst(r);
                   




            }
        }}


        for (int i = 0; i <n ; i++) {
            for (int j = 0; j <m ; j++) {
                if(ar[i][j]=='.'){
                    System.out.print('X');
                }
                else if(ar[i][j]=='@'){
                    System.out.print('.');
                }
                else{
                    System.out.print(ar[i][j]);
                }
            }
            System.out.println();
        }
























    }











    static long gcd(long a, long b)
    {
        if (a == 0)
            return b;
        return gcd(b % a, a);
    }



    static long id6(long a, long b)
    {

        

        if (a == 0)
            return b;
        if (b == 0)
            return a;

        

        if (a == b)
            return a;

        

        

        if (a > b){
            return gcd(a-b, b);

        }
        return gcd(a, b-a);
    }





    

    static long lcm(long a, long b)
    {
        return (a*b)/gcd(a, b);
    }

    


    static int partition(long arr[],long arr1[], int low, int high)
    {
        long pivot = arr[high];
        int i = (low-1); 

        for (int j=low; j<high; j++)
        {
            

            if (arr[j] < pivot)
            {
                i++;

                

                long temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                long temp1=arr1[i];
                arr1[i]=arr1[j];
                arr1[j]=temp1;

            }
        }

        

        long temp = arr[i+1];
        arr[i+1] = arr[high];
        arr[high] = temp;
        long temp1= arr1[i+1];
        arr1[i+1]=arr1[high];
        arr1[high]= temp1;

        return i+1;
    }


    
    static void sort(long arr[],long arr1[], int low, int high)
    {
        if (low < high)
        {
            
            int pi = partition(arr,arr1, low, high);

            

            

            sort(arr,arr1, low, pi-1);
            sort(arr,arr1, pi+1, high);
        }
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





}