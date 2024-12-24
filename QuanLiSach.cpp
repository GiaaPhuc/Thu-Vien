#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "QuanLiSach.h"

/*Ham lay thong tin cac Sach tu file  */
void docDuLieuTuFile(Sach** ds, int* n) {
    FILE* file;
    fopen_s(&file, "sach.txt", "r");
    if (!file) {
        printf("Khong the mo file sach.txt\n");
        return;
    }

    fscanf_s(file, "%d\n", n);
    *ds = (Sach*)malloc((*n) * sizeof(Sach));
    
    for (int i = 0; i < *n; i++) {
        fscanf_s(file, "%s / %s / %s / %s / %d / %s / %d / %d\n",
            (*ds)[i].ISBN, MAX_ISBN_LENGTH,
            (*ds)[i].TenSach, MAX_NAME_LENGTH,
            (*ds)[i].TacGia, MAX_NAME_LENGTH,
            (*ds)[i].NhaXuatBan, MAX_NAME_LENGTH,
            &(*ds)[i].NamXuatBan,
            (*ds)[i].TheLoai, MAX_THELOAI_LENGTH,
            &(*ds)[i].GiaSach,
            &(*ds)[i].SoQuyen);
    }
    fclose(file);
}

/*Ham ghi thong tin sau khi thay doi vao file  */
void ghiDuLieuVaoFile(Sach* ds, int n) {
    FILE* file;
    fopen_s(&file, "sach.txt", "w");
    if (!file) {
        printf("Khong the mo file sach.txt\n");
        return;
    }

    fprintf(file, "%d\n", n);
    for (int i = 0; i < n; i++) {
        fprintf(file, "%s / %s / %s / %s / %d / %s / %d / %d\n",
            ds[i].ISBN, ds[i].TenSach, ds[i].TacGia,
            ds[i].NhaXuatBan, ds[i].NamXuatBan, ds[i].TheLoai,
            ds[i].GiaSach, ds[i].SoQuyen);
    }
    fclose(file);
}

/*  Ham xem danh sach cac Sach trong thu vien  */
void hienThiDanhSach(Sach* ds, int n) {
    printf("-----------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("|                                                              DANH SACH CAC SACH                                                             |\n");
    printf("-----------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("| ISBN                Ten Sach                      Tac Gia           Nha xuat ban         Nam xuat ban      The loai    Gia Sach    So Luong |    \n");
    printf("-----------------------------------------------------------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < n; i++) {
        printf("|");
        printf(" %-18s  %-28s  %-16s  %-20s     %-10d    %-10s  %-10d  %d       |\n",
            ds[i].ISBN, ds[i].TenSach, ds[i].TacGia, ds[i].NhaXuatBan,
            ds[i].NamXuatBan, ds[i].TheLoai, ds[i].GiaSach, ds[i].SoQuyen);
    }
    printf("-----------------------------------------------------------------------------------------------------------------------------------------------\n");
}

/*  Ham them Sach moi vao thu vien
        input: thong tin Sach moi
        output: da them thong tin Sach moi  */
void themSach(Sach** ds, int* n) {
    (*n)++;
    *ds = (Sach*)realloc(*ds, (*n) * sizeof(Sach));

    printf("Nhap ISBN: "); 
    scanf_s("%s", (*ds)[*n - 1].ISBN, MAX_ISBN_LENGTH);

    printf("\nnhap ten Sach (khong co khoang cach): ");
    scanf_s("%s", (*ds)[*n - 1].TenSach, MAX_NAME_LENGTH);

    printf("\nnhap tac gia (khong co khoang cach): ");
    scanf_s("%s", (*ds)[*n - 1].TacGia, MAX_NAME_LENGTH);

    printf("\nnhap nha xuat ban (khong co khoang cach): ");
    scanf_s("%s", (*ds)[*n - 1].NhaXuatBan, MAX_NAME_LENGTH);

    printf("\nnhap nam xuat ban Sach: ");
    scanf_s("%d", &(*ds)[*n - 1].NamXuatBan);
    
    printf("\nnhap the loai Sach: ");
    scanf_s("%s", (*ds)[*n - 1].TheLoai, MAX_THELOAI_LENGTH);
   
    printf("\nnhap gia Sach: ");
    scanf_s("%d", &(*ds)[*n - 1].GiaSach);
    
    printf("\nnhap so quyen Sach: ");
    scanf_s("%d", &(*ds)[*n - 1].SoQuyen);
   
    printf("\n");

    printf("Them sach thanh cong!\n");
}

/*  Ham chinh sua thong tin 1 quyen Sach
        input: nhap ma Sach va chon thong tin muon sua cua Sach
        output: da sua thong tin cua Sach  */
void chinhSuaSach(Sach* ds, int n) {
    char isbn[MAX_ISBN_LENGTH];
    printf("Nhap ISBN cua sach can chinh sua: ");
    fgets(isbn, MAX_ISBN_LENGTH, stdin);
    isbn[strcspn(isbn, "\n")] = 0;

    int choice;
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(ds[i].ISBN, isbn) == 0) {
            found = 1;
            do
            {
                printf("ISBN: %-18s Ten Sach: %-19s Tac Gia: %-16s Nha Xuat Ban: %-20s \nNam Xuat Ban: %-10d   The Loai: %-10s Gia Sach: %-10d So Luong: %d\n",
                    ds[i].ISBN, ds[i].TenSach, ds[i].TacGia,
                    ds[i].NhaXuatBan, ds[i].NamXuatBan, ds[i].TheLoai,
                    ds[i].GiaSach, ds[i].SoQuyen);

                char ISBN[MAX_ISBN_LENGTH];
                char TenSach[MAX_NAME_LENGTH];
                char TacGia[MAX_NAME_LENGTH];
                char NhaXuatBan[MAX_NAME_LENGTH];
                int NamXuatBan;
                char TheLoai[MAX_THELOAI_LENGTH];
                int GiaSach;
                int SoQuyen;

                printf("\n===CHON THONG TIN CAN CHINH SUA===\n");
                printf("1. ISBN\n");
                printf("2. Ten sach\n");
                printf("3. Tac gia\n");
                printf("4. Nha xuat ban\n");
                printf("5. Nam xuat ban\n");
                printf("6. The loai\n");
                printf("7. Gia sach\n");
                printf("8. So quyen sach\n");
                printf("0. Quit\n");
                printf("\nlua chon cua ban la: ");
                scanf_s("%d", &choice);
                switch (choice)
                {
                case 1:
                {
                    printf("\nnhap ISBN moi: ");
                    scanf_s("%s", ISBN, MAX_ISBN_LENGTH);
                    memcpy(ds[i].ISBN, ISBN, MAX_ISBN_LENGTH);
                    printf("da cap nhat thong tin!!");
                    break;
                }
                case 2:
                {
                    printf("\nnhap ten Sach moi(khong co khoang cach): ");
                    scanf_s("%s", TenSach, MAX_NAME_LENGTH);
                    memcpy(ds[i].TenSach, TenSach, MAX_NAME_LENGTH);
                    printf("da cap nhat thong tin!!");
                    break;
                }
                case 3:
                {
                    printf("\nnhap Tac gia moi: ");
                    scanf_s("%s", TacGia, MAX_NAME_LENGTH);
                    memcpy(ds[i].TacGia, TacGia, MAX_NAME_LENGTH);
                    printf("da cap nhat thong tin!!");
                    break;
                }
                case 4:
                {
                    printf("\nnhap Nha xuat ban moi: ");
                    scanf_s("%s", NhaXuatBan, MAX_NAME_LENGTH);
                    memcpy(ds[i].NhaXuatBan, NhaXuatBan, MAX_NAME_LENGTH);
                    printf("da cap nhat thong tin!!");
                    break;
                }
                case 5:
                {
                    printf("\nnhap Nam xuat ban moi: ");
                    scanf_s("%d", &NamXuatBan);
                    ds[i].NamXuatBan = NamXuatBan;
                    printf("da cap nhat thong tin!!");
                    break;
                }
                case 6:
                {
                    printf("\nnhap The loai moi: ");
                    scanf_s("%s", TheLoai, MAX_THELOAI_LENGTH);
                    memcpy(ds[i].TheLoai, TheLoai, MAX_THELOAI_LENGTH);
                    printf("da cap nhat thong tin!!");
                    break;
                }
                case 7:
                {
                    printf("\nnhap Gia Sach moi: ");
                    scanf_s("%d", &GiaSach);
                    ds[i].GiaSach = GiaSach;
                    printf("da cap nhat thong tin!!");
                    break;
                }
                case 8:
                {
                    printf("\nnhap So luong Sach moi: ");
                    scanf_s("%d", &SoQuyen);
                    ds[i].SoQuyen = SoQuyen;
                    printf("da cap nhat thong tin!!");
                    break;
                }
                case 0:
                    break;
                default:
                    printf("Lua chon khong hop le. Vui long chon lai.\n");
                }

            } while (choice);
        }
    }
    if (found == 0) {
        printf("Khong tim thay Sach voi ISBN %s !!\n", isbn);
    }
}

/*  Ham xoa thong tin 1 Sach
        input: nhap ma Sach can xoa thong tin
        output: da xoa thong tin Sach  */
void xoaSach(Sach** ds, int* n) {
    char isbn[MAX_ISBN_LENGTH];
    printf("Nhap ISBN cua sach can xoa: ");
    scanf_s("%s", isbn, MAX_ISBN_LENGTH);

    int found = 0;
    for (int i = 0; i < *n; i++) {
        if (strcmp((*ds)[i].ISBN, isbn) == 0) {
            found = 1;
            for (int j = i; j < *n - 1; j++) {
                (*ds)[j] = (*ds)[j + 1];
            }
            (*n)--;
            *ds = (Sach*)realloc(*ds, (*n) * sizeof(Sach));
            printf("Xoa sach thanh cong!\n");
            break;
        }
    }
    if (!found) {
        printf("Khong tim thay Sach voi ISBN: %s !!\n", isbn);
    }
}

/*  Ham tim kiem Sach theo ISBN
        input: nhap ISBN cua Sach can tim
        output: thong tin cua Sach can tim  */
void timKiemTheoISBN(Sach* ds, int n) {
    char isbn[MAX_ISBN_LENGTH];
    printf("Nhap ISBN cua sach can tim: ");
    scanf_s("%s", isbn, MAX_ISBN_LENGTH);

    int found = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(ds[i].ISBN, isbn) == 0) {
            printf("Tim thay Sach\n");
            printf("ISBN: %-18s Ten Sach: %-19s Tac Gia: %-16s Nha Xuat Ban: %-20s \nNam Xuat Ban: %-10d   The Loai: %-10s Gia Sach: %-10d So Luong: %d\n",
                ds[i].ISBN, ds[i].TenSach, ds[i].TacGia,
                ds[i].NhaXuatBan, ds[i].NamXuatBan, ds[i].TheLoai,
                ds[i].GiaSach, ds[i].SoQuyen);

            found = 1;
            break;
        }
    }
    if (found == 0) {
        printf("Khong tim thay Sach voi ISBN %s !!\n", isbn);
    }
}

/*  Ham tim Sach theo Ten Sach
        input: nhap ten Sach can tim
        output: thong tin cua Sach can tim  */
void timKiemTheoTenSach(Sach* ds, int n) {
    char Ten[MAX_NAME_LENGTH];
    printf("Nhap Ten cua Sach can tim: ");
    scanf_s("%s", Ten, MAX_NAME_LENGTH);

    int found = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(ds[i].TenSach, Ten) == 0) {
            printf("Tim thay Sach\n");
            printf("ISBN: %-18s Ten Sach: %-19s Tac Gia: %-16s Nha Xuat Ban: %-20s \nNam Xuat Ban: %-10d   The Loai: %-10s Gia Sach: %-10d So Luong: %d\n",
                ds[i].ISBN, ds[i].TenSach, ds[i].TacGia,
                ds[i].NhaXuatBan, ds[i].NamXuatBan, ds[i].TheLoai,
                ds[i].GiaSach, ds[i].SoQuyen);

            found = 1;
            break;
        }
    }
    if (found == 0) {
        printf("Khong tim thay Sach voi Ten Sach %s !!\n", Ten);
    }
}
