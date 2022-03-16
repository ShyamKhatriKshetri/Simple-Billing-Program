#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct items{
    char item[20];
    float price;
    int qty;
};
struct orders{
    char costumer[100];
    char date[50];
    int numofitems;
    struct items itm[50];
};
void generatebillheader(char name[50],char date[30]){
    system("cls");
    printf("\n\n");
    printf("\t  S.K RESTAURANT");
    printf("\n\t---------------------");
    printf("\nDATE:%s",date);
    printf("\nordered by:%s",name);
    printf("\n");
    printf("\n---------------------------------\n");
    printf("ITEMS\t\t");
    printf("QTY\t\t");
    printf("TOTAL\t\t");
    printf("\n----------------------------------");
    printf("\n\n");
}
void generatebillbody(char item[20],int qty,float price){
    printf("%s\t\t",item);
    printf("%d\t\t",qty);
    printf("%.2f\t\t",qty*price);
    printf("\n");
}
void generatebillfooter(float total){
    printf("\n");
    system("COLOR 61");
    float dis=0.1*total;
    float netTotal=total-dis;
    float tax=0.013*netTotal;
    float Grandtotal=netTotal+tax;
    printf("--------------------------------\n");
    printf("sub total\t\t\t%.2f",total);
    printf("\nDiscount\t\t\t%.2f",dis);
    printf("\nTax\t\t\t\t%.2f",tax);
    printf("\n\t\t\t\t---------");
    printf("\nGrand Total\t\t\t%.2f",Grandtotal);
    printf("\n-------------------------\n");
    printf("\n\t\t\t\t propiter:");
    printf("\n\t\t\t\t\t shyam kshetri");
    printf("\n\t\tthank you");

}
int main(){
    int i;
    float total;
    int opt,n;
    struct orders ord;
    printf("\t==========S.K RESTAURANT==========");
    printf("\n\nplease select your prefered operation");
    printf("\n1.please help me to make a bill");
    printf("\n2.Exit");

    printf("\n\n");
    printf("\n\n please your choose :");
    scanf("%d",&opt);
    
    switch(opt){
        case 1:
        printf("\n please enter the name of costumer:\t");
        scanf("%s",ord.costumer);
        strcpy(ord.date,__DATE__);
        printf("\nenter the no of items:\t");
        scanf("%d",&n);
        ord.numofitems =n;

        for( i=0;i<n;i++){
            printf("\n\n");
            printf("please enter the %d item\t:",i+1);
            scanf("%s",ord.itm[i].item);
            printf("\nplease enter the quantity:");
            scanf("%d",&ord.itm[i].qty);
            printf("\nplease enter the unit price:");
            scanf("%f",&ord.itm[i].price);
            total+=ord.itm[i].qty*ord.itm[i].price;

        }
        generatebillheader(ord.costumer,ord.date);
        for( i=0;i<ord.numofitems;i++){
            generatebillbody(ord.itm[i].item,ord.itm[i].qty,ord.itm[i].price);
        }
        generatebillfooter(total);

    }


    return 0;
}
