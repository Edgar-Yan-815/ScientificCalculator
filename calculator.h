#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <string>
#include <cmath>
using namespace std;

class Calculator{
    private:
        void alignment(string& num1, string& num2){
            size_t num1Dot=num1.find('.');
            size_t num2Dot=num2.find('.');
            int int1=0,int2=0,dec1=0,dec2=0;
            if (num1Dot!=string::npos){
                int1=num1Dot;
                dec1=num1.length()-int1-1;
            }else{
                int1=num1.length();
            }
            if (num2Dot!=string::npos){
                int2=num2Dot;
                dec2=num2.length()-int2-1;
            }else{
                int2=num2.length();
            }

            if (int1>int2){
                int diff=int1-int2;
                for (int i=0;i<diff;i++){
                    num2.insert(0,1,'0');
                }
            }else if (int2>int1){
                int diff=int2-int1;
                for (int i=0;i<diff;i++){
                    num1.insert(0,1,'0');
                }
            }

            if (dec1>dec2){
                int diff=dec1-dec2;
                for (int i=0;i<diff;i++){
                    num2+='0';
                }
            }else if (dec2<dec1){
                int diff=dec2-dec1;
                for (int i=0;i,diff;i++){
                    num1+='0';
                }
            }
        }

        string add(string num1, string num2){
            string res="";
            alignment(num1,num2);
            int n=num1.length();
            int carry=0;
            for (int i=n-1;i>=0;i--){
                if (num1[i]=='.'){
                    res.insert(0,1,'.');
                    continue;
                }
                int sum=carry+(num1[i]-'0')+(num2[i]-'0');
                if (sum>=10){
                    carry=1;
                    sum-=10;
                }else{
                    carry=0;
                }
                res.insert(0,1,sum+'0');
            }
            return res;
        }

        string sub(string num1, string num2){
            size_t num1Dot=num1.find('.');
            size_t num2Dot=num2.find('.');

            string res="";
            if (num1Dot!=string::npos){
                res=num1.substr(num1Dot+1);
                num1.erase(num1Dot);
            }
            return res;
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