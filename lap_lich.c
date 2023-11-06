#include <stdio.h>

int compare(int d[], int c[], int i1, int i2) {
    int sub_d = d[i1] - d[i2];
    int sub_c = c[i1] - c[i2];
    if (sub_d != 0) {
        return sub_d;
    }
    return sub_c;
}

int sort(int array[], int d[], int c[], int n) {
    for (int i = 0; i + 1 < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (compare(d, c, array[i], array[j]) > 0) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

int max(int a, int b) {
    return ((a > b) ? a : b);
}

int main() 
{
    const int n = 7;
    int d[] = {15, 11, 18, 16, 20, 20, 20};
    int f[] = {5, 3, 13, 10, 14, 16, 20};
    int s[] = {3, 0, 10, 5, 13, 14, 16};
    int a[n];
    int E[n];
    int L[n];
    int c[n];
    int L_max = 0;

    printf("arrival times: \n");
    printf("------------------------------------\n");
    for (int i = 0; i < n; i++) {
        a[i] = s[i]; // De gia tri thoi gian tra ve trung binh nho nhat thi a = s.
        printf("%d   ", a[i]);
    }
    printf("\n\n");

    printf("finish times: \n");
    printf("------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%d   ", f[i]);
    }
    printf("\n\n");

    printf("computation times: \n");
    printf("------------------------------------\n");
    for (int i = 0; i < n; i++) {
        c[i] = f[i] - a[i];
        printf("%d   ", c[i]);
    }
    printf("\n\n");

    printf("lateness times:\n");
    printf("------------------------------------\n");
    for (int i = 0; i < n; i++) {
        L[i] = f[i] - d[i];
        printf("%d   ", L[i]);
        if (L_max < L[i]) {
            L_max = L[i];
        }
    }
    printf("\nmaximum lateness: %d", L_max);
    printf("\n\n");

    printf("Edceeding times: \n");
    printf("------------------------------------\n");
    for (int i = 0; i < n; i++) {
        E[i] = max(0, L[i]);
        printf("%d   ", E[i]);
    }
    printf("\n\n");

    for (int i = 0; i < n; i++) {
        a[i] = 0;
    }
    

    // Lap lich theo thuat toan EDD
    int ss[n];
    for (int i = 0; i < n; i++) {
        ss[i] = i;
    }
    sort(ss, d, c, 7); 

    printf("Thu tu thuc hien cac cong viec sau khi dung thuat toan EDD: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", ss[i]);
    }
    printf("\n\n");

    s[ss[0]] = 0;
    f[ss[0]] = c[ss[0]];
    for (int i = 1; i < n; i++) {
        s[ss[i]] = f[ss[i - 1]];
        f[ss[i]] = s[ss[i]] + c[ss[i]];
    }

    printf("start times: \n");
    printf("------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%d   ", s[i]);
    }
    printf("\n\n");

    printf("finish times: \n");
    printf("------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%d   ", f[i]);
    }
    printf("\n\n");
    
    return 0;
}