/*
Bài tập 7: Hãy xây dựng một chương trình quản lý thông tin chuyến bay. Mỗi chuyến
bay bao gồm các thông tin sau:
- Mã chuyến bay: Chuỗi ký tự dài tối đa 5 ký tự, không được chứa khoảng trắng
hay ký tự đặc biệt.
- Ngày bay: Dữ liệu ngày khởi hành, yêu cầu kiểm tra tính hợp lệ của ngày nhập
(ngày phải tồn tại và hợp lệ theo lịch).
- Giờ bay: Dữ liệu giờ khởi hành, được nhập theo định dạng 24 giờ (từ 00:00 đến
23:59).
- Nơi đi: Chuỗi ký tự dài tối đa 20 ký tự. Phải là tên địa danh hợp lệ, không được
chứa số hoặc ký tự đặc biệt.
- Nơi đến: Chuỗi ký tự dài tối đa 20 ký tự. Tương tự như nơi đi, yêu cầu kiểm tra
định dạng.
Yêu cầu:
1. Viết các hàm nhập và xuất dữ liệu cho một chuyến bay.
- Kiểm tra và báo lỗi nếu người dùng nhập sai các định dạng yêu cầu.
2. Viết thêm các chức năng sau:
- Tìm kiếm chuyến bay theo mã chuyến bay, nơi đi hoặc nơi đến.
- Sắp xếp danh sách chuyến bay theo thứ tự ngày và giờ khởi hành (từ
sớm đến muộn).
3. Hiển thị danh sách tất cả các chuyến bay khởi hành từ một nơi cụ thể trong một
ngày được chỉ định.
4. Đếm số lượng chuyến bay từ một nơi đi đến một nơi đến nhất định.
Ví dụ chi tiết:
Giả sử bạn có danh sách các chuyến bay với thông tin đầy đủ, chương trình cần:
- Kiểm tra xem mã chuyến bay “VN123” có tồn tại không.
- Sắp xếp danh sách các chuyến bay theo ngày giờ khởi hành.
- Liệt kê tất cả các chuyến bay khởi hành từ “Hà Nội” vào ngày 01/01/2024.
- Đếm số chuyến bay từ “Hà Nội” đến “TP. Hồ Chí Minh”.
Đầu vào:
- Số lượng chuyến bay.
- Thông tin chi tiết cho mỗi chuyến bay bao gồm mã chuyến bay, ngày bay, giờ
bay, nơi đi, và nơi đến.
Đầu ra:
- Danh sách chuyến bay đã sắp xếp theo ngày giờ khởi hành.
- Kết quả tìm kiếm và các báo cáo theo yêu cầu.
*/
#include<bits/stdc++.h>
using namespace std;
class AirPlane{
private:
    string IDplane;
    string date;
    vector<int> PartsOfDate;
    string time;
    vector<int> GioPhut;
    string from;
    string des;
public:
    void Thietlap(string IDplane, string date, vector<int> PartsOfDate, string time, string from, string des, vector<int> NgayGio){
        this->IDplane = IDplane;
        this->date = date;
        this->PartsOfDate = PartsOfDate;
        this->time = time;
        this->from = from;
        this->des = des;
        this->GioPhut=GioPhut;
    }
    void Nhap(){
        while(true){
            IDplane.clear();
            cout << "Nhap ma chuyen bay : " ;
            getline(cin>>ws, IDplane);
            if((IDplane.length()>0 && IDplane.length()<6) && TestSpaceDigit()){
                break;
            }
                cout << "LOI: MA CHUYEN BAY KHONG CHUA KHOANG TRANG VA KY TU DAC BIET. MOI NHAP LAI" << endl;
        }
        while (true){
        //Xóa dữ liệu cũ trước khi nhập cái mới
        PartsOfDate.clear();

        //Nhập dữ liệu
        cout << "Moi nhap ngay bay dang dd/mm/yyyy : ";
        getline(cin >> ws, date);
        Tach();

        //Kiểm tra tính hợp lệ
        if((PartsOfDate[0] < 1 || PartsOfDate[0] > 31) || (PartsOfDate[1]<1 || PartsOfDate[1]>12)){
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

      cout << "Nhap gio bay : ";
      getline(cin>>ws, time);
      dinhDang24h();

      while(true){
        from.clear();
        cout << "Nhap noi di : ";
        getline(cin>>ws, from);
        if((from.length()> 0 && from.length() < 21) && TestNumberDigitFrom()){
            break;
        }
            cout << "LOI: TEN DIA DANH KHONG CHUA SO HOAC KY TU DAC BIET, NHAP TOI DA 20 KY TU. MOI NHAP LAI : " << endl;
      }

      while(true){
        des.clear();
        cout << "Nhap noi den : ";
        getline(cin>>ws, des);
        if((des.length()> 0 && des.length() < 21) && TestNumberDigitDes()){
            break;
        }
            cout << "LOI: TEN DIA DANH KHONG CHUA SO HOAC KY TU DAC BIET, NHAP TOI DA 20 KY TU. MOI NHAP LAI : " << endl;
     }
    }
    bool TestNumberDigitDes(){
        for (char c : des){
           if (!isalpha(c) && !isspace(c)) return false;
        }
        return true;
    }
    bool TestNumberDigitFrom(){
        for(char c : from){
            if (!isalpha(c) && !isspace(c)) return false;
        }
        return true;
    }
    void dinhDang24h() {
        if (time[1] == ':'&& time.length()== 4) time.insert(0, "0");
        else if (time[2]==':' && time.length() == 4) time.insert(3,"0");
        else if (time.length()==3){
            time.insert(0,"0");
            time.insert(2,"0");
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
    void TachNgayGio(){
        GioPhut.clear();
        string s = time;
        stringstream ss(s);
        string num;
        while (getline(ss,num,':')){
             GioPhut.push_back(stoi(num));  //=>GioPhut[0] là giờ, GioPhut[1] là phút
        }
    }
    bool TestSpaceDigit()const{
        for (char c : IDplane){
            if (!isalnum(c)) return false;  // Chỉ chấp nhận chữ cái và số
        }
        return true;
    }
    string getIDplane() const{
        return IDplane;
    }
    string getFrom()const{
        return from;
    }
    string getDes()const{
        return des;
    }
    int getNgay(){
        return PartsOfDate[0];
    }
    int getThang(){
        return PartsOfDate[1];
    }
    int getNam(){
        return PartsOfDate[2];
    }
    int getGio(){
        return GioPhut[0];
    }
    int getPhut(){
        return GioPhut[1];
    }
    void XuatThongTinChuyenBay(){
        cout << "Ma chuyen bay : " << IDplane << endl;
        cout << "Ngay bay : " << date << endl;
        cout << "Gio bay : " << time << endl;
        cout << "Noi di : " << from << endl;
        cout << "Noi den : " << des << endl;
    }
};
class QuanLyChuyenBay{
private:
    int spt;
    AirPlane *plane;
public:
    void ThietLap(int spt){
        this->spt=spt;
    }
    int nhap(){
        cout << "Nhap so luong chuyen bay : ";
        cin >> spt;
        if(spt <= 0){
            cout << "LOI! SO LUONG CHUYEN BAY PHAI LON HON 0, CHUONG TRINH SE KET THUC!";
            exit(0); //Dừng chương trình ngay lập tức
        }
        plane = new AirPlane[spt];
        for (int i = 0; i<spt;i++){
            cout << "Nhap chuyen bay thu "<< i+1<<endl;
            plane[i].Nhap();
        }
    }
    void TimKiemChuyenBayTheoMaChuyenBay(){
        string ma;
        cout << "Nhap ma chuyen bay muon tim kiem : ";
        getline(cin >> ws, ma);
        //Chuyen mã nhập vào thành chữ thường(chỉ chữ cái, giữ nguyên số)
        transform(ma.begin(), ma.end(), ma.begin(), [](char c){
                  return isalpha(c) ? tolower(c) : c;
        });
        bool find_ = false;
        for(int i = 0; i<spt;i++){
            string id = plane[i].getIDplane();
            transform(id.begin(), id.end(),id.begin(), [](char c){
                      return isalpha(c) ? tolower(c) : c;
            });
            if(id.find(ma) != string::npos){
                plane[i].XuatThongTinChuyenBay();
                find_=true;
            }
        }
        if(!find_){
            cout << "KHONG THE TIM THAY BAT CU CHUYEN BAY NAO CO TU KHOA " << "'" << ma<< "'" <<endl;
        }
    }
    void TimKiemChuyenBayTheoNoiDi(){
        string tenNoiDi;
        cout << "Nhap ten noi di chuyen bay muon tim kiem : ";
        getline(cin >> ws, tenNoiDi);
        //Chuyen mã nhập vào thành chữ thường(chỉ chữ cái, giữ nguyên số)
        transform(tenNoiDi.begin(), tenNoiDi.end(),tenNoiDi.begin(), [](char c){
                  return isalpha(c) ? tolower(c) : c;
        });
        bool find_ = false;
        for(int i = 0; i<spt;i++){
            string oriPlace = plane[i].getFrom();
            transform(oriPlace.begin(), oriPlace.end(),oriPlace.begin(), [](char c){
                      return isalpha(c) ? tolower(c) : c;
            });
            if(oriPlace.find(tenNoiDi) != string::npos){
                plane[i].XuatThongTinChuyenBay();
                find_=true;
            }
        }
        if(!find_){
            cout << "KHONG THE TIM THAY BAT CU CHUYEN BAY NAO CO TU KHOA " << "'" << tenNoiDi << "'" <<endl;
        }
    }
    void TimKiemChuyenBayTheoNoiDen(){
        string tenNoiDen;
        cout << "Nhap ten noi den chuyen bay muon tim kiem : ";
        getline(cin >> ws, tenNoiDen);
        //Chuyen mã nhập vào thành chữ thường(chỉ chữ cái, giữ nguyên số)
        transform(tenNoiDen.begin(), tenNoiDen.end(),tenNoiDen.begin(), [](char c){
                  return isalpha(c) ? tolower(c) : c;
        });
        bool find_ = false;
        for(int i = 0; i<spt;i++){
            string nextPlace = plane[i].getDes();
            transform(nextPlace.begin(), nextPlace.end(),nextPlace.begin(), [](char c){
                      return isalpha(c) ? tolower(c) : c;
            });
            if(nextPlace.find(tenNoiDen) != string::npos){
                plane[i].XuatThongTinChuyenBay();
                find_=true;
            }
        }
        if(!find_){
            cout << "KHONG THE TIM THAY BAT CU CHUYEN BAY NAO CO TU KHOA " << "'" << tenNoiDen << "'" <<endl;
        }
    }
    // Hàm so sánh để sắp xếp chuyến bay theo ngày và giờ khởi hành
    void SoSanhChuyenBay() {
        sort(plane, plane + spt, [](AirPlane &a,AirPlane &b) {
            if (a.getNam() != b.getNam()) return a.getNam() < b.getNam();
            if (a.getThang() != b.getThang()) return a.getThang() < b.getThang();
            if (a.getNgay() != b.getNgay()) return a.getNgay() < b.getNgay();
            if (a.getGio() != b.getGio()) return a.getGio() < b.getGio();
            return a.getPhut() < b.getPhut();
       });
       cout << "Danh sach chuyen bay sau khi sap xep : " << endl;
       for(int i = 0; i<spt;i++){
            plane[i].XuatThongTinChuyenBay();
       }
   }
   //Hiển thị danh sách tất cả các chuyến bay khởi hành từ một nơi cụ thể trong một ngày được chỉ định.
   //Kiểm tra xem from có khớp không và date có khớp không
   void TimKiemChuyenBayTheoNoiDiVaNgay() {
        string noiDi, ngay;
        cout << "Nhap noi di: ";
        getline(cin >> ws, noiDi);
        cout << "Nhap ngay khoi hanh (dd/mm/yyyy): ";
        getline(cin >> ws, ngay);

        transform(noiDi.begin(), noiDi.end(), noiDi.begin(), ::tolower);

        int day = stoi(ngay.substr(0, 2));
        int month = stoi(ngay.substr(3, 2));
        int year = stoi(ngay.substr(6, 4));
        bool found = false;
        for (int i = 0; i < spt; i++) {
             string from = plane[i].getFrom();
             transform(from.begin(), from.end(), from.begin(), ::tolower);

             if (from == noiDi && plane[i].getNgay() == day && plane[i].getThang() == month && plane[i].getNam() == year) {
                 plane[i].XuatThongTinChuyenBay();
                 found = true;
             }
       }
       if (!found) {
            cout << "Khong co chuyen bay nao khoi hanh tu " << noiDi << " vao ngay " << ngay << endl;
       }
    }
    //Đếm số lượng chuyến bay từ một nơi đi đến một nơi đến nhất định.
    //Đếm số chuyến có from và des trùng khớp
    void DemChuyenBayTheoLoTrinh() {
       string noiDi, noiDen;
       cout << "Nhap noi di: ";
       getline(cin >> ws, noiDi);
       cout << "Nhap noi den: ";
       getline(cin >> ws, noiDen);

       transform(noiDi.begin(), noiDi.end(), noiDi.begin(), ::tolower);
       transform(noiDen.begin(), noiDen.end(), noiDen.begin(), ::tolower);

       int count = 0;
       for (int i = 0; i < spt; i++) {
            string from = plane[i].getFrom();
            string des = plane[i].getDes();
            transform(from.begin(), from.end(), from.begin(), ::tolower);
            transform(des.begin(), des.end(), des.begin(), ::tolower);

            if (from == noiDi && des == noiDen) {
               count++;
            }
       }
       cout << "So luong chuyen bay tu " << noiDi << " den " << noiDen << " la: " << count << endl;
   }
};
int main()
{
    QuanLyChuyenBay qlcb;
    qlcb.nhap();
    cout << endl;
    cout << "Danh sach chuyen bay da sap xep theo ngay va gio : " << endl;
    qlcb.SoSanhChuyenBay();
    cout << "Yeu cau : Tim kiem chuyen bay theo ma chuyen bay : " << endl;
    qlcb.TimKiemChuyenBayTheoMaChuyenBay();
    cout << endl;
    cout << "Yeu cau : Tim kiem chuyen bay theo noi di : " << endl;
    qlcb.TimKiemChuyenBayTheoNoiDi();
    cout << endl;
    cout << "Yeu cau : Tim kiem chuyen bay theo noi den: " << endl;
    qlcb.TimKiemChuyenBayTheoNoiDen();
    cout << endl;
    cout << "Danh sach cac chuyen bay khoi hanh tu mot noi cu the trong mot ngay duoc chi dinh : " << endl;
    qlcb.TimKiemChuyenBayTheoNoiDiVaNgay();
    cout << endl;
    cout << "Dem so luong chuyen bay tu noi di den mot noi nhat dinh : " << endl;
    qlcb.DemChuyenBayTheoLoTrinh();
    cout << endl;
    return 0;
}
