#include<iostream>
#include<fstream>
#include <cstring>
#include<vector>
#include <bits/stdc++.h>
using namespace std;
void seperation();
void seperation2();
void gather();
int t=0;
int t2=0;
int main()
{
    string name;
    ifstream inf("stl_cube.stl");
    ofstream info("File1");
    for(int i=0;i<1;i++)
        {
         getline(inf,name);   
        }
    while(!inf.eof())
    {
        int p=0;
        char sp[2]=" ";
    char ch[1000];
     getline(inf,name);
    int n = name.length();
    char char_array[n + 1];
    strcpy(char_array, name.c_str());
    if(char_array[p]=='\t')
    {
       while(char_array[p]=='\t')
        p++;
        for(int u=0;u<=n-3;u++)
        {
       info<<char_array[p];
        p++;
        }
    }
    else
    {   for(int w=0;w<=n-1;w++)
        {
       // if(char_array[p]!=sp[1])
        info<<char_array[p];
        p++;
        }
    }
    ///info<<name; 
    info<<endl;
    }
    inf.close();
    info.close();
    seperation2();
    seperation();
    gather();

    return 0;
}
void seperation()
{
    string name2;
    ifstream inf1("File1");
    ofstream info1("Facet");
   /// info1<<"o cube"<<endl;
    while(!inf1.eof())
    {
        int p=0;
        char sq[10]="fv";
    char ch[1000];
     getline(inf1,name2);
    int n = name2.length();
    char char_array[n + 1];
    strcpy(char_array, name2.c_str());
    if(char_array[0]==sq[0])
    {
        info1<<"vn ";
    for (int i = 13; i < n; i++)
    {   
        info1<<char_array[i];
    }
      t++;
      info1<<endl;
    }
    }
    inf1.close();
    info1.close();
}
 void seperation2()
 {
    string name2;
    ifstream inf1("File1");
    ofstream info1("vertex");
    info1<<"o cube"<<endl;
    while(!inf1.eof())
    {
        int p=0;
        char sq[10]="fv";
    char ch[1000];
     getline(inf1,name2);
    int n = name2.length();
    char char_array[n + 1];
    strcpy(char_array, name2.c_str());
    if(char_array[0]==sq[1])
    {
        info1<<"v ";
    for (int i = 7; i < n; i++)
    {   
        info1<<char_array[i];
    }
      t2++;
      info1<<endl;
    }
    }
    inf1.close();
    info1.close();
}
void gather()
{
    string get;
    ifstream inf2("vertex");
    ifstream inf3("Facet");
    ofstream info3("File2.obj");
    cout<<t<<endl<<t2;
    for(int i=0;i<t2+1;i++)
    {
    getline(inf2,get);
    info3<<get<<endl;
    }
    info3<<"vt 1.000000 0.333333"<<endl;
    for(int i=0;i<t;i++)
    {
    getline(inf3,get);
    info3<<get<<endl;
    }
    info3<<"usemtl Material"<<endl<<"s off"<<endl;
    for(int a=1;a<=t;a++)
    {
        for(int b=1;b<=t2;a++)
        {
            info3<<"f "<<b<<"/1/"<<a;
            b++;
             info3<<" "<<b<<"/1/"<<a;
            b++;
             info3<<" "<<b<<"/1/"<<a;
             b++;
             info3<<endl;
        }
        
    }
    inf2.close();
    inf3.close();
    info3.close();
}