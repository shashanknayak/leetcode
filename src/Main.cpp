#include "Helpers/Includes.h"
#include "Helpers/Utils.h"
#include "Helpers/ScratchPad.h"

using namespace std;

vector<string> GetDirectories() {

    WIN32_FIND_DATA ffd;
    LARGE_INTEGER filesize;
    size_t length_of_arg;
    TCHAR szDir[MAX_PATH];
    HANDLE hFind = INVALID_HANDLE_VALUE;
    DWORD dwError=0;

    vector<string> directories;

    StringCchCopy(szDir, MAX_PATH, TEXT(".\\src\\*"));
    hFind = FindFirstFile(szDir, &ffd);

    if (INVALID_HANDLE_VALUE == hFind) 
    {
    } 
    
    // List all the files in the directory with some info about them.

    do
    {
        if (ffd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
        {
            if ((ffd.cFileName[0] == '.' && 
                (ffd.cFileName[1] == 0 || ffd.cFileName[1] == '.'))) {
                    continue;
                }

#ifdef _WIN32
                directories.push_back(ffd.cFileName);
#endif
            // wcout << directories.size() << " " << ffd.cFileName << endl;
        }
    }
    while (FindNextFile(hFind, &ffd) != 0);
    
    dwError = GetLastError();
    if (dwError != ERROR_NO_MORE_FILES) 
    {
    }

    FindClose(hFind);
    return directories;
}

int main()
{
    int p;
    bool stop = false;
    auto dirs = GetDirectories();

    while (!stop) {
        cout<<"Pick a problem:"<<endl<<endl;
        cout<<"0. ScratchPad"<<endl;
        
        for (auto it = dirs.begin(); it != dirs.end(); it++) {
            cout << *it << endl;
        }

        cout<<endl<<"Enter -1 to exit."<<endl<<endl;
        cout<<"What say? ";
        cin>>p;

        switch(p) {
            case 0: 
                break;
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