#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int i,n,quantity[30];
float item_price[30],total_price_of_item[100],original_amount_to_be_paid,discount,total_amount,tax;
char store_name[30],name_of_customer[30],item[100][30];
long int mobile_number_of_customer;



void input()
{
    printf("Enter store name : ");
    scanf("%[^\n]s",store_name);
    printf("\nEnter Name of the Customer : ");
    scanf("%s",name_of_customer);
    printf("\nEnter Mobile Number of the Customer : ");
    scanf("%ld",&mobile_number_of_customer);
    printf("\nNo.of purchase items = ");
    scanf("%d",&n);

    for(i=0; i<n; i++)
    {
        printf("\n\nITEM %d  ",i+1);
        printf("\nEnter item name = ");
        scanf("%s",item[i]);
        printf("\nEnter the price of item = ");
        scanf("%f",&item_price[i]);
        printf("\nEnter the quantity of item = ");
        scanf("%d",&quantity[i]);
    }
}

void cal()
{
    
    for(int i=0; i<n; i++)
    {   
        tax = 0.12*original_amount_to_be_paid;
        total_price_of_item[i] = (item_price[i] * quantity[i]);
        original_amount_to_be_paid = total_price_of_item[i]+original_amount_to_be_paid+tax;
    }

    if(original_amount_to_be_paid>1000&&original_amount_to_be_paid<2000)
    {
        discount=(10*original_amount_to_be_paid)/100;
        total_amount = original_amount_to_be_paid-discount;
    }
    else if(original_amount_to_be_paid>2000&&original_amount_to_be_paid<2500)
    {
        discount=(15*original_amount_to_be_paid)/100;
        total_amount = original_amount_to_be_paid-discount;
    }
    else if(original_amount_to_be_paid>2500)
    {
        discount=(20*original_amount_to_be_paid)/100;
        total_amount = original_amount_to_be_paid-discount;
    }
    else
    {
        total_amount = original_amount_to_be_paid-discount;
    }
   
}

void output()
{
    printf("\n\n\n***********************************************************************************************");
    printf("\n\t\t\t\t  %s",store_name);
    printf("\n***************************************************************************************************");
    printf("\nCUSTOMER NAME : %s",name_of_customer);
    printf("\nCUSTOMER MOBILE NUMBER : %ld\n",mobile_number_of_customer);
    time_t t;
    time(&t);
    printf("Time : %s", ctime(&t));
    printf("\n***************************************************************************************************");
    printf("\nITEM.NO\t ITEM NAME\tITEM PRICE\tQUANTITY\tTOTAL PRICE OF ITEM");

    for(i=0; i<n; i++)
    {
        printf("\n %d \t",i+1);
        printf("  %s   \t",item[i]);
        printf(" %.3f     \t",item_price[i]);
        printf("  %d       \t",quantity[i]);
        printf("     %.3f ",total_price_of_item[i]);
    }
    printf("\n***************************************************************************************************");
    
    printf("\nGST (12 PERCENT): %.3f\n",tax);
    
    printf("\nORIGINAL AMOUNT TO BE PAID : %.3f\n",original_amount_to_be_paid);

    printf("\nTOTAL AMOUNT TO BE PAID : %.3f\n",total_amount);
    
    printf("\nNO.OF ITEMS PURCHASED : %d\n",n);
    
    printf("\nYOU SAVED %.3f (DISCOUNT)",discount);

    printf("\n**************************************************************************************************");
    printf("\n\t\t\t      *****HAPPY SHOPPING*****");
    printf("\n\t\t\t  *****THANK YOU! VISIT AGAIN*****");
}


int main()
{
    input();
    cal();
    output();

    return 0;
}
