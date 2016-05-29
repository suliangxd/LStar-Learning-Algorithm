//
//  io.hpp
//  Lstar
//
//  Created by Liang on 16/5/29.
//  Copyright © 2016年 Liang. All rights reserved.
//

#ifndef io_hpp
#define io_hpp

#include <iostream>
#include <vector>
#include <string>

#include "comm.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

// 读取字母集
void read_SigemaSet(vector<string> & sigemaSet);

// 读取U集合
void read_Uset(vector<string> & Uset);

// 输出状态机信息
void outputZTJ(vector<string> sSet, vector<string> fSet, vector<Sdelta> deltaSet);

// 交互判断是否正确
bool isRight();

// 输入反例
string inputCounterExample();

// 字符串转化
string strAdaptor(string str);

#endif /* io_hpp */
