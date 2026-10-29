#include <iostream>
#include <iomanip>
#include "NhapLieu.h"
#include "ChucNangNhanVien.h"

// ===================== NHAP LIEU =====================
NhanVien nhapNhanVien(bool nhapMa) {
    NhanVien nv;
    if (nhapMa) nv.maNV = nhapChuoi("Nhap ma nhan vien: ");
    nv.hoTen = nhapChuoi("Nhap ho ten: ");
    nv.chucVu = nhapChuoi("Nhap chuc vu: ");
    nv.phongBan = nhapChuoi("Nhap phong ban: ");
    nv.heSoLuong = nhapSo("Nhap he so luong (0.1 - 100): ", 0.1, 100);
    nv.phuCap = nhapSo("Nhap phu cap (0 - 100000000): ", 0, 100000000);
    nv.ngayCong = (int)nhapSo("Nhap so ngay cong (0 - 31): ", 0, 31);
    nv.gioOT = nhapSo("Nhap so gio OT (0 - 200): ", 0, 200);
    nv.luongCoBan = nhapSo("Nhap muc luong co ban (VND, vi du 5000000): ", 1, 1000000000);
    cout << "(Quy dinh: moi ngay di tre bi tru " << fixed << setprecision(0)
         << TIEN_TRU_MOT_NGAY_TRE << " VND)\n";
    nv.ngayTre = (int)nhapSo("Nhap so ngay di tre (0 - so ngay cong): ", 0, nv.ngayCong);
    return nv;
}
