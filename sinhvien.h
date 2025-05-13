#ifndef SINH_VIEN_H
#define SINH_VIEN_H

typedef struct sinh_vien
{
    int MSSV;
    char HO_TEN[50];
    float GPA;
    struct sinh_vien *next;
} SINH_VIEN;

SINH_VIEN *newnode();
void THEM_CUOI(SINH_VIEN **SV, SINH_VIEN *THEM);
void IN_SINH_VIEN(SINH_VIEN **SV);
void TIM_KIEM_SV_THEO_TEN(SINH_VIEN **SV);
void TIM_KIEM_SV_THEO_MSSV(SINH_VIEN **SV);
void XOA_SV(SINH_VIEN **SV);
void SUA_SV(SINH_VIEN **SV);
void MAX_GPA(SINH_VIEN **SV);
void SAP_XEP(SINH_VIEN **SV);
void PHAN_LOAI(SINH_VIEN **SV);
void GHI_FILE(SINH_VIEN **SV, const char *tenfile);
void DOC_FILE_VAO_DANH_SACH(SINH_VIEN **SV, const char *tenfile);
void GIAI_PHONG(SINH_VIEN **SV);
void MENU_CT();
#endif
