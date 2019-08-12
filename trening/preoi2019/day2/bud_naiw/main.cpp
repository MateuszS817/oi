#include <bits/stdc++.h>
using namespace std;
int pot = 1;

void Push(int n, int wart, int *d) {
    if(n >= pot * 2) {
        return;
    }
    d[n] = wart;
//    if(d[n] == 0) {
//        d[n] = wart;
//        return;
//    }
//    else {
//        Push(n * 2, d[n], d);
//        Push(n * 2 + 1, d[n], d);
//        d[n] = wart;
//        return;
//    }
}

void Updt(int a, int b, int val, int *d) {
    for(int i = a; i <= b; i++) {
        d[i] = val;
    }
}

int Get(int a, int b, int *d) {
    int res = 0;

    for(int i = a; i <= b; i++){
        res ^= d[i];
    }
    return res;
}


int main() {
    cin.tie(0);
    cout.tie(0);
    std::ios_base::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    int d1[n+1];

    for(int i = 1; i <= n; i ++) {
        cin >> d1[i];
    }

    for(int i = 0; i < q; i ++) {
        int war;
        cin >> war;
        if(war == 0) {
            int a, b, c;
            cin >> a >> b >> c;
            Updt(a , b, c, d1);
        }
        if(war == 1) {
            int a, b;
            cin >> a >> b;
            cout << Get(a, b, d1) << "\n";
        }
    }
}
