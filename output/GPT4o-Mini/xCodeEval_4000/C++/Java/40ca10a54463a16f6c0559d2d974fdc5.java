import java.util.Arrays;
import java.util.Scanner;

public class 40ca10a54463a16f6c0559d2d974fdc5_nc {
    static final int N = 18000;
    static final int M = 18000;
    static boolean[] is = new boolean[N];
    static int[] prm = new int[M];
    static int cntp;

    static int getprm(int n) {
        int k = 0;
        int e = (int) (Math.sqrt(n) + 1);
        Arrays.fill(is, true);
        prm[k++] = 2;
        is[0] = is[1] = false;
        for (int i = 4; i < n; i += 2) is[i] = false;
        for (int i = 3; i < e; i += 2) {
            if (is[i]) {
                prm[k++] = i;
                for (int j = i * i; j < n; j += i * 2) {
                    is[j] = false;
                }
            }
        }
        for (int i = e; i < n; i += 2) {
            if (is[i]) prm[k++] = i;
        }
        return k;
    }
