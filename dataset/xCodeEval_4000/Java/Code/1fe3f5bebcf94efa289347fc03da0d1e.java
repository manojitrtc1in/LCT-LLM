import java.io.*;
import java.util.*;


 public class Main {
static BufferedReader bf;
static PrintWriter out;
static Scanner sc;
static StringTokenizer st;
static long mod = (long)(1e9+7);
static long mod2 = 998244353;
    
static long fact[] = new long[1000001];
static long inverse[] = new long[1000001];
    public static void main (String[] args)throws IOException {
    bf = new BufferedReader(new InputStreamReader(System.in));
    out = new PrintWriter(System.out);
    sc = new Scanner(System.in);












    int t = nextInt();
    while(t-->0){
        solve();
    
    }
    
}
public static void solve() throws IOException{
    int n = nextInt();
    int x = nextInt();
    int count = 0;
    int min = Integer.MAX_VALUE;
    int max = Integer.MIN_VALUE;
    for(int i = 0;i<n;i++){
        int num = nextInt();
        min = Math.min(min , num);
        max = Math.max(max , num);
        int diff = Math.abs(max - min);
        if(diff > 2 * x){
            count++;
            min = num;
            max = num;

        }
    }
    out.println(count);
    out.flush();
 }




public static boolean allEqual(Long []arr){
    long first=  arr[0];
    for(int i = 0;i<arr.length;i++){
        if(arr[i] != first)return false;
    }
    return true;
}
public static String sum(String s , int k){
    String a = s.substring(0, k);
    String b = s.substring(k , s.length());
    StringBuilder sb = new StringBuilder();
    int i = a.length()-1;
  int j = b.length()-1;
  int carry = 0;
  while(i>=0 && j >=0 ){
    int sum = (a.charAt(i) - '0') + (b.charAt(j) - '0') + carry;
    carry = sum / 10;
    sb.append((sum % 10)+"");
    i--;
    j--;

    
    
  }
  while(i>=0){
    int sum = (a.charAt(i) - '0') + carry;
    carry = sum / 10;
    sb.append((sum % 10) + "");
    i--;
    
  }

  while(j >= 0){
    int sum = (b.charAt(j) - '0') + carry;
    carry = sum  / 10;
    sb.append((sum % 10) + "");
    j--;
  }
  if(carry != 0){
    sb.append(carry + "");
  }
  sb.reverse();
  return sb.toString();
}
public static int compare(String a , String b){
    for(int i = 0;i<a.length();i++){
        if(a.charAt(i)  > b.charAt(i)){
            return 1;
        }
        else if(b.charAt(i) > a.charAt(i))return -1;
    }
    return 0;
}


public static int kmp(StringBuilder sb){
    int[]lbs = new int[sb.length()];
    int j = 0;
    int i = 2;
    while(i < sb.length()){
        if(sb.charAt(j+1) == sb.charAt(i)){
            lbs[i] = (j+ 1);
            j++;
            i++;
        }
        else{
            if(j == 0){
                i++;
            }
            else{
                j = lbs[j];

            }
        }
    }
    return lbs[sb.length()-1];
  


}

public static boolean isPalindrome(String s ,int i,int j){
    while(i <= j){
        if(s.charAt(i) != s.charAt(j))return false;
        i++;
        j--;
    }

    return true;
}
public static boolean check(int[][]arr,int mid){
    int first = mid-1;
    int second = 0;
    int count = 0;
    for(int i = 0;i<arr.length;i++){
        if(arr[i][0] >= first && arr[i][1] >= second){
            second++;
            first--;
            count++;
        }
    }
   
    if(count >= mid)return true;
    return false;
}





public static long helping(Long[][]dp,int i ,int count,int n,long []arr,long[]streak){
if(i == n) return 0;
if(dp[i][count] != null)return dp[i][count];
long empty = 0;
if(count + 1 <= n){
    empty = streak[count+1];
}
long first = arr[i] +empty +  helping(dp,i+1,count+1,n,arr,streak);
long second = helping(dp,i+1,0,n,arr,streak);
return dp[i][count] = Math.max(first,second);
}
public static long max(int node, int left , int right, int tleft,int tright,long[]tree){
if(left >= tleft && right <= tright)return tree[node];
if(right < tleft || left > tright) return 0;
int mid = (left + right)/2;
return Math.max(max(node * 2 , left , mid,tleft,tright ,tree) , max(node * 2 +1 ,mid + 1, right , tleft, tright,tree));

}

public static long help(long[][]dp,List<List<Integer>>list,long[]mid,int cur,int parent,long des[][]){

    List<Integer>temp = list.get(cur);
    long nonTake = 0;
    long take = 0;
    for(int i = 0;i<temp.size();i++){
        int next = temp.get(i);
        if(next != parent){
            help(dp,list,mid,next,cur,des);
            nonTake += Math.min(dp[next][0] + Math.abs(des[cur][1] - des[next][1]) , dp[next][1] + Math.abs(mid[next] - des[cur][1]));
            take += dp[next][0] + Math.abs(mid[cur] - des[next][1]);
        }
    }
    dp[cur][1] = take;
    dp[cur][0] = nonTake;
    

    return Math.min(dp[cur][1],dp[cur][0]);
}

public static long nck(int n,int k){
    return fact[n] * inverse[n-k] %mod * inverse[k]%mod;
}


public static void plus(int node,int low,int high,int tlow,int thigh,int[]tree){
    if(low >= tlow && high <= thigh){
        tree[node]++;
        return;
    }
    if(high < tlow || low > thigh)return;
    int mid = (low + high)/2;
    plus(node*2,low,mid,tlow,thigh,tree);
    plus(node*2 + 1 , mid + 1, high,tlow, thigh,tree);
}

public static boolean allEqual(int[]arr,int x){
    for(int i = 0;i<arr.length;i++){
        if(arr[i] != x)return false;
    }
    return true;
}
public static long helper(StringBuilder sb){
return Long.parseLong(sb.toString());

}
public static int min(int node,int low,int high,int tlow,int thigh,int[][]tree){
    if(low >= tlow&& high <= thigh)return tree[node][0];
    if(high < tlow || low > thigh)return Integer.MAX_VALUE;
    int mid = (low + high)/2;
    

    return Math.min(min(node*2,low,mid,tlow,thigh,tree) ,min(node*2+1,mid+1,high,tlow,thigh,tree));

}

public static int max(int node,int low,int high,int tlow,int thigh,int[][]tree){
    if(low >= tlow && high <= thigh)return tree[node][1];
    if(high < tlow || low > thigh)return Integer.MIN_VALUE;
    int mid = (low + high)/2;
    return Math.max(max(node*2,low,mid,tlow,thigh,tree) ,max(node*2+1,mid+1,high,tlow,thigh,tree));

}







    







public static long[] help(List<List<Integer>>list,int[][]range,int cur){
    List<Integer>temp = list.get(cur);
    if(temp.size() == 0)return new long[]{range[cur][1],1};
    long sum = 0;
    long count = 0;
    for(int i = 0;i<temp.size();i++){
        long []arr = help(list,range,temp.get(i));
        sum += arr[0];
        count += arr[1];
        
    }
    if(sum < range[cur][0]){
        count++;
        sum = range[cur][1];
    }
    return new long[]{sum,count};
}
public static long findSum(int node,int low, int high,int tlow,int thigh,long[]tree,long mod){
    if(low >= tlow && high <= thigh)return tree[node]%mod;
    if(low > thigh || high < tlow)return 0;
    int mid = (low + high)/2;
    return((findSum(node*2,low,mid,tlow,thigh,tree,mod) % mod)  + (findSum(node*2+1,mid+1,high,tlow,thigh,tree,mod)))%mod;
}
public static boolean allzero(long[]arr){
    for(int i =0 ;i<arr.length;i++){
        if(arr[i]!=0)return false;

    }
    return true;
}
public static long count(long[][]dp,int i,int[]arr,int drank,long sum){
    if(i == arr.length)return 0;
    if(dp[i][drank]!=-1 && arr[i]+sum >=0)return dp[i][drank];
    if(sum + arr[i] >= 0){
        long count1 = 1 + count(dp,i+1,arr,drank+1,sum+arr[i]);
        long count2 = count(dp,i+1,arr,drank,sum);
        return  dp[i][drank] = Math.max(count1,count2);
    }
return  dp[i][drank] = count(dp,i+1,arr,drank,sum);

}

public static void help(int[]arr,char[]signs,int l,int r){
    if( l < r){
        int mid = (l+r)/2;
        help(arr,signs,l,mid);
        help(arr,signs,mid+1,r);
        merge(arr,signs,l,mid,r);
    }
}
public static void merge(int[]arr,char[]signs,int l,int mid,int r){
    int n1 = mid - l + 1;
    int n2 = r - mid;
    int[]a = new int[n1];
    int []b = new int[n2];
    char[]asigns = new char[n1];
    char[]bsigns = new char[n2];

    for(int i = 0;i<n1;i++){
        a[i] = arr[i+l];
        asigns[i] = signs[i+l];
    }
    for(int i = 0;i<n2;i++){
        b[i] = arr[i+mid+1];
        bsigns[i] = signs[i+mid+1];
    }
    int i = 0;
    int j = 0;
    int k = l;
    boolean opp = false;
    while(i<n1 && j<n2){
        if(a[i] <= b[j]){
            arr[k] = a[i];
            if(opp){
                if(asigns[i] == 'R'){
                    signs[k] = 'L';
                }
                else{
                    signs[k] = 'R';
                }
            }
            else{
                signs[k] = asigns[i];
            }
            i++;
            k++;
        }
        else{
            arr[k] = b[j];
            int times = n1 - i;
            if(times%2 == 1){
                if(bsigns[j] == 'R'){
                    signs[k] = 'L';
                }
                else{
                    signs[k] = 'R';
                }
            }
            else{
                signs[k] = bsigns[j];
            }
            j++;
            opp = !opp;
            k++;
            
        }
    }
    while(i<n1){
        arr[k] = a[i];
        if(opp){
        if(asigns[i] == 'R'){
            signs[k] = 'L';
        }
        else{
            signs[k] = 'R';
        }
        }
        else{
            signs[k] = asigns[i];
        }
    i++;
    k++;
    }
    while(j<n2){
        arr[k] = b[j];
        
        signs[k] = bsigns[j];
        j++;
        k++;
    }

}









public static long binaryExpo(long base,long expo){
    if(expo == 0)return 1;
    long val;
    if(expo%2 == 1){
    val  = (binaryExpo(base, expo-1)*base)%mod;

    }
    else{
        val = binaryExpo(base, expo/2);
        val  = (val*val)%mod;
    }
    return (val%mod);
}



public static boolean isSorted(int[]arr){
    for(int i =1;i<arr.length;i++){
        if(arr[i] < arr[i-1]){
            return false;
        }

    }
    return true;
}









    

    public static boolean hasCycle(int[]indegree,List<List<Integer>>list,int n,List<Integer>topo){
        Queue<Integer>q  = new LinkedList<>();
        for(int i =1;i<indegree.length;i++){
            if(indegree[i] == 0){
                q.add(i);
                topo.add(i);
            }
        }
        while(!q.isEmpty()){
            int cur = q.poll();
        
            List<Integer>l = list.get(cur);
            for(int i = 0;i<l.size();i++){
                indegree[l.get(i)]--;
                if(indegree[l.get(i)] == 0){
                    q.add(l.get(i));
                    topo.add(l.get(i));
                }
            }
        }
    if(topo.size() == n)return false;
        return true;
    }




    

public static int find(int val,int[]parent){
    if(val == parent[val])return val;
    return parent[val] = find(parent[val],parent);
}




public static void union(int[]rank,int[]parent,int u,int v){
    int a = find(u,parent);
    int b= find(v,parent);
    if(a == b)return;
    if(rank[a] == rank[b]){
        parent[b] = a;
        rank[a]++;
    }
    else{
        if(rank[a] > rank[b]){
            parent[b] = a;
        }
        else{
            parent[a] = b;
        }
    }
}


public static int findN(int n){
    int num = 1;
    while(num < n){
        num *=2;
    }
    return num;
}








public static void  print(String s ){
    System.out.print(s);
}
public static void  print(int num ){
    System.out.print(num);
}
public static void  print(long num ){
    System.out.print(num);
}
public static void println(String s){
    System.out.println(s);
}
public static void println(int num){
    System.out.println(num);
}
public static void println(long num){
    System.out.println(num);
}
public static void println(){
    System.out.println();
}

public static int Int(String s){
    return Integer.parseInt(s);
}
public static long Long(String s){
    return Long.parseLong(s);
}
public static String[] nextStringArray()throws IOException{
    return  bf.readLine().split(" ");
}


public static String nextString()throws IOException{
    return bf.readLine();
}

public static long[] nextLongArray(int n)throws IOException{
    String[]str = bf.readLine().split(" ");
    long[]arr = new long[n];
    for(int i =0;i<n;i++){
        arr[i] = Long.parseLong(str[i]);
    }
    return arr;
}
public static int[][] newIntMatrix(int r,int c)throws IOException{
    int[][]arr = new int[r][c];
    for(int i =0;i<r;i++){
        String[]str = bf.readLine().split(" ");
        for(int j =0;j<c;j++){
            arr[i][j] = Integer.parseInt(str[j]);
        }
        }
        return arr;
}

public static long[][] newLongMatrix(int r,int c)throws IOException{
    long[][]arr = new long[r][c];
    for(int i =0;i<r;i++){
        String[]str = bf.readLine().split(" ");
        for(int j =0;j<c;j++){
            arr[i][j] = Long.parseLong(str[j]);
        }
        }
        return arr;
}

static class pair{
    int one;
    int two;
    pair(int one,int two){
        this.one = one ;
        this.two =two;
    }
}
public static long gcd(long a,long b){
    if(b == 0)return a;
    return gcd(b,a%b);
}


public static long lcm(long a,long b){
    return (a*b)/(gcd(a,b));
}
public static boolean isPalindrome(String s){
    int i = 0;
    int j = s.length()-1;
    while(i<=j){
        if(s.charAt(i) != s.charAt(j)){
            return false;
        }
        i++;
        j--;
    }
    return true;
}



public static void sort(int[]arr,int l,int r){
    if(l < r){
        int mid  = (l+r)/2;
        sort(arr,l,mid);
        sort(arr,mid+1,r);
        smallerNumberAfterSelf(arr, l, mid, r);
    }
}
public static void smallerNumberAfterSelf(int[]arr,int l,int mid,int r){
    int n1 = mid - l +1;
    int n2 = r - mid;
    int []a = new int[n1];
    int[]b = new int[n2];
    for(int i = 0;i<n1;i++){
        a[i] = arr[l+i];
    }
    for(int i =0;i<n2;i++){
        b[i] = arr[mid+i+1];
    }
    int i = 0;
    int j =0;
    int k = l;
    while(i<n1 && j < n2){
        if(a[i] < b[j]){
            arr[k++] = a[i++];
        }
        else{
            arr[k++] = b[j++];
        }

    }
    while(i<n1){
        arr[k++] = a[i++];
    }
    while(j<n2){
        arr[k++] = b[j++];
    }
    
    
    
}
public static String next(){
    while (st == null || !st.hasMoreElements()) {
        try {
            st = new StringTokenizer(bf.readLine());
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    return st.nextToken();
}
static int nextInt() {
    return Integer.parseInt(next());
}

static long nextLong() {
    return Long.parseLong(next());
}

static double nextDouble() {
    return Double.parseDouble(next());
}

static String nextLine(){
    String str = "";
try {
str = bf.readLine();
} catch (IOException e) {
e.printStackTrace();
}
return str;
}

}























































