import java.util.Scanner;

public class b95425422148fee2d545985e4b368c23_nc {
    static String z = "\"\"\"6k\"=\"3,\"iG\"17G\"6m?\"C@f\"2<6z\"ki1,\"1Y[{s\"dnF)N\"1j.&{o\"aZ>k}1\"173exa+\"atUi,},\"1canZ35z\"b*-!Ps6l\"1z<F!WJlC\"fQrp~1])H\"1}8l0AiPTl\"nXgm";
    static String q = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!";

    static long zz(String x) {
        long a = 0;
        for (char i : x.toCharArray()) {
            a = a * q.length() + q.indexOf(i);
        }
        return a;
    }

    public static void main(String[] args) {
        String[] parts = z.split("\"");
        long[] k = new long[parts.length];
        
        for (int i = 0; i < parts.length; i++) {
            k[i] = zz(parts[i]);
        }

        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        System.out.println(k[n] % m);
    }
}
