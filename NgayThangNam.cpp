#include "NgayThangNam.h"
#include <bits/stdc++.h>
using namespace std;
NgayThangNam::NgayThangNam(string date,vector<int> tachDate, int iNgay,int iThang,int iNam)
{
    date = "";
    tachDate = {};
    iNgay = iThang = iNam = 0;
}
//Nhap và kiểm tra tính hợp lệ
void NgayThangNam::Nhap(){
    while(true){
        tachDate.clear();
        cout << "Nhap ngay dinh dang dd/mm/yyyy : ";
        getline(cin>>ws, date);
        Tach();
        if((iNgay<1 || iNgay>31) &&(iThang<1 || iThang>12)){
            cout << "Ngay va thang khong hop le ! Moi nhap lai" << endl;
            continue;
        }
        if(iThang<1 || iThang>12){
            cout << "Thang hong hop le ! MOi nhap lai" << endl;
            continue;
        }
        if(iThang==1 ||iThang==3 ||iThang==5 ||iThang==7 ||iThang==8 ||iThang==10 ||iThang==12){
            if(iNgay<1 || iNgay>31){
                cout <<"Ngay khong hop le! Moi nhap lai"<<endl;
                continue;
            }
        }
        if(iThang==4 ||iThang==6 ||iThang==9 ||iThang==11){
            if(iNgay<1 || iNgay>30){
                cout <<"Ngay khong hop le! Moi nhap lai"<<endl;
                continue;
            }
        }
        if(iThang==2){
          if(iNam%400==0 || (iNam%4==0 && iNam%100!=0)){
            if(iNgay<1 || iNgay>29){
                cout <<"Ngay khong hop le! Moi nhap lai"<<endl;
                continue;
            }
          }
          else{
            if(iNgay<1 || iNgay>28){
                cout <<"Ngay khong hop le! Moi nhap lai"<<endl;
                continue;
            }
          }
        }
        break;
    }
}
//Tách chuỗi string đã nhập và chuyển nó thành kiểu int để dễ thao tác
void NgayThangNam::Tach(){
    stringstream s(date);
    string num;
    while(getline(s,num,'/')){
        tachDate.push_back(stoi(num)); //tachDate[0] là ngày, tachDate[1] là tháng, tachDate[2] là năm
    }
    iNgay = tachDate[0];
    iThang=tachDate[1];
    iNam=tachDate[2];
}
//Hàm tìm ngày kế tiếp khi đã hợp lệ
//Nếu ngày hiện tại chưa phải ngày cuối cùng của tháng, chỉ cần tăng ngày lên 1.
//Nếu ngày hiện tại là ngày cuối cùng của tháng, ngày = 1 và tháng tăng lên 1.
//Nếu ngày hiện tại là ngày cuối cùng của năm (31/12), đặt ngày = 1, tháng = 1 và tăng năm lên 1
void NgayThangNam::NgayThangNamTiepTheo(){
    //Tháng có 31 ngày : 1,3,5,7,8,10,12
    if(iThang==1 ||iThang==3 ||iThang==5 ||iThang==7 ||iThang==8 ||iThang==10 ||iThang==12){
        if(iNgay==31){
            iNgay=1;
            if(iThang ==12){
                iThang=1;
                iNam += 1;
            }
            else{
                iThang +=1;
            }
        }
        else{
            iNgay += 1;
        }
    }
    //Tháng có 30 ngày : 4,6,9,11
    if(iThang==4 ||iThang==6 ||iThang==9 ||iThang==11){
        if(iNgay==30){
            iNgay=1;
            iThang +=1;
        }
        else{
            iNgay+=1;
        }
    }
    //Tháng 2 : năm nhuận tháng 2 có 29 ngày, năm không nhuận tháng 2 có 28 ngày
    if(iThang==2){
        //Kiểm tra năm nhuận
        if(iNam%400==0 || (iNam%4==0 && iNam%100!=0)){
            if(iNgay==29){
                iNgay=1;
                iThang+=1;
            }
            else{
                iNgay+=1;
            }
        }
        else{
            if(iNgay==28){
                iNgay=1;
                iThang+=1;
            }
            else{
                iNgay+=1;
            }
        }
    }
}
string NgayThangNam::formatDate(){
    string ngay = (iNgay<10)?"0"+to_string(iNgay):to_string(iNgay);
    string thang = (iThang<10)?"0"+to_string(iThang):to_string(iThang);
    string nam = to_string(iNam);
    return ngay+"/"+thang+"/"+nam;
}
void NgayThangNam::Xuat(){
    //Tạo bản sao ngày hiện tại
    vector<int> temp = tachDate;
    //In ngay tiep theo
    NgayThangNamTiepTheo();
    cout << "Ngay ke tiep : " << formatDate() << endl;
}
NgayThangNam::~NgayThangNam(){}
