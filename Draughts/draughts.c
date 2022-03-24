#include <sys/types.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sqlite3.h>


/* portul folosit */
#define PORT 2024

/* codul de eroare returnat de anumite apeluri */
extern int errno;
int tabla[10][10],linie,coloana;
char save[100]="\0";
char user_logati[3][20];
int nr=0;
sqlite3 *db;

struct lobby{
    char player1[20];
    char player2[20];
    int turn;
};

int creareCont(char name[])
{
	int i;
	char *err=0;
	char sql[256]="INSERT INTO scores (username,scor) VALUES('";
	strcat(sql,name);
	strcat(sql,"',0);");
	i=sqlite3_exec(db,sql,0,0,&err);
	if(i!=SQLITE_OK)
	{
		printf("%s%s\n","SQL ERROR:",err);
		sqlite3_free(err);
		sqlite3_close(db);
		return 0;
	}
	sqlite3_close(db);
	return 1;
}

int verificareCont(char name[])
{
	sqlite3_stmt *stmt;
	const unsigned char* user; 
    sqlite3_prepare_v2(db,"select username from scores",-1,&stmt,0);
    while(sqlite3_step(stmt)!=SQLITE_DONE)
	{
		user=sqlite3_column_text(stmt,0);
		if(strcmp(user,name)==0) 
		{
			sqlite3_close(db);
			return 1;
		}
	}
	sqlite3_close(db);
	return 0;
}

void addScor(int nr,char name[])
{
	char scor[256];
	sprintf(scor,"%d",nr);
	int i;
	char *err=0;
	char sql[256]="UPDATE scores SET scor = scor+";
    strcat(sql,scor);
    strcat(sql," WHERE username = '");
    strcat(sql,name);
    strcat(sql,"';");
	i=sqlite3_exec(db,sql,0,0,&err);
	if(i!=SQLITE_OK)
	{
		printf("%s%s\n","SQL ERROR:",err);
		sqlite3_free(err);
		sqlite3_close(db);
	}
	sqlite3_close(db);
}

void clasament(char clsm[])
{
    clsm[0]='\0';
	sqlite3_stmt *stmt;
	const unsigned char* user;
    const unsigned char* scor; 
    sqlite3_prepare_v2(db,"select * from scores order by scor desc limit 10",-1,&stmt,0);
    while(sqlite3_step(stmt)!=SQLITE_DONE)
	{
        user=sqlite3_column_text(stmt,0);
        scor=sqlite3_column_text(stmt,1);
        strcat(clsm,user);
        strcat(clsm,".");
        strcat(clsm,scor);
        strcat(clsm,".");
	}
	clsm[strlen(clsm)-1]='\0';
	sqlite3_close(db);
}

void tablaJoc()
{
	for(linie=0;linie<10;linie++) 
		tabla[linie][0]=tabla[linie][9]=9;
	for(coloana=0;coloana<10;coloana++)
	    tabla[0][coloana]=tabla[9][coloana]=9;
	for(linie=1;linie<=3;linie++)
	  for(coloana=1;coloana<=8;coloana++)
        if(linie%2==1)
        {
            if(coloana%2==1) tabla[linie][coloana]=0;
            else tabla[linie][coloana]=1;
        }
        else
        {
            if(coloana%2==0) tabla[linie][coloana]=0;
            else tabla[linie][coloana]=1;
        }
	for(linie=4;linie<=5;linie++)
	  for(coloana=1;coloana<=8;coloana++)
	    tabla[linie][coloana]=0;
	for(linie=6;linie<=8;linie++)
	  for(coloana=1;coloana<=8;coloana++)
        if(linie%2==0)
        {
            if(coloana%2==0) tabla[linie][coloana]=0;
            else tabla[linie][coloana]=2;
        }
        else
        {
            if(coloana%2==1) tabla[linie][coloana]=0;
            else tabla[linie][coloana]=2;
        }
}

int verifMutareDama(int l_init,int c_init,int l_fin,int c_fin,int rand)
{
    if(tabla[l_init][c_init]==3 && rand==1) //dama jucator A
    {
        if(l_fin>l_init) //muta inainte
        {
            if(c_fin<c_init)//muta in stanga pozitiei initiale
            {
                if(tabla[l_fin][c_fin]==0 && tabla[l_fin-1][c_fin+1]==3 && l_fin-1==l_init && c_fin+1==c_init)//muta fara a manca
                {
                    printf("%d\n",2);
                    tabla[l_init][c_init]=0;
                    tabla[l_fin][c_fin]=3; 
                    return 1;
                }
                else if(tabla[l_fin][c_fin]==0 && (tabla[l_fin-1][c_fin+1]==2 || tabla[l_fin-1][c_fin+1]==4) && tabla[l_fin-2][c_fin+2]==3)//mananca piesa
                {
                    printf("%d\n",3);
                    tabla[l_init][c_init]=0;
                    tabla[l_fin-1][c_fin+1]=0;
                    tabla[l_fin][c_fin]=3; 
                    return 1;
                }
                else return 0;//incorecta
            }
            else if(c_fin>c_init) //muta in dreapta pozitiei initiale
            {
                if(tabla[l_fin][c_fin]==0 && tabla[l_fin-1][c_fin-1]==3 && l_fin-1==l_init && c_fin-1==c_init)//fara a manca
                {
                    printf("%d\n",4);
                    tabla[l_init][c_init]=0;
                    tabla[l_fin][c_fin]=3; 
                    return 1;
                }
                else if(tabla[l_fin][c_fin]==0 && (tabla[l_fin-1][c_fin-1]==2 || tabla[l_fin-1][c_fin-1]==4) && tabla[l_fin-2][c_fin-2]==3)//mananca piesa
                {
                    printf("%d\n",5);
                    tabla[l_init][c_init]=0;
                    tabla[l_fin-1][c_fin-1]=0;
                    tabla[l_fin][c_fin]=3; 
                    return 1;
                }
                else return 0;//incorecta
            }
            else return 0;
        }
        else //muta inapoi
        {
            if(c_fin<c_init)//muta in stanga pozitiei initiale
            {
                if(tabla[l_fin][c_fin]==0 && tabla[l_fin+1][c_fin+1]==3 && l_fin+1==l_init && c_fin+1==c_init)//muta fara a manca
                {
                    printf("%d\n",2);
                    tabla[l_init][c_init]=0;
                    tabla[l_fin][c_fin]=3; 
                    return 1;
                }
                else if( (tabla[l_fin+1][c_fin+1]==2 || tabla[l_fin+1][c_fin+1]==4) && tabla[l_fin+2][c_fin+2]==3 && tabla[l_fin][c_fin]==0)//mananca piesa
                {
                    printf("%d\n",3);
                    tabla[l_init][c_init]=0;
                    tabla[l_fin+1][c_fin+1]=0;
                    tabla[l_fin][c_fin]=3;
                    return 1;
                }
                else return 0;//incorecta
            }
            else if(c_fin>c_init) //muta in dreapta pozitiei initiale
            {
                if(tabla[l_fin][c_fin]==0 && tabla[l_fin+1][c_fin-1]==3 && l_fin+1==l_init && c_fin-1==c_init)//fara a manca
                {
                    printf("%d\n",4);
                    tabla[l_init][c_init]=0;
                    tabla[l_fin][c_fin]=3;
                    return 1;
                }
                else if( (tabla[l_fin+1][c_fin-1]==2 || tabla[l_fin+1][c_fin-1]==4) && tabla[l_fin+2][c_fin-2]==3 && tabla[l_fin][c_fin]==0)//mananca piesa
                {
                    printf("%d\n",5);
                    tabla[l_init][c_init]=0;
                    tabla[l_fin+1][c_fin-1]=0;
                    tabla[l_fin][c_fin]=3;
                    return 1;
                }
                else return 0;//incorecta
            }
            else return 0;
        }
    }
    else if(tabla[l_init][c_init]==4 && rand==2) //dama jucator B
    {
        if(l_fin<l_init) //muta inainte
        {
            if(c_fin<c_init)//muta in stanga pozitiei initiale
            {
                if(tabla[l_fin][c_fin]==0 && tabla[l_fin+1][c_fin+1]==4 && l_fin+1==l_init && c_fin+1==c_init)//muta fara a manca
                {
                    printf("%d\n",2);
                    tabla[l_init][c_init]=0;
                    tabla[l_fin][c_fin]=4;
                    return 1;
                }
                else if( (tabla[l_fin+1][c_fin+1]==3 || tabla[l_fin+1][c_fin+1]==1) && tabla[l_fin+2][c_fin+2]==4 && tabla[l_fin][c_fin]==0)//mananca piesa
                {
                    printf("%d\n",3);
                    tabla[l_init][c_init]=0;
                    tabla[l_fin+1][c_fin+1]=0;
                    tabla[l_fin][c_fin]=4; 
                    return 1;
                }
                else return 0;//incorecta
            }
            else if(c_fin>c_init) //muta in dreapta pozitiei initiale
            {
                if(tabla[l_fin][c_fin]==0 && tabla[l_fin+1][c_fin-1]==4 && l_fin+1==l_init && c_fin-1==c_init)//fara a manca
                {
                    printf("%d\n",4);
                    tabla[l_init][c_init]=0;
                    tabla[l_fin][c_fin]=4; 
                    return 1;
                }
                else if( (tabla[l_fin+1][c_fin-1]==1 || tabla[l_fin+1][c_fin-1]==3) && tabla[l_fin+2][c_fin-2]==4 && tabla[l_fin][c_fin]==0)//mananca piesa
                {
                    printf("%d\n",5);
                    tabla[l_init][c_init]=0;
                    tabla[l_fin+1][c_fin-1]=0;
                    tabla[l_fin][c_fin]=4;
                    return 1;
                }
                else return 0;//incorecta
            }
            else return 0;
        }
        else //muta inapoi
        {
            if(c_fin<c_init)//muta in stanga pozitiei initiale
            {
                if(tabla[l_fin][c_fin]==0 && tabla[l_fin-1][c_fin+1]==4 && l_fin-1==l_init && c_fin+1==c_init)//muta fara a manca
                {
                    printf("%d\n",2);
                    tabla[l_init][c_init]=0;
                    tabla[l_fin][c_fin]=4; 
                    return 1;
                }
                else if(tabla[l_fin][c_fin]==0 && (tabla[l_fin-1][c_fin+1]==1 || tabla[l_fin-1][c_fin+1]==3) && tabla[l_fin-2][c_fin+2]==4)//mananca piesa
                {
                    printf("%d\n",3);
                    tabla[l_init][c_init]=0;
                    tabla[l_fin-1][c_fin+1]=0;
                    tabla[l_fin][c_fin]=4; 
                    return 1;
                }
                else return 0;//incorecta
            }
            else if(c_fin>c_init) //muta in dreapta pozitiei initiale
            {
                if(tabla[l_fin][c_fin]==0 && tabla[l_fin-1][c_fin-1]==4 && l_fin-1==l_init && c_fin-1==c_init)//fara a manca
                {
                    printf("%d\n",4);
                    tabla[l_init][c_init]=0;
                    tabla[l_fin][c_fin]=4; 
                    return 1;
                }
                else if(tabla[l_fin][c_fin]==0 && (tabla[l_fin-1][c_fin-1]==1 || tabla[l_fin-1][c_fin-1]==3) && tabla[l_fin-2][c_fin-2]==4)//mananca piesa
                {
                    printf("%d\n",5);
                    tabla[l_init][c_init]=0;
                    tabla[l_fin-1][c_fin-1]=0;
                    tabla[l_fin][c_fin]=4; 
                    return 1;
                }
                else return 0;//incorecta
            }
            return 0;
        }
    }
    else return 0;
}

int verifMutarePion(int l_init,int c_init,int l_fin,int c_fin,int rand)
{
    if(tabla[l_init][c_init]==1 && rand==1) //jucator A
    {
        if(c_fin<c_init)//muta in stanga pozitiei initiale
        {
            if(tabla[l_fin][c_fin]==0 && tabla[l_fin-1][c_fin+1]==1 && l_fin-1==l_init && c_fin+1==c_init)//muta fara a manca
            {
                printf("%d\n",2);
                tabla[l_init][c_init]=0;
                if(l_fin==8) tabla[l_fin][c_fin]=3; //se face dama pe prima linie
                else tabla[l_fin][c_fin]=1; //ramane pion
                return 1;
            }
            else if(tabla[l_fin][c_fin]==0 && tabla[l_fin-1][c_fin+1]==2 && tabla[l_fin-2][c_fin+2]==1)//mananca piesa
            {
                printf("%d\n",3);
                tabla[l_init][c_init]=0;
                tabla[l_fin-1][c_fin+1]=0;
                if(l_fin==8) tabla[l_fin][c_fin]=3; //se face dama pe prima linie
                else tabla[l_fin][c_fin]=1; //ramane pion
                return 1;
            }
            else return 0;//incorecta
        }
        else if(c_fin>c_init) //muta in dreapta pozitiei initiale
        {
            if(tabla[l_fin][c_fin]==0 && tabla[l_fin-1][c_fin-1]==1 && l_fin-1==l_init && c_fin-1==c_init)//fara a manca
            {
                printf("%d\n",4);
                tabla[l_init][c_init]=0;
                if(l_fin==8) tabla[l_fin][c_fin]=3; //se face dama pe prima linie
                else tabla[l_fin][c_fin]=1; //ramane pion
                return 1;
            }
            else if(tabla[l_fin][c_fin]==0 && tabla[l_fin-1][c_fin-1]==2 && tabla[l_fin-2][c_fin-2]==1)//mananca piesa
            {
                printf("%d\n",5);
                tabla[l_init][c_init]=0;
                tabla[l_fin-1][c_fin-1]=0;
                if(l_fin==8) tabla[l_fin][c_fin]=3; //se face dama pe prima linie
                else tabla[l_fin][c_fin]=1; //ramane pion
                return 1;
            }
            else return 0;//incorecta
        }
        else return 0;
    }
    else if(tabla[l_init][c_init]==3 && rand==1)
    {
        return verifMutareDama(l_init,c_init,l_fin,c_fin,rand);
    }
    else if(tabla[l_init][c_init]==2 && rand==2) //jucator B
    {
        if(c_fin<c_init)//muta in stanga pozitiei initiale
        {
            if(tabla[l_fin][c_fin]==0 && tabla[l_fin+1][c_fin+1]==2 && l_fin+1==l_init && c_fin+1==c_init)//muta fara a manca
            {
                printf("%d\n",2);
                tabla[l_init][c_init]=0;
                if(l_fin==1) tabla[l_fin][c_fin]=4; //se face dama pe prima linie
                else tabla[l_fin][c_fin]=2; //ramane pion
                return 1;
            }
            else if(tabla[l_fin+1][c_fin+1]==1 && tabla[l_fin+2][c_fin+2]==2 && tabla[l_fin][c_fin]==0)//mananca piesa
            {
                printf("%d\n",3);
                tabla[l_init][c_init]=0;
                tabla[l_fin+1][c_fin+1]=0;
                if(l_fin==1) tabla[l_fin][c_fin]=4; //se face dama pe prima linie
                else tabla[l_fin][c_fin]=2; //ramane pion
                return 1;
            }
            else return 0;//incorecta
        }
        else if(c_fin>c_init) //muta in dreapta pozitiei initiale
        {
            if(tabla[l_fin][c_fin]==0 && tabla[l_fin+1][c_fin-1]==2 && l_fin+1==l_init && c_fin-1==c_init)//fara a manca
            {
                printf("%d\n",4);
                tabla[l_init][c_init]=0;
                if(l_fin==1) tabla[l_fin][c_fin]=4; //se face dama pe prima linie
                else tabla[l_fin][c_fin]=2; //ramane pion
                return 1;
            }
            else if(tabla[l_fin+1][c_fin-1]==1 && tabla[l_fin+2][c_fin-2]==2 && tabla[l_fin][c_fin]==0)//mananca piesa
            {
                printf("%d\n",5);
                tabla[l_init][c_init]=0;
                tabla[l_fin+1][c_fin-1]=0;
                if(l_fin==1) tabla[l_fin][c_fin]=4; //se face dama pe prima linie
                else tabla[l_fin][c_fin]=2; //ramane pion
                return 1;
            }
            else return 0;//incorecta
        }
        else return 0;
    }
    else if(tabla[l_init][c_init]==4 && rand==2)
    {
        return verifMutareDama(l_init,c_init,l_fin,c_fin,rand);
    }
    else return 0;
}

int sfarsitJoc()
{
    int piese1=0,piese2=0;
    int i,j;
    for(i=1;i<=8;i++)
       for(j=1;j<=8;j++)
       {
           if(tabla[i][j]==1 || tabla[i][j]==3)
             piese1++;
           else if(tabla[i][j]==2 || tabla[i][j]==4)
             piese2++;
       }
    if(piese1==0)
       return 1;
    else if(piese2==0) return 2;
    else return 0;
}

char* salvareTabla()
{
    int i,j;
    for(i=1;i<=8;i++)
      for(j=1;j<=8;j++)
      {
          char verif[10];
          sprintf(verif,"%d",tabla[i][j]);
          strcat(save,verif);
      }
    save[strlen(save)]='\0';
    return save;
}

int main ()
{
    struct sockaddr_in server;	// structura folosita de server
    struct sockaddr_in from;
    char msg[100];		//mesajul primit de la client
    char raspuns[1024]=" ";        //mesaj de raspuns pentru client
    int sd;			//descriptorul de socket

    /* crearea unui socket */
    if ((sd = socket (AF_INET, SOCK_STREAM, 0)) == -1)
    {
    	perror ("[server]Eroare la socket().\n");
    	return errno;
    }

    /* pregatirea structurilor de date */
    bzero (&server, sizeof (server));
    bzero (&from, sizeof (from));

    /* umplem structura folosita de server */
    /* stabilirea familiei de socket-uri */
    server.sin_family = AF_INET;
    /* acceptam orice adresa */
    server.sin_addr.s_addr = htonl (INADDR_ANY);
    /* utilizam un port utilizator */
    server.sin_port = htons (PORT);

    /* atasam socketul */
    if (bind (sd, (struct sockaddr *) &server, sizeof (struct sockaddr)) == -1)
    {
    	perror ("[server]Eroare la bind().\n");
    	return errno;
    }

    /* punem serverul sa asculte daca vin clienti sa se conecteze */
    if (listen (sd, 1) == -1)
    {
    	perror ("[server]Eroare la listen().\n");
    	return errno;
    }

    while (1) /* servim in mod concurent clientii... */
    {
		int client;
    	int length = sizeof (from);

    	printf ("[server]Asteptam la portul %d...\n",PORT);
    	fflush (stdout);

    	/* acceptam un client (stare blocanta pina la realizarea conexiunii) */
    	client = accept (sd, (struct sockaddr *) &from, &length);

    	/* eroare la acceptarea conexiunii de la un client */
    	if (client < 0)
    	{
    		perror ("[server]Eroare la accept().\n");
    		continue;
    	}
        
        //deschidem baza de date
		int i=sqlite3_open("proiect",&db);
		if(i!=SQLITE_OK)
		{
			printf("%s\n","Cannot open database");
			sqlite3_close(db);
		}
    	int pid;
    	if ((pid = fork()) == -1) 
		{
    		close(client);
    		continue;
    	} 
		else if (pid > 0) // parinte
		{
    		close(client);
    		while(waitpid(-1,NULL,WNOHANG));
    		continue;
    	} 
		else if (pid == 0) // copil
		{
    		close(sd);
			int iesire=0;
			//cream tabla de joc initiala
            while(iesire!=1) //bucla de citit comenzi
			{
                tablaJoc();
                /* s-a realizat conexiunea, se astepta mesajul */
    		    bzero (msg, 100);
    		    printf ("[server]Asteptam mesajul...\n");
    		    fflush (stdout);

    		    /* citirea mesajului */
    		    if (read (client, msg, 100) == -1)
    		    {
    			    perror ("[server]Eroare la read() de la client.\n");
    			    close (client);	/* inchidem conexiunea cu clientul */
    			    continue;		/* continuam sa ascultam */
    		    }
                msg[strlen(msg)]='\0';
    		    printf ("[server]Mesajul a fost receptionat...%s\n", msg);

				char* p=strtok(msg,":");
				while(p!=NULL)
				{
					char comanda[100];
					strcpy(comanda,p);

					/*prelucram mesajul */
					bzero(raspuns,1024);
					if(strcmp(comanda,"exit")==0)
					{
						strcat(raspuns,"Ai iesit din aplicatie!");
						iesire=1;
						write (client, raspuns, strlen(raspuns)+1);
						exit(1);
					}
					else if(strcmp(comanda,"logout")==0)
					{
                        for(i=0;i<=nr;i++)
                            user_logati[i][0]='\0';
                        nr=0;
                        strcpy(raspuns,"You are disconnected!");
                        write(client,raspuns,strlen(raspuns)+1);
                        break;
					}
					else if(strcmp(comanda,"login")==0)
					{
                        p=strtok(NULL,":.,");
                        if(p!=NULL)
                        {
                            int ok=1;
                            strcpy(comanda,p);
                            for(i=0;i<=nr;i++)
                            {
                                if(strcmp(comanda,user_logati[i])==0)
                                {
                                    ok=0;
                                    strcpy(raspuns,"Username already in used!");
                                    printf("%s\n","User deja conectat!");
                                    write(client,raspuns,strlen(raspuns)+1);
                                    break;
                                }
                            }
                            if(ok==1)
                            {
                                printf("Verificam usernameul:%s\n",comanda);
                                if(verificareCont(comanda)==0)
                                {
                                    strcpy(raspuns,"Invalid username!");
                                    printf("%s\n","User invalid!");
                                    write(client,raspuns,strlen(raspuns)+1);
                                }
                                else
                                {
                                    strcpy(user_logati[nr],comanda);
                                    nr++;
                                    strcpy(raspuns,"You are connected!");
                                    printf("%s\n","Utilizator autentificat!");
                                    write(client,raspuns,strlen(raspuns)+1);
                                }
                            }
                        }
                        break;
                    }
                    else if(strcmp(comanda,"sign up")==0)
                    {
                        p=strtok(NULL,":.,");
                        if(p!=NULL)
                        {
                            strcpy(comanda,p);
                            printf("User de adaugat:%s\n",comanda);
                            if(creareCont(comanda)==0)
                            {
                                strcpy(raspuns,"This username already exists. Enter another!");
                                printf("%s\n","Nu s-a adaugat userul!");
                                write(client,raspuns,strlen(raspuns)+1);
                            }
                            else
                            {
                                strcpy(raspuns,"You have successfully registered! Please log in with your new username!");
                                printf("%s\n","S-a adaugat userul!");
                                write(client,raspuns,strlen(raspuns)+1);
                            }
                        }
                        break;
                    }
                    else if(strcmp(comanda,"clasament")==0)
                    {
                        //salvam clasamentul
                        char clsm[1024];
                        clasament(clsm);
                        strcpy(raspuns,clsm);
                        clsm[0]='\0'; 
                        write(client,raspuns,strlen(raspuns)+1);
                        printf("%s\n","Se trimite clasamentul catre utilizator...");
                        break;
                    }
                    else if(strcmp(comanda,"classic")==0)
					{
                        char coord[100];
                        int lv,cv,ln,cn;
                        int stop=-1;
                        //CREEZ LOBBY SI FAC WRITE cu CINE MUTA primul
                        struct lobby joc;
                        strcpy(joc.player1,user_logati[0]);
                        strcpy(joc.player2,user_logati[1]);
                        joc.turn=1;
                        
                        char initial[100];
                        strcpy(initial,salvareTabla());
                        strcat(initial,"Turn white-player1: ");
                        strcat(initial,joc.player1);
                        initial[strlen(initial)]='\0';
                        printf("Player1 %s incepe!\n",joc.player1);
                        write(client,initial,strlen(initial)+1);

                        do
                        {
                            save[0]='\0';
                            stop=sfarsitJoc();   
                            if(stop==1)
                            {
                                char winer[10];
                                strcpy(winer,joc.player1);
                                strcat(winer," wins!");
                                winer[strlen(winer)]='\0';
                                write(client,winer,strlen(winer)+1);
                            }
                            else
                                if(stop==2)
                                {
                                    char winer[10];
                                    strcpy(winer,joc.player2);
                                    strcat(winer," wins!");
                                    winer[strlen(winer)]='\0';
                                    write(client,winer,strlen(winer)+1);
                                }
                                else{
                                    read(client,coord,100);
                                    if(strcmp(coord,"back")==0) 
                                    {
                                        save[0]='\0';
                                        //tablaJoc();
                                        break;
                                    }
                                    //printf("%s\n",coord);
                                    lv=(int)coord[0]-48;
                                    cv=(int)coord[1]-48;
                                    ln=(int)coord[2]-48;
                                    cn=(int)coord[3]-48;
                                    
                                    if(verifMutarePion(lv,cv,ln,cn,joc.turn)==1)
                                    {
                                        char save[100];
                                        strcpy(save,salvareTabla());
                                        if(joc.turn==1)
                                        {
                                            strcat(save,"Turn black-player2: ");
                                            strcat(save,joc.player2);
                                            save[strlen(save)]='\0';
                                            printf("Randul player-ului 2...\n");
                                            write(client,save,strlen(save)+1);
                                            joc.turn=2;
                                        }
                                        else if(joc.turn==2)
                                        {
                                            strcat(save,"Turn white-player1: ");
                                            strcat(save,joc.player1);
                                            save[strlen(save)]='\0';
                                            printf("Randul player-ului 1...\n");
                                            write(client,save,strlen(save)+1);
                                            joc.turn=1;
                                        }
                                        //printf("%s\n",save);
                                        
                                    }
                                    else
                                    {
                                        char save[100];
                                        strcpy(save,salvareTabla());
                                        if(joc.turn==1)
                                        {
                                            strcat(save,"Turn white-player1: ");
                                            strcat(save,joc.player1);
                                            save[strlen(save)]='\0';
                                            printf("Mutare incorecta! Player1 retrimite...\n");
                                            write(client,save,strlen(save)+1);
                                        }
                                        else if(joc.turn==2)
                                        {
                                            strcat(save,"Turn black-player2: ");
                                            strcat(save,joc.player2);
                                            save[strlen(save)]='\0';
                                            printf("Mutare incorecta! Player2 retrimite...\n");
                                            write(client,save,strlen(save)+1);
                                        }
                                        //printf("%s\n",save);
                                    }
                                }
                            
                        }while(stop==0);
                        if(stop==2)
                        {
                            char winer[10];
                            strcpy(winer,joc.player1);
                            strcat(winer," wins!");
                            winer[strlen(winer)]='\0';
                            printf("%s\n",winer);
                            addScor(100,joc.player1);
                            printf("Player-ul %s a acumulat 100 puncte!\n",joc.player1);
                            addScor(25,joc.player2);
                            printf("Player-ul %s a acumulat 25 puncte!\n",joc.player2);
                            write(client,winer,strlen(winer)+1);
                        }
                        else
                            if(stop==1)
                            {
                                char winer[10];
                                strcpy(winer,joc.player2);
                                strcat(winer," wins!");
                                winer[strlen(winer)]='\0';
                                printf("%s\n",winer);
                                addScor(100,joc.player2);
                                printf("Player-ul %s a acumulat 100 puncte!\n",joc.player2);
                                addScor(25,joc.player1);
                                printf("Player-ul %s a acumulat 25 puncte!\n",joc.player1);
                                write(client,winer,strlen(winer)+1);
                            }
                        break;
                    }
                    else if(strcmp(comanda,"losing")==0)
                    {
                        char coord[100];
                        int lv,cv,ln,cn;
                        int stop=-1;
                        //CREEZ LOBBY SI FAC WRITE cu CINE MUTA primul
                        struct lobby joc;
                        strcpy(joc.player1,user_logati[0]);
                        strcpy(joc.player2,user_logati[1]);
                        joc.turn=1;
                        
                        char initial[100];
                        strcpy(initial,salvareTabla());
                        strcat(initial,"Turn white-player1: ");
                        strcat(initial,joc.player1);
                        initial[strlen(initial)]='\0';
                        printf("Player1 %s incepe!\n",joc.player1);
                        write(client,initial,strlen(initial)+1);

                        do
                        {
                            save[0]='\0';
                            stop=sfarsitJoc();   
                            if(stop==1)
                            {
                                char winer[10];
                                strcpy(winer,joc.player1);
                                strcat(winer," wins!");
                                winer[strlen(winer)]='\0';
                                write(client,winer,strlen(winer)+1);
                            }
                            else
                                if(stop==2)
                                {
                                    char winer[10];
                                    strcpy(winer,joc.player2);
                                    strcat(winer," wins!");
                                    winer[strlen(winer)]='\0';
                                    write(client,winer,strlen(winer)+1);
                                }
                                else{
                                    read(client,coord,100);
                                    if(strcmp(coord,"back")==0) break;
                                    //printf("%s\n",coord);
                                    lv=(int)coord[0]-48;
                                    cv=(int)coord[1]-48;
                                    ln=(int)coord[2]-48;
                                    cn=(int)coord[3]-48;
                                    
                                    if(verifMutarePion(lv,cv,ln,cn,joc.turn)==1)
                                    {
                                        char save[100];
                                        strcpy(save,salvareTabla());
                                        if(joc.turn==1)
                                        {
                                            strcat(save,"Turn black-player2: ");
                                            strcat(save,joc.player2);
                                            save[strlen(save)]='\0';
                                            printf("Randul player-ului 2...\n");
                                            write(client,save,strlen(save)+1);
                                            joc.turn=2;
                                        }
                                        else if(joc.turn==2)
                                        {
                                            strcat(save,"Turn white-player1: ");
                                            strcat(save,joc.player1);
                                            save[strlen(save)]='\0';
                                            printf("Randul player-ului 1...\n");
                                            write(client,save,strlen(save)+1);
                                            joc.turn=1;
                                        }
                                        //printf("%s\n",save);
                                    }
                                    else
                                    {
                                        char save[100];
                                        strcpy(save,salvareTabla());
                                        if(joc.turn==1)
                                        {
                                            strcat(save,"Turn white-player1: ");
                                            strcat(save,joc.player1);
                                            save[strlen(save)]='\0';
                                            printf("Mutare incorecta! Player1 retrimite...\n");
                                            write(client,save,strlen(save)+1);
                                        }
                                        else if(joc.turn==2)
                                        {
                                            strcat(save,"Turn black-player2: ");
                                            strcat(save,joc.player2);
                                            save[strlen(save)]='\0';
                                            printf("Mutare incorecta! Player2 retrimite...\n");
                                            write(client,save,strlen(save)+1);
                                        }
                                        //printf("%s\n",save);
                                    }
                                }
                        }while(stop==0);
                        if(stop==2)
                        {
                            char winer[10];
                            strcpy(winer,joc.player2);
                            strcat(winer," wins!");
                            winer[strlen(winer)]='\0';
                            printf("%s\n",winer);
                            addScor(100,joc.player2);
                            printf("Player-ul %s a acumulat 100 puncte!\n",joc.player2);
                            addScor(25,joc.player1);
                            printf("Player-ul %s a acumulat 25 puncte!\n",joc.player1);
                            write(client,winer,strlen(winer)+1);
                        }
                        else
                            if(stop==1)
                            {
                                char winer[10];
                                strcpy(winer,joc.player1);
                                strcat(winer," wins!");
                                winer[strlen(winer)]='\0';
                                printf("%s\n",winer);
                                addScor(100,joc.player1);
                                printf("Player-ul %s a acumulat 100 puncte!\n",joc.player1);
                                addScor(25,joc.player2);
                                printf("Player-ul %s a acumulat 25 puncte!\n",joc.player2);
                                write(client,winer,strlen(winer)+1);
                            }
                        break;
                    }
				    else break;
                }
			}
			/* am terminat cu acest client, inchidem conexiunea */
	        exit(0);
		    close (client); 
    	}
    }	
}				