#include<iostream>
#include<fstream>
#include <cstring>
#include<vector>
#include <bits/stdc++.h>
using namespace std;
int k;
int q=0;
    vector<int> vertex;
    vector<int> normal;
void seperate();
void seperate2();
void seperate3();
class OBJ
{   public:
    string name;
    string Filename;
    int n;
    int c0,c1=0;
    char d[7] ="v tnf/";
    void file()
    {
      cout<<"Enter the name of file \n";
      cin>>Filename;
      cout<<endl<<Filename;
    }
};
int main()
{  
    OBJ p1;
    p1.file();
    ifstream inf(p1.Filename);
    ofstream info("data22");
    while(!inf.eof())
    {
    int i=0;
    getline(inf,p1.name);
     p1.n = p1.name.length();
     char char_array[p1.n + 1];
     strcpy(char_array, p1.name.c_str());
     while(char_array[i]==p1.d[1])
    { 
    i++;
    }  
     for(i;i<=p1.n-1;i++)
     {
    info<<char_array[i];
    }
    info<<endl;
     }
    inf.close();
    info.close();

void seperate();
{   
  
    ifstream inform("data22");
    ofstream infor1("v");
    ofstream infor2("vn");
    ofstream infor3("f");
    p1.c0=0;
    while(!inform.eof())
    {
    getline(inform,p1.name);
    p1.n = p1.name.length();
     char char_array[p1.n + 1];
    strcpy(char_array, p1.name.c_str());
    if(char_array[0]==p1.d[0]&&char_array[1]==p1.d[1])
    {
    for (int i = 2; i < p1.n; i++)
    {   
        infor1<<char_array[i];
    }
      infor1<<endl;
    }
    if(char_array[0]==p1.d[0]&&char_array[1]==p1.d[3])
    {
    for (int i = 3; i < p1.n; i++)
    {   
        infor2<<char_array[i];
    }
      infor2<<endl;
    }
    if(char_array[0]==p1.d[4]&&char_array[1]==p1.d[1])
    {
      if(char_array[p1.n-1]==p1.d[1])
       p1.n=p1.n-1;
    for (int i = 2; i < p1.n; i++)
    {   
        infor3<<char_array[i];
        if(char_array[i]==p1.d[5])
        {
            p1.c1++;
        }
    }
      infor3<<endl;
      p1.c0++;
    }
    }
    cout<<endl<<p1.c0;
    cout<<endl<<p1.c1;
    k=p1.c1/p1.c0;
    cout<<endl<<k;
    infor1.close();
    infor2.close();
    infor3.close();
    inform.close();
}

void seperate2();
{
  ifstream take("f");
  ofstream take2("f2");
  for(int i=0;i<p1.c0;i++)
  {
   getline(take,p1.name);
   p1.n = p1.name.length();
   char char_array[p1.n + 1];
   strcpy(char_array, p1.name.c_str());
   for(int h=0;h<=(p1.n-1);h++)
    {
        if(char_array[h]==p1.d[5]||char_array[h]==p1.d[1])
        {
          take2<<endl;
        }
        else if(char_array[h]=='\n')
        {
          take2<<endl;
        }
        else
        {
        take2<<char_array[h];
        }
    }
     take2<<endl;
    }
    take.close();
    take2.close();
  }
 void seperate3();
 {
   if(k==0)
   {
     cout<<"File has no normals";
   }
   if(k==3)
   {
     p1.c1=0;
    ifstream take3("f2");
    while(!take3.eof())
       {
         getline(take3,p1.name);
         p1.c1++;
       }
       take3.close();
       ifstream take4("f2",ios::app);
    for(int i=0;i<(p1.c1/2);i++)
    {
      getline(take4,p1.name);
      p1.n=stoi(p1.name);
      vertex.push_back(p1.n);
      getline(take4,p1.name);
      p1.n=stoi(p1.name);
      normal.push_back(p1.n);
      q++;
    } 
    take4.close();
   }
    if(k==6)
   {
      p1.c1=0;
    ifstream take3("f2");
    while(!take3.eof())
       {
         getline(take3,p1.name);
         p1.c1++;
       }
       take3.close();
       ifstream take4("f2",ios::app);
    for(int i=0;i<(p1.c1/3);i++)
    {
      getline(take4,p1.name);
      p1.n=stoi(p1.name);
      vertex.push_back(p1.n);
      getline(take4,p1.name);
      getline(take4,p1.name);
      p1.n=stoi(p1.name);
      normal.push_back(p1.n);
      q++;
    } 
    take4.close();
   }
   }
void print();
{
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
      while(line_no!=normal[i])
    {
      getline(get1,ap);
      line_no++;
    }
    if(line_no==normal[i])
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
    while(line_no!=vertex[i])
    {
      getline(get2,ap);
      line_no++;
    }
    if(line_no==vertex[i])
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
}
