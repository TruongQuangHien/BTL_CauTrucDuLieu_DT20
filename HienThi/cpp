#include <iostream>
#include <iomanip>
#include "HienThi.h"

// ===================== IN AN =====================
void inTieuDe() {
    cout << left << setw(10) << "Ma NV" << setw(22) << "Ho ten"
         << setw(14) << "Chuc vu" << setw(14) << "Phong ban"
         << right << setw(8) << "He so" << setw(11) << "Phu cap"
         << setw(6) << "Cong" << setw(7) << "OT"
         << setw(6) << "Tre" << setw(11) << "Tien tru"
         << setw(15) << "Luong thuc linh" << "\n";
    cout << string(124, '-') << "\n";
}

void inMotNV(const NhanVien &nv) {
    cout << left << setw(10) << nv.maNV << setw(22) << nv.hoTen
         << setw(14) << nv.chucVu << setw(14) << nv.phongBan
         << right << setw(8) << fixed << setprecision(2) << nv.heSoLuong
         << setw(11) << setprecision(0) << nv.phuCap
         << setw(6) << nv.ngayCong
         << setw(7) << setprecision(1) << nv.gioOT
         << setw(6) << nv.ngayTre
         << setw(11) << setprecision(0) << tinhTienTru(nv)
         << setw(15) << setprecision(0) << tinhLuong(nv) << "\n";
}

// Duyet LNR: xuat danh sach tang dan theo ma
void duyetLNR(Node* p) {
    if (p == NULL) return;
    duyetLNR(p->trai);
    inMotNV(p->nv);
    duyetLNR(p->phai);
}
