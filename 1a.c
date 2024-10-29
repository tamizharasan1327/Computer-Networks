#include <stdio.h>
#include <string.h>
int main() 
{
 char data[100], stuffedData[200];
 int i, count = 0, j = 0;
 clrscr();
 printf("Enter the Data for Bit Stuffing: ");
 scanf("%s", data);
 
 for(i = 0; i < strlen(data); i++) 
{
 if(data[i] == '1') 
{
 count++;
 stuffedData[j++] = data[i];
 }
else 
{
 count = 0;
 stuffedData[j++] = data[i];
 }
 
 if(count == 5) 
{
 count = 0;
 stuffedData[j++] = '0';
 }
 }
 
 stuffedData[j] = '\0';
 printf("Data After Bit Stuffing: %s\n", stuffedData);
 getch();
 return 0;
}
