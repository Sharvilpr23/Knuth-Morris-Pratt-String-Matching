#define CATCH_CONFIG_MAIN 
#include "catch.hpp"
#include <vector>
#include <string>
#include "kmp.cpp"
#include "brute_force.cpp"

const string loremIpsum = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do "
    "eiusmod tempor incididunt ut labore et dolore magna aliqua. Orci nulla pellentesque"
    " dignissim enim sit amet. At quis risus sed vulputate odio ut. Morbi tincidunt ornare"
    " massa eget egestas purus viverra accumsan in. Ipsum a arcu cursus vitae congue mauris."
    " Fermentum leo vel orci porta non pulvinar neque. Volutpat commodo sed egestas egestas."
    " Aliquam nulla facilisi cras fermentum odio eu. Pellentesque nec nam aliquam sem et "
    "tortor consequat id porta. Blandit aliquam etiam erat velit. Nisl pretium fusce id velit"
    " ut tortor pretium. Aliquam sem et tortor consequat id porta.\n"
    "Eget arcu dictum varius duis at consectetur. Volutpat sed cras ornare arcu dui vivamus"
    " arcu felis. Aenean euismod elementum nisi quis eleifend quam adipiscing. Nisl rhoncus "
    "mattis rhoncus urna neque viverra. Et netus et malesuada fames ac. Id eu nisl nunc mi ipsum."
    " Magna eget est lorem ipsum dolor sit amet. Tellus in metus vulputate eu scelerisque felis"
    " imperdiet. Rutrum tellus pellentesque eu tincidunt tortor aliquam. Sagittis eu volutpat"
    " odio facilisis mauris sit. Pulvinar neque laoreet suspendisse interdum. Donec et odio"
    " pellentesque diam.\n"
    "Dignissim cras tincidunt lobortis feugiat vivamus at augue eget. Sem fringilla ut morbi"
    " tincidunt augue interdum. Vitae sapien pellentesque habitant morbi tristique senectus."
    " Pharetra diam sit amet nisl. In metus vulputate eu scelerisque felis imperdiet. Cras"
    " semper auctor neque vitae tempus. Velit euismod in pellentesque massa placerat duis"
    " ultricies lacus. Neque viverra justo nec ultrices dui sapien eget mi proin. Ornare"
    " lectus sit amet est placerat in egestas erat. Nulla facilisi nullam vehicula ipsum"
    " a arcu cursus vitae congue. Urna et pharetra pharetra massa massa ultricies mi quis.\n"
    "Nunc scelerisque viverra mauris in aliquam sem fringilla ut morbi. Tellus molestie "
    "nunc non blandit massa enim nec. Lobortis scelerisque fermentum dui faucibus in ornare"
    " quam viverra. Donec pretium vulputate sapien nec sagittis aliquam malesuada bibendum."
    " Sodales neque sodales ut etiam sit. Sed pulvinar proin gravida hendrerit lectus. Non"
    " sodales neque sodales ut etiam sit amet nisl. Amet consectetur adipiscing elit ut aliquam"
    " purus sit. Leo urna molestie at elementum eu facilisis sed odio morbi. Orci sagittis eu"
    " volutpat odio facilisis mauris sit amet.\n"
    "Convallis posuere morbi leo urna molestie at elementum eu. Justo laoreet sit amet cursus"
    " sit amet dictum sit amet. Tellus in metus vulputate eu scelerisque. Sagittis vitae et"
    " leo duis ut diam quam nulla. Quis risus sed vulputate odio ut enim blandit. Sapien et"
    " ligula ullamcorper malesuada. Augue lacus viverra vitae congue eu. Enim diam vulputate"
    " ut pharetra sit amet aliquam. Consectetur lorem donec massa sapien faucibus et molestie"
    " ac. Posuere morbi leo urna molestie at elementum. Ultrices dui sapien eget mi proin. "
    "Nunc lobortis mattis aliquam faucibus purus in massa. Eget mi proin sed libero enim sed."
    " Auctor urna nunc id cursus. Scelerisque varius morbi enim nunc. Euismod elementum nisi "
    "quis eleifend quam.\n"
    "Urna et pharetra pharetra massa massa ultricies mi quis. Molestie at elementum eu "
    "facilisis sed odio morbi quis commodo. Varius morbi enim nunc faucibus a pellentesque sit"
    " amet. Morbi quis commodo odio aenean sed adipiscing diam. Senectus et netus et malesuada"
    " fames ac. Tincidunt eget nullam non nisi est sit amet facilisis. Nullam non nisi est sit"
    " amet facilisis magna etiam. Fames ac turpis egestas sed. Vestibulum sed arcu non odio"
    " euismod. Dui faucibus in ornare quam viverra orci.\n"
    "Massa tempor nec feugiat nisl pretium. Quam quisque id diam vel quam. Eu tincidunt tortor "
    "aliquam nulla facilisi cras. Lacus suspendisse faucibus interdum posuere. Massa id neque "
    "aliquam vestibulum morbi. Interdum consectetur libero id faucibus nisl tincidunt eget. "
    "Ipsum suspendisse ultrices gravida dictum fusce ut placerat orci. Massa sapien faucibus "
    "et molestie ac. Augue mauris augue neque gravida in fermentum et. Dui faucibus in ornare "
    "quam viverra orci. Turpis nunc eget lorem dolor sed viverra ipsum nunc aliquet. Luctus "
    "accumsan tortor posuere ac ut consequat semper viverra. Mi bibendum neque egestas "
    "congue quisque egestas. Vitae suscipit tellus mauris a diam maecenas sed enim ut.\n"
    "Tempor orci dapibus ultrices in iaculis nunc sed augue lacus. Blandit libero volutpat"
    " sed cras ornare arcu dui vivamus arcu. Sapien pellentesque habitant morbi tristique "
    "senectus et netus. Tempus quam pellentesque nec nam aliquam sem et tortor. Vehicula "
    "ipsum a arcu cursus. Id volutpat lacus laoreet non curabitur gravida. Dui accumsan "
    "sit amet nulla facilisi morbi tempus iaculis urna. Adipiscing elit duis tristique "
    "sollicitudin. Ornare arcu odio ut sem nulla pharetra. Interdum consectetur libero "
    "id faucibus nisl tincidunt eget. Magna ac placerat vestibulum lectus mauris ultrices "
    "eros in cursus. Diam sit amet nisl suscipit adipiscing bibendum est ultricies "
    "integer. Ornare lectus sit amet est placerat in egestas. Felis donec et odio "
    "pellentesque diam volutpat commodo. Sed risus pretium quam vulputate dignissim "
    "suspendisse. Integer malesuada nunc vel risus commodo viverra maecenas accumsan lacus.\n";

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
    REQUIRE(kmp(s, p) == true);
}

TEST_CASE("Test 2: Empty pattern string")
{
    string s = "a";
    string p = "";
    REQUIRE(kmp(s, p) == true);
}

TEST_CASE("Test 3: Empty original string")
{
    string s = "";
    string p = "a";
    REQUIRE(kmp(s, p) == false);
}

TEST_CASE("Test 4: 1 character strings (match)")
{
    string s = "a";
    string p = "a";
    REQUIRE(kmp(s, p) == true);
}

TEST_CASE("Test 5: 1 character strings (mismatch)")
{
    string s = "a";
    string p = "b";
    REQUIRE(kmp(s, p) == false);
}

TEST_CASE("Test 6: match")
{
    string s = "aaaab";
    string p = "aab";
    REQUIRE(kmp(s, p) == true);
}

TEST_CASE("Test 7: Festive (Match)")
{
    string s = "All I want for christmas is youuuuuuu, baby";
    string p = "christmas";
    REQUIRE(kmp(s, p) == true);
}

TEST_CASE("Test 8: Partial Word Match (Match)")
{
    string s = "All I want for christmas is youuuuuuu, baby";
    string p = "youuuu";
    REQUIRE(kmp(s, p) == true);
}

TEST_CASE("Test 9: Big Text, Full Match (Match)")
{
    string s = loremIpsum;
    string p = "Dignissim cras tincidunt lobortis feugiat vivamus at augue eget. Sem fringilla ut morbi"
        " tincidunt augue interdum. Vitae sapien pellentesque habitant morbi tristique senectus."
        " Pharetra diam sit amet nisl. In metus vulputate eu scelerisque felis imperdiet. Cras"
        " semper auctor neque vitae tempus. Velit euismod in pellentesque massa placerat duis"
        " ultricies lacus. Neque viverra justo nec ultrices dui sapien eget mi proin. Ornare"
        " lectus sit amet est placerat in egestas erat. Nulla facilisi nullam vehicula ipsum"
        " a arcu cursus vitae congue. Urna et pharetra pharetra massa massa ultricies mi quis.\n";
    REQUIRE(kmp(s, p) == true);
}

TEST_CASE("Test 10: Big Text, One Character Mismatch (Mismatch)")
{
    string s = loremIpsum;
    string p = "Dignissim cras tincidunt lobortis feugiat vivamus at augue eget. Sem fringilla ut morbi"
        " tincidunt augue interdum. Vitae sapien pellentesque habitant morbi tristique senectus."
        " Pharetra diam sit amet nisl. In metus vulputate eu scelerisque felis imperdiet. Cras"
        " semper auctor neque vitae tempus. Velait euismod in pellentesque massa placerat duis"
        " ultricies lacus. Neque viverra justo nec ultrices dui sapien eget mi proin. Ornare"
        " lectus sit amet est placerat in egestas erat. Nulla facilisi nullam vehicula ipsum"
        " a arcu cursus vitae congue. Urna et pharetra pharetra massa massa ultricies mi quis.\n";
    REQUIRE(kmp(s, p) == false);
}

TEST_CASE("Test 11: Big Text, Empty Case (Mismatch)")
{
    string s = loremIpsum;
    string p = "";
    REQUIRE(kmp(s, p) == true);
}

TEST_CASE("Test 12: Big Text, Full Match (Match)")
{
    string s = loremIpsum;
    string p = loremIpsum;
    REQUIRE(kmp(s, p) == true);
}

TEST_CASE("Test 13: match")
{
    string s = "aab"; 
    string p = "ab";
    REQUIRE(kmp(s, p) == true);
}
