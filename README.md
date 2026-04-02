# pipex

*Este proyecto ha sido creado como parte del currículo de 42 por joaseque.*

## Descripcion:
- Pipex es un proyecto culla funcion es simular los pipes de Unix (|) en C, ejecutando comandos de forma encadenada, recibiendo input de un archivo "infile" y mandandolo a un archivo "outfile".

## Instrucciones:
- Se usara el comando "make" para compilar el programa.
- Se ejecuta el programa de la siguiente forma: (./pipex "infile" "cmd1" "cmd2" "outfile").
- El infile debe de estar creado antes de ejecutar el programa.

## Recursos:
- Manuales sobre las funciones autorizadas; *man pipe*, *man fork*, *man execve*, etc.
- uso de claude para explicaciones mas extensas sobre las funciones autorizadas y para entender que errores he ido encontrando.

# pipex_bonus

## Descripción:
- La parte bonus hace que pipex sea capaz de manejar tantos comandos como se desee y tambien el uso de here_doc.

## Instrucciones:
- Se usara el comando "make bonus" para compilar la parte bonus.
- Se ejecuta el programa de la siguiente forma: (./pipex_bonus "infile" "cmd1" "cmd2" "cmd3" ... "outfile").
- Si se quiere utilizar el here_doc se debe ejecutar de esta forma: (./pipex_bonus "here_doc" "LIMITER" "cmd1" "cmd2" ... "outfile").
- En caso de no usar here_doc el infile debe de estar creado antes de ejecutar el programa.