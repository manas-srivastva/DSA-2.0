#include<stdio.h>
#include<conio.h>

void add_elements();
void display();
void insert();
void delete();
int arr[100],N;
int main(){
    int choice;
   do{
    printf("\n Enter Your choice");
    printf("1 for Adding elements in array \n");
    printf("2 for Displaying Array \n");
    printf("3 for Inserting elements in array \n");
    printf("4 for Deletion of Element \n");
    printf("5 for Exiting \n");
     scanf("%d",&choice);
     switch(choice){
        case 1:
        add_elements();
        break;
        case 2:
        display();
        break;
        case 3:
        insert();
        break;
        case 4:
        delete();
        break;
      case 5: 
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid Choice\n");
            break;
    }
} while(choice != 5);
return 0;
}

void add_elements(){
    int i;
    printf("Enter size");
    scanf("%d",&N);

    if (N <= 0 || N > 100) {
        printf("Invalid size! Returning to menu.\n");
      
        return;
    }

    printf("Enter %d integer elements:\n", N);
    for (i = 0; i < N; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    }

void display() {
    int i;
    if (N == 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("Position\tValue\n");
    for (i = 0; i < N; i++) {
        printf("%d\t\t%d\n", i + 1, arr[i]);
    }
}

void insert() {
    int pos, elem, i;

    if (N >= 100) {
        printf("Array is full. Cannot insert.\n");
        return;
    }

    printf("Enter position to insert (1 to %d): ", N + 1);
    scanf("%d", &pos);

    if (pos < 1 || pos > N + 1) {
        printf("Invalid position.\n");
        return;
    }

    printf("Enter element to insert: ");
    scanf("%d", &elem);

   
    for (i = N; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }

    arr[pos - 1] = elem;
    N++;
    printf("Element inserted successfully.\n");
}


void delete() {
    int pos, i;

    if (N == 0) {
        printf("Array is empty. Cannot delete.\n");
        return;
    }

    printf("Enter position to delete (1 to %d): ", N);
    scanf("%d", &pos);

    if (pos < 1 || pos > N) {
        printf("Invalid position.\n");
        return;
    }

    // Shift elements left
    for (i = pos - 1; i < N - 1; i++) {
        arr[i] = arr[i + 1];
    }

    N--;
    printf("Element deleted successfully.\n");
}