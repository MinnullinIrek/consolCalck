#include "parser.h"
#include <iostream>

bool Parser::getResult(string &s, string& errormsg)
{
    deleteSymols(s, "[ ]");
    replace(s, ",", ".");

    if(!checkText(s, errormsg))
        return false;

    smatch result ;

    while(true){
        result = getBkt(s);
        if(result.size() == 0)
            break;

        string res = result[0];
        getResultBkt(res);

        replace(s, result[0], res);
    }

    getResultBkt(s);

    replace(s,"i", "-");
    size_t pos = s.find('.');
    if(std::string::npos != pos){
        if(s[pos+1] == '0' && s[pos+2] == '0')
            s.resize(pos);
        else if(s.size() > pos + 2)
            s.resize(pos+2);
    }
    return true;
}




smatch Parser::getBkt(string& text)
{
    smatch result;
    regex regular ("([(][^(^)]+[)])");
    regex_search(text, result, regular);

    return result;
}

double Parser::textToDouble(string num)
{
    string::size_type sz;
    return std::stod (num, &sz);
}

double Parser::calckBlock(double first, double second, char operation)
{
    double d = first;

    switch (operation){
    case '*':
        d *= second;
        break;
    case '/':
        d /= second;
        break;
    case '+':
        d += second;
        break;
    case '-':
        d -= second;
        break;
    default:
        break;
    }

    return d;
}

bool Parser::replace(std::string& str, const std::string& from, const std::string& to) {
    size_t start_pos = str.find(from);
    if(start_pos == std::string::npos)
        return false;
    str.replace(start_pos, from.length(), to);
    return true;
}

string Parser::doubleToString(double d) {
    string sres = std::to_string(d);

    replace(sres, "-", "i");
    return sres;
}

double Parser::getNumFromStr(string& text) {
    replace(text, "i", "-");
    smatch result;
    regex regular(numReg);
    regex_match(text, result, regular);
    string snum = result[0];
    return textToDouble(snum);
}

void Parser::oper(string &text, string reg) {
    deleteSymols(text, "[)()]");

    smatch result;
    regex regular ( reg.c_str());
    while(true) {
        if (regex_search(text, result, regular)){

            string num1 = result[1];
            string num2 = result[3];
            string operation = result[2];
            double first  = getNumFromStr(num1);
            double second = getNumFromStr(num2);

            double res = calckBlock(first, second, operation[0]);

            replace(text, result[0], doubleToString(res));
        }
        else
            break;
    }
}


void Parser::getResultBkt(string& textInBkt){
    oper(textInBkt, "(^[+-]?[^-+*/]+|[^-+*/]+)([*|/])([^-+*/]+)");
    oper(textInBkt, "(^[+-]?[^-+*/]+|[^-+*/]+)([+-])([^-+*/]+)");
    replace(textInBkt, "-", "i");
}

void Parser::deleteSymols(string &text, const string &reg){
    regex regular (reg);
    text = regex_replace (text, regular, "");
}

bool Parser::checkText(string &text, string &errormsg) {
    regex regular("[^-\\d+*\\/.)()]+|[-+*\\/]{2,}|[^-+*\\/][(]");
    smatch result;
    if(regex_search(text, result, regular)) {
        errormsg = "Некорректные ввод, строка содержит некорректный символ ";
        errormsg += result[0];
        return false;
    }
    return true;
}
