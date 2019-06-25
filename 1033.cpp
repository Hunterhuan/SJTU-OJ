#include <iostream>
#include <memory>
#include <stack>
#include <fstream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <exception>
#include <climits>
#include <array>
#include <cstdint>



using namespace std;

class Token {
public:
    virtual bool isOperator()=0;
    virtual ~Token() {}
};

class ValueToken : public Token {
public:
    long long value;
    long long get_value(){ return value;}
    virtual bool isOperator() { return false; }
    explicit ValueToken(long long val) : value(val) {}
};

class OperatorToken : public Token {
public:
    enum OpType {
        BGN=0, END, ADD, MNS, NEG, MUL, DIV, POW, LBK, RBK
    } optr;

    virtual bool isOperator() { return true; }
    char get_char(){
        switch (optr){
            case BGN:
                return '@';
            case END:
                return '$';
            case ADD:
                return '+';
            case MNS:
                return '-';
            case NEG:
                return '#';
            case MUL:
                return '*';
            case DIV:
                return '/';
            case POW:
                return '^';
            case LBK:
                return '(';
            case RBK:
                return ')';
            default:
                return '?';
        }
    }
    explicit OperatorToken(OperatorToken::OpType op) : optr(op) {}
    bool is_prior(const OperatorToken& r){
        return prior_table[this->optr][r.optr];
    }
    static bool prior_table[10][10];
};
bool OperatorToken::prior_table[10][10]={
        //BGN, END, ADD, MNS, NEG, MUL, DIV, POW, LBK, RBK
        {0,0,0,0,0,0,0,0,0,0},//BGN
        {1,0,0,0,0,0,0,0,0,0},//END
        {1,1,0,0,0,0,0,0,1,0},//ADD
        {1,1,0,0,0,0,0,0,1,0},//MNS
        {1,1,1,1,0,1,1,1,1,0},//NEG
        {1,1,1,1,0,0,0,0,1,0},//MUL
        {1,1,1,1,0,0,0,0,1,0},//DIV
        {1,1,1,1,0,1,1,1,1,0},//POW
        {1,1,1,1,1,1,1,1,1,0},//LBK
        {1,1,0,0,0,0,0,0,1,0},//RBK
};

vector<shared_ptr<Token>> pre_process(const string &str) {
    vector<shared_ptr<Token>> ret;
    ret.emplace_back(new OperatorToken(OperatorToken::BGN));
    long long val = 0;
    bool f = false, is_neg = true;
    for (char c:str) {
        if (c >= '0' && c <= '9') {
            if (f)val = val * 10 + c - '0';
            else val = c - '0';
            is_neg= false;
            f = true;
        } else {
            if (f) {
                ret.emplace_back(new ValueToken(val));
            }
            switch (c) {
                case '+':
                    ret.emplace_back(new OperatorToken(OperatorToken::ADD));
                    is_neg=true;
                    break;
                case '-':
                    ret.emplace_back(new OperatorToken(is_neg?OperatorToken::NEG:OperatorToken::MNS));
                    is_neg=true;
                    break;
                case '*':
                    ret.emplace_back(new OperatorToken(OperatorToken::MUL));
                    is_neg=true;
                    break;
                case '/':
                    ret.emplace_back(new OperatorToken(OperatorToken::DIV));
                    is_neg=true;
                    break;
                case '^':
                    ret.emplace_back(new OperatorToken(OperatorToken::POW));
                    is_neg=true;
                    break;
                case '(':
                    ret.emplace_back(new OperatorToken(OperatorToken::LBK));
                    is_neg=true;
                    break;
                case ')':
                    ret.emplace_back(new OperatorToken(OperatorToken::RBK));
                    is_neg= false;
                    break;
                case ' ':
                    break;
                default:
                    break;
            }
            val = 0;
            f = false;
        }
    }
    if(f)ret.emplace_back(new ValueToken(val));
    ret.emplace_back(new OperatorToken(OperatorToken::END));
    return ret;
}

void print(const vector<shared_ptr<Token>> v){
    for(auto p:v){
        if(p->isOperator()){
            cout<<static_pointer_cast<OperatorToken>(p)->get_char();
        }
        else{
            cout<<static_pointer_cast<ValueToken>(p)->get_value();
        }
    }
}

void compute(stack<shared_ptr<OperatorToken>>& optrs, stack<long long>& vals){
    long long l,r,s;
    auto op=optrs.top()->optr;
    optrs.pop();
    switch (op){
        case OperatorToken::ADD:
            if(vals.size()<2)throw exception();
            r=vals.top();
            vals.pop();
            l=vals.top();
            vals.pop();
            vals.push(l+r);
#ifdef DEBUG
            cout<<l<<"+"<<r<<"="<<vals.top()<<endl;
#endif
            break;
        case OperatorToken::MNS:
            if(vals.size()<2)throw exception();
            r=vals.top();
            vals.pop();
            l=vals.top();
            vals.pop();
            vals.push(l-r);
#ifdef DEBUG
            cout<<l<<"-"<<r<<"="<<vals.top()<<endl;
#endif
            break;
        case OperatorToken::NEG:
            if(vals.size()<1)throw exception();
            l=vals.top();
            vals.pop();
            vals.push(-l);
#ifdef DEBUG
            cout<<" neg "<<l<<"="<<vals.top()<<endl;
#endif
            break;
        case OperatorToken::MUL:
            if(vals.size()<2)throw exception();
            r=vals.top();
            vals.pop();
            l=vals.top();
            vals.pop();
            vals.push(l*r);
#ifdef DEBUG
            cout<<l<<"*"<<r<<"="<<vals.top()<<endl;
#endif
            break;
        case OperatorToken::DIV:
            if(vals.size()<2)throw exception();
            r=vals.top();
            vals.pop();
            if(!r)throw exception();
            l=vals.top();
            vals.pop();
            vals.push(l/r);
#ifdef DEBUG
            cout<<l<<"/"<<r<<"="<<vals.top()<<endl;
#endif
            break;
        case OperatorToken::POW:
            if(vals.size()<2)throw exception();
            r=vals.top();
            vals.pop();
            l=vals.top();
            vals.pop();
            s=pow(l,r);
            vals.push(s);
#ifdef DEBUG
            cout<<l<<"^"<<r<<"="<<vals.top()<<endl;
#endif
            break;
        case OperatorToken::RBK:
            if(optrs.top()->optr!=OperatorToken::LBK)throw exception();
            optrs.pop();
#ifdef DEBUG
            cout<<"()"<<endl;
#endif
            break;
        case OperatorToken::END:
            optrs.pop();
            break;

        default:
            throw exception();
            break;
    }
}

int main() {

    string string1;
    getline(cin,string1);
    auto s = pre_process(string1);
    stack<shared_ptr<OperatorToken>> optrs;
    stack<long long> vals;
    optrs.push(dynamic_pointer_cast<OperatorToken>(s[0]));
    try{
        for(auto& ptoken:s){
            if(ptoken==s[0])continue;
            if(!ptoken->isOperator())vals.push(dynamic_pointer_cast<ValueToken>(ptoken)->value);
            else{
                shared_ptr<OperatorToken> ptr=dynamic_pointer_cast<OperatorToken>(ptoken);
                while (!ptr->is_prior(*optrs.top())){
                    compute(optrs,vals);
                }
                optrs.push(ptr);
            }
        }
        if(vals.size()!=1||optrs.size()!=2)throw exception();
    }catch (exception e){
        cout<<"Error";
        return 0;
    }
    cout<<vals.top();
    return 0;
}