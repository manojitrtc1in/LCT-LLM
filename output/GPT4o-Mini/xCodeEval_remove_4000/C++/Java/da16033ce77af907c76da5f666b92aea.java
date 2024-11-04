import java.util.*;

public class da16033ce77af907c76da5f666b92aeaxcodeeval_processed_4000.json {
    static long pi = 2 * Math.acos(0.0);
    static int id1, test_case = 1;
    static long[][] main_array;
    static long[][] dp_table;

    public static void function_name() {
        Scanner scanner = new Scanner(System.in);
        int array_number = scanner.nextInt();
        int operation_number = scanner.nextInt();

        long[][] id3 = new long[operation_number][array_number];
        main_array = new long[array_number][operation_number];

        long maximum = 0;
        dp_table = new long[array_number][operation_number + 1];
        for (int i = 0; i < array_number; i++) {
            int element_number = scanner.nextInt();
            for (int j = 0; j < element_number; j++) {
                long element = scanner.nextLong();
                if (j < operation_number) {
                    main_array[i][j] = element + (j > 0 ? main_array[i][j - 1] : 0);
                    id3[j][i] = main_array[i][j];
                }
            }
        }

        for (int i = 0; i < operation_number; i++) {
            Arrays.sort(id3[i]);
            reverseArray(id3[i]);
        }

        for (int i = 0; i < array_number; i++) {
            for (int j = 0; j < operation_number; j++) {
                if (main_array[i][j] < id3[j][Math.min(operation_number / (j + 1), array_number - 1)]) {
                    main_array[i][j] = 0;
                }
            }
        }

        for (int id0 = 0; id0 < array_number; id0++) {
            if (id0 > 0) {
                dp_table[id0] = Arrays.copyOf(dp_table[id0 - 1], dp_table[id0 - 1].length);
            }

            for (int id2 = 0; id2 < operation_number; id2++) {
                if (main_array[id0][id2] != 0) {
                    for (int operation_left = operation_number, old = operation_number - (id2 + 1); operation_left > id2; operation_left--, old--) {
                        if (id0 == 0) {
                            dp_table[id0][operation_left] = Math.max(dp_table[id0][operation_left], main_array[id0][id2]);
                        } else {
                            dp_table[id0][operation_left] = Math.max(dp_table[id0][operation_left], main_array[id0][id2] + dp_table[id0 - 1][old]);
                        }
                    }
                }
            }
        }

        long answer = dp_table[array_number - 1][operation_number];
        System.out.println(answer);
    }

    public static void function_name(int v1, int v2, int v3) {
        // Overloaded method
    }

    public static void function_name(String line) {
        // Overloaded method
    }

    static class InitialWorks {
        public void withTestCaseNumber() {
            Scanner scanner = new Scanner(System.in);
            id1 = scanner.nextInt();

            while (test_case <= id1) {
                function_name();
                test_case++;
            }
        }

        public void singleIteration() {
            function_name();
        }

        public void withoutTestCaseNumber() {
            Scanner scanner = new Scanner(System.in);
            while (true) {
                int v1 = scanner.nextInt();
                int v2 = scanner.nextInt();
                int v3 = scanner.nextInt();
                if (v1 == 0) break;
                function_name(v1, v2, v3);
                test_case++;
            }
        }

        public void eoof() {
            Scanner scanner = new Scanner(System.in);
            while (scanner.hasNextLine()) {
                String line = scanner.nextLine();
                function_name(line);
                test_case++;
            }
        }
    }

    public static void main(String[] args) {
        InitialWorks a = new InitialWorks();
        a.singleIteration();
    }

    private static void reverseArray(long[] array) {
        for (int i = 0; i < array.length / 2; i++) {
            long temp = array[i];
            array[i] = array[array.length - 1 - i];
            array[array.length - 1 - i] = temp;
        }
    }
}
