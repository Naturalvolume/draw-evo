#include <iostream>
#include <fstream>
#include<sstream>
using namespace std;
  
int main()
{
  int i=1,j=1;   
  string fname1= "/home/zbq/datasets/Format/rgb/1311868164.363181.png"; 
  string fname2 = "/home/zbq/projects/FormatCag/result/";
  ostringstream oss;
  oss<<i<<j<<".png";
  fname2 += oss.str(); 
  fstream f;
  f.open(fname1.c_str());
  if(!f)
  {
     cout<<"图片不存在！"<<endl;
  }
  else
  {
     rename(fname1.c_str(),fname2.c_str());
     cout<<"成功将重命名为"<<endl;
     f.close();
  }
  return 0;
}
