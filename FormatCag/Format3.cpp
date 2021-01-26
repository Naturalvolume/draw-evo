#include <iostream>
#include <fstream>
#include<sstream>
#include<string>
using namespace std;
  
int main()
{
  int index=2000;
  

for(int k=1;k<=index;k++)
 {
  string fname1= "/home/zbq/append/datasets/resultFrame/"; 
  string fname2 = "/home/zbq/append/datasets/VideoToFrame/";
  stringstream ss;
 ostringstream oss;
  ss.str(""); 
  if(k/1000)
 {
    oss<<"0"<<k<<".jpg";
  }else if(k/100)
 {
    oss<<"00"<<k<<".jpg";
 }
 else if(k/10)
 {
  oss<<"000"<<k<<".jpg";
 }
 else
 {
   oss<<"0000"<<k<<".jpg";
 }
  ss<<"0"<<k;
  string cut2 = ss.str();
 fname1+=cut2;
 string name = ".jpg";
  fname1+=name;

  fname2 += oss.str(); 
  fstream f;
  f.open(fname1.c_str());
  if(!f)
  {
     cout<<fname1<<endl;
     cout<<"图片不存在！"<<endl;
  }
  else
  {
     rename(fname1.c_str(),fname2.c_str());
     cout<<"成功将重命名为"<<endl;
     f.close();
  }

}
 
 
  return 0;
}
