# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test_forks.sh                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amateo-r <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/05 10:15:45 by amateo-r          #+#    #+#              #
#    Updated: 2023/01/05 10:17:14 by amateo-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

# M
# ./philosophers 5 400 400 400

# M: Hay tenedores por cada philosopher. Aquí solo hay un tenedor, por tanto no puede comer.
# El enunciado dice que 1 o más filósofos se sientan a comer, por tanto debe ejecutarse la 
# simulación.
# DEV NOTES
# Se queda en un bucle eterno esperando a algo.
# ./philosophers 1 800 200 200

# V
# ./philosophers 5 800 200 200

# V
# DEV NOTES
# Los estados no se actualizan correctamente
# Hay filósofos que mueren. El primerto tan solo.
# Los estados pueden estar corrompiendose debido a que la simulación termina antes. Con la 
# variable stop activa los estados dejan de actualizarse.
# Además la simulación termina porque no reinicio philo->birth cuando comen.s
# ./philosophers 5 800 200 200 7

# V
# ./philosophers 4 410 200 200

# M
# ./philosophers 4 310 200 100

# V
./philosophers 3 310 103 103

# M: uno tendría que morir.
# ./philosophers 3 310 104 104

# 1 - t104 - e208 - DONE
# 2 - e104 - DONE
# 3 - t104 - s208 - e312
