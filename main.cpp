#include "includes.h"
#include "kmp.cpp"
#include "brute_force.cpp"
#include <chrono>

using namespace std;

int main()
{
    ifstream fin("input.txt");
    string p;
    string s( (istreambuf_iterator<char>(fin) ),
            (istreambuf_iterator<char>() ) );

    cout << "Enter string to find: ";
    cin >> p;
    chrono::steady_clock::time_point brute_start = chrono::steady_clock::now();
    bool brute_found = brute_force(s, p);
    chrono::steady_clock::time_point brute_end = chrono::steady_clock::now();
    chrono::steady_clock::time_point kmp_start = chrono::steady_clock::now();
    bool kmp_found = kmp(s, p);
    chrono::steady_clock::time_point kmp_end = chrono::steady_clock::now();
    if(brute_found && kmp_found) cout << "Pattern Found!" << endl;
    else cout << "Pattern not found." << endl;   
    cout << "Time Elapsed: \n";
    cout << "Brute: " << chrono::duration_cast<chrono::microseconds>(brute_end-brute_start).count() << " µs" << endl;
    cout << "KMP: " << chrono::duration_cast<chrono::microseconds>(kmp_end-kmp_start).count() << " µs" << endl;
    return 0;
}
