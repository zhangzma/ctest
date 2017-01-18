/*
 * 版权所有(C) 2011-2012 Usoft 工作室
 * 保留所有版权
 *
 * 文件名称: main.cpp
 * 摘   要: 程序通过修改 nyfedit.ini 配置文件中的用户初次试用时间
 *           (App.UserLic.FirstUseOn) 来延长软件的试用期限。
 *
 * 修订历史: 创建
 * 版   本: v 0.1
 * 作   者: zhanghb
 * 日   期: 2012.08.28
 * 修   订:
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>
using namespace std;
// 待搜索的指定字符串行
const string sDes = "build_time=";

bool IsRightLine(const string &str);
string UpdateBuildTime(const string & str);
string AddBduildTime();

int main( void)
{
    bool    update_flag = false;
    fstream fp;
    string  sFileName   = "build.ini";
    
    fp.open(sFileName.c_str(), fstream::in | fstream::out);

    if (!fp) {
        std::cerr << "Error: unable to open input file: "
                  << sFileName << endl;
        return -1;
    }

    string  sTmp;
    ifstream::pos_type mark = 0;
    while (mark = fp.tellg(), fp >> sTmp) {
        if (IsRightLine(sTmp)) {
            sTmp = UpdateBuildTime(sTmp);
            update_flag = true;
            break;
        }
    }

    if (!update_flag) {
        mark = 0;
        sTmp = AddBduildTime();
    }
    fp.clear();
    fp.seekp(mark);
    fp << sTmp << std::endl;
    // std::cout << sTmp << std::endl;
    fp.close();

    return 0;
}

/*
 * 函数名称: IsRightLine()
 *
 * 函数功能: 判断字符串是否包含指定信息
 *
 * 入口参数: string str -- 待搜索字符串
 *
 * 出口参数: bool true  -- 找到指定字符串；否则，返回 false
 */
bool IsRightLine(const string &str)
{
    bool isRightLine = false;
    string::size_type pos = str.find(sDes, 0);

    if (pos != string::npos) {
        isRightLine = true;
    }

    return isRightLine;
}

/*
 * 函数名称: UpdateBuildTime()
 *
 * 函数功能: 修改指定字符串的内容
 *
 * 入口参数: string &str -- 待修改字符串
 *
 * 出口参数: 修改后字符串
 */
string UpdateBuildTime(const string &str)
{
    string sKey, sBuildTime;
    istringstream iss(str);
    getline(iss, sKey, '=');
    getline(iss, sBuildTime);

    long int iBuildTime;
    iBuildTime = atol(sBuildTime.c_str());
    iBuildTime++;
    
    ostringstream oss;
    oss << iBuildTime;
    sBuildTime = oss.str();

    return sDes + sBuildTime;
}
    
string AddBduildTime()
{
    return UpdateBuildTime("build_time=0");
}

