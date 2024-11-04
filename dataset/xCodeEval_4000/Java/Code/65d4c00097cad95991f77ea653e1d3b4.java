import java.util.*;
import java.io.*;

public class Main {
    static ContestScanner sc = new ContestScanner(System.in);
    static PrintWriter pw = new PrintWriter(System.out);
    static StringBuilder sb = new StringBuilder();
    static long mod = (long) 1e9 + 7;
    
    static int[] pals = {1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 22, 33, 44, 55, 66, 77, 88, 99, 101, 111, 121, 131, 141, 151, 161, 171, 181, 191, 202, 212, 222, 232, 242, 252, 262, 272, 282, 292, 303, 313, 323, 333, 343, 353, 363, 373, 383, 393, 404, 414, 424, 434, 444, 454, 464, 474, 484, 494, 505, 515, 525, 535, 545, 555, 565, 575, 585, 595, 606, 616, 626, 636, 646, 656, 666, 676, 686, 696, 707, 717, 727, 737, 747, 757, 767, 777, 787, 797, 808, 818, 828, 838, 848, 858, 868, 878, 888, 898, 909, 919, 929, 939, 949, 959, 969, 979, 989, 999, 1001, 1111, 1221, 1331, 1441, 1551, 1661, 1771, 1881, 1991, 2002, 2112, 2222, 2332, 2442, 2552, 2662, 2772, 2882, 2992, 3003, 3113, 3223, 3333, 3443, 3553, 3663, 3773, 3883, 3993, 4004, 4114, 4224, 4334, 4444, 4554, 4664, 4774, 4884, 4994, 5005, 5115, 5225, 5335, 5445, 5555, 5665, 5775, 5885, 5995, 6006, 6116, 6226, 6336, 6446, 6556, 6666, 6776, 6886, 6996, 7007, 7117, 7227, 7337, 7447, 7557, 7667, 7777, 7887, 7997, 8008, 8118, 8228, 8338, 8448, 8558, 8668, 8778, 8888, 8998, 9009, 9119, 9229, 9339, 9449, 9559, 9669, 9779, 9889, 9999, 10001, 10101, 10201, 10301, 10401, 10501, 10601, 10701, 10801, 10901, 11011, 11111, 11211, 11311, 11411, 11511, 11611, 11711, 11811, 11911, 12021, 12121, 12221, 12321, 12421, 12521, 12621, 12721, 12821, 12921, 13031, 13131, 13231, 13331, 13431, 13531, 13631, 13731, 13831, 13931, 14041, 14141, 14241, 14341, 14441, 14541, 14641, 14741, 14841, 14941, 15051, 15151, 15251, 15351, 15451, 15551, 15651, 15751, 15851, 15951, 16061, 16161, 16261, 16361, 16461, 16561, 16661, 16761, 16861, 16961, 17071, 17171, 17271, 17371, 17471, 17571, 17671, 17771, 17871, 17971, 18081, 18181, 18281, 18381, 18481, 18581, 18681, 18781, 18881, 18981, 19091, 19191, 19291, 19391, 19491, 19591, 19691, 19791, 19891, 19991, 20002, 20102, 20202, 20302, 20402, 20502, 20602, 20702, 20802, 20902, 21012, 21112, 21212, 21312, 21412, 21512, 21612, 21712, 21812, 21912, 22022, 22122, 22222, 22322, 22422, 22522, 22622, 22722, 22822, 22922, 23032, 23132, 23232, 23332, 23432, 23532, 23632, 23732, 23832, 23932, 24042, 24142, 24242, 24342, 24442, 24542, 24642, 24742, 24842, 24942, 25052, 25152, 25252, 25352, 25452, 25552, 25652, 25752, 25852, 25952, 26062, 26162, 26262, 26362, 26462, 26562, 26662, 26762, 26862, 26962, 27072, 27172, 27272, 27372, 27472, 27572, 27672, 27772, 27872, 27972, 28082, 28182, 28282, 28382, 28482, 28582, 28682, 28782, 28882, 28982, 29092, 29192, 29292, 29392, 29492, 29592, 29692, 29792, 29892, 29992, 30003, 30103, 30203, 30303, 30403, 30503, 30603, 30703, 30803, 30903, 31013, 31113, 31213, 31313, 31413, 31513, 31613, 31713, 31813, 31913, 32023, 32123, 32223, 32323, 32423, 32523, 32623, 32723, 32823, 32923, 33033, 33133, 33233, 33333, 33433, 33533, 33633, 33733, 33833, 33933, 34043, 34143, 34243, 34343, 34443, 34543, 34643, 34743, 34843, 34943, 35053, 35153, 35253, 35353, 35453, 35553, 35653, 35753, 35853, 35953, 36063, 36163, 36263, 36363, 36463, 36563, 36663, 36763, 36863, 36963, 37073, 37173, 37273, 37373, 37473, 37573, 37673, 37773, 37873, 37973, 38083, 38183, 38283, 38383, 38483, 38583, 38683, 38783, 38883, 38983, 39093, 39193, 39293, 39393, 39493, 39593, 39693, 39793, 39893, 39993};
    static long[][] cnt = new long[40001][pals.length];
    public static void main(String[] args) throws Exception {
        
        cnt[0][0] = 1;
        int index = 0;
        for(int v : pals){
            for(int i = 0; i <= 40000; i++){
                int now = i+v;
                if(index != 0){
                    cnt[i][index] += cnt[i][index-1];
                    cnt[i][index] %= mod;
                }
                if(now > 40000){
                    continue;
                }
                cnt[now][index] += cnt[i][index];
                cnt[now][index] %= mod;
            }
            

            index++;
        }
        
        
        int n = sc.nextInt();
        for(int i = 0; i < n; i++) solve();
        pw.flush();
    }

    public static void solve() {
        pw.println(cnt[sc.nextInt()][pals.length-1]);
        
    }

    static class GeekInteger {
        public static void save_sort(int[] array) {
            shuffle(array);
            Arrays.sort(array);
        }

        public static int[] shuffle(int[] array) {
            int n = array.length;
            Random random = new Random();
            for (int i = 0, j; i < n; i++) {
                j = i + random.nextInt(n - i);
                int randomElement = array[j];
                array[j] = array[i];
                array[i] = randomElement;
            }
            return array;
        }

        public static void save_sort(long[] array) {
            shuffle(array);
            Arrays.sort(array);
        }

        public static long[] shuffle(long[] array) {
            int n = array.length;
            Random random = new Random();
            for (int i = 0, j; i < n; i++) {
                j = i + random.nextInt(n - i);
                long randomElement = array[j];
                array[j] = array[i];
                array[i] = randomElement;
            }
            return array;
        }

    }
}


class ContestScanner {
    private final java.io.InputStream in;
    private final byte[] buffer = new byte[1024];
    private int ptr = 0;
    private int buflen = 0;

    private static final long LONG_MAX_TENTHS = 922337203685477580L;
    private static final int LONG_MAX_LAST_DIGIT = 7;
    private static final int LONG_MIN_LAST_DIGIT = 8;

    public ContestScanner(java.io.InputStream in){
        this.in = in;
    }
    public ContestScanner(java.io.File file) throws java.io.FileNotFoundException {
        this(new java.io.BufferedInputStream(new java.io.FileInputStream(file)));
    }
    public ContestScanner(){
        this(System.in);
    }
 
    private boolean hasNextByte() {
        if (ptr < buflen) {
            return true;
        }else{
            ptr = 0;
            try {
                buflen = in.read(buffer);
            } catch (java.io.IOException e) {
                e.printStackTrace();
            }
            if (buflen <= 0) {
                return false;
            }
        }
        return true;
    }
    private int readByte() { 
        if (hasNextByte()) return buffer[ptr++]; else return -1;
    }
    private static boolean isPrintableChar(int c) {
        return 33 <= c && c <= 126;
    }
    public boolean hasNext() {
        while(hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++;
        return hasNextByte();
    }
    public String next() {
        if (!hasNext()) throw new java.util.NoSuchElementException();
        StringBuilder sb = new StringBuilder();
        int b = readByte();
        while(isPrintableChar(b)) {
            sb.appendCodePoint(b);
            b = readByte();
        }
        return sb.toString();
    }
 
    public long nextLong() {
        if (!hasNext()) throw new java.util.NoSuchElementException();
        long n = 0;
        boolean minus = false;
        int b = readByte();
        if (b == '-') {
            minus = true;
            b = readByte();
        }
        if (b < '0' || '9' < b) {
            throw new NumberFormatException();
        }
        while (true) {
            if ('0' <= b && b <= '9') {
                int digit = b - '0';
                if (n >= LONG_MAX_TENTHS) {
                    if (n == LONG_MAX_TENTHS) {
                        if (minus) {
                            if (digit <= LONG_MIN_LAST_DIGIT) {
                                n = -n * 10 - digit;
                                b = readByte();
                                if (!isPrintableChar(b)) {
                                    return n;
                                } else if (b < '0' || '9' < b) {
                                    throw new NumberFormatException(
                                        String.format("%d%s... is not number", n, Character.toString(b))
                                    );
                                }
                            }
                        } else {
                            if (digit <= LONG_MAX_LAST_DIGIT) {
                                n = n * 10 + digit;
                                b = readByte();
                                if (!isPrintableChar(b)) {
                                    return n;
                                } else if (b < '0' || '9' < b) {
                                    throw new NumberFormatException(
                                        String.format("%d%s... is not number", n, Character.toString(b))
                                    );
                                }
                            }
                        }
                    }
                    throw new ArithmeticException(
                        String.format("%s%d%d... overflows long.", minus ? "-" : "", n, digit)
                    );
                }
                n = n * 10 + digit;
            }else if(b == -1 || !isPrintableChar(b)){
                return minus ? -n : n;
            }else{
                throw new NumberFormatException();
            }
            b = readByte();
        }
    }
    public int nextInt() {
        long nl = nextLong();
        if (nl < Integer.MIN_VALUE || nl > Integer.MAX_VALUE) throw new NumberFormatException();
        return (int) nl;
    }
    public double nextDouble() {
        return Double.parseDouble(next());
    }
 
    public long[] nextLongArray(int length){
        long[] array = new long[length];
        for(int i=0; i<length; i++) array[i] = this.nextLong();
        return array;
    }
    public long[] nextLongArray(int length, java.util.function.LongUnaryOperator map){
        long[] array = new long[length];
        for(int i=0; i<length; i++) array[i] = map.applyAsLong(this.nextLong());
        return array;
    }
    public int[] nextIntArray(int length){
        int[] array = new int[length];
        for(int i=0; i<length; i++) array[i] = this.nextInt();
        return array;
    }
    public int[] nextIntArray(int length, java.util.function.IntUnaryOperator map){
        int[] array = new int[length];
        for(int i=0; i<length; i++) array[i] = map.applyAsInt(this.nextInt());
        return array;
    }
    public double[] nextDoubleArray(int length){
        double[] array = new double[length];
        for(int i=0; i<length; i++) array[i] = this.nextDouble();
        return array;
    }
    public double[] nextDoubleArray(int length, java.util.function.DoubleUnaryOperator map){
        double[] array = new double[length];
        for(int i=0; i<length; i++) array[i] = map.applyAsDouble(this.nextDouble());
        return array;
    }
 
    public long[][] nextLongMatrix(int height, int width){
        long[][] mat = new long[height][width];
        for(int h=0; h<height; h++) for(int w=0; w<width; w++){
            mat[h][w] = this.nextLong();
        }
        return mat;
    }
    public int[][] nextIntMatrix(int height, int width){
        int[][] mat = new int[height][width];
        for(int h=0; h<height; h++) for(int w=0; w<width; w++){
            mat[h][w] = this.nextInt();
        }
        return mat;
    }
    public double[][] nextDoubleMatrix(int height, int width){
        double[][] mat = new double[height][width];
        for(int h=0; h<height; h++) for(int w=0; w<width; w++){
            mat[h][w] = this.nextDouble();
        }
        return mat;
    }
 
    public char[][] nextCharMatrix(int height, int width){
        char[][] mat = new char[height][width];
        for(int h=0; h<height; h++){
            String s = this.next();
            for(int w=0; w<width; w++){
                mat[h][w] = s.charAt(w);
            }
        }
        return mat;
    }
}
