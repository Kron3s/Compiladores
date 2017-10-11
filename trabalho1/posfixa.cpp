#include "posfixa.h"
 using namespace std;
posfixa::posfixa()
{
   flag = true;
}

bool posfixa::getflag(){
    return flag;
}


string posfixa::expressao(string m_palavra){ // função para coloca o simbolo '.' de concatenação caso nao exista
int i = 0;
    while(i < m_palavra.length()){

        if(i +1 == m_palavra.length()){
           i++;
           continue;
        }

         else if(isalnum(m_palavra.at(i)) && isalnum(m_palavra.at(i+1))){
            m_palavra.insert(i+1,1,'.');
        }
        else if (isalnum(m_palavra.at(i)) && (m_palavra.at(i+1) == '(')) {
              m_palavra.insert(i+1,1,'.');
        }
        else if(m_palavra.at(i)== ')'&& isalnum( m_palavra.at(i+1))){
            m_palavra.insert(i+1,1,'.');
}
       else if(m_palavra.at(i) == '*' && (isalnum(m_palavra.at(i+1)) || m_palavra.at(i+1)== '(')){
          m_palavra.insert(i+1,1,'.');}

   i++;
}
    return m_palavra;
}


string posfixa::converte(string exp){
    string palavra  = posfixa::expressao(exp);
    string resultado;
    stack<char>pilha;
    for (int i = 0; i <palavra.length(); ++i) {
       if(isalnum(palavra.at(i))) // caso I
           resultado.append(1,palavra.at(i));
       else if (palavra.at(i)== '(')  //caso II
           pilha.push(palavra.at(i));
       else if (palavra.at(i) == ')'){ // caso III
           while (pilha.top()!= '(' && !(pilha.empty())) {
               resultado.append(1,pilha.top());
               pilha.pop();

           }  // caso III a
                if(pilha.top() == '(') // caso III b
                    pilha.pop();
       }
        else {       // caso IV

           if (palavra.at(i) == '*'){
              while(!pilha.empty() && pilha.top() == '*'){
                  resultado.append(1,pilha.top());
                  pilha.pop();
              }
              pilha.push(palavra.at(i));
           }
             else if( palavra.at(i) == '.'){
               while(!pilha.empty() && (pilha.top() == '*' || pilha.top() == '.')){
                   resultado.append(1,pilha.top());
                   pilha.pop();
               }
               pilha.push(palavra.at(i));

           }
           else if (palavra.at(i) == '+'){
               while (!pilha.empty() && (pilha.top() == '*'|| pilha.top() == '.' || pilha.top() == '+')) {
                    resultado.append(1,pilha.top());
                    pilha.pop();
               }
               pilha.push(palavra.at(i));
           }


       }




    }


    while (!pilha.empty() && pilha.top() != '(') { /// segunda etapa
        resultado.append(1,pilha.top());
        pilha.pop();
    }
    if(!pilha.empty() && pilha.top() == '('){
        flag = false;
    }
    return resultado;
}



