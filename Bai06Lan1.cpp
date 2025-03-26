/* Đề bài :
Bài tập 6: Cho hai mảng A và B chứa các số nguyên. Hãy xây dựng một chương trình
để xác định xem có bao nhiêu lần mảng A xuất hiện liên tiếp dưới dạng một dãy con
trong mảng B.
Cụ thể:
- Mảng A được coi là xuất hiện trong mảng B nếu tất cả các phần tử của A xuất
hiện liên tiếp theo đúng thứ tự trong B.
- Các vị trí xuất hiện của A trong B có thể chồng lấn lên nhau.
Yêu cầu:
1. Viết một thuật toán hiệu quả để đếm số lần xuất hiện của A trong B.
2. Đảm bảo rằng chương trình có thể xử lý các trường hợp mảng lớn và mảng con
xuất hiện nhiều lần liên tiếp trong mảng cha.
3. Trong phần xuất kết quả, liệt kê tất cả các vị trí bắt đầu (chỉ số) của các lần xuất
hiện của A trong B.
Ví dụ: Với A = [1, 2], B = [1, 2, 1, 2, 3, 1, 2], mảng A xuất hiện 3 lần tại các chỉ số bắt
đầu là 0, 2, và 5
Đầu vào:
- Dòng đầu tiên chứa số phần tử của mảng A và mảng B.
- Dòng thứ hai chứa các phần tử của mảng A.
- Dòng thứ ba chứa các phần tử của mảng B.
Đầu ra:
- Số lần mảng A xuất hiện trong mảng B.
- Danh sách các chỉ số bắt đầu của những lần xuất hiện.
*/

/* Các mẫu Input và Output
Input:
2 7
1 2
1 2 1 2 3 1 2
Output:
So lan xuat hien : 3
Vi tri bat dau : 0 2 5

Input:
3 6
7 8 9
1 2 3 4 5 6
Output:
So lan xuat hien : 0
Khong co vi tri bat dau
*/

#include<bits/stdc++.h>
using namespace std;
class Mang{
private:
    int n;
    int m;
    int *a;
    int *b;
public:
    Mang(int n = 0, int m = 0){
        this->n = n;
        this->m = m;
        a= (n>0)?new int[n] : nullptr;
        b= (m>0)?new int[m] : nullptr;
    }
    ~Mang(){
        delete[] a;
        delete[] b;
    }
    void NhapA(){
        if(n==0){
            cin >> n;
            a = new int [n];
        }
        for(int i = 0;i<n;i++){
            cin >> a[i];
        }
    }
    void NhapB(){
        if(m==0){
            cin >> m;
            b = new int [m];
        }
        for(int i = 0;i<m;i++){
            cin >> b[i];
        }
    }
    void Nhap(){
        cin >>n >> m;
        delete[] a;
        delete[] b;
        a = new int[n];
        b = new int[m];
        NhapA();
        NhapB();
    }
    //Để tìm mảng A trong B ta dùng thuật toán Knuth-Morris-Pratt(KMP)
    //Bước đầu tiên của KMB là tạo mảng LPS để ta biết nên nhảy đến đâu khi phần tử của 2 mảng không trùng khớp
    //LPS(Longest Prefix Suffer) là độ dài lớn nhất của một tiền tố cũng là hậu tố
    //Giúp tránh so sánh lại các phần tử đã biết là trùng khớp
    //Tìm mảng LPS
    vector<int> findLPS(){
        vector<int> lps(n, 0); //n phần tử có giá trị = 0
        int length = 0; //Độ dài tiền tố giống hậu tố
        int i = 1; //So sánh cái sau với cái trước
        while(i<n){//khi i+1>n thì phải thoát khỏi vòng lặp
            if(a[i]==a[length]){
                length++;
                lps[i] = length;
                i++;
            }
            else{
                if(length != 0){
                    length = lps[length-1]; //Quay lại giá trị trước đó trong lps
                }
                else{
                    lps[i]=0;
                    i++;
                }
           }
        }
        return lps;
    }
    //Bước tiếp theo : Tìm số lần xuất hiện của A trong B và các index bắt đẩu của những lần xuất hiện bằng KMP
    void TimKiemKMP(){
        vector<int> lps = findLPS();
        vector<int> viTriXuatHien;
        int i = 0, j = 0; //i duyệt B, j duyệt A
        while(i<m){
            //Nếu khớp, tăng i và j
            if(a[j]==b[i]){
                i++;
                j++;
            }
            //Nếu tìm thấy A trong B (j == n)
            if (j==n){
                viTriXuatHien.push_back(i-j);
                j = lps[j-1]; //So sánh tiếp các trường hợp trùng lặp
            }
            //Nếu không khớp khi j>0, dùng LPS để nhảy
            else if (i<m && a[j] != b[i]){
                if(j != 0){
                    j = lps[j-1];
                }
                else{
                    i++; //j==0, tăng i để kiểm tra tiếp
                }
            }
        }
        cout << "So lan xuat hien : ";
        cout << viTriXuatHien.size()<< endl;
        if (viTriXuatHien.size() == 0){ //Nếu trong A không có giá trị nào trùng với B
            cout << "Khong co vi tri bat dau" << endl;
        }
        else{
        cout << "Vi tri bat dau : ";
        for (int index : viTriXuatHien){
            cout << index<<" ";
        }
        cout << endl;
    }
    }
};
int main()
{
    Mang arr;
    arr.Nhap();
    arr.TimKiemKMP();
    return 0;
}
