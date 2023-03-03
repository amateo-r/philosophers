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

#	5 400 400 400		Mío, resultado muy previo M. Probablemente deberían de vivir?
# M 1 800 200 200
# V 5 800 200 200
# V 5 800 200 200 7		viven y cada uno come 7 veces
# V 4 410 200 200
# M 4 310 200 100
# V 3 310 103 103
# M 3 310 104 104		Uno tendría que morir.

# ./philosophers 5 400 400 400

# ./philosophers 5 400 400 400
# ./philosophers 1 800 200 200
./philosophers 5 800 200 200
# ./philosophers 5 800 200 200 7
# ./philosophers 4 410 200 200
# ./philosophers 4 310 200 100
# ./philosophers 3 310 103 103
# ./philosophers 3 310 104 104
