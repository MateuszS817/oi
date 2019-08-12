#include <bits/stdc++.h>
using namespace std;
int pot = 1;

void Push(int n, int wart, int pot, int *d1, int *d2) {
    if(n >= pot * 2) {
        return;
    }
    d2[n] = wart;
    if (n>=pot) {
        d1[n] = wart;
    } else {
        d1[n] = 0;
    }
    for(int i = n/2; i>0; i = i/2) {
        d1[i] = d1[2 * i]^d1[2 * i + 1];
    }
}

void Updt(int n, int a, int b, int lo, int hi, int wart, int pot, int *d1, int *d2) {
    if(b <= a) {
        return;
    }
    if(a == lo && b == hi) {
        //Push(n, wart, d);
        d2[n] = wart;
        if (n<pot) {
            d1[n] = 0;
        } else {
            d1[n] = wart;
        }
        //propagacja zmiany w górê
        for(int i = n/2; i>0; i = i/2) {
            d1[i] = d1[2 * i]^d1[2 * i + 1];
        }
        return;
    }
    int mid = (lo + hi) / 2;
    if (d2[n] != 0) {
        Push(n * 2, d2[n], pot, d1, d2);
        Push(n * 2 + 1, d2[n], pot, d1, d2);
        d2[n] = 0;
    }
    Updt(n * 2, a, min(mid, b), lo, mid, wart, pot, d1, d2);
    Updt(n * 2 + 1, max(a, mid), b, mid, hi, wart, pot, d1, d2);
    return;
}

int Get(int n, int a, int b, int lo, int hi, int x, int *d1, int *d2) {
    if(b <= a) {
        return 0;
    }
    if(x == 0) {
        x = d2[n];
    }
    if(a == lo && b == hi) {
        if(n < pot) {
            if (x != 0) return 0;
            return d1[n];
        }
        else {
            if(x == 0) {
                return d1[n];
            }
            else {
                return x;
            }
        }
    }
    int mid = (lo + hi) / 2;
    int r1 = Get(n * 2, a, min(mid, b), lo, mid, x, d1, d2);
    int r2 = Get(n * 2 + 1, max(a, mid), b, mid, hi, x, d1, d2);

    return(r1 ^ r2);
}


int main() {
    cin.tie(0);
    cout.tie(0);
    std::ios_base::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    while(pot < n) {
        pot *= 2;
    }
    int d1[pot * 2], d2[pot * 2];
    d1[0] = d2[0] = 0;
    for(int i = 0; i < n; i ++) {
        cin >> d1[i + pot];
    }
    for(int i = pot + n; i < 2 * pot; i++) d1[i] = 0;
    for(int i = pot - 1; i > 0; i --) {
        d1[i] = d1[i * 2] ^ d1[i * 2 + 1];
    }
    for(int i = 1; i < pot * 2; i ++) {
        d2[i] = 0;
    }
    for(int i = 0; i < q; i ++) {
        int war;
        cin >> war;
        if(war == 0) {
            int a, b, c;
            cin >> a >> b >> c;
            Updt(1, a - 1, b, 0, pot, c, pot, d1, d2);
        }
        if(war == 1) {
            int a, b;
            cin >> a >> b;
            cout << Get(1, a - 1, b, 0, pot, 0, d1, d2) << "\n";
        }
    }

//    for(int i=0; i<2*pot; i++){
//        cout << d1[i]<< " ";
//    }
//    cout <<"\n";
//    for(int i=0; i<2*pot; i++){
//        cout << d2[i]<< " ";
//    }
//    cout <<"\n";
//    d1[20] = d1[23] = d1[22] = d1[24] = d1[25] = 9;
//    d1[21] = 16;
//    for(int i = pot - 1; i > 0; i --) {
//        d1[i] = d1[i * 2] ^ d1[i * 2 + 1];
//    }
//
//    for(int i=0; i<2*pot; i++){
//        cout << d1[i]<< " ";
//    }
}
