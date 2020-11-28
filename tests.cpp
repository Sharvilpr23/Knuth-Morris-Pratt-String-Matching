#define CATCH_CONFIG_MAIN 
#include "catch.hpp"
#include <vector>
#include <string>
#include "kmp.cpp"
#include "brute_force.cpp"

TEST_CASE("Empty Prefix-Suffix Table")
{
    string p;
    vector<int> v = find_prefix_suffix(p); 
    REQUIRE(v.empty() == true);
}

TEST_CASE("Basic Prefix-Suffix Table (all zeros)")
{
    string p = "abc";
    vector<int> v = find_prefix_suffix(p); 
    REQUIRE(v.size() == p.size());
    bool zeros = all_of(v.begin(), v.end(), [](int i) { return i==0; });
    REQUIRE(zeros == true);
}

TEST_CASE("Basic Prefix-Suffix Table (all non-zeros)")
{
    string p = "abcdabdabc";
    vector<int> v = find_prefix_suffix(p); 
    REQUIRE(v.size() == p.size());
    bool zeros = all_of(v.begin(), v.end(), [](int i) { return i==0; });
    REQUIRE(zeros == false);
}

TEST_CASE("Test 1: Empty String (Both)")
{
    string s = "";
    string p = "";
    REQUIRE(optimized_kmp(s, p) == true);
}

TEST_CASE("Test 2: Empty pattern string")
{
    string s = "a";
    string p = "";
    REQUIRE(optimized_kmp(s, p) == true);
}

TEST_CASE("Test 3: Empty original string")
{
    string s = "";
    string p = "a";
    REQUIRE(optimized_kmp(s, p) == false);
}

TEST_CASE("Test 4: 1 character strings (match)")
{
    string s = "a";
    string p = "a";
    REQUIRE(optimized_kmp(s, p) == true);
}

TEST_CASE("Test 5: 1 character strings (mismatch)")
{
    string s = "a";
    string p = "b";
    REQUIRE(optimized_kmp(s, p) == false);
}

TEST_CASE("Test 6: match")
{
    string s = "aaaab";
    string p = "aab";
    REQUIRE(optimized_kmp(s, p) == true);
}