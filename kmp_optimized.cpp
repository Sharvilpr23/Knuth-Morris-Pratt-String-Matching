#include <iostream>
#include <vector>
#include <string>

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

bool optimized_kmp(string s, string p)
{
    int i = 0;
    int j = 0;

    int n = s.length();
    int m = p.length();

    vector<int> prefix_suffix_table = find_prefix_suffix(p);
    
    for(int i = 0; i < prefix_suffix_table.size(); i++)
    {
        cout << prefix_suffix_table[i] << " ";
    }
    cout << endl;

    for(int i = 0; i < n; i++)
    {
        cout << "( " << i << ", " << j  << " )" << endl;
        
        if(s[i] == p[j])
        {
            j += 1;
        }
        else if (j > 0)
        {
            j = prefix_suffix_table[j];
            i -= 1;
        }

        if(j == m)
            return true;
    }
    return false;
}

int main()
{
    string s; 
    string p;

    if(optimized_kmp(s, p))
        cout << "Pattern found\n";
    else
        cout << "Pattern not found\n";
    return 0;
}
