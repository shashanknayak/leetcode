#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int p;
    bool stop = false;

    while (!stop) {
        cout<<"Pick a problem:"<<endl;
        cout<<"Enter -1 to exit."<<endl<<endl;
        cout<<"What say? ";
        cin>>p;

        switch(p) {
            case 1:
                cout<<"testing";
                break;
            case -1:
            default:
                stop = true;
                break;
        }

        cout<<endl<<endl;
    }
}