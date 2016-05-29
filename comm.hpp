//
//  comm.hpp
//  Lstar
//
//  Created by Liang on 16/5/29.
//  Copyright © 2016年 Liang. All rights reserved.
//

#ifndef comm_hpp
#define comm_hpp

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <map>

using std::string;
using std::vector;
using std::map;

struct Sdelta {
    string _s;
    string _a;
    string _s_1;
    
    Sdelta(string a, string b, string c) :
    _s(a), _a(b), _s_1(c) {
    }
    ;
};

// 得到str的T值
bool getT(string str, vector<string> Uset);

// 得到s*sigema
void getSdotSigemaFromSandSigema(vector<string> sigemaSet, vector<string> sSet,
                                 vector<string> & SdotSigemaSet);

// 更新S和S*sigema
void updateSandSdotSigema(string sa, vector<string> sigemaSet, vector<string> & sSet,
                          vector<string> & SdotSigemaSet);

/**
 * 求不闭合时的sa
 * 当sa==""时，表示闭合
 */
string getSa(vector<string> sSet, vector<string> sigemaSet, vector<string> eSet, vector<string> Uset);

// 生成自动机的F
void getF(vector<string> sSet, vector<string> & fSet, vector<string> Uset);

// 生成自动机的delta
void getDelta(vector<string> sSet, vector<string> SdotSigemaSet,vector<string> eSet,
              vector<string> Uset, vector<Sdelta> & deltaSet);

// 处理反例，更新E集合
// 返回false时代表处理失败
bool solveCounterExample(string strCEX, vector<string> & eSet);

// 判断str是否在list里
bool strInList(string str, vector<string> strList);

#endif /* comm_hpp */
