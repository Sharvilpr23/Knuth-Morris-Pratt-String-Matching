#include "includes.h"
#include "kmp.cpp"
#include "brute_force.cpp"

using namespace std;

int main()
{
    string s = "aaaaaaaaaaaab"; 
    string p = "aaab";

    if(optimized_kmp(s, p))
        cout << "Pattern found\n";
    else
        cout << "Pattern not found\n";
    return 0;
}