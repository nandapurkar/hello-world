// Example program
#include <iostream>
#include <string>
#include <stdlib.h>    
using namespace std;

int calc_modfact(int numbig, int numsmall)
{
    if (numbig == 0) { return 1; }
    else if (numbig == numsmall) { return numbig; }
    else { return numbig * calc_modfact(numbig-1,numsmall); }
}

int permutations(int totnum, int picknum)
{
    return calc_modfact(totnum, totnum-picknum+1);
}

int combinations(int totnum, int picknum)
{
    return permutations(totnum, picknum) / calc_modfact(picknum, 1);
}



int main()
{
    string name;
    
    cout << "How many items total? ";
    getline (cin, name);
    int numtot = atoi(name.c_str()); 

    cout << "How many get picked? ";
    getline (cin, name);
    int numpick = atoi(name.c_str()); 

    int perms = permutations(numtot, numpick);
    int combi = combinations(numtot, numpick);

    cout << "Permutations: " << perms << "\n";
    cout << "Combinations: " << combi << "\n";

}
