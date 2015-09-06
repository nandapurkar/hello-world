#include <iostream>
#include <string>
using namespace std;

int num_pals_exact(string str, int length)
{
    if (length == 0) { return 1; }
    if (length == 1) { return str.length(); }
    int answr = str.length() * num_pals_exact(str, length-2);
    return answr;
}

int num_pals_total(string str, int maxlength)
{
    int currtotal = 0;
    for (int i=0; i<=maxlength; i++) { 
        currtotal = currtotal + num_pals_exact(str, i);
    }
    return currtotal;
}

int gen_pals2(string outpals[], string str, int maxlength, int startpoint, int endpoint) 
{
    int strlength = str.length();
    if (startpoint > endpoint) { return 0; }  // this means no new palindrones were added, so stop and return the outpals array
    else if  (endpoint == 0) { 
        outpals[0] = ""; // if startpoint = 0 push in the null string
        endpoint = -1;  // this will cause the process to stop if no other palindrones are added
        if (maxlength > 0) { // if maxlength was = 0, then need to stop here, else 
            for (int i=0; i<strlength; i++) { outpals[i+1] = str[i]; }  // also push in each of the characters as a single character
            endpoint = strlength; // this will make the endpoint the last character added with startpoint being the null string
        }
    }
    else {
        int numpalsadded = 0; // keep track of how many added on this pass
        for (int i=startpoint; i<=endpoint; i++) { // loop through each of the palindrones added on the last pass
            for (int j=0; j<strlength; j++) {  // loop through each of the original characters
                string testpali = str[j]+outpals[i]+str[j];  // to create a new palindrone, add each character to both sides of each existing palindrone
                if (testpali.length()+1 <= maxlength+1) { // only use palindromes that are less than or equal to the max length
                    numpalsadded++;  // increment the # of pals added counter
                    outpals[endpoint+numpalsadded] = testpali;  // this is the next slot in the array.  place the found palindrone here.
                }
            }
        }
        startpoint = endpoint+1;  // next pass through, start at the first one found on this pass
        endpoint = endpoint+numpalsadded; // next time through, end on the last one found on this pass
    } 
  // do the recursion using the new start and end points
    return gen_pals2(outpals, str, maxlength, startpoint, endpoint); 
}

int gen_pals(char inpstr[], int maxlength)
{
    string str(inpstr);
    int num = num_pals_total(str, maxlength);
    string outpals [num];
    int dummy = gen_pals2(outpals, str, maxlength, 0, 0);
    for (int i=0; i<num; i++) 
    { 
        cout << "\n"; 
        cout << outpals[i]; 
    }
    return 0;
}

int main ()
{
    char inpstr[] = "abc"; // {"a","b","c","\0"};
    string str(inpstr);
    int maxlength = 4;
//    int answr1 = num_pals_exact(str, maxlength);
//    cout << answr1;
//    cout << "\n";
    cout << "Total # = ";
    int answr2 = num_pals_total(str, maxlength);
    cout << answr2;
    cout << "\n"; 
    int dummy = gen_pals(inpstr, maxlength);
    return 0;
}