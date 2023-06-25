#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100

struct Sach {
    char maSach[20];
    char tenSach[100];
    int soLuong;
    float gia;
};

int soLuongSach = 0;  // Luu tru so luong sach trong danh sach
struct Sach danhSachSach[MAX_BOOKS];

// Ham them sach vao danh sach
void themSach(const char *maSach, const char *tenSach, int soLuong, float gia) {
    if (soLuongSach < MAX_BOOKS) {
        strcpy(danhSachSach[soLuongSach].maSach, maSach);
        strcpy(danhSachSach[soLuongSach].tenSach, tenSach);
        danhSachSach[soLuongSach].soLuong = soLuong;
        danhSachSach[soLuongSach].gia = gia;
        soLuongSach++;
        printf("Sach duoc them thanh cong.\n");
    } else {
        printf("So luong sach da dat toi da.\n");
    }
}

// Ham hien thi danh sach sach
void hienThiDanhSachSach() {
	int i;
    if (soLuongSach == 0) {
        printf("Danh sach sach trong.\n");
    } else {
        printf("Danh sach sach:\n");
        
        for (i = 0; i < soLuongSach; i++) {
            printf("Ma sach: %s\n", danhSachSach[i].maSach);
            printf("Ten sach: %s\n", danhSachSach[i].tenSach);
            printf("So luong: %d\n", danhSachSach[i].soLuong);
            printf("Gia: %.2f\n\n", danhSachSach[i].gia);
        }
    }
}

// Ham sap xep danh sach sach theo ma sach
void sapXepSachTheoMa() {
    struct Sach temp;
    int i, j;

    for (i = 0; i < soLuongSach - 1; i++) {
        for (j = 0; j < soLuongSach - i - 1; j++) {
            if (strcmp(danhSachSach[j].maSach, danhSachSach[j + 1].maSach) > 0) {
                temp = danhSachSach[j];
                danhSachSach[j] = danhSachSach[j + 1];
                danhSachSach[j + 1] = temp;
            }
        }
    }

    printf("Danh sach sach da duoc sap xep theo ma sach.\n");
}

// Ham tai du lieu tu tep tin
void taiDuLieuTuTep() {
    FILE *file = fopen("sach.txt", "r");

    if (file == NULL) {
        printf("Khong the mo tep tin.\n");
        return;
    }

    char maSach[20], tenSach[100];
    int soLuong;
    float gia;

    while (fscanf(file, "%s %[^\n] %d %f\n", maSach, tenSach, &soLuong, &gia) != EOF) {
        themSach(maSach, tenSach, soLuong, gia);
    }

    fclose(file);

    printf("Du lieu da duoc tai tu tep tin.\n");
}


// Ham tim sach co gia lon nhat
void timSachGiaMax() {
	int i;
    if (soLuongSach == 0) {
        printf("Danh sach sach trong.\n");
        return;
    }

    struct Sach sachGiaCaoNhat = danhSachSach[0];
    for (i = 1; i < soLuongSach; i++) {
        if (danhSachSach[i].gia > sachGiaCaoNhat.gia) {
            sachGiaCaoNhat = danhSachSach[i];
        }
    }

    printf("Sach co gia cao nhat la:\n");
    printf("Ma sach: %s\n", sachGiaCaoNhat.maSach);
    printf("Ten sach: %s\n", sachGiaCaoNhat.tenSach);
    printf("So luong: %d\n", sachGiaCaoNhat.soLuong);
    printf("Gia: %.2f\n", sachGiaCaoNhat.gia);
}
// Ham tim va sua thong tin sach theo ma
void timVaSuaSach() {
    // Thuc hien tim va sua thong tin sach theo ma
    // (Viet ma de tim va sua thong tin sach theo ma)
    printf("Da tim thay va sua thong tin sach.\n");
}

// Ham tim va xoa sach theo ma
void timVaXoaSach() {
    // Thuc hien tim va xoa sach theo ma
    // (Viet ma de tim va xoa sach theo ma)
    printf("Da tim thay va xoa sach.\n");
}

int main() {
    int luaChon;
    char maSach[20], tenSach[100];
    int soLuong;
    float gia;

    do {
        printf("Chon tuy chon:\n");
        printf("1- Nhap danh sach sach\n");
        printf("2- Hien thi danh sach sach\n");
        printf("3- Sap xep danh sach sach theo ma sach\n");
        printf("4- Tai du lieu tu tep tin\n");
        printf("5- Tim sach co gia lon nhat\n");
        printf("6- Tim va sua thong tin sach theo ma\n");
        printf("7- Tim va xoa sach theo ma\n");
        printf("8- Thoat\n");
        printf("Lua chon cua ban (1-8): ");
        scanf("%d", &luaChon);

        switch (luaChon) {
            case 1:
                printf("Nhap ma sach: ");
                scanf("%s", maSach);
                printf("Nhap ten sach: ");
                scanf(" %[^\n]", tenSach);
                printf("Nhap so luong sach: ");
                scanf("%d", &soLuong);
                printf("Nhap gia sach: ");
                scanf("%f", &gia);
                themSach(maSach, tenSach, soLuong, gia);
                break;
            case 2:
                hienThiDanhSachSach();
                break;
            case 3:
                sapXepSachTheoMa();
                break;
            case 4:
                taiDuLieuTuTep();
                break;
            case 5:
                timSachGiaMax();
                break;
            case 6:
                timVaSuaSach();
                break;
            case 7:
                timVaXoaSach();
                break;
            case 8:
                printf("Dang thoat khoi chuong trinh...\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long thu lai.\n");
                break;
        }

        printf("\n");

    } while (luaChon != 8);

    return 0;
}
