

import java.util.*;

public class Ex3 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int q = in.nextInt();
        for (int t = 0; t < q; t++) {
            int x = in.nextInt();
            int arr[] = new int[x];
            for(int i = 0; i < x; i++){
                arr[i] = in.nextInt();
            }
            for(int i = 0; i < x;i++){
                int k = in.nextInt();
                String str = in.next();
                for(int j = 0; j < str.length(); j++){
                    if(str.charAt(j) == 'D'){
                        if(arr[i] == 9){
                            arr[i] = 0;
                        }else {
                            arr[i]++;
                        }
                    }else {
                        if(arr[i] == 0){
                            arr[i] = 9;
                        }else {
                            arr[i]--;
                        }
                    }
                }
            }
            for(int i = 0; i < x; i++){
                System.out.print(arr[i]+" ");
            }
            System.out.println();
        }
    }

    static long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    static long lcm(long a, long b) {
        return a * b / gcd(a, b);
    }
}


