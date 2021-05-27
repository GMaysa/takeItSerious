#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define maxV 5 

// int rando(int sum){
//     int n;
//     time_t j = time(NULL);
    
//     srand(j);
//     n = (rand() % sum) + 1;
//     // else if();
// }

int ham(){
    int matriks[maxV][maxV];
    int arrV[maxV];
    for(int i = 1; i<=maxV; i++){
        for(int j = 1; j<=maxV; j++){
            if(i == j) matriks[i][j] = 0;
            else matriks[i][j] = 1;
        }
    }
    int idx1, idx2;
    for(int i = 1; i<=maxV; i++){
        for(int j = 1; j<=maxV; i++){
            if(matriks[i][j] == 1 && matriks[j][i] == 1){
                arrV[i] = i;
            }
        }
    }
    srand(time(NULL));
    // for(int i = 0; i < 5 ; i++){
    //     arrV[i] = i + 1;
    // }
    for(int i = 0; i < 5 ; i++){
        int randIndex = rand() % 5;
        int temp = arrV[i];
        arrV[i] = arrV[randIndex];
        arrV[randIndex] = temp;
    }   
    for(int i = 0; i < 5 ; i++){
        printf("%d  ", i);
    }
}

int main(){
    ham();
}