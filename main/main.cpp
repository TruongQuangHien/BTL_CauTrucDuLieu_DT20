#include <iostream>
#include <iomanip>
#include "NhanVien.h"
#include "CayNhanVien.h"
#include "CayLuong.h"
#include "HienThi.h"
#include "ChucNangNhanVien.h"
#include "DuLieuFile.h"
#include "LichSuLuong.h"
#include "LichSuThaoTac.h"
#include "ThongKe.h"

void menu() {
    cout << "\n============================================================\n";
    cout << "       CONTROL PANEL - QUAN LY NHAN VIEN & BANG LUONG\n";
    cout << "============================================================\n";
    cout << " 1. Them nhan vien\n";
    cout << " 2. Tim nhan vien theo ma NV\n";
    cout << " 3. Tim nhan vien theo muc luong toi thieu\n";
    cout << " 4. Xoa nhan vien\n";
    cout << " 5. Cap nhat thong tin / cham cong / OT / di tre\n";
    cout << " 6. In danh sach nhan vien (tang dan theo ma)\n";
    cout << " 7. Thong ke luong trung binh, cao nhat, thap nhat\n";
    cout << " 8. In lich su thay doi luong\n";
    cout << " 9. Xep loai KPI theo ngay cong (cao den thap)\n";
    cout << "10. Thong ke tong quy luong thang (va tong tien tru di tre)\n";
    cout << "11. Hoan tac xoa nhan vien gan nhat\n";
    cout << "12. Luu du lieu ngay\n";
    cout << " 0. Luu va thoat\n";
    cout << "------------------------------------------------------------\n";
}

int main() {
    docDuLieu();
    cout << "Da nap du lieu tu file " << TEN_FILE << " (neu file ton tai).\n";
    int chon;
    do {
        menu();
        chon = (int)nhapSo("Chon chuc nang: ", 0, 12);
        if (chon == 1) chucNangThem();
        else if (chon == 2) chucNangTimMa();
        else if (chon == 3) chucNangTimLuong();
        else if (chon == 4) chucNangXoa();
        else if (chon == 5) chucNangCapNhat();
        else if (chon == 6) {
            if (goc == NULL) cout << "Danh sach nhan vien dang rong.\n";
            else { inTieuDe(); duyetLNR(goc); }
        }
        else if (chon == 7) {
            int dem = 0; double tong = 0, thap = 0, cao = 0;
            thongKeLuong(goc, dem, tong, thap, cao);
            if (dem == 0) cout << "Chua co nhan vien de thong ke.\n";
            else cout << fixed << setprecision(0) << "Luong trung binh: " << tong / dem
                      << " VND\nLuong thap nhat: " << thap
                      << " VND\nLuong cao nhat: " << cao << " VND\n";
        }
        else if (chon == 8) inLichSu();
        else if (chon == 9) inKPITheoCongGiamDan();
        else if (chon == 10) {
            int dem = 0; double tong = 0, thap = 0, cao = 0;
            thongKeLuong(goc, dem, tong, thap, cao);
            double tru = 0;
            tongTienTru(goc, tru);
            cout << fixed << setprecision(0) << "Tong quy luong thang: " << tong << " VND\n"
                 << "Tong tien da tru vi di tre: " << tru << " VND\n";
        }
        else if (chon == 11) hoanTacXoa();
        else if (chon == 12) { luuDuLieu(); cout << "Da luu du lieu vao " << TEN_FILE << ".\n"; }
    } while (chon != 0);
    luuDuLieu();
    giaiPhongCay(goc);
    giaiPhongLuong(gocLuong);
    while (dauLichSu != NULL) { LichSuLuong* p = dauLichSu; dauLichSu = dauLichSu->tiep; delete p; }
    while (dinhStack != NULL) { ThaoTac* p = dinhStack; dinhStack = dinhStack->tiep; delete p; }
    cout << "Da luu du lieu. Tam biet!\n";
    return 0;
}
