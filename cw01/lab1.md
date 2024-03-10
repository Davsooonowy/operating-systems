# Zadanie
1. Zapoznaj się z koncepcją plików Makefile: [link](https://www.gnu.org/software/make/manual/html_node/Introduction.html)
2. Zainstaluj skrypt konfiguracyjny IDE, w którym będziesz pracować przez resztę laboratorium. (np. VS Code, Vim, etc.)
3. Stwórz nowy projekt w dowolnym języku programowania.
4. Napisz prosty program countdown.c który będzie w pętli odliczał od 10 do 0 i wyświetlał aktualną liczbę na konsolce (każda liczba w nowej linii).
5. Stwórz plik Makefile, za pomocą którego zbudujesz swój program.
    - Makefile powinien zawierać co najmniej trzy targety: all, countdown, clean.
        - all — powinien budować wszystkie targety (na razie tylko countdown; w kolejnych zadaniach będziemy dodawać nowe targety).
        - countdown — buduje program countdown.c
        - clean — usuwa wszystkie pliki binarne; czyści cały projekt
    - Użyj zmiennych CC oraz CFLAGS do zdefiniowania kompilatora (gcc) i flag compilacji (-Wall, -std=c17,...).
    - Dodatkowo w Makefile powinien być spisany PHONY.
6. Skompiluj i uruchom program.

Korzystając z gdb (lub lldb) zaznacz poniżej:
1. zatrzymanie programu (breakpoint) wewnątrz pętli
2. podglądzenie aktualnego indeks pętli
3. kontynuację wykony
