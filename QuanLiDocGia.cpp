#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "QuanLiDocGia.h"

/*Ham lay thong tin cac doc gia tu file  */
void docDuLieuTuFile(DocGia** ds, int* n) {
    FILE* f;
    fopen_s(&f, "docgia.txt", "r");
    if (!f) {
        printf("Khong the mo file du lieu.\n");
        return;
    }

    fscanf_s(f, "%d\n", n);
    *ds = (DocGia*)malloc((*n) * sizeof(DocGia));

    for (int i = 0; i < *n; i++) {
        fscanf_s(f, "%s / %s / %s / %s / %s / %s / %s / %s / %s\n",
            (*ds)[i].maDocGia, MAX_CMND_LENGTH,
            (*ds)[i].hoTen, MAX_NAME_LENGTH, 
            (*ds)[i].CMND, MAX_CMND_LENGTH,
            (*ds)[i].ngaySinh, 11,
            (*ds)[i].gioiTinh, 10,
            (*ds)[i].email, MAX_EMAIL_LENGTH,
            (*ds)[i].diaChi, MAX_ADDRESS_LENGTH,
            (*ds)[i].ngayLapThe, 11, 
            (*ds)[i].ngayHetHan, 11);
    }
    fclose(f);
}

/*Ham ghi thong tin sau khi thay doi vao file  */
void ghiDuLieuVaoFile(DocGia* ds, int n) {
    FILE* f;
    fopen_s(&f, "docgia.txt", "w");
    if (!f) {
        printf("Khong the mo file de ghi.\n");
        return;
    }

    fprintf(f, "%d\n", n);
    for (int i = 0; i < n; i++) {
        fprintf(f, "%s / %s / %s / %s / %s / %s / %s / %s / %s\n",
            ds[i].maDocGia, ds[i].hoTen, ds[i].CMND, ds[i].ngaySinh,
            ds[i].gioiTinh, ds[i].email, ds[i].diaChi, ds[i].ngayLapThe, ds[i].ngayHetHan);
    }
    fclose(f);
}

/*  Ham xem danh sach cac Doc Gia trong thu vien  */
void xemDanhSach(DocGia* ds, int n) {
    printf("--------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("|                                                                DANH SACH DOC GIA                                                                     |\n");
    printf("--------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("| Ma          Ten                 CMND             Ngay sinh     Gioi tinh    Email                      Dia chi       Ngay lap the       Ngay het han |\n");
    printf("--------------------------------------------------------------------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < n; i++) {
        printf("|");
        printf(" %-10s  %-18s  %-15s  %-12s     %-6s    %-25s  %-12s  %s         %5s   |\n",
            ds[i].maDocGia, ds[i].hoTen, ds[i].CMND, ds[i].ngaySinh, 
            ds[i].gioiTinh, ds[i].email, ds[i].diaChi, ds[i].ngayLapThe, ds[i].ngayHetHan);
    }
    printf("--------------------------------------------------------------------------------------------------------------------------------------------------------\n");
}

/*  Ham them Doc Gia moi vao thu vien
        input: thong tin Doc Gia
        output: luu thong tin Doc Gia  */
void themDocGia(DocGia** ds, int* n) {
    (*n)++;
    *ds = (DocGia*)realloc(*ds, (*n) * sizeof(DocGia));

    printf("Nhap ma doc gia: ");
    scanf_s("%s", (*ds)[*n - 1].maDocGia, MAX_CMND_LENGTH);

    printf("Nhap ho ten: ");
    scanf_s("%s", (*ds)[*n - 1].hoTen, MAX_NAME_LENGTH);

    printf("Nhap CMND: ");
    scanf_s("%s", (*ds)[*n - 1].CMND, MAX_CMND_LENGTH);

    printf("Nhap ngay sinh (DD/MM/YYYY): ");
    scanf_s("%s", (*ds)[*n - 1].ngaySinh, 11);

    printf("Nhap gioi tinh: ");
    scanf_s("%s", (*ds)[*n - 1].gioiTinh, 10);

    printf("Nhap email: ");
    scanf_s("%s", (*ds)[*n - 1].email, MAX_EMAIL_LENGTH);

    printf("Nhap dia chi: ");
    scanf_s("%s", (*ds)[*n - 1].diaChi, MAX_ADDRESS_LENGTH);

    printf("Nhap ngay lap the (DD/MM/YYYY): ");
    scanf_s("%s", (*ds)[*n - 1].ngayLapThe, 11);

    printf("Nhap ngay het han '4 nam sau khi lap the' (DD/MM/YYYY): ");
    scanf_s("%s", (*ds)[*n - 1].ngayHetHan, 11);

    printf("da them doc gia vao danh sach !!");
}

/*  Ham chinh sua thong tin 1 Doc Gia trong thu vien
        input: nhap CMND Doc Gia va chon thong tin muon sua
        output: da cap nhat thong tin Doc Gia */
void suaThongTin(DocGia* ds, int n) {
    char cmnd[MAX_CMND_LENGTH];
    printf("Nhap CMND cua doc gia can sua: ");
    fgets(cmnd, MAX_CMND_LENGTH, stdin);
    cmnd[strcspn(cmnd, "\n")] = 0;

    int choice;
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(ds[i].CMND, cmnd) == 0) {
            found = 1;
            do
            {
                printf("\nThong tin cua doc gia\n");
                printf("\nMa: %-10s Ten: %-15s CMND: %-15s NgaySinh: %-12s  GioiTinh:   %-6s\nEmail:  %-20s DiaChi: %-10s NgayLapThe: %s  NgayHetHan: %s\n",
                    ds[i].maDocGia, ds[i].hoTen, ds[i].CMND, ds[i].ngaySinh,
                    ds[i].gioiTinh, ds[i].email, ds[i].diaChi, ds[i].ngayLapThe, ds[i].ngayHetHan);

                char maDocGia[MAX_CMND_LENGTH];
                char hoTen[MAX_NAME_LENGTH];
                char CMND[MAX_CMND_LENGTH];
                char ngaySinh[11];
                char gioiTinh[10];
                char email[MAX_EMAIL_LENGTH];
                char diaChi[MAX_ADDRESS_LENGTH];
                printf("\n===CHON THONG TIN CAN CHINH SUA===\n");
                printf("1. Ma doc gia\n");
                printf("2. Ten doc gia\n");
                printf("3. CMND\n");
                printf("4. Ngay sinh\n");
                printf("5. Gioi tinh\n");
                printf("6. Email\n");
                printf("7. Dia chi\n");
                printf("0. Quit.\n");
                printf("\nlua chon cua ban la: ");
                scanf_s("%d", &choice);
                switch (choice)
                {
                case 1:
                {
                    printf("\nnhap ma doc gia moi: ");
                    scanf_s("%s", maDocGia, MAX_CMND_LENGTH);
                    memcpy(ds[i].maDocGia, maDocGia, MAX_CMND_LENGTH);
                    printf("da cap nhat thong tin!!");
                    break;
                }
                case 2:
                {
                    printf("\nnhap ten doc gia moi(khong co khoang cach): ");
                    scanf_s("%s", hoTen, MAX_NAME_LENGTH);
                    memcpy(ds[i].hoTen, hoTen, MAX_NAME_LENGTH);
                    printf("da cap nhat thong tin!!");
                    break;
                }
                case 3:
                {
                    printf("\nnhap CMND moi: ");
                    scanf_s("%s", CMND, MAX_CMND_LENGTH);
                    memcpy(ds[i].CMND, CMND, MAX_CMND_LENGTH);
                    printf("da cap nhat thong tin!!");
                    break;
                }
                case 4:
                {
                    printf("\nnhap Ngay sinh moi: ");
                    scanf_s("%s", ngaySinh, 11);
                    memcpy(ds[i].ngaySinh, ngaySinh, 11);
                    printf("da cap nhat thong tin!!");
                    break;
                }
                case 5:
                {
                    printf("\nnhap Gioi tinh moi: ");
                    scanf_s("%s", gioiTinh, 10);
                    memcpy(ds[i].gioiTinh, gioiTinh, 10);
                    printf("da cap nhat thong tin!!");
                    break;
                }
                case 6:
                {
                    printf("\nnhap EMAIL moi: ");
                    scanf_s("%s", email, MAX_EMAIL_LENGTH);
                    memcpy(ds[i].email, email, MAX_EMAIL_LENGTH);
                    printf("da cap nhat thong tin!!");
                    break;
                }
                case 7:
                {
                    printf("\nnhap Dia chi moi: ");
                    scanf_s("%s", diaChi, MAX_ADDRESS_LENGTH);
                    memcpy(ds[i].diaChi, diaChi, MAX_ADDRESS_LENGTH);
                    printf("da cap nhat thong tin!!");
                    break;
                }
                break;
                case 0:
                    break;
                default:
                    printf("Lua chon khong hop le. Vui long chon lai.\n");
                }

            } while (choice);
        }
    }
    if (found==0) {
        printf("Khong tim thay doc gia voi CMND %s !!\n", cmnd);
    }
}

/*  Ham xoa thong tin 1 Doc Gia trong thu vien
        input: nhap CMND Doc Gia muon xoa thong tin
        output: da xoa thong tin Doc Gia  */
void xoaDocGia(DocGia** ds, int* n) {
    char cmnd[MAX_CMND_LENGTH];
    printf("Nhap CMND cua doc gia can xoa: ");
    fgets(cmnd, MAX_CMND_LENGTH, stdin);
    cmnd[strcspn(cmnd, "\n")] = 0;

    int found = 0;
    for (int i = 0; i < *n; i++) {
        if (strcmp((*ds)[i].CMND, cmnd) == 0) {
            found = 1;
            for (int j = i; j < *n - 1; j++) {
                (*ds)[j] = (*ds)[j + 1];
            }
            (*n)--;
            *ds = (DocGia*)realloc(*ds, (*n) * sizeof(DocGia));
            printf("Xoa doc gia thanh cong!!\n");
            break;
        }
    }
    if (!found) {
        printf("Khong tim thay doc gia voi CMND %s !!\n", cmnd);
    }
}

/*  Ham tim kiem Doc Gia theo CMND
        input: nhap CMND cua Doc Gia can tim
        output: thong tin cua Doc Gia can tim  */
void timKiemCMND(DocGia* ds, int n) {
    char cmnd[MAX_CMND_LENGTH];
    printf("Nhap CMND doc gia can tim: ");
    fgets(cmnd, MAX_CMND_LENGTH, stdin);
    cmnd[strcspn(cmnd, "\n")] = 0;

    int found = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(ds[i].CMND, cmnd) == 0) {
            printf("Tim thay doc gia\n");
            printf("\nMa: %-10s Ten: %-15s CMND: %-15s NgaySinh: %-12s  GioiTinh:   %-6s\nEmail:  %-20s DiaChi: %-10s NgayLapThe: %s  NgayHetHan: %s\n",
                ds[i].maDocGia, ds[i].hoTen, ds[i].CMND, ds[i].ngaySinh,
                ds[i].gioiTinh, ds[i].email, ds[i].diaChi, ds[i].ngayLapThe, ds[i].ngayHetHan);

            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Khong tim thay doc gia voi CMND %s !!\n", cmnd);
    }
}

/*  Ham tim kiem Doc Gia theo Ho Ten
        input: nhap Ho Ten cua Doc Gia can tim
        output: thong tin cua Doc Gia can tim  */
void timKiemTheoTen(DocGia* ds, int n) {
    char ten[MAX_NAME_LENGTH];
    printf("Nhap ten doc gia can tim (Khong co khoang cach): ");
    fgets(ten, MAX_NAME_LENGTH, stdin);
    ten[strcspn(ten, "\n")] = 0;

    int found = 0;
    for (int i = 0; i < n; i++) {
        if (strstr(ds[i].hoTen, ten) != NULL) {
            printf("Tim thay doc gia\n");
            printf("\nMa: %-10s Ten: %-15s CMND: %-15s NgaySinh: %-12s  GioiTinh:   %-6s\nEmail:  %-20s DiaChi: %-10s NgayLapThe: %s  NgayHetHan: %s\n",
                ds[i].maDocGia, ds[i].hoTen, ds[i].CMND, ds[i].ngaySinh,
                ds[i].gioiTinh, ds[i].email, ds[i].diaChi, ds[i].ngayLapThe, ds[i].ngayHetHan);
            found = 1;
        }
    }
    if (!found) {
        printf("Khong tim thay doc gia voi ten %s.\n", ten);
    }
}