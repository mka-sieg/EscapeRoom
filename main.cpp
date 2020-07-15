#include <windows.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <conio.h>

using namespace std;

HANDLE hOut;
//kody do sejfu i drzwi
int good_code1=1231;//sejf
int good_code2=1094; //drzwi
string code_num1[2]={"12","31"};
string code_num2[4]={"1","0","9","4"};
//menu gry
string line="===================================================================================================================\n";
string game_name="                                  ESCAPE ROOM                                    |       dostępne komendy          \n";
string line1="                                                                                 | uzyj - łączy 2 rzeczy           \n";
string line2="         Zadania:                                                                | obroc - obraca gracza           \n";
string line3="         Otwórz sejf.                                                            | wez - dodaje rzecz do ekwipunku \n";
string line4="         Wydostań się ze sklepu.                                                 | ekwipunek - wyświetla ekwipunek \n";
string line5="                                                                                 | popatrz - pozwala zbadać rzecz  \n";
string line6="         Wskazówka:                                                              | kod - pozwala uzyć zamków na kod\n";
string line7="                                                                                 | dziennik - wyświetla dziennik   \n";
string line8="                                                                                 | koniec - kończy gre             \n";
string line7w="| dziennik - wyświetla dziennik   \n";
string line8w="| koniec - kończy gre             \n";
string lines=line1+line2+line3+line4+line5+line6+line7+line8;
//intro
string escape0="oooooooooo     oooooooooo     oooooooooo        ooo        ooooooooooooo    oooooooooo";
string escape1="oooooooooo     oooooooooo     oooooooooo       oo oo       ooooooooooooo    oooooooooo";
string escape2="ooo            ooo            ooo             oo   oo      ooo       ooo    ooo       ";
string escape3="ooo            ooo            ooo            oo     oo     ooo       ooo    ooo       ";
string escape4="ooo            ooo            ooo           oo       oo    ooo       oo     ooo       ";
string escape5="oooooooo       oooooooooo     ooo           ooooooooooo    ooo       oo     oooooooo  ";
string escape6="oooooooo       oooooooooo     ooo           ooooooooooo    ooooooooooo      oooooooo  ";
string escape7="ooo                   ooo     ooo           oo       oo    ooooooooo        ooo       ";
string escape8="ooo                   ooo     ooo           oo       oo    ooo              ooo       ";
string escape9="ooo                   ooo     ooo           oo       oo    ooo              ooo       ";
string escape10="oooooooooo     oooooooooo     oooooooooo    oo       oo    ooo              oooooooooo";
string escape11="oooooooooo     oooooooooo     oooooooooo    oo       oo    ooo              oooooooooo";

string room0="ooooooooooooo     oooooooooooo      oooooooooooo       ooo         ooo ";
string room1="ooooooooooooo     oooooooooooo      oooooooooooo      ooooo       ooooo";
string room2="ooo       ooo     oo        oo      oo        oo      oo  oo     oo  oo";
string room3="ooo       ooo     oo        oo      oo        oo      oo   oo   oo   oo";
string room4="ooo       oo      oo        oo      oo        oo      oo    oo oo    oo";
string room5="ooo       oo      oo        oo      oo        oo      oo     ooo     oo";
string room6="ooooooooooo       oo        oo      oo        oo      oo      o      oo";
string room7="ooooooooo         oo        oo      oo        oo      oo             oo";
string room8="ooo    oo         oo        oo      oo        oo      oo             oo";
string room9="ooo     ooo       oooooooooooo      oooooooooooo      oo             oo";
string room10="ooo     oooo      oooooooooooo      oooooooooooo      oo             oo";

string str_line0="JK wysłał cię do zbadania sklepu.";
string str_line1="Jak trudne to może być.";
string str_line2="Wchodząc do sklepu zauważasz, że nikogo tam nie ma.";
string str_line3="Nagle zatrzaskują się za tobą drzwi.";
string str_line4="Próbujesz je otworzyć, ale są zamknięte.";
string str_lines=str_line0+"\n"+str_line1+"\n"+str_line2+"\n"+str_line3+"\n"+str_line4+"\n";

string notatka="Pod wpływem ciepła można odczytać wiadomości zapisane atramentem sympatycznym";

string scena0="\n              *   *                       * *\n            *   *   *                    *   *\n              *   *                     *  *  *\n                                         *   *\n                                          * *\n                                                                      *\n                                                                      *\n                                                                    *   *\n                                                                * *   *   * *\n                                                                    *   *\n                                                                      *\n                                                                      *\n";
string scena1="                                    * *  *  * *\n                                     * * * * *\n                                 * * * *   * * * * *\n                                     * * * * *\n                                   *  *  *  * *\n                                     *   *   *\n                                    *    *    *                  *\n                                                                 *\n                                                               *   *    \n                                                           * *   *   * *        \n                                                               *   * \n                                                                 *   \n                                                                 *    \n";
string scena2="                                    * *  *  * *\n                                     * * * * *\n                                * * * *    * * * * *\n                                     * * * * *\n                                   *  *  *  * *\n                                     *   *   *\n            *                       *    *    *        \n            *                                  \n          *   *       \n      * *   *   * *  \n          *   *    \n            *      \n            *      \n";
string scena3="                                         *  \n                                       *   *\n                                    * *  *  * *   \n                                       *   *               *       *\n                                         *                  *  *  *\n                                         *               * * *   * * *\n            *                                                * * *\n            *                                               *  *  *   \n          *   *        \n      * *   *   * *     \n          *   *      \n            *       \n            *                \n";
string scena4="                                          *  \n                                       *   *\n                                 *  **   *   **   *   \n                                       *   *              \n                                         *  \n                                         *       \n            *     \n            *     \n          *   *  \n      * *   *   * *   \n          *   *      \n            *         \n            *       \n";
string scena5="\noooooooooo    ooooooooooooo       ooo      oooo             oooo    oooooooooooo   oooooooooooooooo  \noooooooooo    ooooooooooooo      oo oo      ooo             ooo     oooooooooooo    oooooooooooooo\nooo    ooo    ooo       ooo     oo   oo      oo             oo      oo        oo     oooooooooooo\nooo    ooo    ooo       ooo    oo     oo     oo             oo      oo        oo      oooooooooo\nooo    ooo    ooo       oo    oo       oo    oo             oo      oo        oo       oooooooo\nooooooooo     ooo       oo    ooooooooooo    oo     ooo     oo      oo        oo        oooooo\noooooooo      ooooooooooo     ooooooooooo    oo    oo oo    oo      oo        oo        oooooo\nooo    oo     ooooooooo       oo       oo    oo   oo   oo   oo      oo        oo         oooo\nooo     ooo   ooo    oo       oo       oo    oo  oo     oo  oo      oo        oo         \nooo     ooo   ooo     ooo     oo       oo    oo oo       oo oo      oo        oo        oooooo\nooooooooooo   ooo     oooo    oo       oo    oooo         oooo      oooooooooooo        oooooo\nooooooooooo   ooo     ooooo   oo       oo    oo             oo      oooooooooooo        oooooo\n\n\nHasło: Miś polarny\n";
string scena[5]={scena0,scena1,scena2,scena3,scena4};
//wiadomosci jak poprawny kod
string message_drzwi="Poprawny kod.\nOtwarte drzwi.\n";
string message_sejf="Poprawny kod.\nSejf jest otwarty.\nPo otwarciu sejfu okazuje się, że jest pełny notatek.\nNotatki są zapisane w innym języku lub szyfrem nie masz czasu na ich odczytanie.\nJak uda wam się wydostać wtedy może JK pomoże ci je rozszyfrować.";
//opis strony pokoju
string gora="Na wprost widzisz ladę, a na niej pusty kubek obok zapałki. Za ladą stoi krzesło. Wisi na nim sweter.\nZ tyłu stoją półki sięgające do sufitu. Na nich różnego rodzaju produkty. Zwraca twój wzrok dziwna książka i\nsłownik języka chińskiego. Z prawej stoi duża szafa. Nie jest zamknięta. Po drugiej stronie jest metalowy sejf na kod.\nZauważasz, że przed ladą leży mały kolorowy dywan.";
string dol="Widzisz drzwi wejściowe. Na lewo od nich jest roślina w doniczce, \nktóra jest przywiązana do patyka. Sznurek, którym jest przywiązana może się do czegoś przydać.\nPo prawej stoi sekretarzyk. Na nim stoi stara skrzynia zamknięta na klucz i tekturowe pudełko.";
string lewo="Przy tej ścianie stoi tylko mały stolik. Na nim widzisz biały obrus. \nNad stolikiem wisi lustro. Kiedy podchodzisz zauważasz, że pod stołem stoi szafka.";
string prawo="Całą ścianę zajmuje tu obraz przedstawiający bitwę morską.";
//wiadomosc po poprawnym polaczeniu przedmiotow
string good_0_13="Po rozszyfrowaniu znak okazuję się liczbą "+(code_num2[0]);
string good_2_8="Wyjmujesz jedną zapałkę i zapalasz świeczkę.";
string good_24_12="Przykładasz kartkę do świeczki. Ciepło ujawnia ukrytą liczbę "+(code_num2[2]);
string good_9_7="Przyczepiasz magnes do sznurka.";
string good_25_18="Machasz linką z magnesem. Wreszcie słyszysz, że kliknięcie świadczące, \nże kluczyk przyczepił się do magnesu. Udało ci się wyciągnął kluczyk z dziury.\nKluczyk dodany do ekwipunku.";
string good_14_6="Po spojrzeniu na notatkę za pomocą lustra widzisz dokładnie\nco jest napisane: "+notatka;
string good_22_05="Otwierasz skrzynię w środku znajduje się zmięty papier.\nPo rozwinięciu widzisz zapisaną liczbę "+(code_num2[1]);
//tekst przy niepoprawnym polaczeniu przedmiotow
string bad="Nie można nic zrobić";
string bad_9_18="Spuszczasz sznurek powoli do dziury. \nNiestety klucz sam nie potrafi złapać sznurka. \nPrzydałoby się coś co przyczepi metalowy klucz do sznurka.";
string bad_0_2="Uważaj bo spalisz słownik.";
string bad_1_2="Uważaj bo spalisz książkę.";
string bad_4_2="Uważaj bo spalisz obraz.";
string bad_5_2="Uważaj bo spalisz skrzynie z zawartością.";
string bad_9_2="Sznurek może się przydać. Lepiej go nie spalać.";
string bad_10_2="Biedna roślina, co ci zrobiła że chcesz ją spalić.";
string bad_11_2="Jeżeli chcesz się wydostać lepiej tego nie robić.";
string bad_12_2="Jeżeli chcesz się wydostać lepiej tego nie robić.";
string bad_13_2="Jeżeli chcesz się wydostać lepiej tego nie robić.";
string bad_14_2="Jeżeli chcesz się wydostać lepiej tego nie robić.";
string bad_15_7="Dopiero co z tego był wyciągnięty.";
string bad_16_7="Magnes przyciaga się do sejfu, ale raczej ci to nie pomoże.";
string bad_17_2="Dywan może nie jest piękny,ale nie warto go palić.";
string bad_20_2="Jeżeli chcesz się wydostać lepiej tego nie robić.";
string bad_21_2="Jeżeli chcesz się wydostać lepiej tego nie robić.";
string bad_22_18="Chcesz wrzucić klucz do dziury.";
string bad_23_2="Obrus leży na drewnianym stoliku.\nJak go zapalisz niedługo po tym zacznie palić się wszystko w pokoju. ";
string bad_24_2="Świeca już jest zapalona.";
string bad_25_2="Chyba nie chcesz zniszyć swojej pracy.";
string bad_24_18="Lepiej tego nie robić.\nNie masz jak wyjąć świecy jak ją wrzucisz.";
string bad_25_18="Lepiej tego nie robić.\nNie masz jak wyjąć świecy jak ją wrzucisz.";
string bad_25_24="Chyba nie chcesz zniszyć swojej pracy.";
string bad_0_18="Nawet gdyby to był dobry pomysł.\nTen przedmiot nie mieści się w dziurze.";
string bad_1_18="Nawet gdyby to był dobry pomysł.\nTen przedmiot nie mieści się w dziurze.";
string bad_2_18="Wrzucasz zapaloną zapałkę do dziury.\nZapałka od razu gaśnie.\nA czego innego można było się spodziewać.";
string bad_3_18="Lepiej nie wrzucać kubka do dziury.";
string bad_7_18="Jesteś za daleko żeby przyciągnąć klucz.\nPrzydał by się sznurek.";
string bad_8_18="Lepiej tego nie robić.\nNie masz jak wyjąć świecy jak ją wrzucisz.";
string bad_11_18="Nawet gdyby to był dobry pomysł.\nTen przedmiot nie mieści się w dziurze";
string bad_12_18="Lepiej tego nie robić.\nTen przedmiot może się jeszcze przyda";
string bad_13_18="Lepiej tego nie robić.\nTen przedmiot może się jeszcze przydać.";
string bad_14_18="Lepiej tego nie robić.\nTen przedmiot może się jeszcze przydać.";
string bad_15_18="Nawet gdyby to był dobry pomysł.\nTen przedmiot nie mieści się w dziurze.";
//opis przedmiotow, do komenty popatrz
string opis_0="Słownik chińskiego. W tym sklepie nie sprzedają słowników. Może sprzedawca uczy się chińskiego.";
string opis_1="Otwierasz książkę, a że środka wypada wycinek.\nPróbujesz ją odczytać, ale nie znasz tego języka….\nchwila wszystko jest odwrotnie zapisane.";
string opis_2="Pudełko zapałek. Po jednej stronie jest obrazek przedtawiający namiot i napis, Cyranka\n po drugiej kaczka z proporcem i napis Baza Obozowa Hufca ZHP Otwock w Przerwankach";
string opis_3="Teraz widzisz, że kubek nie jest pusty. W środku jest jeszcze troche kawy.\nPo przechyleniu kubka widzisz, że na dnie jest narysowana "+(code_num1[1]);
string opis_4="Przyglądasz się obrazowi.\nPo chwili zauważasz, że kawałek kartki wystaje zza obrazu.\nKartka jest pusta.";
string opis_5="Tę skrzynie można otworzyć przy pomocy klucza.";
string opis_6="O, a kto to w lustrze wyjątkowo dobrze wygląda.\nPrzeglądasz się chwile w swoje oblicze. \nTa nowa fryzura bardzo dobrze ci pasuje.\nWreszcie przypominasz sobie po co tu jesteś i wracasz do roboty.";
string opis_7="Mega mocny magnes";
string opis_8="Biała gruba świeca. Była już kiedyś zapalana.";
string opis_9="Bawełniany sznurek, 100% bio. Bardzo długi.";
string opis_10="Roślina jest przywiązana sznurkiem do patyka.\nOdwiązujesz sznurek.";
string opis_11="Sweter jest niedbale powieszony na krześle.\nW lewej kieszeni nic nie ma, ale w prawej znajdujesz notatkę.\nNotatka jest zapisana w jakimś obcym języku.\nCzy to chiński?";
string opis_12="Papier, który był w kieszeni swetra. Na nim zapisane są jakieś znaki chińskie.";
string opis_13="Notatka z ksiazki z dziwnymi znakami. Są zapisane jakby od tyłu.";
string opis_14="Kartka wyjęta z obrazu. Jest pusta.";
string opis_15="Otwierasz pudełko. W środku znajduje się kilka magnesów.";
string opis_16="Przed tobą stoi metalowy sejf.\nWygląda na to, że ktoś już wpisał pierwszą liczbę. Brakuje tylko dwóch liczb dwucyfrowych.";
string opis_17="Dywan wygląda jakby był niedawno kupiony.\nNie pasuje do reszty mebli. Dość komicznie wygląda przy wielkich szafach i półkach,\nbardziej jak wycieraczka niż dywan. Odkrywasz dywan, a za nim pokazuje mała dziura.\nDziura jest dość głęboka, ale udaje ci się zobaczyć, że w środku znajduje się mały klucz.\nPróbujesz sięgnąć po niego ręką, ale jest za daleko. Przydał by się jakiś sznurek.";
string opis_18="Dziura. \nBardzo głęboka i ciemna dziura. Na dole widać mały metalowy klucz.";
string opis_19="Drzwi wyglądają normalnie, ale są zamknięte i nie mają zamka od klucza.\nObok znajduję się klawiatura do wpisania kodu. Wygląda na to żeby odblokować drzwi musisz znaleźć 4 liczby jednocyfrowe.";
string opis_20="Otwierasz szafkę, a w środku znajduje się tylko jedna świeca.";
string opis_21="Otwierasz szafę. W środku znajdują się jakieś papiery, naczynia, kosmetyki.\nNic z tych rzeczy raczej nie będzie ci przydatne.\nZauważasz jednak na drzwiczkach wycięty numer "+(code_num2[3]);
string opis_22="Mały metalowy klucz";
string opis_23="Przyglądasz się obrusowi.\nWygląda jak zwykły obrus.\nZauważasz jednak, że na brzegu wyhaftowana jest. "+(code_num1[0]);
string opis_24="Zapalona swieczka. Jeszcze nie tak gorąca";
string opis_25="Sznurkomagnes - magnes mocno przywiązany do sznurka. \nNic metalowego nie oprze się temu połączeniu.";
//opis startowy
string start="Będziesz potrzebował kodu, żeby otworzyć drzwi. Warto rozejrzeć się po sklepie.\nMoże są tu jakieś wskazówki.\n\nPoruszasz się i wykonujesz działania wpisując komendy.\nŻeby znaleźć przedmoty obracaj się za pomoca komendy -obroc-.\n";
//tablica kolorow
BOOL kolory[5]={FOREGROUND_BLUE | FOREGROUND_RED,FOREGROUND_RED,FOREGROUND_GREEN,FOREGROUND_BLUE,FOREGROUND_RED|FOREGROUND_GREEN};
//wskazowka wyswietlane losowo
string wskazowka[3]={"Warto użyć komendy popatrz można odkryć ciekawe rzeczy       ","Wszystkie odkryte kody i podpowiedzi znajdują się w dzienniku","Wpisuj wszystkie komendy bez polskich znaków.                "};

struct Rzeczy{//struktura przedmiotow z ktorymi mozna cos zrobic
    string name;
    bool inventory;
    int side;
    bool found;
    int with_name;
    string opis_good;
    string opis_bad;
    string opis;
    bool caninv;
    bool kod;

};
struct Strona{ // struktura stron pokoju
    string name;
    string opis;
    bool active;
    void zmiana_side(int random);

};
struct Dziennik{ //struktura elementow dziennika
    string skad;
    string nazwa;
    string opis;
    bool active;
};
void zmiana_body(string zmiana){ // fun. zmiany tekstu opisu aktywenj strony pokoju
    system( "cls" );
    string side;
    string ekran;
    string body;
    body=zmiana+"\n";
    ekran=line+game_name+line+lines+line+side+line+body+line;
    cout<<ekran<<endl;
}
void Strona::zmiana_side(int random){ //fun. zmiany aktywnej strony pokoju
    system( "cls" );
    string ekran,ekran2;
    string side;
    string body;
    string line_blank,line_blank2;
    body=opis+"\n";
    side="                                                STRONA: "+name+"                                                       \n";
    line7w="| dziennik - wyświetla dziennik   \n";
    line7="         "+wskazowka[random]+"           "+line7w;
    lines=line1+line2+line3+line4+line5+line6;
    ekran=line+game_name+line;
    line_blank="         ";
    line_blank2="           ";
    ekran2=line+side+line+body+line;
    cout<<ekran;
    cout<<lines;
    cout<<line_blank;
    SetConsoleTextAttribute( hOut, kolory[random] );
    cout<<wskazowka[random];
    SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
    cout<<line_blank2;
    cout<<line7w;
    cout<<line8;
    cout<<ekran2<<endl;
}
int main(){
    hOut = GetStdHandle( STD_OUTPUT_HANDLE );
    srand((unsigned)time(0));
    system("chcp 65001");
    PlaySound(TEXT("Muzyka/8-bit-game-theme-2.wav"), NULL, SND_FILENAME | SND_ASYNC);

    string line_blank2="               ";
    string line_blank1="                    ";
    bool cont;
    int gameon,rzecz1num,rzecz2num,dalej,code,good_code,random,random2,active_side,char1;
    string komenda,message,rzecz1,rzecz2;
    gameon=0;
    int x=0;
    //tablica elementow klasy stron pokoju
    Strona tab_side[5]={{"przod",gora,true},{"tyl",dol,false},
    {"lewo",lewo,false},{"prawo",prawo,false},{"niewiadomo","niewiadomo",false}};

    Rzeczy tablica[26]={ //tablica el. klasy przedmiotow
  /*0*/  {"slownik",false,0,false,13,good_0_13,bad,opis_0,true,false},
  /*1*/ {"ksiazka",false,0,false,-1," ",bad,opis_1,true,false},
  /*2*/ {"zapalki",false,0,false,8,good_2_8,bad,opis_2,true,false},
  /*3*/ {"kubek",false,0,false,-1," ",bad,opis_3,true,false},
  /*4*/ {"obraz",false,3,false,-1," ",bad,opis_4,false,false},
  /*5*/ {"skrzynia",false,1,false,22,good_22_05,bad,opis_5,false,false},
  /*6*/{"lustro",false,2,false,14,good_14_6,bad,opis_6,false,false},
  /*7*/{"magnes",false,4,false,9,good_9_7,bad,opis_7,true,false},
  /*8*/{"swieca",false,4,false,2,good_2_8,bad,opis_8,true,false},
  /*9*/{"sznurek",false,4,false,7,good_9_7,bad,opis_9,true,false},
  /*10*/{"roslina",false,1,false,-1," ",bad,opis_10,false,false},
  /*11*/{"sweter",false,0,false,-1," ",bad,opis_11,false,false},
  /*12*/{"kartka",false,4,false,24,good_24_12,bad,opis_12,true,false},
  /*13*/{"notatka",false,4,false,0,good_0_13,bad,opis_13,true,false},
  /*14*/{"wycinek",false,4,false,6,good_14_6,bad,opis_14,true,false},
  /*15*/{"pudelko",false,1,false,-1," ",bad,opis_15,false,false},
  /*16*/{"sejf",false,0,false,-1," ",bad,opis_16,false,true},
  /*17*/{"dywan",false,0,false,-1," ",bad,opis_17,false,false},
  /*18*/{"dziura",false,4,false,25,good_25_18,bad,opis_18,false,false},
  /*19*/{"drzwi",false,1,false,-1," ",bad,opis_19,false,true},
  /*20*/{"szafka",false,2,false,-1," ",bad,opis_20,false,false},
  /*21*/{"szafa",false,0,false,-1," ",bad,opis_21,false,false},
  /*22*/{"klucz",false,4,false,5,good_22_05,bad,opis_22,true,false},
  /*23*/{"obrus",false,2,false,-1," ",bad,opis_23,false,false},
  /*24*/{"zapalona_swieca",false,4,false,12,good_24_12,bad,opis_24,true,false},
  /*25*/{"sznurkomagnes",false,4,false,18,good_25_18,bad,opis_25,true,false}};
//tablica el. klasy dziennika
    Dziennik tab_dziennik[8]={{"sweter","papier",code_num2[0],false},{"obraz","kartka",code_num2[2],false},
    {"książka","notatka",notatka,false},{"skrzynia"," ",code_num2[1],false},{"obrus"," ",code_num1[0],false},{"szafa"," ",code_num2[3],false},
    {"kubek"," ",code_num1[1],false}};

    system( "cls" );
    cout<<"Żeby pominąć intro kliknij spacje, żeby kontynuować kilknij inny klawisz"<<endl;
    //wyswietlenie intra
    if(getch()!=' '){
    system( "cls" );
    cout<<endl<<endl;
    cout<<line_blank2<<escape0<<endl;
    Sleep(500);
    cout<<line_blank2<<escape1<<endl;
    Sleep(500);
    cout<<line_blank2<<escape2<<endl;
    Sleep(500);
    cout<<line_blank2<<escape3<<endl;
    Sleep(500);
    cout<<line_blank2<<escape4<<endl;
    Sleep(500);
    cout<<line_blank2<<escape5<<endl;
    Sleep(500);
    cout<<line_blank2<<escape6<<endl;
    Sleep(500);
    cout<<line_blank2<<escape7<<endl;
    Sleep(500);
    cout<<line_blank2<<escape8<<endl;
    Sleep(500);
    cout<<line_blank2<<escape9<<endl;
    Sleep(500);
    cout<<line_blank2<<escape10<<endl;
    Sleep(500);
    cout<<line_blank2<<escape11<<endl;
    Sleep(1000);
    cout<<endl<<endl;
    cout<<line_blank1<<room0<<endl;
    Sleep(500);
    cout<<line_blank1<<room1<<endl;
    Sleep(500);
    cout<<line_blank1<<room2<<endl;
    Sleep(500);
    cout<<line_blank1<<room3<<endl;
    Sleep(500);
    cout<<line_blank1<<room4<<endl;
    Sleep(500);
    cout<<line_blank1<<room5<<endl;
    Sleep(500);
    cout<<line_blank1<<room6<<endl;
    Sleep(500);
    cout<<line_blank1<<room7<<endl;
    Sleep(500);
    cout<<line_blank1<<room8<<endl;
    Sleep(500);
    cout<<line_blank1<<room9<<endl;
    Sleep(500);
    cout<<line_blank1<<room10<<endl;
    Sleep(500);
    cout<<endl<<endl;
    cout<<endl<<endl;
    Sleep(3500);

    while ( str_lines[x] != '\0'){
        cout << str_lines[x];
        Sleep(100);
        x++;
    };
    system("pause");
    }
    system( "cls" );
    PlaySound(TEXT("Muzyka/keep-at-it-loop"), NULL, SND_LOOP | SND_ASYNC);
    zmiana_body("Rozpoczecie gry\n"+start);
    active_side=0;
    //rozpoczecie gry
    while(gameon==0){
        rzecz1num=-1,rzecz2num=-1;
        rzecz1=" ",rzecz2=" ";
        cout<<"Wpisz komendę: "<<endl;
        cin>>komenda;
        if(komenda=="obroc"){ //zmiana aktywnej strony pokoju
            cout<<"Wpisz stronę(przod, tyl, lewo, prawo): "<<endl;
            cin>>rzecz1;
            for(int i=0;i<5;i++){
                if (tab_side[i].name==rzecz1){
                    char1=i;
                    break;
                }else{
                    char1=active_side;
                }
            }
            cout<<tab_side[char1].opis<<endl;
            tab_side[active_side].active=false;
            tab_side[char1].active=true;
            active_side=char1;
            random= (rand()%3);
            tab_side[active_side].zmiana_side(random);
            for(int i=0;i<26;i++){
                    if (tablica[i].side==active_side and tablica[i].found==false){
                            tablica[i].found=true;
                    }
            }
        }else if(komenda=="koniec"){ //wyjscie z gry
            string odp;
            cout<<"Czy napewno chcesz wyjść z gry"<<endl;
            cout<<"tak | nie"<<endl;
            cin>>odp;
            if(odp=="tak"){
                gameon=1;
            }else {
                cout<<"Kontynuje gre"<<endl;
            }

        }else if(komenda=="uzyj"){ //uzycie dwoch przedmiotow
            dalej=0;
            cout<<"Wpisz pierwszy przedmiot"<<endl;
            cin>>rzecz1;
            for(int i=0;i<26;i++){
                if (tablica[i].name==rzecz1){
                    rzecz1num=i;
                    break;
                }
            }
            if(tablica[rzecz1num].found==true){//sprawdzenie czy 1 przedmiot zostal wczesniej znaleziony
                if(tablica[rzecz1num].inventory==true or tablica[rzecz1num].side==active_side){//spr czy znajduje sie w ekwipunku lub na aktywnej stronie
                    dalej++;
                }else{
                    cout<<"Nie mozna tego zrobic"<<endl;
                    }
            }else{
                cout<<"Nie znaleziono"<<endl;
            }

            if(dalej==1){
                cout<<"Wpisz drugi przedmiot"<<endl;
                cin>>rzecz2;
                for(int i=0;i<26;i++){
                    if (tablica[i].name==rzecz2){
                        rzecz2num=i;
                        break;
                    }
                }
                if(tablica[rzecz2num].found==true){//sprawdzenie czy 2 przedmiot zostal wczesniej znaleziony
                    if(tablica[rzecz2num].inventory==true or tablica[rzecz2num].side==active_side){//spr czy znajduje sie w ekwipunku lub na aktywnej stronie
                        dalej++;
                    }else{
                        cout<<"Nie mozna tego zrobic"<<endl;
                    }
                }else{
                    cout<<"Nie znaleziono"<<endl;
                }
            }
            if(dalej==2){//w zaleznosci od tego jakie przemioty sa uzywane dzieja sie odpowiednio ponizsze komendy
                if(tablica[int(rzecz1num)].with_name==rzecz2num){
                    cout<<tablica[int(rzecz1num)].opis_good<<endl;
                    if((rzecz1num==0 and rzecz2num==13) or (rzecz2num==0 and rzecz1num==13)){
                        tab_dziennik[0].active=true;
                        cout<<"Dodano wpis do dziennika"<<endl;

                    }else if((rzecz1num==2 and rzecz2num==8) or (rzecz2num==2 and rzecz1num==8)){
                        tablica[24].inventory=true;
                        tablica[24].found=true;
                        cout<<"Dodano do ekwipunku "<<tablica[24].name<<endl;
                        tablica[8].inventory=false;

                    }else if((rzecz1num==24 and rzecz2num==12) or (rzecz2num==24 and rzecz1num==12)){
                        tab_dziennik[1].active=true;
                        cout<<"Dodano wpis do dziennika"<<endl;

                    }else if((rzecz1num==9 and rzecz2num==7) or (rzecz2num==9 and rzecz1num==7)){
                        tablica[25].inventory=true;
                        tablica[25].found=true;
                        cout<<"Dodano do ekwipunku "<<tablica[25].name<<endl;
                        tablica[rzecz1num].inventory=false;
                        tablica[rzecz2num].inventory=false;

                    }else if((rzecz1num==25 and rzecz2num==18) or (rzecz2num==25 and rzecz1num==18)){
                        tablica[22].inventory=true;
                        tablica[22].found=true;
                        cout<<"Dodano do ekwipunku "<<tablica[22].name<<endl;

                    }else if((rzecz1num==14 and rzecz2num==6) or (rzecz2num==14 and rzecz1num==6)){
                        tab_dziennik[2].active=true;
                        cout<<"Dodano wpis do dziennika"<<endl;

                    }else if((rzecz1num==22 and rzecz2num==5) or (rzecz2num==22 and rzecz1num==5)){
                        tab_dziennik[3].active=true;
                        cout<<"Dodano wpis do dziennika"<<endl;
                    }
            }else{//wyswietlenie wiadomosci jezeli 2 przednioty nie moga byc razem uzyte
                if((rzecz1num==0 and rzecz2num==2) or (rzecz2num==0 and rzecz1num==2)){
                    cout<<bad_0_2<<endl;
                }else if((rzecz1num==1 and rzecz2num==2) or (rzecz2num==1 and rzecz1num==2)){
                    cout<<bad_1_2<<endl;
                }else if((rzecz1num==4 and rzecz2num==2) or (rzecz2num==4 and rzecz1num==2)){
                    cout<<bad_4_2<<endl;
                }else if((rzecz1num==5 and rzecz2num==2) or (rzecz2num==5 and rzecz1num==2)){
                    cout<<bad_5_2<<endl;
                }else if((rzecz1num==9 and rzecz2num==2) or (rzecz2num==9 and rzecz1num==2)){
                    cout<<bad_9_2<<endl;
                }else if((rzecz1num==10 and rzecz2num==2) or (rzecz2num==10 and rzecz1num==2)){
                    cout<<bad_10_2<<endl;
                }else if((rzecz1num==11 and rzecz2num==2) or (rzecz2num==11 and rzecz1num==2)){
                    cout<<bad_11_2<<endl;
                }else if((rzecz1num==12 and rzecz2num==2) or (rzecz2num==12 and rzecz1num==2)){
                    cout<<bad_12_2<<endl;
                }else if((rzecz1num==13 and rzecz2num==2) or (rzecz2num==13 and rzecz1num==2)){
                    cout<<bad_13_2<<endl;
                }else if((rzecz1num==14 and rzecz2num==2) or (rzecz2num==14 and rzecz1num==2)){
                    cout<<bad_14_2<<endl;
                }else if((rzecz1num==15 and rzecz2num==7) or (rzecz2num==15 and rzecz1num==7)){
                    cout<<bad_15_7<<endl;
                }else if((rzecz1num==16 and rzecz2num==7) or (rzecz2num==16 and rzecz1num==7)){
                    cout<<bad_16_7<<endl;
                }else if((rzecz1num==17 and rzecz2num==2) or (rzecz2num==17 and rzecz1num==2)){
                    cout<<bad_17_2<<endl;
                }else if((rzecz1num==20 and rzecz2num==2) or (rzecz2num==20 and rzecz1num==2)){
                    cout<<bad_20_2<<endl;
                }else if((rzecz1num==21 and rzecz2num==2) or (rzecz2num==21 and rzecz1num==2)){
                    cout<<bad_21_2<<endl;
                }else if((rzecz1num==22 and rzecz2num==18) or (rzecz2num==22 and rzecz1num==18)){
                    cout<<bad_22_18<<endl;
                }else if((rzecz1num==23 and rzecz2num==2) or (rzecz2num==23 and rzecz1num==2)){
                    cout<<bad_23_2<<endl;
                }else if((rzecz1num==24 and rzecz2num==2) or (rzecz2num==24 and rzecz1num==2)){
                    cout<<bad_24_2<<endl;
                }else if((rzecz1num==25 and rzecz2num==2) or (rzecz2num==25 and rzecz1num==2)){
                    cout<<bad_25_2<<endl;
                }else if((rzecz1num==24 and rzecz2num==18) or (rzecz2num==24 and rzecz1num==18)){
                    cout<<bad_24_18<<endl;
                }else if((rzecz1num==25 and rzecz2num==18) or (rzecz2num==25 and rzecz1num==18)){
                    cout<<bad_25_18<<endl;
                }else if((rzecz1num==25 and rzecz2num==24) or (rzecz2num==25 and rzecz1num==24)){
                    cout<<bad_25_24<<endl;
                }else if((rzecz1num==0 and rzecz2num==18) or (rzecz2num==0 and rzecz1num==18)){
                    cout<<bad_0_18<<endl;
                }else if((rzecz1num==1 and rzecz2num==18) or (rzecz2num==1 and rzecz1num==18)){
                    cout<<bad_1_18<<endl;
                }else if((rzecz1num==2 and rzecz2num==18) or (rzecz2num==2 and rzecz1num==18)){
                    cout<<bad_2_18<<endl;
                }else if((rzecz1num==3 and rzecz2num==18) or (rzecz2num==3 and rzecz1num==18)){
                    cout<<bad_3_18<<endl;
                }else if((rzecz1num==7 and rzecz2num==18) or (rzecz2num==7 and rzecz1num==18)){
                    cout<<bad_7_18<<endl;
                }else if((rzecz1num==8 and rzecz2num==18) or (rzecz2num==8 and rzecz1num==18)){
                    cout<<bad_8_18<<endl;
                }else if((rzecz1num==11 and rzecz2num==18) or (rzecz2num==11 and rzecz1num==18)){
                    cout<<bad_11_18<<endl;
                }else if((rzecz1num==12 and rzecz2num==18) or (rzecz2num==12 and rzecz1num==18)){
                    cout<<bad_12_18<<endl;
                }else if((rzecz1num==13 and rzecz2num==18) or (rzecz2num==13 and rzecz1num==18)){
                    cout<<bad_13_18<<endl;
                }else if((rzecz1num==14 and rzecz2num==18) or (rzecz2num==14 and rzecz1num==18)){
                    cout<<bad_14_18<<endl;
                }else if((rzecz1num==15 and rzecz2num==18) or (rzecz2num==15 and rzecz1num==18)){
                    cout<<bad_15_18<<endl;
                }else if((rzecz1num==9 and rzecz2num==18) or (rzecz2num==9 and rzecz1num==18)){
                    cout<<bad_9_18<<endl;
                }else{
                    cout<<tablica[int(rzecz1num)].opis_bad<<endl;
                }
            }
        }
    }else if(komenda=="wez"){//dodaje do ekwipunku przedmiot
        cout<<"Wpisz przedmiot"<<endl;
        cin>>rzecz1;
        for(int i=0;i<26;i++){
            if (tablica[i].name==rzecz1){
                rzecz1num=i;
                break;
            }
        }
        if(tablica[rzecz1num].found==true){
            if(tablica[rzecz1num].caninv==true){
                tablica[rzecz1num].inventory=true;
                cout<<"Przedmiot dodany"<<endl;
            }else{
                cout<<"Nie można dodać"<<endl;
            }
        }
        }else if(komenda=="ekwipunek"){//wyswietla ekwipunek
            cout<<"Ekwipunek:"<<endl;
            for(int i=0;i<26;i++){
                if (tablica[i].inventory==true){
                    cout<<tablica[i].name<<endl;
                }
            }
        }else if(komenda=="popatrz"){//umozliwia przeczytanie opisu przedmiotu
            cout<<"Wpisz przedmiot"<<endl;
            cin>>rzecz1;
            for(int i=0;i<26;i++){
                if (tablica[i].name==rzecz1){
                    rzecz1num=i;
                    break;
                }else{
                    rzecz1num=-1;
                }
            }
            //mozna przeczytac opis gdy przedmiot znajduje sie na aktywnej stronie
            if((tablica[rzecz1num].inventory==true)or( tablica[rzecz1num].side==active_side)){
                    //w przypadkach ponizej uzycie tej komendy odkrywa ukryte wiadomosci lub inne przedmioty
                cout<<tablica[rzecz1num].opis<<endl;
                if(rzecz1num==1){
                   tablica[14].inventory=true;
                   tablica[14].found=true;
                   cout<<"Dodano do ekwipunku "<<tablica[14].name<<endl;
                }else if(rzecz1num==4){
                    tablica[12].inventory=true;
                    tablica[12].found=true;
                    cout<<"Dodano do ekwipunku "<<tablica[12].name<<endl;
                }else if(rzecz1num==23){
                    tab_dziennik[4].active=true;
                    cout<<"Dodano wpis do dziennika"<<endl;
                }else if(rzecz1num==10){
                     tablica[9].inventory=true;
                     tablica[9].found=true;
                     cout<<"Dodano do ekwipunku "<<tablica[9].name<<endl;
                }else if(rzecz1num==15){
                     tablica[7].inventory=true;
                     tablica[7].found=true;
                     cout<<"Dodano do ekwipunku "<<tablica[7].name<<endl;
                }else if(rzecz1num==17){
                    tablica[18].found=true;
                    tablica[18].side=0;
                }else if(rzecz1num==20){
                     tablica[8].inventory=true;
                     tablica[8].found=true;
                     cout<<"Dodano do ekwipunku "<<tablica[8].name<<endl;
                }else if(rzecz1num==21){
                    tab_dziennik[5].active=true;
                    cout<<"Dodano wpis do dziennika"<<endl;
                }else if(rzecz1num==3){
                    tab_dziennik[6].active=true;
                    cout<<"Dodano wpis do dziennika"<<endl;
                }else if(rzecz1num==11){
                   tablica[13].inventory=true;
                   tablica[13].found=true;
                   cout<<"Dodano do ekwipunku "<<tablica[13].name<<endl;
                }
            }else{
                cout<<"Nie da się tego zrobić"<<endl;
            }
        }else if(komenda=="kod"){//umozliwia wpisanie kodu do przedmiotu ktory znajduje sie na aktywnej stronie
            if(active_side==0){//wpisuje kod do sejfu
                message=message_sejf;
                good_code=good_code1;
                rzecz1num=16;
                cont=true;
            }else if (active_side==1){//wpisuje kod do drzwi
                message=message_drzwi;
                good_code=good_code2;
                rzecz1num=19;
                cont=true;
            }else{//na aktywnej stronie nie ma zadnego przedmiotu do ktorego mozna wpisac kod
                cout<<"Nie ma gdzie wpisać kodu.\nObróć się w dobrą stronę."<<endl;
                cont=false;
            }
            if(cont==true){//jezeli gracz nie wpisze liczby
                cout<<"Wpisz kod: "<<endl;
                cin>>code;
                if( !cin ){ // wpisano coś, co nie jest liczbą
                    cin.clear();
                    cin.sync();
                    cout<<"Musisz wpisać liczbę"<<endl;
                }else{
                    if(code==good_code){ //przy wpisanie poprawnego kodu wypisywana jest wiadomosc
                        cout<<message<<endl;
                        if(rzecz1num==19){//jezeli wpisano poprawny kod do drzwi - koniec gry i outro
                            PlaySound(TEXT("Muzyka/gamesound-1"), NULL, SND_LOOP | SND_ASYNC);
                            gameon=1;
                        }
                    }else{
                        cout<<"Zły kod"<<endl;
                    }
                }
            }
        }else if (komenda=="dziennik"){//wyswietlenie dziennika
            for(int i=0;i<8;i++){
                if (tab_dziennik[i].active==true){
                    cout<<tab_dziennik[i].skad<<"->"<<tab_dziennik[i].nazwa<<": "<<tab_dziennik[i].opis<<endl;
                }
            }
        }else{
            cout<<"Wybierz inną komendę"<<endl;
        }
    }
    //outro
    cout<<"Udało się ukończyć grę.\nPo wielu trudach udało ci się wydostać ze sklepu.\nDziwne po co komu takie zabezpieczenia."<<endl;
    system("pause");
    while(1){
        system( "cls" );
        random2= ((rand()%5));
        SetConsoleTextAttribute( hOut, kolory[random2] );
        cout<<scena[random2];
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
        cout<<scena5;
        cout<<"Naciśnij jakiś klawisz by zakończyć grę"<<endl;
        if (kbhit()) break;
        Sleep(800);

    }
    system( "cls" );

    SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
    cout<<"Muzyka: "<<endl;
    cout<<"- 8 Bit Game Theme - Mrthenoronha"<<endl;
    cout<<"- Keep At It loop - bigcat_smauls"<<endl;
    cout<<"- gamesound 1 - milton."<<endl;
    system("pause");
    return 0;
}
