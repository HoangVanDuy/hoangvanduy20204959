#include <stdio.h>
#include <string.h>
#define nameLength 20
#define emailLength 20
#define numLength 12
typedef struct Address{
   char name[nameLength];
   char num[numLength];
   char email[emailLength];
} ad;
ad DcList[100];
void Push(ad *dc, int i, char name[], char num[], char email[]) {
   strcpy((dc + i)->name, name);
   strcpy((dc + i)->num, num);
   strcpy((dc + i)->email, email);
}
void SwapDc(ad *a, ad *b) {
   ad tmp;
   strcpy(tmp.name, b->name);
   strcpy(tmp.num, b->num);
   strcpy(tmp.email, b->email);
   strcpy(b->name, a->name);
   strcpy(b->num, a->num);
   strcpy(b->email, a->email);
   strcpy(a->name, tmp.name);
   strcpy(a->num, tmp.num);
   strcpy(a->email, tmp.email);
}

void Sapxep(ad *dc, int n) {
   for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
         if (strcmp((dc + i)->name, (dc + j)->name) > 0) {
            SwapDc(dc + i, dc + j);
         }
      }
   }
}
void Find(ad *dc, char tmp[], int n, int x) {
   for (int i = 0; i < n; i++) {
      if (x == 1 && strcmp((dc + i)->name, tmp) == 0) {
         printf("\n%s %s %s\n", (dc + i)->name, (dc + i)->num, (dc + i)->email);
         return;
      }
      if (x == 2 && strcmp((dc + i)->email, tmp) == 0) {
         printf("\n%s %s %s\n", (dc + i)->name, (dc + i)->num, (dc + i)->email);
         return;
      }
      if (x == 3 && strcmp((dc + i)->num, tmp) == 0) {
         printf("\n%s %s %s\n", (dc + i)->name, (dc + i)->num, (dc + i)->email);
         return;
      }
   }
   printf("Khong co");
}

void Nhiphan(ad *dc, char name[], int n) {
   int l = 0, r = n - 1;
   while (l <= r) {
      int m = (l + r) / 2;
      int y = strcmp(name, (dc + m)->name);
      if (y == 0) {
         printf("\n%s %s %s\n", (dc + m)->name, (dc + m)->num, (dc + m)->email);
         return;
      }
      if (y > 0)
         l = m + 1;
      if (y < 0)
         r = m - 1;
   }
   printf("Khong co");
}

int main() {
   int n;
   FILE *input = fopen("Danhsach.txt", "r");
   fscanf(input, "%d", &n);
   for (int i = 0; i < n; i++) {
      char name[nameLength], email[emailLength], num[numLength];
      fscanf(input, "%s", name);
      fscanf(input, "%s", num);
      fscanf(input, "%s", email);
      Push(DcList, i, name, num, email);
   }
   printf("Danh sach:\n");
   for (int i = 0; i < n; i++) {
      printf("%s %s %s\n", DcList[i].name, DcList[i].num, DcList[i].email);
   }

   Sapxep(DcList, n);
   printf("\nDanh sach sap xep :\n");
   for (int i = 0; i < n; i++) {
      printf("%s %s %s\n", DcList[i].name, DcList[i].num, DcList[i].email);
   }

   int a;
   do {
      printf("\nChon chuong trinh:\n1. Tim kiem ten\n2. Tim kiem email\n3. Tim kiem so\n4. Tim ten theo nhi phan\nNhan 0 de thuoat chuong trinh\nChon so:");
      scanf("%d", &a);
      char tmp[emailLength];
      switch (a) {
      case 1:
         printf("Nhap ten: ");
         scanf("%s", tmp);
         Find(DcList, tmp, n, 1);
         break;

      case 2:
         printf("Nhap email: ");
         scanf("%s", tmp);
         Find(DcList, tmp, n, 2);
         break;

      case 3:
         printf("Nhap so: ");
         scanf("%s", tmp);
         Find(DcList, tmp, n, 3);
         break;

      case 4:
         printf("Nhap ten: ");
         scanf("%s", tmp);
         Nhiphan(DcList, tmp, n);
         break;

      default:
         return 0;
         break;
      }
   } while (a != 0);
   fclose(input);
}

/*
 Danh sach:
duy 2463725 affgef@gmail.com
hai 5435465 dfgegggr@gmail.com
tuan 6969687 fftyfyuguy@gmail.comduc
duc 6568778 yiuygyug@gmail.com
hien 6597697 ggfiytftyftyi@gmail.thao
thao 6565696 gfyfgh@gmail.com
giang 5659567 tdtytyf@gmail.com
long 4448444 ftuytfdrrgyu@gmail.cquan
quan 8970766 jfgyjft@gmail.com
dat 6576854 gfytfytf@gmail.com

Danh sach sap xep :
dat 6576854 gfytfytf@gmail.com
duc 6568778 yiuygyug@gmail.com
duy 2463725 affgef@gmail.com
giang 5659567 tdtytyf@gmail.com
long 4448444 ftuytfdrrgyu@gmail.cquan
quan 6969687 fftyfyuguy@gmail.comquan
quan 8970766 jfgyjft@gmail.com
quan 6597697 ggfiytftyftyi@gmail.thao
thao 6565696 gfyfgh@gmail.com
tuan 5435465 dfgegggr@gmail.com

Chon chuong trinh:
1. Tim kiem ten
2. Tim kiem email
3. Tim kiem so
4. Tim ten theo nhi phan
Nhan 0 de thuoat chuong trinh
Chon so:1
Nhap ten: duc

duc 6568778 yiuygyug@gmail.com

Chon chuong trinh:
1. Tim kiem ten
2. Tim kiem email
3. Tim kiem so
4. Tim ten theo nhi phan
Nhan 0 de thuoat chuong trinh
Chon so:2
Nhap email: gfyfgh@gmail.com

thao 6565696 gfyfgh@gmail.com

Chon chuong trinh:
1. Tim kiem ten
2. Tim kiem email
3. Tim kiem so
4. Tim ten theo nhi phan
Nhan 0 de thuoat chuong trinh
Chon so:3
Nhap so: 2463725

duy 2463725 affgef@gmail.com

Chon chuong trinh:
1. Tim kiem ten
2. Tim kiem email
3. Tim kiem so
4. Tim ten theo nhi phan
Nhan 0 de thuoat chuong trinh
Chon so:4
Nhap ten: dat

dat 6576854 gfytfytf@gmail.com

Chon chuong trinh:
1. Tim kiem ten
2. Tim kiem email
3. Tim kiem so
4. Tim ten theo nhi phan
Nhan 0 de thuoat chuong trinh
Chon so:0

 */
