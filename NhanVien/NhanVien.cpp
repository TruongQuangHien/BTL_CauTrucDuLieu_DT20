#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <limits>
#include <cstdlib>
#include "NhanVien.h"
using namespace std;
Node* goc = NULL;
NodeLuong* gocLuong = NULL;
LichSuLuong* dauLichSu = NULL;
ThaoTac* dinhStack = NULL;
double tinhTienTru(const NhanVien &nv) {
    return nv.ngayTre * TIEN_TRU_MOT_NGAY_TRE;
}

double tinhLuong(const NhanVien &nv) {
    double luongTheoHeSo = nv.heSoLuong * nv.luongCoBan;
    double luongNgayCong = luongTheoHeSo * nv.ngayCong / 26.0;
    double luongOT = (luongTheoHeSo / 26.0 / 8.0) * HE_SO_OT * nv.gioOT;
    double luong = luongNgayCong + nv.phuCap + luongOT - tinhTienTru(nv);
    return luong < 0 ? 0 : luong;     // luong thuc linh khong am
}
