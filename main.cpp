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
    
    cout << "Time Elapsed: \n";
    cout << "Brute: " << chrono::duration_cast<chrono::microseconds>(brute_end-brute_start).count() << " ms" << endl;
    cout << "KMP: " << chrono::duration_cast<chrono::microseconds>(kmp_end-kmp_start).count() << " ms" << endl;
    return 0;
}
