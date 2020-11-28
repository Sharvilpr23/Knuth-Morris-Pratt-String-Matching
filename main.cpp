#include "includes.h"
#include "kmp.cpp"
#include "brute_force.cpp"

using namespace std;

int main()
{
    string s = "aab"; 
    string p = "ab";

    if(optimized_kmp(s, p))
        cout << "Pattern found\n";
    else
        cout << "Pattern not found\n";
    return 0;
}