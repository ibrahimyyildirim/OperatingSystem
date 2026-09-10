# OperatingSystem

Operating systems course project: a small Unix shell in C (`writeYourOwnShell`).

The shell reads a command line, splits it into arguments and runs external programs with `fork` + `execv`, waiting for the child to finish. Three small programs are built alongside it as external commands — `mul` (multiplication), `div` (division) and `rakam` (prints a digit's name in Turkish) — plus built-in `cat`, `clear`, `help` and `exit`.

```sh
cd writeYourOwnShell
make
./myshell
```
