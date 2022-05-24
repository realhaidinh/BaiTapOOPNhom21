#pragma once
#include"Elements.h"
#include<string>

enum EClassID {
    //Kim
    ThieuLam = 0,
    ThienVuong,
    //Moc
    NguDoc,
    DuongMon,
    //Thuy
    NgaMy,
    ThuyYen,
    //Hoa
    CaiBang,
    ThienNhan,
    //Tho
    ConLon,
    VoDang
};

std::string getClassName(EClassID);
