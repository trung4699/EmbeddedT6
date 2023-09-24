#include "pch.h"

// Quan ly dat ve xem phim
// Them phim moi
// Danh sach phim
// Dat ve cho mot phim
// Kiem tra suc chua rap phim

#include <string>
#include <vector>
using namespace std;

enum class LoaiPhong{
    LOAI_THUONG,
    LOAI_TRUNG,
    LOAI_VIP
};

class Phim {
public:
    Phim(string ten, LoaiPhong loai);
    string getTen();
    LoaiPhong getLoaiPhong();
    int getSoVeDaDat();
    int getSoVeConLai();
    bool datVe(int soLuong);
    int getMaxSoVe();
private:
    string ten;
    LoaiPhong loai;
    int soVeDaDat;
};

Phim::Phim(string ten, LoaiPhong loai) : ten(ten), loai(loai), soVeDaDat(0) {}

string Phim::getTen() {
    return ten;
}

LoaiPhong Phim::getLoaiPhong() {
    return loai;
}

int Phim::getSoVeDaDat() {
    return soVeDaDat;
}

int Phim::getSoVeConLai() {
    return getMaxSoVe() - getSoVeDaDat();
}

bool Phim::datVe(int soLuong) {
    if (soLuong <= 0 || soLuong > getSoVeConLai()) {
        return false;
    }

    soVeDaDat += soLuong;
    return true;
}

int Phim::getMaxSoVe() {
    switch (loai)
    {
    case LoaiPhong::LOAI_THUONG:
        return 50;
        break;
    case LoaiPhong::LOAI_TRUNG:
        return 100;
        break;
    case LoaiPhong::LOAI_VIP:
        return 150;
        break;
    default:
        return 0;
        break;
    }
}

class RapChieuPhim
{
    public:
        void themPhim(Phim phim);
        vector <Phim> getDanhSachPhim();
        bool xoaPhim(Phim phim);
        bool datVePhim(Phim phim, int soLuong);
        int getSucChuaRapPhim();

    private:
        vector <Phim> DanhSachPhim;
};

void RapChieuPhim::themPhim(Phim phim)
{
    DanhSachPhim.push_back(phim);
}

vector <Phim> RapChieuPhim::getDanhSachPhim()
{
    return DanhSachPhim;
}

bool RapChieuPhim::xoaPhim(Phim phim)
{
    vector <Phim> ::iterator it, ptr;
    bool checkPhim = false;
    for (it = DanhSachPhim.begin(); it != DanhSachPhim.end(); ++it)
    {
        if ((*it).getTen() == phim.getTen() && (*it).getLoaiPhong() == phim.getLoaiPhong() )
        {
            ptr = it;
            checkPhim = true;
        }
    }

    if (checkPhim == true)
    {
        DanhSachPhim.erase(ptr);
        return true;
    }
    
    return false;

}

bool RapChieuPhim::datVePhim(Phim phim, int soLuong)
{
    vector <Phim> ::iterator it, ptr;
    bool checkDatVe = false;
    for (it = DanhSachPhim.begin(); it != DanhSachPhim.end(); ++it)
    {
        if ((*it).getTen() == phim.getTen() && (*it).getLoaiPhong() == phim.getLoaiPhong())
        {
           
            if ((*it).datVe(soLuong))
            {
                checkDatVe = true;
            }
        }
    }

    return checkDatVe;
}

int RapChieuPhim::getSucChuaRapPhim()
{
    int sucChua = 0;
    for (auto it : DanhSachPhim)
    {
        sucChua += it.getMaxSoVe();
    }
    return sucChua;
}


TEST(PhimTest, ThemPhimVaXoaPhim)
{
    Phim phim1("TrainToBusan", LoaiPhong::LOAI_THUONG);
    Phim phim2("Falling", LoaiPhong::LOAI_TRUNG);
    Phim phim3("Zombie", LoaiPhong::LOAI_VIP);

    RapChieuPhim CGV;
    ASSERT_EQ(CGV.getDanhSachPhim().size(), 0);

    CGV.themPhim(phim1);
    ASSERT_EQ(CGV.getDanhSachPhim().size(), 1);

    CGV.themPhim(phim2);
    ASSERT_EQ(CGV.getDanhSachPhim().size(), 2);

    ASSERT_EQ(CGV.xoaPhim(phim1), true);
    ASSERT_EQ(CGV.getDanhSachPhim().size(), 1);

    ASSERT_EQ(CGV.xoaPhim(phim3), false);
    ASSERT_EQ(CGV.getDanhSachPhim().size(), 1);
    
}

TEST(PhimTest, DatVe)
{
    Phim phim1("TrainToBusan", LoaiPhong::LOAI_THUONG);
    Phim phim2("Falling", LoaiPhong::LOAI_TRUNG);
    Phim phim3("Zombie", LoaiPhong::LOAI_VIP);
    Phim phim4("Empty", LoaiPhong::LOAI_VIP);

    RapChieuPhim CGV;
    CGV.themPhim(phim1);
    CGV.themPhim(phim2);
    CGV.themPhim(phim3);

    ASSERT_EQ(CGV.getDanhSachPhim().at(0).getMaxSoVe(), 50);
    ASSERT_EQ(CGV.getDanhSachPhim().at(1).getMaxSoVe(), 100);
    ASSERT_EQ(CGV.getDanhSachPhim().at(2).getMaxSoVe(), 150);

    ASSERT_EQ(CGV.datVePhim(phim1, 2), true);
    ASSERT_EQ(CGV.getDanhSachPhim().at(0).getSoVeConLai(), 48);

    ASSERT_EQ(CGV.datVePhim(phim2, 10), true);
    ASSERT_EQ(CGV.getDanhSachPhim().at(1).getSoVeConLai(), 90);

    ASSERT_EQ(CGV.datVePhim(phim3, 15), true);
    ASSERT_EQ(CGV.getDanhSachPhim().at(2).getSoVeConLai(), 135);

    ASSERT_EQ(CGV.datVePhim(phim4, 2), false);
}

TEST(PhimTest, SucChua)
{
    Phim phim1("TrainToBusan", LoaiPhong::LOAI_THUONG);
    Phim phim2("Falling", LoaiPhong::LOAI_TRUNG);
    Phim phim3("Zombie", LoaiPhong::LOAI_VIP);
  
    RapChieuPhim Lotte;

    Lotte.themPhim(phim1);
    ASSERT_EQ(Lotte.getSucChuaRapPhim(), 50);

    Lotte.themPhim(phim2);
    ASSERT_EQ(Lotte.getSucChuaRapPhim(), 150);

    Lotte.themPhim(phim3);
    ASSERT_EQ(Lotte.getSucChuaRapPhim(), 300);

    ASSERT_EQ(Lotte.xoaPhim(phim2), true);
    ASSERT_EQ(Lotte.getSucChuaRapPhim(), 200);
    

}


TEST(PhimTest, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}