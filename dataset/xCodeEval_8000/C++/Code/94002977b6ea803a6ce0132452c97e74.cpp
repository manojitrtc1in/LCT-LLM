#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cstdio>
using namespace std;

int main() {
    int n, k;
    cin>>n>>k;
    vector<int> *vec = new vector<int>[k];
    vector<pair<double, int> > pencilList;
    vector<pair<double, int> > stoolList;
    double sum = 0;
    long long pencils = 0;
    long long stools = 0;
    for(int i=1; i<=n; i++) {
        double p;
        int  t;
        cin>>p>>t;
        if(t==1) {
            stools++;
            stoolList.push_back(make_pair(p,i));
        }
        else {
            pencils++;
            pencilList.push_back(make_pair(p,i));
        }
    }
    sort(stoolList.rbegin(), stoolList.rend());
    double c = 1e9;
    if(stools>=k) {
        for(int i=0; i<k-1; i++) {

            sum+=(stoolList[i].first*0.5);
            vec[i].push_back(stoolList[i].second);
        }
        for(int i=k-1; i<stools; i++) {
            if(stoolList[i].first<c) c=stoolList[i].first;
            

            sum+=(stoolList[i].first);
            vec[k-1].push_back(stoolList[i].second);
        }
        for(int i=0; i<pencils; i++) {
            if(pencilList[i].first<c) c=pencilList[i].first;
            

            sum+=(pencilList[i].first);
            vec[k-1].push_back(pencilList[i].second);
        }
        sum-=(c*0.5);
    }
    else {
        for(int i=0; i<stools; i++) {

            sum+=(stoolList[i].first*0.5);
            vec[i].push_back(stoolList[i].second);
        }
        int j=0;
        for(int i=stools; i<k; i++) {
            sum+=pencilList[j].first;
            vec[i].push_back(pencilList[j].second);
            j++;
        }
        for(int i=j; i<pencilList.size(); i++) {
            sum+=pencilList[i].first;
            vec[k-1].push_back(pencilList[i].second);
        }
    }
    printf("%.1f\n", sum);
    for(int i=0; i<k; i++) {
        cout<<vec[i].size();
        for(vector<int>::iterator it = vec[i].begin(); it!=vec[i].end(); it++) {
            cout<<" "<<*it;
        }
        cout<<endl;
    }
    return 0;
}
















































































































































































































































