#include "CayLuong.h"

// ===================== BST PHU (KHOA = LUONG, MA NV) =====================
bool nhoHon(double l1, const string &m1, double l2, const string &m2) {
    if (l1 != l2) return l1 < l2;
    return m1 < m2;
}

NodeLuong* themLuong(NodeLuong* p, double l, const string &ma) {
    if (p == NULL) return new NodeLuong(l, ma);
    if (nhoHon(l, ma, p->luong, p->maNV)) p->trai = themLuong(p->trai, l, ma);
    else p->phai = themLuong(p->phai, l, ma);
    return p;
}

NodeLuong* nhoNhatLuong(NodeLuong* p) {
    while (p != NULL && p->trai != NULL) p = p->trai;
    return p;
}

NodeLuong* xoaLuong(NodeLuong* p, double l, const string &ma) {
    if (p == NULL) return NULL;
    if (l == p->luong && ma == p->maNV) {
        if (p->trai == NULL) {
            NodeLuong* tam = p->phai;
            delete p;
            return tam;
        }
        if (p->phai == NULL) {
            NodeLuong* tam = p->trai;
            delete p;
            return tam;
        }
        NodeLuong* ke = nhoNhatLuong(p->phai);
        double lKe = ke->luong;
        string maKe = ke->maNV;
        p->luong = lKe;
        p->maNV = maKe;
        p->phai = xoaLuong(p->phai, lKe, maKe);
    } else if (nhoHon(l, ma, p->luong, p->maNV)) {
        p->trai = xoaLuong(p->trai, l, ma);
    } else {
        p->phai = xoaLuong(p->phai, l, ma);
    }
    return p;
}

void giaiPhongLuong(NodeLuong* p) {
    if (p == NULL) return;
    giaiPhongLuong(p->trai);
    giaiPhongLuong(p->phai);
    delete p;
}
