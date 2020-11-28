#include "includes.h"

using namespace std;

bool kmp_brute_force(string s, string p)
{
    int match = 0;
    int i = 0;
    int j = 0;
    int k = 0;

    while(match != p.length() && (i + p.length()) <= s.length())
    {
        j = i;
        k = 0;  
        match = 0;
         
        while(k < p.length() && s[j] == p[k])
        {
            match += 1;
            j += 1;
            k += 1;
        }

        if(match == p.length())
            return true;

        i += 1;
    }
    return false;
}