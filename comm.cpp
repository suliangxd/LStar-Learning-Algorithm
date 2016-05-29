//
//  comm.cpp
//  Lstar
//
//  Created by Liang on 16/5/29.
//  Copyright © 2016年 Liang. All rights reserved.
//

#include "comm.hpp"

bool getT(std::string str, std::vector<std::string> Uset) {
//    if (str == "")
//        return false;
//    
    for (auto uStr : Uset) {
        if (uStr == str) {
            return true;
        }
    }
    return false;
}

// 得到s*sigema
void getSdotSigemaFromSandSigema(vector<string> sigemaSet, vector<string> sSet,
                                 vector<string> & SdotSigemaSet) {
    // 当S为空时
    if (sSet.size() == 0) {
        for (auto s : sigemaSet) {
            SdotSigemaSet.push_back(s);
        }
    } else {
        for (auto s_sSet : sSet) {
            for (auto s_sigemaSet : sigemaSet) {
                SdotSigemaSet.push_back(s_sSet + s_sigemaSet);
            }
        }
    }
}

// 更新S和S*sigema
void updateSandSdotSigema(string sa, vector<string> sigemaSet,
                          vector<string> & sSet, vector<string> & SdotSigemaSet) {
    // 将sa放入S集合
    sSet.push_back(sa);
    // 更新SdotSigemaSet
    for (auto s_sigemaSet : sigemaSet) {
        SdotSigemaSet.push_back(sa + s_sigemaSet);
    }
}

string getSa(vector<string> sSet, vector<string> sigemaSet, vector<string> eSet, vector<string> Uset) {
    string sae = "";
    if (eSet.size() == 0) {
        // sSet和eSet为空
        if (sSet.size() == 0) {
            for (auto a_sigemaSet : sigemaSet) {
                string s0 = a_sigemaSet;
                string s1 = "";
                if (getT(s0, Uset) != getT(s1, Uset)) {
                    sae = s0;
                    goto over;
                }
            }
        } else {
            // eSet为空， sSet不为空
            for (auto s1_sSet : sSet) {
                string s1 = s1_sSet;
                for (auto s_sSet : sSet) {
                    for (auto a_sigemaSet : sigemaSet) {
                        string s0 = s_sSet + a_sigemaSet;
                        if (getT(s0, Uset) != getT(s1, Uset)) {
                            sae = s_sSet + a_sigemaSet;
                            goto over;
                        }
                    }
                }
            }
        }
    }
    else {
        if (sSet.size() == 0) {
            // sSet为空, eSet不为空
            for (auto a_sigemaSet : sigemaSet) {
                for (auto e_sSet : eSet) {
                    string s0 = a_sigemaSet + e_sSet;
                    string s1 = e_sSet;
                    if (getT(s0, Uset) != getT(s1, Uset)) {
                        sae = a_sigemaSet;
                        goto over;
                    }
                }
            }
            
        } else {
            for (auto s1_sSet : sSet){
                for (auto s_sSet : sSet) {
                    for (auto a_sigemaSet : sigemaSet) {
                        for (auto e_sSet : eSet) {
                            string s0 = s_sSet + a_sigemaSet + e_sSet;
                            string s1 = s1_sSet + e_sSet;
                            if (getT(s0, Uset) != getT(s1, Uset)) {
                                sae = s_sSet + a_sigemaSet;
                                goto over;
                            }
                        }
                    }
                }
            }

        }
    }

over:
    return sae;
}

void getF(vector<string> sSet, vector<string> & fSet, vector<string> Uset) {
    fSet.clear();
    for (auto s : sSet) {
        if (getT(s, Uset) == true) {
            fSet.push_back(s);
        }
    }
}

void getDelta(vector<string> sSet, vector<string> SdotSigemaSet,vector<string> eSet,
              vector<string> Uset, vector<Sdelta> & deltaSet) {
    
    deltaSet.clear();
    for(auto sa : SdotSigemaSet) {
        for (auto s_1 : sSet) {
            bool ok = true;
            for (auto e : eSet) {
                if (getT(sa+e, Uset) != getT(s_1+e, Uset)) {
                    ok = false;
                    break;
                }
            }
            if (ok == true) {
                int len = sa.length();
                string _s = sa.substr(0, len - 1);
                string _a = sa.substr(len - 1, 1);
                Sdelta sdelta(_s, _a, s_1);
                deltaSet.push_back(sdelta);
            }
        }
    }
}

bool solveCounterExample(string strCEX, vector<string> & eSet) {
    bool ret = true;
    int sublen = 1;
    string str_e = "";
    for (int index = strCEX.length() - 1; index >= 0; index--, sublen++) {
        str_e = strCEX.substr(index, sublen);
        
        if (strInList(str_e, eSet) == false) {
            eSet.push_back(str_e);
        }
    }
    if (str_e == "") {
        return false;
    } else {
        return true;
    }
}

bool strInList(string str, vector<string> strList) {
    for (auto strFromList : strList) {
        if (str == strFromList) {
            return true;
        }
    }
    return false;
}

