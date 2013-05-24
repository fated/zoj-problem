#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

string s1,s2;
stack<char> cs;
vector<char> io;
int l;

void print()
{
    for(int i=0; i<io.size(); i++)
        cout << io[i] << " ";
    cout << endl;
}

void search(int in,int out)
{
    char t;
    if( in==l && out==l )
    {
        print();
        return;
    }

    if( in<l )
    {
        cs.push(s1[in]);
        io.push_back('i');
        search(in+1,out);
        cs.pop();
        io.pop_back();
    }
    if( out<in && out <l && cs.top()==s2[out] )
    {
        t = cs.top();
        cs.pop();
        io.push_back('o');
        search(in,out+1);
        cs.push(t);
        io.pop_back();
    }
}

int main()
{
    while(cin >> s1 >> s2)
    {
        l = s1.length();
        cout << "[" << endl;
        search(0,0);
        cout << "]" << endl;
    }
    return 0;
}
