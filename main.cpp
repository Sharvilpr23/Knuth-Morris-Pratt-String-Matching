#include "includes.h"
#include "kmp.cpp"
#include "brute_force.cpp"

using namespace std;

int main()
{
    ifstream fin("input.txt");
    string p;
    string s( (istreambuf_iterator<char>(fin) ),
            (istreambuf_iterator<char>() ) );

    cout << "Enter string to find: ";
    cin >> p;

    if(optimized_kmp(s, p))
        cout << "Pattern found\n";
    else
        cout << "Pattern not found\n";
    return 0;
}