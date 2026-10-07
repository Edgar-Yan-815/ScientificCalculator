#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <cmath>
using namespace std;

class Calculator{
    private:
        string add(string num1, string num2){
            size_t num1Dot=num1.find('.');
            size_t num2Dot=num2.find('.');

            string res="";
            if (num1Dot!=string::npos){
                res=num1.substr(num1Dot+1);
                num1.erase(num1Dot);
            }
            int diff=0;
            int carry=0;
            if (num2Dot!=string::npos){
                string temp=num2.substr(num2Dot+1);
                num2.erase(num2Dot);

                if (res.empty()){
                    res=temp;
                }else{
                    diff=max(res.length(),temp.length());
                    while (res.length()<diff){
                        res+='0';
                    }
                    while (temp.length()<diff){
                        temp+='0';
                    }
                    for (int i=diff-1;i>=0;i--){
                        int sum=res[i]-'0'+(temp[i]-'0')+carry;
                        if (sum>=10){
                            carry=1;
                            sum-=10;
                        }else{
                            carry=0;
                        }
                        res[i]='0'+sum;
                    }
                    res.insert(0,1,'.');
                }
            }
            diff=max(num1.length(),num2.length());
            while (num1.length()<diff){
                num1.insert(0,1,'0');
            }
            while (num2.length()<diff){
                num2.insert(0,1,'0');
            }
            for (int i=diff-1;i>=0;i--){
                int sum=num1[i]-'0'+(num2[i]-'0')+carry;
                if (sum>=10){
                    sum-=10;
                    carry=1;
                }else{
                    carry=0;
                }
                res.insert(0,1,'0'+sum);
            }
            if (carry>0){
                res.insert(0,1,'1');
            }
            return res;
        }

        string sub(string num1, string num2){
        }

        void mult(double num1, double num2){
        }

        void div(double num1, double num2){
        }

        void modulo(double num1, double num2){
        }

        void squareRoot(double num){
        }

    public:
        Calculator(){
            string res=add("583920174.00000730940052","0.99999999999999993721");
            string res2=add("7000000000003.0000000000000000047","999999999999.9999999999999999953");
            cout<<res<<endl;
            cout<<res2<<endl;
        };
};
#endif