#ifndef POSFIXA_H
#define POSFIXA_H
#include<iostream>
#include<string>
#include<stack>

using namespace std;

class posfixa{

private :
  bool flag;
 string expressao(string m_palavra);

public:
    bool getflag();


    posfixa();


   string converte(std::string exp);

    bool confere(std::string result);

};

#endif // POSFIXA_H
