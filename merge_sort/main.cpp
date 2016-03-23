#include <iostream>
#include <vector>
#include <math.h>
#include <limits>

using namespace std;

void merge(vector<int>& vec, int p, int q, int r)
{
    int n1 = q - p + 1;  //tamano a ordenar del vector izq
    int n2 = r - q;      //tamano a ordenar del vector der
    
    vector<int> vector_izq(n1 + 1); // agregar un elemento para el elemento final
    vector<int> vector_der(n2 + 1);
    
    for (int i = 0; i < n1; i++)
        vector_izq[i] = vec[p + i];
    
    for (int j = 0; j < n2; j++)
        vector_der[j] = vec[q + j + 1];
    
    vector_izq[n1] = std::numeric_limits<int>:: max(); // sentinel o marca de que llego al final(infinito)
    vector_der[n2] = std::numeric_limits<int>:: max();
    int i=0,j = 0;
    
    for (int k = p; k <= r; k++)    {
        if (vector_izq[i] <= vector_der[j]) {
            vec[k] = vector_izq[i];
            i++;
        }
        else    {
            vec[k] = vector_der[j];
            j++;
        }
    }
}

void merge_sort(vector<int>&vec,int inicio,int final)        {
    if(inicio<final){
        int medio=floor((inicio+final)/2);
        merge_sort(vec,inicio,medio);
        merge_sort(vec,medio+1,final);
        merge     (vec,inicio,medio,final);
    }
}


void imprimir(vector<int>a){
    for(int i=0;i<a.size();i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

int main()  {
    vector<int>vec;
    vec.push_back(100); vec.push_back(21);
    vec.push_back(9);  vec.push_back(3);
    vec.push_back(1);  vec.push_back(7);
    imprimir(vec);
    merge_sort(vec,0,vec.size()-1);
    imprimir(vec);
}




