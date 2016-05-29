//
//  main.cpp
//  Lstar
//
//  Created by Liang on 16/5/29.
//  Copyright © 2016年 Liang. All rights reserved.
//


#include <iostream>

#include "comm.hpp"
#include "io.hpp"

using namespace std;

vector<string> Uset;
vector<string> sigemaSet;
vector<string> sSet;
vector<string> SdotSigemaSet;
vector<string> eSet;
vector<string> fSet;
vector<Sdelta> deltaSet;

void init() {
    Uset.clear();
    sigemaSet.clear();
    sSet.clear();
    SdotSigemaSet.clear();
    eSet.clear();
    fSet.clear();
    deltaSet.clear();
    
    Uset.push_back("");
    eSet.push_back("");
    sSet.push_back("");
}

void LstarAlg() {
    init();
    read_SigemaSet(sigemaSet);
    read_Uset(Uset);
    
    /********************     实现     ********************/
    
    // 生成观察表
    getSdotSigemaFromSandSigema(sigemaSet, sSet, SdotSigemaSet);
    
    while (1) {
        
        string sa = getSa(sSet, sigemaSet, eSet, Uset);
        // 判定是否闭合
        while (sa != "") {
            if (strInList(sa, sSet))
                break;
            
            updateSandSdotSigema(sa, sigemaSet, sSet, SdotSigemaSet);
            sa = getSa(sSet, sigemaSet, eSet, Uset);
        }
        
        /****************   表闭合   ****************/
        getF(sSet, fSet, Uset);
        getDelta(sSet, SdotSigemaSet, eSet, Uset, deltaSet);
        outputZTJ(sSet, fSet, deltaSet);
        
        /****************  自动机判定  ****************/
        bool isright = isRight();
        if (isright == true) {
            puts("程序结束.");
            break;
        } else {
            string counterExample = inputCounterExample();
            bool ret = solveCounterExample(counterExample, eSet);
            if (ret == false) {
                puts("反例加入失败, 程序结束.");
                break;
            } else {
                puts("反例加入成功, 继续执行.");
            }
        }
    }
}

int main(int argc, char **argv) {
    LstarAlg();
    return 0;
}