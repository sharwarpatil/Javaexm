#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n, m; 
    cin >> n >> m;
    vector<pair<int,int>> o(n);
    for(int i = 0; i < n; i++) {
        cin >> o[i].first >> o[i].second;
    }
    vector<int> ft(m,0);
    vector<bool> isfree(m, true);
    for(int i = 0; i < n; i++) {
        int ot = o[i].first;
        int tt = o[i].second;

        for(int j = 0; j < m; j++) {
            if(ft[j] <= ot) {
                isfree[j] = true;
            } else {
                isfree[j] = false;
            }
        }


        int k = -1;
        for(int j = 0; j < m; j++) {
            if(isfree[j]) {
                k = j;
                break;
            }
        }

        if(k != -1) {
            ft[k] = ot + tt;
            isfree [k] = false;
             cout << " C " << (i + 1) << " - D " << k + 1 << "\n";
        } else {
             cout << "C" << (i + 1) << " - No Food " << "\n";
        }
    }
}