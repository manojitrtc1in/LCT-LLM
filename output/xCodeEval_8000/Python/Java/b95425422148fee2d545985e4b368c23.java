public class b95425422148fee2d545985e4b368c23_nc {
    public static void main(String[] args) {
        String z = "\"\"\"6\"k\"=\"3,\"iG\"17G\"6m?\"C@f\"2<6z\"ki1,\"1Y[{s\"dnF)N\"1j.&{o\"aZ>k}1\"173exa+\"atUi,},\"1canZ35z\"b*-!Ps6l\"1z<F!WJlC\"fQrp~1])H\"1}8l0AiPTl\"nXgm";
        String q = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!";

        int[] k = new int[0];
        String[] splitZ = z.split("\"");
        for (String x : splitZ) {
            int a = 0;
            for (int i = 0; i < x.length(); i++) {
                a = a * q.length() + q.indexOf(x.charAt(i));
            }
            int[] temp = new int[k.length + 1];
            System.arraycopy(k, 0, temp, 0, k.length);
            temp[k.length] = a;
            k = temp;
        }

        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();

        System.out.println(k[n] % m);
    }
}
