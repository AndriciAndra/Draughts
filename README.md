# Draughts

# 1. Tehnologiile utilizate

Acest joc se realizeaza cu ajutorul protocolului TCP. Acesta este un serviciu bazat pe conexiuni, insemnand ca masinile care trimit si cele care primesc sunt conectate si comunica una cu cealalta tot timpul.
La polul opus, se afla protocolul UDP care nu este bazat pe conexiuni. UDP-ul urmareste un singur scop: trimiterea pachetelor de la o anumita sursa catre o destinatie, fara sa il intereseze starea acestora. Acest lucru aduce dupa sine un singur avantaj si anume viteza de transmitere a pachetelor ceea ce permite ca aplicatia sa functioneze fara intarzieri.
Pentru jocul ”Draughts”, siguranta primirii tuturor pachetelor este mai importanta decat o fluiditate a aplicatiei si de aceea, protocolul TCP este mai potrivit.
TCP - Transmission Control Protocol este un protocol sigur pentru transportul fluxului de octeti deoarece intre client si server trebuie sa aiba loc o conexiune pentru a putea comunica. Aceasta conexiune se realizeaza prin transmiterea de mesaje de la client la server care ne ofera siguranta deoarece se asteapta mereu confirmarea primirii datelor. Mecanismul stabileste astfel, o ordine a pachetelor care ajuta clientul sa isi dea seama daca au ajuns la destinatie iar in caz de
pierdere a unui pachet, sa il poata retrimite pana cand va primi confirmarea ca si acesta a ajuns la destinatie.

Jocul ”Draughts” nu se poate realiza daca clientul si serverul nu se afla conectati permanent deoarece implica schimbul de mesaje. Dupa ce clientul va cere sa se autentifice/inregistreze, el va veni mereu cu cereri pe care serverul trebuie sa le verifice (mutarea unei piese de joc, afisarea scorului) iar in urma mesajului primit de la server, clientul isi va realiza cererile. Oprirea conexiunii dintre un client si server va avea loc prin implementarea optiunii de ”exit”.

Totodata, este nevoie de un TCP concurent pentru ca serverul sa fie conectat cu mai multi clienti in acelasi timp. Acesta se realizeaza prin crearea de procese copil pentru fiecare client in parte. Astfel, fiecare proces copil se va ocupa de cate un client in paralel, fara ca un client sa fie nevoit sa astepte ca serverul sa inchida conexiunea cu un alt client ca mai apoi sa se poata ocupa de el.

Mecanismul complex de trasmisie a datelor este o caracteristica a TCP-ului importanta pentru joc deoarece este necesar ca fiecare cerere a clientului sa fie citita de server si executata mai apoi. De exemplu, ne putem gandi ca o partida de joc nu se poate realiza normal daca o anumita mutare a unuia dintre jucatori nu este primita de server. Astfel, jucatorul nu ar putea sa respecte regulile implementate daca serverul nu ar verifica mutarea si nu ar confirma ca este una valida sau nu. De asemenea, este importanta si pentru afisarea scorului unui anumit jucator deoarece serverul nu poate cauta in baza de date scorul cerut daca user-ul necesar nu ajunge la destinatie sau poate afisa scorul altui jucator.

SQLite este o biblioteca software care ofera un sistem de gestionare a bazelor de date relationale, fiind cea mai utilizata in intreaga lume. Am optat pentru a folosi aceasta baza de date deoarece este usor de utilizat in ceea ce priveste configurarea, administrarea bazei de date si resursele necesare, in comparatie cu alte baze de date care sunt mai complexe. Spre exemplu, MySQL necesita un proces separat de server pentru a functiona. Aplicatiile care doresc sa acceseze serverul bazei de date, utilizeaza protocolul TCP pentru a trimite si a primi cereri. De aceea, SQLite este caracterizata prin simplitate pentru ca nu utilizeaza arhitectura client/server. Aplicatiile citesc si scriu direct din fisierele bazei de date stocate pe disc intrucat baza de date SQLite este integrata cu aplicatia care acceseaza baza de date.
Pentru proiect, aceasta este utilizata in scopul stocarii scorului fiecarui jucator si afisarii unui clasament atunci cand clientul solicita. Codul sursa este disponibil prin fisierul antet sqlite3.h care defineste interfata pe care biblioteca SQLite o prezinta programelor client.

# 2. Arhitectura aplicatiei - Conceptele implicate
Tabla de joc va fi reprezentata de o matrice de 8 × 8, valorile din matrice reprezentand urmatoarele: 0 (loc liber), 1 (pion al jucatorului A), 2 (pion al jucatorului B), 3 (dama jucatorului A), 4 (dama jucatorului B) iar −1 (border).
Baza de date este reprezentata de o tabela in care sunt stocate usernameurile si punctajele acestora. Va fi utilizata pentru a cauta username-urile existente (cand se primeste cerere de log in sau sign up) si pentru a afisa clasamentul in functie de scorul actualizat al tuturor jucatorilor din baza de date.
Serverul foloseste un TCP concurent pentru a servi mai multi clienti simultan. In momentul in care se realizeaza o conexiune cu un client, se creaza un proces copil care se va ocupa de procesarea cererilor:
– cand primeste cerere pentru a se juca unul dintre cele doua variante, se adauga intr-o structura cei doi jucatori. Se verifica mutarile in functie de coordonate pana cand este indeplinita conditia de final de joc. Ordinea jucatorilor este stabilita de server la fiecare runda, fiind transmis un mesaj clientului in care se specifica cine trebuie sa mute. Cand se termina jocul, acesta transmite parintelui rezultatul care actualizeaza baza de date.
– cand primeste cerere de afisare a clasamentului, serverul alege primii 10 juc˘atori ordonati crescator din baza de date si pozit, ia jucatorului care a facut cererea.

# Cum executam server7.c
1. gcc server7.c -o server7 -lsqlite3
2. ./server7
