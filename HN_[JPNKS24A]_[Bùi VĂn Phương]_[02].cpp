#include <stdio.h>

// Ham Binary Search
int binarySearch(int arr[], int n, int x) {
    int l = 0;
    int r = n - 1;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (arr[m] == x)
            return m;
        if (arr[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}

// Ham Bubble Sort (sap xep tang dan)
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Ham Insertion Sort (sap xep giam dan)
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            arr[j] = key;
        }
    }
}

// Ham kiem tra so nguyen to
int isPrime(int n) {
    if (n <= 1) return 0;
    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main() {
    int n, x;
    int arr[100];
    int chon = 0;
    int tim = -1;
    int soChan = 0, soLe = 0;
    int vitriThem, giaTri, vitriXoa;
    int max = arr[0];
    
    do {
        printf("___________ MENU_________________\n");
        printf("1 nhap so phan tu can nhap va gia tri cac phan tu\n");
        printf("2 in ra gia tri cac phan tu trong mang\n");
        printf("3 dem so luong cac phan tu chan, le trong mang\n");
        printf("4 gia tri lon thu hai trong mang\n");
        printf("5 them mot phan tu vao mang\n");
        printf("6 xoa phan tu trong mang\n");
        printf("7 sap xep mang theo thu tu tang dan\n");
        printf("8 sap xep mang theo thu tu giam dan\n");
        printf("9 in ra so nguyen to va binh phuong no\n");
        printf("10 tim kiem phan tu\n");
        printf("11 thoat\n");
        
        printf("Moi ban chon chuc nang\n");
        scanf("%d", &chon);
    
        switch (chon) {
            case 1: // Nhap so phan tu trong mang
                printf("Moi ban nhap kich thuoc mang\n");
                scanf("%d", &n);
                for (int i = 0; i < n; i++) {
                    printf("Moi ban nhap gia tri cua arr[%d]\n", i);
                    scanf("%d", &arr[i]);
                }
                break;
            case 2: // In ra gia tri cac phan tu trong mang
                for (int i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;
            case 3: // Dem so luong cac phan tu chan, le trong mang
                soChan = 0;
                soLe = 0;
                for (int i = 0; i < n; i++) {
                    if (arr[i] % 2 == 0) soChan++;
                    else soLe++;
                }
                printf("So luong phan tu chan: %d\n", soChan);
                printf("So luong phan tu le: %d\n", soLe);
                break;
            case 4: // Gia tri lon thu hai trong mang
                if (n < 2) {
                    printf("Mang khong co du phan tu\n");
                } else {
                    int max1 = arr[0], max2 = arr[0];
                    for (int i = 1; i < n; i++) {
                        if (arr[i] > max1) {
                            max2 = max1;
                            max1 = arr[i];
                        } else if (arr[i] > max2 && arr[i] != max1) {
                            max2 = arr[i];
                        }
                    }
                    printf("Gia tri lon thu hai trong mang la: %d\n", max2);
                }
                break;
            case 5: // Them mot phan tu vao mang
                if (n < 100) {
                    printf("Nhap gia tri cua phan tu can them\n");
                    scanf("%d", &giaTri);
                    printf("Nhap vi tri can them\n");
                    scanf("%d", &vitriThem);
                    for (int i = n; i > vitriThem; i--) {
                        arr[i] = arr[i - 1];
                    }
                    arr[vitriThem] = giaTri;
                    n++;
                } else {
                    printf("Mang da day\n");
                }
                break;
            case 6: // Xoa phan tu trong mang
                printf("Nhap vi tri cua phan tu can xoa\n");
                scanf("%d", &vitriXoa);
                if (vitriXoa >= 0 && vitriXoa < n) {
                    for (int i = vitriXoa; i < n - 1; i++) {
                        arr[i] = arr[i + 1];
                    }
                    n--;
                } else {
                    printf("Vi tri khong hop le\n");
                }
                break;
            case 7: // Sap xep mang theo thu tu tang dan
                bubbleSort(arr, n);
                break;
            case 8: // Sap xep mang theo thu tu giam dan
                insertionSort(arr, n);
                break;
            case 9: // In ra so nguyen to va binh phuong no
                for (int i = 0; i < n; i++) {
                    if (isPrime(arr[i])) {
                        printf("So nguyen to: %d, binh phuong: %d\n", arr[i], arr[i] * arr[i]);
                    }
                }
                break;
            case 10: // Tim kiem phan tu
                printf("Nhap gia tri can tim: ");
                scanf("%d", &x);
                tim = binarySearch(arr, n, x);
                if (tim != -1)
                    printf("Phan tu %d nam o vi tri %d\n", x, tim);
                else
                    printf("Khong tim thay phan tu\n");
                break;
            case 11: // Thoat
                printf("Thoat chuong trinh.\n");
                break;
        }
    } while (chon != 11);

    return 0;
}

