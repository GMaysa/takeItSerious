#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char judulF[100];
    struct node *next;
};
typedef struct node node;

struct queue
{
    int count;
    node *front;
    node *rear;
};
typedef struct queue queue;

void initialize(queue *q)
{
    q->count = 0;
    q->front = NULL;
    q->rear = NULL;
}

int isempty(queue *q)
{
    return (q->rear == NULL);
}

void enqueue(queue *q, char *judul)
{
    struct node *tmp;
    tmp = (struct node*)malloc(sizeof(struct node));
    strcpy(tmp->judulF,judul);
    tmp->next = NULL;
    if (!isempty(q))
    {
        q->rear->next = tmp;
        q->rear = tmp;
    }
    else
    {
        q->front = q->rear = tmp;
    }
    q->count++;
}

int dequeue(queue *q)
{
    struct node *tmp;
    char n[50];
    // strcpy(n, q->front->judulF);
    tmp = q->front;
    q->front = q->front->next;
    q->count--;
    free(tmp);
    // printf("%s\n", n);
}

void display(node *head)
{
    if(head == NULL){
        // printf("Underflow\n");
        // return 0;
    }else{
        printf("-   %s\n", head->judulF);
        display(head->next);
    }
}

// int insertFilm(){
//     int ch;
//     system("cls");
//     for(int i = 1; i <= 5; i++){
//         if(judul[5].code == 5){
//             break;
//         }else{
//             printf("Masukkan Judul Film: ");
//             fflush(stdin);
//             gets(judul[i].judulF);
//             judul[i].code = i;
//         }
//     }
//     system("pause");
//     if(judul[5].code == 5){
//         system("cls");
//         puts("Film Sudah Penuh");
//         puts("Apakah anda ingin menghapus semua Film saat ini?");
//         puts("Ketik 1 jika IYA");
//         puts("Ketik 0 jika TIDAK");
//         printf("PILIH: ");
//         scanf("%d", &ch);
//         if(ch == 1){
//             for(int j = 1; j <= 5; j++){
//                 judul[j].code = 0;
//             }
//         }
//     }
// }

// int main()
// {
    // int ch;
    // do{
    //     system("cls");
    //     puts("Daftar Film");
    //     for(int i = 1; i <= 5; i++){
    //         if(judul[1].code == 0){
    //             puts("- No Film -");
    //             break;
    //         }else{
    //             printf("- %s\n", judul[i].judulF);
    //         }
    //     }
    //     puts("");
    //     puts("1. INSERT");
    //     puts("0. exit");
    //     printf("PILIH: ");
    //     scanf("%d", &ch);
    //     switch(ch){
    //         case 1:
    //             insertFilm();
    //         break;
    //     }
    //     system("pause");
    // } while (ch != 0);

//======================================
    // queue *q;
    // q = malloc(sizeof(queue));
    // initialize(q);
    
    // enqueue(q, "Kingkong 2");
    // enqueue(q, "Superman vs Batman");
    // printf("Queue before dequeue\n");
    // display(q->front);
    // dequeue(q);
    // printf("Queue after dequeue\n");
    // display(q->front);
    // return 0;
// }