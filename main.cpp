#include <iostream>
#define WIDTH 50
#define HEIGHT 25
using namespace std;

void board(){
    for(int i=0;i<HEIGHT;i++)
    {
        cout<<"#";
        for(int j=0;j<WIDTH-2;j++)
        {
            if(i==0 || i==HEIGHT-1)
                cout<<'#';
            else
                cout<<' ';
        }
        cout<<"#\n";
    }
}
int main()
{
    board();
}
