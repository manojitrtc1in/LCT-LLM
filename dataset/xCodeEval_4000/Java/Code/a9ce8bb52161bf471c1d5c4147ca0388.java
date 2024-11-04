

import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class FileHandler {

    BigInteger fib(int n){

        BigInteger a = new BigInteger("1");
        BigInteger b = new BigInteger("1");
        BigInteger s = new BigInteger("2");

        if(n == 1 || n == 2)
            return a;

        for(int i=3;i<=n;i++) {

            s = a.add(b);
            a = b;
            b = s;
        }
        return s;
    }

    boolean isPrime(int n)

    {
        if(n==0) return false;
        return BigInteger.valueOf(n).isProbablePrime(n);
    }

    int nextprime(int n)
    {
        return BigInteger.valueOf(n).nextProbablePrime().intValue();
    }

    void print1toN(int n)
    {
        if(n == 0)
            return;
        System.out.print(n + " ");
        print1toN(n-1);
    }

    void printNto1(int n)
    {
        if(n == 0)
            return;
        printNto1(n-1);
        System.out.print(n + " ");
    }
    int sumNatural(int n , int s)
    {







        

        if(n == 0)
            return n+s;
        s += n;
        return sumNatural(n-1 , s);
    }

    boolean isPalindrome(String s , int i)
    {
        if(s.charAt(s.length() - 1 - i) != s.charAt(i))
            return false;

        if(i == s.length()-1)
            return true;

        i++;

        return isPalindrome(s , i);
    }

    int sumOfDigits(int n)
    {
        if(n == 0)
            return 0;

        return n%10 + sumOfDigits(n/10);
    }

    int ropeCutting(int n , int a, int b , int c)
    {
        if(n == 0)
            return 0;
        if(n < 0)
            return -1;

        int max = Math.max((Math.max(ropeCutting(n-a ,a,b,c), ropeCutting(n-b,a,b,c))), ropeCutting(n-c, a,b,c));

        if(max == -1)
            return -1;

        return ++max;
    }

    void subsets(String s , String t , int i)
    {
        if(i == s.length()){
            System.out.print(t + " ");
            return;
        }
        subsets(s , t , i + 1);
        subsets(s , t + s.charAt(i), i + 1);
    }

    int towerOfHanoy(int n, char a, char b, char c)
    {

        if(n == 1) {
            System.out.println("Move disc 1 from " + a + " to " + c);
            return 1;
        }

        towerOfHanoy(n-1 , a , c , b);
        System.out.println("Move disc " + n + " from " + a + " to " + c);
        towerOfHanoy(n-1 , b , a , c);

        return (int) (Math.pow(2 , n) - 1);
    }

    int countDigits(int n)
    {
        if(n <= 9)
            return 1;
        return 1 + countDigits(n/10);
    }

     boolean isPalin(int N)
    {
        

        

        String s = String.valueOf(N);
        return isPalindrome(s , 0);
    }

    int recursiveGCD(int a, int b)
    {
        if(a == 0) return b;
        if(b == 0) return a;

        if(a > b)
            return recursiveGCD(a%b,b);
        else
            return recursiveGCD(a,b%a);
    }

     void printArrayRecursively(int arr[], int n)
    {
        

        if(n == 0) return;

        printArrayRecursively(arr,n-1);
        System.out.print(arr[n-1] + " ");
    }

    int RecursivePower(int n,int p)
    {
        if(p == 0)
            return 1;
        return n*RecursivePower(n , p-1);
    }

    int sumOfProductOfDigits(int n1, int n2)
    {
        

        if(n1 == 0 || n2 == 0)
            return 0;

        return (n1%10)*(n2%10) + sumOfProductOfDigits(n1/10,n2/10);

    }

    int sumOfMaxandMin(int arr[], int n)
    {
        

        return Arrays.stream(arr).min().getAsInt() + Arrays.stream(arr).max().getAsInt();
    }

    int longestLength(int[] arr, int n)
    {

        int maxLength = 0;
        int pane = 1;

        for(int i=1;i<n;i++){
            if(arr[i] == arr[i-1])
                pane++;
            else{
                maxLength = Math.max(maxLength , pane);
                pane = 1;
            }
        }
        return Math.max(maxLength , pane);
    }

    boolean zeroSum(int[] arr)
    {
        HashSet<Integer> hs = new HashSet<>();
        int ps =0;

        for(int i = 0; i < arr.length; i++){
            ps += arr[i];

            if(ps == 0 || hs.contains(ps))
                return true;
            hs.add(ps);
        }
        return false;
    }

    int longSubarraySum(int[]arr , int target)
    {
        HashMap<Integer,Integer> hm = new HashMap<>();
        int ps=0;
        int max=0;

        for(int i=0;i<arr.length;i++){
            ps += arr[i];

            if(ps == target)
                max = i+1;

            if(!hm.containsKey(ps))
                hm.put(ps , i);

            if(hm.containsKey(ps - target))
                max = Math.max(max , i - hm.get(ps - target) );
        }
        return max;
    }

    int longestZeroSum(int[] arr)
    {
        for(int i = 0; i<arr.length;i++)
            arr[i] = (arr[i] == 0) ? -1 : 1;

        return longSubarraySum(arr, 0);
    }

    int countDistinctelement(int[] arr)
    {
        HashSet<Integer> hs = new HashSet<>();
        for(int i : arr)
            hs.add(i);
        return hs.size();
    }

    void frquenciesOfElements(int[] arr)
    {
        HashMap<Integer , Integer> hm = new HashMap<>();
        for(int i = 0; i < arr.length;i++){
            hm.put(arr[i] , hm.getOrDefault(arr[i] , 0) + 1);
        }
        for(int keys : hm.keySet())
            System.out.println(keys + " --> " + hm.get(keys));
    }

    int binarySearch(long[] arr, int target)
    {
        int h = arr.length - 1;
        int l = 0;
        int mid;

        while(l <= h)
        {
            mid = (h+l)/2;

            if(arr[mid] == target)
                return mid;
            else if(arr[mid] < target)
                l = mid + 1;
            else
                h = mid - 1;
        }
        return -1;
    }

    int binarySearch(int[] arr , int low, int high,int target)
    {

        if(low > high)
            return -1;

        int mid = (low+high)/2;

        if(arr[mid] == target)
            return mid;
        else if(arr[mid] > target)
           return binarySearch(arr , low , mid - 1 , target);
        else
           return binarySearch(arr ,mid + 1 , high , target);
    }

    long sqrt(long n)
    {
        long low = 1;
        long high = n / 2;
        long res = 1;

        while(low <= high)
        {
            long mid = (high+low)/2;
            long sqre = mid*mid;

            if(sqre == n)
                return mid;
            else if(sqre < n){
                low = mid+1;
                res = mid;
            }
            else
                high= mid-1;
        }
        return res;
    }

    int majorityElement(int[] arr)
    {
        int count=0;
        int majority=0;

        for(int i=0;i<arr.length;i++)
        {
            if(count == 0)
                majority = arr[i];

            if(majority == arr[i])
                count++;
            else
                count--;
        }

        int t=0;
        for(int i = 0;i<arr.length;i++)
        {
            if(arr[i] == majority)
                t++;
        }

        if(t > arr.length/2)
            return majority;

        return -1;
    }

    void sortSelection(int[] arr)
    {
        for(int i=0;i<arr.length;i++)
        {
            int min = i;
            int j = i+1;
            while(j < arr.length){
                if(arr[j] < arr[min])
                    min = j;
                j++;
            }
            int t = arr[min];
            arr[min] = arr[i];
            arr[i] = t;
        }
    }

    void sortInsertion(int[] arr)
    {
        for(int i=1;i<arr.length;i++){
            int key = arr[i];

            int j =i - 1;
            while(j >=0 && arr[j] > key){
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = key;
        }
    }

    void combineSort(int[] arr , int low, int mid, int high)
    {
        int n1 = mid - low + 1;
        int n2 = high - mid;

        int[] left = new int[n1];
        int[] right = new int[n2];

        for(int i =0;i<n1;i++)
            left[i] = arr[i+low];

        for(int j=0;j<n2;j++)
            right[j] = arr[mid+1+j];

        int i=0,j=0,k=low;
        while(i < n1 && j < n2)
        {
            if(left[i] < right[j]){
                arr[k] = left[i];
                i++;
            }
            else{
                arr[k] = right[j];
                j++;
            }
            k++;
        }

        while(i < n1) {
            arr[k++] = left[i];
            i++;
        }

        while (j < n2) {
            arr[k++] = right[j];
            j++;
        }
    }

    void mergeSort(int[] arr , int low, int high)
    {
        if(low < high){
            int mid = low + (high-low)/2;

            mergeSort(arr, low, mid);
            mergeSort(arr, mid+1, high);
            combineSort(arr, low, mid, high);
        }
    }

    void commonelements(int[] arr, int[] brr)
    {
        int i=0;
        int j=0;

        while (i < arr.length && j < brr.length) {

            if (i > 0 && arr[i] == arr[i - 1]){
                i++;
            continue;
            }

            if(arr[i] < brr[j])
                i++;
            else if(arr[i] > brr[j])
                j++;
            else{
                if(arr[i] == brr[j]){
                    System.out.print(arr[i] + " ");
                }

                i++;
                j++;
            }
        }
    }

    void unionElements(int[] arr, int[] brr)
    {
        int i = 0;
        int j = 0;

        while (i < arr.length && j < brr.length){

            if(i > 0 && arr[i] == arr[i-1]) {
                i++;
                continue;
            }

            if(j > 0 && brr[j] == brr[j-1]){
                j++;
                continue;
            }

            if(arr[i] < brr[j]){
                System.out.print(arr[i] + " ");
                i++;
            }
            else if(arr[i] > brr[j]){
                System.out.print(brr[j] + " ");
                j++;
            }
            else{
                System.out.print(brr[j] + " ");
                j++;
                i++;
            }
        }

        while(i < arr.length){
            if(arr[i] != arr[i-1])
                System.out.print(arr[i] + " ");
            i++;
        }

        while(j < brr.length){
            if(brr[j] != brr[j-1])
                System.out.print(brr[j] + " ");
            j++;
        }
    }

    int countInversion(int[] arr, int low, int high)
    {
        int res=0;
        if(low < high){

            int mid= (low+high)/2;
            res += countInversion(arr, 0, mid);
            res += countInversion(arr, mid+1, high);
            res += mergeInverse(arr, low, mid, high);
        }
       return res;
    }

    int mergeInverse(int[] arr , int low, int mid, int high)
    {
        int n1 = mid - low + 1;
        int n2 = high - mid;
        int res=0;

        int[] left = new int[n1];
        int[] right = new int[n2];

        for(int i =0;i<n1;i++)
            left[i] = arr[i+low];

        for(int j=0;j<n2;j++)
            right[j] = arr[mid+1+j];

        int i=0,j=0,k=low;
        while(i < n1 && j < n2)
        {
            if(left[i] <= right[j]){
                arr[k] = left[i];
                i++;
            }
            else{
                arr[k] = right[j];
                res += n1 - i;
                j++;
            }
            k++;
        }

        while(i < n1) {
            arr[k++] = left[i];
            i++;
        }

        while (j < n2) {
            arr[k++] = right[j];
            j++;
        }
        return res;
    }

    void twoTypesElementSortHoore(int[] arr){
        int l = 0;
        int r = arr.length - 1;

        while(l < r)
        {
            while(arr[l] < 0 && l < r){
                l++;
            }

            while (arr[r] > 0 && l < r){
                r--;
            }

            if(l < r){
                int t = arr[l];
                arr[l] = arr[r];
                arr[r] = t;
                r--;
                l++;
            }
        }
    }

    void twoTypesElementSortLomuto(int[] arr)
    {
        int i = -1;
       

        int k = Integer.MAX_VALUE;
        for(int j=0;j<arr.length;j++){
            if(arr[j] < k && arr[j] >=0)
                k = arr[j];
        }

        for(int j = 0;j<arr.length - 1;j++){
            if(arr[j] < k){
                i++;
                int t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
            }
        }

        int temp = arr[arr.length - 1];
        arr[arr.length - 1] = arr[i+1];
        arr[i+1] = temp;
    }

    public static int getMaximum(int N, int[] arr) {
        

        long sum = 0;
        for(int i = 0;i<N;i++)
            sum += arr[i];
        while(N > 0)
        {
            if(sum % N == 0)
                return N;
            N--;
        }
        return 1;
    }

    public static boolean check(long A[],long B[],int N)
    {
        

        HashMap<Long , Integer> hm1 = new HashMap<>();
        HashMap<Long , Integer> hm2 = new HashMap<>();

        for(long i : A)
            hm1.put(i, hm1.getOrDefault(i,0)+1);
        for(long i : B)
            hm1.put(i, hm2.getOrDefault(i,0)+1);


        return hm1.equals(hm2);
    }

    public long minValue(long a[], long b[], long n)
    {
        

        Arrays.sort(a);

        int i=0;
        int t = (int) (n-1);
        while(i < t)
        {
            long temp = b[i];
            b[i] = b[t];
            b[t] = temp;

            t--;
            i++;
        }

        long sum =0;

        for(int j=0;j<n;j++)
            sum += a[i]*b[i];

        return sum;
    }

    static ArrayList<Integer> subarraySum(int[] arr, int n, int s) {
        



        ArrayList<Integer> a = new ArrayList<>();
        for (int i = 1; i < n; i++) {
            arr[i] = arr[i - 1] + arr[i];
            

        }

        int left = 0;
        int right = 1;

        if(n == 1 && arr[0] == s){
            a.add(1);
            a.add(1);
            return a;
        }

        while (left <= right && right < n) {
            if (arr[right] == s) {
                a.add(1);
                a.add(right + 1);
                return a;
            }

            if (arr[left] == s) {
                a.add(left + 1);
                a.add(left + 1);
                return a;
            }

            if (arr[right] - arr[left] < s)
                right++;
            else if (arr[right] - arr[left] > s)
                left++;
            else {
                a.add(left + 2);
                a.add(right + 1);
                return a;
            }
        }

        a.add(-1);
        return a;
    }

    static int equilibrium(long[] arr, int n)
    {

































        long totalsum=0;
        long cur_sum=0;

        for(long l : arr)
            totalsum += l;

        for(int i = 0;i< n;i++){

            if(totalsum - arr[i] - cur_sum == cur_sum)
                return i;
            cur_sum += arr[i];
        }
        return -1;
    }

    static ArrayList<Integer> leaders(int arr[], int n){
        


        int l=0;
        int h=n-1;
        while(l <= h)
        {
            int t = arr[l];
            arr[l] = arr[h];
            arr[h] = t;
            h--;
            l++;
        }
        ArrayList<Integer> a = new ArrayList<>();
        a.add(arr[0]);

        int j=0;
        int i=1;
        while(i < n && j < i)
        {
            if(arr[i] >= arr[j]) {
                a.add(arr[i]);
                j = i;
            }
            i++;
        }
        Collections.reverse(a);
        return a;
    }

    int maxLen(int arr[], int n)
    {
        

        HashMap<Integer, Integer> hm = new HashMap<>();
        int cur=0;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            cur += arr[i];
            if(hm.containsKey(cur))
            {
                ans = Math.max(ans , i - hm.get(cur));
            }
            else
                hm.put(cur,i);
        }
        int max = -1;
        for(int i = n-1;i>=0;i--){
            if(arr[i] == 0){
                max = i + 1;
                break;
            }
        }
        return Math.max(ans, max);
    }

    public String isSubset( long a1[], long a2[], long n, long m) {

        HashMap<Long, Integer> hm1 = new HashMap<>();
        HashMap<Long, Integer> hm2 = new HashMap<>();
        for (long l : a1) {
            hm1.put(l, hm1.getOrDefault(l, 0) + 1);
        }

        for (long l : a2) {
            hm2.put(l, hm2.getOrDefault(l, 0) + 1);

        }

        for (long l : a2) {
            if (!hm1.get(l).equals(hm2.get(l)))
                return "No";
        }
        return "Yes";
    }

    String longestCommonPrefix(String arr[], int n){
        

        String s = "";
        int l = findMinLength(arr, n);
        for(int i = 0; i < l;i++)
        {
            char c = arr[0].charAt(i);

            for(int j = 0;j<n;j++){
                if(arr[j].charAt(i) != c)
                    return s;
                s += c;
            }
        }
        return s;
    }

    int findMinLength(String arr[], int n)
    {
        int min = arr[0].length();

        for (int i = 1; i < n; i++)
        {
            if (arr[i].length() < min)
            {
                min = arr[i].length();
            }
        }

        return (min);
    }

    long findSwapValues(long A[], int n, long  B[], int m)
    {
        

        long sa = 0,sb=0;

        Arrays.sort(A);
        Arrays.sort(B);

        for(int i=0;i<n;i++)
            sa+=A[i];

        for(int i=0;i<m;i++)
            sb+=B[i];
        

        if(Math.abs(sa+sb) % 2 == 1)
            return -1;

        long dif = Math.max(sa,sb) - (sa+sb)/2;

        int index=-1;
        for(int i=0;i<n;i++)
        {

            long target = A[i] - dif;

            if(dif > A[i])
                target = A[i];
             index = binarySearch(B, (int)target);
        }

        

        if(index != -1)
            return 1;

        for(int i=0;i<m;i++)
        {
            long target = B[i] - dif;

            if(dif > B[i])
                target = B[i];
            index = binarySearch(A, (int)target);
        }
        

        if(index != -1)
            return 1;

        return -1;
    }

    public static int avgOfString(String s)
    {
        

        int sum = 0;
        for(char c : s.toCharArray())
        {
            sum += c;
        }
        return sum;
    }

    public static String TieBreak(String names[], int n)
    {
        

        HashMap<String, Integer> hm = new HashMap<>();

        for(String name : names){
            hm.put(name , hm.getOrDefault(name,0) +1);
        }
        int max = -1;
        String pname = "";
        String cname = "";
        for(String s : hm.keySet()) {
            int t = hm.get(s);

            if(t > max) {
                pname = s;
                max = t;
            }
            else if(t == max && s.compareTo(pname) < 0)
                pname = s;
        }

        System.out.println(hm);
        return pname;
    }

    public static int sumOfDiff(int arr[], int n)
    {
        

        

        

        Arrays.sort(arr);
        int sum = 0;
        int l = 0;
        int h = n - 1;
        while(l < h)
        {
            sum += Math.abs(arr[l] - arr[h]);
            h--;
            l++;
        }
        if(n%2==1)
            sum += arr[n/2];
        return sum;

    }

    int minSubset(int[] arr,int n) {
        Arrays.sort(arr);
        long sum=0;
        int ans=0;
        long s = 0;

        for(int i : arr)
            s += i;

        for(int i = arr.length - 1; i>=0; i--)
        {
            sum += arr[i];
            ans++;
            if(sum > s - sum)
                break;
        }
        return ans;
    }

    void compareChildandParent()
    {
        Scanner scan = new Scanner(System.in);
        int T = scan.nextInt();

        while(T > 0) {
            String a = scan.next();
            String b = scan.next();

            String parentName = a + b;
            boolean is = true;
            int n = scan.nextInt();
            String[] names = new String[n];

            String concatName="";

            for(int i=0;i<n;i++) {
                names[i] = scan.next();
                concatName += names[i];
            }

            HashMap<Character, Integer> parentHM = new HashMap<>();
            for(char c : parentName.toCharArray())
            {
                parentHM.put(c, parentHM.getOrDefault(c,0)+1);
            }

            HashMap<Character, Integer> childHM = new HashMap<>();
            for(char c : concatName.toCharArray())
            {
                childHM.put(c, childHM.getOrDefault(c,0)+1);
            }

            for(char c : childHM.keySet()){
                if(parentHM.get(c) == null || parentHM.get(c) < childHM.get(c)) {
                    System.out.println("NO");
                    is = false;
                    break;
                }
            }
            if(is)
                System.out.println("YES");

            T--;
        }

    }

    static boolean search(long[] arr)
    {
        for(long l : arr)
            if(l == 0)
                return true;

        return false;
    }

    public int[] findOriginalArray(int[] changed) {

        Arrays.sort(changed);
        ArrayList<Integer> a = new ArrayList<>();

        for(int i=0;i<changed.length;i++)
        {
            if(!a.contains(i))
            {
                int index = binarySearch(changed, i+1,changed.length-1,2*changed[i]);
                


                if(a.contains(index))
                    index = binarySearch(changed,index+1,changed.length-1,2*changed[i]);

                if(index != -1)
                    a.add(index);
            }
        }
        int[] arr = new int[changed.length/2];

        if(2*a.size() != changed.length)
            return new int[0];

        int j=0;
        System.out.println(a.size());
        for(int i=0;i<changed.length;i++){
            if(!a.contains(i)) {
                arr[j] = changed[i];
                j++;
                System.out.print("J " + j);
            }
        }
        return arr;
    }

    public int removeDuplicates(int[] arr) {
        int j=0;
        for(int i=0;i<arr.length-1;i++){
            if(arr[i] != arr[i+1]){
                arr[j] = arr[i];
                j++;
            }
        }
        arr[j] = arr[arr.length-1];
        return j+1;
    }

    public void streamPractise()
    {
        List<Integer> a = Arrays.asList(2,3,4,5,6,7,8);
        a.stream().filter(x->(x%2==0 && x < 5)).forEach(System.out::println);
        int[] arr = {1,2,3,4,5,6,7,8};
        Arrays.stream(arr).filter(x -> x % 2 ==1).forEach(System.out::println);
    }

    void solve()
    {
        Scanner scan = new Scanner(System.in);
        int t = scan.nextInt();
        while(t>0)
        {

            int n = scan.nextInt();
            int[] arr = new int[n];
            int max = -1, min= Integer.MAX_VALUE;
            int index = -1;
            for(int i=0; i<n; i++)
            {
                arr[i] = scan.nextInt();
                if(arr[i] > max)
                {
                    max = arr[i];
                    index = i;
                }

                if(arr[i] < min)
                    min = arr[i];
            }

            if(min == max)
                System.out.println(n);
            else
                System.out.println(index + 1);
            t--;
        }
    }

    public static void main(String[] temp) {

        FileHandler f = new FileHandler();















            f.solve();













































































        

    }

}

