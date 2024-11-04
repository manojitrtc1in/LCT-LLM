import java.util.*;

public class da16033ce77af907c76da5f666b92aea_nc {
    static long[][] mainArray;
    static long[][] dpTable;
    static int testCaseNumber, testCase = 1;

    public static void functionName() {
        Scanner scanner = new Scanner(System.in);
        int arrayNumber = scanner.nextInt();
        int operationNumber = scanner.nextInt();

        long[][] reversedArray = new long[operationNumber][arrayNumber];
        mainArray = new long[arrayNumber][operationNumber];

        long maximum = 0;
        dpTable = new long[arrayNumber][operationNumber + 1];
        for (int i = 0; i < arrayNumber; i++) {
            int elementNumber = scanner.nextInt();
            for (int j = 0; j < elementNumber; j++) {
                long element = scanner.nextLong();
                if (j < operationNumber) {
                    mainArray[i][j] = element + (j > 0 ? mainArray[i][j - 1] : 0);
                    reversedArray[j][i] = mainArray[i][j];
                }
            }
        }

        for (int i = 0; i < operationNumber; i++) {
            Arrays.sort(reversedArray[i]);
            reverse(reversedArray[i]);
        }

        for (int i = 0; i < arrayNumber; i++) {
            for (int j = 0; j < operationNumber; j++) {
                if (mainArray[i][j] < reversedArray[j][Math.min(operationNumber / (j + 1), arrayNumber - 1)]) {
                    mainArray[i][j] = 0;
                }
            }
        }

        for (int currentArrayNo = 0; currentArrayNo < arrayNumber; currentArrayNo++) {
            if (currentArrayNo > 0) {
                dpTable[currentArrayNo] = dpTable[currentArrayNo - 1].clone();
            }

            for (int currentColumnNo = 0; currentColumnNo < operationNumber; currentColumnNo++) {
                if (mainArray[currentArrayNo][currentColumnNo] != 0) {
                    for (int operationLeft = operationNumber, old = operationNumber - (currentColumnNo + 1); operationLeft > currentColumnNo; operationLeft--, old--) {
                        if (currentArrayNo == 0) {
                            dpTable[currentArrayNo][operationLeft] = Math.max(dpTable[currentArrayNo][operationLeft], mainArray[currentArrayNo][currentColumnNo]);
                        } else {
                            dpTable[currentArrayNo][operationLeft] = Math.max(dpTable[currentArrayNo][operationLeft], mainArray[currentArrayNo][currentColumnNo] + dpTable[currentArrayNo - 1][old]);
                        }
                    }
                }
            }
        }

        long answer = dpTable[arrayNumber - 1][operationNumber];
        System.out.println(answer);
    }

    public static void reverse(long[] array) {
        for (int i = 0; i < array.length / 2; i++) {
            long temp = array[i];
            array[i] = array[array.length - 1 - i];
            array[array.length - 1 - i] = temp;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        testCaseNumber = scanner.nextInt();

        while (testCase <= testCaseNumber) {
            functionName();
            testCase++;
        }
    }
}
