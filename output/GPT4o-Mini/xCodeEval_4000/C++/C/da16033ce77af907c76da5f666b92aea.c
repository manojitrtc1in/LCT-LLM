#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define MAX_ARRAY_SIZE 1000
#define MAX_OPERATION_SIZE 1000
#define MOD1 1000000007
#define MOD2 998244353

typedef long long ll;

ll main_array[MAX_ARRAY_SIZE][MAX_OPERATION_SIZE];
ll reversed_array[MAX_OPERATION_SIZE][MAX_ARRAY_SIZE];
ll dp_table[MAX_ARRAY_SIZE][MAX_OPERATION_SIZE + 1];

void function_name() {
    int array_number, operation_number;
    scanf("%d %d", &array_number, &operation_number);

    memset(main_array, 0, sizeof(main_array));
    memset(reversed_array, 0, sizeof(reversed_array));
    memset(dp_table, 0, sizeof(dp_table));

    for (int i = 0; i < array_number; i++) {
        int element_number;
        scanf("%d", &element_number);
        for (int j = 0; j < element_number; j++) {
            ll element;
            scanf("%lld", &element);
            if (j < operation_number) {
                main_array[i][j] = element + (j > 0) * main_array[i][j - 1];
                reversed_array[j][i] = main_array[i][j];
            }
        }
    }

    for (int i = 0; i < operation_number; i++) {
        qsort(reversed_array[i], array_number, sizeof(ll), (int (*)(const void *, const void *))greater);
    }

    for (int i = 0; i < array_number; i++) {
        for (int j = 0; j < operation_number; j++) {
            if (main_array[i][j] < reversed_array[j][fmin(operation_number / (j + 1), array_number - 1)]) {
                main_array[i][j] = 0;
            }
        }
    }

    for (int current_array_no = 0; current_array_no < array_number; current_array_no++) {
        if (current_array_no > 0) {
            memcpy(dp_table[current_array_no], dp_table[current_array_no - 1], sizeof(dp_table[0]));
        }

        for (int current_column_no = 0; current_column_no < operation_number; current_column_no++) {
            if (main_array[current_array_no][current_column_no] != 0) {
                for (int operation_left = operation_number, old = operation_number - (current_column_no + 1); operation_left > current_column_no; operation_left--, old--) {
                    if (current_array_no == 0) {
                        dp_table[current_array_no][operation_left] = fmax(dp_table[current_array_no][operation_left], main_array[current_array_no][current_column_no]);
                    } else {
                        dp_table[current_array_no][operation_left] = fmax(dp_table[current_array_no][operation_left], main_array[current_array_no][current_column_no] + dp_table[current_array_no - 1][old]);
                    }
                }
            }
        }
    }

    ll answer = dp_table[array_number - 1][operation_number];
    printf("%lld\n", answer);
}

void function_name_with_args(int v1, int v2, int v3) {
    // Implementation for this function can be added if needed
}

void function_name_with_string(char *line) {
    // Implementation for this function can be added if needed
}

int main() {
    int test_case_number, test_case = 1;
    scanf("%d", &test_case_number);

    while (test_case <= test_case_number) {
        function_name();
        test_case++;
    }

    return 0;
}
