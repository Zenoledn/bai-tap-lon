#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sinhvien.h"
SINH_VIEN *newnode()
{
    SINH_VIEN *temp = (SINH_VIEN *)malloc(sizeof(SINH_VIEN));
    if (temp == NULL)
    {
        printf("\nloi khong the cap phat bo nho");
        exit(1);
    }
    temp->next = NULL;
    return temp;
}
void NHAP_SINH_VIEN(SINH_VIEN **SV)
{
    int n;
    printf("\n Nhap so luong sinh vien:");
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++)
    {
        printf("\n<+=========================================================+>");
        printf("\n||                      Sinh vien %d                       ||", i + 1);
        printf("\n<+=========================================================+>");
        SINH_VIEN *sv = newnode();
        printf("\n||Nhap ma so sinh vien:");
        scanf("%d", &sv->MSSV);
        getchar();
        printf("\n||Nhap ten sinh vien  :"); // dùng puts thì tự động xuốngg dòng
        fgets(sv->HO_TEN, sizeof(sv->HO_TEN), stdin);
        sv->HO_TEN[strcspn(sv->HO_TEN, "\n")] = '\0';
        do
        {
            printf("\n||Nhap GPA (GPA<=4.0):");
            scanf("%f", &sv->GPA);
            getchar();
        } while (sv->GPA < 0 || sv->GPA > 4.0);

        if (*SV == NULL)
        {
            *SV = sv;
            sv->next = NULL;
        }
        else
        {
            SINH_VIEN *p;
            for (p = *SV; p->next != NULL; p = p->next)
                ;
            p->next = sv;
        }
    }
}
void IN_SINH_VIEN(SINH_VIEN **SV)
{
    if (*SV == NULL)
    {
        printf("\nDanh sach sinh vien rong!\n");
        return;
    }

    printf("\n<+==========================================================+>");
    printf("\n|| STT||    MSSV      ||         Ho Ten           ||   GPA  ||");
    printf("\n=============================================================");

    int count = 1;
    SINH_VIEN *p;
    for (p = *SV; p != NULL; p = p->next)
    {
        printf("\n|| %2d || %-12d || %-26s || %5.2f ||",
               count, p->MSSV, p->HO_TEN, p->GPA);
        count++;
    }

    printf("\n<+==========================================================+>");
}

void XOA_SINH_VIEN_THEO_MSSV(SINH_VIEN **SV)
{
    if (*SV == NULL)
    {
        printf("\n danh sach rong");
        return;
    }
    int find;
    printf("\n Nhap MSSV cua sinh vien can xoa:\t");
    scanf("%d", &find);
    getchar();
    SINH_VIEN *p, *prev;
    for (prev = NULL, p = *SV; p != NULL; prev = p, p = p->next)
    {
        if (p->MSSV == find)
        {
            if (prev == NULL)
            {
                *SV = p->next;
            }
            else
            {
                prev->next = p->next;
            }
            free(p);
            printf("\n da loai bo sinh vien co mssv:%d\t", find);
            return;
        }
    }
    printf("\n khong tim thay sinh vien co MSSV:%d", find);
}
void SUA_SV_THEO_MSSV(SINH_VIEN **SV)
{
    if (*SV == NULL)
    {
        printf("\n danh saach rong");
        return;
    }
    int find;
    printf("\n Nhap MSSV cua sinh vien can sua:\t");
    scanf("%d", &find);
    getchar();
    SINH_VIEN *p;
    for (p = *SV; p != NULL; p = p->next)
    {
        if (p->MSSV == find)
        {
            printf("\n Nhap thong tin moi cho sinh vien co MSSV cu la:%d\t", p->MSSV);
            printf("\n Nhap MSSV moi:\t");
            scanf("%d", &p->MSSV);
            getchar();
            puts("\n Nhap ten moi:\t");
            fgets(p->HO_TEN, sizeof(p->HO_TEN), stdin);
            p->HO_TEN[strcspn(p->HO_TEN, "\n")] = '\0';
            printf("\n Nhap GPA moi:\t");
            scanf("%f", &p->GPA);
            return;
        }
    }
    printf("\n khong tim thay sinh vien co MSSV:%d", find);
}
void MAX_GPA(SINH_VIEN **SV)
{
    if (*SV == NULL)
    {
        printf("\n danh sach rong");
        return;
    }
    SINH_VIEN *temp = *SV;
    for (SINH_VIEN *p = *SV; p != NULL; p = p->next)
    {
        if (p->GPA > temp->GPA)
        {
            temp = p;
        }
    }
    printf("\n<=== Sinh vien co GPA cao nhat la ===>");
    printf("\nMSSV: %d\nTen: %s\nGPA: %.2f", temp->MSSV, temp->HO_TEN, temp->GPA);
}
void SAP_XEP_THEO_GPA(SINH_VIEN **SV)
{
    if (*SV == NULL)
    {
        printf("\n danh sach rong");
        return;
    }
    for (SINH_VIEN *i = *SV; i != NULL; i = i->next)
    {
        for (SINH_VIEN *j = i->next; j != NULL; j = j->next)
        {
            if (i->GPA < j->GPA)
            {
                int tempMSSV = i->MSSV;
                float tempGPA = i->GPA;
                char tempHOTEN[50];
                strcpy(tempHOTEN, i->HO_TEN);

                i->MSSV = j->MSSV;
                i->GPA = j->GPA;
                strcpy(i->HO_TEN, j->HO_TEN);

                j->MSSV = tempMSSV;
                j->GPA = tempGPA;
                strcpy(j->HO_TEN, tempHOTEN);
            }
        }
    }
}
void TIM_KIEM_SV_THEO_TEN(SINH_VIEN **SV)
{
    if (*SV == NULL)
    {
        printf("\n danh sach rong");
        return;
    }
    char find[50];
    printf("\n Nhap ten sinh vien can tim:\t");
    fgets(find, sizeof(find), stdin);
    find[strcspn(find, "\n")] = '\0';
    int flag = 0;
    printf("\n <====Ket qua tim kiem=====>");
    for (SINH_VIEN *i = *SV; i != NULL; i = i->next)
    {
        if (strcasecmp(find, i->HO_TEN) == 0)
        {
            printf("\n |Sinh vien:%d", i->MSSV);
            printf("\n |Ten      :%s", i->HO_TEN);
            printf("\n |GPA      :%.2f", i->GPA);
            flag++;
        }
    }
    if (flag == 0)
    {
        printf("\n khong tim thay sinh vien nao co ten:%s", find);
    }
}
void LUU_FILE(SINH_VIEN **SV, const char *tenfile)
{
    if (*SV == NULL)
    {
        printf("\n danh sach rong");
        return;
    }

    FILE *f = fopen(tenfile, "w");
    if (f == NULL)
    {
        printf("\n file khong ton tai");
        return;
    }
    for (SINH_VIEN *i = *SV; i != NULL; i = i->next)
    {
        fprintf(f, "%d\n%s\n%.2f\n", i->MSSV, i->HO_TEN, i->GPA);
    }
    fclose(f);
}
void THEM_CUOI(SINH_VIEN **SV, SINH_VIEN *THEM)
{
    if (*SV == NULL)
    {
        *SV = THEM;
        THEM->next = NULL;
        return;
    }
    SINH_VIEN *i;
    for (i = *SV; i->next != NULL; i = i->next)
    {
    }
    i->next = THEM;
    THEM->next = NULL;
}
void PHAN_LOAI_SV(SINH_VIEN **SV, SINH_VIEN **DAT, SINH_VIEN **KO_DAT)
{
    if (*SV == NULL)
    {
        printf("\n danh sach rong");
        return;
    }
    for (SINH_VIEN *i = *SV; i != NULL; i = i->next)
    {
        if (i->GPA < 2.0)
        {
            SINH_VIEN *sao_chep = newnode();
            sao_chep->MSSV = i->MSSV;
            sao_chep->GPA = i->GPA;
            strcpy(sao_chep->HO_TEN, i->HO_TEN);
            THEM_CUOI(KO_DAT, sao_chep);
        }
        else
        {
            SINH_VIEN *sao_chep = newnode();
            sao_chep->MSSV = i->MSSV;
            sao_chep->GPA = i->GPA;
            strcpy(sao_chep->HO_TEN, i->HO_TEN);
            THEM_CUOI(DAT, sao_chep);
        }
    }
}
void XUAT_FILE(SINH_VIEN **SV, const char *tenfile)
{
    if (*SV == NULL)
    {
        printf("\n danh sach rong");
        return;
    }
    FILE *f = fopen(tenfile, "r");
    if (f == NULL)
    {
        printf("\n khong mo duoc file");
        return;
    }
    int MSSV;
    char TEN[50];
    float GPA;
    while (fscanf(f, "%d\n", &MSSV) == 1 && fgets(TEN, sizeof(TEN), f) != NULL && fscanf(f, "%f\n", &GPA) == 1)
    {
        TEN[strcspn(TEN, "\n")] = '\0';
        printf("\nMSSV: %d", MSSV);
        printf("\nHo ten: %s", TEN);
        printf("\nGPA: %.2f\n", GPA);
    }
    fclose(f);
}
void FREE_LIST(SINH_VIEN **SV)
{
    if (*SV == NULL)
    {
        printf("\n danh sach rong");
        return;
    }
    SINH_VIEN *temp;
    while (*SV != NULL)
    {
        temp = *SV;
        *SV = (*SV)->next;
        free(temp);
    }
}
void MENU_CT()
{
    SINH_VIEN *SV = NULL;
    SINH_VIEN *DAT = NULL;
    SINH_VIEN *KO_DAT = NULL;
    int choice;
    char tenfile[50], tenfile1[50], tenfile2[50];
    do
    {
        printf("\n<+==================================================+>");
        printf("\n||                   MENU CHUONG TRINH              ||");
        printf("\n||==================================================||");
        printf("\n|| 1. Them sinh vien                                ||");
        printf("\n|| 2. In danh sach sinh vien                        ||");
        printf("\n|| 3. Tim kiem sinh vien theo MSSV                  ||");
        printf("\n|| 4. Xoa sinh vien theo MSSV                       ||");
        printf("\n|| 5. Tim sinh vien co GPA cao nhat                 ||");
        printf("\n|| 6. Cap nhat thong tin sinh vien theo MSSV        ||");
        printf("\n|| 7. Sap xep danh sach sinh vien theo GPA          ||");
        printf("\n|| 8. Phan loai sinh vien dat va khong dat          ||");
        printf("\n|| 9. Luu danh sach sinh vien vao file              ||");
        printf("\n||10. Thoat chuong trinh                            ||");
        printf("\n<+==================================================+>");
        printf("\n Nhap lua chon cua ban  : ");

        scanf("%d", &choice);
        getchar();
        switch (choice)
        {
        case 1:
            NHAP_SINH_VIEN(&SV);
            break;
        case 2:
            IN_SINH_VIEN(&SV);
            break;
        case 3:
            TIM_KIEM_SV_THEO_TEN(&SV);
            break;
        case 4:
            XOA_SINH_VIEN_THEO_MSSV(&SV);
            break;
        case 5:
            MAX_GPA(&SV);
            break;
        case 6:
            SUA_SV_THEO_MSSV(&SV);
            break;
        case 7:
            SAP_XEP_THEO_GPA(&SV);
            break;
        case 8:
            PHAN_LOAI_SV(&SV, &DAT, &KO_DAT);
            printf("\nDanh sach sinh vien dat:\n");
            IN_SINH_VIEN(&DAT);
            printf("\nDanh sach sinh vien khong dat:\n");
            IN_SINH_VIEN(&KO_DAT);
            break;
        case 9:
            printf("\nNhap ten file de luu danh sach: ");
            fgets(tenfile, sizeof(tenfile), stdin);
            tenfile[strcspn(tenfile, "\n")] = '\0';
            LUU_FILE(&SV, tenfile);
            break;
        case 10:
            FREE_LIST(&SV);
            FREE_LIST(&DAT);
            FREE_LIST(&KO_DAT);
            printf("\n Da giai phong bo nho\n");
            break;
        default:
            printf("\nLua chon khong hop le, vui long chon lai!");
            break;
        }
    } while (choice != 10);
    printf("\nket thuc phien su dung chuong trinh!");
}
