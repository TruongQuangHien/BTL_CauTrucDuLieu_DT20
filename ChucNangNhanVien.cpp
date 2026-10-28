
#include <iostream>
#include <iomanip>
#include <limits>
#include <cstdlib>
#include <cmath>
#include <string>

#include "ChucNangNhanVien.h"
#include "CayNhanVien.h"
#include "CayLuong.h"
#include "NhapLieu.h"
#include "HienThi.h"
#include "DuLieuFile.h"
#include "LichSuLuong.h"
#include "LichSuThaoTac.h"

using namespace std;

// ===================== NHAP CHUOI =====================
string nhapChuoi(string thongBao) {
    string s;

    cout << thongBao;

    if (!getline(cin, s)) {
        exit(0);
    }

    // Loai bo khoang trang o dau va cuoi
    size_t dau = s.find_first_not_of(" \t\r\n");

    if (dau == string::npos) {
        return "";
    }

    size_t cuoi = s.find_last_not_of(" \t\r\n");
    s = s.substr(dau, cuoi - dau + 1);

    // Khong cho phep ky tu phan tach truong trong file
    for (size_t i = 0; i < s.size(); i++) {
        if (s[i] == '|') {
            s[i] = '-';
        }
    }

    return s;
}

// ===================== NHAP SO =====================
double nhapSo(string thongBao, double minVal, double maxVal) {
    double x;

    while (true) {
        cout << thongBao;

        if (!(cin >> x)) {
            if (cin.eof()) {
                exit(0);
            }

            cout << "Du lieu khong hop le. Vui long nhap lai!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (!isfinite(x)) {
            cout << "Gia tri phai la mot so huu han!\n";
            continue;
        }

        if (x < minVal || x > maxVal) {
            cout << "Gia tri phai nam trong khoang ["
                 << minVal << ", " << maxVal << "]!\n";
            continue;
        }

        return x;
    }
}

// ===================== THEM NHAN VIEN =====================
bool themNV(const NhanVien &nv) {
    bool trung = false;

    goc = themNode(goc, nv, trung);

    if (trung) {
        return false;
    }

    // Them dong thoi vao cay luong
    double luong = tinhLuong(nv);
    gocLuong = themLuong(gocLuong, luong, nv.maNV);

    return true;
}

// ===================== XOA NHAN VIEN =====================
bool xoaNV(const string &ma, NhanVien &nvDaXoa) {
    bool timThay = false;

    goc = xoaNode(goc, ma, timThay, nvDaXoa);

    if (!timThay) {
        return false;
    }

    // Xoa nhan vien tu cay luong
    double luong = tinhLuong(nvDaXoa);
    gocLuong = xoaLuong(gocLuong, luong, nvDaXoa.maNV);

    return true;
}

// ===================== THEM NHAN VIEN =====================
void chucNangThem() {
    cout << "\n========== THEM NHAN VIEN ==========\n";

    NhanVien nv = nhapNhanVien();

    if (nv.maNV.empty()) {
        cout << "Ma nhan vien khong duoc de trong!\n";
        return;
    }

    if (themNV(nv)) {
        cout << "Them nhan vien thanh cong!\n";
        luuDuLieu();
    } else {
        cout << "Ma nhan vien da ton tai!\n";
    }
}

// ===================== TIM NHAN VIEN THEO MA =====================
void chucNangTimMa() {
    cout << "\n========== TIM NHAN VIEN ==========\n";

    string ma = nhapChuoi("Nhap ma nhan vien can tim: ");

    if (ma.empty()) {
        cout << "Ma nhan vien khong duoc de trong!\n";
        return;
    }

    Node *p = timNode(goc, ma);

    if (p == NULL) {
        cout << "Khong tim thay nhan vien co ma " << ma << "!\n";
        return;
    }

    inTieuDe();
    inMotNV(p->nv);
}

// ===================== XOA NHAN VIEN =====================
void chucNangXoa() {
    cout << "\n========== XOA NHAN VIEN ==========\n";

    string ma = nhapChuoi("Nhap ma nhan vien can xoa: ");

    if (ma.empty()) {
        cout << "Ma nhan vien khong duoc de trong!\n";
        return;
    }

    NhanVien nv;

    if (!xoaNV(ma, nv)) {
        cout << "Khong tim thay nhan vien co ma " << ma << "!\n";
        return;
    }

    // Luu thong tin de ho tro hoan tac xoa
    dayStack(nv);

    cout << "Da xoa nhan vien " << nv.hoTen
         << " (ma: " << nv.maNV << ").\n";

    cout << "Thong tin da duoc dua vao lich su hoan tac.\n";

    luuDuLieu();
}

// ===================== CAP NHAT NHAN VIEN =====================
void chucNangCapNhat() {
    cout << "\n========== CAP NHAT NHAN VIEN ==========\n";

    string ma = nhapChuoi("Nhap ma nhan vien can cap nhat: ");

    if (ma.empty()) {
        cout << "Ma nhan vien khong duoc de trong!\n";
        return;
    }

    Node *p = timNode(goc, ma);

    if (p == NULL) {
        cout << "Khong tim thay nhan vien co ma " << ma << "!\n";
        return;
    }

    // Luu thong tin cu
    NhanVien cu = p->nv;

    cout << "\nNhap thong tin moi cho nhan vien.\n";
    cout << "Ma nhan vien duoc giu nguyen: " << cu.maNV << "\n";

    // Khong nhap lai ma nhan vien
    NhanVien moi = nhapNhanVien(false);
    moi.maNV = cu.maNV;

    // Tinh luong truoc va sau cap nhat
    double luongCu = tinhLuong(cu);
    double luongMoi = tinhLuong(moi);

    // Ghi lich su neu luong thay doi
    if (luongCu != luongMoi) {
        themLichSu(cu.maNV, luongCu, luongMoi);
    }

    // Cap nhat cay luong
    gocLuong = xoaLuong(gocLuong, luongCu, cu.maNV);
    gocLuong = themLuong(gocLuong, luongMoi, moi.maNV);

    // Cap nhat thong tin trong cay nhan vien
    p->nv = moi;

    cout << "Cap nhat nhan vien thanh cong!\n";

    luuDuLieu();
}
