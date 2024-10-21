/***********************************************
* @Proposito: Disenar un programa que involucre 3 ascensores que 
* circulen en un entrono de 8 plantas para proponer unas posibles
* reformas en uno de los edificios de la Salle.
* @Autor/es: Marc Dominguez Larroya
* @Fecha crecion: 12 / 11 / 23
* @Fecha ultima modificacion: 26 / 11 / 23
************************************************/

#include <stdio.h>

int main () {
    // definicion variables:
    char entrada_funcion;

    char entrada_desde = 0;
    char entrada_hasta = 0;

    int desde = 0;
    int hasta = 0;

    int planta_actual_a = 1;
    int planta_actual_b = 1;
    int planta_actual_g = 1;

    int plantas_a_total = 0;
    int plantas_b_total = 0;
    int plantas_g_total = 0;

    int viajes_subida_a = 0;
    int viajes_subida_b = 0;
    int viajes_subida_g = 0;

    int viajes_bajada_a = 0;
    int viajes_bajada_b = 0;
    int viajes_bajada_g = 0;

    char selected_elevator = 'A';

    int distancia_a_sincarga = 0;
    int distancia_b_sincarga = 0;
    int distancia_g_sincarga = 0;

    int distancia_a_concarga = 0;
    int distancia_b_concarga = 0;
    int distancia_g_concarga = 0;

    int subida_sincarga_a = 0;
    int bajada_sincarga_a = 0;
    int subida_concarga_a = 0;
    int bajada_concarga_a = 0;

    int subida_sincarga_b = 0;
    int bajada_sincarga_b = 0;
    int subida_concarga_b = 0;
    int bajada_concarga_b = 0;

    int subida_sincarga_g = 0;
    int bajada_sincarga_g = 0;
    int subida_concarga_g = 0;
    int bajada_concarga_g = 0;


    int coste_total_inspecciones = 0;
    int coste_total_inspecciones_a = 0;
    int coste_total_inspecciones_b = 0;
    int coste_total_inspecciones_g = 0;

    int requiere_inspeccion_a=0;
    int requiere_inspeccion_b=0;
    int requiere_inspeccion_g=0;

    char entrada_inspeccion = 0;

    #define FLOORS_FOR_INSPECTION 12
    #define INSPECTION_PRICE 150

    // Mensaje de bienvenida
    printf ("Welcome to our building!\n");
        
    do {
        // Menú de selección de opciones:
        do {
            printf ("\nA. Use Elevator | B. Statistics | C. Elevators inspection | Q. Quit");
            printf ("\nEnter option: ");
            scanf (" %c", &entrada_funcion);
            if (entrada_funcion != 'A' && entrada_funcion != 'B' && entrada_funcion != 'C' && entrada_funcion != 'Q' && entrada_funcion != 'a' && entrada_funcion != 'b' && entrada_funcion != 'c' && entrada_funcion != 'q') {
                printf ("(ERROR) Invalid option\n");
            }
        } while (entrada_funcion != 'A' && entrada_funcion != 'B' && entrada_funcion != 'C' && entrada_funcion != 'Q' && entrada_funcion != 'a' && entrada_funcion != 'b' && entrada_funcion != 'c' && entrada_funcion != 'q');

        if (entrada_funcion == 'A' || entrada_funcion == 'a') {
            printf ("\n");
            do {
                //entrada from / to:
                printf ("From? ");
                scanf (" %c", &entrada_desde);

                //pasar caracter a entero para luego hacer operaciones:
                if (entrada_desde == 'B' || entrada_desde == 'b') {
                    desde = 0;
                } else if (entrada_desde == 'G' || entrada_desde == 'g') {
                    desde = 1;
                } else if (entrada_desde == '1') {
                    desde = 2;
                } else if (entrada_desde == '2') {
                    desde = 3;
                } else if (entrada_desde == '3') {
                    desde = 4;
                } else if (entrada_desde == '4') {
                    desde = 5;
                } else if (entrada_desde == '5') {
                    desde = 6;
                } else if (entrada_desde == 'A' || entrada_desde == 'a') {
                    desde = 7;
                }
            } while (entrada_desde != 'A' && entrada_desde != 'G' && entrada_desde != 'B' && entrada_desde != '1' && entrada_desde != '2' && entrada_desde != '3' && entrada_desde != '4' && entrada_desde != '5');
            

            do {
                //entrada from / to:
                printf ("To? ");
                scanf (" %c", &entrada_hasta);

                //pasar caracter a entero para luego hacer operaciones:
                if (entrada_hasta == 'B' || entrada_hasta == 'b') {
                    hasta = 0;
                } else if (entrada_hasta == 'G' || entrada_hasta == 'g') {
                    hasta = 1;
                } else if (entrada_hasta == '1') {
                    hasta = 2;
                } else if (entrada_hasta == '2') {
                    hasta = 3;
                } else if (entrada_hasta == '3') {
                    hasta = 4;
                } else if (entrada_hasta == '4') {
                    hasta = 5;
                } else if (entrada_hasta == '5') {
                    hasta = 6;
                } else if (entrada_hasta == 'A' || entrada_hasta == 'a') {
                    hasta = 7;
                }
            } while (entrada_hasta != 'A' && entrada_hasta != 'G' && entrada_hasta != 'B' && entrada_hasta != '1' && entrada_hasta != '2' && entrada_hasta != '3' && entrada_hasta != '4' && entrada_hasta != '5');
            
            if (entrada_desde == entrada_hasta) {
                printf ("(ERROR) Are you joking?\n");
            }
            //seleccionar ascensor:
            //calcular distancias entre planta actual de todos los ascensores y desde:
            if (planta_actual_a > desde) {
                distancia_a_sincarga = planta_actual_a - desde;
                subida_sincarga_a = 0;
                bajada_sincarga_a = 1;
            } else if (planta_actual_a < desde) {
                distancia_a_sincarga = desde - planta_actual_a;
                subida_sincarga_a = 1;
                bajada_sincarga_a = 0;
            } else {
                distancia_a_sincarga = 0;
                subida_sincarga_a = 0;
                bajada_sincarga_a = 0;
            }
            if (planta_actual_b > desde) {
                distancia_b_sincarga = planta_actual_b - desde;
                subida_sincarga_b = 0;
                bajada_sincarga_b = 1;
            } else if (planta_actual_b < desde) {
                distancia_b_sincarga = desde - planta_actual_b;
                subida_sincarga_b = 1;
                bajada_sincarga_b = 0;
            } else {
                distancia_b_sincarga = 0;
                subida_sincarga_b = 0;
                bajada_sincarga_b = 0;
            }
            if (planta_actual_g > desde) {
                distancia_g_sincarga = planta_actual_g - desde;
                subida_sincarga_g = 0;
                bajada_sincarga_g = 1;
            } else if (planta_actual_g < desde) {
                distancia_g_sincarga = desde - planta_actual_g;
                subida_sincarga_g = 1;
                bajada_sincarga_g = 0;
            } else {
                distancia_g_sincarga = 0;
                subida_sincarga_g = 0;
                bajada_sincarga_g = 0;
            }



            //Menor distancia para seleccionar el ascensor:
            if (distancia_a_sincarga <= distancia_b_sincarga && distancia_a_sincarga <= distancia_g_sincarga) {
                selected_elevator = 'A';
                //ver preferencia cuando las distancias son iguales puede cambiar la asignación
                    if (distancia_a_sincarga == distancia_g_sincarga) {
                        if (plantas_a_total <= plantas_g_total) {
                            selected_elevator = 'A';
                        } else {
                            selected_elevator = 'G';
                        }

                    } 
                    if (distancia_a_sincarga == distancia_b_sincarga) {
                        if (plantas_a_total <= plantas_b_total) {
                            selected_elevator = 'A';
                        } else {
                            selected_elevator = 'B';
                        }
                    }

            }
            else if (distancia_b_sincarga <= distancia_a_sincarga && distancia_b_sincarga <= distancia_g_sincarga) {
                selected_elevator = 'B';
                //ver preferencia cuando las distancias son iguales puede cambiar la asignación
                if (distancia_b_sincarga == distancia_g_sincarga) {
                    if (plantas_b_total <= plantas_g_total) {
                        selected_elevator = 'B';
                    } else {
                        selected_elevator = 'G';
                    }

                } 
                if (distancia_b_sincarga == distancia_a_sincarga) {
                     if (plantas_b_total <= plantas_a_total) {
                        selected_elevator = 'B';
                    } else {
                         selected_elevator = 'A';
                    }
                }
            }
            else if (distancia_g_sincarga <= distancia_a_sincarga && distancia_g_sincarga <= distancia_b_sincarga) {
                selected_elevator = 'G';
                //ver preferencia cuando las distancias son iguales puede cambiar la asignación
                if (distancia_g_sincarga == distancia_b_sincarga) {
                    if (plantas_g_total <= plantas_b_total) {
                        selected_elevator = 'G';
                    } else  {
                        selected_elevator = 'B';
                    }
                } 
                if (distancia_g_sincarga == distancia_a_sincarga) {
                     if (plantas_g_total <= plantas_a_total) {
                        selected_elevator = 'G';
                    } else  {
                         selected_elevator = 'A';
                    }
                }
            }
            
            //si la distancia es igual en los tres vuelvo a evaluar
            if (distancia_a_sincarga == distancia_g_sincarga && distancia_a_sincarga == distancia_b_sincarga ) {
                if (plantas_g_total <= plantas_a_total && plantas_g_total <= plantas_b_total) {
                    selected_elevator = 'G';
                }
                if (plantas_b_total <= plantas_a_total && plantas_b_total <= plantas_g_total) {
                    selected_elevator = 'B';
                }
                if (plantas_a_total <= plantas_g_total && plantas_a_total <= plantas_b_total) {
                    selected_elevator = 'A';
                }
            }  
            
            //actualizar variables para recorrido con carga:
            if (selected_elevator == 'A') {
               if (desde > hasta) {
                    //bajada con carga
                    distancia_a_concarga = desde - hasta;
                    plantas_a_total = plantas_a_total + distancia_a_concarga;
                    viajes_bajada_a++;
                    bajada_concarga_a = 1;
                    subida_concarga_a = 0;
   
                } else {
                    //subida con carga
                    distancia_a_concarga = hasta - desde;
                    plantas_a_total = plantas_a_total + distancia_a_concarga;
                    viajes_subida_a++;
                    subida_concarga_a = 1;
                    bajada_concarga_a = 0;

                }
                
            }
            if (selected_elevator == 'B') {
                if (desde > hasta) {
                    //bajada con carga
                    distancia_b_concarga = desde - hasta;
                    plantas_b_total = plantas_b_total + distancia_b_concarga;
                    viajes_bajada_b++;
                    bajada_concarga_b = 1;
                    subida_concarga_b = 0;

                } else {
                    //subida con carga
                    distancia_b_concarga = hasta - desde;
                    plantas_b_total = plantas_b_total + distancia_b_concarga;
                    viajes_subida_b++;
                    bajada_concarga_b = 0;
                    subida_concarga_b = 1;

                }
                
            }
            if (selected_elevator == 'G') {
                if (desde > hasta) {
                    //bajada con carga
                    distancia_g_concarga = desde - hasta;
                    plantas_g_total = plantas_g_total + distancia_g_concarga;
                    viajes_bajada_g++;
                    bajada_concarga_g = 1;
                    subida_concarga_g = 0;
                  
                } else {
                    //subida con carga
                    distancia_g_concarga = hasta - desde;
                    plantas_g_total = plantas_g_total + distancia_g_concarga;
                    viajes_subida_g++;
                    subida_concarga_g = 1;
                    bajada_concarga_g = 0;
           
                }
               
            }

            // printar por pantalla en el formato del enunciado
           if (selected_elevator == 'A') {
                printf ("Elevator Alpha assigned\n");
                if (subida_sincarga_a) {
                    //hacemos el bucle hasta el penúltimo
                    for (int i = planta_actual_a; i < desde; i++) {
                        //traducir de número a piso
                        if (i == 0) {
                            printf ("B..");
                        }
                        if (i == 1) {
                            printf ("G..");
                        }
                        if (i > 1 && i < 7) {
                            printf ("%d..", i - 1);
                        }
                        if (i == 7) {
                            printf("A..");
                        }
                    }
                    //Añadimos el último piso a printar
                    //traducir de número a piso, es el tramo sin carga , trayecto planta_actual hasta desde
                    if (desde == 0) {
                        printf ("B ");
                    }
                    if (desde == 1) {
                        printf ("G ");
                    }
                    if (desde > 1 && desde < 7) {
                        printf ("%d ", desde - 1);
                    }
                    if (desde == 7) {
                        printf ("A ");
                    }                
 
                } else if (bajada_sincarga_a){
                    for (int i = planta_actual_a; i > desde; i--) {
                        //traducir de número a piso
                        if (i == 0) {
                            printf ("B..");
                        }
                        if (i == 1) {
                            printf ("G..");
                        }
                        if (i > 1 && i < 7) {
                            printf ("%d..", i - 1);
                        }
                        if (i == 7) {
                            printf ("A..");
                        }
                    }
                    //Añadimos el último piso a printar
                    //traducir de número a piso, es el tramo sin carga , trayecto planta_actual hasta desde
                    if (desde == 0) {
                        printf ("B ");
                    }
                    if (desde == 1) {
                        printf ("G ");
                    }
                    if (desde > 1 && desde < 7) {
                        printf ("%d ", desde - 1);
                    }
                    if (desde == 7) {
                        printf ("A ");
                    }
                }
                if (subida_concarga_a) {
                        printf ("Going up! ");
                        for (int i = desde; i < hasta; i++) {
                            //traducir de número a piso
                            if (i == 0) {
                                printf ("B..");
                            }
                            if (i == 1) {
                                printf ("G..");
                            }
                            if (i > 1 && i < 7) {
                                printf ("%d..", i - 1);
                            }
                            if (i == 7) {
                                printf ("A..");
                            }
                        }
                        //Añadimos el último piso a printar
                        //traducir de número a piso
                        if (hasta == 0) {
                            printf("B\n");
                        }
                        if (hasta == 1) {
                            printf ("G\n");
                        }
                        if (hasta > 1 && hasta < 7) {
                            printf ("%d\n", hasta - 1);
                        }
                        if (hasta == 7) {
                            printf ("A\n");
                        }
                    }
                else if (bajada_concarga_a) {
                        printf ("Going down! ");
                        for (int i = desde; i > hasta; i--) {
                            //traducir de número a piso
                            if (i == 0) {
                                printf ("B..");
                            }
                            if (i == 1) {
                                printf ("G..");
                            }
                            if (i > 1 && i < 7) {
                                printf ("%d..", i - 1);
                            }
                            if (i == 7) {
                                printf ("A..");
                            }
                        }
                        //Añadimos el último piso a printar
                        //traducir de número a piso
                        if (hasta == 0) {
                            printf ("B\n");
                        }
                        if (hasta == 1) {
                            printf ("G\n");
                        }
                        if (hasta > 1 && hasta < 7) {
                            printf ("%d\n", hasta - 1);
                        }
                        if (hasta == 7) {
                            printf ("A\n");
                        }
                    }
                planta_actual_a = hasta;
            } 
           if (selected_elevator == 'B') {
               printf ("Elevator Beta assigned\n");
                if (subida_sincarga_b) {
                    //hacemos el bucle hasta el penúltimo
                    for (int i = planta_actual_b; i < desde; i++) {
                        //traducir de número a piso
                        if (i == 0) {
                            printf ("B..");
                        }
                        if (i == 1) {
                            printf ("G..");
                        }
                        if (i > 1 && i < 7) {
                            printf ("%d..", i - 1);
                        }
                        if (i == 7) {
                            printf ("A..");
                        }
                    }
                    //Añadimos el último piso a printar
                    //traducir de número a piso
                    if (desde == 0) {
                        printf ("B ");
                    }
                    if (desde == 1) {
                        printf ("G ");
                    }
                    if (desde > 1 && desde < 7) {
                        printf ("%d ", desde - 1);
                    }
                    if (desde == 7) {
                        printf ("A ");
                    }                
 
                } else if (bajada_sincarga_b){
                    for (int i = planta_actual_b; i > desde; i--) {
                        //traducir de número a piso
                        if (i == 0) {
                            printf ("B..");
                        }
                        if (i == 1) {
                            printf ("G..");
                        }
                        if (i > 1 && i < 7) {
                            printf ("%d..", i - 1);
                        }
                        if (i == 7) {
                            printf ("A..");
                        }
                    }
                    //Añadimos el último piso a printar
                    //traducir de número a piso
                    if (desde == 0) {
                        printf ("B ");
                    }
                    if (desde == 1) {
                        printf ("G ");
                    }
                    if (desde > 1 && desde < 7) {
                        printf ("%d ", desde - 1);
                    }
                    if (desde == 7) {
                        printf ("A ");
                    }
                }
                if (subida_concarga_b) {
                        printf ("Going up! ");
                        for (int i = desde; i < hasta; i++) {
                            //traducir de número a piso
                            if (i == 0) {
                                printf ("B..");
                            }
                            if (i == 1) {
                                printf ("G..");
                            }
                            if (i > 1 && i < 7) {
                                printf ("%d..", i - 1);
                            }
                            if (i == 7) {
                                printf ("A..");
                            }
                        }
                        //Añadimos el último piso a printar
                        //traducir de número a piso
                        if (hasta == 0) {
                            printf ("B\n");
                        }
                        if (hasta == 1) {
                            printf ("G\n");
                        }
                        if (hasta > 1 && hasta < 7) {
                            printf ("%d\n", hasta - 1);
                        }
                        if (hasta == 7) {
                            printf ("A\n");
                        }
                    }
                else if (bajada_concarga_b) {
                        printf ("Going down! ");
                        for (int i = desde; i > hasta; i--) {
                            //traducir de número a piso
                            if (i == 0) {
                                printf ("B..");
                            }
                            if (i == 1) {
                                printf ("G..");
                            }
                            if (i > 1 && i < 7) {
                                printf ("%d..", i - 1);
                            }
                            if (i == 7) {
                                printf ("A..");
                            }
                        }
                        //Añadimos el último piso a printar
                        //traducir de número a piso
                        if (hasta == 0) {
                            printf ("B\n");
                        }
                        if (hasta == 1) {
                            printf ("G\n");
                        }
                        if (hasta > 1 && hasta < 7) {
                            printf ("%d\n", hasta - 1);
                        }
                        if (hasta == 7) {
                            printf ("A\n");
                        }
                    }
                planta_actual_b = hasta;
            } 
           if (selected_elevator == 'G') {
                   printf ("Elevator Gamma assigned\n");
                if (subida_sincarga_g) {
                    //hacemos el bucle hasta el penúltimo
                    for (int i = planta_actual_g; i < desde; i++) {
                        //traducir de número a piso
                        if (i == 0) {
                            printf ("B..");
                        }
                        if (i == 1) {
                            printf ("G..");
                        }
                        if (i > 1 && i < 7) {
                            printf ("%d..", i - 1);
                        }
                        if (i == 7) {
                            printf ("A..");
                        }
                    }
                    //Añadimos el último piso a printar
                    //traducir de número a piso, es el tramo sin carga , trayecto planta_actual hasta desde
                    if (desde == 0) {
                        printf ("B ");
                    }
                    if (desde == 1) {
                        printf ("G ");
                    }
                    if (desde > 1 && desde < 7) {
                        printf ("%d ", desde - 1);
                    }
                    if (desde == 7) {
                        printf ("A ");
                    }                
 
                } else if (bajada_sincarga_g){
                    for (int i = planta_actual_g; i > desde; i--) {
                        //traducir de número a piso
                        if (i == 0) {
                            printf ("B..");
                        }
                        if (i == 1) {
                            printf ("G..");
                        }
                        if (i > 1 && i < 7) {
                            printf ("%d..", i - 1);
                        }
                        if (i == 7) {
                            printf ("A..");
                        }
                    }
                     //Añadimos el último piso a printar
                     //traducir de número a piso, es el tramo sin carga , trayecto planta_actual hasta desde
                    if (desde == 0) {
                        printf ("B ");
                    }
                    if (desde == 1) {
                        printf ("G ");
                    }
                    if (desde > 1 && desde < 7) {
                        printf ("%d ", desde - 1);
                    }
                    if (desde == 7) {
                        printf ("A ");
                    }
                }
                if (subida_concarga_g) {
                        printf ("Going up! ");
                        for (int i = desde; i < hasta; i++) {
                            //traducir de número a piso
                            if (i == 0) {
                                printf ("B..");
                            }
                            if (i == 1) {
                                printf ("G..");
                            }
                            if (i > 1 && i < 7) {
                                printf ("%d..", i - 1);
                            }
                            if (i == 7) {
                                printf ("A..");
                            }
                        }
                        //Añadimos el último piso a printar
                        //traducir de número a piso
                        if (hasta == 0) {
                            printf ("B\n");
                        }
                        if (hasta == 1) {
                            printf ("G\n");
                        }
                        if (hasta > 1 && hasta < 7) {
                            printf ("%d\n", hasta - 1);
                        }
                        if (hasta == 7) {
                            printf ("A\n");
                        }
                    }
                else if (bajada_concarga_g) {
                        printf ("Going down! ");
                        for (int i = desde; i > hasta; i--) {
                            //traducir de número a piso
                            if (i == 0) {
                                printf ("B..");
                            }
                            if (i == 1) {
                                printf ("G..");
                            }
                            if (i > 1 && i < 7) {
                                printf ("%d..", i - 1);
                            }
                            if (i == 7) {
                                printf ("A..");
                            }
                        }
                        //Añadimos el último piso a printar
                        //traducir de número a piso
                        if (hasta == 0) {
                            printf ("B\n");
                        }
                        if (hasta == 1) {
                            printf ("G\n");
                        }
                        if (hasta > 1 && hasta < 7) {
                            printf ("%d\n", hasta - 1);
                        }
                        if (hasta == 7) {
                            printf ("A\n");
                        }
                    }
                planta_actual_g = hasta;
            } 

        }
            
        if (entrada_funcion == 'B' || entrada_funcion == 'b') {
            printf ("\nElevators statistics:\n");
            printf ("\nALPHA: %d rides (%d-%d) and %d floors traveled", viajes_subida_a + viajes_bajada_a, viajes_subida_a, viajes_bajada_a, plantas_a_total);
            printf ("\nBETA: %d rides (%d-%d) and %d floors traveled", viajes_subida_b + viajes_bajada_b, viajes_subida_b, viajes_bajada_b, plantas_b_total);
            printf ("\nGAMMA: %d rides (%d-%d) and %d floors traveled", viajes_subida_g + viajes_bajada_g, viajes_subida_g, viajes_bajada_g, plantas_g_total);
            printf ("\n");

        }

        if (entrada_funcion == 'C' || entrada_funcion == 'c') {
            requiere_inspeccion_a = plantas_a_total / FLOORS_FOR_INSPECTION;
            requiere_inspeccion_b = plantas_b_total / FLOORS_FOR_INSPECTION;
            requiere_inspeccion_g = plantas_g_total / FLOORS_FOR_INSPECTION;

            if (requiere_inspeccion_a > 0 || requiere_inspeccion_b > 0 || requiere_inspeccion_g > 0) {
                if (requiere_inspeccion_a > 0) {
                    printf ("\nElevator Alpha: inspection required");
                }
                if (requiere_inspeccion_b > 0) {
                    printf ("\nElevator Beta: inspection required");
                }
                if (requiere_inspeccion_g > 0) {
                    printf ("\nElevator Gamma: inspection required");
                }
            } else {
                printf ("\nNo required inspection");
            }
            printf ("\n\n");
            if (requiere_inspeccion_a > 0 || requiere_inspeccion_b > 0 || requiere_inspeccion_g > 0) {
                do {
                    printf ("Perform inspection? ");
                    scanf (" %c", &entrada_inspeccion);
                    if (entrada_inspeccion == 'y' || entrada_inspeccion == 'Y') {
                        if (requiere_inspeccion_a > 0) {
                            coste_total_inspecciones_a = requiere_inspeccion_a * INSPECTION_PRICE;
                            //reset plantas
                            plantas_a_total = 0;
                            printf ("Elevator Alpha inspected! (%d euros)\n", coste_total_inspecciones_a);
                        }
                        if (requiere_inspeccion_b > 0) {
                            coste_total_inspecciones_b = requiere_inspeccion_b * INSPECTION_PRICE;
                            //reset plantas
                            plantas_b_total = 0;
                            printf ("Elevator Beta inspected! (%d euros)\n", coste_total_inspecciones_b);
                        }
                        if (requiere_inspeccion_g > 0) {
                            coste_total_inspecciones_g = requiere_inspeccion_g * INSPECTION_PRICE;
                            //reset plantas
                            plantas_g_total = 0;
                            printf ("Elevator Gamma inspected! (%d euros)\n", coste_total_inspecciones_g);
                        } 
                    } else if (entrada_inspeccion == 'n' || entrada_inspeccion == 'N') {
                        break;
                    }
                } while (entrada_inspeccion != 'y' && entrada_inspeccion != 'Y');
                
            }
            coste_total_inspecciones = coste_total_inspecciones + coste_total_inspecciones_a + coste_total_inspecciones_b + coste_total_inspecciones_g;
            printf ("\nAccumulated expense: %d euros\n", coste_total_inspecciones);
        }

    } while (entrada_funcion != 'Q' && entrada_funcion != 'q');

    printf ("\nSee you later!");

    return 0;
    
}
