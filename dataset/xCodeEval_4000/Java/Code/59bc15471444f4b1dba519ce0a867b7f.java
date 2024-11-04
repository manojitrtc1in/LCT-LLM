import java.io.*;
import java.nio.charset.StandardCharsets;
import java.util.*;


import java.util.List;

import static java.lang.Math.*;

public class ACM {
    static int MOD= 1000000007 ;
    public static void main(String args[]) throws FileNotFoundException, IOException, Exception {


        StringBuilder out = new StringBuilder();
        StringTokenizer tk;
        Reader.init(System.in);
        int t = Reader.nextInt();

        while(t-->0){
            HashMap<Integer, Integer> num = new HashMap<>();
            

            num.put(0,0);
            num.put(1,0);
            num.put(2,0);
            num.put(3,0);
            num.put(4,0);
            num.put(5,0);
            num.put(6,0);
            num.put(7,0);
            num.put(8,0);
            num.put(9,0);

            List<Integer> list=new ArrayList<>();
            int n = Reader.nextInt();
            int arr[] = new int[n];
            for (int i = 0; i < n; i++) {
                arr[i] = Reader.nextInt();
                if (num.containsKey(arr[i])) {
                    num.put( arr[i], num.get(arr[i]) + 1);
                }
            }
            for ( int key : num.keySet() ) {
                if(num.get(key) == 0)
                    list.add(key);
            }
            















            int summ =list.size()-1;
            System.out.println(6*((summ*(summ+1))/2));
        }


    }
















































    static int gcd(int a, int b)
    {
        

        int i;
        if (a < b)
            i = a;
        else
            i = b;

        

        for (i = i; i > 1; i--) {

            

            

            

            if (a % i == 0 && b % i == 0)
                return i;
        }

        

        

        return 1;
    }


    public static int change(int[] arr, int[] arr2){
        int count=0;
        int che= max(sum(arr),sum(arr2))- min(sum(arr),sum(arr2));
        for (int i = 0; i < arr.length; i++) {
            if(count==che)
                break;
            if(arr[i] != arr2[i]){
                if(arr[i]>arr2[i])
                    arr[i]--;
                else
                    arr2[i]--;
                count++;
                if(sum(arr) == sum(arr2))
                    break;
            }
        }
        return count;
    }
    public static int sum(int [] arr){
        int sum = 0;
        for (int i = 0; i < arr.length; i++)
            sum += arr[i];

        return sum;
    }

    public static boolean check (int [] arr, int [] arr2){
        for (int i = 0; i < arr.length; i++) {
            if(arr[i] != arr2[i])
                return false;
        }
        return true;
    }









































    public static long findMaximumSum(List<Integer> stockPrice, int k) {

        if(stockPrice.size()==k)
            return -1;

        ArrayList<Integer>  list = new ArrayList<Integer>();
        int sum=0;
        

        int cc=0;
        for (int i = 0; i < k; i++) {
            sum=0;
            int count=0;
            for (int j = cc; j < stockPrice.size(); j++) {

                if(count==k) {
                    cc=j;
                    System.out.println(cc);
                    break;
                }

                if(j+k < stockPrice.size()) {
                    sum += stockPrice.get(j);
                   System.out.println(stockPrice.get(j));
                }
                else {
                    j -= (j+k)-stockPrice.size();
                    j--;
                }

                count++;
            }
            System.out.println("*********");
            list.add(sum);
        }

        System.out.println(list);

        return sum;
    }


    public static int minimumKeypadClickCount(String text) {
        char[] ch = text.toCharArray();
       HashMap<Character,Integer> alp= new HashMap<>();

        for (int i = 0; i < ch.length; i++) {

            if(alp.containsKey(ch[i]))
                alp.put(ch[i],alp.get(ch[i])+1);

            else
                alp.put(ch[i],1);
        }




        Object[] value = alp.values().toArray();
        int [] values = new int[value.length];


        for (int i = 0; i < value.length; i++) {
           values[i]=(int)value[i];
        }









        Arrays.sort(values);

        int [] valuesDis=new int[values.length];
        int j=0;
        for (int i = values.length-1; i >=0; i--,j++) {
            valuesDis[j]=values[i];
        }








        int sum=0;
        for (int i = 0; i < valuesDis.length; i++) {
            if(i<9) {
                sum += valuesDis[i];
                

            }
            else if(i<18) {
                sum += (valuesDis[i] * 2);
                

            }
            else
                sum+=(valuesDis[i]*3);
        }












        return sum;

    }

    public static int binary(ArrayList<Integer> arr, int x)
    {
        int low = 0, high = arr.size() - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (arr.get(mid) <= x)
                low = mid + 1;
            else if (arr.get(mid) > x &&
                    arr.get(mid) <= x)
                return mid;
            else if (arr.get(mid) > x && mid == 0)
                return mid;
            else
                high = mid - 1;
        }
        return -1;
    }


    public static boolean PrimeNumber(double num)
    {
        double n=num/6;
        if(n<Math.round(n))
        {
            n=6*(Math.round(n))-1;
            if(n==num)
                return true;
            else
                return false;
        }
        else
        {
            n=6*(Math.round(n))+1;
            if(n==num)
                return true;
        }
        return false;
    }

public static boolean ch(int [] arr){
    if(arr[0]==arr[1] && arr[2]%2==0)
        return true;
    else if(arr[0]==arr[2] && arr[1]%2==0)
        return true;
    else if(arr[2]==arr[1] && arr[0]%2==0)
        return true;

    return false;
}



    public static int countways(int arr[])
    {
        int arr1[] = new int[arr.length];
        int sum = 0;
        for (int i = 0 ; i < arr.length ; i++)
        {
            sum += arr[i];
        }

        if (sum % 3 != 0)
            return 0;

        sum /= 3;
        int count=0;

        for (int i = 0; i < arr.length; i++) {

            for (int j = i; j < arr.length; j++) {
                if(arr[i]==sum) {
                    count++;
                    break;
                }
                else{

                }
            }
        }



        return count;
    }


    public static boolean isRectangle(int a, int b,
                                      int c, int d)
    {
        

        if (a == b && a == c &&
                a == d && c == d &&
                b == c && b == d)
            return true;

        else if (a == b && c == d)
            return true;
        else if (a == d && c == b)
            return true;
        else if (a == c && d == b)
            return true;
        else
            return false;
    }


    public static int prowr(int x,int b){
        int res=1;
        while(b>0){
            if(b%2 !=0 ){
                res=mul(res,x);
            }
            b/=2;

            x=mul(x,x);
        }
        return res;
    }

    public static int mul(int a,int b){
        return a*b%1000000007;
    }

    public static int sumList(ArrayList<Integer> s){
        int sum=0;
        for (int i = 0; i < s.size(); i++) {
            sum+=s.get(i);
        }
        return sum;
    }
    static boolean isSquare(int num)
    {
        int root = (int)Math.sqrt(num);
        return (root * root) == num;
    }


    static boolean isCube(int num)
    {
        int root = (int)Math.cbrt(num);
        return (root * root *
                root) == num;
    }


    static int countSC(int N)
    {
        int count = 0;
        for (int i = 1; i <= N; i++)
        {

            

            

            if (isSquare(i))
                count++;

                

                

            else if (isCube(i))
                count++;
        }

        return count;
    }


    public static int __gcd(int a, int b)
    {
        return b == 0 ? a :
                __gcd(b, a % b);
    }


    public static boolean coprime(int a, int b)
    {
        return (__gcd(a, b) == 1);
    }


    public static void pairSu(int n)
    {

        int mid = n / 2;

        for (int i = mid; i >= 1; i--) {
            if (coprime(i, n - i) == true) {
                System.out.println(i + " " + (n - i)+" "+1);
                break;
            }
        }
    }

    static int binarysearch(Vector<Integer> v, int x)
    {
        int low = 0, high = v.size() - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (v.get(mid) <= x)
                low = mid + 1;
            else if (v.get(mid) > x &&
                    v.get(mid) <= x)
                return mid;
            else if (v.get(mid) > x && mid == 0)
                return mid;
            else
                high = mid - 1;
        }
        return -1;
    }


    static int CountContiguousParts(int arr[], int n)
    {
        int count = 0; 


        

        int []prefix = new int[n];
        prefix[0] = arr[0];
        for (int i = 1; i < n; i++)
            prefix[i] = prefix[i - 1] + arr[i];

        

        

        int total_sum = prefix[n - 1];

        

        

        

        if (total_sum % 3 != 0)
            return 0;

        

        int []suffix = new int[n];
        suffix[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--)
            suffix[i] = suffix[i + 1] + arr[i];

        

        

        Vector<Integer> v = new Vector<>();
        for (int i = 0; i < n; i++)
            if (suffix[i] == total_sum / 3)
                v.add(i);

        

        

        for (int i = 0; i < n; i++)
        {
            

            if (prefix[i] == total_sum / 3)
            {
                

                

                int res = binarysearch(v, i + 1);

                if (res != -1)
                    count += v.size() - res;
            }
        }
        return count;
    }

    public static String sortString(String inputString)
    {
        

        char tempArray[] = inputString.toCharArray();

        

        Arrays.sort(tempArray);

        

        return new String(tempArray);
    }


    public static String findSmallestString(String str1, String str2)
    {
        int []freq1 = new int[26];
        int []freq2 = new int[26];
        Arrays.fill(freq1, 0);
        Arrays.fill(freq2, 0);

        

        int n1 = str1.length();
        int n2 = str2.length();

        

        

        for(int i = 0; i < n1; ++i)
        {
            freq1[str1.charAt(i) - 'a']++;
        }

        

        

        for(int i = 0; i < n2; ++i)
        {
            freq2[str2.charAt(i) - 'a']++;
        }

        

        

        

        for(int i = 0; i < 26; ++i)
        {
            freq1[i] -= freq2[i];
        }

        

        String res = "";

        

        

        int minIndex = str2.charAt(0) - 'a';

        

        

        for(int i = 0; i < 26; ++i)
        {

            

            

            for(int j = 0; j < freq1[i]; ++j)
            {
                res += (char)(i + 'a');
            }

            

            

            if (i == minIndex)
            {
                res += str2;
            }
        }

        

        return res;
    }

    public static String remove(String s, int a){
        String ss  = "";
        for (int i = 0; i <s.length() ; i++) {
            if(i == a){
                break;
            }
            else{
                ss += s.charAt(i);
            }
        }
        return ss;
    }

    public static void test(){
        for (int j = 0; j < 10; j++) {

        }
        for (int j = 0; j < 20; j++) {

        }
    }

    public static void find3Numbers(int arr[])
    {
        int sum=arr[arr.length-1];

        first:
        for (int i = 0; i < arr.length - 2; i++) {

            for (int j = i + 1; j < arr.length - 1; j++) {

                for (int k = j + 1; k < arr.length; k++) {

                    if (arr[i] + arr[j] + arr[k] == sum) {
                        System.out.println(arr[i] + " " + arr[j] + " " + arr[k]);
                        break first;
                    }
                }
            }
        }
    }

    static int[] reverse(int a[])
    {
        int[] b = new int[a.length];
        int j = a.length;
        for (int i = 0; i < a.length; i++) {
            b[j - 1] = a[i];
            j = j - 1;
        }

        

        return b;
    }


    public static int [] eversionsArray(int [] arr){
        int x=arr[arr.length-1];
        int [] allArr=new int [arr.length];
        ArrayList<Integer> small= new ArrayList<>();
        ArrayList<Integer> big= new ArrayList<>();
        for (int i = 0; i < arr.length; i++) {
            if(arr[i]<=x)
                small.add(arr[i]);
            else
                big.add(arr[i]);
        }
        for (int i = 0; i < small.size(); i++) {
            allArr[i]=small.get(i);
        }
        int j=0;
        for (int i = small.size(); j < big.size(); i++) {
            allArr[i]=big.get(j);
            j++;
        }
        return allArr;
    }

    public static String buildTheArray(int n,int a,int b){
        int [] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i]=i+1;
        }
        return buildThePermutation(arr,a,b);
    }

    public static String buildThePermutation(int [] arr,int a,int b){
        if(a*3>arr.length)
            return "-1";
        else if(b*3>arr.length)
            return "-1";

        int n=arr.length-1;
        int count=0;
        for (int j = 0; j < arr.length; j+=2) {
            int temp=arr[j+1];
            arr[j+1]=arr[n];
            n-=1;
            arr[n+1]=temp;
            count++;
            if(count==a)
                break;
        }
           
        String s="";
        for (int i = 0; i < arr.length; i++) {
            s+=arr[i]+" ";
        }
        return s;
    }

    public static void sort(String a[], int n)
    {

        

        for(int i = 0;i < n;i++)
        {
            for(int j = i + 1;j < n;j++)
            {

                

                

                

                

                if((a[i] + a[j]).compareTo(a[j] + a[i]) > 0)
                {
                    String s = a[i];
                    a[i] = a[j];
                    a[j] = s;
                }
            }
        }
    }

    public static int sumList(List<Integer> s){
        int sum=0;

        for (int i = 0; i < s.size(); i++) {
            sum+=s.get(i);
        }
        return sum;
    }

    public static int makeItIntger(String s){
        int count=0;

        if(Character.getNumericValue(s.charAt(0))%2==0){
            count++;
            return count;
        }
        count =2;
        return count;
    }

    public static boolean checkAllOdd(String s){
        int number=Integer.parseInt(s);
        for (int i = 0; i < s.length(); i++) {
            int num=number%10;
            if(num%2==0)
                return false;

            number/=10;
        }
        return true;
    }

    public static int solv(ArrayList<Integer>a){
        int sum=0;
        for (int i = 1; i < a.size(); i++) {
            sum+= abs(a.get(i)-a.get(i-1));
        }
        return sum;
    }

    static void solve() throws IOException {
        int n=Reader.nextInt();
        for (int i = 0; i < n; i++) {
            if (Reader.nextInt() != Reader.nextInt()) {
                System.out.println("Happy Alex");
                return;
            }
        }
        System.out.println("Poor Alex");
    }

    static String  xoring(String a, String b){
        String ans = "";
        for (int i = 0; i < a.length(); i++) {
            if (a.charAt(i) == b.charAt(i))
                ans += "0";
            else
                ans += "1";
        }
        return ans;
    }

    static String or(String a , String b){
        String ans = "";
        for (int i = 0; i <a.length() ; i++) {
            if(a.charAt(i) == b.charAt(i)){
                ans += (a.charAt(i));
            }
            else{
                ans += "1";
            }
        }
        return ans;
    }

    public static int  odd(int []a){
        int sum=0;
        for (int i = 0; i < a.length-2; i+=2) {
            

            sum+= abs(a[i]-a[i+2]);
            System.out.println("ood "+sum);

        }
        return sum;
    }

    public static int even(int []a){
        int sum=0;
        for (int i = 1; i < a.length-2; i+=2) {
            

            sum+= abs(a[i]-a[i+2]);
            System.out.println("even "+ abs(a[i]-a[i+2]));
        }
        return sum;
    }

    public static Boolean areDistinct(String str, int i, int j)
    {
        boolean[] visited = new boolean[26];
        for(int k = i; k <= j; k++)
        {
            if (visited[str.charAt(k) - 'a'] == true)
                return false;
            visited[str.charAt(k) - 'a'] = true;
        }
        return true;
    }

    public static int longestUniqueSubsttr(String str)
    {
        int n = str.length();
        int res = 0;
        for(int i = 0; i < n; i++)
            for(int j = i; j < n; j++)
                if (areDistinct(str, i, j))
                    res = max(res, j - i + 1);
        return res;
    }

    public static int test1(int b,int a){
        return test2(a+b);
    }

    public static int test2 (int b){
        b+=b++;
        return b;
    }

    private static String GeneratorString(int n,int a,int b){
        char c='a';
        String str="";
        for (int i = 0; i < n; i++) {
            str += c++;
        }
        for (int i = 0; i < (n-a)+1; i++) {
            String str2=str.substring(i,a);
            HashSet<Character> HS=new HashSet<>();
            for (int j = 0; j <str2.length(); j++) {
                HS.add(str2.charAt(i));
            }
            if(HS.size()==b) {
                str2 = "";
                HS.clear();
            }
            else{
                str2.replace(str2.charAt(str2.length()-1),str2.charAt(0));
                str.replace(str.charAt((a+i)-1),str2.charAt(str2.length()-1));
                str2="";
                HS.clear();
            }
        }
        return str;
    }

    public static long OrangeAndCandy(int Candy , int Orange , int minForC , int minForO){
        long count=0;
        int max = max(minForC,minForO);
        int a=Orange-minForO;
        int b=Candy-minForC;
        int min= min(a,b);
        Orange-=min;
        Candy-=min;
        count+=min;

        if(Candy>minForC && Orange==minForO)
            count+=Candy( Candy ,  Orange ,  minForC ,  minForO);
        else
            count+=Orange( Candy ,  Orange ,  minForC ,  minForO);

        return count;
    }

    public static long Orange(int Candy , int Orange , int minForC , int minForO){
        long count=Orange-minForO;;
        return count;
    }
    public static long Candy(int Candy , int Orange , int minForC , int minForO){
        long count=Candy-minForC;
        return count;
    }

    public static long gcd(long a, long b)
    {
        if (a == 0)
            return b;
        if (b == 0)
            return a;

        if (a == b)
            return a;

        if (a > b)
            return gcd(a-b, b);
        return gcd(a, b-a);
    }

    public static ArrayList<Integer> makeRound(int num){
        ArrayList <Integer> arr=new ArrayList<>();
        int count=0;
        int j=num;
        while(count>=0){
            j/=10;
            count++;
            if(j<=0)
                break;
        }
        num=Reverse(num);
        

        while(num>0){
            int f=num%10;
            num/=10;
            count--;
            arr.add((int) (f* pow(10,count)));
        }
        

        return arr;
    }

    public static boolean isRound(Integer num){
        if(num>0 && num<10)
            return true;
        else{
            String s=  num.toString();
            for (int i = s.length()-1; i > 0; i--) {
                if(s.charAt(i) != '0') {
                    

                    return false;
                }
            }
        }
        return true;
    }

    public static int Reverse(int num){
        int reversed = 0;
        while(num != 0) {
            int digit = num % 10;
            reversed = reversed * 10 + digit;
            num /= 10;
        }
        return reversed;
    }

   

}
class Reader {

    static BufferedReader reader;
    static StringTokenizer tokenizer;

    static void init(InputStream input) throws UnsupportedEncodingException {
        reader = new BufferedReader(
                new InputStreamReader(input, "UTF-8"));
        tokenizer = new StringTokenizer("");
    }

    static String next() throws IOException {
        while (!tokenizer.hasMoreTokens()) {
            

            tokenizer = new StringTokenizer(
                    reader.readLine());
        }
        return tokenizer.nextToken();
    }

    static String nextLine() throws IOException {
        return reader.readLine();
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
class pair implements Comparable<pair> {
    Integer first, second;

    pair() {
    }

    pair(Integer a, Integer b) {
        first = a;
        second = b;
    }

    @Override
    public int compareTo(pair o) {
        return 0;
    }
}
