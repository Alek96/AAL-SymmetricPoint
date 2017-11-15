# AAL-symmetricPoint  
_Projekt dla przedmiotu AAL (Analiza Algorytmów) na PW_  
_Tytuł projektu: Punkty Symetryczne_  


## Opis problemu  
W układzie współrzędnych XY znajduje się n punktów o współrzędnych całkowitych. Należy znaleźć prostokąt o bokach równoległych do osi współrzędnych o najmniejszym obwodzie, który zawiera wszystkie punkty lub ich odbicia symetryczne względem prostej y=x. Jeśli prostokątów o najmniejszym obwodzie jest kilka, należy wybrać ten zawierający więcej punktów oryginalnych (nie odbitych).  

## O programie  
Program ma za zadanie przetestować algorytm (heurystyka.h), który rozwiązuje podany powyżej problem.  

## Biblioteki zewnętrzne  
Projekt wykorzystuje do budowanie bibliotekę SCons, do testów jednostkowych bibliotekę catch.hpp, oraz do wprowadzenia parametrów uruchamiania programu bibliotekę cxxopts.hpp.  

## Budowanie (SCons)  
Do zbudowania aplikacji wystarczy wpisać w konsolę `scons` w katalogu głównym.  
Aby zobaczyć większą liczbę dostępnych opcji należy wpisać `scons -h`.  
Możliwość budowania na systemach Windows, Linux (możliwe że też na innych, ale nie było to testowane).  

Wersja SCons użytego w tym projekcie: 2.5.1   

## Uruchomienie  
### Tryb podstawowy  
Do uruchomienia programu wystarczy wpisać jego nazwe w terminalu:  
```
	./Project
```
W tym trybie dane wejściowe są wprowadzane przez konsolę. Ich forma jest następująca: w pierwszej kolejności podajemy liczbę punktów (n), a następnie ich współrzędne (x, y). np:  
```
	5
	-1 2
	2  4
	2 -2
	4  4
	4 -4
```
Program powinien wyświetlić odpowiedz:  
```	
	[(2,-4),(4,4),4]
```
która jest współrzędnymi prostokąta, kolejno lewego dolnego, oraz prawego górnego rógu, oraz liczbę orginalnych punktów (nie odbitych symetrycznie względem  prostej y=x) znajdujących się w tym prostokącie.  

### Tryb z użyciem flag  
Program można uruchomić używając flag, wszystkie flagi dostępne są po wpisaniu `-h` lub odpowiednio `--help`.  

Gdy zdecydujemy się na uruchomienie programu z użyciem flag, dane wejściowe będą generowane automatycznie - nie będzie ich trzeba wprowadzać ręcznie.  

Flaga `-v, --verify` umożliwia sprawdzanie poprawności odpowiedzi.  
```
	./Project -v
```
__Uwaga!__ Bez dodania flagi `-o, --output`, nie zauważymy wyników w terminalu.  
__Uwaga!__ Algorytm sprawdzający poprawność wyników jest złożoności O(2^n * logn), więc nie poleca się używania tej flagi przy liczbie punktów w teście więkrzych niż 20.  

Flaga `-o, --output` umożliwia wyświetlanie wyników każdego z przeprowadzonych testów.  
```	
	./Project -o
```
Flaga `-c, --time` umożliwia pomiar czasu wykonywania każdego z przeprowadzonych testów.  
```	
	./Project -c
```
Dodając flagi `-p, --points arg1` i `-r, --range arg2` zostanie wygenerowany test o `arg1` punktach, gdzie każdy z punktów będzie się mieścił w zakresie (`-atg2`, `arg2`).  
```	
	./Project -p 10 --range 5
```
Gdy do tych dwóch flag dodamy jeszcze `-t, --tests arg3` jesteśmy w stanie okręślicz liczbę testów jaka zostanie wygenerowana.  
```	
	./Project -p 10 --range 5 --tests=10
```
Możliwe jest jescze dodanie dodatkowych dwóch fag `-i, --increment arg4` i `-s, --step arg5` które wygenerują `arg5` kroków. Na każdym kroku zostanie przeprowadzone `arg3` testy, oraz po zakończeniu każdego kroku liczba generowanych punktów `arg1`, będzie zwiększana o `arg4`.  
Gdy do tej opcji dodamy flagę `-c` po zakończeniu każdego kroku zostanie wyświetlona średnia arytmetyczna pomiar czasu wykonywania każdego z przeprowadzonych testów w tym kroku.  

## Metoda rozwiązania problemu  
### heurystyka.h  
Prblem został rozwiązany w trzech krokach:  
__krok 1__ Przerzucamy wszystkie punkty na 1 stronę osi symetrii - w ten sposób dostajemy prostokąt o najmniejszym obwodzie zawierający wszystkie punkty.  
__krok 2__ Sprawdzamy czy jesteś w stanie otrzymać lepszy wynik (wiecej punktów orginalnych w prostokącie) przez symetryczne odbijanie punktów idąc od jedej ze stron osi wspólrzędnych, aż otrzymamy taki sam obwód prostokąta jak w punkcie 1. Powatarzamy to dla drugiej osi współrzędnych i dla obu na raz.  
__krok 3__ Powatarzamy krok 1, ale przerzucamy punkty na 2 stronę osi symetrii.  

Złożoność __O(n)__  

## brut.h  
program sprawdzający poprawność wyników.  
Problem został rozwiązany przez sprawdzenie wszystkich możliwych wyników i wybranie najlepszego. Zostało to przeprowadzone z wykorzystaniem rekurencji [O(2^n)], oraz struktury drzewiaste trzymające minimalne i maksymalne wielkości x-ów i y-ów [O(logn)].  

Złożoność __O(2^n * logn)__  

## Dokumentacja  
* src:  
	*  main.cpp - petla główna programu obsługująca dane wejściowe  
	*  Algorithm:  
		* basicAlgorithm.h - Klasa abstrakcyjna, która jest podstawą wszystkich algorytmów do rozwiązywania problemu.  
		* brut.h - Klasa rozwiązująca problem w złożoności O(2^n * logn).  
		* heurystyka.h - Klasa rozwiązująca problem w złożoności O(n).  
		* generator.h - Klasa tworząca dane do tesów.  
	* Data:  
		* rectangle.h - Klasa trzymająca dane o prostokącie.  
		* pointData.h - Klasa trzymająca dane punktów.  
		* rectangleData.h - Klasa dziedzicząca po pointData.h, wraz z trzymaniem danych punktów, posiada struktury drzewiaste trzymające minimalne i maksymalne wielkości x-ów i y-ów.  
	* Test:  
		* outputTest.h - Klasa trzymająca dane o przeprowadzonych testach.  
		* test.h - Klasa testująca.  
	* UnitTest:  
		* UnitTest.py - Stworzony własny program do budowania Testów jednostkowych integralny z SCons.  
* 3rd-party - Biblioteki zewnętrzne.  
* example test - Przykładowe dane do problemu.  
* SConstruct, SConstruct.py, SConscript.py - pliki konfigurujące SCons  

---
Autor: ___Aleksander Zamojski___  
