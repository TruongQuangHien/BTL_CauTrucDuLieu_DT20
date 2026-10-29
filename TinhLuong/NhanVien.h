#pragma once
#include <string>
#include <cstddef>
struct NhanVien {
    std::string maNV, hoTen, chucVu, phongBan;
    double heSoLuong, phuCap;
    int ngayCong;
    double gioOT;
    double luongCoBan;
    int ngayTre;           
};
struct Node {
    NhanVien nv;
    Node *trai, *phai;
    Node(NhanVien x) {
        nv = x;
        trai = NULL;
        phai = NULL;
    }
};
struct NodeLuong {
    double luong;
    std::string maNV;
    NodeLuong *trai, *phai;
    NodeLuong(double l, std::string ma) {
        luong = l;
        maNV = ma;
        trai = NULL;
        phai = NULL;
    }
};
struct LichSuLuong {
    std::string maNV;
    double luongCu, luongMoi;
    LichSuLuong *tiep;
    LichSuLuong(std::string ma, double cu, double moi) {
        maNV = ma;
        luongCu = cu;
        luongMoi = moi;
        tiep = NULL;
    }
};
struct ThaoTac {
    NhanVien nv;
    ThaoTac *tiep;
    ThaoTac(NhanVien x) {
        nv = x;
        tiep = NULL;
    }
};
const std::string TEN_FILE = "nhanvien.txt";
const double HE_SO_OT = 1.5;
const double TIEN_TRU_MOT_NGAY_TRE = 50000.0; 
extern Node* goc;
extern NodeLuong* gocLuong;
extern LichSuLuong* dauLichSu;
extern ThaoTac* dinhStack;
double tinhTienTru(const NhanVien &nv);
double tinhLuong(const NhanVien &nv);