#include <bits/stdc++.h>
#include <regex>

using namespace std;

int maxLen(string s){
    string unique = "";
    
    for (int i = 0; i < s.size(); i++) {
        if (unique.find(s.at(i)) == string::npos) {
            unique += s.at(i);
        }
    }
    
    cout << unique << endl;
    
    string _s;
    regex e("(.)(?!\1)(.)(\1\2)*(\1)?");
    int maxLenghtSoFar = 0;
    
    for (int i = 0; i < unique.size(); i++) {
        for (int j = i + 1; j < unique.size(); j++) {
            
            
            string values = "";
                   values += unique.at(i);
                   values += unique.at(j);
            regex regex("[^" + values + "]");
            _s = regex_replace(s, regex, "");
                        
            auto words_begin = 
                std::sregex_iterator(s.begin(), s.end(), e);
            auto words_end = std::sregex_iterator();

            std::cout << "Found " 
                      << std::distance(words_begin, words_end) 
                      << " words:\n";

            for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
                std::smatch match = *i;                                                 
                std::string match_str = match.str(); 
                std::cout << match_str << '\n';
            }   
            
            cout << endl;
        }
    }
    
    return maxLenghtSoFar;
}

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int result = maxLen(s);
    cout << result << endl;
    return 0;
}
