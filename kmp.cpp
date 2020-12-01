#include "includes.h"

using namespace std; 

vector<int> find_prefix_suffix(string p) {
    vector<int> prefix_suffix_table(p.size());
    int j = 0;

    for (int i = 1; i < (int)p.size(); i++) 
    {
        while (j > 0 && p[j] != p[i]) {
            j = prefix_suffix_table[j - 1];
        }

        if (p[j] == p[i])
            j++;

        prefix_suffix_table[i] = j;
    }   
    return prefix_suffix_table;
}

bool kmp(string s, string p)
{
    int i = 0;
    int j = 0;

    int n = s.length();
    int m = p.length();

    // Every string contains an empty string
    if (m == 0)
        return true;

    vector<int> prefix_suffix_table = find_prefix_suffix(p);

    for(int i = 0; i < n; i++)
    {   
        if(s[i] == p[j])
        {
            j += 1;
        }
        else if (j > 0)
        {
            j = prefix_suffix_table[j -1];
            i -= 1;
        }

        if(j == m)
            return true;
    }
    return false;
}
