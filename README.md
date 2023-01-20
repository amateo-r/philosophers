# philosophers
Stupid forks.
The final answer to the problem is Resource hierarchy solution.

## Allowed Functions
memset
printf
malloc
free
write
usleep
- Por procedimientos del sistema puede demorar o alterar el tiempo de espera. MALO, MUY MALO.
gettimeofday
- Tipo de dato personalizado struct en input.
pthread_create
- Para matar un proceso se necista llamar a pthread_join al final o alternativamente pthread_detacth. Own Structs Data Inputs case.
pthread_detach
- Finaliza un proceso cuando ha terminado su ejecución. Si no lo ha hecho, no lo mata. Múltiples llamadas de esta función sobre un mismo proceso produce efectos inesperados.
pthread_join
- Finaliza la ejecución del hilo convocado cuando el hilo objetivo termina. Problemático quizás.
pthread_mutex_init
- Inicia un mutex.
pthread_mutex_destroy
- Libera el espacio alocado a un mutex.
pthread_mutex_lock
- Bloquea un mutex.
pthread_mutex_unlock
- Desbloque un mutex.

> Conclusión: Como viene siendo costumbre las explicaciones del sistema son una basura.

## Help links
- https://www.geeksforgeeks.org/mutex-lock-for-linux-thread-synchronization/?ref=gcse
- https://docs.oracle.com/cd/E37838_01/pdf/E61057.pdf
- https://www.ibm.com/docs/en/i/7.3?topic=ssw_ibm_i_73/apis/users_61.htm
- https://es.wikipedia.org/wiki/Exclusi%C3%B3n_mutua_(inform%C3%A1tica)
- https://www.ibm.com/docs/en/aix/7.2?topic=programming-using-mutexes

## Testeos

//P  0   1   2   3
// 1 F 2 F 3 F 4 F
//F0   1   2   3
// N = 4
// #define LEFT (i + N - 1) % N    // number of i's left neighbor
// #define RIGHT (i + 1 ) % N     // number of i's right neighbor

// L1 = (0 + 4 - 1) % 4 = 3
// R1 = (0 + 1) % 4 = 1

// L2 = (1 + 4 - 1) % 4 = 0
// R2 = (1 + 1) % 4 = 2

// L3 = (2 + 4 - 1) % 4 = 1
// R3 = (2 + 1) % 4 = 3

// L4 = (3 + 4 - 1) % 4 = 2
// R4 = (3 + 1) % 4 = 0

## Notes
- El orden de las acciones de los filósofos es el siguiente:
	- eating -> sleeping -> thinking
- pthread_mutex_init puede dar error por no crear un mutex al no haber suficiente espacio de memoria.
- Un mutex debe de ser destruido antes de que se libere su hilo. La librería de hilos mantiene un enlace a una lista de mutex.
	de no destruirlo la lista queda corrupta al tener un enlace de un hilo que ya no existe.
- Hay que comprobar la alocación de memoria de los pthreads. Aparentemente devuelven un número que quizá revele su estado 
existencial.
- Para la función gettimeofday hay dos argumentos, timeval (tp) y timezone (tzp) que son estructuras. Si tp es non-NULL y tzp es 
NULL solo la estructura tp es relleneda con datos. Si ambos son NULL no devuelve nada. Un 0 es un retorno exitoso. Un -1 que un 
error ha ocurrido. Sus resultados pueden funcionar con %ld. Añade unos cuantos segundos de más.
	- Interpreto que tengo que sacar el tiempo llamando dos veces a esta función y hacer la resta.
- La función usleep recibe por parámetro microsegundos no milisegundos.
- Arbitrator solution: un filósofo solo puede coger todos los tenedores o ninguno. Una entidad denominada "waiter" se encarga de 
administrar los tenedores. Dicha entidad sería su propio mutex.
- El tiempo empiza a contar cuando comienza la simulación o justo después de que un filósofo coma. Se ve que hay que tomar un 
valor global de tiempo antes de iniciar todos los hilos, probablemente para restar con ese.
- Da la sensación de que hay que crear un hilo para la impresión de mensajes.
- Podría parecer que hay que crear un hilo en cada filósofo para comprobar su estado de vida. Se me ocurre que al hacer esto 
podría incurrir en un problema cuando un filósofo tuviera que comer varias veces.
- ¿Cómo narices hago para pasar datos entre los hilos?
	- Un puntero a un array o struct con datos para cada t_philosopher
- Mis recursos compartidos son los tenedores.
- La inicialización de mutex puede incurrir en error.
- Los mutex deben ser destruidos.

