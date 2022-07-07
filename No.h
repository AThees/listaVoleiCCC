#ifndef NO_H_INCLUDED
#define NO_H_INCLUDED
#include <string>

using namespace std;

class No
{
private:
    string info;
    No* prox;
public:
    No()                    {};
    ~No()                   {};
    void setInfo(string val)   { info = val; };
    void setProx(No* p)     { prox = p; };
    string getInfo()           { return info; };
    No * getProx()          { return prox; };
};

#endif // NO_H_INCLUDED
