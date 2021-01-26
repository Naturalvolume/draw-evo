#include <iostream>
#include <fstream>
#include<sstream>
#include<string>
using namespace std;
  
int main()
{
  int index=4540;
  

for(int k=0;k<=index;k++)
 {
  string fname1= "/home/zbq/datasets/image_0/"; 
  string fname2 = "/home/zbq/datasets/result/";
  stringstream ss;
 ostringstream oss;
  ss.str(""); 
  if(k%1000)
 {
    ss<<"00"<<k;
    oss<<"0"<<k<<".png";
  }else if(k%100)
 {
    ss<<"000"<<k;
    oss<<"00"<<k<<".png";
 }
 else if(k%10)
 {
  ss<<"0000"<<k;
  oss<<"000"<<k<<".png";
 }
 else
 {
   ss<<"00000"<<k;
   oss<<"0000"<<k<<".png";
 }
  string cut2 = ss.str();

 string name = ".png";
  fname1+=cut2;

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
