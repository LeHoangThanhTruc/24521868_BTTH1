//Bài tập 1: Viết chương trình nhập vào một phân số, rút gọn phân số và xuất kết quả.
//(Bởi vì trong đề bài không để cụ thể là nhập tử số và mẫu số theo kiểu dữ liệu nào
//và có cần thiết xử lí trường hợp mẫu số bằng 0 hay không
//nên em sẽ cố gắng xử lí tất cả các trường hợp mà em có thể nghĩ đến,
//nếu có gì sai xót mong thầy thông cảm). Em xin cảm ơn rất nhiếu!

/* Các mẫu Input và Output
Nhap tu so va mau so theo dang a/b : 1/0
WARNING : MAU SO KHONG THE BANG 0, MOI NHAP LAI:
Nhap tu so va mau so theo dang a/b : 2/0
WARNING : MAU SO KHONG THE BANG 0, MOI NHAP LAI:
Nhap tu so va mau so theo dang a/b : 2.6/3
Phan so da rut gon la : 13/15

Nhap tu so va mau so theo dang a/b : 3/2.5
Phan so da rut gon la : 6/5

Nhap tu so va mau so theo dang a/b : 2.3/5.8
Phan so da rut gon la : 23/58

Nhap tu so va mau so theo dang a/b : -2.8/-5.6
Phan so da rut gon la : 1/2

Nhap tu so va mau so theo dang a/b : 40/7
Phan so da rut gon la : 40/7

Nhap tu so va mau so theo dang a/b : 68/22
Phan so da rut gon la : 34/11

Nhap tu so va mau so theo dang a/b : 2/2
Phan so da rut gon la : 1/1

Nhap tu so va mau so theo dang a/b : 22/-12
Phan so da rut gon la : -11/6

Nhap tu so va mau so theo dang a/b : 234567/890652
Phan so da rut gon la : 78189/296884

Nhap tu so va mau so theo dang a/b : 2.56789101112/1.123456789011
Phan so da rut gon la : 2.56789e+06/1.12346e+06            //Đối với số mà phần thập phân có nhiều số em chỉ có thể làm thành số xấp xỉ thôi ạ

Nhap tu so va mau so theo dang a/b : 12345678910/1987654321
Phan so da rut gon la : 1.23457e+10/1.98765e+09       //Tương tự như cái trên, đối với số quá lớn, em cũng chỉ làm được số xấp xỉ thôi ạ

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
        cout << "Nhap tu so va mau so theo dang a/b : ";
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
    // Hàm tìm ước chung lớn nhất để lát nữa rút gọn
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
             mausoNguyen = round(mausoNguyen); //Mẫu số quá lớn cần làm tròn để có thể lấy số gần nhất, tránh tràn số, mặc dù sẽ có sai số nhỏ,
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
};

int main()
{
    PhanSo a;   //Khai báo đối tượng phân số a
    a.Nhap();  //Gọi hàm nhập để nhập phân số a
    a.Rutgon(); //Gọi hàm Rutgon để rút gọn phân số a, không cần gọi hàm UCLN vì trong hàm Rutgon đã gọi hàm UCLN
    cout << "Phan so da rut gon la : ";
    a.Xuat();   //Goi hàm Xuat để in ra màn hình phân số a đã rút gọn
    return 0;
}
