[![Build Status](https://travis-ci.com/Z1NZ/corewar.svg?token=56VCMhHqbWRfYQ8NUxs3&branch=master)](https://travis-ci.com/Z1NZ/corewar)
[![Stories in Progress](https://badge.waffle.io/Z1NZ/corewar.svg?label=waffle%3Ain%20progress&title=In%50Progress)](https://waffle.io/Z1NZ/corewar)

                                                  /****/COREWAR SUPER VM/****/


C’est quoi, le Corewar ?
Le Corewar est un jeu très particulier. Il consiste à rassembler autour d’une "ma- chine virtuelle" des "joueurs", lesquels vont y charger des "champions" qui vont se battre à l’aide de "processus", dans le but, entre autres, de faire en sorte qu’on dise d’eux qu’ils sont "en vie".
Les processus s’exécutent séquentiellement au sein de la même machine virtuelle, et du même espace mémoire. Ils peuvent donc, entre autre chose, s’écrire les uns sur les autres afin de se corrompre mutuellement, de forcer les autres à exécuter des instructions qui leur font du mal, de tenter de recréer à la volée l’équivalent logiciel d’un Côtes du Rhône 1982, etc ...
Le jeu se termine quand plus aucun processus n’est en vie. À ce moment là, le gagnant est le dernier joueur à avoir été rapporté comme étant "en vie".
