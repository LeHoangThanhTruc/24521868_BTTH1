//Bài tập 5: Viết chương trình nhập vào một ngày.
//- Tìm ngày kế tiếp và xuất kết quả.
//- Tìm ngày trước ngày này và xuất kết quả.
//- Tính xem ngày đó là ngày thứ bao nhiêu trong năm và xuất kết quả.

/* Mẫu Input và Output
Moi nhap ngay dang dd/mm/yyyy : 25/10/2025
Ngay ke tiep: 26/10/2025
Ngay truoc ngay do : 24/10/2025
Ngay do la ngay thu 298 trong nam.

Moi nhap ngay dang dd/mm/yyyy : 29/2/2025
NGAY KHONG HOP LE, MOI NHAP LAI :
Moi nhap ngay dang dd/mm/yyyy : 1/3/2025
Ngay ke tiep: 02/03/2025
Ngay truoc ngay do : 28/02/2025
Ngay do la ngay thu 60 trong nam.

Moi nhap ngay dang dd/mm/yyyy : 31/12/2022
Ngay ke tiep: 01/01/2023
Ngay truoc ngay do : 30/12/2022
Ngay do la ngay thu 365 trong nam.

Moi nhap ngay dang dd/mm/yyyy : 30/2/2027
NGAY KHONG HOP LE, MOI NHAP LAI :
Moi nhap ngay dang dd/mm/yyyy : 29/2/2026
NGAY KHONG HOP LE, MOI NHAP LAI :
Moi nhap ngay dang dd/mm/yyyy : 29/2/2024
Ngay ke tiep: 01/03/2024
Ngay truoc ngay do : 28/02/2024
Ngay do la ngay thu 60 trong nam.

Moi nhap ngay dang dd/mm/yyyy : 1/9/2025
Ngay ke tiep: 02/09/2025
Ngay truoc ngay do : 31/08/2025
Ngay do la ngay thu 244 trong nam.

Moi nhap ngay dang dd/mm/yyyy : 1/7/2025
Ngay ke tiep: 02/07/2025
Ngay truoc ngay do : 30/06/2025
Ngay do la ngay thu 182 trong nam.
*/

#include<iostream>
#include<sstream>
#include<vector>
using namespace std;
class Next{
private:
    string date;
    vector<int> PartsOfDate;
public:
    void Thietlap(string date, vector<int> PartsOfDate){
        this->date = date;
        this->PartsOfDate = PartsOfDate;
    }
    //Hàm nhập và kiểm tra tinh hop le
    void Nhap(){
      //Phải ghi nhớ để lần sau không sai nữa : dùng vòng lặp vô hạn while(true){}, kiểm tra tính hợp lệ ngay khi nhập và
      //dùng kết hợp continue, break sẽ tránh được lỗi stack overflow thay vì phải gọi hàm Nhap() nhiều lần gây tràn bộ nhớ và sinh ra lỗi.
      while (true){
        //Xóa dữ liệu cũ trước khi nhập cái mới
        PartsOfDate.clear();

        //Nhập dữ liệu
        cout << "Moi nhap ngay dang dd/mm/yyyy : ";
        getline(cin >> ws, date);
        Tach();

        //Kiểm tra tính hợp lệ
        if((PartsOfDate[0] < 1 || PartsOfDate[0] > 31) && (PartsOfDate[1]<1 || PartsOfDate[1]>12)){
            cout << "NGAY VA THANG KHONG HOP LE, MOI NHAP LAI : " << endl;
            continue;
        }
        if (PartsOfDate[1]<1 || PartsOfDate[1]>12){
            cout << "THANG KHONG HOP LE, MOI NHAP LAI : " << endl;
            continue;
        }
        if (PartsOfDate[1]==2){
            if(PartsOfDate[2]%400==0 || (PartsOfDate[2]%4==0 && PartsOfDate[2]%100 != 0)){
                if (PartsOfDate[0] < 1 || PartsOfDate[0] >29) {
                    cout << "NGAY KHONG HOP LE, MOI NHAP LAI : " << endl;
                    continue;
                }
            }
            else{
                if (PartsOfDate[0] < 1 || PartsOfDate[0] >28) {
                    cout << "NGAY KHONG HOP LE, MOI NHAP LAI : " << endl;
                    continue;
                }
            }
        }
        if (PartsOfDate[1] == 1 || PartsOfDate[1] == 3 || PartsOfDate[1] == 5 || PartsOfDate[1] == 7 || PartsOfDate[1] == 8 || PartsOfDate[1] == 10 || PartsOfDate[1] == 12){
            if(PartsOfDate[0] < 1 || PartsOfDate[0] > 31){
                cout << "NGAY KHONG HOP LE, MOI NHAP LAI : " << endl;
                continue;
            }
        }
        if(PartsOfDate[1] == 4 || PartsOfDate[1] == 6 || PartsOfDate[1] == 9 || PartsOfDate[1] == 11){
            if(PartsOfDate[0] < 1 || PartsOfDate[0] > 30){
                cout << "NGAY KHONG HOP LE, MOI NHAP LAI : " << endl;
                continue;
            }
        }

        //Nếu hợp lệ sẽ thoát vòng lặp
        break;
      }
    }

    //Tách thành ngày, tháng năm riêng biệt để dễ thao tác
    void Tach(){
        string s = date;
        stringstream ss(s);
        string num;
        while (getline(ss,num,'/')){
             PartsOfDate.push_back(stoi(num));  //=>PartsOfDate[0] là ngày, PartsOfDate[1] là tháng, PartsOfDate[2] là năm
        }
    }

    //Hàm tìm ngày kế tiếp khi đã hợp lệ
    //Nếu ngày hiện tại chưa phải ngày cuối cùng của tháng, chỉ cần tăng ngày lên 1.
    //Nếu ngày hiện tại là ngày cuối cùng của tháng, ngày = 1 và tháng tăng lên 1.
    //Nếu ngày hiện tại là ngày cuối cùng của năm (31/12), đặt ngày = 1, tháng = 1 và tăng năm lên 1
    void KTNextDay(){
        //Tháng có 31 ngày : 1,3,5,7,8,10,12
        if (PartsOfDate[1] == 1 || PartsOfDate[1] == 3 || PartsOfDate[1] == 5 || PartsOfDate[1] == 7 || PartsOfDate[1] == 8 || PartsOfDate[1] == 10 || PartsOfDate[1] == 12){
            if (PartsOfDate[0]==31){
                PartsOfDate[0]=1;
                if(PartsOfDate[1]==12){
                    PartsOfDate[1] =1;
                    PartsOfDate[2] += 1;
                    }
                else if(PartsOfDate[1]>=1 && PartsOfDate[1]<12){
                        PartsOfDate[1] += 1;
                        }
            }
            else if(PartsOfDate[0]>=1 && PartsOfDate[0]<31){
                    PartsOfDate[0] += 1;
                    }
        }
        //Tháng có 30 ngày : 4,6,9,11
        else if(PartsOfDate[1] == 4 || PartsOfDate[1] == 6 || PartsOfDate[1] == 9 || PartsOfDate[1] == 11){
           if (PartsOfDate[0]==30){
               PartsOfDate[0]=1;
               PartsOfDate[1] += 1;
            }
           else if (PartsOfDate[0]>=1 && PartsOfDate[0]<30){
                PartsOfDate[0] += 1;
                }
        }
        //Tháng 2 : năm nhuận tháng 2 có 29 ngày, năm không nhuận tháng 2 có 28 ngày
        else if (PartsOfDate[1]==2) {
            //Kiểm tra năm nhuận
            if(PartsOfDate[2]%400==0 || (PartsOfDate[2]%4==0 && PartsOfDate[2]%100 != 0)){
                if (PartsOfDate[0]==29){
                    PartsOfDate[0]=1;
                    PartsOfDate[1] += 1;
                    }
                else if (PartsOfDate[0]>=1 && PartsOfDate[0]<29){
                        PartsOfDate[0] += 1;
                        }
            }
            //Kiểm tra năm không nhuận
            else {
                if (PartsOfDate[0]==28) {
                    PartsOfDate[0]=1;
                    PartsOfDate[1] += 1;
                }
                else if(PartsOfDate[0]>=1 && PartsOfDate[0]<28){
                        PartsOfDate[0] += 1;
                        }
            }

        }
    }
    int KTNamNhuan(int year){
         if(year%400==0 || (year%4==0 && year%100 != 0))return 29;
         return 28;
    }
    void KTPreviousDate(){
        //Tháng có ngày cuối của tháng trước đó là ngày 31
       if(PartsOfDate[1] == 1 || PartsOfDate[1] == 8 || PartsOfDate[1] == 2 ||PartsOfDate[1] == 4 || PartsOfDate[1] == 6 || PartsOfDate[1] == 9 || PartsOfDate[1] == 11){
            if(PartsOfDate[0]==1 && PartsOfDate[1]==1){
                PartsOfDate[0] =31;
                PartsOfDate[1] = 12;
                PartsOfDate[2] --;
            }
            else if(PartsOfDate[0]==1){
                PartsOfDate[0]=31;
                PartsOfDate[1]--;
            }
            else PartsOfDate[0]--;
       }
       //Tháng có ngày cuối của tháng trước đó là ngày 30
       else if(PartsOfDate[1] == 5 || PartsOfDate[1] == 7 || PartsOfDate[1] == 10 || PartsOfDate[1] == 12){
           if(PartsOfDate[0]==1){
                PartsOfDate[0]=30;
                PartsOfDate[1]--;
           }
           else PartsOfDate[0]--;
      }
      //Tháng có ngày cuối của tháng trước đó là ngày 28 hoặc 29 (tùy theo năm không nhuận hoặc nhuận)
      else if(PartsOfDate[1] == 3){
           int x;
           x=KTNamNhuan(PartsOfDate[2]);
           if(PartsOfDate[0]==1){
              if(x==29){
                PartsOfDate[0]=29;
                PartsOfDate[1]=2;
              }
              else if(x==28){
                PartsOfDate[0]=28;
                PartsOfDate[1]=2;
              }
           }
          else {PartsOfDate[0]--;}
      }
    }
    //Tính xem ngày đó là ngày thứ bao nhiêu trong năm và xuất kết quả.
    int sttDayInYear(){
        //Khởi tạo danh sách ngày của các tháng của năm không nhuận
        vector<int> month1 ={31,28,31,30,31,30,31,31,30,31,30,31};
         //Khởi tạo danh sách ngày của các tháng của năm nhuận
        vector<int> month2 ={31,29,31,30,31,30,31,31,30,31,30,31};
        int y;
        y = KTNamNhuan(PartsOfDate[2]);
        int tong = 0;
        //Đối với năm không nhuận
        if(y==28){
            for (int i = 0; i < (PartsOfDate[1]-1); i++){
                tong += month1[i];
            }
            return tong = tong + PartsOfDate[0];
        }
        //Đối với năm nhuận
        if(y==29){
            for (int i = 0; i < (PartsOfDate[1]-1); i++){
                tong += month2[i];
            }
            return tong = tong + PartsOfDate[0];
        }
    }

    //Định dạng Date đầu ra dạng dd/mm/yyyy
    string formatDate(){
        string day = (PartsOfDate[0]<10) ? "0"+to_string(PartsOfDate[0]) : to_string(PartsOfDate[0]);
        string month = (PartsOfDate[1]<10) ? "0"+to_string(PartsOfDate[1]) : to_string(PartsOfDate[1]);
        string year = to_string(PartsOfDate[2]);
        return day + "/"+month+"/"+year;
    }

    //Hàm xuất
    void Xuat(){
        //Tạo bản sao ngày hiện tại
        vector<int> temp =PartsOfDate;

        //In ngày kế tiếp
        KTNextDay();
        cout << "Ngay ke tiep: " << formatDate() <<endl;

        //Khôi phục ngày ban đầu
        PartsOfDate = temp;

        //In ngày trước đó
        KTPreviousDate();
        cout << "Ngay truoc ngay do : " << formatDate() <<endl;

        //Khôi phục ngày ban đầu
        PartsOfDate = temp;

        //In số thứ tự của ngày trong năm
        cout <<  "Ngay do la ngay thu " << sttDayInYear() << " trong nam." <<endl;
    }
};
int main()
{
    Next day;
    day.Nhap();
    day.Xuat();
    return 0;
}
