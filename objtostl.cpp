#include<iostream>
#include<fstream>
#include <cstring>
#include<vector>
#include <bits/stdc++.h>
using namespace std;
void call();
int print(int itt1);
int print2(int itt2);
void delete_line(const char *file_name, int n);
void delete_line2(const char *file_name, int n);
int sv;
int sr;
 int q=0;
    vector<int> e;
    vector<int> r;
int main()
{   int i,j=0;
    string name;
    ifstream inf("obj_bottle.obj");
    ofstream info("data2");
    for(i=0;i<=1;i++)
        {
         getline(inf,name);   
        }
    while(!inf.eof())
    {
    getline(inf,name);
    info<<name; 
   // cout<<name;
   // cout<<endl;
    info<<endl;
    }
    inf.close();
    info.close();
    ifstream inform("data2");
    ofstream infor1("v");
    ofstream infor2("vn");
    ofstream infor3("f");
    while(!inform.eof())
    {
    string bg;
    char ch[1000];
    char d[6] ="v tnf";
    getline(inform,bg);
    int n = bg.length();
     char char_array[n + 1];
    strcpy(char_array, bg.c_str());
    if(char_array[2]==d[0]&&char_array[3]==d[1])
    {
    for (int i = 4; i < n; i++)
    {   
        //cout << char_array[i];
        infor1<<char_array[i];
    }
      infor1<<endl;
    }
    if(char_array[0]==d[0]&&char_array[1]==d[3])
    {
    for (int i = 3; i < n; i++)
    {   
        //cout << char_array[i];
        infor2<<char_array[i];
    }
      infor2<<endl;
    }
    if(char_array[0]==d[4]&&char_array[1]==d[1])
    {
    for (int i = 2; i < n-1; i++)
    {   
        //cout << char_array[i];
        infor3<<char_array[i];
    }
      infor3<<endl;
    }
    }
    infor1.close();
    infor2.close();
    infor3.close();
    inform.close();
    ifstream take("f");
    ofstream take2("f2");
    string tf;
    int n=0;
    while(!take.eof())
    {
    getline(take,tf);
    char fi[3]="/ ";
    int l = tf.length();
    char char_array[l];
    strcpy(char_array, tf.c_str());
    for(int h=0;h<=(l-1);h++)
    {
        if(char_array[h]==fi[0]||char_array[h]==fi[1])
        {
          take2<<endl;
          n++;
        }
        else if(char_array[h]=='\n')
        {
          take2<<endl;
          n++;
        }
        else
        {
        take2<<char_array[h];
        }
    }
     take2<<endl;
     n++;
    }
    take.close();
    take2.close();
    delete_line("f2", n);
    delete_line2("f4", n);
    call();
   // print();
    
    return 0;
}
void call()
{
    int v;
    string p;
    ifstream take3("f5");
    ofstream take4("f3");
    while(!take3.eof())
    {
      getline(take3,p);
      v=stoi(p);
      e.push_back(v);
      getline(take3,p);
      v=stoi(p);
      r.push_back(v);
     // cout<<e[q]<<"  "<<r[q]<<endl;
      q++;
    }
    //cout<<sizeof(e)<<endl<<sizeof(r)<<q;
    take3.close();
    take4.close();
    int itt1;
    int itt2;
    
    ifstream get2("v");
    ofstream put2;
    put2.open("bottle1.stl");
    cout<<"solid"<<endl;
    put2<<"solid"<<endl;
    
    for(int i=0;i<q;i++)
    {  
      cout<<"facet normal ";
     put2<<"facet normal ";
     // print(r[i]);
     int yup=0;
     if(yup==0)
     {
       string ap;  
      int line_no=1;
      ifstream get1("vn",ios::app);
      while(line_no!=r[i])
    {
      getline(get1,ap);
      line_no++;
    }
    if(line_no==r[i])
    {
      getline(get1,ap);
      cout<<ap;
      put2<<ap;
    }
    get1.close();
     }
       cout<<endl<<"\touter loop"<<endl;
     put2<<endl<<"\touter loop"<<endl;
      for(int hj=0;hj<=2;hj++)
      {
        if(yup==0)
        {
           string ap;  
  int line_no=1;
    ifstream get2("v",ios::app);
    while(line_no!=e[i])
    {
      getline(get2,ap);
      line_no++;
    }
    if(line_no==e[i])
    {
      getline(get2,ap);
      cout<<"\t\tvertex "<<ap<<endl;
      put2<<"\t\tvertex "<<ap<<endl;
    }
    get2.close();
        }
        cout<<endl;
        put2<<endl;
        i++;
      }
      cout<<"\tend loop"<<endl<<"endfacet";
     put2<<"\tend loop"<<endl<<"endfacet";
      cout<<endl;
      put2<<endl;
      i--;
    }
    cout<<"endsolid";
    put2<<"endsolid";
   //  get1.close();
     get2.close();
    put2.close();
    
}

void delete_line(const char *file_name, int n)
{
    ifstream is(file_name);
    ofstream ofs;
    ofs.open("f4", ofstream::out);
    char c;
    int line_no = 1;
    while (is.get(c))
    {
        if (c == '\n')
        line_no++;
        if (line_no != n)
            ofs << c;
    }
    ofs.close();
    is.close();
}
void delete_line2(const char *file_name, int n)
{
    ifstream is(file_name);
    ofstream ofs;
    ofs.open("f5", ofstream::out);
    char c;
    int line_no = 1;
    while (is.get(c))
    {
        if (c == '\n')
        line_no++;
        if (line_no != n)
            ofs << c;
    }
    ofs.close();
    is.close();
}
#