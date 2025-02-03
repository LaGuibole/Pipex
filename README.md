# 📝 Pipex
Pipex is a project from 42 aimed at reproducing the behavior of the pipe ``` | ``` command in UNIX. 
It allows executing two commands by linking them ia an inter-process communication pipe, just like the bash shell does.

The project teaches process management, the use of pipes (```pipe())```, redirections ```(dup2())```, and program execution (```execve()```).

# 📁 Compilation and installation
Clone this repository and compile the program using make:
```
make
```
This generates an executable called pipex in the current directory

# 🚀 Usage
Basic syntax
```
./pipex infile "cmd1" "cmd2" outfile
```
```infile```: input file
```cm1```: first command executed, reading from ```infile```
```cmd2```: second command executed, receiving output from ```cmd1```
```outfile```: output file containing the final result

# 🔹Example Usage
Equivalent to the shell command:
```
< infile cmd1 | cmd2 > outfile
```
Practcal exemple with ```ls``` and ```wc```:
```
./pipex infile "ls -l" "wc -l" outfile
```
This lists the files in ```infile```, counts the line and writes the result to ```outfile```

# 📌 Features
- File management (```open```, ```close```, ```read```, ```write```)
- Process creation (```fork```)
- Inter-Process communication (```pipe```)
- Command Execution (```execve```)
- Error handling

# 🛠 Bonus
The bonus project adds:
- Handling multiple pipes (```cmd1 | cmd2 | cmd3 | ... | cmdN```)
- Support for (```here_doc```)

# Syntax
```./pipex here_doc LIMITER "cmd1" "cmd2" "..." "cmdN" outfile```

# 📜 Internal Workflow
1. Opening files (```open()```)
2. Creating the pipes (```pipe()```)
3. Forking process (```fork()```)
4. Redirecting input/output (```dup2()```)
5. Executing commands (```execve()```)
6. Closing files and pipes (```close()```)

# 🐞 Error handling
The program handles:
- Non-existent files
- Insufficient permissions
- Command not found
- Invalid arguments

# 🌀 My understanding of the project: 
./pipex
```
[ Parent Process ]
		┌──────────────┬──────────────┐
		│ pipex.fd[0]  │ pipex.fd[1]  │
		│  (lecture)   │  (écriture)  │
		└──────────────┴──────────────┘

[ Parent Process ]       [ Child 1 ]
    ┌──────────────┬──────────────┐
    │ pipex.fd[0]  │ pipex.fd[1]  │
    │  (lecture)   │  (écriture)  │
    └──────────────┴──────────────┘
          │                │
          │                ├──> STDOUT de cmd1 redirigé vers pipex.fd[1]
          │                ├──> Exécute `cmd1`
          │                └──> Produit une sortie
          
 [ Parent Process ]       [ Child 1 ]      [ Child 2 ]
    ┌──────────────┬──────────────┐
    │ pipex.fd[0]  │ pipex.fd[1]  │
    │  (lecture)   │  (écriture)  │
    └──────────────┴──────────────┘
          │                │               │
          │                │               ├──> STDIN de cmd2 redirigé depuis pipex.fd[0]
          │                │               ├──> Exécute `cmd2`
          │                │               └──> Lit la sortie de `cmd1`
          
          [ Parent Process ]
    ┌──────────────┬──────────────┐
    │  (fermé)     │  (fermé)     │
    └──────────────┴──────────────┘
    
          +---------+      pipe      +---------+
  file1 → |  cmd1   |  ───────────►  |  cmd2   | → file2
          +---------+                +---------+
```
./pipex_bonus
```
./pipex_bonus here_doc <LIMITER> <cmd1> <cmd2> <...> <outfile>>

     +---------+
     | infile  |
     +---------+
         │
         ▼
     [cmd1] → pipe → [cmd2] → pipe → [cmd3] → ... → [cmdN]
     
     [cmd1] → pipe → [cmd2] → pipe → [cmd3] → ... → [cmdN] → outfile
     
        +---------+      pipe      +---------+      pipe      +---------+      pipe      +---------+
stdin → |  cmd1   |  ───────────►  |  cmd2   |  ───────────►  |  cmd3   |  ───────────►  |  cmdN   | → outfile
        +---------+                +---------+                +---------+                +---------+
          (fork)                      (fork)                      (fork)                      (exec)
          (dup2 infile)               (dup pipe)                  (dup pipe)                  (dup2 outfile)
```
