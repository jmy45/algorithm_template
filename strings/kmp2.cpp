//非标
#include<bits/stdc++.h>
using namespace std;
int main(){
    //s for source
    string s="abccbabbacba";
    //p for pattern
    string p="ba";
    //construct prefix table
    int M=s.size();
    int N=p.size();
    int pre[N];
    //len==j
    int j=0;
    int i=1;
    while (i<N){
        if (p[i]==p[j]){
            j++;
            pre[i]=j;
            i++;
        }
        else{
            if (j)
                j=pre[j-1];
            else{
                pre[i]=0;
                i++;
            }
        }
    }
    for (i=N-1;i;i--)
        pre[i]=pre[i-1];
    pre[0]=-1;
    i=0;
    j=0;
    while (i<M){
        if (j==N-1&&s[i]==p[j]){
            cout<<"Found at:"<<i-j<<endl;
            j=pre[j];
        }
        if (s[i]==p[j]){
            i++;
            j++;
        }
        else{
            j=pre[j];
            if (j==-1){
                i++;j++;
            }
        }
    }
    return 0;
}