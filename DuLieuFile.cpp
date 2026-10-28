
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>

#include "DuLieuFile.h"
#include "CayNhanVien.h"
#include "ChucNangNhanVien.h"

using namespace std;

// ===================== GHI MOT NHAN VIEN =====================
void ghiCay(Node *p, ofstream &f) {
    if (p == NULL) {
        return;
    }

    const NhanVien &nv = p->nv;

    f << nv.maNV << '|'
      << nv.hoTen << '|'
      << nv.chucVu << '|'
      << nv.phongBan << '|'
      << nv.heSoLuong << '|'
      << nv.phuCap << '|'
      << nv.ngayCong << '|'
      << nv.gioOT << '|'
      << nv.luongCoBan << '|'
      << nv.ngayTre << '\n';

    ghiCay(p->trai, f);
    ghiCay(p->phai, f);
}

// ===================== LUU DU LIEU =====================
void luuDuLieu() {
    ofstream f(TEN_FILE.c_str());

    if (!f.is_open()) {
        cout << "Loi: Khong mo duoc file "
             << TEN_FILE << " de ghi!\n";
        return;
    }

    // Luu so thuc voi 2 chu so thap phan
    f << fixed << setprecision(2);

    ghiCay(goc, f);

    f.close();

    if (f.fail()) {
        cout << "Canh bao: Co loi khi ghi file!\n";
    }
}

// ===================== DOC DU LIEU =====================
void docDuLieu() {
    ifstream f(TEN_FILE.c_str());

    // File chua ton tai: co the la lan chay dau tien
    if (!f.is_open()) {
        return;
    }

    string dong;

    while (getline(f, dong)) {
        if (dong.empty()) {
            continue;
        }

        // Tach cac truong bang dau |
        vector<string> truong;
        stringstream ss(dong);
        string tam;

        while (getline(ss, tam, '|')) {
            truong.push_back(tam);
        }

        // Bo qua dong co dinh dang khong hop le
        if (truong.size() != 10 && truong.size() != 8) {
            continue;
        }

        NhanVien nv;

        try {
            if (truong.size() == 10) {
                // Dinh dang moi: 10 truong
                nv.maNV       = truong[0];
                nv.hoTen       = truong[1];
                nv.chucVu      = truong[2];
                nv.phongBan    = truong[3];
                nv.heSoLuong   = stod(truong[4]);
                nv.phuCap      = stod(truong[5]);
                nv.ngayCong    = stoi(truong[6]);
                nv.gioOT       = stod(truong[7]);
                nv.luongCoBan  = stod(truong[8]);
                nv.ngayTre     = stoi(truong[9]);
            } else {
                // Dinh dang cu: 8 truong
                // maNV|hoTen|phongBan|heSoLuong|phuCap|
                // ngayCong|gioOT|luongCoBan

                nv.maNV       = truong[0];
                nv.hoTen       = truong[1];
                nv.chucVu      = "";
                nv.phongBan    = truong[2];
                nv.heSoLuong   = stod(truong[3]);
                nv.phuCap      = stod(truong[4]);
                nv.ngayCong    = stoi(truong[5]);
                nv.gioOT       = stod(truong[6]);
                nv.luongCoBan  = stod(truong[7]);
                nv.ngayTre     = 0;
            }
        } catch (...) {
            // Bo qua dong co truong so khong chuyen doi duoc
            continue;
        }

        // Khong nap nhan vien thieu ma
        if (nv.maNV.empty()) {
            continue;
        }

        // Them vao ca cay nhan vien va cay luong.
        // Neu ma da ton tai, themNV se tu choi.
        themNV(nv);
    }

    f.close();
}
