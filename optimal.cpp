#include <iostream>
#include <vector>
#include <queue>
#include <array>     
#include <algorithm> 

using namespace std;

struct cmpBusy {
    bool operator()(const array<int, 2> &a, const array<int, 2> &b) const {
        if (a[0] != b[0]) return a[0] > b[0];
        return a[1] > b[1];
    }
};

int main() {
    int N, M;
    cin >> N >> M;

    vector<array<int, 2>> o(N);
    for (int i = 0; i < N; i++) {
        cin >> o[i][0] >> o[i][1];
    }


    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= M; i++) {
        pq.push(i);
    }

    priority_queue<array<int, 2>, vector<array<int, 2>>, cmpBusy> busyDriv;

    for (int i = 0; i < N; i++) {
        int ot = o[i][0]; 
        int tt = o[i][1]; 

     
        while (!busyDriv.empty() && busyDriv.top()[0] <= ot) {
            auto freed = busyDriv.top();
            busyDriv.pop();
            pq.push(freed[1]);
        }

        if (!pq.empty()) {
            int k = pq.top();
            pq.pop();
            cout << "C" << (i + 1) << " - D" << k << "\n";
            busyDriv.push({ot + tt, k});
        } else {
            cout << "C" << (i + 1) << " - No Food :-(" << "\n";
        }
    }

    return 0;
}
