//Bài tập 3: Viết chương trình nhập vào hai phân số. Tính tổng, hiệu, tích, thương giữa
//chúng và xuất kết quả.
/*Mẫu Input và Output
Nhap phan so thu 1 dang a/b : 1/2
Nhap phan so thu 2 dang a/b : 2/3
Phep cong : 7/6
Phep tru : 1/-6
Phep nhan : 1/3
Phep chia : 3/4

Nhap phan so thu 1 dang a/b : -2/9
Nhap phan so thu 2 dang a/b : 6/-3.5
Phep cong : -122/63
Phep tru : 94/63
Phep nhan : 8/21
Phep chia : 7/54

*/

#include <iostream>
#include<cmath>
using namespace std;
class PhanSo{
private:
    double tuso, mauso;  //Khai báo tử số và mẫu số
public:
    //Hàm khởi tạo tử số và mẫu số, khi mình tạo tử số và mẫu số nó sẽ tự động được gọi
    void Thietlap(double tuso, double mauso){
        this->tuso = tuso;
        this->mauso = mauso;
    }
    // Hàm nhập
    void Nhap(){
        //Tạo vòng lặp vô hạn để khi nào nhập đúng thì mới thực hiện các hàm khác.
        while(true){
        char dauxec;  //'/'
        cin >> tuso >> dauxec >> mauso;  //Nhập phân số dạng a/b , giả sử ta nhập 40/7
        //Mẫu số không thể bằng 0 nên cần nhập lại đến khi nào đúng thì thôi
        if(mauso == 0){
            cout << "WARNING : MAU SO KHONG THE BANG 0, MOI NHAP LAI: " << endl;
            continue;   //Bỏ qua các lệnh bên dưới
        }
        break;  //Thoát khỏi vòng lặp khi đã nhập phân số đúng quy tắt (mẫu số không được bằng 0)
        }
    }
    //Hàm xuất ra màn hình, hiển thị phân số đã rút gọn
    void Xuat(){
        cout << tuso << "/" << mauso <<endl;     //In ra phân số đã rút gọn là  40/7
    }
    //Hàm tìm ước chung lớn nhất để lát nữa rút gọn
    //Đầu vào 2 số nguyên a và b
    //Đầu ra là ước chung lớn nhất của a và b
    long long UCLN(long long a, long long b){  //VD: Tìm UCLN(40,7)
        if(b==0) return a;     // Do 2%1=0 nên rả về UCLN là 1
        return UCLN(b,a%b);  //lần 1: (7,40%7=5), lần 2(5,7%5=2), lần 3 (2,5%2=1)->lần 4 (1,2%1=0)
    }
    //Hàm rút gọn phân số đã nhập
    //Rút gọn bằng cách chia cả tử và mẫu cho ước chung lớn nhất đã tìm ở hàm UCLN
    void Rutgon(){
        int ucln;
        //Nếu tử số và mẫu số đều là số thập phân
        //hoặc tử số đã nhập là số thập phân, mẫu số đã nhập là số nguyên
        //hoặc tử số đã nhập là số nguyên, mẫu số đã nhập là số thập phân
        //thì ta cần chuyển tử số và mẫu số thành số nguyên rồi mới rút gọn được
        long long e = tuso;
        long long f = floor(mauso);
        long long g = ceil(mauso);
        // Dùng cách này ta có thể xử lý trường hợp tử số và mẫu số đã nhập là số nguyên nhưng có giá trị khác nhau
        // và cả trường hợp tử số hoặc mẫu số hoặc cả tử số và mẫu số là số thập phân
        if(e != f || e!=g){
             long long tusoNguyen = tuso*pow(10,6);   //Chuyển tử sô thành số nguyên
             tusoNguyen = round(tusoNguyen); //Tử số quá lớn cần làm tròn để lấy số gần nhất, tránh tràn số, mặc dù sẽ có sai số nhỏ
             long long mausoNguyen = mauso*pow(10,6);  //Chuyển mẫu số thành số nguyên
             mausoNguyen = round(mausoNguyen) ;//Mẫu số quá lớn cần làm tròn để có thể lấy số gần nhất, tránh tràn số, mặc dù sẽ có sai số nhỏ,
             ucln = UCLN(tusoNguyen,mausoNguyen);  //Tìm ước chung lớn nhất của tử số nguyên và mẫu số nguyên
             //Lấy tử số và mẫu số đã chuyển thành số nguyên chia cho ước chung lớn nhất để tìm phân số rút gọn
             tuso = tusoNguyen/ucln;
             mauso = mausoNguyen/ucln;
        }
       //Trường hợp tử số và mẫu số đã nhập là số nguyên và có giá trị bằng nhau
        else{
        ucln = UCLN(tuso, mauso); //Ví dụ truyền tuso = 40 và mauso = 7 vào hàm UCLN
        tuso = tuso/ucln;   //Giả sử ta rút gọn phân số 40/7, tử số = 40/1
        mauso = mauso/ucln;                                //mẫu số = 7/1
        }
    }
    //Phép cộng 2 phân số
    PhanSo operator+(PhanSo v){
        PhanSo res;
        res.tuso = tuso*v.mauso + v.tuso*mauso;
        res.mauso = mauso*v.mauso;
        res.Rutgon();
        return res;
    }
    //Phép trừ 2 phân số
    PhanSo operator-(PhanSo v){
        PhanSo res;
        res.tuso = tuso*v.mauso - v.tuso*mauso;
        res.mauso = mauso*v.mauso;
        res.Rutgon();
        return res;
    }
    //Phép nhân 2 phân số
    PhanSo operator*(PhanSo v){
        PhanSo res;
        res.tuso = tuso*v.tuso;
        res.mauso = mauso*v.mauso;
        res.Rutgon();
        return res;
    }
    //Phép chia 2 phân số
    PhanSo operator/(PhanSo v){
        PhanSo res;
        res.tuso = tuso*v.mauso;
        res.mauso = mauso*v.tuso;
        res.Rutgon();
        return res;
    }
};

int main()
{
    PhanSo a, b;
    cout << "Nhap phan so thu 1 dang a/b : ";
    a.Nhap();
    cout << "Nhap phan so thu 2 dang a/b : ";
    b.Nhap();
    PhanSo c1 = a+b;
    cout << "Phep cong : ";
    c1.Xuat();
    PhanSo c2 = a-b;
    cout << "Phep tru : ";
    c2.Xuat();
    PhanSo c3 = a*b;
    cout << "Phep nhan : ";
    c3.Xuat();
    PhanSo c4 = a/b;
    cout << "Phep chia : ";
    c4.Xuat();
    return 0;
}
