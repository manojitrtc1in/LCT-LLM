












using namespace std;
typedef long long int lld;
typedef double llf;
vector<int> prime;
int num[100]= {};
bool isPrime(lld n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (lld i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}
void id4()
{
    for(int i=2; i<250; i++)
    {
        if(!num[i])
        {
            for(int j=i; j<250; j+=i)
            {
                num[j]=1;
            }
            prime.pb(i);
        }

    }
}
void eraseDemo(string str,int i)
{
    

    str.erase(i);
}
string id3(string arr[], int n)
{
    

    sort(arr, arr + n);

    

    int max_count = 1,  curr_count = 1;
    string res = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] == arr[i - 1])
            curr_count++;
        else
        {
            if (curr_count > max_count)
            {
                max_count = curr_count;
                res = arr[i - 1];
            }
            curr_count = 1;
        }
    }

    

    if (curr_count > max_count)
    {
        max_count = curr_count;
        res = arr[n - 1];
    }

    return res;
}
bool id1(int arr[], int n)
{
    

    if (n == 0 || n == 1)
        return true;

    for (int i = 1; i < n; i++)

        

        if (arr[i - 1] > arr[i])
            return false;

    

    return true;
}
void make_small(string j)
{
    for(int i=0; i<j.size(); i++)
    {
        if(j[i]<'a')
        {
            j[i]=(j[i]-'A')+'a';
        }
    }
}
int id0(int arr[], int n)
{
    int temp = arr[0];
    for(int i=0; i<n; i++)
    {
        if(temp>arr[i])
        {
            temp=arr[i];
        }
    }
    return temp;
}
float smallest(int x, int y, int z)
{

    int smallest = 99999;

    if (x < smallest)
        smallest=x;
    if (y < smallest)
        smallest=y;
    if(z < smallest)
        smallest=z;

    return smallest;
}
void print_string(string a)
{
    for(int i=0; i<a.size(); i++)
    {
        cout<<a[i];
    }
}
int id2(string l)
{
    int max1=0,v1=0;
    for(int i=0; i<l.size()-1; i++)
    {
        if(l[i]!=l[i+1])
        {
            v1++;
        }
        else
        {
            v1=0;
        }
        if(max1<=v1)
        {
            max1=v1;
        }
    }
    if(l[l.size()-1]!=l[l.size()-2])
        max1++;
    return max1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    
    
    
    
    
    
    
    
    
    
    

    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    

    
    
    
    
    
    
    
    int n,k;
    int p=0,sol=0;
    cin>>n>>k;
    int freq[10]={0};
    while(n--)
    {
        string vv;
        cin>>vv;
        for(int i=0;i<=k;i++)
        {
            for(int j=0;j<vv.size();j++)
            {
                if(vv[j]-'0'==i)
                {
                    p++;
                    break;
                }
            }
        }
        if(p==k+1)
            sol++;
        p=0;
    }
    cout<<sol;
}
