#include <iostream>
#include <iomanip>
#include "ThongKe.h"
#include "CayNhanVien.h"
#include "HienThi.h"
#include "NhapLieu.h"
#include "ChucNangNhanVien.h"

// Tim luong >= muc tren BST luong: bo qua nhanh trai khi node < muc
// -> do phuc tap O(h + k), k la so ket qua. Ket qua tang dan theo luong.
void timTheoLuong(NodeLuong* p, double muc, bool &daIn) {
    if (p == NULL) return;
    if (p->luong >= muc) {
        timTheoLuong(p->trai, muc, daIn);
        Node* n = timNode(goc, p->maNV);
        if (n != NULL) {
            if (!daIn) inTieuDe();
            inMotNV(n->nv);
            daIn = true;
        }
    }
    timTheoLuong(p->phai, muc, daIn);
}

void chucNangTimLuong() {
    double muc = nhapSo("Nhap muc luong toi thieu (VND): ", 0, 1000000000000.0);
    bool daIn = false;
    timTheoLuong(gocLuong, muc, daIn);
    if (!daIn) cout << "Khong co nhan vien nao dat muc luong nay.\n";
}

void thongKeLuong(Node* p, int &soLuong, double &tong, double &thapNhat, double &caoNhat) {
    if (p == NULL) return;
    double l = tinhLuong(p->nv);
    if (soLuong == 0 || l < thapNhat) thapNhat = l;
    if (soLuong == 0 || l > caoNhat) caoNhat = l;
    soLuong++;
    tong += l;
    thongKeLuong(p->trai, soLuong, tong, thapNhat, caoNhat);
    thongKeLuong(p->phai, soLuong, tong, thapNhat, caoNhat);
}

// Tong tien da tru vi di tre cua toan cong ty
void tongTienTru(Node* p, double &tong) {
    if (p == NULL) return;
    tongTienTru(p->trai, tong);
    tong += tinhTienTru(p->nv);
    tongTienTru(p->phai, tong);
}

// Thu thap nhan vien vao mang dong
void thuThap(Node* p, NhanVien ds[], int &n) {
    if (p == NULL) return;
    thuThap(p->trai, ds, n);
    ds[n++] = p->nv;
    thuThap(p->phai, ds, n);
}

void inKPITheoCongGiamDan() {
    int tong = demCay(goc);
    if (tong == 0) {
        cout << "Danh sach nhan vien dang rong.\n";
        return;
    }
    NhanVien* ds = new NhanVien[tong];
    int n = 0;
    thuThap(goc, ds, n);
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (ds[j].ngayCong > ds[i].ngayCong) {
                NhanVien tam = ds[i];
                ds[i] = ds[j];
                ds[j] = tam;
            }
    cout << left << setw(12) << "Ma NV" << setw(24) << "Ho ten" << setw(14) << "Ngay cong" << "KPI\n";
    for (int i = 0; i < n; i++) {
        string loai = ds[i].ngayCong >= 26 ? "A" : ds[i].ngayCong >= 22 ? "B" : ds[i].ngayCong >= 16 ? "C" : "D";
        cout << left << setw(12) << ds[i].maNV << setw(24) << ds[i].hoTen
             << setw(14) << ds[i].ngayCong << loai << "\n";
    }
    delete[] ds;
}
