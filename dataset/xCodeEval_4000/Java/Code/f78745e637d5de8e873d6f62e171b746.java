

import java.util.*;

public class Ex3 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int q = in.nextInt();
        for (int t = 0; t < q; t++) {
            int n = in.nextInt();
            int arr[]=new int[n];
            int arr1[]=new int[n];
            int max[]=new int[n];
            for(int i=0;i<n;i++){
                arr[i]=in.nextInt();
                arr1[i]=in.nextInt();
            }
            for(int i=0;i<n;i++){
                if(arr[i]>arr1[i]){
                    max[i]=arr[i];
                }
                else{
                    max[i]=arr1[i];
                }
            }
            long sum=0;
            for(int i=0;i<n;i++){
                if(max[i]==arr[i]){
                    sum+=arr1[i];
                }
                else{
                    sum+=arr[i];
                }
            }
            Arrays.sort(max);
            sum+=max[n-1];
            sum*=2;
            System.out.println(sum);
        }
        }
    

    static long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    static long lcm(long a, long b) {
        return a * b / gcd(a, b);
    }
}


