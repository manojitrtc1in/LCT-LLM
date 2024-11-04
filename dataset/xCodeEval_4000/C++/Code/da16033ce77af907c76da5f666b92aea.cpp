



















#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <string>
#include <sstream>
#include <cstdio>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <deque>
#include <bitset>
#include <string.h>
#include <climits>
#include <set>
#include <cassert>
#include <cfloat>
#include <stack>
#include <unordered_map>
#include <functional>
#include <chrono>

#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>








#define p(x) std::cout<<#x<<" = "<<x<<"\n"
#define mem(a,b) memset(a,b,sizeof(a))
#define mod1 1000000007
#define mod2 998244353
#define absolute(x) (((x)<0)?(-(x)):(x))




typedef long long int ll;
typedef unsigned long long llu;
typedef long double lld;
template <class T> using ordered_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, std::less<T>, __gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>;
template<class T> using matrix = std::vector<std::vector<T>>;



lld pi = 2 * acosl(0.0);

int test_case_number, test_case=1;



















std::vector<std::vector<ll>> main_array;
std::vector<std::vector<ll>> dp_table;

void function_name()
{
    int array_number, operation_number;
    scanf("%d %d",&array_number, &operation_number);

    std::vector<std::vector<ll>> reversed_array (operation_number, std::vector<ll>(array_number,0));

    main_array = std::vector<std::vector<ll>>(array_number , std::vector<ll>(operation_number,0));
    

    

    int maximum = 0;
    dp_table = std::vector<std::vector<ll>>(array_number, std::vector<ll>(operation_number+1, maximum));

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
                main_array[i][j] = element + (j>0)*main_array[i][j-1];
                reversed_array[j][i] = main_array[i][j];
            }
        }
    }

    for(int i=0;i<operation_number;i++)
    {
        std::sort(reversed_array[i].begin(),reversed_array[i].end(), std::greater<ll>());
    }

    for(int i=0;i<array_number;i++)
    {
        for(int j=0;j<operation_number;j++)
        {
            if(main_array[i][j] < reversed_array[j][std::min(operation_number/(j+1), array_number-1)])
            {
                

                

                

                main_array[i][j] = 0;
            }
        }
    }

    for(int current_array_no = 0; current_array_no<array_number; current_array_no++)
    {
        if(current_array_no>0)
        {
            dp_table[current_array_no] = dp_table[current_array_no-1];
        }

        for(int current_column_no = 0; current_column_no< operation_number; current_column_no++)
        {
            if(main_array[current_array_no][current_column_no] != 0)
            {
                for(int operation_left = operation_number, old = operation_number-(current_column_no+1); operation_left > current_column_no; operation_left--, old-- )
                {
                    if(current_array_no == 0)
                    {
                        dp_table[current_array_no][operation_left]=std::max(dp_table[current_array_no][operation_left], main_array[current_array_no][current_column_no]);
                    }
                    else
                    {
                        dp_table[current_array_no][operation_left]=std::max(dp_table[current_array_no][operation_left], main_array[current_array_no][current_column_no] + dp_table[current_array_no-1][old]);
                    }
                }
            }
        }
    }

    ll answer = dp_table[array_number-1][operation_number];
    printf("%lld\n",answer);
}
void function_name(int v1, int v2, int v3)
{

}
void function_name(std::string line)
{

}
class initial_works
{
public:

    void with_test_case_number()
    {
        scanf("%d", &test_case_number);
        

        while(test_case <= test_case_number)
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
        while(scanf("%d %d %d", &v1, &v2, &v3)==3 && v1!=0)
        {
            function_name(v1, v2, v3);
            test_case++;
        }
    }

    void eoof()
    {
        char dummy_char_array[100]={0};
        while(scanf("%[^\n]", &dummy_char_array)!=EOF)
        {
            

            getchar();
            

            

            std::string line = dummy_char_array;
            function_name(line);
            test_case++;
        }
    }
};


int main()
{
    

    #ifdef _DEBUG
        

        freopen("output.txt", "w", stdout);
    #endif

    initial_works a;
    a.single_iteration();

    return 0;
}
























































































