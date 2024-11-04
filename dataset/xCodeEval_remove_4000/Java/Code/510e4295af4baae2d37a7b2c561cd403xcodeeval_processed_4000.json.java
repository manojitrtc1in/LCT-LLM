

import javax.naming.InsufficientResourcesException;
import java.nio.charset.StandardCharsets;
import java.security.KeyPair;
import java.util.*;


public class dec {










    private static final Scanner in = new Scanner(System.in);

    public static void main(String[] args) throws Exception {

        

        char []abets = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t',
                          'u','v','w','x','y','z' };






        



















        

















        int t=in.nextInt();
        while(t-->0){
            int n = in.nextInt();


            int temp = in.nextInt();;
            int cnt=0;
            for(int i=1;i<n;i++){
                if(in.nextInt()%temp!=0){
                    cnt=1;


                }
            }
            System.out.println(cnt==1 ? "NO":"YES");
        }


    }

    public static void id0(String s, int idx, List<String> path, List<List<String>>ans){

        if(idx == s.length()){
            ans.add(new ArrayList<>(path));
            return;
        }

        for(int i=idx; i<s.length();i++){

            if(isPalindrome(s,idx,i)){   

                path.add(s.substring(idx,i+1));
                id0(s,i+1,path,ans);

                

                path.remove(path.size()-1);
            }
        }
    }















    


















    public static void swapSort(int []a){

        int n = a.length;
        int i=0;
        while(i<n){
            int value = a[i];
            int id2 = value - 1;
            if((i + 1) != value)
            {
                if(a[i] == a[value - 1])   

                {
                    i++;      

                    continue;
                }
                swap(a, i , id2);
            }
            else
            {
                i++;
            }

        }
    }


    


    

    public static int egg(int e,int f,int [][]dp){
        

        if(e==1) return f;
        if(f==0 || f==1) return f;

        if(dp[e][f]!=-1){
            return dp[e][f];
        }

        int ans = Integer.MAX_VALUE;
        

        for(int k=1;k<=f;k++){



            int temp = 1 + Math.max(egg(e-1,k-1,dp), egg(e,f-k,dp));
            


            if(temp < ans){

                ans = temp;
            }
        }
        dp[e][f] = ans;

        return ans;
    }

    

    public static boolean scramble(String a ,String b){








        

        if(a.compareTo(b)==0){
            return true;
        }

        if(a.length()<=1){
            return false;
        }

        int n = a.length();


        

        for(int i=1;i<n;i++) {
            

            

            

            if (scramble(a.substring(0, i), b.substring(0, i)) &&
                    scramble(a.substring(i, n), b.substring(i, n)))
            {
                return true;
            }
            

            

            

            if (scramble(a.substring(n - i, n), b.substring(0, i)) &&
                    scramble(a.substring(0, n - i), b.substring(i, n)))
            {
                return true;


            }
        }

        return false;
    }

    public static int id5(String s, int i, int j,int isTrue,int [][][]dp){











        

        if(i>j){                            

            return 0;
        }

        if(i==j){
            if(isTrue==1){
                return s.charAt(i)=='T' ? 1:0;
            }else{
                return s.charAt(i)=='F' ? 1:0;
            }
        }

        if(dp[i][j][isTrue] != -1){
            return dp[i][j][isTrue];
        }

        

        for(int k=i+1;k<j;k+=2){
            int  lt,lf,rt,rf;
            int ans=0;
            

            if(dp[i][k-1][1]!=-1){
                lt = dp[i][k-1][1];
            }else{

                lt = id5(s, i, k - 1, 1, dp);
            }

            if (dp[i][k - 1][0] != -1) {
                lf = dp[i][k - 1][0];
            }else{

                lf = id5(s, i, k - 1, 0, dp);
            }

            if (dp[k + 1][j][1] != -1) {
                rt = dp[k + 1][j][1];
            }else{

                rt = id5(s, k + 1, j, 1, dp);
            }

            if (dp[k + 1][j][0] != -1) {
                rf = dp[k + 1][j][0];
            } else {

                rf = id5(s, k + 1, j, 0, dp);
            }

            

            if(s.charAt(k)=='&'){
                if(isTrue==1){
                    ans = ans + (lt * rt);
                }else{
                    ans = ans + (lf*rf) + (lf*rt) + (rf*lt);
                }
            }else if(s.charAt(k)=='|'){
                if(isTrue==1){
                    ans = ans + (lt * rt) + (lf*rt) + (rf*lt);
                }else{
                    ans = ans + (lf*rf);
                }
            }else if(s.charAt(k)=='^'){
                if(isTrue==1){
                    ans = ans + (lt * rf) + (rt*lf);
                }else{
                    ans = ans + (lf*rf) + (lt*rt);
                }
            }
        }

        return  ans;
    }

    public static int id8(int []a,int n){
        int [][]dp = new int[n][n];



        int i,j,l;

        

        for(i=1;i<n;i++) dp[i][i]=0;

        

        for(l=2;l<n;l++){

            for(i=1; i<n-l+1;i++){

                j = i + l - 1;
                if(j==n){
                    continue;
                }
                dp[i][j] = Integer.MAX_VALUE;

                for(int k=i;k<j;k++){

                    int ans = dp[i][k] + dp[k+1][j] + (a[i-1]*a[k]*a[j]);

                    if(ans < dp[i][j]){
                        dp[i][j] = ans;
                    }
                }

            }
        }

        return dp[1][n-1];
    }

    public static int ans=Integer.MAX_VALUE;

    public static int palPartition(String s,int i,int j,int [][]dp,int ans){

        

        if(i>=j){                            

            return 0;
        }

        if(isPalindrome(s,i,j)){
            return 0;
        }

        
























        

        for(int k=i;k<j-1;k++){

            int left;
            int right;

            

            if(dp[i][k]!=-1){
                left = dp[i][k];
            }else{
                left = palPartition(s,i,k,dp,ans);
            }

            

            if(dp[k+1][j]!=-1){
                right = dp[k+1][j];
            }else{
                right = palPartition(s,k+1,j,dp,ans);
            }

            int temp = 1 + left + right;

            if(temp < ans){
                ans = temp;
            }
        }

        dp[i][j] = ans;

        return  ans;

    }

    static boolean isPalindrome(String s,int i,int j){
        while(j>=i){
            if(s.charAt(i)!=s.charAt(j)){
                return false;
            }
            else{
                j--;
                i++;
            }
        }
        return true;
    }

    public static int mcm(int []a, int i, int j){




        int ans=Integer.MAX_VALUE;





        

        if(i>=j){                            

            return 0;
        }

        

        for(int k=i;k<j;k++){
            

            int temp = mcm(a,i,k) + mcm(a,k+1,j) + (a[i-1] * a[k] * a[j]);  


            if(temp < ans){
                ans = temp;
            }
        }

        return  ans;
    }

    

    

    public static String id6(String a, String b, int n, int m){

        int [][]dp = new int[n+1][m+1];










        for(int i=0; i<m+1; i++) dp[0][i] = 0;
        for(int i=0; i<n+1; i++) dp[i][0] = 0;

        

        for(int i=1; i<=n; i++) {
            for (int j = 1; j <= m; j++) {

                if (a.charAt(i-1) == b.charAt(j-1)) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = Math.max(dp[i-1][j], dp[i][j - 1]);
                }
            }
        }














































        StringBuilder ans = new StringBuilder();
        int i=n,j=m;

        while(i>0 && j>0){
            if(a.charAt(i-1)==b.charAt(j-1)){
                ans.append(a.charAt(i-1));
                i--;
                j--;
            }else if(dp[i][j-1]>dp[i-1][j]){
                j--;
            }else{
                i--;
            }
        }

        return ans.reverse().toString();

    }

    public static int lcSubstring(String a, String b, int n, int m){

        int [][]dp = new int[n+1][m+1];
        int cnt=0;

        







        for(int i=0; i<m+1; i++) dp[0][i] = 0;
        for(int i=0; i<n+1; i++) dp[i][0] = 0;

        

        for(int i=1; i<=n; i++) {
            for (int j = 1; j <= m; j++) {

                if (a.charAt(i-1) == b.charAt(j-1)) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                    cnt = Math.max(cnt,dp[i][j]);
                } else {
                    dp[i][j] = 0;
                }
            }
        }

        return cnt;

    }

    

    public static int id9(String a, String b, int n, int m){

        int [][]dp = new int[n+1][m+1];

        for(int i=0; i<m+1; i++) dp[0][i] = i;
        for(int i=0; i<n+1; i++) dp[i][0] = i;

        

        for(int i=1; i<=n; i++) {
            for (int j = 1; j <= m; j++) {

                if (a.charAt(i-1) == b.charAt(j-1)) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = Math.min(dp[i-1][j-1]+1, Math.min(dp[i-1][j]+1, dp[i][j - 1]+1));
                }
            }
        }

        return dp[n][m];

    }

    public static int id7(String a, String b, int n, int m){

        int [][]dp = new int[n+1][m+1];

        for(int i=0; i<m+1; i++) dp[0][i] = 0;    

        for(int i=0; i<n+1; i++) dp[i][0] = 1;   


        

        for(int i=1; i<=n; i++) {
            for (int j = 1; j <= m; j++) {

                if (a.charAt(i-1) == b.charAt(j-1)) {
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];  

                } else {
                    dp[i][j] = dp[i-1][j];  

                }
            }
        }

        return dp[n][m];

    }

    public static int lcs(String a, String b, int n, int m){

        int [][]dp = new int[n+1][m+1];

        







        for(int i=0; i<m+1; i++) dp[0][i] = 0;
        for(int i=0; i<n+1; i++) dp[i][0] = 0;

        

        for(int i=1; i<=n; i++) {
            for (int j = 1; j <= m; j++) {

                if (a.charAt(i-1) == b.charAt(j-1)) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = Math.max(dp[i-1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[n][m];

    }

    public static int id1(int []a, int sum, int n){

        int[][]dp = new int[n+1][sum+1];   


        for(int i=0; i<sum+1;i++) dp[0][i] = Integer.MAX_VALUE-1;   

        for(int i=1; i<sum+1;i++) {
            if(i%a[i]==0){
                dp[1][i]= i/a[0];
            }else {
                dp[1][i] = Integer.MAX_VALUE-1;   

            }
        }
        for(int i=0; i<n+1; i++) dp[i][0] = 0;

        for(int i=2;i<=n;i++){
            for(int j=1; j<=sum; j++){

                if(a[i-1]<=j){                  

                    dp[i][j] = Math.min(dp[i][j-a[i-1]] + 1, dp[i-1][j]);
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][sum];
    }




    public static int id3(int []a,int diff){
        int n = a.length;
        int sum=0;
        for(int i=0;i<n;i++) sum += a[i];
        int s1 = (diff+sum)/2;

        return sumSubset(a,s1,n);
    }

    public static int id4(int []a){

        int n = a.length;
        int sum = 0;
        for(int i=0;i<n;i++){
            sum+=a[i];
        }

        int sum_half = sum/2;
        boolean[][] t = new boolean[n+1][sum_half+1];

        for(int i = 0; i<=n; i++){
            for(int j = 0; j<=sum_half; j++) {
                if(i==0)
                    t[i][j]=false;
                if(j==0)
                    t[i][j]=true;
            }
        }


        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=sum_half; j++) {
                if(a[i-1]<=j){
                    t[i][j] = t[i-1][j-a[i-1]] || t[i-1][j];
                } else {
                    t[i][j] = t[i-1][j];
                }
            }
        }



        int min = Integer.MAX_VALUE;
        for(int j = 0; j<=sum_half; j++) {
            if(t[n][j]==true){

                min = Math.min(min, sum - 2 * j);


            }
        }
        return min;
    }

    public static int sumSubset(int []a, int sum, int n){

        int [][]dp = new int[n+1][sum+1];

        for(int i=0;i<sum+1;i++) dp[0][i] = 0;
        for(int i=0;i<n+1;i++) dp[i][0] = 1;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                if(a[i-1]<=j){
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-a[i-1]];
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[n][sum];
    }


    public static int id10(int wt[], int val[],int w, int n)
    {
        int [][]dp = new int[n+1][w+1];

        

        for(int i=0; i<w+1; i++) dp[0][i] = 0;
        for(int j=0; j<n+1; j++) dp[j][0] = 0;

        

        for(int i = 1; i<n+1; i++){
            for(int j=1; j<w+1; j++){
                

                if(wt[i-1] <= j){
                    dp[i][j] = Math.max(val[i-1] + dp[i-1][j-wt[i-1]], 0+dp[i-1][j]);
                }
                

                else if(wt[i-1] > j){
                    dp[i][j] = 0+dp[i-1][j];
                }
            }
        }
        return dp[n][w];
    }



    public ArrayList<Integer> bfs(int v,ArrayList<ArrayList<Integer>> adj){

        ArrayList<Integer> bfs = new ArrayList<>();

        boolean vis[] = new boolean[v+1];

        for(int i=1; i<=v; i++){

            if(vis[i] == false){

                Queue<Integer> q = new LinkedList<>();
                q.add(i);
                vis[i] = true;

                while(!q.isEmpty()){

                    Integer node = q.poll();
                    bfs.add(node);

                    for(Integer it:adj.get(node)){
                        if(vis[it]==false){
                            vis[it]=true;
                            q.add(it);
                        }
                    }
                }
            }
        }

        return bfs;

    }

    public static void reverse(int []a){

        int len = a.length;

        for(int i=0; i<len/2; i++){

            int temp = a[i];
            a[i] = a[len-1-i];
            a[len-1-i] = temp;
        }
    }


    public static void swap (int []arr, int i, int j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    public static void reverse (int []arr, int i, int j){
        while(i<=j){
            swap(arr,i,j);
            i++;
            j--;
        }

    }

    public static int solve(int []b, int []fill, int index) {

        if(index>=b.length){
            return 0;
        }
        if(fill[index]!=-1){
            return fill[index];
        }
        int moni = b[index];
        int alt = index+2;

        moni += solve(b,fill,alt);

        int id11 = solve(b,fill,index+1);

        fill[index] = Math.max(moni,id11);

        return fill[index];

    }

    public static boolean canEat(int []piles, int sph, int h) {
        int t=0;
        for(int i=0; i<piles.length; i++){
            t += (int)Math.ceil(piles[i]*1.0/sph);
        }
        if(t<=h){
            return true;
        }
        return false;
    }
}















































































