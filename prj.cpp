#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    using namespace std;

    vector<string> words;
    for (string temp; cin>>temp;)
        words.push_back(temp);
    cout << "Number of words: " << words.size() << endl;

    sort(words.begin(), words.end());

    for (int i=0; i<words.size(); ++i)
        if (i==0 || words[i-1]!=words[i])
            cout << words[i] << endl;
    
    return 0;
}