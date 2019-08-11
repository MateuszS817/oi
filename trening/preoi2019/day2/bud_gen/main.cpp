#include <iostream>
#include <fstream>
#include <cmath>
#include <set>
#include <cstdlib>

using namespace std;

void gen(int szczyt, int lprob, int nrplik) {
    ofstream myfile;
    char nrp[250];
    sprintf(nrp, "%d", nrplik);

    string fname = "in\\bud_"+std::string(nrp)+".in";
    myfile.open (fname);

    myfile << szczyt << " " << lprob << endl;

    for(int i=0; i<szczyt; i++) myfile << (int) rand()%(5*szczyt) << " ";
    myfile << "\n";

    for(int i=0; i<lprob; i++) {
        myfile << 1 << " ";

        int a = 1 + rand() % szczyt;
        int b = 1 + rand() % szczyt;
        myfile <<  min(a,b) << " " << max(a, b) << "\n";

        myfile << 0 << " ";
        a = 1 + rand() % szczyt;
        b = 1 + rand() % szczyt;
        int val = rand() % (5*szczyt);
        myfile <<  min(a,b) << " " << max(a, b) << " " << val << "\n";
    }

    myfile.close();
}

int main()
{
    int fc = 0;
    for(int i=1; i<=3; i++) {
        for(int k=0; k<100; k++)
            gen(i*5, i*3, fc++);
    }
}
