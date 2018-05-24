#include <iostream>

using namespace std;

class matrix {
public:
    int nums[2][2];
    matrix(int a, int b, int c, int d) {
        nums[0][0] = a;
        nums[0][1] = b;
        nums[1][0] = c;
        nums[1][1] = d;
    }
};

void multiply(matrix &m1, matrix &m2) { // 2*2 x 2*2 rsult -> m1!
    int a = (m1.nums[0][0] * m2.nums[0][0] + m1.nums[0][1] * m2.nums[1][0]) % 2010;
    int b = (m1.nums[0][0] * m2.nums[0][1] + m1.nums[0][1] * m2.nums[1][1]) % 2010;
    int c = (m1.nums[1][0] * m2.nums[0][0] + m1.nums[1][1] * m2.nums[1][0]) % 2010;
    int d = (m1.nums[1][0] * m2.nums[0][1] + m1.nums[1][1] * m2.nums[1][1]) % 2010;
    m1.nums[0][0] = a;
    m1.nums[0][1] = b;
    m1.nums[1][0] = c;
    m1.nums[1][1] = d;
}

int main()
{
    matrix result(1, 0, 0, 1);
    matrix base(1, 1, 1, 0);
    long long n;
    cin >> n;
    long long index = n - 1;
    while (index) {
        if (index & 1) {
            multiply(result, base);
        }
        index = index >> 1;
        multiply(base, base);
    }
    cout << result.nums[0][0];
    //cout << result.nums[0][0] << "   " << result.nums[0][1] << endl;
    //cout << result.nums[1][0] << "   " << result.nums[1][1] << endl;
    return 0;
}
