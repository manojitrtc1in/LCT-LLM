import java.util.Arrays;

public class 40ca10a54463a16f6c0559d2d974fdc5xcodeeval_processed_8000.json {
    static final int N = 18000;
    static final int M = 18000;
    static boolean[] is = new boolean[N];
    static int[] prm = new int[M];
    static int cntp;

    static int id0(int n) {
        int k = 0;
        int s, e = (int) (Math.sqrt(0.0 + n) + 1);
        Arrays.fill(is, true);
        prm[k++] = 2;
        is[0] = is[1] = false;
        for (int i = 4; i < n; i += 2) is[i] = false;
        for (int i = 3; i < e; i += 2) {
            if (is[i]) {
                prm[k++] = i;
                for (s = i * 2, int j = i * i; j < n; j += s) {
                    is[j] = false;
                }
            }
        }
        for (int i = 0; i < n; i += 2) {
            if (is[i]) prm[k++] = i;
        }
        return k;
    }

