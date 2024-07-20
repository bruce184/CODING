#include <bits/stdc++.h>
#include <algorithm>

using namespace std;


int main(){
// Upper_bound(iter1, iter2, key)
// tìm trong khoảng [iter1, iter2) => Trả về vị trí đầu tiên của phần tử LỚN HƠN key
// Nếu tất cả phần tử trong mảng đều <= key => Trả về iter2
    int n, x;
    cin>>n>>x;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    auto it = upper_bound(a, a+n, x);
    cout<<*it<<endl;
    cout<<distance(a, it)<<endl;
    if(it == a+n){
        cout<<"Khong co phan tu lon hon "<<x<<endl;
    }



















return 0;
}
