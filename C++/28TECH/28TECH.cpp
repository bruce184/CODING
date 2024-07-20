#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n, m, k; cin>>n>>m>>k;
        int a[500][500];
        vector<int> v;

        // Nhập ma trận vuông
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>a[i][j];
            }
        }

        int h1=0, h2=n-1;
        int c1=0, c2=m-1;
        while(h2>=h1 && c2>=c1){
            // Xây dựng dòng trên cùng
            // Chạy là chạy từ cột 0 đến cột 2
            for(int i=c1; i<=c2; i++){
                // cout<<a[h1][i]<<" ";
                v.push_back(a[h1][i]);
            }
            h1++;


            // Xây dựng cột bên phải
            // Do trước đó h1 đã tăng lên 1 (hàng chỉ số 1)
            // Nên xuất ra từ hàng chỉ số 1 trở xuống
            for(int i=h1; i<=h2; i++){
                // cout<<a[i][c2]<<" ";
                v.push_back(a[i][c2]);
            }
            c2--;


            // Do ko phải ma trận vuông, nên phải đảm bảo đk nhỏ hơn trước khi chạy
            // Nghĩa là còn dòng để chạy
            if(h1<=h2){
                for(int i=c2; i>=c1; i--){
                    // cout<<a[h2][i]<<" ";
                    v.push_back(a[h2][i]);
                }
                h2--;
            }

            if(c1<=c2){
                for(int i=h2; i>=h1; i--){
                    // cout<<a[i][c1]<<" ";
                    v.push_back(a[i][c1]);
                }
                c1++;
            }
        }
        cout<<endl;
        cout<<v[k-1]<<endl;;
    }
return 0;
}
