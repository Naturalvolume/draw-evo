#include<iostream>
#include<algorithm>
#include<fstream>
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
  string strFile = string(argv[1]);
  LoadImages(strFile, vstrImageFilenames, vTimestamps);
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

