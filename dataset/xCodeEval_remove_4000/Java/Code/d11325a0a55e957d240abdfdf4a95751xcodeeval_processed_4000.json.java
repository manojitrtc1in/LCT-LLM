import javafx.util.Pair;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Short.parseShort;
import static java.lang.Byte.parseByte;
import java.io.*;
import java.util.*;

public class Main {

    static int nextInt() throws IOException {
        return parseInt(next());
    }

    static long nextLong() throws IOException {
        return parseLong(next());
    }

    static short nextShort() throws IOException {
        return parseShort(next());
    }

    static byte nextByte() throws IOException {
        return parseByte(next());
    }

    static String next() throws IOException {
        while (tok == null || !tok.hasMoreTokens())
            tok = new StringTokenizer(in.readLine());
        return tok.nextToken();
    }

    static String nextLine() throws IOException {
        return in.readLine();
    }

    private static BufferedReader in;
    private static StringTokenizer tok;
    private static PrintWriter out = new PrintWriter(System.out);
    private static Utilities doThis = new Utilities(out);
    private static MyMath doMath = new MyMath();
    private static NextPermutation permute = new NextPermutation();
    private static MergeSort mergeSort = new MergeSort();

    public static void main(String[] args) throws Exception {
        in = new BufferedReader(new InputStreamReader(System.in));

        
        solve();
        

        in.close();
        out.close();
    }

    static int max = Integer.MIN_VALUE, min = Integer.MAX_VALUE;
    static long longMax = Long.MAX_VALUE, longMin = Long.MIN_VALUE, longSum = 0, longCount;

    static void solve() throws IOException {
        n = nextInt();
        m = nextInt();

        grid = new char[n][];
        answer = new int[n][m];
        for (int i = 0; i <n ; i++) {
            grid[i] = next().toCharArray();
        }

        visited = new boolean[n][m];

        HashMap<Integer, Integer> sizes = new HashMap<>();
        ArrayList<Pair<Integer, Integer>> id3 = new ArrayList<>();

        int component = 0;
        for (int i = 0; i <n ; i++) {
            for (int k = 0; k <m ; k++) {
                if (grid[i][k]=='.' && !visited[i][k]){
                    size = 0;
                    dfs(i,k, component);
                    sizes.put(component, size);
                    component++;
                }else if (grid[i][k] =='*'){
                    id3.add(new Pair<>(i, k));
                }
            }
        }
        HashSet<Integer> id1 = new HashSet<>();
        for (int i = 0; i <id3.size(); i++) {
            int r = id3.get(i).getKey(), c = id3.get(i).getValue(), ans = 1;
            for (int k = 0; k <dx.length ; k++) {
                r+=dx[k];
                c+=dy[k];
                if (valid(r, c) && grid[r][c] == '.'){
                    id1.add(answer[r][c]);
                }
                r-=dx[k];
                c-=dy[k];
            }
            for (Integer adjacent : id1) {
                ans += sizes.get(adjacent);
            }
            grid[r][c] = (char)((ans%10)+48);
            id1.clear();
        }


        for (int i = 0; i <n ; i++) {
            out.println(grid[i]);
        }

    }
    static int[] dx = {1, -1, 0, 0};
    static int[] dy = {0, 0, 1, -1};

    static int[][] answer;

    static boolean[][] visited;
    static char[][] grid;

    static int size;
    static int n,m;

    static boolean valid(int r , int c) {
        if (r < 0 || c < 0)
            return false;
        return r < n && c < m;
    }

    static void dfs(int r, int c, int component) {
        if (visited[r][c])
            return;

        visited[r][c] = true;

        answer[r][c] = component;

        size++;

        for (int i = 0; i < dx.length; i++) {
            r += dx[i];
            c += dy[i];
            if (valid(r, c) && grid[r][c] == '.') {
                dfs(r, c, component);
            }
            r -= dx[i];
            c -= dy[i];
        }
    }
}
class id6{
    private int[] link;
    private int[] size;
    id6(int[] link, int[] size) {
        this.link = link;
        this.size = size;
        init(this.link);
        init(this.size);
    }
    private void init(int[] arr){
        for (int i = 0; i <arr.length ; i++) {
            arr[i] = i;
        }
    }
    public int find(int x){
        while(x!=link[x])
            x = link[x];
        return x;
    }

    public boolean same(int a, int b){
        return find(a) == find(b);
    }
    public void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (size[a] < size[b]) {
            int temp = a;
            a = b;
            b = temp;
        }
        size[a] += size[b];
        link[b] = a;
    }
}
class IntegerPair implements Comparable<IntegerPair>{
    

    int first;
    int second;
    int value;
    private final int HASH;
    private final String STRING;

    private IntegerPair(int first, int second){
        this.first = first;
        this.second = second;
        STRING = first+" "+second;
        HASH = STRING.hashCode();
    }

    static IntegerPair of(int first, int second){
        return new IntegerPair(first, second);
    }

    @Override
    public boolean equals(Object o){
        if(o == null)
            return false;
        if (! (o instanceof IntegerPair))
            return false;
        if (this == o)
            return true;

        IntegerPair other =(IntegerPair) o;
        if(first == other.first && second == other.second)
            return true;
        return false;
    }

    @Override
    public int compareTo(IntegerPair other) {
        if (second == other.second)
            return first - other.first;
        return second - other.second;
    }

    @Override
    public int hashCode(){
        return HASH;
    }

    @Override
    public String toString(){
        return STRING;
    }
}
class Utilities {
    PrintWriter out;
    Utilities(PrintWriter out){
        this.out = out;
    }
    

    int lowerBound(int[] arr, int low, int high, int element) {
        int middle;
        while (low < high) {
            middle = low + (high - low) / 2;
            if (element > arr[middle])
                low = middle + 1;
            else
                high = middle;
        }
        if (low < arr.length && arr[low] < element)
            return -1;
        return low;
    }

    int upperBound(int[] arr, int low, int high, int element) {
        int middle;
        while (low < high) {
            middle = low + (high - low) / 2;
            if (arr[middle] > element)
                high = middle;
            else
                low = middle + 1;
        }
        if (low<arr.length && arr[low] <= element)
            return -1;
        return low;
    }
    

    

    int lowerBound(long[] arr, int low, int high, long element) {
        int middle;
        while (low < high) {
            middle = low + (high - low) / 2;
            if (element > arr[middle])
                low = middle + 1;
            else
                high = middle;
        }
        if (low < arr.length && arr[low] < element)
            return -1;
        return low;
    }

    int upperBound(long[] arr, int low, int high, long element) {
        int middle;
        while (low < high) {
            middle = low + (high - low) / 2;
            if (arr[middle] > element)
                high = middle;
            else
                low = middle + 1;
        }
        if (low<arr.length &&arr[low] <= element)
            return -1;
        return low;
    }
    

    

    int lowerBound(double[] arr, int low, int high, double element) {
        int middle;
        while (low < high) {
            middle = low + (high - low) / 2;
            if (element > arr[middle])
                low = middle + 1;
            else
                high = middle;
        }
        if (arr[low] < element)
            return -1;
        return low;
    }

    int upperBound(double[] arr, int low, int high, double element) {
        int middle;
        while (low < high) {
            middle = low + (high - low) / 2;
            if (arr[middle] > element)
                high = middle;
            else
                low = middle + 1;
        }
        if (arr[low] <= element)
            return -1;
        return low;
    }
    

    int arrUp(int [][]arr,int i, int j){
        if(i<=0)
            return Integer.MIN_VALUE;
        return arr[i-1][j];
    }
    int arrDown(int [][]arr,int i, int j){
        if(i>=arr.length-1)
            return Integer.MIN_VALUE;
        return arr[i+1][j];
    }
    int arrLeft(int [][]arr,int i, int j){
        if(j<=0)
            return Integer.MIN_VALUE;
        return arr[i][j-1];
    }
    int arrRight(int [][]arr,int i, int j){
        if(j>=arr[i].length-1)
            return Integer.MIN_VALUE;
        return arr[i][j+1];
    }
    


    char arrUp(char [][]arr,int i, int j){
        if(i<=0)
            return '\0';
        return arr[i-1][j];
    }
    char arrDown(char [][]arr,int i, int j){
        if(i>=arr.length-1)
            return '\0';
        return arr[i+1][j];
    }
    char arrLeft(char [][]arr,int i, int j){
        if(j<=0)
            return '\0';
        return arr[i][j-1];
    }
    char arrRight(char [][]arr,int i, int j){
        if(j>=arr[i].length-1)
            return '\0';
        return arr[i][j+1];
    }
    int count(char[] s, char c){
        int count = 0;
        for (int i = 0; i < s.length; i++) {
            if (s[i]==c)
                count++;
        }
        return count;
    }
    void swap(char[] s, int a,int b){
        char temp =s[b];
        s[b]= s[a];
        s[a] = temp;
    }
    void yes(){
        out.println("YES");
    }
    void no() {
        out.println("NO");
    }
    void bad(){
        out.println(-1);
    }
}
class MyMath {
    boolean id4(int a, int b) {
        return gcd(a, b) == 1;
    }

    int gcd(int a, int b) {
        int temp;
        while(b!=0){
            temp = a%b;
            a = b;
            b = temp;
        }
        return a;
    }

    long gcd(long a, long b) {
        long temp;
        while(b!=0){
            temp = a%b;
            a = b;
            b = temp;
        }
        return a;
    }
    long lcm(long a, long b){
        return (a*b)/gcd(a,b);
    }

    int lcm(int a, int b){
        return (a*b)/gcd(a,b);
    }

    int log2(int x) {
        return (int) (Math.log(x) / Math.log(2));
    }
    boolean[] id5(int n) {
        

        

        

        boolean primes[] = new boolean[n+1];
        for(int i=0;i<n;i++)
            primes[i] = true;

        for(int p = 2; p*p <=n; p++)
        {
            

            if(primes[p])
            {
                

                for(int i = p*p; i <= n; i += p)
                    primes[i] = false;
            }
        }
        return primes;
    }
}
class NextPermutation {

    

    

    private int[] swap(int data[], int left, int right) {

        

        int temp = data[left];
        data[left] = data[right];
        data[right] = temp;

        

        return data;
    }

    

    

    

    private int[] reverse(int data[], int left, int right) {

        

        while (left < right) {
            int temp = data[left];
            data[left++] = data[right];
            data[right--] = temp;
        }

        

        return data;
    }

    

    

    boolean id2(int data[]) {

        

        

        

        if (data.length <= 1)
            return false;

        int last = data.length - 2;

        

        

        while (last >= 0) {
            if (data[last] < data[last + 1]) {
                break;
            }
            last--;
        }

        

        

        if (last < 0)
            return false;

        int nextGreater = data.length - 1;

        

        for (int i = data.length - 1; i > last; i--) {
            if (data[i] > data[last]) {
                nextGreater = i;
                break;
            }
        }

        

        data = swap(data, nextGreater, last);

        

        data = reverse(data, last + 1, data.length - 1);

        

        return true;
    }
}
class MergeSort {
    

    

    

    void merge(int arr[], int l, int m, int r) {
        

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
            } else {
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

    

    

    void sort(int[] arr){
        sort(arr, 0, arr.length-1);
    }
    void sort(int arr[], int l, int r) {
        if (l < r) {
            

            int m = (l + r) / 2;

            

            sort(arr, l, m);
            sort(arr, m + 1, r);

            

            merge(arr, l, m, r);
        }
    }
}



class id0<T extends Comparable<T>> {
    private class Node<T extends Comparable<T>> {
        private Node left, right;
        T data;

        Node(T data) {
            this.data = data;
        }

        void insert(T data) {
            if (this.data.compareTo(data) >= 0) {
                if (right == null) {
                    right = new Node(data);
                } else {
                    right.insert(data);
                }
            } else {
                if (left == null) {
                    left = new Node(data);
                } else {
                    left.insert(data);
                }
            }
        }

        boolean contains(T data) {
            if (this.data.equals(data)) {
                return true;
            } else if (this.data.compareTo(data) > 0) {
                if (right == null)
                    return false;
                return right.contains(data);
            } else {
                if (left == null)
                    return false;
                return left.contains(data);
            }
        }
        void id7(){
            if(right !=null){
                right.id7();
            }
            System.out.println(data);
            if (left != null){
                left.id7();
            }
        }
    }

    private Node root;
    private int nodes;
    id0(T data) {
        setRoot(data);
    }

    id0(){

    }
    public void setRoot(T data){
        if(root != null)
            throw new IllegalStateException();
        root = new Node(data);
        nodes++;
    }
    public void insert(T data) {
        root.insert(data);
        nodes++;
    }

    public boolean contains(T data) {
        return root.contains(data);
    }
    public void id7(){
        root.id7();
    }
}