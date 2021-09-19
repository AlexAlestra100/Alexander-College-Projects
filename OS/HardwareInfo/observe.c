/*Alexander Alestra*/
/*CSC 139 Assignment 1*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/time.h>
#include <time.h>
#include <string.h>

int partB();
int partC();

int main(int argc, char *argv[])
{
    
    printf("\nPart B\n");
    partB();
    
    if(argc == 2)
    {
       if(strcmp(argv[1],"-s") == 0)
       {
            printf("Part C\n");
            partC();
       }
    }
    
    return 0;
}

int partC()
{
    FILE *pt;
    char temp[10];
    int fuser, nuser, systm, idle;

    char stat[] = "/proc/stat"; 

    pt = fopen(stat,  "r");

    if(pt)
    { 
        fscanf(pt, "%s%d%d%d%d", temp, &fuser, &nuser, &systm, &idle);
        printf("\nUser mode: %d\nSystem mode: %d\nIdle: %d\n", (fuser + nuser), systm, idle);
        fclose(pt);
    }
    else
    {
        printf("\nCould not open file %s.\n", stat);   
    }

    char mem[] = "/proc/partitions";

    pt = fopen(mem, "r");
    
    char rw[20];

    if(pt)
    { 
        int i;
        for(i = 0; i < 11; i++)
        {
            fscanf(pt, "%s", rw);
        }
        printf("\nDisk read/write requests: %s\n", rw);
        fclose(pt);
    }
    else
    {
        printf("\nCould not open file %s.\n", mem);   
    }

    char stat2[] = "/proc/stat";
    char swit[15];
    char pros[17];
    
    pt = fopen(stat2, "r");

    if(pt)
    {
        int j;
        
        for(j = 0; j < 81; j++)
        {
            fgets(swit, 15, pt);
        }

        printf("\nContext Switches: %s\n", swit);

        fclose(pt);
    }
    else
    {
        printf("Could not open file %s\n", stat2);
    }

    pt = fopen(stat2, "r");

    if(pt)
    {
        int j;

        for(j = 0; j < 75; j++)
        {   
            fgets(pros, 17, pt);
        }

        printf("\nProcesses since boot: %s\n\n", pros);

        fclose(pt);
    }
    else
    {
        printf("Could not open file %s\n", stat2);
    }

    return 0;
}

int partB()
{
    FILE *fp;
    FILE *fp1;
    FILE *fp2;
    char cpuModel[100];
    char linuxV[42];
    double uptime = 0;
    
    fp = fopen("/proc/cpuinfo", "r");
    
    if(fp)
    {
        int i;

        for(i = 0; i < 5; i++)
        {
            fgets(cpuModel, 100, fp);
        }

        printf("\n%s\n", cpuModel);

        fclose(fp);

    }
    else
    {
        printf("Unable to open file!\n");
    }

    fp1 = fopen("/proc/version", "r");

    if(fp1)
    {

        fgets(linuxV, 42, fp1);
       
        printf("%s\n", linuxV);

        fclose(fp1);


    }
    else
    {
        printf("Unable to open file!\n");
    }
    
    fp2 = fopen("/proc/uptime", "r");
    
    int days, hours, minutes, seconds; 
    int upsec; 
    
    if(fp2)
    {

        fscanf(fp2, "%lf", &uptime);
        
        upsec = uptime;

        days = upsec / 86400;

        hours = (upsec % 86400) / 3600;
        
        minutes = (upsec % 3600) / 60;
        
        seconds = (upsec % 60); 
          
        printf("\nTime since last reboot: (%d:%d:%d:%d)\n", days, hours, minutes, seconds);

        fclose(fp2);

    }
    else
    {
        printf("Unable to open file!\n");
    }
    
    time_t now = time(NULL);
    struct tm tm = *localtime(&now);
    printf("\nCurrent Time: %02d:%02d:%02d\n", tm.tm_hour, tm.tm_min, tm.tm_sec);

    fp1 = fopen("/proc/sys/kernel/hostname", "r");

    char host[30]; 
    
    if(fp1)
    {

        fgets(host, 30, fp1);
       
        printf("\nMachine Host Name: %s\n", host);

        fclose(fp1);


    }
    else
    {
        printf("Unable to open file!\n");
    }

    return 0;
}