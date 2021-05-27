#include<stdio.h>
#include<stdlib.h>

struct seat
{
    int key;
    struct seat *left;
    struct seat *right;
};

struct seat *newSeat(int n)
{
    struct seat *currNewSeat = (struct seat *)malloc(sizeof(struct seat));
    currNewSeat->key = n;
    currNewSeat->left = NULL;
    currNewSeat->right = NULL;

    return currNewSeat;
};

struct seat *insert(struct seat *root, int n)
{
    if (root == NULL)
        return newSeat(n); //jika root masih kosong akan dibuatkan seat baru yang terdapat diatas
    else if (n < root->key)
        root->left = insert(root->left, n);//jika nilai lebih kecil dari root maka akan ditaruh di sebelah kiri dan kembali ke fungsi ini lagi sehingga root kosong
    else if (n > root->key)
        root->right = insert(root->right, n); //jika lebih besar maka akan ditaruh di sebelah kanan dan kembali ke fungsi ini lagi sehingga root kosong

    return root;
}

struct seat *freeAll(struct seat *root)
{
    if (root == NULL)return NULL; //jika tidak ada data maka tidak terjadi apa-apa
    root->left = freeAll(root->left); //memanggil semua data yang ada dikiri
    root->right = freeAll(root->right); //memanggil semua data yang ada dikiri
    free(root);//menghapus semua data
    return NULL;
}

struct seat *predecessor(struct seat *root)
{
    struct seat *curr = root->left;//curr akan menggunakan child kiri
    while (curr->right != NULL)//jika ada data di kanan maka curr akan menggunakan data yang kanan dan terus mencari child yang ada dikanan
    {
        curr = curr->right;
    }
    return curr;
}

struct seat *delete (struct seat *root, int n)
{
    if (root == NULL)
        return NULL; //kondisi dimana data tidak ada didalam tree
    else if (n < root->key)
        root->left = delete (root->left, n); //jika value lebih kecil dari root maka data akan kembali ke fungsi dan root akan berindah ke kiri
    else if (n > root->key)
        root->right = delete (root->right, n);//jika value lebih besar dari root maka data akan kembali ke fungsi dan root akan berpindah ke kanan
    else //kondisi dimana data berhasil ditemukan
    {
        //cari tahu berapa jumlah child dari value yang akan kita hapus
        if ((root->left) == NULL || (root->right) == NULL) //kondisi dimana root memiliki salah satu atau kedua child yang NULL atau tidak memiliki child
        {
            struct seat *temp = NULL;
            if (root->left != NULL)
                temp = root->left;//jika child kiri berisi value atau tidak sama dengan NULL maka value dari child kiri akan dimasukkan ke dalam temp
            else
                temp = root->right;//jika tidak maka value dari child kanan yang akan dimasukkan kedalam temp

            if (temp == NULL)//jika temp tidak ada
            {
                temp = root;//maka taruh root yang tidak mempunyai child ke dalam temp
                root = NULL;//lalu beri niali NULL
            }
            else//jika temp tidak kosong 
            {
                *root = *temp;
            }
            free(temp);//fungsi untuk delete temp yang sudah berisi root didalamnya
        }
        else //kondisi dimana child lengkap
        {
            struct seat *temp = predecessor(root);
            root->key = temp->key;
            root->left = delete (root->left, temp->key);
        }
    }
    return root;
}

void displaySeat(struct seat *root)
{
    if (root == NULL) return;
    displaySeat(root->left);
    printf("%d ", root->key);
    displaySeat(root->right);
}

int main(){
    struct seat *root = NULL;

    root = insert(root, 20);
    root = insert(root, 5);
    root = insert(root, 25);
    root = insert(root, 15);
    root = insert(root, 8);
    root = insert(root, 32);
    root = insert(root, 12);
    root = insert(root, 28);

    displaySeat(root);
    root = delete(root, 5);
    puts("");
    displaySeat(root);
    root = delete(root, 15);
    puts("");
    displaySeat(root);
    return 0;
}