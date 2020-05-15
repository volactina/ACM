#include <iostream>
using namespace std;
int main()
{
    const int type[3][4]={{1,2,2,1},{4,3,3,4},{1,2,2,1}};
    int t;
    cin>>t;
    while (t--){
        int x,y;
        cin>>x>>y;
        x--,y--;
        switch(type[x][y]){
        case 1:
            {
                cout<<"Win"<<endl<<"6"<<endl;
                break;
            }
        case 4:
            {
                cout<<"Equal"<<endl<<"0"<<endl;
                break;
            }
        case 2:case 3:
            {
                cout<<"Win"<<endl<<"4"<<endl;
                break;
            }
        }
    }
    return 0;
}
