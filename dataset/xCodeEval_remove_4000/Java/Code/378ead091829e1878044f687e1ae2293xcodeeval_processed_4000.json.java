import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class id12 {

    private FastScanner in;
    private PrintWriter out;

    public void solve() throws IOException {
        byte[] sequenceBytes = in.next().getBytes();

        byte[] id10 = new byte[sequenceBytes.length * 2];
        id10[0] = sequenceBytes[0];
        int count = 1;
        int countLR = 0;
        if(id10[0] != 'X'){
            countLR++;
        }
        for(int i = 1; i < sequenceBytes.length; i++){
            if(sequenceBytes[i] == sequenceBytes[i - 1] && sequenceBytes[i] != 'X'){
                id10[count] = 'X';
                count++;
            }
            id10[count] = sequenceBytes[i];
            if(id10[count] != 'X'){
                countLR++;
            }
            count++;
        }

        int[] array = new int[count + 1];
        int arrayCount = 0;
        int i = 0;
        boolean isRight = true;
        int sum = 0;
        int maxPrefix = 0;
        int minPrefix = 0;
        int id2 = -1;
        while(i < count){
            int c = 0;
            while(i < count){
                if(id10[i] == 'L'){
                    if(i % 2 == 1 ^ isRight){
                        c++;
                    }
                    else{
                        break;
                    }
                }
                else if(id10[i] == 'R'){
                    if(i % 2 == 0 ^ isRight){
                        c++;
                    }
                    else{
                        break;
                    }
                }
                i++;
            }
            if(isRight){
                array[arrayCount] = c;
            }
            else{
                array[arrayCount] = -c;
            }
            sum += array[arrayCount];
            if(sum > maxPrefix){
                maxPrefix = sum;
                id2 = arrayCount;
            }
            if(sum < minPrefix){
                minPrefix = sum;
            }
            arrayCount++;
            isRight = !isRight;
        }

        int minSuffix = sum - maxPrefix;

        int[] arrayNew = new int[arrayCount];
        boolean processed = false;
        if(count % 2 == 0){
            if(id10[0] != id10[count - 1] || id10[0] == 'X'){
                for(i = 0; i < arrayCount; i++){
                    arrayNew[i] = array[i];
                }
            }
            else{
                processed = true;
                if(minPrefix < minSuffix){
                    sum = 0;
                    maxPrefix = 0;
                    id2 = -1;
                    for(i = 0; i < arrayCount; i++){
                        array[i] = -array[i];
                        sum += array[i];
                        if(sum > maxPrefix){
                            maxPrefix = sum;
                            id2 = i;
                        }
                    }
                }
                count++;
            }
        }
        minSuffix = sum - maxPrefix;
        if(count % 2 == 1){
            if(id10[0] != id10[count - 1] || id10[0] == 'X' || processed){
                for(i = 0; i <= id2; i++){
                    arrayNew[i] = array[i];
                }
                for(i = id2 + 1; i < arrayCount; i++){
                    arrayNew[i] = -array[i];
                }

                sum = sum - 2 * minSuffix;
            }
            else{
                if(sum > 0){
                    for(i = 0; i < arrayCount; i++){
                        arrayNew[i] = array[i];
                    }
                }
                else{
                    for(i = 0; i < arrayCount; i++){
                        arrayNew[i] = -array[i];
                    }
                    sum = -sum;
                }
                processed = true;
            }
            count++;
        }

        int kMax = 1;
        if(!processed){
            kMax = 0;
        }

        long bestNum = 0;
        long bestDen = 1;

        int oldCount = count;

        for(int k = -1; k <= kMax; k = k + 2){
            count = oldCount;
            int currSum = -k * sum;
            int sumPos = (countLR - currSum) / 2 + currSum;

            if(compare(bestNum, bestDen, sumPos, count) < 0){
                bestNum = sumPos;
                bestDen = count;
            }

            SegmentTree tree = new SegmentTree(arrayNew);
            if(k == 1) tree.id9(0, arrayNew.length - 1);
            while(true){
                int min = tree.id7();
                if(tree.id7() >= 0){
                    break;
                }
                long range = tree.id1();
                int rangeLeft = (int) (range >> 32);
                int rangeRight = (int) (range);
                tree.id9(rangeLeft, rangeRight);
                count += 2;
                sumPos -= min;
                if(compare(bestNum, bestDen, sumPos, count) < 0){
                    bestNum = sumPos;
                    bestDen = count;
                }
            }
        }

        String res = Long.toString(bestNum * 100 * 1000000 / bestDen);
        while(res.length() < 7){
            res = "0" + res;
        }
        out.println(res.substring(0, res.length() - 6) + "." + res.substring(res.length() - 6));
    }

    private int compare(long num1, long den1, long num2, long den2){
        if(num1 * den2 < num2 * den1) return -1;
        if(num1 * den2 == num2 * den1) return 0;
        return 1;
    }

    public void run() {
        try {
            in = new FastScanner(System.in);
            out = new PrintWriter(System.out);
            solve();
            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    class FastScanner {

        BufferedReader br;
        StringTokenizer st;

        FastScanner(InputStream is) {
            br = new BufferedReader(new InputStreamReader(is));
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }
    }

    public static void main(String[] arg) {
        new id12().run();
    }

    public class SegmentTree {

        private int length;

        private int[] id0;
        private int[] id13;
        private int[] id4;
        private int[] id3;
        private int[] sum;
        private byte[] coeff;

        public SegmentTree(int[] array){
            length = array.length;
            int size = 1 + (int) Math.pow(2, Math.ceil(Math.log(2 * length - 1) / Math.log(2)));

            id0 = new int[size];
            id13 = new int[size];
            id4 = new int[size];
            id3 = new int[size];
            sum = new int[size];
            coeff = new byte[size];

            build(array, 0, length - 1, 1);
        }

        private void build(int[] array, int left, int right, int v){
            if(left == right){
                id0[v] = Math.max(0, array[left]);
                id13[v] = Math.min(0, array[left]);
                id4[v] = Math.max(0, array[left]);
                id3[v] = Math.min(0, array[left]);
                sum[v] = array[left];
                coeff[v] = 1;
            }
            else{
                int mid = (left + right) / 2;
                build(array, left, mid, 2 * v);
                build(array, mid + 1, right, 2 * v + 1);
                combine(v);
                coeff[v] = 1;
            }
        }

        private void combine(int v){
            int leftChild = 2 * v;
            int rightChild = 2 * v + 1;
            id0[v] = Math.max(id0[leftChild], sum[leftChild] + id0[rightChild]);
            id13[v] = Math.min(id13[leftChild], sum[leftChild] + id13[rightChild]);
            id4[v] = Math.max(Math.max(id4[rightChild], id4[leftChild]),
                    sum[leftChild] - id13[leftChild] + id0[rightChild]);
            id3[v] = Math.min(Math.min(id3[rightChild], id3[leftChild]),
                    sum[leftChild] - id0[leftChild] + id13[rightChild]);
            sum[v] = sum[leftChild] + sum[rightChild];
        }

        public void id9(int left, int right){
            id6(1, 0, length - 1, left, right);
        }

        private void id6(int v, int currentLeft, int currentRight, int left, int right){
            if(currentLeft == left && currentRight == right){
                int t  = id0[v];
                id0[v] =  -id13[v];
                id13[v] = -t;
                t = id4[v];
                id4[v] = -id3[v];
                id3[v] = -t;
                sum[v] *= -1;
                coeff[v] *= -1;
            }
            else{
                int mid = (currentLeft + currentRight) / 2;
                if(coeff[v] == 1){
                    if(left < mid + 1){
                        id6(2 * v, currentLeft, mid, left, Math.min(right, mid));
                    }
                    if(right > mid){
                        id6(2 * v + 1, mid + 1, currentRight, Math.max(mid + 1, left), right);
                    }
                }
                else{
                    coeff[v] = 1;
                    if(left >= mid + 1){
                        id6(2 * v, currentLeft, mid, currentLeft, mid);
                        if(left > mid + 1){
                            id6(2 * v + 1, mid + 1, currentRight, mid + 1, left - 1);
                        }
                        if(right < currentRight){
                            id6(2 * v + 1, mid + 1, currentRight, right + 1, currentRight);
                        }
                    }
                    else if(right <= mid){
                        id6(2 * v + 1, mid + 1, currentRight, mid + 1, currentRight);
                        if(left > currentLeft){
                            id6(2 * v, currentLeft, mid, currentLeft, left - 1);
                        }
                        if(right < mid){
                            id6(2 * v, currentLeft, mid, right + 1, mid);
                        }
                    }
                    else{
                        if(left > currentLeft){
                            id6(2 * v, currentLeft, mid, currentLeft, left - 1);
                        }
                        if(right < currentRight){
                            id6(2 * v + 1, mid + 1, currentRight, right + 1, currentRight);
                        }
                    }
                }
                combine(v);
            }
        }

        public int id7(){
            return id3[1];
        }

        public long id1(){
            if(id3[1] == 0){
                return (1L << 32);
            }
            return id15(1, 0, length - 1);
        }

        private long id15(int v, int currentLeft, int currentRight){
            int mid = (currentLeft + currentRight) / 2;
            if(sum[v] == id3[v]){
                long range = currentLeft;
                range <<= 32;
                range |= currentRight;
                return range;
            }
            if(coeff[v] == 1){
                if(id3[v] == id3[2 * v]){
                    return id15(2 * v, currentLeft, mid);
                }
                if(id3[v] == id3[2 * v + 1]){
                    return id15(2 * v + 1, mid + 1, currentRight);
                }
                long suffix = id5(2 * v, currentLeft, mid);
                long prefix = id16(2 * v + 1, mid + 1, currentRight);
                return (suffix << 32) | prefix;
            }
            else{
                if(id3[v] == -id4[2 * v]){
                    return id8(2 * v, currentLeft, mid);
                }
                if(id3[v] == -id4[2 * v + 1]){
                    return id8(2 * v + 1, mid + 1, currentRight);
                }
                long suffix = id14(2 * v, currentLeft, mid);
                long prefix = id11(2 * v + 1, mid + 1, currentRight);
                return (suffix << 32) | prefix;
            }
        }

        private long id8(int v, int currentLeft, int currentRight){
            int mid = (currentLeft + currentRight) / 2;
            if(sum[v] == id4[v]){
                long range = currentLeft;
                range <<= 32;
                range |= currentRight;
                return range;
            }
            if(coeff[v] == 1){
                if(id4[v] == id4[2 * v]){
                    return id8(2 * v, currentLeft, mid);
                }
                if(id4[v] == id4[2 * v + 1]){
                    return id8(2 * v + 1, mid + 1, currentRight);
                }
                long suffix = id14(2 * v, currentLeft, mid);
                long prefix = id11(2 * v + 1, mid + 1, currentRight);
                return (suffix << 32) | prefix;
            }
            else{
                if(id4[v] == -id3[2 * v]){
                    return id15(2 * v, currentLeft, mid);
                }
                if(id4[v] == -id3[2 * v + 1]){
                    return id15(2 * v + 1, mid + 1, currentRight);
                }
                long suffix = id5(2 * v, currentLeft, mid);
                long prefix = id16(2 * v + 1, mid + 1, currentRight);
                return (suffix << 32) | prefix;
            }
        }

        private int id5(int v, int currentLeft, int currentRight){
            int mid = (currentLeft + currentRight) / 2;
            if(sum[v] - id0[v] == sum[v]){
                return currentLeft;
            }
            else if (sum[v] - id0[v] == 0){
                return currentRight + 1;
            }
            if(coeff[v] == 1){
                if(sum[v] - id0[v] == sum[2 * v + 1] - id0[2 * v + 1]){
                    return id5(2 * v + 1, mid + 1, currentRight);
                }
                else{
                    return id5(2 * v, currentLeft, mid);
                }
            }
            else{
                if(sum[v] - id0[v] == -(sum[2 * v + 1] - id13[2 * v + 1])){
                    return id14(2 * v + 1, mid + 1, currentRight);
                }
                else{
                    return id14(2 * v, currentLeft, mid);
                }
            }
        }

        private int id14(int v, int currentLeft, int currentRight){
            int mid = (currentLeft + currentRight) / 2;
            if(sum[v] - id13[v] == sum[v]){
                return currentLeft;
            }
            else if (sum[v] - id13[v] == 0){
                return currentRight + 1;
            }
            if(coeff[v] == 1){
                if(sum[v] - id13[v] == sum[2 * v + 1] - id13[2 * v + 1]){
                    return id14(2 * v + 1, mid + 1, currentRight);
                }
                else{
                    return id14(2 * v, currentLeft, mid);
                }
            }
            else{
                if(sum[v] - id13[v] == -(sum[2 * v + 1] - id0[2 * v + 1])){
                    return id5(2 * v + 1, mid + 1, currentRight);
                }
                else{
                    return id5(2 * v, currentLeft, mid);
                }
            }
        }

        private int id16(int v, int currentLeft, int currentRight){
            int mid = (currentLeft + currentRight) / 2;
            if(id13[v] == sum[v]){
                return currentRight;
            }
            else if (id13[v] == 0){
                return currentLeft - 1;
            }
            if(coeff[v] == 1){
                if(id13[v] == id13[2 * v]){
                    return id16(2 * v, currentLeft, mid);
                }
                else{
                    return id16(2 * v + 1, mid + 1, currentRight);
                }
            }
            else{
                if(id13[v] == -id0[2 * v]){
                    return id11(2 * v, currentLeft, mid);
                }
                else{
                    return id11(2 * v + 1, mid + 1, currentRight);
                }
            }
        }

        private int id11(int v, int currentLeft, int currentRight){
            int mid = (currentLeft + currentRight) / 2;
            if(id0[v] == sum[v]){
                return currentRight;
            }
            else if (id0[v] == 0){
                return currentLeft - 1;
            }
            if(coeff[v] == 1){
                if(id0[v] == id0[2 * v]){
                    return id11(2 * v, currentLeft, mid);
                }
                else{
                    return id11(2 * v + 1, mid + 1, currentRight);
                }
            }
            else{
                if(id0[v] == -id13[2 * v]){
                    return id16(2 * v, currentLeft, mid);
                }
                else{
                    return id16(2 * v + 1, mid + 1, currentRight);
                }
            }
        }
    }

}