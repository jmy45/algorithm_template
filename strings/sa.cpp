#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
//原始板子
using namespace std;

const int N = 10;

char s[N];
int n, sa[N], rk[N << 1], oldrk[N << 1], id[N], cnt[N];
//int ht[N];
int main() {
    //O(nlogn)板子
  int i, m, p, w;

  scanf("%s", s + 1);
  n = strlen(s + 1);
  m = max(n, 300);
  for (i = 1; i <= n; ++i) ++cnt[rk[i] = s[i]];
  for (i = 1; i <= m; ++i) cnt[i] += cnt[i - 1];
  for (i = n; i >= 1; --i) sa[cnt[rk[i]]--] = i;

  for (w = 1; w < n; w <<= 1) {
    memset(cnt, 0, sizeof(cnt));
    for (i = 1; i <= n; ++i) id[i] = sa[i];
    for (i = 1; i <= n; ++i) ++cnt[rk[id[i] + w]];
    for (i = 1; i <= m; ++i) cnt[i] += cnt[i - 1];
    for (i = n; i >= 1; --i) sa[cnt[rk[id[i] + w]]--] = id[i];
    memset(cnt, 0, sizeof(cnt));
    for (i = 1; i <= n; ++i) id[i] = sa[i];
    for (i = 1; i <= n; ++i) ++cnt[rk[id[i]]];
    for (i = 1; i <= m; ++i) cnt[i] += cnt[i - 1];
    for (i = n; i >= 1; --i) sa[cnt[rk[id[i]]]--] = id[i];
    memcpy(oldrk, rk, sizeof(rk));
    for (p = 0, i = 1; i <= n; ++i) {
      if (oldrk[sa[i]] == oldrk[sa[i - 1]] &&
          oldrk[sa[i] + w] == oldrk[sa[i - 1] + w]) {
        rk[sa[i]] = p;
      } else {
        rk[sa[i]] = ++p;
      }
    }
  }

  for (i = 1; i <= n; ++i) printf("%d ", sa[i]);

/*
//求height
  for (int i = 1, k = 0; i <= n; ++i) {
        if (k) --k;
        while (s[i + k] == s[sa[rk[i] - 1] + k]) ++k;
        ht[rk[i]] = k;  
  }
  int maxid=1;
  for (int i=2;i<=n;i++)
        if (ht[i]>ht[maxid])
            maxid=i;
  return ht[maxid]==0?"":s.substr(sa[i],ht[i])*/
  return 0;
}