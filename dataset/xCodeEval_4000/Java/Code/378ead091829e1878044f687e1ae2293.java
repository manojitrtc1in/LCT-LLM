import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Main11E {

    private FastScanner in;
    private PrintWriter out;

    public void solve() throws IOException {
        byte[] sequenceBytes = in.next().getBytes();

        byte[] sequenceBytesNew = new byte[sequenceBytes.length * 2];
        sequenceBytesNew[0] = sequenceBytes[0];
        int count = 1;
        int countLR = 0;
        if(sequenceBytesNew[0] != 'X'){
            countLR++;
        }
        for(int i = 1; i < sequenceBytes.length; i++){
            if(sequenceBytes[i] == sequenceBytes[i - 1] && sequenceBytes[i] != 'X'){
                sequenceBytesNew[count] = 'X';
                count++;
            }
            sequenceBytesNew[count] = sequenceBytes[i];
            if(sequenceBytesNew[count] != 'X'){
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
        int maxPrefixIndex = -1;
        while(i < count){
            int c = 0;
            while(i < count){
                if(sequenceBytesNew[i] == 'L'){
                    if(i % 2 == 1 ^ isRight){
                        c++;
                    }
                    else{
                        break;
                    }
                }
                else if(sequenceBytesNew[i] == 'R'){
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
                maxPrefixIndex = arrayCount;
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
            if(sequenceBytesNew[0] != sequenceBytesNew[count - 1] || sequenceBytesNew[0] == 'X'){
                for(i = 0; i < arrayCount; i++){
                    arrayNew[i] = array[i];
                }
            }
            else{
                processed = true;
                if(minPrefix < minSuffix){
                    sum = 0;
                    maxPrefix = 0;
                    maxPrefixIndex = -1;
                    for(i = 0; i < arrayCount; i++){
                        array[i] = -array[i];
                        sum += array[i];
                        if(sum > maxPrefix){
                            maxPrefix = sum;
                            maxPrefixIndex = i;
                        }
                    }
                }
                count++;
            }
        }
        minSuffix = sum - maxPrefix;
        if(count % 2 == 1){
            if(sequenceBytesNew[0] != sequenceBytesNew[count - 1] || sequenceBytesNew[0] == 'X' || processed){
                for(i = 0; i <= maxPrefixIndex; i++){
                    arrayNew[i] = array[i];
                }
                for(i = maxPrefixIndex + 1; i < arrayCount; i++){
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
            if(k == 1) tree.multiplyByMinusOne(0, arrayNew.length - 1);
            while(true){
                int min = tree.getMinSubsegment();
                if(tree.getMinSubsegment() >= 0){
                    break;
                }
                long range = tree.getMinSubsegmentRange();
                int rangeLeft = (int) (range >> 32);
                int rangeRight = (int) (range);
                tree.multiplyByMinusOne(rangeLeft, rangeRight);
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
        new Main11E().run();
    }

    public class SegmentTree {

        private int length;

        private int[] maxPrefixSum;
        private int[] minPrefixSum;
        private int[] maxSubsegmentSum;
        private int[] minSubsegmentSum;
        private int[] sum;
        private byte[] coeff;

        public SegmentTree(int[] array){
            length = array.length;
            int size = 1 + (int) Math.pow(2, Math.ceil(Math.log(2 * length - 1) / Math.log(2)));

            maxPrefixSum = new int[size];
            minPrefixSum = new int[size];
            maxSubsegmentSum = new int[size];
            minSubsegmentSum = new int[size];
            sum = new int[size];
            coeff = new byte[size];

            build(array, 0, length - 1, 1);
        }

        private void build(int[] array, int left, int right, int v){
            if(left == right){
                maxPrefixSum[v] = Math.max(0, array[left]);
                minPrefixSum[v] = Math.min(0, array[left]);
                maxSubsegmentSum[v] = Math.max(0, array[left]);
                minSubsegmentSum[v] = Math.min(0, array[left]);
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
            maxPrefixSum[v] = Math.max(maxPrefixSum[leftChild], sum[leftChild] + maxPrefixSum[rightChild]);
            minPrefixSum[v] = Math.min(minPrefixSum[leftChild], sum[leftChild] + minPrefixSum[rightChild]);
            maxSubsegmentSum[v] = Math.max(Math.max(maxSubsegmentSum[rightChild], maxSubsegmentSum[leftChild]),
                    sum[leftChild] - minPrefixSum[leftChild] + maxPrefixSum[rightChild]);
            minSubsegmentSum[v] = Math.min(Math.min(minSubsegmentSum[rightChild], minSubsegmentSum[leftChild]),
                    sum[leftChild] - maxPrefixSum[leftChild] + minPrefixSum[rightChild]);
            sum[v] = sum[leftChild] + sum[rightChild];
        }

        public void multiplyByMinusOne(int left, int right){
            multiplyByMinusOneRec(1, 0, length - 1, left, right);
        }

        private void multiplyByMinusOneRec(int v, int currentLeft, int currentRight, int left, int right){
            if(currentLeft == left && currentRight == right){
                int t  = maxPrefixSum[v];
                maxPrefixSum[v] =  -minPrefixSum[v];
                minPrefixSum[v] = -t;
                t = maxSubsegmentSum[v];
                maxSubsegmentSum[v] = -minSubsegmentSum[v];
                minSubsegmentSum[v] = -t;
                sum[v] *= -1;
                coeff[v] *= -1;
            }
            else{
                int mid = (currentLeft + currentRight) / 2;
                if(coeff[v] == 1){
                    if(left < mid + 1){
                        multiplyByMinusOneRec(2 * v, currentLeft, mid, left, Math.min(right, mid));
                    }
                    if(right > mid){
                        multiplyByMinusOneRec(2 * v + 1, mid + 1, currentRight, Math.max(mid + 1, left), right);
                    }
                }
                else{
                    coeff[v] = 1;
                    if(left >= mid + 1){
                        multiplyByMinusOneRec(2 * v, currentLeft, mid, currentLeft, mid);
                        if(left > mid + 1){
                            multiplyByMinusOneRec(2 * v + 1, mid + 1, currentRight, mid + 1, left - 1);
                        }
                        if(right < currentRight){
                            multiplyByMinusOneRec(2 * v + 1, mid + 1, currentRight, right + 1, currentRight);
                        }
                    }
                    else if(right <= mid){
                        multiplyByMinusOneRec(2 * v + 1, mid + 1, currentRight, mid + 1, currentRight);
                        if(left > currentLeft){
                            multiplyByMinusOneRec(2 * v, currentLeft, mid, currentLeft, left - 1);
                        }
                        if(right < mid){
                            multiplyByMinusOneRec(2 * v, currentLeft, mid, right + 1, mid);
                        }
                    }
                    else{
                        if(left > currentLeft){
                            multiplyByMinusOneRec(2 * v, currentLeft, mid, currentLeft, left - 1);
                        }
                        if(right < currentRight){
                            multiplyByMinusOneRec(2 * v + 1, mid + 1, currentRight, right + 1, currentRight);
                        }
                    }
                }
                combine(v);
            }
        }

        public int getMinSubsegment(){
            return minSubsegmentSum[1];
        }

        public long getMinSubsegmentRange(){
            if(minSubsegmentSum[1] == 0){
                return (1L << 32);
            }
            return getMinSubsegmentRangeRec(1, 0, length - 1);
        }

        private long getMinSubsegmentRangeRec(int v, int currentLeft, int currentRight){
            int mid = (currentLeft + currentRight) / 2;
            if(sum[v] == minSubsegmentSum[v]){
                long range = currentLeft;
                range <<= 32;
                range |= currentRight;
                return range;
            }
            if(coeff[v] == 1){
                if(minSubsegmentSum[v] == minSubsegmentSum[2 * v]){
                    return getMinSubsegmentRangeRec(2 * v, currentLeft, mid);
                }
                if(minSubsegmentSum[v] == minSubsegmentSum[2 * v + 1]){
                    return getMinSubsegmentRangeRec(2 * v + 1, mid + 1, currentRight);
                }
                long suffix = getMinSuffixRec(2 * v, currentLeft, mid);
                long prefix = getMinPrefixRec(2 * v + 1, mid + 1, currentRight);
                return (suffix << 32) | prefix;
            }
            else{
                if(minSubsegmentSum[v] == -maxSubsegmentSum[2 * v]){
                    return getMaxSubsegmentRangeRec(2 * v, currentLeft, mid);
                }
                if(minSubsegmentSum[v] == -maxSubsegmentSum[2 * v + 1]){
                    return getMaxSubsegmentRangeRec(2 * v + 1, mid + 1, currentRight);
                }
                long suffix = getMaxSuffixRec(2 * v, currentLeft, mid);
                long prefix = getMaxPrefixRec(2 * v + 1, mid + 1, currentRight);
                return (suffix << 32) | prefix;
            }
        }

        private long getMaxSubsegmentRangeRec(int v, int currentLeft, int currentRight){
            int mid = (currentLeft + currentRight) / 2;
            if(sum[v] == maxSubsegmentSum[v]){
                long range = currentLeft;
                range <<= 32;
                range |= currentRight;
                return range;
            }
            if(coeff[v] == 1){
                if(maxSubsegmentSum[v] == maxSubsegmentSum[2 * v]){
                    return getMaxSubsegmentRangeRec(2 * v, currentLeft, mid);
                }
                if(maxSubsegmentSum[v] == maxSubsegmentSum[2 * v + 1]){
                    return getMaxSubsegmentRangeRec(2 * v + 1, mid + 1, currentRight);
                }
                long suffix = getMaxSuffixRec(2 * v, currentLeft, mid);
                long prefix = getMaxPrefixRec(2 * v + 1, mid + 1, currentRight);
                return (suffix << 32) | prefix;
            }
            else{
                if(maxSubsegmentSum[v] == -minSubsegmentSum[2 * v]){
                    return getMinSubsegmentRangeRec(2 * v, currentLeft, mid);
                }
                if(maxSubsegmentSum[v] == -minSubsegmentSum[2 * v + 1]){
                    return getMinSubsegmentRangeRec(2 * v + 1, mid + 1, currentRight);
                }
                long suffix = getMinSuffixRec(2 * v, currentLeft, mid);
                long prefix = getMinPrefixRec(2 * v + 1, mid + 1, currentRight);
                return (suffix << 32) | prefix;
            }
        }

        private int getMinSuffixRec(int v, int currentLeft, int currentRight){
            int mid = (currentLeft + currentRight) / 2;
            if(sum[v] - maxPrefixSum[v] == sum[v]){
                return currentLeft;
            }
            else if (sum[v] - maxPrefixSum[v] == 0){
                return currentRight + 1;
            }
            if(coeff[v] == 1){
                if(sum[v] - maxPrefixSum[v] == sum[2 * v + 1] - maxPrefixSum[2 * v + 1]){
                    return getMinSuffixRec(2 * v + 1, mid + 1, currentRight);
                }
                else{
                    return getMinSuffixRec(2 * v, currentLeft, mid);
                }
            }
            else{
                if(sum[v] - maxPrefixSum[v] == -(sum[2 * v + 1] - minPrefixSum[2 * v + 1])){
                    return getMaxSuffixRec(2 * v + 1, mid + 1, currentRight);
                }
                else{
                    return getMaxSuffixRec(2 * v, currentLeft, mid);
                }
            }
        }

        private int getMaxSuffixRec(int v, int currentLeft, int currentRight){
            int mid = (currentLeft + currentRight) / 2;
            if(sum[v] - minPrefixSum[v] == sum[v]){
                return currentLeft;
            }
            else if (sum[v] - minPrefixSum[v] == 0){
                return currentRight + 1;
            }
            if(coeff[v] == 1){
                if(sum[v] - minPrefixSum[v] == sum[2 * v + 1] - minPrefixSum[2 * v + 1]){
                    return getMaxSuffixRec(2 * v + 1, mid + 1, currentRight);
                }
                else{
                    return getMaxSuffixRec(2 * v, currentLeft, mid);
                }
            }
            else{
                if(sum[v] - minPrefixSum[v] == -(sum[2 * v + 1] - maxPrefixSum[2 * v + 1])){
                    return getMinSuffixRec(2 * v + 1, mid + 1, currentRight);
                }
                else{
                    return getMinSuffixRec(2 * v, currentLeft, mid);
                }
            }
        }

        private int getMinPrefixRec(int v, int currentLeft, int currentRight){
            int mid = (currentLeft + currentRight) / 2;
            if(minPrefixSum[v] == sum[v]){
                return currentRight;
            }
            else if (minPrefixSum[v] == 0){
                return currentLeft - 1;
            }
            if(coeff[v] == 1){
                if(minPrefixSum[v] == minPrefixSum[2 * v]){
                    return getMinPrefixRec(2 * v, currentLeft, mid);
                }
                else{
                    return getMinPrefixRec(2 * v + 1, mid + 1, currentRight);
                }
            }
            else{
                if(minPrefixSum[v] == -maxPrefixSum[2 * v]){
                    return getMaxPrefixRec(2 * v, currentLeft, mid);
                }
                else{
                    return getMaxPrefixRec(2 * v + 1, mid + 1, currentRight);
                }
            }
        }

        private int getMaxPrefixRec(int v, int currentLeft, int currentRight){
            int mid = (currentLeft + currentRight) / 2;
            if(maxPrefixSum[v] == sum[v]){
                return currentRight;
            }
            else if (maxPrefixSum[v] == 0){
                return currentLeft - 1;
            }
            if(coeff[v] == 1){
                if(maxPrefixSum[v] == maxPrefixSum[2 * v]){
                    return getMaxPrefixRec(2 * v, currentLeft, mid);
                }
                else{
                    return getMaxPrefixRec(2 * v + 1, mid + 1, currentRight);
                }
            }
            else{
                if(maxPrefixSum[v] == -minPrefixSum[2 * v]){
                    return getMinPrefixRec(2 * v, currentLeft, mid);
                }
                else{
                    return getMinPrefixRec(2 * v + 1, mid + 1, currentRight);
                }
            }
        }
    }

}