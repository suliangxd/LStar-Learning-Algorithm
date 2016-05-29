//
//  io.cpp
//  Lstar
//
//  Created by Liang on 16/5/29.
//  Copyright © 2016年 Liang. All rights reserved.
//

#include "io.hpp"

void read_SigemaSet(vector<string> & sigemaSet) {
    puts("输入sigema集合，以\"end\"结束.");
    string str;
    while(cin >> str) {
        if (str == "end") {
            puts("字母集构造完毕...");
            break;
        } else {
            sigemaSet.push_back(str);
        }
    }
    cout << endl;
}

void read_Uset(vector<string> & Uset) {
    puts("输入U集合，以\"end\"结束.");
    string str;
    while(cin >> str) {
        if (str == "end") {
            puts("U集合构造完毕...");
            break;
        } else {
            Uset.push_back(str);
        }
    }
    cout << endl;
}

void outputZTJ(vector<string> sSet, vector<string> fSet, vector<Sdelta> deltaSet) {
    puts("S[状态]集合: ");
    for (auto s : sSet) {
        cout << strAdaptor(s) << " ";
    }
    cout << endl;
    puts("F[终态]集合: ");
    for (auto str : fSet) {
        cout << strAdaptor(str) << " ";
    }
    cout << endl;
    puts("delta[转移]集合: ");
    for (auto sdelta : deltaSet) {
        cout << "( " << strAdaptor(sdelta._s) << " , " << strAdaptor(sdelta._a) << " )" << " = " << strAdaptor(sdelta._s_1) << endl;
    }
}

bool isRight() {
    puts("自动机是否正确, y/n");
    string str;
    while(cin >> str) {
        if (str == "y") {
            return true;
        } else if (str == "n") {
            return false;
        } else {
            puts("输入不合法, 重新输入.");
        }
    }
    return true;
}

string inputCounterExample() {
    puts("请输入反例: ");
    string str;
    cin >> str;
    return str;
}

// 字符串转化
string strAdaptor(string str) {
    if (str == "")
        return "ϵ";
    return str;
}
