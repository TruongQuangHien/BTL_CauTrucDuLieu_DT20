
#pragma once

#include <fstream>
#include "NhanVien.h"

// Ghi cay nhan vien vao file
void ghiCay(Node *p, std::ofstream &f);

// Luu du lieu tu RAM vao file
void luuDuLieu();

// Doc du lieu tu file vao RAM
void docDuLieu();
