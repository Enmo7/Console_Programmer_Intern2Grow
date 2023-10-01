#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int countWords(const string& text) {
    stringstream ss(text);
    string word;
    int count = 0;
    while (ss >> word) {
        count++;
    }
    return count;
}

int countSentences(const string& text) {
    int count = 0;
    for (char c : text) {
        if (c == '.' || c == '?' || c == '!') {
            count++;
        }
    }
    return count;
}

int main() {
    string filename;
    cout << "Words Counter\n";
    cout << "Enter the filename: ";
    cin >> filename;

    ifstream file(filename);
    if (!file) {
        cout << "Error opening file\n";
        return 1;
    }

    stringstream buffer;
    buffer << file.rdbuf();
    string content = buffer.str();

    int numChars = content.size();
    int numWords = countWords(content);
    int numSentences = countSentences(content);

    cout << "Number of characters: " << numChars << endl;
    cout << "Number of words: " << numWords << endl;
    cout << "Number of sentences: " << numSentences << endl;

    return 0;
}
