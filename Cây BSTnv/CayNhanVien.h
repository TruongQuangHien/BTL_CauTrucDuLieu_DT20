#pragma once
#include "NhanVien.h"

// ===================== BST CHINH (KHOA = MA NV) =====================
Node* timNode(Node* p, const string &ma);
Node* themNode(Node* p, const NhanVien &nv, bool &trung);
Node* nodeNhoNhat(Node* p);
Node* xoaNode(Node* p, const string &ma, bool &timThay, NhanVien &nvDaXoa);
void giaiPhongCay(Node* p);
int demCay(Node* p);
