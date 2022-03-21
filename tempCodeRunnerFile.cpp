   {
     p1.c1=0;
    ifstream take3("f2");
    while(!take3.eof())
       {
         getline(take3,p1.name);
         p1.c1++;
       }
       take3.close();
       ifstream take4("f2");
    for(int i=0;i<p1.c1-1;i++)
    {
      getline(take3,p1.name);
      p1.n=stoi(p1.name);
      vertex.push_back(p1.n);
      getline(take3,p1.name);
      p1.n=stoi(p1.name);
      normal.push_back(p1.n);
      q++;
    } 
    take4.close();
   }
}