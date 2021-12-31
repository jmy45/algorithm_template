#include<bits/stdc++.h>
using namespace std;
int main(){
    //s for source
    string s="#babababab";
    //p for pattern
    string p="#abab";
    int M=s.size()-1;
    int N=p.size()-1;
    int next[N+1];
    int j=0;
    next[1]=0;
    for (int i=2;i<=N;i++){
        while (j&&p[j+1]!=p[i])
            j=next[j];
        if (p[j+1]==p[i])
            j++;
        next[i]=j;
    }
    j=0;
    for (int i=1;i<=M;i++){
        while (j&&p[j+1]!=s[i])
            j=next[j];
        if (p[j+1]==s[i])
            j++;
        if (j==N){
            cout<<"Found at:"<<i-N+1<<endl;
            j=next[j];
        }
    }
    return 0;
}