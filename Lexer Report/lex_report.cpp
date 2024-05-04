#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Function to check if a character is a letter
bool isLetter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

// Function to check if a character is a digit
bool isDigit(char c) {
    return (c >= '0' && c <= '9');
}

// Function to check if a string is a C++ keyword
bool isKeyword(const string& word) {
    static const string keywords[] = {"int", "float", "char", "if", "else", "while", "for", "return", "include", "namespace", "using", "cout", "cin", "endl"};
    for (const string& keyword : keywords) {
        if (word == keyword)
            return true;
    }
    return false;
}

// Function to check if a string is a valid variable name
bool isVariable(const string& word) {


        bool flag = true;

    if (!((word[0] >= 'a' && word[0] <= 'z') || (word[0] >= 'A' && word[0] <= 'Z') || (word[0] == '_')))
    {
        flag = false;
    }
    else
    {

        for (int i = 1; i < word.size(); i++)
        {
            if (!((word[i] >= 'a' && word[i] <= 'z') || (word[i] >= 'A' && word[i] <= 'Z') || (word[i] == '_') || (word[i] >= '0' && word[i] <= '9')))
            {
                flag = false;
                break;
            }
        }
    }
}

// Function to check if a string is a constant
bool isConstant(const string& word) {
    // A constant can be a sequence of digits
    for (char c : word) {
        if (!isDigit(c))
            return false;
    }
    return true;
}

// Function to check if a string is an operator
bool isOperator(const string& word) {
    static const string operators[] = {"+", "-", "*", "/", "%", "=", "==", "!=", ">", "<", ">=", "<=", "&&", "||", "!", "&", "|", "^", "~", "<<", ">>", "+=", "-=", "*=", "/=", "%=", "<<=", ">>=", "&=", "|=", "^=", "++", "--"};
    for (const string& op : operators) {
        if (word == op)
            return true;
    }
    return false;
}

// Function to check if a string is an identifier
bool isIdentifier(const string& word) {
    // Identifiers include function names, variable names, class names, namespace names, struct names
    return !isKeyword(word) && !isConstant(word) && !isVariable(word);
}

// Function to report lexer information
void lexerReport(const string& word) {
    if (isKeyword(word))
        cout << word << " is a keyword." << endl;
    else if (isVariable(word))
        cout << word << " is a variable name." << endl;
    else if (isConstant(word))
        cout << word << " is a constant." << endl;
    else if (isOperator(word))
        cout << word << " is an operator." << endl;
    else if (word == ";" || word == "," || word == "." || word == "(" || word == ")" || word == "{" || word == "}" || word == "[" || word == "]")
        cout << word << " is a punctuation." << endl;
    else if (isIdentifier(word))
        cout << word << " is an identifier." << endl;
    else
        cout << word << " is unrecognized." << endl;
}

int main() {
    ifstream file("lex_input.txt");
    if (!file.is_open()) {
        cout << "Failed to open the file." << endl;
        return 1;
    }

    string word;
    while (file >> word) {
        lexerReport(word);
    }

    file.close();

    return 0;
}
