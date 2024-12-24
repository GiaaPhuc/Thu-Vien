#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ThongKe.h"
#include "QuanLiDocGia.h"
#include "QuanLiSach.h"


/*  Ham thong ke so luong Sach trong thu vien
        output: so luong Sach cua loai va tong so luong Sach trong thu vien  */
void ThongkeSoLuongSach()
{
    Sach* ds = NULL;
    int n = 0;
    int tongsach = 0;
    docDuLieuTuFile(&ds, &n);

    printf("----------------------------------------------------------\n");
    printf("|                       SO LUONG SACH                    |\n");
    printf("----------------------------------------------------------\n");
    printf("| ISBN                Ten Sach                  So Luong |    \n");
    printf("----------------------------------------------------------\n");

    for (int i = 0; i < n; i++) {
        printf("|");
        printf(" %-18s  %-28s %d    |\n",
            ds[i].ISBN, ds[i].TenSach, ds[i].SoQuyen);
        tongsach = tongsach + ds[i].SoQuyen;
    }
    printf("----------------------------------------------------------\n");
    printf("| Tong so luong Sach = %d                               |\n", tongsach);
    printf("----------------------------------------------------------\n");

    free(ds);
}

/*  Ham thong ke so luong Sach theo the loai trong thu vien
        output: so luong Sach theo cac The Loai va tong so luong Sach trong thu vien  */
void ThongkeSoLuongSachtheoTheloai()
{
    Sach* ds = NULL;
    int n = 0;
    docDuLieuTuFile(&ds, &n);

    int tongsachCNTT = 0;
    int tongsachKhoaHoc = 0;
    int tongsachTamLiHoc = 0;
    int tongsachLichSu = 0;
    int tongsachKinhTe = 0;
    int tongsachToanHoc = 0;
    int tongsachTrietHoc = 0;
    int tongsach = 0;
    printf("-----------------------------------\n");
    printf("|   SO LUONG SACH THEO THE LOAI   |\n");
    printf("------------------------------------\n");
    printf("|   Theo loai          So Luong   |\n");
    printf("-----------------------------------\n");

    for (int i = 0; i < n; i++) {
       
        if (strcmp(ds[i].TheLoai, "CNTT") == 0)
        {
            tongsachCNTT = tongsachCNTT + ds[i].SoQuyen;
        }
        if (strcmp(ds[i].TheLoai, "KhoaHoc") == 0)
        {
            tongsachKhoaHoc = tongsachKhoaHoc + ds[i].SoQuyen;
        }
        if (strcmp(ds[i].TheLoai, "TamLiHoc") == 0)
        {
            tongsachTamLiHoc = tongsachTamLiHoc + ds[i].SoQuyen;
        }
        if (strcmp(ds[i].TheLoai, "LichSu") == 0)
        {
            tongsachLichSu = tongsachLichSu + ds[i].SoQuyen;
        }
        if (strcmp(ds[i].TheLoai, "KinhTe") == 0)
        {
            tongsachKinhTe = tongsachKinhTe + ds[i].SoQuyen;
        }
        if (strcmp(ds[i].TheLoai, "ToanHoc") == 0)
        {
            tongsachToanHoc = tongsachToanHoc + ds[i].SoQuyen;
        }
        if (strcmp(ds[i].TheLoai, "TrietHoc") == 0)
        {
            tongsachTrietHoc = tongsachTrietHoc + ds[i].SoQuyen;
        }
        tongsach = tongsach + ds[i].SoQuyen;
    }
    printf("|   CNTT                 %-5d    |\n", tongsachCNTT);
    printf("|   KhoaHoc              %-5d    |\n", tongsachKhoaHoc);
    printf("|   TamLiHoc             %-5d    |\n", tongsachTamLiHoc);
    printf("|   LichSu               %-5d    |\n", tongsachLichSu);
    printf("|   KinhTe               %-5d    |\n", tongsachKinhTe);
    printf("|   ToanHoc              %-5d    |\n", tongsachToanHoc);
    printf("|   TrietHoc             %-5d    |\n", tongsachTrietHoc);
    printf("-----------------------------------\n");
    printf("| Tong so luong Sach = %-6d     |\n", tongsach);
    printf("-----------------------------------\n");
    
    free(ds);
}

/*  Ham thong ke so luong Doc Gia trong thu vien
        output: so luong Doc Gia trong thu vien  */
void ThongkeSoLuongDocGia()
{
    DocGia* ds = NULL;
    int n = 0;

    docDuLieuTuFile(&ds, &n);
   
    printf("--------------------------------\n");
    printf("| So luong Doc Gia la: %-4d    |\n", n);
    printf("--------------------------------\n");

    free(ds);
}

/*  Ham thong ke so luong Doc Gia theo gioi tinh
        output: so luong Doc Gia gioi tinh Nam
                so luong Doc Gia gioi tinh Nu  */
void ThongkeSoLuongDocGiatheoGioiTinh()
{
    DocGia* ds = NULL;
    int n = 0;
    docDuLieuTuFile(&ds, &n);

    int tongNam = 0;
    int tongNu = 0;

    for (int i = 0; i < n; i++) {

        if (strcmp(ds[i].gioiTinh, "Nam") == 0)
            tongNam++;
        if (strcmp(ds[i].gioiTinh, "Nu") == 0)
            tongNu++;
    }

    printf("\n");
    printf("Tong Doc Gia Nam la: %d\n", tongNam);
    printf("Tong Doc Gia Nu  la: %d\n", tongNu);

    free(ds);
}

/*  Ham thong ke Sach duoc muon trong thu vien
        output: danh sach cac Sach duoc muon trong thu vien  */
void ThongkesoSachduocmuon()
{
    char maDocGia[MAX_CMND_LENGTH];
    char hoTen[MAX_NAME_LENGTH];
    int ngaymuon, thangmuon, nammuon;
    int ngaytradukien, thangtradukien, namtradukien;
    char ISBN[MAX_ISBN_LENGTH];
    int GiaSach;
    FILE* file;
    fopen_s(&file, "muonSach.txt", "r");
    if (file)
    {
        printf("------------------------------------------------------------------------------------------------------\n");
        printf("|                                   Danh Sach Cac Sach Duoc Muon                                     |\n");
        printf("------------------------------------------------------------------------------------------------------\n");
        printf("| Ma Doc Gia     Ten Doc Gia                Ngay Muon      Ngay Tra Du Kien     ISBN Sach Duoc Muon  |    \n");
        printf("------------------------------------------------------------------------------------------------------\n");
        int soluong = 0;
        while (!feof(file))
        {
            fscanf_s(file, "%s / %s / %d-%d-%d / %d-%d-%d / %s / %d\n",
                maDocGia, MAX_CMND_LENGTH,
                hoTen, MAX_NAME_LENGTH,
                &ngaymuon, &thangmuon, &nammuon,
                &ngaytradukien, &thangtradukien, &namtradukien,
                ISBN, MAX_ISBN_LENGTH,
                &GiaSach);
            soluong++;
            printf("| ");
            printf("%-13s  %-25s  %d-%d-%-10d  %d-%d-%-10d  %s       |\n",
                maDocGia,
                hoTen,
                ngaymuon, thangmuon, nammuon,
                ngaytradukien, thangtradukien, namtradukien,
                ISBN);
        }
        fclose(file);
        printf("------------------------------------------------------------------------------------------------------\n");
        printf("| So luong Sach duoc muon la: %-3d                                                                    |\n", soluong);
        printf("------------------------------------------------------------------------------------------------------\n");
    }
    else
    {
        printf("Khong co Sach duoc muon !!\n");
    }
}

/*  Ham thong ke cac Doc Gia bi tre han tra Sach
        output: danh sach cac Doc Gia bi tre han tra Sach  */
void ThongkeDocGiaBiTreHan()
{
    int ngayhientai, thanghientai, namhientai;
    printf("nhap ngay hien tai (dd-mm-yyyy): ");
    scanf_s("%d-%d-%d", &ngayhientai, &thanghientai, &namhientai);
    printf("\n");
    char maDocGia[MAX_CMND_LENGTH];
    char hoTen[MAX_NAME_LENGTH];
    int ngaymuon, thangmuon, nammuon;
    int ngaytradukien, thangtradukien, namtradukien;
    char ISBN[MAX_ISBN_LENGTH];
    int GiaSach;
    FILE* file;
    fopen_s(&file, "muonSach.txt", "r");
    if (file)
    {
        printf("------------------------------------------------------------------------------------------------------\n");
        printf("|                                 Danh Sach Cac Doc Gia Bi Tre han                                   |\n");
        printf("------------------------------------------------------------------------------------------------------\n");
        printf("| Ma Doc Gia     Ten Doc Gia                Ngay Muon      Ngay Tra Du Kien     ISBN Sach Duoc Muon  |    \n");
        printf("------------------------------------------------------------------------------------------------------\n");
        while (!feof(file))
        {
            fscanf_s(file, "%s / %s / %d-%d-%d / %d-%d-%d / %s / %d\n",
                maDocGia, MAX_CMND_LENGTH,
                hoTen, MAX_NAME_LENGTH,
                &ngaymuon, &thangmuon, &nammuon,
                &ngaytradukien, &thangtradukien, &namtradukien,
                ISBN, MAX_ISBN_LENGTH,
                &GiaSach);
            if (((ngayhientai + thanghientai * 30 + namhientai * 360) - (ngaymuon + thangmuon * 30 + nammuon * 360)) > 7)
            {
                printf("| ");
                printf("%-13d  %-25s  %d-%d-%-10d  %d-%d-%-10d  %s       |\n",
                    maDocGia,
                    hoTen,
                    ngaymuon, thangmuon, nammuon,
                    ngaytradukien, thangtradukien, namtradukien,
                    ISBN);
            }

        }
        fclose(file);
        printf("------------------------------------------------------------------------------------------------------\n");
    }
    else
    {
        printf("Khong co Sach duoc muon !!\n");
    }
}