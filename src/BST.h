// BST.h - Cay nhi phan tim kiem quan ly nhan vien
#pragma once
#include <iostream>
#include <string>
using namespace std;

struct NhanVien {
    string maNV;
    string hoTen;
    double luong;
};

struct Node {
    NhanVien data;
    Node* left;
    Node* right;
};
