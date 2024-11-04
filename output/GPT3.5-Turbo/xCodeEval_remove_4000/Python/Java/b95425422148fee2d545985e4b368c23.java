public class b95425422148fee2d545985e4b368c23xcodeeval_processed_4000.json {
    public static void main(String[] args) {
        String z = "\"\"\"6\"k\"=\"3,\"iG\"17G\"6m?\"C@f\"2<6z\"ki1,\"1Y[{s\"dnF)N\"1j.&{o\"aZ>k}1\"173exa+\"atUi,},\"1canZ35z\"b*-!Ps6l\"1z<F!WJlC\"fQrp~1])H\"1}8l0AiPTl\"nXgm";
        String q = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!";

        int[] k = new int[z.split("\"").length / 2];
        int index = 0;
        for (String x : z.split("\"")) {
            if (!x.isEmpty()) {
                k[index++] = zz(x);
            }
        }

        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();

        System.out.println(k[n] % m);
    }

    public static int zz(String x) {
        String q = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!";
        int a = 0;
        for (char i : x.toCharArray()) {
            a = a * q.length() + q.indexOf(i);
        }
        return a;
    }
}
