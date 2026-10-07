#ifndef PARSE_H
#define PARSE_H
#include <string>
#include <vector>
#include <stack>
using namespace std;
class Parse{
    private:
        string sentence;
        const vector<char> operators={'+','-','*','/','(',')'};
    public:
        Parse(){};

        void read(string s){
            
        }
};
#endif