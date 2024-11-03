import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class 5ff06312c9f00109c984ee2127a9080fxcodeeval_processed_8000.json {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int l = Integer.parseInt(input[0]);
        int r = Integer.parseInt(input[1]);

        System.out.println(ans(r) - ans(l - 1));
    }

    public static boolean prime(int x) {
        if (x < 2)
            return false;
        int j = 2;
        while (j * j <= x) {
            if (x % j == 0) {
                return false;
            }
            if (j == 2)
                j++;
            else
                j += 2;
        }
        return true;
    }

    public static int ans(int x) {
        int j = x / 100000;
        int ret = 0;
        if (x >= 2)
            ret++;
        for (int i = 0; i <= j; ++i) {
            ret += f[i];
        }
        if (j > 0)
            ret--;

        int b = j * 100000;
        b++;

        for (int i = b; i <= x; i += 4) {
            if (prime(i))
                ret++;
        }
        return ret;
    }

    static final int[] f = {
