#pragma once
#define MAX_ISBN_LENGTH 20
#define MAX_NAME_LENGTH 100
#define MAX_THELOAI_LENGTH 200
#define MAX_CMND_LENGTH 20

typedef struct {
    char ISBN[MAX_ISBN_LENGTH];
    char TenSach[MAX_NAME_LENGTH];
    char TacGia[MAX_NAME_LENGTH];
    char NhaXuatBan[MAX_NAME_LENGTH];
    int NamXuatBan;
    char TheLoai[MAX_THELOAI_LENGTH];
    int GiaSach;
    int SoQuyen;
} Sach;

int QuanLiSach();

void docDuLieuTuFile(Sach** ds, int* n);
void ghiDuLieuVaoFile(Sach* ds, int n);
void hienThiDanhSach(Sach* ds, int n);
void themSach(Sach** ds, int* n);
void chinhSuaSach(Sach* ds, int n);
void xoaSach(Sach** ds, int* n);
void timKiemTheoISBN(Sach* ds, int n);
void timKiemTheoTenSach(Sach* ds, int n);

void LapPhieuMuonSach();
void LapPhieuTraSach();