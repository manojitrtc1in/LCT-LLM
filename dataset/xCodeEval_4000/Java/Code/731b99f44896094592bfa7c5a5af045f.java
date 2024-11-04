




import javax.swing.*;
import java.io.*;
import java.lang.reflect.Array;
import java.util.*;



public class cf1 {
    static class Pair {
    int x,y,z;
    public Pair(int a,int b,int c){
        this.x = a;
        this.y = b;
        this.z = c;
    }
    public void print(){
        System.out.println(x+" "+y);
    }
}
    public static boolean isPrime(int n){
        for (int i = 2; i <= Math.sqrt(n) ; i++) {
            if(n%i == 0)
                return false;
        }
        return true;
    }

    public static long even_sum(int n){
        return n*n+n;
    }
    public static long odd_sum(int n){
        return n*n;
    }

    public static int dfs(List<List<Integer>> ls){
        int ans =0,cur,n = ls.size();
        boolean[] vis = new boolean[n];
        int[] seen = new int[n];

        Arrays.fill(vis,false);
        Arrays.fill(seen,0);

        Stack<Integer> st = new Stack<>();

        for (int k = 0; k <n ; k++) {


            if(!vis[k]) {
                st.add(k);
                vis[k] = true;
                seen[k] = 1;

                while (!st.isEmpty()){
                    cur = st.pop();
                    vis[cur] = true;
                    int cur_color = seen[cur];

                    for (int i = 0; i <ls.get(cur).size() ; i++) {
                        if(seen[ls.get(cur).get(i)] == 0 )
                            seen[ls.get(cur).get(i)] = -1*cur_color;
                        else if (seen[ls.get(cur).get(i)] == cur_color)
                            ans += 1;

                        if (!vis[ls.get(cur).get(i)]) {
                            st.add(ls.get(cur).get(i));
                            vis[ls.get(cur).get(i)] = true;
                        }
                    }
                }
            }
        }
        return ans/2;
    }

    public static boolean stable(int d, int[] arr , int c){
        int cnt = 1, prev = arr[0];



        for (int i = 1; i <arr.length ; i++) {
            if(arr[i]-prev >= d){
                cnt+=1;
                prev = arr[i];
            }
        }



        return cnt>=c;
    }

    public static void merge(long arr[],int s, int m ,int e) {
        int n = arr.length;
        long[] left = new long[m-s+1];
        long[] right = new long[e-m];

        for (int i = s; i <=m ; i++) {
            left[i-s] = arr[i];
        }
        for (int i = m+1; i <=e ; i++) {
            right[i-m-1] = arr[i];
        }







        int i = s,j =0 ,k=0;
        while(j<left.length && k<right.length){
            if(left[j]<right[k]){
                arr[i] = left[j];
                j+=1;
            }
            else{
                arr[i] = right[k];
                k+=1;
            }
            i+=1;
        }
        while(j<left.length){
            arr[i++] = left[j++];
        }
        while(k<right.length){
            arr[i++] = right[k++];
        }

    }
    public static void merge_sort(long arr[],int start, int end){
        int mid ;
        if(start<end){
            mid = start+ (end-start)/2;
            merge_sort(arr,start,mid);
            merge_sort(arr,mid+1,end);
            merge(arr,start,mid,end);
        }

    }

    public static long gcd(long a, long b){


        if(a==0)
            return b;
        return gcd(b%a,a);
    }
    public static long lcm(long a, long b){
        return (a/gcd(a,b))*b;
    }

    public static int minMove(String s){
        
        if(s.charAt(0)==s.charAt(3) && s.charAt(1)==s.charAt(4))
            return 0;
        int[][] board = new int[8][8];
        int[][] moves = {
                {1,-2},{1,2},{-1,-2},{-1,2},
                {-2,1},{-2,-1},{2,-1},{2,1},
        };
        int r = s.charAt(0)-'a';
        int c = Character.getNumericValue(s.charAt(1))-1;

        boolean[][] vis = new boolean[8][8];
        for (int i = 0; i <8 ; i++) {
            Arrays.fill(vis[i],false);
        }
               Queue<Integer> q = new LinkedList<>();
        board[r][c] = 0;
        q.add(r*8+c);
        vis[r][c] = true;

        r = s.charAt(3)-'a';
        c = Character.getNumericValue(s.charAt(4))-1;
        board[r][c] = -1;

        int cur,cur_r,cur_c;
        while (!q.isEmpty()){
            cur = q.poll();
            cur_r = cur/8;
            cur_c = cur%8;

            for (int i = 0; i <8 ; i++) {
                if(moves[i][0]+cur_r >=0 && moves[i][0]+cur_r<8
                && moves[i][1]+cur_c >=0 && moves[i][1]+cur_c<8) {

                    if (board[moves[i][0] + cur_r][moves[i][1] + cur_c] == -1) {
                        return 1 + board[cur_r][cur_c];
                    }
                    if (!vis[moves[i][0] + cur_r][moves[i][1] + cur_c]) {
                        board[moves[i][0] + cur_r][moves[i][1] + cur_c] =
                                1 + board[cur_r][cur_c];
                        vis[moves[i][0] + cur_r][moves[i][1] + cur_c] = true;
                        q.add((moves[i][0] + cur_r) * 8 + (moves[i][1] + cur_c));
                    }
                }
            }
        }
        return -1;
    }
    public static int[] topological(List<List<Integer>> ls, int[] in, long[] arr){
        int cur,n = ls.size();
        int[] time = new int[n];

        Queue<Integer> q = new LinkedList<>();
        for (int i = 0; i <n ; i++) {
            time[i] = (int) arr[i];
            if(in[i]==0)
                q.add(i);
        }


        while (!q.isEmpty()){
            cur= q.poll();



            for (int i = 0; i <ls.get(cur).size() ; i++) {
                time[ls.get(cur).get(i)] += time[cur];


                in[ls.get(cur).get(i)] -=1;
                if(in[ls.get(cur).get(i)]==0){
                    q.add(ls.get(cur).get(i));
                }
            }
            for (int i = 0; i <ls.get(cur).size() ; i++) {
                ls.get(cur).remove(i);
            }
        }
        return time;

    }

    public static long funct(int[] arr,int i, int prev ,long ans){
       if(i==arr.length)
           return ans;

       if(prev==arr[i]|| arr[i]==0){
           ans +=1;


               return funct(arr,i+1,-1,ans);


       }
       else if(arr[i]==3){
           long a1,a2;
           a2 =  funct(arr,i+1,2,ans);
           a1 =  funct(arr,i+1,1,ans);
           if(prev==1)
                return a2;
           else if (prev==2)
               return a1;
           return Math.min(a1,a2);
       }
       else if(arr[i]==1){


               return funct(arr,i+1,1,ans);




       }
       else {


               return funct(arr,i+1,2,ans);
       }



    }

    public static int[] count_dividors(){
        int[] last = new int[1000001];
        int max = 1000000;
        last[1] = 0;

        for (int i = 1; i <= max ; i++) {
            for (int j = i; j <=max ; j+=i)
                last[j] +=1;
        }
        return last;
    }
    public static int Hanoi(int n , int start , int end ,
                             int temp,int[] pos,int step ){
        if(n>0){
            System.out.println(start +" "+temp+" "+end);




            Hanoi(n-1,start,temp,end,pos,step+1);
            Hanoi(n-1,temp,end,start,pos,step+2);
        }
        return -1;
    }

    public static long pow(int base, int power, int mod){
        long ans = 1;
        while(power>0){
            ans  = ans*base % mod;
            power--;
        }
        return ans;
    }

    public  void powerset(int[] diffs){
        int n = diffs.length;
        for (int i = 1; i < Math.pow(2,n) ; i++) {
           
            long m,sum = 0,min = 100000000,max = -1;
            for (int j = 0; j <n ; j++) {
                m =  (int)Math.pow(2,j);
                if((i&(m))==m) {
                    sum += diffs[j];
                    min = Math.min(min, diffs[j]);
                    max = Math.max(max, diffs[j]);
                }
            }

        }
    }


    public static double dist(int x,int y,int x1,int y1, int x2, int y2){






        return (x-x1)*(y2-y1) - (y-y1)*(x2-x1);
    }
    public static void main(String[] das) throws IOException {


        InputReader sc= new InputReader(System.in);







        int t, n,min, max=-1, m = 0, k, l, r, a, b, cur = 0, d = 0;
        long cnt,ans = 0;











        t = sc.nextInt();


         String s1,s,s3,s2="";  

       int x,y,z,inf = 998244353;




        while(t-->0){
            n = sc.nextInt();

















































































            s = sc.nextLine();
            s1 = sc.nextLine(); 

            if(s.equals(s1))
                System.out.println("YES");
            else if(s.length()==1 ||s.indexOf('b')== -1)
                System.out.println("NO");
            else {
                int[] cnts = new int[3];
                for (int i = 0; i <n ; i++) {
                    cnts[s.charAt(i)-'a'] +=1;
                    cnts[s1.charAt(i)-'a'] -=1;
                }

                if(cnts[0]==0 && cnts[1]==0 && cnts[2]==0){
                    int j=0;
                    boolean f = true;
                    for (int i = 0; i < n; i++) {
                        if(s.charAt(i)=='b')
                            continue;
                        while(s1.charAt(j)=='b')
                            j+=1;

                        if(s.charAt(i)!=s1.charAt(j) || (s.charAt(i)=='a' && i>j) ||(s.charAt(i)=='c' && i<j)){
                            f = false;
                            break;
                        }
                        j+=1;
                    }
                    if(f)
                        System.out.println("YES");
                    else
                        System.out.println("NO");
                }
                else
                    System.out.println("NO");

            }
        }
    }

}

class InputReader {
    private BufferedReader reader;
    private StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream));
        tokenizer = null;
    }

    public InputReader(FileReader fr) {
        reader = new BufferedReader(fr);
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

    public String nextLine() throws IOException {
        String str = "";
        try
        {
            str = reader.readLine();
        }
        catch (IOException e)
        {
            e.printStackTrace();
        }
        return str;
    }

    public double nextDouble() {
        return Double.parseDouble(next());
    }
}


