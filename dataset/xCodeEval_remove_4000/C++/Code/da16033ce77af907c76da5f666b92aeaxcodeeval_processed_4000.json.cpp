





























































typedef long long int ll;
typedef unsigned long long llu;
typedef long double lld;
template <class T> using ordered_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, std::less<T>, __gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>;
template<class T> using matrix = std::vector<std::vector<T>>;



lld pi = 2 * acosl(0.0);

int id1, test_case=1;



















std::vector<std::vector<ll>> main_array;
std::vector<std::vector<ll>> dp_table;

void function_name()
{
    int array_number, operation_number;
    scanf("%d %d",&array_number, &operation_number);

    std::vector<std::vector<ll>> id3 (operation_number, std::vector<ll>(array_number,0));

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
                id3[j][i] = main_array[i][j];
            }
        }
    }

    for(int i=0;i<operation_number;i++)
    {
        std::sort(id3[i].begin(),id3[i].end(), std::greater<ll>());
    }

    for(int i=0;i<array_number;i++)
    {
        for(int j=0;j<operation_number;j++)
        {
            if(main_array[i][j] < id3[j][std::min(operation_number/(j+1), array_number-1)])
            {
                

                

                

                main_array[i][j] = 0;
            }
        }
    }

    for(int id0 = 0; id0<array_number; id0++)
    {
        if(id0>0)
        {
            dp_table[id0] = dp_table[id0-1];
        }

        for(int id2 = 0; id2< operation_number; id2++)
        {
            if(main_array[id0][id2] != 0)
            {
                for(int operation_left = operation_number, old = operation_number-(id2+1); operation_left > id2; operation_left--, old-- )
                {
                    if(id0 == 0)
                    {
                        dp_table[id0][operation_left]=std::max(dp_table[id0][operation_left], main_array[id0][id2]);
                    }
                    else
                    {
                        dp_table[id0][operation_left]=std::max(dp_table[id0][operation_left], main_array[id0][id2] + dp_table[id0-1][old]);
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
        scanf("%d", &id1);
        

        while(test_case <= id1)
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
        char id4[100]={0};
        while(scanf("%[^\n]", &id4)!=EOF)
        {
            

            getchar();
            

            

            std::string line = id4;
            function_name(line);
            test_case++;
        }
    }
};


int main()
{
    

    
        

        freopen("output.txt", "w", stdout);
    

    initial_works a;
    a.single_iteration();

    return 0;
}
























































































