//Declaraciones Elementos de la pantalla

//Declaraciones elementos de página 0
NexPage page0 = NexPage(0, 0, "intro");

///////////////////////////////////////////////

//Declaraciones de página 1 MENU
NexPage page1 = NexPage(1, 0, "menu");

///////////////////////////////////////////////

//Declaraciones de página 2 Ajustes
NexPage page2 = NexPage(2, 0, "ajustes");

//Elementos Pantalla 2 Ajustes
NexSlider h0_2 = NexSlider(2, 2, "h0");  //umbral

////////////////////////////////////////////////

//Declaraciones página 3 repro
NexPage page3 = NexPage(3, 0, "repro");

//Elementos pantalla 3 repro
NexButton b1_3 = NexButton(3, 2, "b1");
NexButton b2_3 = NexButton(3, 3, "b2");
NexButton b3_3 = NexButton(3, 4, "b3");
NexButton b4_3 = NexButton(3, 7, "b4");
NexButton b5_3 = NexButton(3, 8, "b5");
NexButton b6_3 = NexButton(3, 5, "b6");
NexButton b7_3 = NexButton(3, 9, "b7");  //Botón STOP

NexSlider h0_3 = NexSlider(3, 6, "h0");  //volumen

//Declaraciones página 4 Micrófono
NexPage page4 = NexPage(4, 0, "microfono");

//Elementos pçagina 4 Micrófono


//Lista de Eventos
NexTouch *nex_listen_list[]=
{
    &page0,   //página 0
    &page1,   //Página 1
    &page2,   //Página 2
    &h0_2,
    &page3,  //Página 3
    &b1_3,
    &b2_3,
    &b3_3,
    &b4_3,
    &b5_3,
    &b6_3,
    &b7_3,
    &h0_3,
    &page4,
    NULL
};


