#include<iostream>
#include<algorithm>
#include<fstream>
#include<sstream>
#include<opencv2/core/core.hpp>

using namespace std;

void LoadImages(const string &strFile, vector<string> &vstrImageFilenames,
                vector<double> &vTimestamps);

int main(int argc, char **argv)
{
 if(argc != 2)
    {
        cerr << endl << "no path_to_sequence? oops " << endl;
        return 1;
    }
  vector<string> vstrImageFilenames;
  vector<double> vTimestamps;
  string strFile = string(argv[1])+"/zbq.txt";
  LoadImages(strFile, vstrImageFilenames, vTimestamps);
  cout<<"ok all images are saved"<<endl;
  int nImages = vstrImageFilenames.size();
  cout<<"images: "<<nImages<<endl;
   for(int ni=0; ni<nImages; ni++)
    {
       
  string fname1= string(argv[1])+"/"+vstrImageFilenames[ni];
  string fname2 = "/home/zbq/projects/FormatCag/result/";
  ostringstream oss;
  int a=ni/10;
  int b=ni/100;
  int c=ni/1000;
  if(c)
  {
    oss<<"0"<<ni<<".png"; 
  }else if(b)
  {
     oss<<"00"<<ni<<".png"; 
  } else if(a)
        {
         oss<<"000"<<ni<<".png"; 
         } else {   oss<<"0000"<<ni<<".png";   }
    
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

    }
}


void LoadImages(const string &strFile, vector<string> &vstrImageFilenames, vector<double> &vTimestamps)
{
    ifstream f;
    f.open(strFile.c_str());

    // skip first three lines
    string s0;
    getline(f,s0);
    getline(f,s0);
    getline(f,s0);

    while(!f.eof())
    {
        string s;
        getline(f,s);
        if(!s.empty())
        {
            stringstream ss;
            ss << s;
            double t;
            string sRGB;
            ss >> t;
            vTimestamps.push_back(t);
            ss >> sRGB;
            vstrImageFilenames.push_back(sRGB);
        }
    }
}

