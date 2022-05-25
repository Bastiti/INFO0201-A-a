#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

int mod(char x,int n)
{

    int a=n+x;
    a-=32;
    a%=126;
    a+=32;

    return a;
}

string codage(string txt,int n)
{
    string a=txt;
    for(int i=0; i<txt.size(); i++)
    {
        a[i]=mod(txt[i],n);
    }

    return a;
}

int main()
{
    string message;
    ifstream txt("./message.txt");
    getline(txt,message);

    string mdp;
    cin>>mdp;

    int n=0;
    for(int i=0;i<mdp.size();i++)
    {
        n+=mdp[i];
    }
    cout<<mdp<<endl;
    cout<<n<<endl;


    ofstream message_code("./message_code.txt");
    message_code<<codage(message,n)<<endl;

    cout<<codage(message,n)<<endl;


    return 0;
}
