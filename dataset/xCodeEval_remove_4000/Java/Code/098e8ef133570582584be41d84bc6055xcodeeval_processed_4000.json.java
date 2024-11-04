

import java.io.IOException;
import java.util.*;


public class A {

    
    private static void fun2(int n, int x, int[] a) {

        int oddNum = 0;
        boolean hasOu = false;
        int ouNum = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] % 2 == 0) {
                ouNum++;

            } else {
                oddNum++;
            }
        }
        if (ouNum >= 2) {
            hasOu = true;
        }

        while (x > 2) {
            if (ouNum >= 2) {
                ouNum -= 2;
                x -= 2;
            } else if (oddNum >= 2) {
                oddNum -= 2;
                x -= 2;
            } else {
                break;
            }
        }

        if (x == 2) {
            if (oddNum > 0 && ouNum > 0) {
                System.out.println("Yes");
                return;
            } else if (oddNum > 2 && hasOu) {
                System.out.println("Yes");
                return;
            }
        } else if (x == 1) {
            if (oddNum > 0) {
                System.out.println("Yes");
                return;
            }
        } else {
            System.out.println("No");
            return;
        }

        System.out.println("No");
    }

    
    private static void fun(int n, int x, int[] a) {





        int[] f = new int[2];
        for (int i = 0; i < n; i++) {
            f[a[i] % 2]++;
        }
        boolean good = false;
        if (n == x) {
            

            good = f[1] % 2 == 1;
        } else if (f[1] > 0) {
            

            if (f[0] > 0) {
                

                good = true;
            } else if (x % 2 == 1) {
                

                good = true;
            }
        }

        if (good) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }

    }


    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int id0 = sc.nextInt();

        for (int t = 0; t < id0; t++) {
            

            int n = sc.nextInt();
            

            int x = sc.nextInt();
            int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = sc.nextInt();
            }
            fun(n, x, a);
        }
    }


}

