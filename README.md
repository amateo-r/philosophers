# philosophers
Stupid forks.
The final answer to the problem is Resource hierarchy solution.

## Allowed Functions
memset
printf
malloc
free
write
usleep					- Por procedimientos del sistema puede demorar o alterar el tiempo de espera. MALO, MUY MALO.
gettimeofday			- Tipo de dato personalizado struct en input.
pthread_create			- Para matar un proceso se necista llamar a pthread_join al final o alternativamente pthread_detacth. Own Structs Data Inputs case.
pthread_detach			- Finaliza un proceso cuando ha terminado su ejecución. Si no lo ha hecho, no lo mata. Múltiples llamadas de esta función sobre un mismo proceso produce efectos inesperados.
pthread_join			- Finaliza la ejecución del hilo convocado cuando el hilo objetivo termina. Problemático quizás.
pthread_mutex_init		- Inicia un mutex.
pthread_mutex_destroy	- Libera el espacio alocado a un mutex.
pthread_mutex_lock		- Bloquea un mutex.
pthread_mutex_unlock	- Desbloque un mutex.

						Conclusión: Como viene siendo costumbre las explicaciones del sistema son una basura.

## Help links
https://www.geeksforgeeks.org/mutex-lock-for-linux-thread-synchronization/?ref=gcse
https://docs.oracle.com/cd/E37838_01/pdf/E61057.pdf
https://www.ibm.com/docs/en/i/7.3?topic=ssw_ibm_i_73/apis/users_61.htm

## Testeos

//P  0   1   2   3
// 1 F 2 F 3 F 4 F
//F0   1   2   3
// N = 4
// #define LEFT (i+N-1)%N    // number of i's left neighbor
// #define RIGHT (i+1)%N     // number of i's right neighbor

// L1 = (0 + 4 - 1) % 4 = 3
// R1 = (0 + 1) % 4 = 1

// L2 = (1 + 4 - 1) % 4 = 0
// R2 = (1 + 1) % 4 = 2

// L3 = (2 + 4 - 1) % 4 = 1
// R3 = (2 + 1) % 4 = 3

// L4 = (3 + 4 - 1) % 4 = 2
// R4 = (3 + 1) % 4 = 0
