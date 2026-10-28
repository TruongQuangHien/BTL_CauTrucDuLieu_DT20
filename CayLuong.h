#pragma once
#include "NhanVien.h"

// ===================== BST PHU (KHOA = LUONG, MA NV) =====================
bool nhoHon(double l1, const string &m1, double l2, const string &m2);
NodeLuong* themLuong(NodeLuong* p, double l, const string &ma);
NodeLuong* nhoNhatLuong(NodeLuong* p);
NodeLuong* xoaLuong(NodeLuong* p, double l, const string &ma);
void giaiPhongLuong(NodeLuong* p);
