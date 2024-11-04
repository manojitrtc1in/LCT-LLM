import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;
import java.util.Comparator;

public class scratch_25 {
    static class Reader {
        static BufferedReader reader;
        static StringTokenizer tokenizer;

        
        static void init(InputStream input) {
            reader = new BufferedReader(
                    new InputStreamReader(input) );
            tokenizer = new StringTokenizer("");
        }

        
        static String next() throws IOException {
            while ( ! tokenizer.hasMoreTokens() ) {
                

                tokenizer = new StringTokenizer(
                        reader.readLine() );
            }
            return tokenizer.nextToken();
        }

        static int nextInt() throws IOException {
            return Integer.parseInt( next() );
        }

        static double nextDouble() throws IOException {
            return Double.parseDouble( next() );
        }
        static long nextLong() throws IOException{
            return Long.parseLong(next());
        }
    }
    static class pair
    {
        long first, second;
        public pair(long first, long second)
        {
            this.first = first;
            this.second = second;
        }
    }
    



    static long findPowerOfP(long n, long p)
    {
        long count = 0;
        long r = p;
        while (n>0)
        {
            n/=r;

            

            

            count += n ;

            

            


        }
        return count;
    }

    


    



    static long largestPowerOfK(long n, long k)
    {
        Vector<pair > vec = new Vector<pair>();
        vec = primeFactorsofK(k);
        long ans = Long.MAX_VALUE;
        for (int i = 0; i < vec.size(); i++){
          


            

            

            ans = Math.min(ans, findPowerOfP(n,
                    vec.get(i).first) / vec.get(i).second);}

        return ans;
    }
    public static Vector<pair> primeFactorsofK(long n)
    {
        Vector<pair> ans = new Vector<pair>();
        

        long count=0;
        while (n%2==0)
        {
            count++;
           

            n /= 2;
        }
        if(count>0){
        ans.add(new pair(2,count));}

        

        

        for (int i = 3; i <= Math.sqrt(n); i+= 2)
        {
            long count1=0;
            

            while (n%i == 0)
            {
                count1++;
               

                n /= i;
            }
            if(count1>0){
            ans.add(new pair(i,count1));}
        }

        

        

        if(n>2){
            ans.add(new pair(n,1));
        }



        return ans;
    }
    static int longSubarrWthSumDivByK(int arr[],
                                      int n, int k)
    {
        

        

        HashMap<Integer, Integer> um= new HashMap<Integer, Integer>();

        

        int mod_arr[]= new int[n];
        int max = 0;
        int curr_sum = 0;

        

        

        for (int i = 0; i < n; i++)
        {
            curr_sum += arr[i];

            

            

            mod_arr[i] = ((curr_sum % k) + k) % k;
        }

        for (int i = 0; i < n; i++)
        {
            

            

            if (mod_arr[i] == 0)
                

                max = i + 1;

                

                

                

            else if (um.containsKey(mod_arr[i]) == false)
                um.put(mod_arr[i] , i);

            else
                

                if (max < (i - um.get(mod_arr[i])))
                    max = i - um.get(mod_arr[i]);
        }

        

        

        return max;
    }
    static BigInteger count(String a, String b)
    {
        int m = a.length();
        int n = b.length();

        

        

        BigInteger lookup[][] = new BigInteger[m + 1][n + 1];

        

        for (int i = 0; i <= n; ++i)
            lookup[0][i] = BigInteger.valueOf(0);

        

        for (int i = 0; i <= m; ++i)
            lookup[i][0] = BigInteger.valueOf(1);

        

        

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                

                

                

                

                

                

                if (a.charAt(i - 1) == b.charAt(j - 1)) {
                    lookup[i][j] = lookup[i - 1][j - 1].add(lookup[i - 1][j]);
                }

                else
                    

                    

                    

                    lookup[i][j] = lookup[i - 1][j];
            }
        }

        return lookup[m][n];
    }
    public static int findMaxGCD(int arr[], int n)
    {
        

        int high = 0;
        for (int i = 0; i < n; i++)
            high = Math.max(high, arr[i]);

        

        

        int divisors[] =new int[high + 1];

        

        for (int i = 0; i < n; i++)
        {
            

            for (int j = 1; j <= Math.sqrt(arr[i]); j++)
            {
                

                if (arr[i] % j == 0)
                {
                    

                    divisors[j]++;

                    

                    

                    

                    if (j != arr[i] / j)
                        divisors[arr[i] / j]++;
                }
            }
        }

        

        for (int i = high; i >= 1; i--)

            

            

            if (divisors[i] > 1)
                return i;
        return 1;
    }
    public static int gp(long n){
        int count=0;
        while(n%2==0){
            n=n/2;
            count++;
        }
        return count;
















    }
    static class ans{
        int a;
        int b;
        public ans(int a, int b){
            this.a=a;
            this.b=b;

        }
    }
    static class sort implements Comparator<ans>{


        @Override
        public int compare(ans a1,ans a2){
            return a1.a-a2.a;
        }




    }
   









    public static void main(String[] args) throws IOException {
        Reader.init(System.in);
      int n= Reader.nextInt();
      int m= Reader.nextInt();
      char arr[][]= new char[n][m];
      char arr1[][]= new char[n][m];
        for (int i = 0; i <n ; i++) {
            arr[i]=Reader.next().toCharArray();
            arr1[i]=arr[i].clone();
        }











        for (int i = 0; i <n ; i++) {
            for (int j = 0; j <m ; j++) {
                char d= arr[i][j];
                boolean b=true;
                for (int k = j+1; k <m ; k++) {
                    if(Character.compare(d,arr[i][k])==0 && Character.compare(d,'#')!=0){
                        arr[i][k]='#';
                        b=false;
                    }
                }
                if(!b){
                arr[i][j]='#';
            }}
        }










        for (int i = 0; i <m ; i++) {
            for (int j = 0; j <n ; j++) {
                char d= arr1[j][i];
                boolean b1=true;
                for (int k = j+1; k <n ; k++) {
                    if(Character.compare(d,arr1[k][i])==0 && Character.compare(d,'#')!=0){
                        arr1[k][i]='#';
                        b1=false;
                    }
                }
                if(!b1){
                    arr1[j][i]='#';
                }}
            }








        String s="";
char arr3[][]= new char[n][m];
        for (int i = 0; i <n ; i++) {
            for (int j = 0; j <m ; j++) {
                if(Character.compare(arr[i][j],'#')==0 || Character.compare(arr1[i][j],'#')==0){
                    arr3[i][j]='#';
                }
                else{
                    arr3[i][j]=arr1[i][j];
                    s+=arr3[i][j];
                }
            }
        }






        System.out.println(s);












    }














    static void print(int x){
        if(x==0){
            System.out.println("S");
        }
        else if(x==1){
            System.out.println("M");
        }
        else if(x==2){
            System.out.println("L");
        }
        else if(x==3){
            System.out.println("XL");
        }
        else if(x==4){
            System.out.println("XXL");
        }
    }



    static void merge(int arr[], int l, int m, int r)
    {
        

        int n1 = m - l + 1;
        int n2 = r - m;

        
        int L[] = new int [n1];
        int R[] = new int [n2];

        
        for (int i=0; i<n1; ++i)
            L[i] = arr[l + i];
        for (int j=0; j<n2; ++j)
            R[j] = arr[m + 1+ j];


        

        

        int i = 0, j = 0;

        

        int k = l;
        while (i < n1 && j < n2)
        {
            if (L[i] <= R[j])
            {
                arr[k] = L[i];
                i++;
            }
            else
            {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        
        while (i < n1)
        {
            arr[k] = L[i];
            i++;
            k++;
        }

        
        while (j < n2)
        {
            arr[k] = R[j];
            j++;
            k++;
        }
    }

    

    

    static void sort(int arr[], int l, int r)
    {
        if (l < r)
        {
            

            int m = (l+r)/2;

            

            sort(arr, l, m);
            sort(arr , m+1, r);

            

            merge(arr, l, m, r);
        }
    }
    static boolean ans(int check, long arr[],int n,int med,int k){
        long ans=0;
        for (int i = med; i <n ; i++) {
            if(check>=arr[i]){
                ans+=check-arr[i];
            }
        }
        return ans<=k;




    }

    static long smallestDivisor(long n)
    {
        

        if (n % 2 == 0)
            return 2;

        

        for (int i = 3; (long)i *(long) i <= n; i += 2) {
            if (n % i == 0)
                return i;
        }

        return n;
    }
    static boolean isPrime(long n)
    {
        

        if (n <= 1) return false;
        if (n <= 3) return true;

        

        

        if (n % 2 == 0 || n % 3 == 0) return false;

        for (long i = 5; i * i <= n; i = i + 6)
            if (n % i == 0 || n % (i + 2) == 0)
                return false;

        return true;
    }
static BigDecimal fd(int mid, double h, double c){
        BigDecimal a = new BigDecimal((h+c)/(2.0));
        BigDecimal b = new BigDecimal((h-c)/(2.0*mid));
        BigDecimal cd = a.add(b);
        return cd;




}
    static   int partition(double arr[],int arr1[],int arr2[], int low, int high)
    {
        double pivot = arr[high];
        int i = (low-1); 

        for (int j=low; j<high; j++)
        {
            

            if (arr[j] < pivot)
            {
                i++;

                

                double temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                int temp1=arr1[i];
                arr1[i]=arr1[j];
                arr1[j]=temp1;
                int temp2=arr2[i];
                arr2[i]=arr2[j];
                arr2[j]=temp2;

            }
        }

        

        double temp = arr[i+1];
        arr[i+1] = arr[high];
        arr[high] = temp;
        int temp1= arr1[i+1];
        arr1[i+1]=arr1[high];
        arr1[high]= temp1;
        int temp2= arr2[i+1];
        arr2[i+1]=arr2[high];
        arr2[high]= temp2;

        return i+1;
    }


    
    static void sort(double arr[],int arr1[],int arr2[], int low, int high)
    {
        if (low < high)
        {
            
            int pi = partition(arr,arr1,arr2, low, high);

            

            

            sort(arr,arr1,arr2, low, pi-1);
            sort(arr,arr1, arr2,pi+1, high);
        }
    }
    static int removeDuplicates(int arr[], int n)
    {
        

        

        if (n==0 || n==1)
            return n;

        int[] temp = new int[n];

        

        int j = 0;
        for (int i=0; i<n-1; i++)
            

            

            

            if (arr[i] != arr[i+1])
                temp[j++] = arr[i];

        

        

        

        temp[j++] = arr[n-1];

        

        for (int i=0; i<j; i++)
            arr[i] = temp[i];

        return j;
    }
    static long maxPrimeFactors( long n)
    {
        

        

        

        long maxPrime = -1;

        

        

        while (n % 2 == 0) {
            maxPrime = 2;

            

            n >>= 1;
        }

        

        

        

        

        for (int i = 3; i <= Math.sqrt(n); i += 2) {
            while (n % i == 0) {
                maxPrime = i;
                n = n / i;
            }
        }

        

        

        

        if (n > 2)
            maxPrime = n;

        return maxPrime;
    }




}