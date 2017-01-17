const char *self_str="636f6e73742063686172202a73656c665f7374723d22223b0d0a23696e636c7564653c6d61703e0d0a23696e636c7564653c737472696e673e0d0a23696e636c7564653c696f73747265616d3e0d0a23696e636c7564653c7373747265616d3e0d0a23696e636c7564653c696f6d616e69703e0d0a23696e636c7564653c6673747265616d3e0d0a7573696e67206e616d657370616365207374643b0d0a737472696e6720656e6328636f6e737420737472696e67202673297b0d0a2020737472696e6773747265616d2073733b0d0a202069662028732e73697a6528293d3d31297b0d0a20202020696e742069203d20735b305d3b0d0a2020202073733c3c736574772832293c3c73657466696c6c28273027293c3c73657462617365283136293c3c693b0d0a2020202072657475726e2073732e73747228293b0d0a20207d20656c7365207b0d0a2020202069737472696e6773747265616d20696e732873293b0d0a20202020696e7420633b0d0a20202020696e733e3e736574772832293e3e73657462617365283136293e3e633b0d0a2020202073733c3c7374617469635f636173743c636861723e2863293b0d0a2020202072657475726e2073732e73747228293b0d0a20207d0d0a7d0d0a696e74206d61696e28297b0d0a2020737472696e672073203d2073656c665f7374723b0d0a2020696e74207072656669785f6c656e203d2032202a207374726c656e2822636f6e73742063686172202a73656c665f7374723d22293b0d0a2020666f722028696e7420693d303b20693c20732e73697a6528293b20692b3d32297b0d0a20202020636f75743c3c656e6328732e73756273747228692c3229293b0d0a2020202069662028693d3d7072656669785f6c656e290d0a202020202020636f75743c3c733b0d0a20207d0d0a202072657475726e20303b0d0a7d0d0a";
#include<map>
#include<string>
#include<iostream>
#include<sstream>
#include<iomanip>
#include<fstream>
#include <string.h>

using namespace std;
string enc(const string &s){
  stringstream ss;
  if (s.size()==1){
    int i = s[0];
    ss<<setw(2)<<setfill('0')<<setbase(16)<<i;
    return ss.str();
  } else {
    istringstream ins(s);
    int c;
    ins>>setw(2)>>setbase(16)>>c;
    ss<<static_cast<char>(c);
    return ss.str();
  }
}
int main(){
  string s = self_str;
  int prefix_len = 2 * strlen("const char *self_str=");
  for (int i=0; i< s.size(); i+=2){
    cout<<enc(s.substr(i,2));
    if (i==prefix_len)
      cout<<s;
  }
  return 0;
}
