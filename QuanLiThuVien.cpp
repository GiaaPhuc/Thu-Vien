#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "QuanLiDocGia.h"
#include "QuanLiSach.h"
#include "ThongKe.h"


int main()
{

	int choice;
	do
	{
		printf("\n===========MENU===========\n");
		printf("1. Quan li doc gia\n");
		printf("2. Quan li sach\n");
		printf("3. Lap phieu muon sach\n");
		printf("4. Lap phieu tra sach\n");
		printf("5. Cac thong ke co ban\n");
		printf("0. Quit\n");
		printf("--------------------------\n");
		printf("lua chon cua ban la: ");
		scanf_s("%d", &choice);
		printf("\n");
		switch (choice)
		{
		case 1:
		{
			QuanLidocGia();
			break;
		}
		case 2:
		{
			QuanLiSach();
			break;
		}
		case 3:
		{
			LapPhieuMuonSach();
			break;
		}
		case 4:
		{
			LapPhieuTraSach();
			break;
		}
		case 5:
		{
			CacThongKeCoBan();
			break;
		}
		case 0:
            printf("Thoat chuong trinh....\n");
			break;
		default:
			break;
		}

	} while (choice);
	return 0;
}

// quan li Doc Gia trong thu vien
int QuanLidocGia() {
    DocGia* ds = NULL;
    int n = 0;

    docDuLieuTuFile(&ds, &n);

    int luaChon;
    do {
        printf("\n====Quan Ly Doc Gia Thu Vien====\n");
        printf("1. Xem danh sach doc gia\n");
        printf("2. Them doc gia\n");
        printf("3. Sua thong tin doc gia\n");
        printf("4. Xoa doc gia\n");
        printf("5. Tim kiem doc gia theo CMND\n");
        printf("6. Tim kiem doc gia theo ten\n");
        printf("0. Luu thay doi va Quay lai MENU\n");
        printf("Chon chuc nang: ");
        scanf_s("%d", &luaChon);
		getchar();

        switch (luaChon) {
        case 1:
            xemDanhSach(ds, n);
            break;
        case 2:
            themDocGia(&ds, &n);
            break;
        case 3:
            suaThongTin(ds, n);
            break;
        case 4:
            xoaDocGia(&ds, &n);
            break;
        case 5:
            timKiemCMND(ds, n);
            break;
        case 6:
            timKiemTheoTen(ds, n);
            break;
        case 0:
            ghiDuLieuVaoFile(ds, n);
            break;
        default:
            printf("Lua chon khong hop le. Vui long chon lai.\n");
            break;
        }
    } while (luaChon);

    free(ds); 
    return 0;
}

// quan li Sach trong thu vien
int QuanLiSach()
{
    Sach* ds = NULL;
    int n = 0;

    docDuLieuTuFile(&ds, &n);

    int luaChon;
    do {
        printf("\nChuong trinh quan ly thu vien\n");
        printf("1. Xem danh sach sach\n");
        printf("2. Them sach moi\n");
        printf("3. Chinh sua thong tin sach\n");
        printf("4. Xoa sach\n");
        printf("5. Tim kiem sach theo ISBN\n");
        printf("6. Tim kiem sach theo ten\n");
        printf("0. Luu thay doi va Quay lai MENU\n");
        printf("Nhap lua chon: ");
        scanf_s("%d", &luaChon);

        switch (luaChon) {
        case 1:
            hienThiDanhSach(ds, n);
            break;
        case 2:
            themSach(&ds, &n);
            break;
        case 3:
            chinhSuaSach(ds, n);
            break;
        case 4:
            xoaSach(&ds, &n);
            break;
        case 5:
            timKiemTheoISBN(ds, n);
            break;
        case 6:
            timKiemTheoTenSach(ds, n);
            break;
        case 0:
            ghiDuLieuVaoFile(ds, n);
            break;
        default:
            printf("Lua chon khong hop le.\n");
        }
    } while (luaChon != 0);

    free(ds);
    return 0;
}

// lap phieu muon sach
void LapPhieuMuonSach()
{
    char maDocGia_muonSach[MAX_CMND_LENGTH];
    char ISBN_muonSach[MAX_ISBN_LENGTH];
    int ngaymuon, thangmuon, nammuon;
    int ngaytradukien, thangtradukien, namtradukien;
    printf("nhap ma Doc gia muon Sach: ");
    scanf_s("%s", maDocGia_muonSach, MAX_CMND_LENGTH);
    printf("\n");
    printf("nhap ma Sach can muon: ");
    scanf_s("%s", ISBN_muonSach, MAX_ISBN_LENGTH);
    printf("\n");
    printf("nhap ngay muon Sach (dd-mm-yyyy): ");
    scanf_s("%d-%d-%d", &ngaymuon, &thangmuon, &nammuon);
    printf("\n");
    printf("nhap ngay tra Sach du kien (dd-mm-yyyy): ");
    scanf_s("%d-%d-%d", &ngaytradukien, &thangtradukien, &namtradukien);
    printf("\n");

    //gia su moi thang 30 ngay -> 1 nam 360 ngay cho de tinh a T^T
    if (((ngaytradukien + thangtradukien * 30 + namtradukien * 360) - (ngaymuon + thangmuon * 30 + nammuon * 360)) > 7)
    {
        printf("err: Muon Sach toi da trong 7 ngay");
        return;
    }
    else
    {
        DocGia* ds_dg = NULL;
        int n_dg = 0;
        docDuLieuTuFile(&ds_dg, &n_dg);

        Sach* ds_sach = NULL;
        int n_sach = 0;
        docDuLieuTuFile(&ds_sach, &n_sach);

        // tim doc gia
        int found_dg = 0;
        for (int i = 0; i < n_dg; i++) {
            if (strcmp(ds_dg[i].maDocGia, maDocGia_muonSach) == 0) {

                // tim sach
                int found = 0;
                for (int j = 0; j < n_sach; j++) {
                    if (strcmp(ds_sach[j].ISBN, ISBN_muonSach) == 0) {
                        
                        // tim duoc Doc Gia va Sach => ghi vao file
                        FILE* file1;
                        fopen_s(&file1, "muonSach.txt", "a");
                        if (file1)
                        {
                            fprintf(file1, "%s / %s / %d-%d-%d / %d-%d-%d / %s / %d\n",
                                ds_dg[i].maDocGia,
                                ds_dg[i].hoTen,
                                ngaymuon, thangmuon, nammuon,
                                ngaytradukien, thangtradukien, namtradukien,
                                ds_sach[j].ISBN, ds_sach[j].GiaSach);
                        }
                        else
                        {
                            printf("loi file muonSach.txt");
                        }

                        fclose(file1);
                        printf("Da them vao danh sach cac Sach duoc muon !!\n");

                        //
                        found = 1;
                        break;
                    }
                }
                if (found == 0) {
                    printf("Khong tim thay Sach voi ISBN %s !!\n", ISBN_muonSach);
                }

                //
                found_dg = 1;
                break;
            }
        }
        if (!found_dg) {
            printf("Khong tim thay doc gia voi Ma Doc Gia %s !!\n", maDocGia_muonSach);
        }
        free(ds_dg);
        free(ds_sach);
        return;
    }
}

// lap phieu tra sach
void LapPhieuTraSach()
{
    char maDocGia_muonSach[MAX_CMND_LENGTH];
    char ISBN_muonSach[MAX_ISBN_LENGTH];
    int ngaytra, thangtra, namtra;
    int matsach;
    long tienphat = 0;
    int kiemtratontai = 0;

    printf("nhap ma Doc gia tra Sach: ");
    scanf_s("%s", maDocGia_muonSach, MAX_CMND_LENGTH);
    printf("\n");

    printf("nhap ma Sach can tra: ");
    scanf_s("%s", ISBN_muonSach, MAX_ISBN_LENGTH);
    printf("\n");

    printf("nhap ngay tra Sach (dd-mm-yyyy): ");
    scanf_s("%d-%d-%d", &ngaytra, &thangtra, &namtra);
    printf("\n");

    printf("nhap '1' neu mat Sach, neu khong thi nhap '0': ");
    scanf_s("%d", &matsach);
    printf("\n");

    char maDocGia[MAX_CMND_LENGTH];
    char hoTen[MAX_NAME_LENGTH];
    char ISBN[MAX_ISBN_LENGTH];
    int ngaymuon, thangmuon, nammuon;
    int ngaytradukien, thangtradukien, namtradukien;
    int GiaSach;

    FILE* file1, * file2;
    fopen_s(&file1, "muonSach.txt", "r");
    fopen_s(&file2, "saukhitraSach.txt", "w");

    if (file1 && file2)
    {
        while (!feof(file1))
        {
            fscanf_s(file1, "%s / %s / %d-%d-%d / %d-%d-%d / %s / %d\n",
                maDocGia, MAX_CMND_LENGTH,
                hoTen, MAX_NAME_LENGTH,
                &ngaymuon, &thangmuon, &nammuon,
                &ngaytradukien, &thangtradukien, &namtradukien,
                ISBN, MAX_ISBN_LENGTH,
                &GiaSach);
            if (strcmp(maDocGia, maDocGia_muonSach) == 0 && strcmp(ISBN, ISBN_muonSach) == 0)
            {
                kiemtratontai = 1;
                //gia su 1 thang co 30 ngay cho de tinh -> 1 nam co 360 ngay
                if (((ngaytra + thangtra * 30 + namtra * 360) - (ngaymuon + thangmuon * 30 + nammuon * 360)) > 7)
                {
                    tienphat = ((ngaytra + thangtra * 30 + namtra * 360) - (ngaymuon + thangmuon * 30 + nammuon * 360)) * 5000 - 7 * 5000;
                }
                if (matsach == 1)
                {
                    tienphat = 2 * GiaSach;
                }
                printf("\nMa Doc Gia: %-10s Ten doc gia: %-15s \nNgay muon: %d-%d-%-5d Ngay tra: %d-%d-%-5d  \nISBN Sach muon:  %-20s  \nTien phat: %d\n",
                    maDocGia,
                    hoTen,
                    ngaymuon, thangmuon, nammuon,
                    ngaytra, thangtra, namtra,
                    ISBN, tienphat);
            }
            else
            {
                fprintf(file2, "\n%s / %s / %d-%d-%d / %d-%d-%d / %s / %d\n",
                    maDocGia,
                    hoTen,
                    ngaymuon, thangmuon, nammuon,
                    ngaytradukien, thangtradukien, namtradukien,
                    ISBN, GiaSach);
            }
        }


        fclose(file1);
        fclose(file2);
    }
    if (kiemtratontai == 0)
    {
        printf("\ndoc gia khong muon sach nay!!\n");
    }

    FILE* file3, * file4;
    fopen_s(&file3, "muonSach.txt", "w");
    fopen_s(&file4, "saukhitraSach.txt", "r");
    while (!feof(file4))
    {
        fscanf_s(file4, "%s / %s / %d-%d-%d / %d-%d-%d / %s / %d\n",
            maDocGia, MAX_CMND_LENGTH,
            hoTen, MAX_NAME_LENGTH,
            &ngaymuon, &thangmuon, &nammuon,
            &ngaytradukien, &thangtradukien, &namtradukien,
            ISBN, MAX_ISBN_LENGTH,
            &GiaSach);
        fprintf(file2, "\n%s / %s / %d-%d-%d / %d-%d-%d / %s / %d\n",
            maDocGia,
            hoTen,
            ngaymuon, thangmuon, nammuon,
            ngaytradukien, thangtradukien, namtradukien,
            ISBN, GiaSach);
    }
    fclose(file3);
    fclose(file4);

}

// cac thong ke co ban
void CacThongKeCoBan()
{
    int choice;
    do
    {
        printf("\n================Thong Ke Co Ban================\n");
        printf("1. Thong ke so luong Sach trong thu vien\n");
        printf("2. Thong ke so luong Sach theo the loai\n");
        printf("3. Thong ke so luong Doc Gia\n");
        printf("4. Thong ke so luong Doc Gia theo gioi tinh\n");
        printf("5. Thong ke so Sach dang duoc muon\n");
        printf("6. Thong ke danh sach Doc Gia bi tre han tra Sach\n");
        printf("0. Quay lai MENU\n");
        printf("-----------------------------------------------\n");
        printf("lua chon cua ban la: ");
        scanf_s("%d", &choice);
        printf("\n");
        switch (choice)
        {
        case 1:
        {
            ThongkeSoLuongSach();
            break;
        }
        case 2:
        {
            ThongkeSoLuongSachtheoTheloai();
            break;
        }
        case 3:
        {
            ThongkeSoLuongDocGia();
            break;
        }
        case 4:
        {
            ThongkeSoLuongDocGiatheoGioiTinh();
            break;
        }
        case 5:
        {
            ThongkesoSachduocmuon();
            break;
        }
        case 6:
        {
            ThongkeDocGiaBiTreHan();
            break;
        }
        case 0:
            break;
        default:
            break;
        }

    } while (choice);
}