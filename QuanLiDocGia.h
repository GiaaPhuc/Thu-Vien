#pragma once
#define MAX_NAME_LENGTH 100
#define MAX_EMAIL_LENGTH 100
#define MAX_ADDRESS_LENGTH 200
#define MAX_CMND_LENGTH 20

typedef struct {
    char maDocGia[MAX_CMND_LENGTH];
    char hoTen[MAX_NAME_LENGTH];
    char CMND[MAX_CMND_LENGTH];
    char ngaySinh[11]; // Định dạng DD/MM/YYYY
    char gioiTinh[10];
    char email[MAX_EMAIL_LENGTH];
    char diaChi[MAX_ADDRESS_LENGTH];
    char ngayLapThe[11]; // Định dạng DD/MM/YYYY
    char ngayHetHan[11]; // Định dạng DD/MM/YYYY
} DocGia;

int QuanLidocGia();

void docDuLieuTuFile(DocGia** ds, int* n);
void ghiDuLieuVaoFile(DocGia* ds, int n);
void themDocGia(DocGia** ds, int* n);
void xemDanhSach(DocGia* ds, int n);
void suaThongTin(DocGia* ds, int n);
void xoaDocGia(DocGia** ds, int* n);
void timKiemCMND(DocGia* ds, int n);
void timKiemTheoTen(DocGia* ds, int n);
