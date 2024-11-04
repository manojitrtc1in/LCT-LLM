


import java.util.*;

public class Main {
    public static void main(String[] args) {

       Scanner sc = new Scanner(System.in);
       int t=sc.nextInt();
       while(t-- >0){

           int n =sc.nextInt();
           int arr[]=new int[n];
           for(int i=0;i<arr.length;i++){
               arr[i]=sc.nextInt();
           }

           if(n == 1 || n==2){
               System.out.println("yes");
               continue;
           }


           boolean breakpoint = false;
           Stack<Integer> stk =  new Stack<>();
           int ngr[]=new int[n];
           int ngl[]=new int[n];

           

           for(int i=n-1;i>=0;i--){

               if(stk.size() == 0){
                   stk.add(arr[i]);
                   ngr[i]=-1;
               }
               else if(stk.peek() <= arr[i]){

                   while(stk.size()>0 && stk.peek() <= arr[i]){
                       stk.pop();
                   }

                   if(stk.size() == 0){
                       stk.add(arr[i]);
                       ngr[i]=-1;
                   }
                   else{
                       ngr[i] = stk.peek();
                       stk.add(arr[i]);
                   }
               }
               else{
                   ngr[i] = stk.peek();
                   stk.add(arr[i]);
               }

           }


           stk=new Stack<>();
           for(int i=0;i<n;i++){

               if(stk.size() == 0){
                   stk.add(arr[i]);
                   ngl[i]=-1;
               }
               else if(stk.peek() <= arr[i]){

                   while(stk.size()>0 && stk.peek() <= arr[i]){
                       stk.pop();
                   }

                   if(stk.size() == 0){
                       stk.add(arr[i]);
                       ngl[i]=-1;
                   }
                   else{
                       ngl[i] = stk.peek();
                       stk.add(arr[i]);
                   }
               }
               else{
                   ngl[i] = stk.peek();
                   stk.add(arr[i]);
               }

           }

           for(int i=0;i<n;i++){

               if(ngl[i] != -1 && ngr[i] != -1 ){
                   breakpoint=true;
                   break;
               }
           }






           if(breakpoint){
               System.out.println("no");
           }
           else{
               System.out.println("yes");
           }






           }





       }




    public static String findOrder(String [] dict, int N, int K)
    {
        int []indegree = new int[K];
        ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < K; i++) {
            adj.add(new ArrayList<>());
        }

        for (int i = 0; i < N-1; i++) {

            String s1=dict[i];
            String s2=dict[i+1];

            for (int j = 0; j < Math.min(s1.length(),s2.length()); j++) {

                if(s1.charAt(j) != s2.charAt(j)){

                    

                    adj.get(s1.charAt(j)-'0').add(s2.charAt(j)-'0');
                    indegree[s2.charAt(j)-'0']++;
                }

            }
        }


        Queue<Integer> q= new LinkedList<>();
        for (int i = 0; i < indegree.length; i++) {

            if(indegree[i]==0){
                q.add(i);
            }
        }

        StringBuilder sb = new StringBuilder();
        while(q.size()>0){

            int node=q.poll();
            sb.append((char)(node+'a'));
            for(Integer it:adj.get(node)){
                sb.append((char)(it+'a'));
                indegree[it]--;
                if(indegree[it] == 0){
                    q.add(it);
                }
            }
        }


        return sb.toString();

    }


    public int id3(int[] weights, int days) {

        int tot=0;
        for(Integer it:weights) tot+=it;

        Arrays.sort(weights);
        int l=1;
        int h=tot;

        int ans=0;
        while(l<=h){

            int mid=(l+h)/2;
            if(isPossible(mid,weights,days) == true){
                ans=mid;
                h=mid-1;
            }else{
                l=mid+1;
            }
        }

        System.out.println("mid: "+ans + " low: "+l + "high:" + h);
        return ans;
    }

    private static boolean isPossible(int mid, int[] weights, int days) {

        int count=1;
        int sum=0;
        for (int i = 0; i < weights.length; i++) {

            if(sum+weights[i]<=mid){
                sum+=weights[i];
            }else{
                count++;
                sum=weights[i];
            }
        }


        return count<=days;
    }


    public static int id2(String str)
    {

        int [][]dp=new int[str.length()+1][str.length()+1];
        for(int []it:dp)
            Arrays.fill(it,-1);

        return f(str,str,0,0,dp);

    }

    public static int f(String s1,String s2,int i,int j, int [][]dp){

        if(i>=s1.length() || j>=s2.length()){
            return 0;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int ti=0,nti1=0,nti2=0;
        if(s1.charAt(i) == s2.charAt(j) && i!=j){
            ti = f(s1,s2,i+1,j+1,dp) + 1;
        }

        nti1 = f(s1,s2,i+1,j,dp) + 0;
        nti2 = f(s1,s2,i,j+1,dp) + 0;

        return dp[i][j]=Math.max(ti,Math.max(nti1,nti2));
    }

    static char[][] fill(int n, int m, char a[][])
    {

        boolean [][]vis=new boolean[n+1][m+1];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if(i == n-1 || j == m-1 || i == 0 || j == 0){

                    if( vis[i][j] == false){
                            dfs(a,i,j,vis);
                    }
                }
            }
        }


        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if(vis[i][j]==false && a[i][j]=='0'){
                    a[i][j]='X';
                }
            }
        }


        return a;


    }

    public static void dfs(char [][]mat,int r,int c,boolean[][] vis){

        if(r<0 || c<0 || r>=mat.length || c>= mat[0].length || mat[r][c]=='X' || vis[r][c]==true){
            return;
        }

        vis[r][c]=true;
        int dir[][]={{1,0},{0,1},{-1,0},{0,-1}};
        for (int i = 0; i < 4; i++) {

            dfs(mat,r+dir[i][0],c+dir[i][1],vis);
        }
    }


    public static String minWindow(String s, String t) {

        HashMap<Character,Integer> mapS = new HashMap<>();
        HashMap<Character,Integer> mapT = new HashMap<>();
        int tot=0;
        for(Character it:t.toCharArray()){
            mapS.put(it,mapS.getOrDefault(it,0)+1);
        }
        for(Integer it:mapS.values()) tot+=it;


        int current_count=0;
        String ans = "";
        for (int low=0,high = 0; high < s.length(); high++) {

            if(mapS.containsKey(s.charAt(high))){

                if( mapT.containsKey(s.charAt(high)) &&  mapT.get(s.charAt(high)) <= mapS.get(s.charAt(high)))
                    current_count++;

                mapT.put(s.charAt(high),mapT.getOrDefault(s.charAt(high),0)+1);
            }

            int back=0;
            for ( back = low; back <= high && current_count >= tot; back++) {

                String oa = s.substring(back,high+1);

                if( ans.isEmpty() || oa.length() < ans.length()){
                    ans = oa;
                }

                if(mapS.containsKey(s.charAt(back))){

                    if(mapT.get(s.charAt(back)) <= mapS.get(s.charAt(back))){
                        current_count--;
                    }
                    mapT.put(s.charAt(back),mapT.getOrDefault(s.charAt(back),0)-1);

                }
            }
            low = back;

        }


        return ans;
    }



    public static List<Integer> findSubstring(String s, String[] words) {


        int len=words[0].length();
        int totlen = len* words.length;
        if(totlen>s.length()){
            return new ArrayList<>();
        }

        ArrayList<Integer> ans = new ArrayList<>();

        HashMap<String,Integer> map = new HashMap<>();
        for(String it:words) map.put(it,map.getOrDefault(it,0)+1);

        for (int i = 0; i < s.length() - totlen; i++) {

            HashMap<String ,Integer> copyMap = new HashMap<>(map);

            for (int j = 0; j < words.length; j++) {

                String word = s.substring(i + len * j, i+ j * len + len);

                if(copyMap.containsKey(word)){


                    if(copyMap.get(word) == 1){
                        copyMap.remove(word);
                    }else{
                        copyMap.put(word,copyMap.get(word)-1);
                    }


                    if(copyMap.isEmpty()){
                        ans.add(i);
                        break;
                    }

                }
                else{
                    break;
                }

            }

        }
            return ans;
    }
































































































































































































































































































































    class Pair{
        int i;
        int j;
        int maxDif;
        public Pair(int i,int j,int s){
            this.i=i;
            this.j=j;
            this.maxDif=s;
        }
    }
    int id1(int h[][]) {

        int n=h.length;
        int m=h[0].length;
        int dist[][]=new int[n][m];
        for( int []it:dist)Arrays.fill(it,Integer.MAX_VALUE);
        Queue<Pair> q = new LinkedList<>();
        q.add(new Pair(0,0,0));
        dist[0][0]=0;


        int [][]dir={{1,0},{0,1},{-1,0},{0,-1}};
        while(q.size()>0){

            Pair p = q.poll();
            int i=p.i;
            int j=p.j;
            int maxDiff=p.maxDif;

            for (int k = 0; k < 4; k++) {

                int r = i + dir[k][0];
                int c = j + dir[k][1];

                if(isValid(h,r,c,dist,maxDiff,h[i][j])){

                    int curVal = Math.abs(h[i][j] -h[r][c]);
                    q.add(new Pair(r,c,curVal));
                }
            }
        }


        return dist[n-1][m-1];
    }

    public static boolean isValid(int [][]h,int i,int j,int [][]dist,int maxDif, int curVal){

        if(i<0 || j<0 || i>=h.length || j>=h[0].length || Math.abs(curVal-h[i][j]) > dist[i][j] ){
            return false;
        }
        return true;
    }



    class Pair1 implements Comparable<Pair1>{
        int v;
        int stops;
        public Pair1(int v, int s){
            this.v=v;
            this.stops=s;
        }
        public int compareTo(Pair1 o){
            return this.stops - o.stops;
        }
    }
    public int id0(int n,int f[][],int src,int dst,int k) {

        k++;
        ArrayList<ArrayList<ArrayList<Integer>>> adj = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            adj.add(new ArrayList<>());
        }

        for (int i = 0; i < f.length; i++) {

            int u=f[i][0];
            int v=f[i][1];
            int d=f[i][2];

            ArrayList<Integer> temp1 = new ArrayList<>();
            ArrayList<Integer> temp2 = new ArrayList<>();

            temp1.add(v);temp1.add(d);
            temp2.add(u);temp2.add(d);

            adj.get(u).add(temp1);
            adj.get(v).add(temp2);
        }

        PriorityQueue<Pair1> pq = new PriorityQueue<>();
        pq.add(new Pair1(src,0));

        int dist[]=new int[n];
        Arrays.fill(dist,Integer.MAX_VALUE);
        dist[src]=0;
        while(pq.size()>0){

            Pair1  p = pq.poll();
            int node = p.v;
            int stops = p.stops;

            for(ArrayList<Integer> it:adj.get(node)){

                int ver = it.get(0);
                int d = it.get(1);

                if(stops <= k && dist[ver] > dist[node] + d){

                    pq.add(new Pair1(ver,stops+1));
                    dist[ver] = dist[node] + d;
                }

            }

        }

        return dist[dst];
    }


    class Pair2 implements Comparable<Pair2>{
        int v;
        int d;
        public Pair2(int v,int d){
            this.v=v;
            this.d=d;
        }
        public int compareTo(Pair2 o){
            return this.d-o.d;
        }
    }
    public  int paths(int [][]edges,int n ,int m){

        int []dist=new int[n];
        Arrays.fill(dist,Integer.MAX_VALUE);
        dist[0]=0;
        ArrayList<ArrayList<ArrayList<Integer>>> adj = new ArrayList<>();
        for( int i=0;i<n;i++) adj.add(new ArrayList<>());
        for(int i=0;i<edges.length;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int d=edges[i][2];

            ArrayList<Integer> t1=new ArrayList<>();
            ArrayList<Integer> t2=new ArrayList<>();

            t1.add(v);
            t1.add(d);
            adj.get(u).add(t1);
            t2.add(u);
            t2.add(d);
            adj.get(v).add(t2);
        }


        PriorityQueue<Pair2> pq= new PriorityQueue<>();
        pq.add(new Pair2(0,0));
        int count=0;
        while(pq.size()>0){
            Pair2 p=pq.poll();
            int node = p.v;
            int distance = p.d;

            for(ArrayList<Integer> it:adj.get(node)){
                int vertex = it.get(0);
                int nodeDist = it.get(1);
                if(dist[vertex] > distance + dist[node]){
                    dist[vertex] = distance + dist[node];
                    pq.add(new Pair2(vertex,distance + dist[node]));
                    if(vertex == n-1){
                        count=1;
                    }
                }
                else if(dist[vertex] == distance + dist[node] && vertex == n-1){
                    count++;
                }
            }
        }
        return count;
    }






}
