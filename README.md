# philosophers
Stupid forks

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
