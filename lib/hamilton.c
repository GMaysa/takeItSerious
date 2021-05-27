#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define maxV 5 

int h[maxV];

int rando(int sum){
    int n;
    time_t j = time(NULL);
    
    srand(j);
    n = (rand() % sum) + 1;
    // else if();
}

int ham(int matriks[maxV][maxV]){
    int arrV[maxV];
    for(int i = 1; i<=maxV; i++){
        for(int j = 1; j<=maxV; j++){
            if(i == j) matriks[i][j] = 0;
            else matriks[i][j] = 1;
        }
    }
    time_t j = time(NULL);
    srand(j);
    arrV[1] = (rand() % maxV) + 1;
    int idx1, idx2;
    for(int i = 2; i<=maxV; i++){
        idx1 = arrV[i-1];
        if(matriks[idx2][idx1] == 1){
            
        }
    }
}

int main(){
    int matriks[maxV][maxV];
    ham(matriks);
}