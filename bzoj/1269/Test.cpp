#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <ext/rope>
#include <algorithm>
using namespace std;
using __gnu_cxx::crope;
 
const int maxn = 10010;
char op[maxn];
crope text;
 
int main(){
    text.clear();
    scanf("%s",op);
    int l = strlen(op);
    for(int i = 0; i < l; i++)
        text += op[i];
    cout<<text<<endl;
 
    cout<<"test.push_back(x);//在末尾添加x"<<endl;
    text.push_back('a');
    cout<<text<<endl;
    /*
    text.push_back("bbb");
    cout<<text<<endl;//编译错误
    */
 
    cout<<"test.insert(pos,x);//在pos插入x"<<endl;
    text.insert(1,'b');
    cout<<text<<endl;
    text.insert(2,"aaa");
    cout<<text<<endl<<endl;
 
    cout<<"test.erase(pos,x);//从pos开始删除x个"<<endl;
    text.erase(1,3);
    cout<<text<<endl<<endl;
 
    cout<<"test.copy(pos,len,x);//从pos开始到pos+len为止用x代替"<<endl;
    text.copy(1,5,op);
    cout<<text<<endl<<endl;
 
    cout<<"test.replace(pos,x);//从pos开始换成x"<<endl;
    text.replace(1,'c');
    cout<<text<<endl;
    text.replace(1,"ccc");
    cout<<text<<endl<<endl<<endl;
 
    cout<<"test.substr(pos,x);//提取pos开始x个"<<endl;
    //text = text.substr(2);这样默认为提取一个
    cout<<text.substr(2)<<endl;
    cout<<text.substr(2,3)<<endl<<endl;
 
    cout<<"test.at(x)/[x];//访问第x个元素"<<endl;
    cout<<text.at(4)<<endl<<endl;
}
