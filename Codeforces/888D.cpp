#include<bits/stdc++.h>

using namespace std;

int64_t smart_f(int64_t k){
    int64_t f = 1;
    if(k==2){
        f = 1;
    }
    else if(k==3){
        f = 2;
    }
    else if(k==4){
        f = 9;
    }
    return f;
}

int64_t get_c(int64_t n, int16_t k){
    int64_t top=1, bot=1;
    for(int i=n-k+1; i<=n; ++i){
        top*=i;
    }
    for(int i=1; i<=k; ++i){
        bot*=i;
    }
    return top/bot;
}

void solve(){
    int64_t n, k, ans=0;
    cin>>n>>k;
    while(k){
        if(k==1){
            ans+=1;
        }
        else{
            ans += get_c(n, k) * smart_f(k);
        }
        --k;
    }
    cout<<ans<<'\n';
    return;
}

int main(){
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}