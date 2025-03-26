//Bài 4: Lập chương trình tính Sin(x) với độ chính xác 0.00001 theo công thức
//Tại sao không thể xử lý trường hợp -6.532, cách sửa
/*
Input:  2
Output: sin(2) = 0.909297
Input: -3
Output: sin(-3) = -0.14112
Input: 2.8
Output: sin(2.8) = 0.334988
*/

#include<bits/stdc++.h>
using namespace std;
class SinX{
private:
    double x;
public:
    void KhoiTao(double x){
        this->x=x;
    }
    void Nhap(){
        cin >> x;
    }
    double giaiThua(long long n){
        long long result = 1;
        for(long long i = 1; i <= n; i++){
            result *= i;
        }
        return result;
    }
    double Taylor(double x){
        double sin = 0;
        long long n = 0;
        while(x ){
            double gT = giaiThua(2*n+1);
            double phepTinh = (pow(-1, n)*pow(x, 2*n+1))/gT;
            sin += phepTinh;
            if(fabs(phepTinh) < 0.00001) break;
            n++;
        }
        return sin;
    }
    void Xuat(){
        cout << "sin("<<x<<")"<<" = "<<Taylor(x) << endl;
    }
};
int main()
{
    SinX x;
    x.Nhap();
    x.Xuat();
    return 0;
}
