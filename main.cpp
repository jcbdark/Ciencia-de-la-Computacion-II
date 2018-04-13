#include <iostream>
using namespace std;
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
int sum_array(int arr[],int n) {
    int total = 0;
    for(int i = 0; i < n; i++) {
        total += arr[i];
    }
    return total;
}
int sum_array_r(int arr[], int n) {
   if(n == 0)
 	return 0;
   else
        return arr[n-1] + sum_array_r(arr,n-1);
}
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    /* crear arrays tmeporales */
    int L[n1], R[n2];
 
    /* Copia de los datos a los arrays tmeporales L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
 
    /* mezclar los arrayas temporales y ponerlos dentro arr[l..r]*/
    i = 0; // indice inicial del primer subarray 
    j = 0; // indice inicial del segundo subarray
    k = l; // indice inicial del subarray mezcla 
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copiar los elementos restantes de L[],si existe alguno */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    /* Copiar los elementos de restantes de R[],si existe alguno */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
/* l es para el indice izquierdo y r es para el indice derecho odel subarray que sera ordenado*/
void mergesort(int arr[], int l, int r)
{
    if (l < r)
    {
        // indice medio
        int m = l+(r-l)/2;
 
        // Ordenar
        mergesort(arr, l, m);
        mergesort(arr, m+1, r);
 
        merge(arr, l, m, r);
    }
}
int particion (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivote
    int i = (low - 1);  // indice del menor elemento
 
    for (int j = low; j <= high- 1; j++)
    {
        // si el elemento actual es menor o igual al pivote
        if (arr[j] <= pivot)
        {
            i++;    // incrementamos el indice del menor elemento
            intercambio(&arr[i], &arr[j]);
        }
    }
    intercambio(&arr[i + 1], &arr[high]);
    return (i + 1);
}
 

void quicksort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi es el indice de particionamiento */
        int pi = particion(arr, low, high);
 
        // Ordenar los elementos
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}
void insertionsort(int arr[], int n)
{
   int  key, j;
   /* Mueve los elementos del arr[0..i-1], que son
          mayores que la llave, una posicion adelante de su posicion actual */
   for (int i = 1; i < n; i++)
   {
       key = arr[i];
       j = i-1;

       while (j >= 0 && arr[j] > key)
       {
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = key;
   }
}

void multipla_matrices(int a[][], int b[][], int c[][], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            c[i][j] = 0;
            for (int k = 0; k < n; k++)
                c[i][j] += a[i][k]*b[k][j];
        }
    }
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
void concatenar(char a[], char b[])
{
    int i = 0,j= 0;
    while (a[i] != '\0')
        i++;
    while ((a[i++] = b[j++]) != '\0');
}
void concatenar_ptr(char *a, char *b)
{
    while (*a != '\0') {
        a++;
    }
    while((*a++ = *b++) != '\0');
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
bool es_palindromo(char *xs, int n){
    int i=0;
    int k= n;
    int j=k-1;
    while(i < k/2){
        if(*(xs+i)!=*(xs+j)){
            return false;
        }
        i++;
        j--;
    }
    return true;
}
int convert_to_char_to_int(char *s)
{
    int n = 0;
    while (*s >= '0' && *s <= '9')
    {
        n = 10 * n + (*s - '0');
        s++;
    }
    return n;
}
double convert_to_char_to_double(char* x)
{
	double total=0, num;
	int df=10,i=0;
	bool decimal=false;
	while(x[i])
	{
		num=x[i]-'0';
		if(decimal)
		{
		num=num/df;
		df=df*10;
		}
		else if (!decimal && ( x[i]>='0' && x[i]<='9'))
		total=total*10;

		if(x[i]=='.' )
		decimal=true;
		else total+=num;

		i++;
	}
	return total;
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
    int N = 4;
    int a[N][N] = { {1, 1, 1, 1},
                    {2, 2, 2, 2},
                    {3, 3, 3, 3},
                    {4, 4, 4, 4}};
 
    int b[N][N] = { {1, 1, 1, 1},
                    {2, 2, 2, 2},
                    {3, 3, 3, 3},
                    {4, 4, 4, 4}};
 
    int c[N][N]; 
    multiplica_matrices(a, b, c ,N);
    for (int i = 0; i < N; i++) {
	    for(int j = 0; j < N; j++) {
		    cout<<c[i][j];
	    }
	    cout<<endl;
    }
    char entero[] = {'1','2','3','4','\0'};
    char s[]={'a','n','a','\0'};
    cout<<es_palindromo(s,3)<<endl;
    cout<<convert_to_char_to_int(entero)<<endl;
    concatenar(str1,str2);
    cout<<str1<<endl;
    char cadena3[]={'m','a','f','e','r','\0'};
    concatenar_ptr(cadena,cadena3);
    cout<<cadena;
    char doble[]= {'3','.','1','5','\0'};
    cout<<convert_to_char_to_double(doble)<<endl;
    int nums[] = {18,5,4,23,1,8,2};
    mergesort(nums,0,6);
    for (int i = 0; i < 7; i++)
	cout<<nums[i]<<" ";
    cout<<endl;
    int nums2[] = {26,2,45,1,6,8};
    quicksort(nums2,0,5);
    for (int i = 0; i < 6; i++)
    {
	cout<<nums2[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}
