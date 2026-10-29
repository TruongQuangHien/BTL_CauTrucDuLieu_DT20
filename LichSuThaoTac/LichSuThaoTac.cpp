#include <iostream>
#include "LichSuThaoTac.h"
#include "ChucNangNhanVien.h"
#include "DuLieuFile.h"

void dayStack(const NhanVien &nv) {
    ThaoTac* p = new ThaoTac(nv);
    p->tiep = dinhStack;
    dinhStack = p;
}

bool layStack(NhanVien &nv) {
    if (dinhStack == NULL) return false;
    ThaoTac* p = dinhStack;
    nv = p->nv;
    dinhStack = p->tiep;
    delete p;
    return true;
}

void hoanTacXoa() {
    NhanVien nv;
    if (!layStack(nv)) {
        cout << "Khong co thao tac xoa nao de hoan tac.\n";
        return;
    }
    if (themNV(nv)) {
        cout << "Da khoi phuc nhan vien " << nv.maNV << ".\n";
        luuDuLieu();
    } else {
        cout << "Khong the khoi phuc vi ma NV da ton tai.\n";
    }
}
