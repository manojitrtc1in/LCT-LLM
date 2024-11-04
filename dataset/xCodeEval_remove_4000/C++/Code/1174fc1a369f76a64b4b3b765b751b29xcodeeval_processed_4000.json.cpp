
using namespace std;




int arr[100000][2];
void id4 (int arrayy[][2],int left,int middle,int right,int column)
{
    int dep=1,ind=1;
    if (column ==0)
        ind=0;
    else
        dep=0;

    int i=left,k2=middle+1,k1=left;
    for (; k1<=middle && k2<=right; i++)
        if (arrayy[k1][ind]<arrayy[k2][ind])
        {
            arr[i][dep] =arrayy[k1][dep];
            arr[i][ind] =arrayy[k1++][ind];
        }
        else
        {
            arr[i][dep] =arrayy[k2][dep];
            arr[i][ind]=arrayy[k2++][ind];

        }

    while (k2<=right)
    {
        arr[i][dep]=arrayy[k2][dep];
        arr[i++][ind]=arrayy[k2++][ind];
    }
    while (k1<=middle)
    {
        arr[i][dep]=arrayy[k1][dep];
        arr[i++][ind]=arrayy[k1++][ind];
    }

    for (i=left; i<=right; i++)
    {
        arrayy[i][ind]=arr[i][ind];
        arrayy[i][dep]=arr[i][dep];

    }
}

void id2  (int  arrayy[][2],int left,int right,int column)
{
    int middle;
    if (left<right)
    {
        middle = (left+right)/2;
        id2(arrayy,left,middle,column);
        id2(arrayy,middle+1,right,column);
        id4(arrayy,left,middle,right,column);
    }
    else
        return;
}

int id5(int value,int arrayyy[][2],int length)
{
    int left=0,right=length,mid=(left+right)/2;
    while(left<=right)
    {
        int zft=arrayyy[mid][0];
        if(value>arrayyy[mid][0])
        {
            left=mid+1;
            mid=(left+right)/2;
        }
        else if (value<arrayyy[mid][0])
        {
            right=mid-1;
            mid=(left+right)/2;
        }
        else
            return mid;
    }
    return 999999999;
}

int id1(int value,int arrayyy[][2],int length)
{
    int left=0,right=length,mid=(left+right)/2;
    while(left<=right)
    {
        int zft=arrayyy[mid][0];
        if(value>arrayyy[mid][0])
        {
            left=mid+1;
            mid=(left+right)/2;
        }
        else if (value<arrayyy[mid][0])
        {
            right=mid-1;
            mid=(left+right)/2;
        }
        else
            return mid;
    }
    return mid;
}


int GCD( int a,int b)
{
    if(a==0)
        return b;
    else
        return GCD(b%a,a);
}

long long combination(long long n, long long r)
{
    int gcd;
    long long cnt=1;
    vector<int> N;
    vector<int> N_R;
    for(int i=r+1; i<=n; i++)
        N.push_back(i);
    for(int i=2; i<=n-r; i++)
        N_R.push_back(i);
    for(int i=0; i<N_R.size(); i++)
        for(int j=0; j<N.size(); j++)
        {
            gcd=GCD( N[j],N_R[i]);
            N[j]=N[j]/gcd;
            N_R[i]=N_R[i]/gcd;
            if(N_R[i]==1)
                break;
        }
    for(int i=0; i<N.size(); i++)
        cnt*=N[i];
    return cnt;
}
vector<int> id3(int num)
{
    vector<int>id0;
    for(int i=2; i/2<=num; i++)
        while(num%i==0)
        {
            id0.push_back(i);
            num=num/i;
        }
    return id0;
}
bool visited[101]= {0};
vector<int>employee_languages[100];

void DFS(int node)
{
    if(visited[node])
        return ;
    visited[node]=true;
    for(int i=0; i<employee_languages[node].size(); i++)
    {
        int child=employee_languages[node][i];
        if(!visited[child])
            DFS(child);
    }
}

int connected_component(int m)
{
    int cnt=0;
    for(int i=1; i<=m; i++)
        if(!visited[i])
        {
            DFS(i);
            cnt++;
        }
    return cnt;
}

vector<int>factorization(int num)
{
    vector<int> ans;
    for(int i=1; i*i<=num; i++)
        if(num%i==0)
        {
            ans.push_back(i);
            ans.push_back(num/i);
        }
    sort(ans.begin(),ans.end());
    return ans;
}


bool binary (vector<int >&vec,int lenght,long long int val)
{
    int left=0,right=lenght-1,mid=(left+right)/2;
    while(left<=right)
    {
        if(vec[mid]==val)
        {
            vec[mid]=0;
            return true;
        }
        else if(vec[mid]>val)
        {
            right=mid-1;
            mid=(left+right)/2;
        }
        else
        {
            left=mid+1;
            mid=(left+right)/2;
        }
    }
    return false;
}
int main()
{





    




    




    




    




    




    




    




    




    




    




    




    





    




    





    

    



    




    












    




    




    




    




    




    




    




    




    




    




    




    




    

    



    





    int n,m,z;
    cin>>n;
    int targets[n][2],copied[n][2];
    for(int i=0; i<n; i++)
        cin>>targets[i][0]>>targets[i][1];
    for(int i=0; i<n; i++)
    {
        copied[i][0]=targets[i][0];
        copied[i][1]=targets[i][1];
    }
    cin>>m;
    int shots[m][2];
    for(int i=0; i<m; i++)
        cin>>shots[i][0]>>shots[i][1];
    id2(targets,0,n-1,0);
    int up,down,exact;
    int ans[n];
    for(int i=0; i<n; i++)
        ans[i]=-1;
    int cnt=0;
    for(int j=0; j<m; j++)
    {
        int value=shots[j][0];
        int x=targets[1][0];
        

        int Y=abs(shots[j][1]);
        exact=id5(value,targets,n-1);
        if(exact==999999999)
        {
            up= id1(value,targets,n-1);
            if(targets[up][0]<value)
                up++;
            down=up-1;
            if(up <= n-1&&sqrt(Y*Y+(value-targets[up][0])*(value-targets[up][0]))<=targets[up][1] && ans[up]==-1)
            {
                ans[up]=j+1;
                cnt++;
            }
            if(down>=0 && sqrt(Y*Y+(value-targets[down][0])*(value-targets[down][0]))<=targets[down][1] && ans[down]==-1)
            {
                ans[down]=j+1;
                cnt++;
            }
        }
        else if(Y<=targets[exact][1] && ans[exact]==-1)
        {
            ans[exact]=j+1;
            cnt++;
        }
    }
    cout<<cnt<<endl;
    for(int i=0; i<n; i++)
    {
        z=id5(copied[i][0],targets,n-1);
        cout<<ans[z]<<" ";
    }
    return 0;
}
