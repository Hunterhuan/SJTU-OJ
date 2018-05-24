#include <iostream>

using namespace std;

int main()
{
    int able_number = 0;
    int apple_height,people_height, desk_height, apple_number;
    cin>>people_height>>desk_height>>apple_number;
    for(int i = 0;i<apple_number;++i)
    {
        cin>>apple_height;
        if(apple_height<=(people_height+desk_height))
            able_number++;
    }
    cout<<able_number;
    return 0;
}
