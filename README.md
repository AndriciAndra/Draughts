# How to run server7.c


# Draughts

# 1 Tehnologiile utilizate

Acest joc se realizeaza cu ajutorul protocolului TCP. Acesta este un serviciu bazat pe conexiuni, insemnand ca masinile care trimit si cele care primesc sunt conectate si comunica una cu cealalta tot timpul.
La polul opus, se afla protocolul UDP care nu este bazat pe conexiuni. UDP-ul urmareste un singur scop: trimiterea pachetelor de la o anumita sursa catre o destinatie, fara sa il intereseze starea acestora. Acest lucru aduce dupa sine un singur avantaj si anume viteza de transmitere a pachetelor ceea ce permite ca aplicatia sa functioneze fara intarzieri.
Pentru jocul ”Draughts”, siguranta primirii tuturor pachetelor este mai importanta decat o fluiditate a aplicatiei si de aceea, protocolul TCP este mai potrivit.
TCP - Transmission Control Protocol este un protocol sigur pentru transportul fluxului de octeti deoarece intre client si server trebuie sa aiba loc o conexiune pentru a putea comunica. Aceasta conexiune se realizeaza prin transmiterea de mesaje de la client la server care ne ofera siguranta deoarece se asteapta mereu confirmarea primirii datelor. Mecanismul stabileste astfel, o ordine a pachetelor care ajuta clientul sa isi dea seama daca au ajuns la destinatie iar in caz de
pierdere a unui pachet, sa il poata retrimite pana cand va primi confirmarea ca si acesta a ajuns la destinatie.

Jocul ”Draughts” nu se poate realiza daca clientul si serverul nu se afl˘a conectat, i permanent deoarece implic˘a schimbul de mesaje. Dup˘a ce clientul va
cere s˘a se autentifice/ˆınregistreze, el va veni mereu cu cereri pe care serverul trebuie s˘a le verifice (mutarea unei piese de joc, afis,area scorului) iar ˆın urma mesajului primit de la server, clientul ˆıs, i va realiza cererile.
Oprirea conexiunii dintre un client s,i server va avea loc prin implementarea opt,iunii de ”exit”.
Totodat˘a, este nevoie de un TCP concurent pentru ca serverul sa fie conectat cu mai mult, i client, i ˆın acelas, i timp. Acesta se realizeaz˘a prin crearea de procese copil pentru fiecare client ˆın parte. Astfel, fiecare proces copil se va ocupa de cate un client ˆın paralel, f˘ar˘a ca un client s˘a fie nevoit s˘a as,tepte ca serverul s˘a ˆınchid˘a conexiunea cu un alt client ca mai apoi s˘a se poat˘a ocupa de el.
Mecanismul complex de trasmisie a datelor este o caracteristic˘a a TCP-ului important˘a pentru joc deoarece este necesar ca fiecare cerere a clientului s˘a fie
citit˘a de server s,i executat˘a mai apoi. De exemplu, ne putem gˆandi c˘a o partid˘a de joc nu se poate realiza normal dac˘a o anumit˘a mutare a unuia dintre juc˘atori nu este primit˘a de server. Astfel, juc˘atorul nu ar putea s˘a respecte regulile implementate dac˘a serverul nu ar verifica mutarea s,i nu ar confirma c˘a este una valid˘a sau nu. De asemenea, este important˘a s,i pentru afis,area scorului unui anumit juc˘ator deoarece serverul nu poate c˘auta ˆın baza de date scorul cerut dac˘a user-ul necesar nu ajunge la destinat, ie sau poate afis,a scorul altui juc˘ator.
SQLite este o bibliotec˘a software care ofer˘a un sistem de gestionare a bazelor de date relat,ionale,fiind cea mai utilizat˘a ˆın ˆıntreaga lume.
Am optat pentru a folosi aceast˘a baz˘a de date deoarece este usor de utilizat ˆın ceea ce prives,te configurarea, administrarea bazei de dates,i resursele necesare, ˆın comparat, ie cu alte baze de date care sunt mai complexe. Spre exemplu, MySQL necesit˘a un proces separat de server pentru a funct,iona. Aplicat, iile care doresc s˘a acceseze serverul bazei de date, utilizeaz˘a protocolul TCP pentru a trimite s,i a primi cereri. De aceea, SQLite este caracterizat˘a prin simplitate pentru c˘a nu utilizeaz˘a arhitectura client/server. Aplicat, iile citesc s,i scriu direct din fis, ierele bazei de date stocate pe disc ˆıntrucat baza de date SQLite este integrat˘a cu aplicat,ia care acceseaz˘a baza de date.
Pentru proiect, aceasta este utilizat˘a ˆın scopul stoc˘arii scorului fiecarui jucator s,i afis, arii unui clasament atunci cˆand clientul solicit˘a. Codul surs˘a este disponibil prin fis,ierul antet sqlite3.h care defines,te interfat,a pe care biblioteca SQLite o prezint˘a programelor client.

# 2 Arhitectura aplicatiei
# 2.1 Conceptele implicate
Tabla de joc va fi reprezentat˘a de o matrice de 8 × 8, valorile din matrice reprezentˆand urmatoarele: 0 (loc liber), 1 (pion al juc˘atorului A), 2 (pion al juc˘atorului B), 3 (dama juc˘atorului A), 4 (dama juc˘atorului B) iar −1 (border).
Baza de date este reprezentat˘a de o tabel˘a ˆın care sunt stocate usernameurile s,i punctajele acestora. Va fi utilizat˘a pentru a caut˘a username-urile existente
(cˆand se primes,te cerere de log in sau sign up) s,i pentru a afis,a clasamentul ˆın funct, ie de scorul actualizat al tuturor juc˘atorilor din baza de date.
Serverul foloses,te un TCP concurent pentru a servi mai mult, i client, i simultan. ˆIn momentul ˆın care se realizeaz˘a o conexiune cu un client, se creaz˘a un proces copil care se va ocupa de procesarea cererilor:
– cˆand primes,te cerere pentru a se juca unul dintre cele dou˘a variante, se adaug˘a ˆıntr-o structur˘a cei doi juc˘atori. Se verific˘a mut˘arile ˆın funct, ie de
coordonate pˆan˘a cˆand este ˆındeplinit˘a condit,ia de final de joc. Ordinea juc˘atorilor este stabilit˘a de server la fiecare rund˘a, fiind transmis un mesaj clientului ˆın care se specific˘a cine trebuie s˘a mute. Clientul este responsabil de blocarea act,iunilor celui care nu mut˘a.
Cˆand se termin˘a jocul, acesta transmite p˘arintelui rezultatul care actualizeaz ˘a baza de date.
– cˆand primes,te cerere de afis,are a clasamentului, serverul alege primii 10 juc˘atori ordonat, i cresc˘ator din baza de date s,i pozit, ia juc˘atorului care a facut cererea.
