
#include <bits/stdc++.h>
using namespace std;
int inf = 2000000000;
vector <int> dobre[3];
void Dziel(int *x, int *y, int *z, int ile) {
    if(ile > 4) {
        vector <int> bracket[8];
        int minx = inf, maxx = -inf, miny = inf, maxy = -inf, minz = inf, maxz = -inf;
        for(int i = 0; i < ile; i ++) {
            minx = min(minx, x[i]);
            miny = min(miny, y[i]);
            minz = min(minz, z[i]);
            maxx = max(maxx, x[i]);
            maxy = max(maxy, y[i]);
            maxz = max(maxz, z[i]);
        }
        int a = (minx + maxx) / 2, b = (miny + maxy) / 2, c = (minz + maxz) / 2;
        for(int i = 0; i < ile; i ++) {
            int teraz = 0;
            if(x[i] > a) {
                teraz += 1;
            }
            if(y[i] > b) {
                teraz += 2;
            }
            if(z[i] > c) {
                teraz += 4;
            }
            bracket[teraz].push_back(i);
        }
        for(int i = 0; i < 8; i ++) {
            if(i == 7 && bracket[0].size() != 0) {
                break;
            }
            int xx[bracket[i].size()], yy[bracket[i].size()], zz[bracket[i].size()];
            for(int k = 0; k < bracket[i].size(); k ++) {
                xx[k] = x[bracket[i][k]];
                yy[k] = y[bracket[i][k]];
                zz[k] = z[bracket[i][k]];
            }
            Dziel(xx, yy, zz, bracket[i].size());
        }
    }
    else {
        for(int i = 0; i < ile; i ++) {
            bool war = true;
            for(int k = 0; k < ile; k ++) {
                if(x[i] < x[k] && y[i] < y[k] && z[i] < z[k]) {
                    war = false;
                    break;
                }
            }
            if(war) {
                dobre[0].push_back(x[i]);
                dobre[1].push_back(y[i]);
                dobre[2].push_back(z[i]);
            }
        }
    }
}

int main() {
    cin.tie(0);
    cout.tie(0);
    std::ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    int x[n], y[n], z[n];
    map <pair <int, pair <int, int> > , int> mapa;
    for(int i = 0; i < n; i ++) {
        cin >> x[i] >> y[i] >> z[i];
        pair <int, pair <int, int> > para;
        para.first = x[i];
        para.second.first = y[i];
        para.second.second = z[i];
        mapa[para] = i + 1;
    }
    Dziel(x, y, z, n);
    vector <int> wyjscie;
    for(int i = 0; i < dobre[0].size(); i ++) {
        //cout << dobre[0][i] << " " << dobre[1][i] << " " << dobre[2][i] << endl;
        pair <int, pair <int, int> > para;
        para.first = dobre[0][i];
        para.second.first = dobre[1][i];
        para.second.second = dobre[2][i];
        wyjscie.push_back(mapa[para]);
    }
    sort(wyjscie.begin(), wyjscie.end());
    cout << wyjscie.size() << "\n";
    for(int i = 0; i < wyjscie.size(); i ++) {
        cout << wyjscie[i] << " ";
    }
}
