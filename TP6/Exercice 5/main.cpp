#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

int mod(char x,int n)
{

    int a=n+x;
    a-=32;
    a%=126;
    a+=32;

    return a;
}

string decryptage(string txt, int cle)
{
    for(int i=0; i<txt.size(); i++)
    {
        txt[i]=mod(txt[i],cle);
    }

    return txt;
}

int n_espace(string txt)
{
    int n=0;
    char l_max;

    for(int i=0; i<txt.size(); i++)
    {
        int t=0;
        int k=0;

        while (txt.find(txt[i],k)!=-1)
        {
            k=txt.find(txt[i],k)+1;
            t++;
        }

        if(n<t)
        {
            n=t;
            l_max=txt[i];
        }
    }
    return n;
}

char lettre_max (string txt, int n_espace)
{
    int n=0;
    char l_max;

    for(int i=0; i<txt.size(); i++)
    {
        int t=0;
        int k=0;

        while (txt.find(txt[i],k)!=-1)
        {
            k=txt.find(txt[i],k)+1;
            t++;
        }

        if((n<t)&&(t<n_espace))
        {
            n=t;
            l_max=txt[i];
        }
    }
    return l_max;
}

int main()
{
    string message;
    ifstream md("C:\\Users\\axel_\\Google Drive\\cours\\B1Q2\\Programation\\code\\message_code.txt");
    getline(md,message);

    int cle=abs(lettre_max(message,n_espace(message))-'e');

    for(int i=0;i<126;i++)
    {
       cout<<decryptage(message,i)<<endl;
    }


    return 0;
}
