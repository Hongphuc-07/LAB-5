#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
#include "CKhachHang.h"
#include "CKhachHangBinhThuong.h"
#include "CKhachHangThanThiet.h"
#include "CKhachHangDacBiet.h"

using namespace std;

int main() {
    // KẾT NỐI LUỒNG FILE DỮ LIỆU VÀO / RA
    ifstream fileIn("XYZ.INP");
    ofstream fileOut("XYZ.OUT");

    // Kiểm tra trạng thái mở file để ngăn ngừa lỗi đọc/ghi trên file không tồn tại
    if (!fileIn.is_open() || !fileOut.is_open()) {
        cout << "Loi: Khong the mo file XYZ.INP hoac XYZ.OUT!" << endl;
        return 1;
    }

    // ĐỌC THÔNG TIN SỐ LƯỢNG BAN ĐẦU
    int x, y, z; // x: Khách bình thường, y: Khách thân thiết, z: Khách đặc biệt
    fileIn >> x >> y >> z;

    // Bỏ qua ký tự xuống dòng thừa sau khi đọc số để tránh lỗi trôi dòng khi đọc chuỗi tiếp theo
    fileIn.ignore(numeric_limits<streamsize>::max(), '\n');

    // Khởi tạo container vector lưu trữ các con trỏ vùng nhớ khách hàng (Tính đa hình)
    vector<CKhachHang*> dsKhachHang;
    double tongDoanhThu = 0;

    // ĐỌC DANH SÁCH KHÁCH HÀNG BÌNH THƯỜNG
    for (int i = 0; i < x; i++) {
        CKhachHang* kh = new CKhachHangBinhThuong();
        kh->DocTuFile(fileIn);
        dsKhachHang.push_back(kh); // Thêm con trỏ khách hàng vào cuối vector
    }

    // ĐỌC DANH SÁCH KHÁCH HÀNG THÂN THIẾT
    for (int i = 0; i < y; i++) {
        CKhachHang* kh = new CKhachHangThanThiet();
        kh->DocTuFile(fileIn);
        
        // Xóa bộ đệm dòng để chuẩn bị cho lượt đọc dữ liệu tiếp theo từ file
        fileIn.ignore(numeric_limits<streamsize>::max(), '\n');
        
        dsKhachHang.push_back(kh);
    }

    // ĐỌC DANH SÁCH KHÁCH HÀNG ĐẶC BIỆT
    for (int i = 0; i < z; i++) {
        CKhachHang* kh = new CKhachHangDacBiet();
        kh->DocTuFile(fileIn);
        dsKhachHang.push_back(kh);
    }

    // XUẤT KẾT QUẢ RA FILE (XYZ.OUT)
    // Ghi lại số lượng từng loại khách hàng ở dòng đầu tiên của file output
    fileOut << x << " " << y << " " << z << endl;

    // Duyệt qua toàn bộ vector để xuất thông tin chi tiết và tích lũy doanh thu
    for (size_t i = 0; i < dsKhachHang.size(); i++) {
        dsKhachHang[i]->XuatRaFile(fileOut);
        tongDoanhThu += dsKhachHang[i]->TinhThanhTien(); // Tính đa hình: Tự động gọi đúng hàm TinhThanhTien tương ứng từng lớp con
    }

    // Ghi tổng doanh thu của tất cả khách hàng vào dòng cuối cùng của file output
    fileOut << tongDoanhThu << endl;

    // GIẢI PHÓNG BỘ NHỚ ĐỘNG VÀ ĐÓNG LUỒNG FILE
    // Giải phóng các vùng nhớ đối tượng cụ thể được quản lý bởi các con trỏ bên trong vector
    for (size_t i = 0; i < dsKhachHang.size(); i++) {
        delete dsKhachHang[i];
    }
    dsKhachHang.clear(); // Xóa các con trỏ trống rỗng ra khỏi vector để tránh rác dữ liệu

    // Đóng kết nối để giải phóng tài nguyên hệ thống file của hệ điều hành
    fileIn.close();
    fileOut.close();

    return 0;
}