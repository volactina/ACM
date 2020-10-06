#include<cstdio>
#include<ext/rope>
#include<iostream>
using namespace std;
using namespace __gnu_cxx;
inline int Rin(){
  int x=0,c=getchar(),f=1;
  for(;c<48||c>57;c=getchar())
    if(!(c^45))f=-1;
  for(;c>47&&c<58;c=getchar())
    x=(x<<1)+(x<<3)+c-48;
  return x*f;
}
int n,pos,x,l;
rope<char>a,b,tmp;
char sign[10],ch[1<<22],rch[1<<22];
int main(){
  n=Rin();
  while(n--){
    scanf("%s",sign);
    switch(sign[0]){
    case'M':pos=Rin();break;
    case'P':pos--;break;
    case'N':pos++;break;
    case'G':putchar(a[pos]);putchar('\n');break;
    case'I':
      x=Rin();
      l=a.length();
      for(int i=0;i<x;i++){
    do{ch[i]=getchar();}
    while(ch[i]=='\n');
    rch[x-i-1]=ch[i];
      }
      ch[x]=rch[x]='\0';
      a.insert(pos,ch);
      b.insert(l-pos,rch);
      break;
    case'D':
      x=Rin();
      l=a.length();
      a.erase(pos,x);
      b.erase(l-pos-x,x);
      break;
    case'R':
      x=Rin();
      l=a.length();
      tmp=a.substr(pos,x);
      a=a.substr(0,pos)+b.substr(l-pos-x,x)+a.substr(pos+x,l-pos-x);
      b=b.substr(0,l-pos-x)+tmp+b.substr(l-pos,pos);
      break;
    }
  }
  return 0;
}