# pipex

*This project has been created as part of the 42 curriculum by joaseque.*

## Description:
- Pipex is a project whose purpose is to simulate Unix pipes (|) in C, executing commands in a chained manner, taking input from an "infile" and sending the output to an "outfile".

## Instructions:
- The "make" command will be used to compile the program.
- The program is executed as follows: (./pipex "infile" "cmd1" "cmd2" "outfile").
- The infile must be created before running the program.

## Resources:
- Manuals for the authorized functions; *man pipe*, *man fork*, *man execve*, etc.
- Use of Claude for more detailed explanations of the authorized functions and to understand the errors encountered during development.

# pipex_bonus

## Description:
- The bonus part allows pipex to handle as many commands as desired and also supports the use of here_doc.

## Instructions:
- The "make bonus" command will be used to compile the bonus part.
- The program is executed as follows: (./pipex_bonus "infile" "cmd1" "cmd2" "cmd3" ... "outfile").
- To use here_doc, it should be executed as follows: (./pipex_bonus "here_doc" "LIMITER" "cmd1" "cmd2" ... "outfile").
- If here_doc is not used, the infile must be created before running the program.