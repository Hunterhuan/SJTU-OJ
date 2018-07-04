#include <iostream>
#include <iomanip>
using namespace std;

class MyComplex
{
    friend ostream & operator<<(ostream &out, MyComplex &obj);
    friend istream & operator>>(istream &in, MyComplex &obj);
private:
  double x,y;
public:
    MyComplex(double m=0,double n=0)
    {
        x = m;
        y = n;
    }
    MyComplex(MyComplex &obj)
    {
        x = obj.x;
        y = obj.y;
    }
    MyComplex& operator=(const MyComplex &obj)
    {
        this->x = obj.x;
        this->y = obj.y;
        return *this;
    }
    MyComplex operator+(const MyComplex &obj)
    {
        MyComplex p(this->x+obj.x,this->y+obj.y);
        return p;
    }
    MyComplex operator-(const MyComplex &obj)
    {
        MyComplex p(this->x-obj.x,this->y-obj.y);
        return p;
    }
    MyComplex operator*(const MyComplex &obj)
    {
        MyComplex p(this->x*obj.x-this->y*obj.y,this->x*obj.y+this->y*obj.x);
        return p;
    }
    MyComplex operator/(const MyComplex &obj)
    {
        double q = obj.x*obj.x+obj.y*obj.y;
        MyComplex p((this->x*obj.x+this->y*obj.y)/q,(this->x*obj.y*(-1.0)+this->y*obj.x)/q);
        return p;
    }
  /* Implementation of MyComplex */

};
ostream & operator<<(ostream &out, MyComplex &obj)
{
    out<<setprecision(2)<<std::fixed<<obj.x<<' '<<obj.y;
    return out;
}
istream & operator>>(istream &in, MyComplex &obj)
{
    in>>obj.x>>obj.y;
    return in;
}

int main()
{
  MyComplex z1;
  MyComplex z2;

  cin >> z1 >> z2;
  MyComplex z3(z1);
  z3 = z1 + z2;
  cout << z3 <<endl;
  z3 = z1 - z2;
  cout << z3 <<endl;
  z3 = z1*z2;
  cout << z3 <<endl;
  z3 = z1/z2;
  cout << z3 <<endl;
  z1 = z1+z2;
  cout << z1 <<endl;
  z1 = z1-z2;
  cout << z1 <<endl;
  z1 = z1*z2;
  cout << z1 <<endl;
  z1 = z1/z2;
  cout << z1 <<endl;

  return 0;
}
