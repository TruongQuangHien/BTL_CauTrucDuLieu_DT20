#include <iostream>
#include <iomanip>
#include "LichSuLuong.h"

// ===================== LICH SU (DSLK) & STACK =====================
void themLichSu(string ma, double cu, double moi) {
    LichSuLuong* p = new LichSuLuong(ma, cu, moi);
    p->tiep = dauLichSu;
    dauLichSu = p;
}

void inLichSu() {
    if (dauLichSu == NULL) {
        cout << "Chua co lich su thay doi luong trong phien lam viec nay.\n";
        return;
    }
    cout << left << setw(12) << "Ma NV" << setw(20) << "Luong cu" << "Luong moi\n";
    for (LichSuLuong* p = dauLichSu; p != NULL; p = p->tiep)
        cout << left << setw(12) << p->maNV << setw(20) << fixed << setprecision(0)
             << p->luongCu << p->luongMoi << "\n";
}
