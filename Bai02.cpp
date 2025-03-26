//Bài tập 2: Viết chương trình nhập vào hai phân số, tìm phân số lớn nhất và xuất kết quả.

/* Các mẫu Input và Output
Nhap phan so thu 1 dang a/b : 1/2
Nhap Phan so thu 2 dang a/b : 3/4
Phan so lon nhat la : 3/4

Nhap phan so thu 1 dang a/b : 1.5/6.875
Nhap Phan so thu 2 dang a/b : 9/89
Phan so lon nhat la : 1.5/6.875
*/

#include <iostream>
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

    //Tìm phân số lớn nhất dựa theo giá trị thực
    double PSLonNhat(PhanSo b){
        double giaTriPS1 = tuso/mauso; //Tính giá trị tử số chia mẫu số của phân số thứ nhất
        double giaTriPS2 =b.tuso/b.mauso;  //Tính giá trị tử số chia mẫu số của phân số thứ hai
        //Nếu giá trị phân số thứ nhất lớn hơn giá trị phân số thứ hai là đúng thì PSMax = phân số thứ nhất, nếu không thì PSMax = phân số thứ hai
        double PSMax = (giaTriPS1>giaTriPS2)?giaTriPS1:giaTriPS2;
        //Nếu PSMax = phân số thứ nhất thì in ra màn hình phân số thứ nhất, nếu không in ra màn hình phàn phân số thứ hai
        if(PSMax==giaTriPS1) cout << tuso << "/" << mauso << endl;
        else cout << b.tuso << "/" << b.mauso << endl;
    }
};

int main()
{
    PhanSo a, b;   //Khai báo đối tượng phân số a, b;
    cout << "Nhap phan so thu 1 dang a/b : ";
    a.Nhap();  //Gọi hàm nhập để nhập phân số a
    cout << "Nhap Phan so thu 2 dang a/b : ";
    b.Nhap();  ////Gọi hàm nhập để nhập phân số b
    cout << "Phan so lon nhat la : ";
    a.PSLonNhat(b);  //So sánh phân số a và b và đưa ra phân số lớn nhất
    return 0;
}
