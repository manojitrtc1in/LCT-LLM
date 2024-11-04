#include <stdio.h>
#include <stdlib.h>

typedef long long int ll;
typedef unsigned long long llu;
typedef long double lld;

lld pi = 2 * acosl(0.0);

int id1, test_case = 1;

ll** main_array;
ll** dp_table;

void function_name()
{
    int array_number, operation_number;
    scanf("%d %d", &array_number, &operation_number);

    ll** id3 = (ll**)malloc(operation_number * sizeof(ll*));
    for (int i = 0; i < operation_number; i++)
    {
        id3[i] = (ll*)malloc(array_number * sizeof(ll));
    }

    main_array = (ll**)malloc(array_number * sizeof(ll*));
    for (int i = 0; i < array_number; i++)
    {
        main_array[i] = (ll*)malloc(operation_number * sizeof(ll));
    }

    int maximum = 0;
    dp_table = (ll**)malloc(array_number * sizeof(ll*));
    for (int i = 0; i < array_number; i++)
    {
        dp_table[i] = (ll*)malloc((operation_number + 1) * sizeof(ll));
        for (int j = 0; j <= operation_number; j++)
        {
            dp_table[i][j] = maximum;
        }
    }

    for (int i = 0; i < array_number; i++)
    {
        int element_number;
        scanf("%d", &element_number);
        for (int j = 0; j < element_number; j++)
        {
            ll element;
            scanf("%lld", &element);
            if (j < operation_number)
            {
                main_array[i][j] = element + (j > 0) * main_array[i][j - 1];
                id3[j][i] = main_array[i][j];
            }
        }
    }

    for (int i = 0; i < operation_number; i++)
    {
        for (int j = 0; j < array_number; j++)
        {
            for (int k = j + 1; k < array_number; k++)
            {
                if (id3[i][j] < id3[i][k])
                {
                    ll temp = id3[i][j];
                    id3[i][j] = id3[i][k];
                    id3[i][k] = temp;
                }
            }
        }
    }

    for (int i = 0; i < array_number; i++)
    {
        for (int j = 0; j < operation_number; j++)
        {
            if (main_array[i][j] < id3[j][operation_number / (j + 1) < array_number - 1 ? operation_number / (j + 1) : array_number - 1])
            {
                main_array[i][j] = 0;
            }
        }
    }

    for (int id0 = 0; id0 < array_number; id0++)
    {
        if (id0 > 0)
        {
            for (int i = 0; i <= operation_number; i++)
            {
                dp_table[id0][i] = dp_table[id0 - 1][i];
            }
        }

        for (int id2 = 0; id2 < operation_number; id2++)
        {
            if (main_array[id0][id2] != 0)
            {
                for (int operation_left = operation_number, old = operation_number - (id2 + 1); operation_left > id2; operation_left--, old--)
                {
                    if (id0 == 0)
                    {
                        if (dp_table[id0][operation_left] < main_array[id0][id2])
                        {
                            dp_table[id0][operation_left] = main_array[id0][id2];
                        }
                    }
                    else
                    {
                        if (dp_table[id0][operation_left] < main_array[id0][id2] + dp_table[id0 - 1][old])
                        {
                            dp_table[id0][operation_left] = main_array[id0][id2] + dp_table[id0 - 1][old];
                        }
                    }
                }
            }
        }
    }

    ll answer = dp_table[array_number - 1][operation_number];
    printf("%lld\n", answer);
}

void function_name_int(int v1, int v2, int v3)
{

}

void function_name_string(char* line)
{

}

typedef struct
{
    void (*with_test_case_number)();
    void (*single_iteration)();
    void (*without_test_case_number)();
    void (*eoof)();
} initial_works;

void with_test_case_number()
{
    scanf("%d", &id1);

    while (test_case <= id1)
    {
        function_name();
        test_case++;
    }
}

void single_iteration()
{
    function_name();
}

void without_test_case_number()
{
    int v1, v2, v3;
    while (scanf("%d %d %d", &v1, &v2, &v3) == 3 && v1 != 0)
    {
        function_name_int(v1, v2, v3);
        test_case++;
    }
}

void eoof()
{
    char id4[100] = { 0 };
    while (scanf("%[^\n]", id4) != EOF)
    {
        getchar();

        char* line = id4;
        function_name_string(line);
        test_case++;
    }
}

int main()
{
    freopen("output.txt", "w", stdout);

    initial_works a;
    a.single_iteration();

    return 0;
}
