


import com.sun.security.jgss.GSSUtil;

import java.io.*;
import java.util.*;
import java.util.LinkedList;

public class Main {

    static class Reader {
        final private int BUFFER_SIZE = 1 << 16;
        private DataInputStream din;
        private byte[] buffer;
        private int bufferPointer, bytesRead;

        public Reader() {
            din = new DataInputStream(System.in);
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }

        public Reader(String file_name) throws IOException {
            din = new DataInputStream(
                    new FileInputStream(file_name));
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }

        public String readLine() throws IOException {
            byte[] buf = new byte[64]; 

            int cnt = 0, c;
            while ((c = read()) != -1) {
                if (c == '\n') {
                    if (cnt != 0) {
                        break;
                    } else {
                        continue;
                    }
                }
                buf[cnt++] = (byte) c;
            }
            return new String(buf, 0, cnt);
        }

        public int nextInt() throws IOException {
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

        public long nextLong() throws IOException {
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

        public double nextDouble() throws IOException {
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

        private void fillBuffer() throws IOException {
            bytesRead = din.read(buffer, bufferPointer = 0,
                    BUFFER_SIZE);
            if (bytesRead == -1)
                buffer[0] = -1;
        }

        private byte read() throws IOException {
            if (bufferPointer == bytesRead)
                fillBuffer();
            return buffer[bufferPointer++];
        }

        public void close() throws IOException {
            if (din == null)
                return;
            din.close();
        }

        static class FastReader {
            BufferedReader br;
            StringTokenizer st;

            public FastReader() {
                br = new BufferedReader(
                        new InputStreamReader(System.in));
            }

            String next() {
                while (st == null || !st.hasMoreElements()) {
                    try {
                        st = new StringTokenizer(br.readLine());
                    } catch (IOException e) {
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
                String str = "";
                try {
                    str = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                return str;
            }
        }

    }


    public static void main(String[] args) {
        Reader.FastReader sc = new Reader.FastReader();
        int t = sc.nextInt();
        while(t-->0){
            int n = sc.nextInt();
            int m = sc.nextInt();
            int k = sc.nextInt();

            String [] a = sc.nextLine().split("");
            String [] b = sc.nextLine().split("");

            Arrays.sort(a);
            Arrays.sort(b);

            int i = 0;
            int j = 0;
            int kk  = k;
            StringBuilder s = new StringBuilder();
            boolean last = false;
            boolean enter = false;
            while(i<a.length && j<b.length) {
                if(a[i].charAt(0)< b[j].charAt(0) && kk>0){
                    if(j>=b.length){
                        break;
                    }
                    if(!last){
                        kk = k;
                    }

                    s.append(a[i]);
                    i++;
                    last = true;
                    kk--;
                }
                else if(kk>0 && a[i].charAt(0)>= b[j].charAt(0)){

                    if(i>=a.length){
                        break;
                    }
                    if(last) {
                        kk = k;
                    }

                    s.append(b[j]);
                    j++;
                    last = false;
                    kk--;
                }

                if(kk==0){
                    if(i>=a.length || j>= b.length){
                        break;
                    }
                    if(last){
                        s.append(b[j]);
                        j++;
                        last = false;
                    }
                    else{
                        s.append(a[i]);
                        i++;
                        last = true;
                    }
                    kk = k;
                    kk--;
                }
            }
            System.out.println(s);
        }
    }

    private static int id0(ArrayList<ArrayList<Integer>> gr, int c,int sum,  int src, boolean[] vis, int [] dp, int [] cats) {
        if(cats[src]==1){


            sum++;
        }
        else{
            sum = 0;
        }
        if(sum>c){
            return 0;
        }
        if(gr.get(src).size()==1 && src!=0){


            return 1;
        }
        if(dp[src]!=-1){
            return dp[src];
        }
        vis[src] = true;
        int res = 0;
        for(int adj : gr.get(src)){
            if(!vis[adj]){
                res+=id0(gr, c, sum, adj, vis, dp, cats);
            }
        }

        return dp[src] = res;
    }

    public static void cirno(long x){
        int o = -1;
        int z = -1;
        for(int i = 0; i<31; i++){
            if((x&(1<<(i)))>0){
                o = i;
                break;
            }

        }

        for(int i = o+1; i<31; i++){
            if((x&(1L <<(i)))>0){
                z = i;
                break;
            }
        }

        if(z==-1){
            if(o!=0){
                z = 0;
            }
            else{
                z=1;
            }
            System.out.println((int)(Math.pow(2,o)+Math.pow(2,z)));
        }

        else{
            System.out.println((int)(Math.pow(2,o)));
        }




    }


    public static long patch(int [] arr, int n){

        int value = -1;
        int o = 0;
        for(int i = 0; i<n; i++){
            if(arr[i]%2==0 && value==-1){
                value = arr[i];
            }
            if(arr[i]%2==1){
                o++;
            }
        }
        if(value==-1){
            return 0;
        }

        if(o!=0){
            return n-o;
        }



        int min = Integer.MAX_VALUE;
        for(int i = 0; i<n; i++){
            int val = arr[i];
            int op = 0;
            while(val%2!=1){
                val/=2;
                op++;
            }

            min  = Math.min(min, op);
        }
        min+=(n-1);
        return min;
    }

    public void LCA(int [][] q, int [] first, int [] height){

    }
    public void sgtree(int [] height, int left, int right, int [] tree){
        int mid = (left+right)/2;

    }



    public void dfs(ArrayList<ArrayList<Integer>> gr, int src, boolean [] vis,int [] first, int [] height, ArrayList<Integer> euler, int h){
        vis[src] = true;
        height[src] = h;
        first[src] = euler.size()-1;
        euler.add(src);
        for(int adj : gr.get(src)){
            if(!vis[adj]){
                dfs(gr, adj, vis, first, height, euler, h+1);
                euler.add(adj);
            }
        }
    }

    public static int [] id1(ArrayList<ArrayList<Integer>> arr, int n){
        int [] ans = new int [n];
        boolean [] vis = new boolean [n];
        Queue<int []>q = new LinkedList<>();
        q.add(new int []{0,0});
        while(!q.isEmpty()){
            int [] rem = q.poll();
            int u = rem[0];
            int dist = rem[1];
            vis[u] = true;
            for(int adj : arr.get(u)){
                if(!vis[adj]){
                    q.add(new int []{adj, dist+1});
                    ans[adj] = dist+1;
                }
            }
        }

        return ans;
    }












    public static boolean monsters(int [][] distances, String [][] map, int n, int m){
        Queue<int []> q = new LinkedList<>();
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(map[i][j].equals("A")){
                    q.add(new int []{i, j, 0});
                }
            }
        }
        boolean [][] vis = new boolean [n][m];
        int [] x = {1,-1,0,0};
        int [] y = {0,0,-1,1};

        while(!q.isEmpty()){
            int [] rem = q.poll();
            int xi = rem[0];
            int yi = rem[1];
            if(xi==n || xi==0 || yi==0 ||yi==m){
                    return true;
            }
            vis[rem[0]][rem[1]] = true;
            for(int i =0; i<4; i++){
                int newX = rem[0]+x[i];
                int newY = rem[1]+y[i];
                int dist = rem[2]+1;

                if(newX>=0 && newX<n && newY>=0 && newY<m && !map[newX][newY].equals("
                    q.add(new int []{newX,newY, dist});
                }

            }
        }

        return false;
    }
    public static int [][] findTiming(String [][] map, int n, int m){
        Queue<int []> q = new LinkedList<>();
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(map[i][j].equals("M")){
                    q.add(new int []{i, j, 0});
                }
            }
        }
        int [][] distances = new int[n][m];
        for(int i = 0; i<n; i++)
          Arrays.fill(distances[i], Integer.MAX_VALUE);
        boolean [][] vis = new boolean [n][m];
        int [] x = {1,-1,0,0};
        int [] y = {0,0,-1,1};


        while(!q.isEmpty()){
            int [] rem = q.poll();
            vis[rem[0]][rem[1]] = true;
            distances[rem[0]][rem[1]] = Math.min(rem[2], distances[rem[0]][rem[1]]);
            for(int i =0; i<4; i++){
                int newX = rem[0]+x[i];
                int newY = rem[1]+y[i];
                int dist = rem[2]+1;

                if(newX>=0 && newX<n && newY>=0 && newY<m && !map[newX][newY].equals("
                    q.add(new int []{newX,newY, dist});
                }
            }
        }

        return distances;
    }







































    public static boolean roundTrip2(ArrayList<ArrayList<Integer>> arr,int src,  boolean [] vis, boolean [] rec, int [] parentArr, int parent, int [] ans){

        parentArr[src] = parent;


        if(vis[src]) return false;


        vis[src] = true;
        rec[src] = true;
        for(int adj : arr.get(src)){
            if(rec[adj]) {
                ans[0] = src;
                ans[1] = adj;
                return true;
            }
            if(roundTrip2(arr, adj, vis, rec, parentArr, src, ans)){
                    return true;
            }
        }
        rec[src] = false;
        return false;
    }
    public static boolean roundTrip(ArrayList<ArrayList<Integer>> arr,int src,  boolean [] vis, int parent, int [] ans, int [] parentarr){
        vis[src] =true;
        parentarr[src] = parent;
        for(int adj : arr.get(src)){

            if(!vis[adj]){
                if(roundTrip(arr, adj, vis, src, ans, parentarr))
                    return true;

            }
            else if(adj!=parent){
                ans[0] = src;
                ans[1] = adj;
                return true;
            }
        }
        return false;
    }



    public static boolean buildingT(ArrayList<ArrayList<Integer>> gr, int src, int [] vis, int value){
        vis[src] = value;
        value = value==1 ?2:1;
        for(int i : gr.get(src)){
            if(vis[i]==0){
                if(!buildingT(gr, i, vis, value)){
                    return false;
                }
            }
            else{
                if(vis[i]!=value){
                    return false;
                }
            }
        }
        return true;
    }
    public static void dfs(ArrayList<ArrayList<Integer>> arr, int n, int src, boolean [] vis){
        vis[src] = true;
        for(int i : arr.get(src)){
            if(!vis[i]){
                dfs(arr, n, i, vis);
            }
        }
    }


    public static ArrayList<ArrayList<Integer>> roads(int [][] edges, int n){
        ArrayList<ArrayList<Integer>> arr = new ArrayList<>();
        for(int i = 0; i<n; i++) {
            arr.add(new ArrayList<Integer>());
        }
        for(int i = 0; i<edges.length; i++){
            arr.get(edges[i][0]-1).add(edges[i][1]-1);
            arr.get(edges[i][1]-1).add(edges[i][0]-1);
        }
        return arr;
    }
    public static void labyrinth(String [][]map, int n,int m, int i, int j, boolean [][] vis, String s, ArrayList<String> ans, int [] tp){


        if(i<0 || j<0 || i==n || j==m ||vis[i][j] || map[i][j].equals("
            return;
        }

        if(i==tp[0] && j==tp[1]){
            ans.add(s);
            return;
        }


        vis[i][j] = true;
        labyrinth(map, n,m, i, j+1, vis, s+"R", ans,tp);
        labyrinth(map, n,m, i+1, j, vis, s+"D", ans,tp);
        labyrinth(map, n,m, i, j-1, vis, s+"L", ans,tp);
        labyrinth(map, n,m, i-1, j, vis, s+"U", ans,tp);
        vis[i][j] = false;

    }
    public static int bfs(String [][] map, int n, int m){
        Queue<int []> q = new LinkedList<>();
        int [] dx = {1,-1,0,0};
        int [] dy = {0,0,-1,1};
        boolean[][] vis = new boolean[n][m];
        int ans = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(map[i][j].equals(".") && !vis[i][j]){
                    ans++;
                    q.add(new int []{i,j});
                    while(!q.isEmpty()){
                        int [] rem = q.poll();
                        int x = rem[0];
                        int y = rem[1];

                        if(!vis[x][y]){
                            vis[x][y] = true;
                            for(int nw= 0; nw<4;nw++){
                                int nx = x+dx[nw];
                                int ny = y+dy[nw];
                                if(nx>=0 && ny>=0 && nx<n && ny<m && !vis[nx][ny] && !map[nx][ny].equals("
                                    q.add(new int []{nx, ny});

                            }
                        }
                    }
                }
            }
        }
        return ans;


    }

    public static ArrayList<ArrayList<Integer>> graph(int [][] edges, int n){
        ArrayList<ArrayList<Integer>> graph = new ArrayList<>();
        for(int i = 0; i<n; i++){
            graph.add(new ArrayList<>());
        }

        for(int i = 0; i<edges.length; i++){
            graph.get(edges[i][0]-1).add(edges[i][1]-1);
            graph.get(edges[i][1]-1).add(edges[i][0]-1);
        }

        return graph;
    }

    public static ArrayList<ArrayList<Integer>> graph2(int [][] edges, int n){
        ArrayList<ArrayList<Integer>> graph = new ArrayList<>();
        for(int i = 0; i<n; i++){
            graph.add(new ArrayList<>());
        }

        for(int i = 0; i<edges.length; i++){
            graph.get(edges[i][0]-1).add(edges[i][1]-1);
        }

        return graph;
    }

    public static int dfs(ArrayList<ArrayList<Integer>> graph, int n, int [] dp,int[]depth, int [] size,boolean [] vis,  int src){
        vis[src] = true;

        for(int adj : graph.get(src)){
            if(!vis[adj]){
                depth[adj] = 1+depth[src];
                size[src]+=dfs(graph, n, dp,depth,size, vis, adj);
            }
        }
        dp[src] = size[src]-depth[src];
        return size[src];
    }


}