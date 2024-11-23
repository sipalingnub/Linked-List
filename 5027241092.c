#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char nama[100];
    char nrp[11];
    char hp[13];
    struct Node* next;
}; //deklarasi struktur node berupa nama, nrp, dan hp dengan jumlah digit tertentu

struct Node* createNode(char* nama, char* nrp, char* hp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Error: Memori tidak cukup.\n");
        exit(1);
    }
    strcpy(newNode->nama, nama);
    strcpy(newNode->nrp, nrp);
    strcpy(newNode->hp, hp);
    newNode->next = NULL;
    return newNode;
} //fungsi membuat node baru

//(insert at the beginning, insert at the end, insert at a certain index) yang dimana ini adalah fungsi insert node dari posisi tertentu

void insertAtBeginning(struct Node** head, char* nama, char* nrp, char* hp) {
    struct Node* newNode = createNode(nama, nrp, hp);
    newNode->next = *head;
    *head = newNode;
} //fungsi menambah node di awal list

void insertAtEnd(struct Node** head, char* nama, char* nrp, char* hp) {
    struct Node* newNode = createNode(nama, nrp, hp);
    if (*head == NULL) {
        *head = newNode;
        return;
    } 
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
} //fungsi menambah node di akhir list

void insertAtIndex(struct Node** head, int index, char* nama, char* nrp, char* hp) {
    if (index == 0) {
        insertAtBeginning(head, nama, nrp, hp);
        return;
    }
    struct Node* newNode = createNode(nama, nrp, hp);
    struct Node* temp = *head;
    for (int i = 0; i < index - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Index %d di luar batas.\n", index);
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
} //fungsi menambah node di indeks tertentu

//(delete at the beginning, delete at the end, delete at a certain index) yang dimana ini adalah fungsi delete node dari posisi tertentu

void deleteAtBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("List kosong, tidak ada yang bisa dihapus.\n");
        return;
    }
    struct Node* temp = *head;
    *head = temp->next;
    free(temp);
} //fungsi menghapus node awal list

void deleteAtEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List kosong, tidak ada yang bisa dihapus.\n");
        return;
    }
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    struct Node* temp = *head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
} //fungsi menghapus node akhir list

void deleteAtIndex(struct Node** head, int index) {
    if (*head == NULL) {
        printf("List kosong, tidak ada yang bisa dihapus.\n");
        return;
    }
    if (index == 0) {
        deleteAtBeginning(head);
        return;
    }
    struct Node* temp = *head;
    for (int i = 0; i < index - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Index %d di luar batas.\n", index);
        return;
    }
    struct Node* toDelete = temp->next;
    temp->next = toDelete->next;
    free(toDelete);
} //fungsi menghapus node di indeks tertentu

void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List kosong.\n");
        return;
    }
    struct Node* temp = head;
    printf("Daftar Mahasiswa:\n");
    while (temp != NULL) {
        printf("Nama: %s, NRP: %s, No.HP: %s\n", temp->nama, temp->nrp, temp->hp);
        temp = temp->next;
    }
} //fungsi menampilkan isi linked list

int main() { //fungsi utama
    struct Node* head = NULL;

    insertAtBeginning(&head, "Beck Kubain", "5027241057", "081081018154");
    insertAtEnd(&head, "Jimmy Lamar", "5080321987", "08111111111");
    insertAtIndex(&head, 1, "Bob Marley", "5027123456", "08122222222");
    //menambahkan data

    printf("Linked List setelah penambahan:\n");
    displayList(head); //cetak isi linked list setelah di insert

    deleteAtBeginning(&head);
    deleteAtEnd(&head);
    deleteAtIndex(&head, 0); //menghapus data

    printf("\nLinked List setelah penghapusan:\n");
    displayList(head); //cetak isi linked list setelah di delete

    return 0;
}