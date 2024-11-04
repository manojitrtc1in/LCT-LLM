#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define p(x) printf(#x " = %d\n", x)
#define mem(a,b) memset(a,b,sizeof(a))
#define mod1 1000000007
#define mod2 998244353
#define absolute(x) (((x)<0)?(-(x)):(x))

typedef long long int ll;
typedef unsigned long long llu;
typedef long double lld;

int test_case_number, test_case=1;

ll pi;

typedef struct {
    ll* array;
    int size;
} vector;

typedef struct {
    vector* array;
    int size;
} matrix;

vector main_array;
matrix dp_table;

void function_name()
{
    int array_number, operation_number;
    scanf("%d %d",&array_number, &operation_number);

    vector reversed_array;
    reversed_array.size = operation_number;
    reversed_array.array = (ll*)malloc(operation_number * sizeof(ll));
    for(int i=0;i<operation_number;i++)
    {
        reversed_array.array[i] = (ll*)malloc(array_number * sizeof(ll));
    }

    main_array.size = array_number;
    main_array.array = (ll*)malloc(array_number * sizeof(ll));
    for(int i=0;i<array_number;i++)
    {
        main_array.array[i] = (ll*)malloc(operation_number * sizeof(ll));
    }

    int maximum = 0;
    dp_table.size = array_number;
    dp_table.array = (vector*)malloc(array_number * sizeof(vector));
    for(int i=0;i<array_number;i++)
    {
        dp_table.array[i].size = operation_number+1;
        dp_table.array[i].array = (ll*)malloc((operation_number+1) * sizeof(ll));
        for(int j=0;j<operation_number+1;j++)
        {
            dp_table.array[i].array[j] = maximum;
        }
    }

    for(int i=0;i<array_number;i++)
    {
        int element_number;
        scanf("%d",&element_number);
        for(int j=0;j<element_number;j++)
        {
            ll element;
            scanf("%lld",&element);
            if(j<operation_number)
            {
                main_array.array[i][j] = element + (j>0)*main_array.array[i][j-1];
                reversed_array.array[j][i] = main_array.array[i][j];
            }
        }
    }

    for(int i=0;i<operation_number;i++)
    {
        for(int j=0;j<array_number;j++)
        {
            for(int k=j+1;k<array_number;k++)
            {
                if(reversed_array.array[i][j] < reversed_array.array[i][k])
                {
                    ll temp = reversed_array.array[i][j];
                    reversed_array.array[i][j] = reversed_array.array[i][k];
                    reversed_array.array[i][k] = temp;
                }
            }
        }
    }

    for(int i=0;i<array_number;i++)
    {
        for(int j=0;j<operation_number;j++)
        {
            if(main_array.array[i][j] < reversed_array.array[j][operation_number/(j+1) < array_number-1 ? operation_number/(j+1) : array_number-1])
            {
                main_array.array[i][j] = 0;
            }
        }
    }

    for(int current_array_no = 0; current_array_no<array_number; current_array_no++)
    {
        if(current_array_no>0)
        {
            for(int i=0;i<operation_number+1;i++)
            {
                dp_table.array[current_array_no].array[i] = dp_table.array[current_array_no-1].array[i];
            }
        }

        for(int current_column_no = 0; current_column_no< operation_number; current_column_no++)
        {
            if(main_array.array[current_array_no][current_column_no] != 0)
            {
                for(int operation_left = operation_number, old = operation_number-(current_column_no+1); operation_left > current_column_no; operation_left--, old-- )
                {
                    if(current_array_no == 0)
                    {
                        dp_table.array[current_array_no].array[operation_left] = main_array.array[current_array_no][current_column_no];
                    }
                    else
                    {
                        dp_table.array[current_array_no].array[operation_left] = main_array.array[current_array_no][current_column_no] + dp_table.array[current_array_no-1].array[old];
                    }
                }
            }
        }
    }

    ll answer = dp_table.array[array_number-1].array[operation_number];
    printf("%lld\n",answer);
}

void function_name(int v1, int v2, int v3)
{

}

void function_name(char* line)
{

}

typedef struct {
    void (*with_test_case_number)();
    void (*single_iteration)();
    void (*without_test_case_number)();
    void (*eoof)();
} initial_works;

void initial_works_with_test_case_number()
{
    scanf("%d", &test_case_number);

    while(test_case <= test_case_number)
    {
        function_name();
        test_case++;
    }
}

void initial_works_single_iteration()
{
    function_name();
}

void initial_works_without_test_case_number()
{
    int v1, v2, v3;
    while(scanf("%d %d %d", &v1, &v2, &v3)==3 && v1!=0)
    {
        function_name(v1, v2, v3);
        test_case++;
    }
}

void initial_works_eoof()
{
    char dummy_char_array[100]={0};
    while(scanf("%[^\n]", &dummy_char_array)!=EOF)
    {
        getchar();

        char* line = dummy_char_array;
        function_name(line);
        test_case++;
    }
}

int main()
{
    initial_works a;
    a.single_iteration();

    return 0;
}
