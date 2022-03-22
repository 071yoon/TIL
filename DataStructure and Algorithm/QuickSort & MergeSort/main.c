//
// Created by 윤영기 on 2022/03/22.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mergeSort(float data[], int p, int r);
void merge(float data[], int p, int q, int r);
void quickSort(float data[], int L, int R);

int main() {
    srand((unsigned)time(NULL));
    float data[20] = {0};
    for(int i = 0; i < 20; i++){ //임의로 20개의 실수형 데이터 받기  (0 ~ 100)
        data[i] = (float)((rand() % 10000) / (float)100);
    }
    printf("정렬 전\n");
    for(int i = 0; i < 20; i++) {
        printf("%.2f ", data[i]); //이쁘게 소수점 두자리 까지만 보여주기
    }
    printf("\nMerge Sort 정렬\n");
    float mergeData[20];
    for(int i = 0; i < 20; i++){
        mergeData[i] = data[i]; //mergeSort 해줄 Data
    }
    mergeSort(mergeData, 0, 19);
    printf("\nMerge Sort 끝\n");
    for(int i = 0; i < 20; i++) { //MergeSort 결과
        printf("%.2f ", mergeData[i]);
    }
    printf("\n\nQuick Sort 정렬\n");
    float quickData[20];
    for(int i = 0; i < 20; i++){
        quickData[i] = data[i]; //quickSort 해줄 Data
    }
    quickSort(quickData, 0, 19);
    printf("\nQuick Sort 끝\n");
    for(int i = 0; i < 20; i++){
        printf("%.2f ", quickData[i]);
    }
    return 0;
}

void mergeSort(float data[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2; //mid 가 현재의 중앙 index
        printf("Sort left-side : [%d] to [%d]\n", left, mid);
        mergeSort(data, left, mid); //왼쪽 정렬
        printf("Sort right-side: [%d] to [%d]\n", mid + 1, right);
        mergeSort(data, mid + 1, right); //오른쪽 정렬
        merge(data, left, mid, right); //왼쪽 오른쪽 합치기
    }
}
void merge(float data[], int left, int mid, int right) {
    printf("\nMerging : [%d] to  [%d]\n", left, right); //여기부터 여기까지 합칠거다
    int i = left, j = mid + 1, k = left;
    float tmp[20]; // 여기에다 저장 후 합쳐줄거임
    while(i <= mid && j <= right) {
        if(data[i] <= data[j]) tmp[k++] = data[i++];
        else tmp[k++] = data[j++];
    }
    while(i <= mid)
        tmp[k++] = data[i++];
    while(j <= right)
        tmp[k++] = data[j++];
    for(int a = left; a <= right; a++)
        data[a] = tmp[a];
    printf("Data : "); //정렬된 인덱스와 데이터 보여주기
    for(int i = left; i <= right; i++){
        printf("[%d]:[%.2f] ", i, data[i]);
    }
    printf("\n\n");
}
void quickSort(float data[], int L, int R) {
    int left = L, right = R;
    float pivot = data[(L + R) / 2];    // pivot 설정 (가운데)
    float temp;
    while (left <= right) {
        while (data[left] < pivot)    // left가 pivot보다 큰 값을 만나거나 pivot을 만날 때까지 
            left++;
        while (data[right] > pivot)    // right가 pivot보다 작은 값을 만나거나 pivot을 만날 때까지 
            right--;
        if (left <= right) {    // left가 right보다 왼쪽에 있다면 교환
            temp = data[left];
            data[left] = data[right];
            data[right] = temp;
            left++; //오른쪽으로 한칸 이동
            right--; //왼쪽으로 한칸 이동
        }
    }   // left가 right 보다 오른쪽에 있을 때까지 반복

    /* recursion */
    if (L < right)
        quickSort(data, L, right);    // 왼쪽 배열 재귀적으로 반복 

    if (left < R)
        quickSort(data, left, R);    // 오른쪽 배열 재귀적으로 반복 
}