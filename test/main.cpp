#include <iostream>

using namespace std;

int main()
{
    int32_t a,b,c;
    a = 0x00001000;
    c = 0x20000000;
    b = 0x20001400;
    cout<<(a-c);
    cout<<endl<<b-c;
    //cout << "Hello world!" << endl;
    return 0;
}
