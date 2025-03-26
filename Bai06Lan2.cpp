/* Đề bài
Bài tập 6: Viết chương trình quản lý thông tin của nhiều học sinh, bao gồm họ tên,
điểm toán, điểm văn, và thêm điểm ngoại ngữ. Chương trình cần thực hiện các chức
năng sau:
1. Nhập thông tin cho n học sinh, bao gồm:
- Họ tên (phải kiểm tra độ dài và định dạng, không chứa ký tự số).
- Điểm Toán, Văn và Ngoại ngữ (phải là số thực trong khoảng từ 0 đến 10,
nếu nhập sai phải yêu cầu nhập lại).
2. Tính điểm trung bình của mỗi học sinh theo công thức:
Đ𝑖ể𝑚 𝑡𝑟𝑢𝑛𝑔 𝑏ì𝑛ℎ =[(2. Đ𝑖ể𝑚 𝑇𝑜á𝑛) + Đ𝑖ể𝑚 𝑉ă𝑛 + Đ𝑖ể𝑚 𝐴𝑛ℎ]/4
Trong đó, điểm Toán có trọng số cao hơn.
3. Phân loại học sinh dựa trên điểm trung bình:
- Xuất sắc: Điểm trung bình từ 9 trở lên.
- Giỏi: Điểm trung bình từ 8 đến dưới 9.
- Khá: Điểm trung bình từ 6.5 đến dưới 8.
- Trung bình: Điểm trung bình từ 5 đến dưới 6.5.
- Yếu: Điểm trung bình dưới 5.
4. Tìm kiếm và xuất thông tin của học sinh có điểm trung bình cao nhất.
5. Tìm kiếm học sinh theo tên (cho phép tìm kiếm với từ khóa không phân biệt
hoa thường và không cần nhập tên đầy đủ).
6. Xuất danh sách học sinh có điểm toán thấp nhất.
Yêu cầu:
- Chương trình cần có giao diện nhập liệu và xuất kết quả rõ ràng.
- Đảm bảo kiểm tra tính hợp lệ của tất cả các dữ liệu đầu vào.
- Phân loại học sinh phải chính xác và chương trình phải có tính linh hoạt khi tìm
kiếm thông tin theo tên.
Đầu vào:
- Số lượng học sinh: 3
- Thông tin từng học sinh bao gồm họ tên, điểm toán, điểm văn, điểm ngoại ngữ.
Đầu ra:
- Điểm trung bình và phân loại học sinh.
- Học sinh có điểm trung bình cao nhất.
- Kết quả tìm kiếm theo tên.
- Danh sách học sinh có điểm toán thấp nhất.
*/
/* Mẫu Input và Output
//Input và Output lần 1
Nhap so luong hoc sinh : 3
Nhap hoc sinh thu 1
Nhap ho va ten : Le HOANG yEn
Nhap diem Toan : 8.0
Nhap diem Van : 7.25
Nhap diem Ngoai Ngu : 3
Nhap hoc sinh thu 2
Nhap ho va ten : %Tran 56Van LE
HO TEN DA NHAP KHONG HOP LE! HO TEN KHONG CHUA KY TU DAC BIET VA SO LUONG KY TU LON HON 1 VA BE HON 50
Nhap ho va ten : Tran &Van Le
HO TEN DA NHAP KHONG HOP LE! HO TEN KHONG CHUA KY TU DAC BIET VA SO LUONG KY TU LON HON 1 VA BE HON 50
Nhap ho va ten : TRan Van LE
Nhap diem Toan : 23
DIEM Toan KHONG HOP LE! 0<=DIEM<=10, MOI NHAP LAI :
Nhap diem Toan : 2.5
Nhap diem Van : 5.75
Nhap diem Ngoai Ngu : 9
Nhap hoc sinh thu 3
Nhap ho va ten : Le Hoang Thanh Truc
Nhap diem Toan : 9.0
Nhap diem Van : -8
DIEM Van KHONG HOP LE! 0<=DIEM<=10, MOI NHAP LAI :
Nhap diem Van : 8.5
Nhap diem Ngoai Ngu : 90
DIEM Ngoai Ngu KHONG HOP LE! 0<=DIEM<=10, MOI NHAP LAI :
Nhap diem Ngoai Ngu : 9.2

Ho va ten : Le Hoang Yen
Diem Toan : 8
Diem Van : 7.25
Diem Ngoai Ngu : 3
Diem trung binh : 6.5625
Kha
Ho va ten : Tran Van Le
Diem Toan : 2.5
Diem Van : 5.75
Diem Ngoai Ngu : 9
Diem trung binh : 4.9375
Yeu
Ho va ten : Le Hoang Thanh Truc
Diem Toan : 9
Diem Van : 8.5
Diem Ngoai Ngu : 9.2
Diem trung binh : 8.925
Gioi

Diem trung binh cao nhat : 8.925
Thong tin hoc sinh co diem trung binh cao nhat :
Ho va ten : Le Hoang Thanh Truc
Diem Toan : 9
Diem Van : 8.5
Diem Ngoai Ngu : 9.2
Diem trung binh : 8.925
Gioi

Nhap ten hoc sinh muon tim kiem : Nhu
KHONG THE TIM THAY BAT CU HOC SINH NAO CO TU KHOA 'Nhu'

Diem Toan thap nhat : 2.5
Danh sach hoc sinh co diem Toan thap nhat :
Ho va ten : Tran Van Le
Diem Toan : 2.5
Diem Van : 5.75
Diem Ngoai Ngu : 9
Diem trung binh : 4.9375
Yeu

//Input và Output lần 2
Nhap so luong hoc sinh : 2
Nhap hoc sinh thu 1
Nhap ho va ten : MY NHAN
Nhap diem Toan : 7.8
Nhap diem Van : 4
Nhap diem Ngoai Ngu : 7.9
Nhap hoc sinh thu 2
Nhap ho va ten : LE van 8 thei
HO TEN DA NHAP KHONG HOP LE! HO TEN KHONG CHUA KY TU DAC BIET VA SO LUONG KY TU LON HON 1 VA BE HON 50
Nhap ho va ten : Le Van Thien*
HO TEN DA NHAP KHONG HOP LE! HO TEN KHONG CHUA KY TU DAC BIET VA SO LUONG KY TU LON HON 1 VA BE HON 50
Nhap ho va ten : Le Van Thien
Nhap diem Toan : 60
DIEM Toan KHONG HOP LE! 0<=DIEM<=10, MOI NHAP LAI :
Nhap diem Toan : 6.0
Nhap diem Van : -2
DIEM Van KHONG HOP LE! 0<=DIEM<=10, MOI NHAP LAI :
Nhap diem Van : 2
Nhap diem Ngoai Ngu : 7.9

Ho va ten : My Nhan
Diem Toan : 7.8
Diem Van : 4
Diem Ngoai Ngu : 7.9
Diem trung binh : 6.875
Kha
Ho va ten : Le Van Thien
Diem Toan : 6
Diem Van : 2
Diem Ngoai Ngu : 7.9
Diem trung binh : 5.475
Trung Binh

Diem trung binh cao nhat : 6.875
Thong tin hoc sinh co diem trung binh cao nhat :
Ho va ten : My Nhan
Diem Toan : 7.8
Diem Van : 4
Diem Ngoai Ngu : 7.9
Diem trung binh : 6.875
Kha

Nhap ten hoc sinh muon tim kiem : Thien
Ho va ten : Le Van Thien
Diem Toan : 6
Diem Van : 2
Diem Ngoai Ngu : 7.9
Diem trung binh : 5.475
Trung Binh

Diem Toan thap nhat : 6
Danh sach hoc sinh co diem Toan thap nhat :
Ho va ten : Le Van Thien
Diem Toan : 6
Diem Van : 2
Diem Ngoai Ngu : 7.9
Diem trung binh : 5.475
Trung Binh
*/
#include<bits/stdc++.h>
using namespace std;
class HocSinh{
private:
    string HoTen;
    double DiemToan, DiemVan, DiemNN, DiemTB;
public:
    void ThietLap(string HoTen,double DiemToan, double DiemVan, double DiemNN, double DiemTB){
        this->HoTen = HoTen;
        this->DiemToan = DiemToan;
        this->DiemVan = DiemVan;
        this->DiemNN = DiemNN;
        this->DiemTB = DiemTB;
    }
    void Nhap(){
        while(true){
            HoTen.clear();
            cout << "Nhap ho va ten : " ;
            getline(cin >> ws, HoTen);
            if ((HoTen.length()>1 && HoTen.length()<50) && TestDigitName()){
                ChuanHoaTen();
            }
            if((HoTen.length()<=1 || HoTen.length()>=50) || !TestDigitName()){
                cout << "HO TEN DA NHAP KHONG HOP LE! HO TEN KHONG CHUA KY TU DAC BIET VA SO LUONG KY TU LON HON 1 VA BE HON 50" << endl;
                continue;
            }
            break;
        }
       NhapDiem(DiemToan, "Toan");
       NhapDiem(DiemVan, "Van");
       NhapDiem(DiemNN, "Ngoai Ngu");
    }
    void NhapDiem(double &diem, const string &tenMon){
        while(true){
            cout << "Nhap diem " << tenMon << " : ";
            cin >> diem;
            if(diem < 0 || diem> 10){
                cout << "DIEM " << tenMon <<" KHONG HOP LE! 0<=DIEM<=10, MOI NHAP LAI : " << endl;
            }
            else {
                break;
            }
        }
    }
    bool TestDigitName()const{
        for (char c : HoTen){
            if (!isalpha(c) && !isspace(c)){//Chỉ chấp nhận chữ cái và khoảng trắng
                return false; //false nếu họ tên chưa số và ký tự đặc biệt
            }
        }
        return true;
    }
    void ChuanHoaTen(){
       stringstream ss(HoTen);
       string word, result;
       while (ss >> word){
          long long n = word.size();
          word[0] = toupper(word[0]);
          for(long long i = 1;i < n;i++){
              word[i] = tolower(word[i]);
          }
        result += word + " ";
      }
      HoTen = result.substr(0, result.size()-1); //Tách lấy họ tên, bỏ khoảng trắng ở cuối ra
    }
    string getHoTen()const{
        return HoTen;
    }
    double getDiemToan()const{
        return DiemToan;
    }
    double AvrScore()const{
        return ((2*DiemToan)+DiemVan+DiemNN)/4;
    }
    void PhanLoaiHS()const{
        double dtb = AvrScore();
        if(dtb >= 9){
            cout << "Xuat sac" << endl;
        }
        else if(dtb >= 8 && dtb < 9){
            cout << "Gioi" << endl;
        }
        else if(dtb >=6.5 && dtb<8){
            cout << "Kha" <<endl;
        }
        else if(dtb>=5 && dtb <6.5){
            cout << "Trung Binh" << endl;
        }
        else{
            cout << "Yeu" << endl;
        }
    }
    void XuatThongTinHS() const {
        cout << "Ho va ten : " << HoTen << endl;
        cout << "Diem Toan : " << DiemToan << endl;
        cout << "Diem Van : " << DiemVan << endl;
        cout << "Diem Ngoai Ngu : " << DiemNN << endl;
        cout << "Diem trung binh : " << AvrScore() << endl;
        PhanLoaiHS();
    }
};
class N_HocSinh{
private:
    int spt;
    HocSinh *hs;
public:
    void ThietLap(int spt){
        this->spt=spt;
    }
    int nhap(){
        cout << "Nhap so luong hoc sinh : ";
        cin >> spt;
        if(spt <=0){
            cout << "LOI! SO LUONG HOC SINH PHAI LON HON 0, CHUONG TRINH SE KET THUC!";
            exit(0); //Dừng chương trình ngay lập tức
        }
        hs = new HocSinh[spt];
        for (int i = 0; i<spt;i++){
            cout << "Nhap hoc sinh thu "<< i+1<<endl;
            hs[i].TestDigitName();
            hs[i].Nhap();
        }
    }
    //Điểm trung bình và phân loại học sinh.
    void AvrScRank(){
        for (int i = 0; i<spt;i++){
            hs[i].XuatThongTinHS();
        }
    }

    //4. Tìm kiếm và xuất thông tin của học sinh có điểm trung bình cao nhất.
    void MAXdtb(){
         double max_ = hs[0].AvrScore();

         for (int i = 1; i<spt;i++){
            max_= max(max_, hs[i].AvrScore());
         }
         cout << "Diem trung binh cao nhat : " << max_ << endl;
         //Nếu 2 người có cùng điểm trung bình cao nhất thì sao, ta xuất danh sách
         cout << "Thong tin hoc sinh co diem trung binh cao nhat : " << endl;
         for (int i = 0; i<spt;i++){
            if(hs[i].AvrScore()==max_){
                 hs[i].XuatThongTinHS();
            }
         }
    }
    //5. Tìm kiếm học sinh theo tên (cho phép tìm kiếm với từ khóa không phân biệt hoa thường và không cần nhập tên đầy đủ).
    void TimKiemHSTheoTen(){
        string key;
        cout << "Nhap ten hoc sinh muon tim kiem : ";
        getline(cin >> ws, key);
        //Chuyen tu khoa tim kiem thanh chu thuong
        string tuKhoaLower = key;
        transform(tuKhoaLower.begin(), tuKhoaLower.end(), tuKhoaLower.begin(), ::tolower);
        bool find_ = false;
        //Chuan hoa ten hs thanh chu thuong de so sanh
        for(int i = 0; i<spt;i++){
            string hoTenLower =hs[i].getHoTen();
            transform(hoTenLower.begin(), hoTenLower.end(), hoTenLower.begin(), ::tolower);
            //KT xem key co xuat hien trong ten khong?
            if(hoTenLower.find(tuKhoaLower) != string::npos){
                hs[i].XuatThongTinHS();
                find_=true;
            }
        }
        if(!find_){
            cout << "KHONG THE TIM THAY BAT CU HOC SINH NAO CO TU KHOA " << "'" << key << "'" <<endl;
        }
    }
    void SlowestMathScoreStudents(){
         double min_ = hs[0].getDiemToan();
         //Tim diem Toan nho nhat
         for (int i = 1; i<spt;i++){
            if(hs[i].getDiemToan()<min_){
                min_ = hs[i].getDiemToan();
            }
         }
         cout << "Diem Toan thap nhat : " << min_ << endl;
         //Xuat danh sach hoc sinh co diem toan nho nhat
         cout << "Danh sach hoc sinh co diem Toan thap nhat : " << endl;
         for (int i = 1; i<spt;i++){
             if(hs[i].getDiemToan() == min_){
                hs[i].XuatThongTinHS();
             }
         }
    }
    //Destructor
    ~N_HocSinh(){
        // Để đảm bào delete[] hs; không làm mất dữ liệu và bị nhập lại liên tục cần thêm if
        if(hs){
          delete[] hs;
          hs = nullptr;
        }
    }
};

int main()
{

    N_HocSinh HS;
    HS.nhap();
    cout << endl;
    HS.AvrScRank();
    cout << endl;
    HS.MAXdtb();
    cout << endl;
    HS.TimKiemHSTheoTen();
    cout << endl;
    HS.SlowestMathScoreStudents();
    return 0;
}
