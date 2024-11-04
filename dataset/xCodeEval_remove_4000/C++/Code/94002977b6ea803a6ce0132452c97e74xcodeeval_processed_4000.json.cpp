




using namespace std;

int main() {
    int n, k;
    cin>>n>>k;
    vector<int> *vec = new vector<int>[k];
    vector<pair<double, int> > id1;
    vector<pair<double, int> > id0;
    double sum = 0;
    long long pencils = 0;
    long long stools = 0;
    for(int i=1; i<=n; i++) {
        double p;
        int  t;
        cin>>p>>t;
        if(t==1) {
            stools++;
            id0.push_back(make_pair(p,i));
        }
        else {
            pencils++;
            id1.push_back(make_pair(p,i));
        }
    }
    sort(id0.rbegin(), id0.rend());
    double c = 1e9;
    if(stools>=k) {
        for(int i=0; i<k-1; i++) {

            sum+=(id0[i].first*0.5);
            vec[i].push_back(id0[i].second);
        }
        for(int i=k-1; i<stools; i++) {
            if(id0[i].first<c) c=id0[i].first;
            

            sum+=(id0[i].first);
            vec[k-1].push_back(id0[i].second);
        }
        for(int i=0; i<pencils; i++) {
            if(id1[i].first<c) c=id1[i].first;
            

            sum+=(id1[i].first);
            vec[k-1].push_back(id1[i].second);
        }
        sum-=(c*0.5);
    }
    else {
        for(int i=0; i<stools; i++) {

            sum+=(id0[i].first*0.5);
            vec[i].push_back(id0[i].second);
        }
        int j=0;
        for(int i=stools; i<k; i++) {
            sum+=id1[j].first;
            vec[i].push_back(id1[j].second);
            j++;
        }
        for(int i=j; i<id1.size(); i++) {
            sum+=id1[i].first;
            vec[k-1].push_back(id1[i].second);
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
















































































































































































































































