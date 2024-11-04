



import java.util.*;

import java.lang.*;

import java.io.*;

import java.math.*;

public class Main
{    
    public static long[] array = new long[1000001];

    

    
    public static int swap1(int[][] student, int[][] professor, int[] student_list, int[] professor_list,int curr_prof,int stud, int prof, int n, int flag){

                        int j3=1;
        
                        

        
                        while(j3<n+1){
        
                            if(student[stud][j3]==prof){
        
                                flag=1;
        
                                break;
        
                            }
        
                            else if(student[stud][j3]==curr_prof){
        
                                break;
        
                            }
        
                            j3++;
        
                        }
                        return flag;

    }        
    
    public static void swap3(int[] student_list, int[] professor_list, int stud, int prof, int curr_prof){
     
        student_list[stud]=prof; professor_list[curr_prof]=0; professor_list[prof]=1;
    
    }

    public static void filling1(long[] array1,long left,long right,long[] array,long[] aux){
        array1[0]=left;
        while(array1[0]<right+1){
            array[(int)array1[0]]=aux[(int)array1[0]];
            array1[0]=array1[0]+1;
        }
    }

    public static void swap5(int[] student_list, int[] professor_list, int[][] student, int[][] professor, int n, int total){

        int num=0;
            
        while(num!=total){
        
                int prof = 0;
        
                int j1=1;
        
                prof=swap2(j1,professor_list,prof,n);
        
                int j2=1;
                
                ArrayList<Integer> list = new ArrayList<Integer>();

                while(j2<n+1){
        
                    int stud = professor[prof][j2];
        
                    if(student_list[stud]!=0){
        
                        int curr_prof = student_list[stud];
                        
                        int flag=0;
        
                        flag=swap1(student,professor,student_list,professor_list,curr_prof,stud,prof,n,flag);


                        if(flag!=0){
        
                            swap3(student_list,professor_list,stud,prof,curr_prof);

                            break;
        
                        }
        
                    }
        
                    else{
                        
                        total = swap4(professor_list,student_list,prof,stud,total);
        
                        break;
        
                    }
        
                    j2++;
        
                }
        
            }
        
    }

    public static int max_sum(int[][] array,int i, int j,int n,boolean[][] array2){
        
        int sum=array[i][j];
        if(i>n || j>n){
            

            return 0;
        }else if(array2[i][j]==true){
            

            return sum;
        }else{
            array[i][j]=Math.max(max_sum(array,i+1,j,n,array2),max_sum(array,i,j+1,n,array2));
            array2[i][j]=true;
            return array[i][j];
        }
        
    }

    public static void filling3(long[] array1,long[] array,long[] aux,long right){
        while(array1[1]<right+1){
            aux[(int)array1[2]]=array[(int)array1[1]];
            array1[2]=array1[2]+1;
            array1[1]=array1[1]+1;
        }
    }

    public static void mergesort(long[] array, long left, long right, long size,long[] aux){
        long count=0;
        if(left<right){
            long mid = (left+right)/2;
            mergesort(array,mid+1,right,size,aux);
            mergesort(array,left,mid,size,aux);            
            merge(array,left,mid+1,right,size,aux);
            

        }
        

    }

    public static void update(int[] a1, int[] a2 , int n){
        
        for(int i=1;i<n+1;i++){
        
            a1[a2[i]]=i;
        
        }
    }

    public static long checking(long j){
        if(j==1){
            return 0;
        }
        else{
            if(j%2!=0){
                return 1+checking(3*j+1);
            }else{
                return 1+checking(j/2);
            }
        }
    }

    public static long horse_path(long n, long m, long start1, long start2){
        if(n==start1 && start2==m){
            return 0;
        }else if(start1>n || start2>m){
            return -1;
        }else{
            long a,b;
            if(horse_path(n,m,start1+2,start2+1)==-1){
                a = 0+horse_path(n,m,start1+2,start2+1);
            }else{
                a=1+horse_path(n,m,start1+2,start2+1);
            }
            if(horse_path(n,m,start1+1,start2+2)==-1){
                b = 0+horse_path(n,m,start1+1,start2+2);
            }else{
                b=1+horse_path(n,m,start1+1,start2+2);
            }
            return min_val(a,b);
        }
    }

    public static long looping(long[] array, int n, int i, long maximum, long value1, long value2){
        while(i<n){
            long temp=value2+array[i];
            maximum =  max(temp,value1);
            value2=store(array,n,value1);
            value1=store(array,n,maximum);
            i++;
        }
        return maximum;
    }

    public static void Result(long value){
        
        System.out.println(value);
    
    }

    public static long store(long[] array,int n,long a){
        return a;
    }

    public static long storing(long n){
        long count = 0;
        while(n!=1){
            if(n%2==0){
                count++;
                n=n/2;
            }else{
                count++;
                n=3*n+1;
            }
        }
        return count;        
    }

    public static long min_val(long a, long b){
        if(a>b){
            return a;
        }else{
            return b;
        }
    }


    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long[] array=new long[n+1];
        for(int i=1;i<n+1;i++){
            array[i]=sc.nextLong();
        }
        long odd = 0;
        long even =0;
        for(int kk=1;kk<n+1;kk++){
            if(kk%2!=0){
                odd+=array[kk];
            }else{
                even+=array[kk];
            }
        }
        long sum1=0;
        long sum2=0;
        long c=0;
        long ans1=0;
        long ans2=0;
        for(int j=1;j<n+1;j++){
            if(j%2!=0){
                ans1=sum1+(even-sum2);
                ans2=sum2+(odd-sum1)-array[j];
                sum1+=array[j];
            }else{
                ans1=sum1+(even-sum2)-array[j];
                ans2=sum2+(odd-sum1);
                sum2+=array[j];
            }

            if(ans1==ans2){
                c++;
            }
        }
        System.out.println(c);
    } 

    public static long sumodd(long[] array,int i,int n){
        long sum=0;
        for(int i1=i;i1<n+1;i1++){
            if(i1%2!=0){
                sum=sum+array[i1];
            }
            
        }
        return sum;
    }
    
    public static long sumeven(long[] array,int i,int n){
        long sum=0;
        for(int i1=i;i1<n+1;i1++){
            if(i1%2==0){
                sum=sum+array[i1];
            }
            
        }
        return sum;
    }

    public static int height(int[] array,int n,int indx){
        if(indx>=n-1){
            return 0;
        }else if(indx==n-2){
            return Math.abs(array[indx]-array[indx+1]);
        }
        else{
            return Math.min(Math.abs(array[indx]-array[indx+1])+height(array,n,indx+1),Math.abs(array[indx]-array[indx+2])+height(array,n,indx+2));
        }
    }

    public static boolean comparing(String s,int odd, int k){
        if(odd<=k && s.length()>=k){
            return true;
        }else{
            return false;
        }
    }  

    public static int oddcount(int[] array, String s, int n){
        for(int i=0;i<s.length();i++){
            if(s.substring(i,i+1).equals("a")){
                array[1]++;
            }else if(s.substring(i,i+1).equals("b")){
               array[2]++;
            }else if(s.substring(i,i+1).equals("c")){
               array[3]++;
            }else if(s.substring(i,i+1).equals("d")){
               array[4]++;
            }else if(s.substring(i,i+1).equals("e")){
               array[5]++;
            }else if(s.substring(i,i+1).equals("f")){
               array[6]++;
            }else if(s.substring(i,i+1).equals("g")){
               array[7]++;
            }else if(s.substring(i,i+1).equals("h")){
               array[8]++;
            }else if(s.substring(i,i+1).equals("i")){
               array[9]++;
            }else if(s.substring(i,i+1).equals("j")){
                array[10]++;
            }else if(s.substring(i,i+1).equals("k")){
                array[11]++;
            }else if(s.substring(i,i+1).equals("l")){
                array[12]++;
            }else if(s.substring(i,i+1).equals("m")){
                array[13]++;
            }else if(s.substring(i,i+1).equals("n")){
                array[14]++;
            }else if(s.substring(i,i+1).equals("o")){
                array[15]++;
            }else if(s.substring(i,i+1).equals("p")){
                array[16]++;
            }else if(s.substring(i,i+1).equals("q")){
                array[17]++;
            }else if(s.substring(i,i+1).equals("r")){
                array[18]++;
            }else if(s.substring(i,i+1).equals("s")){
                array[19]++;
            }else if(s.substring(i,i+1).equals("t")){
                array[20]++;
            }else if(s.substring(i,i+1).equals("u")){
                array[21]++;
            }else if(s.substring(i,i+1).equals("v")){
                array[22]++;
            }else if(s.substring(i,i+1).equals("w")){
                array[23]++;
            }else if(s.substring(i,i+1).equals("x")){
                array[24]++;
            }else if(s.substring(i,i+1).equals("y")){
                array[25]++;
            }else if(s.substring(i,i+1).equals("z")){
                array[26]++;
            }
        }
        return oddchecking(array, n);
    }

    public static int oddchecking(int[] array, int n){
        int odd=0;
        for(int j=1;j<n+1;j++){
            if(array[j]%2!=0){
                odd++;
            }
        }
        return odd;   
    }

    public static int printDivisors(int n) 
    { int c=0;
        

        for (int i=1; i<=Math.sqrt(n); i++) 
        { 
            if (n%i==0) 
            { 
                if(n/i==i){
                    c++;
                }else{
                    c=c+2;
                }
            } 
        } 
        return c;
    } 

    public static long gcd(long a, long b) 
    { 
      if (b == 0){
        return a;
      }
      else{
        return gcd(b,a%b);
      }  
    } 

    public static long money(long[] array,long n,long sum,long i1,long i2){
        
        for(int k=(int)n-1;k>=0;k--){
            i1++;
            array[k]=array[k]%1000000007;
            sum=(sum+(array[k]*((i1*i2)%1000000007)))%1000000007;
            i2=(i1*i2)%1000000007;
        }

        return sum;
    }

    public static int largestsum(int[][] array,int i,int j,int n){
        if(i>n || j>n){
            return 0;
        }
        else{
            return array[i][j]+Math.max(largestsum(array,i+1,j,n),largestsum(array,i+1,j+1,n));
        }
    }

    public static void LongestIncreasingSubsequence(long[] array, long n){
        boolean flag=true;
        for(int i=2;i<=n;i++){
            if(array[i]>=array[i-1])
            {
                flag=false;
                break;
            }
        }
        if(flag)
            System.out.println(0);
        else{
        long count=0;
        long maximum=0;
        for(int i1=1;i1<=n;i1++){
            long m1=0;
            long l1=0;
            for(int i2=1;i2<i1;i2++){
                if(array[i2]<=array[i2+1] && array[i2+1]<=array[i1]){
                    l1++;
                }else{
                    if(l1!=0){
                        l1++;
                    }
                    if(m1<l1){
                        m1=l1;
                        l1=0;
                    }else{
                        l1=0;
                    }
                }
            }
            if(m1<l1){
                m1=l1;
            }

            long m2=0;
            long l2=0;
            for(int i2=i1;i2<=n;i2++){
                if(i2==n && array[i2]>=array[i1]){
                    l2++;
                    if(m2<=l2){
                        m2=l2;
                        l2=0;
                    }
                }
                else if(i2==n && array[i2]<array[i1]){
                    if(m2<l2){
                        m2=l2;
                        l2=0;
                    }
                }
                else if(i2!=n && array[i2]<=array[i2+1] && array[i2]>=array[i1]){
                    l2++;
                }
                else{
                    l2++;
                    if(m2<l2){
                        m2=l2;
                        l2=0;
                    }
                    else{
                        l2=0;
                    }
                }
            }
            if(m2<l2){
                m2=l2;
            }
            

            count = m1+m2;
            if(maximum<=count){
                maximum=count;
            }

        }
        System.out.println(maximum);}

        
    }

    public static int max_sum(int[][] array,int i, int j,int n){
        

        if(i>n || j>n){
            

            return 0;
        }
        return array[i][j]+Math.max(max_sum(array,i+1,j,n),max_sum(array,i,j+1,n));
    }

    public static boolean isPrime(long num){
    if ( num > 2 && num%2 == 0 ) {
        

        return false;
    }
    long top = (long)Math.sqrt(num) + 1;
    for(int i = 3; i < top; i+=2){
        if(num % i == 0){
            

            return false;
        }
    }
    

    return true; 
}

    public static BigInteger gcd(BigInteger a, BigInteger b) 
    {   
        BigInteger b1 = new BigInteger("0");
        

        if (a.equals(b1) || b.equals(b1)) 
           return b1; 
       
        

        if (a.equals(b)) 
            return a; 
       
        

        if (a.compareTo(b)==1) 
            return gcd(a.subtract(b), b); 
        return gcd(a, b.subtract(a)); 
    } 
      
    

    public static BigInteger lcm(BigInteger a, BigInteger b) 
    { 
        
        return (a.multiply(b)).divide(gcd(a, b)); 
    }

    public static void filling2(long[] array1,long[] array,long[] aux,long mid){
        while(array1[0]<mid){
            aux[(int)array1[2]]=array[(int)array1[0]];
            array1[2]=array1[2]+1;
            array1[0]=array1[0]+1;
        }
    }

    public static boolean compare(long a, long b){
        if(a>b){
            return true;
        }else{
            return false;
        }
    }

    public static long modu(long n, long a, long b, long temp){
        long m = n/2;
        if(m<1){
            return 0;
        }else if(m>temp){
            return 0;
        }
        else{
            if(m%a==0 && m%b!=0 || m%b==0 && m%a!=0){
                return 1+modu(m-1,a,b,temp)+modu(m+1,a,b,temp);
            }else{
                return modu(m-1,a,b,temp)+modu(m+1,a,b,temp);
            }
        }
    }
    
    public static double distance(double a, double b, double c, double d){
        double d1 = (a-c)*(a-c);
        double d2 = (b-d)*(b-d);
        double d3 = d1+d2;
        double d4 = Math.sqrt(d3);
        return d4;
    }

    public static void merge(long[] array,long left,long mid,long right,long size,long[] aux){
        long[] array1 = new long[3];
        array1[0]=left;
        array1[1]=mid;
        array1[2]=left;
        long count=0;
        while((array1[0]<mid) && (array1[1]<right+1)){
            if(compare(array[(int)array1[0]],array[(int)array1[1]])){
                aux[(int)array1[2]]=array[(int)array1[1]];
                array1[2]=array1[2]+1;
                array1[1]=array1[1]+1;
                count+=mid-array1[0];
            }else{
                aux[(int)array1[2]]=array[(int)array1[0]];
                array1[2]=array1[2]+1;
                array1[0]=array1[0]+1;
            }
        }
        filling3(array1,array,aux,right);
        filling2(array1,array,aux,mid);
        filling1(array1,left,right,array,aux);
        

    }


    public static long weigh(long n){
        if(n<=30){
            return 40;
        }else if(n>30 && n<51){
            return 55;
        }else{
            if(n%50==0){
                long temp = n/50;
                long value = 25*(temp-1);
                return value+55;
            }else{
                long temp = n/50;
                temp++;
                

                long value = 25*(temp-1);
                return value+55;
            }
        }
    }

    public static long max_val(long[] array, int n, int start, int end){
        long maximum=0;
        long value1=array[0];
        long value2=0;
        int i=1;
        long result = looping(array,n,i,maximum,value1,value2);
        return result;
    }

    public static long max(long a , long b){
        if(a>b){
            return a;
        }else{
            return b;
        }
    }
    
    public static void counting(int[] array, int a, int b, int n){
            int indx1 = Binary(array,1,n,a);
       
            int indx2 = Binary(array,1,n,b);
       
            int diff = indx2-indx1;
       
            int result = diff+1;
       
            Result(result);      
    }

    public static long result(long n, long m){
        long value = horse_path(n,m,1,1);
        return value;
    }

    public static int permutations(int n,int i, int count){
        while(i<n+1){
            int j=1;
            while(j<n+1){
                int prod = 0;
                prod = i*j;
                if(n%prod==0){
                    count++;
                }
                j++;
            }
            i++;
        }
        return count;
    }

    public static int swap2(int j1,int[] professor_list,int prof,int n){

                while(j1<n+1)
                {
        
                    if(professor_list[j1]==0){
        
                        prof=j1;
        
                        break;
        
                    }
        
                    j1++;
        
                }
                return prof;
    
    }

    public static boolean check(int[] array,int n, int sum, boolean boo, int max){
        int temp=max;
        boolean curr = boo;
        if(sum>0 && n==0){
            return false;
        }else if(sum==0){
            return true;
        }else if(array[n-1]>sum){
            return check(array,n-1,sum,curr,temp);
        }
        else{
            return check(array,n-1,sum,curr,temp) || check(array,n-1,sum-array[n-1],curr,temp);
        }
    }

    public static int swap4(int[] professor_list, int[] student_list, int prof, int stud, int total){

            professor_list[prof]=1;
        
            student_list[stud]=prof;

            total--;

            return total;
        
    }


    public static void show(int[] array,int n){
        
        for(int i=1;i<n+1;i++){
        
            System.out.println(i+" "+array[i]);
        
        }
    }
   
    public static int Binary(int[] array , int min, int max, int num){
        
        if(max<min){
        
            return -1;
        
        }

        else
        {
        
            int mid = min + (max-min)/2;
        
            if(array[mid]==num){
        
                return mid;
        
            }
            else if(array[mid]>num){
            
                return Binary(array,min,mid-1,num);
            
            }
            else
            {
            
                return Binary(array,mid+1,max,num);
            
            }
        }
    }

}