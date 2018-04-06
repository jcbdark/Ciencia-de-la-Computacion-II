#include <iostream>
using namespace std;
int sum_array(int arr[],int n) {
    int total = 0;
    for(int i = 0; i < n; i++) {
        total += arr[i];
    }
    return total;
}
int sum_array_r(int arr[], int n) {
        return arr[n] + arr[n-1];
        n--;
}
void paso_valor(int a ,int b)
{
    int temp = a;
    a = b;
    b = temp;
}
void paso_referencia(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}
void intercambio(int *a, int * b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int len_lista(char c[]) {
    int i = 0;
    int total = 0;
    while (c[i] != '\0') {
        total++;
        i++;
    }
    return total;
}
int len_lista_p(char *s) {
    int n;
    for (n = 0; *s != '\0'; s++) {
        n++;
    }
    return n;
}
void copia(char s[], char t []) {
    int  i = 0;
    while ((s[i] = t[i]) != '\0')
        i++;
}
void copia_t(char *s, char *t) {
    while ((*s = *t) != '\0') {
        s++;
        t++;
    }
}
void swap_char(char a[], char b[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int temp = a[i];
        a[i] = b[i];
        b[i] = temp;
    }
}
void swap_char_p(char *a ,char *b, int n)
{
    int i = 0;
    while(i < n)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
        a++;
        b++;
        i++;
    }
}
int main()
{
    int a = 3;
    int b = 5;
    paso_valor(a, b);
    cout<<a<<b<<endl;
    paso_referencia(a,b);
    cout<<a<<b<<endl;
    char cadena[] ={'j','o','s','e','\0'};
	int arr[] = {3,5,7};
    cout<<sum_array_r(arr,3)<<endl;
    int c = 5;
    int d = 7;
    char cadena2[] ={'a','n','y','a','\0'};
    intercambio(&c,&d);
    cout<<c<<d<<endl;
    cout<<len_lista_p(cadena)<<endl;
    cout<<len_lista(cadena)<<endl;
    copia_t(cadena,cadena2);
    cout<<cadena<<endl;
    cout<<cadena2<<endl;
    char str1[] ={'j','o','s','e','\0'};
    char str2[] ={'a','n','y','a','\0'};
    swap_char_p(str1,str2,4);
    cout<<str1<<endl;
    cout<<str2<<endl;
	return 0;
}