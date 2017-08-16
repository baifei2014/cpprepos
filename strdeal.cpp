#include<iostream>
#include<vector>
#include<string>
using namespace std;

/** 
 * 把一个字符串的大写字母放到字符串的后面，各个字符的相对位置不变，且不能申请额外的空间。
 */
void getString(vector<string> &str){
    int i, j, k, strchildlength;
    for(i = 0; i < str.size(); i++){
        strchildlength = str[i].length();
        for(j = 0; j < strchildlength; j++){
            if(65 <= int(str[i][j]) && int(str[i][j] <= 90)){
                str[i] = str[i] + str[i][j];
                str[i].erase(j, 1);
                strchildlength -= 1;
                if(j>0){
                    j -= 1;
                }
            }
        }

    }
}
void main(){
    vector<string> str;
    string str1, str2, str3;
    str1 = "hEllo,wOrld";
    str2 = "heLlo, mArs";
    str3 = "Hello, mOon";
    str.push_back(str1);
    str.push_back(str2);
    str.push_back(str3);
    getString(str);
    for(int i = 0; i< str.size(); i++){
        cout<<str[i]<<endl;
    }
}
