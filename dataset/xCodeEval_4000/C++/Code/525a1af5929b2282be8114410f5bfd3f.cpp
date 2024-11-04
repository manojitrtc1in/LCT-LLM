






























#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <iomanip>
#include <stdio.h>
#include <time.h>
using namespace std;





















































































#define vc   vector 
#define sz(v)  (int)(v.size())
#define pb(a)  push_back(a)
#define each(it,s)  for(auto it = s.begin(); it != s.end(); it++)
#define rep(i, b, n)  for(int i = (b); i < (n); i++)
#define all(v)  v.begin(), v.end()
#define FI  first
#define SE  second
#define rr(i,j,n,m) for(int i=0;i<n;i++) for(int j=0;j<m;j++)
#define NO  cout << "NO"
#define YES cout << "YES"
#define ex(n) return n;
typedef long long int lli;
typedef long long ll;
typedef double db;


























































































int gcd(int a,int b)
{
    return b?gcd(b,a%b):a;
}

struct resul
{
    int team;
    string name;
    int point=0;
    int per=0;
    int pereh=0;
    int pod=0;
};



















struct element                      
{
    int x;                            
    element *Next;                     
};
 
class List                         
{
    element *Head; 

    public:
    List() {Head = NULL;}             
    ~List();                           
    void Add(int x);                   
    void Show();     
    void Delete();
    void Sort(); 
};
 
List::~List()                       
{
    while (Head != NULL)            
    {
        element *temp = Head->Next; 
        delete Head;                
        Head = temp;               
    }
}

void List::Add(int x)               
{
    element *temp = new element;       
    temp->x = x;                        
    temp->Next = Head;                  
    Head = temp;                        
}
 
void List::Show()                   
{
    element *temp=Head;                
 
    while (temp != NULL)               
    {
        cout << temp->x << " ";          
        temp = temp->Next;              
    }
}
void List::Delete()
{
    int k;
    cin >> k;
    element *temp=Head;
    element *prev = 0;
    while (temp)
    {
        element *next = temp->Next;
        if (temp->x == k )
        {
            if (prev) prev->Next = next;
            delete temp;
        }
        else
        {
            prev = temp;
        }
        temp = next;
    }
}
void List::Sort()
{
    element *temp=Head;  
    while(temp->Next)
    {
        if(temp->x >temp->Next->x)
        {
            swap(temp->x,temp->Next->x);
            temp=temp->Next;
            Sort();
        }
        else
            temp=temp->Next;
    }
}




















int main()
{
    int n,maxi=0,temp=0;
    cin >> n;
    int **sum=new int *[n+1];
    for(int i=0;i<n+1;i++)
        sum[i]=new int [n+1];
    for(int i=0;i<n+1;i++)
        for(int j=0;j<n+1;j++)
            sum[i][j]=0;
    for(int i=1;i<=n;i++)
    {
        cin >> sum[1][i];
        if(maxi==0 && sum[1][i]>100)
            maxi=1;
        for(int j=2;j<=i;j++)
        {
            sum[j][i]=sum[j-1][i-1]+sum[1][i];
            if(sum[j][i]>100*j)
                maxi=max(maxi,j);
        }
    }
    cout << maxi;
}
