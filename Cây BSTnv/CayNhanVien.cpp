#include "CayNhanVien.h"

// ===================== BST CHINH (KHOA = MA NV) =====================
Node* timNode(Node* p, const string &ma) {
    if (p == NULL || p->nv.maNV == ma) return p;
    if (ma < p->nv.maNV) return timNode(p->trai, ma);
    return timNode(p->phai, ma);
}

Node* themNode(Node* p, const NhanVien &nv, bool &trung) {
    if (p == NULL) return new Node(nv);
    if (nv.maNV == p->nv.maNV) {
        trung = true;
        return p;
    }
    if (nv.maNV < p->nv.maNV) p->trai = themNode(p->trai, nv, trung);
    else p->phai = themNode(p->phai, nv, trung);
    return p;
}

Node* nodeNhoNhat(Node* p) {
    while (p != NULL && p->trai != NULL) p = p->trai;
    return p;
}

// Xoa node: du 3 truong hop (la, mot con, hai con)
Node* xoaNode(Node* p, const string &ma, bool &timThay, NhanVien &nvDaXoa) {
    if (p == NULL) return NULL;
    if (ma < p->nv.maNV) p->trai = xoaNode(p->trai, ma, timThay, nvDaXoa);
    else if (ma > p->nv.maNV) p->phai = xoaNode(p->phai, ma, timThay, nvDaXoa);
    else {
        timThay = true;
        nvDaXoa = p->nv;
        if (p->trai == NULL) {            // la hoac chi co con phai
            Node* tam = p->phai;
            delete p;
            return tam;
        }
        if (p->phai == NULL) {            // chi co con trai
            Node* tam = p->trai;
            delete p;
            return tam;
        }
        Node* ke = nodeNhoNhat(p->phai);  // hai con: thay bang node ke tiep
        p->nv = ke->nv;
        bool boQua = false;
        NhanVien nvTam;
        p->phai = xoaNode(p->phai, ke->nv.maNV, boQua, nvTam);
    }
    return p;
}

void giaiPhongCay(Node* p) {
    if (p == NULL) return;
    giaiPhongCay(p->trai);
    giaiPhongCay(p->phai);
    delete p;
}

int demCay(Node* p) {
    if (p == NULL) return 0;
    return 1 + demCay(p->trai) + demCay(p->phai);
}
