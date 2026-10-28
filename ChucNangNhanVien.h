
#pragma once

#include <string>
#include "NhanVien.h"

// Ham nhap lieu
std::string nhapChuoi(std::string thongBao);
double nhapSo(std::string thongBao, double minVal, double maxVal);

// Cac ham nghiep vu, dong bo cay nhan vien va cay luong
bool themNV(const NhanVien &nv);
bool xoaNV(const std::string &ma, NhanVien &nvDaXoa);

// Cac chuc nang nhan vien
void chucNangThem();
void chucNangTimMa();
void chucNangXoa();
void chucNangCapNhat();
