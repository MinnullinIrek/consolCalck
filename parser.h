#ifndef PARSER_H
#define PARSER_H


#include <regex>
#include <string>

using namespace std;
class Parser
{
public:
    bool getResult(string &s, string& errormsg);

private:
    string numReg = "[-]?\\d+[.,]\\d+|[-]?(\\d+)*";

    smatch getBkt(string& text);

    double textToDouble(string num);

    double calckBlock(double first, double second, char operation);

    bool replace(std::string& str, const std::string& from, const std::string& to);

    string doubleToString(double d);

    double getNumFromStr(string& text);

    void oper(string &text, string reg);

    void getResultBkt(string& textInBkt);

    void deleteSymols(string &text, const string &reg);

    bool checkText(string &text, string &wrongText);
};


#endif // PARSER_H
