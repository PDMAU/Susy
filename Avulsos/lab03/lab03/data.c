#include "data.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


Data criaData(int dia, int mes, int ano){
    Data data;
    data.dia = dia;
    data.mes = mes;
    data.ano = ano;
    return data;
}


Data leData(){
    int mes, dia, ano;
    scanf(" %d/%d/%d", &dia,&mes,&ano);
    return criaData(dia,mes,ano);
}

int comparaData(Data data1, Data data2){
    if(data1.ano == data2.ano){
        if(data1.mes == data2.mes){
            if(data1.dia == data2.dia)
                return 0;
            else if(data1.dia < data2.dia)
                return -1;
            else
                return 1;
        }else if(data1.mes < data2.mes)
            return -1;
        else
            return 1;

    }
    else if(data1.ano < data2.ano){
        return -1;
    }
    else{
        return 1;
    }
    return -1;
}

