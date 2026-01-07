#include <time.h>
#include <stdio.h>
#include <string.h>
#include "logger.h"

FILE * archLog;

void log_init(const char *filename){
    archLog = fopen(filename,"a");
    if(!archLog)
        archLog = fopen(filename,"r+");
}

void log_message(log_level_t level, const char *message){
    if(!archLog)
        perror("error");
    time_t hora = time(NULL);
    struct tm *info = localtime(&hora);
    char buffer[40];
    strftime(buffer,40,"%Y-%m-%d %H:%M:%S",info);

    char linea[80];
    char aviso[10];

    switch (level)
    {
    case LOG_INFO:
        strcpy(aviso,"INFO");
        break;
    case LOG_WARN:
        strcpy(aviso,"WARNING");
        break;
    case LOG_DEBUG:
        strcpy(aviso,"DEBUG");
        break;
    case LOG_ERROR:
        strcpy(aviso,"ERROR");
        break;
    default:
        break;
    }
    snprintf(linea,sizeof(linea),"[%s] [%s] %s\n",buffer,aviso,message);
    
    // cerrar y crear otro archivo si nos pasamos del limite
    float file_size;
    fseek(archLog,0,SEEK_END);
    file_size = (float)(ftell(archLog) / 1024.0f);
    
    if(file_size >= MAX_FILE){
        log_close();
        rename("logs/app.log","logs/app.log.1");
        archLog = fopen("logs/app.log","r+");
        if(!archLog) 
            archLog = fopen("logs/app.log","w");
    }
    fputs(linea,archLog);
}

void log_close(){
    if(archLog) fclose(archLog);
}