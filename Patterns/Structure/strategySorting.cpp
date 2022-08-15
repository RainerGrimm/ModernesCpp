// strategySorting.cpp

#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

void showMe(const std::vector<std::string>& myVec) {
    for (const auto& v: myVec) std::cout << v << " ";
    std::cout << "\n\n";
}


int main(){

    std::cout << '\n';

    // initializing with a initializer lists
    std::vector<std::string> myStrVec = {"Only", "for", "Testing", "Purpose", "!!!!!"};
    showMe(myStrVec);     // Only for Testing Purpose !!!!! 

    // lexicographic sorting
    std::sort(myStrVec.begin(), myStrVec.end());
    showMe(myStrVec);    // !!!!! Only Purpose Testing for 

    // case insensitive first character
    std::sort(myStrVec.begin(), myStrVec.end(), 
              [](const std::string& f, const std::string& s){ return std::tolower(f[0]) < std::tolower(s[0]); });
    showMe(myStrVec);   // !!!!! for Only Purpose Testing 

    // sorting ascending based on the length of the strings
    std::sort(myStrVec.begin(), myStrVec.end(), 
              [](const std::string& f, const std::string& s){ return f.length() < s.length(); });
    showMe(myStrVec);   // for Only !!!!! Purpose Testing 

    // reverse 
    std::sort(myStrVec.begin(), myStrVec.end(), std::greater<std::string>() );
    showMe(myStrVec);   // for Testing Purpose Only !!!!! 

    std::cout << "\n\n";

}