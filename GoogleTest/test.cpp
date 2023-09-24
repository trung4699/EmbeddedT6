#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include "gtest/gtest.h"


using namespace std;

// them sinh vien
// xoa sinh vien theo ID
// lay diem trung binh
// xuat thong tin sinh vien


class SinhVien {
public:
    SinhVien(int id, string name, double diem);
    int getID();
    string getName();
    double getDiem();
private:
    int id;
    string name;
    double diem;
};

SinhVien::SinhVien(int id, string name, double diem) : id(id), name(name), diem(diem) {}

int SinhVien::getID() {
    return id;
}

string SinhVien::getName() {
    return name;
}

double SinhVien::getDiem() {
    return diem;
}

class QuanLySinhVien {
    public:
        void themSinhVien(int id, string name, double diem);
        bool xoaSinhVien(int id);
        double getDiemTrungBinh();
        vector<SinhVien> getDanhSachSinhVien();
    private:
        vector<SinhVien> danhDachSinhVien;
};

void QuanLySinhVien::themSinhVien(int id, string name, double diem) {
    danhDachSinhVien.emplace_back(id, name, diem);
}

bool QuanLySinhVien::xoaSinhVien(int id) {
    auto it = remove_if(danhDachSinhVien.begin(), danhDachSinhVien.end(),
        [id](SinhVien& sv) {return sv.getID() == id; });

    if (it != danhDachSinhVien.end()) {
        danhDachSinhVien.erase(it, danhDachSinhVien.end());
        return true;
    }
    return false;
}

double QuanLySinhVien::getDiemTrungBinh() {
    if (danhDachSinhVien.empty()) return 0.0;

    double tongDiem = 0.0;

    for (SinhVien& sv : danhDachSinhVien) {
        tongDiem += sv.getDiem();
    }
    return tongDiem / danhDachSinhVien.size();
}

vector<SinhVien> QuanLySinhVien::getDanhSachSinhVien() {
    return danhDachSinhVien;
}


TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(QuanLySinhVienTest, ThemVaXoaSinhVien) {
    QuanLySinhVien ql;
    ql.themSinhVien(1, "Nguyen A", 8.5);
    ql.themSinhVien(2, "Nguyen B", 7.4);

    ASSERT_EQ(ql.getDanhSachSinhVien().size(), 2);

    ql.xoaSinhVien(1);

    ASSERT_EQ(ql.getDanhSachSinhVien().size(), 1);
}

TEST(QuanLySinhVienTest, DiemTrungBinh) {
    QuanLySinhVien ql;
    ql.themSinhVien(1, "Nguyen A", 8.5);
    ql.themSinhVien(2, "Nguyen B", 7.4);
    ASSERT_DOUBLE_EQ(ql.getDiemTrungBinh(), 7.95);
}

TEST(QuanLySinhVienTest, XoaSinhVienKhongTonTai) {
    QuanLySinhVien ql;
    ql.themSinhVien(1, "Nguyen A", 8.5);
    ql.themSinhVien(2, "Nguyen B", 7.4);

    ql.xoaSinhVien(3);
    ASSERT_EQ(ql.getDanhSachSinhVien().size(), 2);
}

TEST(QuanLySinhVienTest, DanhSachRong) {
    QuanLySinhVien ql;

    ASSERT_EQ(ql.getDanhSachSinhVien().size(), 0);
}