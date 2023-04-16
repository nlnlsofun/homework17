#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    string input;
    getline(cin, input);

 
    transform(input.begin(), input.end(), input.begin(), ::tolower);

    vector<string> words;
    istringstream iss(input);
    string word;

  
    while (iss >> word) {
        words.push_back(word);
    }

 
    sort(words.begin(), words.end(), [input](const string& a, const string& b) {
        return input.find(a) < input.find(b);
        });


    words.erase(unique(words.begin(), words.end()), words.end());

 
    for (const auto& w : words) {
        cout << w << " ";
    }
    cout << endl;

    return 0;
}

